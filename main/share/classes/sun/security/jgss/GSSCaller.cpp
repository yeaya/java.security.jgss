#include <sun/security/jgss/GSSCaller.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

#undef CALLER_ACCEPT
#undef CALLER_INITIATE
#undef CALLER_UNKNOWN

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _GSSCaller_FieldInfo_[] = {
	{"CALLER_UNKNOWN", "Lsun/security/jgss/GSSCaller;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSCaller, CALLER_UNKNOWN)},
	{"CALLER_INITIATE", "Lsun/security/jgss/GSSCaller;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSCaller, CALLER_INITIATE)},
	{"CALLER_ACCEPT", "Lsun/security/jgss/GSSCaller;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSCaller, CALLER_ACCEPT)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(GSSCaller, name)},
	{}
};

$MethodInfo _GSSCaller_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(GSSCaller::*)($String*)>(&GSSCaller::init$))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _GSSCaller_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.GSSCaller",
	"java.lang.Object",
	nullptr,
	_GSSCaller_FieldInfo_,
	_GSSCaller_MethodInfo_
};

$Object* allocate$GSSCaller($Class* clazz) {
	return $of($alloc(GSSCaller));
}

GSSCaller* GSSCaller::CALLER_UNKNOWN = nullptr;
GSSCaller* GSSCaller::CALLER_INITIATE = nullptr;
GSSCaller* GSSCaller::CALLER_ACCEPT = nullptr;

void GSSCaller::init$($String* s) {
	$set(this, name, s);
}

$String* GSSCaller::toString() {
	return $str({"GSSCaller{"_s, this->name, $$str(u'}')});
}

void clinit$GSSCaller($Class* class$) {
	$assignStatic(GSSCaller::CALLER_UNKNOWN, $new(GSSCaller, "UNKNOWN"_s));
	$assignStatic(GSSCaller::CALLER_INITIATE, $new(GSSCaller, "INITIATE"_s));
	$assignStatic(GSSCaller::CALLER_ACCEPT, $new(GSSCaller, "ACCEPT"_s));
}

GSSCaller::GSSCaller() {
}

$Class* GSSCaller::load$($String* name, bool initialize) {
	$loadClass(GSSCaller, name, initialize, &_GSSCaller_ClassInfo_, clinit$GSSCaller, allocate$GSSCaller);
	return class$;
}

$Class* GSSCaller::class$ = nullptr;

		} // jgss
	} // security
} // sun