#ifndef _sun_security_krb5_KrbTgsReq_h_
#define _sun_security_krb5_KrbTgsReq_h_
//$ class sun.security.krb5.KrbTgsReq
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class EncryptionKey;
			class KrbTgsRep;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class AuthorizationData;
				class HostAddresses;
				class KDCOptions;
				class KerberosTime;
				class PAData;
				class TGSReq;
				class Ticket;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $export KrbTgsReq : public ::java::lang::Object {
	$class(KrbTgsReq, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KrbTgsReq();
	void init$(::sun::security::krb5::internal::KDCOptions* options, ::sun::security::krb5::Credentials* asCreds, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* clientAlias, ::sun::security::krb5::PrincipalName* sname, ::sun::security::krb5::PrincipalName* serverAlias, $Array<::sun::security::krb5::internal::Ticket>* additionalTickets, $Array<::sun::security::krb5::internal::PAData>* extraPAs);
	void init$(::sun::security::krb5::internal::KDCOptions* options, ::sun::security::krb5::Credentials* asCreds, ::sun::security::krb5::PrincipalName* sname, ::sun::security::krb5::PrincipalName* serverAlias, ::sun::security::krb5::internal::KerberosTime* from, ::sun::security::krb5::internal::KerberosTime* till, ::sun::security::krb5::internal::KerberosTime* rtime, $ints* eTypes, ::sun::security::krb5::internal::HostAddresses* addresses, ::sun::security::krb5::internal::AuthorizationData* authorizationData, $Array<::sun::security::krb5::internal::Ticket>* additionalTickets, ::sun::security::krb5::EncryptionKey* subKey);
	void init$(::sun::security::krb5::internal::KDCOptions* options, ::sun::security::krb5::Credentials* asCreds, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* clientAlias, ::sun::security::krb5::PrincipalName* sname, ::sun::security::krb5::PrincipalName* serverAlias, ::sun::security::krb5::internal::KerberosTime* from, ::sun::security::krb5::internal::KerberosTime* till, ::sun::security::krb5::internal::KerberosTime* rtime, $ints* eTypes, ::sun::security::krb5::internal::HostAddresses* addresses, ::sun::security::krb5::internal::AuthorizationData* authorizationData, $Array<::sun::security::krb5::internal::Ticket>* additionalTickets, ::sun::security::krb5::EncryptionKey* subKey, $Array<::sun::security::krb5::internal::PAData>* extraPAs);
	::sun::security::krb5::internal::TGSReq* createRequest(::sun::security::krb5::internal::KDCOptions* kdc_options, ::sun::security::krb5::internal::Ticket* ticket, ::sun::security::krb5::EncryptionKey* key, ::sun::security::krb5::internal::KerberosTime* ctime, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* sname, ::sun::security::krb5::internal::KerberosTime* from, ::sun::security::krb5::internal::KerberosTime* till, ::sun::security::krb5::internal::KerberosTime* rtime, $ints* eTypes, ::sun::security::krb5::internal::HostAddresses* addresses, ::sun::security::krb5::internal::AuthorizationData* authorizationData, $Array<::sun::security::krb5::internal::Ticket>* additionalTickets, ::sun::security::krb5::EncryptionKey* subKey, $Array<::sun::security::krb5::internal::PAData>* extraPAs);
	static void debug($String* message);
	virtual ::sun::security::krb5::PrincipalName* getClientAlias();
	virtual ::sun::security::krb5::internal::KerberosTime* getCtime();
	virtual ::sun::security::krb5::internal::TGSReq* getMessage();
	virtual ::sun::security::krb5::KrbTgsRep* getReply();
	virtual ::sun::security::krb5::internal::Ticket* getSecondTicket();
	virtual ::sun::security::krb5::PrincipalName* getServerAlias();
	virtual void send();
	virtual ::sun::security::krb5::Credentials* sendAndGetCreds();
	virtual bool usedSubkey();
	::sun::security::krb5::PrincipalName* princName = nullptr;
	::sun::security::krb5::PrincipalName* clientAlias = nullptr;
	::sun::security::krb5::PrincipalName* servName = nullptr;
	::sun::security::krb5::PrincipalName* serverAlias = nullptr;
	::sun::security::krb5::internal::TGSReq* tgsReqMessg = nullptr;
	::sun::security::krb5::internal::KerberosTime* ctime = nullptr;
	::sun::security::krb5::internal::Ticket* secondTicket = nullptr;
	bool useSubkey = false;
	::sun::security::krb5::EncryptionKey* tgsReqKey = nullptr;
	$bytes* obuf = nullptr;
	$bytes* ibuf = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbTgsReq_h_