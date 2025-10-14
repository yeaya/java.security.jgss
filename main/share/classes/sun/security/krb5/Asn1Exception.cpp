#include <sun/security/krb5/Asn1Exception.h>

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

$FieldInfo _Asn1Exception_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Asn1Exception, serialVersionUID)},
	{}
};

$MethodInfo _Asn1Exception_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(Asn1Exception::*)(int32_t)>(&Asn1Exception::init$))},
	{}
};

$ClassInfo _Asn1Exception_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.Asn1Exception",
	"sun.security.krb5.KrbException",
	nullptr,
	_Asn1Exception_FieldInfo_,
	_Asn1Exception_MethodInfo_
};

$Object* allocate$Asn1Exception($Class* clazz) {
	return $of($alloc(Asn1Exception));
}

void Asn1Exception::init$(int32_t i) {
	$KrbException::init$(i);
}

Asn1Exception::Asn1Exception() {
}

Asn1Exception::Asn1Exception(const Asn1Exception& e) {
}

Asn1Exception Asn1Exception::wrapper$() {
	$pendingException(this);
	return *this;
}

void Asn1Exception::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* Asn1Exception::load$($String* name, bool initialize) {
	$loadClass(Asn1Exception, name, initialize, &_Asn1Exception_ClassInfo_, allocate$Asn1Exception);
	return class$;
}

$Class* Asn1Exception::class$ = nullptr;

		} // krb5
	} // security
} // sun