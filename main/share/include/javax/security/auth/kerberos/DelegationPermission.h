#ifndef _javax_security_auth_kerberos_DelegationPermission_h_
#define _javax_security_auth_kerberos_DelegationPermission_h_
//$ class javax.security.auth.kerberos.DelegationPermission
//$ extends java.security.BasicPermission

#include <java/security/BasicPermission.h>

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
	}
}
namespace java {
	namespace security {
		class Permission;
		class PermissionCollection;
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class $import DelegationPermission : public ::java::security::BasicPermission {
	$class(DelegationPermission, $NO_CLASS_INIT, ::java::security::BasicPermission)
public:
	DelegationPermission();
	void init$($String* principals);
	void init$($String* principals, $String* actions);
	virtual bool equals(Object$* obj) override;
	virtual int32_t hashCode() override;
	virtual bool implies(::java::security::Permission* p) override;
	void init($String* target);
	virtual ::java::security::PermissionCollection* newPermissionCollection() override;
	void readObject(::java::io::ObjectInputStream* s);
	void writeObject(::java::io::ObjectOutputStream* s);
	static const int64_t serialVersionUID = (int64_t)0x0C418503874A6612;
	$String* subordinate = nullptr;
	$String* service = nullptr;
};

			} // kerberos
		} // auth
	} // security
} // javax

#endif // _javax_security_auth_kerberos_DelegationPermission_h_