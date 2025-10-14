#ifndef _sun_security_krb5_internal_crypto_Nonce_h_
#define _sun_security_krb5_internal_crypto_Nonce_h_
//$ class sun.security.krb5.internal.crypto.Nonce
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class Nonce : public ::java::lang::Object {
	$class(Nonce, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Nonce();
	void init$();
	static int32_t value();
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_crypto_Nonce_h_