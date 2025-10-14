#include <sun/security/krb5/internal/EncTicketPart.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/TransitedEncoding.h>
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
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $TransitedEncoding = ::sun::security::krb5::internal::TransitedEncoding;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _EncTicketPart_FieldInfo_[] = {
	{"flags", "Lsun/security/krb5/internal/TicketFlags;", nullptr, $PUBLIC, $field(EncTicketPart, flags)},
	{"key", "Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC, $field(EncTicketPart, key)},
	{"cname", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(EncTicketPart, cname)},
	{"transited", "Lsun/security/krb5/internal/TransitedEncoding;", nullptr, $PUBLIC, $field(EncTicketPart, transited)},
	{"authtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncTicketPart, authtime)},
	{"starttime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncTicketPart, starttime)},
	{"endtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncTicketPart, endtime)},
	{"renewTill", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncTicketPart, renewTill)},
	{"caddr", "Lsun/security/krb5/internal/HostAddresses;", nullptr, $PUBLIC, $field(EncTicketPart, caddr)},
	{"authorizationData", "Lsun/security/krb5/internal/AuthorizationData;", nullptr, $PUBLIC, $field(EncTicketPart, authorizationData)},
	{}
};

$MethodInfo _EncTicketPart_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/TicketFlags;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/TransitedEncoding;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/HostAddresses;Lsun/security/krb5/internal/AuthorizationData;)V", nullptr, $PUBLIC, $method(static_cast<void(EncTicketPart::*)($TicketFlags*,$EncryptionKey*,$PrincipalName*,$TransitedEncoding*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$HostAddresses*,$AuthorizationData*)>(&EncTicketPart::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(EncTicketPart::*)($bytes*)>(&EncTicketPart::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(EncTicketPart::*)($DerValue*)>(&EncTicketPart::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.KrbException,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"getHexBytes", "([BI)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($bytes*,int32_t)>(&EncTicketPart::getHexBytes)), "java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(EncTicketPart::*)($DerValue*)>(&EncTicketPart::init)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{}
};

$ClassInfo _EncTicketPart_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.EncTicketPart",
	"java.lang.Object",
	nullptr,
	_EncTicketPart_FieldInfo_,
	_EncTicketPart_MethodInfo_
};

$Object* allocate$EncTicketPart($Class* clazz) {
	return $of($alloc(EncTicketPart));
}

void EncTicketPart::init$($TicketFlags* new_flags, $EncryptionKey* new_key, $PrincipalName* new_cname, $TransitedEncoding* new_transited, $KerberosTime* new_authtime, $KerberosTime* new_starttime, $KerberosTime* new_endtime, $KerberosTime* new_renewTill, $HostAddresses* new_caddr, $AuthorizationData* new_authorizationData) {
	$set(this, flags, new_flags);
	$set(this, key, new_key);
	$set(this, cname, new_cname);
	$set(this, transited, new_transited);
	$set(this, authtime, new_authtime);
	$set(this, starttime, new_starttime);
	$set(this, endtime, new_endtime);
	$set(this, renewTill, new_renewTill);
	$set(this, caddr, new_caddr);
	$set(this, authorizationData, new_authorizationData);
}

void EncTicketPart::init$($bytes* data) {
	init($$new($DerValue, data));
}

void EncTicketPart::init$($DerValue* encoding) {
	init(encoding);
}

$String* EncTicketPart::getHexBytes($bytes* bytes, int32_t len) {
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t i = 0; i < len; ++i) {
		int32_t b1 = (int32_t)(($nc(bytes)->get(i) >> 4) & (uint32_t)15);
		int32_t b2 = (int32_t)(bytes->get(i) & (uint32_t)15);
		sb->append($($Integer::toHexString(b1)));
		sb->append($($Integer::toHexString(b2)));
		sb->append(u' ');
	}
	return sb->toString();
}

void EncTicketPart::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	$set(this, renewTill, nullptr);
	$set(this, caddr, nullptr);
	$set(this, authorizationData, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)3);
	bool var$0 = var$1 || ($nc(encoding)->isApplication() != true);
	if (var$0 || ($nc(encoding)->isConstructed() != true)) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if ($nc(der)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, flags, $TicketFlags::parse($($nc(der)->getData()), (int8_t)0, false));
	$set(this, key, $EncryptionKey::parse($($nc(der)->getData()), (int8_t)1, false));
	$var($Realm, crealm, $Realm::parse($($nc(der)->getData()), (int8_t)2, false));
	$set(this, cname, $PrincipalName::parse($($nc(der)->getData()), (int8_t)3, false, crealm));
	$set(this, transited, $TransitedEncoding::parse($($nc(der)->getData()), (int8_t)4, false));
	$set(this, authtime, $KerberosTime::parse($($nc(der)->getData()), (int8_t)5, false));
	$set(this, starttime, $KerberosTime::parse($($nc(der)->getData()), (int8_t)6, true));
	$set(this, endtime, $KerberosTime::parse($($nc(der)->getData()), (int8_t)7, false));
	if ($nc($($nc(der)->getData()))->available() > 0) {
		$set(this, renewTill, $KerberosTime::parse($(der->getData()), (int8_t)8, true));
	}
	if ($nc($($nc(der)->getData()))->available() > 0) {
		$set(this, caddr, $HostAddresses::parse($(der->getData()), (int8_t)9, true));
	}
	if ($nc($($nc(der)->getData()))->available() > 0) {
		$set(this, authorizationData, $AuthorizationData::parse($(der->getData()), (int8_t)10, true));
	}
	if ($nc($($nc(der)->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* EncTicketPart::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0);
	bytes->write(var$0, $($nc(this->flags)->asn1Encode()));
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
	bytes->write(var$1, $($nc(this->key)->asn1Encode()));
	int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
	bytes->write(var$2, $($nc($($nc(this->cname)->getRealm()))->asn1Encode()));
	int8_t var$3 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
	bytes->write(var$3, $($nc(this->cname)->asn1Encode()));
	int8_t var$4 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
	bytes->write(var$4, $($nc(this->transited)->asn1Encode()));
	int8_t var$5 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)5);
	bytes->write(var$5, $($nc(this->authtime)->asn1Encode()));
	if (this->starttime != nullptr) {
		int8_t var$6 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)6);
		bytes->write(var$6, $($nc(this->starttime)->asn1Encode()));
	}
	int8_t var$7 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)7);
	bytes->write(var$7, $($nc(this->endtime)->asn1Encode()));
	if (this->renewTill != nullptr) {
		int8_t var$8 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)8);
		bytes->write(var$8, $($nc(this->renewTill)->asn1Encode()));
	}
	if (this->caddr != nullptr) {
		int8_t var$9 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)9);
		bytes->write(var$9, $($nc(this->caddr)->asn1Encode()));
	}
	if (this->authorizationData != nullptr) {
		int8_t var$10 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)10);
		bytes->write(var$10, $($nc(this->authorizationData)->asn1Encode()));
	}
	temp->write($DerValue::tag_Sequence, bytes);
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)3), temp);
	return bytes->toByteArray();
}

EncTicketPart::EncTicketPart() {
}

$Class* EncTicketPart::load$($String* name, bool initialize) {
	$loadClass(EncTicketPart, name, initialize, &_EncTicketPart_ClassInfo_, allocate$EncTicketPart);
	return class$;
}

$Class* EncTicketPart::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun