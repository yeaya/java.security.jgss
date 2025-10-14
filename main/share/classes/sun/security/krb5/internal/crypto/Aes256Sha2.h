#ifndef _sun_security_krb5_internal_crypto_Aes256Sha2_h_
#define _sun_security_krb5_internal_crypto_Aes256Sha2_h_
//$ class sun.security.krb5.internal.crypto.Aes256Sha2
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
						class AesSha2DkCrypto;
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

class Aes256Sha2 : public ::java::lang::Object {
	$class(Aes256Sha2, 0, ::java::lang::Object)
public:
	Aes256Sha2();
	void init$();
	static $bytes* calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len);
	static $bytes* decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len);
	static $bytes* decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len);
	static $bytes* encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len);
	static $bytes* encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len);
	static int32_t getChecksumLength();
	static $bytes* stringToKey($chars* password, $String* salt, $bytes* params);
	static ::sun::security::krb5::internal::crypto::dk::AesSha2DkCrypto* CRYPTO;
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("CRYPTO")

#endif // _sun_security_krb5_internal_crypto_Aes256Sha2_h_