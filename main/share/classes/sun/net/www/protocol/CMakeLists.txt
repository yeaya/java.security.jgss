#machine generated

add_subdirectory("http")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.net.www.protocol_SRCS)
file(GLOB classes.sun.net.www.protocol_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.net.www.protocol_HEADERS}) 
list(LENGTH classes.sun.net.www.protocol_SRCS classes.sun.net.www.protocol_SRCS_LENGTH)
if(classes.sun.net.www.protocol_SRCS_LENGTH)
	add_library(classes.sun.net.www.protocol OBJECT "${classes.sun.net.www.protocol_SRCS}" "${classes.sun.net.www.protocol_HEADERS}")
	jcpp_enable_bigobj(classes.sun.net.www.protocol)
endif()