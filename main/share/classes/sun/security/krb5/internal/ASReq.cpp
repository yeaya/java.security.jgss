#include <sun/security/krb5/internal/ASReq.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/KDCReq.h>
#include <sun/security/krb5/internal/KDCReqBody.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef KRB_AS_REQ

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KDCReq = ::sun::security::krb5::internal::KDCReq;
using $KDCReqBody = ::sun::security::krb5::internal::KDCReqBody;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$MethodInfo _ASReq_MethodInfo_[] = {
	{"<init>", "([Lsun/security/krb5/internal/PAData;Lsun/security/krb5/internal/KDCReqBody;)V", nullptr, $PUBLIC, $method(static_cast<void(ASReq::*)($PADataArray*,$KDCReqBody*)>(&ASReq::init$)), "java.io.IOException"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(ASReq::*)($bytes*)>(&ASReq::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(ASReq::*)($DerValue*)>(&ASReq::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.KrbException,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(ASReq::*)($DerValue*)>(&ASReq::init)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{}
};

$ClassInfo _ASReq_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ASReq",
	"sun.security.krb5.internal.KDCReq",
	nullptr,
	nullptr,
	_ASReq_MethodInfo_
};

$Object* allocate$ASReq($Class* clazz) {
	return $of($alloc(ASReq));
}

void ASReq::init$($PADataArray* new_pAData, $KDCReqBody* new_reqBody) {
	$KDCReq::init$(new_pAData, new_reqBody, $Krb5::KRB_AS_REQ);
}

void ASReq::init$($bytes* data) {
	$KDCReq::init$();
	init($$new($DerValue, data));
}

void ASReq::init$($DerValue* encoding) {
	$KDCReq::init$();
	init(encoding);
}

void ASReq::init($DerValue* encoding) {
	$KDCReq::init(encoding, $Krb5::KRB_AS_REQ);
}

ASReq::ASReq() {
}

$Class* ASReq::load$($String* name, bool initialize) {
	$loadClass(ASReq, name, initialize, &_ASReq_ClassInfo_, allocate$ASReq);
	return class$;
}

$Class* ASReq::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun