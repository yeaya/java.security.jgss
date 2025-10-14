#ifndef _sun_security_krb5_internal_crypto_dk_DkCrypto_h_
#define _sun_security_krb5_internal_crypto_dk_DkCrypto_h_
//$ class sun.security.krb5.internal.crypto.dk.DkCrypto
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("KERBEROS_CONSTANT")
#undef KERBEROS_CONSTANT

namespace javax {
	namespace crypto {
		class Cipher;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {
					namespace dk {

class DkCrypto : public ::java::lang::Object {
	$class(DkCrypto, 0, ::java::lang::Object)
public:
	DkCrypto();
	void init$();
	static $bytes* binaryStringToBytes($String* str);
	static $String* bytesToString($bytes* digest);
	virtual $bytes* calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len);
	static $bytes* charToUtf16($chars* chars);
	static $bytes* charToUtf8($chars* chars);
	virtual $bytes* decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len);
	virtual $bytes* decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len);
	virtual $bytes* dk($bytes* key, $bytes* constant);
	virtual $bytes* dr($bytes* key, $bytes* constant);
	virtual $bytes* encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len);
	virtual $bytes* encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len);
	virtual int32_t getChecksumLength() {return 0;}
	virtual ::javax::crypto::Cipher* getCipher($bytes* key, $bytes* ivec, int32_t mode) {return nullptr;}
	virtual $bytes* getHmac($bytes* key, $bytes* plaintext) {return nullptr;}
	virtual int32_t getKeySeedLength() {return 0;}
	static $bytes* nfold($bytes* in, int32_t outbits);
	virtual $bytes* randomToKey($bytes* in) {return nullptr;}
	virtual int32_t roundup(int32_t n, int32_t blocksize);
	static void traceOutput($String* traceTag, $bytes* output, int32_t offset, int32_t len);
	static const bool debug = false;
	static $bytes* KERBEROS_CONSTANT;
};

					} // dk
				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("KERBEROS_CONSTANT")

#endif // _sun_security_krb5_internal_crypto_dk_DkCrypto_h_