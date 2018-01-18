dnl $Id$
dnl config.m4 for extension env

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(env, for env support,
dnl Make sure that the comment is aligned:
dnl [  --with-env             Include env support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(env, whether to enable env support,
[  --enable-env           Enable env support])

if test "$PHP_ENV" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-env -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/env.h"  # you most likely want to change this
  dnl if test -r $PHP_ENV/$SEARCH_FOR; then # path given as parameter
  dnl   ENV_DIR=$PHP_ENV
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for env files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       ENV_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$ENV_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the env distribution])
  dnl fi

  dnl # --with-env -> add include path
  dnl PHP_ADD_INCLUDE($ENV_DIR/include)

  dnl # --with-env -> check for lib and symbol presence
  dnl LIBNAME=env # you may want to change this
  dnl LIBSYMBOL=env # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $ENV_DIR/$PHP_LIBDIR, ENV_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_ENVLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong env lib version or lib not found])
  dnl ],[
  dnl   -L$ENV_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(ENV_SHARED_LIBADD)

  PHP_NEW_EXTENSION(env, env.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
