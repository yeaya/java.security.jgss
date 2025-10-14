#include <sun/security/krb5/internal/AuthorizationDataEntry.h>

#include <java/io/BufferedOutputStream.h>
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
#include <sun/security/krb5/internal/ccache/CCacheOutputStream.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef TAG_CONTEXT

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $CCacheOutputStream = ::sun::security::krb5::internal::ccache::CCacheOutputStream;
using $KrbDataOutputStream = ::sun::security::krb5::internal::util::KrbDataOutputStream;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _AuthorizationDataEntry_FieldInfo_[] = {
	{"adType", "I", nullptr, $PUBLIC, $field(AuthorizationDataEntry, adType)},
	{"adData", "[B", nullptr, $PUBLIC, $field(AuthorizationDataEntry, adData)},
	{}
};

$MethodInfo _AuthorizationDataEntry_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(AuthorizationDataEntry::*)()>(&AuthorizationDataEntry::init$))},
	{"<init>", "(I[B)V", nullptr, $PUBLIC, $method(static_cast<void(AuthorizationDataEntry::*)(int32_t,$bytes*)>(&AuthorizationDataEntry::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(AuthorizationDataEntry::*)($DerValue*)>(&AuthorizationDataEntry::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeEntry", "(Lsun/security/krb5/internal/ccache/CCacheOutputStream;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _AuthorizationDataEntry_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.AuthorizationDataEntry",
	"java.lang.Object",
	"java.lang.Cloneable",
	_AuthorizationDataEntry_FieldInfo_,
	_AuthorizationDataEntry_MethodInfo_
};

$Object* allocate$AuthorizationDataEntry($Class* clazz) {
	return $of($alloc(AuthorizationDataEntry));
}

void AuthorizationDataEntry::init$() {
}

void AuthorizationDataEntry::init$(int32_t new_adType, $bytes* new_adData) {
	this->adType = new_adType;
	$set(this, adData, new_adData);
}

$Object* AuthorizationDataEntry::clone() {
	$var(AuthorizationDataEntry, new_authorizationDataEntry, $new(AuthorizationDataEntry));
	new_authorizationDataEntry->adType = this->adType;
	if (this->adData != nullptr) {
		$set(new_authorizationDataEntry, adData, $new($bytes, $nc(this->adData)->length));
		$System::arraycopy(this->adData, 0, new_authorizationDataEntry->adData, 0, $nc(this->adData)->length);
	}
	return $of(new_authorizationDataEntry);
}

void AuthorizationDataEntry::init$($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)0) {
		this->adType = $nc($($nc($(der->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)1) {
		$set(this, adData, $nc($(der->getData()))->getOctetString());
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* AuthorizationDataEntry::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger(this->adType);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putOctetString(this->adData);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

void AuthorizationDataEntry::writeEntry($CCacheOutputStream* cos) {
	$nc(cos)->write16(this->adType);
	cos->write32($nc(this->adData)->length);
	cos->write(this->adData, 0, $nc(this->adData)->length);
}

$String* AuthorizationDataEntry::toString() {
	return ($str({"adType="_s, $$str(this->adType), " adData.length="_s, $$str($nc(this->adData)->length)}));
}

AuthorizationDataEntry::AuthorizationDataEntry() {
}

$Class* AuthorizationDataEntry::load$($String* name, bool initialize) {
	$loadClass(AuthorizationDataEntry, name, initialize, &_AuthorizationDataEntry_ClassInfo_, allocate$AuthorizationDataEntry);
	return class$;
}

$Class* AuthorizationDataEntry::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun