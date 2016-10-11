/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_onepiece.h"

/* If you declare any globals in php_onepiece.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(onepiece)
*/

/* True global resources - no need for thread safety here */
static int le_onepiece;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("onepiece.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_onepiece_globals, onepiece_globals)
    STD_PHP_INI_ENTRY("onepiece.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_onepiece_globals, onepiece_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_onepiece_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_onepiece_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "onepiece", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_onepiece_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_onepiece_init_globals(zend_onepiece_globals *onepiece_globals)
{
	onepiece_globals->global_value = 0;
	onepiece_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
zend_class_entry * onepiece_ce;

//定义方法
ZEND_METHOD(OnePiece, public_method){
        php_printf("一个public类型方法！\r\n");
}

ZEND_METHOD(OnePiece, __construct){
        php_printf("__construct方法！\r\n");
}

static zend_function_entry onepiece_method[] = {
	ZEND_ME(OnePiece, public_method, NULL, ZEND_ACC_PUBLIC)
	ZEND_ME(OnePiece, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	{NULL, NULL, NULL}
};



PHP_MINIT_FUNCTION(onepiece)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "OnePiece", onepiece_method);
	onepiece_ce = zend_register_internal_class(&ce TSRMLS_CC);
	//定义属性
	zend_declare_property_null(onepiece_ce, "public_var", strlen("public_var"), ZEND_ACC_PUBLIC TSRMLS_CC);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(onepiece)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(onepiece)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(onepiece)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(onepiece)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "onepiece support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ onepiece_functions[]
 *
 * Every user visible function must have an entry in onepiece_functions[].
 */
const zend_function_entry onepiece_functions[] = {
	PHP_FE(confirm_onepiece_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in onepiece_functions[] */
};
/* }}} */

/* {{{ onepiece_module_entry
 */
zend_module_entry onepiece_module_entry = {
	STANDARD_MODULE_HEADER,
	"onepiece",
	onepiece_functions,
	PHP_MINIT(onepiece),
	PHP_MSHUTDOWN(onepiece),
	PHP_RINIT(onepiece),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(onepiece),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(onepiece),
	PHP_ONEPIECE_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ONEPIECE
ZEND_GET_MODULE(onepiece)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
