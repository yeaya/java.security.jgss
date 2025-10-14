#ifndef _javax_security_auth_kerberos_KerberosPrincipal_h_
#define _javax_security_auth_kerberos_KerberosPrincipal_h_
//$ class javax.security.auth.kerberos.KerberosPrincipal
//$ extends java.security.Principal
//$ implements java.io.Serializable

#include <java/io/Serializable.h>
#include <java/security/Principal.h>

#pragma push_macro("KRB_NT_ENTERPRISE")
#undef KRB_NT_ENTERPRISE
#pragma push_macro("KRB_NT_PRINCIPAL")
#undef KRB_NT_PRINCIPAL
#pragma push_macro("KRB_NT_SRV_HST")
#undef KRB_NT_SRV_HST
#pragma push_macro("KRB_NT_SRV_INST")
#undef KRB_NT_SRV_INST
#pragma push_macro("KRB_NT_SRV_XHST")
#undef KRB_NT_SRV_XHST
#pragma push_macro("KRB_NT_UID")
#undef KRB_NT_UID
#pragma push_macro("KRB_NT_UNKNOWN")
#undef KRB_NT_UNKNOWN

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class $export KerberosPrincipal : public ::java::security::Principal, public ::java::io::Serializable {
	$class(KerberosPrincipal, $NO_CLASS_INIT, ::java::security::Principal, ::java::io::Serializable)
public:
	KerberosPrincipal();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	virtual $Object* clone() override;
	virtual void finalize() override;
	void init$($String* name);
	void init$($String* name, int32_t nameType);
	virtual bool equals(Object$* other) override;
	virtual $String* getName() override;
	int32_t getNameType();
	$String* getRealm();
	virtual int32_t hashCode() override;
	void readObject(::java::io::ObjectInputStream* ois);
	virtual $String* toString() override;
	void writeObject(::java::io::ObjectOutputStream* oos);
	static const int64_t serialVersionUID = (int64_t)0x99A77D5D0F1E3329;
	static const int32_t KRB_NT_UNKNOWN = 0;
	static const int32_t KRB_NT_PRINCIPAL = 1;
	static const int32_t KRB_NT_SRV_INST = 2;
	static const int32_t KRB_NT_SRV_HST = 3;
	static const int32_t KRB_NT_SRV_XHST = 4;
	static const int32_t KRB_NT_UID = 5;
	static const int32_t KRB_NT_ENTERPRISE = 10;
	$String* fullName = nullptr;
	$String* realm = nullptr;
	int32_t nameType = 0;
};

			} // kerberos
		} // auth
	} // security
} // javax

#pragma pop_macro("KRB_NT_ENTERPRISE")
#pragma pop_macro("KRB_NT_PRINCIPAL")
#pragma pop_macro("KRB_NT_SRV_HST")
#pragma pop_macro("KRB_NT_SRV_INST")
#pragma pop_macro("KRB_NT_SRV_XHST")
#pragma pop_macro("KRB_NT_UID")
#pragma pop_macro("KRB_NT_UNKNOWN")

#endif // _javax_security_auth_kerberos_KerberosPrincipal_h_