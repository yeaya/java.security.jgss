#ifndef _javax_security_auth_kerberos_ServicePermission_h_
#define _javax_security_auth_kerberos_ServicePermission_h_
//$ class javax.security.auth.kerberos.ServicePermission
//$ extends java.security.Permission

#include <java/security/Permission.h>

#pragma push_macro("ACCEPT")
#undef ACCEPT
#pragma push_macro("ALL")
#undef ALL
#pragma push_macro("INITIATE")
#undef INITIATE
#pragma push_macro("NONE")
#undef NONE

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
	}
}
namespace java {
	namespace security {
		class PermissionCollection;
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class $export ServicePermission : public ::java::security::Permission {
	$class(ServicePermission, $NO_CLASS_INIT, ::java::security::Permission)
public:
	ServicePermission();
	void init$($String* servicePrincipal, $String* action);
	void init$($String* servicePrincipal, int32_t mask);
	virtual bool equals(Object$* obj) override;
	static $String* getActions(int32_t mask);
	virtual $String* getActions() override;
	int32_t getMask();
	static int32_t getMask($String* action);
	virtual int32_t hashCode() override;
	virtual bool implies(::java::security::Permission* p) override;
	bool impliesIgnoreMask(::javax::security::auth::kerberos::ServicePermission* p);
	void init($String* servicePrincipal, int32_t mask);
	virtual ::java::security::PermissionCollection* newPermissionCollection() override;
	void readObject(::java::io::ObjectInputStream* s);
	void writeObject(::java::io::ObjectOutputStream* s);
	static const int64_t serialVersionUID = (int64_t)0xEEF6BDEAF2C90259;
	static const int32_t INITIATE = 1;
	static const int32_t ACCEPT = 2;
	static const int32_t ALL = 3; // INITIATE | ACCEPT
	static const int32_t NONE = 0;
	int32_t mask = 0;
	$String* actions = nullptr;
};

			} // kerberos
		} // auth
	} // security
} // javax

#pragma pop_macro("ACCEPT")
#pragma pop_macro("ALL")
#pragma pop_macro("INITIATE")
#pragma pop_macro("NONE")

#endif // _javax_security_auth_kerberos_ServicePermission_h_