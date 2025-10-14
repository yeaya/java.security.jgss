#include <sun/security/krb5/Config$1.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/Void.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <sun/security/krb5/Config.h>
#include <jcpp.h>

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $Files = ::java::nio::file::Files;
using $LinkOption = ::java::nio::file::LinkOption;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $Config = ::sun::security::krb5::Config;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _Config$1_FieldInfo_[] = {
	{"this$0", "Lsun/security/krb5/Config;", nullptr, $FINAL | $SYNTHETIC, $field(Config$1, this$0)},
	{"val$dupsCheck", "Ljava/util/Set;", nullptr, $FINAL | $SYNTHETIC, $field(Config$1, val$dupsCheck)},
	{"val$raw", "Ljava/util/List;", nullptr, $FINAL | $SYNTHETIC, $field(Config$1, val$raw)},
	{"val$fullp", "Ljava/nio/file/Path;", nullptr, $FINAL | $SYNTHETIC, $field(Config$1, val$fullp)},
	{"val$fileName", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(Config$1, val$fileName)},
	{}
};

$MethodInfo _Config$1_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/Config;Ljava/lang/String;Ljava/nio/file/Path;Ljava/util/List;Ljava/util/Set;)V", "()V", 0, $method(static_cast<void(Config$1::*)($Config*,$String*,$Path*,$List*,$Set*)>(&Config$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$EnclosingMethodInfo _Config$1_EnclosingMethodInfo_ = {
	"sun.security.krb5.Config",
	"loadConfigFile",
	"(Ljava/lang/String;)Ljava/util/List;"
};

$InnerClassInfo _Config$1_InnerClassesInfo_[] = {
	{"sun.security.krb5.Config$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Config$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.Config$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_Config$1_FieldInfo_,
	_Config$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/Void;>;",
	&_Config$1_EnclosingMethodInfo_,
	_Config$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.Config"
};

$Object* allocate$Config$1($Class* clazz) {
	return $of($alloc(Config$1));
}

void Config$1::init$($Config* this$0, $String* val$fileName, $Path* val$fullp, $List* val$raw, $Set* val$dupsCheck) {
	$set(this, this$0, this$0);
	$set(this, val$fileName, val$fileName);
	$set(this, val$fullp, val$fullp);
	$set(this, val$raw, val$raw);
	$set(this, val$dupsCheck, val$dupsCheck);
}

$Object* Config$1::run() {
	$var($Path, path, $Paths::get(this->val$fileName, $$new($StringArray, 0)));
	if (!$Files::exists(path, $$new($LinkOptionArray, 0))) {
		return $of(nullptr);
	} else {
		return $of($Config::readConfigFileLines(this->val$fullp, this->val$raw, this->val$dupsCheck));
	}
}

Config$1::Config$1() {
}

$Class* Config$1::load$($String* name, bool initialize) {
	$loadClass(Config$1, name, initialize, &_Config$1_ClassInfo_, allocate$Config$1);
	return class$;
}

$Class* Config$1::class$ = nullptr;

		} // krb5
	} // security
} // sun