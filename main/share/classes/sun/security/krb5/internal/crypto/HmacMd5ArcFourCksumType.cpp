#include <sun/security/krb5/internal/crypto/HmacMd5ArcFourCksumType.h>

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
#include <sun/security/krb5/internal/crypto/ArcFourHmac.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>
#include <jcpp.h>

#undef CKSUMTYPE_HMAC_MD5_ARCFOUR
#undef KEYTYPE_ARCFOUR_HMAC

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Checksum = ::sun::security::krb5::Checksum;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $ArcFourHmac = ::sun::security::krb5::internal::crypto::ArcFourHmac;
using $CksumType = ::sun::security::krb5::internal::crypto::CksumType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _HmacMd5ArcFourCksumType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HmacMd5ArcFourCksumType::*)()>(&HmacMd5ArcFourCksumType::init$))},
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

$ClassInfo _HmacMd5ArcFourCksumType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.HmacMd5ArcFourCksumType",
	"sun.security.krb5.internal.crypto.CksumType",
	nullptr,
	nullptr,
	_HmacMd5ArcFourCksumType_MethodInfo_
};

$Object* allocate$HmacMd5ArcFourCksumType($Class* clazz) {
	return $of($alloc(HmacMd5ArcFourCksumType));
}

void HmacMd5ArcFourCksumType::init$() {
	$CksumType::init$();
}

int32_t HmacMd5ArcFourCksumType::confounderSize() {
	return 8;
}

int32_t HmacMd5ArcFourCksumType::cksumType() {
	return $Checksum::CKSUMTYPE_HMAC_MD5_ARCFOUR;
}

bool HmacMd5ArcFourCksumType::isKeyed() {
	return true;
}

int32_t HmacMd5ArcFourCksumType::cksumSize() {
	return 16;
}

int32_t HmacMd5ArcFourCksumType::keyType() {
	return $Krb5::KEYTYPE_ARCFOUR_HMAC;
}

int32_t HmacMd5ArcFourCksumType::keySize() {
	return 16;
}

$bytes* HmacMd5ArcFourCksumType::calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) {
	try {
		return $ArcFourHmac::calculateChecksum(key, usage, data, 0, size);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

bool HmacMd5ArcFourCksumType::verifyChecksum($bytes* data, int32_t size, $bytes* key, $bytes* checksum, int32_t usage) {
	try {
		$var($bytes, newCksum, $ArcFourHmac::calculateChecksum(key, usage, data, 0, size));
		return isChecksumEqual(checksum, newCksum);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

HmacMd5ArcFourCksumType::HmacMd5ArcFourCksumType() {
}

$Class* HmacMd5ArcFourCksumType::load$($String* name, bool initialize) {
	$loadClass(HmacMd5ArcFourCksumType, name, initialize, &_HmacMd5ArcFourCksumType_ClassInfo_, allocate$HmacMd5ArcFourCksumType);
	return class$;
}

$Class* HmacMd5ArcFourCksumType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun