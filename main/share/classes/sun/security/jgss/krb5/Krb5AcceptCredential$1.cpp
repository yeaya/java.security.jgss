#include <sun/security/jgss/krb5/Krb5AcceptCredential$1.h>

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
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/krb5/Krb5AcceptCredential.h>
#include <sun/security/jgss/krb5/Krb5Util.h>
#include <sun/security/jgss/krb5/ServiceCreds.h>
#include <jcpp.h>

#undef CALLER_ACCEPT
#undef CALLER_UNKNOWN

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessControlContext = ::java::security::AccessControlContext;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $Krb5AcceptCredential = ::sun::security::jgss::krb5::Krb5AcceptCredential;
using $Krb5Util = ::sun::security::jgss::krb5::Krb5Util;
using $ServiceCreds = ::sun::security::jgss::krb5::ServiceCreds;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5AcceptCredential$1_FieldInfo_[] = {
	{"val$acc", "Ljava/security/AccessControlContext;", nullptr, $FINAL | $SYNTHETIC, $field(Krb5AcceptCredential$1, val$acc)},
	{"val$serverPrinc", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(Krb5AcceptCredential$1, val$serverPrinc)},
	{"val$caller", "Lsun/security/jgss/GSSCaller;", nullptr, $FINAL | $SYNTHETIC, $field(Krb5AcceptCredential$1, val$caller)},
	{}
};

$MethodInfo _Krb5AcceptCredential$1_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/GSSCaller;Ljava/lang/String;Ljava/security/AccessControlContext;)V", "()V", 0, $method(static_cast<void(Krb5AcceptCredential$1::*)($GSSCaller*,$String*,$AccessControlContext*)>(&Krb5AcceptCredential$1::init$))},
	{"run", "()Lsun/security/jgss/krb5/ServiceCreds;", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{}
};

$EnclosingMethodInfo _Krb5AcceptCredential$1_EnclosingMethodInfo_ = {
	"sun.security.jgss.krb5.Krb5AcceptCredential",
	"getInstance",
	"(Lsun/security/jgss/GSSCaller;Lsun/security/jgss/krb5/Krb5NameElement;)Lsun/security/jgss/krb5/Krb5AcceptCredential;"
};

$InnerClassInfo _Krb5AcceptCredential$1_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.Krb5AcceptCredential$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Krb5AcceptCredential$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.Krb5AcceptCredential$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_Krb5AcceptCredential$1_FieldInfo_,
	_Krb5AcceptCredential$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Lsun/security/jgss/krb5/ServiceCreds;>;",
	&_Krb5AcceptCredential$1_EnclosingMethodInfo_,
	_Krb5AcceptCredential$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.Krb5AcceptCredential"
};

$Object* allocate$Krb5AcceptCredential$1($Class* clazz) {
	return $of($alloc(Krb5AcceptCredential$1));
}

void Krb5AcceptCredential$1::init$($GSSCaller* val$caller, $String* val$serverPrinc, $AccessControlContext* val$acc) {
	$set(this, val$caller, val$caller);
	$set(this, val$serverPrinc, val$serverPrinc);
	$set(this, val$acc, val$acc);
}

$Object* Krb5AcceptCredential$1::run() {
	$init($GSSCaller);
	return $of($Krb5Util::getServiceCreds(this->val$caller == $GSSCaller::CALLER_UNKNOWN ? $GSSCaller::CALLER_ACCEPT : this->val$caller, this->val$serverPrinc, this->val$acc));
}

Krb5AcceptCredential$1::Krb5AcceptCredential$1() {
}

$Class* Krb5AcceptCredential$1::load$($String* name, bool initialize) {
	$loadClass(Krb5AcceptCredential$1, name, initialize, &_Krb5AcceptCredential$1_ClassInfo_, allocate$Krb5AcceptCredential$1);
	return class$;
}

$Class* Krb5AcceptCredential$1::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun