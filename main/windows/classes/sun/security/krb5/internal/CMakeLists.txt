#machine generated

add_subdirectory("tools")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" windows-classes.sun.securit_14_SRCS)
file(GLOB windows-classes.sun.securit_14_HEADERS *.h *.hpp)
source_group("Include" FILES ${windows-classes.sun.securit_14_HEADERS}) 
list(LENGTH windows-classes.sun.securit_14_SRCS windows-classes.sun.securit_14_SRCS_LENGTH)
if(windows-classes.sun.securit_14_SRCS_LENGTH)
	add_library(windows-classes.sun.securit_14 OBJECT "${windows-classes.sun.securit_14_SRCS}" "${windows-classes.sun.securit_14_HEADERS}")
	jcpp_enable_bigobj(windows-classes.sun.securit_14)
endif()