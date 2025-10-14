#ifndef _sun_security_jgss_krb5_Krb5Context$2_h_
#define _sun_security_jgss_krb5_Krb5Context$2_h_
//$ class sun.security.jgss.krb5.Krb5Context$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

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
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class Krb5Context$2 : public ::java::security::PrivilegedAction {
	$class(Krb5Context$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Krb5Context$2();
	void init$(::sun::security::jgss::krb5::Krb5Context* this$0, ::java::security::AccessControlContext* val$acc);
	virtual $Object* run() override;
	::sun::security::jgss::krb5::Krb5Context* this$0 = nullptr;
	::java::security::AccessControlContext* val$acc = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5Context$2_h_