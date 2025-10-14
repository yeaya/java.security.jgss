#include <sun/security/krb5/internal/crypto/HmacSha2Aes256CksumType.h>

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
#include <sun/security/krb5/KrbCryptoException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/Aes256Sha2.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>
#include <jcpp.h>

#undef KEYTYPE_AES

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Checksum = ::sun::security::krb5::Checksum;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Aes256Sha2 = ::sun::security::krb5::internal::crypto::Aes256Sha2;
using $CksumType = ::sun::security::krb5::internal::crypto::CksumType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _HmacSha2Aes256CksumType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HmacSha2Aes256CksumType::*)()>(&HmacSha2Aes256CksumType::init$))},
	{"calculateChecksum", "([BI[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"cksumSize", "()I", nullptr, $PUBLIC},
	{"cksumType", "()I", nullptr, $PUBLIC},
	{"confounderSize", "()I", nullptr, $PUBLIC},
	{"isKeyed", "()Z", nullptr, $PUBLIC},
	{"keySize", "()I", nullptr, $PUBLIC},
	{"keyType", "()I", nullptr, $PUBLIC},
	{"verifyChecksum", "([BI[B[BI)Z", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{}
};

$ClassInfo _HmacSha2Aes256CksumType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.HmacSha2Aes256CksumType",
	"sun.security.krb5.internal.crypto.CksumType",
	nullptr,
	nullptr,
	_HmacSha2Aes256CksumType_MethodInfo_
};

$Object* allocate$HmacSha2Aes256CksumType($Class* clazz) {
	return $of($alloc(HmacSha2Aes256CksumType));
}

void HmacSha2Aes256CksumType::init$() {
	$CksumType::init$();
}

int32_t HmacSha2Aes256CksumType::confounderSize() {
	return 16;
}

int32_t HmacSha2Aes256CksumType::cksumType() {
	return $Checksum::CKSUMTYPE_HMAC_SHA384_192_AES256;
}

bool HmacSha2Aes256CksumType::isKeyed() {
	return true;
}

int32_t HmacSha2Aes256CksumType::cksumSize() {
	return 24;
}

int32_t HmacSha2Aes256CksumType::keyType() {
	return $Krb5::KEYTYPE_AES;
}

int32_t HmacSha2Aes256CksumType::keySize() {
	return 32;
}

$bytes* HmacSha2Aes256CksumType::calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) {
	try {
		return $Aes256Sha2::calculateChecksum(key, usage, data, 0, size);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

bool HmacSha2Aes256CksumType::verifyChecksum($bytes* data, int32_t size, $bytes* key, $bytes* checksum, int32_t usage) {
	try {
		$var($bytes, newCksum, $Aes256Sha2::calculateChecksum(key, usage, data, 0, size));
		return isChecksumEqual(checksum, newCksum);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

HmacSha2Aes256CksumType::HmacSha2Aes256CksumType() {
}

$Class* HmacSha2Aes256CksumType::load$($String* name, bool initialize) {
	$loadClass(HmacSha2Aes256CksumType, name, initialize, &_HmacSha2Aes256CksumType_ClassInfo_, allocate$HmacSha2Aes256CksumType);
	return class$;
}

$Class* HmacSha2Aes256CksumType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun