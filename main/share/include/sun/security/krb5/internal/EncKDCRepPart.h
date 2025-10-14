#ifndef _sun_security_krb5_internal_EncKDCRepPart_h_
#define _sun_security_krb5_internal_EncKDCRepPart_h_
//$ class sun.security.krb5.internal.EncKDCRepPart
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class HostAddresses;
				class KerberosTime;
				class LastReq;
				class PAData;
				class TicketFlags;
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

class $import EncKDCRepPart : public ::java::lang::Object {
	$class(EncKDCRepPart, $NO_CLASS_INIT, ::java::lang::Object)
public:
	EncKDCRepPart();
	void init$(::sun::security::krb5::EncryptionKey* new_key, ::sun::security::krb5::internal::LastReq* new_lastReq, int32_t new_nonce, ::sun::security::krb5::internal::KerberosTime* new_keyExpiration, ::sun::security::krb5::internal::TicketFlags* new_flags, ::sun::security::krb5::internal::KerberosTime* new_authtime, ::sun::security::krb5::internal::KerberosTime* new_starttime, ::sun::security::krb5::internal::KerberosTime* new_endtime, ::sun::security::krb5::internal::KerberosTime* new_renewTill, ::sun::security::krb5::PrincipalName* new_sname, ::sun::security::krb5::internal::HostAddresses* new_caddr, $Array<::sun::security::krb5::internal::PAData>* new_pAData, int32_t new_msgType);
	void init$();
	void init$($bytes* data, int32_t rep_type);
	void init$(::sun::security::util::DerValue* encoding, int32_t rep_type);
	virtual $bytes* asn1Encode(int32_t rep_type);
	virtual void init(::sun::security::util::DerValue* encoding, int32_t rep_type);
	::sun::security::krb5::EncryptionKey* key = nullptr;
	::sun::security::krb5::internal::LastReq* lastReq = nullptr;
	int32_t nonce = 0;
	::sun::security::krb5::internal::KerberosTime* keyExpiration = nullptr;
	::sun::security::krb5::internal::TicketFlags* flags = nullptr;
	::sun::security::krb5::internal::KerberosTime* authtime = nullptr;
	::sun::security::krb5::internal::KerberosTime* starttime = nullptr;
	::sun::security::krb5::internal::KerberosTime* endtime = nullptr;
	::sun::security::krb5::internal::KerberosTime* renewTill = nullptr;
	::sun::security::krb5::PrincipalName* sname = nullptr;
	::sun::security::krb5::internal::HostAddresses* caddr = nullptr;
	$Array<::sun::security::krb5::internal::PAData>* pAData = nullptr;
	int32_t msgType = 0;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_EncKDCRepPart_h_