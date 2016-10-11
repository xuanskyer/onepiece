dnl $Id$
dnl config.m4 for extension onepiece

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

 PHP_ARG_WITH(onepiece, for onepiece support,
 Make sure that the comment is aligned:
 [  --with-onepiece             Include onepiece support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(onepiece, whether to enable onepiece support,
dnl Make sure that the comment is aligned:
dnl [  --enable-onepiece           Enable onepiece support])

if test "$PHP_ONEPIECE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-onepiece -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/onepiece.h"  # you most likely want to change this
  dnl if test -r $PHP_ONEPIECE/$SEARCH_FOR; then # path given as parameter
  dnl   ONEPIECE_DIR=$PHP_ONEPIECE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for onepiece files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       ONEPIECE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$ONEPIECE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the onepiece distribution])
  dnl fi

  dnl # --with-onepiece -> add include path
  dnl PHP_ADD_INCLUDE($ONEPIECE_DIR/include)

  dnl # --with-onepiece -> check for lib and symbol presence
  dnl LIBNAME=onepiece # you may want to change this
  dnl LIBSYMBOL=onepiece # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $ONEPIECE_DIR/$PHP_LIBDIR, ONEPIECE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_ONEPIECELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong onepiece lib version or lib not found])
  dnl ],[
  dnl   -L$ONEPIECE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(ONEPIECE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(onepiece, onepiece.c, $ext_shared)
fi
