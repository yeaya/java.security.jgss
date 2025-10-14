#ifndef _sun_security_jgss_SunProvider$1_h_
#define _sun_security_jgss_SunProvider$1_h_
//$ class sun.security.jgss.SunProvider$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace security {
		class Provider;
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			class SunProvider;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class SunProvider$1 : public ::java::security::PrivilegedAction {
	$class(SunProvider$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	SunProvider$1();
	void init$(::sun::security::jgss::SunProvider* this$0, ::java::security::Provider* val$p);
	virtual $Object* run() override;
	::sun::security::jgss::SunProvider* this$0 = nullptr;
	::java::security::Provider* val$p = nullptr;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_SunProvider$1_h_