#include <sun/security/krb5/Checksum.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <java/util/Arrays.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/internal/KdcErrException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef CKSUMTYPE_CRC32
#undef CKSUMTYPE_DEFAULT
#undef CKSUMTYPE_DES_MAC
#undef CKSUMTYPE_DES_MAC_K
#undef CKSUMTYPE_HMAC_MD5_ARCFOUR
#undef CKSUMTYPE_HMAC_SHA1_DES3_KD
#undef CKSUMTYPE_NULL
#undef CKSUMTYPE_RSA_MD4
#undef CKSUMTYPE_RSA_MD4_DES
#undef CKSUMTYPE_RSA_MD4_DES_K
#undef CKSUMTYPE_RSA_MD5
#undef CKSUMTYPE_RSA_MD5_DES
#undef DEBUG
#undef KRB_AP_ERR_INAPP_CKSUM
#undef SAFECKSUMTYPE_DEFAULT
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Arrays = ::java::util::Arrays;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Config = ::sun::security::krb5::Config;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KdcErrException = ::sun::security::krb5::internal::KdcErrException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $CksumType = ::sun::security::krb5::internal::crypto::CksumType;
using $EType = ::sun::security::krb5::internal::crypto::EType;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _Checksum_FieldInfo_[] = {
	{"cksumType", "I", nullptr, $PRIVATE, $field(Checksum, cksumType)},
	{"checksum", "[B", nullptr, $PRIVATE, $field(Checksum, checksum)},
	{"CKSUMTYPE_NULL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_NULL)},
	{"CKSUMTYPE_CRC32", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_CRC32)},
	{"CKSUMTYPE_RSA_MD4", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_RSA_MD4)},
	{"CKSUMTYPE_RSA_MD4_DES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_RSA_MD4_DES)},
	{"CKSUMTYPE_DES_MAC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_DES_MAC)},
	{"CKSUMTYPE_DES_MAC_K", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_DES_MAC_K)},
	{"CKSUMTYPE_RSA_MD4_DES_K", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_RSA_MD4_DES_K)},
	{"CKSUMTYPE_RSA_MD5", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_RSA_MD5)},
	{"CKSUMTYPE_RSA_MD5_DES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_RSA_MD5_DES)},
	{"CKSUMTYPE_HMAC_SHA1_DES3_KD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_HMAC_SHA1_DES3_KD)},
	{"CKSUMTYPE_HMAC_SHA1_96_AES128", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_HMAC_SHA1_96_AES128)},
	{"CKSUMTYPE_HMAC_SHA1_96_AES256", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_HMAC_SHA1_96_AES256)},
	{"CKSUMTYPE_HMAC_SHA256_128_AES128", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_HMAC_SHA256_128_AES128)},
	{"CKSUMTYPE_HMAC_SHA384_192_AES256", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_HMAC_SHA384_192_AES256)},
	{"CKSUMTYPE_HMAC_MD5_ARCFOUR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Checksum, CKSUMTYPE_HMAC_MD5_ARCFOUR)},
	{"CKSUMTYPE_DEFAULT", "I", nullptr, $STATIC, $staticField(Checksum, CKSUMTYPE_DEFAULT)},
	{"SAFECKSUMTYPE_DEFAULT", "I", nullptr, $STATIC, $staticField(Checksum, SAFECKSUMTYPE_DEFAULT)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(Checksum, DEBUG)},
	{}
};

$MethodInfo _Checksum_MethodInfo_[] = {
	{"<init>", "([BI)V", nullptr, $PUBLIC, $method(static_cast<void(Checksum::*)($bytes*,int32_t)>(&Checksum::init$))},
	{"<init>", "(I[BLsun/security/krb5/EncryptionKey;I)V", nullptr, $PUBLIC, $method(static_cast<void(Checksum::*)(int32_t,$bytes*,$EncryptionKey*,int32_t)>(&Checksum::init$)), "sun.security.krb5.internal.KdcErrException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(Checksum::*)($DerValue*)>(&Checksum::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getBytes", "()[B", nullptr, $PUBLIC | $FINAL, $method(static_cast<$bytes*(Checksum::*)()>(&Checksum::getBytes))},
	{"getType", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(Checksum::*)()>(&Checksum::getType))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"initStatic", "()V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)()>(&Checksum::initStatic))},
	{"isEqual", "(Lsun/security/krb5/Checksum;)Z", nullptr, 0, nullptr, "sun.security.krb5.internal.KdcErrException"},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/Checksum;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Checksum*(*)($DerInputStream*,int8_t,bool)>(&Checksum::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"verifyAnyChecksum", "([BLsun/security/krb5/EncryptionKey;I)Z", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KdcErrException,sun.security.krb5.KrbCryptoException"},
	{"verifyKeyedChecksum", "([BLsun/security/krb5/EncryptionKey;I)Z", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KdcErrException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{}
};

$ClassInfo _Checksum_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.Checksum",
	"java.lang.Object",
	nullptr,
	_Checksum_FieldInfo_,
	_Checksum_MethodInfo_
};

$Object* allocate$Checksum($Class* clazz) {
	return $of($alloc(Checksum));
}

int32_t Checksum::CKSUMTYPE_DEFAULT = 0;
int32_t Checksum::SAFECKSUMTYPE_DEFAULT = 0;
bool Checksum::DEBUG = false;

void Checksum::initStatic() {
	$init(Checksum);
	$var($String, temp, nullptr);
	$var($Config, cfg, nullptr);
	try {
		$assign(cfg, $Config::getInstance());
		$assign(temp, $nc(cfg)->get($$new($StringArray, {
			"libdefaults"_s,
			"default_checksum"_s
		})));
		if (temp != nullptr) {
			Checksum::CKSUMTYPE_DEFAULT = $Config::getType(temp);
		} else {
			Checksum::CKSUMTYPE_DEFAULT = -1;
		}
	} catch ($Exception&) {
		$var($Exception, exc, $catch());
		if (Checksum::DEBUG) {
			$init($System);
			$nc($System::out)->println("Exception in getting default checksum value from the configuration. No default checksum set."_s);
			exc->printStackTrace();
		}
		Checksum::CKSUMTYPE_DEFAULT = -1;
	}
	try {
		$assign(temp, $nc(cfg)->get($$new($StringArray, {
			"libdefaults"_s,
			"safe_checksum_type"_s
		})));
		if (temp != nullptr) {
			Checksum::SAFECKSUMTYPE_DEFAULT = $Config::getType(temp);
		} else {
			Checksum::SAFECKSUMTYPE_DEFAULT = -1;
		}
	} catch ($Exception&) {
		$var($Exception, exc, $catch());
		if (Checksum::DEBUG) {
			$init($System);
			$nc($System::out)->println("Exception in getting safe default checksum value from the configuration. No safe default checksum set."_s);
			exc->printStackTrace();
		}
		Checksum::SAFECKSUMTYPE_DEFAULT = -1;
	}
}

void Checksum::init$($bytes* data, int32_t new_cksumType) {
	this->cksumType = new_cksumType;
	$set(this, checksum, data);
}

void Checksum::init$(int32_t new_cksumType, $bytes* data, $EncryptionKey* key, int32_t usage) {
	if (new_cksumType == -1) {
		this->cksumType = $nc($($EType::getInstance($nc(key)->getEType())))->checksumType();
	} else {
		this->cksumType = new_cksumType;
	}
	$set(this, checksum, $nc($($CksumType::getInstance(this->cksumType)))->calculateChecksum(data, $nc(data)->length, $($nc(key)->getBytes()), usage));
}

bool Checksum::verifyKeyedChecksum($bytes* data, $EncryptionKey* key, int32_t usage) {
	$var($CksumType, cksumEngine, $CksumType::getInstance(this->cksumType));
	if (!$nc(cksumEngine)->isKeyed()) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_INAPP_CKSUM);
	} else {
		return cksumEngine->verifyChecksum(data, $nc(data)->length, $($nc(key)->getBytes()), this->checksum, usage);
	}
}

bool Checksum::verifyAnyChecksum($bytes* data, $EncryptionKey* key, int32_t usage) {
	return $nc($($CksumType::getInstance(this->cksumType)))->verifyChecksum(data, $nc(data)->length, $($nc(key)->getBytes()), this->checksum, usage);
}

bool Checksum::isEqual(Checksum* cksum) {
	if (this->cksumType != $nc(cksum)->cksumType) {
		return false;
	}
	return $CksumType::isChecksumEqual(this->checksum, $nc(cksum)->checksum);
}

void Checksum::init$($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)0) {
		this->cksumType = $nc($($nc($(der->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)1) {
		$set(this, checksum, $nc($(der->getData()))->getOctetString());
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* Checksum::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->cksumType)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putOctetString(this->checksum);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

Checksum* Checksum::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(Checksum);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(Checksum, subDer);
	}
}

$bytes* Checksum::getBytes() {
	return this->checksum;
}

int32_t Checksum::getType() {
	return this->cksumType;
}

bool Checksum::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(Checksum, obj))) {
		return false;
	}
	try {
		return isEqual($cast(Checksum, obj));
	} catch ($KdcErrException&) {
		$var($KdcErrException, kee, $catch());
		return false;
	}
	$shouldNotReachHere();
}

int32_t Checksum::hashCode() {
	int32_t result = 17;
	result = 37 * result + this->cksumType;
	if (this->checksum != nullptr) {
		result = 37 * result + $Arrays::hashCode(this->checksum);
	}
	return result;
}

void clinit$Checksum($Class* class$) {
	$init($Krb5);
	Checksum::DEBUG = $Krb5::DEBUG;
	{
		Checksum::initStatic();
	}
}

Checksum::Checksum() {
}

$Class* Checksum::load$($String* name, bool initialize) {
	$loadClass(Checksum, name, initialize, &_Checksum_ClassInfo_, clinit$Checksum, allocate$Checksum);
	return class$;
}

$Class* Checksum::class$ = nullptr;

		} // krb5
	} // security
} // sun