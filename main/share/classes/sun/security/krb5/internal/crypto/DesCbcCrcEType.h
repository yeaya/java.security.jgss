#ifndef _sun_security_krb5_internal_crypto_DesCbcCrcEType_h_
#define _sun_security_krb5_internal_crypto_DesCbcCrcEType_h_
//$ class sun.security.krb5.internal.crypto.DesCbcCrcEType
//$ extends sun.security.krb5.internal.crypto.DesCbcEType

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/crypto/DesCbcEType.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class DesCbcCrcEType : public ::sun::security::krb5::internal::crypto::DesCbcEType {
	$class(DesCbcCrcEType, $NO_CLASS_INIT, ::sun::security::krb5::internal::crypto::DesCbcEType)
public:
	DesCbcCrcEType();
	void init$();
	virtual int32_t blockSize() override;
	virtual $bytes* calculateChecksum($bytes* data, int32_t size) override;
	virtual int32_t checksumSize() override;
	virtual int32_t checksumType() override;
	virtual int32_t confounderSize() override;
	virtual $bytes* decrypt($bytes* cipher, $bytes* key, int32_t usage) override;
	virtual $bytes* decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) override;
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

#endif // _sun_security_krb5_internal_crypto_DesCbcCrcEType_h_