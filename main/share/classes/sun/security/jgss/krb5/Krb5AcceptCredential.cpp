#include <sun/security/jgss/krb5/Krb5AcceptCredential.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/Provider.h>
#include <javax/security/auth/DestroyFailedException.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/krb5/Krb5AcceptCredential$1.h>
#include <sun/security/jgss/krb5/Krb5InitCredential.h>
#include <sun/security/jgss/krb5/Krb5MechFactory.h>
#include <sun/security/jgss/krb5/Krb5NameElement.h>
#include <sun/security/jgss/krb5/ServiceCreds.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <jcpp.h>

#undef FAILURE
#undef GSS_KRB5_MECH_OID
#undef INDEFINITE_LIFETIME
#undef NO_CRED
#undef NT_GSS_KRB5_PRINCIPAL
#undef PROVIDER

using $EncryptionKeyArray = $Array<::sun::security::krb5::EncryptionKey>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Provider = ::java::security::Provider;
using $DestroyFailedException = ::javax::security::auth::DestroyFailedException;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $Krb5AcceptCredential$1 = ::sun::security::jgss::krb5::Krb5AcceptCredential$1;
using $Krb5CredElement = ::sun::security::jgss::krb5::Krb5CredElement;
using $Krb5InitCredential = ::sun::security::jgss::krb5::Krb5InitCredential;
using $Krb5MechFactory = ::sun::security::jgss::krb5::Krb5MechFactory;
using $Krb5NameElement = ::sun::security::jgss::krb5::Krb5NameElement;
using $ServiceCreds = ::sun::security::jgss::krb5::ServiceCreds;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $Credentials = ::sun::security::krb5::Credentials;
using $PrincipalName = ::sun::security::krb5::PrincipalName;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5AcceptCredential_FieldInfo_[] = {
	{"name", "Lsun/security/jgss/krb5/Krb5NameElement;", nullptr, $PRIVATE | $FINAL, $field(Krb5AcceptCredential, name)},
	{"screds", "Lsun/security/jgss/krb5/ServiceCreds;", nullptr, $PRIVATE | $FINAL, $field(Krb5AcceptCredential, screds)},
	{}
};

$MethodInfo _Krb5AcceptCredential_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/Krb5NameElement;Lsun/security/jgss/krb5/ServiceCreds;)V", nullptr, $PRIVATE, $method(static_cast<void(Krb5AcceptCredential::*)($Krb5NameElement*,$ServiceCreds*)>(&Krb5AcceptCredential::init$))},
	{"destroy", "()V", nullptr, $PUBLIC, nullptr, "javax.security.auth.DestroyFailedException"},
	{"dispose", "()V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getAcceptLifetime", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getInitLifetime", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getInstance", "(Lsun/security/jgss/GSSCaller;Lsun/security/jgss/krb5/Krb5NameElement;)Lsun/security/jgss/krb5/Krb5AcceptCredential;", nullptr, $STATIC, $method(static_cast<Krb5AcceptCredential*(*)($GSSCaller*,$Krb5NameElement*)>(&Krb5AcceptCredential::getInstance)), "org.ietf.jgss.GSSException"},
	{"getKrb5EncryptionKeys", "(Lsun/security/krb5/PrincipalName;)[Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC},
	{"getMechanism", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $FINAL},
	{"getName", "()Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $FINAL},
	{"impersonate", "(Lsun/security/jgss/spi/GSSNameSpi;)Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isAcceptorCredential", "()Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isInitiatorCredential", "()Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{}
};

$InnerClassInfo _Krb5AcceptCredential_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.Krb5AcceptCredential$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Krb5AcceptCredential_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.krb5.Krb5AcceptCredential",
	"java.lang.Object",
	"sun.security.jgss.krb5.Krb5CredElement",
	_Krb5AcceptCredential_FieldInfo_,
	_Krb5AcceptCredential_MethodInfo_,
	nullptr,
	nullptr,
	_Krb5AcceptCredential_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.Krb5AcceptCredential$1"
};

$Object* allocate$Krb5AcceptCredential($Class* clazz) {
	return $of($alloc(Krb5AcceptCredential));
}

void Krb5AcceptCredential::init$($Krb5NameElement* name, $ServiceCreds* creds) {
	$set(this, name, name);
	$set(this, screds, creds);
}

Krb5AcceptCredential* Krb5AcceptCredential::getInstance($GSSCaller* caller, $Krb5NameElement* name$renamed) {
	$init(Krb5AcceptCredential);
	$var($Krb5NameElement, name, name$renamed);
	$beforeCallerSensitive();
	$var($String, serverPrinc, name == nullptr ? ($String*)nullptr : $nc($($nc(name)->getKrb5PrincipalName()))->getName());
	$var($AccessControlContext, acc, $AccessController::getContext());
	$var($ServiceCreds, creds, nullptr);
	try {
		$assign(creds, $cast($ServiceCreds, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($Krb5AcceptCredential$1, caller, serverPrinc, acc)))));
	} catch ($PrivilegedActionException&) {
		$var($PrivilegedActionException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::NO_CRED, -1, "Attempt to obtain new ACCEPT credentials failed!"_s));
		ge->initCause($(e->getException()));
		$throw(ge);
	}
	if (creds == nullptr) {
		$throwNew($GSSException, $GSSException::NO_CRED, -1, "Failed to find any Kerberos credentials"_s);
	}
	if (name == nullptr) {
		$var($String, fullName, $nc(creds)->getName());
		if (fullName != nullptr) {
			$init($Krb5MechFactory);
			$assign(name, $Krb5NameElement::getInstance(fullName, $Krb5MechFactory::NT_GSS_KRB5_PRINCIPAL));
		}
	}
	return $new(Krb5AcceptCredential, name, creds);
}

$GSSNameSpi* Krb5AcceptCredential::getName() {
	return this->name;
}

int32_t Krb5AcceptCredential::getInitLifetime() {
	return 0;
}

int32_t Krb5AcceptCredential::getAcceptLifetime() {
	return $GSSCredential::INDEFINITE_LIFETIME;
}

bool Krb5AcceptCredential::isInitiatorCredential() {
	return false;
}

bool Krb5AcceptCredential::isAcceptorCredential() {
	return true;
}

$Oid* Krb5AcceptCredential::getMechanism() {
	$init($Krb5MechFactory);
	return $Krb5MechFactory::GSS_KRB5_MECH_OID;
}

$Provider* Krb5AcceptCredential::getProvider() {
	$init($Krb5MechFactory);
	return $Krb5MechFactory::PROVIDER;
}

$EncryptionKeyArray* Krb5AcceptCredential::getKrb5EncryptionKeys($PrincipalName* princ) {
	return $nc(this->screds)->getEKeys(princ);
}

void Krb5AcceptCredential::dispose() {
	try {
		destroy();
	} catch ($DestroyFailedException&) {
		$var($DestroyFailedException, e, $catch());
		$var($GSSException, gssException, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not destroy credentials - "_s, $(e->getMessage())})));
		gssException->initCause(e);
	}
}

void Krb5AcceptCredential::destroy() {
	$nc(this->screds)->destroy();
}

$GSSCredentialSpi* Krb5AcceptCredential::impersonate($GSSNameSpi* name) {
	$var($Credentials, cred, $nc(this->screds)->getInitCred());
	if (cred != nullptr) {
		return $nc($($Krb5InitCredential::getInstance(this->name, cred)))->impersonate(name);
	} else {
		$throwNew($GSSException, $GSSException::FAILURE, -1, "Only an initiate credentials can impersonate"_s);
	}
}

Krb5AcceptCredential::Krb5AcceptCredential() {
}

$Class* Krb5AcceptCredential::load$($String* name, bool initialize) {
	$loadClass(Krb5AcceptCredential, name, initialize, &_Krb5AcceptCredential_ClassInfo_, allocate$Krb5AcceptCredential);
	return class$;
}

$Class* Krb5AcceptCredential::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun