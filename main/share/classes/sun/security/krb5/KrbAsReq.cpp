#include <sun/security/krb5/KrbAsReq.h>

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
#include <java/time/Instant.h>
#include <java/util/Arrays.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/RealmException.h>
#include <sun/security/krb5/internal/ASReq.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/KDCReqBody.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/PAEncTSEnc.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/krb5/internal/crypto/Nonce.h>
#include <jcpp.h>

#undef DEBUG
#undef ENC_TKT_IN_SKEY
#undef FORWARDED
#undef KRB_AP_ERR_REQ_OPTIONS
#undef KU_PA_ENC_TS
#undef PA_ENC_TIMESTAMP
#undef POSTDATED
#undef PROXY
#undef REALM_NULL
#undef RENEW
#undef RENEWABLE
#undef VALIDATE

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $TicketArray = $Array<::sun::security::krb5::internal::Ticket>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Instant = ::java::time::Instant;
using $Arrays = ::java::util::Arrays;
using $Config = ::sun::security::krb5::Config;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $RealmException = ::sun::security::krb5::RealmException;
using $ASReq = ::sun::security::krb5::internal::ASReq;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $KDCReq = ::sun::security::krb5::internal::KDCReq;
using $KDCReqBody = ::sun::security::krb5::internal::KDCReqBody;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $PAData = ::sun::security::krb5::internal::PAData;
using $PAEncTSEnc = ::sun::security::krb5::internal::PAEncTSEnc;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $Nonce = ::sun::security::krb5::internal::crypto::Nonce;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbAsReq_FieldInfo_[] = {
	{"asReqMessg", "Lsun/security/krb5/internal/ASReq;", nullptr, $PRIVATE, $field(KrbAsReq, asReqMessg)},
	{"DEBUG", "Z", nullptr, $PRIVATE, $field(KrbAsReq, DEBUG)},
	{}
};

$MethodInfo _KrbAsReq_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/KDCOptions;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;[ILsun/security/krb5/internal/HostAddresses;[Lsun/security/krb5/internal/PAData;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbAsReq::*)($EncryptionKey*,$KDCOptions*,$PrincipalName*,$PrincipalName*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$ints*,$HostAddresses*,$PADataArray*)>(&KrbAsReq::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"encoding", "()[B", nullptr, 0, nullptr, "java.io.IOException,sun.security.krb5.Asn1Exception"},
	{"getMessage", "()Lsun/security/krb5/internal/ASReq;", nullptr, 0},
	{}
};

$ClassInfo _KrbAsReq_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.KrbAsReq",
	"java.lang.Object",
	nullptr,
	_KrbAsReq_FieldInfo_,
	_KrbAsReq_MethodInfo_
};

$Object* allocate$KrbAsReq($Class* clazz) {
	return $of($alloc(KrbAsReq));
}

void KrbAsReq::init$($EncryptionKey* pakey, $KDCOptions* options$renamed, $PrincipalName* cname, $PrincipalName* sname$renamed, $KerberosTime* from$renamed, $KerberosTime* till$renamed, $KerberosTime* rtime$renamed, $ints* eTypes, $HostAddresses* addresses$renamed, $PADataArray* extraPAs) {
	$var($HostAddresses, addresses, addresses$renamed);
	$var($KerberosTime, till, till$renamed);
	$var($KerberosTime, rtime, rtime$renamed);
	$var($PrincipalName, sname, sname$renamed);
	$var($KDCOptions, options, options$renamed);
	$var($KerberosTime, from, from$renamed);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	if (options == nullptr) {
		$assign(options, $new($KDCOptions));
	}
	bool var$3 = $nc(options)->get($KDCOptions::FORWARDED);
	bool var$2 = var$3 || $nc(options)->get($KDCOptions::PROXY);
	bool var$1 = var$2 || $nc(options)->get($KDCOptions::ENC_TKT_IN_SKEY);
	bool var$0 = var$1 || $nc(options)->get($KDCOptions::RENEW);
	if (var$0 || $nc(options)->get($KDCOptions::VALIDATE)) {
		$throwNew($KrbException, $Krb5::KRB_AP_ERR_REQ_OPTIONS);
	}
	if ($nc(options)->get($KDCOptions::POSTDATED)) {
	} else if (from != nullptr) {
		$assign(from, nullptr);
	}
	$var($PADataArray, paData, nullptr);
	if (pakey != nullptr) {
		$var($PAEncTSEnc, ts, $new($PAEncTSEnc));
		$var($bytes, temp, ts->asn1Encode());
		$var($EncryptedData, encTs, $new($EncryptedData, pakey, temp, $KeyUsage::KU_PA_ENC_TS));
		$assign(paData, $new($PADataArray, 1));
		paData->set(0, $$new($PAData, $Krb5::PA_ENC_TIMESTAMP, $(encTs->asn1Encode())));
	}
	if (extraPAs != nullptr && extraPAs->length > 0) {
		if (paData == nullptr) {
			$assign(paData, $new($PADataArray, extraPAs->length));
		} else {
			$assign(paData, $fcast($PADataArray, $Arrays::copyOf(paData, $nc(paData)->length + extraPAs->length)));
		}
		$System::arraycopy(extraPAs, 0, paData, $nc(paData)->length - extraPAs->length, extraPAs->length);
	}
	if ($nc(cname)->getRealm() == nullptr) {
		$throwNew($RealmException, $Krb5::REALM_NULL, "default realm not specified "_s);
	}
	if (this->DEBUG) {
		$init($System);
		$nc($System::out)->println(">>> KrbAsReq creating message"_s);
	}
	$var($Config, cfg, $Config::getInstance());
	if (addresses == nullptr && $nc(cfg)->useAddresses()) {
		$assign(addresses, $HostAddresses::getLocalAddresses());
	}
	if (sname == nullptr) {
		$var($String, realm, $nc(cname)->getRealmAsString());
		$assign(sname, $PrincipalName::tgsService(realm, realm));
	}
	if (till == nullptr) {
		$var($String, d, $nc(cfg)->get($$new($StringArray, {
			"libdefaults"_s,
			"ticket_lifetime"_s
		})));
		if (d != nullptr) {
			$assign(till, $new($KerberosTime, $($nc($($Instant::now()))->plusSeconds($Config::duration(d)))));
		} else {
			$assign(till, $new($KerberosTime, (int64_t)0));
		}
	}
	if (rtime == nullptr) {
		$var($String, d, $nc(cfg)->get($$new($StringArray, {
			"libdefaults"_s,
			"renew_lifetime"_s
		})));
		if (d != nullptr) {
			$assign(rtime, $new($KerberosTime, $($nc($($Instant::now()))->plusSeconds($Config::duration(d)))));
		}
	}
	if (rtime != nullptr) {
		$nc(options)->set($KDCOptions::RENEWABLE, true);
		if ($nc(till)->greaterThan(rtime)) {
			$assign(rtime, till);
		}
	}
	$var($KDCReqBody, kdc_req_body, $new($KDCReqBody, options, cname, sname, from, till, rtime, $Nonce::value(), eTypes, addresses, nullptr, nullptr));
	$set(this, asReqMessg, $new($ASReq, paData, kdc_req_body));
}

$bytes* KrbAsReq::encoding() {
	return $nc(this->asReqMessg)->asn1Encode();
}

$ASReq* KrbAsReq::getMessage() {
	return this->asReqMessg;
}

KrbAsReq::KrbAsReq() {
}

$Class* KrbAsReq::load$($String* name, bool initialize) {
	$loadClass(KrbAsReq, name, initialize, &_KrbAsReq_ClassInfo_, allocate$KrbAsReq);
	return class$;
}

$Class* KrbAsReq::class$ = nullptr;

		} // krb5
	} // security
} // sun