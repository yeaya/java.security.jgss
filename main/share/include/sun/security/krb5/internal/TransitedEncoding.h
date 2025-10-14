#ifndef _sun_security_krb5_internal_TransitedEncoding_h_
#define _sun_security_krb5_internal_TransitedEncoding_h_
//$ class sun.security.krb5.internal.TransitedEncoding
//$ extends java.lang.Object

#include <java/lang/Array.h>

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

class $import TransitedEncoding : public ::java::lang::Object {
	$class(TransitedEncoding, $NO_CLASS_INIT, ::java::lang::Object)
public:
	TransitedEncoding();
	void init$(int32_t type, $bytes* cont);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	static ::sun::security::krb5::internal::TransitedEncoding* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	int32_t trType = 0;
	$bytes* contents = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_TransitedEncoding_h_