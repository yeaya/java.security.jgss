#include <sun/security/krb5/KrbKdcRep.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/EncKDCRepPart.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/KDCRep.h>
#include <sun/security/krb5/internal/KDCReq.h>
#include <sun/security/krb5/internal/KDCReqBody.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef CANONICALIZE
#undef DEBUG
#undef KRB_AP_ERR_MODIFIED
#undef KRB_AP_ERR_SKEW
#undef KRB_NT_ENTERPRISE
#undef KU_AS_REQ
#undef PA_REQ_ENC_PA_REP
#undef RENEWABLE
#undef TGS_DEFAULT_SRV_NAME
#undef TKT_OPTS_ENC_PA_REP

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $Checksum = ::sun::security::krb5::Checksum;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $EncKDCRepPart = ::sun::security::krb5::internal::EncKDCRepPart;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $KDCRep = ::sun::security::krb5::internal::KDCRep;
using $KDCReq = ::sun::security::krb5::internal::KDCReq;
using $KDCReqBody = ::sun::security::krb5::internal::KDCReqBody;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $PAData = ::sun::security::krb5::internal::PAData;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$MethodInfo _KrbKdcRep_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(KrbKdcRep::*)()>(&KrbKdcRep::init$))},
	{"check", "(ZLsun/security/krb5/internal/KDCReq;Lsun/security/krb5/internal/KDCRep;Lsun/security/krb5/EncryptionKey;)V", nullptr, $STATIC, $method(static_cast<void(*)(bool,$KDCReq*,$KDCRep*,$EncryptionKey*)>(&KrbKdcRep::check)), "sun.security.krb5.internal.KrbApErrException"},
	{}
};

$ClassInfo _KrbKdcRep_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.KrbKdcRep",
	"java.lang.Object",
	nullptr,
	nullptr,
	_KrbKdcRep_MethodInfo_
};

$Object* allocate$KrbKdcRep($Class* clazz) {
	return $of($alloc(KrbKdcRep));
}

void KrbKdcRep::init$() {
}

void KrbKdcRep::check(bool isAsReq, $KDCReq* req, $KDCRep* rep, $EncryptionKey* replyKey) {
	bool var$0 = isAsReq && !$nc($nc($nc(req)->reqBody)->cname)->equals($nc(rep)->cname);
	if (var$0) {
		bool var$2 = !$nc($nc(req->reqBody)->kdcOptions)->get($KDCOptions::CANONICALIZE);
		bool var$1 = (var$2 && $nc($nc(req->reqBody)->cname)->getNameType() != $PrincipalName::KRB_NT_ENTERPRISE);
		var$0 = (var$1 || !$nc($nc($nc(rep)->encKDCRepPart)->flags)->get($Krb5::TKT_OPTS_ENC_PA_REP));
	}
	if (var$0) {
		$nc($nc(rep->encKDCRepPart)->key)->destroy();
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
	}
	if (!$nc($nc($nc(req)->reqBody)->sname)->equals($nc($nc(rep)->encKDCRepPart)->sname)) {
		$var($StringArray, snameStrings, $nc($nc($nc(rep)->encKDCRepPart)->sname)->getNameStrings());
		bool var$4 = isAsReq || !$nc($nc(req->reqBody)->kdcOptions)->get($KDCOptions::CANONICALIZE) || snameStrings == nullptr || $nc(snameStrings)->length != 2;
		bool var$3 = var$4 || !$nc($nc(snameStrings)->get(0))->equals($PrincipalName::TGS_DEFAULT_SRV_NAME);
		if (var$3 || !$nc($($nc($nc(rep->encKDCRepPart)->sname)->getRealmString()))->equals($($nc($nc(req->reqBody)->sname)->getRealmString()))) {
			$nc($nc(rep->encKDCRepPart)->key)->destroy();
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
		}
	}
	if ($nc($nc(req)->reqBody)->getNonce() != $nc($nc(rep)->encKDCRepPart)->nonce) {
		$nc($nc(rep->encKDCRepPart)->key)->destroy();
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
	}
	if (($nc($nc(req)->reqBody)->addresses != nullptr && $nc($nc(rep)->encKDCRepPart)->caddr != nullptr) && !$nc($nc(req->reqBody)->addresses)->equals($nc(rep->encKDCRepPart)->caddr)) {
		$nc($nc(rep->encKDCRepPart)->key)->destroy();
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
	}
	for (int32_t i = 2; i < 6; ++i) {
		bool var$5 = $nc($nc($nc(req)->reqBody)->kdcOptions)->get(i);
		if (var$5 != $nc($nc($nc(rep)->encKDCRepPart)->flags)->get(i)) {
			$init($Krb5);
			if ($Krb5::DEBUG) {
				$init($System);
				$var($String, var$6, $$str({"> KrbKdcRep.check: at #"_s, $$str(i), ". request for "_s, $$str($nc($nc(req->reqBody)->kdcOptions)->get(i)), ", received "_s}));
				$nc($System::out)->println($$concat(var$6, $$str($nc($nc(rep->encKDCRepPart)->flags)->get(i))));
			}
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
		}
	}
	bool var$7 = $nc($nc($nc(req)->reqBody)->kdcOptions)->get($KDCOptions::RENEWABLE);
	if (var$7 && !$nc($nc($nc(rep)->encKDCRepPart)->flags)->get($KDCOptions::RENEWABLE)) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
	}
	if (($nc($nc(req)->reqBody)->from == nullptr) || $nc($nc($nc(req)->reqBody)->from)->isZero()) {
		if (($nc($nc(rep)->encKDCRepPart)->starttime != nullptr) && !$nc($nc(rep->encKDCRepPart)->starttime)->inClockSkew()) {
			$nc($nc(rep->encKDCRepPart)->key)->destroy();
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_SKEW);
		}
	}
	if (($nc($nc(req)->reqBody)->from != nullptr) && !$nc($nc(req->reqBody)->from)->isZero()) {
		if (($nc($nc(rep)->encKDCRepPart)->starttime != nullptr) && !$nc($nc(req->reqBody)->from)->equals($nc(rep->encKDCRepPart)->starttime)) {
			$nc($nc(rep->encKDCRepPart)->key)->destroy();
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
		}
	}
	bool var$8 = !$nc($nc($nc(req)->reqBody)->till)->isZero();
	if (var$8 && $nc($nc($nc(rep)->encKDCRepPart)->endtime)->greaterThan($nc(req->reqBody)->till)) {
		$nc($nc(rep->encKDCRepPart)->key)->destroy();
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
	}
	if ($nc($nc($nc(req)->reqBody)->kdcOptions)->get($KDCOptions::RENEWABLE)) {
		if ($nc(req->reqBody)->rtime != nullptr && !$nc($nc(req->reqBody)->rtime)->isZero()) {
			if (($nc($nc(rep)->encKDCRepPart)->renewTill == nullptr) || $nc($nc($nc(rep)->encKDCRepPart)->renewTill)->greaterThan($nc(req->reqBody)->rtime)) {
				$nc($nc(rep->encKDCRepPart)->key)->destroy();
				$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
			}
		}
	}
	if ($nc($nc($nc(rep)->encKDCRepPart)->flags)->get($Krb5::TKT_OPTS_ENC_PA_REP)) {
		bool reqPaReqEncPaRep = false;
		bool repPaReqEncPaRepValid = false;
		if ($nc(req)->pAData != nullptr) {
			{
				$var($PADataArray, arr$, req->pAData);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($PAData, pa, arr$->get(i$));
					{
						if ($nc(pa)->getType() == $Krb5::PA_REQ_ENC_PA_REP) {
							reqPaReqEncPaRep = true;
							break;
						}
					}
				}
			}
		}
		if ($nc(rep->encKDCRepPart)->pAData != nullptr) {
			{
				$var($PADataArray, arr$, $nc(rep->encKDCRepPart)->pAData);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($PAData, pa, arr$->get(i$));
					{
						if ($nc(pa)->getType() == $Krb5::PA_REQ_ENC_PA_REP) {
							try {
								$var($Checksum, repCksum, $new($Checksum, $($$new($DerInputStream, $(pa->getValue()))->getDerValue())));
								repPaReqEncPaRepValid = repCksum->verifyAnyChecksum($($nc(req)->asn1Encode()), replyKey, $KeyUsage::KU_AS_REQ);
							} catch ($Exception&) {
								$var($Exception, e, $catch());
								$init($Krb5);
								if ($Krb5::DEBUG) {
									e->printStackTrace();
								}
							}
							break;
						}
					}
				}
			}
		}
		if (reqPaReqEncPaRep && !repPaReqEncPaRepValid) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
		}
	}
}

KrbKdcRep::KrbKdcRep() {
}

$Class* KrbKdcRep::load$($String* name, bool initialize) {
	$loadClass(KrbKdcRep, name, initialize, &_KrbKdcRep_ClassInfo_, allocate$KrbKdcRep);
	return class$;
}

$Class* KrbKdcRep::class$ = nullptr;

		} // krb5
	} // security
} // sun