#include <sun/security/krb5/internal/EncKDCRepPart.h>

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
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/LastReq.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef KRB_ENC_AS_REP_PART
#undef KRB_ENC_TGS_REP_PART
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $LastReq = ::sun::security::krb5::internal::LastReq;
using $PAData = ::sun::security::krb5::internal::PAData;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _EncKDCRepPart_FieldInfo_[] = {
	{"key", "Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC, $field(EncKDCRepPart, key)},
	{"lastReq", "Lsun/security/krb5/internal/LastReq;", nullptr, $PUBLIC, $field(EncKDCRepPart, lastReq)},
	{"nonce", "I", nullptr, $PUBLIC, $field(EncKDCRepPart, nonce)},
	{"keyExpiration", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncKDCRepPart, keyExpiration)},
	{"flags", "Lsun/security/krb5/internal/TicketFlags;", nullptr, $PUBLIC, $field(EncKDCRepPart, flags)},
	{"authtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncKDCRepPart, authtime)},
	{"starttime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncKDCRepPart, starttime)},
	{"endtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncKDCRepPart, endtime)},
	{"renewTill", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncKDCRepPart, renewTill)},
	{"sname", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(EncKDCRepPart, sname)},
	{"caddr", "Lsun/security/krb5/internal/HostAddresses;", nullptr, $PUBLIC, $field(EncKDCRepPart, caddr)},
	{"pAData", "[Lsun/security/krb5/internal/PAData;", nullptr, $PUBLIC, $field(EncKDCRepPart, pAData)},
	{"msgType", "I", nullptr, $PUBLIC, $field(EncKDCRepPart, msgType)},
	{}
};

$MethodInfo _EncKDCRepPart_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/LastReq;ILsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/TicketFlags;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/HostAddresses;[Lsun/security/krb5/internal/PAData;I)V", nullptr, $PUBLIC, $method(static_cast<void(EncKDCRepPart::*)($EncryptionKey*,$LastReq*,int32_t,$KerberosTime*,$TicketFlags*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$PrincipalName*,$HostAddresses*,$PADataArray*,int32_t)>(&EncKDCRepPart::init$))},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(EncKDCRepPart::*)()>(&EncKDCRepPart::init$))},
	{"<init>", "([BI)V", nullptr, $PUBLIC, $method(static_cast<void(EncKDCRepPart::*)($bytes*,int32_t)>(&EncKDCRepPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{"<init>", "(Lsun/security/util/DerValue;I)V", nullptr, $PUBLIC, $method(static_cast<void(EncKDCRepPart::*)($DerValue*,int32_t)>(&EncKDCRepPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{"asn1Encode", "(I)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;I)V", nullptr, $PROTECTED, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{}
};

$ClassInfo _EncKDCRepPart_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.EncKDCRepPart",
	"java.lang.Object",
	nullptr,
	_EncKDCRepPart_FieldInfo_,
	_EncKDCRepPart_MethodInfo_
};

$Object* allocate$EncKDCRepPart($Class* clazz) {
	return $of($alloc(EncKDCRepPart));
}

void EncKDCRepPart::init$($EncryptionKey* new_key, $LastReq* new_lastReq, int32_t new_nonce, $KerberosTime* new_keyExpiration, $TicketFlags* new_flags, $KerberosTime* new_authtime, $KerberosTime* new_starttime, $KerberosTime* new_endtime, $KerberosTime* new_renewTill, $PrincipalName* new_sname, $HostAddresses* new_caddr, $PADataArray* new_pAData, int32_t new_msgType) {
	$set(this, key, new_key);
	$set(this, lastReq, new_lastReq);
	this->nonce = new_nonce;
	$set(this, keyExpiration, new_keyExpiration);
	$set(this, flags, new_flags);
	$set(this, authtime, new_authtime);
	$set(this, starttime, new_starttime);
	$set(this, endtime, new_endtime);
	$set(this, renewTill, new_renewTill);
	$set(this, sname, new_sname);
	$set(this, caddr, new_caddr);
	$set(this, pAData, new_pAData);
	this->msgType = new_msgType;
}

void EncKDCRepPart::init$() {
}

void EncKDCRepPart::init$($bytes* data, int32_t rep_type) {
	init($$new($DerValue, data), rep_type);
}

void EncKDCRepPart::init$($DerValue* encoding, int32_t rep_type) {
	init(encoding, rep_type);
}

void EncKDCRepPart::init($DerValue* encoding, int32_t rep_type) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	this->msgType = ((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31));
	if (this->msgType != $Krb5::KRB_ENC_AS_REP_PART && this->msgType != $Krb5::KRB_ENC_TGS_REP_PART) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if ($nc(der)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, key, $EncryptionKey::parse($($nc(der)->getData()), (int8_t)0, false));
	$set(this, lastReq, $LastReq::parse($($nc(der)->getData()), (int8_t)1, false));
	$assign(subDer, $nc($($nc(der)->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)2) {
		this->nonce = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, keyExpiration, $KerberosTime::parse($(der->getData()), (int8_t)3, true));
	$set(this, flags, $TicketFlags::parse($(der->getData()), (int8_t)4, false));
	$set(this, authtime, $KerberosTime::parse($(der->getData()), (int8_t)5, false));
	$set(this, starttime, $KerberosTime::parse($(der->getData()), (int8_t)6, true));
	$set(this, endtime, $KerberosTime::parse($(der->getData()), (int8_t)7, false));
	$set(this, renewTill, $KerberosTime::parse($(der->getData()), (int8_t)8, true));
	$var($Realm, srealm, $Realm::parse($(der->getData()), (int8_t)9, false));
	$set(this, sname, $PrincipalName::parse($(der->getData()), (int8_t)10, false, srealm));
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, caddr, $HostAddresses::parse($(der->getData()), (int8_t)11, true));
	}
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, pAData, $PAData::parseSequence($(der->getData()), (int8_t)12, true));
	}
}

$bytes* EncKDCRepPart::asn1Encode(int32_t rep_type) {
	$var($DerOutputStream, bytes, nullptr);
	$var($DerOutputStream, temp, $new($DerOutputStream));
	$var($DerOutputStream, out, $new($DerOutputStream));
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0);
	out->write(var$0, $($nc(this->key)->asn1Encode()));
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
	out->write(var$1, $($nc(this->lastReq)->asn1Encode()));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->nonce)));
	out->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), temp);
	if (this->keyExpiration != nullptr) {
		int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
		out->write(var$2, $($nc(this->keyExpiration)->asn1Encode()));
	}
	int8_t var$3 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
	out->write(var$3, $($nc(this->flags)->asn1Encode()));
	int8_t var$4 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)5);
	out->write(var$4, $($nc(this->authtime)->asn1Encode()));
	if (this->starttime != nullptr) {
		int8_t var$5 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)6);
		out->write(var$5, $($nc(this->starttime)->asn1Encode()));
	}
	int8_t var$6 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)7);
	out->write(var$6, $($nc(this->endtime)->asn1Encode()));
	if (this->renewTill != nullptr) {
		int8_t var$7 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)8);
		out->write(var$7, $($nc(this->renewTill)->asn1Encode()));
	}
	int8_t var$8 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)9);
	out->write(var$8, $($nc($($nc(this->sname)->getRealm()))->asn1Encode()));
	int8_t var$9 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)10);
	out->write(var$9, $($nc(this->sname)->asn1Encode()));
	if (this->caddr != nullptr) {
		int8_t var$10 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)11);
		out->write(var$10, $($nc(this->caddr)->asn1Encode()));
	}
	if (this->pAData != nullptr && $nc(this->pAData)->length > 0) {
		$assign(temp, $new($DerOutputStream));
		for (int32_t i = 0; i < $nc(this->pAData)->length; ++i) {
			temp->write($($nc($nc(this->pAData)->get(i))->asn1Encode()));
		}
		$assign(bytes, $new($DerOutputStream));
		bytes->write($DerValue::tag_SequenceOf, temp);
		out->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)12), bytes);
	}
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, out);
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)this->msgType), temp);
	return bytes->toByteArray();
}

EncKDCRepPart::EncKDCRepPart() {
}

$Class* EncKDCRepPart::load$($String* name, bool initialize) {
	$loadClass(EncKDCRepPart, name, initialize, &_EncKDCRepPart_ClassInfo_, allocate$EncKDCRepPart);
	return class$;
}

$Class* EncKDCRepPart::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun