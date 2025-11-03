#PenMath RootCmake
cmake_minimum_required(VERSION 3.24 FATAL_ERROR) # PATH_EQUAL

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(TARGET_NAME ${PROJECT_NAME})

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

install(TARGETS ${TARGET_NAME} EXPORT PenMathEx)

target_include_directories(${TARGET_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/PenMath/Header>
        $<INSTALL_INTERFACE:include>
)


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

install(
	EXPORT PenMathEx
    	FILE PenMathLib.cmake
    	NAMESPACE PenMath::
    	DESTINATION ${CMAKE_INSTALL_LIBDIR}/PenMath
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/PenMathConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_file(PenMathConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/PenMathConfig.cmake"
)



if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PenMath)
endif()