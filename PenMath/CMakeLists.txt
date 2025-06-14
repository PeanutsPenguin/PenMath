#PenMath/PenMath
cmake_minimum_required(VERSION 3.24 FATAL_ERROR) # PATH_EQUAL

get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(${TARGET_NAME} LANGUAGES CXX)

#Headers
file(GLOB_RECURSE TARGET_HEADER_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.inl)
list(FILTER TARGET_HEADER_FILES EXCLUDE REGEX ${CMAKE_CURRENT_BINARY_DIR})

#Sources
file(GLOB_RECURSE TARGET_SOURCE_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/*.cc # C with classe
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.cxx
	${CMAKE_CURRENT_SOURCE_DIR}/*.c++)
list(FILTER TARGET_SOURCE_FILES EXCLUDE REGEX ${CMAKE_CURRENT_BINARY_DIR})

#Target files
set(TARGET_FILES ${TARGET_HEADER_FILES} ${TARGET_SOURCE_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${TARGET_FILES}) # generate visual studio filter


#Static library
add_library(${TARGET_NAME} STATIC)
target_sources(${TARGET_NAME} PRIVATE ${TARGET_FILES})


target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Header)


function(add_source_group_dir path)
  set(headerDir "${CMAKE_CURRENT_SOURCE_DIR}/Header/${path}")
  set(sourceDir "${CMAKE_CURRENT_SOURCE_DIR}/Source/${path}")
  file(GLOB headerFiles LIST_DIRECTORIES false "${headerDir}/*")
  file(GLOB sourceFiles LIST_DIRETORIES false "${sourceDir}/*")

  source_group("${path}/Header" FILES ${headerFiles})
  source_group("${path}/Source" FILES ${sourceFiles})

  file(GLOB children RELATIVE "${headerDir}" "${headerDir}/*")
  foreach(child ${children})
    if(IS_DIRECTORY "${headerDir}/${child}")
      add_source_group_dir("${path}/${child}")
    endif()
  endforeach()
endfunction()

file(GLOB children RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/Header" "${CMAKE_CURRENT_SOURCE_DIR}/Header/*")
foreach(child ${children})
  if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Header/${child}")
    add_source_group_dir("${child}")
  endif()
endforeach()

#Exposed variables
set(PENMATH_LIBRARY ${TARGET_NAME} PARENT_SCOPE)