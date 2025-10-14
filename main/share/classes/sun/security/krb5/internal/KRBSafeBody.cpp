#include <sun/security/krb5/internal/KRBSafeBody.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/HostAddress.h>
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
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KRBSafeBody_FieldInfo_[] = {
	{"userData", "[B", nullptr, $PUBLIC, $field(KRBSafeBody, userData)},
	{"timestamp", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KRBSafeBody, timestamp)},
	{"usec", "Ljava/lang/Integer;", nullptr, $PUBLIC, $field(KRBSafeBody, usec)},
	{"seqNumber", "Ljava/lang/Integer;", nullptr, $PUBLIC, $field(KRBSafeBody, seqNumber)},
	{"sAddress", "Lsun/security/krb5/internal/HostAddress;", nullptr, $PUBLIC, $field(KRBSafeBody, sAddress)},
	{"rAddress", "Lsun/security/krb5/internal/HostAddress;", nullptr, $PUBLIC, $field(KRBSafeBody, rAddress)},
	{}
};

$MethodInfo _KRBSafeBody_MethodInfo_[] = {
	{"<init>", "([BLsun/security/krb5/internal/KerberosTime;Ljava/lang/Integer;Ljava/lang/Integer;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBSafeBody::*)($bytes*,$KerberosTime*,$Integer*,$Integer*,$HostAddress*,$HostAddress*)>(&KRBSafeBody::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBSafeBody::*)($DerValue*)>(&KRBSafeBody::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/internal/KRBSafeBody;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KRBSafeBody*(*)($DerInputStream*,int8_t,bool)>(&KRBSafeBody::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{}
};

$ClassInfo _KRBSafeBody_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KRBSafeBody",
	"java.lang.Object",
	nullptr,
	_KRBSafeBody_FieldInfo_,
	_KRBSafeBody_MethodInfo_
};

$Object* allocate$KRBSafeBody($Class* clazz) {
	return $of($alloc(KRBSafeBody));
}

void KRBSafeBody::init$($bytes* new_userData, $KerberosTime* new_timestamp, $Integer* new_usec, $Integer* new_seqNumber, $HostAddress* new_sAddress, $HostAddress* new_rAddress) {
	$set(this, userData, nullptr);
	if (new_userData != nullptr) {
		$set(this, userData, $cast($bytes, new_userData->clone()));
	}
	$set(this, timestamp, new_timestamp);
	$set(this, usec, new_usec);
	$set(this, seqNumber, new_seqNumber);
	$set(this, sAddress, new_sAddress);
	$set(this, rAddress, new_rAddress);
}

void KRBSafeBody::init$($DerValue* encoding) {
	$set(this, userData, nullptr);
	$var($DerValue, der, nullptr);
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 0) {
		$set(this, userData, $nc($(der->getData()))->getOctetString());
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, timestamp, $KerberosTime::parse($(encoding->getData()), (int8_t)1, true));
	if (((int32_t)($nc($(encoding->getData()))->peekByte() & (uint32_t)31)) == 2) {
		$assign(der, $nc($(encoding->getData()))->getDerValue());
		$set(this, usec, $Integer::valueOf($nc($($nc($($nc(der)->getData()))->getBigInteger()))->intValue()));
	}
	if (((int32_t)($nc($(encoding->getData()))->peekByte() & (uint32_t)31)) == 3) {
		$assign(der, $nc($(encoding->getData()))->getDerValue());
		$set(this, seqNumber, $Integer::valueOf($nc($($nc($($nc(der)->getData()))->getBigInteger()))->intValue()));
	}
	$set(this, sAddress, $HostAddress::parse($(encoding->getData()), (int8_t)4, false));
	if ($nc($(encoding->getData()))->available() > 0) {
		$set(this, rAddress, $HostAddress::parse($(encoding->getData()), (int8_t)5, true));
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* KRBSafeBody::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putOctetString(this->userData);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	if (this->timestamp != nullptr) {
		int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
		bytes->write(var$0, $($nc(this->timestamp)->asn1Encode()));
	}
	if (this->usec != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putInteger($($BigInteger::valueOf((int64_t)$nc(this->usec)->intValue())));
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), temp);
	}
	if (this->seqNumber != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putInteger($($BigInteger::valueOf($nc(this->seqNumber)->longValue())));
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3), temp);
	}
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
	bytes->write(var$1, $($nc(this->sAddress)->asn1Encode()));
	if (this->rAddress != nullptr) {
		$assign(temp, $new($DerOutputStream));
	}
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

KRBSafeBody* KRBSafeBody::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(KRBSafeBody, subDer);
	}
}

KRBSafeBody::KRBSafeBody() {
}

$Class* KRBSafeBody::load$($String* name, bool initialize) {
	$loadClass(KRBSafeBody, name, initialize, &_KRBSafeBody_ClassInfo_, allocate$KRBSafeBody);
	return class$;
}

$Class* KRBSafeBody::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun