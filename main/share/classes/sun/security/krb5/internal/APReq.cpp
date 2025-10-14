#include <sun/security/krb5/internal/APReq.h>

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
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/internal/APOptions.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef KRB_AP_ERR_BADVERSION
#undef KRB_AP_ERR_MSG_TYPE
#undef KRB_AP_REQ
#undef PVNO
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $APOptions = ::sun::security::krb5::internal::APOptions;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _APReq_FieldInfo_[] = {
	{"pvno", "I", nullptr, $PUBLIC, $field(APReq, pvno)},
	{"msgType", "I", nullptr, $PUBLIC, $field(APReq, msgType)},
	{"apOptions", "Lsun/security/krb5/internal/APOptions;", nullptr, $PUBLIC, $field(APReq, apOptions)},
	{"ticket", "Lsun/security/krb5/internal/Ticket;", nullptr, $PUBLIC, $field(APReq, ticket)},
	{"authenticator", "Lsun/security/krb5/EncryptedData;", nullptr, $PUBLIC, $field(APReq, authenticator)},
	{}
};

$MethodInfo _APReq_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/APOptions;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptedData;)V", nullptr, $PUBLIC, $method(static_cast<void(APReq::*)($APOptions*,$Ticket*,$EncryptedData*)>(&APReq::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(APReq::*)($bytes*)>(&APReq::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.RealmException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(APReq::*)($DerValue*)>(&APReq::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.RealmException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(APReq::*)($DerValue*)>(&APReq::init)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.RealmException"},
	{}
};

$ClassInfo _APReq_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.APReq",
	"java.lang.Object",
	nullptr,
	_APReq_FieldInfo_,
	_APReq_MethodInfo_
};

$Object* allocate$APReq($Class* clazz) {
	return $of($alloc(APReq));
}

void APReq::init$($APOptions* new_apOptions, $Ticket* new_ticket, $EncryptedData* new_authenticator) {
	this->pvno = $Krb5::PVNO;
	this->msgType = $Krb5::KRB_AP_REQ;
	$set(this, apOptions, new_apOptions);
	$set(this, ticket, new_ticket);
	$set(this, authenticator, new_authenticator);
}

void APReq::init$($bytes* data) {
	init($$new($DerValue, data));
}

void APReq::init$($DerValue* encoding) {
	init(encoding);
}

void APReq::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != $Krb5::KRB_AP_REQ);
	bool var$0 = var$1 || ($nc(encoding)->isApplication() != true);
	if (var$0 || ($nc(encoding)->isConstructed() != true)) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if ($nc(der)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($($nc(der)->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	this->pvno = $nc($($nc($($nc(subDer)->getData()))->getBigInteger()))->intValue();
	if (this->pvno != $Krb5::PVNO) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADVERSION);
	}
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)(subDer->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)1) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	this->msgType = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
	if (this->msgType != $Krb5::KRB_AP_REQ) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MSG_TYPE);
	}
	$set(this, apOptions, $APOptions::parse($(der->getData()), (int8_t)2, false));
	$set(this, ticket, $Ticket::parse($(der->getData()), (int8_t)3, false));
	$set(this, authenticator, $EncryptedData::parse($(der->getData()), (int8_t)4, false));
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* APReq::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->pvno)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->msgType)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
	bytes->write(var$0, $($nc(this->apOptions)->asn1Encode()));
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
	bytes->write(var$1, $($nc(this->ticket)->asn1Encode()));
	int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
	bytes->write(var$2, $($nc(this->authenticator)->asn1Encode()));
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	$var($DerOutputStream, apreq, $new($DerOutputStream));
	apreq->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)14), temp);
	return apreq->toByteArray();
}

APReq::APReq() {
}

$Class* APReq::load$($String* name, bool initialize) {
	$loadClass(APReq, name, initialize, &_APReq_ClassInfo_, allocate$APReq);
	return class$;
}

$Class* APReq::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun