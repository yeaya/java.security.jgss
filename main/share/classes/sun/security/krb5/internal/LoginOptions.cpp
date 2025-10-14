#include <sun/security/krb5/internal/LoginOptions.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <jcpp.h>

#undef ALLOW_POSTDATE
#undef ENC_TKT_IN_SKEY
#undef FORWARDABLE
#undef MAX
#undef PROXIABLE
#undef RENEW
#undef RENEWABLE
#undef RENEWABLE_OK
#undef RESERVED
#undef VALIDATE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _LoginOptions_FieldInfo_[] = {
	{"RESERVED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, RESERVED)},
	{"FORWARDABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, FORWARDABLE)},
	{"PROXIABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, PROXIABLE)},
	{"ALLOW_POSTDATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, ALLOW_POSTDATE)},
	{"RENEWABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, RENEWABLE)},
	{"RENEWABLE_OK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, RENEWABLE_OK)},
	{"ENC_TKT_IN_SKEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, ENC_TKT_IN_SKEY)},
	{"RENEW", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, RENEW)},
	{"VALIDATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, VALIDATE)},
	{"MAX", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LoginOptions, MAX)},
	{}
};

$MethodInfo _LoginOptions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LoginOptions::*)()>(&LoginOptions::init$))},
	{}
};

$ClassInfo _LoginOptions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.LoginOptions",
	"sun.security.krb5.internal.KDCOptions",
	nullptr,
	_LoginOptions_FieldInfo_,
	_LoginOptions_MethodInfo_
};

$Object* allocate$LoginOptions($Class* clazz) {
	return $of($alloc(LoginOptions));
}

void LoginOptions::init$() {
	$KDCOptions::init$();
}

LoginOptions::LoginOptions() {
}

$Class* LoginOptions::load$($String* name, bool initialize) {
	$loadClass(LoginOptions, name, initialize, &_LoginOptions_ClassInfo_, allocate$LoginOptions);
	return class$;
}

$Class* LoginOptions::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun