#include <sun/security/krb5/internal/crypto/Aes128Sha2.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/crypto/dk/AesSha2DkCrypto.h>
#include <jcpp.h>

#undef CRYPTO

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AesSha2DkCrypto = ::sun::security::krb5::internal::crypto::dk::AesSha2DkCrypto;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$FieldInfo _Aes128Sha2_FieldInfo_[] = {
	{"CRYPTO", "Lsun/security/krb5/internal/crypto/dk/AesSha2DkCrypto;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Aes128Sha2, CRYPTO)},
	{}
};

$MethodInfo _Aes128Sha2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Aes128Sha2::*)()>(&Aes128Sha2::init$))},
	{"calculateChecksum", "([BI[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,int32_t,int32_t)>(&Aes128Sha2::calculateChecksum)), "java.security.GeneralSecurityException"},
	{"decrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes128Sha2::decrypt)), "java.security.GeneralSecurityException"},
	{"decryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes128Sha2::decryptRaw)), "java.security.GeneralSecurityException"},
	{"encrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes128Sha2::encrypt)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Aes128Sha2::encryptRaw)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"getChecksumLength", "()I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)()>(&Aes128Sha2::getChecksumLength))},
	{"stringToKey", "([CLjava/lang/String;[B)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($chars*,$String*,$bytes*)>(&Aes128Sha2::stringToKey)), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _Aes128Sha2_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.Aes128Sha2",
	"java.lang.Object",
	nullptr,
	_Aes128Sha2_FieldInfo_,
	_Aes128Sha2_MethodInfo_
};

$Object* allocate$Aes128Sha2($Class* clazz) {
	return $of($alloc(Aes128Sha2));
}

$AesSha2DkCrypto* Aes128Sha2::CRYPTO = nullptr;

void Aes128Sha2::init$() {
}

$bytes* Aes128Sha2::stringToKey($chars* password, $String* salt, $bytes* params) {
	$init(Aes128Sha2);
	return $nc(Aes128Sha2::CRYPTO)->stringToKey(password, salt, params);
}

int32_t Aes128Sha2::getChecksumLength() {
	$init(Aes128Sha2);
	return $nc(Aes128Sha2::CRYPTO)->getChecksumLength();
}

$bytes* Aes128Sha2::calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) {
	$init(Aes128Sha2);
	return $nc(Aes128Sha2::CRYPTO)->calculateChecksum(baseKey, usage, input, start, len);
}

$bytes* Aes128Sha2::encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$init(Aes128Sha2);
	return $nc(Aes128Sha2::CRYPTO)->encrypt(baseKey, usage, ivec, nullptr, plaintext, start, len);
}

$bytes* Aes128Sha2::encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$init(Aes128Sha2);
	return $nc(Aes128Sha2::CRYPTO)->encryptRaw(baseKey, usage, ivec, plaintext, start, len);
}

$bytes* Aes128Sha2::decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(Aes128Sha2);
	return $nc(Aes128Sha2::CRYPTO)->decrypt(baseKey, usage, ivec, ciphertext, start, len);
}

$bytes* Aes128Sha2::decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(Aes128Sha2);
	return $nc(Aes128Sha2::CRYPTO)->decryptRaw(baseKey, usage, ivec, ciphertext, start, len);
}

void clinit$Aes128Sha2($Class* class$) {
	$assignStatic(Aes128Sha2::CRYPTO, $new($AesSha2DkCrypto, 128));
}

Aes128Sha2::Aes128Sha2() {
}

$Class* Aes128Sha2::load$($String* name, bool initialize) {
	$loadClass(Aes128Sha2, name, initialize, &_Aes128Sha2_ClassInfo_, clinit$Aes128Sha2, allocate$Aes128Sha2);
	return class$;
}

$Class* Aes128Sha2::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun