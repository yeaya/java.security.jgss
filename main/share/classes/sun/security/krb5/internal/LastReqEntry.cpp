#include <sun/security/krb5/internal/LastReqEntry.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _LastReqEntry_FieldInfo_[] = {
	{"lrType", "I", nullptr, $PRIVATE, $field(LastReqEntry, lrType)},
	{"lrValue", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $field(LastReqEntry, lrValue)},
	{}
};

$MethodInfo _LastReqEntry_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(LastReqEntry::*)()>(&LastReqEntry::init$))},
	{"<init>", "(ILsun/security/krb5/internal/KerberosTime;)V", nullptr, $PUBLIC, $method(static_cast<void(LastReqEntry::*)(int32_t,$KerberosTime*)>(&LastReqEntry::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(LastReqEntry::*)($DerValue*)>(&LastReqEntry::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _LastReqEntry_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.LastReqEntry",
	"java.lang.Object",
	nullptr,
	_LastReqEntry_FieldInfo_,
	_LastReqEntry_MethodInfo_
};

$Object* allocate$LastReqEntry($Class* clazz) {
	return $of($alloc(LastReqEntry));
}

void LastReqEntry::init$() {
}

void LastReqEntry::init$(int32_t Type, $KerberosTime* time) {
	this->lrType = Type;
	$set(this, lrValue, time);
}

void LastReqEntry::init$($DerValue* encoding) {
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$var($DerValue, der, nullptr);
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 0) {
		this->lrType = $nc($($nc($(der->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, lrValue, $KerberosTime::parse($(encoding->getData()), (int8_t)1, false));
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* LastReqEntry::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger(this->lrType);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
	bytes->write(var$0, $($nc(this->lrValue)->asn1Encode()));
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

$Object* LastReqEntry::clone() {
	$var(LastReqEntry, newEntry, $new(LastReqEntry));
	newEntry->lrType = this->lrType;
	$set(newEntry, lrValue, this->lrValue);
	return $of(newEntry);
}

LastReqEntry::LastReqEntry() {
}

$Class* LastReqEntry::load$($String* name, bool initialize) {
	$loadClass(LastReqEntry, name, initialize, &_LastReqEntry_ClassInfo_, allocate$LastReqEntry);
	return class$;
}

$Class* LastReqEntry::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun