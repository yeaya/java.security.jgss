#include <javax/security/auth/kerberos/KerberosKey.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Arrays.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <javax/security/auth/kerberos/KeyImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $SecretKey = ::javax::crypto::SecretKey;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;
using $KeyImpl = ::javax::security::auth::kerberos::KeyImpl;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _KerberosKey_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosKey, serialVersionUID)},
	{"principal", "Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PRIVATE, $field(KerberosKey, principal)},
	{"versionNum", "I", nullptr, $PRIVATE | $FINAL, $field(KerberosKey, versionNum)},
	{"key", "Ljavax/security/auth/kerberos/KeyImpl;", nullptr, $PRIVATE, $field(KerberosKey, key)},
	{"destroyed", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(KerberosKey, destroyed)},
	{}
};

$MethodInfo _KerberosKey_MethodInfo_[] = {
	{"<init>", "(Ljavax/security/auth/kerberos/KerberosPrincipal;[BII)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosKey::*)($KerberosPrincipal*,$bytes*,int32_t,int32_t)>(&KerberosKey::init$))},
	{"<init>", "(Ljavax/security/auth/kerberos/KerberosPrincipal;[CLjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosKey::*)($KerberosPrincipal*,$chars*,$String*)>(&KerberosKey::init$))},
	{"destroy", "()V", nullptr, $PUBLIC, nullptr, "javax.security.auth.DestroyFailedException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"getEncoded", "()[B", nullptr, $PUBLIC | $FINAL},
	{"getFormat", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"getKeyType", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(KerberosKey::*)()>(&KerberosKey::getKeyType))},
	{"getPrincipal", "()Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$KerberosPrincipal*(KerberosKey::*)()>(&KerberosKey::getPrincipal))},
	{"getVersionNumber", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(KerberosKey::*)()>(&KerberosKey::getVersionNumber))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isDestroyed", "()Z", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KerberosKey_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.security.auth.kerberos.KerberosKey",
	"java.lang.Object",
	"javax.crypto.SecretKey",
	_KerberosKey_FieldInfo_,
	_KerberosKey_MethodInfo_
};

$Object* allocate$KerberosKey($Class* clazz) {
	return $of($alloc(KerberosKey));
}

void KerberosKey::init$($KerberosPrincipal* principal, $bytes* keyBytes, int32_t keyType, int32_t versionNum) {
	this->destroyed = false;
	$set(this, principal, principal);
	this->versionNum = versionNum;
	$set(this, key, $new($KeyImpl, keyBytes, keyType));
}

void KerberosKey::init$($KerberosPrincipal* principal, $chars* password, $String* algorithm) {
	this->destroyed = false;
	$set(this, principal, principal);
	this->versionNum = 0;
	$set(this, key, $new($KeyImpl, principal, password, algorithm));
}

$KerberosPrincipal* KerberosKey::getPrincipal() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This key is no longer valid"_s);
	}
	return this->principal;
}

int32_t KerberosKey::getVersionNumber() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This key is no longer valid"_s);
	}
	return this->versionNum;
}

int32_t KerberosKey::getKeyType() {
	return $nc(this->key)->getKeyType();
}

$String* KerberosKey::getAlgorithm() {
	return $nc(this->key)->getAlgorithm();
}

$String* KerberosKey::getFormat() {
	return $nc(this->key)->getFormat();
}

$bytes* KerberosKey::getEncoded() {
	return $nc(this->key)->getEncoded();
}

void KerberosKey::destroy() {
	if (!this->destroyed) {
		$nc(this->key)->destroy();
		$set(this, principal, nullptr);
		this->destroyed = true;
	}
}

bool KerberosKey::isDestroyed() {
	return this->destroyed;
}

$String* KerberosKey::toString() {
	if (this->destroyed) {
		return "Destroyed KerberosKey"_s;
	}
	$var($String, var$0, $$str({"Kerberos Principal "_s, this->principal, "Key Version "_s, $$str(this->versionNum), "key "_s}));
	return $concat(var$0, $($nc(this->key)->toString()));
}

int32_t KerberosKey::hashCode() {
	int32_t result = 17;
	if (isDestroyed()) {
		return result;
	}
	result = 37 * result + $Arrays::hashCode($(getEncoded()));
	result = 37 * result + getKeyType();
	if (this->principal != nullptr) {
		result = 37 * result + $nc(this->principal)->hashCode();
	}
	return result * 37 + this->versionNum;
}

bool KerberosKey::equals(Object$* other) {
	if ($equals(other, this)) {
		return true;
	}
	if (!($instanceOf(KerberosKey, other))) {
		return false;
	}
	$var(KerberosKey, otherKey, $cast(KerberosKey, other));
	bool var$0 = isDestroyed();
	if (var$0 || $nc(otherKey)->isDestroyed()) {
		return false;
	}
	bool var$2 = this->versionNum != $nc(otherKey)->getVersionNumber();
	if (!var$2) {
		int32_t var$3 = getKeyType();
		var$2 = var$3 != $nc(otherKey)->getKeyType();
	}
	bool var$1 = var$2;
	if (!var$1) {
		$var($bytes, var$4, getEncoded());
		var$1 = !$Arrays::equals(var$4, $($nc(otherKey)->getEncoded()));
	}
	if (var$1) {
		return false;
	}
	if (this->principal == nullptr) {
		if ($nc(otherKey)->getPrincipal() != nullptr) {
			return false;
		}
	} else if (!$nc(this->principal)->equals($($nc(otherKey)->getPrincipal()))) {
		return false;
	}
	return true;
}

KerberosKey::KerberosKey() {
}

$Class* KerberosKey::load$($String* name, bool initialize) {
	$loadClass(KerberosKey, name, initialize, &_KerberosKey_ClassInfo_, allocate$KerberosKey);
	return class$;
}

$Class* KerberosKey::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax