#PenMath RootCmake
cmake_minimum_required(VERSION 3.24 FATAL_ERROR) # PATH_EQUAL

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(PenMath)

install(
	EXPORT PENMATH_LIBRARY
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