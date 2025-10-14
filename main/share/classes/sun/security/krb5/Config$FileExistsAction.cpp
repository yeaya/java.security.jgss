#include <sun/security/krb5/Config$FileExistsAction.h>

#include <java/io/File.h>
#include <java/lang/Boolean.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Config.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Config = ::sun::security::krb5::Config;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _Config$FileExistsAction_FieldInfo_[] = {
	{"fileName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Config$FileExistsAction, fileName)},
	{}
};

$MethodInfo _Config$FileExistsAction_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Config$FileExistsAction::*)($String*)>(&Config$FileExistsAction::init$))},
	{"run", "()Ljava/lang/Boolean;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Config$FileExistsAction_InnerClassesInfo_[] = {
	{"sun.security.krb5.Config$FileExistsAction", "sun.security.krb5.Config", "FileExistsAction", $STATIC},
	{}
};

$ClassInfo _Config$FileExistsAction_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.Config$FileExistsAction",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_Config$FileExistsAction_FieldInfo_,
	_Config$FileExistsAction_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Boolean;>;",
	nullptr,
	_Config$FileExistsAction_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.Config"
};

$Object* allocate$Config$FileExistsAction($Class* clazz) {
	return $of($alloc(Config$FileExistsAction));
}

void Config$FileExistsAction::init$($String* fileName) {
	$set(this, fileName, fileName);
}

$Object* Config$FileExistsAction::run() {
	return $of($Boolean::valueOf($$new($File, this->fileName)->exists()));
}

Config$FileExistsAction::Config$FileExistsAction() {
}

$Class* Config$FileExistsAction::load$($String* name, bool initialize) {
	$loadClass(Config$FileExistsAction, name, initialize, &_Config$FileExistsAction_ClassInfo_, allocate$Config$FileExistsAction);
	return class$;
}

$Class* Config$FileExistsAction::class$ = nullptr;

		} // krb5
	} // security
} // sun