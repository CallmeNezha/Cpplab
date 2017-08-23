function( add_note ARG_NAME )
    # Parse arguments
    #                      {prefix}  {options}    {oneValue}  {multiValue}    {args...}
    # cmake_parse_arguments( ARG       ""           ""          ""              ${ARGN} )

    # Get all sources files
    set( DIR ${NOTES_DIR}/${ARG_NAME} )
    set( SOURCES "" )

    file( GLOB GLOB_SOURCES ${DIR}/*.cpp ${DIR}/*.h ${DIR}/*.inl )
    message( STATUS ${GLOB_SOURCES} ) 
    list( APPEND SOURCES ${GLOB_SOURCES} )

    if( INSTALL_NOTES )
        add_executable( note-${ARG_NAME} ${SOURCES} )
    else()
        add_executable( note-${ARG_NAME} EXCLUDE_FROM_ALL ${SOURCES} )
    endif()
    add_dependencies( install-all-notes note-${ARG_NAME} )

    set_target_properties( note-${ARG_NAME} PROPERTIES FOLDER "notes" )

endfunction() # add_notes

add_custom_target( install-all-notes )
set_target_properties( install-all-notes PROPERTIES FOLDER "notes" )

set(
    NOTES
    "memory"
    )

foreach( NOTE ${NOTES} )
    add_note( ${NOTE} )
endforeach()
