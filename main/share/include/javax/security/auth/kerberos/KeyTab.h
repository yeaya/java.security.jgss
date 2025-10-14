#ifndef _javax_security_auth_kerberos_KeyTab_h_
#define _javax_security_auth_kerberos_KeyTab_h_
//$ class javax.security.auth.kerberos.KeyTab
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace io {
		class File;
	}
}
namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KerberosKey;
				class KerberosPrincipal;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {
					class KeyTab;
				}
			}
		}
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class $import KeyTab : public ::java::lang::Object {
	$class(KeyTab, 0, ::java::lang::Object)
public:
	KeyTab();
	void init$(::javax::security::auth::kerberos::KerberosPrincipal* princ, ::java::io::File* file, bool bound);
	virtual bool equals(Object$* other) override;
	bool exists();
	$Array<::sun::security::krb5::EncryptionKey>* getEncryptionKeys(::sun::security::krb5::PrincipalName* principal);
	static ::javax::security::auth::kerberos::KeyTab* getInstance(::java::io::File* file);
	static ::javax::security::auth::kerberos::KeyTab* getInstance(::javax::security::auth::kerberos::KerberosPrincipal* princ, ::java::io::File* file);
	static ::javax::security::auth::kerberos::KeyTab* getInstance();
	static ::javax::security::auth::kerberos::KeyTab* getInstance(::javax::security::auth::kerberos::KerberosPrincipal* princ);
	$Array<::javax::security::auth::kerberos::KerberosKey>* getKeys(::javax::security::auth::kerberos::KerberosPrincipal* principal);
	::javax::security::auth::kerberos::KerberosPrincipal* getPrincipal();
	static ::javax::security::auth::kerberos::KeyTab* getUnboundInstance(::java::io::File* file);
	static ::javax::security::auth::kerberos::KeyTab* getUnboundInstance();
	virtual int32_t hashCode() override;
	bool isBound();
	::sun::security::krb5::internal::ktab::KeyTab* takeSnapshot();
	virtual $String* toString() override;
	::java::io::File* file = nullptr;
	::javax::security::auth::kerberos::KerberosPrincipal* princ = nullptr;
	bool bound = false;
};

			} // kerberos
		} // auth
	} // security
} // javax

#endif // _javax_security_auth_kerberos_KeyTab_h_