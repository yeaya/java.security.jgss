#ifndef _sun_security_krb5_internal_EncTGSRepPart_h_
#define _sun_security_krb5_internal_EncTGSRepPart_h_
//$ class sun.security.krb5.internal.EncTGSRepPart
//$ extends sun.security.krb5.internal.EncKDCRepPart

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/EncKDCRepPart.h>

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

class $export EncTGSRepPart : public ::sun::security::krb5::internal::EncKDCRepPart {
	$class(EncTGSRepPart, $NO_CLASS_INIT, ::sun::security::krb5::internal::EncKDCRepPart)
public:
	EncTGSRepPart();
	using ::sun::security::krb5::internal::EncKDCRepPart::init;
	using ::sun::security::krb5::internal::EncKDCRepPart::asn1Encode;
	void init$(::sun::security::krb5::EncryptionKey* new_key, ::sun::security::krb5::internal::LastReq* new_lastReq, int32_t new_nonce, ::sun::security::krb5::internal::KerberosTime* new_keyExpiration, ::sun::security::krb5::internal::TicketFlags* new_flags, ::sun::security::krb5::internal::KerberosTime* new_authtime, ::sun::security::krb5::internal::KerberosTime* new_starttime, ::sun::security::krb5::internal::KerberosTime* new_endtime, ::sun::security::krb5::internal::KerberosTime* new_renewTill, ::sun::security::krb5::PrincipalName* new_sname, ::sun::security::krb5::internal::HostAddresses* new_caddr, $Array<::sun::security::krb5::internal::PAData>* new_pAData);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	void init(::sun::security::util::DerValue* encoding);
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_EncTGSRepPart_h_