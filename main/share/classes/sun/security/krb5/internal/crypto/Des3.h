#ifndef _sun_security_krb5_internal_crypto_Des3_h_
#define _sun_security_krb5_internal_crypto_Des3_h_
//$ class sun.security.krb5.internal.crypto.Des3
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("CRYPTO")
#undef CRYPTO

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {
					namespace dk {
						class Des3DkCrypto;
					}
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class Des3 : public ::java::lang::Object {
	$class(Des3, 0, ::java::lang::Object)
public:
	Des3();
	void init$();
	static $bytes* calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len);
	static $bytes* decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len);
	static $bytes* decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len);
	static $bytes* encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len);
	static $bytes* encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len);
	static int32_t getChecksumLength();
	static $bytes* parityFix($bytes* value);
	static $bytes* stringToKey($chars* chars);
	static ::sun::security::krb5::internal::crypto::dk::Des3DkCrypto* CRYPTO;
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("CRYPTO")

#endif // _sun_security_krb5_internal_crypto_Des3_h_