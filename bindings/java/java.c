/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#define SWIGJAVA

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  (*jenv)->ExceptionClear(jenv);
  excep = (*jenv)->FindClass(jenv, except_ptr->java_exception);
  if (excep)
    (*jenv)->ThrowNew(jenv, excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include <rlib.h>
 

#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jlong JNICALL Java_rlibJNI_rlib_1init(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  rlib *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (rlib *)rlib_init();
  *(rlib **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1datasource_1mysql(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4, jstring jarg5, jstring jarg6) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  char *arg4 = (char *) 0 ;
  char *arg5 = (char *) 0 ;
  char *arg6 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  arg4 = 0;
  if (jarg4) {
    arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
    if (!arg4) return 0;
  }
  arg5 = 0;
  if (jarg5) {
    arg5 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg5, 0);
    if (!arg5) return 0;
  }
  arg6 = 0;
  if (jarg6) {
    arg6 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg6, 0);
    if (!arg6) return 0;
  }
  result = (int)rlib_add_datasource_mysql(arg1,arg2,arg3,arg4,arg5,arg6);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, (const char *)arg4);
  if (arg5) (*jenv)->ReleaseStringUTFChars(jenv, jarg5, (const char *)arg5);
  if (arg6) (*jenv)->ReleaseStringUTFChars(jenv, jarg6, (const char *)arg6);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1datasource_1postgres(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  result = (int)rlib_add_datasource_postgres(arg1,arg2,arg3);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1datasource_1odbc(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4, jstring jarg5) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  char *arg4 = (char *) 0 ;
  char *arg5 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  arg4 = 0;
  if (jarg4) {
    arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
    if (!arg4) return 0;
  }
  arg5 = 0;
  if (jarg5) {
    arg5 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg5, 0);
    if (!arg5) return 0;
  }
  result = (int)rlib_add_datasource_odbc(arg1,arg2,arg3,arg4,arg5);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, (const char *)arg4);
  if (arg5) (*jenv)->ReleaseStringUTFChars(jenv, jarg5, (const char *)arg5);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1datasource_1xml(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  result = (int)rlib_add_datasource_xml(arg1,arg2);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1datasource_1csv(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  result = (int)rlib_add_datasource_csv(arg1,arg2);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1query_1as(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  char *arg4 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  arg4 = 0;
  if (jarg4) {
    arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
    if (!arg4) return 0;
  }
  result = (int)rlib_add_query_as(arg1,arg2,arg3,arg4);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, (const char *)arg4);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1search_1path(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  result = (int)rlib_add_search_path(arg1,(char const *)arg2);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1report(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  result = (int)rlib_add_report(arg1,arg2);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1report_1from_1buffer(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  result = (int)rlib_add_report_from_buffer(arg1,arg2);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1execute(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  result = (int)rlib_execute(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_rlibJNI_rlib_1get_1content_1type_1as_1text(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jstring jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  result = (char *)rlib_get_content_type_as_text(arg1);
  if (result) jresult = (*jenv)->NewStringUTF(jenv, (const char *)result);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1spool(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  result = (int)rlib_spool(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1set_1output_1format(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  int arg2 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = (int)jarg2; 
  result = (int)rlib_set_output_format(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1resultset_1follower_1n_1to_11(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4, jstring jarg5) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  char *arg4 = (char *) 0 ;
  char *arg5 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  arg4 = 0;
  if (jarg4) {
    arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
    if (!arg4) return 0;
  }
  arg5 = 0;
  if (jarg5) {
    arg5 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg5, 0);
    if (!arg5) return 0;
  }
  result = (int)rlib_add_resultset_follower_n_to_1(arg1,arg2,arg3,arg4,arg5);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, (const char *)arg4);
  if (arg5) (*jenv)->ReleaseStringUTFChars(jenv, jarg5, (const char *)arg5);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1resultset_1follower(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  result = (int)rlib_add_resultset_follower(arg1,arg2,arg3);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1set_1output_1format_1from_1text(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  result = (int)rlib_set_output_format_from_text(arg1,arg2);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_rlibJNI_rlib_1get_1output(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jstring jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  result = (char *)rlib_get_output(arg1);
  if (result) jresult = (*jenv)->NewStringUTF(jenv, (const char *)result);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1get_1output_1length(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  result = (int)rlib_get_output_length(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1signal_1connect(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2, jlong jarg3, jlong jarg4) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  int arg2 ;
  int (*arg3)(rlib *,void *) = (int (*)(rlib *,void *)) 0 ;
  void *arg4 = (void *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = (int)jarg2; 
  arg3 = *(int (**)(rlib *,void *))&jarg3; 
  arg4 = *(void **)&jarg4; 
  result = (int)rlib_signal_connect(arg1,arg2,arg3,arg4);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1signal_1connect_1string(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jlong jarg3, jlong jarg4) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int (*arg3)(rlib *,void *) = (int (*)(rlib *,void *)) 0 ;
  void *arg4 = (void *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = *(int (**)(rlib *,void *))&jarg3; 
  arg4 = *(void **)&jarg4; 
  result = (int)rlib_signal_connect_string(arg1,arg2,arg3,arg4);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1query_1refresh(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  result = (int)rlib_query_refresh(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1add_1parameter(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  result = (int)rlib_add_parameter(arg1,(char const *)arg2,(char const *)arg3);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1set_1locale(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  result = (int)rlib_set_locale(arg1,arg2);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_rlibJNI_rlib_1bindtextdomain(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
  jstring jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  result = (char *)rlib_bindtextdomain(arg1,arg2,arg3);
  if (result) jresult = (*jenv)->NewStringUTF(jenv, (const char *)result);
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  return jresult;
}


SWIGEXPORT void JNICALL Java_rlibJNI_rlib_1set_1radix_1character(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  rlib *arg1 = (rlib *) 0 ;
  gchar arg2 ;
  gchar *argp2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  argp2 = *(gchar **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null gchar");
    return ;
  }
  arg2 = *argp2; 
  rlib_set_radix_character(arg1,arg2);
}


SWIGEXPORT void JNICALL Java_rlibJNI_rlib_1set_1output_1parameter(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return ;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return ;
  }
  rlib_set_output_parameter(arg1,arg2,arg3);
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
}


SWIGEXPORT void JNICALL Java_rlibJNI_rlib_1set_1output_1encoding(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return ;
  }
  rlib_set_output_encoding(arg1,(char const *)arg2);
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1set_1datasource_1encoding(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  result = (int)rlib_set_datasource_encoding(arg1,arg2,arg3);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1free(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  result = (int)rlib_free(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_rlibJNI_rlib_1version(JNIEnv *jenv, jclass jcls) {
  jstring jresult = 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (char *)rlib_version();
  if (result) jresult = (*jenv)->NewStringUTF(jenv, (const char *)result);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1graph_1add_1bg_1region(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4, jfloat jarg5, jfloat jarg6) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  char *arg4 = (char *) 0 ;
  float arg5 ;
  float arg6 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  arg4 = 0;
  if (jarg4) {
    arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
    if (!arg4) return 0;
  }
  arg5 = (float)jarg5; 
  arg6 = (float)jarg6; 
  result = (int)rlib_graph_add_bg_region(arg1,arg2,arg3,arg4,arg5,arg6);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, (const char *)arg4);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1graph_1clear_1bg_1region(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  result = (int)rlib_graph_clear_bg_region(arg1,arg2);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1graph_1set_1x_1minor_1tick(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  char *arg3 = (char *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
    if (!arg3) return 0;
  }
  result = (int)rlib_graph_set_x_minor_tick(arg1,arg2,arg3);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, (const char *)arg3);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1graph_1set_1x_1minor_1tick_1by_1location(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jint jarg3) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  char *arg2 = (char *) 0 ;
  int arg3 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = (int)jarg3; 
  result = (int)rlib_graph_set_x_minor_tick_by_location(arg1,arg2,arg3);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jfloat JNICALL Java_rlibJNI_rlib_1graph(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jfloat jarg4, jlong jarg5) {
  jfloat jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  struct rlib_part *arg2 = (struct rlib_part *) 0 ;
  struct rlib_report *arg3 = (struct rlib_report *) 0 ;
  float arg4 ;
  float *arg5 = (float *) 0 ;
  float result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  arg2 = *(struct rlib_part **)&jarg2; 
  arg3 = *(struct rlib_report **)&jarg3; 
  arg4 = (float)jarg4; 
  arg5 = *(float **)&jarg5; 
  result = (float)rlib_graph(arg1,arg2,arg3,arg4,arg5);
  jresult = (jfloat)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_rlibJNI_rlib_1parse(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  rlib *arg1 = (rlib *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(rlib **)&jarg1; 
  result = (int)rlib_parse(arg1);
  jresult = (jint)result; 
  return jresult;
}


#ifdef __cplusplus
}
#endif

