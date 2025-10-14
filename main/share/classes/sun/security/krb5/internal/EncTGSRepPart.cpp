#include <sun/security/krb5/internal/EncTGSRepPart.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/EncKDCRepPart.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/LastReq.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef KRB_ENC_TGS_REP_PART

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $EncKDCRepPart = ::sun::security::krb5::internal::EncKDCRepPart;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $LastReq = ::sun::security::krb5::internal::LastReq;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$MethodInfo _EncTGSRepPart_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/LastReq;ILsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/TicketFlags;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/HostAddresses;[Lsun/security/krb5/internal/PAData;)V", nullptr, $PUBLIC, $method(static_cast<void(EncTGSRepPart::*)($EncryptionKey*,$LastReq*,int32_t,$KerberosTime*,$TicketFlags*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$PrincipalName*,$HostAddresses*,$PADataArray*)>(&EncTGSRepPart::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(EncTGSRepPart::*)($bytes*)>(&EncTGSRepPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(EncTGSRepPart::*)($DerValue*)>(&EncTGSRepPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(EncTGSRepPart::*)($DerValue*)>(&EncTGSRepPart::init)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{}
};

$ClassInfo _EncTGSRepPart_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.EncTGSRepPart",
	"sun.security.krb5.internal.EncKDCRepPart",
	nullptr,
	nullptr,
	_EncTGSRepPart_MethodInfo_
};

$Object* allocate$EncTGSRepPart($Class* clazz) {
	return $of($alloc(EncTGSRepPart));
}

void EncTGSRepPart::init$($EncryptionKey* new_key, $LastReq* new_lastReq, int32_t new_nonce, $KerberosTime* new_keyExpiration, $TicketFlags* new_flags, $KerberosTime* new_authtime, $KerberosTime* new_starttime, $KerberosTime* new_endtime, $KerberosTime* new_renewTill, $PrincipalName* new_sname, $HostAddresses* new_caddr, $PADataArray* new_pAData) {
	$EncKDCRepPart::init$(new_key, new_lastReq, new_nonce, new_keyExpiration, new_flags, new_authtime, new_starttime, new_endtime, new_renewTill, new_sname, new_caddr, new_pAData, $Krb5::KRB_ENC_TGS_REP_PART);
}

void EncTGSRepPart::init$($bytes* data) {
	$EncKDCRepPart::init$();
	init($$new($DerValue, data));
}

void EncTGSRepPart::init$($DerValue* encoding) {
	$EncKDCRepPart::init$();
	init(encoding);
}

void EncTGSRepPart::init($DerValue* encoding) {
	init(encoding, $Krb5::KRB_ENC_TGS_REP_PART);
}

$bytes* EncTGSRepPart::asn1Encode() {
	return asn1Encode($Krb5::KRB_ENC_TGS_REP_PART);
}

EncTGSRepPart::EncTGSRepPart() {
}

$Class* EncTGSRepPart::load$($String* name, bool initialize) {
	$loadClass(EncTGSRepPart, name, initialize, &_EncTGSRepPart_ClassInfo_, allocate$EncTGSRepPart);
	return class$;
}

$Class* EncTGSRepPart::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun