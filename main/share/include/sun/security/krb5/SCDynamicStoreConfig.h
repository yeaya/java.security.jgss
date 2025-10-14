#ifndef _sun_security_krb5_SCDynamicStoreConfig_h_
#define _sun_security_krb5_SCDynamicStoreConfig_h_
//$ class sun.security.krb5.SCDynamicStoreConfig
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace util {
		class Hashtable;
		class List;
		class Vector;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import SCDynamicStoreConfig : public ::java::lang::Object {
	$class(SCDynamicStoreConfig, 0, ::java::lang::Object)
public:
	SCDynamicStoreConfig();
	void init$();
	static ::java::util::Hashtable* getConfig();
	static ::java::util::List* getKerberosConfig();
	static void installNotificationCallback();
	static ::java::util::Vector* v1($String* s);
	static bool DEBUG;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_SCDynamicStoreConfig_h_