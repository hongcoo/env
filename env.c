/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: PersiLiao PersiLiao@sixsir.com                               |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_env.h"


ZEND_DECLARE_MODULE_GLOBALS(env)

PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("env.name", "product", PHP_INI_SYSTEM, OnUpdateString, name, zend_env_globals, env_globals)
PHP_INI_END()


PHP_METHOD(env, getEnviron)
{
	RETURN_STR(zend_string_copy(zend_string_init(ENV_G(name),strlen(ENV_G(name)),0)));
}

PHP_METHOD(env, isProduct)
{
	if(zend_string_equals(zend_string_init(ENV_G(name),strlen(ENV_G(name)),0),zend_string_init(ENV_ENVIORN_PRODUCT,strlen(ENV_ENVIORN_PRODUCT),0))){
		RETURN_TRUE
	}
	RETURN_FALSE
}

PHP_METHOD(env, isGray)
{
	if(zend_string_equals(zend_string_init(ENV_G(name),strlen(ENV_G(name)),0),zend_string_init(ENV_ENVIORN_GRAY,strlen(ENV_ENVIORN_GRAY),0))){
		RETURN_TRUE
	}
	RETURN_FALSE
}

PHP_METHOD(env, isDev)
{
	if(zend_string_equals(zend_string_init(ENV_G(name),strlen(ENV_G(name)),0),zend_string_init(ENV_ENVIORN_DEV,strlen(ENV_ENVIORN_DEV),0))){
		RETURN_TRUE
	}
	RETURN_FALSE
}

PHP_METHOD(env, isLocal)
{
	if(zend_string_equals(zend_string_init(ENV_G(name),strlen(ENV_G(name)),0),zend_string_init(ENV_ENVIORN_LOCAL,strlen(ENV_ENVIORN_LOCAL),0))){
		RETURN_TRUE
	}
	RETURN_FALSE
}

zend_function_entry env_methods[] =
{
    PHP_ME(env, getEnviron, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(env, isProduct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(env, isGray, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(env, isDev, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(env, isLocal, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    {NULL, NULL, NULL}
};

PHP_MINIT_FUNCTION (env)
{
    zend_class_entry ce;

    REGISTER_INI_ENTRIES();
    REGISTER_STRINGL_CONSTANT("ENV\\VERSION", PHP_ENV_VERSION, sizeof(PHP_ENV_VERSION) - 1, CONST_PERSISTENT | CONST_CS);
    REGISTER_STRINGL_CONSTANT("ENV\\ENVIRON", ENV_G(name), strlen(ENV_G(name)), CONST_PERSISTENT | CONST_CS);

    INIT_CLASS_ENTRY(ce, "Env", env_methods);
    zend_register_internal_class(&ce);

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(env)
{
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(env)
{
#if defined(COMPILE_DL_ENV) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(env)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(env)
{
	php_info_print_table_header(2, "env support", "enabled");
    php_info_print_table_row(2, "Version", PHP_ENV_VERSION);
    php_info_print_table_row(2, "Author", "PersiLiao");
    php_info_print_table_end();
    DISPLAY_INI_ENTRIES();
}
/* }}} */

/* {{{ env_functions[]
 *
 * Every user visible function must have an entry in env_functions[].
 */
const zend_function_entry env_functions[] = {
	PHP_FE_END	/* Must be the last line in env_functions[] */
};
/* }}} */

/* {{{ env_module_entry
 */
zend_module_entry env_module_entry = {
	STANDARD_MODULE_HEADER,
	"env",
	env_functions,
	PHP_MINIT(env),
	PHP_MSHUTDOWN(env),
	PHP_RINIT(env),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(env),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(env),
	PHP_ENV_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ENV
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(env)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
