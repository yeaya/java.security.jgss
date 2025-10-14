#include <sun/security/krb5/internal/ASRep.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/KDCRep.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef KRB_AS_REP

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $KDCRep = ::sun::security::krb5::internal::KDCRep;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$MethodInfo _ASRep_MethodInfo_[] = {
	{"<init>", "([Lsun/security/krb5/internal/PAData;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptedData;)V", nullptr, $PUBLIC, $method(static_cast<void(ASRep::*)($PADataArray*,$PrincipalName*,$Ticket*,$EncryptedData*)>(&ASRep::init$)), "java.io.IOException"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(ASRep::*)($bytes*)>(&ASRep::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(ASRep::*)($DerValue*)>(&ASRep::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(ASRep::*)($DerValue*)>(&ASRep::init)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{}
};

$ClassInfo _ASRep_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ASRep",
	"sun.security.krb5.internal.KDCRep",
	nullptr,
	nullptr,
	_ASRep_MethodInfo_
};

$Object* allocate$ASRep($Class* clazz) {
	return $of($alloc(ASRep));
}

void ASRep::init$($PADataArray* new_pAData, $PrincipalName* new_cname, $Ticket* new_ticket, $EncryptedData* new_encPart) {
	$KDCRep::init$(new_pAData, new_cname, new_ticket, new_encPart, $Krb5::KRB_AS_REP);
}

void ASRep::init$($bytes* data) {
	$KDCRep::init$();
	init($$new($DerValue, data));
}

void ASRep::init$($DerValue* encoding) {
	$KDCRep::init$();
	init(encoding);
}

void ASRep::init($DerValue* encoding) {
	init(encoding, $Krb5::KRB_AS_REP);
}

ASRep::ASRep() {
}

$Class* ASRep::load$($String* name, bool initialize) {
	$loadClass(ASRep, name, initialize, &_ASRep_ClassInfo_, allocate$ASRep);
	return class$;
}

$Class* ASRep::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun