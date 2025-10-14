#include <sun/security/krb5/internal/ETypeInfo.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/util/KerberosString.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef MSNAME
#undef TAG_CONTEXT
#undef TAG_TYPE
#undef TAG_VALUE
#undef UTF_8

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KerberosString = ::sun::security::krb5::internal::util::KerberosString;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _ETypeInfo_FieldInfo_[] = {
	{"etype", "I", nullptr, $PRIVATE, $field(ETypeInfo, etype)},
	{"salt", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ETypeInfo, salt)},
	{"TAG_TYPE", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ETypeInfo, TAG_TYPE)},
	{"TAG_VALUE", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ETypeInfo, TAG_VALUE)},
	{}
};

$MethodInfo _ETypeInfo_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ETypeInfo::*)()>(&ETypeInfo::init$))},
	{"<init>", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ETypeInfo::*)(int32_t,$String*)>(&ETypeInfo::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(ETypeInfo::*)($DerValue*)>(&ETypeInfo::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"getEType", "()I", nullptr, $PUBLIC},
	{"getSalt", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ETypeInfo_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ETypeInfo",
	"java.lang.Object",
	nullptr,
	_ETypeInfo_FieldInfo_,
	_ETypeInfo_MethodInfo_
};

$Object* allocate$ETypeInfo($Class* clazz) {
	return $of($alloc(ETypeInfo));
}

void ETypeInfo::init$() {
	$set(this, salt, nullptr);
}

void ETypeInfo::init$(int32_t etype, $String* salt) {
	$set(this, salt, nullptr);
	this->etype = etype;
	$set(this, salt, salt);
}

$Object* ETypeInfo::clone() {
	return $of($new(ETypeInfo, this->etype, this->salt));
}

void ETypeInfo::init$($DerValue* encoding) {
	$set(this, salt, nullptr);
	$var($DerValue, der, nullptr);
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 0) {
		this->etype = $nc($($nc($(der->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$assign(der, $nc($(encoding->getData()))->getDerValue());
		if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 1) {
			$var($bytes, saltBytes, $nc($(der->getData()))->getOctetString());
			$init($KerberosString);
			if ($KerberosString::MSNAME) {
				$init($StandardCharsets);
				$set(this, salt, $new($String, saltBytes, $StandardCharsets::UTF_8));
			} else {
				$set(this, salt, $new($String, saltBytes));
			}
		}
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* ETypeInfo::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger(this->etype);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, ETypeInfo::TAG_TYPE), temp);
	if (this->salt != nullptr) {
		$assign(temp, $new($DerOutputStream));
		$init($KerberosString);
		if ($KerberosString::MSNAME) {
			$init($StandardCharsets);
			temp->putOctetString($($nc(this->salt)->getBytes($StandardCharsets::UTF_8)));
		} else {
			temp->putOctetString($($nc(this->salt)->getBytes()));
		}
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, ETypeInfo::TAG_VALUE), temp);
	}
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

int32_t ETypeInfo::getEType() {
	return this->etype;
}

$String* ETypeInfo::getSalt() {
	return this->salt;
}

ETypeInfo::ETypeInfo() {
}

$Class* ETypeInfo::load$($String* name, bool initialize) {
	$loadClass(ETypeInfo, name, initialize, &_ETypeInfo_ClassInfo_, allocate$ETypeInfo);
	return class$;
}

$Class* ETypeInfo::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun