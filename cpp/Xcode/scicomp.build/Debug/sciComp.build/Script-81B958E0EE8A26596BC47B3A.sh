#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/bernardocohen/repos/sciComp/cpp/Xcode
  /usr/local/Cellar/cmake/3.21.1/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/sciComp/cpp/Xcode/Debug/libsciComp.dylib /Users/bernardocohen/repos/sciComp/cpp/Xcode/Debug/libsciComp.dylib /Users/bernardocohen/repos/sciComp/cpp/Xcode/Debug/libsciComp.dylib
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/bernardocohen/repos/sciComp/cpp/Xcode
  /usr/local/Cellar/cmake/3.21.1/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/sciComp/cpp/Xcode/Release/libsciComp.dylib /Users/bernardocohen/repos/sciComp/cpp/Xcode/Release/libsciComp.dylib /Users/bernardocohen/repos/sciComp/cpp/Xcode/Release/libsciComp.dylib
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/bernardocohen/repos/sciComp/cpp/Xcode
  /usr/local/Cellar/cmake/3.21.1/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/sciComp/cpp/Xcode/MinSizeRel/libsciComp.dylib /Users/bernardocohen/repos/sciComp/cpp/Xcode/MinSizeRel/libsciComp.dylib /Users/bernardocohen/repos/sciComp/cpp/Xcode/MinSizeRel/libsciComp.dylib
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/bernardocohen/repos/sciComp/cpp/Xcode
  /usr/local/Cellar/cmake/3.21.1/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/sciComp/cpp/Xcode/RelWithDebInfo/libsciComp.dylib /Users/bernardocohen/repos/sciComp/cpp/Xcode/RelWithDebInfo/libsciComp.dylib /Users/bernardocohen/repos/sciComp/cpp/Xcode/RelWithDebInfo/libsciComp.dylib
fi

