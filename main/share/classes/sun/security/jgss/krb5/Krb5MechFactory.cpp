#include <sun/security/jgss/krb5/Krb5MechFactory.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Permission.h>
#include <java/security/Provider.h>
#include <java/util/Vector.h>
#include <javax/security/auth/kerberos/ServicePermission.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/SunProvider.h>
#include <sun/security/jgss/krb5/Krb5AcceptCredential.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/jgss/krb5/Krb5CredElement.h>
#include <sun/security/jgss/krb5/Krb5InitCredential.h>
#include <sun/security/jgss/krb5/Krb5NameElement.h>
#include <sun/security/jgss/krb5/Krb5ProxyCredential.h>
#include <sun/security/jgss/krb5/Krb5Util.h>
#include <sun/security/jgss/spi/GSSContextSpi.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/krb5/PrincipalName.h>
#include <jcpp.h>

#undef ACCEPT_ONLY
#undef CALLER_UNKNOWN
#undef DEBUG
#undef FAILURE
#undef GSS_KRB5_MECH_OID
#undef INDEFINITE_LIFETIME
#undef INITIATE_AND_ACCEPT
#undef INITIATE_ONLY
#undef NT_EXPORT_NAME
#undef NT_GSS_KRB5_PRINCIPAL
#undef NT_HOSTBASED_SERVICE
#undef NT_USER_NAME
#undef PROVIDER

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Permission = ::java::security::Permission;
using $Provider = ::java::security::Provider;
using $Vector = ::java::util::Vector;
using $ServicePermission = ::javax::security::auth::kerberos::ServicePermission;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $SunProvider = ::sun::security::jgss::SunProvider;
using $Krb5AcceptCredential = ::sun::security::jgss::krb5::Krb5AcceptCredential;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;
using $Krb5CredElement = ::sun::security::jgss::krb5::Krb5CredElement;
using $Krb5InitCredential = ::sun::security::jgss::krb5::Krb5InitCredential;
using $Krb5NameElement = ::sun::security::jgss::krb5::Krb5NameElement;
using $Krb5ProxyCredential = ::sun::security::jgss::krb5::Krb5ProxyCredential;
using $Krb5Util = ::sun::security::jgss::krb5::Krb5Util;
using $GSSContextSpi = ::sun::security::jgss::spi::GSSContextSpi;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $MechanismFactory = ::sun::security::jgss::spi::MechanismFactory;
using $PrincipalName = ::sun::security::krb5::PrincipalName;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5MechFactory_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Krb5MechFactory, DEBUG)},
	{"PROVIDER", "Ljava/security/Provider;", nullptr, $STATIC | $FINAL, $staticField(Krb5MechFactory, PROVIDER)},
	{"GSS_KRB5_MECH_OID", "Lorg/ietf/jgss/Oid;", nullptr, $STATIC | $FINAL, $staticField(Krb5MechFactory, GSS_KRB5_MECH_OID)},
	{"NT_GSS_KRB5_PRINCIPAL", "Lorg/ietf/jgss/Oid;", nullptr, $STATIC | $FINAL, $staticField(Krb5MechFactory, NT_GSS_KRB5_PRINCIPAL)},
	{"nameTypes", "[Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE | $STATIC, $staticField(Krb5MechFactory, nameTypes)},
	{"caller", "Lsun/security/jgss/GSSCaller;", nullptr, $PRIVATE | $FINAL, $field(Krb5MechFactory, caller)},
	{}
};

$MethodInfo _Krb5MechFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Krb5MechFactory::*)()>(&Krb5MechFactory::init$))},
	{"<init>", "(Lsun/security/jgss/GSSCaller;)V", nullptr, $PUBLIC, $method(static_cast<void(Krb5MechFactory::*)($GSSCaller*)>(&Krb5MechFactory::init$))},
	{"checkAcceptCredPermission", "(Lsun/security/jgss/krb5/Krb5NameElement;Lsun/security/jgss/spi/GSSNameSpi;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($Krb5NameElement*,$GSSNameSpi*)>(&Krb5MechFactory::checkAcceptCredPermission))},
	{"checkInitCredPermission", "(Lsun/security/jgss/krb5/Krb5NameElement;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($Krb5NameElement*)>(&Krb5MechFactory::checkInitCredPermission))},
	{"createOid", "(Ljava/lang/String;)Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Oid*(*)($String*)>(&Krb5MechFactory::createOid))},
	{"getCredFromSubject", "(Lsun/security/jgss/spi/GSSNameSpi;Z)Lsun/security/jgss/krb5/Krb5CredElement;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Krb5CredElement*(*)($GSSNameSpi*,bool)>(&Krb5MechFactory::getCredFromSubject)), "org.ietf.jgss.GSSException"},
	{"getCredentialElement", "(Lsun/security/jgss/spi/GSSNameSpi;III)Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismContext", "(Lsun/security/jgss/spi/GSSNameSpi;Lsun/security/jgss/spi/GSSCredentialSpi;I)Lsun/security/jgss/spi/GSSContextSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismContext", "(Lsun/security/jgss/spi/GSSCredentialSpi;)Lsun/security/jgss/spi/GSSContextSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismContext", "([B)Lsun/security/jgss/spi/GSSContextSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismOid", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $FINAL},
	{"getNameElement", "(Ljava/lang/String;Lorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getNameElement", "([BLorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getNameTypes", "()[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Krb5MechFactory_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.jgss.krb5.Krb5MechFactory",
	"java.lang.Object",
	"sun.security.jgss.spi.MechanismFactory",
	_Krb5MechFactory_FieldInfo_,
	_Krb5MechFactory_MethodInfo_
};

$Object* allocate$Krb5MechFactory($Class* clazz) {
	return $of($alloc(Krb5MechFactory));
}

bool Krb5MechFactory::DEBUG = false;
$Provider* Krb5MechFactory::PROVIDER = nullptr;
$Oid* Krb5MechFactory::GSS_KRB5_MECH_OID = nullptr;
$Oid* Krb5MechFactory::NT_GSS_KRB5_PRINCIPAL = nullptr;
$OidArray* Krb5MechFactory::nameTypes = nullptr;

$Krb5CredElement* Krb5MechFactory::getCredFromSubject($GSSNameSpi* name, bool initiate) {
	$init(Krb5MechFactory);
	$load($Krb5InitCredential);
	$load($Krb5AcceptCredential);
	$var($Vector, creds, $GSSUtil::searchSubject(name, Krb5MechFactory::GSS_KRB5_MECH_OID, initiate, (initiate ? $Krb5InitCredential::class$ : $Krb5AcceptCredential::class$)));
	$var($Krb5CredElement, result, (creds == nullptr || $nc(creds)->isEmpty()) ? ($Krb5CredElement*)nullptr : $cast($Krb5CredElement, $nc(creds)->firstElement()));
	if (result != nullptr) {
		if (initiate) {
			checkInitCredPermission($cast($Krb5NameElement, $(result->getName())));
		} else {
			checkAcceptCredPermission($cast($Krb5NameElement, $(result->getName())), name);
		}
	}
	return result;
}

void Krb5MechFactory::init$() {
	$init($GSSCaller);
	Krb5MechFactory::init$($GSSCaller::CALLER_UNKNOWN);
}

void Krb5MechFactory::init$($GSSCaller* caller) {
	$set(this, caller, caller);
}

$GSSNameSpi* Krb5MechFactory::getNameElement($String* nameStr, $Oid* nameType) {
	return $Krb5NameElement::getInstance(nameStr, nameType);
}

$GSSNameSpi* Krb5MechFactory::getNameElement($bytes* name, $Oid* nameType) {
	return $Krb5NameElement::getInstance($$new($String, name), nameType);
}

$GSSCredentialSpi* Krb5MechFactory::getCredentialElement($GSSNameSpi* name$renamed, int32_t initLifetime, int32_t acceptLifetime, int32_t usage) {
	$var($GSSNameSpi, name, name$renamed);
	if (name != nullptr && !($instanceOf($Krb5NameElement, name))) {
		$var($String, var$0, name->toString());
		$assign(name, $Krb5NameElement::getInstance(var$0, $(name->getStringNameType())));
	}
	$var($Krb5CredElement, credElement, getCredFromSubject(name, (usage != $GSSCredential::ACCEPT_ONLY)));
	if (credElement == nullptr) {
		if (usage == $GSSCredential::INITIATE_ONLY || usage == $GSSCredential::INITIATE_AND_ACCEPT) {
			$assign(credElement, $Krb5InitCredential::getInstance(this->caller, $cast($Krb5NameElement, name), initLifetime));
			$assign(credElement, $Krb5ProxyCredential::tryImpersonation(this->caller, $cast($Krb5InitCredential, credElement)));
			checkInitCredPermission($cast($Krb5NameElement, $($nc(credElement)->getName())));
		} else if (usage == $GSSCredential::ACCEPT_ONLY) {
			$assign(credElement, $Krb5AcceptCredential::getInstance(this->caller, $cast($Krb5NameElement, name)));
			checkAcceptCredPermission($cast($Krb5NameElement, $($nc(credElement)->getName())), name);
		} else {
			$throwNew($GSSException, $GSSException::FAILURE, -1, "Unknown usage mode requested"_s);
		}
	}
	return credElement;
}

void Krb5MechFactory::checkInitCredPermission($Krb5NameElement* name) {
	$init(Krb5MechFactory);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($String, realm, $nc(($($nc(name)->getKrb5PrincipalName())))->getRealmAsString());
		$var($String, tgsPrincipal, $new($String, $$str({"krbtgt/"_s, realm, $$str(u'@'), realm})));
		$var($ServicePermission, perm, $new($ServicePermission, tgsPrincipal, "initiate"_s));
		try {
			sm->checkPermission(perm);
		} catch ($SecurityException&) {
			$var($SecurityException, e, $catch());
			if (Krb5MechFactory::DEBUG) {
				$nc($System::out)->println($$str({"Permission to initiatekerberos init credential"_s, $(e->getMessage())}));
			}
			$throw(e);
		}
	}
}

void Krb5MechFactory::checkAcceptCredPermission($Krb5NameElement* name, $GSSNameSpi* originalName) {
	$init(Krb5MechFactory);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr && name != nullptr) {
		$var($ServicePermission, perm, $new($ServicePermission, $($nc($(name->getKrb5PrincipalName()))->getName()), "accept"_s));
		try {
			sm->checkPermission(perm);
		} catch ($SecurityException&) {
			$var($SecurityException, e, $catch());
			if (originalName == nullptr) {
				$assign(e, $new($SecurityException, "No permission to acquire Kerberos accept credential"_s));
			}
			$throw(e);
		}
	}
}

$GSSContextSpi* Krb5MechFactory::getMechanismContext($GSSNameSpi* peer$renamed, $GSSCredentialSpi* myInitiatorCred$renamed, int32_t lifetime) {
	$var($GSSNameSpi, peer, peer$renamed);
	$var($GSSCredentialSpi, myInitiatorCred, myInitiatorCred$renamed);
	if (peer != nullptr && !($instanceOf($Krb5NameElement, peer))) {
		$var($String, var$0, peer->toString());
		$assign(peer, $Krb5NameElement::getInstance(var$0, $(peer->getStringNameType())));
	}
	if (myInitiatorCred == nullptr) {
		$assign(myInitiatorCred, getCredentialElement(nullptr, lifetime, 0, $GSSCredential::INITIATE_ONLY));
	}
	return $new($Krb5Context, this->caller, $cast($Krb5NameElement, peer), $cast($Krb5CredElement, myInitiatorCred), lifetime);
}

$GSSContextSpi* Krb5MechFactory::getMechanismContext($GSSCredentialSpi* myAcceptorCred$renamed) {
	$var($GSSCredentialSpi, myAcceptorCred, myAcceptorCred$renamed);
	if (myAcceptorCred == nullptr) {
		$assign(myAcceptorCred, getCredentialElement(nullptr, 0, $GSSCredential::INDEFINITE_LIFETIME, $GSSCredential::ACCEPT_ONLY));
	}
	return $new($Krb5Context, this->caller, $cast($Krb5CredElement, myAcceptorCred));
}

$GSSContextSpi* Krb5MechFactory::getMechanismContext($bytes* exportedContext) {
	return $new($Krb5Context, this->caller, exportedContext);
}

$Oid* Krb5MechFactory::getMechanismOid() {
	return Krb5MechFactory::GSS_KRB5_MECH_OID;
}

$Provider* Krb5MechFactory::getProvider() {
	return Krb5MechFactory::PROVIDER;
}

$OidArray* Krb5MechFactory::getNameTypes() {
	return Krb5MechFactory::nameTypes;
}

$Oid* Krb5MechFactory::createOid($String* oidStr) {
	$init(Krb5MechFactory);
	$var($Oid, retVal, nullptr);
	try {
		$assign(retVal, $new($Oid, oidStr));
	} catch ($GSSException&) {
		$catch();
	}
	return retVal;
}

void clinit$Krb5MechFactory($Class* class$) {
	$init($Krb5Util);
	Krb5MechFactory::DEBUG = $Krb5Util::DEBUG;
	$assignStatic(Krb5MechFactory::PROVIDER, $new($SunProvider));
	$assignStatic(Krb5MechFactory::GSS_KRB5_MECH_OID, Krb5MechFactory::createOid("1.2.840.113554.1.2.2"_s));
	$assignStatic(Krb5MechFactory::NT_GSS_KRB5_PRINCIPAL, Krb5MechFactory::createOid("1.2.840.113554.1.2.2.1"_s));
		$init($GSSName);
	$assignStatic(Krb5MechFactory::nameTypes, $new($OidArray, {
		$GSSName::NT_USER_NAME,
		$GSSName::NT_HOSTBASED_SERVICE,
		$GSSName::NT_EXPORT_NAME,
		Krb5MechFactory::NT_GSS_KRB5_PRINCIPAL
	}));
}

Krb5MechFactory::Krb5MechFactory() {
}

$Class* Krb5MechFactory::load$($String* name, bool initialize) {
	$loadClass(Krb5MechFactory, name, initialize, &_Krb5MechFactory_ClassInfo_, clinit$Krb5MechFactory, allocate$Krb5MechFactory);
	return class$;
}

$Class* Krb5MechFactory::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun