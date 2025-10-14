#ifndef _sun_security_krb5_internal_ccache_FileCCacheConstants_h_
#define _sun_security_krb5_internal_ccache_FileCCacheConstants_h_
//$ interface sun.security.krb5.internal.ccache.FileCCacheConstants
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("FCC_TAG_DELTATIME")
#undef FCC_TAG_DELTATIME
#pragma push_macro("KRB5_FCC_FVNO_1")
#undef KRB5_FCC_FVNO_1
#pragma push_macro("KRB5_FCC_FVNO_2")
#undef KRB5_FCC_FVNO_2
#pragma push_macro("KRB5_FCC_FVNO_3")
#undef KRB5_FCC_FVNO_3
#pragma push_macro("KRB5_FCC_FVNO_4")
#undef KRB5_FCC_FVNO_4
#pragma push_macro("KRB5_NT_UNKNOWN")
#undef KRB5_NT_UNKNOWN
#pragma push_macro("TKT_FLG_FORWARDABLE")
#undef TKT_FLG_FORWARDABLE
#pragma push_macro("TKT_FLG_FORWARDED")
#undef TKT_FLG_FORWARDED
#pragma push_macro("TKT_FLG_HW_AUTH")
#undef TKT_FLG_HW_AUTH
#pragma push_macro("TKT_FLG_INITIAL")
#undef TKT_FLG_INITIAL
#pragma push_macro("TKT_FLG_INVALID")
#undef TKT_FLG_INVALID
#pragma push_macro("TKT_FLG_MAY_POSTDATE")
#undef TKT_FLG_MAY_POSTDATE
#pragma push_macro("TKT_FLG_POSTDATED")
#undef TKT_FLG_POSTDATED
#pragma push_macro("TKT_FLG_PRE_AUTH")
#undef TKT_FLG_PRE_AUTH
#pragma push_macro("TKT_FLG_PROXIABLE")
#undef TKT_FLG_PROXIABLE
#pragma push_macro("TKT_FLG_PROXY")
#undef TKT_FLG_PROXY
#pragma push_macro("TKT_FLG_RENEWABLE")
#undef TKT_FLG_RENEWABLE

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

class FileCCacheConstants : public ::java::lang::Object {
	$interface(FileCCacheConstants, $NO_CLASS_INIT, ::java::lang::Object)
public:
	static const int32_t KRB5_FCC_FVNO_1 = 1281;
	static const int32_t KRB5_FCC_FVNO_2 = 1282;
	static const int32_t KRB5_FCC_FVNO_3 = 1283;
	static const int32_t KRB5_FCC_FVNO_4 = 1284;
	static const int32_t FCC_TAG_DELTATIME = 1;
	static const int32_t KRB5_NT_UNKNOWN = 0;
	static const int32_t TKT_FLG_FORWARDABLE = 0x40000000;
	static const int32_t TKT_FLG_FORWARDED = 0x20000000;
	static const int32_t TKT_FLG_PROXIABLE = 0x10000000;
	static const int32_t TKT_FLG_PROXY = 0x08000000;
	static const int32_t TKT_FLG_MAY_POSTDATE = 0x04000000;
	static const int32_t TKT_FLG_POSTDATED = 0x02000000;
	static const int32_t TKT_FLG_INVALID = 0x01000000;
	static const int32_t TKT_FLG_RENEWABLE = 0x00800000;
	static const int32_t TKT_FLG_INITIAL = 0x00400000;
	static const int32_t TKT_FLG_PRE_AUTH = 0x00200000;
	static const int32_t TKT_FLG_HW_AUTH = 0x00100000;
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("FCC_TAG_DELTATIME")
#pragma pop_macro("KRB5_FCC_FVNO_1")
#pragma pop_macro("KRB5_FCC_FVNO_2")
#pragma pop_macro("KRB5_FCC_FVNO_3")
#pragma pop_macro("KRB5_FCC_FVNO_4")
#pragma pop_macro("KRB5_NT_UNKNOWN")
#pragma pop_macro("TKT_FLG_FORWARDABLE")
#pragma pop_macro("TKT_FLG_FORWARDED")
#pragma pop_macro("TKT_FLG_HW_AUTH")
#pragma pop_macro("TKT_FLG_INITIAL")
#pragma pop_macro("TKT_FLG_INVALID")
#pragma pop_macro("TKT_FLG_MAY_POSTDATE")
#pragma pop_macro("TKT_FLG_POSTDATED")
#pragma pop_macro("TKT_FLG_PRE_AUTH")
#pragma pop_macro("TKT_FLG_PROXIABLE")
#pragma pop_macro("TKT_FLG_PROXY")
#pragma pop_macro("TKT_FLG_RENEWABLE")

#endif // _sun_security_krb5_internal_ccache_FileCCacheConstants_h_