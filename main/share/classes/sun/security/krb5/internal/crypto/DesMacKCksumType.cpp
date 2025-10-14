#include <sun/security/krb5/internal/crypto/DesMacKCksumType.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/InvalidKeyException.h>
#include <javax/crypto/spec/DESKeySpec.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>
#include <sun/security/krb5/internal/crypto/Des.h>
#include <jcpp.h>

#undef CKSUMTYPE_DES_MAC_K
#undef KEYTYPE_DES

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $DESKeySpec = ::javax::crypto::spec::DESKeySpec;
using $Checksum = ::sun::security::krb5::Checksum;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $CksumType = ::sun::security::krb5::internal::crypto::CksumType;
using $Des = ::sun::security::krb5::internal::crypto::Des;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _DesMacKCksumType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DesMacKCksumType::*)()>(&DesMacKCksumType::init$))},
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

$ClassInfo _DesMacKCksumType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.DesMacKCksumType",
	"sun.security.krb5.internal.crypto.CksumType",
	nullptr,
	nullptr,
	_DesMacKCksumType_MethodInfo_
};

$Object* allocate$DesMacKCksumType($Class* clazz) {
	return $of($alloc(DesMacKCksumType));
}

void DesMacKCksumType::init$() {
	$CksumType::init$();
}

int32_t DesMacKCksumType::confounderSize() {
	return 0;
}

int32_t DesMacKCksumType::cksumType() {
	return $Checksum::CKSUMTYPE_DES_MAC_K;
}

bool DesMacKCksumType::isKeyed() {
	return true;
}

int32_t DesMacKCksumType::cksumSize() {
	return 16;
}

int32_t DesMacKCksumType::keyType() {
	return $Krb5::KEYTYPE_DES;
}

int32_t DesMacKCksumType::keySize() {
	return 8;
}

$bytes* DesMacKCksumType::calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) {
	try {
		if ($DESKeySpec::isWeak(key, 0)) {
			$nc(key)->set(7, (int8_t)(key->get(7) ^ 240));
		}
	} catch ($InvalidKeyException&) {
		$catch();
	}
	$var($bytes, ivec, $new($bytes, $nc(key)->length));
	$System::arraycopy(key, 0, ivec, 0, key->length);
	$var($bytes, cksum, $Des::des_cksum(ivec, data, key));
	return cksum;
}

bool DesMacKCksumType::verifyChecksum($bytes* data, int32_t size, $bytes* key, $bytes* checksum, int32_t usage) {
	$var($bytes, new_cksum, calculateChecksum(data, $nc(data)->length, key, usage));
	return isChecksumEqual(checksum, new_cksum);
}

DesMacKCksumType::DesMacKCksumType() {
}

$Class* DesMacKCksumType::load$($String* name, bool initialize) {
	$loadClass(DesMacKCksumType, name, initialize, &_DesMacKCksumType_ClassInfo_, allocate$DesMacKCksumType);
	return class$;
}

$Class* DesMacKCksumType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun