#include <javax/security/auth/kerberos/KerberosCredMessage.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Arrays.h>
#include <java/util/Base64$Encoder.h>
#include <java/util/Base64.h>
#include <java/util/Objects.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Base64 = ::java::util::Base64;
using $Base64$Encoder = ::java::util::Base64$Encoder;
using $Objects = ::java::util::Objects;
using $Destroyable = ::javax::security::auth::Destroyable;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _KerberosCredMessage_FieldInfo_[] = {
	{"sender", "Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PRIVATE | $FINAL, $field(KerberosCredMessage, sender)},
	{"recipient", "Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PRIVATE | $FINAL, $field(KerberosCredMessage, recipient)},
	{"message", "[B", nullptr, $PRIVATE | $FINAL, $field(KerberosCredMessage, message)},
	{"destroyed", "Z", nullptr, $PRIVATE, $field(KerberosCredMessage, destroyed)},
	{}
};

$MethodInfo _KerberosCredMessage_MethodInfo_[] = {
	{"<init>", "(Ljavax/security/auth/kerberos/KerberosPrincipal;Ljavax/security/auth/kerberos/KerberosPrincipal;[B)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosCredMessage::*)($KerberosPrincipal*,$KerberosPrincipal*,$bytes*)>(&KerberosCredMessage::init$))},
	{"destroy", "()V", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $method(static_cast<$bytes*(KerberosCredMessage::*)()>(&KerberosCredMessage::getEncoded))},
	{"getRecipient", "()Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC, $method(static_cast<$KerberosPrincipal*(KerberosCredMessage::*)()>(&KerberosCredMessage::getRecipient))},
	{"getSender", "()Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC, $method(static_cast<$KerberosPrincipal*(KerberosCredMessage::*)()>(&KerberosCredMessage::getSender))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isDestroyed", "()Z", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KerberosCredMessage_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"javax.security.auth.kerberos.KerberosCredMessage",
	"java.lang.Object",
	"javax.security.auth.Destroyable",
	_KerberosCredMessage_FieldInfo_,
	_KerberosCredMessage_MethodInfo_
};

$Object* allocate$KerberosCredMessage($Class* clazz) {
	return $of($alloc(KerberosCredMessage));
}

void KerberosCredMessage::init$($KerberosPrincipal* sender, $KerberosPrincipal* recipient, $bytes* message) {
	this->destroyed = false;
	$set(this, sender, $cast($KerberosPrincipal, $Objects::requireNonNull(sender)));
	$set(this, recipient, $cast($KerberosPrincipal, $Objects::requireNonNull(recipient)));
	$set(this, message, $cast($bytes, $nc(($cast($bytes, $Objects::requireNonNull(message))))->clone()));
}

$bytes* KerberosCredMessage::getEncoded() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This object is no longer valid"_s);
	}
	return $cast($bytes, $nc(this->message)->clone());
}

$KerberosPrincipal* KerberosCredMessage::getSender() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This object is no longer valid"_s);
	}
	return this->sender;
}

$KerberosPrincipal* KerberosCredMessage::getRecipient() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This object is no longer valid"_s);
	}
	return this->recipient;
}

void KerberosCredMessage::destroy() {
	if (!this->destroyed) {
		$Arrays::fill(this->message, (int8_t)0);
		this->destroyed = true;
	}
}

bool KerberosCredMessage::isDestroyed() {
	return this->destroyed;
}

$String* KerberosCredMessage::toString() {
	if (this->destroyed) {
		return "Destroyed KerberosCredMessage"_s;
	} else {
		$var($String, var$0, $$str({"KRB_CRED from "_s, this->sender, " to "_s, this->recipient, ":\n"_s}));
		return $concat(var$0, $($nc($($Base64::getUrlEncoder()))->encodeToString(this->message)));
	}
}

int32_t KerberosCredMessage::hashCode() {
	if (isDestroyed()) {
		return -1;
	} else {
		return $Objects::hash($$new($ObjectArray, {
			$of(this->sender),
			$of(this->recipient),
			$($of($Integer::valueOf($Arrays::hashCode(this->message))))
		}));
	}
}

bool KerberosCredMessage::equals(Object$* other) {
	if ($equals(other, this)) {
		return true;
	}
	if (!($instanceOf(KerberosCredMessage, other))) {
		return false;
	}
	$var(KerberosCredMessage, otherMessage, $cast(KerberosCredMessage, other));
	bool var$0 = isDestroyed();
	if (var$0 || $nc(otherMessage)->isDestroyed()) {
		return false;
	}
	bool var$2 = $Objects::equals(this->sender, $nc(otherMessage)->sender);
	bool var$1 = var$2 && $Objects::equals(this->recipient, $nc(otherMessage)->recipient);
	return var$1 && $Arrays::equals(this->message, $nc(otherMessage)->message);
}

KerberosCredMessage::KerberosCredMessage() {
}

$Class* KerberosCredMessage::load$($String* name, bool initialize) {
	$loadClass(KerberosCredMessage, name, initialize, &_KerberosCredMessage_ClassInfo_, allocate$KerberosCredMessage);
	return class$;
}

$Class* KerberosCredMessage::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax