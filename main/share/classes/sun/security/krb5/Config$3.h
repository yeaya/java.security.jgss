#ifndef _sun_security_krb5_Config$3_h_
#define _sun_security_krb5_Config$3_h_
//$ class sun.security.krb5.Config$3
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class Config;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class Config$3 : public ::java::security::PrivilegedAction {
	$class(Config$3, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Config$3();
	void init$(::sun::security::krb5::Config* this$0);
	virtual $Object* run() override;
	::sun::security::krb5::Config* this$0 = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_Config$3_h_