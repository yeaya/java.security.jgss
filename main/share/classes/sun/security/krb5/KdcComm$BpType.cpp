#include <sun/security/krb5/KdcComm$BpType.h>

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
#include <sun/security/krb5/KdcComm.h>
#include <jcpp.h>

#undef NONE
#undef TRY_LAST
#undef TRY_LESS

using $KdcComm$BpTypeArray = $Array<::sun::security::krb5::KdcComm$BpType>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KdcComm = ::sun::security::krb5::KdcComm;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KdcComm$BpType_FieldInfo_[] = {
	{"NONE", "Lsun/security/krb5/KdcComm$BpType;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(KdcComm$BpType, NONE)},
	{"TRY_LAST", "Lsun/security/krb5/KdcComm$BpType;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(KdcComm$BpType, TRY_LAST)},
	{"TRY_LESS", "Lsun/security/krb5/KdcComm$BpType;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(KdcComm$BpType, TRY_LESS)},
	{"$VALUES", "[Lsun/security/krb5/KdcComm$BpType;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(KdcComm$BpType, $VALUES)},
	{}
};

$MethodInfo _KdcComm$BpType_MethodInfo_[] = {
	{"$values", "()[Lsun/security/krb5/KdcComm$BpType;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$KdcComm$BpTypeArray*(*)()>(&KdcComm$BpType::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(KdcComm$BpType::*)($String*,int32_t)>(&KdcComm$BpType::init$))},
	{"valueOf", "(Ljava/lang/String;)Lsun/security/krb5/KdcComm$BpType;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KdcComm$BpType*(*)($String*)>(&KdcComm$BpType::valueOf))},
	{"values", "()[Lsun/security/krb5/KdcComm$BpType;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$KdcComm$BpTypeArray*(*)()>(&KdcComm$BpType::values))},
	{}
};

$InnerClassInfo _KdcComm$BpType_InnerClassesInfo_[] = {
	{"sun.security.krb5.KdcComm$BpType", "sun.security.krb5.KdcComm", "BpType", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _KdcComm$BpType_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"sun.security.krb5.KdcComm$BpType",
	"java.lang.Enum",
	nullptr,
	_KdcComm$BpType_FieldInfo_,
	_KdcComm$BpType_MethodInfo_,
	"Ljava/lang/Enum<Lsun/security/krb5/KdcComm$BpType;>;",
	nullptr,
	_KdcComm$BpType_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.KdcComm"
};

$Object* allocate$KdcComm$BpType($Class* clazz) {
	return $of($alloc(KdcComm$BpType));
}

KdcComm$BpType* KdcComm$BpType::NONE = nullptr;
KdcComm$BpType* KdcComm$BpType::TRY_LAST = nullptr;
KdcComm$BpType* KdcComm$BpType::TRY_LESS = nullptr;
$KdcComm$BpTypeArray* KdcComm$BpType::$VALUES = nullptr;

$KdcComm$BpTypeArray* KdcComm$BpType::$values() {
	$init(KdcComm$BpType);
	return $new($KdcComm$BpTypeArray, {
		KdcComm$BpType::NONE,
		KdcComm$BpType::TRY_LAST,
		KdcComm$BpType::TRY_LESS
	});
}

$KdcComm$BpTypeArray* KdcComm$BpType::values() {
	$init(KdcComm$BpType);
	return $cast($KdcComm$BpTypeArray, KdcComm$BpType::$VALUES->clone());
}

KdcComm$BpType* KdcComm$BpType::valueOf($String* name) {
	$init(KdcComm$BpType);
	return $cast(KdcComm$BpType, $Enum::valueOf(KdcComm$BpType::class$, name));
}

void KdcComm$BpType::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$KdcComm$BpType($Class* class$) {
	$assignStatic(KdcComm$BpType::NONE, $new(KdcComm$BpType, "NONE"_s, 0));
	$assignStatic(KdcComm$BpType::TRY_LAST, $new(KdcComm$BpType, "TRY_LAST"_s, 1));
	$assignStatic(KdcComm$BpType::TRY_LESS, $new(KdcComm$BpType, "TRY_LESS"_s, 2));
	$assignStatic(KdcComm$BpType::$VALUES, KdcComm$BpType::$values());
}

KdcComm$BpType::KdcComm$BpType() {
}

$Class* KdcComm$BpType::load$($String* name, bool initialize) {
	$loadClass(KdcComm$BpType, name, initialize, &_KdcComm$BpType_ClassInfo_, clinit$KdcComm$BpType, allocate$KdcComm$BpType);
	return class$;
}

$Class* KdcComm$BpType::class$ = nullptr;

		} // krb5
	} // security
} // sun