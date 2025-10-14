#ifndef _sun_security_jgss_wrapper_SunNativeProvider$1_h_
#define _sun_security_jgss_wrapper_SunNativeProvider$1_h_
//$ class sun.security.jgss.wrapper.SunNativeProvider$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

class SunNativeProvider$1 : public ::java::security::PrivilegedAction {
	$class(SunNativeProvider$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	SunNativeProvider$1();
	void init$();
	virtual $Object* run() override;
};

			} // wrapper
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_wrapper_SunNativeProvider$1_h_