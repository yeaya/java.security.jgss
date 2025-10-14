#ifndef _sun_security_jgss_krb5_Krb5Context$KerberosSessionKey_h_
#define _sun_security_jgss_krb5_Krb5Context$KerberosSessionKey_h_
//$ class sun.security.jgss.krb5.Krb5Context$KerberosSessionKey
//$ extends java.security.Key

#include <java/lang/Array.h>
#include <java/security/Key.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class Krb5Context$KerberosSessionKey : public ::java::security::Key {
	$class(Krb5Context$KerberosSessionKey, $NO_CLASS_INIT, ::java::security::Key)
public:
	Krb5Context$KerberosSessionKey();
	void init$(::sun::security::krb5::EncryptionKey* key);
	virtual $String* getAlgorithm() override;
	virtual $bytes* getEncoded() override;
	virtual $String* getFormat() override;
	virtual $String* toString() override;
	static const int64_t serialVersionUID = (int64_t)0x09B4705B275EBA5D;
	::sun::security::krb5::EncryptionKey* key = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5Context$KerberosSessionKey_h_