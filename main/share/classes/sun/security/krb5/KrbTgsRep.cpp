#include <sun/security/krb5/KrbTgsRep.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/KrbKdcRep.h>
#include <sun/security/krb5/KrbTgsReq.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/EncKDCRepPart.h>
#include <sun/security/krb5/internal/EncTGSRepPart.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCRep.h>
#include <sun/security/krb5/internal/KDCReq.h>
#include <sun/security/krb5/internal/KDCReqBody.h>
#include <sun/security/krb5/internal/KRBError.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/TGSRep.h>
#include <sun/security/krb5/internal/TGSReq.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/ccache/Credentials.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef KU_ENC_TGS_REP_PART_SESSKEY
#undef KU_ENC_TGS_REP_PART_SUBKEY
#undef TGS_DEFAULT_SRV_NAME

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $1Credentials = ::sun::security::krb5::Credentials;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $KrbKdcRep = ::sun::security::krb5::KrbKdcRep;
using $KrbTgsReq = ::sun::security::krb5::KrbTgsReq;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $EncKDCRepPart = ::sun::security::krb5::internal::EncKDCRepPart;
using $EncTGSRepPart = ::sun::security::krb5::internal::EncTGSRepPart;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCRep = ::sun::security::krb5::internal::KDCRep;
using $KDCReq = ::sun::security::krb5::internal::KDCReq;
using $KDCReqBody = ::sun::security::krb5::internal::KDCReqBody;
using $KRBError = ::sun::security::krb5::internal::KRBError;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $TGSRep = ::sun::security::krb5::internal::TGSRep;
using $TGSReq = ::sun::security::krb5::internal::TGSReq;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $Credentials = ::sun::security::krb5::internal::ccache::Credentials;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbTgsRep_FieldInfo_[] = {
	{"rep", "Lsun/security/krb5/internal/TGSRep;", nullptr, $PRIVATE, $field(KrbTgsRep, rep)},
	{"creds", "Lsun/security/krb5/Credentials;", nullptr, $PRIVATE, $field(KrbTgsRep, creds)},
	{"secondTicket", "Lsun/security/krb5/internal/Ticket;", nullptr, $PRIVATE, $field(KrbTgsRep, secondTicket)},
	{}
};

$MethodInfo _KrbTgsRep_MethodInfo_[] = {
	{"<init>", "([BLsun/security/krb5/KrbTgsReq;)V", nullptr, 0, $method(static_cast<void(KrbTgsRep::*)($bytes*,$KrbTgsReq*)>(&KrbTgsRep::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"getCreds", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC},
	{"isReferralSname", "(Lsun/security/krb5/PrincipalName;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($PrincipalName*)>(&KrbTgsRep::isReferralSname))},
	{"setCredentials", "()Lsun/security/krb5/internal/ccache/Credentials;", nullptr, 0},
	{}
};

$ClassInfo _KrbTgsRep_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.KrbTgsRep",
	"sun.security.krb5.KrbKdcRep",
	nullptr,
	_KrbTgsRep_FieldInfo_,
	_KrbTgsRep_MethodInfo_
};

$Object* allocate$KrbTgsRep($Class* clazz) {
	return $of($alloc(KrbTgsRep));
}

void KrbTgsRep::init$($bytes* ibuf, $KrbTgsReq* tgsReq) {
	$KrbKdcRep::init$();
	$var($DerValue, ref, $new($DerValue, ibuf));
	$var($TGSReq, req, $nc(tgsReq)->getMessage());
	$var($TGSRep, rep, nullptr);
	try {
		$assign(rep, $new($TGSRep, ref));
	} catch ($Asn1Exception&) {
		$var($Asn1Exception, e, $catch());
		$assign(rep, nullptr);
		$var($KRBError, err, $new($KRBError, ref));
		$var($String, errStr, err->getErrorString());
		$var($String, eText, nullptr);
		if (errStr != nullptr && errStr->length() > 0) {
			if (errStr->charAt(errStr->length() - 1) == 0) {
				$assign(eText, errStr->substring(0, errStr->length() - 1));
			} else {
				$assign(eText, errStr);
			}
		}
		$var($KrbException, ke, nullptr);
		if (eText == nullptr) {
			$assign(ke, $new($KrbException, err->getErrorCode()));
		} else {
			$assign(ke, $new($KrbException, err->getErrorCode(), eText));
		}
		$nc(ke)->initCause(e);
		$throw(ke);
	}
	$var($bytes, enc_tgs_rep_bytes, $nc($nc(rep)->encPart)->decrypt(tgsReq->tgsReqKey, tgsReq->usedSubkey() ? $KeyUsage::KU_ENC_TGS_REP_PART_SUBKEY : $KeyUsage::KU_ENC_TGS_REP_PART_SESSKEY));
	$var($bytes, enc_tgs_rep_part, $nc(rep->encPart)->reset(enc_tgs_rep_bytes));
	$assign(ref, $new($DerValue, enc_tgs_rep_part));
	$var($EncTGSRepPart, enc_part, $new($EncTGSRepPart, ref));
	$set(rep, encKDCRepPart, enc_part);
	check(false, req, rep, tgsReq->tgsReqKey);
	$var($PrincipalName, serverAlias, tgsReq->getServerAlias());
	if (serverAlias != nullptr) {
		$var($PrincipalName, repSname, enc_part->sname);
		bool var$0 = serverAlias->equals(repSname);
		if (var$0 || isReferralSname(repSname)) {
			$assign(serverAlias, nullptr);
		}
	}
	$var($PrincipalName, clientAlias, nullptr);
	if ($nc(rep->cname)->equals($nc($nc(req)->reqBody)->cname)) {
		$assign(clientAlias, tgsReq->getClientAlias());
	}
	$set(this, creds, $new($1Credentials, rep->ticket, rep->cname, clientAlias, enc_part->sname, serverAlias, enc_part->key, enc_part->flags, enc_part->authtime, enc_part->starttime, enc_part->endtime, enc_part->renewTill, enc_part->caddr));
	$set(this, rep, rep);
	$set(this, secondTicket, tgsReq->getSecondTicket());
}

$1Credentials* KrbTgsRep::getCreds() {
	return this->creds;
}

$Credentials* KrbTgsRep::setCredentials() {
	return $new($Credentials, this->rep, this->secondTicket);
}

bool KrbTgsRep::isReferralSname($PrincipalName* sname) {
	$init(KrbTgsRep);
	if (sname != nullptr) {
		$var($StringArray, snameStrings, sname->getNameStrings());
		if ($nc(snameStrings)->length == 2 && $nc(snameStrings->get(0))->equals($PrincipalName::TGS_DEFAULT_SRV_NAME)) {
			return true;
		}
	}
	return false;
}

KrbTgsRep::KrbTgsRep() {
}

$Class* KrbTgsRep::load$($String* name, bool initialize) {
	$loadClass(KrbTgsRep, name, initialize, &_KrbTgsRep_ClassInfo_, allocate$KrbTgsRep);
	return class$;
}

$Class* KrbTgsRep::class$ = nullptr;

		} // krb5
	} // security
} // sun