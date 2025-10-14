#include <sun/security/jgss/spnego/SpNegoMechFactory.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <java/util/Vector.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSManagerImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/ProviderList.h>
#include <sun/security/jgss/SunProvider.h>
#include <sun/security/jgss/krb5/Krb5AcceptCredential.h>
#include <sun/security/jgss/krb5/Krb5InitCredential.h>
#include <sun/security/jgss/krb5/Krb5MechFactory.h>
#include <sun/security/jgss/krb5/Krb5NameElement.h>
#include <sun/security/jgss/spi/GSSContextSpi.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/spnego/SpNegoContext.h>
#include <sun/security/jgss/spnego/SpNegoCredElement.h>
#include <jcpp.h>

#undef ACCEPT_ONLY
#undef CALLER_UNKNOWN
#undef DEFAULT_MECH_OID
#undef DEFAULT_SPNEGO_MECH_OID
#undef GSS_KRB5_MECH_OID
#undef GSS_SPNEGO_MECH_OID
#undef NT_EXPORT_NAME
#undef NT_HOSTBASED_SERVICE
#undef NT_USER_NAME
#undef PROVIDER

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $Vector = ::java::util::Vector;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $GSSManagerImpl = ::sun::security::jgss::GSSManagerImpl;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $ProviderList = ::sun::security::jgss::ProviderList;
using $SunProvider = ::sun::security::jgss::SunProvider;
using $Krb5AcceptCredential = ::sun::security::jgss::krb5::Krb5AcceptCredential;
using $Krb5InitCredential = ::sun::security::jgss::krb5::Krb5InitCredential;
using $Krb5MechFactory = ::sun::security::jgss::krb5::Krb5MechFactory;
using $Krb5NameElement = ::sun::security::jgss::krb5::Krb5NameElement;
using $GSSContextSpi = ::sun::security::jgss::spi::GSSContextSpi;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $MechanismFactory = ::sun::security::jgss::spi::MechanismFactory;
using $SpNegoContext = ::sun::security::jgss::spnego::SpNegoContext;
using $SpNegoCredElement = ::sun::security::jgss::spnego::SpNegoCredElement;

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

$FieldInfo _SpNegoMechFactory_FieldInfo_[] = {
	{"PROVIDER", "Ljava/security/Provider;", nullptr, $STATIC | $FINAL, $staticField(SpNegoMechFactory, PROVIDER)},
	{"GSS_SPNEGO_MECH_OID", "Lorg/ietf/jgss/Oid;", nullptr, $STATIC | $FINAL, $staticField(SpNegoMechFactory, GSS_SPNEGO_MECH_OID)},
	{"nameTypes", "[Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE | $STATIC, $staticField(SpNegoMechFactory, nameTypes)},
	{"DEFAULT_SPNEGO_MECH_OID", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SpNegoMechFactory, DEFAULT_SPNEGO_MECH_OID)},
	{"manager", "Lsun/security/jgss/GSSManagerImpl;", nullptr, $FINAL, $field(SpNegoMechFactory, manager)},
	{"availableMechs", "[Lorg/ietf/jgss/Oid;", nullptr, $FINAL, $field(SpNegoMechFactory, availableMechs)},
	{}
};

$MethodInfo _SpNegoMechFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SpNegoMechFactory::*)()>(&SpNegoMechFactory::init$))},
	{"<init>", "(Lsun/security/jgss/GSSCaller;)V", nullptr, $PUBLIC, $method(static_cast<void(SpNegoMechFactory::*)($GSSCaller*)>(&SpNegoMechFactory::init$))},
	{"getCredFromSubject", "(Lsun/security/jgss/spi/GSSNameSpi;Z)Lsun/security/jgss/spnego/SpNegoCredElement;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$SpNegoCredElement*(*)($GSSNameSpi*,bool)>(&SpNegoMechFactory::getCredFromSubject)), "org.ietf.jgss.GSSException"},
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

$ClassInfo _SpNegoMechFactory_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.jgss.spnego.SpNegoMechFactory",
	"java.lang.Object",
	"sun.security.jgss.spi.MechanismFactory",
	_SpNegoMechFactory_FieldInfo_,
	_SpNegoMechFactory_MethodInfo_
};

$Object* allocate$SpNegoMechFactory($Class* clazz) {
	return $of($alloc(SpNegoMechFactory));
}

$Provider* SpNegoMechFactory::PROVIDER = nullptr;
$Oid* SpNegoMechFactory::GSS_SPNEGO_MECH_OID = nullptr;
$OidArray* SpNegoMechFactory::nameTypes = nullptr;
$Oid* SpNegoMechFactory::DEFAULT_SPNEGO_MECH_OID = nullptr;

$SpNegoCredElement* SpNegoMechFactory::getCredFromSubject($GSSNameSpi* name, bool initiate) {
	$init(SpNegoMechFactory);
	$load($SpNegoCredElement);
	$var($Vector, creds, $GSSUtil::searchSubject(name, SpNegoMechFactory::GSS_SPNEGO_MECH_OID, initiate, $SpNegoCredElement::class$));
	$var($SpNegoCredElement, result, (creds == nullptr || $nc(creds)->isEmpty()) ? ($SpNegoCredElement*)nullptr : $cast($SpNegoCredElement, $nc(creds)->firstElement()));
	if (result != nullptr) {
		$var($GSSCredentialSpi, cred, result->getInternalCred());
		if ($GSSUtil::isKerberosMech($($nc(cred)->getMechanism()))) {
			if (initiate) {
				$var($Krb5InitCredential, krbCred, $cast($Krb5InitCredential, cred));
				$Krb5MechFactory::checkInitCredPermission($cast($Krb5NameElement, $($nc(krbCred)->getName())));
			} else {
				$var($Krb5AcceptCredential, krbCred, $cast($Krb5AcceptCredential, cred));
				$Krb5MechFactory::checkAcceptCredPermission($cast($Krb5NameElement, $($nc(krbCred)->getName())), name);
			}
		}
	}
	return result;
}

void SpNegoMechFactory::init$() {
	$init($GSSCaller);
	SpNegoMechFactory::init$($GSSCaller::CALLER_UNKNOWN);
}

void SpNegoMechFactory::init$($GSSCaller* caller) {
	$set(this, manager, $new($GSSManagerImpl, caller, false));
	$var($OidArray, mechs, $nc(this->manager)->getMechs());
	$set(this, availableMechs, $new($OidArray, $nc(mechs)->length - 1));
	{
		int32_t i = 0;
		int32_t j = 0;
		for (; i < mechs->length; ++i) {
			if (!$nc(mechs->get(i))->equals(SpNegoMechFactory::GSS_SPNEGO_MECH_OID)) {
				$nc(this->availableMechs)->set(j++, mechs->get(i));
			}
		}
	}
	for (int32_t i = 0; i < $nc(this->availableMechs)->length; ++i) {
		if ($nc($nc(this->availableMechs)->get(i))->equals(SpNegoMechFactory::DEFAULT_SPNEGO_MECH_OID)) {
			if (i != 0) {
				$nc(this->availableMechs)->set(i, $nc(this->availableMechs)->get(0));
				$nc(this->availableMechs)->set(0, SpNegoMechFactory::DEFAULT_SPNEGO_MECH_OID);
			}
			break;
		}
	}
}

$GSSNameSpi* SpNegoMechFactory::getNameElement($String* nameStr, $Oid* nameType) {
	return $nc(this->manager)->getNameElement(nameStr, nameType, SpNegoMechFactory::DEFAULT_SPNEGO_MECH_OID);
}

$GSSNameSpi* SpNegoMechFactory::getNameElement($bytes* name, $Oid* nameType) {
	return $nc(this->manager)->getNameElement(name, nameType, SpNegoMechFactory::DEFAULT_SPNEGO_MECH_OID);
}

$GSSCredentialSpi* SpNegoMechFactory::getCredentialElement($GSSNameSpi* name, int32_t initLifetime, int32_t acceptLifetime, int32_t usage) {
	$var($SpNegoCredElement, credElement, getCredFromSubject(name, (usage != $GSSCredential::ACCEPT_ONLY)));
	if (credElement == nullptr) {
		$assign(credElement, $new($SpNegoCredElement, $($nc(this->manager)->getCredentialElement(name, initLifetime, acceptLifetime, nullptr, usage))));
	}
	return credElement;
}

$GSSContextSpi* SpNegoMechFactory::getMechanismContext($GSSNameSpi* peer, $GSSCredentialSpi* myInitiatorCred$renamed, int32_t lifetime) {
	$var($GSSCredentialSpi, myInitiatorCred, myInitiatorCred$renamed);
	if (myInitiatorCred == nullptr) {
		$assign(myInitiatorCred, getCredFromSubject(nullptr, true));
	} else if (!($instanceOf($SpNegoCredElement, myInitiatorCred))) {
		$var($SpNegoCredElement, cred, $new($SpNegoCredElement, myInitiatorCred));
		return $new($SpNegoContext, this, peer, cred, lifetime);
	}
	return $new($SpNegoContext, this, peer, myInitiatorCred, lifetime);
}

$GSSContextSpi* SpNegoMechFactory::getMechanismContext($GSSCredentialSpi* myAcceptorCred$renamed) {
	$var($GSSCredentialSpi, myAcceptorCred, myAcceptorCred$renamed);
	if (myAcceptorCred == nullptr) {
		$assign(myAcceptorCred, getCredFromSubject(nullptr, false));
	} else if (!($instanceOf($SpNegoCredElement, myAcceptorCred))) {
		$var($SpNegoCredElement, cred, $new($SpNegoCredElement, myAcceptorCred));
		return $new($SpNegoContext, this, static_cast<$GSSCredentialSpi*>(cred));
	}
	return $new($SpNegoContext, this, myAcceptorCred);
}

$GSSContextSpi* SpNegoMechFactory::getMechanismContext($bytes* exportedContext) {
	return $new($SpNegoContext, this, exportedContext);
}

$Oid* SpNegoMechFactory::getMechanismOid() {
	return SpNegoMechFactory::GSS_SPNEGO_MECH_OID;
}

$Provider* SpNegoMechFactory::getProvider() {
	return SpNegoMechFactory::PROVIDER;
}

$OidArray* SpNegoMechFactory::getNameTypes() {
	return SpNegoMechFactory::nameTypes;
}

void clinit$SpNegoMechFactory($Class* class$) {
	$assignStatic(SpNegoMechFactory::PROVIDER, $new($SunProvider));
	$assignStatic(SpNegoMechFactory::GSS_SPNEGO_MECH_OID, $GSSUtil::createOid("1.3.6.1.5.5.2"_s));
		$init($GSSName);
	$assignStatic(SpNegoMechFactory::nameTypes, $new($OidArray, {
		$GSSName::NT_USER_NAME,
		$GSSName::NT_HOSTBASED_SERVICE,
		$GSSName::NT_EXPORT_NAME
	}));
	$init($ProviderList);
	$assignStatic(SpNegoMechFactory::DEFAULT_SPNEGO_MECH_OID, $nc($ProviderList::DEFAULT_MECH_OID)->equals(SpNegoMechFactory::GSS_SPNEGO_MECH_OID) ? $GSSUtil::GSS_KRB5_MECH_OID : $ProviderList::DEFAULT_MECH_OID);
}

SpNegoMechFactory::SpNegoMechFactory() {
}

$Class* SpNegoMechFactory::load$($String* name, bool initialize) {
	$loadClass(SpNegoMechFactory, name, initialize, &_SpNegoMechFactory_ClassInfo_, clinit$SpNegoMechFactory, allocate$SpNegoMechFactory);
	return class$;
}

$Class* SpNegoMechFactory::class$ = nullptr;

			} // spnego
		} // jgss
	} // security
} // sun