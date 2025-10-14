#include <sun/security/krb5/internal/crypto/dk/AesDkCrypto.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/KeySpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/Mac.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/SecretKeyFactory.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/PBEKeySpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/krb5/Confounder.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/krb5/internal/crypto/dk/DkCrypto.h>
#include <jcpp.h>

#undef BLOCK_SIZE
#undef DECRYPT_MODE
#undef DEFAULT_ITERATION_COUNT
#undef ENCRYPT_MODE
#undef KERBEROS_CONSTANT
#undef PBKDF2
#undef UTF_8
#undef ZERO_IV

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $KeySpec = ::java::security::spec::KeySpec;
using $Arrays = ::java::util::Arrays;
using $Cipher = ::javax::crypto::Cipher;
using $Mac = ::javax::crypto::Mac;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeyFactory = ::javax::crypto::SecretKeyFactory;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $PBEKeySpec = ::javax::crypto::spec::PBEKeySpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $Confounder = ::sun::security::krb5::Confounder;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $DkCrypto = ::sun::security::krb5::internal::crypto::dk::DkCrypto;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {
					namespace dk {

$FieldInfo _AesDkCrypto_FieldInfo_[] = {
	{"debug", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AesDkCrypto, debug)},
	{"BLOCK_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AesDkCrypto, BLOCK_SIZE)},
	{"DEFAULT_ITERATION_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AesDkCrypto, DEFAULT_ITERATION_COUNT)},
	{"ZERO_IV", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AesDkCrypto, ZERO_IV)},
	{"hashSize", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AesDkCrypto, hashSize)},
	{"keyLength", "I", nullptr, $PRIVATE | $FINAL, $field(AesDkCrypto, keyLength)},
	{}
};

$MethodInfo _AesDkCrypto_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(AesDkCrypto::*)(int32_t)>(&AesDkCrypto::init$))},
	{"PBKDF2", "([C[BII)[B", nullptr, $PRIVATE | $STATIC, $method(static_cast<$bytes*(*)($chars*,$bytes*,int32_t,int32_t)>(&AesDkCrypto::PBKDF2)), "java.security.GeneralSecurityException"},
	{"calculateChecksum", "([BI[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"decrypt", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"decryptCTS", "([BI[B[BIIZ)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(AesDkCrypto::*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t,bool)>(&AesDkCrypto::decryptCTS)), "java.security.GeneralSecurityException"},
	{"decryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"encrypt", "([BI[B[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptCTS", "([BI[B[B[BIIZ)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(AesDkCrypto::*)($bytes*,int32_t,$bytes*,$bytes*,$bytes*,int32_t,int32_t,bool)>(&AesDkCrypto::encryptCTS)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"getChecksumLength", "()I", nullptr, $PUBLIC},
	{"getCipher", "([B[BI)Ljavax/crypto/Cipher;", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"getHmac", "([B[B)[B", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"getKeySeedLength", "()I", nullptr, $PROTECTED},
	{"randomToKey", "([B)[B", nullptr, $PROTECTED},
	{"readBigEndian", "([BII)I", nullptr, $PUBLIC | $STATIC | $FINAL, $method(static_cast<int32_t(*)($bytes*,int32_t,int32_t)>(&AesDkCrypto::readBigEndian))},
	{"stringToKey", "([CLjava/lang/String;[B)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"stringToKey", "([C[B[B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(AesDkCrypto::*)($chars*,$bytes*,$bytes*)>(&AesDkCrypto::stringToKey)), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _AesDkCrypto_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.dk.AesDkCrypto",
	"sun.security.krb5.internal.crypto.dk.DkCrypto",
	nullptr,
	_AesDkCrypto_FieldInfo_,
	_AesDkCrypto_MethodInfo_
};

$Object* allocate$AesDkCrypto($Class* clazz) {
	return $of($alloc(AesDkCrypto));
}

$bytes* AesDkCrypto::ZERO_IV = nullptr;

void AesDkCrypto::init$(int32_t length) {
	$DkCrypto::init$();
	this->keyLength = length;
}

int32_t AesDkCrypto::getKeySeedLength() {
	return this->keyLength;
}

$bytes* AesDkCrypto::stringToKey($chars* password, $String* salt, $bytes* s2kparams) {
	$var($bytes, saltUtf8, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$init($StandardCharsets);
				$assign(saltUtf8, $nc(salt)->getBytes($StandardCharsets::UTF_8));
				$assign(var$2, stringToKey(password, saltUtf8, s2kparams));
				return$1 = true;
				goto $finally;
			} catch ($Exception&) {
				$var($Exception, e, $catch());
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			if (saltUtf8 != nullptr) {
				$Arrays::fill(saltUtf8, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$bytes* AesDkCrypto::stringToKey($chars* secret, $bytes* salt, $bytes* params) {
	int32_t iter_count = AesDkCrypto::DEFAULT_ITERATION_COUNT;
	if (params != nullptr) {
		if (params->length != 4) {
			$throwNew($RuntimeException, "Invalid parameter to stringToKey"_s);
		}
		iter_count = readBigEndian(params, 0, 4);
	}
	$var($bytes, tmpKey, randomToKey($(PBKDF2(secret, salt, iter_count, getKeySeedLength()))));
	$init($DkCrypto);
	$var($bytes, result, dk(tmpKey, $DkCrypto::KERBEROS_CONSTANT));
	return result;
}

$bytes* AesDkCrypto::randomToKey($bytes* in) {
	return in;
}

$Cipher* AesDkCrypto::getCipher($bytes* key, $bytes* ivec$renamed, int32_t mode) {
	$var($bytes, ivec, ivec$renamed);
	if (ivec == nullptr) {
		$assign(ivec, AesDkCrypto::ZERO_IV);
	}
	$var($SecretKeySpec, secretKey, $new($SecretKeySpec, key, "AES"_s));
	$var($Cipher, cipher, $Cipher::getInstance("AES/CBC/NoPadding"_s));
	$var($IvParameterSpec, encIv, $new($IvParameterSpec, ivec, 0, $nc(ivec)->length));
	$nc(cipher)->init(mode, static_cast<$Key*>(secretKey), static_cast<$AlgorithmParameterSpec*>(encIv));
	return cipher;
}

int32_t AesDkCrypto::getChecksumLength() {
	return AesDkCrypto::hashSize;
}

$bytes* AesDkCrypto::getHmac($bytes* key, $bytes* msg) {
	$var($SecretKey, keyKi, $new($SecretKeySpec, key, "HMAC"_s));
	$var($Mac, m, $Mac::getInstance("HmacSHA1"_s));
	$nc(m)->init(keyKi);
	$var($bytes, hash, m->doFinal(msg));
	$var($bytes, output, $new($bytes, AesDkCrypto::hashSize));
	$System::arraycopy(hash, 0, output, 0, AesDkCrypto::hashSize);
	return output;
}

$bytes* AesDkCrypto::calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, constant, $new($bytes, 5));
	constant->set(0, (int8_t)((int32_t)((usage >> 24) & (uint32_t)255)));
	constant->set(1, (int8_t)((int32_t)((usage >> 16) & (uint32_t)255)));
	constant->set(2, (int8_t)((int32_t)((usage >> 8) & (uint32_t)255)));
	constant->set(3, (int8_t)((int32_t)(usage & (uint32_t)255)));
	constant->set(4, (int8_t)153);
	$var($bytes, Kc, dk(baseKey, constant));
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($bytes, hmac, getHmac(Kc, input));
			if ($nc(hmac)->length == getChecksumLength()) {
				$assign(var$2, hmac);
				return$1 = true;
				goto $finally;
			} else if (hmac->length > getChecksumLength()) {
				$var($bytes, buf, $new($bytes, getChecksumLength()));
				$System::arraycopy(hmac, 0, buf, 0, buf->length);
				$assign(var$2, buf);
				return$1 = true;
				goto $finally;
			} else {
				$throwNew($GeneralSecurityException, $$str({"checksum size too short: "_s, $$str(hmac->length), "; expecting : "_s, $$str(getChecksumLength())}));
			}
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			$Arrays::fill(Kc, 0, $nc(Kc)->length, (int8_t)0);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$bytes* AesDkCrypto::encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, output, encryptCTS(baseKey, usage, ivec, new_ivec, plaintext, start, len, true));
	return output;
}

$bytes* AesDkCrypto::encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, output, encryptCTS(baseKey, usage, ivec, nullptr, plaintext, start, len, false));
	return output;
}

$bytes* AesDkCrypto::decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, output, decryptCTS(baseKey, usage, ivec, ciphertext, start, len, true));
	return output;
}

$bytes* AesDkCrypto::decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, output, decryptCTS(baseKey, usage, ivec, ciphertext, start, len, false));
	return output;
}

$bytes* AesDkCrypto::encryptCTS($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len, bool confounder_exists) {
	$var($bytes, Ke, nullptr);
	$var($bytes, Ki, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($bytes, constant, $new($bytes, 5));
			constant->set(0, (int8_t)((int32_t)((usage >> 24) & (uint32_t)255)));
			constant->set(1, (int8_t)((int32_t)((usage >> 16) & (uint32_t)255)));
			constant->set(2, (int8_t)((int32_t)((usage >> 8) & (uint32_t)255)));
			constant->set(3, (int8_t)((int32_t)(usage & (uint32_t)255)));
			constant->set(4, (int8_t)170);
			$assign(Ke, dk(baseKey, constant));
			$var($bytes, toBeEncrypted, nullptr);
			if (confounder_exists) {
				$var($bytes, confounder, $Confounder::bytes(AesDkCrypto::BLOCK_SIZE));
				$assign(toBeEncrypted, $new($bytes, $nc(confounder)->length + len));
				$System::arraycopy(confounder, 0, toBeEncrypted, 0, confounder->length);
				$System::arraycopy(plaintext, start, toBeEncrypted, confounder->length, len);
			} else {
				$assign(toBeEncrypted, $new($bytes, len));
				$System::arraycopy(plaintext, start, toBeEncrypted, 0, len);
			}
			$var($bytes, output, $new($bytes, $nc(toBeEncrypted)->length + AesDkCrypto::hashSize));
			$var($Cipher, cipher, $Cipher::getInstance("AES/CTS/NoPadding"_s));
			$var($SecretKeySpec, secretKey, $new($SecretKeySpec, Ke, "AES"_s));
			$var($IvParameterSpec, encIv, $new($IvParameterSpec, ivec, 0, $nc(ivec)->length));
			$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(secretKey), static_cast<$AlgorithmParameterSpec*>(encIv));
			cipher->doFinal(toBeEncrypted, 0, toBeEncrypted->length, output);
			constant->set(4, (int8_t)85);
			$assign(Ki, dk(baseKey, constant));
			$var($bytes, hmac, getHmac(Ki, toBeEncrypted));
			$System::arraycopy(hmac, 0, output, toBeEncrypted->length, $nc(hmac)->length);
			$assign(var$2, output);
			return$1 = true;
			goto $finally;
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			if (Ke != nullptr) {
				$Arrays::fill(Ke, 0, Ke->length, (int8_t)0);
			}
			if (Ki != nullptr) {
				$Arrays::fill(Ki, 0, Ki->length, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$bytes* AesDkCrypto::decryptCTS($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len, bool confounder_exists) {
	$var($bytes, Ke, nullptr);
	$var($bytes, Ki, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($bytes, constant, $new($bytes, 5));
			constant->set(0, (int8_t)((int32_t)((usage >> 24) & (uint32_t)255)));
			constant->set(1, (int8_t)((int32_t)((usage >> 16) & (uint32_t)255)));
			constant->set(2, (int8_t)((int32_t)((usage >> 8) & (uint32_t)255)));
			constant->set(3, (int8_t)((int32_t)(usage & (uint32_t)255)));
			constant->set(4, (int8_t)170);
			$assign(Ke, dk(baseKey, constant));
			$var($Cipher, cipher, $Cipher::getInstance("AES/CTS/NoPadding"_s));
			$var($SecretKeySpec, secretKey, $new($SecretKeySpec, Ke, "AES"_s));
			$var($IvParameterSpec, encIv, $new($IvParameterSpec, ivec, 0, $nc(ivec)->length));
			$nc(cipher)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>(secretKey), static_cast<$AlgorithmParameterSpec*>(encIv));
			$var($bytes, plaintext, cipher->doFinal(ciphertext, start, len - AesDkCrypto::hashSize));
			constant->set(4, (int8_t)85);
			$assign(Ki, dk(baseKey, constant));
			$var($bytes, calculatedHmac, getHmac(Ki, plaintext));
			int32_t hmacOffset = start + len - AesDkCrypto::hashSize;
			bool cksumFailed = false;
			if ($nc(calculatedHmac)->length >= AesDkCrypto::hashSize) {
				for (int32_t i = 0; i < AesDkCrypto::hashSize; ++i) {
					if (calculatedHmac->get(i) != $nc(ciphertext)->get(hmacOffset + i)) {
						cksumFailed = true;
						break;
					}
				}
			}
			if (cksumFailed) {
				$throwNew($GeneralSecurityException, "Checksum failed"_s);
			}
			if (confounder_exists) {
				$var($bytes, output, $new($bytes, $nc(plaintext)->length - AesDkCrypto::BLOCK_SIZE));
				$System::arraycopy(plaintext, AesDkCrypto::BLOCK_SIZE, output, 0, output->length);
				$assign(var$2, output);
				return$1 = true;
				goto $finally;
			} else {
				$assign(var$2, plaintext);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			if (Ke != nullptr) {
				$Arrays::fill(Ke, 0, Ke->length, (int8_t)0);
			}
			if (Ki != nullptr) {
				$Arrays::fill(Ki, 0, Ki->length, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$bytes* AesDkCrypto::PBKDF2($chars* secret, $bytes* salt, int32_t count, int32_t keyLength) {
	$init(AesDkCrypto);
	$var($PBEKeySpec, keySpec, $new($PBEKeySpec, secret, salt, count, keyLength));
	$var($SecretKeyFactory, skf, $SecretKeyFactory::getInstance("PBKDF2WithHmacSHA1"_s));
	$var($SecretKey, key, $nc(skf)->generateSecret(keySpec));
	$var($bytes, result, $nc(key)->getEncoded());
	return result;
}

int32_t AesDkCrypto::readBigEndian($bytes* data, int32_t pos, int32_t size) {
	$init(AesDkCrypto);
	int32_t retVal = 0;
	int32_t shifter = (size - 1) * 8;
	while (size > 0) {
		retVal += $sl((int32_t)($nc(data)->get(pos) & (uint32_t)255), shifter);
		shifter -= 8;
		++pos;
		--size;
	}
	return retVal;
}

void clinit$AesDkCrypto($Class* class$) {
	$assignStatic(AesDkCrypto::ZERO_IV, $new($bytes, {
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
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

AesDkCrypto::AesDkCrypto() {
}

$Class* AesDkCrypto::load$($String* name, bool initialize) {
	$loadClass(AesDkCrypto, name, initialize, &_AesDkCrypto_ClassInfo_, clinit$AesDkCrypto, allocate$AesDkCrypto);
	return class$;
}

$Class* AesDkCrypto::class$ = nullptr;

					} // dk
				} // crypto
			} // internal
		} // krb5
	} // security
} // sun