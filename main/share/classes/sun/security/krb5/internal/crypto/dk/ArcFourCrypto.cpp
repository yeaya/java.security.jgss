#include <sun/security/krb5/internal/crypto/dk/ArcFourCrypto.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/Mac.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/krb5/Confounder.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/krb5/internal/crypto/dk/DkCrypto.h>
#include <sun/security/provider/MD4.h>
#include <jcpp.h>

#undef DECRYPT_MODE
#undef ENCRYPT_MODE
#undef ZERO_IV

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $Cipher = ::javax::crypto::Cipher;
using $Mac = ::javax::crypto::Mac;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $Confounder = ::sun::security::krb5::Confounder;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $DkCrypto = ::sun::security::krb5::internal::crypto::dk::DkCrypto;
using $MD4 = ::sun::security::provider::MD4;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {
					namespace dk {

$FieldInfo _ArcFourCrypto_FieldInfo_[] = {
	{"debug", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ArcFourCrypto, debug)},
	{"confounderSize", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ArcFourCrypto, confounderSize)},
	{"ZERO_IV", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ArcFourCrypto, ZERO_IV)},
	{"hashSize", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ArcFourCrypto, hashSize)},
	{"keyLength", "I", nullptr, $PRIVATE | $FINAL, $field(ArcFourCrypto, keyLength)},
	{}
};

$MethodInfo _ArcFourCrypto_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(ArcFourCrypto::*)(int32_t)>(&ArcFourCrypto::init$))},
	{"arcfour_translate_usage", "(I)I", nullptr, $PRIVATE, $method(static_cast<int32_t(ArcFourCrypto::*)(int32_t)>(&ArcFourCrypto::arcfour_translate_usage))},
	{"calculateChecksum", "([BI[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"decrypt", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"decryptRaw", "([BI[B[BII[B)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"decryptSeq", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encrypt", "([BI[B[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptSeq", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"getChecksumLength", "()I", nullptr, $PUBLIC},
	{"getCipher", "([B[BI)Ljavax/crypto/Cipher;", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"getHmac", "([B[B)[B", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"getKeySeedLength", "()I", nullptr, $PROTECTED},
	{"getSalt", "(I)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(ArcFourCrypto::*)(int32_t)>(&ArcFourCrypto::getSalt))},
	{"randomToKey", "([B)[B", nullptr, $PROTECTED},
	{"stringToKey", "([C)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"stringToKey", "([C[B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(ArcFourCrypto::*)($chars*,$bytes*)>(&ArcFourCrypto::stringToKey)), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _ArcFourCrypto_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.dk.ArcFourCrypto",
	"sun.security.krb5.internal.crypto.dk.DkCrypto",
	nullptr,
	_ArcFourCrypto_FieldInfo_,
	_ArcFourCrypto_MethodInfo_
};

$Object* allocate$ArcFourCrypto($Class* clazz) {
	return $of($alloc(ArcFourCrypto));
}

$bytes* ArcFourCrypto::ZERO_IV = nullptr;

void ArcFourCrypto::init$(int32_t length) {
	$DkCrypto::init$();
	this->keyLength = length;
}

int32_t ArcFourCrypto::getKeySeedLength() {
	return this->keyLength;
}

$bytes* ArcFourCrypto::randomToKey($bytes* in) {
	return in;
}

$bytes* ArcFourCrypto::stringToKey($chars* passwd) {
	return stringToKey(passwd, nullptr);
}

$bytes* ArcFourCrypto::stringToKey($chars* secret, $bytes* opaque) {
	if (opaque != nullptr && opaque->length > 0) {
		$throwNew($RuntimeException, "Invalid parameter to stringToKey"_s);
	}
	$var($bytes, passwd, nullptr);
	$var($bytes, digest, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(passwd, charToUtf16(secret));
				$var($MessageDigest, md, $MD4::getInstance());
				$nc(md)->update(passwd);
				$assign(digest, md->digest());
			} catch ($Exception&) {
				$var($Exception, e, $catch());
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			if (passwd != nullptr) {
				$Arrays::fill(passwd, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	return digest;
}

$Cipher* ArcFourCrypto::getCipher($bytes* key, $bytes* ivec$renamed, int32_t mode) {
	$var($bytes, ivec, ivec$renamed);
	if (ivec == nullptr) {
		$assign(ivec, ArcFourCrypto::ZERO_IV);
	}
	$var($SecretKeySpec, secretKey, $new($SecretKeySpec, key, "ARCFOUR"_s));
	$var($Cipher, cipher, $Cipher::getInstance("ARCFOUR"_s));
	$var($IvParameterSpec, encIv, $new($IvParameterSpec, ivec, 0, $nc(ivec)->length));
	$nc(cipher)->init(mode, static_cast<$Key*>(secretKey), static_cast<$AlgorithmParameterSpec*>(encIv));
	return cipher;
}

int32_t ArcFourCrypto::getChecksumLength() {
	return ArcFourCrypto::hashSize;
}

$bytes* ArcFourCrypto::getHmac($bytes* key, $bytes* msg) {
	$var($SecretKey, keyKi, $new($SecretKeySpec, key, "HmacMD5"_s));
	$var($Mac, m, $Mac::getInstance("HmacMD5"_s));
	$nc(m)->init(keyKi);
	$var($bytes, hash, m->doFinal(msg));
	return hash;
}

$bytes* ArcFourCrypto::calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, Ksign, nullptr);
	try {
		$var($bytes, ss, "signaturekey"_s->getBytes());
		$var($bytes, new_ss, $new($bytes, ss->length + 1));
		$System::arraycopy(ss, 0, new_ss, 0, ss->length);
		$assign(Ksign, getHmac(baseKey, new_ss));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$var($GeneralSecurityException, gse, $new($GeneralSecurityException, "Calculate Checkum Failed!"_s));
		gse->initCause(e);
		$throw(gse);
	}
	$var($bytes, salt, getSalt(usage));
	$var($MessageDigest, messageDigest, nullptr);
	try {
		$assign(messageDigest, $MessageDigest::getInstance("MD5"_s));
	} catch ($NoSuchAlgorithmException&) {
		$var($NoSuchAlgorithmException, e, $catch());
		$var($GeneralSecurityException, gse, $new($GeneralSecurityException, "Calculate Checkum Failed!"_s));
		gse->initCause(e);
		$throw(gse);
	}
	$nc(messageDigest)->update(salt);
	messageDigest->update(input, start, len);
	$var($bytes, md5tmp, messageDigest->digest());
	$var($bytes, hmac, getHmac(Ksign, md5tmp));
	if ($nc(hmac)->length == getChecksumLength()) {
		return hmac;
	} else if (hmac->length > getChecksumLength()) {
		$var($bytes, buf, $new($bytes, getChecksumLength()));
		$System::arraycopy(hmac, 0, buf, 0, buf->length);
		return buf;
	} else {
		$throwNew($GeneralSecurityException, $$str({"checksum size too short: "_s, $$str(hmac->length), "; expecting : "_s, $$str(getChecksumLength())}));
	}
}

$bytes* ArcFourCrypto::encryptSeq($bytes* baseKey, int32_t usage, $bytes* checksum, $bytes* plaintext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, salt, $new($bytes, 4));
	$var($bytes, kSeq, getHmac(baseKey, salt));
	$assign(kSeq, getHmac(kSeq, checksum));
	$var($Cipher, cipher, $Cipher::getInstance("ARCFOUR"_s));
	$var($SecretKeySpec, secretKey, $new($SecretKeySpec, kSeq, "ARCFOUR"_s));
	$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(secretKey));
	$var($bytes, output, cipher->doFinal(plaintext, start, len));
	return output;
}

$bytes* ArcFourCrypto::decryptSeq($bytes* baseKey, int32_t usage, $bytes* checksum, $bytes* ciphertext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, salt, $new($bytes, 4));
	$var($bytes, kSeq, getHmac(baseKey, salt));
	$assign(kSeq, getHmac(kSeq, checksum));
	$var($Cipher, cipher, $Cipher::getInstance("ARCFOUR"_s));
	$var($SecretKeySpec, secretKey, $new($SecretKeySpec, kSeq, "ARCFOUR"_s));
	$nc(cipher)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>(secretKey));
	$var($bytes, output, cipher->doFinal(ciphertext, start, len));
	return output;
}

$bytes* ArcFourCrypto::encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, confounder, $Confounder::bytes(ArcFourCrypto::confounderSize));
	int32_t plainSize = roundup($nc(confounder)->length + len, 1);
	$var($bytes, toBeEncrypted, $new($bytes, plainSize));
	$System::arraycopy(confounder, 0, toBeEncrypted, 0, $nc(confounder)->length);
	$System::arraycopy(plaintext, start, toBeEncrypted, $nc(confounder)->length, len);
	$var($bytes, k1, $new($bytes, $nc(baseKey)->length));
	$System::arraycopy(baseKey, 0, k1, 0, baseKey->length);
	$var($bytes, salt, getSalt(usage));
	$var($bytes, k2, getHmac(k1, salt));
	$var($bytes, checksum, getHmac(k2, toBeEncrypted));
	$var($bytes, k3, getHmac(k2, checksum));
	$var($Cipher, cipher, $Cipher::getInstance("ARCFOUR"_s));
	$var($SecretKeySpec, secretKey, $new($SecretKeySpec, k3, "ARCFOUR"_s));
	$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(secretKey));
	$var($bytes, output, cipher->doFinal(toBeEncrypted, 0, toBeEncrypted->length));
	$var($bytes, result, $new($bytes, ArcFourCrypto::hashSize + $nc(output)->length));
	$System::arraycopy(checksum, 0, result, 0, ArcFourCrypto::hashSize);
	$System::arraycopy(output, 0, result, ArcFourCrypto::hashSize, output->length);
	return result;
}

$bytes* ArcFourCrypto::encryptRaw($bytes* baseKey, int32_t usage, $bytes* seqNum, $bytes* plaintext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, klocal, $new($bytes, $nc(baseKey)->length));
	for (int32_t i = 0; i <= 15; ++i) {
		klocal->set(i, (int8_t)(baseKey->get(i) ^ 240));
	}
	$var($bytes, salt, $new($bytes, 4));
	$var($bytes, kcrypt, getHmac(klocal, salt));
	$assign(kcrypt, getHmac(kcrypt, seqNum));
	$var($Cipher, cipher, $Cipher::getInstance("ARCFOUR"_s));
	$var($SecretKeySpec, secretKey, $new($SecretKeySpec, kcrypt, "ARCFOUR"_s));
	$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(secretKey));
	$var($bytes, output, cipher->doFinal(plaintext, start, len));
	return output;
}

$bytes* ArcFourCrypto::decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, k1, $new($bytes, $nc(baseKey)->length));
	$System::arraycopy(baseKey, 0, k1, 0, baseKey->length);
	$var($bytes, salt, getSalt(usage));
	$var($bytes, k2, getHmac(k1, salt));
	$var($bytes, checksum, $new($bytes, ArcFourCrypto::hashSize));
	$System::arraycopy(ciphertext, start, checksum, 0, ArcFourCrypto::hashSize);
	$var($bytes, k3, getHmac(k2, checksum));
	$var($Cipher, cipher, $Cipher::getInstance("ARCFOUR"_s));
	$var($SecretKeySpec, secretKey, $new($SecretKeySpec, k3, "ARCFOUR"_s));
	$nc(cipher)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>(secretKey));
	$var($bytes, plaintext, cipher->doFinal(ciphertext, start + ArcFourCrypto::hashSize, len - ArcFourCrypto::hashSize));
	$var($bytes, calculatedHmac, getHmac(k2, plaintext));
	bool cksumFailed = false;
	if ($nc(calculatedHmac)->length >= ArcFourCrypto::hashSize) {
		for (int32_t i = 0; i < ArcFourCrypto::hashSize; ++i) {
			if (calculatedHmac->get(i) != $nc(ciphertext)->get(i)) {
				cksumFailed = true;
				break;
			}
		}
	}
	if (cksumFailed) {
		$throwNew($GeneralSecurityException, "Checksum failed"_s);
	}
	$var($bytes, output, $new($bytes, $nc(plaintext)->length - ArcFourCrypto::confounderSize));
	$System::arraycopy(plaintext, ArcFourCrypto::confounderSize, output, 0, output->length);
	return output;
}

$bytes* ArcFourCrypto::decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len, $bytes* seqNum) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, klocal, $new($bytes, $nc(baseKey)->length));
	for (int32_t i = 0; i <= 15; ++i) {
		klocal->set(i, (int8_t)(baseKey->get(i) ^ 240));
	}
	$var($bytes, salt, $new($bytes, 4));
	$var($bytes, kcrypt, getHmac(klocal, salt));
	$var($bytes, sequenceNum, $new($bytes, 4));
	$System::arraycopy(seqNum, 0, sequenceNum, 0, sequenceNum->length);
	$assign(kcrypt, getHmac(kcrypt, sequenceNum));
	$var($Cipher, cipher, $Cipher::getInstance("ARCFOUR"_s));
	$var($SecretKeySpec, secretKey, $new($SecretKeySpec, kcrypt, "ARCFOUR"_s));
	$nc(cipher)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>(secretKey));
	$var($bytes, output, cipher->doFinal(ciphertext, start, len));
	return output;
}

$bytes* ArcFourCrypto::getSalt(int32_t usage) {
	int32_t ms_usage = arcfour_translate_usage(usage);
	$var($bytes, salt, $new($bytes, 4));
	salt->set(0, (int8_t)((int32_t)(ms_usage & (uint32_t)255)));
	salt->set(1, (int8_t)((int32_t)((ms_usage >> 8) & (uint32_t)255)));
	salt->set(2, (int8_t)((int32_t)((ms_usage >> 16) & (uint32_t)255)));
	salt->set(3, (int8_t)((int32_t)((ms_usage >> 24) & (uint32_t)255)));
	return salt;
}

int32_t ArcFourCrypto::arcfour_translate_usage(int32_t usage) {
	switch (usage) {
	case 3:
		{
			return 8;
		}
	case 9:
		{
			return 8;
		}
	case 23:
		{
			return 13;
		}
	default:
		{
			return usage;
		}
	}
}

void clinit$ArcFourCrypto($Class* class$) {
	$assignStatic(ArcFourCrypto::ZERO_IV, $new($bytes, {
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0
	}));
}

ArcFourCrypto::ArcFourCrypto() {
}

$Class* ArcFourCrypto::load$($String* name, bool initialize) {
	$loadClass(ArcFourCrypto, name, initialize, &_ArcFourCrypto_ClassInfo_, clinit$ArcFourCrypto, allocate$ArcFourCrypto);
	return class$;
}

$Class* ArcFourCrypto::class$ = nullptr;

					} // dk
				} // crypto
			} // internal
		} // krb5
	} // security
} // sun