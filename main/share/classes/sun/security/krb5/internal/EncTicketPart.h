#ifndef _sun_security_krb5_internal_EncTicketPart_h_
#define _sun_security_krb5_internal_EncTicketPart_h_
//$ class sun.security.krb5.internal.EncTicketPart
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
				class AuthorizationData;
				class HostAddresses;
				class KerberosTime;
				class TicketFlags;
				class TransitedEncoding;
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

class $export EncTicketPart : public ::java::lang::Object {
	$class(EncTicketPart, $NO_CLASS_INIT, ::java::lang::Object)
public:
	EncTicketPart();
	void init$(::sun::security::krb5::internal::TicketFlags* new_flags, ::sun::security::krb5::EncryptionKey* new_key, ::sun::security::krb5::PrincipalName* new_cname, ::sun::security::krb5::internal::TransitedEncoding* new_transited, ::sun::security::krb5::internal::KerberosTime* new_authtime, ::sun::security::krb5::internal::KerberosTime* new_starttime, ::sun::security::krb5::internal::KerberosTime* new_endtime, ::sun::security::krb5::internal::KerberosTime* new_renewTill, ::sun::security::krb5::internal::HostAddresses* new_caddr, ::sun::security::krb5::internal::AuthorizationData* new_authorizationData);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	static $String* getHexBytes($bytes* bytes, int32_t len);
	void init(::sun::security::util::DerValue* encoding);
	::sun::security::krb5::internal::TicketFlags* flags = nullptr;
	::sun::security::krb5::EncryptionKey* key = nullptr;
	::sun::security::krb5::PrincipalName* cname = nullptr;
	::sun::security::krb5::internal::TransitedEncoding* transited = nullptr;
	::sun::security::krb5::internal::KerberosTime* authtime = nullptr;
	::sun::security::krb5::internal::KerberosTime* starttime = nullptr;
	::sun::security::krb5::internal::KerberosTime* endtime = nullptr;
	::sun::security::krb5::internal::KerberosTime* renewTill = nullptr;
	::sun::security::krb5::internal::HostAddresses* caddr = nullptr;
	::sun::security::krb5::internal::AuthorizationData* authorizationData = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_EncTicketPart_h_