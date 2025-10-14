#include <sun/security/krb5/EncryptedData.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbCryptoException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef ETYPE_ARCFOUR_HMAC
#undef ETYPE_ARCFOUR_HMAC_EXP
#undef ETYPE_DES3_CBC_HMAC_SHA1_KD
#undef ETYPE_DES_CBC_CRC
#undef ETYPE_DES_CBC_MD4
#undef ETYPE_DES_CBC_MD5
#undef ETYPE_NULL
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $EType = ::sun::security::krb5::internal::crypto::EType;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _EncryptedData_FieldInfo_[] = {
	{"eType", "I", nullptr, 0, $field(EncryptedData, eType)},
	{"kvno", "Ljava/lang/Integer;", nullptr, 0, $field(EncryptedData, kvno)},
	{"cipher", "[B", nullptr, 0, $field(EncryptedData, cipher)},
	{"plain", "[B", nullptr, 0, $field(EncryptedData, plain)},
	{"ETYPE_NULL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_NULL)},
	{"ETYPE_DES_CBC_CRC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_DES_CBC_CRC)},
	{"ETYPE_DES_CBC_MD4", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_DES_CBC_MD4)},
	{"ETYPE_DES_CBC_MD5", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_DES_CBC_MD5)},
	{"ETYPE_ARCFOUR_HMAC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_ARCFOUR_HMAC)},
	{"ETYPE_ARCFOUR_HMAC_EXP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_ARCFOUR_HMAC_EXP)},
	{"ETYPE_DES3_CBC_HMAC_SHA1_KD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_DES3_CBC_HMAC_SHA1_KD)},
	{"ETYPE_AES128_CTS_HMAC_SHA1_96", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_AES128_CTS_HMAC_SHA1_96)},
	{"ETYPE_AES256_CTS_HMAC_SHA1_96", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_AES256_CTS_HMAC_SHA1_96)},
	{"ETYPE_AES128_CTS_HMAC_SHA256_128", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_AES128_CTS_HMAC_SHA256_128)},
	{"ETYPE_AES256_CTS_HMAC_SHA384_192", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(EncryptedData, ETYPE_AES256_CTS_HMAC_SHA384_192)},
	{}
};

$MethodInfo _EncryptedData_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(EncryptedData::*)()>(&EncryptedData::init$))},
	{"<init>", "(ILjava/lang/Integer;[B)V", nullptr, $PUBLIC, $method(static_cast<void(EncryptedData::*)(int32_t,$Integer*,$bytes*)>(&EncryptedData::init$))},
	{"<init>", "(Lsun/security/krb5/EncryptionKey;[BI)V", nullptr, $PUBLIC, $method(static_cast<void(EncryptedData::*)($EncryptionKey*,$bytes*,int32_t)>(&EncryptedData::init$)), "sun.security.krb5.internal.KdcErrException,sun.security.krb5.KrbCryptoException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(EncryptedData::*)($DerValue*)>(&EncryptedData::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"decrypt", "(Lsun/security/krb5/EncryptionKey;I)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KdcErrException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"decryptedData", "()[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(EncryptedData::*)()>(&EncryptedData::decryptedData)), "sun.security.krb5.internal.KdcErrException"},
	{"getBytes", "()[B", nullptr, $PUBLIC},
	{"getEType", "()I", nullptr, $PUBLIC},
	{"getKeyVersionNumber", "()Ljava/lang/Integer;", nullptr, $PUBLIC},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/EncryptedData;", nullptr, $PUBLIC | $STATIC, $method(static_cast<EncryptedData*(*)($DerInputStream*,int8_t,bool)>(&EncryptedData::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"reset", "([B)[B", nullptr, $PUBLIC},
	{}
};

$ClassInfo _EncryptedData_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.EncryptedData",
	"java.lang.Object",
	"java.lang.Cloneable",
	_EncryptedData_FieldInfo_,
	_EncryptedData_MethodInfo_
};

$Object* allocate$EncryptedData($Class* clazz) {
	return $of($alloc(EncryptedData));
}

void EncryptedData::init$() {
}

$Object* EncryptedData::clone() {
	$var(EncryptedData, new_encryptedData, $new(EncryptedData));
	new_encryptedData->eType = this->eType;
	if (this->kvno != nullptr) {
		$set(new_encryptedData, kvno, $Integer::valueOf($nc(this->kvno)->intValue()));
	}
	if (this->cipher != nullptr) {
		$set(new_encryptedData, cipher, $new($bytes, $nc(this->cipher)->length));
		$System::arraycopy(this->cipher, 0, new_encryptedData->cipher, 0, $nc(this->cipher)->length);
	}
	return $of(new_encryptedData);
}

void EncryptedData::init$(int32_t new_eType, $Integer* new_kvno, $bytes* new_cipher) {
	this->eType = new_eType;
	$set(this, kvno, new_kvno);
	$set(this, cipher, new_cipher);
}

void EncryptedData::init$($EncryptionKey* key, $bytes* plaintext, int32_t usage) {
	$var($EType, etypeEngine, $EType::getInstance($nc(key)->getEType()));
	$set(this, cipher, $nc(etypeEngine)->encrypt(plaintext, $($nc(key)->getBytes()), usage));
	this->eType = $nc(key)->getEType();
	$set(this, kvno, key->getKeyVersionNumber());
}

$bytes* EncryptedData::decrypt($EncryptionKey* key, int32_t usage) {
	if (this->eType != $nc(key)->getEType()) {
		$var($String, var$0, $$str({"EncryptedData is encrypted using keytype "_s, $($EType::toString(this->eType)), " but decryption key is of type "_s}));
		$throwNew($KrbCryptoException, $$concat(var$0, $($EType::toString(key->getEType()))));
	}
	$var($EType, etypeEngine, $EType::getInstance(this->eType));
	$set(this, plain, $nc(etypeEngine)->decrypt(this->cipher, $($nc(key)->getBytes()), usage));
	return etypeEngine->decryptedData(this->plain);
}

$bytes* EncryptedData::decryptedData() {
	if (this->plain != nullptr) {
		$var($EType, etypeEngine, $EType::getInstance(this->eType));
		return $nc(etypeEngine)->decryptedData(this->plain);
	}
	return nullptr;
}

void EncryptedData::init$($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)0) {
		this->eType = $nc(($($nc($(der->getData()))->getBigInteger())))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if (((int32_t)($nc($(encoding->getData()))->peekByte() & (uint32_t)31)) == 1) {
		$assign(der, $nc($(encoding->getData()))->getDerValue());
		int32_t i = $nc(($($nc($($nc(der)->getData()))->getBigInteger())))->intValue();
		$set(this, kvno, $Integer::valueOf(i));
	} else {
		$set(this, kvno, nullptr);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)2) {
		$set(this, cipher, $nc($(der->getData()))->getOctetString());
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* EncryptedData::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->eType)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	if (this->kvno != nullptr) {
		temp->putInteger($($BigInteger::valueOf($nc(this->kvno)->longValue())));
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
		$assign(temp, $new($DerOutputStream));
	}
	temp->putOctetString(this->cipher);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), temp);
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

EncryptedData* EncryptedData::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(EncryptedData);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(EncryptedData, subDer);
	}
}

$bytes* EncryptedData::reset($bytes* data) {
	$var($bytes, bytes, nullptr);
	if (((int32_t)($nc(data)->get(1) & (uint32_t)255)) < 128) {
		$assign(bytes, $new($bytes, data->get(1) + 2));
		$System::arraycopy(data, 0, bytes, 0, data->get(1) + 2);
	} else if (((int32_t)(data->get(1) & (uint32_t)255)) > 128) {
		int32_t len = (int32_t)(data->get(1) & (uint32_t)(int32_t)(int8_t)127);
		int32_t result = 0;
		for (int32_t i = 0; i < len; ++i) {
			result |= $sl((int32_t)(data->get(i + 2) & (uint32_t)255), 8 * (len - i - 1));
		}
		$assign(bytes, $new($bytes, result + len + 2));
		$System::arraycopy(data, 0, bytes, 0, result + len + 2);
	}
	return bytes;
}

int32_t EncryptedData::getEType() {
	return this->eType;
}

$Integer* EncryptedData::getKeyVersionNumber() {
	return this->kvno;
}

$bytes* EncryptedData::getBytes() {
	return this->cipher;
}

EncryptedData::EncryptedData() {
}

$Class* EncryptedData::load$($String* name, bool initialize) {
	$loadClass(EncryptedData, name, initialize, &_EncryptedData_ClassInfo_, allocate$EncryptedData);
	return class$;
}

$Class* EncryptedData::class$ = nullptr;

		} // krb5
	} // security
} // sun