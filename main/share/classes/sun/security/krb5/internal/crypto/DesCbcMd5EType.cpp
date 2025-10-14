#include <sun/security/krb5/internal/crypto/DesCbcMd5EType.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/MessageDigest.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/KrbCryptoException.h>
#include <sun/security/krb5/internal/crypto/DesCbcEType.h>
#include <jcpp.h>

#undef CKSUMTYPE_RSA_MD5
#undef ETYPE_DES_CBC_MD5

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $MessageDigest = ::java::security::MessageDigest;
using $Checksum = ::sun::security::krb5::Checksum;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $DesCbcEType = ::sun::security::krb5::internal::crypto::DesCbcEType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _DesCbcMd5EType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DesCbcMd5EType::*)()>(&DesCbcMd5EType::init$))},
	{"blockSize", "()I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"calculateChecksum", "([BI)[B", nullptr, $PROTECTED, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"checksumSize", "()I", nullptr, $PUBLIC},
	{"checksumType", "()I", nullptr, $PUBLIC},
	{"confounderSize", "()I", nullptr, $PUBLIC},
	{"decrypt", "([B[B[BI)[B", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"decrypt", "([B[BI)[B", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"eType", "()I", nullptr, $PUBLIC},
	{"encrypt", "([B[B[BI)[B", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"encrypt", "([B[BI)[B", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"keySize", "()I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"keyType", "()I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"minimumPadSize", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _DesCbcMd5EType_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.DesCbcMd5EType",
	"sun.security.krb5.internal.crypto.DesCbcEType",
	nullptr,
	nullptr,
	_DesCbcMd5EType_MethodInfo_
};

$Object* allocate$DesCbcMd5EType($Class* clazz) {
	return $of($alloc(DesCbcMd5EType));
}

void DesCbcMd5EType::init$() {
	$DesCbcEType::init$();
}

int32_t DesCbcMd5EType::eType() {
	return $EncryptedData::ETYPE_DES_CBC_MD5;
}

int32_t DesCbcMd5EType::minimumPadSize() {
	return 0;
}

int32_t DesCbcMd5EType::confounderSize() {
	return 8;
}

int32_t DesCbcMd5EType::checksumType() {
	return $Checksum::CKSUMTYPE_RSA_MD5;
}

int32_t DesCbcMd5EType::checksumSize() {
	return 16;
}

$bytes* DesCbcMd5EType::calculateChecksum($bytes* data, int32_t size) {
	$var($MessageDigest, md5, nullptr);
	try {
		$assign(md5, $MessageDigest::getInstance("MD5"_s));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$throwNew($KrbCryptoException, $$str({"JCE provider may not be installed. "_s, $(e->getMessage())}));
	}
	try {
		$nc(md5)->update(data);
		return (md5->digest());
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$throwNew($KrbCryptoException, $(e->getMessage()));
	}
	$shouldNotReachHere();
}

$bytes* DesCbcMd5EType::decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) {
	return $DesCbcEType::decrypt(cipher, key, ivec, usage);
}

$bytes* DesCbcMd5EType::decrypt($bytes* cipher, $bytes* key, int32_t usage) {
	return $DesCbcEType::decrypt(cipher, key, usage);
}

$bytes* DesCbcMd5EType::encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) {
	return $DesCbcEType::encrypt(data, key, ivec, usage);
}

$bytes* DesCbcMd5EType::encrypt($bytes* data, $bytes* key, int32_t usage) {
	return $DesCbcEType::encrypt(data, key, usage);
}

int32_t DesCbcMd5EType::keySize() {
	return $DesCbcEType::keySize();
}

int32_t DesCbcMd5EType::keyType() {
	return $DesCbcEType::keyType();
}

int32_t DesCbcMd5EType::blockSize() {
	return $DesCbcEType::blockSize();
}

DesCbcMd5EType::DesCbcMd5EType() {
}

$Class* DesCbcMd5EType::load$($String* name, bool initialize) {
	$loadClass(DesCbcMd5EType, name, initialize, &_DesCbcMd5EType_ClassInfo_, allocate$DesCbcMd5EType);
	return class$;
}

$Class* DesCbcMd5EType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun