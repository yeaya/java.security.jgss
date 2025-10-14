#include <sun/security/krb5/internal/TGSReq.h>

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

#undef KRB_TGS_REQ

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

$MethodInfo _TGSReq_MethodInfo_[] = {
	{"<init>", "([Lsun/security/krb5/internal/PAData;Lsun/security/krb5/internal/KDCReqBody;)V", nullptr, $PUBLIC, $method(static_cast<void(TGSReq::*)($PADataArray*,$KDCReqBody*)>(&TGSReq::init$)), "java.io.IOException"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(TGSReq::*)($bytes*)>(&TGSReq::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(TGSReq::*)($DerValue*)>(&TGSReq::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(TGSReq::*)($DerValue*)>(&TGSReq::init)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{}
};

$ClassInfo _TGSReq_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.TGSReq",
	"sun.security.krb5.internal.KDCReq",
	nullptr,
	nullptr,
	_TGSReq_MethodInfo_
};

$Object* allocate$TGSReq($Class* clazz) {
	return $of($alloc(TGSReq));
}

void TGSReq::init$($PADataArray* new_pAData, $KDCReqBody* new_reqBody) {
	$KDCReq::init$(new_pAData, new_reqBody, $Krb5::KRB_TGS_REQ);
}

void TGSReq::init$($bytes* data) {
	$KDCReq::init$();
	init($$new($DerValue, data));
}

void TGSReq::init$($DerValue* encoding) {
	$KDCReq::init$();
	init(encoding);
}

void TGSReq::init($DerValue* encoding) {
	init(encoding, $Krb5::KRB_TGS_REQ);
}

TGSReq::TGSReq() {
}

$Class* TGSReq::load$($String* name, bool initialize) {
	$loadClass(TGSReq, name, initialize, &_TGSReq_ClassInfo_, allocate$TGSReq);
	return class$;
}

$Class* TGSReq::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun