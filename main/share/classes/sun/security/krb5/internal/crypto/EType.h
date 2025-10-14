#ifndef _sun_security_krb5_internal_crypto_EType_h_
#define _sun_security_krb5_internal_crypto_EType_h_
//$ class sun.security.krb5.internal.crypto.EType
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("BUILTIN_ETYPES")
#undef BUILTIN_ETYPES
#pragma push_macro("BUILTIN_ETYPES_NOAES256")
#undef BUILTIN_ETYPES_NOAES256
#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class EType : public ::java::lang::Object {
	$class(EType, 0, ::java::lang::Object)
public:
	EType();
	void init$();
	virtual int32_t blockSize() {return 0;}
	virtual int32_t checksumSize() {return 0;}
	virtual int32_t checksumType() {return 0;}
	virtual int32_t confounderSize() {return 0;}
	virtual int32_t dataSize($bytes* data);
	virtual $bytes* decrypt($bytes* cipher, $bytes* key, int32_t usage) {return nullptr;}
	virtual $bytes* decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) {return nullptr;}
	virtual $bytes* decryptedData($bytes* data);
	virtual int32_t eType() {return 0;}
	virtual $bytes* encrypt($bytes* data, $bytes* key, int32_t usage) {return nullptr;}
	virtual $bytes* encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) {return nullptr;}
	static $ints* getBuiltInDefaults();
	static $ints* getDefaults($String* configName);
	static $ints* getDefaults($String* configName, $Array<::sun::security::krb5::EncryptionKey>* keys);
	static ::sun::security::krb5::internal::crypto::EType* getInstance(int32_t eTypeConst);
	static void initStatic();
	static bool isNewer(int32_t eTypeConst);
	static bool isSupported(int32_t eTypeConst, $ints* config);
	static bool isSupported(int32_t eTypeConst);
	virtual int32_t keySize() {return 0;}
	virtual int32_t keyType() {return 0;}
	virtual int32_t minimumPadSize() {return 0;}
	virtual int32_t padSize($bytes* data);
	virtual int32_t startOfChecksum();
	virtual int32_t startOfData();
	virtual int32_t startOfPad($bytes* data);
	using ::java::lang::Object::toString;
	static $String* toString(int32_t type);
	static bool DEBUG;
	static bool allowWeakCrypto;
	static $ints* BUILTIN_ETYPES;
	static $ints* BUILTIN_ETYPES_NOAES256;
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("BUILTIN_ETYPES")
#pragma pop_macro("BUILTIN_ETYPES_NOAES256")
#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_crypto_EType_h_