#include <javax/security/auth/kerberos/KrbServicePermissionCollection$1.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Permission.h>
#include <javax/security/auth/kerberos/KrbServicePermissionCollection.h>
#include <javax/security/auth/kerberos/ServicePermission.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Permission = ::java::security::Permission;
using $BiFunction = ::java::util::function::BiFunction;
using $KrbServicePermissionCollection = ::javax::security::auth::kerberos::KrbServicePermissionCollection;
using $ServicePermission = ::javax::security::auth::kerberos::ServicePermission;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _KrbServicePermissionCollection$1_FieldInfo_[] = {
	{"this$0", "Ljavax/security/auth/kerberos/KrbServicePermissionCollection;", nullptr, $FINAL | $SYNTHETIC, $field(KrbServicePermissionCollection$1, this$0)},
	{"val$princName", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(KrbServicePermissionCollection$1, val$princName)},
	{}
};

$MethodInfo _KrbServicePermissionCollection$1_MethodInfo_[] = {
	{"<init>", "(Ljavax/security/auth/kerberos/KrbServicePermissionCollection;Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(KrbServicePermissionCollection$1::*)($KrbServicePermissionCollection*,$String*)>(&KrbServicePermissionCollection$1::init$))},
	{"apply", "(Ljava/security/Permission;Ljava/security/Permission;)Ljava/security/Permission;", nullptr, $PUBLIC},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{}
};

$EnclosingMethodInfo _KrbServicePermissionCollection$1_EnclosingMethodInfo_ = {
	"javax.security.auth.kerberos.KrbServicePermissionCollection",
	"add",
	"(Ljava/security/Permission;)V"
};

$InnerClassInfo _KrbServicePermissionCollection$1_InnerClassesInfo_[] = {
	{"javax.security.auth.kerberos.KrbServicePermissionCollection$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _KrbServicePermissionCollection$1_ClassInfo_ = {
	$ACC_SUPER,
	"javax.security.auth.kerberos.KrbServicePermissionCollection$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	_KrbServicePermissionCollection$1_FieldInfo_,
	_KrbServicePermissionCollection$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/function/BiFunction<Ljava/security/Permission;Ljava/security/Permission;Ljava/security/Permission;>;",
	&_KrbServicePermissionCollection$1_EnclosingMethodInfo_,
	_KrbServicePermissionCollection$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.security.auth.kerberos.KrbServicePermissionCollection"
};

$Object* allocate$KrbServicePermissionCollection$1($Class* clazz) {
	return $of($alloc(KrbServicePermissionCollection$1));
}

void KrbServicePermissionCollection$1::init$($KrbServicePermissionCollection* this$0, $String* val$princName) {
	$set(this, this$0, this$0);
	$set(this, val$princName, val$princName);
}

$Permission* KrbServicePermissionCollection$1::apply($Permission* existingVal, $Permission* newVal) {
	int32_t oldMask = $nc(($cast($ServicePermission, existingVal)))->getMask();
	int32_t newMask = $nc(($cast($ServicePermission, newVal)))->getMask();
	if (oldMask != newMask) {
		int32_t effective = oldMask | newMask;
		if (effective == newMask) {
			return newVal;
		}
		if (effective != oldMask) {
			return $new($ServicePermission, this->val$princName, effective);
		}
	}
	return existingVal;
}

$Object* KrbServicePermissionCollection$1::apply(Object$* existingVal, Object$* newVal) {
	return $of(this->apply($cast($Permission, existingVal), $cast($Permission, newVal)));
}

KrbServicePermissionCollection$1::KrbServicePermissionCollection$1() {
}

$Class* KrbServicePermissionCollection$1::load$($String* name, bool initialize) {
	$loadClass(KrbServicePermissionCollection$1, name, initialize, &_KrbServicePermissionCollection$1_ClassInfo_, allocate$KrbServicePermissionCollection$1);
	return class$;
}

$Class* KrbServicePermissionCollection$1::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax