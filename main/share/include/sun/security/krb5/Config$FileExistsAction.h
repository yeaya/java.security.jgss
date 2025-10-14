#ifndef _sun_security_krb5_Config$FileExistsAction_h_
#define _sun_security_krb5_Config$FileExistsAction_h_
//$ class sun.security.krb5.Config$FileExistsAction
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace security {
		namespace krb5 {

class $import Config$FileExistsAction : public ::java::security::PrivilegedAction {
	$class(Config$FileExistsAction, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Config$FileExistsAction();
	void init$($String* fileName);
	virtual $Object* run() override;
	$String* fileName = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_Config$FileExistsAction_h_