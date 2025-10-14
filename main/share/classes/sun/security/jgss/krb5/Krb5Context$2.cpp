#include <sun/security/jgss/krb5/Krb5Context$2.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/AccessControlContext.h>
#include <javax/security/auth/Subject.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessControlContext = ::java::security::AccessControlContext;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Subject = ::javax::security::auth::Subject;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5Context$2_FieldInfo_[] = {
	{"this$0", "Lsun/security/jgss/krb5/Krb5Context;", nullptr, $FINAL | $SYNTHETIC, $field(Krb5Context$2, this$0)},
	{"val$acc", "Ljava/security/AccessControlContext;", nullptr, $FINAL | $SYNTHETIC, $field(Krb5Context$2, val$acc)},
	{}
};

$MethodInfo _Krb5Context$2_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Ljava/security/AccessControlContext;)V", "()V", 0, $method(static_cast<void(Krb5Context$2::*)($Krb5Context*,$AccessControlContext*)>(&Krb5Context$2::init$))},
	{"run", "()Ljavax/security/auth/Subject;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _Krb5Context$2_EnclosingMethodInfo_ = {
	"sun.security.jgss.krb5.Krb5Context",
	"initSecContext",
	"(Ljava/io/InputStream;I)[B"
};

$InnerClassInfo _Krb5Context$2_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.Krb5Context$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Krb5Context$2_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.Krb5Context$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_Krb5Context$2_FieldInfo_,
	_Krb5Context$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljavax/security/auth/Subject;>;",
	&_Krb5Context$2_EnclosingMethodInfo_,
	_Krb5Context$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.Krb5Context"
};

$Object* allocate$Krb5Context$2($Class* clazz) {
	return $of($alloc(Krb5Context$2));
}

void Krb5Context$2::init$($Krb5Context* this$0, $AccessControlContext* val$acc) {
	$set(this, this$0, this$0);
	$set(this, val$acc, val$acc);
}

$Object* Krb5Context$2::run() {
	return $of(($Subject::getSubject(this->val$acc)));
}

Krb5Context$2::Krb5Context$2() {
}

$Class* Krb5Context$2::load$($String* name, bool initialize) {
	$loadClass(Krb5Context$2, name, initialize, &_Krb5Context$2_ClassInfo_, allocate$Krb5Context$2);
	return class$;
}

$Class* Krb5Context$2::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun