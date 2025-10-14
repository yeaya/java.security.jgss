#ifndef _sun_security_jgss_krb5_Krb5Context$1_h_
#define _sun_security_jgss_krb5_Krb5Context$1_h_
//$ class sun.security.jgss.krb5.Krb5Context$1
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
			namespace krb5 {
				class Krb5Context;
				class Krb5ProxyCredential;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class Krb5Context$1 : public ::java::security::PrivilegedExceptionAction {
	$class(Krb5Context$1, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	Krb5Context$1();
	void init$(::sun::security::jgss::krb5::Krb5Context* this$0, ::sun::security::jgss::krb5::Krb5ProxyCredential* val$second, ::java::security::AccessControlContext* val$acc);
	virtual $Object* run() override;
	::sun::security::jgss::krb5::Krb5Context* this$0 = nullptr;
	::java::security::AccessControlContext* val$acc = nullptr;
	::sun::security::jgss::krb5::Krb5ProxyCredential* val$second = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5Context$1_h_