#ifndef _sun_security_krb5_EncryptedData_h_
#define _sun_security_krb5_EncryptedData_h_
//$ class sun.security.krb5.EncryptedData
//$ extends java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

#pragma push_macro("ETYPE_ARCFOUR_HMAC")
#undef ETYPE_ARCFOUR_HMAC
#pragma push_macro("ETYPE_ARCFOUR_HMAC_EXP")
#undef ETYPE_ARCFOUR_HMAC_EXP
#pragma push_macro("ETYPE_DES3_CBC_HMAC_SHA1_KD")
#undef ETYPE_DES3_CBC_HMAC_SHA1_KD
#pragma push_macro("ETYPE_DES_CBC_CRC")
#undef ETYPE_DES_CBC_CRC
#pragma push_macro("ETYPE_DES_CBC_MD4")
#undef ETYPE_DES_CBC_MD4
#pragma push_macro("ETYPE_DES_CBC_MD5")
#undef ETYPE_DES_CBC_MD5
#pragma push_macro("ETYPE_NULL")
#undef ETYPE_NULL

namespace java {
	namespace lang {
		class Integer;
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
		namespace util {
			class DerInputStream;
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import EncryptedData : public ::java::lang::Cloneable {
	$class(EncryptedData, $NO_CLASS_INIT, ::java::lang::Cloneable)
public:
	EncryptedData();
	void init$();
	void init$(int32_t new_eType, ::java::lang::Integer* new_kvno, $bytes* new_cipher);
	void init$(::sun::security::krb5::EncryptionKey* key, $bytes* plaintext, int32_t usage);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual $bytes* decrypt(::sun::security::krb5::EncryptionKey* key, int32_t usage);
	$bytes* decryptedData();
	virtual $bytes* getBytes();
	virtual int32_t getEType();
	virtual ::java::lang::Integer* getKeyVersionNumber();
	static ::sun::security::krb5::EncryptedData* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	virtual $bytes* reset($bytes* data);
	int32_t eType = 0;
	::java::lang::Integer* kvno = nullptr;
	$bytes* cipher = nullptr;
	$bytes* plain = nullptr;
	static const int32_t ETYPE_NULL = 0;
	static const int32_t ETYPE_DES_CBC_CRC = 1;
	static const int32_t ETYPE_DES_CBC_MD4 = 2;
	static const int32_t ETYPE_DES_CBC_MD5 = 3;
	static const int32_t ETYPE_ARCFOUR_HMAC = 23;
	static const int32_t ETYPE_ARCFOUR_HMAC_EXP = 24;
	static const int32_t ETYPE_DES3_CBC_HMAC_SHA1_KD = 16;
	static const int32_t ETYPE_AES128_CTS_HMAC_SHA1_96 = 17;
	static const int32_t ETYPE_AES256_CTS_HMAC_SHA1_96 = 18;
	static const int32_t ETYPE_AES128_CTS_HMAC_SHA256_128 = 19;
	static const int32_t ETYPE_AES256_CTS_HMAC_SHA384_192 = 20;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("ETYPE_ARCFOUR_HMAC")
#pragma pop_macro("ETYPE_ARCFOUR_HMAC_EXP")
#pragma pop_macro("ETYPE_DES3_CBC_HMAC_SHA1_KD")
#pragma pop_macro("ETYPE_DES_CBC_CRC")
#pragma pop_macro("ETYPE_DES_CBC_MD4")
#pragma pop_macro("ETYPE_DES_CBC_MD5")
#pragma pop_macro("ETYPE_NULL")

#endif // _sun_security_krb5_EncryptedData_h_