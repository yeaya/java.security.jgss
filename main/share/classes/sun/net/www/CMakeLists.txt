#machine generated

add_subdirectory("protocol")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.net.www_SRCS)
file(GLOB classes.sun.net.www_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.net.www_HEADERS}) 
list(LENGTH classes.sun.net.www_SRCS classes.sun.net.www_SRCS_LENGTH)
if(classes.sun.net.www_SRCS_LENGTH)
	add_library(classes.sun.net.www OBJECT "${classes.sun.net.www_SRCS}" "${classes.sun.net.www_HEADERS}")
	jcpp_enable_bigobj(classes.sun.net.www)
endif()