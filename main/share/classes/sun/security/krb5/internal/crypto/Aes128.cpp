#include <sun/security/krb5/internal/crypto/Aes128.h>

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

$FieldInfo _Aes128_FieldInfo_[] = {
	{"CRYPTO", "Lsun/security/krb5/internal/crypto/dk/AesDkCrypto;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Aes128, CRYPTO)},
	{}
};

$MethodInfo _Aes128_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Aes128::*)()>(&Aes128::init$))},
	{"calculateChecksum", "([BI[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,int32_t,int32_t)>(&Aes128::calculateChecksum)), "java.security.GeneralSecurityException"},
	{"decrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes128::decrypt)), "java.security.GeneralSecurityException"},
	{"decryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes128::decryptRaw)), "java.security.GeneralSecurityException"},
	{"encrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes128::encrypt)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes128::encryptRaw)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"getChecksumLength", "()I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)()>(&Aes128::getChecksumLength))},
	{"stringToKey", "([CLjava/lang/String;[B)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($chars*,$String*,$bytes*)>(&Aes128::stringToKey)), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _Aes128_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.Aes128",
	"java.lang.Object",
	nullptr,
	_Aes128_FieldInfo_,
	_Aes128_MethodInfo_
};

$Object* allocate$Aes128($Class* clazz) {
	return $of($alloc(Aes128));
}

$AesDkCrypto* Aes128::CRYPTO = nullptr;

void Aes128::init$() {
}

$bytes* Aes128::stringToKey($chars* password, $String* salt, $bytes* params) {
	$init(Aes128);
	return $nc(Aes128::CRYPTO)->stringToKey(password, salt, params);
}

int32_t Aes128::getChecksumLength() {
	$init(Aes128);
	return $nc(Aes128::CRYPTO)->getChecksumLength();
}

$bytes* Aes128::calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) {
	$init(Aes128);
	return $nc(Aes128::CRYPTO)->calculateChecksum(baseKey, usage, input, start, len);
}

$bytes* Aes128::encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$init(Aes128);
	return $nc(Aes128::CRYPTO)->encrypt(baseKey, usage, ivec, nullptr, plaintext, start, len);
}

$bytes* Aes128::encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$init(Aes128);
	return $nc(Aes128::CRYPTO)->encryptRaw(baseKey, usage, ivec, plaintext, start, len);
}

$bytes* Aes128::decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(Aes128);
	return $nc(Aes128::CRYPTO)->decrypt(baseKey, usage, ivec, ciphertext, start, len);
}

$bytes* Aes128::decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(Aes128);
	return $nc(Aes128::CRYPTO)->decryptRaw(baseKey, usage, ivec, ciphertext, start, len);
}

void clinit$Aes128($Class* class$) {
	$assignStatic(Aes128::CRYPTO, $new($AesDkCrypto, 128));
}

Aes128::Aes128() {
}

$Class* Aes128::load$($String* name, bool initialize) {
	$loadClass(Aes128, name, initialize, &_Aes128_ClassInfo_, clinit$Aes128, allocate$Aes128);
	return class$;
}

$Class* Aes128::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun