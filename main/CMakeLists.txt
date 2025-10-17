#machine generated

jcpp_add_dependencies(
	"java.base:17.35"
	"java.logging:17.35"
	"java.naming:17.35"
	"java.security.sasl:17.35"
)

include_directories("share/classes")
include_directories("share/native")

if(JCPP_OS MATCHES "linux")
	include_directories("linux/classes")
endif()

if(JCPP_OS MATCHES "macosx")
	include_directories("macosx/classes")
	include_directories("macosx/native")
endif()

if(JCPP_OS MATCHES "windows")
	include_directories("windows/classes")
endif()

add_subdirectory("share/classes")
add_subdirectory("share/native")

if(JCPP_OS MATCHES "linux")
	add_subdirectory("linux/classes")
endif()

if(JCPP_OS MATCHES "macosx")
	add_subdirectory("macosx/classes")
	add_subdirectory("macosx/native")
endif()

if(JCPP_OS MATCHES "windows")
	add_subdirectory("windows/classes")
endif()

set(local_object ${local_object}
	"$<TARGET_OBJECTS:classes.javax.security.auth._0>"
	"$<TARGET_OBJECTS:classes.org.ietf.jgss>"
	"$<TARGET_OBJECTS:classes.sun.net.www.protocol_2>"
	"$<TARGET_OBJECTS:classes.sun.security.jgss>"
	"$<TARGET_OBJECTS:classes.sun.security.jgss.krb5>"
	"$<TARGET_OBJECTS:classes.sun.security.jgss.kr_3>"
	"$<TARGET_OBJECTS:classes.sun.security.jgss.spi>"
	"$<TARGET_OBJECTS:classes.sun.security.jgss.sp_4>"
	"$<TARGET_OBJECTS:classes.sun.security.jgss.wr_5>"
	"$<TARGET_OBJECTS:classes.sun.security.krb5>"
	"$<TARGET_OBJECTS:classes.sun.security.krb5.in_6>"
	"$<TARGET_OBJECTS:classes.sun.security.krb5.in_7>"
	"$<TARGET_OBJECTS:classes.sun.security.krb5.in_8>"
	"$<TARGET_OBJECTS:classes.sun.security.krb5.in_9>"
	"$<TARGET_OBJECTS:classes.sun.security.krb5.i_10>"
	"$<TARGET_OBJECTS:classes.sun.security.krb5.i_11>"
	"$<TARGET_OBJECTS:classes.sun.security.krb5.i_12>"
	"$<TARGET_OBJECTS:native>"
)

if(JCPP_OS MATCHES "linux")
	set(local_object ${local_object}
		"$<TARGET_OBJECTS:linux-classes>"
	)
endif()

if(JCPP_OS MATCHES "macosx")
	set(local_object ${local_object}
		"$<TARGET_OBJECTS:macosx-classes>"
		"$<TARGET_OBJECTS:macosx-native>"
	)
endif()

if(JCPP_OS MATCHES "windows")
	set(local_object ${local_object}
		"$<TARGET_OBJECTS:windows-classes>"
		"$<TARGET_OBJECTS:windows-classes.sun.securit_15>"
	)
endif()

if(BUILD_STATIC_LIB)
	add_library(${JCPP_PROJECT_NAME}_static STATIC "${local_object}" "${source_SRCS}")

	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_static PROPERTIES OUTPUT_NAME "${JCPP_PROJECT_FULL_NAME}")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_static PROPERTIES VERSION ${JCPP_PROJECT_VERSION} SOVERSION 1)

	jcpp_enable_bigobj(${JCPP_PROJECT_NAME}_static)

	install(TARGETS ${JCPP_PROJECT_NAME}_static
		LIBRARY DESTINATION "${JCPP_INSTALL_LIB_DIR}"
		ARCHIVE DESTINATION "${JCPP_INSTALL_LIB_DIR}"
		RUNTIME DESTINATION "${JCPP_INSTALL_BIN_DIR}"
	)
endif()

if(BUILD_SHARED_LIB)
	add_library(${JCPP_PROJECT_NAME}_shared SHARED "${local_object}" "${source_SRCS}")

	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES OUTPUT_NAME "${JCPP_PROJECT_FULL_NAME}")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES VERSION ${JCPP_PROJECT_VERSION} SOVERSION 1)
if(JCPP_OS MATCHES "linux")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES INSTALL_RPATH "\\\$ORIGIN;\\\$ORIGIN/../lib")
elseif(JCPP_OS MATCHES "macosx")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES INSTALL_RPATH ".;../lib")
endif()

	if(JCPP_OS MATCHES "macosx")
		set(JCPP_EXT_LIBS ${JCPP_EXT_LIBS}
			-framework Cocoa -framework SystemConfiguration -framework Kerberos
		)
	endif()

	target_link_libraries(${JCPP_PROJECT_NAME}_shared
		PUBLIC ${JCPP_DEPENDENCY_LIBS}
		PRIVATE ${JCPP_EXT_LIBS}
	)

	jcpp_enable_bigobj(${JCPP_PROJECT_NAME}_shared)

	jcpp_enable_debug_info(${JCPP_PROJECT_NAME}_shared)

	install(TARGETS ${JCPP_PROJECT_NAME}_shared
		LIBRARY DESTINATION "${JCPP_INSTALL_LIB_DIR}"
		ARCHIVE DESTINATION "${JCPP_INSTALL_LIB_DIR}"
		RUNTIME DESTINATION "${JCPP_INSTALL_BIN_DIR}"
	)
endif()

install(
	DIRECTORY "share/include/"
	DESTINATION "${JCPP_INSTALL_INCLUDE_DIR}"
)

if(JCPP_OS MATCHES "windows")
	install(
		DIRECTORY "windows/include/"
		DESTINATION "${JCPP_INSTALL_INCLUDE_DIR}"
	)
endif()

if(INSTALL_TO_REPO)
	install(
		FILES "share/dependencies.txt"
		DESTINATION "${JCPP_INSTALL_DIR}"
	)
endif()
