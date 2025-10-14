#include <sun/security/krb5/internal/CredentialsUtil.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractSequentialList.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/KrbTgsReq.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/CredentialsUtil$S4U2Type.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/PAForUserEnc.h>
#include <sun/security/krb5/internal/PaPacOptions.h>
#include <sun/security/krb5/internal/ReferralsCache$ReferralCacheEntry.h>
#include <sun/security/krb5/internal/ReferralsCache.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef CANONICALIZE
#undef CNAME_IN_ADDL_TKT
#undef DEBUG
#undef DISABLE_REFERRALS
#undef FORWARDABLE
#undef KRB_AP_ERR_GEN_CRED
#undef KRB_NT_UNKNOWN
#undef MAX_REFERRALS
#undef NONE
#undef PA_FOR_USER
#undef PA_PAC_OPTIONS
#undef PROXY
#undef SELF
#undef TGS_DEFAULT_SRV_NAME

using $CredentialsArray = $Array<::sun::security::krb5::Credentials>;
using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $TicketArray = $Array<::sun::security::krb5::internal::Ticket>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractList = ::java::util::AbstractList;
using $AbstractSequentialList = ::java::util::AbstractSequentialList;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Config = ::sun::security::krb5::Config;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $KrbTgsReq = ::sun::security::krb5::KrbTgsReq;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $CredentialsUtil$S4U2Type = ::sun::security::krb5::internal::CredentialsUtil$S4U2Type;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $PAData = ::sun::security::krb5::internal::PAData;
using $PAForUserEnc = ::sun::security::krb5::internal::PAForUserEnc;
using $PaPacOptions = ::sun::security::krb5::internal::PaPacOptions;
using $ReferralsCache = ::sun::security::krb5::internal::ReferralsCache;
using $ReferralsCache$ReferralCacheEntry = ::sun::security::krb5::internal::ReferralsCache$ReferralCacheEntry;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _CredentialsUtil_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(CredentialsUtil, DEBUG)},
	{}
};

$MethodInfo _CredentialsUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(CredentialsUtil::*)()>(&CredentialsUtil::init$))},
	{"acquireS4U2proxyCreds", "(Ljava/lang/String;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Credentials;)Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Credentials*(*)($String*,$Ticket*,$PrincipalName*,$Credentials*)>(&CredentialsUtil::acquireS4U2proxyCreds)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"acquireS4U2selfCreds", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Credentials;)Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Credentials*(*)($PrincipalName*,$Credentials*)>(&CredentialsUtil::acquireS4U2selfCreds)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"acquireServiceCreds", "(Ljava/lang/String;Lsun/security/krb5/Credentials;)Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Credentials*(*)($String*,$Credentials*)>(&CredentialsUtil::acquireServiceCreds)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"getTGTforRealm", "(Ljava/lang/String;Ljava/lang/String;Lsun/security/krb5/Credentials;[Z)Lsun/security/krb5/Credentials;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Credentials*(*)($String*,$String*,$Credentials*,$booleans*)>(&CredentialsUtil::getTGTforRealm)), "sun.security.krb5.KrbException"},
	{"handleS4U2ProxyReferral", "(Lsun/security/krb5/Credentials;[Lsun/security/krb5/Credentials;Lsun/security/krb5/PrincipalName;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($Credentials*,$CredentialsArray*,$PrincipalName*)>(&CredentialsUtil::handleS4U2ProxyReferral)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"handleS4U2SelfReferral", "([Lsun/security/krb5/internal/PAData;Lsun/security/krb5/Credentials;Lsun/security/krb5/Credentials;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($PADataArray*,$Credentials*,$Credentials*)>(&CredentialsUtil::handleS4U2SelfReferral)), "sun.security.krb5.Asn1Exception,sun.security.krb5.KrbException,java.io.IOException"},
	{"serviceCreds", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Credentials;)Lsun/security/krb5/Credentials;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Credentials*(*)($PrincipalName*,$Credentials*)>(&CredentialsUtil::serviceCreds)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"serviceCreds", "(Lsun/security/krb5/internal/KDCOptions;Lsun/security/krb5/Credentials;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;[Lsun/security/krb5/internal/Ticket;[Lsun/security/krb5/internal/PAData;Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;)Lsun/security/krb5/Credentials;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Credentials*(*)($KDCOptions*,$Credentials*,$PrincipalName*,$PrincipalName*,$TicketArray*,$PADataArray*,$CredentialsUtil$S4U2Type*)>(&CredentialsUtil::serviceCreds)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"serviceCredsReferrals", "(Lsun/security/krb5/internal/KDCOptions;Lsun/security/krb5/Credentials;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;[Lsun/security/krb5/internal/Ticket;[Lsun/security/krb5/internal/PAData;)Lsun/security/krb5/Credentials;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Credentials*(*)($KDCOptions*,$Credentials*,$PrincipalName*,$PrincipalName*,$CredentialsUtil$S4U2Type*,$TicketArray*,$PADataArray*)>(&CredentialsUtil::serviceCredsReferrals)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"serviceCredsSingle", "(Lsun/security/krb5/internal/KDCOptions;Lsun/security/krb5/Credentials;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;[Lsun/security/krb5/internal/Ticket;[Lsun/security/krb5/internal/PAData;)Lsun/security/krb5/Credentials;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Credentials*(*)($KDCOptions*,$Credentials*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$CredentialsUtil$S4U2Type*,$TicketArray*,$PADataArray*)>(&CredentialsUtil::serviceCredsSingle)), "sun.security.krb5.KrbException,java.io.IOException"},
	{}
};

$InnerClassInfo _CredentialsUtil_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.CredentialsUtil$S4U2Type", "sun.security.krb5.internal.CredentialsUtil", "S4U2Type", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _CredentialsUtil_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.CredentialsUtil",
	"java.lang.Object",
	nullptr,
	_CredentialsUtil_FieldInfo_,
	_CredentialsUtil_MethodInfo_,
	nullptr,
	nullptr,
	_CredentialsUtil_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.CredentialsUtil$S4U2Type"
};

$Object* allocate$CredentialsUtil($Class* clazz) {
	return $of($alloc(CredentialsUtil));
}

bool CredentialsUtil::DEBUG = false;

void CredentialsUtil::init$() {
}

$Credentials* CredentialsUtil::acquireS4U2selfCreds($PrincipalName* client, $Credentials* ccreds) {
	$init(CredentialsUtil);
	if (!$nc(ccreds)->isForwardable()) {
		$throwNew($KrbException, "S4U2self needs a FORWARDABLE ticket"_s);
	}
	$var($PrincipalName, sname, $nc(ccreds)->getClient());
	$var($String, uRealm, $nc(client)->getRealmString());
	$var($String, localRealm, $nc($(ccreds->getClient()))->getRealmString());
	if (!$nc(uRealm)->equals(localRealm)) {
		$init($Config);
		if ($Config::DISABLE_REFERRALS) {
			$throwNew($KrbException, "Cross-realm S4U2Self request not possible when referrals are disabled."_s);
		}
		if (ccreds->getClientAlias() != nullptr) {
			$assign(sname, ccreds->getClientAlias());
		}
		int32_t var$0 = $nc(sname)->getNameType();
		$var($StringArray, var$1, sname->getNameStrings());
		$assign(sname, $new($PrincipalName, var$0, var$1, $$new($Realm, uRealm)));
	}
	$var($KDCOptions, var$2, $KDCOptions::with($$new($ints, {$KDCOptions::FORWARDABLE})));
	$var($Credentials, var$3, ccreds);
	$var($PrincipalName, var$4, ccreds->getClient());
	$var($PrincipalName, var$5, sname);
	$init($CredentialsUtil$S4U2Type);
	$var($Credentials, creds, serviceCreds(var$2, var$3, var$4, var$5, nullptr, $$new($PADataArray, {
		$$new($PAData, $Krb5::PA_FOR_USER, $($$new($PAForUserEnc, client, $(ccreds->getSessionKey()))->asn1Encode())),
		$$new($PAData, $Krb5::PA_PAC_OPTIONS, $($nc($($nc($($$new($PaPacOptions)->setResourceBasedConstrainedDelegation(true)))->setClaims(true)))->asn1Encode()))
	}), $CredentialsUtil$S4U2Type::SELF));
	if (!$nc($($nc(creds)->getClient()))->equals(client)) {
		$throwNew($KrbException, "S4U2self request not honored by KDC"_s);
	}
	if (!$nc(creds)->isForwardable()) {
		$throwNew($KrbException, "S4U2self ticket must be FORWARDABLE"_s);
	}
	return creds;
}

$Credentials* CredentialsUtil::acquireS4U2proxyCreds($String* backend, $Ticket* second, $PrincipalName* client, $Credentials* ccreds) {
	$init(CredentialsUtil);
	$var($PrincipalName, backendPrincipal, $new($PrincipalName, backend));
	$var($String, backendRealm, backendPrincipal->getRealmString());
	$var($String, localRealm, $nc($($nc(ccreds)->getClient()))->getRealmString());
	if (!$nc(backendRealm)->equals(localRealm)) {
		$init($Config);
		if ($Config::DISABLE_REFERRALS) {
			$throwNew($KrbException, "Cross-realm S4U2Proxy request not possible when referrals are disabled."_s);
		}
		int32_t var$0 = backendPrincipal->getNameType();
		$var($StringArray, var$1, backendPrincipal->getNameStrings());
		$assign(backendPrincipal, $new($PrincipalName, var$0, var$1, $$new($Realm, localRealm)));
	}
	$var($KDCOptions, var$2, $KDCOptions::with($$new($ints, {
		$KDCOptions::CNAME_IN_ADDL_TKT,
		$KDCOptions::FORWARDABLE
	})));
	$var($Credentials, var$3, ccreds);
	$var($PrincipalName, var$4, ccreds->getClient());
	$var($PrincipalName, var$5, backendPrincipal);
	$var($TicketArray, var$6, $new($TicketArray, {second}));
	$init($CredentialsUtil$S4U2Type);
	$var($Credentials, creds, serviceCreds(var$2, var$3, var$4, var$5, var$6, $$new($PADataArray, {$$new($PAData, $Krb5::PA_PAC_OPTIONS, $($nc($($nc($($$new($PaPacOptions)->setResourceBasedConstrainedDelegation(true)))->setClaims(true)))->asn1Encode()))}), $CredentialsUtil$S4U2Type::PROXY));
	if (!$nc($($nc(creds)->getClient()))->equals(client)) {
		$throwNew($KrbException, "S4U2proxy request not honored by KDC"_s);
	}
	return creds;
}

$Credentials* CredentialsUtil::acquireServiceCreds($String* service, $Credentials* ccreds) {
	$init(CredentialsUtil);
	$var($PrincipalName, sname, $new($PrincipalName, service, $PrincipalName::KRB_NT_UNKNOWN));
	return serviceCreds(sname, ccreds);
}

$Credentials* CredentialsUtil::getTGTforRealm($String* localRealm, $String* serviceRealm, $Credentials* ccreds, $booleans* okAsDelegate) {
	$init(CredentialsUtil);
	$var($StringArray, realms, $Realm::getRealmsList(localRealm, serviceRealm));
	int32_t i = 0;
	int32_t k = 0;
	$var($Credentials, cTgt, nullptr);
	$var($Credentials, newTgt, nullptr);
	$var($Credentials, theTgt, nullptr);
	$var($PrincipalName, tempService, nullptr);
	$var($String, newTgtRealm, nullptr);
	$nc(okAsDelegate)->set(0, true);
	for ($assign(cTgt, ccreds), i = 0; i < $nc(realms)->length;) {
		$assign(tempService, $PrincipalName::tgsService(serviceRealm, realms->get(i)));
		if (CredentialsUtil::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>> Credentials acquireServiceCreds: main loop: ["_s, $$str(i), "] tempService="_s, tempService}));
		}
		try {
			$assign(newTgt, serviceCreds(tempService, cTgt));
		} catch ($Exception&) {
			$var($Exception, exc, $catch());
			$assign(newTgt, nullptr);
		}
		if (newTgt == nullptr) {
			if (CredentialsUtil::DEBUG) {
				$init($System);
				$nc($System::out)->println(">>> Credentials acquireServiceCreds: no tgt; searching thru capath"_s);
			}
			for ($assign(newTgt, nullptr), k = i + 1; newTgt == nullptr && k < realms->length; ++k) {
				$assign(tempService, $PrincipalName::tgsService(realms->get(k), realms->get(i)));
				if (CredentialsUtil::DEBUG) {
					$init($System);
					$nc($System::out)->println($$str({">>> Credentials acquireServiceCreds: inner loop: ["_s, $$str(k), "] tempService="_s, tempService}));
				}
				try {
					$assign(newTgt, serviceCreds(tempService, cTgt));
				} catch ($Exception&) {
					$var($Exception, exc, $catch());
					$assign(newTgt, nullptr);
				}
			}
		}
		if (newTgt == nullptr) {
			if (CredentialsUtil::DEBUG) {
				$init($System);
				$nc($System::out)->println(">>> Credentials acquireServiceCreds: no tgt; cannot get creds"_s);
			}
			break;
		}
		$assign(newTgtRealm, $nc($($nc(newTgt)->getServer()))->getInstanceComponent());
		if (okAsDelegate->get(0) && !newTgt->checkDelegate()) {
			if (CredentialsUtil::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({">>> Credentials acquireServiceCreds: global OK-AS-DELEGATE turned off at "_s, $(newTgt->getServer())}));
			}
			okAsDelegate->set(0, false);
		}
		if (CredentialsUtil::DEBUG) {
			$init($System);
			$nc($System::out)->println(">>> Credentials acquireServiceCreds: got tgt"_s);
		}
		if ($nc(newTgtRealm)->equals(serviceRealm)) {
			$assign(theTgt, newTgt);
			break;
		}
		for (k = i + 1; k < realms->length; ++k) {
			if ($nc(newTgtRealm)->equals(realms->get(k))) {
				break;
			}
		}
		if (k < realms->length) {
			i = k;
			$assign(cTgt, newTgt);
			if (CredentialsUtil::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({">>> Credentials acquireServiceCreds: continuing with main loop counter reset to "_s, $$str(i)}));
			}
			continue;
		} else {
			break;
		}
	}
	return theTgt;
}

$Credentials* CredentialsUtil::serviceCreds($PrincipalName* service, $Credentials* ccreds) {
	$init(CredentialsUtil);
	$var($KDCOptions, var$0, $new($KDCOptions));
	$var($Credentials, var$1, ccreds);
	$init($CredentialsUtil$S4U2Type);
	return serviceCreds(var$0, var$1, $($nc(ccreds)->getClient()), service, nullptr, nullptr, $CredentialsUtil$S4U2Type::NONE);
}

$Credentials* CredentialsUtil::serviceCreds($KDCOptions* options, $Credentials* asCreds, $PrincipalName* cname, $PrincipalName* sname, $TicketArray* additionalTickets, $PADataArray* extraPAs, $CredentialsUtil$S4U2Type* s4u2Type) {
	$init(CredentialsUtil);
	$init($Config);
	if (!$Config::DISABLE_REFERRALS) {
		try {
			return serviceCredsReferrals(options, asCreds, cname, sname, s4u2Type, additionalTickets, extraPAs);
		} catch ($KrbException&) {
			$catch();
		}
	}
	return serviceCredsSingle(options, asCreds, cname, $($nc(asCreds)->getClientAlias()), sname, sname, s4u2Type, additionalTickets, extraPAs);
}

$Credentials* CredentialsUtil::serviceCredsReferrals($KDCOptions* options$renamed, $Credentials* asCreds$renamed, $PrincipalName* cname, $PrincipalName* sname, $CredentialsUtil$S4U2Type* s4u2Type, $TicketArray* additionalTickets, $PADataArray* extraPAs) {
	$init(CredentialsUtil);
	$var($KDCOptions, options, options$renamed);
	$var($Credentials, asCreds, asCreds$renamed);
	$assign(options, $new($KDCOptions, $($nc(options)->toBooleanArray())));
	options->set($KDCOptions::CANONICALIZE, true);
	$var($PrincipalName, cSname, sname);
	$var($PrincipalName, refSname, sname);
	$var($Credentials, creds, nullptr);
	bool isReferral = false;
	$var($List, referrals, $new($LinkedList));
	$var($PrincipalName, clientAlias, $nc(asCreds)->getClientAlias());
	$init($Config);
	while (referrals->size() <= $Config::MAX_REFERRALS) {
		$var($ReferralsCache$ReferralCacheEntry, ref, $ReferralsCache::get(cname, sname, $($nc(refSname)->getRealmString())));
		$var($String, toRealm, nullptr);
		if (ref == nullptr) {
			$assign(creds, serviceCredsSingle(options, asCreds, cname, clientAlias, refSname, cSname, s4u2Type, additionalTickets, extraPAs));
			$var($PrincipalName, server, $nc(creds)->getServer());
			if (!$nc(refSname)->equals(server)) {
				$var($StringArray, serverNameStrings, $nc(server)->getNameStrings());
				bool var$0 = $nc(serverNameStrings)->length == 2 && $nc(serverNameStrings->get(0))->equals($PrincipalName::TGS_DEFAULT_SRV_NAME);
				if (var$0 && !$nc($(refSname->getRealmAsString()))->equals(serverNameStrings->get(1))) {
					$init($CredentialsUtil$S4U2Type);
					if (s4u2Type == $CredentialsUtil$S4U2Type::NONE) {
						$ReferralsCache::put(cname, sname, $(server->getRealmString()), serverNameStrings->get(1), creds);
					}
					$assign(toRealm, serverNameStrings->get(1));
					isReferral = true;
				}
			}
		} else {
			$assign(creds, $nc(ref)->getCreds());
			$assign(toRealm, ref->getToRealm());
			isReferral = true;
		}
		if (isReferral) {
			$init($CredentialsUtil$S4U2Type);
			if (s4u2Type == $CredentialsUtil$S4U2Type::PROXY) {
				$var($CredentialsArray, credsInOut, $new($CredentialsArray, {
					creds,
					($Credentials*)nullptr
				}));
				$assign(toRealm, handleS4U2ProxyReferral(asCreds, credsInOut, sname));
				$assign(creds, credsInOut->get(0));
				if (additionalTickets == nullptr || $nc(additionalTickets)->length == 0 || credsInOut->get(1) == nullptr) {
					$throwNew($KrbException, "Additional tickets expected for S4U2Proxy."_s);
				}
				$nc(additionalTickets)->set(0, $($nc(credsInOut->get(1))->getTicket()));
			} else {
				if (s4u2Type == $CredentialsUtil$S4U2Type::SELF) {
					handleS4U2SelfReferral(extraPAs, asCreds, creds);
				}
			}
			if (referrals->contains(toRealm)) {
				return nullptr;
			}
			$assign(asCreds, creds);
			$var($String, var$1, $nc(refSname)->getNameString());
			$assign(refSname, $new($PrincipalName, var$1, refSname->getNameType(), toRealm));
			referrals->add(toRealm);
			isReferral = false;
			continue;
		}
		break;
	}
	return creds;
}

$Credentials* CredentialsUtil::serviceCredsSingle($KDCOptions* options, $Credentials* asCreds$renamed, $PrincipalName* cname$renamed, $PrincipalName* clientAlias, $PrincipalName* refSname, $PrincipalName* sname, $CredentialsUtil$S4U2Type* s4u2Type, $TicketArray* additionalTickets, $PADataArray* extraPAs) {
	$init(CredentialsUtil);
	$var($PrincipalName, cname, cname$renamed);
	$var($Credentials, asCreds, asCreds$renamed);
	$var($Credentials, theCreds, nullptr);
	$var($booleans, okAsDelegate, $new($booleans, {true}));
	$var($StringArray, serverAsCredsNames, $nc($($nc(asCreds)->getServer()))->getNameStrings());
	$var($String, tgtRealm, $nc(serverAsCredsNames)->get(1));
	$var($String, serviceRealm, $nc(refSname)->getRealmString());
	if (!$nc(serviceRealm)->equals(tgtRealm)) {
		if (CredentialsUtil::DEBUG) {
			$init($System);
			$nc($System::out)->println(">>> serviceCredsSingle: cross-realm authentication"_s);
			$nc($System::out)->println($$str({">>> serviceCredsSingle: obtaining credentials from "_s, tgtRealm, " to "_s, serviceRealm}));
		}
		$var($Credentials, newTgt, getTGTforRealm(tgtRealm, serviceRealm, asCreds, okAsDelegate));
		if (newTgt == nullptr) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_GEN_CRED, "No service creds"_s);
		}
		if (CredentialsUtil::DEBUG) {
			$init($System);
			$nc($System::out)->println(">>> Cross-realm TGT Credentials serviceCredsSingle: "_s);
			$Credentials::printDebug(newTgt);
		}
		$init($CredentialsUtil$S4U2Type);
		if (s4u2Type == $CredentialsUtil$S4U2Type::SELF) {
			handleS4U2SelfReferral(extraPAs, asCreds, newTgt);
		}
		$assign(asCreds, newTgt);
		$assign(cname, $nc(asCreds)->getClient());
	} else {
		if (CredentialsUtil::DEBUG) {
			$init($System);
			$nc($System::out)->println(">>> Credentials serviceCredsSingle: same realm"_s);
		}
	}
	$var($KrbTgsReq, req, $new($KrbTgsReq, options, asCreds, cname, clientAlias, refSname, sname, additionalTickets, extraPAs));
	$assign(theCreds, req->sendAndGetCreds());
	if (theCreds != nullptr) {
		if (CredentialsUtil::DEBUG) {
			$init($System);
			$nc($System::out)->println(">>> TGS credentials serviceCredsSingle:"_s);
			$Credentials::printDebug(theCreds);
		}
		if (!okAsDelegate->get(0)) {
			theCreds->resetDelegate();
		}
	}
	return theCreds;
}

void CredentialsUtil::handleS4U2SelfReferral($PADataArray* pas, $Credentials* oldCeds, $Credentials* newCreds) {
	$init(CredentialsUtil);
	if (CredentialsUtil::DEBUG) {
		$init($System);
		$nc($System::out)->println(">>> Handling S4U2Self referral"_s);
	}
	for (int32_t i = 0; i < $nc(pas)->length; ++i) {
		$var($PAData, pa, pas->get(i));
		if ($nc(pa)->getType() == $Krb5::PA_FOR_USER) {
			$var($DerValue, var$0, $new($DerValue, $(pa->getValue())));
			$var($PAForUserEnc, paForUser, $new($PAForUserEnc, var$0, $($nc(oldCeds)->getSessionKey())));
			$var($PrincipalName, var$1, paForUser->getName());
			pas->set(i, $$new($PAData, $Krb5::PA_FOR_USER, $($$new($PAForUserEnc, var$1, $($nc(newCreds)->getSessionKey()))->asn1Encode())));
			break;
		}
	}
}

$String* CredentialsUtil::handleS4U2ProxyReferral($Credentials* asCreds, $CredentialsArray* credsInOut, $PrincipalName* sname) {
	$init(CredentialsUtil);
	if (CredentialsUtil::DEBUG) {
		$init($System);
		$nc($System::out)->println(">>> Handling S4U2Proxy referral"_s);
	}
	$var($Credentials, refTGT, nullptr);
	$var($Credentials, middleSvcCredsInBackendRealm, serviceCreds(sname, asCreds));
	$var($String, backendRealm, $nc($($nc(middleSvcCredsInBackendRealm)->getServer()))->getRealmString());
	$var($String, toRealm, $nc($($nc($($nc($nc(credsInOut)->get(0))->getServer()))->getNameStrings()))->get(1));
	if (!$nc(toRealm)->equals(backendRealm)) {
		$assign(refTGT, getTGTforRealm(toRealm, backendRealm, credsInOut->get(0), $$new($booleans, 1)));
	} else {
		$assign(refTGT, credsInOut->get(0));
	}
	credsInOut->set(0, $(getTGTforRealm($($nc($($nc(asCreds)->getClient()))->getRealmString()), backendRealm, asCreds, $$new($booleans, 1))));
	credsInOut->set(1, refTGT);
	return backendRealm;
}

void clinit$CredentialsUtil($Class* class$) {
	$init($Krb5);
	CredentialsUtil::DEBUG = $Krb5::DEBUG;
}

CredentialsUtil::CredentialsUtil() {
}

$Class* CredentialsUtil::load$($String* name, bool initialize) {
	$loadClass(CredentialsUtil, name, initialize, &_CredentialsUtil_ClassInfo_, clinit$CredentialsUtil, allocate$CredentialsUtil);
	return class$;
}

$Class* CredentialsUtil::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun