#include <sun/security/jgss/spnego/SpNegoCredElement.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/spnego/SpNegoMechFactory.h>
#include <jcpp.h>

#undef GSS_SPNEGO_MECH_OID
#undef PROVIDER

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $SpNegoMechFactory = ::sun::security::jgss::spnego::SpNegoMechFactory;

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

$FieldInfo _SpNegoCredElement_FieldInfo_[] = {
	{"cred", "Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PRIVATE, $field(SpNegoCredElement, cred)},
	{}
};

$MethodInfo _SpNegoCredElement_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/spi/GSSCredentialSpi;)V", nullptr, $PUBLIC, $method(static_cast<void(SpNegoCredElement::*)($GSSCredentialSpi*)>(&SpNegoCredElement::init$)), "org.ietf.jgss.GSSException"},
	{"dispose", "()V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getAcceptLifetime", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getInitLifetime", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getInternalCred", "()Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC},
	{"getInternalMech", "()Lorg/ietf/jgss/Oid;", nullptr, 0},
	{"getMechanism", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getName", "()Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC},
	{"impersonate", "(Lsun/security/jgss/spi/GSSNameSpi;)Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isAcceptorCredential", "()Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isInitiatorCredential", "()Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _SpNegoCredElement_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.spnego.SpNegoCredElement",
	"java.lang.Object",
	"sun.security.jgss.spi.GSSCredentialSpi",
	_SpNegoCredElement_FieldInfo_,
	_SpNegoCredElement_MethodInfo_
};

$Object* allocate$SpNegoCredElement($Class* clazz) {
	return $of($alloc(SpNegoCredElement));
}

void SpNegoCredElement::init$($GSSCredentialSpi* cred) {
	$set(this, cred, nullptr);
	$set(this, cred, cred);
}

$Oid* SpNegoCredElement::getInternalMech() {
	return $nc(this->cred)->getMechanism();
}

$GSSCredentialSpi* SpNegoCredElement::getInternalCred() {
	return this->cred;
}

$Provider* SpNegoCredElement::getProvider() {
	$init($SpNegoMechFactory);
	return $SpNegoMechFactory::PROVIDER;
}

void SpNegoCredElement::dispose() {
	$nc(this->cred)->dispose();
}

$GSSNameSpi* SpNegoCredElement::getName() {
	return $nc(this->cred)->getName();
}

int32_t SpNegoCredElement::getInitLifetime() {
	return $nc(this->cred)->getInitLifetime();
}

int32_t SpNegoCredElement::getAcceptLifetime() {
	return $nc(this->cred)->getAcceptLifetime();
}

bool SpNegoCredElement::isInitiatorCredential() {
	return $nc(this->cred)->isInitiatorCredential();
}

bool SpNegoCredElement::isAcceptorCredential() {
	return $nc(this->cred)->isAcceptorCredential();
}

$Oid* SpNegoCredElement::getMechanism() {
	$init($GSSUtil);
	return $GSSUtil::GSS_SPNEGO_MECH_OID;
}

$GSSCredentialSpi* SpNegoCredElement::impersonate($GSSNameSpi* name) {
	return $nc(this->cred)->impersonate(name);
}

SpNegoCredElement::SpNegoCredElement() {
}

$Class* SpNegoCredElement::load$($String* name, bool initialize) {
	$loadClass(SpNegoCredElement, name, initialize, &_SpNegoCredElement_ClassInfo_, allocate$SpNegoCredElement);
	return class$;
}

$Class* SpNegoCredElement::class$ = nullptr;

			} // spnego
		} // jgss
	} // security
} // sun