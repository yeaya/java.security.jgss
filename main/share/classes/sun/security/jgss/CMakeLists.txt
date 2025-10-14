#machine generated

add_subdirectory("krb5")
add_subdirectory("spi")
add_subdirectory("spnego")
add_subdirectory("wrapper")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.security.jgss_SRCS)
file(GLOB classes.sun.security.jgss_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.security.jgss_HEADERS}) 
list(LENGTH classes.sun.security.jgss_SRCS classes.sun.security.jgss_SRCS_LENGTH)
if(classes.sun.security.jgss_SRCS_LENGTH)
	add_library(classes.sun.security.jgss OBJECT "${classes.sun.security.jgss_SRCS}" "${classes.sun.security.jgss_HEADERS}")
	jcpp_enable_bigobj(classes.sun.security.jgss)
endif()