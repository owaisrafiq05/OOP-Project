# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Ecommerce-Cpp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ecommerce-Cpp_autogen.dir\\ParseCache.txt"
  "Ecommerce-Cpp_autogen"
  )
endif()
