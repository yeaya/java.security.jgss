#machine generated

add_subdirectory("kerberos")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.security.auth_SRCS)
file(GLOB classes.javax.security.auth_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.security.auth_HEADERS}) 
list(LENGTH classes.javax.security.auth_SRCS classes.javax.security.auth_SRCS_LENGTH)
if(classes.javax.security.auth_SRCS_LENGTH)
	add_library(classes.javax.security.auth OBJECT "${classes.javax.security.auth_SRCS}" "${classes.javax.security.auth_HEADERS}")
	jcpp_enable_bigobj(classes.javax.security.auth)
endif()