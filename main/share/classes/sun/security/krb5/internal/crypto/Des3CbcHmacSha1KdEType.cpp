#include <sun/security/krb5/internal/crypto/Des3CbcHmacSha1KdEType.h>

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
#include <sun/security/krb5/internal/crypto/Des3.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <jcpp.h>

#undef CKSUMTYPE_HMAC_SHA1_DES3_KD
#undef ETYPE_DES3_CBC_HMAC_SHA1_KD
#undef KEYTYPE_DES3

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Checksum = ::sun::security::krb5::Checksum;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Des3 = ::sun::security::krb5::internal::crypto::Des3;
using $EType = ::sun::security::krb5::internal::crypto::EType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _Des3CbcHmacSha1KdEType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Des3CbcHmacSha1KdEType::*)()>(&Des3CbcHmacSha1KdEType::init$))},
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

$ClassInfo _Des3CbcHmacSha1KdEType_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.Des3CbcHmacSha1KdEType",
	"sun.security.krb5.internal.crypto.EType",
	nullptr,
	nullptr,
	_Des3CbcHmacSha1KdEType_MethodInfo_
};

$Object* allocate$Des3CbcHmacSha1KdEType($Class* clazz) {
	return $of($alloc(Des3CbcHmacSha1KdEType));
}

void Des3CbcHmacSha1KdEType::init$() {
	$EType::init$();
}

int32_t Des3CbcHmacSha1KdEType::eType() {
	return $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD;
}

int32_t Des3CbcHmacSha1KdEType::minimumPadSize() {
	return 0;
}

int32_t Des3CbcHmacSha1KdEType::confounderSize() {
	return blockSize();
}

int32_t Des3CbcHmacSha1KdEType::checksumType() {
	return $Checksum::CKSUMTYPE_HMAC_SHA1_DES3_KD;
}

int32_t Des3CbcHmacSha1KdEType::checksumSize() {
	return $Des3::getChecksumLength();
}

int32_t Des3CbcHmacSha1KdEType::blockSize() {
	return 8;
}

int32_t Des3CbcHmacSha1KdEType::keyType() {
	return $Krb5::KEYTYPE_DES3;
}

int32_t Des3CbcHmacSha1KdEType::keySize() {
	return 24;
}

$bytes* Des3CbcHmacSha1KdEType::encrypt($bytes* data, $bytes* key, int32_t usage) {
	$var($bytes, ivec, $new($bytes, blockSize()));
	return encrypt(data, key, ivec, usage);
}

$bytes* Des3CbcHmacSha1KdEType::encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) {
	try {
		return $Des3::encrypt(key, usage, ivec, data, 0, $nc(data)->length);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

$bytes* Des3CbcHmacSha1KdEType::decrypt($bytes* cipher, $bytes* key, int32_t usage) {
	$var($bytes, ivec, $new($bytes, blockSize()));
	return decrypt(cipher, key, ivec, usage);
}

$bytes* Des3CbcHmacSha1KdEType::decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) {
	try {
		return $Des3::decrypt(key, usage, ivec, cipher, 0, $nc(cipher)->length);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

$bytes* Des3CbcHmacSha1KdEType::decryptedData($bytes* data) {
	return data;
}

Des3CbcHmacSha1KdEType::Des3CbcHmacSha1KdEType() {
}

$Class* Des3CbcHmacSha1KdEType::load$($String* name, bool initialize) {
	$loadClass(Des3CbcHmacSha1KdEType, name, initialize, &_Des3CbcHmacSha1KdEType_ClassInfo_, allocate$Des3CbcHmacSha1KdEType);
	return class$;
}

$Class* Des3CbcHmacSha1KdEType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun