#ifndef _sun_security_krb5_internal_EncKrbPrivPart_h_
#define _sun_security_krb5_internal_EncKrbPrivPart_h_
//$ class sun.security.krb5.internal.EncKrbPrivPart
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
				class KerberosTime;
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

class $export EncKrbPrivPart : public ::java::lang::Object {
	$class(EncKrbPrivPart, $NO_CLASS_INIT, ::java::lang::Object)
public:
	EncKrbPrivPart();
	void init$($bytes* new_userData, ::sun::security::krb5::internal::KerberosTime* new_timestamp, ::java::lang::Integer* new_usec, ::java::lang::Integer* new_seqNumber, ::sun::security::krb5::internal::HostAddress* new_sAddress, ::sun::security::krb5::internal::HostAddress* new_rAddress);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	void init(::sun::security::util::DerValue* encoding);
	$bytes* userData = nullptr;
	::sun::security::krb5::internal::KerberosTime* timestamp = nullptr;
	::java::lang::Integer* usec = nullptr;
	::java::lang::Integer* seqNumber = nullptr;
	::sun::security::krb5::internal::HostAddress* sAddress = nullptr;
	::sun::security::krb5::internal::HostAddress* rAddress = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_EncKrbPrivPart_h_