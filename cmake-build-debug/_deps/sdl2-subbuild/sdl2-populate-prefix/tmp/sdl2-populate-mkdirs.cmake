# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/PTSD/lib/sdl2")
  file(MAKE_DIRECTORY "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/PTSD/lib/sdl2")
endif()
file(MAKE_DIRECTORY
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/sdl2-build"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/sdl2-subbuild/sdl2-populate-prefix"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/sdl2-subbuild/sdl2-populate-prefix/tmp"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/sdl2-subbuild/sdl2-populate-prefix/src"
  "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Users/User/Desktop/113-2_oop/bad-ice-cream/cmake-build-debug/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
