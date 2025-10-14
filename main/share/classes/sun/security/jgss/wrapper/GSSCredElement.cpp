#include <sun/security/jgss/wrapper/GSSCredElement.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/wrapper/GSSLibStub.h>
#include <sun/security/jgss/wrapper/GSSNameElement.h>
#include <sun/security/jgss/wrapper/Krb5Util.h>
#include <sun/security/jgss/wrapper/SunNativeProvider.h>
#include <jcpp.h>

#undef ACCEPT_ONLY
#undef DEF_ACCEPTOR
#undef FAILURE
#undef INITIATE_ONLY
#undef INSTANCE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $Provider = ::java::security::Provider;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $GSSLibStub = ::sun::security::jgss::wrapper::GSSLibStub;
using $GSSNameElement = ::sun::security::jgss::wrapper::GSSNameElement;
using $Krb5Util = ::sun::security::jgss::wrapper::Krb5Util;
using $SunNativeProvider = ::sun::security::jgss::wrapper::SunNativeProvider;

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

$FieldInfo _GSSCredElement_FieldInfo_[] = {
	{"usage", "I", nullptr, $PRIVATE, $field(GSSCredElement, usage)},
	{"pCred", "J", nullptr, 0, $field(GSSCredElement, pCred)},
	{"name", "Lsun/security/jgss/wrapper/GSSNameElement;", nullptr, $PRIVATE, $field(GSSCredElement, name)},
	{"cStub", "Lsun/security/jgss/wrapper/GSSLibStub;", nullptr, $PRIVATE, $field(GSSCredElement, cStub)},
	{}
};

$MethodInfo _GSSCredElement_MethodInfo_[] = {
	{"<init>", "(JLsun/security/jgss/wrapper/GSSNameElement;Lorg/ietf/jgss/Oid;)V", nullptr, 0, $method(static_cast<void(GSSCredElement::*)(int64_t,$GSSNameElement*,$Oid*)>(&GSSCredElement::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/wrapper/GSSNameElement;IILsun/security/jgss/wrapper/GSSLibStub;)V", nullptr, 0, $method(static_cast<void(GSSCredElement::*)($GSSNameElement*,int32_t,int32_t,$GSSLibStub*)>(&GSSCredElement::init$)), "org.ietf.jgss.GSSException"},
	{"dispose", "()V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"doServicePermCheck", "()V", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"finalize", "()V", nullptr, $PROTECTED, nullptr, "java.lang.Throwable"},
	{"getAcceptLifetime", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getInitLifetime", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanism", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getName", "()Lsun/security/jgss/wrapper/GSSNameElement;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC},
	{"impersonate", "(Lsun/security/jgss/spi/GSSNameSpi;)Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isAcceptorCredential", "()Z", nullptr, $PUBLIC},
	{"isInitiatorCredential", "()Z", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _GSSCredElement_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.wrapper.GSSCredElement",
	"java.lang.Object",
	"sun.security.jgss.spi.GSSCredentialSpi",
	_GSSCredElement_FieldInfo_,
	_GSSCredElement_MethodInfo_
};

$Object* allocate$GSSCredElement($Class* clazz) {
	return $of($alloc(GSSCredElement));
}

void GSSCredElement::doServicePermCheck() {
	if ($GSSUtil::isKerberosMech($($nc(this->cStub)->getMech()))) {
		if ($System::getSecurityManager() != nullptr) {
			if (isInitiatorCredential()) {
				$var($String, tgsName, $Krb5Util::getTGSName(this->name));
				$Krb5Util::checkServicePermission(tgsName, "initiate"_s);
			}
			$init($GSSNameElement);
			if (isAcceptorCredential() && this->name != $GSSNameElement::DEF_ACCEPTOR) {
				$var($String, krbName, $nc(this->name)->getKrbName());
				$Krb5Util::checkServicePermission(krbName, "accept"_s);
			}
		}
	}
}

void GSSCredElement::init$(int64_t pCredentials, $GSSNameElement* srcName, $Oid* mech) {
	$set(this, name, nullptr);
	this->pCred = pCredentials;
	$set(this, cStub, $GSSLibStub::getInstance(mech));
	this->usage = $GSSCredential::INITIATE_ONLY;
	$set(this, name, srcName);
}

void GSSCredElement::init$($GSSNameElement* name, int32_t lifetime, int32_t usage, $GSSLibStub* stub) {
	$set(this, name, nullptr);
	$set(this, cStub, stub);
	this->usage = usage;
	if (name != nullptr) {
		$set(this, name, name);
		doServicePermCheck();
		this->pCred = $nc(this->cStub)->acquireCred($nc(this->name)->pName, lifetime, usage);
	} else {
		this->pCred = $nc(this->cStub)->acquireCred(0, lifetime, usage);
		$set(this, name, $new($GSSNameElement, $nc(this->cStub)->getCredName(this->pCred), this->cStub));
		doServicePermCheck();
	}
}

$Provider* GSSCredElement::getProvider() {
	$init($SunNativeProvider);
	return $SunNativeProvider::INSTANCE;
}

void GSSCredElement::dispose() {
	$set(this, name, nullptr);
	if (this->pCred != 0) {
		this->pCred = $nc(this->cStub)->releaseCred(this->pCred);
	}
}

$GSSNameSpi* GSSCredElement::getName() {
	$init($GSSNameElement);
	return ((this->name == $GSSNameElement::DEF_ACCEPTOR ? ($GSSNameElement*)nullptr : this->name));
}

int32_t GSSCredElement::getInitLifetime() {
	if (isInitiatorCredential()) {
		return $nc(this->cStub)->getCredTime(this->pCred);
	} else {
		return 0;
	}
}

int32_t GSSCredElement::getAcceptLifetime() {
	if (isAcceptorCredential()) {
		return $nc(this->cStub)->getCredTime(this->pCred);
	} else {
		return 0;
	}
}

bool GSSCredElement::isInitiatorCredential() {
	return (this->usage != $GSSCredential::ACCEPT_ONLY);
}

bool GSSCredElement::isAcceptorCredential() {
	return (this->usage != $GSSCredential::INITIATE_ONLY);
}

$Oid* GSSCredElement::getMechanism() {
	return $nc(this->cStub)->getMech();
}

$String* GSSCredElement::toString() {
	return "N/A"_s;
}

void GSSCredElement::finalize() {
	dispose();
}

$GSSCredentialSpi* GSSCredElement::impersonate($GSSNameSpi* name) {
	$throwNew($GSSException, $GSSException::FAILURE, -1, "Not supported yet"_s);
	$shouldNotReachHere();
}

GSSCredElement::GSSCredElement() {
}

$Class* GSSCredElement::load$($String* name, bool initialize) {
	$loadClass(GSSCredElement, name, initialize, &_GSSCredElement_ClassInfo_, allocate$GSSCredElement);
	return class$;
}

$Class* GSSCredElement::class$ = nullptr;

			} // wrapper
		} // jgss
	} // security
} // sun