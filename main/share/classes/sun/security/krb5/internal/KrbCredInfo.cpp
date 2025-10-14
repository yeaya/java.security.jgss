#include <sun/security/krb5/internal/KrbCredInfo.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Vector.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef TAG_CONTEXT

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Vector = ::java::util::Vector;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KrbCredInfo_FieldInfo_[] = {
	{"key", "Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC, $field(KrbCredInfo, key)},
	{"pname", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(KrbCredInfo, pname)},
	{"flags", "Lsun/security/krb5/internal/TicketFlags;", nullptr, $PUBLIC, $field(KrbCredInfo, flags)},
	{"authtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KrbCredInfo, authtime)},
	{"starttime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KrbCredInfo, starttime)},
	{"endtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KrbCredInfo, endtime)},
	{"renewTill", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KrbCredInfo, renewTill)},
	{"sname", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(KrbCredInfo, sname)},
	{"caddr", "Lsun/security/krb5/internal/HostAddresses;", nullptr, $PUBLIC, $field(KrbCredInfo, caddr)},
	{}
};

$MethodInfo _KrbCredInfo_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(KrbCredInfo::*)()>(&KrbCredInfo::init$))},
	{"<init>", "(Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/TicketFlags;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/HostAddresses;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbCredInfo::*)($EncryptionKey*,$PrincipalName*,$TicketFlags*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$PrincipalName*,$HostAddresses*)>(&KrbCredInfo::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbCredInfo::*)($DerValue*)>(&KrbCredInfo::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KrbCredInfo_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KrbCredInfo",
	"java.lang.Object",
	nullptr,
	_KrbCredInfo_FieldInfo_,
	_KrbCredInfo_MethodInfo_
};

$Object* allocate$KrbCredInfo($Class* clazz) {
	return $of($alloc(KrbCredInfo));
}

void KrbCredInfo::init$() {
}

void KrbCredInfo::init$($EncryptionKey* new_key, $PrincipalName* new_pname, $TicketFlags* new_flags, $KerberosTime* new_authtime, $KerberosTime* new_starttime, $KerberosTime* new_endtime, $KerberosTime* new_renewTill, $PrincipalName* new_sname, $HostAddresses* new_caddr) {
	$set(this, key, new_key);
	$set(this, pname, new_pname);
	$set(this, flags, new_flags);
	$set(this, authtime, new_authtime);
	$set(this, starttime, new_starttime);
	$set(this, endtime, new_endtime);
	$set(this, renewTill, new_renewTill);
	$set(this, sname, new_sname);
	$set(this, caddr, new_caddr);
}

void KrbCredInfo::init$($DerValue* encoding) {
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, pname, nullptr);
	$set(this, flags, nullptr);
	$set(this, authtime, nullptr);
	$set(this, starttime, nullptr);
	$set(this, endtime, nullptr);
	$set(this, renewTill, nullptr);
	$set(this, sname, nullptr);
	$set(this, caddr, nullptr);
	$set(this, key, $EncryptionKey::parse($($nc(encoding)->getData()), (int8_t)0, false));
	$var($Realm, prealm, nullptr);
	$var($Realm, srealm, nullptr);
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$assign(prealm, $Realm::parse($(encoding->getData()), (int8_t)1, true));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$set(this, pname, $PrincipalName::parse($(encoding->getData()), (int8_t)2, true, prealm));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$set(this, flags, $TicketFlags::parse($(encoding->getData()), (int8_t)3, true));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$set(this, authtime, $KerberosTime::parse($(encoding->getData()), (int8_t)4, true));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$set(this, starttime, $KerberosTime::parse($(encoding->getData()), (int8_t)5, true));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$set(this, endtime, $KerberosTime::parse($(encoding->getData()), (int8_t)6, true));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$set(this, renewTill, $KerberosTime::parse($(encoding->getData()), (int8_t)7, true));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$assign(srealm, $Realm::parse($(encoding->getData()), (int8_t)8, true));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$set(this, sname, $PrincipalName::parse($(encoding->getData()), (int8_t)9, true, srealm));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$set(this, caddr, $HostAddresses::parse($(encoding->getData()), (int8_t)10, true));
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* KrbCredInfo::asn1Encode() {
	$var($Vector, v, $new($Vector));
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0);
	v->addElement($$new($DerValue, var$0, $($nc(this->key)->asn1Encode())));
	if (this->pname != nullptr) {
		int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
		v->addElement($$new($DerValue, var$1, $($nc($($nc(this->pname)->getRealm()))->asn1Encode())));
		int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
		v->addElement($$new($DerValue, var$2, $($nc(this->pname)->asn1Encode())));
	}
	if (this->flags != nullptr) {
		int8_t var$3 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
		v->addElement($$new($DerValue, var$3, $($nc(this->flags)->asn1Encode())));
	}
	if (this->authtime != nullptr) {
		int8_t var$4 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
		v->addElement($$new($DerValue, var$4, $($nc(this->authtime)->asn1Encode())));
	}
	if (this->starttime != nullptr) {
		int8_t var$5 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)5);
		v->addElement($$new($DerValue, var$5, $($nc(this->starttime)->asn1Encode())));
	}
	if (this->endtime != nullptr) {
		int8_t var$6 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)6);
		v->addElement($$new($DerValue, var$6, $($nc(this->endtime)->asn1Encode())));
	}
	if (this->renewTill != nullptr) {
		int8_t var$7 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)7);
		v->addElement($$new($DerValue, var$7, $($nc(this->renewTill)->asn1Encode())));
	}
	if (this->sname != nullptr) {
		int8_t var$8 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)8);
		v->addElement($$new($DerValue, var$8, $($nc($($nc(this->sname)->getRealm()))->asn1Encode())));
		int8_t var$9 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)9);
		v->addElement($$new($DerValue, var$9, $($nc(this->sname)->asn1Encode())));
	}
	if (this->caddr != nullptr) {
		int8_t var$10 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)10);
		v->addElement($$new($DerValue, var$10, $($nc(this->caddr)->asn1Encode())));
	}
	$var($DerValueArray, der, $new($DerValueArray, v->size()));
	v->copyInto(der);
	$var($DerOutputStream, out, $new($DerOutputStream));
	out->putSequence(der);
	return out->toByteArray();
}

$Object* KrbCredInfo::clone() {
	$var(KrbCredInfo, kcred, $new(KrbCredInfo));
	$set(kcred, key, $cast($EncryptionKey, $nc(this->key)->clone()));
	if (this->pname != nullptr) {
		$set(kcred, pname, $cast($PrincipalName, $nc(this->pname)->clone()));
	}
	if (this->flags != nullptr) {
		$set(kcred, flags, $cast($TicketFlags, $nc(this->flags)->clone()));
	}
	$set(kcred, authtime, this->authtime);
	$set(kcred, starttime, this->starttime);
	$set(kcred, endtime, this->endtime);
	$set(kcred, renewTill, this->renewTill);
	if (this->sname != nullptr) {
		$set(kcred, sname, $cast($PrincipalName, $nc(this->sname)->clone()));
	}
	if (this->caddr != nullptr) {
		$set(kcred, caddr, $cast($HostAddresses, $nc(this->caddr)->clone()));
	}
	return $of(kcred);
}

KrbCredInfo::KrbCredInfo() {
}

$Class* KrbCredInfo::load$($String* name, bool initialize) {
	$loadClass(KrbCredInfo, name, initialize, &_KrbCredInfo_ClassInfo_, allocate$KrbCredInfo);
	return class$;
}

$Class* KrbCredInfo::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun