#ifndef _sun_security_krb5_EncryptionKey_h_
#define _sun_security_krb5_EncryptionKey_h_
//$ class sun.security.krb5.EncryptionKey
//$ extends java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("NULL_KEY")
#undef NULL_KEY

namespace java {
	namespace lang {
		class Integer;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class PAData$SaltAndParams;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {
					class CCacheOutputStream;
				}
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class DerInputStream;
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import EncryptionKey : public ::java::lang::Cloneable {
	$class(EncryptionKey, 0, ::java::lang::Cloneable)
public:
	EncryptionKey();
	void init$($bytes* keyValue, int32_t keyType, ::java::lang::Integer* kvno);
	void init$(int32_t keyType, $bytes* keyValue);
	void init$($chars* password, $String* salt, $String* algorithm);
	void init$(::sun::security::krb5::EncryptionKey* key);
	void init$(::sun::security::util::DerValue* encoding);
	static ::sun::security::krb5::EncryptionKey* acquireSecretKey(::sun::security::krb5::PrincipalName* cname, $chars* password, int32_t etype, ::sun::security::krb5::internal::PAData$SaltAndParams* snp);
	static ::sun::security::krb5::EncryptionKey* acquireSecretKey($chars* password, $String* salt, int32_t etype, $bytes* s2kparams);
	static $Array<::sun::security::krb5::EncryptionKey>* acquireSecretKeys(::sun::security::krb5::PrincipalName* princ, $String* keytab);
	static $Array<::sun::security::krb5::EncryptionKey>* acquireSecretKeys($chars* password, $String* salt);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual void destroy();
	static ::sun::security::krb5::EncryptionKey* findKey(int32_t etype, $Array<::sun::security::krb5::EncryptionKey>* keys);
	static ::sun::security::krb5::EncryptionKey* findKey(int32_t etype, ::java::lang::Integer* kvno, $Array<::sun::security::krb5::EncryptionKey>* keys);
	$bytes* getBytes();
	virtual int32_t getEType();
	::java::lang::Integer* getKeyVersionNumber();
	static ::sun::security::krb5::EncryptionKey* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	static $bytes* stringToKey($chars* password, $String* salt, $bytes* s2kparams, int32_t keyType);
	virtual $String* toString() override;
	static bool versionMatches(::java::lang::Integer* v1, ::java::lang::Integer* v2);
	virtual void writeKey(::sun::security::krb5::internal::ccache::CCacheOutputStream* cos);
	static ::sun::security::krb5::EncryptionKey* NULL_KEY;
	int32_t keyType = 0;
	$bytes* keyValue = nullptr;
	::java::lang::Integer* kvno = nullptr;
	static bool DEBUG;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")
#pragma pop_macro("NULL_KEY")

#endif // _sun_security_krb5_EncryptionKey_h_