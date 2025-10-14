#ifndef _sun_security_jgss_LoginConfigImpl$1_h_
#define _sun_security_jgss_LoginConfigImpl$1_h_
//$ class sun.security.jgss.LoginConfigImpl$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace security {
		namespace jgss {
			class LoginConfigImpl;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class LoginConfigImpl$1 : public ::java::security::PrivilegedAction {
	$class(LoginConfigImpl$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	LoginConfigImpl$1();
	void init$(::sun::security::jgss::LoginConfigImpl* this$0);
	virtual $Object* run() override;
	::sun::security::jgss::LoginConfigImpl* this$0 = nullptr;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_LoginConfigImpl$1_h_