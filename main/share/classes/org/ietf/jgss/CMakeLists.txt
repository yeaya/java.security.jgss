#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.org.ietf.jgss_SRCS)
file(GLOB classes.org.ietf.jgss_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.org.ietf.jgss_HEADERS}) 
list(LENGTH classes.org.ietf.jgss_SRCS classes.org.ietf.jgss_SRCS_LENGTH)
if(classes.org.ietf.jgss_SRCS_LENGTH)
	add_library(classes.org.ietf.jgss OBJECT "${classes.org.ietf.jgss_SRCS}" "${classes.org.ietf.jgss_HEADERS}")
	jcpp_enable_bigobj(classes.org.ietf.jgss)
endif()