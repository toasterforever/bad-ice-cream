# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/PTSD")
  file(MAKE_DIRECTORY "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/PTSD")
endif()
file(MAKE_DIRECTORY
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/ptsd-build"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/ptsd-subbuild/ptsd-populate-prefix"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/ptsd-subbuild/ptsd-populate-prefix/tmp"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/ptsd-subbuild/ptsd-populate-prefix/src/ptsd-populate-stamp"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/ptsd-subbuild/ptsd-populate-prefix/src"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/ptsd-subbuild/ptsd-populate-prefix/src/ptsd-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/ptsd-subbuild/ptsd-populate-prefix/src/ptsd-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/ptsd-subbuild/ptsd-populate-prefix/src/ptsd-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
