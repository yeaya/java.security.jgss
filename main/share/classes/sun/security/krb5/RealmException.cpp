#include <sun/security/krb5/RealmException.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
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

$FieldInfo _RealmException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RealmException, serialVersionUID)},
	{}
};

$MethodInfo _RealmException_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(RealmException::*)(int32_t)>(&RealmException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(RealmException::*)($String*)>(&RealmException::init$))},
	{"<init>", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(RealmException::*)(int32_t,$String*)>(&RealmException::init$))},
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(RealmException::*)($Throwable*)>(&RealmException::init$))},
	{}
};

$ClassInfo _RealmException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.RealmException",
	"sun.security.krb5.KrbException",
	nullptr,
	_RealmException_FieldInfo_,
	_RealmException_MethodInfo_
};

$Object* allocate$RealmException($Class* clazz) {
	return $of($alloc(RealmException));
}

void RealmException::init$(int32_t i) {
	$KrbException::init$(i);
}

void RealmException::init$($String* s) {
	$KrbException::init$(s);
}

void RealmException::init$(int32_t i, $String* s) {
	$KrbException::init$(i, s);
}

void RealmException::init$($Throwable* cause) {
	$KrbException::init$(cause);
}

RealmException::RealmException() {
}

RealmException::RealmException(const RealmException& e) {
}

RealmException RealmException::wrapper$() {
	$pendingException(this);
	return *this;
}

void RealmException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* RealmException::load$($String* name, bool initialize) {
	$loadClass(RealmException, name, initialize, &_RealmException_ClassInfo_, allocate$RealmException);
	return class$;
}

$Class* RealmException::class$ = nullptr;

		} // krb5
	} // security
} // sun