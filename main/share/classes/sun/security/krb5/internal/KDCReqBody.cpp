#include <sun/security/krb5/internal/KDCReqBody.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
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
#include <java/util/Vector.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef KRB_AS_REQ
#undef TAG_CONTEXT

using $TicketArray = $Array<::sun::security::krb5::internal::Ticket>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Vector = ::java::util::Vector;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KDCReqBody_FieldInfo_[] = {
	{"kdcOptions", "Lsun/security/krb5/internal/KDCOptions;", nullptr, $PUBLIC, $field(KDCReqBody, kdcOptions)},
	{"cname", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(KDCReqBody, cname)},
	{"sname", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(KDCReqBody, sname)},
	{"from", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KDCReqBody, from)},
	{"till", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KDCReqBody, till)},
	{"rtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KDCReqBody, rtime)},
	{"addresses", "Lsun/security/krb5/internal/HostAddresses;", nullptr, $PUBLIC, $field(KDCReqBody, addresses)},
	{"nonce", "I", nullptr, $PRIVATE, $field(KDCReqBody, nonce)},
	{"eType", "[I", nullptr, $PRIVATE, $field(KDCReqBody, eType)},
	{"encAuthorizationData", "Lsun/security/krb5/EncryptedData;", nullptr, $PRIVATE, $field(KDCReqBody, encAuthorizationData)},
	{"additionalTickets", "[Lsun/security/krb5/internal/Ticket;", nullptr, $PRIVATE, $field(KDCReqBody, additionalTickets)},
	{}
};

$MethodInfo _KDCReqBody_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/KDCOptions;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;I[ILsun/security/krb5/internal/HostAddresses;Lsun/security/krb5/EncryptedData;[Lsun/security/krb5/internal/Ticket;)V", nullptr, $PUBLIC, $method(static_cast<void(KDCReqBody::*)($KDCOptions*,$PrincipalName*,$PrincipalName*,$KerberosTime*,$KerberosTime*,$KerberosTime*,int32_t,$ints*,$HostAddresses*,$EncryptedData*,$TicketArray*)>(&KDCReqBody::init$)), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;I)V", nullptr, $PUBLIC, $method(static_cast<void(KDCReqBody::*)($DerValue*,int32_t)>(&KDCReqBody::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.KrbException,java.io.IOException"},
	{"asn1Encode", "(I)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"getNonce", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KDCReqBody_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KDCReqBody",
	"java.lang.Object",
	nullptr,
	_KDCReqBody_FieldInfo_,
	_KDCReqBody_MethodInfo_
};

$Object* allocate$KDCReqBody($Class* clazz) {
	return $of($alloc(KDCReqBody));
}

void KDCReqBody::init$($KDCOptions* new_kdcOptions, $PrincipalName* new_cname, $PrincipalName* new_sname, $KerberosTime* new_from, $KerberosTime* new_till, $KerberosTime* new_rtime, int32_t new_nonce, $ints* new_eType, $HostAddresses* new_addresses, $EncryptedData* new_encAuthorizationData, $TicketArray* new_additionalTickets) {
	$set(this, eType, nullptr);
	$set(this, kdcOptions, new_kdcOptions);
	$set(this, cname, new_cname);
	$set(this, sname, new_sname);
	$set(this, from, new_from);
	$set(this, till, new_till);
	$set(this, rtime, new_rtime);
	this->nonce = new_nonce;
	if (new_eType != nullptr) {
		$set(this, eType, $cast($ints, new_eType->clone()));
	}
	$set(this, addresses, new_addresses);
	$set(this, encAuthorizationData, new_encAuthorizationData);
	if (new_additionalTickets != nullptr) {
		$set(this, additionalTickets, $new($TicketArray, new_additionalTickets->length));
		for (int32_t i = 0; i < new_additionalTickets->length; ++i) {
			if (new_additionalTickets->get(i) == nullptr) {
				$throwNew($IOException, "Cannot create a KDCReqBody"_s);
			} else {
				$nc(this->additionalTickets)->set(i, $cast($Ticket, $($nc(new_additionalTickets->get(i))->clone())));
			}
		}
	}
}

void KDCReqBody::init$($DerValue* encoding, int32_t msgType) {
	$set(this, eType, nullptr);
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	$set(this, addresses, nullptr);
	$set(this, encAuthorizationData, nullptr);
	$set(this, additionalTickets, nullptr);
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, kdcOptions, $KDCOptions::parse($($nc(encoding)->getData()), (int8_t)0, false));
	$var($DerInputStream, var$0, $nc(encoding)->getData());
	int8_t var$1 = (int8_t)1;
	$set(this, cname, $PrincipalName::parse(var$0, var$1, true, $$new($Realm, "PLACEHOLDER"_s)));
	if ((msgType != $Krb5::KRB_AS_REQ) && (this->cname != nullptr)) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$var($Realm, realm, $Realm::parse($($nc(encoding)->getData()), (int8_t)2, false));
	if (this->cname != nullptr) {
		int32_t var$2 = $nc(this->cname)->getNameType();
		$set(this, cname, $new($PrincipalName, var$2, $($nc(this->cname)->getNameStrings()), realm));
	}
	$set(this, sname, $PrincipalName::parse($($nc(encoding)->getData()), (int8_t)3, true, realm));
	$set(this, from, $KerberosTime::parse($($nc(encoding)->getData()), (int8_t)4, true));
	$set(this, till, $KerberosTime::parse($($nc(encoding)->getData()), (int8_t)5, false));
	$set(this, rtime, $KerberosTime::parse($($nc(encoding)->getData()), (int8_t)6, true));
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)7) {
		this->nonce = $nc($($nc($(der->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	$var($Vector, v, $new($Vector));
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)8) {
		$assign(subDer, $nc($(der->getData()))->getDerValue());
		if ($nc(subDer)->getTag() == $DerValue::tag_SequenceOf) {
			while ($nc($(subDer->getData()))->available() > 0) {
				v->addElement($($Integer::valueOf($nc($($nc($(subDer->getData()))->getBigInteger()))->intValue())));
			}
			$set(this, eType, $new($ints, v->size()));
			for (int32_t i = 0; i < v->size(); ++i) {
				$nc(this->eType)->set(i, $nc(($cast($Integer, $(v->elementAt(i)))))->intValue());
			}
		} else {
			$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$set(this, addresses, $HostAddresses::parse($(encoding->getData()), (int8_t)9, true));
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$set(this, encAuthorizationData, $EncryptedData::parse($(encoding->getData()), (int8_t)10, true));
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$var($Vector, tempTickets, $new($Vector));
		$assign(der, $nc($(encoding->getData()))->getDerValue());
		if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)11) {
			$assign(subDer, $nc($(der->getData()))->getDerValue());
			if ($nc(subDer)->getTag() == $DerValue::tag_SequenceOf) {
				while ($nc($(subDer->getData()))->available() > 0) {
					tempTickets->addElement($$new($Ticket, $($nc($(subDer->getData()))->getDerValue())));
				}
			} else {
				$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
			}
			if (tempTickets->size() > 0) {
				$set(this, additionalTickets, $new($TicketArray, tempTickets->size()));
				tempTickets->copyInto(this->additionalTickets);
			}
		} else {
			$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
		}
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* KDCReqBody::asn1Encode(int32_t msgType) {
	$var($Vector, v, $new($Vector));
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0);
	v->addElement($$new($DerValue, var$0, $($nc(this->kdcOptions)->asn1Encode())));
	if (msgType == $Krb5::KRB_AS_REQ) {
		if (this->cname != nullptr) {
			int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
			v->addElement($$new($DerValue, var$1, $($nc(this->cname)->asn1Encode())));
		}
	}
	if (this->sname != nullptr) {
		int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
		v->addElement($$new($DerValue, var$2, $($nc($($nc(this->sname)->getRealm()))->asn1Encode())));
		int8_t var$3 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
		v->addElement($$new($DerValue, var$3, $($nc(this->sname)->asn1Encode())));
	} else if (this->cname != nullptr) {
		int8_t var$4 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
		v->addElement($$new($DerValue, var$4, $($nc($($nc(this->cname)->getRealm()))->asn1Encode())));
	}
	if (this->from != nullptr) {
		int8_t var$5 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
		v->addElement($$new($DerValue, var$5, $($nc(this->from)->asn1Encode())));
	}
	int8_t var$6 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)5);
	v->addElement($$new($DerValue, var$6, $($nc(this->till)->asn1Encode())));
	if (this->rtime != nullptr) {
		int8_t var$7 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)6);
		v->addElement($$new($DerValue, var$7, $($nc(this->rtime)->asn1Encode())));
	}
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->nonce)));
	int8_t var$8 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)7);
	v->addElement($$new($DerValue, var$8, $(temp->toByteArray())));
	$assign(temp, $new($DerOutputStream));
	for (int32_t i = 0; i < $nc(this->eType)->length; ++i) {
		temp->putInteger($($BigInteger::valueOf((int64_t)$nc(this->eType)->get(i))));
	}
	$var($DerOutputStream, eTypetemp, $new($DerOutputStream));
	eTypetemp->write($DerValue::tag_SequenceOf, temp);
	int8_t var$9 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)8);
	v->addElement($$new($DerValue, var$9, $(eTypetemp->toByteArray())));
	if (this->addresses != nullptr) {
		int8_t var$10 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)9);
		v->addElement($$new($DerValue, var$10, $($nc(this->addresses)->asn1Encode())));
	}
	if (this->encAuthorizationData != nullptr) {
		int8_t var$11 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)10);
		v->addElement($$new($DerValue, var$11, $($nc(this->encAuthorizationData)->asn1Encode())));
	}
	if (this->additionalTickets != nullptr && $nc(this->additionalTickets)->length > 0) {
		$assign(temp, $new($DerOutputStream));
		for (int32_t i = 0; i < $nc(this->additionalTickets)->length; ++i) {
			temp->write($($nc($nc(this->additionalTickets)->get(i))->asn1Encode()));
		}
		$var($DerOutputStream, ticketsTemp, $new($DerOutputStream));
		ticketsTemp->write($DerValue::tag_SequenceOf, temp);
		int8_t var$12 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)11);
		v->addElement($$new($DerValue, var$12, $(ticketsTemp->toByteArray())));
	}
	$var($DerValueArray, der, $new($DerValueArray, v->size()));
	v->copyInto(der);
	$assign(temp, $new($DerOutputStream));
	temp->putSequence(der);
	return temp->toByteArray();
}

int32_t KDCReqBody::getNonce() {
	return this->nonce;
}

KDCReqBody::KDCReqBody() {
}

$Class* KDCReqBody::load$($String* name, bool initialize) {
	$loadClass(KDCReqBody, name, initialize, &_KDCReqBody_ClassInfo_, allocate$KDCReqBody);
	return class$;
}

$Class* KDCReqBody::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun