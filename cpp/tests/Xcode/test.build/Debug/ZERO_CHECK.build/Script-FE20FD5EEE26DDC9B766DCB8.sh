#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/bernardocohen/repos/sciComp/cpp/tests/Xcode
  make -f /Users/bernardocohen/repos/sciComp/cpp/tests/Xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/bernardocohen/repos/sciComp/cpp/tests/Xcode
  make -f /Users/bernardocohen/repos/sciComp/cpp/tests/Xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/bernardocohen/repos/sciComp/cpp/tests/Xcode
  make -f /Users/bernardocohen/repos/sciComp/cpp/tests/Xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/bernardocohen/repos/sciComp/cpp/tests/Xcode
  make -f /Users/bernardocohen/repos/sciComp/cpp/tests/Xcode/CMakeScripts/ReRunCMake.make
fi

