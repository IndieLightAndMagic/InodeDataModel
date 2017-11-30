cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

#Project Name and Resources 
set(TARGET_NAME node)


project(${TARGET_NAME})



aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_LIST)
if (${CMAKE_GENERATOR} STREQUAL "Unix Makefiles")
	add_executable(${TARGET_NAME} ${SOURCE_LIST})
elseif (${CMAKE_GENERATOR} STREQUAL "Xcode")
	add_executable(${TARGET_NAME} MACOSX_BUNDLE ${SOURCE_LIST} )
endif()


#DEBUG
set(CMAKE_VERBOSE_MAKEFILE ON)

#DIRECTORIES
get_filename_component(ROOT_DIR ".." ABSOLUTE)
set(INCLUDE_DIR "${ROOT_DIR}")
set(LIB_DIR "${ROOT_DIR}/m")
message(STATUS "SYSTEM NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "ROOT_DIR: ${ROOT_DIR}")
message(STATUS "INCLUDE_DIR: ${INCLUDE_DIR}")
message(STATUS "LIB_DIR: ${LIB_DIR}")
message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_GENERATOR: ${CMAKE_GENERATOR}")
message(STATUS "-----------------------------")

if (${CMAKE_GENERATOR} STREQUAL "Unix Makefiles")
	message(STATUS "Unix Makefiles")
elseif(${CMAKE_GENERATOR} STREQUAL "Xcode")
	message(STATUS "Xcode")
endif()

#C++14
set(CPP14 "-std=c++14")
#MACRO DEFINITIONS
add_definitions(-DRES_DIR="${RES_DIR}")
#HEADER FILES
include_directories(${INCLUDE_DIR})
#COMPILE FLAGS
set(CMAKE_CXX_FLAGS "${CPP14}")

#LIBRARY LINKS
set(G_STATIC_LIBRARIES "Inode")
set(STATIC_LIBRARIES ${G_STATIC_LIBRARIES})


foreach(G_STATIC_LIB ${G_STATIC_LIBRARIES})
	message(STATUS "LINKING: ${LIB_DIR}/lib${G_STATIC_LIB}.a")
	target_link_libraries(${TARGET_NAME} "${LIB_DIR}/lib${G_STATIC_LIB}.a")
endforeach(G_STATIC_LIB)


