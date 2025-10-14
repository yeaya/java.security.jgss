#include <sun/security/krb5/internal/crypto/Des3.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/crypto/dk/Des3DkCrypto.h>
#include <jcpp.h>

#undef CRYPTO

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Des3DkCrypto = ::sun::security::krb5::internal::crypto::dk::Des3DkCrypto;
using $DkCrypto = ::sun::security::krb5::internal::crypto::dk::DkCrypto;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$FieldInfo _Des3_FieldInfo_[] = {
	{"CRYPTO", "Lsun/security/krb5/internal/crypto/dk/Des3DkCrypto;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Des3, CRYPTO)},
	{}
};

$MethodInfo _Des3_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Des3::*)()>(&Des3::init$))},
	{"calculateChecksum", "([BI[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,int32_t,int32_t)>(&Des3::calculateChecksum)), "java.security.GeneralSecurityException"},
	{"decrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Des3::decrypt)), "java.security.GeneralSecurityException"},
	{"decryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Des3::decryptRaw)), "java.security.GeneralSecurityException"},
	{"encrypt", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Des3::encrypt)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t)>(&Des3::encryptRaw)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"getChecksumLength", "()I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)()>(&Des3::getChecksumLength))},
	{"parityFix", "([B)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*)>(&Des3::parityFix)), "java.security.GeneralSecurityException"},
	{"stringToKey", "([C)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($chars*)>(&Des3::stringToKey)), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _Des3_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.Des3",
	"java.lang.Object",
	nullptr,
	_Des3_FieldInfo_,
	_Des3_MethodInfo_
};

$Object* allocate$Des3($Class* clazz) {
	return $of($alloc(Des3));
}

$Des3DkCrypto* Des3::CRYPTO = nullptr;

void Des3::init$() {
}

$bytes* Des3::stringToKey($chars* chars) {
	$init(Des3);
	return $nc(Des3::CRYPTO)->stringToKey(chars);
}

$bytes* Des3::parityFix($bytes* value) {
	$init(Des3);
	return $nc(Des3::CRYPTO)->parityFix(value);
}

int32_t Des3::getChecksumLength() {
	$init(Des3);
	return $nc(Des3::CRYPTO)->getChecksumLength();
}

$bytes* Des3::calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) {
	$init(Des3);
	return $nc(Des3::CRYPTO)->calculateChecksum(baseKey, usage, input, start, len);
}

$bytes* Des3::encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$init(Des3);
	return $nc(Des3::CRYPTO)->encrypt(baseKey, usage, ivec, nullptr, plaintext, start, len);
}

$bytes* Des3::encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$init(Des3);
	return $nc(Des3::CRYPTO)->encryptRaw(baseKey, usage, ivec, plaintext, start, len);
}

$bytes* Des3::decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(Des3);
	return $nc(Des3::CRYPTO)->decrypt(baseKey, usage, ivec, ciphertext, start, len);
}

$bytes* Des3::decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$init(Des3);
	return $nc(Des3::CRYPTO)->decryptRaw(baseKey, usage, ivec, ciphertext, start, len);
}

void clinit$Des3($Class* class$) {
	$assignStatic(Des3::CRYPTO, $new($Des3DkCrypto));
}

Des3::Des3() {
}

$Class* Des3::load$($String* name, bool initialize) {
	$loadClass(Des3, name, initialize, &_Des3_ClassInfo_, clinit$Des3, allocate$Des3);
	return class$;
}

$Class* Des3::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun