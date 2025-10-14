#ifndef _sun_security_krb5_internal_crypto_Des_h_
#define _sun_security_krb5_internal_crypto_Des_h_
//$ class sun.security.krb5.internal.crypto.Des
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("CHARSET")
#undef CHARSET

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class Des : public ::java::lang::Object {
	$class(Des, 0, ::java::lang::Object)
public:
	Des();
	void init$();
	static bool bad_key(int64_t key);
	static bool bad_key($bytes* key);
	static void cbc_encrypt($bytes* input, $bytes* output, $bytes* key, $bytes* ivec, bool encrypt);
	static int64_t char_to_key($chars* passwdChars);
	static $bytes* des_cksum($bytes* ivec, $bytes* msg, $bytes* key);
	static $bytes* long2octet(int64_t input);
	static void long2octet(int64_t input, $bytes* output);
	static void long2octet(int64_t input, $bytes* output, int32_t offset);
	static int64_t octet2long($bytes* input);
	static int64_t octet2long($bytes* input, int32_t offset);
	static $bytes* pad($bytes* data);
	static $bytes* set_parity($bytes* key);
	static int64_t set_parity(int64_t key);
	static $bytes* string_to_key_bytes($chars* passwdChars);
	static $String* CHARSET;
	static $longs* bad_keys;
	static $bytes* good_parity;
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("CHARSET")

#endif // _sun_security_krb5_internal_crypto_Des_h_