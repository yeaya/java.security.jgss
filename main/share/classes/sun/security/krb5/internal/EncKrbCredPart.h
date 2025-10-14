#ifndef _sun_security_krb5_internal_EncKrbCredPart_h_
#define _sun_security_krb5_internal_EncKrbCredPart_h_
//$ class sun.security.krb5.internal.EncKrbCredPart
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class Integer;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class HostAddress;
				class HostAddresses;
				class KerberosTime;
				class KrbCredInfo;
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

class $export EncKrbCredPart : public ::java::lang::Object {
	$class(EncKrbCredPart, $NO_CLASS_INIT, ::java::lang::Object)
public:
	EncKrbCredPart();
	void init$($Array<::sun::security::krb5::internal::KrbCredInfo>* new_ticketInfo, ::sun::security::krb5::internal::KerberosTime* new_timeStamp, ::java::lang::Integer* new_usec, ::java::lang::Integer* new_nonce, ::sun::security::krb5::internal::HostAddress* new_sAddress, ::sun::security::krb5::internal::HostAddresses* new_rAddress);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	void init(::sun::security::util::DerValue* encoding);
	$Array<::sun::security::krb5::internal::KrbCredInfo>* ticketInfo = nullptr;
	::sun::security::krb5::internal::KerberosTime* timeStamp = nullptr;
	::java::lang::Integer* nonce = nullptr;
	::java::lang::Integer* usec = nullptr;
	::sun::security::krb5::internal::HostAddress* sAddress = nullptr;
	::sun::security::krb5::internal::HostAddresses* rAddress = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_EncKrbCredPart_h_