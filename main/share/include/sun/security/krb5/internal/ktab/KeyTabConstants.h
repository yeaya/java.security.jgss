#ifndef _sun_security_krb5_internal_ktab_KeyTabConstants_h_
#define _sun_security_krb5_internal_ktab_KeyTabConstants_h_
//$ interface sun.security.krb5.internal.ktab.KeyTabConstants
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("KRB5_KT_VNO")
#undef KRB5_KT_VNO
#pragma push_macro("KRB5_KT_VNO_1")
#undef KRB5_KT_VNO_1

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {

class $import KeyTabConstants : public ::java::lang::Object {
	$interface(KeyTabConstants, $NO_CLASS_INIT, ::java::lang::Object)
public:
	static const int32_t principalComponentSize = 2;
	static const int32_t realmSize = 2;
	static const int32_t principalSize = 2;
	static const int32_t principalTypeSize = 4;
	static const int32_t timestampSize = 4;
	static const int32_t keyVersionSize = 1;
	static const int32_t keyTypeSize = 2;
	static const int32_t keySize = 2;
	static const int32_t KRB5_KT_VNO_1 = 1281;
	static const int32_t KRB5_KT_VNO = 1282;
};

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("KRB5_KT_VNO")
#pragma pop_macro("KRB5_KT_VNO_1")

#endif // _sun_security_krb5_internal_ktab_KeyTabConstants_h_