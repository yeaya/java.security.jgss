#ifndef _sun_security_krb5_Checksum_h_
#define _sun_security_krb5_Checksum_h_
//$ class sun.security.krb5.Checksum
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("CKSUMTYPE_CRC32")
#undef CKSUMTYPE_CRC32
#pragma push_macro("CKSUMTYPE_DEFAULT")
#undef CKSUMTYPE_DEFAULT
#pragma push_macro("CKSUMTYPE_DES_MAC")
#undef CKSUMTYPE_DES_MAC
#pragma push_macro("CKSUMTYPE_DES_MAC_K")
#undef CKSUMTYPE_DES_MAC_K
#pragma push_macro("CKSUMTYPE_HMAC_MD5_ARCFOUR")
#undef CKSUMTYPE_HMAC_MD5_ARCFOUR
#pragma push_macro("CKSUMTYPE_HMAC_SHA1_DES3_KD")
#undef CKSUMTYPE_HMAC_SHA1_DES3_KD
#pragma push_macro("CKSUMTYPE_NULL")
#undef CKSUMTYPE_NULL
#pragma push_macro("CKSUMTYPE_RSA_MD4")
#undef CKSUMTYPE_RSA_MD4
#pragma push_macro("CKSUMTYPE_RSA_MD4_DES")
#undef CKSUMTYPE_RSA_MD4_DES
#pragma push_macro("CKSUMTYPE_RSA_MD4_DES_K")
#undef CKSUMTYPE_RSA_MD4_DES_K
#pragma push_macro("CKSUMTYPE_RSA_MD5")
#undef CKSUMTYPE_RSA_MD5
#pragma push_macro("CKSUMTYPE_RSA_MD5_DES")
#undef CKSUMTYPE_RSA_MD5_DES
#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("SAFECKSUMTYPE_DEFAULT")
#undef SAFECKSUMTYPE_DEFAULT

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
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

class $export Checksum : public ::java::lang::Object {
	$class(Checksum, 0, ::java::lang::Object)
public:
	Checksum();
	void init$($bytes* data, int32_t new_cksumType);
	void init$(int32_t new_cksumType, $bytes* data, ::sun::security::krb5::EncryptionKey* key, int32_t usage);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual bool equals(Object$* obj) override;
	$bytes* getBytes();
	int32_t getType();
	virtual int32_t hashCode() override;
	static void initStatic();
	virtual bool isEqual(::sun::security::krb5::Checksum* cksum);
	static ::sun::security::krb5::Checksum* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	virtual bool verifyAnyChecksum($bytes* data, ::sun::security::krb5::EncryptionKey* key, int32_t usage);
	virtual bool verifyKeyedChecksum($bytes* data, ::sun::security::krb5::EncryptionKey* key, int32_t usage);
	int32_t cksumType = 0;
	$bytes* checksum = nullptr;
	static const int32_t CKSUMTYPE_NULL = 0;
	static const int32_t CKSUMTYPE_CRC32 = 1;
	static const int32_t CKSUMTYPE_RSA_MD4 = 2;
	static const int32_t CKSUMTYPE_RSA_MD4_DES = 3;
	static const int32_t CKSUMTYPE_DES_MAC = 4;
	static const int32_t CKSUMTYPE_DES_MAC_K = 5;
	static const int32_t CKSUMTYPE_RSA_MD4_DES_K = 6;
	static const int32_t CKSUMTYPE_RSA_MD5 = 7;
	static const int32_t CKSUMTYPE_RSA_MD5_DES = 8;
	static const int32_t CKSUMTYPE_HMAC_SHA1_DES3_KD = 12;
	static const int32_t CKSUMTYPE_HMAC_SHA1_96_AES128 = 15;
	static const int32_t CKSUMTYPE_HMAC_SHA1_96_AES256 = 16;
	static const int32_t CKSUMTYPE_HMAC_SHA256_128_AES128 = 19;
	static const int32_t CKSUMTYPE_HMAC_SHA384_192_AES256 = 20;
	static const int32_t CKSUMTYPE_HMAC_MD5_ARCFOUR = (-138);
	static int32_t CKSUMTYPE_DEFAULT;
	static int32_t SAFECKSUMTYPE_DEFAULT;
	static bool DEBUG;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("CKSUMTYPE_CRC32")
#pragma pop_macro("CKSUMTYPE_DEFAULT")
#pragma pop_macro("CKSUMTYPE_DES_MAC")
#pragma pop_macro("CKSUMTYPE_DES_MAC_K")
#pragma pop_macro("CKSUMTYPE_HMAC_MD5_ARCFOUR")
#pragma pop_macro("CKSUMTYPE_HMAC_SHA1_DES3_KD")
#pragma pop_macro("CKSUMTYPE_NULL")
#pragma pop_macro("CKSUMTYPE_RSA_MD4")
#pragma pop_macro("CKSUMTYPE_RSA_MD4_DES")
#pragma pop_macro("CKSUMTYPE_RSA_MD4_DES_K")
#pragma pop_macro("CKSUMTYPE_RSA_MD5")
#pragma pop_macro("CKSUMTYPE_RSA_MD5_DES")
#pragma pop_macro("DEBUG")
#pragma pop_macro("SAFECKSUMTYPE_DEFAULT")

#endif // _sun_security_krb5_Checksum_h_