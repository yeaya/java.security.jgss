#include <sun/security/krb5/internal/PAForUserEnc.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/RealmException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/krb5/internal/util/KerberosString.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef AUTH_PACKAGE
#undef CKSUMTYPE_HMAC_MD5_ARCFOUR
#undef KU_PA_FOR_USER_ENC_CKSUM
#undef TAG_CONTEXT
#undef UTF_8

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Checksum = ::sun::security::krb5::Checksum;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $RealmException = ::sun::security::krb5::RealmException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $KerberosString = ::sun::security::krb5::internal::util::KerberosString;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _PAForUserEnc_FieldInfo_[] = {
	{"name", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $FINAL, $field(PAForUserEnc, name)},
	{"key", "Lsun/security/krb5/EncryptionKey;", nullptr, $PRIVATE | $FINAL, $field(PAForUserEnc, key)},
	{"AUTH_PACKAGE", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PAForUserEnc, AUTH_PACKAGE)},
	{}
};

$MethodInfo _PAForUserEnc_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/EncryptionKey;)V", nullptr, $PUBLIC, $method(static_cast<void(PAForUserEnc::*)($PrincipalName*,$EncryptionKey*)>(&PAForUserEnc::init$))},
	{"<init>", "(Lsun/security/util/DerValue;Lsun/security/krb5/EncryptionKey;)V", nullptr, $PUBLIC, $method(static_cast<void(PAForUserEnc::*)($DerValue*,$EncryptionKey*)>(&PAForUserEnc::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.KrbException,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"getName", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC},
	{"getS4UByteArray", "()[B", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _PAForUserEnc_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.PAForUserEnc",
	"java.lang.Object",
	nullptr,
	_PAForUserEnc_FieldInfo_,
	_PAForUserEnc_MethodInfo_
};

$Object* allocate$PAForUserEnc($Class* clazz) {
	return $of($alloc(PAForUserEnc));
}

$String* PAForUserEnc::AUTH_PACKAGE = nullptr;

void PAForUserEnc::init$($PrincipalName* name, $EncryptionKey* key) {
	$set(this, name, name);
	$set(this, key, key);
}

void PAForUserEnc::init$($DerValue* encoding, $EncryptionKey* key) {
	$var($DerValue, der, nullptr);
	$set(this, key, key);
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$var($PrincipalName, tmpName, nullptr);
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 0) {
		try {
			$var($DerValue, var$0, $nc($(der->getData()))->getDerValue());
			$assign(tmpName, $new($PrincipalName, var$0, $$new($Realm, "PLACEHOLDER"_s)));
		} catch ($RealmException&) {
			$catch();
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 1) {
		try {
			$var($Realm, realm, $new($Realm, $($nc($(der->getData()))->getDerValue())));
			int32_t var$1 = $nc(tmpName)->getNameType();
			$set(this, name, $new($PrincipalName, var$1, $(tmpName->getNameStrings()), realm));
		} catch ($RealmException&) {
			$var($RealmException, re, $catch());
			$throwNew($IOException, static_cast<$Throwable*>(re));
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 2) {
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 3) {
		$var($String, authPackage, $$new($KerberosString, $($nc($(der->getData()))->getDerValue()))->toString());
		if (!$nc(authPackage)->equalsIgnoreCase(PAForUserEnc::AUTH_PACKAGE)) {
			$throwNew($IOException, "Incorrect auth-package"_s);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* PAForUserEnc::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0);
	bytes->write(var$0, $($nc(this->name)->asn1Encode()));
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
	bytes->write(var$1, $($nc($($nc(this->name)->getRealm()))->asn1Encode()));
	try {
		$var($Checksum, cks, $new($Checksum, $Checksum::CKSUMTYPE_HMAC_MD5_ARCFOUR, $(getS4UByteArray()), this->key, $KeyUsage::KU_PA_FOR_USER_ENC_CKSUM));
		int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
		bytes->write(var$2, $(cks->asn1Encode()));
	} catch ($KrbException&) {
		$var($KrbException, ke, $catch());
		$throwNew($IOException, static_cast<$Throwable*>(ke));
	}
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putDerValue($($$new($KerberosString, PAForUserEnc::AUTH_PACKAGE)->toDerValue()));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3), temp);
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

$bytes* PAForUserEnc::getS4UByteArray() {
	$var($ByteArrayOutputStream, ba, $new($ByteArrayOutputStream));
	ba->writeBytes($$new($bytes, 4));
	{
		$var($StringArray, arr$, $nc(this->name)->getNameStrings());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, s, arr$->get(i$));
			{
				$init($StandardCharsets);
				ba->writeBytes($($nc(s)->getBytes($StandardCharsets::UTF_8)));
			}
		}
	}
	$init($StandardCharsets);
	ba->writeBytes($($nc($($nc($($nc(this->name)->getRealm()))->toString()))->getBytes($StandardCharsets::UTF_8)));
	ba->writeBytes($($nc(PAForUserEnc::AUTH_PACKAGE)->getBytes($StandardCharsets::UTF_8)));
	$var($bytes, output, ba->toByteArray());
	int32_t pnType = $nc(this->name)->getNameType();
	$nc(output)->set(0, (int8_t)((int32_t)(pnType & (uint32_t)255)));
	output->set(1, (int8_t)((int32_t)((pnType >> 8) & (uint32_t)255)));
	output->set(2, (int8_t)((int32_t)((pnType >> 16) & (uint32_t)255)));
	output->set(3, (int8_t)((int32_t)((pnType >> 24) & (uint32_t)255)));
	return output;
}

$PrincipalName* PAForUserEnc::getName() {
	return this->name;
}

$String* PAForUserEnc::toString() {
	return $str({"PA-FOR-USER: "_s, this->name});
}

PAForUserEnc::PAForUserEnc() {
}

void clinit$PAForUserEnc($Class* class$) {
	$assignStatic(PAForUserEnc::AUTH_PACKAGE, "Kerberos"_s);
}

$Class* PAForUserEnc::load$($String* name, bool initialize) {
	$loadClass(PAForUserEnc, name, initialize, &_PAForUserEnc_ClassInfo_, clinit$PAForUserEnc, allocate$PAForUserEnc);
	return class$;
}

$Class* PAForUserEnc::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun