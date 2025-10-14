#ifndef _sun_security_jgss_krb5_CipherHelper_h_
#define _sun_security_jgss_krb5_CipherHelper_h_
//$ class sun.security.jgss.krb5.CipherHelper
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("AES_IV_SIZE")
#undef AES_IV_SIZE
#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("DES_CHECKSUM_SIZE")
#undef DES_CHECKSUM_SIZE
#pragma push_macro("DES_IV_SIZE")
#undef DES_IV_SIZE
#pragma push_macro("HMAC_CHECKSUM_SIZE")
#undef HMAC_CHECKSUM_SIZE
#pragma push_macro("KG_USAGE_SEAL")
#undef KG_USAGE_SEAL
#pragma push_macro("KG_USAGE_SEQ")
#undef KG_USAGE_SEQ
#pragma push_macro("KG_USAGE_SIGN")
#undef KG_USAGE_SIGN
#pragma push_macro("KG_USAGE_SIGN_MS")
#undef KG_USAGE_SIGN_MS
#pragma push_macro("ZERO_IV")
#undef ZERO_IV
#pragma push_macro("ZERO_IV_AES")
#undef ZERO_IV_AES

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
	}
}
namespace javax {
	namespace crypto {
		class Cipher;
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class WrapToken;
				class WrapToken_v2;
			}
		}
	}
}
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

class CipherHelper : public ::java::lang::Object {
	$class(CipherHelper, 0, ::java::lang::Object)
public:
	CipherHelper();
	void init$(::sun::security::krb5::EncryptionKey* key);
	void aes128Decrypt(::sun::security::jgss::krb5::WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage);
	$bytes* aes128Encrypt($bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage);
	void aes128Sha2Decrypt(::sun::security::jgss::krb5::WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage);
	$bytes* aes128Sha2Encrypt($bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage);
	void aes256Decrypt(::sun::security::jgss::krb5::WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage);
	$bytes* aes256Encrypt($bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage);
	void aes256Sha2Decrypt(::sun::security::jgss::krb5::WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage);
	$bytes* aes256Sha2Encrypt($bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage);
	void arcFourDecrypt(::sun::security::jgss::krb5::WrapToken* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart);
	$bytes* arcFourEncrypt(::sun::security::jgss::krb5::WrapToken* token, $bytes* confounder, $bytes* plaintext, int32_t start, int32_t len, $bytes* padding);
	virtual $bytes* calculateChecksum(int32_t alg, $bytes* header, $bytes* trailer, $bytes* data, int32_t start, int32_t len, int32_t tokenId);
	virtual $bytes* calculateChecksum($bytes* header, $bytes* data, int32_t start, int32_t len, int32_t key_usage);
	virtual void decryptData(::sun::security::jgss::krb5::WrapToken* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart);
	virtual void decryptData(::sun::security::jgss::krb5::WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage);
	virtual void decryptData(::sun::security::jgss::krb5::WrapToken* token, ::java::io::InputStream* cipherStream, int32_t cLen, $bytes* plaintext, int32_t pStart);
	virtual void decryptData(::sun::security::jgss::krb5::WrapToken_v2* token, ::java::io::InputStream* cipherStream, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage);
	virtual $bytes* decryptSeq($bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len);
	void des3KdDecrypt(::sun::security::jgss::krb5::WrapToken* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart);
	$bytes* des3KdEncrypt($bytes* confounder, $bytes* plaintext, int32_t start, int32_t len, $bytes* padding);
	void desCbcDecrypt(::sun::security::jgss::krb5::WrapToken* token, $bytes* key, $bytes* cipherText, int32_t offset, int32_t len, $bytes* dataOutBuf, int32_t dataOffset);
	void desCbcDecrypt(::sun::security::jgss::krb5::WrapToken* token, $bytes* key, ::java::io::InputStream* is, int32_t len, $bytes* dataOutBuf, int32_t dataOffset);
	virtual void encryptData(::sun::security::jgss::krb5::WrapToken* token, $bytes* confounder, $bytes* plaintext, int32_t start, int32_t len, $bytes* padding, ::java::io::OutputStream* os);
	virtual $bytes* encryptData(::sun::security::jgss::krb5::WrapToken_v2* token, $bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage);
	virtual void encryptData(::sun::security::jgss::krb5::WrapToken* token, $bytes* confounder, $bytes* plaintext, int32_t pStart, int32_t pLen, $bytes* padding, $bytes* ciphertext, int32_t cStart);
	virtual int32_t encryptData(::sun::security::jgss::krb5::WrapToken_v2* token, $bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t pStart, int32_t pLen, $bytes* ciphertext, int32_t cStart, int32_t key_usage);
	virtual $bytes* encryptSeq($bytes* ivec, $bytes* plaintext, int32_t start, int32_t len);
	virtual int32_t getChecksumLength();
	$bytes* getDesCbcChecksum($bytes* key, $bytes* header, $bytes* data, int32_t offset, int32_t len);
	static $bytes* getDesEncryptionKey($bytes* key);
	virtual int32_t getEType();
	::javax::crypto::Cipher* getInitializedDes(bool encryptMode, $bytes* key, $bytes* ivBytes);
	virtual int32_t getProto();
	virtual int32_t getSealAlg();
	virtual int32_t getSgnAlg();
	virtual bool isArcFour();
	static const int32_t KG_USAGE_SEAL = 22;
	static const int32_t KG_USAGE_SIGN = 23;
	static const int32_t KG_USAGE_SEQ = 24;
	static const int32_t DES_CHECKSUM_SIZE = 8;
	static const int32_t DES_IV_SIZE = 8;
	static const int32_t AES_IV_SIZE = 16;
	static const int32_t HMAC_CHECKSUM_SIZE = 8;
	static const int32_t KG_USAGE_SIGN_MS = 15;
	static bool DEBUG;
	static $bytes* ZERO_IV;
	static $bytes* ZERO_IV_AES;
	int32_t etype = 0;
	int32_t sgnAlg = 0;
	int32_t sealAlg = 0;
	$bytes* keybytes = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("AES_IV_SIZE")
#pragma pop_macro("DEBUG")
#pragma pop_macro("DES_CHECKSUM_SIZE")
#pragma pop_macro("DES_IV_SIZE")
#pragma pop_macro("HMAC_CHECKSUM_SIZE")
#pragma pop_macro("KG_USAGE_SEAL")
#pragma pop_macro("KG_USAGE_SEQ")
#pragma pop_macro("KG_USAGE_SIGN")
#pragma pop_macro("KG_USAGE_SIGN_MS")
#pragma pop_macro("ZERO_IV")
#pragma pop_macro("ZERO_IV_AES")

#endif // _sun_security_jgss_krb5_CipherHelper_h_