#machine generated

add_subdirectory("jgss")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.org.ietf_SRCS)
file(GLOB classes.org.ietf_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.org.ietf_HEADERS}) 
list(LENGTH classes.org.ietf_SRCS classes.org.ietf_SRCS_LENGTH)
if(classes.org.ietf_SRCS_LENGTH)
	add_library(classes.org.ietf OBJECT "${classes.org.ietf_SRCS}" "${classes.org.ietf_HEADERS}")
	jcpp_enable_bigobj(classes.org.ietf)
endif()