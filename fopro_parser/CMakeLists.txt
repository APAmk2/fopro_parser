# CMakeList.txt : CMake project for fopro_parser, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (fopro_parser "main.cpp"  "fopro.cpp" "fopro.h" "csv.cpp" "csv.h"  "utils.h" "utils.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET fopro_parser PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
