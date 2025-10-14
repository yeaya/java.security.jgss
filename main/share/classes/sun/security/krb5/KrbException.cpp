#include <sun/security/krb5/KrbException.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/KRBError.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KRBError = ::sun::security::krb5::internal::KRBError;
using $Krb5 = ::sun::security::krb5::internal::Krb5;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KrbException, serialVersionUID)},
	{"returnCode", "I", nullptr, $PRIVATE, $field(KrbException, returnCode$)},
	{"error", "Lsun/security/krb5/internal/KRBError;", nullptr, $PRIVATE, $field(KrbException, error)},
	{}
};

$MethodInfo _KrbException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbException::*)($String*)>(&KrbException::init$))},
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbException::*)($Throwable*)>(&KrbException::init$))},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(KrbException::*)(int32_t)>(&KrbException::init$))},
	{"<init>", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbException::*)(int32_t,$String*)>(&KrbException::init$))},
	{"<init>", "(Lsun/security/krb5/internal/KRBError;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbException::*)($KRBError*)>(&KrbException::init$))},
	{"<init>", "(Lsun/security/krb5/internal/KRBError;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbException::*)($KRBError*,$String*)>(&KrbException::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"errorMessage", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)(int32_t)>(&KrbException::errorMessage))},
	{"getError", "()Lsun/security/krb5/internal/KRBError;", nullptr, $PUBLIC},
	{"getMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"krbErrorMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"returnCode", "()I", nullptr, $PUBLIC},
	{"returnCodeMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"returnCodeSymbol", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"returnCodeSymbol", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)(int32_t)>(&KrbException::returnCodeSymbol))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KrbException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.KrbException",
	"java.lang.Exception",
	nullptr,
	_KrbException_FieldInfo_,
	_KrbException_MethodInfo_
};

$Object* allocate$KrbException($Class* clazz) {
	return $of($alloc(KrbException));
}

void KrbException::init$($String* s) {
	$Exception::init$(s);
}

void KrbException::init$($Throwable* cause) {
	$Exception::init$(cause);
}

void KrbException::init$(int32_t i) {
	$Exception::init$();
	this->returnCode$ = i;
}

void KrbException::init$(int32_t i, $String* s) {
	KrbException::init$(s);
	this->returnCode$ = i;
}

void KrbException::init$($KRBError* e) {
	$Exception::init$();
	this->returnCode$ = $nc(e)->getErrorCode();
	$set(this, error, e);
}

void KrbException::init$($KRBError* e, $String* s) {
	KrbException::init$(s);
	this->returnCode$ = $nc(e)->getErrorCode();
	$set(this, error, e);
}

$KRBError* KrbException::getError() {
	return this->error;
}

int32_t KrbException::returnCode() {
	return this->returnCode$;
}

$String* KrbException::returnCodeSymbol() {
	return returnCodeSymbol(this->returnCode$);
}

$String* KrbException::returnCodeSymbol(int32_t i) {
	$init(KrbException);
	return "not yet implemented"_s;
}

$String* KrbException::returnCodeMessage() {
	return $Krb5::getErrorMessage(this->returnCode$);
}

$String* KrbException::errorMessage(int32_t i) {
	$init(KrbException);
	return $Krb5::getErrorMessage(i);
}

$String* KrbException::krbErrorMessage() {
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("krb_error "_s)->append(this->returnCode$);
	$var($String, msg, getMessage());
	if (msg != nullptr) {
		sb->append(" "_s);
		sb->append(msg);
	}
	return sb->toString();
}

$String* KrbException::getMessage() {
	$var($StringBuilder, message, $new($StringBuilder));
	int32_t returnCode = this->returnCode();
	if (returnCode != 0) {
		message->append($(returnCodeMessage()));
		message->append(" ("_s)->append(this->returnCode())->append(u')');
	}
	$var($String, consMessage, $Exception::getMessage());
	if (consMessage != nullptr && consMessage->length() != 0) {
		if (returnCode != 0) {
			message->append(" - "_s);
		}
		message->append(consMessage);
	}
	return message->toString();
}

$String* KrbException::toString() {
	return ($str({"KrbException: "_s, $(getMessage())}));
}

int32_t KrbException::hashCode() {
	int32_t result = 17;
	result = 37 * result + this->returnCode$;
	if (this->error != nullptr) {
		result = 37 * result + $nc(this->error)->hashCode();
	}
	return result;
}

bool KrbException::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(KrbException, obj))) {
		return false;
	}
	$var(KrbException, other, $cast(KrbException, obj));
	if (this->returnCode$ != $nc(other)->returnCode$) {
		return false;
	}
	return (this->error == nullptr) ? ($nc(other)->error == nullptr) : ($nc(this->error)->equals(other->error));
}

KrbException::KrbException() {
}

KrbException::KrbException(const KrbException& e) {
}

KrbException KrbException::wrapper$() {
	$pendingException(this);
	return *this;
}

void KrbException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* KrbException::load$($String* name, bool initialize) {
	$loadClass(KrbException, name, initialize, &_KrbException_ClassInfo_, allocate$KrbException);
	return class$;
}

$Class* KrbException::class$ = nullptr;

		} // krb5
	} // security
} // sun