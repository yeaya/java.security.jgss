#ifndef _sun_security_jgss_krb5_ServiceCreds_h_
#define _sun_security_jgss_krb5_ServiceCreds_h_
//$ class sun.security.jgss.krb5.ServiceCreds
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace util {
		class List;
		class Set;
	}
}
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
				class KerberosKey;
				class KerberosPrincipal;
				class KerberosTicket;
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
		namespace jgss {
			namespace krb5 {

class $import ServiceCreds : public ::java::lang::Object {
	$class(ServiceCreds, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ServiceCreds();
	void init$();
	void destroy();
	$Array<::sun::security::krb5::EncryptionKey>* getEKeys(::sun::security::krb5::PrincipalName* princ);
	::sun::security::krb5::Credentials* getInitCred();
	static ::sun::security::jgss::krb5::ServiceCreds* getInstance(::javax::security::auth::Subject* subj, $String* serverPrincipal);
	$Array<::javax::security::auth::kerberos::KerberosKey>* getKKeys();
	$Array<::javax::security::auth::kerberos::KerberosKey>* getKKeys(::javax::security::auth::kerberos::KerberosPrincipal* princ);
	$String* getName();
	::javax::security::auth::kerberos::KerberosPrincipal* kp = nullptr;
	::java::util::Set* allPrincs = nullptr;
	::java::util::List* ktabs = nullptr;
	::java::util::List* kk = nullptr;
	::javax::security::auth::kerberos::KerberosTicket* tgt = nullptr;
	bool destroyed = false;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_ServiceCreds_h_