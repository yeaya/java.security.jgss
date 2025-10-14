#include <sun/security/krb5/internal/CredentialsUtil$S4U2Type.h>

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
#include <sun/security/krb5/internal/CredentialsUtil.h>
#include <jcpp.h>

#undef NONE
#undef PROXY
#undef SELF

using $CredentialsUtil$S4U2TypeArray = $Array<::sun::security::krb5::internal::CredentialsUtil$S4U2Type>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CredentialsUtil = ::sun::security::krb5::internal::CredentialsUtil;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _CredentialsUtil$S4U2Type_FieldInfo_[] = {
	{"NONE", "Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(CredentialsUtil$S4U2Type, NONE)},
	{"SELF", "Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(CredentialsUtil$S4U2Type, SELF)},
	{"PROXY", "Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(CredentialsUtil$S4U2Type, PROXY)},
	{"$VALUES", "[Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(CredentialsUtil$S4U2Type, $VALUES)},
	{}
};

$MethodInfo _CredentialsUtil$S4U2Type_MethodInfo_[] = {
	{"$values", "()[Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$CredentialsUtil$S4U2TypeArray*(*)()>(&CredentialsUtil$S4U2Type::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(CredentialsUtil$S4U2Type::*)($String*,int32_t)>(&CredentialsUtil$S4U2Type::init$))},
	{"valueOf", "(Ljava/lang/String;)Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;", nullptr, $PUBLIC | $STATIC, $method(static_cast<CredentialsUtil$S4U2Type*(*)($String*)>(&CredentialsUtil$S4U2Type::valueOf))},
	{"values", "()[Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$CredentialsUtil$S4U2TypeArray*(*)()>(&CredentialsUtil$S4U2Type::values))},
	{}
};

$InnerClassInfo _CredentialsUtil$S4U2Type_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.CredentialsUtil$S4U2Type", "sun.security.krb5.internal.CredentialsUtil", "S4U2Type", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _CredentialsUtil$S4U2Type_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"sun.security.krb5.internal.CredentialsUtil$S4U2Type",
	"java.lang.Enum",
	nullptr,
	_CredentialsUtil$S4U2Type_FieldInfo_,
	_CredentialsUtil$S4U2Type_MethodInfo_,
	"Ljava/lang/Enum<Lsun/security/krb5/internal/CredentialsUtil$S4U2Type;>;",
	nullptr,
	_CredentialsUtil$S4U2Type_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.CredentialsUtil"
};

$Object* allocate$CredentialsUtil$S4U2Type($Class* clazz) {
	return $of($alloc(CredentialsUtil$S4U2Type));
}

CredentialsUtil$S4U2Type* CredentialsUtil$S4U2Type::NONE = nullptr;
CredentialsUtil$S4U2Type* CredentialsUtil$S4U2Type::SELF = nullptr;
CredentialsUtil$S4U2Type* CredentialsUtil$S4U2Type::PROXY = nullptr;
$CredentialsUtil$S4U2TypeArray* CredentialsUtil$S4U2Type::$VALUES = nullptr;

$CredentialsUtil$S4U2TypeArray* CredentialsUtil$S4U2Type::$values() {
	$init(CredentialsUtil$S4U2Type);
	return $new($CredentialsUtil$S4U2TypeArray, {
		CredentialsUtil$S4U2Type::NONE,
		CredentialsUtil$S4U2Type::SELF,
		CredentialsUtil$S4U2Type::PROXY
	});
}

$CredentialsUtil$S4U2TypeArray* CredentialsUtil$S4U2Type::values() {
	$init(CredentialsUtil$S4U2Type);
	return $cast($CredentialsUtil$S4U2TypeArray, CredentialsUtil$S4U2Type::$VALUES->clone());
}

CredentialsUtil$S4U2Type* CredentialsUtil$S4U2Type::valueOf($String* name) {
	$init(CredentialsUtil$S4U2Type);
	return $cast(CredentialsUtil$S4U2Type, $Enum::valueOf(CredentialsUtil$S4U2Type::class$, name));
}

void CredentialsUtil$S4U2Type::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$CredentialsUtil$S4U2Type($Class* class$) {
	$assignStatic(CredentialsUtil$S4U2Type::NONE, $new(CredentialsUtil$S4U2Type, "NONE"_s, 0));
	$assignStatic(CredentialsUtil$S4U2Type::SELF, $new(CredentialsUtil$S4U2Type, "SELF"_s, 1));
	$assignStatic(CredentialsUtil$S4U2Type::PROXY, $new(CredentialsUtil$S4U2Type, "PROXY"_s, 2));
	$assignStatic(CredentialsUtil$S4U2Type::$VALUES, CredentialsUtil$S4U2Type::$values());
}

CredentialsUtil$S4U2Type::CredentialsUtil$S4U2Type() {
}

$Class* CredentialsUtil$S4U2Type::load$($String* name, bool initialize) {
	$loadClass(CredentialsUtil$S4U2Type, name, initialize, &_CredentialsUtil$S4U2Type_ClassInfo_, clinit$CredentialsUtil$S4U2Type, allocate$CredentialsUtil$S4U2Type);
	return class$;
}

$Class* CredentialsUtil$S4U2Type::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun