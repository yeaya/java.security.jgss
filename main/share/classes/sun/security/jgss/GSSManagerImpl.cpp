#include <sun/security/jgss/GSSManagerImpl.h>

#include <java/lang/Array.h>
#include <java/lang/Boolean.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/GSSContext.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSManager.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSContextImpl.h>
#include <sun/security/jgss/GSSCredentialImpl.h>
#include <sun/security/jgss/GSSNameImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/JgssExtender.h>
#include <sun/security/jgss/ProviderList.h>
#include <sun/security/jgss/spi/GSSContextSpi.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/spi/MechanismFactory.h>
#include <jcpp.h>

#undef CALLER_UNKNOWN
#undef NO_CONTEXT
#undef NT_HOSTBASED_SERVICE
#undef UNAVAILABLE
#undef USE_NATIVE

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $GSSContext = ::org::ietf::jgss::GSSContext;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSManager = ::org::ietf::jgss::GSSManager;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $GSSContextImpl = ::sun::security::jgss::GSSContextImpl;
using $GSSCredentialImpl = ::sun::security::jgss::GSSCredentialImpl;
using $GSSNameImpl = ::sun::security::jgss::GSSNameImpl;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $JgssExtender = ::sun::security::jgss::JgssExtender;
using $ProviderList = ::sun::security::jgss::ProviderList;
using $GSSContextSpi = ::sun::security::jgss::spi::GSSContextSpi;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $MechanismFactory = ::sun::security::jgss::spi::MechanismFactory;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _GSSManagerImpl_FieldInfo_[] = {
	{"USE_NATIVE", "Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GSSManagerImpl, USE_NATIVE)},
	{"list", "Lsun/security/jgss/ProviderList;", nullptr, $PRIVATE, $field(GSSManagerImpl, list)},
	{}
};

$MethodInfo _GSSManagerImpl_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/GSSCaller;Z)V", nullptr, $PUBLIC, $method(static_cast<void(GSSManagerImpl::*)($GSSCaller*,bool)>(&GSSManagerImpl::init$))},
	{"<init>", "(Lsun/security/jgss/GSSCaller;)V", nullptr, $PUBLIC, $method(static_cast<void(GSSManagerImpl::*)($GSSCaller*)>(&GSSManagerImpl::init$))},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(GSSManagerImpl::*)()>(&GSSManagerImpl::init$))},
	{"addProviderAtEnd", "(Ljava/security/Provider;Lorg/ietf/jgss/Oid;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"addProviderAtFront", "(Ljava/security/Provider;Lorg/ietf/jgss/Oid;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createContext", "(Lorg/ietf/jgss/GSSName;Lorg/ietf/jgss/Oid;Lorg/ietf/jgss/GSSCredential;I)Lorg/ietf/jgss/GSSContext;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createContext", "(Lorg/ietf/jgss/GSSCredential;)Lorg/ietf/jgss/GSSContext;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createContext", "([B)Lorg/ietf/jgss/GSSContext;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createCredential", "(I)Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createCredential", "(Lorg/ietf/jgss/GSSName;ILorg/ietf/jgss/Oid;I)Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createCredential", "(Lorg/ietf/jgss/GSSName;I[Lorg/ietf/jgss/Oid;I)Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createName", "(Ljava/lang/String;Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createName", "([BLorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createName", "(Ljava/lang/String;Lorg/ietf/jgss/Oid;Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"createName", "([BLorg/ietf/jgss/Oid;Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getCredentialElement", "(Lsun/security/jgss/spi/GSSNameSpi;IILorg/ietf/jgss/Oid;I)Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismContext", "(Lsun/security/jgss/spi/GSSNameSpi;Lsun/security/jgss/spi/GSSCredentialSpi;ILorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/GSSContextSpi;", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismContext", "(Lsun/security/jgss/spi/GSSCredentialSpi;Lorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/GSSContextSpi;", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismContext", "([B)Lsun/security/jgss/spi/GSSContextSpi;", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechs", "()[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getMechsForName", "(Lorg/ietf/jgss/Oid;)[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getNameElement", "(Ljava/lang/String;Lorg/ietf/jgss/Oid;Lorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getNameElement", "([BLorg/ietf/jgss/Oid;Lorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getNamesForMech", "(Lorg/ietf/jgss/Oid;)[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "(Lsun/security/jgss/GSSCredentialImpl;)Lorg/ietf/jgss/GSSCredential;", nullptr, $STATIC, $method(static_cast<$GSSCredential*(*)($GSSCredentialImpl*)>(&GSSManagerImpl::wrap))},
	{"wrap", "(Lsun/security/jgss/GSSContextImpl;)Lorg/ietf/jgss/GSSContext;", nullptr, $STATIC, $method(static_cast<$GSSContext*(*)($GSSContextImpl*)>(&GSSManagerImpl::wrap))},
	{}
};

$ClassInfo _GSSManagerImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.GSSManagerImpl",
	"org.ietf.jgss.GSSManager",
	nullptr,
	_GSSManagerImpl_FieldInfo_,
	_GSSManagerImpl_MethodInfo_
};

$Object* allocate$GSSManagerImpl($Class* clazz) {
	return $of($alloc(GSSManagerImpl));
}

$Boolean* GSSManagerImpl::USE_NATIVE = nullptr;

void GSSManagerImpl::init$($GSSCaller* caller, bool useNative) {
	$GSSManager::init$();
	$set(this, list, $new($ProviderList, caller, useNative));
}

void GSSManagerImpl::init$($GSSCaller* caller) {
	$GSSManager::init$();
	$set(this, list, $new($ProviderList, caller, $nc(GSSManagerImpl::USE_NATIVE)->booleanValue()));
}

void GSSManagerImpl::init$() {
	$GSSManager::init$();
	$init($GSSCaller);
	$set(this, list, $new($ProviderList, $GSSCaller::CALLER_UNKNOWN, $nc(GSSManagerImpl::USE_NATIVE)->booleanValue()));
}

$OidArray* GSSManagerImpl::getMechs() {
	return $nc(this->list)->getMechs();
}

$OidArray* GSSManagerImpl::getNamesForMech($Oid* mech) {
	$var($MechanismFactory, factory, $nc(this->list)->getMechFactory(mech));
	return $cast($OidArray, $nc($($nc(factory)->getNameTypes()))->clone());
}

$OidArray* GSSManagerImpl::getMechsForName($Oid* nameType$renamed) {
	$var($Oid, nameType, nameType$renamed);
	$var($OidArray, mechs, $nc(this->list)->getMechs());
	$var($OidArray, retVal, $new($OidArray, $nc(mechs)->length));
	int32_t pos = 0;
	$init($GSSNameImpl);
	if ($nc(nameType)->equals($GSSNameImpl::oldHostbasedServiceName)) {
		$init($GSSName);
		$assign(nameType, $GSSName::NT_HOSTBASED_SERVICE);
	}
	for (int32_t i = 0; i < mechs->length; ++i) {
		$var($Oid, mech, mechs->get(i));
		try {
			$var($OidArray, namesForMech, getNamesForMech(mech));
			if ($nc(nameType)->containedIn(namesForMech)) {
				retVal->set(pos++, mech);
			}
		} catch ($GSSException&) {
			$var($GSSException, e, $catch());
			$GSSUtil::debug($$str({"Skip "_s, mech, ": error retrieving supported name types"_s}));
		}
	}
	if (pos < retVal->length) {
		$var($OidArray, temp, $new($OidArray, pos));
		for (int32_t i = 0; i < pos; ++i) {
			temp->set(i, retVal->get(i));
		}
		$assign(retVal, temp);
	}
	return retVal;
}

$GSSName* GSSManagerImpl::createName($String* nameStr, $Oid* nameType) {
	return $new($GSSNameImpl, this, nameStr, nameType);
}

$GSSName* GSSManagerImpl::createName($bytes* name, $Oid* nameType) {
	return $new($GSSNameImpl, this, name, nameType);
}

$GSSName* GSSManagerImpl::createName($String* nameStr, $Oid* nameType, $Oid* mech) {
	return $new($GSSNameImpl, this, nameStr, nameType, mech);
}

$GSSName* GSSManagerImpl::createName($bytes* name, $Oid* nameType, $Oid* mech) {
	return $new($GSSNameImpl, this, name, nameType, mech);
}

$GSSCredential* GSSManagerImpl::createCredential(int32_t usage) {
	return wrap($$new($GSSCredentialImpl, this, usage));
}

$GSSCredential* GSSManagerImpl::createCredential($GSSName* aName, int32_t lifetime, $Oid* mech, int32_t usage) {
	return wrap($$new($GSSCredentialImpl, this, aName, lifetime, mech, usage));
}

$GSSCredential* GSSManagerImpl::createCredential($GSSName* aName, int32_t lifetime, $OidArray* mechs, int32_t usage) {
	return wrap($$new($GSSCredentialImpl, this, aName, lifetime, mechs, usage));
}

$GSSContext* GSSManagerImpl::createContext($GSSName* peer, $Oid* mech, $GSSCredential* myCred, int32_t lifetime) {
	return wrap($$new($GSSContextImpl, this, peer, mech, myCred, lifetime));
}

$GSSContext* GSSManagerImpl::createContext($GSSCredential* myCred) {
	return wrap($$new($GSSContextImpl, this, myCred));
}

$GSSContext* GSSManagerImpl::createContext($bytes* interProcessToken) {
	return wrap($$new($GSSContextImpl, this, interProcessToken));
}

void GSSManagerImpl::addProviderAtFront($Provider* p, $Oid* mech) {
	$nc(this->list)->addProviderAtFront(p, mech);
}

void GSSManagerImpl::addProviderAtEnd($Provider* p, $Oid* mech) {
	$nc(this->list)->addProviderAtEnd(p, mech);
}

$GSSCredentialSpi* GSSManagerImpl::getCredentialElement($GSSNameSpi* name, int32_t initLifetime, int32_t acceptLifetime, $Oid* mech, int32_t usage) {
	$var($MechanismFactory, factory, $nc(this->list)->getMechFactory(mech));
	return $nc(factory)->getCredentialElement(name, initLifetime, acceptLifetime, usage);
}

$GSSNameSpi* GSSManagerImpl::getNameElement($String* name, $Oid* nameType, $Oid* mech) {
	$var($MechanismFactory, factory, $nc(this->list)->getMechFactory(mech));
	return $nc(factory)->getNameElement(name, nameType);
}

$GSSNameSpi* GSSManagerImpl::getNameElement($bytes* name, $Oid* nameType, $Oid* mech) {
	$var($MechanismFactory, factory, $nc(this->list)->getMechFactory(mech));
	return $nc(factory)->getNameElement(name, nameType);
}

$GSSContextSpi* GSSManagerImpl::getMechanismContext($GSSNameSpi* peer, $GSSCredentialSpi* myInitiatorCred, int32_t lifetime, $Oid* mech) {
	$var($Provider, p, nullptr);
	if (myInitiatorCred != nullptr) {
		$assign(p, myInitiatorCred->getProvider());
	}
	$var($MechanismFactory, factory, $nc(this->list)->getMechFactory(mech, p));
	return $nc(factory)->getMechanismContext(peer, myInitiatorCred, lifetime);
}

$GSSContextSpi* GSSManagerImpl::getMechanismContext($GSSCredentialSpi* myAcceptorCred, $Oid* mech) {
	$var($Provider, p, nullptr);
	if (myAcceptorCred != nullptr) {
		$assign(p, myAcceptorCred->getProvider());
	}
	$var($MechanismFactory, factory, $nc(this->list)->getMechFactory(mech, p));
	return $nc(factory)->getMechanismContext(myAcceptorCred);
}

$GSSContextSpi* GSSManagerImpl::getMechanismContext($bytes* exportedContext) {
	if ((exportedContext == nullptr) || ($nc(exportedContext)->length == 0)) {
		$throwNew($GSSException, $GSSException::NO_CONTEXT);
	}
	$var($GSSContextSpi, result, nullptr);
	$var($OidArray, mechs, $nc(this->list)->getMechs());
	for (int32_t i = 0; i < $nc(mechs)->length; ++i) {
		$var($MechanismFactory, factory, $nc(this->list)->getMechFactory(mechs->get(i)));
		if ($nc($($nc($($nc(factory)->getProvider()))->getName()))->equals("SunNativeGSS"_s)) {
			$assign(result, factory->getMechanismContext(exportedContext));
			if (result != nullptr) {
				break;
			}
		}
	}
	if (result == nullptr) {
		$throwNew($GSSException, $GSSException::UNAVAILABLE);
	}
	return result;
}

$GSSCredential* GSSManagerImpl::wrap($GSSCredentialImpl* cred) {
	$init(GSSManagerImpl);
	return $nc($($JgssExtender::getExtender()))->wrap(static_cast<$GSSCredential*>(cred));
}

$GSSContext* GSSManagerImpl::wrap($GSSContextImpl* ctxt) {
	$init(GSSManagerImpl);
	return $nc($($JgssExtender::getExtender()))->wrap(static_cast<$GSSContext*>(ctxt));
}

void clinit$GSSManagerImpl($Class* class$) {
	$beforeCallerSensitive();
	$assignStatic(GSSManagerImpl::USE_NATIVE, $Boolean::valueOf($GetBooleanAction::privilegedGetProperty("sun.security.jgss.native"_s)));
	{
		try {
			$Class::forName("com.sun.security.jgss.Extender"_s);
		} catch ($Exception&) {
			$catch();
		}
	}
}

GSSManagerImpl::GSSManagerImpl() {
}

$Class* GSSManagerImpl::load$($String* name, bool initialize) {
	$loadClass(GSSManagerImpl, name, initialize, &_GSSManagerImpl_ClassInfo_, clinit$GSSManagerImpl, allocate$GSSManagerImpl);
	return class$;
}

$Class* GSSManagerImpl::class$ = nullptr;

		} // jgss
	} // security
} // sun