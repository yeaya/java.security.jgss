#include <sun/security/krb5/internal/PAData$SaltAndParams.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/PAData.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PAData = ::sun::security::krb5::internal::PAData;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _PAData$SaltAndParams_FieldInfo_[] = {
	{"salt", "Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $field(PAData$SaltAndParams, salt)},
	{"params", "[B", nullptr, $PUBLIC | $FINAL, $field(PAData$SaltAndParams, params)},
	{}
};

$MethodInfo _PAData$SaltAndParams_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC, $method(static_cast<void(PAData$SaltAndParams::*)($String*,$bytes*)>(&PAData$SaltAndParams::init$))},
	{}
};

$InnerClassInfo _PAData$SaltAndParams_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.PAData$SaltAndParams", "sun.security.krb5.internal.PAData", "SaltAndParams", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _PAData$SaltAndParams_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.PAData$SaltAndParams",
	"java.lang.Object",
	nullptr,
	_PAData$SaltAndParams_FieldInfo_,
	_PAData$SaltAndParams_MethodInfo_,
	nullptr,
	nullptr,
	_PAData$SaltAndParams_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.PAData"
};

$Object* allocate$PAData$SaltAndParams($Class* clazz) {
	return $of($alloc(PAData$SaltAndParams));
}

void PAData$SaltAndParams::init$($String* s$renamed, $bytes* p) {
	$var($String, s, s$renamed);
	if (s != nullptr && s->isEmpty()) {
		$assign(s, nullptr);
	}
	$set(this, salt, s);
	$set(this, params, p);
}

PAData$SaltAndParams::PAData$SaltAndParams() {
}

$Class* PAData$SaltAndParams::load$($String* name, bool initialize) {
	$loadClass(PAData$SaltAndParams, name, initialize, &_PAData$SaltAndParams_ClassInfo_, allocate$PAData$SaltAndParams);
	return class$;
}

$Class* PAData$SaltAndParams::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun