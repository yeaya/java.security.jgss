#ifndef _sun_security_krb5_Credentials$1_h_
#define _sun_security_krb5_Credentials$1_h_
//$ class sun.security.krb5.Credentials$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace security {
		namespace krb5 {

class Credentials$1 : public ::java::security::PrivilegedAction {
	$class(Credentials$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Credentials$1();
	void init$();
	virtual $Object* run() override;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_Credentials$1_h_