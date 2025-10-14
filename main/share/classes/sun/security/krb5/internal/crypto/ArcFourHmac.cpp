#include <sun/security/krb5/internal/crypto/ArcFourHmac.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/crypto/dk/ArcFourCrypto.h>
#include <jcpp.h>

#undef CRYPTO

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArcFourCrypto = ::sun::security::krb5::internal::crypto::dk::ArcFourCrypto;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$FieldInfo _ArcFourHmac_FieldInfo_[] = {
	{"CRYPTO", "Lsun/security/krb5/internal/crypto/dk/ArcFourCrypto;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ArcFourHmac, CRYPTO)},
	{}
};

$MethodInfo _ArcFourHmac_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ArcFourHmac::*)()>(&ArcFourHmac::init$))},
	{"calculateChecksum", "([BI[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,int32_t,int32_t)>(&ArcFourHmac::calculateChecksum)), "java.security.GeneralSecurityException"},
	{"decrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&ArcFourHmac::decrypt)), "java.security.GeneralSecurityException"},
	{"decryptRaw", "([BI[B[BII[B)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t,$bytes*)>(&ArcFourHmac::decryptRaw)), "java.security.GeneralSecurityException"},
	{"decryptSeq", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&ArcFourHmac::decryptSeq)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&ArcFourHmac::encrypt)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&ArcFourHmac::encryptRaw)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptSeq", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&ArcFourHmac::encryptSeq)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"getChecksumLength", "()I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)()>(&ArcFourHmac::getChecksumLength))},
	{"stringToKey", "([C)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($chars*)>(&ArcFourHmac::stringToKey)), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _ArcFourHmac_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.ArcFourHmac",
	"java.lang.Object",
	nullptr,
	_ArcFourHmac_FieldInfo_,
	_ArcFourHmac_MethodInfo_
};

$Object* allocate$ArcFourHmac($Class* clazz) {
	return $of($alloc(ArcFourHmac));
}

$ArcFourCrypto* ArcFourHmac::CRYPTO = nullptr;

void ArcFourHmac::init$() {
}

$bytes* ArcFourHmac::stringToKey($chars* password) {
	$init(ArcFourHmac);
	return $nc(ArcFourHmac::CRYPTO)->stringToKey(password);
}

int32_t ArcFourHmac::getChecksumLength() {
	$init(ArcFourHmac);
	return $nc(ArcFourHmac::CRYPTO)->getChecksumLength();
}

$bytes* ArcFourHmac::calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) {
	$init(ArcFourHmac);
	return $nc(ArcFourHmac::CRYPTO)->calculateChecksum(baseKey, usage, input, start, len);
}

$bytes* ArcFourHmac::encryptSeq($bytes* baseKey, int32_t usage, $bytes* checksum, $bytes* plaintext, int32_t start, int32_t len) {
	$init(ArcFourHmac);
	return $nc(ArcFourHmac::CRYPTO)->encryptSeq(baseKey, usage, checksum, plaintext, start, len);
}

$bytes* ArcFourHmac::decryptSeq($bytes* baseKey, int32_t usage, $bytes* checksum, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(ArcFourHmac);
	return $nc(ArcFourHmac::CRYPTO)->decryptSeq(baseKey, usage, checksum, ciphertext, start, len);
}

$bytes* ArcFourHmac::encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$init(ArcFourHmac);
	return $nc(ArcFourHmac::CRYPTO)->encrypt(baseKey, usage, ivec, nullptr, plaintext, start, len);
}

$bytes* ArcFourHmac::encryptRaw($bytes* baseKey, int32_t usage, $bytes* seqNum, $bytes* plaintext, int32_t start, int32_t len) {
	$init(ArcFourHmac);
	return $nc(ArcFourHmac::CRYPTO)->encryptRaw(baseKey, usage, seqNum, plaintext, start, len);
}

$bytes* ArcFourHmac::decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(ArcFourHmac);
	return $nc(ArcFourHmac::CRYPTO)->decrypt(baseKey, usage, ivec, ciphertext, start, len);
}

$bytes* ArcFourHmac::decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len, $bytes* seqNum) {
	$init(ArcFourHmac);
	return $nc(ArcFourHmac::CRYPTO)->decryptRaw(baseKey, usage, ivec, ciphertext, start, len, seqNum);
}

void clinit$ArcFourHmac($Class* class$) {
	$assignStatic(ArcFourHmac::CRYPTO, $new($ArcFourCrypto, 128));
}

ArcFourHmac::ArcFourHmac() {
}

$Class* ArcFourHmac::load$($String* name, bool initialize) {
	$loadClass(ArcFourHmac, name, initialize, &_ArcFourHmac_ClassInfo_, clinit$ArcFourHmac, allocate$ArcFourHmac);
	return class$;
}

$Class* ArcFourHmac::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun