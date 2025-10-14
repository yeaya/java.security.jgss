#include <sun/security/krb5/internal/KDCRep.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintStream.h>
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
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/EncKDCRepPart.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef DEBUG
#undef KRB_AP_ERR_BADVERSION
#undef KRB_AP_ERR_MSG_TYPE
#undef PVNO
#undef TAG_CONTEXT

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $EncKDCRepPart = ::sun::security::krb5::internal::EncKDCRepPart;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $PAData = ::sun::security::krb5::internal::PAData;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KDCRep_FieldInfo_[] = {
	{"cname", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(KDCRep, cname)},
	{"ticket", "Lsun/security/krb5/internal/Ticket;", nullptr, $PUBLIC, $field(KDCRep, ticket)},
	{"encPart", "Lsun/security/krb5/EncryptedData;", nullptr, $PUBLIC, $field(KDCRep, encPart)},
	{"encKDCRepPart", "Lsun/security/krb5/internal/EncKDCRepPart;", nullptr, $PUBLIC, $field(KDCRep, encKDCRepPart)},
	{"pvno", "I", nullptr, $PRIVATE, $field(KDCRep, pvno)},
	{"msgType", "I", nullptr, $PRIVATE, $field(KDCRep, msgType)},
	{"pAData", "[Lsun/security/krb5/internal/PAData;", nullptr, $PUBLIC, $field(KDCRep, pAData)},
	{"DEBUG", "Z", nullptr, $PRIVATE, $field(KDCRep, DEBUG)},
	{}
};

$MethodInfo _KDCRep_MethodInfo_[] = {
	{"<init>", "([Lsun/security/krb5/internal/PAData;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptedData;I)V", nullptr, $PUBLIC, $method(static_cast<void(KDCRep::*)($PADataArray*,$PrincipalName*,$Ticket*,$EncryptedData*,int32_t)>(&KDCRep::init$)), "java.io.IOException"},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(KDCRep::*)()>(&KDCRep::init$))},
	{"<init>", "([BI)V", nullptr, $PUBLIC, $method(static_cast<void(KDCRep::*)($bytes*,int32_t)>(&KDCRep::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.RealmException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;I)V", nullptr, $PUBLIC, $method(static_cast<void(KDCRep::*)($DerValue*,int32_t)>(&KDCRep::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;I)V", nullptr, $PROTECTED, nullptr, "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,java.io.IOException,sun.security.krb5.internal.KrbApErrException"},
	{}
};

$ClassInfo _KDCRep_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KDCRep",
	"java.lang.Object",
	nullptr,
	_KDCRep_FieldInfo_,
	_KDCRep_MethodInfo_
};

$Object* allocate$KDCRep($Class* clazz) {
	return $of($alloc(KDCRep));
}

void KDCRep::init$($PADataArray* new_pAData, $PrincipalName* new_cname, $Ticket* new_ticket, $EncryptedData* new_encPart, int32_t req_type) {
	$set(this, pAData, nullptr);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	this->pvno = $Krb5::PVNO;
	this->msgType = req_type;
	if (new_pAData != nullptr) {
		$set(this, pAData, $new($PADataArray, new_pAData->length));
		for (int32_t i = 0; i < new_pAData->length; ++i) {
			if (new_pAData->get(i) == nullptr) {
				$throwNew($IOException, "Cannot create a KDCRep"_s);
			} else {
				$nc(this->pAData)->set(i, $cast($PAData, $($nc(new_pAData->get(i))->clone())));
			}
		}
	}
	$set(this, cname, new_cname);
	$set(this, ticket, new_ticket);
	$set(this, encPart, new_encPart);
}

void KDCRep::init$() {
	$set(this, pAData, nullptr);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
}

void KDCRep::init$($bytes* data, int32_t req_type) {
	$set(this, pAData, nullptr);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	init($$new($DerValue, data), req_type);
}

void KDCRep::init$($DerValue* encoding, int32_t req_type) {
	$set(this, pAData, nullptr);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	init(encoding, req_type);
}

void KDCRep::init($DerValue* encoding, int32_t req_type) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	if (((int32_t)($nc(encoding)->getTag() & (uint32_t)31)) != req_type) {
		if (this->DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>> KDCRep: init() encoding tag is "_s, $$str(encoding->getTag()), " req type is "_s, $$str(req_type)}));
		}
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
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
		if (this->msgType != req_type) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MSG_TYPE);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if (((int32_t)($nc($(der->getData()))->peekByte() & (uint32_t)31)) == 2) {
		$assign(subDer, $nc($(der->getData()))->getDerValue());
		$var($DerValueArray, padata, $nc($($nc(subDer)->getData()))->getSequence(1));
		$set(this, pAData, $new($PADataArray, $nc(padata)->length));
		for (int32_t i = 0; i < padata->length; ++i) {
			$nc(this->pAData)->set(i, $$new($PAData, padata->get(i)));
		}
	} else {
		$set(this, pAData, nullptr);
	}
	$var($Realm, crealm, $Realm::parse($(der->getData()), (int8_t)3, false));
	$set(this, cname, $PrincipalName::parse($(der->getData()), (int8_t)4, false, crealm));
	$set(this, ticket, $Ticket::parse($(der->getData()), (int8_t)5, false));
	$set(this, encPart, $EncryptedData::parse($(der->getData()), (int8_t)6, false));
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* KDCRep::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->pvno)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->msgType)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	if (this->pAData != nullptr && $nc(this->pAData)->length > 0) {
		$var($DerOutputStream, padata_stream, $new($DerOutputStream));
		for (int32_t i = 0; i < $nc(this->pAData)->length; ++i) {
			padata_stream->write($($nc($nc(this->pAData)->get(i))->asn1Encode()));
		}
		$assign(temp, $new($DerOutputStream));
		temp->write($DerValue::tag_SequenceOf, padata_stream);
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), temp);
	}
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
	bytes->write(var$0, $($nc($($nc(this->cname)->getRealm()))->asn1Encode()));
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
	bytes->write(var$1, $($nc(this->cname)->asn1Encode()));
	int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)5);
	bytes->write(var$2, $($nc(this->ticket)->asn1Encode()));
	int8_t var$3 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)6);
	bytes->write(var$3, $($nc(this->encPart)->asn1Encode()));
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

KDCRep::KDCRep() {
}

$Class* KDCRep::load$($String* name, bool initialize) {
	$loadClass(KDCRep, name, initialize, &_KDCRep_ClassInfo_, allocate$KDCRep);
	return class$;
}

$Class* KDCRep::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun