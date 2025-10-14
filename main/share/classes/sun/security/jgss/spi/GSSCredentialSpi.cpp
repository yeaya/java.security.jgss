#include <sun/security/jgss/spi/GSSCredentialSpi.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;

namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {

$MethodInfo _GSSCredentialSpi_MethodInfo_[] = {
	{"dispose", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getAcceptLifetime", "()I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getInitLifetime", "()I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanism", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT},
	{"getName", "()Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $ABSTRACT},
	{"impersonate", "(Lsun/security/jgss/spi/GSSNameSpi;)Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"isAcceptorCredential", "()Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"isInitiatorCredential", "()Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _GSSCredentialSpi_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.security.jgss.spi.GSSCredentialSpi",
	nullptr,
	nullptr,
	nullptr,
	_GSSCredentialSpi_MethodInfo_
};

$Object* allocate$GSSCredentialSpi($Class* clazz) {
	return $of($alloc(GSSCredentialSpi));
}

$Class* GSSCredentialSpi::load$($String* name, bool initialize) {
	$loadClass(GSSCredentialSpi, name, initialize, &_GSSCredentialSpi_ClassInfo_, allocate$GSSCredentialSpi);
	return class$;
}

$Class* GSSCredentialSpi::class$ = nullptr;

			} // spi
		} // jgss
	} // security
} // sun