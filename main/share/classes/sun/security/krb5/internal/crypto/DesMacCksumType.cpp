#include <sun/security/krb5/internal/crypto/DesMacCksumType.h>

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
#include <sun/security/krb5/Confounder.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>
#include <sun/security/krb5/internal/crypto/Des.h>
#include <jcpp.h>

#undef CKSUMTYPE_DES_MAC
#undef KEYTYPE_DES

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $DESKeySpec = ::javax::crypto::spec::DESKeySpec;
using $Checksum = ::sun::security::krb5::Checksum;
using $Confounder = ::sun::security::krb5::Confounder;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $CksumType = ::sun::security::krb5::internal::crypto::CksumType;
using $Des = ::sun::security::krb5::internal::crypto::Des;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _DesMacCksumType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DesMacCksumType::*)()>(&DesMacCksumType::init$))},
	{"calculateChecksum", "([BI[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"cksumSize", "()I", nullptr, $PUBLIC},
	{"cksumType", "()I", nullptr, $PUBLIC},
	{"confounderSize", "()I", nullptr, $PUBLIC},
	{"decryptKeyedChecksum", "([B[B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(DesMacCksumType::*)($bytes*,$bytes*)>(&DesMacCksumType::decryptKeyedChecksum)), "sun.security.krb5.KrbCryptoException"},
	{"isKeyed", "()Z", nullptr, $PUBLIC},
	{"keySize", "()I", nullptr, $PUBLIC},
	{"keyType", "()I", nullptr, $PUBLIC},
	{"verifyChecksum", "([BI[B[BI)Z", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{}
};

$ClassInfo _DesMacCksumType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.DesMacCksumType",
	"sun.security.krb5.internal.crypto.CksumType",
	nullptr,
	nullptr,
	_DesMacCksumType_MethodInfo_
};

$Object* allocate$DesMacCksumType($Class* clazz) {
	return $of($alloc(DesMacCksumType));
}

void DesMacCksumType::init$() {
	$CksumType::init$();
}

int32_t DesMacCksumType::confounderSize() {
	return 8;
}

int32_t DesMacCksumType::cksumType() {
	return $Checksum::CKSUMTYPE_DES_MAC;
}

bool DesMacCksumType::isKeyed() {
	return true;
}

int32_t DesMacCksumType::cksumSize() {
	return 16;
}

int32_t DesMacCksumType::keyType() {
	return $Krb5::KEYTYPE_DES;
}

int32_t DesMacCksumType::keySize() {
	return 8;
}

$bytes* DesMacCksumType::calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) {
	$var($bytes, new_data, $new($bytes, size + confounderSize()));
	$var($bytes, conf, $Confounder::bytes(confounderSize()));
	$System::arraycopy(conf, 0, new_data, 0, confounderSize());
	$System::arraycopy(data, 0, new_data, confounderSize(), size);
	try {
		if ($DESKeySpec::isWeak(key, 0)) {
			$nc(key)->set(7, (int8_t)(key->get(7) ^ 240));
		}
	} catch ($InvalidKeyException&) {
		$catch();
	}
	$var($bytes, residue_ivec, $new($bytes, $nc(key)->length));
	$var($bytes, residue, $Des::des_cksum(residue_ivec, new_data, key));
	$var($bytes, cksum, $new($bytes, cksumSize()));
	$System::arraycopy(conf, 0, cksum, 0, confounderSize());
	$var($Object, var$0, $of(residue));
	$var($Object, var$1, $of(cksum));
	int32_t var$2 = confounderSize();
	int32_t var$3 = cksumSize();
	$System::arraycopy(var$0, 0, var$1, var$2, var$3 - confounderSize());
	$var($bytes, new_key, $new($bytes, keySize()));
	$System::arraycopy(key, 0, new_key, 0, key->length);
	for (int32_t i = 0; i < new_key->length; ++i) {
		new_key->set(i, (int8_t)(new_key->get(i) ^ 240));
	}
	try {
		if ($DESKeySpec::isWeak(new_key, 0)) {
			new_key->set(7, (int8_t)(new_key->get(7) ^ 240));
		}
	} catch ($InvalidKeyException&) {
		$catch();
	}
	$var($bytes, ivec, $new($bytes, new_key->length));
	$var($bytes, enc_cksum, $new($bytes, cksum->length));
	$Des::cbc_encrypt(cksum, enc_cksum, new_key, ivec, true);
	return enc_cksum;
}

bool DesMacCksumType::verifyChecksum($bytes* data, int32_t size, $bytes* key, $bytes* checksum, int32_t usage) {
	$var($bytes, cksum, decryptKeyedChecksum(checksum, key));
	$var($bytes, new_data, $new($bytes, size + confounderSize()));
	$System::arraycopy(cksum, 0, new_data, 0, confounderSize());
	$System::arraycopy(data, 0, new_data, confounderSize(), size);
	try {
		if ($DESKeySpec::isWeak(key, 0)) {
			$nc(key)->set(7, (int8_t)(key->get(7) ^ 240));
		}
	} catch ($InvalidKeyException&) {
		$catch();
	}
	$var($bytes, ivec, $new($bytes, $nc(key)->length));
	$var($bytes, new_cksum, $Des::des_cksum(ivec, new_data, key));
	int32_t var$0 = cksumSize();
	$var($bytes, orig_cksum, $new($bytes, var$0 - confounderSize()));
	$var($Object, var$1, $of(cksum));
	int32_t var$2 = confounderSize();
	$var($Object, var$3, $of(orig_cksum));
	int32_t var$4 = cksumSize();
	$System::arraycopy(var$1, var$2, var$3, 0, var$4 - confounderSize());
	return isChecksumEqual(orig_cksum, new_cksum);
}

$bytes* DesMacCksumType::decryptKeyedChecksum($bytes* enc_cksum, $bytes* key) {
	$var($bytes, new_key, $new($bytes, keySize()));
	$System::arraycopy(key, 0, new_key, 0, $nc(key)->length);
	for (int32_t i = 0; i < new_key->length; ++i) {
		new_key->set(i, (int8_t)(new_key->get(i) ^ 240));
	}
	try {
		if ($DESKeySpec::isWeak(new_key, 0)) {
			new_key->set(7, (int8_t)(new_key->get(7) ^ 240));
		}
	} catch ($InvalidKeyException&) {
		$catch();
	}
	$var($bytes, ivec, $new($bytes, new_key->length));
	$var($bytes, cksum, $new($bytes, $nc(enc_cksum)->length));
	$Des::cbc_encrypt(enc_cksum, cksum, new_key, ivec, false);
	return cksum;
}

DesMacCksumType::DesMacCksumType() {
}

$Class* DesMacCksumType::load$($String* name, bool initialize) {
	$loadClass(DesMacCksumType, name, initialize, &_DesMacCksumType_ClassInfo_, allocate$DesMacCksumType);
	return class$;
}

$Class* DesMacCksumType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun