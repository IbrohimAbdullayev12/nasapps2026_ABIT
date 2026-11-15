# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "Astria_autogen"
  "CMakeFiles\\Astria_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Astria_autogen.dir\\ParseCache.txt"
  )
endif()
