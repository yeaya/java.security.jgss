#include <sun/security/krb5/internal/crypto/ArcFourHmacEType.h>

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
#include <sun/security/krb5/internal/crypto/ArcFourHmac.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <jcpp.h>

#undef CKSUMTYPE_HMAC_MD5_ARCFOUR
#undef ETYPE_ARCFOUR_HMAC
#undef KEYTYPE_ARCFOUR_HMAC

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Checksum = ::sun::security::krb5::Checksum;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $ArcFourHmac = ::sun::security::krb5::internal::crypto::ArcFourHmac;
using $EType = ::sun::security::krb5::internal::crypto::EType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _ArcFourHmacEType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ArcFourHmacEType::*)()>(&ArcFourHmacEType::init$))},
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

$ClassInfo _ArcFourHmacEType_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.ArcFourHmacEType",
	"sun.security.krb5.internal.crypto.EType",
	nullptr,
	nullptr,
	_ArcFourHmacEType_MethodInfo_
};

$Object* allocate$ArcFourHmacEType($Class* clazz) {
	return $of($alloc(ArcFourHmacEType));
}

void ArcFourHmacEType::init$() {
	$EType::init$();
}

int32_t ArcFourHmacEType::eType() {
	return $EncryptedData::ETYPE_ARCFOUR_HMAC;
}

int32_t ArcFourHmacEType::minimumPadSize() {
	return 1;
}

int32_t ArcFourHmacEType::confounderSize() {
	return 8;
}

int32_t ArcFourHmacEType::checksumType() {
	return $Checksum::CKSUMTYPE_HMAC_MD5_ARCFOUR;
}

int32_t ArcFourHmacEType::checksumSize() {
	return $ArcFourHmac::getChecksumLength();
}

int32_t ArcFourHmacEType::blockSize() {
	return 1;
}

int32_t ArcFourHmacEType::keyType() {
	return $Krb5::KEYTYPE_ARCFOUR_HMAC;
}

int32_t ArcFourHmacEType::keySize() {
	return 16;
}

$bytes* ArcFourHmacEType::encrypt($bytes* data, $bytes* key, int32_t usage) {
	$var($bytes, ivec, $new($bytes, blockSize()));
	return encrypt(data, key, ivec, usage);
}

$bytes* ArcFourHmacEType::encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) {
	try {
		return $ArcFourHmac::encrypt(key, usage, ivec, data, 0, $nc(data)->length);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

$bytes* ArcFourHmacEType::decrypt($bytes* cipher, $bytes* key, int32_t usage) {
	$var($bytes, ivec, $new($bytes, blockSize()));
	return decrypt(cipher, key, ivec, usage);
}

$bytes* ArcFourHmacEType::decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) {
	try {
		return $ArcFourHmac::decrypt(key, usage, ivec, cipher, 0, $nc(cipher)->length);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	$shouldNotReachHere();
}

$bytes* ArcFourHmacEType::decryptedData($bytes* data) {
	return data;
}

ArcFourHmacEType::ArcFourHmacEType() {
}

$Class* ArcFourHmacEType::load$($String* name, bool initialize) {
	$loadClass(ArcFourHmacEType, name, initialize, &_ArcFourHmacEType_ClassInfo_, allocate$ArcFourHmacEType);
	return class$;
}

$Class* ArcFourHmacEType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun