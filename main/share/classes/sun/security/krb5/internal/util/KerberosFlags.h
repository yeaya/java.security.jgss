#ifndef _sun_security_krb5_internal_util_KerberosFlags_h_
#define _sun_security_krb5_internal_util_KerberosFlags_h_
//$ class sun.security.krb5.internal.util.KerberosFlags
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("BITS_PER_UNIT")
#undef BITS_PER_UNIT

namespace sun {
	namespace security {
		namespace util {
			class BitArray;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace util {

class $export KerberosFlags : public ::java::lang::Object {
	$class(KerberosFlags, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KerberosFlags();
	void init$(int32_t length);
	void init$(int32_t length, $bytes* a);
	void init$($booleans* bools);
	virtual $bytes* asn1Encode();
	virtual bool get(int32_t index);
	virtual void set(int32_t index, bool value);
	virtual $booleans* toBooleanArray();
	virtual $String* toString() override;
	::sun::security::util::BitArray* bits = nullptr;
	static const int32_t BITS_PER_UNIT = 8;
};

				} // util
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("BITS_PER_UNIT")

#endif // _sun_security_krb5_internal_util_KerberosFlags_h_