#include <sun/security/krb5/KrbAsReqBuilder$State.h>

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
#include <sun/security/krb5/KrbAsReqBuilder.h>
#include <jcpp.h>

#undef DESTROYED
#undef INIT
#undef REQ_OK

using $KrbAsReqBuilder$StateArray = $Array<::sun::security::krb5::KrbAsReqBuilder$State>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KrbAsReqBuilder = ::sun::security::krb5::KrbAsReqBuilder;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbAsReqBuilder$State_FieldInfo_[] = {
	{"INIT", "Lsun/security/krb5/KrbAsReqBuilder$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(KrbAsReqBuilder$State, INIT)},
	{"REQ_OK", "Lsun/security/krb5/KrbAsReqBuilder$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(KrbAsReqBuilder$State, REQ_OK)},
	{"DESTROYED", "Lsun/security/krb5/KrbAsReqBuilder$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(KrbAsReqBuilder$State, DESTROYED)},
	{"$VALUES", "[Lsun/security/krb5/KrbAsReqBuilder$State;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(KrbAsReqBuilder$State, $VALUES)},
	{}
};

$MethodInfo _KrbAsReqBuilder$State_MethodInfo_[] = {
	{"$values", "()[Lsun/security/krb5/KrbAsReqBuilder$State;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$KrbAsReqBuilder$StateArray*(*)()>(&KrbAsReqBuilder$State::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(KrbAsReqBuilder$State::*)($String*,int32_t)>(&KrbAsReqBuilder$State::init$))},
	{"valueOf", "(Ljava/lang/String;)Lsun/security/krb5/KrbAsReqBuilder$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KrbAsReqBuilder$State*(*)($String*)>(&KrbAsReqBuilder$State::valueOf))},
	{"values", "()[Lsun/security/krb5/KrbAsReqBuilder$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$KrbAsReqBuilder$StateArray*(*)()>(&KrbAsReqBuilder$State::values))},
	{}
};

$InnerClassInfo _KrbAsReqBuilder$State_InnerClassesInfo_[] = {
	{"sun.security.krb5.KrbAsReqBuilder$State", "sun.security.krb5.KrbAsReqBuilder", "State", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _KrbAsReqBuilder$State_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"sun.security.krb5.KrbAsReqBuilder$State",
	"java.lang.Enum",
	nullptr,
	_KrbAsReqBuilder$State_FieldInfo_,
	_KrbAsReqBuilder$State_MethodInfo_,
	"Ljava/lang/Enum<Lsun/security/krb5/KrbAsReqBuilder$State;>;",
	nullptr,
	_KrbAsReqBuilder$State_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.KrbAsReqBuilder"
};

$Object* allocate$KrbAsReqBuilder$State($Class* clazz) {
	return $of($alloc(KrbAsReqBuilder$State));
}

KrbAsReqBuilder$State* KrbAsReqBuilder$State::INIT = nullptr;
KrbAsReqBuilder$State* KrbAsReqBuilder$State::REQ_OK = nullptr;
KrbAsReqBuilder$State* KrbAsReqBuilder$State::DESTROYED = nullptr;
$KrbAsReqBuilder$StateArray* KrbAsReqBuilder$State::$VALUES = nullptr;

$KrbAsReqBuilder$StateArray* KrbAsReqBuilder$State::$values() {
	$init(KrbAsReqBuilder$State);
	return $new($KrbAsReqBuilder$StateArray, {
		KrbAsReqBuilder$State::INIT,
		KrbAsReqBuilder$State::REQ_OK,
		KrbAsReqBuilder$State::DESTROYED
	});
}

$KrbAsReqBuilder$StateArray* KrbAsReqBuilder$State::values() {
	$init(KrbAsReqBuilder$State);
	return $cast($KrbAsReqBuilder$StateArray, KrbAsReqBuilder$State::$VALUES->clone());
}

KrbAsReqBuilder$State* KrbAsReqBuilder$State::valueOf($String* name) {
	$init(KrbAsReqBuilder$State);
	return $cast(KrbAsReqBuilder$State, $Enum::valueOf(KrbAsReqBuilder$State::class$, name));
}

void KrbAsReqBuilder$State::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$KrbAsReqBuilder$State($Class* class$) {
	$assignStatic(KrbAsReqBuilder$State::INIT, $new(KrbAsReqBuilder$State, "INIT"_s, 0));
	$assignStatic(KrbAsReqBuilder$State::REQ_OK, $new(KrbAsReqBuilder$State, "REQ_OK"_s, 1));
	$assignStatic(KrbAsReqBuilder$State::DESTROYED, $new(KrbAsReqBuilder$State, "DESTROYED"_s, 2));
	$assignStatic(KrbAsReqBuilder$State::$VALUES, KrbAsReqBuilder$State::$values());
}

KrbAsReqBuilder$State::KrbAsReqBuilder$State() {
}

$Class* KrbAsReqBuilder$State::load$($String* name, bool initialize) {
	$loadClass(KrbAsReqBuilder$State, name, initialize, &_KrbAsReqBuilder$State_ClassInfo_, clinit$KrbAsReqBuilder$State, allocate$KrbAsReqBuilder$State);
	return class$;
}

$Class* KrbAsReqBuilder$State::class$ = nullptr;

		} // krb5
	} // security
} // sun