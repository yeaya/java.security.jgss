#ifndef _sun_security_krb5_internal_crypto_dk_Des3DkCrypto_h_
#define _sun_security_krb5_internal_crypto_dk_Des3DkCrypto_h_
//$ class sun.security.krb5.internal.crypto.dk.Des3DkCrypto
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

class Des3DkCrypto : public ::sun::security::krb5::internal::crypto::dk::DkCrypto {
	$class(Des3DkCrypto, 0, ::sun::security::krb5::internal::crypto::dk::DkCrypto)
public:
	Des3DkCrypto();
	void init$();
	static $bytes* des3Expand($bytes* input, int32_t start, int32_t end);
	virtual int32_t getChecksumLength() override;
	virtual ::javax::crypto::Cipher* getCipher($bytes* key, $bytes* ivec, int32_t mode) override;
	virtual $bytes* getHmac($bytes* key, $bytes* msg) override;
	virtual int32_t getKeySeedLength() override;
	static $bytes* keyCorrection($bytes* key);
	virtual $bytes* parityFix($bytes* value);
	virtual $bytes* randomToKey($bytes* in) override;
	static void setParityBit($bytes* key);
	virtual $bytes* stringToKey($chars* salt);
	$bytes* stringToKey($bytes* secretAndSalt, $bytes* opaque);
	static $bytes* ZERO_IV;
};

					} // dk
				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("ZERO_IV")

#endif // _sun_security_krb5_internal_crypto_dk_Des3DkCrypto_h_