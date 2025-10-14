#machine generated

add_subdirectory("auth")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.security_SRCS)
file(GLOB classes.javax.security_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.security_HEADERS}) 
list(LENGTH classes.javax.security_SRCS classes.javax.security_SRCS_LENGTH)
if(classes.javax.security_SRCS_LENGTH)
	add_library(classes.javax.security OBJECT "${classes.javax.security_SRCS}" "${classes.javax.security_HEADERS}")
	jcpp_enable_bigobj(classes.javax.security)
endif()