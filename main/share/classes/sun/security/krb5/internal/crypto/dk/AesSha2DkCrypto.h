#ifndef _sun_security_krb5_internal_crypto_dk_AesSha2DkCrypto_h_
#define _sun_security_krb5_internal_crypto_dk_AesSha2DkCrypto_h_
//$ class sun.security.krb5.internal.crypto.dk.AesSha2DkCrypto
//$ extends sun.security.krb5.internal.crypto.dk.DkCrypto

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/crypto/dk/DkCrypto.h>

#pragma push_macro("BLOCK_SIZE")
#undef BLOCK_SIZE
#pragma push_macro("DEFAULT_ITERATION_COUNT")
#undef DEFAULT_ITERATION_COUNT
#pragma push_macro("ETYPE_NAME_128")
#undef ETYPE_NAME_128
#pragma push_macro("ETYPE_NAME_256")
#undef ETYPE_NAME_256
#pragma push_macro("PBKDF2")
#undef PBKDF2
#pragma push_macro("ZERO_IV")
#undef ZERO_IV

namespace javax {
	namespace crypto {
		class Cipher;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {
					namespace dk {

class AesSha2DkCrypto : public ::sun::security::krb5::internal::crypto::dk::DkCrypto {
	$class(AesSha2DkCrypto, 0, ::sun::security::krb5::internal::crypto::dk::DkCrypto)
public:
	AesSha2DkCrypto();
	void init$(int32_t length);
	static $bytes* PBKDF2($chars* secret, $bytes* salt, int32_t count, int32_t keyLength);
	virtual $bytes* calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) override;
	virtual $bytes* decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) override;
	$bytes* decryptCTS($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len, bool confounder_exists);
	virtual $bytes* decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) override;
	$bytes* deriveKey($bytes* baseKey, int32_t usage, int8_t type);
	virtual $bytes* dr($bytes* key, $bytes* constant) override;
	virtual $bytes* encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len) override;
	$bytes* encryptCTS($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len, bool confounder_exists);
	virtual $bytes* encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) override;
	virtual int32_t getChecksumLength() override;
	virtual ::javax::crypto::Cipher* getCipher($bytes* key, $bytes* ivec, int32_t mode) override;
	virtual $bytes* getHmac($bytes* key, $bytes* msg) override;
	virtual int32_t getKeySeedLength() override;
	virtual $bytes* randomToKey($bytes* in) override;
	static int32_t readBigEndian($bytes* data, int32_t pos, int32_t size);
	virtual $bytes* stringToKey($chars* password, $String* salt, $bytes* s2kparams);
	$bytes* stringToKey($chars* secret, $bytes* salt, $bytes* params);
	static const bool debug = false;
	static const int32_t BLOCK_SIZE = 16;
	static const int32_t DEFAULT_ITERATION_COUNT = 32768;
	static $bytes* ZERO_IV;
	static $bytes* ETYPE_NAME_128;
	static $bytes* ETYPE_NAME_256;
	int32_t hashSize = 0;
	int32_t keyLength = 0;
};

					} // dk
				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("BLOCK_SIZE")
#pragma pop_macro("DEFAULT_ITERATION_COUNT")
#pragma pop_macro("ETYPE_NAME_128")
#pragma pop_macro("ETYPE_NAME_256")
#pragma pop_macro("PBKDF2")
#pragma pop_macro("ZERO_IV")

#endif // _sun_security_krb5_internal_crypto_dk_AesSha2DkCrypto_h_