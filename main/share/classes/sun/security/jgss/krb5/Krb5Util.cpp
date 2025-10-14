#include <sun/security/jgss/krb5/Krb5Util.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/security/AccessControlContext.h>
#include <java/util/Date.h>
#include <javax/crypto/SecretKey.h>
#include <javax/security/auth/Subject.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <javax/security/auth/kerberos/KerberosTicket.h>
#include <javax/security/auth/kerberos/KeyTab.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/krb5/ServiceCreds.h>
#include <sun/security/jgss/krb5/SubjectComber.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/JavaxSecurityAuthKerberosAccess.h>
#include <sun/security/krb5/KerberosSecrets.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/ktab/KeyTab.h>
#include <jcpp.h>

#undef DEBUG
#undef GSS_KRB5_MECH_OID
#undef KRB_NT_SRV_INST

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $EncryptionKeyArray = $Array<::sun::security::krb5::EncryptionKey>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessControlContext = ::java::security::AccessControlContext;
using $Key = ::java::security::Key;
using $Date = ::java::util::Date;
using $SecretKey = ::javax::crypto::SecretKey;
using $Subject = ::javax::security::auth::Subject;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;
using $KerberosTicket = ::javax::security::auth::kerberos::KerberosTicket;
using $1KeyTab = ::javax::security::auth::kerberos::KeyTab;
using $Oid = ::org::ietf::jgss::Oid;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $ServiceCreds = ::sun::security::jgss::krb5::ServiceCreds;
using $SubjectComber = ::sun::security::jgss::krb5::SubjectComber;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $JavaxSecurityAuthKerberosAccess = ::sun::security::krb5::JavaxSecurityAuthKerberosAccess;
using $KerberosSecrets = ::sun::security::krb5::KerberosSecrets;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $KeyTab = ::sun::security::krb5::internal::ktab::KeyTab;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5Util_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $STATIC | $FINAL, $staticField(Krb5Util, DEBUG)},
	{}
};

$MethodInfo _Krb5Util_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Krb5Util::*)()>(&Krb5Util::init$))},
	{"credsToTicket", "(Lsun/security/krb5/Credentials;)Ljavax/security/auth/kerberos/KerberosTicket;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$KerberosTicket*(*)($Credentials*)>(&Krb5Util::credsToTicket))},
	{"getInitialTicket", "(Lsun/security/jgss/GSSCaller;Ljava/lang/String;Ljava/security/AccessControlContext;)Ljavax/security/auth/kerberos/KerberosTicket;", nullptr, $STATIC, $method(static_cast<$KerberosTicket*(*)($GSSCaller*,$String*,$AccessControlContext*)>(&Krb5Util::getInitialTicket)), "javax.security.auth.login.LoginException"},
	{"getServiceCreds", "(Lsun/security/jgss/GSSCaller;Ljava/lang/String;Ljava/security/AccessControlContext;)Lsun/security/jgss/krb5/ServiceCreds;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ServiceCreds*(*)($GSSCaller*,$String*,$AccessControlContext*)>(&Krb5Util::getServiceCreds)), "javax.security.auth.login.LoginException"},
	{"getServiceTicket", "(Lsun/security/jgss/GSSCaller;Ljava/lang/String;Ljava/lang/String;Ljava/security/AccessControlContext;)Ljavax/security/auth/kerberos/KerberosTicket;", nullptr, $STATIC, $method(static_cast<$KerberosTicket*(*)($GSSCaller*,$String*,$String*,$AccessControlContext*)>(&Krb5Util::getServiceTicket)), "javax.security.auth.login.LoginException"},
	{"keysFromJavaxKeyTab", "(Ljavax/security/auth/kerberos/KeyTab;Lsun/security/krb5/PrincipalName;)[Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$EncryptionKeyArray*(*)($1KeyTab*,$PrincipalName*)>(&Krb5Util::keysFromJavaxKeyTab))},
	{"snapshotFromJavaxKeyTab", "(Ljavax/security/auth/kerberos/KeyTab;)Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$KeyTab*(*)($1KeyTab*)>(&Krb5Util::snapshotFromJavaxKeyTab))},
	{"ticketToCreds", "(Ljavax/security/auth/kerberos/KerberosTicket;)Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Credentials*(*)($KerberosTicket*)>(&Krb5Util::ticketToCreds)), "sun.security.krb5.KrbException,java.io.IOException"},
	{}
};

$ClassInfo _Krb5Util_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.krb5.Krb5Util",
	"java.lang.Object",
	nullptr,
	_Krb5Util_FieldInfo_,
	_Krb5Util_MethodInfo_
};

$Object* allocate$Krb5Util($Class* clazz) {
	return $of($alloc(Krb5Util));
}

bool Krb5Util::DEBUG = false;

void Krb5Util::init$() {
}

$KerberosTicket* Krb5Util::getServiceTicket($GSSCaller* caller, $String* clientPrincipal, $String* serverPrincipal, $AccessControlContext* acc) {
	$init(Krb5Util);
	$var($Subject, accSubj, $Subject::getSubject(acc));
	$load($KerberosTicket);
	$var($KerberosTicket, ticket, $cast($KerberosTicket, $SubjectComber::find(accSubj, serverPrincipal, clientPrincipal, $KerberosTicket::class$)));
	return ticket;
}

$KerberosTicket* Krb5Util::getInitialTicket($GSSCaller* caller, $String* clientPrincipal, $AccessControlContext* acc) {
	$init(Krb5Util);
	$var($Subject, accSubj, $Subject::getSubject(acc));
	$load($KerberosTicket);
	$var($KerberosTicket, ticket, $cast($KerberosTicket, $SubjectComber::find(accSubj, nullptr, clientPrincipal, $KerberosTicket::class$)));
	if (ticket == nullptr && !$GSSUtil::useSubjectCredsOnly(caller)) {
		$init($GSSUtil);
		$var($Subject, subject, $GSSUtil::login(caller, $GSSUtil::GSS_KRB5_MECH_OID));
		$assign(ticket, $cast($KerberosTicket, $SubjectComber::find(subject, nullptr, clientPrincipal, $KerberosTicket::class$)));
	}
	return ticket;
}

$ServiceCreds* Krb5Util::getServiceCreds($GSSCaller* caller, $String* serverPrincipal, $AccessControlContext* acc) {
	$init(Krb5Util);
	$var($Subject, accSubj, $Subject::getSubject(acc));
	$var($ServiceCreds, sc, nullptr);
	if (accSubj != nullptr) {
		$assign(sc, $ServiceCreds::getInstance(accSubj, serverPrincipal));
	}
	if (sc == nullptr && !$GSSUtil::useSubjectCredsOnly(caller)) {
		$init($GSSUtil);
		$var($Subject, subject, $GSSUtil::login(caller, $GSSUtil::GSS_KRB5_MECH_OID));
		$assign(sc, $ServiceCreds::getInstance(subject, serverPrincipal));
	}
	return sc;
}

$KerberosTicket* Krb5Util::credsToTicket($Credentials* serviceCreds) {
	$init(Krb5Util);
	$var($EncryptionKey, sessionKey, $nc(serviceCreds)->getSessionKey());
	$var($bytes, var$0, serviceCreds->getEncoded());
	$var($KerberosPrincipal, var$1, $new($KerberosPrincipal, $($nc($(serviceCreds->getClient()))->getName())));
	$var($KerberosPrincipal, var$2, $new($KerberosPrincipal, $($nc($(serviceCreds->getServer()))->getName()), $KerberosPrincipal::KRB_NT_SRV_INST));
	$var($bytes, var$3, $nc(sessionKey)->getBytes());
	int32_t var$4 = sessionKey->getEType();
	$var($booleans, var$5, serviceCreds->getFlags());
	$var($Date, var$6, serviceCreds->getAuthTime());
	$var($Date, var$7, serviceCreds->getStartTime());
	$var($Date, var$8, serviceCreds->getEndTime());
	$var($Date, var$9, serviceCreds->getRenewTill());
	$var($KerberosTicket, kt, $new($KerberosTicket, var$0, var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, var$9, $(serviceCreds->getClientAddresses())));
	$var($PrincipalName, clientAlias, serviceCreds->getClientAlias());
	$var($PrincipalName, serverAlias, serviceCreds->getServerAlias());
	if (clientAlias != nullptr) {
		$var($String, var$10, clientAlias->getName());
		$nc($($KerberosSecrets::getJavaxSecurityAuthKerberosAccess()))->kerberosTicketSetClientAlias(kt, $$new($KerberosPrincipal, var$10, clientAlias->getNameType()));
	}
	if (serverAlias != nullptr) {
		$var($String, var$11, serverAlias->getName());
		$nc($($KerberosSecrets::getJavaxSecurityAuthKerberosAccess()))->kerberosTicketSetServerAlias(kt, $$new($KerberosPrincipal, var$11, serverAlias->getNameType()));
	}
	return kt;
}

$Credentials* Krb5Util::ticketToCreds($KerberosTicket* kerbTicket) {
	$init(Krb5Util);
	$var($KerberosPrincipal, clientAlias, $nc($($KerberosSecrets::getJavaxSecurityAuthKerberosAccess()))->kerberosTicketGetClientAlias(kerbTicket));
	$var($KerberosPrincipal, serverAlias, $nc($($KerberosSecrets::getJavaxSecurityAuthKerberosAccess()))->kerberosTicketGetServerAlias(kerbTicket));
	$var($bytes, var$0, $nc(kerbTicket)->getEncoded());
	$var($String, var$1, $nc($(kerbTicket->getClient()))->getName());
	$var($String, var$2, (clientAlias != nullptr ? $nc(clientAlias)->getName() : ($String*)nullptr));
	$var($String, var$3, $nc($(kerbTicket->getServer()))->getName());
	$var($String, var$4, (serverAlias != nullptr ? $nc(serverAlias)->getName() : ($String*)nullptr));
	$var($bytes, var$5, $nc($(kerbTicket->getSessionKey()))->getEncoded());
	int32_t var$6 = kerbTicket->getSessionKeyType();
	$var($booleans, var$7, kerbTicket->getFlags());
	$var($Date, var$8, kerbTicket->getAuthTime());
	$var($Date, var$9, kerbTicket->getStartTime());
	$var($Date, var$10, kerbTicket->getEndTime());
	$var($Date, var$11, kerbTicket->getRenewTill());
	return $new($Credentials, var$0, var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, var$9, var$10, var$11, $(kerbTicket->getClientAddresses()));
}

$KeyTab* Krb5Util::snapshotFromJavaxKeyTab($1KeyTab* ktab) {
	$init(Krb5Util);
	return $nc($($KerberosSecrets::getJavaxSecurityAuthKerberosAccess()))->keyTabTakeSnapshot(ktab);
}

$EncryptionKeyArray* Krb5Util::keysFromJavaxKeyTab($1KeyTab* ktab, $PrincipalName* cname) {
	$init(Krb5Util);
	return $nc($(snapshotFromJavaxKeyTab(ktab)))->readServiceKeys(cname);
}

void clinit$Krb5Util($Class* class$) {
	Krb5Util::DEBUG = $GetBooleanAction::privilegedGetProperty("sun.security.krb5.debug"_s);
}

Krb5Util::Krb5Util() {
}

$Class* Krb5Util::load$($String* name, bool initialize) {
	$loadClass(Krb5Util, name, initialize, &_Krb5Util_ClassInfo_, clinit$Krb5Util, allocate$Krb5Util);
	return class$;
}

$Class* Krb5Util::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun