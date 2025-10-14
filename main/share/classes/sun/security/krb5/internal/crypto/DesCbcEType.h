#ifndef _sun_security_krb5_internal_crypto_DesCbcEType_h_
#define _sun_security_krb5_internal_crypto_DesCbcEType_h_
//$ class sun.security.krb5.internal.crypto.DesCbcEType
//$ extends sun.security.krb5.internal.crypto.EType

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/crypto/EType.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class DesCbcEType : public ::sun::security::krb5::internal::crypto::EType {
	$class(DesCbcEType, $NO_CLASS_INIT, ::sun::security::krb5::internal::crypto::EType)
public:
	DesCbcEType();
	void init$();
	virtual int32_t blockSize() override;
	virtual $bytes* calculateChecksum($bytes* data, int32_t size) {return nullptr;}
	$bytes* checksumField($bytes* data);
	void copyChecksumField($bytes* data, $bytes* cksum);
	virtual $bytes* decrypt($bytes* cipher, $bytes* key, int32_t usage) override;
	virtual $bytes* decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) override;
	virtual $bytes* encrypt($bytes* data, $bytes* key, int32_t usage) override;
	virtual $bytes* encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) override;
	$bytes* generateChecksum($bytes* data);
	bool isChecksumEqual($bytes* cksum1, $bytes* cksum2);
	virtual bool isChecksumValid($bytes* data);
	virtual int32_t keySize() override;
	virtual int32_t keyType() override;
	void resetChecksumField($bytes* data);
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_crypto_DesCbcEType_h_