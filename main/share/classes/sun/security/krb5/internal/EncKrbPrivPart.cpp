#include <sun/security/krb5/internal/EncKrbPrivPart.h>

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
#undef TAG_APPLICATION
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

$FieldInfo _EncKrbPrivPart_FieldInfo_[] = {
	{"userData", "[B", nullptr, $PUBLIC, $field(EncKrbPrivPart, userData)},
	{"timestamp", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncKrbPrivPart, timestamp)},
	{"usec", "Ljava/lang/Integer;", nullptr, $PUBLIC, $field(EncKrbPrivPart, usec)},
	{"seqNumber", "Ljava/lang/Integer;", nullptr, $PUBLIC, $field(EncKrbPrivPart, seqNumber)},
	{"sAddress", "Lsun/security/krb5/internal/HostAddress;", nullptr, $PUBLIC, $field(EncKrbPrivPart, sAddress)},
	{"rAddress", "Lsun/security/krb5/internal/HostAddress;", nullptr, $PUBLIC, $field(EncKrbPrivPart, rAddress)},
	{}
};

$MethodInfo _EncKrbPrivPart_MethodInfo_[] = {
	{"<init>", "([BLsun/security/krb5/internal/KerberosTime;Ljava/lang/Integer;Ljava/lang/Integer;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;)V", nullptr, $PUBLIC, $method(static_cast<void(EncKrbPrivPart::*)($bytes*,$KerberosTime*,$Integer*,$Integer*,$HostAddress*,$HostAddress*)>(&EncKrbPrivPart::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(EncKrbPrivPart::*)($bytes*)>(&EncKrbPrivPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(EncKrbPrivPart::*)($DerValue*)>(&EncKrbPrivPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(EncKrbPrivPart::*)($DerValue*)>(&EncKrbPrivPart::init)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{}
};

$ClassInfo _EncKrbPrivPart_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.EncKrbPrivPart",
	"java.lang.Object",
	nullptr,
	_EncKrbPrivPart_FieldInfo_,
	_EncKrbPrivPart_MethodInfo_
};

$Object* allocate$EncKrbPrivPart($Class* clazz) {
	return $of($alloc(EncKrbPrivPart));
}

void EncKrbPrivPart::init$($bytes* new_userData, $KerberosTime* new_timestamp, $Integer* new_usec, $Integer* new_seqNumber, $HostAddress* new_sAddress, $HostAddress* new_rAddress) {
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

void EncKrbPrivPart::init$($bytes* data) {
	$set(this, userData, nullptr);
	init($$new($DerValue, data));
}

void EncKrbPrivPart::init$($DerValue* encoding) {
	$set(this, userData, nullptr);
	init(encoding);
}

void EncKrbPrivPart::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)28);
	bool var$0 = var$1 || ($nc(encoding)->isApplication() != true);
	if (var$0 || ($nc(encoding)->isConstructed() != true)) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if ($nc(der)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($($nc(der)->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)0) {
		$set(this, userData, $nc($(subDer->getData()))->getOctetString());
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, timestamp, $KerberosTime::parse($(der->getData()), (int8_t)1, true));
	if (((int32_t)($nc($(der->getData()))->peekByte() & (uint32_t)31)) == 2) {
		$assign(subDer, $nc($(der->getData()))->getDerValue());
		$set(this, usec, $Integer::valueOf($nc($($nc($($nc(subDer)->getData()))->getBigInteger()))->intValue()));
	} else {
		$set(this, usec, nullptr);
	}
	if (((int32_t)($nc($(der->getData()))->peekByte() & (uint32_t)31)) == 3) {
		$assign(subDer, $nc($(der->getData()))->getDerValue());
		$set(this, seqNumber, $Integer::valueOf($nc($($nc($($nc(subDer)->getData()))->getBigInteger()))->intValue()));
	} else {
		$set(this, seqNumber, nullptr);
	}
	$set(this, sAddress, $HostAddress::parse($(der->getData()), (int8_t)4, false));
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, rAddress, $HostAddress::parse($(der->getData()), (int8_t)5, true));
	}
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* EncKrbPrivPart::asn1Encode() {
	$var($DerOutputStream, temp, $new($DerOutputStream));
	$var($DerOutputStream, bytes, $new($DerOutputStream));
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
		int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)5);
		bytes->write(var$2, $($nc(this->rAddress)->asn1Encode()));
	}
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)28), temp);
	return bytes->toByteArray();
}

EncKrbPrivPart::EncKrbPrivPart() {
}

$Class* EncKrbPrivPart::load$($String* name, bool initialize) {
	$loadClass(EncKrbPrivPart, name, initialize, &_EncKrbPrivPart_ClassInfo_, allocate$EncKrbPrivPart);
	return class$;
}

$Class* EncKrbPrivPart::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun