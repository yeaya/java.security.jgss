#include <sun/security/jgss/GSSUtil.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/Security.h>
#include <java/util/AbstractSet.h>
#include <java/util/Date.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <javax/crypto/SecretKey.h>
#include <javax/security/auth/Subject.h>
#include <javax/security/auth/callback/CallbackHandler.h>
#include <javax/security/auth/kerberos/KerberosKey.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <javax/security/auth/kerberos/KerberosTicket.h>
#include <javax/security/auth/login/Configuration.h>
#include <javax/security/auth/login/LoginContext.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/net/www/protocol/http/HttpCallerInfo.h>
#include <sun/net/www/protocol/http/spnego/NegotiateCallbackHandler.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSCredentialImpl.h>
#include <sun/security/jgss/GSSNameImpl.h>
#include <sun/security/jgss/GSSUtil$1.h>
#include <sun/security/jgss/HttpCaller.h>
#include <sun/security/jgss/LoginConfigImpl.h>
#include <sun/security/jgss/krb5/Krb5NameElement.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/spnego/SpNegoCredElement.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/util/ConsoleCallbackHandler.h>
#include <jcpp.h>

#undef DEBUG
#undef GSS_KRB5_MECH_OID
#undef GSS_KRB5_MECH_OID2
#undef GSS_KRB5_MECH_OID_MS
#undef GSS_SPNEGO_MECH_OID
#undef NT_GSS_KRB5_PRINCIPAL

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Key = ::java::security::Key;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Security = ::java::security::Security;
using $AbstractSet = ::java::util::AbstractSet;
using $Date = ::java::util::Date;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;
using $SecretKey = ::javax::crypto::SecretKey;
using $Subject = ::javax::security::auth::Subject;
using $CallbackHandler = ::javax::security::auth::callback::CallbackHandler;
using $KerberosKey = ::javax::security::auth::kerberos::KerberosKey;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;
using $KerberosTicket = ::javax::security::auth::kerberos::KerberosTicket;
using $Configuration = ::javax::security::auth::login::Configuration;
using $LoginContext = ::javax::security::auth::login::LoginContext;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $HttpCallerInfo = ::sun::net::www::protocol::http::HttpCallerInfo;
using $NegotiateCallbackHandler = ::sun::net::www::protocol::http::spnego::NegotiateCallbackHandler;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $GSSCredentialImpl = ::sun::security::jgss::GSSCredentialImpl;
using $GSSNameImpl = ::sun::security::jgss::GSSNameImpl;
using $GSSUtil$1 = ::sun::security::jgss::GSSUtil$1;
using $HttpCaller = ::sun::security::jgss::HttpCaller;
using $LoginConfigImpl = ::sun::security::jgss::LoginConfigImpl;
using $Krb5NameElement = ::sun::security::jgss::krb5::Krb5NameElement;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $SpNegoCredElement = ::sun::security::jgss::spnego::SpNegoCredElement;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $ConsoleCallbackHandler = ::sun::security::util::ConsoleCallbackHandler;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _GSSUtil_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(GSSUtil, $assertionsDisabled)},
	{"GSS_KRB5_MECH_OID", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSUtil, GSS_KRB5_MECH_OID)},
	{"GSS_KRB5_MECH_OID2", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSUtil, GSS_KRB5_MECH_OID2)},
	{"GSS_KRB5_MECH_OID_MS", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSUtil, GSS_KRB5_MECH_OID_MS)},
	{"GSS_SPNEGO_MECH_OID", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSUtil, GSS_SPNEGO_MECH_OID)},
	{"NT_GSS_KRB5_PRINCIPAL", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSUtil, NT_GSS_KRB5_PRINCIPAL)},
	{"DEBUG", "Z", nullptr, $STATIC | $FINAL, $staticField(GSSUtil, DEBUG)},
	{}
};

$MethodInfo _GSSUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(GSSUtil::*)()>(&GSSUtil::init$))},
	{"createOid", "(Ljava/lang/String;)Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Oid*(*)($String*)>(&GSSUtil::createOid))},
	{"debug", "(Ljava/lang/String;)V", nullptr, $STATIC, $method(static_cast<void(*)($String*)>(&GSSUtil::debug))},
	{"getMechStr", "(Lorg/ietf/jgss/Oid;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($Oid*)>(&GSSUtil::getMechStr))},
	{"getSubject", "(Lorg/ietf/jgss/GSSName;Lorg/ietf/jgss/GSSCredential;)Ljavax/security/auth/Subject;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Subject*(*)($GSSName*,$GSSCredential*)>(&GSSUtil::getSubject))},
	{"isKerberosMech", "(Lorg/ietf/jgss/Oid;)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)($Oid*)>(&GSSUtil::isKerberosMech))},
	{"isSpNegoMech", "(Lorg/ietf/jgss/Oid;)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)($Oid*)>(&GSSUtil::isSpNegoMech))},
	{"login", "(Lsun/security/jgss/GSSCaller;Lorg/ietf/jgss/Oid;)Ljavax/security/auth/Subject;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Subject*(*)($GSSCaller*,$Oid*)>(&GSSUtil::login)), "javax.security.auth.login.LoginException"},
	{"populateCredentials", "(Ljava/util/Set;Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/lang/Object;>;Ljava/util/Set<*>;)V", $PRIVATE | $STATIC, $method(static_cast<void(*)($Set*,$Set*)>(&GSSUtil::populateCredentials))},
	{"searchSubject", "(Lsun/security/jgss/spi/GSSNameSpi;Lorg/ietf/jgss/Oid;ZLjava/lang/Class;)Ljava/util/Vector;", "<T::Lsun/security/jgss/spi/GSSCredentialSpi;>(Lsun/security/jgss/spi/GSSNameSpi;Lorg/ietf/jgss/Oid;ZLjava/lang/Class<+TT;>;)Ljava/util/Vector<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$Vector*(*)($GSSNameSpi*,$Oid*,bool,$Class*)>(&GSSUtil::searchSubject))},
	{"useMSInterop", "()Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)()>(&GSSUtil::useMSInterop))},
	{"useSubjectCredsOnly", "(Lsun/security/jgss/GSSCaller;)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)($GSSCaller*)>(&GSSUtil::useSubjectCredsOnly))},
	{}
};

$InnerClassInfo _GSSUtil_InnerClassesInfo_[] = {
	{"sun.security.jgss.GSSUtil$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _GSSUtil_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.GSSUtil",
	"java.lang.Object",
	nullptr,
	_GSSUtil_FieldInfo_,
	_GSSUtil_MethodInfo_,
	nullptr,
	nullptr,
	_GSSUtil_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.GSSUtil$1"
};

$Object* allocate$GSSUtil($Class* clazz) {
	return $of($alloc(GSSUtil));
}

bool GSSUtil::$assertionsDisabled = false;
$Oid* GSSUtil::GSS_KRB5_MECH_OID = nullptr;
$Oid* GSSUtil::GSS_KRB5_MECH_OID2 = nullptr;
$Oid* GSSUtil::GSS_KRB5_MECH_OID_MS = nullptr;
$Oid* GSSUtil::GSS_SPNEGO_MECH_OID = nullptr;
$Oid* GSSUtil::NT_GSS_KRB5_PRINCIPAL = nullptr;
bool GSSUtil::DEBUG = false;

void GSSUtil::init$() {
}

void GSSUtil::debug($String* message) {
	$init(GSSUtil);
	if (GSSUtil::DEBUG) {
		if (!GSSUtil::$assertionsDisabled && !(message != nullptr)) {
			$throwNew($AssertionError);
		}
		$init($System);
		$nc($System::out)->println(message);
	}
}

$Oid* GSSUtil::createOid($String* oidStr) {
	$init(GSSUtil);
	try {
		return $new($Oid, oidStr);
	} catch ($GSSException&) {
		$var($GSSException, e, $catch());
		debug($$str({"Ignored invalid OID: "_s, oidStr}));
		return nullptr;
	}
	$shouldNotReachHere();
}

bool GSSUtil::isSpNegoMech($Oid* oid) {
	$init(GSSUtil);
	return ($nc(GSSUtil::GSS_SPNEGO_MECH_OID)->equals(oid));
}

bool GSSUtil::isKerberosMech($Oid* oid) {
	$init(GSSUtil);
	bool var$1 = $nc(GSSUtil::GSS_KRB5_MECH_OID)->equals(oid);
	bool var$0 = var$1 || $nc(GSSUtil::GSS_KRB5_MECH_OID2)->equals(oid);
	return (var$0 || $nc(GSSUtil::GSS_KRB5_MECH_OID_MS)->equals(oid));
}

$String* GSSUtil::getMechStr($Oid* oid) {
	$init(GSSUtil);
	if (isSpNegoMech(oid)) {
		return "SPNEGO"_s;
	} else if (isKerberosMech(oid)) {
		return "Kerberos V5"_s;
	} else {
		return $nc(oid)->toString();
	}
}

$Subject* GSSUtil::getSubject($GSSName* name, $GSSCredential* creds) {
	$init(GSSUtil);
	$var($HashSet, privCredentials, nullptr);
	$var($HashSet, pubCredentials, $new($HashSet));
	$var($Set, gssCredentials, nullptr);
	$var($Set, krb5Principals, $new($HashSet));
	if ($instanceOf($GSSNameImpl, name)) {
		try {
			$var($GSSNameSpi, ne, $nc(($cast($GSSNameImpl, name)))->getElement(GSSUtil::GSS_KRB5_MECH_OID));
			$var($String, krbName, $nc(ne)->toString());
			if ($instanceOf($Krb5NameElement, ne)) {
				$assign(krbName, $nc($($nc(($cast($Krb5NameElement, ne)))->getKrb5PrincipalName()))->getName());
			}
			$var($KerberosPrincipal, krbPrinc, $new($KerberosPrincipal, krbName));
			krb5Principals->add(krbPrinc);
		} catch ($GSSException&) {
			$var($GSSException, ge, $catch());
			debug($$str({"Skipped name "_s, name, " due to "_s, ge}));
		}
	}
	if ($instanceOf($GSSCredentialImpl, creds)) {
		$assign(gssCredentials, $nc(($cast($GSSCredentialImpl, creds)))->getElements());
		$assign(privCredentials, $new($HashSet, $nc(gssCredentials)->size()));
		populateCredentials(privCredentials, gssCredentials);
	} else {
		$assign(privCredentials, $new($HashSet));
	}
	debug("Created Subject with the following"_s);
	debug($$str({"principals="_s, krb5Principals}));
	debug($$str({"public creds="_s, pubCredentials}));
	debug($$str({"private creds="_s, privCredentials}));
	return $new($Subject, false, krb5Principals, pubCredentials, privCredentials);
}

void GSSUtil::populateCredentials($Set* credentials, $Set* gssCredentials) {
	$init(GSSUtil);
	$var($Object, cred, nullptr);
	$var($Iterator, elements, $nc(gssCredentials)->iterator());
	while ($nc(elements)->hasNext()) {
		$assign(cred, elements->next());
		if ($instanceOf($SpNegoCredElement, cred)) {
			$assign(cred, $nc(($cast($SpNegoCredElement, cred)))->getInternalCred());
		}
		if ($instanceOf($KerberosTicket, cred)) {
			if (!$nc($($nc($of(cred))->getClass()->getName()))->equals("javax.security.auth.kerberos.KerberosTicket"_s)) {
				$var($KerberosTicket, tempTkt, $cast($KerberosTicket, cred));
				$var($bytes, var$0, tempTkt->getEncoded());
				$var($KerberosPrincipal, var$1, tempTkt->getClient());
				$var($KerberosPrincipal, var$2, tempTkt->getServer());
				$var($bytes, var$3, $nc($(tempTkt->getSessionKey()))->getEncoded());
				int32_t var$4 = tempTkt->getSessionKeyType();
				$var($booleans, var$5, tempTkt->getFlags());
				$var($Date, var$6, tempTkt->getAuthTime());
				$var($Date, var$7, tempTkt->getStartTime());
				$var($Date, var$8, tempTkt->getEndTime());
				$var($Date, var$9, tempTkt->getRenewTill());
				$assign(cred, $new($KerberosTicket, var$0, var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, var$9, $(tempTkt->getClientAddresses())));
			}
			$nc(credentials)->add(cred);
		} else if ($instanceOf($KerberosKey, cred)) {
			if (!$nc($($nc($of(cred))->getClass()->getName()))->equals("javax.security.auth.kerberos.KerberosKey"_s)) {
				$var($KerberosKey, tempKey, $cast($KerberosKey, cred));
				$var($KerberosPrincipal, var$10, tempKey->getPrincipal());
				$var($bytes, var$11, tempKey->getEncoded());
				int32_t var$12 = tempKey->getKeyType();
				$assign(cred, $new($KerberosKey, var$10, var$11, var$12, tempKey->getVersionNumber()));
			}
			$nc(credentials)->add(cred);
		} else {
			debug($$str({"Skipped cred element: "_s, cred}));
		}
	}
}

$Subject* GSSUtil::login($GSSCaller* caller, $Oid* mech) {
	$init(GSSUtil);
	$var($CallbackHandler, cb, nullptr);
	if ($instanceOf($HttpCaller, caller)) {
		$assign(cb, $new($NegotiateCallbackHandler, $($nc(($cast($HttpCaller, caller)))->info())));
	} else {
		$var($String, defaultHandler, $Security::getProperty("auth.login.defaultCallbackHandler"_s));
		if ((defaultHandler != nullptr) && (defaultHandler->length() != 0)) {
			$assign(cb, nullptr);
		} else {
			$assign(cb, $new($ConsoleCallbackHandler));
		}
	}
	$var($LoginContext, lc, $new($LoginContext, ""_s, nullptr, cb, $$new($LoginConfigImpl, caller, mech)));
	lc->login();
	return lc->getSubject();
}

bool GSSUtil::useSubjectCredsOnly($GSSCaller* caller) {
	$init(GSSUtil);
	$var($String, propValue, $GetPropertyAction::privilegedGetProperty("javax.security.auth.useSubjectCredsOnly"_s));
	if ($instanceOf($HttpCaller, caller)) {
		return "true"_s->equalsIgnoreCase(propValue);
	} else {
		return !("false"_s->equalsIgnoreCase(propValue));
	}
}

bool GSSUtil::useMSInterop() {
	$init(GSSUtil);
	$var($String, propValue, $GetPropertyAction::privilegedGetProperty("sun.security.spnego.msinterop"_s, "true"_s));
	return (!$nc(propValue)->equalsIgnoreCase("false"_s));
}

$Vector* GSSUtil::searchSubject($GSSNameSpi* name, $Oid* mech, bool initiate, $Class* credCls) {
	$init(GSSUtil);
	$beforeCallerSensitive();
	$var($String, var$3, $$str({"Search Subject for "_s, $(getMechStr(mech)), (initiate ? " INIT"_s : " ACCEPT"_s), " cred ("_s}));
	$var($String, var$2, $$concat(var$3, (name == nullptr ? "<<DEF>>"_s : $($nc(name)->toString()))));
	$var($String, var$1, $$concat(var$2, ", "));
	$var($String, var$0, $$concat(var$1, $($nc(credCls)->getName())));
	debug($$concat(var$0, ")"));
	$var($AccessControlContext, acc, $AccessController::getContext());
	try {
		$var($Vector, creds, $cast($Vector, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($GSSUtil$1, acc, mech, initiate, credCls, name)))));
		return creds;
	} catch ($PrivilegedActionException&) {
		$var($PrivilegedActionException, pae, $catch());
		debug("Unexpected exception when searching Subject:"_s);
		if (GSSUtil::DEBUG) {
			pae->printStackTrace();
		}
		return nullptr;
	}
	$shouldNotReachHere();
}

void clinit$GSSUtil($Class* class$) {
	GSSUtil::$assertionsDisabled = !GSSUtil::class$->desiredAssertionStatus();
	$assignStatic(GSSUtil::GSS_KRB5_MECH_OID, GSSUtil::createOid("1.2.840.113554.1.2.2"_s));
	$assignStatic(GSSUtil::GSS_KRB5_MECH_OID2, GSSUtil::createOid("1.3.5.1.5.2"_s));
	$assignStatic(GSSUtil::GSS_KRB5_MECH_OID_MS, GSSUtil::createOid("1.2.840.48018.1.2.2"_s));
	$assignStatic(GSSUtil::GSS_SPNEGO_MECH_OID, GSSUtil::createOid("1.3.6.1.5.5.2"_s));
	$assignStatic(GSSUtil::NT_GSS_KRB5_PRINCIPAL, GSSUtil::createOid("1.2.840.113554.1.2.2.1"_s));
	GSSUtil::DEBUG = $GetBooleanAction::privilegedGetProperty("sun.security.jgss.debug"_s);
}

GSSUtil::GSSUtil() {
}

$Class* GSSUtil::load$($String* name, bool initialize) {
	$loadClass(GSSUtil, name, initialize, &_GSSUtil_ClassInfo_, clinit$GSSUtil, allocate$GSSUtil);
	return class$;
}

$Class* GSSUtil::class$ = nullptr;

		} // jgss
	} // security
} // sun