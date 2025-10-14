#include <sun/security/krb5/internal/Ticket.h>

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
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef KRB_AP_ERR_BADVERSION
#undef KRB_TKT
#undef TAG_APPLICATION
#undef TAG_CONTEXT
#undef TICKET_VNO

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _Ticket_FieldInfo_[] = {
	{"tkt_vno", "I", nullptr, $PUBLIC, $field(Ticket, tkt_vno)},
	{"sname", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(Ticket, sname)},
	{"encPart", "Lsun/security/krb5/EncryptedData;", nullptr, $PUBLIC, $field(Ticket, encPart)},
	{}
};

$MethodInfo _Ticket_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Ticket::*)()>(&Ticket::init$))},
	{"<init>", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/EncryptedData;)V", nullptr, $PUBLIC, $method(static_cast<void(Ticket::*)($PrincipalName*,$EncryptedData*)>(&Ticket::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(Ticket::*)($bytes*)>(&Ticket::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(Ticket::*)($DerValue*)>(&Ticket::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(Ticket::*)($DerValue*)>(&Ticket::init)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/internal/Ticket;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Ticket*(*)($DerInputStream*,int8_t,bool)>(&Ticket::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException"},
	{}
};

$ClassInfo _Ticket_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.Ticket",
	"java.lang.Object",
	"java.lang.Cloneable",
	_Ticket_FieldInfo_,
	_Ticket_MethodInfo_
};

$Object* allocate$Ticket($Class* clazz) {
	return $of($alloc(Ticket));
}

void Ticket::init$() {
}

$Object* Ticket::clone() {
	$var(Ticket, new_ticket, $new(Ticket));
	$set(new_ticket, sname, $cast($PrincipalName, $nc(this->sname)->clone()));
	$set(new_ticket, encPart, $cast($EncryptedData, $nc(this->encPart)->clone()));
	new_ticket->tkt_vno = this->tkt_vno;
	return $of(new_ticket);
}

void Ticket::init$($PrincipalName* new_sname, $EncryptedData* new_encPart) {
	this->tkt_vno = $Krb5::TICKET_VNO;
	$set(this, sname, new_sname);
	$set(this, encPart, new_encPart);
}

void Ticket::init$($bytes* data) {
	init($$new($DerValue, data));
}

void Ticket::init$($DerValue* encoding) {
	init(encoding);
}

void Ticket::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != $Krb5::KRB_TKT);
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
	this->tkt_vno = $nc($($nc($($nc(subDer)->getData()))->getBigInteger()))->intValue();
	if (this->tkt_vno != $Krb5::TICKET_VNO) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADVERSION);
	}
	$var($Realm, srealm, $Realm::parse($(der->getData()), (int8_t)1, false));
	$set(this, sname, $PrincipalName::parse($(der->getData()), (int8_t)2, false, srealm));
	$set(this, encPart, $EncryptedData::parse($(der->getData()), (int8_t)3, false));
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* Ticket::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	$var($DerValueArray, der, $new($DerValueArray, 4));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->tkt_vno)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
	bytes->write(var$0, $($nc($($nc(this->sname)->getRealm()))->asn1Encode()));
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
	bytes->write(var$1, $($nc(this->sname)->asn1Encode()));
	int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
	bytes->write(var$2, $($nc(this->encPart)->asn1Encode()));
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	$var($DerOutputStream, ticket, $new($DerOutputStream));
	ticket->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)1), temp);
	return ticket->toByteArray();
}

Ticket* Ticket::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(Ticket);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(Ticket, subDer);
	}
}

Ticket::Ticket() {
}

$Class* Ticket::load$($String* name, bool initialize) {
	$loadClass(Ticket, name, initialize, &_Ticket_ClassInfo_, allocate$Ticket);
	return class$;
}

$Class* Ticket::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun