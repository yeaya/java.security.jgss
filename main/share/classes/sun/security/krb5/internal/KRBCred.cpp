#include <sun/security/krb5/internal/KRBCred.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <java/util/Vector.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/EncryptedData.h>
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
#undef KRB_CRED
#undef PVNO
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $TicketArray = $Array<::sun::security::krb5::internal::Ticket>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Vector = ::java::util::Vector;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KRBCred_FieldInfo_[] = {
	{"tickets", "[Lsun/security/krb5/internal/Ticket;", nullptr, $PUBLIC, $field(KRBCred, tickets)},
	{"encPart", "Lsun/security/krb5/EncryptedData;", nullptr, $PUBLIC, $field(KRBCred, encPart)},
	{"pvno", "I", nullptr, $PRIVATE, $field(KRBCred, pvno)},
	{"msgType", "I", nullptr, $PRIVATE, $field(KRBCred, msgType)},
	{}
};

$MethodInfo _KRBCred_MethodInfo_[] = {
	{"<init>", "([Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptedData;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBCred::*)($TicketArray*,$EncryptedData*)>(&KRBCred::init$)), "java.io.IOException"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(KRBCred::*)($bytes*)>(&KRBCred::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBCred::*)($DerValue*)>(&KRBCred::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(KRBCred::*)($DerValue*)>(&KRBCred::init)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{}
};

$ClassInfo _KRBCred_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KRBCred",
	"java.lang.Object",
	nullptr,
	_KRBCred_FieldInfo_,
	_KRBCred_MethodInfo_
};

$Object* allocate$KRBCred($Class* clazz) {
	return $of($alloc(KRBCred));
}

void KRBCred::init$($TicketArray* new_tickets, $EncryptedData* new_encPart) {
	$set(this, tickets, nullptr);
	this->pvno = $Krb5::PVNO;
	this->msgType = $Krb5::KRB_CRED;
	if (new_tickets != nullptr) {
		$set(this, tickets, $new($TicketArray, new_tickets->length));
		for (int32_t i = 0; i < new_tickets->length; ++i) {
			if (new_tickets->get(i) == nullptr) {
				$throwNew($IOException, "Cannot create a KRBCred"_s);
			} else {
				$nc(this->tickets)->set(i, $cast($Ticket, $($nc(new_tickets->get(i))->clone())));
			}
		}
	}
	$set(this, encPart, new_encPart);
}

void KRBCred::init$($bytes* data) {
	$set(this, tickets, nullptr);
	init($$new($DerValue, data));
}

void KRBCred::init$($DerValue* encoding) {
	$set(this, tickets, nullptr);
	init(encoding);
}

void KRBCred::init($DerValue* encoding) {
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)22);
	bool var$0 = var$1 || ($nc(encoding)->isApplication() != true);
	if (var$0 || ($nc(encoding)->isConstructed() != true)) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if ($nc(der)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($($nc(der)->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)31)) == 0) {
		this->pvno = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
		if (this->pvno != $Krb5::PVNO) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADVERSION);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)31)) == 1) {
		this->msgType = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
		if (this->msgType != $Krb5::KRB_CRED) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MSG_TYPE);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)31)) == 2) {
		$var($DerValue, subsubDer, $nc($(subDer->getData()))->getDerValue());
		if ($nc(subsubDer)->getTag() != $DerValue::tag_SequenceOf) {
			$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
		}
		$var($Vector, v, $new($Vector));
		while ($nc($($nc(subsubDer)->getData()))->available() > 0) {
			v->addElement($$new($Ticket, $($nc($(subsubDer->getData()))->getDerValue())));
		}
		if (v->size() > 0) {
			$set(this, tickets, $new($TicketArray, v->size()));
			v->copyInto(this->tickets);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, encPart, $EncryptedData::parse($(der->getData()), (int8_t)3, false));
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* KRBCred::asn1Encode() {
	$var($DerOutputStream, temp, nullptr);
	$var($DerOutputStream, bytes, nullptr);
	$var($DerOutputStream, out, nullptr);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->pvno)));
	$assign(out, $new($DerOutputStream));
	out->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->msgType)));
	out->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	$assign(temp, $new($DerOutputStream));
	for (int32_t i = 0; i < $nc(this->tickets)->length; ++i) {
		temp->write($($nc($nc(this->tickets)->get(i))->asn1Encode()));
	}
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::tag_SequenceOf, temp);
	out->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), bytes);
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
	out->write(var$0, $($nc(this->encPart)->asn1Encode()));
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::tag_Sequence, out);
	$assign(out, $new($DerOutputStream));
	out->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)22), bytes);
	return out->toByteArray();
}

KRBCred::KRBCred() {
}

$Class* KRBCred::load$($String* name, bool initialize) {
	$loadClass(KRBCred, name, initialize, &_KRBCred_ClassInfo_, allocate$KRBCred);
	return class$;
}

$Class* KRBCred::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun