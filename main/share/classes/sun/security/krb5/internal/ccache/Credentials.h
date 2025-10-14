#ifndef _sun_security_krb5_internal_ccache_Credentials_h_
#define _sun_security_krb5_internal_ccache_Credentials_h_
//$ class sun.security.krb5.internal.ccache.Credentials
//$ extends java.lang.Object

#include <java/lang/Object.h>

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
				class AuthorizationData;
				class HostAddresses;
				class KDCRep;
				class KerberosTime;
				class Ticket;
				class TicketFlags;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

class Credentials : public ::java::lang::Object {
	$class(Credentials, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Credentials();
	void init$(::sun::security::krb5::PrincipalName* new_cname, ::sun::security::krb5::PrincipalName* new_sname, ::sun::security::krb5::EncryptionKey* new_key, ::sun::security::krb5::internal::KerberosTime* new_authtime, ::sun::security::krb5::internal::KerberosTime* new_starttime, ::sun::security::krb5::internal::KerberosTime* new_endtime, ::sun::security::krb5::internal::KerberosTime* new_renewTill, bool new_isEncInSKey, ::sun::security::krb5::internal::TicketFlags* new_flags, ::sun::security::krb5::internal::HostAddresses* new_caddr, ::sun::security::krb5::internal::AuthorizationData* new_authData, ::sun::security::krb5::internal::Ticket* new_ticket, ::sun::security::krb5::internal::Ticket* new_secondTicket);
	void init$(::sun::security::krb5::internal::KDCRep* kdcRep, ::sun::security::krb5::internal::Ticket* new_secondTicket, ::sun::security::krb5::internal::AuthorizationData* new_authorizationData, bool new_isEncInSKey);
	void init$(::sun::security::krb5::internal::KDCRep* kdcRep);
	void init$(::sun::security::krb5::internal::KDCRep* kdcRep, ::sun::security::krb5::internal::Ticket* new_ticket);
	virtual ::sun::security::krb5::internal::KerberosTime* getAuthTime();
	virtual ::sun::security::krb5::PrincipalName* getClientPrincipal();
	virtual int32_t getEType();
	virtual ::sun::security::krb5::internal::KerberosTime* getEndTime();
	virtual ::sun::security::krb5::EncryptionKey* getKey();
	virtual ::sun::security::krb5::internal::KerberosTime* getRenewTill();
	virtual ::sun::security::krb5::PrincipalName* getServicePrincipal();
	virtual ::sun::security::krb5::PrincipalName* getServicePrincipal2();
	virtual ::sun::security::krb5::internal::KerberosTime* getStartTime();
	virtual ::sun::security::krb5::internal::Ticket* getTicket();
	virtual ::sun::security::krb5::internal::TicketFlags* getTicketFlags();
	virtual int32_t getTktEType();
	virtual int32_t getTktEType2();
	virtual bool isValid();
	virtual ::sun::security::krb5::Credentials* setKrbCreds();
	::sun::security::krb5::PrincipalName* cname = nullptr;
	::sun::security::krb5::PrincipalName* sname = nullptr;
	::sun::security::krb5::EncryptionKey* key = nullptr;
	::sun::security::krb5::internal::KerberosTime* authtime = nullptr;
	::sun::security::krb5::internal::KerberosTime* starttime = nullptr;
	::sun::security::krb5::internal::KerberosTime* endtime = nullptr;
	::sun::security::krb5::internal::KerberosTime* renewTill = nullptr;
	::sun::security::krb5::internal::HostAddresses* caddr = nullptr;
	::sun::security::krb5::internal::AuthorizationData* authorizationData = nullptr;
	bool isEncInSKey = false;
	::sun::security::krb5::internal::TicketFlags* flags = nullptr;
	::sun::security::krb5::internal::Ticket* ticket = nullptr;
	::sun::security::krb5::internal::Ticket* secondTicket = nullptr;
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ccache_Credentials_h_