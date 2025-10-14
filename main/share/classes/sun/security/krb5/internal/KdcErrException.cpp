#include <sun/security/krb5/internal/KdcErrException.h>

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

$FieldInfo _KdcErrException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KdcErrException, serialVersionUID)},
	{}
};

$MethodInfo _KdcErrException_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(KdcErrException::*)(int32_t)>(&KdcErrException::init$))},
	{"<init>", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KdcErrException::*)(int32_t,$String*)>(&KdcErrException::init$))},
	{}
};

$ClassInfo _KdcErrException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KdcErrException",
	"sun.security.krb5.KrbException",
	nullptr,
	_KdcErrException_FieldInfo_,
	_KdcErrException_MethodInfo_
};

$Object* allocate$KdcErrException($Class* clazz) {
	return $of($alloc(KdcErrException));
}

void KdcErrException::init$(int32_t i) {
	$KrbException::init$(i);
}

void KdcErrException::init$(int32_t i, $String* s) {
	$KrbException::init$(i, s);
}

KdcErrException::KdcErrException() {
}

KdcErrException::KdcErrException(const KdcErrException& e) {
}

KdcErrException KdcErrException::wrapper$() {
	$pendingException(this);
	return *this;
}

void KdcErrException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* KdcErrException::load$($String* name, bool initialize) {
	$loadClass(KdcErrException, name, initialize, &_KdcErrException_ClassInfo_, allocate$KdcErrException);
	return class$;
}

$Class* KdcErrException::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun