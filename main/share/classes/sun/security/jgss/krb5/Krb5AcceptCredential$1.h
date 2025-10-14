#ifndef _sun_security_jgss_krb5_Krb5AcceptCredential$1_h_
#define _sun_security_jgss_krb5_Krb5AcceptCredential$1_h_
//$ class sun.security.jgss.krb5.Krb5AcceptCredential$1
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			class GSSCaller;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class Krb5AcceptCredential$1 : public ::java::security::PrivilegedExceptionAction {
	$class(Krb5AcceptCredential$1, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	Krb5AcceptCredential$1();
	void init$(::sun::security::jgss::GSSCaller* val$caller, $String* val$serverPrinc, ::java::security::AccessControlContext* val$acc);
	virtual $Object* run() override;
	::java::security::AccessControlContext* val$acc = nullptr;
	$String* val$serverPrinc = nullptr;
	::sun::security::jgss::GSSCaller* val$caller = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5AcceptCredential$1_h_