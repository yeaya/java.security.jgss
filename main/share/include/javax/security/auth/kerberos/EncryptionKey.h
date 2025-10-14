#ifndef _javax_security_auth_kerberos_EncryptionKey_h_
#define _javax_security_auth_kerberos_EncryptionKey_h_
//$ class javax.security.auth.kerberos.EncryptionKey
//$ extends javax.crypto.SecretKey

#include <java/lang/Array.h>
#include <javax/crypto/SecretKey.h>

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KeyImpl;
			}
		}
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class $import EncryptionKey : public ::javax::crypto::SecretKey {
	$class(EncryptionKey, $NO_CLASS_INIT, ::javax::crypto::SecretKey)
public:
	EncryptionKey();
	void init$($bytes* keyBytes, int32_t keyType);
	virtual void destroy() override;
	virtual bool equals(Object$* other) override;
	virtual $String* getAlgorithm() override;
	virtual $bytes* getEncoded() override;
	virtual $String* getFormat() override;
	int32_t getKeyType();
	virtual int32_t hashCode() override;
	virtual bool isDestroyed() override;
	virtual $String* toString() override;
	static const int64_t serialVersionUID = (int64_t)9;
	::javax::security::auth::kerberos::KeyImpl* key = nullptr;
	bool destroyed = false;
};

			} // kerberos
		} // auth
	} // security
} // javax

#endif // _javax_security_auth_kerberos_EncryptionKey_h_