#include <sun/security/krb5/internal/crypto/Aes128CtsHmacSha1EType.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/GeneralSecurityException.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/KrbCryptoException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/Aes128.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <jcpp.h>

#undef KEYTYPE_AES

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Checksum = ::sun::security::krb5::Checksum;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Aes128 = ::sun::security::krb5::internal::crypto::Aes128;
using $EType = ::sun::security::krb5::internal::crypto::EType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _Aes128CtsHmacSha1EType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Aes128CtsHmacSha1EType::*)()>(&Aes128CtsHmacSha1EType::init$))},
	{"blockSize", "()I", nullptr, $PUBLIC},
	{"checksumSize", "()I", nullptr, $PUBLIC},
	{"checksumType", "()I", nullptr, $PUBLIC},
	{"confounderSize", "()I", nullptr, $PUBLIC},
	{"decrypt", "([B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"decrypt", "([B[B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"decryptedData", "([B)[B", nullptr, $PUBLIC},
	{"eType", "()I", nullptr, $PUBLIC},
	{"encrypt", "([B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"encrypt", "([B[B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"keySize", "()I", nullptr, $PUBLIC},
	{"keyType", "()I", nullptr, $PUBLIC},
	{"minimumPadSize", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Aes128CtsHmacSha1EType_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.Aes128CtsHmacSha1EType",
	"sun.security.krb5.internal.crypto.EType",
	nullptr,
	nullptr,
	_Aes128CtsHmacSha1EType_MethodInfo_
};

$Object* allocate$Aes128CtsHmacSha1EType($Class* clazz) {
	return $of($alloc(Aes128CtsHmacSha1EType));
}

void Aes128CtsHmacSha1EType::init$() {
	$EType::init$();
}

int32_t Aes128CtsHmacSha1EType::eType() {
	return $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96;
}

int32_t Aes128CtsHmacSha1EType::minimumPadSize() {
	return 0;
}

int32_t Aes128CtsHmacSha1EType::confounderSize() {
	return blockSize();
}

int32_t Aes128CtsHmacSha1EType::checksumType() {
	return $Checksum::CKSUMTYPE_HMAC_SHA1_96_AES128;
}

int32_t Aes128CtsHmacSha1EType::checksumSize() {
	return $Aes128::getChecksumLength();
}

int32_t Aes128CtsHmacSha1EType::blockSize() {
	return 16;
}

int32_t Aes128CtsHmacSha1EType::keyType() {
	return $Krb5::KEYTYPE_AES;
}

int32_t Aes128CtsHmacSha1EType::keySize() {
	return 16;
}

$bytes* Aes128CtsHmacSha1EType::encrypt($bytes* data, $bytes* key, int32_t usage) {
	$var($bytes, ivec, $new($bytes, blockSize()));
	return encrypt(data, key, ivec, usage);
}

$bytes* Aes128CtsHmacSha1EType::encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) {
	try {
		return $Aes128::encrypt(key, usage, ivec, data, 0, $nc(data)->length);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

$bytes* Aes128CtsHmacSha1EType::decrypt($bytes* cipher, $bytes* key, int32_t usage) {
	$var($bytes, ivec, $new($bytes, blockSize()));
	return decrypt(cipher, key, ivec, usage);
}

$bytes* Aes128CtsHmacSha1EType::decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) {
	try {
		return $Aes128::decrypt(key, usage, ivec, cipher, 0, $nc(cipher)->length);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

$bytes* Aes128CtsHmacSha1EType::decryptedData($bytes* data) {
	return data;
}

Aes128CtsHmacSha1EType::Aes128CtsHmacSha1EType() {
}

$Class* Aes128CtsHmacSha1EType::load$($String* name, bool initialize) {
	$loadClass(Aes128CtsHmacSha1EType, name, initialize, &_Aes128CtsHmacSha1EType_ClassInfo_, allocate$Aes128CtsHmacSha1EType);
	return class$;
}

$Class* Aes128CtsHmacSha1EType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun