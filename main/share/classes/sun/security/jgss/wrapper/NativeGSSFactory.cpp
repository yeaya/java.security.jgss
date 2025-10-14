#include <sun/security/jgss/wrapper/NativeGSSFactory.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/Provider.h>
#include <java/util/Vector.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/spi/GSSContextSpi.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/wrapper/GSSCredElement.h>
#include <sun/security/jgss/wrapper/GSSLibStub.h>
#include <sun/security/jgss/wrapper/GSSNameElement.h>
#include <sun/security/jgss/wrapper/NativeGSSContext.h>
#include <sun/security/jgss/wrapper/SunNativeProvider.h>
#include <jcpp.h>

#undef ACCEPT_ONLY
#undef BAD_NAME
#undef DEF_ACCEPTOR
#undef FAILURE
#undef INITIATE_AND_ACCEPT
#undef INITIATE_ONLY
#undef INSTANCE
#undef NO_CRED
#undef UTF_8

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Provider = ::java::security::Provider;
using $Vector = ::java::util::Vector;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $GSSContextSpi = ::sun::security::jgss::spi::GSSContextSpi;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $MechanismFactory = ::sun::security::jgss::spi::MechanismFactory;
using $GSSCredElement = ::sun::security::jgss::wrapper::GSSCredElement;
using $GSSLibStub = ::sun::security::jgss::wrapper::GSSLibStub;
using $GSSNameElement = ::sun::security::jgss::wrapper::GSSNameElement;
using $NativeGSSContext = ::sun::security::jgss::wrapper::NativeGSSContext;
using $SunNativeProvider = ::sun::security::jgss::wrapper::SunNativeProvider;

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

$FieldInfo _NativeGSSFactory_FieldInfo_[] = {
	{"cStub", "Lsun/security/jgss/wrapper/GSSLibStub;", nullptr, 0, $field(NativeGSSFactory, cStub)},
	{"caller", "Lsun/security/jgss/GSSCaller;", nullptr, $PRIVATE | $FINAL, $field(NativeGSSFactory, caller)},
	{}
};

$MethodInfo _NativeGSSFactory_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/GSSCaller;)V", nullptr, $PUBLIC, $method(static_cast<void(NativeGSSFactory::*)($GSSCaller*)>(&NativeGSSFactory::init$))},
	{"getCredFromSubject", "(Lsun/security/jgss/wrapper/GSSNameElement;Z)Lsun/security/jgss/wrapper/GSSCredElement;", nullptr, $PRIVATE, $method(static_cast<$GSSCredElement*(NativeGSSFactory::*)($GSSNameElement*,bool)>(&NativeGSSFactory::getCredFromSubject)), "org.ietf.jgss.GSSException"},
	{"getCredentialElement", "(Lsun/security/jgss/spi/GSSNameSpi;III)Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismContext", "(Lsun/security/jgss/spi/GSSNameSpi;Lsun/security/jgss/spi/GSSCredentialSpi;I)Lsun/security/jgss/spi/GSSContextSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismContext", "(Lsun/security/jgss/spi/GSSCredentialSpi;)Lsun/security/jgss/spi/GSSContextSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismContext", "([B)Lsun/security/jgss/spi/GSSContextSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanismOid", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $FINAL},
	{"getNameElement", "(Ljava/lang/String;Lorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getNameElement", "([BLorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getNameTypes", "()[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC},
	{"setMech", "(Lorg/ietf/jgss/Oid;)V", nullptr, $PUBLIC, $method(static_cast<void(NativeGSSFactory::*)($Oid*)>(&NativeGSSFactory::setMech)), "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _NativeGSSFactory_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.jgss.wrapper.NativeGSSFactory",
	"java.lang.Object",
	"sun.security.jgss.spi.MechanismFactory",
	_NativeGSSFactory_FieldInfo_,
	_NativeGSSFactory_MethodInfo_
};

$Object* allocate$NativeGSSFactory($Class* clazz) {
	return $of($alloc(NativeGSSFactory));
}

$GSSCredElement* NativeGSSFactory::getCredFromSubject($GSSNameElement* name, bool initiate) {
	$var($Oid, mech, $nc(this->cStub)->getMech());
	$load($GSSCredElement);
	$var($Vector, creds, $GSSUtil::searchSubject(name, mech, initiate, $GSSCredElement::class$));
	if (creds != nullptr && creds->isEmpty()) {
		if ($GSSUtil::useSubjectCredsOnly(this->caller)) {
			$throwNew($GSSException, $GSSException::NO_CRED);
		}
	}
	$var($GSSCredElement, result, (creds == nullptr || $nc(creds)->isEmpty()) ? ($GSSCredElement*)nullptr : $cast($GSSCredElement, $nc(creds)->firstElement()));
	if (result != nullptr) {
		result->doServicePermCheck();
	}
	return result;
}

void NativeGSSFactory::init$($GSSCaller* caller) {
	$set(this, cStub, nullptr);
	$set(this, caller, caller);
}

void NativeGSSFactory::setMech($Oid* mech) {
	$set(this, cStub, $GSSLibStub::getInstance(mech));
}

$GSSNameSpi* NativeGSSFactory::getNameElement($String* nameStr, $Oid* nameType) {
	$init($StandardCharsets);
	$var($bytes, nameBytes, nameStr == nullptr ? ($bytes*)nullptr : $nc(nameStr)->getBytes($StandardCharsets::UTF_8));
	return $new($GSSNameElement, nameBytes, nameType, this->cStub);
}

$GSSNameSpi* NativeGSSFactory::getNameElement($bytes* name, $Oid* nameType) {
	return $new($GSSNameElement, name, nameType, this->cStub);
}

$GSSCredentialSpi* NativeGSSFactory::getCredentialElement($GSSNameSpi* name, int32_t initLifetime, int32_t acceptLifetime, int32_t usage) {
	$var($GSSNameElement, nname, nullptr);
	if (name != nullptr && !($instanceOf($GSSNameElement, name))) {
		$var($String, var$0, name->toString());
		$assign(nname, $cast($GSSNameElement, getNameElement(var$0, $(name->getStringNameType()))));
	} else {
		$assign(nname, $cast($GSSNameElement, name));
	}
	if (usage == $GSSCredential::INITIATE_AND_ACCEPT) {
		usage = $GSSCredential::INITIATE_ONLY;
	}
	$var($GSSCredElement, credElement, getCredFromSubject(nname, (usage == $GSSCredential::INITIATE_ONLY)));
	if (credElement == nullptr) {
		if (usage == $GSSCredential::INITIATE_ONLY) {
			$assign(credElement, $new($GSSCredElement, nname, initLifetime, usage, this->cStub));
		} else if (usage == $GSSCredential::ACCEPT_ONLY) {
			if (nname == nullptr) {
				$init($GSSNameElement);
				$assign(nname, $GSSNameElement::DEF_ACCEPTOR);
			}
			$assign(credElement, $new($GSSCredElement, nname, acceptLifetime, usage, this->cStub));
		} else {
			$throwNew($GSSException, $GSSException::FAILURE, -1, "Unknown usage mode requested"_s);
		}
	}
	return credElement;
}

$GSSContextSpi* NativeGSSFactory::getMechanismContext($GSSNameSpi* peer$renamed, $GSSCredentialSpi* myCred$renamed, int32_t lifetime) {
	$var($GSSCredentialSpi, myCred, myCred$renamed);
	$var($GSSNameSpi, peer, peer$renamed);
	if (peer == nullptr) {
		$throwNew($GSSException, $GSSException::BAD_NAME);
	} else if (!($instanceOf($GSSNameElement, peer))) {
		$var($String, var$0, $nc(peer)->toString());
		$assign(peer, $cast($GSSNameElement, getNameElement(var$0, $(peer->getStringNameType()))));
	}
	if (myCred == nullptr) {
		$assign(myCred, getCredFromSubject(nullptr, true));
	} else if (!($instanceOf($GSSCredElement, myCred))) {
		$throwNew($GSSException, $GSSException::NO_CRED);
	}
	return $new($NativeGSSContext, $cast($GSSNameElement, peer), $cast($GSSCredElement, myCred), lifetime, this->cStub);
}

$GSSContextSpi* NativeGSSFactory::getMechanismContext($GSSCredentialSpi* myCred$renamed) {
	$var($GSSCredentialSpi, myCred, myCred$renamed);
	if (myCred == nullptr) {
		$assign(myCred, getCredFromSubject(nullptr, false));
	} else if (!($instanceOf($GSSCredElement, myCred))) {
		$throwNew($GSSException, $GSSException::NO_CRED);
	}
	return $new($NativeGSSContext, $cast($GSSCredElement, myCred), this->cStub);
}

$GSSContextSpi* NativeGSSFactory::getMechanismContext($bytes* exportedContext) {
	return $nc(this->cStub)->importContext(exportedContext);
}

$Oid* NativeGSSFactory::getMechanismOid() {
	return $nc(this->cStub)->getMech();
}

$Provider* NativeGSSFactory::getProvider() {
	$init($SunNativeProvider);
	return $SunNativeProvider::INSTANCE;
}

$OidArray* NativeGSSFactory::getNameTypes() {
	return $nc(this->cStub)->inquireNamesForMech();
}

NativeGSSFactory::NativeGSSFactory() {
}

$Class* NativeGSSFactory::load$($String* name, bool initialize) {
	$loadClass(NativeGSSFactory, name, initialize, &_NativeGSSFactory_ClassInfo_, allocate$NativeGSSFactory);
	return class$;
}

$Class* NativeGSSFactory::class$ = nullptr;

			} // wrapper
		} // jgss
	} // security
} // sun