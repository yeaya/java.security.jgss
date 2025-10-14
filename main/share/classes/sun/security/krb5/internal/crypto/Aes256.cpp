#include <sun/security/krb5/internal/crypto/Aes256.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/crypto/dk/AesDkCrypto.h>
#include <jcpp.h>

#undef CRYPTO

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AesDkCrypto = ::sun::security::krb5::internal::crypto::dk::AesDkCrypto;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$FieldInfo _Aes256_FieldInfo_[] = {
	{"CRYPTO", "Lsun/security/krb5/internal/crypto/dk/AesDkCrypto;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Aes256, CRYPTO)},
	{}
};

$MethodInfo _Aes256_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Aes256::*)()>(&Aes256::init$))},
	{"calculateChecksum", "([BI[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,int32_t,int32_t)>(&Aes256::calculateChecksum)), "java.security.GeneralSecurityException"},
	{"decrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes256::decrypt)), "java.security.GeneralSecurityException"},
	{"decryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes256::decryptRaw)), "java.security.GeneralSecurityException"},
	{"encrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes256::encrypt)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes256::encryptRaw)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"getChecksumLength", "()I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)()>(&Aes256::getChecksumLength))},
	{"stringToKey", "([CLjava/lang/String;[B)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($chars*,$String*,$bytes*)>(&Aes256::stringToKey)), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _Aes256_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.Aes256",
	"java.lang.Object",
	nullptr,
	_Aes256_FieldInfo_,
	_Aes256_MethodInfo_
};

$Object* allocate$Aes256($Class* clazz) {
	return $of($alloc(Aes256));
}

$AesDkCrypto* Aes256::CRYPTO = nullptr;

void Aes256::init$() {
}

$bytes* Aes256::stringToKey($chars* password, $String* salt, $bytes* params) {
	$init(Aes256);
	return $nc(Aes256::CRYPTO)->stringToKey(password, salt, params);
}

int32_t Aes256::getChecksumLength() {
	$init(Aes256);
	return $nc(Aes256::CRYPTO)->getChecksumLength();
}

$bytes* Aes256::calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) {
	$init(Aes256);
	return $nc(Aes256::CRYPTO)->calculateChecksum(baseKey, usage, input, start, len);
}

$bytes* Aes256::encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$init(Aes256);
	return $nc(Aes256::CRYPTO)->encrypt(baseKey, usage, ivec, nullptr, plaintext, start, len);
}

$bytes* Aes256::encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$init(Aes256);
	return $nc(Aes256::CRYPTO)->encryptRaw(baseKey, usage, ivec, plaintext, start, len);
}

$bytes* Aes256::decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(Aes256);
	return $nc(Aes256::CRYPTO)->decrypt(baseKey, usage, ivec, ciphertext, start, len);
}

$bytes* Aes256::decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(Aes256);
	return $nc(Aes256::CRYPTO)->decryptRaw(baseKey, usage, ivec, ciphertext, start, len);
}

void clinit$Aes256($Class* class$) {
	$assignStatic(Aes256::CRYPTO, $new($AesDkCrypto, 256));
}

Aes256::Aes256() {
}

$Class* Aes256::load$($String* name, bool initialize) {
	$loadClass(Aes256, name, initialize, &_Aes256_ClassInfo_, clinit$Aes256, allocate$Aes256);
	return class$;
}

$Class* Aes256::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun