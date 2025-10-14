#ifndef _javax_security_auth_kerberos_KrbServicePermissionCollection$1_h_
#define _javax_security_auth_kerberos_KrbServicePermissionCollection$1_h_
//$ class javax.security.auth.kerberos.KrbServicePermissionCollection$1
//$ extends java.util.function.BiFunction

#include <java/util/function/BiFunction.h>

namespace java {
	namespace security {
		class Permission;
	}
}
namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KrbServicePermissionCollection;
			}
		}
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class KrbServicePermissionCollection$1 : public ::java::util::function::BiFunction {
	$class(KrbServicePermissionCollection$1, $NO_CLASS_INIT, ::java::util::function::BiFunction)
public:
	KrbServicePermissionCollection$1();
	void init$(::javax::security::auth::kerberos::KrbServicePermissionCollection* this$0, $String* val$princName);
	virtual ::java::security::Permission* apply(::java::security::Permission* existingVal, ::java::security::Permission* newVal);
	virtual $Object* apply(Object$* existingVal, Object$* newVal) override;
	::javax::security::auth::kerberos::KrbServicePermissionCollection* this$0 = nullptr;
	$String* val$princName = nullptr;
};

			} // kerberos
		} // auth
	} // security
} // javax

#endif // _javax_security_auth_kerberos_KrbServicePermissionCollection$1_h_