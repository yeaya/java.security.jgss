#include <sun/security/krb5/internal/EncKrbCredPart.h>

#include <java/io/IOException.h>
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
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbCredInfo.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $KrbCredInfoArray = $Array<::sun::security::krb5::internal::KrbCredInfo>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbCredInfo = ::sun::security::krb5::internal::KrbCredInfo;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _EncKrbCredPart_FieldInfo_[] = {
	{"ticketInfo", "[Lsun/security/krb5/internal/KrbCredInfo;", nullptr, $PUBLIC, $field(EncKrbCredPart, ticketInfo)},
	{"timeStamp", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncKrbCredPart, timeStamp)},
	{"nonce", "Ljava/lang/Integer;", nullptr, $PRIVATE, $field(EncKrbCredPart, nonce)},
	{"usec", "Ljava/lang/Integer;", nullptr, $PRIVATE, $field(EncKrbCredPart, usec)},
	{"sAddress", "Lsun/security/krb5/internal/HostAddress;", nullptr, $PRIVATE, $field(EncKrbCredPart, sAddress)},
	{"rAddress", "Lsun/security/krb5/internal/HostAddresses;", nullptr, $PRIVATE, $field(EncKrbCredPart, rAddress)},
	{}
};

$MethodInfo _EncKrbCredPart_MethodInfo_[] = {
	{"<init>", "([Lsun/security/krb5/internal/KrbCredInfo;Lsun/security/krb5/internal/KerberosTime;Ljava/lang/Integer;Ljava/lang/Integer;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddresses;)V", nullptr, $PUBLIC, $method(static_cast<void(EncKrbCredPart::*)($KrbCredInfoArray*,$KerberosTime*,$Integer*,$Integer*,$HostAddress*,$HostAddresses*)>(&EncKrbCredPart::init$)), "java.io.IOException"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(EncKrbCredPart::*)($bytes*)>(&EncKrbCredPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(EncKrbCredPart::*)($DerValue*)>(&EncKrbCredPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(EncKrbCredPart::*)($DerValue*)>(&EncKrbCredPart::init)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{}
};

$ClassInfo _EncKrbCredPart_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.EncKrbCredPart",
	"java.lang.Object",
	nullptr,
	_EncKrbCredPart_FieldInfo_,
	_EncKrbCredPart_MethodInfo_
};

$Object* allocate$EncKrbCredPart($Class* clazz) {
	return $of($alloc(EncKrbCredPart));
}

void EncKrbCredPart::init$($KrbCredInfoArray* new_ticketInfo, $KerberosTime* new_timeStamp, $Integer* new_usec, $Integer* new_nonce, $HostAddress* new_sAddress, $HostAddresses* new_rAddress) {
	$set(this, ticketInfo, nullptr);
	if (new_ticketInfo != nullptr) {
		$set(this, ticketInfo, $new($KrbCredInfoArray, new_ticketInfo->length));
		for (int32_t i = 0; i < new_ticketInfo->length; ++i) {
			if (new_ticketInfo->get(i) == nullptr) {
				$throwNew($IOException, "Cannot create a EncKrbCredPart"_s);
			} else {
				$nc(this->ticketInfo)->set(i, $cast($KrbCredInfo, $($nc(new_ticketInfo->get(i))->clone())));
			}
		}
	}
	$set(this, timeStamp, new_timeStamp);
	$set(this, usec, new_usec);
	$set(this, nonce, new_nonce);
	$set(this, sAddress, new_sAddress);
	$set(this, rAddress, new_rAddress);
}

void EncKrbCredPart::init$($bytes* data) {
	$set(this, ticketInfo, nullptr);
	init($$new($DerValue, data));
}

void EncKrbCredPart::init$($DerValue* encoding) {
	$set(this, ticketInfo, nullptr);
	init(encoding);
}

void EncKrbCredPart::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	$set(this, nonce, nullptr);
	$set(this, timeStamp, nullptr);
	$set(this, usec, nullptr);
	$set(this, sAddress, nullptr);
	$set(this, rAddress, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)29);
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
		$var($DerValueArray, derValues, $nc($(subDer->getData()))->getSequence(1));
		$set(this, ticketInfo, $new($KrbCredInfoArray, $nc(derValues)->length));
		for (int32_t i = 0; i < derValues->length; ++i) {
			$nc(this->ticketInfo)->set(i, $$new($KrbCredInfo, derValues->get(i)));
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($(der->getData()))->available() > 0) {
		if (((int32_t)((int8_t)($nc($(der->getData()))->peekByte()) & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)1) {
			$assign(subDer, $nc($(der->getData()))->getDerValue());
			$set(this, nonce, $Integer::valueOf($nc($($nc($($nc(subDer)->getData()))->getBigInteger()))->intValue()));
		}
	}
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, timeStamp, $KerberosTime::parse($(der->getData()), (int8_t)2, true));
	}
	if ($nc($(der->getData()))->available() > 0) {
		if (((int32_t)((int8_t)($nc($(der->getData()))->peekByte()) & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)3) {
			$assign(subDer, $nc($(der->getData()))->getDerValue());
			$set(this, usec, $Integer::valueOf($nc($($nc($($nc(subDer)->getData()))->getBigInteger()))->intValue()));
		}
	}
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, sAddress, $HostAddress::parse($(der->getData()), (int8_t)4, true));
	}
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, rAddress, $HostAddresses::parse($(der->getData()), (int8_t)5, true));
	}
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* EncKrbCredPart::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	$var($DerValueArray, tickets, $new($DerValueArray, $nc(this->ticketInfo)->length));
	for (int32_t i = 0; i < $nc(this->ticketInfo)->length; ++i) {
		tickets->set(i, $$new($DerValue, $($nc($nc(this->ticketInfo)->get(i))->asn1Encode())));
	}
	temp->putSequence(tickets);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	if (this->nonce != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putInteger($($BigInteger::valueOf((int64_t)$nc(this->nonce)->intValue())));
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	}
	if (this->timeStamp != nullptr) {
		int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
		bytes->write(var$0, $($nc(this->timeStamp)->asn1Encode()));
	}
	if (this->usec != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putInteger($($BigInteger::valueOf((int64_t)$nc(this->usec)->intValue())));
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3), temp);
	}
	if (this->sAddress != nullptr) {
		int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
		bytes->write(var$1, $($nc(this->sAddress)->asn1Encode()));
	}
	if (this->rAddress != nullptr) {
		int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)5);
		bytes->write(var$2, $($nc(this->rAddress)->asn1Encode()));
	}
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)29), temp);
	return bytes->toByteArray();
}

EncKrbCredPart::EncKrbCredPart() {
}

$Class* EncKrbCredPart::load$($String* name, bool initialize) {
	$loadClass(EncKrbCredPart, name, initialize, &_EncKrbCredPart_ClassInfo_, allocate$EncKrbCredPart);
	return class$;
}

$Class* EncKrbCredPart::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun