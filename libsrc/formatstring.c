/*
 *  Copyright (C) 2003 SICOM Systems, INC.
 *
 *  Authors: Bob Doan <bdoan@sicompos.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <langinfo.h>
#include <monetary.h>

#include "rlib.h"
#include "pcode.h"


/*
* Formats numbers in money format using locale parameters and moneyformat codes
*/
static gint format_money(char *dest, int max, const char *moneyformat, long long x) { 
	double d = ((double) x) / RLIB_DECIMAL_PRECISION;
	int result;

	result = strfmon(dest, max - 1, moneyformat, d);
	return (result >= 0)? strlen(dest) : 0;
}


static gint format_number(char *dest, int max, const char *fmt, long long x) {
	double d = (((double) x) / RLIB_DECIMAL_PRECISION);
	return snprintf(dest, max - 1, fmt, d);
}


gint rlb_string_sprintf(gchar *dest, gchar *fmtstr, struct rlib_value *rval) {
	gchar *value = RLIB_VALUE_GET_AS_STRING(rval);
	return sprintf(dest, fmtstr, value);
}


gint rlib_number_sprintf(gchar *dest, gchar *fmtstr, const struct rlib_value *rval, gint special_format) {
	gint dec=0;
	gint left_mul=1;
	gint left_padzero=0;
	gint left_pad=0;
	gint right_mul=1;
	gint right_padzero=1;
	gint right_pad=0;
	gint where=0;
	gint commatize=0;
	gchar *c;
//	char *radixchar = nl_langinfo(RADIXCHAR);

	for(c=fmtstr;*c && (*c != 'd');c++) {
		if(*c=='$') {
			commatize=1;
		}
		if(*c=='%')
			where=0;
		else if(*c=='.') {
			dec=1;
			where=1;
		} else if(isdigit(*c)) {		
			if(where==0) {
				if(*c=='0')
					left_padzero = 1;
				else {
					left_pad += (*c-'0')*left_mul;
					left_mul *= 10;
				}
			
			} else {
				if(*c=='0')
					right_padzero = 1;
				else {
					right_pad += (*c-'0')*right_mul;
					right_mul *= 10;
				}				
			}
		}	
	}
	if(rval != NULL) {
		gchar fleft[20];
		gchar fright[20];
		gchar left_holding[20];
		gchar right_holding[20];
		gint ptr=0;
		gint64 left, right;
		left = RLIB_VALUE_GET_AS_NUMBER(rval) / RLIB_DECIMAL_PRECISION;
		if(special_format)
			left = llabs(left);
		fleft[ptr++]='%';
		if(left_padzero)
			fleft[ptr++]='0';
		if(left_pad)
			if(commatize)
				sprintf(fleft +ptr, "%d'lld", left_pad);
			else
				sprintf(fleft +ptr, "%dlld", left_pad);
		else {
			if(commatize)
				fleft[ptr++] = '\'';
			fleft[ptr++] = 'l';
			fleft[ptr++] = 'l';
			fleft[ptr++] = 'd';
			fleft[ptr++] = '\0';
		}
		sprintf(left_holding, fleft, left);
		strcpy(dest, left_holding);
		dest[strlen(left_holding)] = '\0';
		if(dec) {
			ptr=0;
			if(!special_format && RLIB_VALUE_GET_AS_NUMBER(rval) < 0 && left == 0) {
				gchar tmp[MAXSTRLEN];
				sprintf(tmp, "-%s", left_holding);
				strcpy(left_holding, tmp);
				strcpy(dest, left_holding);
				dest[strlen(left_holding)] = '\0';
			}
				
			right = llabs(RLIB_VALUE_GET_AS_NUMBER(rval)) % RLIB_DECIMAL_PRECISION;
			fright[ptr++]='%';
			if(right_padzero)
				fright[ptr++]='0';
			if(right_pad)
				sprintf(&fright[ptr], "%dlld", right_pad);
			else {
				fright[ptr++] = 'l';
				fright[ptr++] = 'l';
				fright[ptr++] = 'd';
				fright[ptr++] = '\0';
			}
			right /= tentothe(RLIB_FXP_PRECISION-right_pad);
			sprintf(right_holding, fright, right);
			dest[strlen(left_holding)] = '.';
			strcpy((dest+strlen(left_holding))+1, right_holding);
			dest[strlen(left_holding)+strlen(right_holding)+1]='\0';
		}
	
	}
	return strlen(dest);
}

gint rlib_format_string(rlib *r, struct report_field *rf, struct rlib_value *rval, gchar *buf) {
	if(rf->format == NULL) {
		if(RLIB_VALUE_IS_NUMBER(rval)) {
			sprintf(buf, "%lld", RLIB_FXP_TO_NORMAL_LONG_LONG(RLIB_VALUE_GET_AS_NUMBER(rval)));
		} else if(RLIB_VALUE_IS_STRING(rval)) {
			sprintf(buf, "%s", RLIB_VALUE_GET_AS_STRING(rval));
		} else if(RLIB_VALUE_IS_DATE(rval))  {
			strftime(buf, 100, "%m/%d/%Y", &RLIB_VALUE_GET_AS_DATE(rval));
		} else {
			sprintf(buf, "!ERR_F");
			return FALSE;
		}
	} else {
		gchar *formatstring;
		struct rlib_value rval_fmtstr2, *rval_fmtstr=&rval_fmtstr2;
		rval_fmtstr = rlib_execute_pcode(r, &rval_fmtstr2, rf->format_code, rval);
		if(!RLIB_VALUE_IS_STRING(rval_fmtstr)) {
			sprintf(buf, "!ERR_F_F");
			rlib_value_free(rval_fmtstr);
			return FALSE;
		} else {
			formatstring = RLIB_VALUE_GET_AS_STRING(rval_fmtstr);
			if (*formatstring == '!') {
				char *tfmt = formatstring + 1;
				switch (*tfmt) {
				case '$': //Format as money
					if (RLIB_VALUE_IS_NUMBER(rval)) {
						return format_money(buf, 100, tfmt + 1, RLIB_VALUE_GET_AS_NUMBER(rval));
					}
					++formatstring;
					break;
				case '#': //Format as number
					if (RLIB_VALUE_IS_NUMBER(rval)) {
						return format_number(buf, 100, tfmt + 1, RLIB_VALUE_GET_AS_NUMBER(rval));
					}
					++formatstring;
					break;
				case '@': //Format as time/date
					if(RLIB_VALUE_IS_DATE(rval)) {
						strftime(buf, 100, tfmt + 1, &RLIB_VALUE_GET_AS_DATE(rval));				
					}
					break;
				}
			}
			if(RLIB_VALUE_IS_DATE(rval)) {
				strftime(buf, 100, formatstring, &RLIB_VALUE_GET_AS_DATE(rval));				
			} else {	
				gint i=0,j=0,pos=0,fpos=0;
				gchar fmtstr[20];
				gint special_format=0;
				gchar *idx;
				gint len_formatstring;
				idx = strchr(formatstring, ':');
				if(idx != NULL && RLIB_VALUE_IS_NUMBER(rval)) {
					formatstring = g_strdup(formatstring);
					idx = strchr(formatstring, ':');
					special_format=1;
					if(RLIB_VALUE_GET_AS_NUMBER(rval) >= 0)
						idx[0] = '\0';
					else
						formatstring = idx+1;				
				}
					
				len_formatstring = strlen(formatstring);
				
				for(i=0;i<len_formatstring;i++) {
					if(formatstring[i] == '%' && ((i+1) < len_formatstring && formatstring[i+1] != '%')) {
						int tchar;
						while(formatstring[i] != 's' && formatstring[i] != 'd' && i <=len_formatstring) {
							fmtstr[fpos++] = formatstring[i++];
						}
						fmtstr[fpos++] = formatstring[i];
						fmtstr[fpos] = '\0';
						tchar = fmtstr[fpos - 1];
						if ((tchar == 'd') || (tchar == 'i') || (tchar == 'n')) {
							if(RLIB_VALUE_IS_NUMBER(rval)) {
								gchar tmp[50];
								
								rlib_number_sprintf(tmp, fmtstr, rval, special_format);
								for(j=0;j<(int)strlen(tmp);j++)
									buf[pos++] = tmp[j];
							} else {
								sprintf(buf, "!ERR_F_D");
								rlib_value_free(rval_fmtstr);
								return FALSE;
							}
						} else if (tchar == 's') {
							if(RLIB_VALUE_IS_STRING(rval)) {
								gchar tmp[500];
								rlb_string_sprintf(tmp, fmtstr, rval);
								for(j=0;j<(int)strlen(tmp);j++)
									buf[pos++] = tmp[j];

							} else {
								sprintf(buf, "!ERR_F_S");
								rlib_value_free(rval_fmtstr);
								return FALSE;
							}
						}
					} else {
						buf[pos++] = formatstring[i];
						if(formatstring[i] == '%')
							i++;
					}
				}
				buf[pos++] = '\0'; 
			}
			
		}
		rlib_value_free(rval_fmtstr);
	}


	return TRUE;
}
