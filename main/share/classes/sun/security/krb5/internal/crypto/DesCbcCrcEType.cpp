#include <sun/security/krb5/internal/crypto/DesCbcCrcEType.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/internal/crypto/DesCbcEType.h>
#include <sun/security/krb5/internal/crypto/crc32.h>
#include <jcpp.h>

#undef CKSUMTYPE_RSA_MD5
#undef ETYPE_DES_CBC_CRC

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Checksum = ::sun::security::krb5::Checksum;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $DesCbcEType = ::sun::security::krb5::internal::crypto::DesCbcEType;
using $crc32 = ::sun::security::krb5::internal::crypto::crc32;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _DesCbcCrcEType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DesCbcCrcEType::*)()>(&DesCbcCrcEType::init$))},
	{"blockSize", "()I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"calculateChecksum", "([BI)[B", nullptr, $PROTECTED},
	{"checksumSize", "()I", nullptr, $PUBLIC},
	{"checksumType", "()I", nullptr, $PUBLIC},
	{"confounderSize", "()I", nullptr, $PUBLIC},
	{"decrypt", "([B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"decrypt", "([B[B[BI)[B", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"eType", "()I", nullptr, $PUBLIC},
	{"encrypt", "([B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"encrypt", "([B[B[BI)[B", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"keySize", "()I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"keyType", "()I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"minimumPadSize", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _DesCbcCrcEType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.DesCbcCrcEType",
	"sun.security.krb5.internal.crypto.DesCbcEType",
	nullptr,
	nullptr,
	_DesCbcCrcEType_MethodInfo_
};

$Object* allocate$DesCbcCrcEType($Class* clazz) {
	return $of($alloc(DesCbcCrcEType));
}

void DesCbcCrcEType::init$() {
	$DesCbcEType::init$();
}

int32_t DesCbcCrcEType::eType() {
	return $EncryptedData::ETYPE_DES_CBC_CRC;
}

int32_t DesCbcCrcEType::minimumPadSize() {
	return 4;
}

int32_t DesCbcCrcEType::confounderSize() {
	return 8;
}

int32_t DesCbcCrcEType::checksumType() {
	return $Checksum::CKSUMTYPE_RSA_MD5;
}

int32_t DesCbcCrcEType::checksumSize() {
	return 4;
}

$bytes* DesCbcCrcEType::encrypt($bytes* data, $bytes* key, int32_t usage) {
	return encrypt(data, key, key, usage);
}

$bytes* DesCbcCrcEType::decrypt($bytes* cipher, $bytes* key, int32_t usage) {
	return decrypt(cipher, key, key, usage);
}

$bytes* DesCbcCrcEType::calculateChecksum($bytes* data, int32_t size) {
	return $crc32::byte2crc32sum_bytes(data, size);
}

$bytes* DesCbcCrcEType::decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) {
	return $DesCbcEType::decrypt(cipher, key, ivec, usage);
}

$bytes* DesCbcCrcEType::encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) {
	return $DesCbcEType::encrypt(data, key, ivec, usage);
}

int32_t DesCbcCrcEType::keySize() {
	return $DesCbcEType::keySize();
}

int32_t DesCbcCrcEType::keyType() {
	return $DesCbcEType::keyType();
}

int32_t DesCbcCrcEType::blockSize() {
	return $DesCbcEType::blockSize();
}

DesCbcCrcEType::DesCbcCrcEType() {
}

$Class* DesCbcCrcEType::load$($String* name, bool initialize) {
	$loadClass(DesCbcCrcEType, name, initialize, &_DesCbcCrcEType_ClassInfo_, allocate$DesCbcCrcEType);
	return class$;
}

$Class* DesCbcCrcEType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun