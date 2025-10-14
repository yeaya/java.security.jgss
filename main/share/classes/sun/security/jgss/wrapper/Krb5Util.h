#ifndef _sun_security_jgss_wrapper_Krb5Util_h_
#define _sun_security_jgss_wrapper_Krb5Util_h_
//$ class sun.security.jgss.wrapper.Krb5Util
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {
				class GSSNameElement;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

class Krb5Util : public ::java::lang::Object {
	$class(Krb5Util, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Krb5Util();
	void init$();
	static void checkServicePermission($String* target, $String* action);
	static $String* getTGSName(::sun::security::jgss::wrapper::GSSNameElement* name);
};

			} // wrapper
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_wrapper_Krb5Util_h_