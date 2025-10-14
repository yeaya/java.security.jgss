#include <sun/security/krb5/internal/crypto/CksumType.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/internal/KdcErrException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/Crc32CksumType.h>
#include <sun/security/krb5/internal/crypto/DesMacCksumType.h>
#include <sun/security/krb5/internal/crypto/DesMacKCksumType.h>
#include <sun/security/krb5/internal/crypto/HmacMd5ArcFourCksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha1Aes128CksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha1Aes256CksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha1Des3KdCksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha2Aes128CksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha2Aes256CksumType.h>
#include <sun/security/krb5/internal/crypto/RsaMd5CksumType.h>
#include <sun/security/krb5/internal/crypto/RsaMd5DesCksumType.h>
#include <jcpp.h>

#undef CKSUMTYPE_CRC32
#undef CKSUMTYPE_DES_MAC
#undef CKSUMTYPE_DES_MAC_K
#undef CKSUMTYPE_HMAC_MD5_ARCFOUR
#undef CKSUMTYPE_HMAC_SHA1_DES3_KD
#undef CKSUMTYPE_RSA_MD4
#undef CKSUMTYPE_RSA_MD4_DES
#undef CKSUMTYPE_RSA_MD4_DES_K
#undef CKSUMTYPE_RSA_MD5
#undef CKSUMTYPE_RSA_MD5_DES
#undef DEBUG
#undef KDC_ERR_SUMTYPE_NOSUPP

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Checksum = ::sun::security::krb5::Checksum;
using $KdcErrException = ::sun::security::krb5::internal::KdcErrException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Crc32CksumType = ::sun::security::krb5::internal::crypto::Crc32CksumType;
using $DesMacCksumType = ::sun::security::krb5::internal::crypto::DesMacCksumType;
using $DesMacKCksumType = ::sun::security::krb5::internal::crypto::DesMacKCksumType;
using $HmacMd5ArcFourCksumType = ::sun::security::krb5::internal::crypto::HmacMd5ArcFourCksumType;
using $HmacSha1Aes128CksumType = ::sun::security::krb5::internal::crypto::HmacSha1Aes128CksumType;
using $HmacSha1Aes256CksumType = ::sun::security::krb5::internal::crypto::HmacSha1Aes256CksumType;
using $HmacSha1Des3KdCksumType = ::sun::security::krb5::internal::crypto::HmacSha1Des3KdCksumType;
using $HmacSha2Aes128CksumType = ::sun::security::krb5::internal::crypto::HmacSha2Aes128CksumType;
using $HmacSha2Aes256CksumType = ::sun::security::krb5::internal::crypto::HmacSha2Aes256CksumType;
using $RsaMd5CksumType = ::sun::security::krb5::internal::crypto::RsaMd5CksumType;
using $RsaMd5DesCksumType = ::sun::security::krb5::internal::crypto::RsaMd5DesCksumType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$FieldInfo _CksumType_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(CksumType, DEBUG)},
	{}
};

$MethodInfo _CksumType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(CksumType::*)()>(&CksumType::init$))},
	{"calculateChecksum", "([BI[BI)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"cksumSize", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"cksumType", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"confounderSize", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"getInstance", "(I)Lsun/security/krb5/internal/crypto/CksumType;", nullptr, $PUBLIC | $STATIC, $method(static_cast<CksumType*(*)(int32_t)>(&CksumType::getInstance)), "sun.security.krb5.internal.KdcErrException"},
	{"isChecksumEqual", "([B[B)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)($bytes*,$bytes*)>(&CksumType::isChecksumEqual))},
	{"isKeyed", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"keySize", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"keyType", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"verifyChecksum", "([BI[B[BI)Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "sun.security.krb5.KrbCryptoException"},
	{}
};

$ClassInfo _CksumType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.internal.crypto.CksumType",
	"java.lang.Object",
	nullptr,
	_CksumType_FieldInfo_,
	_CksumType_MethodInfo_
};

$Object* allocate$CksumType($Class* clazz) {
	return $of($alloc(CksumType));
}

bool CksumType::DEBUG = false;

void CksumType::init$() {
}

CksumType* CksumType::getInstance(int32_t cksumTypeConst) {
	$init(CksumType);
	$var(CksumType, cksumType, nullptr);
	$var($String, cksumTypeName, nullptr);
	switch (cksumTypeConst) {
	case $Checksum::CKSUMTYPE_CRC32:
		{
			$assign(cksumType, $new($Crc32CksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.Crc32CksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_DES_MAC:
		{
			$assign(cksumType, $new($DesMacCksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.DesMacCksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_DES_MAC_K:
		{
			$assign(cksumType, $new($DesMacKCksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.DesMacKCksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_RSA_MD5:
		{
			$assign(cksumType, $new($RsaMd5CksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.RsaMd5CksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_RSA_MD5_DES:
		{
			$assign(cksumType, $new($RsaMd5DesCksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.RsaMd5DesCksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_HMAC_SHA1_DES3_KD:
		{
			$assign(cksumType, $new($HmacSha1Des3KdCksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.HmacSha1Des3KdCksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_HMAC_SHA1_96_AES128:
		{
			$assign(cksumType, $new($HmacSha1Aes128CksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.HmacSha1Aes128CksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_HMAC_SHA1_96_AES256:
		{
			$assign(cksumType, $new($HmacSha1Aes256CksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.HmacSha1Aes256CksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_HMAC_SHA256_128_AES128:
		{
			$assign(cksumType, $new($HmacSha2Aes128CksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.HmacSha2Aes128CksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_HMAC_SHA384_192_AES256:
		{
			$assign(cksumType, $new($HmacSha2Aes256CksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.HmacSha2Aes256CksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_HMAC_MD5_ARCFOUR:
		{
			$assign(cksumType, $new($HmacMd5ArcFourCksumType));
			$assign(cksumTypeName, "sun.security.krb5.internal.crypto.HmacMd5ArcFourCksumType"_s);
			break;
		}
	case $Checksum::CKSUMTYPE_RSA_MD4_DES_K:
		{}
	case $Checksum::CKSUMTYPE_RSA_MD4:
		{}
	case $Checksum::CKSUMTYPE_RSA_MD4_DES:
		{}
	default:
		{
			$throwNew($KdcErrException, $Krb5::KDC_ERR_SUMTYPE_NOSUPP);
		}
	}
	if (CksumType::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>> CksumType: "_s, cksumTypeName}));
	}
	return cksumType;
}

bool CksumType::isChecksumEqual($bytes* cksum1, $bytes* cksum2) {
	$init(CksumType);
	if (cksum1 == cksum2) {
		return true;
	}
	if ((cksum1 == nullptr && cksum2 != nullptr) || (cksum1 != nullptr && cksum2 == nullptr)) {
		return false;
	}
	if ($nc(cksum1)->length != $nc(cksum2)->length) {
		return false;
	}
	for (int32_t i = 0; i < $nc(cksum1)->length; ++i) {
		if (cksum1->get(i) != $nc(cksum2)->get(i)) {
			return false;
		}
	}
	return true;
}

void clinit$CksumType($Class* class$) {
	$init($Krb5);
	CksumType::DEBUG = $Krb5::DEBUG;
}

CksumType::CksumType() {
}

$Class* CksumType::load$($String* name, bool initialize) {
	$loadClass(CksumType, name, initialize, &_CksumType_ClassInfo_, clinit$CksumType, allocate$CksumType);
	return class$;
}

$Class* CksumType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun