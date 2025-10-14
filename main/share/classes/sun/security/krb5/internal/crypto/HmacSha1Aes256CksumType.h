#ifndef _sun_security_krb5_internal_crypto_HmacSha1Aes256CksumType_h_
#define _sun_security_krb5_internal_crypto_HmacSha1Aes256CksumType_h_
//$ class sun.security.krb5.internal.crypto.HmacSha1Aes256CksumType
//$ extends sun.security.krb5.internal.crypto.CksumType

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class HmacSha1Aes256CksumType : public ::sun::security::krb5::internal::crypto::CksumType {
	$class(HmacSha1Aes256CksumType, $NO_CLASS_INIT, ::sun::security::krb5::internal::crypto::CksumType)
public:
	HmacSha1Aes256CksumType();
	void init$();
	virtual $bytes* calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) override;
	virtual int32_t cksumSize() override;
	virtual int32_t cksumType() override;
	virtual int32_t confounderSize() override;
	virtual bool isKeyed() override;
	virtual int32_t keySize() override;
	virtual int32_t keyType() override;
	virtual bool verifyChecksum($bytes* data, int32_t size, $bytes* key, $bytes* checksum, int32_t usage) override;
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_crypto_HmacSha1Aes256CksumType_h_