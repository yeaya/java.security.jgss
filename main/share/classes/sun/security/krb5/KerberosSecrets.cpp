#include <sun/security/krb5/KerberosSecrets.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <javax/security/auth/kerberos/KeyTab.h>
#include <sun/security/krb5/JavaxSecurityAuthKerberosAccess.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $KeyTab = ::javax::security::auth::kerberos::KeyTab;
using $JavaxSecurityAuthKerberosAccess = ::sun::security::krb5::JavaxSecurityAuthKerberosAccess;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KerberosSecrets_FieldInfo_[] = {
	{"javaxSecurityAuthKerberosAccess", "Lsun/security/krb5/JavaxSecurityAuthKerberosAccess;", nullptr, $PRIVATE | $STATIC, $staticField(KerberosSecrets, javaxSecurityAuthKerberosAccess)},
	{}
};

$MethodInfo _KerberosSecrets_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(KerberosSecrets::*)()>(&KerberosSecrets::init$))},
	{"getJavaxSecurityAuthKerberosAccess", "()Lsun/security/krb5/JavaxSecurityAuthKerberosAccess;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$JavaxSecurityAuthKerberosAccess*(*)()>(&KerberosSecrets::getJavaxSecurityAuthKerberosAccess))},
	{"setJavaxSecurityAuthKerberosAccess", "(Lsun/security/krb5/JavaxSecurityAuthKerberosAccess;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($JavaxSecurityAuthKerberosAccess*)>(&KerberosSecrets::setJavaxSecurityAuthKerberosAccess))},
	{}
};

$ClassInfo _KerberosSecrets_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.KerberosSecrets",
	"java.lang.Object",
	nullptr,
	_KerberosSecrets_FieldInfo_,
	_KerberosSecrets_MethodInfo_
};

$Object* allocate$KerberosSecrets($Class* clazz) {
	return $of($alloc(KerberosSecrets));
}

$JavaxSecurityAuthKerberosAccess* KerberosSecrets::javaxSecurityAuthKerberosAccess = nullptr;

void KerberosSecrets::init$() {
}

void KerberosSecrets::setJavaxSecurityAuthKerberosAccess($JavaxSecurityAuthKerberosAccess* jsaka) {
	$init(KerberosSecrets);
	$assignStatic(KerberosSecrets::javaxSecurityAuthKerberosAccess, jsaka);
}

$JavaxSecurityAuthKerberosAccess* KerberosSecrets::getJavaxSecurityAuthKerberosAccess() {
	$load(KerberosSecrets);
	$beforeCallerSensitive();
	$init(KerberosSecrets);
	if (KerberosSecrets::javaxSecurityAuthKerberosAccess == nullptr) {
		try {
			$load($KeyTab);
			$nc($($MethodHandles::lookup()))->ensureInitialized($KeyTab::class$);
		} catch ($IllegalAccessException&) {
			$catch();
		}
	}
	return KerberosSecrets::javaxSecurityAuthKerberosAccess;
}

KerberosSecrets::KerberosSecrets() {
}

$Class* KerberosSecrets::load$($String* name, bool initialize) {
	$loadClass(KerberosSecrets, name, initialize, &_KerberosSecrets_ClassInfo_, allocate$KerberosSecrets);
	return class$;
}

$Class* KerberosSecrets::class$ = nullptr;

		} // krb5
	} // security
} // sun