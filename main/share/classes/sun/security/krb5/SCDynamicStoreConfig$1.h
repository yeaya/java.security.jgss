#ifndef _sun_security_krb5_SCDynamicStoreConfig$1_h_
#define _sun_security_krb5_SCDynamicStoreConfig$1_h_
//$ class sun.security.krb5.SCDynamicStoreConfig$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace security {
		namespace krb5 {

class SCDynamicStoreConfig$1 : public ::java::security::PrivilegedAction {
	$class(SCDynamicStoreConfig$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	SCDynamicStoreConfig$1();
	void init$();
	virtual $Object* run() override;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_SCDynamicStoreConfig$1_h_