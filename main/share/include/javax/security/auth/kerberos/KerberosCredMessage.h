#ifndef _javax_security_auth_kerberos_KerberosCredMessage_h_
#define _javax_security_auth_kerberos_KerberosCredMessage_h_
//$ class javax.security.auth.kerberos.KerberosCredMessage
//$ extends javax.security.auth.Destroyable

#include <java/lang/Array.h>
#include <javax/security/auth/Destroyable.h>

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KerberosPrincipal;
			}
		}
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class $import KerberosCredMessage : public ::javax::security::auth::Destroyable {
	$class(KerberosCredMessage, $NO_CLASS_INIT, ::javax::security::auth::Destroyable)
public:
	KerberosCredMessage();
	void init$(::javax::security::auth::kerberos::KerberosPrincipal* sender, ::javax::security::auth::kerberos::KerberosPrincipal* recipient, $bytes* message);
	virtual void destroy() override;
	virtual bool equals(Object$* other) override;
	$bytes* getEncoded();
	::javax::security::auth::kerberos::KerberosPrincipal* getRecipient();
	::javax::security::auth::kerberos::KerberosPrincipal* getSender();
	virtual int32_t hashCode() override;
	virtual bool isDestroyed() override;
	virtual $String* toString() override;
	::javax::security::auth::kerberos::KerberosPrincipal* sender = nullptr;
	::javax::security::auth::kerberos::KerberosPrincipal* recipient = nullptr;
	$bytes* message = nullptr;
	bool destroyed = false;
};

			} // kerberos
		} // auth
	} // security
} // javax

#endif // _javax_security_auth_kerberos_KerberosCredMessage_h_