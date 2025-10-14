#ifndef _javax_security_auth_kerberos_KeyImpl_h_
#define _javax_security_auth_kerberos_KeyImpl_h_
//$ class javax.security.auth.kerberos.KeyImpl
//$ extends javax.crypto.SecretKey

#include <java/lang/Array.h>
#include <javax/crypto/SecretKey.h>

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
				class KerberosPrincipal;
			}
		}
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class KeyImpl : public ::javax::crypto::SecretKey {
	$class(KeyImpl, $NO_CLASS_INIT, ::javax::crypto::SecretKey)
public:
	KeyImpl();
	void init$($bytes* keyBytes, int32_t keyType);
	void init$(::javax::security::auth::kerberos::KerberosPrincipal* principal, $chars* password, $String* algorithm);
	virtual void destroy() override;
	virtual bool equals(Object$* other) override;
	virtual $String* getAlgorithm() override;
	$String* getAlgorithmName(int32_t eType);
	virtual $bytes* getEncoded() override;
	virtual $String* getFormat() override;
	int32_t getKeyType();
	virtual int32_t hashCode() override;
	virtual bool isDestroyed() override;
	void readObject(::java::io::ObjectInputStream* ois);
	virtual $String* toString() override;
	void writeObject(::java::io::ObjectOutputStream* oos);
	static const int64_t serialVersionUID = (int64_t)0x928386E83CAF4BD7;
	$bytes* keyBytes = nullptr;
	int32_t keyType = 0;
	$volatile(bool) destroyed = false;
};

			} // kerberos
		} // auth
	} // security
} // javax

#endif // _javax_security_auth_kerberos_KeyImpl_h_