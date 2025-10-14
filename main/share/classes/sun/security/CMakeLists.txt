#machine generated

add_subdirectory("jgss")
add_subdirectory("krb5")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.security_SRCS)
file(GLOB classes.sun.security_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.security_HEADERS}) 
list(LENGTH classes.sun.security_SRCS classes.sun.security_SRCS_LENGTH)
if(classes.sun.security_SRCS_LENGTH)
	add_library(classes.sun.security OBJECT "${classes.sun.security_SRCS}" "${classes.sun.security_HEADERS}")
	jcpp_enable_bigobj(classes.sun.security)
endif()