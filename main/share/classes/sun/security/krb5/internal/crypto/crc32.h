#ifndef _sun_security_krb5_internal_crypto_crc32_h_
#define _sun_security_krb5_internal_crypto_crc32_h_
//$ class sun.security.krb5.internal.crypto.crc32
//$ extends java.security.MessageDigestSpi
//$ implements java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>
#include <java/security/MessageDigestSpi.h>

#pragma push_macro("CRC32_LENGTH")
#undef CRC32_LENGTH
#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class crc32 : public ::java::security::MessageDigestSpi, public ::java::lang::Cloneable {
	$class(crc32, 0, ::java::security::MessageDigestSpi, ::java::lang::Cloneable)
public:
	crc32();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	using ::java::security::MessageDigestSpi::engineUpdate;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	static int32_t byte2crc32($bytes* data);
	static int32_t byte2crc32sum(int32_t seed, $bytes* data, int32_t size);
	static int32_t byte2crc32sum(int32_t seed, $bytes* data);
	static int32_t byte2crc32sum($bytes* data);
	static $bytes* byte2crc32sum_bytes($bytes* data);
	static $bytes* byte2crc32sum_bytes($bytes* data, int32_t size);
	virtual $Object* clone() override;
	virtual $bytes* engineDigest() override;
	virtual int32_t engineDigest($bytes* buf, int32_t offset, int32_t len) override;
	virtual int32_t engineGetDigestLength() override;
	virtual void engineReset() override;
	virtual void engineUpdate(int8_t b) override;
	virtual void engineUpdate($bytes* input, int32_t offset, int32_t len) override;
	void init();
	static int32_t int2crc32(int32_t b);
	static $bytes* int2quad(int64_t input);
	static void printcrc32Table();
	void processData($bytes* data, int32_t off, int32_t len);
	virtual $String* toString() override;
	static const int32_t CRC32_LENGTH = 4;
	int32_t seed = 0;
	static bool DEBUG;
	static $ints* crc32Table;
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("CRC32_LENGTH")
#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_crypto_crc32_h_