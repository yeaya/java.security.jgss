#ifndef _sun_security_krb5_internal_LastReq_h_
#define _sun_security_krb5_internal_LastReq_h_
//$ class sun.security.krb5.internal.LastReq
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class LastReqEntry;
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

class $export LastReq : public ::java::lang::Object {
	$class(LastReq, $NO_CLASS_INIT, ::java::lang::Object)
public:
	LastReq();
	void init$($Array<::sun::security::krb5::internal::LastReqEntry>* entries);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	static ::sun::security::krb5::internal::LastReq* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	$Array<::sun::security::krb5::internal::LastReqEntry>* entry = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_LastReq_h_