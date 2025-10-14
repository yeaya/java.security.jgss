#include <sun/security/krb5/internal/Authenticator.h>

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
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef AUTHNETICATOR_VNO
#undef KRB_AP_ERR_BADVERSION
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Vector = ::java::util::Vector;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Checksum = ::sun::security::krb5::Checksum;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _Authenticator_FieldInfo_[] = {
	{"authenticator_vno", "I", nullptr, $PUBLIC, $field(Authenticator, authenticator_vno)},
	{"cname", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(Authenticator, cname)},
	{"cksum", "Lsun/security/krb5/Checksum;", nullptr, 0, $field(Authenticator, cksum)},
	{"cusec", "I", nullptr, $PUBLIC, $field(Authenticator, cusec)},
	{"ctime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(Authenticator, ctime)},
	{"subKey", "Lsun/security/krb5/EncryptionKey;", nullptr, 0, $field(Authenticator, subKey)},
	{"seqNumber", "Ljava/lang/Integer;", nullptr, 0, $field(Authenticator, seqNumber)},
	{"authorizationData", "Lsun/security/krb5/internal/AuthorizationData;", nullptr, $PUBLIC, $field(Authenticator, authorizationData)},
	{}
};

$MethodInfo _Authenticator_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Checksum;ILsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/EncryptionKey;Ljava/lang/Integer;Lsun/security/krb5/internal/AuthorizationData;)V", nullptr, $PUBLIC, $method(static_cast<void(Authenticator::*)($PrincipalName*,$Checksum*,int32_t,$KerberosTime*,$EncryptionKey*,$Integer*,$AuthorizationData*)>(&Authenticator::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(Authenticator::*)($bytes*)>(&Authenticator::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.RealmException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(Authenticator::*)($DerValue*)>(&Authenticator::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.RealmException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"getChecksum", "()Lsun/security/krb5/Checksum;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Checksum*(Authenticator::*)()>(&Authenticator::getChecksum))},
	{"getSeqNumber", "()Ljava/lang/Integer;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Integer*(Authenticator::*)()>(&Authenticator::getSeqNumber))},
	{"getSubKey", "()Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$EncryptionKey*(Authenticator::*)()>(&Authenticator::getSubKey))},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(Authenticator::*)($DerValue*)>(&Authenticator::init)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.RealmException"},
	{}
};

$ClassInfo _Authenticator_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.Authenticator",
	"java.lang.Object",
	nullptr,
	_Authenticator_FieldInfo_,
	_Authenticator_MethodInfo_
};

$Object* allocate$Authenticator($Class* clazz) {
	return $of($alloc(Authenticator));
}

void Authenticator::init$($PrincipalName* new_cname, $Checksum* new_cksum, int32_t new_cusec, $KerberosTime* new_ctime, $EncryptionKey* new_subKey, $Integer* new_seqNumber, $AuthorizationData* new_authorizationData) {
	this->authenticator_vno = $Krb5::AUTHNETICATOR_VNO;
	$set(this, cname, new_cname);
	$set(this, cksum, new_cksum);
	this->cusec = new_cusec;
	$set(this, ctime, new_ctime);
	$set(this, subKey, new_subKey);
	$set(this, seqNumber, new_seqNumber);
	$set(this, authorizationData, new_authorizationData);
}

void Authenticator::init$($bytes* data) {
	init($$new($DerValue, data));
}

void Authenticator::init$($DerValue* encoding) {
	init(encoding);
}

void Authenticator::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)2);
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
	this->authenticator_vno = $nc($($nc($($nc(subDer)->getData()))->getBigInteger()))->intValue();
	if (this->authenticator_vno != 5) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADVERSION);
	}
	$var($Realm, crealm, $Realm::parse($(der->getData()), (int8_t)1, false));
	$set(this, cname, $PrincipalName::parse($(der->getData()), (int8_t)2, false, crealm));
	$set(this, cksum, $Checksum::parse($(der->getData()), (int8_t)3, true));
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)(subDer->getTag() & (uint32_t)(int32_t)(int8_t)31)) == 4) {
		this->cusec = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, ctime, $KerberosTime::parse($(der->getData()), (int8_t)5, false));
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, subKey, $EncryptionKey::parse($(der->getData()), (int8_t)6, true));
	} else {
		$set(this, subKey, nullptr);
		$set(this, seqNumber, nullptr);
		$set(this, authorizationData, nullptr);
	}
	if ($nc($(der->getData()))->available() > 0) {
		if (((int32_t)($nc($(der->getData()))->peekByte() & (uint32_t)31)) == 7) {
			$assign(subDer, $nc($(der->getData()))->getDerValue());
			if (((int32_t)($nc(subDer)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)7) {
				$set(this, seqNumber, $Integer::valueOf($nc($($nc($(subDer->getData()))->getBigInteger()))->intValue()));
			}
		}
	} else {
		$set(this, seqNumber, nullptr);
		$set(this, authorizationData, nullptr);
	}
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, authorizationData, $AuthorizationData::parse($(der->getData()), (int8_t)8, true));
	} else {
		$set(this, authorizationData, nullptr);
	}
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* Authenticator::asn1Encode() {
	$var($Vector, v, $new($Vector));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->authenticator_vno)));
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0);
	v->addElement($$new($DerValue, var$0, $(temp->toByteArray())));
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
	v->addElement($$new($DerValue, var$1, $($nc($($nc(this->cname)->getRealm()))->asn1Encode())));
	int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
	v->addElement($$new($DerValue, var$2, $($nc(this->cname)->asn1Encode())));
	if (this->cksum != nullptr) {
		int8_t var$3 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
		v->addElement($$new($DerValue, var$3, $($nc(this->cksum)->asn1Encode())));
	}
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->cusec)));
	int8_t var$4 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
	v->addElement($$new($DerValue, var$4, $(temp->toByteArray())));
	int8_t var$5 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)5);
	v->addElement($$new($DerValue, var$5, $($nc(this->ctime)->asn1Encode())));
	if (this->subKey != nullptr) {
		int8_t var$6 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)6);
		v->addElement($$new($DerValue, var$6, $($nc(this->subKey)->asn1Encode())));
	}
	if (this->seqNumber != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putInteger($($BigInteger::valueOf($nc(this->seqNumber)->longValue())));
		int8_t var$7 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)7);
		v->addElement($$new($DerValue, var$7, $(temp->toByteArray())));
	}
	if (this->authorizationData != nullptr) {
		int8_t var$8 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)8);
		v->addElement($$new($DerValue, var$8, $($nc(this->authorizationData)->asn1Encode())));
	}
	$var($DerValueArray, der, $new($DerValueArray, v->size()));
	v->copyInto(der);
	$assign(temp, $new($DerOutputStream));
	temp->putSequence(der);
	$var($DerOutputStream, out, $new($DerOutputStream));
	out->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)2), temp);
	return out->toByteArray();
}

$Checksum* Authenticator::getChecksum() {
	return this->cksum;
}

$Integer* Authenticator::getSeqNumber() {
	return this->seqNumber;
}

$EncryptionKey* Authenticator::getSubKey() {
	return this->subKey;
}

Authenticator::Authenticator() {
}

$Class* Authenticator::load$($String* name, bool initialize) {
	$loadClass(Authenticator, name, initialize, &_Authenticator_ClassInfo_, allocate$Authenticator);
	return class$;
}

$Class* Authenticator::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun