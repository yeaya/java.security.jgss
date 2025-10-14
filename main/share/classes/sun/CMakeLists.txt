#machine generated

add_subdirectory("net")
add_subdirectory("security")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun_SRCS)
file(GLOB classes.sun_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun_HEADERS}) 
list(LENGTH classes.sun_SRCS classes.sun_SRCS_LENGTH)
if(classes.sun_SRCS_LENGTH)
	add_library(classes.sun OBJECT "${classes.sun_SRCS}" "${classes.sun_HEADERS}")
	jcpp_enable_bigobj(classes.sun)
endif()