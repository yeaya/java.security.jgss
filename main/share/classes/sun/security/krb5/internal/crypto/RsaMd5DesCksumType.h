#ifndef _sun_security_krb5_internal_crypto_RsaMd5DesCksumType_h_
#define _sun_security_krb5_internal_crypto_RsaMd5DesCksumType_h_
//$ class sun.security.krb5.internal.crypto.RsaMd5DesCksumType
//$ extends sun.security.krb5.internal.crypto.CksumType

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class RsaMd5DesCksumType : public ::sun::security::krb5::internal::crypto::CksumType {
	$class(RsaMd5DesCksumType, $NO_CLASS_INIT, ::sun::security::krb5::internal::crypto::CksumType)
public:
	RsaMd5DesCksumType();
	void init$();
	virtual $bytes* calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) override;
	$bytes* calculateRawChecksum($bytes* data, int32_t size);
	virtual int32_t cksumSize() override;
	virtual int32_t cksumType() override;
	virtual int32_t confounderSize() override;
	$bytes* decryptKeyedChecksum($bytes* enc_cksum, $bytes* key);
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

#endif // _sun_security_krb5_internal_crypto_RsaMd5DesCksumType_h_