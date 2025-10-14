#include <sun/security/krb5/internal/crypto/HmacSha1Des3KdCksumType.h>

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
#include <sun/security/krb5/internal/crypto/CksumType.h>
#include <sun/security/krb5/internal/crypto/Des3.h>
#include <jcpp.h>

#undef CKSUMTYPE_HMAC_SHA1_DES3_KD
#undef KEYTYPE_DES3

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Checksum = ::sun::security::krb5::Checksum;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $CksumType = ::sun::security::krb5::internal::crypto::CksumType;
using $Des3 = ::sun::security::krb5::internal::crypto::Des3;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _HmacSha1Des3KdCksumType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HmacSha1Des3KdCksumType::*)()>(&HmacSha1Des3KdCksumType::init$))},
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

$ClassInfo _HmacSha1Des3KdCksumType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.HmacSha1Des3KdCksumType",
	"sun.security.krb5.internal.crypto.CksumType",
	nullptr,
	nullptr,
	_HmacSha1Des3KdCksumType_MethodInfo_
};

$Object* allocate$HmacSha1Des3KdCksumType($Class* clazz) {
	return $of($alloc(HmacSha1Des3KdCksumType));
}

void HmacSha1Des3KdCksumType::init$() {
	$CksumType::init$();
}

int32_t HmacSha1Des3KdCksumType::confounderSize() {
	return 8;
}

int32_t HmacSha1Des3KdCksumType::cksumType() {
	return $Checksum::CKSUMTYPE_HMAC_SHA1_DES3_KD;
}

bool HmacSha1Des3KdCksumType::isKeyed() {
	return true;
}

int32_t HmacSha1Des3KdCksumType::cksumSize() {
	return 20;
}

int32_t HmacSha1Des3KdCksumType::keyType() {
	return $Krb5::KEYTYPE_DES3;
}

int32_t HmacSha1Des3KdCksumType::keySize() {
	return 24;
}

$bytes* HmacSha1Des3KdCksumType::calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) {
	try {
		return $Des3::calculateChecksum(key, usage, data, 0, size);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

bool HmacSha1Des3KdCksumType::verifyChecksum($bytes* data, int32_t size, $bytes* key, $bytes* checksum, int32_t usage) {
	try {
		$var($bytes, newCksum, $Des3::calculateChecksum(key, usage, data, 0, size));
		return isChecksumEqual(checksum, newCksum);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

HmacSha1Des3KdCksumType::HmacSha1Des3KdCksumType() {
}

$Class* HmacSha1Des3KdCksumType::load$($String* name, bool initialize) {
	$loadClass(HmacSha1Des3KdCksumType, name, initialize, &_HmacSha1Des3KdCksumType_ClassInfo_, allocate$HmacSha1Des3KdCksumType);
	return class$;
}

$Class* HmacSha1Des3KdCksumType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun