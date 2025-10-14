#ifndef _sun_security_krb5_internal_crypto_dk_ArcFourCrypto_h_
#define _sun_security_krb5_internal_crypto_dk_ArcFourCrypto_h_
//$ class sun.security.krb5.internal.crypto.dk.ArcFourCrypto
//$ extends sun.security.krb5.internal.crypto.dk.DkCrypto

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/crypto/dk/DkCrypto.h>

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

class ArcFourCrypto : public ::sun::security::krb5::internal::crypto::dk::DkCrypto {
	$class(ArcFourCrypto, 0, ::sun::security::krb5::internal::crypto::dk::DkCrypto)
public:
	ArcFourCrypto();
	using ::sun::security::krb5::internal::crypto::dk::DkCrypto::decryptRaw;
	void init$(int32_t length);
	int32_t arcfour_translate_usage(int32_t usage);
	virtual $bytes* calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) override;
	virtual $bytes* decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) override;
	virtual $bytes* decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len, $bytes* seqNum);
	virtual $bytes* decryptSeq($bytes* baseKey, int32_t usage, $bytes* checksum, $bytes* ciphertext, int32_t start, int32_t len);
	virtual $bytes* encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len) override;
	virtual $bytes* encryptRaw($bytes* baseKey, int32_t usage, $bytes* seqNum, $bytes* plaintext, int32_t start, int32_t len) override;
	virtual $bytes* encryptSeq($bytes* baseKey, int32_t usage, $bytes* checksum, $bytes* plaintext, int32_t start, int32_t len);
	virtual int32_t getChecksumLength() override;
	virtual ::javax::crypto::Cipher* getCipher($bytes* key, $bytes* ivec, int32_t mode) override;
	virtual $bytes* getHmac($bytes* key, $bytes* msg) override;
	virtual int32_t getKeySeedLength() override;
	$bytes* getSalt(int32_t usage);
	virtual $bytes* randomToKey($bytes* in) override;
	virtual $bytes* stringToKey($chars* passwd);
	$bytes* stringToKey($chars* secret, $bytes* opaque);
	static const bool debug = false;
	static const int32_t confounderSize = 8;
	static $bytes* ZERO_IV;
	static const int32_t hashSize = 16;
	int32_t keyLength = 0;
};

					} // dk
				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("ZERO_IV")

#endif // _sun_security_krb5_internal_crypto_dk_ArcFourCrypto_h_