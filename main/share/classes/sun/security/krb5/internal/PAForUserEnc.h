#ifndef _sun_security_krb5_internal_PAForUserEnc_h_
#define _sun_security_krb5_internal_PAForUserEnc_h_
//$ class sun.security.krb5.internal.PAForUserEnc
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("AUTH_PACKAGE")
#undef AUTH_PACKAGE

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
		namespace util {
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export PAForUserEnc : public ::java::lang::Object {
	$class(PAForUserEnc, 0, ::java::lang::Object)
public:
	PAForUserEnc();
	void init$(::sun::security::krb5::PrincipalName* name, ::sun::security::krb5::EncryptionKey* key);
	void init$(::sun::security::util::DerValue* encoding, ::sun::security::krb5::EncryptionKey* key);
	virtual $bytes* asn1Encode();
	virtual ::sun::security::krb5::PrincipalName* getName();
	virtual $bytes* getS4UByteArray();
	virtual $String* toString() override;
	::sun::security::krb5::PrincipalName* name = nullptr;
	::sun::security::krb5::EncryptionKey* key = nullptr;
	static $String* AUTH_PACKAGE;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("AUTH_PACKAGE")

#endif // _sun_security_krb5_internal_PAForUserEnc_h_