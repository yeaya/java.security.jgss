#machine generated

add_subdirectory("ccache")
add_subdirectory("crypto")
add_subdirectory("ktab")
add_subdirectory("rcache")
add_subdirectory("util")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.security.krb5.in_6_SRCS)
file(GLOB classes.sun.security.krb5.in_6_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.security.krb5.in_6_HEADERS}) 
list(LENGTH classes.sun.security.krb5.in_6_SRCS classes.sun.security.krb5.in_6_SRCS_LENGTH)
if(classes.sun.security.krb5.in_6_SRCS_LENGTH)
	add_library(classes.sun.security.krb5.in_6 OBJECT "${classes.sun.security.krb5.in_6_SRCS}" "${classes.sun.security.krb5.in_6_HEADERS}")
	jcpp_enable_bigobj(classes.sun.security.krb5.in_6)
endif()