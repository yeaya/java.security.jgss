#include <sun/security/krb5/internal/crypto/EType.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Boolean.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <javax/crypto/Cipher.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/internal/KdcErrException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/Aes128CtsHmacSha1EType.h>
#include <sun/security/krb5/internal/crypto/Aes128CtsHmacSha2EType.h>
#include <sun/security/krb5/internal/crypto/Aes256CtsHmacSha1EType.h>
#include <sun/security/krb5/internal/crypto/Aes256CtsHmacSha2EType.h>
#include <sun/security/krb5/internal/crypto/ArcFourHmacEType.h>
#include <sun/security/krb5/internal/crypto/Des3CbcHmacSha1KdEType.h>
#include <sun/security/krb5/internal/crypto/DesCbcCrcEType.h>
#include <sun/security/krb5/internal/crypto/DesCbcEType.h>
#include <sun/security/krb5/internal/crypto/DesCbcMd5EType.h>
#include <sun/security/krb5/internal/crypto/NullEType.h>
#include <jcpp.h>

#undef BUILTIN_ETYPES
#undef BUILTIN_ETYPES_NOAES256
#undef DEBUG
#undef ETYPE_ARCFOUR_HMAC
#undef ETYPE_ARCFOUR_HMAC_EXP
#undef ETYPE_DES3_CBC_HMAC_SHA1_KD
#undef ETYPE_DES_CBC_CRC
#undef ETYPE_DES_CBC_MD4
#undef ETYPE_DES_CBC_MD5
#undef ETYPE_NULL
#undef KDC_ERR_ETYPE_NOSUPP
#undef TRUE

using $EncryptionKeyArray = $Array<::sun::security::krb5::EncryptionKey>;
using $PrintStream = ::java::io::PrintStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $List = ::java::util::List;
using $Cipher = ::javax::crypto::Cipher;
using $Config = ::sun::security::krb5::Config;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $KdcErrException = ::sun::security::krb5::internal::KdcErrException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Aes128CtsHmacSha1EType = ::sun::security::krb5::internal::crypto::Aes128CtsHmacSha1EType;
using $Aes128CtsHmacSha2EType = ::sun::security::krb5::internal::crypto::Aes128CtsHmacSha2EType;
using $Aes256CtsHmacSha1EType = ::sun::security::krb5::internal::crypto::Aes256CtsHmacSha1EType;
using $Aes256CtsHmacSha2EType = ::sun::security::krb5::internal::crypto::Aes256CtsHmacSha2EType;
using $ArcFourHmacEType = ::sun::security::krb5::internal::crypto::ArcFourHmacEType;
using $Des3CbcHmacSha1KdEType = ::sun::security::krb5::internal::crypto::Des3CbcHmacSha1KdEType;
using $DesCbcCrcEType = ::sun::security::krb5::internal::crypto::DesCbcCrcEType;
using $DesCbcEType = ::sun::security::krb5::internal::crypto::DesCbcEType;
using $DesCbcMd5EType = ::sun::security::krb5::internal::crypto::DesCbcMd5EType;
using $NullEType = ::sun::security::krb5::internal::crypto::NullEType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$FieldInfo _EType_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EType, DEBUG)},
	{"allowWeakCrypto", "Z", nullptr, $PRIVATE | $STATIC, $staticField(EType, allowWeakCrypto)},
	{"BUILTIN_ETYPES", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EType, BUILTIN_ETYPES)},
	{"BUILTIN_ETYPES_NOAES256", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EType, BUILTIN_ETYPES_NOAES256)},
	{}
};

$MethodInfo _EType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(EType::*)()>(&EType::init$))},
	{"blockSize", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"checksumSize", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"checksumType", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"confounderSize", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"dataSize", "([B)I", nullptr, $PUBLIC},
	{"decrypt", "([B[BI)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"decrypt", "([B[B[BI)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"decryptedData", "([B)[B", nullptr, $PUBLIC},
	{"eType", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"encrypt", "([B[BI)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"encrypt", "([B[B[BI)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"getBuiltInDefaults", "()[I", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ints*(*)()>(&EType::getBuiltInDefaults))},
	{"getDefaults", "(Ljava/lang/String;)[I", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ints*(*)($String*)>(&EType::getDefaults)), "sun.security.krb5.KrbException"},
	{"getDefaults", "(Ljava/lang/String;[Lsun/security/krb5/EncryptionKey;)[I", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ints*(*)($String*,$EncryptionKeyArray*)>(&EType::getDefaults)), "sun.security.krb5.KrbException"},
	{"getInstance", "(I)Lsun/security/krb5/internal/crypto/EType;", nullptr, $PUBLIC | $STATIC, $method(static_cast<EType*(*)(int32_t)>(&EType::getInstance)), "sun.security.krb5.internal.KdcErrException"},
	{"initStatic", "()V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)()>(&EType::initStatic))},
	{"isNewer", "(I)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)(int32_t)>(&EType::isNewer))},
	{"isSupported", "(I[I)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)(int32_t,$ints*)>(&EType::isSupported))},
	{"isSupported", "(I)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)(int32_t)>(&EType::isSupported))},
	{"keySize", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"keyType", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"minimumPadSize", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"padSize", "([B)I", nullptr, $PUBLIC},
	{"startOfChecksum", "()I", nullptr, $PUBLIC},
	{"startOfData", "()I", nullptr, $PUBLIC},
	{"startOfPad", "([B)I", nullptr, $PUBLIC},
	{"toString", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)(int32_t)>(&EType::toString))},
	{}
};

$ClassInfo _EType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.internal.crypto.EType",
	"java.lang.Object",
	nullptr,
	_EType_FieldInfo_,
	_EType_MethodInfo_
};

$Object* allocate$EType($Class* clazz) {
	return $of($alloc(EType));
}

bool EType::DEBUG = false;
bool EType::allowWeakCrypto = false;
$ints* EType::BUILTIN_ETYPES = nullptr;
$ints* EType::BUILTIN_ETYPES_NOAES256 = nullptr;

void EType::init$() {
}

void EType::initStatic() {
	$init(EType);
	bool allowed = false;
	try {
		$var($Config, cfg, $Config::getInstance());
		$init($Boolean);
		allowed = $nc(cfg)->getBooleanObject($$new($StringArray, {
			"libdefaults"_s,
			"allow_weak_crypto"_s
		})) == $Boolean::TRUE;
	} catch ($Exception&) {
		$var($Exception, exc, $catch());
		if (EType::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({"Exception in getting allow_weak_crypto, using default value: "_s, $(exc->getMessage())}));
		}
	}
	EType::allowWeakCrypto = allowed;
}

EType* EType::getInstance(int32_t eTypeConst) {
	$init(EType);
	$var(EType, eType, nullptr);
	$var($String, eTypeName, nullptr);
	{
		$var($String, msg, nullptr)
		switch (eTypeConst) {
		case $EncryptedData::ETYPE_NULL:
			{
				$assign(eType, $new($NullEType));
				$assign(eTypeName, "sun.security.krb5.internal.crypto.NullEType"_s);
				break;
			}
		case $EncryptedData::ETYPE_DES_CBC_CRC:
			{
				$assign(eType, $new($DesCbcCrcEType));
				$assign(eTypeName, "sun.security.krb5.internal.crypto.DesCbcCrcEType"_s);
				break;
			}
		case $EncryptedData::ETYPE_DES_CBC_MD5:
			{
				$assign(eType, $new($DesCbcMd5EType));
				$assign(eTypeName, "sun.security.krb5.internal.crypto.DesCbcMd5EType"_s);
				break;
			}
		case $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD:
			{
				$assign(eType, $new($Des3CbcHmacSha1KdEType));
				$assign(eTypeName, "sun.security.krb5.internal.crypto.Des3CbcHmacSha1KdEType"_s);
				break;
			}
		case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
			{
				$assign(eType, $new($Aes128CtsHmacSha1EType));
				$assign(eTypeName, "sun.security.krb5.internal.crypto.Aes128CtsHmacSha1EType"_s);
				break;
			}
		case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
			{
				$assign(eType, $new($Aes256CtsHmacSha1EType));
				$assign(eTypeName, "sun.security.krb5.internal.crypto.Aes256CtsHmacSha1EType"_s);
				break;
			}
		case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
			{
				$assign(eType, $new($Aes128CtsHmacSha2EType));
				$assign(eTypeName, "sun.security.krb5.internal.crypto.Aes128CtsHmacSha2EType"_s);
				break;
			}
		case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
			{
				$assign(eType, $new($Aes256CtsHmacSha2EType));
				$assign(eTypeName, "sun.security.krb5.internal.crypto.Aes256CtsHmacSha2EType"_s);
				break;
			}
		case $EncryptedData::ETYPE_ARCFOUR_HMAC:
			{
				$assign(eType, $new($ArcFourHmacEType));
				$assign(eTypeName, "sun.security.krb5.internal.crypto.ArcFourHmacEType"_s);
				break;
			}
		default:
			{
				$assign(msg, $str({"encryption type = "_s, $(toString(eTypeConst)), " ("_s, $$str(eTypeConst), ")"_s}));
				$throwNew($KdcErrException, $Krb5::KDC_ERR_ETYPE_NOSUPP, msg);
			}
		}
	}
	if (EType::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>> EType: "_s, eTypeName}));
	}
	return eType;
}

int32_t EType::dataSize($bytes* data) {
	return $nc(data)->length - startOfData();
}

int32_t EType::padSize($bytes* data) {
	int32_t var$1 = $nc(data)->length - confounderSize();
	int32_t var$0 = var$1 - checksumSize();
	return var$0 - dataSize(data);
}

int32_t EType::startOfChecksum() {
	return confounderSize();
}

int32_t EType::startOfData() {
	int32_t var$0 = confounderSize();
	return var$0 + checksumSize();
}

int32_t EType::startOfPad($bytes* data) {
	int32_t var$1 = confounderSize();
	int32_t var$0 = var$1 + checksumSize();
	return var$0 + dataSize(data);
}

$bytes* EType::decryptedData($bytes* data) {
	int32_t tempSize = dataSize(data);
	$var($bytes, result, $new($bytes, tempSize));
	$System::arraycopy(data, startOfData(), result, 0, tempSize);
	return result;
}

$ints* EType::getBuiltInDefaults() {
	$init(EType);
	int32_t allowed = 0;
	try {
		allowed = $Cipher::getMaxAllowedKeyLength("AES"_s);
	} catch ($Exception&) {
		$catch();
	}
	$var($ints, result, nullptr);
	if (allowed < 256) {
		$assign(result, EType::BUILTIN_ETYPES_NOAES256);
	} else {
		$assign(result, EType::BUILTIN_ETYPES);
	}
	if (!EType::allowWeakCrypto) {
		return $Arrays::copyOfRange(result, 0, $nc(result)->length - 4);
	}
	return result;
}

$ints* EType::getDefaults($String* configName) {
	$init(EType);
	$var($Config, config, nullptr);
	try {
		$assign(config, $Config::getInstance());
	} catch ($KrbException&) {
		$var($KrbException, exc, $catch());
		if (EType::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({"Exception while getting "_s, configName, ": "_s, $(exc->getMessage())}));
			$nc($System::out)->println("Using default builtin etypes"_s);
		}
		return getBuiltInDefaults();
	}
	return $nc(config)->defaultEtype(configName);
}

$ints* EType::getDefaults($String* configName, $EncryptionKeyArray* keys) {
	$init(EType);
	$var($ints, answer, getDefaults(configName));
	$var($List, list, $new($ArrayList, $nc(answer)->length));
	for (int32_t i = 0; i < $nc(answer)->length; ++i) {
		if ($EncryptionKey::findKey(answer->get(i), keys) != nullptr) {
			list->add($($Integer::valueOf(answer->get(i))));
		}
	}
	int32_t len = list->size();
	if (len <= 0) {
		$var($StringBuilder, keystr, $new($StringBuilder));
		for (int32_t i = 0; i < $nc(keys)->length; ++i) {
			keystr->append($(toString($nc(keys->get(i))->getEType())));
			keystr->append(" "_s);
		}
		$throwNew($KrbException, $$str({"Do not have keys of types listed in "_s, configName, " available; only have keys of following type: "_s, $(keystr->toString())}));
	} else {
		$assign(answer, $new($ints, len));
		for (int32_t i = 0; i < len; ++i) {
			answer->set(i, $nc(($cast($Integer, $(list->get(i)))))->intValue());
		}
		return answer;
	}
}

bool EType::isSupported(int32_t eTypeConst, $ints* config) {
	$init(EType);
	for (int32_t i = 0; i < $nc(config)->length; ++i) {
		if (eTypeConst == config->get(i)) {
			return true;
		}
	}
	return false;
}

bool EType::isSupported(int32_t eTypeConst) {
	$init(EType);
	$var($ints, enabledETypes, getBuiltInDefaults());
	return isSupported(eTypeConst, enabledETypes);
}

bool EType::isNewer(int32_t eTypeConst) {
	$init(EType);
	return eTypeConst != $EncryptedData::ETYPE_DES_CBC_CRC && eTypeConst != $EncryptedData::ETYPE_DES_CBC_MD4 && eTypeConst != $EncryptedData::ETYPE_DES_CBC_MD5 && eTypeConst != $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD && eTypeConst != $EncryptedData::ETYPE_ARCFOUR_HMAC && eTypeConst != $EncryptedData::ETYPE_ARCFOUR_HMAC_EXP;
}

$String* EType::toString(int32_t type) {
	$init(EType);
	switch (type) {
	case 0:
		{
			return "NULL"_s;
		}
	case 1:
		{
			return "DES CBC mode with CRC-32"_s;
		}
	case 2:
		{
			return "DES CBC mode with MD4"_s;
		}
	case 3:
		{
			return "DES CBC mode with MD5"_s;
		}
	case 4:
		{
			return "reserved"_s;
		}
	case 5:
		{
			return "DES3 CBC mode with MD5"_s;
		}
	case 6:
		{
			return "reserved"_s;
		}
	case 7:
		{
			return "DES3 CBC mode with SHA1"_s;
		}
	case 9:
		{
			return "DSA with SHA1- Cms0ID"_s;
		}
	case 10:
		{
			return "MD5 with RSA encryption - Cms0ID"_s;
		}
	case 11:
		{
			return "SHA1 with RSA encryption - Cms0ID"_s;
		}
	case 12:
		{
			return "RC2 CBC mode with Env0ID"_s;
		}
	case 13:
		{
			return "RSA encryption with Env0ID"_s;
		}
	case 14:
		{
			return "RSAES-0AEP-ENV-0ID"_s;
		}
	case 15:
		{
			return "DES-EDE3-CBC-ENV-0ID"_s;
		}
	case 16:
		{
			return "DES3 CBC mode with SHA1-KD"_s;
		}
	case 17:
		{
			return "AES128 CTS mode with HMAC SHA1-96"_s;
		}
	case 18:
		{
			return "AES256 CTS mode with HMAC SHA1-96"_s;
		}
	case 23:
		{
			return "RC4 with HMAC"_s;
		}
	case 24:
		{
			return "RC4 with HMAC EXP"_s;
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
		{
			return "AES128 CTS mode with HMAC SHA256-128"_s;
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
		{
			return "AES256 CTS mode with HMAC SHA384-192"_s;
		}
	}
	return $str({"Unknown ("_s, $$str(type), ")"_s});
}

void clinit$EType($Class* class$) {
	$init($Krb5);
	EType::DEBUG = $Krb5::DEBUG;
	{
		EType::initStatic();
	}
	$assignStatic(EType::BUILTIN_ETYPES, $new($ints, {
		$EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96,
		$EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96,
		$EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192,
		$EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128,
		$EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD,
		$EncryptedData::ETYPE_ARCFOUR_HMAC,
		$EncryptedData::ETYPE_DES_CBC_CRC,
		$EncryptedData::ETYPE_DES_CBC_MD5
	}));
	$assignStatic(EType::BUILTIN_ETYPES_NOAES256, $new($ints, {
		$EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96,
		$EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128,
		$EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD,
		$EncryptedData::ETYPE_ARCFOUR_HMAC,
		$EncryptedData::ETYPE_DES_CBC_CRC,
		$EncryptedData::ETYPE_DES_CBC_MD5
	}));
}

EType::EType() {
}

$Class* EType::load$($String* name, bool initialize) {
	$loadClass(EType, name, initialize, &_EType_ClassInfo_, clinit$EType, allocate$EType);
	return class$;
}

$Class* EType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun