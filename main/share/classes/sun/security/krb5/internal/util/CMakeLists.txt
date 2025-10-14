#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.security.krb5.i_12_SRCS)
file(GLOB classes.sun.security.krb5.i_12_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.security.krb5.i_12_HEADERS}) 
list(LENGTH classes.sun.security.krb5.i_12_SRCS classes.sun.security.krb5.i_12_SRCS_LENGTH)
if(classes.sun.security.krb5.i_12_SRCS_LENGTH)
	add_library(classes.sun.security.krb5.i_12 OBJECT "${classes.sun.security.krb5.i_12_SRCS}" "${classes.sun.security.krb5.i_12_HEADERS}")
	jcpp_enable_bigobj(classes.sun.security.krb5.i_12)
endif()