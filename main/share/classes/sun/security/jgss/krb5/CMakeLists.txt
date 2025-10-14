#machine generated

add_subdirectory("internal")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.security.jgss.krb5_SRCS)
file(GLOB classes.sun.security.jgss.krb5_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.security.jgss.krb5_HEADERS}) 
list(LENGTH classes.sun.security.jgss.krb5_SRCS classes.sun.security.jgss.krb5_SRCS_LENGTH)
if(classes.sun.security.jgss.krb5_SRCS_LENGTH)
	add_library(classes.sun.security.jgss.krb5 OBJECT "${classes.sun.security.jgss.krb5_SRCS}" "${classes.sun.security.jgss.krb5_HEADERS}")
	jcpp_enable_bigobj(classes.sun.security.jgss.krb5)
endif()