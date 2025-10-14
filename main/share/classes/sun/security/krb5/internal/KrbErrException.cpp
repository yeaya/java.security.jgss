#include <sun/security/krb5/internal/KrbErrException.h>

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

$FieldInfo _KrbErrException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KrbErrException, serialVersionUID)},
	{}
};

$MethodInfo _KrbErrException_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(KrbErrException::*)(int32_t)>(&KrbErrException::init$))},
	{"<init>", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbErrException::*)(int32_t,$String*)>(&KrbErrException::init$))},
	{}
};

$ClassInfo _KrbErrException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KrbErrException",
	"sun.security.krb5.KrbException",
	nullptr,
	_KrbErrException_FieldInfo_,
	_KrbErrException_MethodInfo_
};

$Object* allocate$KrbErrException($Class* clazz) {
	return $of($alloc(KrbErrException));
}

void KrbErrException::init$(int32_t i) {
	$KrbException::init$(i);
}

void KrbErrException::init$(int32_t i, $String* s) {
	$KrbException::init$(i, s);
}

KrbErrException::KrbErrException() {
}

KrbErrException::KrbErrException(const KrbErrException& e) {
}

KrbErrException KrbErrException::wrapper$() {
	$pendingException(this);
	return *this;
}

void KrbErrException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* KrbErrException::load$($String* name, bool initialize) {
	$loadClass(KrbErrException, name, initialize, &_KrbErrException_ClassInfo_, allocate$KrbErrException);
	return class$;
}

$Class* KrbErrException::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun