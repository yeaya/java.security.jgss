#include <sun/security/krb5/EncryptionKey.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <java/security/GeneralSecurityException.h>
#include <java/util/Arrays.h>
#include <javax/crypto/spec/DESKeySpec.h>
#include <javax/crypto/spec/DESedeKeySpec.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Confounder.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/KrbCryptoException.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/PAData$SaltAndParams.h>
#include <sun/security/krb5/internal/ccache/CCacheOutputStream.h>
#include <sun/security/krb5/internal/crypto/Aes128.h>
#include <sun/security/krb5/internal/crypto/Aes128Sha2.h>
#include <sun/security/krb5/internal/crypto/Aes256.h>
#include <sun/security/krb5/internal/crypto/Aes256Sha2.h>
#include <sun/security/krb5/internal/crypto/ArcFourHmac.h>
#include <sun/security/krb5/internal/crypto/Des.h>
#include <sun/security/krb5/internal/crypto/Des3.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <sun/security/krb5/internal/ktab/KeyTab.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef DEBUG
#undef ETYPE_ARCFOUR_HMAC
#undef ETYPE_DES3_CBC_HMAC_SHA1_KD
#undef ETYPE_DES_CBC_CRC
#undef ETYPE_DES_CBC_MD5
#undef ETYPE_NULL
#undef NULL_KEY
#undef TAG_CONTEXT

using $EncryptionKeyArray = $Array<::sun::security::krb5::EncryptionKey>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $BigInteger = ::java::math::BigInteger;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Arrays = ::java::util::Arrays;
using $DESKeySpec = ::javax::crypto::spec::DESKeySpec;
using $DESedeKeySpec = ::javax::crypto::spec::DESedeKeySpec;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Confounder = ::sun::security::krb5::Confounder;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $PAData$SaltAndParams = ::sun::security::krb5::internal::PAData$SaltAndParams;
using $CCacheOutputStream = ::sun::security::krb5::internal::ccache::CCacheOutputStream;
using $Aes128 = ::sun::security::krb5::internal::crypto::Aes128;
using $Aes128Sha2 = ::sun::security::krb5::internal::crypto::Aes128Sha2;
using $Aes256 = ::sun::security::krb5::internal::crypto::Aes256;
using $Aes256Sha2 = ::sun::security::krb5::internal::crypto::Aes256Sha2;
using $ArcFourHmac = ::sun::security::krb5::internal::crypto::ArcFourHmac;
using $Des = ::sun::security::krb5::internal::crypto::Des;
using $Des3 = ::sun::security::krb5::internal::crypto::Des3;
using $EType = ::sun::security::krb5::internal::crypto::EType;
using $KeyTab = ::sun::security::krb5::internal::ktab::KeyTab;
using $KrbDataOutputStream = ::sun::security::krb5::internal::util::KrbDataOutputStream;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _EncryptionKey_FieldInfo_[] = {
	{"NULL_KEY", "Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(EncryptionKey, NULL_KEY)},
	{"keyType", "I", nullptr, $PRIVATE, $field(EncryptionKey, keyType)},
	{"keyValue", "[B", nullptr, $PRIVATE, $field(EncryptionKey, keyValue)},
	{"kvno", "Ljava/lang/Integer;", nullptr, $PRIVATE, $field(EncryptionKey, kvno)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EncryptionKey, DEBUG)},
	{}
};

$MethodInfo _EncryptionKey_MethodInfo_[] = {
	{"<init>", "([BILjava/lang/Integer;)V", nullptr, $PUBLIC, $method(static_cast<void(EncryptionKey::*)($bytes*,int32_t,$Integer*)>(&EncryptionKey::init$))},
	{"<init>", "(I[B)V", nullptr, $PUBLIC, $method(static_cast<void(EncryptionKey::*)(int32_t,$bytes*)>(&EncryptionKey::init$))},
	{"<init>", "([CLjava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(EncryptionKey::*)($chars*,$String*,$String*)>(&EncryptionKey::init$)), "sun.security.krb5.KrbCryptoException"},
	{"<init>", "(Lsun/security/krb5/EncryptionKey;)V", nullptr, $PUBLIC, $method(static_cast<void(EncryptionKey::*)(EncryptionKey*)>(&EncryptionKey::init$)), "sun.security.krb5.KrbCryptoException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(EncryptionKey::*)($DerValue*)>(&EncryptionKey::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"acquireSecretKey", "(Lsun/security/krb5/PrincipalName;[CILsun/security/krb5/internal/PAData$SaltAndParams;)Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $STATIC, $method(static_cast<EncryptionKey*(*)($PrincipalName*,$chars*,int32_t,$PAData$SaltAndParams*)>(&EncryptionKey::acquireSecretKey)), "sun.security.krb5.KrbException"},
	{"acquireSecretKey", "([CLjava/lang/String;I[B)Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $STATIC, $method(static_cast<EncryptionKey*(*)($chars*,$String*,int32_t,$bytes*)>(&EncryptionKey::acquireSecretKey)), "sun.security.krb5.KrbException"},
	{"acquireSecretKeys", "(Lsun/security/krb5/PrincipalName;Ljava/lang/String;)[Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$EncryptionKeyArray*(*)($PrincipalName*,$String*)>(&EncryptionKey::acquireSecretKeys))},
	{"acquireSecretKeys", "([CLjava/lang/String;)[Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$EncryptionKeyArray*(*)($chars*,$String*)>(&EncryptionKey::acquireSecretKeys)), "sun.security.krb5.KrbException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"destroy", "()V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"findKey", "(I[Lsun/security/krb5/EncryptionKey;)Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $STATIC, $method(static_cast<EncryptionKey*(*)(int32_t,$EncryptionKeyArray*)>(&EncryptionKey::findKey)), "sun.security.krb5.KrbException"},
	{"findKey", "(ILjava/lang/Integer;[Lsun/security/krb5/EncryptionKey;)Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $STATIC, $method(static_cast<EncryptionKey*(*)(int32_t,$Integer*,$EncryptionKeyArray*)>(&EncryptionKey::findKey)), "sun.security.krb5.KrbException"},
	{"getBytes", "()[B", nullptr, $PUBLIC | $FINAL, $method(static_cast<$bytes*(EncryptionKey::*)()>(&EncryptionKey::getBytes))},
	{"getEType", "()I", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"getKeyVersionNumber", "()Ljava/lang/Integer;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Integer*(EncryptionKey::*)()>(&EncryptionKey::getKeyVersionNumber))},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $STATIC, $method(static_cast<EncryptionKey*(*)($DerInputStream*,int8_t,bool)>(&EncryptionKey::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"stringToKey", "([CLjava/lang/String;[BI)[B", nullptr, $PRIVATE | $STATIC, $method(static_cast<$bytes*(*)($chars*,$String*,$bytes*,int32_t)>(&EncryptionKey::stringToKey)), "sun.security.krb5.KrbCryptoException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"versionMatches", "(Ljava/lang/Integer;Ljava/lang/Integer;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($Integer*,$Integer*)>(&EncryptionKey::versionMatches))},
	{"writeKey", "(Lsun/security/krb5/internal/ccache/CCacheOutputStream;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _EncryptionKey_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.EncryptionKey",
	"java.lang.Object",
	"java.lang.Cloneable",
	_EncryptionKey_FieldInfo_,
	_EncryptionKey_MethodInfo_
};

$Object* allocate$EncryptionKey($Class* clazz) {
	return $of($alloc(EncryptionKey));
}

EncryptionKey* EncryptionKey::NULL_KEY = nullptr;
bool EncryptionKey::DEBUG = false;

int32_t EncryptionKey::getEType() {
	$synchronized(this) {
		return this->keyType;
	}
}

$Integer* EncryptionKey::getKeyVersionNumber() {
	return this->kvno;
}

$bytes* EncryptionKey::getBytes() {
	return this->keyValue;
}

$Object* EncryptionKey::clone() {
	$synchronized(this) {
		return $of($new(EncryptionKey, this->keyValue, this->keyType, this->kvno));
	}
}

$EncryptionKeyArray* EncryptionKey::acquireSecretKeys($PrincipalName* princ, $String* keytab) {
	$init(EncryptionKey);
	if (princ == nullptr) {
		$throwNew($IllegalArgumentException, "Cannot have null pricipal name to look in keytab."_s);
	}
	$var($KeyTab, ktab, $KeyTab::getInstance(keytab));
	return $nc(ktab)->readServiceKeys(princ);
}

EncryptionKey* EncryptionKey::acquireSecretKey($PrincipalName* cname, $chars* password, int32_t etype, $PAData$SaltAndParams* snp) {
	$init(EncryptionKey);
	$var($String, salt, nullptr);
	$var($bytes, s2kparams, nullptr);
	if (snp != nullptr) {
		$assign(salt, snp->salt != nullptr ? snp->salt : $nc(cname)->getSalt());
		$assign(s2kparams, snp->params);
	} else {
		$assign(salt, $nc(cname)->getSalt());
		$assign(s2kparams, nullptr);
	}
	return acquireSecretKey(password, salt, etype, s2kparams);
}

EncryptionKey* EncryptionKey::acquireSecretKey($chars* password, $String* salt, int32_t etype, $bytes* s2kparams) {
	$init(EncryptionKey);
	return $new(EncryptionKey, $(stringToKey(password, salt, s2kparams, etype)), etype, ($Integer*)nullptr);
}

$EncryptionKeyArray* EncryptionKey::acquireSecretKeys($chars* password, $String* salt) {
	$init(EncryptionKey);
	$var($ints, etypes, $EType::getDefaults("default_tkt_enctypes"_s));
	$var($EncryptionKeyArray, encKeys, $new($EncryptionKeyArray, $nc(etypes)->length));
	for (int32_t i = 0; i < etypes->length; ++i) {
		if ($EType::isSupported(etypes->get(i))) {
			encKeys->set(i, $$new(EncryptionKey, $(stringToKey(password, salt, nullptr, etypes->get(i))), etypes->get(i), ($Integer*)nullptr));
		} else {
			if (EncryptionKey::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"Encryption Type "_s, $($EType::toString(etypes->get(i))), " is not supported/enabled"_s}));
			}
		}
	}
	return encKeys;
}

void EncryptionKey::init$($bytes* keyValue, int32_t keyType, $Integer* kvno) {
	if (keyValue != nullptr) {
		$set(this, keyValue, $new($bytes, keyValue->length));
		$System::arraycopy(keyValue, 0, this->keyValue, 0, keyValue->length);
	} else {
		$throwNew($IllegalArgumentException, "EncryptionKey: Key bytes cannot be null!"_s);
	}
	this->keyType = keyType;
	$set(this, kvno, kvno);
}

void EncryptionKey::init$(int32_t keyType, $bytes* keyValue) {
	EncryptionKey::init$(keyValue, keyType, ($Integer*)nullptr);
}

$bytes* EncryptionKey::stringToKey($chars* password, $String* salt, $bytes* s2kparams, int32_t keyType) {
	$init(EncryptionKey);
	$var($chars, slt, $nc(salt)->toCharArray());
	$var($chars, pwsalt, $new($chars, $nc(password)->length + slt->length));
	$System::arraycopy(password, 0, pwsalt, 0, password->length);
	$System::arraycopy(slt, 0, pwsalt, password->length, slt->length);
	$Arrays::fill(slt, u'0');
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				switch (keyType) {
				case $EncryptedData::ETYPE_DES_CBC_CRC:
					{}
				case $EncryptedData::ETYPE_DES_CBC_MD5:
					{
						$assign(var$2, $Des::string_to_key_bytes(pwsalt));
						return$1 = true;
						goto $finally;
					}
				case $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD:
					{
						$assign(var$2, $Des3::stringToKey(pwsalt));
						return$1 = true;
						goto $finally;
					}
				case $EncryptedData::ETYPE_ARCFOUR_HMAC:
					{
						$assign(var$2, $ArcFourHmac::stringToKey(password));
						return$1 = true;
						goto $finally;
					}
				case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
					{
						$assign(var$2, $Aes128::stringToKey(password, salt, s2kparams));
						return$1 = true;
						goto $finally;
					}
				case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
					{
						$assign(var$2, $Aes256::stringToKey(password, salt, s2kparams));
						return$1 = true;
						goto $finally;
					}
				case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
					{
						$assign(var$2, $Aes128Sha2::stringToKey(password, salt, s2kparams));
						return$1 = true;
						goto $finally;
					}
				case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
					{
						$assign(var$2, $Aes256Sha2::stringToKey(password, salt, s2kparams));
						return$1 = true;
						goto $finally;
					}
				default:
					{
						$throwNew($IllegalArgumentException, $$str({"encryption type "_s, $($EType::toString(keyType)), " not supported"_s}));
					}
				}
			} catch ($GeneralSecurityException&) {
				$var($GeneralSecurityException, e, $catch());
				$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
				ke->initCause(e);
				$throw(ke);
			}
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			$Arrays::fill(pwsalt, u'0');
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

void EncryptionKey::init$($chars* password, $String* salt, $String* algorithm) {
	bool var$0 = algorithm == nullptr || $nc(algorithm)->equalsIgnoreCase("DES"_s);
	if (var$0 || $nc(algorithm)->equalsIgnoreCase("des-cbc-md5"_s)) {
		this->keyType = $EncryptedData::ETYPE_DES_CBC_MD5;
	} else if (algorithm->equalsIgnoreCase("des-cbc-crc"_s)) {
		this->keyType = $EncryptedData::ETYPE_DES_CBC_CRC;
	} else {
		bool var$2 = algorithm->equalsIgnoreCase("DESede"_s);
		if (var$2 || algorithm->equalsIgnoreCase("des3-cbc-sha1-kd"_s)) {
			this->keyType = $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD;
		} else {
			bool var$4 = algorithm->equalsIgnoreCase("AES128"_s);
			if (var$4 || algorithm->equalsIgnoreCase("aes128-cts-hmac-sha1-96"_s)) {
				this->keyType = $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96;
			} else {
				bool var$6 = algorithm->equalsIgnoreCase("ArcFourHmac"_s);
				if (var$6 || algorithm->equalsIgnoreCase("rc4-hmac"_s)) {
					this->keyType = $EncryptedData::ETYPE_ARCFOUR_HMAC;
				} else {
					bool var$8 = algorithm->equalsIgnoreCase("AES256"_s);
					if (var$8 || algorithm->equalsIgnoreCase("aes256-cts-hmac-sha1-96"_s)) {
						this->keyType = $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96;
						if (!$EType::isSupported(this->keyType)) {
							$throwNew($IllegalArgumentException, $$str({"Algorithm "_s, algorithm, " not enabled"_s}));
						}
					} else if (algorithm->equalsIgnoreCase("aes128-cts-hmac-sha256-128"_s)) {
						this->keyType = $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128;
					} else if (algorithm->equalsIgnoreCase("aes256-cts-hmac-sha384-192"_s)) {
						this->keyType = $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192;
						if (!$EType::isSupported(this->keyType)) {
							$throwNew($IllegalArgumentException, $$str({"Algorithm "_s, algorithm, " not enabled"_s}));
						}
					} else {
						$throwNew($IllegalArgumentException, $$str({"Algorithm "_s, algorithm, " not supported"_s}));
					}
				}
			}
		}
	}
	$set(this, keyValue, stringToKey(password, salt, nullptr, this->keyType));
	$set(this, kvno, nullptr);
}

void EncryptionKey::init$(EncryptionKey* key) {
	$set(this, keyValue, $Confounder::bytes($nc($nc(key)->keyValue)->length));
	for (int32_t i = 0; i < $nc(this->keyValue)->length; ++i) {
		(*$nc(this->keyValue))[i] ^= $nc($nc(key)->keyValue)->get(i);
	}
	this->keyType = $nc(key)->keyType;
	try {
		if ((this->keyType == $EncryptedData::ETYPE_DES_CBC_MD5) || (this->keyType == $EncryptedData::ETYPE_DES_CBC_CRC)) {
			if (!$DESKeySpec::isParityAdjusted(this->keyValue, 0)) {
				$set(this, keyValue, $Des::set_parity(this->keyValue));
			}
			if ($DESKeySpec::isWeak(this->keyValue, 0)) {
				$nc(this->keyValue)->set(7, (int8_t)($nc(this->keyValue)->get(7) ^ 240));
			}
		}
		if (this->keyType == $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD) {
			if (!$DESedeKeySpec::isParityAdjusted(this->keyValue, 0)) {
				$set(this, keyValue, $Des3::parityFix(this->keyValue));
			}
			$var($bytes, oneKey, $new($bytes, 8));
			for (int32_t i = 0; i < $nc(this->keyValue)->length; i += 8) {
				$System::arraycopy(this->keyValue, i, oneKey, 0, 8);
				if ($DESKeySpec::isWeak(oneKey, 0)) {
					$nc(this->keyValue)->set(i + 7, (int8_t)($nc(this->keyValue)->get(i + 7) ^ 240));
				}
			}
		}
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
}

void EncryptionKey::init$($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)0) {
		this->keyType = $nc($($nc($(der->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)1) {
		$set(this, keyValue, $nc($(der->getData()))->getOctetString());
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($($nc(der)->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* EncryptionKey::asn1Encode() {
	$synchronized(this) {
		$var($DerOutputStream, bytes, $new($DerOutputStream));
		$var($DerOutputStream, temp, $new($DerOutputStream));
		temp->putInteger(this->keyType);
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
		$assign(temp, $new($DerOutputStream));
		temp->putOctetString(this->keyValue);
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
		$assign(temp, $new($DerOutputStream));
		temp->write($DerValue::tag_Sequence, bytes);
		return temp->toByteArray();
	}
}

void EncryptionKey::destroy() {
	$synchronized(this) {
		if (this->keyValue != nullptr) {
			for (int32_t i = 0; i < $nc(this->keyValue)->length; ++i) {
				$nc(this->keyValue)->set(i, (int8_t)0);
			}
		}
	}
}

EncryptionKey* EncryptionKey::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(EncryptionKey);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(EncryptionKey, subDer);
	}
}

void EncryptionKey::writeKey($CCacheOutputStream* cos) {
	$synchronized(this) {
		$nc(cos)->write16(this->keyType);
		cos->write16(this->keyType);
		cos->write32($nc(this->keyValue)->length);
		for (int32_t i = 0; i < $nc(this->keyValue)->length; ++i) {
			cos->write8($nc(this->keyValue)->get(i));
		}
	}
}

$String* EncryptionKey::toString() {
	$var($String, var$0, $$str({"EncryptionKey: keyType="_s, $$str(this->keyType), " kvno="_s, this->kvno, " keyValue (hex dump)="_s}));
	$init($Krb5);
	return $new($String, $$concat(var$0, (this->keyValue == nullptr || $nc(this->keyValue)->length == 0 ? " Empty Key"_s : $$str({$$str(u'\n'), $($nc($Krb5::hexDumper)->encodeBuffer(this->keyValue)), $$str(u'\n')}))));
}

EncryptionKey* EncryptionKey::findKey(int32_t etype, $EncryptionKeyArray* keys) {
	$init(EncryptionKey);
	return findKey(etype, nullptr, keys);
}

bool EncryptionKey::versionMatches($Integer* v1, $Integer* v2) {
	$init(EncryptionKey);
	bool var$0 = v1 == nullptr || $nc(v1)->intValue() == 0 || v2 == nullptr;
	if (var$0 || $nc(v2)->intValue() == 0) {
		return true;
	}
	return $nc(v1)->equals(v2);
}

EncryptionKey* EncryptionKey::findKey(int32_t etype, $Integer* kvno, $EncryptionKeyArray* keys) {
	$init(EncryptionKey);
	if (!$EType::isSupported(etype)) {
		$throwNew($KrbException, $$str({"Encryption type "_s, $($EType::toString(etype)), " is not supported/enabled"_s}));
	}
	int32_t ktype = 0;
	bool etypeFound = false;
	int32_t kvno_found = 0;
	$var(EncryptionKey, key_found, nullptr);
	for (int32_t i = 0; i < $nc(keys)->length; ++i) {
		ktype = $nc(keys->get(i))->getEType();
		if ($EType::isSupported(ktype)) {
			$var($Integer, kv, $nc(keys->get(i))->getKeyVersionNumber());
			if (etype == ktype) {
				etypeFound = true;
				if (versionMatches(kvno, kv)) {
					return keys->get(i);
				} else if (kv->intValue() > kvno_found) {
					$assign(key_found, keys->get(i));
					kvno_found = kv->intValue();
				}
			}
		}
	}
	if (etype == $EncryptedData::ETYPE_DES_CBC_CRC || etype == $EncryptedData::ETYPE_DES_CBC_MD5) {
		for (int32_t i = 0; i < $nc(keys)->length; ++i) {
			ktype = $nc(keys->get(i))->getEType();
			if (ktype == $EncryptedData::ETYPE_DES_CBC_CRC || ktype == $EncryptedData::ETYPE_DES_CBC_MD5) {
				$var($Integer, kv, $nc(keys->get(i))->getKeyVersionNumber());
				etypeFound = true;
				if (versionMatches(kvno, kv)) {
					return $new(EncryptionKey, etype, $($nc(keys->get(i))->getBytes()));
				} else if (kv->intValue() > kvno_found) {
					$assign(key_found, $new(EncryptionKey, etype, $($nc(keys->get(i))->getBytes())));
					kvno_found = kv->intValue();
				}
			}
		}
	}
	if (etypeFound) {
		return key_found;
	}
	return nullptr;
}

void clinit$EncryptionKey($Class* class$) {
	$assignStatic(EncryptionKey::NULL_KEY, $new(EncryptionKey, $$new($bytes, 0), $EncryptedData::ETYPE_NULL, ($Integer*)nullptr));
	$init($Krb5);
	EncryptionKey::DEBUG = $Krb5::DEBUG;
}

EncryptionKey::EncryptionKey() {
}

$Class* EncryptionKey::load$($String* name, bool initialize) {
	$loadClass(EncryptionKey, name, initialize, &_EncryptionKey_ClassInfo_, clinit$EncryptionKey, allocate$EncryptionKey);
	return class$;
}

$Class* EncryptionKey::class$ = nullptr;

		} // krb5
	} // security
} // sun