#ifndef _sun_security_jgss_krb5_Krb5Util_h_
#define _sun_security_jgss_krb5_Krb5Util_h_
//$ class sun.security.jgss.krb5.Krb5Util
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KerberosTicket;
				class KeyTab;
			}
		}
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
				class ServiceCreds;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class EncryptionKey;
			class PrincipalName;
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
		namespace jgss {
			namespace krb5 {

class $export Krb5Util : public ::java::lang::Object {
	$class(Krb5Util, 0, ::java::lang::Object)
public:
	Krb5Util();
	void init$();
	static ::javax::security::auth::kerberos::KerberosTicket* credsToTicket(::sun::security::krb5::Credentials* serviceCreds);
	static ::javax::security::auth::kerberos::KerberosTicket* getInitialTicket(::sun::security::jgss::GSSCaller* caller, $String* clientPrincipal, ::java::security::AccessControlContext* acc);
	static ::sun::security::jgss::krb5::ServiceCreds* getServiceCreds(::sun::security::jgss::GSSCaller* caller, $String* serverPrincipal, ::java::security::AccessControlContext* acc);
	static ::javax::security::auth::kerberos::KerberosTicket* getServiceTicket(::sun::security::jgss::GSSCaller* caller, $String* clientPrincipal, $String* serverPrincipal, ::java::security::AccessControlContext* acc);
	static $Array<::sun::security::krb5::EncryptionKey>* keysFromJavaxKeyTab(::javax::security::auth::kerberos::KeyTab* ktab, ::sun::security::krb5::PrincipalName* cname);
	static ::sun::security::krb5::internal::ktab::KeyTab* snapshotFromJavaxKeyTab(::javax::security::auth::kerberos::KeyTab* ktab);
	static ::sun::security::krb5::Credentials* ticketToCreds(::javax::security::auth::kerberos::KerberosTicket* kerbTicket);
	static bool DEBUG;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_jgss_krb5_Krb5Util_h_