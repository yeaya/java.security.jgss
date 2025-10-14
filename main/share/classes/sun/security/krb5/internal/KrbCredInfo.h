#ifndef _sun_security_krb5_internal_KrbCredInfo_h_
#define _sun_security_krb5_internal_KrbCredInfo_h_
//$ class sun.security.krb5.internal.KrbCredInfo
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

class $export KrbCredInfo : public ::java::lang::Object {
	$class(KrbCredInfo, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KrbCredInfo();
	void init$();
	void init$(::sun::security::krb5::EncryptionKey* new_key, ::sun::security::krb5::PrincipalName* new_pname, ::sun::security::krb5::internal::TicketFlags* new_flags, ::sun::security::krb5::internal::KerberosTime* new_authtime, ::sun::security::krb5::internal::KerberosTime* new_starttime, ::sun::security::krb5::internal::KerberosTime* new_endtime, ::sun::security::krb5::internal::KerberosTime* new_renewTill, ::sun::security::krb5::PrincipalName* new_sname, ::sun::security::krb5::internal::HostAddresses* new_caddr);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	::sun::security::krb5::EncryptionKey* key = nullptr;
	::sun::security::krb5::PrincipalName* pname = nullptr;
	::sun::security::krb5::internal::TicketFlags* flags = nullptr;
	::sun::security::krb5::internal::KerberosTime* authtime = nullptr;
	::sun::security::krb5::internal::KerberosTime* starttime = nullptr;
	::sun::security::krb5::internal::KerberosTime* endtime = nullptr;
	::sun::security::krb5::internal::KerberosTime* renewTill = nullptr;
	::sun::security::krb5::PrincipalName* sname = nullptr;
	::sun::security::krb5::internal::HostAddresses* caddr = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_KrbCredInfo_h_