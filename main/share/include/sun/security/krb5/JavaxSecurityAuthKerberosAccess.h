#ifndef _sun_security_krb5_JavaxSecurityAuthKerberosAccess_h_
#define _sun_security_krb5_JavaxSecurityAuthKerberosAccess_h_
//$ interface sun.security.krb5.JavaxSecurityAuthKerberosAccess
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KerberosPrincipal;
				class KerberosTicket;
				class KeyTab;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {
					class KeyTab;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import JavaxSecurityAuthKerberosAccess : public ::java::lang::Object {
	$interface(JavaxSecurityAuthKerberosAccess, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::javax::security::auth::kerberos::KerberosPrincipal* kerberosTicketGetClientAlias(::javax::security::auth::kerberos::KerberosTicket* t) {return nullptr;}
	virtual ::javax::security::auth::kerberos::KerberosTicket* kerberosTicketGetProxy(::javax::security::auth::kerberos::KerberosTicket* t) {return nullptr;}
	virtual ::javax::security::auth::kerberos::KerberosPrincipal* kerberosTicketGetServerAlias(::javax::security::auth::kerberos::KerberosTicket* t) {return nullptr;}
	virtual void kerberosTicketSetClientAlias(::javax::security::auth::kerberos::KerberosTicket* t, ::javax::security::auth::kerberos::KerberosPrincipal* a) {}
	virtual void kerberosTicketSetProxy(::javax::security::auth::kerberos::KerberosTicket* t, ::javax::security::auth::kerberos::KerberosTicket* p) {}
	virtual void kerberosTicketSetServerAlias(::javax::security::auth::kerberos::KerberosTicket* t, ::javax::security::auth::kerberos::KerberosPrincipal* a) {}
	virtual ::sun::security::krb5::internal::ktab::KeyTab* keyTabTakeSnapshot(::javax::security::auth::kerberos::KeyTab* ktab) {return nullptr;}
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_JavaxSecurityAuthKerberosAccess_h_