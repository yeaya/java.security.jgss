#include <sun/security/krb5/Credentials$1.h>

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
#include <sun/security/krb5/Credentials.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Credentials = ::sun::security::krb5::Credentials;

namespace sun {
	namespace security {
		namespace krb5 {

$MethodInfo _Credentials$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Credentials$1::*)()>(&Credentials$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _Credentials$1_EnclosingMethodInfo_ = {
	"sun.security.krb5.Credentials",
	"ensureLoaded",
	"()V"
};

$InnerClassInfo _Credentials$1_InnerClassesInfo_[] = {
	{"sun.security.krb5.Credentials$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Credentials$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.Credentials$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_Credentials$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_Credentials$1_EnclosingMethodInfo_,
	_Credentials$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.Credentials"
};

$Object* allocate$Credentials$1($Class* clazz) {
	return $of($alloc(Credentials$1));
}

void Credentials$1::init$() {
}

$Object* Credentials$1::run() {
	$beforeCallerSensitive();
	if ($nc($($System::getProperty("os.name"_s)))->contains("OS X"_s)) {
		$System::loadLibrary("osxkrb5"_s);
	} else {
		$System::loadLibrary("w2k_lsa_auth"_s);
	}
	return $of(nullptr);
}

Credentials$1::Credentials$1() {
}

$Class* Credentials$1::load$($String* name, bool initialize) {
	$loadClass(Credentials$1, name, initialize, &_Credentials$1_ClassInfo_, allocate$Credentials$1);
	return class$;
}

$Class* Credentials$1::class$ = nullptr;

		} // krb5
	} // security
} // sun