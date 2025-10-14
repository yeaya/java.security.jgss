#machine generated

add_subdirectory("spnego")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.net.www.protocol_1_SRCS)
file(GLOB classes.sun.net.www.protocol_1_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.net.www.protocol_1_HEADERS}) 
list(LENGTH classes.sun.net.www.protocol_1_SRCS classes.sun.net.www.protocol_1_SRCS_LENGTH)
if(classes.sun.net.www.protocol_1_SRCS_LENGTH)
	add_library(classes.sun.net.www.protocol_1 OBJECT "${classes.sun.net.www.protocol_1_SRCS}" "${classes.sun.net.www.protocol_1_HEADERS}")
	jcpp_enable_bigobj(classes.sun.net.www.protocol_1)
endif()