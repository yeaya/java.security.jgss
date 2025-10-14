#include <javax/security/auth/kerberos/KeyImpl.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Arrays.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef ETYPE_ARCFOUR_HMAC
#undef ETYPE_DES3_CBC_HMAC_SHA1_KD
#undef ETYPE_DES_CBC_CRC
#undef ETYPE_DES_CBC_MD5
#undef ETYPE_NULL
#undef NULL_KEY

using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $SecretKey = ::javax::crypto::SecretKey;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _KeyImpl_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KeyImpl, serialVersionUID)},
	{"keyBytes", "[B", nullptr, $PRIVATE | $TRANSIENT, $field(KeyImpl, keyBytes)},
	{"keyType", "I", nullptr, $PRIVATE | $TRANSIENT, $field(KeyImpl, keyType)},
	{"destroyed", "Z", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(KeyImpl, destroyed)},
	{}
};

$MethodInfo _KeyImpl_MethodInfo_[] = {
	{"<init>", "([BI)V", nullptr, $PUBLIC, $method(static_cast<void(KeyImpl::*)($bytes*,int32_t)>(&KeyImpl::init$))},
	{"<init>", "(Ljavax/security/auth/kerberos/KerberosPrincipal;[CLjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KeyImpl::*)($KerberosPrincipal*,$chars*,$String*)>(&KeyImpl::init$))},
	{"destroy", "()V", nullptr, $PUBLIC, nullptr, "javax.security.auth.DestroyFailedException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"getAlgorithmName", "(I)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(KeyImpl::*)(int32_t)>(&KeyImpl::getAlgorithmName))},
	{"getEncoded", "()[B", nullptr, $PUBLIC | $FINAL},
	{"getFormat", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"getKeyType", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(KeyImpl::*)()>(&KeyImpl::getKeyType))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isDestroyed", "()Z", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KeyImpl::*)($ObjectInputStream*)>(&KeyImpl::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KeyImpl::*)($ObjectOutputStream*)>(&KeyImpl::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _KeyImpl_ClassInfo_ = {
	$ACC_SUPER,
	"javax.security.auth.kerberos.KeyImpl",
	"java.lang.Object",
	"javax.crypto.SecretKey",
	_KeyImpl_FieldInfo_,
	_KeyImpl_MethodInfo_
};

$Object* allocate$KeyImpl($Class* clazz) {
	return $of($alloc(KeyImpl));
}

void KeyImpl::init$($bytes* keyBytes, int32_t keyType) {
	this->destroyed = false;
	$set(this, keyBytes, $cast($bytes, $nc(keyBytes)->clone()));
	this->keyType = keyType;
}

void KeyImpl::init$($KerberosPrincipal* principal, $chars* password, $String* algorithm) {
	this->destroyed = false;
	try {
		$var($PrincipalName, princ, $new($PrincipalName, $($nc(principal)->getName())));
		$var($EncryptionKey, key, nullptr);
		if ("none"_s->equalsIgnoreCase(algorithm)) {
			$init($EncryptionKey);
			$assign(key, $EncryptionKey::NULL_KEY);
		} else {
			$assign(key, $new($EncryptionKey, password, $(princ->getSalt()), algorithm));
		}
		$set(this, keyBytes, $nc(key)->getBytes());
		this->keyType = key->getEType();
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		$throwNew($IllegalArgumentException, $(e->getMessage()));
	}
}

int32_t KeyImpl::getKeyType() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This key is no longer valid"_s);
	}
	return this->keyType;
}

$String* KeyImpl::getAlgorithm() {
	return getAlgorithmName(this->keyType);
}

$String* KeyImpl::getAlgorithmName(int32_t eType) {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This key is no longer valid"_s);
	}
	switch (eType) {
	case $EncryptedData::ETYPE_DES_CBC_CRC:
		{
			return "des-cbc-crc"_s;
		}
	case $EncryptedData::ETYPE_DES_CBC_MD5:
		{
			return "des-cbc-md5"_s;
		}
	case $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD:
		{
			return "des3-cbc-sha1-kd"_s;
		}
	case $EncryptedData::ETYPE_ARCFOUR_HMAC:
		{
			return "rc4-hmac"_s;
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
		{
			return "aes128-cts-hmac-sha1-96"_s;
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
		{
			return "aes256-cts-hmac-sha1-96"_s;
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
		{
			return "aes128-cts-hmac-sha256-128"_s;
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
		{
			return "aes256-cts-hmac-sha384-192"_s;
		}
	case $EncryptedData::ETYPE_NULL:
		{
			return "none"_s;
		}
	default:
		{
			return eType > 0 ? "unknown"_s : "private"_s;
		}
	}
}

$String* KeyImpl::getFormat() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This key is no longer valid"_s);
	}
	return "RAW"_s;
}

$bytes* KeyImpl::getEncoded() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This key is no longer valid"_s);
	}
	return $cast($bytes, $nc(this->keyBytes)->clone());
}

void KeyImpl::destroy() {
	if (!this->destroyed) {
		this->destroyed = true;
		$Arrays::fill(this->keyBytes, (int8_t)0);
	}
}

bool KeyImpl::isDestroyed() {
	return this->destroyed;
}

void KeyImpl::writeObject($ObjectOutputStream* oos) {
	if (this->destroyed) {
		$throwNew($IOException, "This key is no longer valid"_s);
	}
	try {
		$nc(oos)->writeObject($(($$new($EncryptionKey, this->keyType, this->keyBytes))->asn1Encode()));
	} catch ($Asn1Exception&) {
		$var($Asn1Exception, ae, $catch());
		$throwNew($IOException, $(ae->getMessage()));
	}
}

void KeyImpl::readObject($ObjectInputStream* ois) {
	try {
		$var($EncryptionKey, encKey, $new($EncryptionKey, $$new($DerValue, $cast($bytes, $($nc(ois)->readObject())))));
		this->keyType = encKey->getEType();
		$set(this, keyBytes, encKey->getBytes());
	} catch ($Asn1Exception&) {
		$var($Asn1Exception, ae, $catch());
		$throwNew($IOException, $(ae->getMessage()));
	}
}

$String* KeyImpl::toString() {
	$var($HexDumpEncoder, hd, $new($HexDumpEncoder));
	return $str({"EncryptionKey: keyType="_s, $$str(this->keyType), " keyBytes (hex dump)="_s, (this->keyBytes == nullptr || $nc(this->keyBytes)->length == 0 ? " Empty Key"_s : $$str({$$str(u'\n'), $(hd->encodeBuffer(this->keyBytes)), $$str(u'\n')}))});
}

int32_t KeyImpl::hashCode() {
	int32_t result = 17;
	if (isDestroyed()) {
		return result;
	}
	result = 37 * result + $Arrays::hashCode(this->keyBytes);
	return 37 * result + this->keyType;
}

bool KeyImpl::equals(Object$* other) {
	if ($equals(other, this)) {
		return true;
	}
	if (!($instanceOf(KeyImpl, other))) {
		return false;
	}
	$var(KeyImpl, otherKey, $cast(KeyImpl, other));
	bool var$0 = isDestroyed();
	if (var$0 || $nc(otherKey)->isDestroyed()) {
		return false;
	}
	bool var$1 = this->keyType != $nc(otherKey)->getKeyType();
	if (var$1 || !$Arrays::equals(this->keyBytes, $($nc(otherKey)->getEncoded()))) {
		return false;
	}
	return true;
}

KeyImpl::KeyImpl() {
}

$Class* KeyImpl::load$($String* name, bool initialize) {
	$loadClass(KeyImpl, name, initialize, &_KeyImpl_ClassInfo_, allocate$KeyImpl);
	return class$;
}

$Class* KeyImpl::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax