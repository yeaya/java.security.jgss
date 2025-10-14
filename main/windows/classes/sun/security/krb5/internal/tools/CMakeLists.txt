#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" windows-classes.sun.securit_15_SRCS)
file(GLOB windows-classes.sun.securit_15_HEADERS *.h *.hpp)
source_group("Include" FILES ${windows-classes.sun.securit_15_HEADERS}) 
list(LENGTH windows-classes.sun.securit_15_SRCS windows-classes.sun.securit_15_SRCS_LENGTH)
if(windows-classes.sun.securit_15_SRCS_LENGTH)
	add_library(windows-classes.sun.securit_15 OBJECT "${windows-classes.sun.securit_15_SRCS}" "${windows-classes.sun.securit_15_HEADERS}")
	jcpp_enable_bigobj(windows-classes.sun.securit_15)
endif()