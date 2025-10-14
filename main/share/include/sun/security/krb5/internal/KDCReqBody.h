#ifndef _sun_security_krb5_internal_KDCReqBody_h_
#define _sun_security_krb5_internal_KDCReqBody_h_
//$ class sun.security.krb5.internal.KDCReqBody
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptedData;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class HostAddresses;
				class KDCOptions;
				class KerberosTime;
				class Ticket;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import KDCReqBody : public ::java::lang::Object {
	$class(KDCReqBody, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KDCReqBody();
	void init$(::sun::security::krb5::internal::KDCOptions* new_kdcOptions, ::sun::security::krb5::PrincipalName* new_cname, ::sun::security::krb5::PrincipalName* new_sname, ::sun::security::krb5::internal::KerberosTime* new_from, ::sun::security::krb5::internal::KerberosTime* new_till, ::sun::security::krb5::internal::KerberosTime* new_rtime, int32_t new_nonce, $ints* new_eType, ::sun::security::krb5::internal::HostAddresses* new_addresses, ::sun::security::krb5::EncryptedData* new_encAuthorizationData, $Array<::sun::security::krb5::internal::Ticket>* new_additionalTickets);
	void init$(::sun::security::util::DerValue* encoding, int32_t msgType);
	virtual $bytes* asn1Encode(int32_t msgType);
	virtual int32_t getNonce();
	::sun::security::krb5::internal::KDCOptions* kdcOptions = nullptr;
	::sun::security::krb5::PrincipalName* cname = nullptr;
	::sun::security::krb5::PrincipalName* sname = nullptr;
	::sun::security::krb5::internal::KerberosTime* from = nullptr;
	::sun::security::krb5::internal::KerberosTime* till = nullptr;
	::sun::security::krb5::internal::KerberosTime* rtime = nullptr;
	::sun::security::krb5::internal::HostAddresses* addresses = nullptr;
	int32_t nonce = 0;
	$ints* eType = nullptr;
	::sun::security::krb5::EncryptedData* encAuthorizationData = nullptr;
	$Array<::sun::security::krb5::internal::Ticket>* additionalTickets = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_KDCReqBody_h_