#include <sun/security/krb5/SCDynamicStoreConfig$1.h>

#include <java/lang/Boolean.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/SCDynamicStoreConfig.h>
#include <jcpp.h>

using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $SCDynamicStoreConfig = ::sun::security::krb5::SCDynamicStoreConfig;

namespace sun {
	namespace security {
		namespace krb5 {

$MethodInfo _SCDynamicStoreConfig$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(SCDynamicStoreConfig$1::*)()>(&SCDynamicStoreConfig$1::init$))},
	{"run", "()Ljava/lang/Boolean;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _SCDynamicStoreConfig$1_EnclosingMethodInfo_ = {
	"sun.security.krb5.SCDynamicStoreConfig",
	nullptr,
	nullptr
};

$InnerClassInfo _SCDynamicStoreConfig$1_InnerClassesInfo_[] = {
	{"sun.security.krb5.SCDynamicStoreConfig$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SCDynamicStoreConfig$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.SCDynamicStoreConfig$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_SCDynamicStoreConfig$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Boolean;>;",
	&_SCDynamicStoreConfig$1_EnclosingMethodInfo_,
	_SCDynamicStoreConfig$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.SCDynamicStoreConfig"
};

$Object* allocate$SCDynamicStoreConfig$1($Class* clazz) {
	return $of($alloc(SCDynamicStoreConfig$1));
}

void SCDynamicStoreConfig$1::init$() {
}

$Object* SCDynamicStoreConfig$1::run() {
	$beforeCallerSensitive();
	$var($String, osname, $System::getProperty("os.name"_s));
	if ($nc(osname)->contains("OS X"_s)) {
		$System::loadLibrary("osxkrb5"_s);
		return $of($Boolean::valueOf(true));
	}
	return $of($Boolean::valueOf(false));
}

SCDynamicStoreConfig$1::SCDynamicStoreConfig$1() {
}

$Class* SCDynamicStoreConfig$1::load$($String* name, bool initialize) {
	$loadClass(SCDynamicStoreConfig$1, name, initialize, &_SCDynamicStoreConfig$1_ClassInfo_, allocate$SCDynamicStoreConfig$1);
	return class$;
}

$Class* SCDynamicStoreConfig$1::class$ = nullptr;

		} // krb5
	} // security
} // sun