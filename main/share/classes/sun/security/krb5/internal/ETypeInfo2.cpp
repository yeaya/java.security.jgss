#include <sun/security/krb5/internal/ETypeInfo2.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/util/KerberosString.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef TAG_CONTEXT
#undef TAG_TYPE
#undef TAG_VALUE1
#undef TAG_VALUE2

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
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

$FieldInfo _ETypeInfo2_FieldInfo_[] = {
	{"etype", "I", nullptr, $PRIVATE, $field(ETypeInfo2, etype)},
	{"saltStr", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ETypeInfo2, saltStr)},
	{"s2kparams", "[B", nullptr, $PRIVATE, $field(ETypeInfo2, s2kparams)},
	{"TAG_TYPE", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ETypeInfo2, TAG_TYPE)},
	{"TAG_VALUE1", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ETypeInfo2, TAG_VALUE1)},
	{"TAG_VALUE2", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ETypeInfo2, TAG_VALUE2)},
	{}
};

$MethodInfo _ETypeInfo2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ETypeInfo2::*)()>(&ETypeInfo2::init$))},
	{"<init>", "(ILjava/lang/String;[B)V", nullptr, $PUBLIC, $method(static_cast<void(ETypeInfo2::*)(int32_t,$String*,$bytes*)>(&ETypeInfo2::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(ETypeInfo2::*)($DerValue*)>(&ETypeInfo2::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"getEType", "()I", nullptr, $PUBLIC},
	{"getParams", "()[B", nullptr, $PUBLIC},
	{"getSalt", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ETypeInfo2_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ETypeInfo2",
	"java.lang.Object",
	nullptr,
	_ETypeInfo2_FieldInfo_,
	_ETypeInfo2_MethodInfo_
};

$Object* allocate$ETypeInfo2($Class* clazz) {
	return $of($alloc(ETypeInfo2));
}

void ETypeInfo2::init$() {
	$set(this, saltStr, nullptr);
	$set(this, s2kparams, nullptr);
}

void ETypeInfo2::init$(int32_t etype, $String* salt, $bytes* s2kparams) {
	$set(this, saltStr, nullptr);
	$set(this, s2kparams, nullptr);
	this->etype = etype;
	$set(this, saltStr, salt);
	if (s2kparams != nullptr) {
		$set(this, s2kparams, $cast($bytes, s2kparams->clone()));
	}
}

$Object* ETypeInfo2::clone() {
	$var(ETypeInfo2, etypeInfo2, $new(ETypeInfo2));
	etypeInfo2->etype = this->etype;
	$set(etypeInfo2, saltStr, this->saltStr);
	if (this->s2kparams != nullptr) {
		$set(etypeInfo2, s2kparams, $new($bytes, $nc(this->s2kparams)->length));
		$System::arraycopy(this->s2kparams, 0, etypeInfo2->s2kparams, 0, $nc(this->s2kparams)->length);
	}
	return $of(etypeInfo2);
}

void ETypeInfo2::init$($DerValue* encoding) {
	$set(this, saltStr, nullptr);
	$set(this, s2kparams, nullptr);
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
		if (((int32_t)($nc($(encoding->getData()))->peekByte() & (uint32_t)31)) == 1) {
			$assign(der, $nc($(encoding->getData()))->getDerValue());
			$set(this, saltStr, $$new($KerberosString, $($nc($($nc(der)->getData()))->getDerValue()))->toString());
		}
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		if (((int32_t)($nc($(encoding->getData()))->peekByte() & (uint32_t)31)) == 2) {
			$assign(der, $nc($(encoding->getData()))->getDerValue());
			$set(this, s2kparams, $nc($($nc(der)->getData()))->getOctetString());
		}
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* ETypeInfo2::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger(this->etype);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, ETypeInfo2::TAG_TYPE), temp);
	if (this->saltStr != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putDerValue($($$new($KerberosString, this->saltStr)->toDerValue()));
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, ETypeInfo2::TAG_VALUE1), temp);
	}
	if (this->s2kparams != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putOctetString(this->s2kparams);
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, ETypeInfo2::TAG_VALUE2), temp);
	}
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

int32_t ETypeInfo2::getEType() {
	return this->etype;
}

$String* ETypeInfo2::getSalt() {
	return this->saltStr;
}

$bytes* ETypeInfo2::getParams() {
	return ((this->s2kparams == nullptr) ? ($bytes*)nullptr : $cast($bytes, $nc(this->s2kparams)->clone()));
}

ETypeInfo2::ETypeInfo2() {
}

$Class* ETypeInfo2::load$($String* name, bool initialize) {
	$loadClass(ETypeInfo2, name, initialize, &_ETypeInfo2_ClassInfo_, allocate$ETypeInfo2);
	return class$;
}

$Class* ETypeInfo2::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun