#machine generated

add_subdirectory("dk")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.security.krb5.in_8_SRCS)
file(GLOB classes.sun.security.krb5.in_8_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.security.krb5.in_8_HEADERS}) 
list(LENGTH classes.sun.security.krb5.in_8_SRCS classes.sun.security.krb5.in_8_SRCS_LENGTH)
if(classes.sun.security.krb5.in_8_SRCS_LENGTH)
	add_library(classes.sun.security.krb5.in_8 OBJECT "${classes.sun.security.krb5.in_8_SRCS}" "${classes.sun.security.krb5.in_8_HEADERS}")
	jcpp_enable_bigobj(classes.sun.security.krb5.in_8)
endif()