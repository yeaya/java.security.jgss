#include <javax/security/auth/kerberos/KerberosPrincipal.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Permission.h>
#include <java/security/Principal.h>
#include <javax/security/auth/kerberos/ServicePermission.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef AUTODEDUCEREALM
#undef KRB_NT_ENTERPRISE
#undef KRB_NT_PRINCIPAL
#undef KRB_NT_SRV_HST
#undef KRB_NT_SRV_INST
#undef KRB_NT_SRV_XHST
#undef KRB_NT_UID
#undef KRB_NT_UNKNOWN

using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Permission = ::java::security::Permission;
using $Principal = ::java::security::Principal;
using $ServicePermission = ::javax::security::auth::kerberos::ServicePermission;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $DerValue = ::sun::security::util::DerValue;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _KerberosPrincipal_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosPrincipal, serialVersionUID)},
	{"KRB_NT_UNKNOWN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KerberosPrincipal, KRB_NT_UNKNOWN)},
	{"KRB_NT_PRINCIPAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KerberosPrincipal, KRB_NT_PRINCIPAL)},
	{"KRB_NT_SRV_INST", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KerberosPrincipal, KRB_NT_SRV_INST)},
	{"KRB_NT_SRV_HST", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KerberosPrincipal, KRB_NT_SRV_HST)},
	{"KRB_NT_SRV_XHST", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KerberosPrincipal, KRB_NT_SRV_XHST)},
	{"KRB_NT_UID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KerberosPrincipal, KRB_NT_UID)},
	{"KRB_NT_ENTERPRISE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KerberosPrincipal, KRB_NT_ENTERPRISE)},
	{"fullName", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(KerberosPrincipal, fullName)},
	{"realm", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(KerberosPrincipal, realm)},
	{"nameType", "I", nullptr, $PRIVATE | $TRANSIENT, $field(KerberosPrincipal, nameType)},
	{}
};

$MethodInfo _KerberosPrincipal_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosPrincipal::*)($String*)>(&KerberosPrincipal::init$))},
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosPrincipal::*)($String*,int32_t)>(&KerberosPrincipal::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getNameType", "()I", nullptr, $PUBLIC, $method(static_cast<int32_t(KerberosPrincipal::*)()>(&KerberosPrincipal::getNameType))},
	{"getRealm", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(static_cast<$String*(KerberosPrincipal::*)()>(&KerberosPrincipal::getRealm))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KerberosPrincipal::*)($ObjectInputStream*)>(&KerberosPrincipal::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KerberosPrincipal::*)($ObjectOutputStream*)>(&KerberosPrincipal::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _KerberosPrincipal_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"javax.security.auth.kerberos.KerberosPrincipal",
	"java.lang.Object",
	"java.security.Principal,java.io.Serializable",
	_KerberosPrincipal_FieldInfo_,
	_KerberosPrincipal_MethodInfo_
};

$Object* allocate$KerberosPrincipal($Class* clazz) {
	return $of($alloc(KerberosPrincipal));
}

$Object* KerberosPrincipal::clone() {
	 return this->$Principal::clone();
}

void KerberosPrincipal::finalize() {
	this->$Principal::finalize();
}

void KerberosPrincipal::init$($String* name) {
	KerberosPrincipal::init$(name, KerberosPrincipal::KRB_NT_PRINCIPAL);
}

void KerberosPrincipal::init$($String* name, int32_t nameType) {
	$var($PrincipalName, krb5Principal, nullptr);
	try {
		$assign(krb5Principal, $new($PrincipalName, name, nameType));
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		$throwNew($IllegalArgumentException, $(e->getMessage()));
	}
	$init($Realm);
	if ($nc(krb5Principal)->isRealmDeduced() && !$Realm::AUTODEDUCEREALM) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			try {
				sm->checkPermission($$new($ServicePermission, $$str({"@"_s, $(krb5Principal->getRealmAsString())}), "-"_s));
			} catch ($SecurityException&) {
				$var($SecurityException, se, $catch());
				$throwNew($SecurityException, "Cannot read realm info"_s);
			}
		}
	}
	this->nameType = nameType;
	$set(this, fullName, $nc(krb5Principal)->toString());
	$set(this, realm, krb5Principal->getRealmString());
}

$String* KerberosPrincipal::getRealm() {
	return this->realm;
}

int32_t KerberosPrincipal::hashCode() {
	return $nc($(getName()))->hashCode();
}

bool KerberosPrincipal::equals(Object$* other) {
	if ($equals(other, this)) {
		return true;
	}
	if (!($instanceOf(KerberosPrincipal, other))) {
		return false;
	}
	$var($String, myFullName, getName());
	$var($String, otherFullName, $nc(($cast(KerberosPrincipal, other)))->getName());
	return $nc(myFullName)->equals(otherFullName);
}

void KerberosPrincipal::writeObject($ObjectOutputStream* oos) {
	$var($PrincipalName, krb5Principal, nullptr);
	try {
		$assign(krb5Principal, $new($PrincipalName, this->fullName, this->nameType));
		$nc(oos)->writeObject($(krb5Principal->asn1Encode()));
		oos->writeObject($($nc($(krb5Principal->getRealm()))->asn1Encode()));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
}

void KerberosPrincipal::readObject($ObjectInputStream* ois) {
	$var($bytes, asn1EncPrincipal, $cast($bytes, $nc(ois)->readObject()));
	$var($bytes, encRealm, $cast($bytes, ois->readObject()));
	try {
		$var($Realm, realmObject, $new($Realm, $$new($DerValue, encRealm)));
		$var($PrincipalName, krb5Principal, $new($PrincipalName, $$new($DerValue, asn1EncPrincipal), realmObject));
		$set(this, realm, realmObject->toString());
		$set(this, fullName, krb5Principal->toString());
		this->nameType = krb5Principal->getNameType();
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
}

$String* KerberosPrincipal::getName() {
	return this->fullName;
}

int32_t KerberosPrincipal::getNameType() {
	return this->nameType;
}

$String* KerberosPrincipal::toString() {
	return getName();
}

KerberosPrincipal::KerberosPrincipal() {
}

$Class* KerberosPrincipal::load$($String* name, bool initialize) {
	$loadClass(KerberosPrincipal, name, initialize, &_KerberosPrincipal_ClassInfo_, allocate$KerberosPrincipal);
	return class$;
}

$Class* KerberosPrincipal::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax