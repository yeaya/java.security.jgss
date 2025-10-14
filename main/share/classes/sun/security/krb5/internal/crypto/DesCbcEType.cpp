#include <sun/security/krb5/internal/crypto/DesCbcEType.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Confounder.h>
#include <sun/security/krb5/KrbCryptoException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/crypto/Des.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <jcpp.h>

#undef KEYTYPE_DES
#undef KRB_AP_ERR_BAD_INTEGRITY

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Confounder = ::sun::security::krb5::Confounder;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $Des = ::sun::security::krb5::internal::crypto::Des;
using $EType = ::sun::security::krb5::internal::crypto::EType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _DesCbcEType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(DesCbcEType::*)()>(&DesCbcEType::init$))},
	{"blockSize", "()I", nullptr, $PUBLIC},
	{"calculateChecksum", "([BI)[B", nullptr, $PROTECTED | $ABSTRACT, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"checksumField", "([B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(DesCbcEType::*)($bytes*)>(&DesCbcEType::checksumField))},
	{"copyChecksumField", "([B[B)V", nullptr, $PRIVATE, $method(static_cast<void(DesCbcEType::*)($bytes*,$bytes*)>(&DesCbcEType::copyChecksumField))},
	{"decrypt", "([B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"decrypt", "([B[B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"encrypt", "([B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"encrypt", "([B[B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"generateChecksum", "([B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(DesCbcEType::*)($bytes*)>(&DesCbcEType::generateChecksum)), "sun.security.krb5.KrbCryptoException"},
	{"isChecksumEqual", "([B[B)Z", nullptr, $PRIVATE, $method(static_cast<bool(DesCbcEType::*)($bytes*,$bytes*)>(&DesCbcEType::isChecksumEqual))},
	{"isChecksumValid", "([B)Z", nullptr, $PROTECTED, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"keySize", "()I", nullptr, $PUBLIC},
	{"keyType", "()I", nullptr, $PUBLIC},
	{"resetChecksumField", "([B)V", nullptr, $PRIVATE, $method(static_cast<void(DesCbcEType::*)($bytes*)>(&DesCbcEType::resetChecksumField))},
	{}
};

$ClassInfo _DesCbcEType_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.internal.crypto.DesCbcEType",
	"sun.security.krb5.internal.crypto.EType",
	nullptr,
	nullptr,
	_DesCbcEType_MethodInfo_
};

$Object* allocate$DesCbcEType($Class* clazz) {
	return $of($alloc(DesCbcEType));
}

void DesCbcEType::init$() {
	$EType::init$();
}

int32_t DesCbcEType::blockSize() {
	return 8;
}

int32_t DesCbcEType::keyType() {
	return $Krb5::KEYTYPE_DES;
}

int32_t DesCbcEType::keySize() {
	return 8;
}

$bytes* DesCbcEType::encrypt($bytes* data, $bytes* key, int32_t usage) {
	$var($bytes, ivec, $new($bytes, keySize()));
	return encrypt(data, key, ivec, usage);
}

$bytes* DesCbcEType::encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) {
	if ($nc(key)->length > 8) {
		$throwNew($KrbCryptoException, "Invalid DES Key!"_s);
	}
	int32_t var$0 = $nc(data)->length + confounderSize();
	int32_t new_size = var$0 + checksumSize();
	$var($bytes, new_data, nullptr);
	int8_t pad = 0;
	if ($mod(new_size, blockSize()) == 0) {
		$assign(new_data, $new($bytes, new_size + blockSize()));
		pad = (int8_t)8;
	} else {
		int32_t var$1 = new_size + blockSize();
		$assign(new_data, $new($bytes, var$1 - $mod(new_size, blockSize())));
		int32_t var$2 = blockSize();
		pad = (int8_t)(var$2 - $mod(new_size, blockSize()));
	}
	for (int32_t i = new_size; i < $nc(new_data)->length; ++i) {
		new_data->set(i, pad);
	}
	$var($bytes, conf, $Confounder::bytes(confounderSize()));
	$System::arraycopy(conf, 0, new_data, 0, confounderSize());
	$System::arraycopy(data, 0, new_data, startOfData(), data->length);
	$var($bytes, cksum, calculateChecksum(new_data, $nc(new_data)->length));
	$var($Object, var$3, $of(cksum));
	$var($Object, var$4, $of(new_data));
	int32_t var$5 = startOfChecksum();
	$System::arraycopy(var$3, 0, var$4, var$5, checksumSize());
	$var($bytes, cipher, $new($bytes, $nc(new_data)->length));
	$Des::cbc_encrypt(new_data, cipher, key, ivec, true);
	return cipher;
}

$bytes* DesCbcEType::decrypt($bytes* cipher, $bytes* key, int32_t usage) {
	$var($bytes, ivec, $new($bytes, keySize()));
	return decrypt(cipher, key, ivec, usage);
}

$bytes* DesCbcEType::decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) {
	if ($nc(key)->length > 8) {
		$throwNew($KrbCryptoException, "Invalid DES Key!"_s);
	}
	$var($bytes, data, $new($bytes, $nc(cipher)->length));
	$Des::cbc_encrypt(cipher, data, key, ivec, false);
	if (!isChecksumValid(data)) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BAD_INTEGRITY);
	}
	return data;
}

void DesCbcEType::copyChecksumField($bytes* data, $bytes* cksum) {
	for (int32_t i = 0; i < checksumSize(); ++i) {
		$nc(data)->set(startOfChecksum() + i, $nc(cksum)->get(i));
	}
}

$bytes* DesCbcEType::checksumField($bytes* data) {
	$var($bytes, result, $new($bytes, checksumSize()));
	for (int32_t i = 0; i < checksumSize(); ++i) {
		result->set(i, $nc(data)->get(startOfChecksum() + i));
	}
	return result;
}

void DesCbcEType::resetChecksumField($bytes* data) {
	{
		int32_t i = startOfChecksum();
		for (;; ++i) {
			int32_t var$0 = i;
			int32_t var$2 = startOfChecksum();
			int32_t var$1 = var$2 + checksumSize();
			if (!(var$0 < var$1)) {
				break;
			}
			{
				$nc(data)->set(i, (int8_t)0);
			}
		}
	}
}

$bytes* DesCbcEType::generateChecksum($bytes* data) {
	$var($bytes, cksum1, checksumField(data));
	resetChecksumField(data);
	$var($bytes, cksum2, calculateChecksum(data, $nc(data)->length));
	copyChecksumField(data, cksum1);
	return cksum2;
}

bool DesCbcEType::isChecksumEqual($bytes* cksum1, $bytes* cksum2) {
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

bool DesCbcEType::isChecksumValid($bytes* data) {
	$var($bytes, cksum1, checksumField(data));
	$var($bytes, cksum2, generateChecksum(data));
	return isChecksumEqual(cksum1, cksum2);
}

DesCbcEType::DesCbcEType() {
}

$Class* DesCbcEType::load$($String* name, bool initialize) {
	$loadClass(DesCbcEType, name, initialize, &_DesCbcEType_ClassInfo_, allocate$DesCbcEType);
	return class$;
}

$Class* DesCbcEType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun