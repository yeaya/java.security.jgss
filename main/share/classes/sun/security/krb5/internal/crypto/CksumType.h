#ifndef _sun_security_krb5_internal_crypto_CksumType_h_
#define _sun_security_krb5_internal_crypto_CksumType_h_
//$ class sun.security.krb5.internal.crypto.CksumType
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class CksumType : public ::java::lang::Object {
	$class(CksumType, 0, ::java::lang::Object)
public:
	CksumType();
	void init$();
	virtual $bytes* calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) {return nullptr;}
	virtual int32_t cksumSize() {return 0;}
	virtual int32_t cksumType() {return 0;}
	virtual int32_t confounderSize() {return 0;}
	static ::sun::security::krb5::internal::crypto::CksumType* getInstance(int32_t cksumTypeConst);
	static bool isChecksumEqual($bytes* cksum1, $bytes* cksum2);
	virtual bool isKeyed() {return false;}
	virtual int32_t keySize() {return 0;}
	virtual int32_t keyType() {return 0;}
	virtual bool verifyChecksum($bytes* data, int32_t size, $bytes* key, $bytes* checksum, int32_t usage) {return false;}
	static bool DEBUG;
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_crypto_CksumType_h_