#include <sun/security/krb5/internal/crypto/dk/AesSha2DkCrypto.h>

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
#undef ETYPE_NAME_128
#undef ETYPE_NAME_256
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

$FieldInfo _AesSha2DkCrypto_FieldInfo_[] = {
	{"debug", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AesSha2DkCrypto, debug)},
	{"BLOCK_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AesSha2DkCrypto, BLOCK_SIZE)},
	{"DEFAULT_ITERATION_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AesSha2DkCrypto, DEFAULT_ITERATION_COUNT)},
	{"ZERO_IV", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AesSha2DkCrypto, ZERO_IV)},
	{"ETYPE_NAME_128", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AesSha2DkCrypto, ETYPE_NAME_128)},
	{"ETYPE_NAME_256", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AesSha2DkCrypto, ETYPE_NAME_256)},
	{"hashSize", "I", nullptr, $PRIVATE | $FINAL, $field(AesSha2DkCrypto, hashSize)},
	{"keyLength", "I", nullptr, $PRIVATE | $FINAL, $field(AesSha2DkCrypto, keyLength)},
	{}
};

$MethodInfo _AesSha2DkCrypto_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(AesSha2DkCrypto::*)(int32_t)>(&AesSha2DkCrypto::init$))},
	{"PBKDF2", "([C[BII)[B", nullptr, $PRIVATE | $STATIC, $method(static_cast<$bytes*(*)($chars*,$bytes*,int32_t,int32_t)>(&AesSha2DkCrypto::PBKDF2)), "java.security.GeneralSecurityException"},
	{"calculateChecksum", "([BI[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"decrypt", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"decryptCTS", "([BI[B[BIIZ)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(AesSha2DkCrypto::*)($bytes*,int32_t,$bytes*,$bytes*,int32_t,int32_t,bool)>(&AesSha2DkCrypto::decryptCTS)), "java.security.GeneralSecurityException"},
	{"decryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"deriveKey", "([BIB)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(AesSha2DkCrypto::*)($bytes*,int32_t,int8_t)>(&AesSha2DkCrypto::deriveKey)), "java.security.GeneralSecurityException"},
	{"dr", "([B[B)[B", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"encrypt", "([BI[B[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptCTS", "([BI[B[B[BIIZ)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(AesSha2DkCrypto::*)($bytes*,int32_t,$bytes*,$bytes*,$bytes*,int32_t,int32_t,bool)>(&AesSha2DkCrypto::encryptCTS)), "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"getChecksumLength", "()I", nullptr, $PUBLIC},
	{"getCipher", "([B[BI)Ljavax/crypto/Cipher;", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"getHmac", "([B[B)[B", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"getKeySeedLength", "()I", nullptr, $PROTECTED},
	{"randomToKey", "([B)[B", nullptr, $PROTECTED},
	{"readBigEndian", "([BII)I", nullptr, $PUBLIC | $STATIC | $FINAL, $method(static_cast<int32_t(*)($bytes*,int32_t,int32_t)>(&AesSha2DkCrypto::readBigEndian))},
	{"stringToKey", "([CLjava/lang/String;[B)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"stringToKey", "([C[B[B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(AesSha2DkCrypto::*)($chars*,$bytes*,$bytes*)>(&AesSha2DkCrypto::stringToKey)), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _AesSha2DkCrypto_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.dk.AesSha2DkCrypto",
	"sun.security.krb5.internal.crypto.dk.DkCrypto",
	nullptr,
	_AesSha2DkCrypto_FieldInfo_,
	_AesSha2DkCrypto_MethodInfo_
};

$Object* allocate$AesSha2DkCrypto($Class* clazz) {
	return $of($alloc(AesSha2DkCrypto));
}

$bytes* AesSha2DkCrypto::ZERO_IV = nullptr;
$bytes* AesSha2DkCrypto::ETYPE_NAME_128 = nullptr;
$bytes* AesSha2DkCrypto::ETYPE_NAME_256 = nullptr;

void AesSha2DkCrypto::init$(int32_t length) {
	$DkCrypto::init$();
	this->keyLength = length;
	this->hashSize = (length == 128 ? 128 : 192) / 8;
}

int32_t AesSha2DkCrypto::getKeySeedLength() {
	return this->keyLength;
}

$bytes* AesSha2DkCrypto::stringToKey($chars* password, $String* salt, $bytes* s2kparams) {
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

$bytes* AesSha2DkCrypto::stringToKey($chars* secret, $bytes* salt, $bytes* params) {
	int32_t iter_count = AesSha2DkCrypto::DEFAULT_ITERATION_COUNT;
	if (params != nullptr) {
		if (params->length != 4) {
			$throwNew($RuntimeException, "Invalid parameter to stringToKey"_s);
		}
		iter_count = readBigEndian(params, 0, 4);
	}
	$var($bytes, saltp, $new($bytes, 26 + 1 + $nc(salt)->length));
	if (this->keyLength == 128) {
		$System::arraycopy(AesSha2DkCrypto::ETYPE_NAME_128, 0, saltp, 0, 26);
	} else {
		$System::arraycopy(AesSha2DkCrypto::ETYPE_NAME_256, 0, saltp, 0, 26);
	}
	$System::arraycopy(salt, 0, saltp, 27, salt->length);
	$var($bytes, tmpKey, randomToKey($(PBKDF2(secret, saltp, iter_count, getKeySeedLength()))));
	$init($DkCrypto);
	$var($bytes, result, dk(tmpKey, $DkCrypto::KERBEROS_CONSTANT));
	return result;
}

$bytes* AesSha2DkCrypto::randomToKey($bytes* in) {
	return in;
}

$bytes* AesSha2DkCrypto::dr($bytes* key, $bytes* constant) {
	$var($bytes, result, nullptr);
	$var($bytes, input, $new($bytes, $nc(constant)->length + 9));
	input->set(3, (int8_t)1);
	$System::arraycopy(constant, 0, input, 4, constant->length);
	$var($SecretKeySpec, tkey, $new($SecretKeySpec, key, "HMAC"_s));
	$var($Mac, mac, $Mac::getInstance(this->keyLength == 128 ? "HmacSHA256"_s : "HmacSHA384"_s));
	$nc(mac)->init(tkey);
	int32_t k = 0;
	if (this->keyLength == 128) {
		k = 128;
	} else {
		int8_t last = constant->get(constant->length - 1);
		if (last == (int8_t)153 || last == (int8_t)85) {
			k = 192;
		} else {
			k = 256;
		}
	}
	input->set(input->length - 1, (int8_t)(k));
	input->set(input->length - 2, (int8_t)(k / 256));
	$assign(result, mac->doFinal(input));
	return $Arrays::copyOf(result, k / 8);
}

$Cipher* AesSha2DkCrypto::getCipher($bytes* key, $bytes* ivec$renamed, int32_t mode) {
	$var($bytes, ivec, ivec$renamed);
	if (ivec == nullptr) {
		$assign(ivec, AesSha2DkCrypto::ZERO_IV);
	}
	$var($SecretKeySpec, secretKey, $new($SecretKeySpec, key, "AES"_s));
	$var($Cipher, cipher, $Cipher::getInstance("AES/CBC/NoPadding"_s));
	$var($IvParameterSpec, encIv, $new($IvParameterSpec, ivec, 0, $nc(ivec)->length));
	$nc(cipher)->init(mode, static_cast<$Key*>(secretKey), static_cast<$AlgorithmParameterSpec*>(encIv));
	return cipher;
}

int32_t AesSha2DkCrypto::getChecksumLength() {
	return this->hashSize;
}

$bytes* AesSha2DkCrypto::getHmac($bytes* key, $bytes* msg) {
	$var($SecretKey, keyKi, $new($SecretKeySpec, key, "HMAC"_s));
	$var($Mac, m, $Mac::getInstance(this->keyLength == 128 ? "HmacSHA256"_s : "HmacSHA384"_s));
	$nc(m)->init(keyKi);
	$var($bytes, hash, m->doFinal(msg));
	$var($bytes, output, $new($bytes, this->hashSize));
	$System::arraycopy(hash, 0, output, 0, this->hashSize);
	return output;
}

$bytes* AesSha2DkCrypto::deriveKey($bytes* baseKey, int32_t usage, int8_t type) {
	$var($bytes, constant, $new($bytes, 5));
	constant->set(0, (int8_t)((int32_t)((usage >> 24) & (uint32_t)255)));
	constant->set(1, (int8_t)((int32_t)((usage >> 16) & (uint32_t)255)));
	constant->set(2, (int8_t)((int32_t)((usage >> 8) & (uint32_t)255)));
	constant->set(3, (int8_t)((int32_t)(usage & (uint32_t)255)));
	constant->set(4, type);
	return dk(baseKey, constant);
}

$bytes* AesSha2DkCrypto::calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, Kc, deriveKey(baseKey, usage, (int8_t)153));
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

$bytes* AesSha2DkCrypto::encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, output, encryptCTS(baseKey, usage, ivec, new_ivec, plaintext, start, len, true));
	return output;
}

$bytes* AesSha2DkCrypto::encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, output, encryptCTS(baseKey, usage, ivec, nullptr, plaintext, start, len, false));
	return output;
}

$bytes* AesSha2DkCrypto::decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, output, decryptCTS(baseKey, usage, ivec, ciphertext, start, len, true));
	return output;
}

$bytes* AesSha2DkCrypto::decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, output, decryptCTS(baseKey, usage, ivec, ciphertext, start, len, false));
	return output;
}

$bytes* AesSha2DkCrypto::encryptCTS($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len, bool confounder_exists) {
	$var($bytes, Ke, nullptr);
	$var($bytes, Ki, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(Ke, deriveKey(baseKey, usage, (int8_t)170));
			$var($bytes, toBeEncrypted, nullptr);
			if (confounder_exists) {
				$var($bytes, confounder, $Confounder::bytes(AesSha2DkCrypto::BLOCK_SIZE));
				$assign(toBeEncrypted, $new($bytes, $nc(confounder)->length + len));
				$System::arraycopy(confounder, 0, toBeEncrypted, 0, confounder->length);
				$System::arraycopy(plaintext, start, toBeEncrypted, confounder->length, len);
			} else {
				$assign(toBeEncrypted, $new($bytes, len));
				$System::arraycopy(plaintext, start, toBeEncrypted, 0, len);
			}
			$var($bytes, output, $new($bytes, $nc(toBeEncrypted)->length + this->hashSize));
			$var($Cipher, cipher, $Cipher::getInstance("AES/CTS/NoPadding"_s));
			$var($SecretKeySpec, secretKey, $new($SecretKeySpec, Ke, "AES"_s));
			$var($IvParameterSpec, encIv, $new($IvParameterSpec, ivec, 0, $nc(ivec)->length));
			$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(secretKey), static_cast<$AlgorithmParameterSpec*>(encIv));
			cipher->doFinal(toBeEncrypted, 0, toBeEncrypted->length, output);
			$assign(Ki, deriveKey(baseKey, usage, (int8_t)85));
			$var($bytes, msg, $Arrays::copyOf(ivec, $nc(ivec)->length + toBeEncrypted->length));
			$System::arraycopy(output, 0, msg, $nc(ivec)->length, toBeEncrypted->length);
			$var($bytes, hmac, getHmac(Ki, msg));
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

$bytes* AesSha2DkCrypto::decryptCTS($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len, bool confounder_exists) {
	$var($bytes, Ke, nullptr);
	$var($bytes, Ki, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(Ke, deriveKey(baseKey, usage, (int8_t)170));
			$var($Cipher, cipher, $Cipher::getInstance("AES/CTS/NoPadding"_s));
			$var($SecretKeySpec, secretKey, $new($SecretKeySpec, Ke, "AES"_s));
			$var($IvParameterSpec, encIv, $new($IvParameterSpec, ivec, 0, $nc(ivec)->length));
			$nc(cipher)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>(secretKey), static_cast<$AlgorithmParameterSpec*>(encIv));
			$var($bytes, plaintext, cipher->doFinal(ciphertext, start, len - this->hashSize));
			$assign(Ki, deriveKey(baseKey, usage, (int8_t)85));
			$var($bytes, msg, $Arrays::copyOf(ivec, $nc(ivec)->length + len - this->hashSize));
			$System::arraycopy(ciphertext, start, msg, $nc(ivec)->length, len - this->hashSize);
			$var($bytes, calculatedHmac, getHmac(Ki, msg));
			int32_t hmacOffset = start + len - this->hashSize;
			bool cksumFailed = false;
			if ($nc(calculatedHmac)->length >= this->hashSize) {
				for (int32_t i = 0; i < this->hashSize; ++i) {
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
				$var($bytes, output, $new($bytes, $nc(plaintext)->length - AesSha2DkCrypto::BLOCK_SIZE));
				$System::arraycopy(plaintext, AesSha2DkCrypto::BLOCK_SIZE, output, 0, output->length);
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

$bytes* AesSha2DkCrypto::PBKDF2($chars* secret, $bytes* salt, int32_t count, int32_t keyLength) {
	$init(AesSha2DkCrypto);
	$var($PBEKeySpec, keySpec, $new($PBEKeySpec, secret, salt, count, keyLength));
	$var($SecretKeyFactory, skf, $SecretKeyFactory::getInstance(keyLength == 128 ? "PBKDF2WithHmacSHA256"_s : "PBKDF2WithHmacSHA384"_s));
	$var($SecretKey, key, $nc(skf)->generateSecret(keySpec));
	$var($bytes, result, $nc(key)->getEncoded());
	return result;
}

int32_t AesSha2DkCrypto::readBigEndian($bytes* data, int32_t pos, int32_t size) {
	$init(AesSha2DkCrypto);
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

void clinit$AesSha2DkCrypto($Class* class$) {
	$assignStatic(AesSha2DkCrypto::ZERO_IV, $new($bytes, {
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
	$assignStatic(AesSha2DkCrypto::ETYPE_NAME_128, "aes128-cts-hmac-sha256-128"_s->getBytes());
	$assignStatic(AesSha2DkCrypto::ETYPE_NAME_256, "aes256-cts-hmac-sha384-192"_s->getBytes());
}

AesSha2DkCrypto::AesSha2DkCrypto() {
}

$Class* AesSha2DkCrypto::load$($String* name, bool initialize) {
	$loadClass(AesSha2DkCrypto, name, initialize, &_AesSha2DkCrypto_ClassInfo_, clinit$AesSha2DkCrypto, allocate$AesSha2DkCrypto);
	return class$;
}

$Class* AesSha2DkCrypto::class$ = nullptr;

					} // dk
				} // crypto
			} // internal
		} // krb5
	} // security
} // sun