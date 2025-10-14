#ifndef _javax_security_auth_kerberos_KerberosKey_h_
#define _javax_security_auth_kerberos_KerberosKey_h_
//$ class javax.security.auth.kerberos.KerberosKey
//$ extends javax.crypto.SecretKey

#include <java/lang/Array.h>
#include <javax/crypto/SecretKey.h>

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KerberosPrincipal;
				class KeyImpl;
			}
		}
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class $export KerberosKey : public ::javax::crypto::SecretKey {
	$class(KerberosKey, $NO_CLASS_INIT, ::javax::crypto::SecretKey)
public:
	KerberosKey();
	void init$(::javax::security::auth::kerberos::KerberosPrincipal* principal, $bytes* keyBytes, int32_t keyType, int32_t versionNum);
	void init$(::javax::security::auth::kerberos::KerberosPrincipal* principal, $chars* password, $String* algorithm);
	virtual void destroy() override;
	virtual bool equals(Object$* other) override;
	virtual $String* getAlgorithm() override;
	virtual $bytes* getEncoded() override;
	virtual $String* getFormat() override;
	int32_t getKeyType();
	::javax::security::auth::kerberos::KerberosPrincipal* getPrincipal();
	int32_t getVersionNumber();
	virtual int32_t hashCode() override;
	virtual bool isDestroyed() override;
	virtual $String* toString() override;
	static const int64_t serialVersionUID = (int64_t)0xBFCF45226BB0F22F;
	::javax::security::auth::kerberos::KerberosPrincipal* principal = nullptr;
	int32_t versionNum = 0;
	::javax::security::auth::kerberos::KeyImpl* key = nullptr;
	bool destroyed = false;
};

			} // kerberos
		} // auth
	} // security
} // javax

#endif // _javax_security_auth_kerberos_KerberosKey_h_