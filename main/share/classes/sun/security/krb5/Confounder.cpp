#include <sun/security/krb5/Confounder.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/SecureRandom.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecureRandom = ::java::security::SecureRandom;
using $Random = ::java::util::Random;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _Confounder_FieldInfo_[] = {
	{"srand", "Ljava/security/SecureRandom;", nullptr, $PRIVATE | $STATIC, $staticField(Confounder, srand)},
	{}
};

$MethodInfo _Confounder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Confounder::*)()>(&Confounder::init$))},
	{"bytes", "(I)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)(int32_t)>(&Confounder::bytes))},
	{"intValue", "()I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)()>(&Confounder::intValue))},
	{"longValue", "()J", nullptr, $PUBLIC | $STATIC, $method(static_cast<int64_t(*)()>(&Confounder::longValue))},
	{}
};

$ClassInfo _Confounder_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.Confounder",
	"java.lang.Object",
	nullptr,
	_Confounder_FieldInfo_,
	_Confounder_MethodInfo_
};

$Object* allocate$Confounder($Class* clazz) {
	return $of($alloc(Confounder));
}

$SecureRandom* Confounder::srand = nullptr;

void Confounder::init$() {
}

$bytes* Confounder::bytes(int32_t size) {
	$init(Confounder);
	$var($bytes, data, $new($bytes, size));
	$nc(Confounder::srand)->nextBytes(data);
	return data;
}

int32_t Confounder::intValue() {
	$init(Confounder);
	return $nc(Confounder::srand)->nextInt();
}

int64_t Confounder::longValue() {
	$init(Confounder);
	return $nc(Confounder::srand)->nextLong();
}

void clinit$Confounder($Class* class$) {
	$assignStatic(Confounder::srand, $new($SecureRandom));
}

Confounder::Confounder() {
}

$Class* Confounder::load$($String* name, bool initialize) {
	$loadClass(Confounder, name, initialize, &_Confounder_ClassInfo_, clinit$Confounder, allocate$Confounder);
	return class$;
}

$Class* Confounder::class$ = nullptr;

		} // krb5
	} // security
} // sun