#machine generated

add_subdirectory("www")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.net_SRCS)
file(GLOB classes.sun.net_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.net_HEADERS}) 
list(LENGTH classes.sun.net_SRCS classes.sun.net_SRCS_LENGTH)
if(classes.sun.net_SRCS_LENGTH)
	add_library(classes.sun.net OBJECT "${classes.sun.net_SRCS}" "${classes.sun.net_HEADERS}")
	jcpp_enable_bigobj(classes.sun.net)
endif()