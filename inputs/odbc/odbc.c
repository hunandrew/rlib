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
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
 
#include "ralloc.h"
#include "rlib_input.h"

#define MAXSTRLEN 1024
#define INPUT_PRIVATE(input) (((struct _private *)input->private))

struct odbc_fields {
	int col;
	char name[512];
};

struct odbc_field_values {
	int len;
	char *value;
};

struct rlib_odbc_results {
	char *name;
	SQLHSTMT V_OD_hstmt;
	int row;
	int tot_rows;
	int tot_fields;
	int total_size;
	int isdone;
	int state_previous;
	struct odbc_fields *fields;
	struct odbc_field_values *values;
	struct odbc_field_values *more_values;
	struct odbc_field_values *save_values;
};

struct _private {
	SQLHENV V_OD_Env;
	SQLHDBC V_OD_hdbc;
};

void * rlib_odbc_connect(void * input_ptr, char *source, char *user, char *password) {
	struct input_filter *input = input_ptr;
	long V_OD_erg;
	SQLINTEGER	V_OD_err;
	SQLSMALLINT	V_OD_mlen;
	char V_OD_stat[10]; 
	char V_OD_msg[200];

	V_OD_erg=SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&INPUT_PRIVATE(input)->V_OD_Env);
	if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO)) {
		rlogit("Error AllocHandle\n");
		return NULL;
	}
	V_OD_erg=SQLSetEnvAttr(INPUT_PRIVATE(input)->V_OD_Env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
	if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO)) {
		rlogit("Error SetEnv\n");
		SQLFreeHandle(SQL_HANDLE_ENV, INPUT_PRIVATE(input)->V_OD_Env);
		return NULL;
	}
	V_OD_erg = SQLAllocHandle(SQL_HANDLE_DBC, INPUT_PRIVATE(input)->V_OD_Env, &INPUT_PRIVATE(input)->V_OD_hdbc); 
	if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO)) {
		rlogit("Error AllocHDB %d\n",V_OD_erg);
		SQLFreeHandle(SQL_HANDLE_ENV, INPUT_PRIVATE(input)->V_OD_Env);
		return NULL;
	}
	SQLSetConnectAttr(INPUT_PRIVATE(input)->V_OD_hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER *)5, 0);

	V_OD_erg = SQLConnect(INPUT_PRIVATE(input)->V_OD_hdbc, (SQLCHAR*) source, SQL_NTS, (SQLCHAR*) user, SQL_NTS, (SQLCHAR*) password, SQL_NTS);
	if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO)) {
		rlogit("Error SQLConnect %d\n",V_OD_erg);
		SQLGetDiagRec(SQL_HANDLE_DBC, INPUT_PRIVATE(input)->V_OD_hdbc,1, V_OD_stat, &V_OD_err,V_OD_msg,100,&V_OD_mlen);
		rlogit("%s (%d)\n", V_OD_msg, V_OD_err);
		SQLFreeHandle(SQL_HANDLE_DBC, INPUT_PRIVATE(input)->V_OD_hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV, INPUT_PRIVATE(input)->V_OD_Env);
		return NULL;
	}
	
	return  INPUT_PRIVATE(input)->V_OD_Env;
}

static int rlib_odbc_input_close(void *input_ptr) {
	struct input_filter *input = input_ptr;
	SQLFreeHandle(SQL_HANDLE_ENV, INPUT_PRIVATE(input)->V_OD_Env);
	SQLDisconnect(INPUT_PRIVATE(input)->V_OD_hdbc);
	INPUT_PRIVATE(input)->V_OD_Env = NULL;
	return 0;
}

static SQLHSTMT * rlib_odbc_query(void * input_ptr, char *query) {
	struct input_filter *input = input_ptr;
	SQLHSTMT V_OD_hstmt;
	SQLINTEGER	V_OD_err;
	SQLSMALLINT	V_OD_mlen;
	char V_OD_stat[10]; 
	char V_OD_msg[200];
	long V_OD_erg;

	V_OD_erg=SQLAllocHandle(SQL_HANDLE_STMT, INPUT_PRIVATE(input)->V_OD_hdbc, &V_OD_hstmt);
	if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO)) {
		rlogit("Failed to allocate a connection handle %d\n",V_OD_erg);
		SQLGetDiagRec(SQL_HANDLE_DBC, INPUT_PRIVATE(input)->V_OD_hdbc,1, V_OD_stat,&V_OD_err,V_OD_msg,100,&V_OD_mlen);
		rlogit("%s (%d)\n",V_OD_msg,V_OD_err);
		SQLDisconnect(INPUT_PRIVATE(input)->V_OD_hdbc);
		SQLFreeHandle(SQL_HANDLE_DBC,INPUT_PRIVATE(input)->V_OD_hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV, INPUT_PRIVATE(input)->V_OD_Env);
		return NULL;
	}

	V_OD_erg=SQLExecDirect(V_OD_hstmt, query, SQL_NTS);
	if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO)) {
		rlogit("Error Select %d\n",V_OD_erg);
		SQLGetDiagRec(SQL_HANDLE_DBC, INPUT_PRIVATE(input)->V_OD_hdbc,1, V_OD_stat, &V_OD_err, V_OD_msg,100,&V_OD_mlen);
		rlogit("%s (%d)\n",V_OD_msg,V_OD_err);
		SQLFreeHandle(SQL_HANDLE_STMT,V_OD_hstmt);
		SQLDisconnect(INPUT_PRIVATE(input)->V_OD_hdbc);
		SQLFreeHandle(SQL_HANDLE_DBC,INPUT_PRIVATE(input)->V_OD_hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV,INPUT_PRIVATE(input)-> V_OD_Env);
		return NULL;
	}
	return V_OD_hstmt;
}

int odbc_read_next(void *result_ptr) {
	struct rlib_odbc_results *results = result_ptr;
	long V_OD_erg;
	int i;
	SQLINTEGER ind;
	
	if(SQL_SUCCEEDED(( V_OD_erg = SQLFetch (results->V_OD_hstmt)))) {
		for (i=0;i<results->tot_fields;i++)
			V_OD_erg = SQLGetData (results->V_OD_hstmt, i+1, SQL_C_CHAR, results->values[i].value, results->values[i].len, &ind);
		return TRUE;
	}
	return FALSE;
}


static int rlib_odbc_first(void *input_ptr, void *result_ptr) {
	struct rlib_odbc_results *result = result_ptr;
	result->row = 0;
	result->isdone = FALSE;
	result->state_previous = FALSE;
	return odbc_read_next(result_ptr);
	return TRUE;
}

static void copy_to_from(struct rlib_odbc_results *results, struct odbc_field_values *to, struct odbc_field_values *from) {
	int i;
	for(i=0;i<results->tot_fields;i++) {
		memcpy(to->value, from->value, from->len+1);
	}
}

static int rlib_odbc_next(void *input_ptr, void *result_ptr) {
	struct rlib_odbc_results *results = result_ptr;
	
	if(results->state_previous) {
		copy_to_from(results, results->values, results->save_values);
	} else {
		copy_to_from(results, results->more_values, results->values);
		odbc_read_next(result_ptr);
	}
	
	if(results->row+1 < results->tot_rows) {
		results->row++;
		results->isdone = FALSE;
		return TRUE;
	}
	results->isdone = TRUE;
	return FALSE;
}

static int rlib_odbc_isdone(void *input_ptr, void *result_ptr) {
	struct rlib_odbc_results *result = result_ptr;
	return result->isdone;
}

static int rlib_odbc_previous(void *input_ptr, void *result_ptr) {
	struct rlib_odbc_results *results = result_ptr;

	copy_to_from(results, results->save_values, results->values);
	copy_to_from(results, results->values, results->more_values);

	if(results->row-1 > 0) {
		results->row--;
		results->isdone = FALSE;
		return TRUE;
	}
	results->isdone = TRUE;
	return FALSE;
}

static int rlib_odbc_last(void *input_ptr, void *result_ptr) {
	struct rlib_odbc_results *result = result_ptr;
	result->row = result->tot_rows-1;
	result->isdone = FALSE;
	return TRUE;
}

static char * rlib_odbc_get_field_value_as_string(void *input_ptr, void *result_ptr, void *field_ptr) {
	struct rlib_odbc_results *results = result_ptr;
	struct odbc_fields *the_field = field_ptr;
	long field = the_field->col;
	return results->values[field].value;
}

static void * rlib_odbc_resolve_field_pointer(void *input_ptr, void *result_ptr, char *name) {
	struct rlib_odbc_results *results = result_ptr;
	int i=0;
	for (i = 0; i < results->tot_fields; i++) {
		if(!strcmp(results->fields[i].name, name)) {
			return &results->fields[i];
		}
	}
	return NULL;
}

void * odbc_new_result_from_query(void *input_ptr, char *query) {
	struct rlib_odbc_results *results;
	SQLHSTMT V_OD_hstmt;
	unsigned int i;
	SQLSMALLINT ncols;
	SQLINTEGER nrows;
	long V_OD_erg;
	SQLUINTEGER col_size;
	V_OD_hstmt = rlib_odbc_query(input_ptr, query);
	if(V_OD_hstmt == NULL)
		return NULL;
	else {
		results = rmalloc(sizeof(struct rlib_odbc_results));
		results->V_OD_hstmt = V_OD_hstmt;
	}

	SQLNumResultCols (V_OD_hstmt, &ncols);

	results->fields = rmalloc(sizeof(struct odbc_fields) * ncols);
	results->values = rmalloc(sizeof(struct odbc_field_values) * ncols);
	results->more_values = rmalloc(sizeof(struct odbc_field_values) * ncols);
	results->save_values = rmalloc(sizeof(struct odbc_field_values) * ncols);

	results->total_size = 0;
	for(i=0;i<ncols;i++) {
		SQLCHAR name[ 256 ];
		SQLSMALLINT name_length;
		V_OD_erg = SQLDescribeCol( V_OD_hstmt, i+1,	name, sizeof( name ), &name_length, NULL, &col_size, NULL, NULL );
		results->fields[i].col = i;
		strcpy(results->fields[i].name, name);
		results->values[i].len = col_size;
		results->values[i].value = rmalloc(col_size+1);
		results->more_values[i].len = col_size;
		results->more_values[i].value = rmalloc(col_size+1);
		results->save_values[i].len = col_size;
		results->save_values[i].value = rmalloc(col_size+1);
		results->total_size += col_size+1;
	}

	results->tot_fields = ncols;
	V_OD_erg=SQLRowCount(V_OD_hstmt,&nrows);
	results->tot_rows = nrows;

	return results;
}

static void rlib_odbc_rlib_free_result(void *input_ptr, void *result_ptr) {
	struct rlib_odbc_results *results = result_ptr;
	int i;

	SQLFreeHandle(SQL_HANDLE_STMT,results->V_OD_hstmt);
	for(i=0;i<results->tot_fields;i++) {
		rfree(results->values[i].value);
		rfree(results->more_values[i].value);
		rfree(results->save_values[i].value);
	}
	rfree(results->fields);
	rfree(results->values);
	rfree(results->more_values);
	rfree(results->save_values);
	rfree(results);
}

static int rlib_odbc_free_input_filter(void *input_ptr) {
	struct input_filter *input = input_ptr;
	SQLDisconnect(INPUT_PRIVATE(input)->V_OD_hdbc);
	SQLFreeHandle(SQL_HANDLE_DBC,INPUT_PRIVATE(input)->V_OD_hdbc);
	SQLFreeHandle(SQL_HANDLE_ENV,INPUT_PRIVATE(input)-> V_OD_Env);
	rfree(input->private);
	rfree(input);
	return 0;
}

void * rlib_odbc_new_input_filter() {
	struct input_filter *input;
	
	input = rmalloc(sizeof(struct input_filter));
	input->private = rmalloc(sizeof(struct _private));
	bzero(input->private, sizeof(struct _private));
	input->input_close = rlib_odbc_input_close;
	input->first = rlib_odbc_first;
	input->next = rlib_odbc_next;
	input->previous = rlib_odbc_previous;
	input->last = rlib_odbc_last;
	input->isdone = rlib_odbc_isdone;
	input->new_result_from_query = odbc_new_result_from_query;
	input->get_field_value_as_string = rlib_odbc_get_field_value_as_string;

	input->resolve_field_pointer = rlib_odbc_resolve_field_pointer;

	input->free = rlib_odbc_free_input_filter;
	input->free_result = rlib_odbc_rlib_free_result;
	return input;
}