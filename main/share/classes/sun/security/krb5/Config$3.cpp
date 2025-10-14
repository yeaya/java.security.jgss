#include <sun/security/krb5/Config$3.h>

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

$FieldInfo _Config$3_FieldInfo_[] = {
	{"this$0", "Lsun/security/krb5/Config;", nullptr, $FINAL | $SYNTHETIC, $field(Config$3, this$0)},
	{}
};

$MethodInfo _Config$3_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/Config;)V", nullptr, 0, $method(static_cast<void(Config$3::*)($Config*)>(&Config$3::init$))},
	{"run", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _Config$3_EnclosingMethodInfo_ = {
	"sun.security.krb5.Config",
	"getKDCList",
	"(Ljava/lang/String;)Ljava/lang/String;"
};

$InnerClassInfo _Config$3_InnerClassesInfo_[] = {
	{"sun.security.krb5.Config$3", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Config$3_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.Config$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_Config$3_FieldInfo_,
	_Config$3_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/String;>;",
	&_Config$3_EnclosingMethodInfo_,
	_Config$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.Config"
};

$Object* allocate$Config$3($Class* clazz) {
	return $of($alloc(Config$3));
}

void Config$3::init$($Config* this$0) {
	$set(this, this$0, this$0);
}

$Object* Config$3::run() {
	$var($String, osname, $System::getProperty("os.name"_s));
	if ($nc(osname)->startsWith("Windows"_s)) {
		$var($String, logonServer, $System::getenv("LOGONSERVER"_s));
		if (logonServer != nullptr && logonServer->startsWith("\\\\"_s)) {
			$assign(logonServer, logonServer->substring(2));
		}
		return $of(logonServer);
	}
	return $of(nullptr);
}

Config$3::Config$3() {
}

$Class* Config$3::load$($String* name, bool initialize) {
	$loadClass(Config$3, name, initialize, &_Config$3_ClassInfo_, allocate$Config$3);
	return class$;
}

$Class* Config$3::class$ = nullptr;

		} // krb5
	} // security
} // sun