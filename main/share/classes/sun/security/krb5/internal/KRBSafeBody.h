#ifndef _sun_security_krb5_internal_KRBSafeBody_h_
#define _sun_security_krb5_internal_KRBSafeBody_h_
//$ class sun.security.krb5.internal.KRBSafeBody
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
			class DerInputStream;
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export KRBSafeBody : public ::java::lang::Object {
	$class(KRBSafeBody, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KRBSafeBody();
	void init$($bytes* new_userData, ::sun::security::krb5::internal::KerberosTime* new_timestamp, ::java::lang::Integer* new_usec, ::java::lang::Integer* new_seqNumber, ::sun::security::krb5::internal::HostAddress* new_sAddress, ::sun::security::krb5::internal::HostAddress* new_rAddress);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	static ::sun::security::krb5::internal::KRBSafeBody* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
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

#endif // _sun_security_krb5_internal_KRBSafeBody_h_