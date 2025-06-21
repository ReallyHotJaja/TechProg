# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\aes_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\aes_autogen.dir\\ParseCache.txt"
  "aes_autogen"
  )
endif()
