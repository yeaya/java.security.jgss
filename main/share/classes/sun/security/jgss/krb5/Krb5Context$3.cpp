#include <sun/security/jgss/krb5/Krb5Context$3.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Set.h>
#include <javax/security/auth/Subject.h>
#include <javax/security/auth/kerberos/KerberosTicket.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Set = ::java::util::Set;
using $Subject = ::javax::security::auth::Subject;
using $KerberosTicket = ::javax::security::auth::kerberos::KerberosTicket;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5Context$3_FieldInfo_[] = {
	{"this$0", "Lsun/security/jgss/krb5/Krb5Context;", nullptr, $FINAL | $SYNTHETIC, $field(Krb5Context$3, this$0)},
	{"val$kt", "Ljavax/security/auth/kerberos/KerberosTicket;", nullptr, $FINAL | $SYNTHETIC, $field(Krb5Context$3, val$kt)},
	{"val$subject", "Ljavax/security/auth/Subject;", nullptr, $FINAL | $SYNTHETIC, $field(Krb5Context$3, val$subject)},
	{}
};

$MethodInfo _Krb5Context$3_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Ljavax/security/auth/Subject;Ljavax/security/auth/kerberos/KerberosTicket;)V", "()V", 0, $method(static_cast<void(Krb5Context$3::*)($Krb5Context*,$Subject*,$KerberosTicket*)>(&Krb5Context$3::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _Krb5Context$3_EnclosingMethodInfo_ = {
	"sun.security.jgss.krb5.Krb5Context",
	"initSecContext",
	"(Ljava/io/InputStream;I)[B"
};

$InnerClassInfo _Krb5Context$3_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.Krb5Context$3", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Krb5Context$3_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.Krb5Context$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_Krb5Context$3_FieldInfo_,
	_Krb5Context$3_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_Krb5Context$3_EnclosingMethodInfo_,
	_Krb5Context$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.Krb5Context"
};

$Object* allocate$Krb5Context$3($Class* clazz) {
	return $of($alloc(Krb5Context$3));
}

void Krb5Context$3::init$($Krb5Context* this$0, $Subject* val$subject, $KerberosTicket* val$kt) {
	$set(this, this$0, this$0);
	$set(this, val$subject, val$subject);
	$set(this, val$kt, val$kt);
}

$Object* Krb5Context$3::run() {
	$nc($($nc(this->val$subject)->getPrivateCredentials()))->add(this->val$kt);
	return $of(nullptr);
}

Krb5Context$3::Krb5Context$3() {
}

$Class* Krb5Context$3::load$($String* name, bool initialize) {
	$loadClass(Krb5Context$3, name, initialize, &_Krb5Context$3_ClassInfo_, allocate$Krb5Context$3);
	return class$;
}

$Class* Krb5Context$3::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun