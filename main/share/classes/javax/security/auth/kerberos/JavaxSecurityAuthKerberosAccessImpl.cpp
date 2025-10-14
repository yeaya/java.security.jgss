#include <javax/security/auth/kerberos/JavaxSecurityAuthKerberosAccessImpl.h>

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
using $JavaxSecurityAuthKerberosAccess = ::sun::security::krb5::JavaxSecurityAuthKerberosAccess;
using $KeyTab = ::sun::security::krb5::internal::ktab::KeyTab;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$MethodInfo _JavaxSecurityAuthKerberosAccessImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(JavaxSecurityAuthKerberosAccessImpl::*)()>(&JavaxSecurityAuthKerberosAccessImpl::init$))},
	{"kerberosTicketGetClientAlias", "(Ljavax/security/auth/kerberos/KerberosTicket;)Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC},
	{"kerberosTicketGetProxy", "(Ljavax/security/auth/kerberos/KerberosTicket;)Ljavax/security/auth/kerberos/KerberosTicket;", nullptr, $PUBLIC},
	{"kerberosTicketGetServerAlias", "(Ljavax/security/auth/kerberos/KerberosTicket;)Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC},
	{"kerberosTicketSetClientAlias", "(Ljavax/security/auth/kerberos/KerberosTicket;Ljavax/security/auth/kerberos/KerberosPrincipal;)V", nullptr, $PUBLIC},
	{"kerberosTicketSetProxy", "(Ljavax/security/auth/kerberos/KerberosTicket;Ljavax/security/auth/kerberos/KerberosTicket;)V", nullptr, $PUBLIC},
	{"kerberosTicketSetServerAlias", "(Ljavax/security/auth/kerberos/KerberosTicket;Ljavax/security/auth/kerberos/KerberosPrincipal;)V", nullptr, $PUBLIC},
	{"keyTabTakeSnapshot", "(Ljavax/security/auth/kerberos/KeyTab;)Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _JavaxSecurityAuthKerberosAccessImpl_ClassInfo_ = {
	$ACC_SUPER,
	"javax.security.auth.kerberos.JavaxSecurityAuthKerberosAccessImpl",
	"java.lang.Object",
	"sun.security.krb5.JavaxSecurityAuthKerberosAccess",
	nullptr,
	_JavaxSecurityAuthKerberosAccessImpl_MethodInfo_
};

$Object* allocate$JavaxSecurityAuthKerberosAccessImpl($Class* clazz) {
	return $of($alloc(JavaxSecurityAuthKerberosAccessImpl));
}

void JavaxSecurityAuthKerberosAccessImpl::init$() {
}

$KeyTab* JavaxSecurityAuthKerberosAccessImpl::keyTabTakeSnapshot($1KeyTab* ktab) {
	return $nc(ktab)->takeSnapshot();
}

$KerberosPrincipal* JavaxSecurityAuthKerberosAccessImpl::kerberosTicketGetClientAlias($KerberosTicket* t) {
	return $nc(t)->clientAlias;
}

void JavaxSecurityAuthKerberosAccessImpl::kerberosTicketSetClientAlias($KerberosTicket* t, $KerberosPrincipal* a) {
	$set($nc(t), clientAlias, a);
}

$KerberosPrincipal* JavaxSecurityAuthKerberosAccessImpl::kerberosTicketGetServerAlias($KerberosTicket* t) {
	return $nc(t)->serverAlias;
}

void JavaxSecurityAuthKerberosAccessImpl::kerberosTicketSetServerAlias($KerberosTicket* t, $KerberosPrincipal* a) {
	$set($nc(t), serverAlias, a);
}

$KerberosTicket* JavaxSecurityAuthKerberosAccessImpl::kerberosTicketGetProxy($KerberosTicket* t) {
	return $nc(t)->proxy;
}

void JavaxSecurityAuthKerberosAccessImpl::kerberosTicketSetProxy($KerberosTicket* t, $KerberosTicket* p) {
	$set($nc(t), proxy, p);
}

JavaxSecurityAuthKerberosAccessImpl::JavaxSecurityAuthKerberosAccessImpl() {
}

$Class* JavaxSecurityAuthKerberosAccessImpl::load$($String* name, bool initialize) {
	$loadClass(JavaxSecurityAuthKerberosAccessImpl, name, initialize, &_JavaxSecurityAuthKerberosAccessImpl_ClassInfo_, allocate$JavaxSecurityAuthKerberosAccessImpl);
	return class$;
}

$Class* JavaxSecurityAuthKerberosAccessImpl::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax