#machine generated

add_subdirectory("security")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" windows-classes.sun_SRCS)
file(GLOB windows-classes.sun_HEADERS *.h *.hpp)
source_group("Include" FILES ${windows-classes.sun_HEADERS}) 
list(LENGTH windows-classes.sun_SRCS windows-classes.sun_SRCS_LENGTH)
if(windows-classes.sun_SRCS_LENGTH)
	add_library(windows-classes.sun OBJECT "${windows-classes.sun_SRCS}" "${windows-classes.sun_HEADERS}")
	jcpp_enable_bigobj(windows-classes.sun)
endif()