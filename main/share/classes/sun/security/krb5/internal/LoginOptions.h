#ifndef _sun_security_krb5_internal_LoginOptions_h_
#define _sun_security_krb5_internal_LoginOptions_h_
//$ class sun.security.krb5.internal.LoginOptions
//$ extends sun.security.krb5.internal.KDCOptions

#include <sun/security/krb5/internal/KDCOptions.h>

#pragma push_macro("ALLOW_POSTDATE")
#undef ALLOW_POSTDATE
#pragma push_macro("ENC_TKT_IN_SKEY")
#undef ENC_TKT_IN_SKEY
#pragma push_macro("FORWARDABLE")
#undef FORWARDABLE
#pragma push_macro("MAX")
#undef MAX
#pragma push_macro("PROXIABLE")
#undef PROXIABLE
#pragma push_macro("RENEW")
#undef RENEW
#pragma push_macro("RENEWABLE")
#undef RENEWABLE
#pragma push_macro("RENEWABLE_OK")
#undef RENEWABLE_OK
#pragma push_macro("RESERVED")
#undef RESERVED
#pragma push_macro("VALIDATE")
#undef VALIDATE

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export LoginOptions : public ::sun::security::krb5::internal::KDCOptions {
	$class(LoginOptions, $NO_CLASS_INIT, ::sun::security::krb5::internal::KDCOptions)
public:
	LoginOptions();
	void init$();
	static const int32_t RESERVED = 0;
	static const int32_t FORWARDABLE = 1;
	static const int32_t PROXIABLE = 3;
	static const int32_t ALLOW_POSTDATE = 5;
	static const int32_t RENEWABLE = 8;
	static const int32_t RENEWABLE_OK = 27;
	static const int32_t ENC_TKT_IN_SKEY = 28;
	static const int32_t RENEW = 30;
	static const int32_t VALIDATE = 31;
	static const int32_t MAX = 31;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("ALLOW_POSTDATE")
#pragma pop_macro("ENC_TKT_IN_SKEY")
#pragma pop_macro("FORWARDABLE")
#pragma pop_macro("MAX")
#pragma pop_macro("PROXIABLE")
#pragma pop_macro("RENEW")
#pragma pop_macro("RENEWABLE")
#pragma pop_macro("RENEWABLE_OK")
#pragma pop_macro("RESERVED")
#pragma pop_macro("VALIDATE")

#endif // _sun_security_krb5_internal_LoginOptions_h_