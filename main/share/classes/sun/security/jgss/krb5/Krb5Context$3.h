#ifndef _sun_security_jgss_krb5_Krb5Context$3_h_
#define _sun_security_jgss_krb5_Krb5Context$3_h_
//$ class sun.security.jgss.krb5.Krb5Context$3
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace javax {
	namespace security {
		namespace auth {
			class Subject;
		}
	}
}
namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KerberosTicket;
			}
		}
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

class Krb5Context$3 : public ::java::security::PrivilegedAction {
	$class(Krb5Context$3, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Krb5Context$3();
	void init$(::sun::security::jgss::krb5::Krb5Context* this$0, ::javax::security::auth::Subject* val$subject, ::javax::security::auth::kerberos::KerberosTicket* val$kt);
	virtual $Object* run() override;
	::sun::security::jgss::krb5::Krb5Context* this$0 = nullptr;
	::javax::security::auth::kerberos::KerberosTicket* val$kt = nullptr;
	::javax::security::auth::Subject* val$subject = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5Context$3_h_