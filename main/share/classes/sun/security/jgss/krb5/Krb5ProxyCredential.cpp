#include <sun/security/jgss/krb5/Krb5ProxyCredential.h>

#include <java/io/IOException.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <javax/security/auth/DestroyFailedException.h>
#include <javax/security/auth/kerberos/KerberosTicket.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/krb5/Krb5CredElement.h>
#include <sun/security/jgss/krb5/Krb5InitCredential.h>
#include <sun/security/jgss/krb5/Krb5MechFactory.h>
#include <sun/security/jgss/krb5/Krb5NameElement.h>
#include <sun/security/jgss/krb5/Krb5Util.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <jcpp.h>

#undef DEFECTIVE_CREDENTIAL
#undef FAILURE
#undef GSS_KRB5_MECH_OID
#undef PROVIDER

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $DestroyFailedException = ::javax::security::auth::DestroyFailedException;
using $KerberosTicket = ::javax::security::auth::kerberos::KerberosTicket;
using $GSSException = ::org::ietf::jgss::GSSException;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $Krb5CredElement = ::sun::security::jgss::krb5::Krb5CredElement;
using $Krb5InitCredential = ::sun::security::jgss::krb5::Krb5InitCredential;
using $Krb5MechFactory = ::sun::security::jgss::krb5::Krb5MechFactory;
using $Krb5NameElement = ::sun::security::jgss::krb5::Krb5NameElement;
using $Krb5Util = ::sun::security::jgss::krb5::Krb5Util;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $Credentials = ::sun::security::krb5::Credentials;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Ticket = ::sun::security::krb5::internal::Ticket;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5ProxyCredential_FieldInfo_[] = {
	{"self", "Lsun/security/jgss/krb5/Krb5InitCredential;", nullptr, $PUBLIC | $FINAL, $field(Krb5ProxyCredential, self)},
	{"client", "Lsun/security/jgss/krb5/Krb5NameElement;", nullptr, $PRIVATE | $FINAL, $field(Krb5ProxyCredential, client)},
	{"tkt", "Lsun/security/krb5/internal/Ticket;", nullptr, $PUBLIC | $FINAL, $field(Krb5ProxyCredential, tkt)},
	{}
};

$MethodInfo _Krb5ProxyCredential_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/Krb5InitCredential;Lsun/security/jgss/krb5/Krb5NameElement;Lsun/security/krb5/internal/Ticket;)V", nullptr, 0, $method(static_cast<void(Krb5ProxyCredential::*)($Krb5InitCredential*,$Krb5NameElement*,$Ticket*)>(&Krb5ProxyCredential::init$))},
	{"dispose", "()V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getAcceptLifetime", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getInitLifetime", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanism", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $FINAL},
	{"getName", "()Lsun/security/jgss/krb5/Krb5NameElement;", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $FINAL},
	{"impersonate", "(Lsun/security/jgss/spi/GSSNameSpi;)Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isAcceptorCredential", "()Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isInitiatorCredential", "()Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"tryImpersonation", "(Lsun/security/jgss/GSSCaller;Lsun/security/jgss/krb5/Krb5InitCredential;)Lsun/security/jgss/krb5/Krb5CredElement;", nullptr, $STATIC, $method(static_cast<$Krb5CredElement*(*)($GSSCaller*,$Krb5InitCredential*)>(&Krb5ProxyCredential::tryImpersonation)), "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _Krb5ProxyCredential_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.krb5.Krb5ProxyCredential",
	"java.lang.Object",
	"sun.security.jgss.krb5.Krb5CredElement",
	_Krb5ProxyCredential_FieldInfo_,
	_Krb5ProxyCredential_MethodInfo_
};

$Object* allocate$Krb5ProxyCredential($Class* clazz) {
	return $of($alloc(Krb5ProxyCredential));
}

void Krb5ProxyCredential::init$($Krb5InitCredential* self, $Krb5NameElement* client, $Ticket* tkt) {
	$set(this, self, self);
	$set(this, tkt, tkt);
	$set(this, client, client);
}

$GSSNameSpi* Krb5ProxyCredential::getName() {
	return this->client;
}

int32_t Krb5ProxyCredential::getInitLifetime() {
	return $nc(this->self)->getInitLifetime();
}

int32_t Krb5ProxyCredential::getAcceptLifetime() {
	return 0;
}

bool Krb5ProxyCredential::isInitiatorCredential() {
	return true;
}

bool Krb5ProxyCredential::isAcceptorCredential() {
	return false;
}

$Oid* Krb5ProxyCredential::getMechanism() {
	$init($Krb5MechFactory);
	return $Krb5MechFactory::GSS_KRB5_MECH_OID;
}

$Provider* Krb5ProxyCredential::getProvider() {
	$init($Krb5MechFactory);
	return $Krb5MechFactory::PROVIDER;
}

void Krb5ProxyCredential::dispose() {
	try {
		$nc(this->self)->destroy();
	} catch ($DestroyFailedException&) {
		$var($DestroyFailedException, e, $catch());
		$var($GSSException, gssException, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not destroy credentials - "_s, $(e->getMessage())})));
		gssException->initCause(e);
	}
}

$GSSCredentialSpi* Krb5ProxyCredential::impersonate($GSSNameSpi* name) {
	$throwNew($GSSException, $GSSException::FAILURE, -1, "Only an initiate credentials can impersonate"_s);
	$shouldNotReachHere();
}

$Krb5CredElement* Krb5ProxyCredential::tryImpersonation($GSSCaller* caller, $Krb5InitCredential* initiator) {
	$init(Krb5ProxyCredential);
	try {
		$var($KerberosTicket, proxy, $nc(initiator)->proxyTicket);
		if (proxy != nullptr) {
			$var($Credentials, proxyCreds, $Krb5Util::ticketToCreds(proxy));
			$var($Krb5InitCredential, var$0, initiator);
			$var($Krb5NameElement, var$1, $Krb5NameElement::getInstance($($nc(proxyCreds)->getClient())));
			return $new(Krb5ProxyCredential, var$0, var$1, $($nc(proxyCreds)->getTicket()));
		} else {
			return initiator;
		}
	} catch ($KrbException&) {
		$var($Exception, e, $catch());
		$throwNew($GSSException, $GSSException::DEFECTIVE_CREDENTIAL, -1, "Cannot create proxy credential"_s);
	} catch ($IOException&) {
		$var($Exception, e, $catch());
		$throwNew($GSSException, $GSSException::DEFECTIVE_CREDENTIAL, -1, "Cannot create proxy credential"_s);
	}
	$shouldNotReachHere();
}

Krb5ProxyCredential::Krb5ProxyCredential() {
}

$Class* Krb5ProxyCredential::load$($String* name, bool initialize) {
	$loadClass(Krb5ProxyCredential, name, initialize, &_Krb5ProxyCredential_ClassInfo_, allocate$Krb5ProxyCredential);
	return class$;
}

$Class* Krb5ProxyCredential::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun