#ifndef _sun_security_krb5_internal_crypto_Aes256CtsHmacSha2EType_h_
#define _sun_security_krb5_internal_crypto_Aes256CtsHmacSha2EType_h_
//$ class sun.security.krb5.internal.crypto.Aes256CtsHmacSha2EType
//$ extends sun.security.krb5.internal.crypto.EType

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/crypto/EType.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class Aes256CtsHmacSha2EType : public ::sun::security::krb5::internal::crypto::EType {
	$class(Aes256CtsHmacSha2EType, $NO_CLASS_INIT, ::sun::security::krb5::internal::crypto::EType)
public:
	Aes256CtsHmacSha2EType();
	void init$();
	virtual int32_t blockSize() override;
	virtual int32_t checksumSize() override;
	virtual int32_t checksumType() override;
	virtual int32_t confounderSize() override;
	virtual $bytes* decrypt($bytes* cipher, $bytes* key, int32_t usage) override;
	virtual $bytes* decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) override;
	virtual $bytes* decryptedData($bytes* data) override;
	virtual int32_t eType() override;
	virtual $bytes* encrypt($bytes* data, $bytes* key, int32_t usage) override;
	virtual $bytes* encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) override;
	virtual int32_t keySize() override;
	virtual int32_t keyType() override;
	virtual int32_t minimumPadSize() override;
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_crypto_Aes256CtsHmacSha2EType_h_