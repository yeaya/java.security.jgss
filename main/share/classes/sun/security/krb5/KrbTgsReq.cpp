#include <sun/security/krb5/KrbTgsReq.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/time/Instant.h>
#include <java/util/Arrays.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KdcComm.h>
#include <sun/security/krb5/KrbApReq.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/KrbTgsRep.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/APOptions.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/KDCReqBody.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/SeqNumber.h>
#include <sun/security/krb5/internal/TGSReq.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/krb5/internal/crypto/Nonce.h>
#include <jcpp.h>

#undef ALLOW_POSTDATE
#undef CKSUMTYPE_DEFAULT
#undef CNAME_IN_ADDL_TKT
#undef ENC_TKT_IN_SKEY
#undef FORWARDABLE
#undef FORWARDED
#undef KRB_AP_ERR_REQ_OPTIONS
#undef KRB_TGS_REQ
#undef KU_PA_TGS_REQ_CKSUM
#undef KU_TGS_REQ_AUTH_DATA_SESSKEY
#undef KU_TGS_REQ_AUTH_DATA_SUBKEY
#undef PA_TGS_REQ
#undef POSTDATED
#undef PROXIABLE
#undef PROXY
#undef RENEWABLE
#undef TKT_OPTS_FORWARDABLE
#undef TKT_OPTS_MAY_POSTDATE
#undef TKT_OPTS_PROXIABLE
#undef TKT_OPTS_RENEWABLE

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $TicketArray = $Array<::sun::security::krb5::internal::Ticket>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Instant = ::java::time::Instant;
using $Arrays = ::java::util::Arrays;
using $Checksum = ::sun::security::krb5::Checksum;
using $Config = ::sun::security::krb5::Config;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KdcComm = ::sun::security::krb5::KdcComm;
using $KrbApReq = ::sun::security::krb5::KrbApReq;
using $KrbException = ::sun::security::krb5::KrbException;
using $KrbTgsRep = ::sun::security::krb5::KrbTgsRep;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $APOptions = ::sun::security::krb5::internal::APOptions;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $KDCReq = ::sun::security::krb5::internal::KDCReq;
using $KDCReqBody = ::sun::security::krb5::internal::KDCReqBody;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $PAData = ::sun::security::krb5::internal::PAData;
using $SeqNumber = ::sun::security::krb5::internal::SeqNumber;
using $TGSReq = ::sun::security::krb5::internal::TGSReq;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $EType = ::sun::security::krb5::internal::crypto::EType;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $Nonce = ::sun::security::krb5::internal::crypto::Nonce;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbTgsReq_FieldInfo_[] = {
	{"princName", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KrbTgsReq, princName)},
	{"clientAlias", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KrbTgsReq, clientAlias)},
	{"servName", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KrbTgsReq, servName)},
	{"serverAlias", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KrbTgsReq, serverAlias)},
	{"tgsReqMessg", "Lsun/security/krb5/internal/TGSReq;", nullptr, $PRIVATE, $field(KrbTgsReq, tgsReqMessg)},
	{"ctime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $field(KrbTgsReq, ctime)},
	{"secondTicket", "Lsun/security/krb5/internal/Ticket;", nullptr, $PRIVATE, $field(KrbTgsReq, secondTicket)},
	{"useSubkey", "Z", nullptr, $PRIVATE, $field(KrbTgsReq, useSubkey)},
	{"tgsReqKey", "Lsun/security/krb5/EncryptionKey;", nullptr, 0, $field(KrbTgsReq, tgsReqKey)},
	{"obuf", "[B", nullptr, $PRIVATE, $field(KrbTgsReq, obuf)},
	{"ibuf", "[B", nullptr, $PRIVATE, $field(KrbTgsReq, ibuf)},
	{}
};

$MethodInfo _KrbTgsReq_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/KDCOptions;Lsun/security/krb5/Credentials;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;[Lsun/security/krb5/internal/Ticket;[Lsun/security/krb5/internal/PAData;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbTgsReq::*)($KDCOptions*,$Credentials*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$TicketArray*,$PADataArray*)>(&KrbTgsReq::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "(Lsun/security/krb5/internal/KDCOptions;Lsun/security/krb5/Credentials;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;[ILsun/security/krb5/internal/HostAddresses;Lsun/security/krb5/internal/AuthorizationData;[Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptionKey;)V", nullptr, 0, $method(static_cast<void(KrbTgsReq::*)($KDCOptions*,$Credentials*,$PrincipalName*,$PrincipalName*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$ints*,$HostAddresses*,$AuthorizationData*,$TicketArray*,$EncryptionKey*)>(&KrbTgsReq::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "(Lsun/security/krb5/internal/KDCOptions;Lsun/security/krb5/Credentials;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;[ILsun/security/krb5/internal/HostAddresses;Lsun/security/krb5/internal/AuthorizationData;[Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptionKey;[Lsun/security/krb5/internal/PAData;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbTgsReq::*)($KDCOptions*,$Credentials*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$ints*,$HostAddresses*,$AuthorizationData*,$TicketArray*,$EncryptionKey*,$PADataArray*)>(&KrbTgsReq::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"createRequest", "(Lsun/security/krb5/internal/KDCOptions;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;[ILsun/security/krb5/internal/HostAddresses;Lsun/security/krb5/internal/AuthorizationData;[Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptionKey;[Lsun/security/krb5/internal/PAData;)Lsun/security/krb5/internal/TGSReq;", nullptr, $PRIVATE, $method(static_cast<$TGSReq*(KrbTgsReq::*)($KDCOptions*,$Ticket*,$EncryptionKey*,$KerberosTime*,$PrincipalName*,$PrincipalName*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$ints*,$HostAddresses*,$AuthorizationData*,$TicketArray*,$EncryptionKey*,$PADataArray*)>(&KrbTgsReq::createRequest)), "java.io.IOException,sun.security.krb5.KrbException,java.net.UnknownHostException"},
	{"debug", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($String*)>(&KrbTgsReq::debug))},
	{"getClientAlias", "()Lsun/security/krb5/PrincipalName;", nullptr, 0},
	{"getCtime", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, 0},
	{"getMessage", "()Lsun/security/krb5/internal/TGSReq;", nullptr, 0},
	{"getReply", "()Lsun/security/krb5/KrbTgsRep;", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException,java.io.IOException"},
	{"getSecondTicket", "()Lsun/security/krb5/internal/Ticket;", nullptr, 0},
	{"getServerAlias", "()Lsun/security/krb5/PrincipalName;", nullptr, 0},
	{"send", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException,sun.security.krb5.KrbException"},
	{"sendAndGetCreds", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC, nullptr, "java.io.IOException,sun.security.krb5.KrbException"},
	{"usedSubkey", "()Z", nullptr, 0},
	{}
};

$ClassInfo _KrbTgsReq_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.KrbTgsReq",
	"java.lang.Object",
	nullptr,
	_KrbTgsReq_FieldInfo_,
	_KrbTgsReq_MethodInfo_
};

$Object* allocate$KrbTgsReq($Class* clazz) {
	return $of($alloc(KrbTgsReq));
}

void KrbTgsReq::init$($KDCOptions* options, $Credentials* asCreds, $PrincipalName* cname, $PrincipalName* clientAlias, $PrincipalName* sname, $PrincipalName* serverAlias, $TicketArray* additionalTickets, $PADataArray* extraPAs) {
	KrbTgsReq::init$(options, asCreds, cname, clientAlias, sname, serverAlias, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, additionalTickets, nullptr, extraPAs);
}

void KrbTgsReq::init$($KDCOptions* options, $Credentials* asCreds, $PrincipalName* sname, $PrincipalName* serverAlias, $KerberosTime* from, $KerberosTime* till, $KerberosTime* rtime, $ints* eTypes, $HostAddresses* addresses, $AuthorizationData* authorizationData, $TicketArray* additionalTickets, $EncryptionKey* subKey) {
	$var($KDCOptions, var$0, options);
	$var($Credentials, var$1, asCreds);
	$var($PrincipalName, var$2, $nc(asCreds)->getClient());
	KrbTgsReq::init$(var$0, var$1, var$2, $(asCreds->getClientAlias()), sname, serverAlias, from, till, rtime, eTypes, addresses, authorizationData, additionalTickets, subKey, nullptr);
}

void KrbTgsReq::init$($KDCOptions* options, $Credentials* asCreds, $PrincipalName* cname, $PrincipalName* clientAlias, $PrincipalName* sname, $PrincipalName* serverAlias, $KerberosTime* from$renamed, $KerberosTime* till, $KerberosTime* rtime$renamed, $ints* eTypes, $HostAddresses* addresses, $AuthorizationData* authorizationData, $TicketArray* additionalTickets$renamed, $EncryptionKey* subKey, $PADataArray* extraPAs) {
	$var($KerberosTime, rtime, rtime$renamed);
	$var($TicketArray, additionalTickets, additionalTickets$renamed);
	$var($KerberosTime, from, from$renamed);
	$set(this, secondTicket, nullptr);
	this->useSubkey = false;
	$set(this, princName, cname);
	$set(this, clientAlias, clientAlias);
	$set(this, servName, sname);
	$set(this, serverAlias, serverAlias);
	$set(this, ctime, $KerberosTime::now());
	bool var$0 = $nc(options)->get($KDCOptions::FORWARDABLE);
	if (var$0 && (!($nc($nc(asCreds)->flags)->get($Krb5::TKT_OPTS_FORWARDABLE)))) {
		options->set($KDCOptions::FORWARDABLE, false);
	}
	if ($nc(options)->get($KDCOptions::FORWARDED)) {
		if (!($nc($nc(asCreds)->flags)->get($KDCOptions::FORWARDABLE))) {
			$throwNew($KrbException, $Krb5::KRB_AP_ERR_REQ_OPTIONS);
		}
	}
	bool var$1 = $nc(options)->get($KDCOptions::PROXIABLE);
	if (var$1 && (!($nc($nc(asCreds)->flags)->get($Krb5::TKT_OPTS_PROXIABLE)))) {
		$throwNew($KrbException, $Krb5::KRB_AP_ERR_REQ_OPTIONS);
	}
	if ($nc(options)->get($KDCOptions::PROXY)) {
		if (!($nc($nc(asCreds)->flags)->get($KDCOptions::PROXIABLE))) {
			$throwNew($KrbException, $Krb5::KRB_AP_ERR_REQ_OPTIONS);
		}
	}
	bool var$2 = $nc(options)->get($KDCOptions::ALLOW_POSTDATE);
	if (var$2 && (!($nc($nc(asCreds)->flags)->get($Krb5::TKT_OPTS_MAY_POSTDATE)))) {
		$throwNew($KrbException, $Krb5::KRB_AP_ERR_REQ_OPTIONS);
	}
	bool var$3 = $nc(options)->get($KDCOptions::RENEWABLE);
	if (var$3 && (!($nc($nc(asCreds)->flags)->get($Krb5::TKT_OPTS_RENEWABLE)))) {
		$throwNew($KrbException, $Krb5::KRB_AP_ERR_REQ_OPTIONS);
	}
	if ($nc(options)->get($KDCOptions::POSTDATED)) {
		if (!($nc($nc(asCreds)->flags)->get($KDCOptions::POSTDATED))) {
			$throwNew($KrbException, $Krb5::KRB_AP_ERR_REQ_OPTIONS);
		}
	} else if (from != nullptr) {
		$assign(from, nullptr);
	}
	if ($nc(options)->get($KDCOptions::RENEWABLE)) {
		if (!($nc($nc(asCreds)->flags)->get($KDCOptions::RENEWABLE))) {
			$throwNew($KrbException, $Krb5::KRB_AP_ERR_REQ_OPTIONS);
		}
	} else if (rtime != nullptr) {
		$assign(rtime, nullptr);
	}
	bool var$4 = $nc(options)->get($KDCOptions::ENC_TKT_IN_SKEY);
	if (var$4 || $nc(options)->get($KDCOptions::CNAME_IN_ADDL_TKT)) {
		if (additionalTickets == nullptr) {
			$throwNew($KrbException, $Krb5::KRB_AP_ERR_REQ_OPTIONS);
		}
		$set(this, secondTicket, $nc(additionalTickets)->get(0));
	} else if (additionalTickets != nullptr) {
		$assign(additionalTickets, nullptr);
	}
	$set(this, tgsReqMessg, createRequest(options, $nc(asCreds)->ticket, asCreds->key, this->ctime, this->princName, this->servName, from, till, rtime, eTypes, addresses, authorizationData, additionalTickets, subKey, extraPAs));
	$set(this, obuf, $nc(this->tgsReqMessg)->asn1Encode());
	if ($nc($nc(asCreds)->flags)->get($KDCOptions::FORWARDED)) {
		$nc(options)->set($KDCOptions::FORWARDED, true);
	}
}

void KrbTgsReq::send() {
	$var($String, realmStr, nullptr);
	if (this->servName != nullptr) {
		$assign(realmStr, $nc(this->servName)->getRealmString());
	}
	$var($KdcComm, comm, $new($KdcComm, realmStr));
	$set(this, ibuf, comm->send(this->obuf));
}

$KrbTgsRep* KrbTgsReq::getReply() {
	return $new($KrbTgsRep, this->ibuf, this);
}

$Credentials* KrbTgsReq::sendAndGetCreds() {
	$var($KrbTgsRep, tgs_rep, nullptr);
	$var($String, kdc, nullptr);
	send();
	$assign(tgs_rep, getReply());
	return $nc(tgs_rep)->getCreds();
}

$KerberosTime* KrbTgsReq::getCtime() {
	return this->ctime;
}

$TGSReq* KrbTgsReq::createRequest($KDCOptions* kdc_options, $Ticket* ticket, $EncryptionKey* key, $KerberosTime* ctime, $PrincipalName* cname, $PrincipalName* sname, $KerberosTime* from, $KerberosTime* till, $KerberosTime* rtime, $ints* eTypes, $HostAddresses* addresses, $AuthorizationData* authorizationData, $TicketArray* additionalTickets, $EncryptionKey* subKey, $PADataArray* extraPAs) {
	$var($KerberosTime, req_till, nullptr);
	if (till == nullptr) {
		$var($String, d, $nc($($Config::getInstance()))->get($$new($StringArray, {
			"libdefaults"_s,
			"ticket_lifetime"_s
		})));
		if (d != nullptr) {
			$assign(req_till, $new($KerberosTime, $($nc($($Instant::now()))->plusSeconds($Config::duration(d)))));
		} else {
			$assign(req_till, $new($KerberosTime, (int64_t)0));
		}
	} else {
		$assign(req_till, till);
	}
	$set(this, tgsReqKey, key);
	$var($ints, req_eTypes, nullptr);
	if (eTypes == nullptr) {
		$assign(req_eTypes, $EType::getDefaults("default_tgs_enctypes"_s));
	} else {
		$assign(req_eTypes, eTypes);
	}
	$var($EncryptionKey, reqKey, nullptr);
	$var($EncryptedData, encAuthorizationData, nullptr);
	if (authorizationData != nullptr) {
		$var($bytes, ad, authorizationData->asn1Encode());
		if (subKey != nullptr) {
			$assign(reqKey, subKey);
			$set(this, tgsReqKey, subKey);
			this->useSubkey = true;
			$assign(encAuthorizationData, $new($EncryptedData, reqKey, ad, $KeyUsage::KU_TGS_REQ_AUTH_DATA_SUBKEY));
		} else {
			$assign(encAuthorizationData, $new($EncryptedData, key, ad, $KeyUsage::KU_TGS_REQ_AUTH_DATA_SESSKEY));
		}
	}
	$var($KDCReqBody, reqBody, $new($KDCReqBody, kdc_options, cname, sname, from, req_till, rtime, $Nonce::value(), req_eTypes, addresses, encAuthorizationData, additionalTickets));
	$var($bytes, temp, reqBody->asn1Encode($Krb5::KRB_TGS_REQ));
	$init($Checksum);
	$var($Checksum, cksum, $new($Checksum, $Checksum::CKSUMTYPE_DEFAULT, temp, key, $KeyUsage::KU_PA_TGS_REQ_CKSUM));
	$var($bytes, tgs_ap_req, $$new($KrbApReq, $$new($APOptions), ticket, key, cname, cksum, ctime, reqKey, nullptr, nullptr)->getMessage());
	$var($PAData, tgsPAData, $new($PAData, $Krb5::PA_TGS_REQ, tgs_ap_req));
	$var($PADataArray, pa, nullptr);
	if (extraPAs != nullptr) {
		$assign(pa, $fcast($PADataArray, $Arrays::copyOf(extraPAs, extraPAs->length + 1)));
		pa->set(extraPAs->length, tgsPAData);
	} else {
		$assign(pa, $new($PADataArray, {tgsPAData}));
	}
	return $new($TGSReq, pa, reqBody);
}

$TGSReq* KrbTgsReq::getMessage() {
	return this->tgsReqMessg;
}

$Ticket* KrbTgsReq::getSecondTicket() {
	return this->secondTicket;
}

$PrincipalName* KrbTgsReq::getClientAlias() {
	return this->clientAlias;
}

$PrincipalName* KrbTgsReq::getServerAlias() {
	return this->serverAlias;
}

void KrbTgsReq::debug($String* message) {
}

bool KrbTgsReq::usedSubkey() {
	return this->useSubkey;
}

KrbTgsReq::KrbTgsReq() {
}

$Class* KrbTgsReq::load$($String* name, bool initialize) {
	$loadClass(KrbTgsReq, name, initialize, &_KrbTgsReq_ClassInfo_, allocate$KrbTgsReq);
	return class$;
}

$Class* KrbTgsReq::class$ = nullptr;

		} // krb5
	} // security
} // sun