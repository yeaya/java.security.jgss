#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.security.krb5.in_7_SRCS)
file(GLOB classes.sun.security.krb5.in_7_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.security.krb5.in_7_HEADERS}) 
list(LENGTH classes.sun.security.krb5.in_7_SRCS classes.sun.security.krb5.in_7_SRCS_LENGTH)
if(classes.sun.security.krb5.in_7_SRCS_LENGTH)
	add_library(classes.sun.security.krb5.in_7 OBJECT "${classes.sun.security.krb5.in_7_SRCS}" "${classes.sun.security.krb5.in_7_HEADERS}")
	jcpp_enable_bigobj(classes.sun.security.krb5.in_7)
endif()