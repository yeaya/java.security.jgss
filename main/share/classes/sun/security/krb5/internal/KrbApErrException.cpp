#include <sun/security/krb5/internal/KrbApErrException.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/KrbException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KrbException = ::sun::security::krb5::KrbException;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KrbApErrException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KrbApErrException, serialVersionUID)},
	{}
};

$MethodInfo _KrbApErrException_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(KrbApErrException::*)(int32_t)>(&KrbApErrException::init$))},
	{"<init>", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbApErrException::*)(int32_t,$String*)>(&KrbApErrException::init$))},
	{}
};

$ClassInfo _KrbApErrException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KrbApErrException",
	"sun.security.krb5.KrbException",
	nullptr,
	_KrbApErrException_FieldInfo_,
	_KrbApErrException_MethodInfo_
};

$Object* allocate$KrbApErrException($Class* clazz) {
	return $of($alloc(KrbApErrException));
}

void KrbApErrException::init$(int32_t i) {
	$KrbException::init$(i);
}

void KrbApErrException::init$(int32_t i, $String* s) {
	$KrbException::init$(i, s);
}

KrbApErrException::KrbApErrException() {
}

KrbApErrException::KrbApErrException(const KrbApErrException& e) {
}

KrbApErrException KrbApErrException::wrapper$() {
	$pendingException(this);
	return *this;
}

void KrbApErrException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* KrbApErrException::load$($String* name, bool initialize) {
	$loadClass(KrbApErrException, name, initialize, &_KrbApErrException_ClassInfo_, allocate$KrbApErrException);
	return class$;
}

$Class* KrbApErrException::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun