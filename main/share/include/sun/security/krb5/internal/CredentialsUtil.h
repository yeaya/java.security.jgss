#ifndef _sun_security_krb5_internal_CredentialsUtil_h_
#define _sun_security_krb5_internal_CredentialsUtil_h_
//$ class sun.security.krb5.internal.CredentialsUtil
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class CredentialsUtil$S4U2Type;
				class KDCOptions;
				class PAData;
				class Ticket;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import CredentialsUtil : public ::java::lang::Object {
	$class(CredentialsUtil, 0, ::java::lang::Object)
public:
	CredentialsUtil();
	void init$();
	static ::sun::security::krb5::Credentials* acquireS4U2proxyCreds($String* backend, ::sun::security::krb5::internal::Ticket* second, ::sun::security::krb5::PrincipalName* client, ::sun::security::krb5::Credentials* ccreds);
	static ::sun::security::krb5::Credentials* acquireS4U2selfCreds(::sun::security::krb5::PrincipalName* client, ::sun::security::krb5::Credentials* ccreds);
	static ::sun::security::krb5::Credentials* acquireServiceCreds($String* service, ::sun::security::krb5::Credentials* ccreds);
	static ::sun::security::krb5::Credentials* getTGTforRealm($String* localRealm, $String* serviceRealm, ::sun::security::krb5::Credentials* ccreds, $booleans* okAsDelegate);
	static $String* handleS4U2ProxyReferral(::sun::security::krb5::Credentials* asCreds, $Array<::sun::security::krb5::Credentials>* credsInOut, ::sun::security::krb5::PrincipalName* sname);
	static void handleS4U2SelfReferral($Array<::sun::security::krb5::internal::PAData>* pas, ::sun::security::krb5::Credentials* oldCeds, ::sun::security::krb5::Credentials* newCreds);
	static ::sun::security::krb5::Credentials* serviceCreds(::sun::security::krb5::PrincipalName* service, ::sun::security::krb5::Credentials* ccreds);
	static ::sun::security::krb5::Credentials* serviceCreds(::sun::security::krb5::internal::KDCOptions* options, ::sun::security::krb5::Credentials* asCreds, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* sname, $Array<::sun::security::krb5::internal::Ticket>* additionalTickets, $Array<::sun::security::krb5::internal::PAData>* extraPAs, ::sun::security::krb5::internal::CredentialsUtil$S4U2Type* s4u2Type);
	static ::sun::security::krb5::Credentials* serviceCredsReferrals(::sun::security::krb5::internal::KDCOptions* options, ::sun::security::krb5::Credentials* asCreds, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* sname, ::sun::security::krb5::internal::CredentialsUtil$S4U2Type* s4u2Type, $Array<::sun::security::krb5::internal::Ticket>* additionalTickets, $Array<::sun::security::krb5::internal::PAData>* extraPAs);
	static ::sun::security::krb5::Credentials* serviceCredsSingle(::sun::security::krb5::internal::KDCOptions* options, ::sun::security::krb5::Credentials* asCreds, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* clientAlias, ::sun::security::krb5::PrincipalName* refSname, ::sun::security::krb5::PrincipalName* sname, ::sun::security::krb5::internal::CredentialsUtil$S4U2Type* s4u2Type, $Array<::sun::security::krb5::internal::Ticket>* additionalTickets, $Array<::sun::security::krb5::internal::PAData>* extraPAs);
	static bool DEBUG;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_CredentialsUtil_h_