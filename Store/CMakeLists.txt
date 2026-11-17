# CMakeList.txt : CMake project for Store, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Store "main.cpp"  "product.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Store PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
