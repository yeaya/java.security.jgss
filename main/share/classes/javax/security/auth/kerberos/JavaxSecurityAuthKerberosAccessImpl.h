#ifndef _javax_security_auth_kerberos_JavaxSecurityAuthKerberosAccessImpl_h_
#define _javax_security_auth_kerberos_JavaxSecurityAuthKerberosAccessImpl_h_
//$ class javax.security.auth.kerberos.JavaxSecurityAuthKerberosAccessImpl
//$ extends sun.security.krb5.JavaxSecurityAuthKerberosAccess

#include <sun/security/krb5/JavaxSecurityAuthKerberosAccess.h>

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

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class JavaxSecurityAuthKerberosAccessImpl : public ::sun::security::krb5::JavaxSecurityAuthKerberosAccess {
	$class(JavaxSecurityAuthKerberosAccessImpl, $NO_CLASS_INIT, ::sun::security::krb5::JavaxSecurityAuthKerberosAccess)
public:
	JavaxSecurityAuthKerberosAccessImpl();
	void init$();
	virtual ::javax::security::auth::kerberos::KerberosPrincipal* kerberosTicketGetClientAlias(::javax::security::auth::kerberos::KerberosTicket* t) override;
	virtual ::javax::security::auth::kerberos::KerberosTicket* kerberosTicketGetProxy(::javax::security::auth::kerberos::KerberosTicket* t) override;
	virtual ::javax::security::auth::kerberos::KerberosPrincipal* kerberosTicketGetServerAlias(::javax::security::auth::kerberos::KerberosTicket* t) override;
	virtual void kerberosTicketSetClientAlias(::javax::security::auth::kerberos::KerberosTicket* t, ::javax::security::auth::kerberos::KerberosPrincipal* a) override;
	virtual void kerberosTicketSetProxy(::javax::security::auth::kerberos::KerberosTicket* t, ::javax::security::auth::kerberos::KerberosTicket* p) override;
	virtual void kerberosTicketSetServerAlias(::javax::security::auth::kerberos::KerberosTicket* t, ::javax::security::auth::kerberos::KerberosPrincipal* a) override;
	virtual ::sun::security::krb5::internal::ktab::KeyTab* keyTabTakeSnapshot(::javax::security::auth::kerberos::KeyTab* ktab) override;
};

			} // kerberos
		} // auth
	} // security
} // javax

#endif // _javax_security_auth_kerberos_JavaxSecurityAuthKerberosAccessImpl_h_