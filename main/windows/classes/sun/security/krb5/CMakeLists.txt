#machine generated

add_subdirectory("internal")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" windows-classes.sun.securit_13_SRCS)
file(GLOB windows-classes.sun.securit_13_HEADERS *.h *.hpp)
source_group("Include" FILES ${windows-classes.sun.securit_13_HEADERS}) 
list(LENGTH windows-classes.sun.securit_13_SRCS windows-classes.sun.securit_13_SRCS_LENGTH)
if(windows-classes.sun.securit_13_SRCS_LENGTH)
	add_library(windows-classes.sun.securit_13 OBJECT "${windows-classes.sun.securit_13_SRCS}" "${windows-classes.sun.securit_13_HEADERS}")
	jcpp_enable_bigobj(windows-classes.sun.securit_13)
endif()