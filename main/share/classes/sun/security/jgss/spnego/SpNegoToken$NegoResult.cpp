#include <sun/security/jgss/spnego/SpNegoToken$NegoResult.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Enum.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/jgss/spnego/SpNegoToken.h>
#include <jcpp.h>

#undef ACCEPT_COMPLETE
#undef ACCEPT_INCOMPLETE
#undef REJECT

using $SpNegoToken$NegoResultArray = $Array<::sun::security::jgss::spnego::SpNegoToken$NegoResult>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SpNegoToken = ::sun::security::jgss::spnego::SpNegoToken;

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

$FieldInfo _SpNegoToken$NegoResult_FieldInfo_[] = {
	{"ACCEPT_COMPLETE", "Lsun/security/jgss/spnego/SpNegoToken$NegoResult;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SpNegoToken$NegoResult, ACCEPT_COMPLETE)},
	{"ACCEPT_INCOMPLETE", "Lsun/security/jgss/spnego/SpNegoToken$NegoResult;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SpNegoToken$NegoResult, ACCEPT_INCOMPLETE)},
	{"REJECT", "Lsun/security/jgss/spnego/SpNegoToken$NegoResult;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SpNegoToken$NegoResult, REJECT)},
	{"$VALUES", "[Lsun/security/jgss/spnego/SpNegoToken$NegoResult;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(SpNegoToken$NegoResult, $VALUES)},
	{}
};

$MethodInfo _SpNegoToken$NegoResult_MethodInfo_[] = {
	{"$values", "()[Lsun/security/jgss/spnego/SpNegoToken$NegoResult;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$SpNegoToken$NegoResultArray*(*)()>(&SpNegoToken$NegoResult::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(SpNegoToken$NegoResult::*)($String*,int32_t)>(&SpNegoToken$NegoResult::init$))},
	{"valueOf", "(Ljava/lang/String;)Lsun/security/jgss/spnego/SpNegoToken$NegoResult;", nullptr, $PUBLIC | $STATIC, $method(static_cast<SpNegoToken$NegoResult*(*)($String*)>(&SpNegoToken$NegoResult::valueOf))},
	{"values", "()[Lsun/security/jgss/spnego/SpNegoToken$NegoResult;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$SpNegoToken$NegoResultArray*(*)()>(&SpNegoToken$NegoResult::values))},
	{}
};

$InnerClassInfo _SpNegoToken$NegoResult_InnerClassesInfo_[] = {
	{"sun.security.jgss.spnego.SpNegoToken$NegoResult", "sun.security.jgss.spnego.SpNegoToken", "NegoResult", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _SpNegoToken$NegoResult_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"sun.security.jgss.spnego.SpNegoToken$NegoResult",
	"java.lang.Enum",
	nullptr,
	_SpNegoToken$NegoResult_FieldInfo_,
	_SpNegoToken$NegoResult_MethodInfo_,
	"Ljava/lang/Enum<Lsun/security/jgss/spnego/SpNegoToken$NegoResult;>;",
	nullptr,
	_SpNegoToken$NegoResult_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.spnego.SpNegoToken"
};

$Object* allocate$SpNegoToken$NegoResult($Class* clazz) {
	return $of($alloc(SpNegoToken$NegoResult));
}

SpNegoToken$NegoResult* SpNegoToken$NegoResult::ACCEPT_COMPLETE = nullptr;
SpNegoToken$NegoResult* SpNegoToken$NegoResult::ACCEPT_INCOMPLETE = nullptr;
SpNegoToken$NegoResult* SpNegoToken$NegoResult::REJECT = nullptr;
$SpNegoToken$NegoResultArray* SpNegoToken$NegoResult::$VALUES = nullptr;

$SpNegoToken$NegoResultArray* SpNegoToken$NegoResult::$values() {
	$init(SpNegoToken$NegoResult);
	return $new($SpNegoToken$NegoResultArray, {
		SpNegoToken$NegoResult::ACCEPT_COMPLETE,
		SpNegoToken$NegoResult::ACCEPT_INCOMPLETE,
		SpNegoToken$NegoResult::REJECT
	});
}

$SpNegoToken$NegoResultArray* SpNegoToken$NegoResult::values() {
	$init(SpNegoToken$NegoResult);
	return $cast($SpNegoToken$NegoResultArray, SpNegoToken$NegoResult::$VALUES->clone());
}

SpNegoToken$NegoResult* SpNegoToken$NegoResult::valueOf($String* name) {
	$init(SpNegoToken$NegoResult);
	return $cast(SpNegoToken$NegoResult, $Enum::valueOf(SpNegoToken$NegoResult::class$, name));
}

void SpNegoToken$NegoResult::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$SpNegoToken$NegoResult($Class* class$) {
	$assignStatic(SpNegoToken$NegoResult::ACCEPT_COMPLETE, $new(SpNegoToken$NegoResult, "ACCEPT_COMPLETE"_s, 0));
	$assignStatic(SpNegoToken$NegoResult::ACCEPT_INCOMPLETE, $new(SpNegoToken$NegoResult, "ACCEPT_INCOMPLETE"_s, 1));
	$assignStatic(SpNegoToken$NegoResult::REJECT, $new(SpNegoToken$NegoResult, "REJECT"_s, 2));
	$assignStatic(SpNegoToken$NegoResult::$VALUES, SpNegoToken$NegoResult::$values());
}

SpNegoToken$NegoResult::SpNegoToken$NegoResult() {
}

$Class* SpNegoToken$NegoResult::load$($String* name, bool initialize) {
	$loadClass(SpNegoToken$NegoResult, name, initialize, &_SpNegoToken$NegoResult_ClassInfo_, clinit$SpNegoToken$NegoResult, allocate$SpNegoToken$NegoResult);
	return class$;
}

$Class* SpNegoToken$NegoResult::class$ = nullptr;

			} // spnego
		} // jgss
	} // security
} // sun