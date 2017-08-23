cmake_minimum_required( VERSION 3.5 )
project( CppLab )

set_property( GLOBAL PROPERTY USE_FOLDERS ON )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" )


if( NOT NOTES_DIR )
	set( NOTES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/notes" CACHE STRING "Location of notes." )
endif()

option( BUILD_NOTES     "Build cpp notes."  ON )
option( INSTALL_NOTES   "Install notes"     ON )

if( BUILD_NOTES )
	include( cmake/notes.cmake )
endif()

