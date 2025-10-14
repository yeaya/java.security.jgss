#include <sun/security/jgss/krb5/Krb5NameElement.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/String.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/Permission.h>
#include <java/security/Provider.h>
#include <java/util/Locale.h>
#include <javax/security/auth/kerberos/ServicePermission.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/krb5/Krb5MechFactory.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <jcpp.h>

#undef AUTODEDUCEREALM
#undef BAD_NAME
#undef BAD_NAMETYPE
#undef ENGLISH
#undef FAILURE
#undef GSS_KRB5_MECH_OID
#undef KRB_NT_PRINCIPAL
#undef KRB_NT_SRV_HST
#undef NT_ANONYMOUS
#undef NT_EXPORT_NAME
#undef NT_GSS_KRB5_PRINCIPAL
#undef NT_HOSTBASED_SERVICE
#undef NT_USER_NAME
#undef PROVIDER
#undef UTF_8

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $StringBuffer = ::java::lang::StringBuffer;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Permission = ::java::security::Permission;
using $Provider = ::java::security::Provider;
using $Locale = ::java::util::Locale;
using $ServicePermission = ::javax::security::auth::kerberos::ServicePermission;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $Krb5MechFactory = ::sun::security::jgss::krb5::Krb5MechFactory;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5NameElement_FieldInfo_[] = {
	{"krb5PrincipalName", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(Krb5NameElement, krb5PrincipalName)},
	{"gssNameStr", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Krb5NameElement, gssNameStr)},
	{"gssNameType", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(Krb5NameElement, gssNameType)},
	{}
};

$MethodInfo _Krb5NameElement_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/PrincipalName;Ljava/lang/String;Lorg/ietf/jgss/Oid;)V", nullptr, $PRIVATE, $method(static_cast<void(Krb5NameElement::*)($PrincipalName*,$String*,$Oid*)>(&Krb5NameElement::init$))},
	{"equals", "(Lsun/security/jgss/spi/GSSNameSpi;)Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"export", "()[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getComponents", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$StringArray*(*)($String*)>(&Krb5NameElement::getComponents)), "org.ietf.jgss.GSSException"},
	{"getGSSNameType", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getHostBasedInstance", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($String*,$String*)>(&Krb5NameElement::getHostBasedInstance)), "org.ietf.jgss.GSSException"},
	{"getInstance", "(Ljava/lang/String;Lorg/ietf/jgss/Oid;)Lsun/security/jgss/krb5/Krb5NameElement;", nullptr, $STATIC, $method(static_cast<Krb5NameElement*(*)($String*,$Oid*)>(&Krb5NameElement::getInstance)), "org.ietf.jgss.GSSException"},
	{"getInstance", "(Lsun/security/krb5/PrincipalName;)Lsun/security/jgss/krb5/Krb5NameElement;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Krb5NameElement*(*)($PrincipalName*)>(&Krb5NameElement::getInstance))},
	{"getKrb5PrincipalName", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$PrincipalName*(Krb5NameElement::*)()>(&Krb5NameElement::getKrb5PrincipalName))},
	{"getMechanism", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC},
	{"getStringNameType", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isAnonymousName", "()Z", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Krb5NameElement_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.krb5.Krb5NameElement",
	"java.lang.Object",
	"sun.security.jgss.spi.GSSNameSpi",
	_Krb5NameElement_FieldInfo_,
	_Krb5NameElement_MethodInfo_
};

$Object* allocate$Krb5NameElement($Class* clazz) {
	return $of($alloc(Krb5NameElement));
}

void Krb5NameElement::init$($PrincipalName* principalName, $String* gssNameStr, $Oid* gssNameType) {
	$set(this, gssNameStr, nullptr);
	$set(this, gssNameType, nullptr);
	$set(this, krb5PrincipalName, principalName);
	$set(this, gssNameStr, gssNameStr);
	$set(this, gssNameType, gssNameType);
}

Krb5NameElement* Krb5NameElement::getInstance($String* gssNameStr, $Oid* gssNameType$renamed) {
	$init(Krb5NameElement);
	$var($Oid, gssNameType, gssNameType$renamed);
	if (gssNameType == nullptr) {
		$init($Krb5MechFactory);
		$assign(gssNameType, $Krb5MechFactory::NT_GSS_KRB5_PRINCIPAL);
	} else {
		$init($GSSName);
		bool var$5 = !$nc(gssNameType)->equals($GSSName::NT_USER_NAME);
		bool var$4 = var$5 && !gssNameType->equals($GSSName::NT_HOSTBASED_SERVICE);
		$init($Krb5MechFactory);
		bool var$3 = var$4 && !gssNameType->equals($Krb5MechFactory::NT_GSS_KRB5_PRINCIPAL);
		if (var$3 && !gssNameType->equals($GSSName::NT_EXPORT_NAME)) {
			$throwNew($GSSException, $GSSException::BAD_NAMETYPE, -1, $$str({$(gssNameType->toString()), " is an unsupported nametype"_s}));
		}
	}
	$var($PrincipalName, principalName, nullptr);
	try {
		$init($GSSName);
		bool var$6 = $nc(gssNameType)->equals($GSSName::NT_EXPORT_NAME);
		$init($Krb5MechFactory);
		if (var$6 || $nc(gssNameType)->equals($Krb5MechFactory::NT_GSS_KRB5_PRINCIPAL)) {
			$assign(principalName, $new($PrincipalName, gssNameStr, $PrincipalName::KRB_NT_PRINCIPAL));
		} else {
			$var($StringArray, components, getComponents(gssNameStr));
			if (gssNameType->equals($GSSName::NT_USER_NAME)) {
				$assign(principalName, $new($PrincipalName, gssNameStr, $PrincipalName::KRB_NT_PRINCIPAL));
			} else {
				$var($String, hostName, nullptr);
				$var($String, service, $nc(components)->get(0));
				if (components->length >= 2) {
					$assign(hostName, components->get(1));
				}
				$var($String, principal, getHostBasedInstance(service, hostName));
				$assign(principalName, $new($PrincipalName, principal, $PrincipalName::KRB_NT_SRV_HST));
			}
		}
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		$throwNew($GSSException, $GSSException::BAD_NAME, -1, $(e->getMessage()));
	}
	$init($Realm);
	if ($nc(principalName)->isRealmDeduced() && !$Realm::AUTODEDUCEREALM) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			try {
				sm->checkPermission($$new($ServicePermission, $$str({"@"_s, $(principalName->getRealmAsString())}), "-"_s));
			} catch ($SecurityException&) {
				$var($SecurityException, se, $catch());
				$throwNew($GSSException, $GSSException::FAILURE);
			}
		}
	}
	return $new(Krb5NameElement, principalName, gssNameStr, gssNameType);
}

Krb5NameElement* Krb5NameElement::getInstance($PrincipalName* principalName) {
	$init(Krb5NameElement);
	$init($Krb5MechFactory);
	return $new(Krb5NameElement, principalName, $($nc(principalName)->getName()), $Krb5MechFactory::NT_GSS_KRB5_PRINCIPAL);
}

$StringArray* Krb5NameElement::getComponents($String* gssNameStr) {
	$init(Krb5NameElement);
	$var($StringArray, retVal, nullptr);
	int32_t separatorPos = $nc(gssNameStr)->lastIndexOf((int32_t)u'@', gssNameStr->length());
	if ((separatorPos > 0) && (gssNameStr->charAt(separatorPos - 1) == u'\\')) {
		if ((separatorPos - 2 < 0) || (gssNameStr->charAt(separatorPos - 2) != u'\\')) {
			separatorPos = -1;
		}
	}
	if (separatorPos > 0) {
		$var($String, serviceName, gssNameStr->substring(0, separatorPos));
		$var($String, hostName, gssNameStr->substring(separatorPos + 1));
		$assign(retVal, $new($StringArray, {
			serviceName,
			hostName
		}));
	} else {
		$assign(retVal, $new($StringArray, {gssNameStr}));
	}
	return retVal;
}

$String* Krb5NameElement::getHostBasedInstance($String* serviceName, $String* hostName$renamed) {
	$init(Krb5NameElement);
	$var($String, hostName, hostName$renamed);
	$var($StringBuffer, temp, $new($StringBuffer, serviceName));
	try {
		if (hostName == nullptr) {
			$assign(hostName, $nc($($InetAddress::getLocalHost()))->getHostName());
		}
	} catch ($UnknownHostException&) {
		$catch();
	}
	$init($Locale);
	$assign(hostName, $nc(hostName)->toLowerCase($Locale::ENGLISH));
	$assign(temp, temp->append(u'/')->append(hostName));
	return temp->toString();
}

$PrincipalName* Krb5NameElement::getKrb5PrincipalName() {
	return this->krb5PrincipalName;
}

bool Krb5NameElement::equals($GSSNameSpi* other) {
	if ($equals(other, this)) {
		return true;
	}
	if ($instanceOf(Krb5NameElement, other)) {
		$var(Krb5NameElement, that, $cast(Krb5NameElement, other));
		return ($nc($($nc(this->krb5PrincipalName)->getName()))->equals($($nc($nc(that)->krb5PrincipalName)->getName())));
	}
	return false;
}

bool Krb5NameElement::equals(Object$* another) {
	if ($equals(this, another)) {
		return true;
	}
	try {
		if ($instanceOf(Krb5NameElement, another)) {
			return equals($cast(Krb5NameElement, another));
		}
	} catch ($GSSException&) {
		$catch();
	}
	return false;
}

int32_t Krb5NameElement::hashCode() {
	return 37 * 17 + $nc($($nc(this->krb5PrincipalName)->getName()))->hashCode();
}

$bytes* Krb5NameElement::export$() {
	$init($StandardCharsets);
	return $nc($($nc(this->krb5PrincipalName)->getName()))->getBytes($StandardCharsets::UTF_8);
}

$Oid* Krb5NameElement::getMechanism() {
	$init($Krb5MechFactory);
	return ($Krb5MechFactory::GSS_KRB5_MECH_OID);
}

$String* Krb5NameElement::toString() {
	return (this->gssNameStr);
}

$Oid* Krb5NameElement::getGSSNameType() {
	return (this->gssNameType);
}

$Oid* Krb5NameElement::getStringNameType() {
	return (this->gssNameType);
}

bool Krb5NameElement::isAnonymousName() {
	$init($GSSName);
	return ($nc(this->gssNameType)->equals($GSSName::NT_ANONYMOUS));
}

$Provider* Krb5NameElement::getProvider() {
	$init($Krb5MechFactory);
	return $Krb5MechFactory::PROVIDER;
}

Krb5NameElement::Krb5NameElement() {
}

$Class* Krb5NameElement::load$($String* name, bool initialize) {
	$loadClass(Krb5NameElement, name, initialize, &_Krb5NameElement_ClassInfo_, allocate$Krb5NameElement);
	return class$;
}

$Class* Krb5NameElement::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun