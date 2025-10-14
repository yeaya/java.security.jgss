#include <sun/security/krb5/Config$2.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Config.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Config = ::sun::security::krb5::Config;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _Config$2_FieldInfo_[] = {
	{"this$0", "Lsun/security/krb5/Config;", nullptr, $FINAL | $SYNTHETIC, $field(Config$2, this$0)},
	{}
};

$MethodInfo _Config$2_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/Config;)V", nullptr, 0, $method(static_cast<void(Config$2::*)($Config*)>(&Config$2::init$))},
	{"run", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _Config$2_EnclosingMethodInfo_ = {
	"sun.security.krb5.Config",
	"getDefaultRealm",
	"()Ljava/lang/String;"
};

$InnerClassInfo _Config$2_InnerClassesInfo_[] = {
	{"sun.security.krb5.Config$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Config$2_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.Config$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_Config$2_FieldInfo_,
	_Config$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/String;>;",
	&_Config$2_EnclosingMethodInfo_,
	_Config$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.Config"
};

$Object* allocate$Config$2($Class* clazz) {
	return $of($alloc(Config$2));
}

void Config$2::init$($Config* this$0) {
	$set(this, this$0, this$0);
}

$Object* Config$2::run() {
	$var($String, osname, $System::getProperty("os.name"_s));
	if ($nc(osname)->startsWith("Windows"_s)) {
		return $of($System::getenv("USERDNSDOMAIN"_s));
	}
	return $of(nullptr);
}

Config$2::Config$2() {
}

$Class* Config$2::load$($String* name, bool initialize) {
	$loadClass(Config$2, name, initialize, &_Config$2_ClassInfo_, allocate$Config$2);
	return class$;
}

$Class* Config$2::class$ = nullptr;

		} // krb5
	} // security
} // sun