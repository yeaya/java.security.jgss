#include <sun/security/krb5/JavaxSecurityAuthKerberosAccess.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <javax/security/auth/kerberos/KerberosTicket.h>
#include <javax/security/auth/kerberos/KeyTab.h>
#include <sun/security/krb5/internal/ktab/KeyTab.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;
using $KerberosTicket = ::javax::security::auth::kerberos::KerberosTicket;
using $1KeyTab = ::javax::security::auth::kerberos::KeyTab;
using $KeyTab = ::sun::security::krb5::internal::ktab::KeyTab;

namespace sun {
	namespace security {
		namespace krb5 {

$MethodInfo _JavaxSecurityAuthKerberosAccess_MethodInfo_[] = {
	{"kerberosTicketGetClientAlias", "(Ljavax/security/auth/kerberos/KerberosTicket;)Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC | $ABSTRACT},
	{"kerberosTicketGetProxy", "(Ljavax/security/auth/kerberos/KerberosTicket;)Ljavax/security/auth/kerberos/KerberosTicket;", nullptr, $PUBLIC | $ABSTRACT},
	{"kerberosTicketGetServerAlias", "(Ljavax/security/auth/kerberos/KerberosTicket;)Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC | $ABSTRACT},
	{"kerberosTicketSetClientAlias", "(Ljavax/security/auth/kerberos/KerberosTicket;Ljavax/security/auth/kerberos/KerberosPrincipal;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"kerberosTicketSetProxy", "(Ljavax/security/auth/kerberos/KerberosTicket;Ljavax/security/auth/kerberos/KerberosTicket;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"kerberosTicketSetServerAlias", "(Ljavax/security/auth/kerberos/KerberosTicket;Ljavax/security/auth/kerberos/KerberosPrincipal;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"keyTabTakeSnapshot", "(Ljavax/security/auth/kerberos/KeyTab;)Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _JavaxSecurityAuthKerberosAccess_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.security.krb5.JavaxSecurityAuthKerberosAccess",
	nullptr,
	nullptr,
	nullptr,
	_JavaxSecurityAuthKerberosAccess_MethodInfo_
};

$Object* allocate$JavaxSecurityAuthKerberosAccess($Class* clazz) {
	return $of($alloc(JavaxSecurityAuthKerberosAccess));
}

$Class* JavaxSecurityAuthKerberosAccess::load$($String* name, bool initialize) {
	$loadClass(JavaxSecurityAuthKerberosAccess, name, initialize, &_JavaxSecurityAuthKerberosAccess_ClassInfo_, allocate$JavaxSecurityAuthKerberosAccess);
	return class$;
}

$Class* JavaxSecurityAuthKerberosAccess::class$ = nullptr;

		} // krb5
	} // security
} // sun