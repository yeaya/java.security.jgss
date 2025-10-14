#ifndef _sun_security_krb5_internal_KDCOptions_h_
#define _sun_security_krb5_internal_KDCOptions_h_
//$ class sun.security.krb5.internal.KDCOptions
//$ extends sun.security.krb5.internal.util.KerberosFlags

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/util/KerberosFlags.h>

#pragma push_macro("ALLOW_POSTDATE")
#undef ALLOW_POSTDATE
#pragma push_macro("CANONICALIZE")
#undef CANONICALIZE
#pragma push_macro("CNAME_IN_ADDL_TKT")
#undef CNAME_IN_ADDL_TKT
#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("ENC_TKT_IN_SKEY")
#undef ENC_TKT_IN_SKEY
#pragma push_macro("FORWARDABLE")
#undef FORWARDABLE
#pragma push_macro("FORWARDED")
#undef FORWARDED
#pragma push_macro("KDC_OPT_FORWARDABLE")
#undef KDC_OPT_FORWARDABLE
#pragma push_macro("KDC_OPT_PROXIABLE")
#undef KDC_OPT_PROXIABLE
#pragma push_macro("KDC_OPT_RENEWABLE_OK")
#undef KDC_OPT_RENEWABLE_OK
#pragma push_macro("POSTDATED")
#undef POSTDATED
#pragma push_macro("PROXIABLE")
#undef PROXIABLE
#pragma push_macro("PROXY")
#undef PROXY
#pragma push_macro("RENEW")
#undef RENEW
#pragma push_macro("RENEWABLE")
#undef RENEWABLE
#pragma push_macro("RENEWABLE_OK")
#undef RENEWABLE_OK
#pragma push_macro("RESERVED")
#undef RESERVED
#pragma push_macro("UNUSED10")
#undef UNUSED10
#pragma push_macro("UNUSED11")
#undef UNUSED11
#pragma push_macro("UNUSED7")
#undef UNUSED7
#pragma push_macro("UNUSED9")
#undef UNUSED9
#pragma push_macro("VALIDATE")
#undef VALIDATE

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
			namespace internal {

class $export KDCOptions : public ::sun::security::krb5::internal::util::KerberosFlags {
	$class(KDCOptions, 0, ::sun::security::krb5::internal::util::KerberosFlags)
public:
	KDCOptions();
	void init$();
	void init$(int32_t size, $bytes* data);
	void init$($booleans* data);
	void init$(::sun::security::util::DerValue* encoding);
	void init$($bytes* options);
	virtual bool get(int32_t option) override;
	static ::sun::security::krb5::internal::KDCOptions* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	virtual void set(int32_t option, bool value) override;
	void setDefault();
	virtual $String* toString() override;
	static ::sun::security::krb5::internal::KDCOptions* with($ints* flags);
	static const int32_t KDC_OPT_PROXIABLE = 0x10000000;
	static const int32_t KDC_OPT_RENEWABLE_OK = 16;
	static const int32_t KDC_OPT_FORWARDABLE = 0x40000000;
	static const int32_t RESERVED = 0;
	static const int32_t FORWARDABLE = 1;
	static const int32_t FORWARDED = 2;
	static const int32_t PROXIABLE = 3;
	static const int32_t PROXY = 4;
	static const int32_t ALLOW_POSTDATE = 5;
	static const int32_t POSTDATED = 6;
	static const int32_t UNUSED7 = 7;
	static const int32_t RENEWABLE = 8;
	static const int32_t UNUSED9 = 9;
	static const int32_t UNUSED10 = 10;
	static const int32_t UNUSED11 = 11;
	static const int32_t CNAME_IN_ADDL_TKT = 14;
	static const int32_t CANONICALIZE = 15;
	static const int32_t RENEWABLE_OK = 27;
	static const int32_t ENC_TKT_IN_SKEY = 28;
	static const int32_t RENEW = 30;
	static const int32_t VALIDATE = 31;
	static $StringArray* names;
	bool DEBUG = false;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("ALLOW_POSTDATE")
#pragma pop_macro("CANONICALIZE")
#pragma pop_macro("CNAME_IN_ADDL_TKT")
#pragma pop_macro("DEBUG")
#pragma pop_macro("ENC_TKT_IN_SKEY")
#pragma pop_macro("FORWARDABLE")
#pragma pop_macro("FORWARDED")
#pragma pop_macro("KDC_OPT_FORWARDABLE")
#pragma pop_macro("KDC_OPT_PROXIABLE")
#pragma pop_macro("KDC_OPT_RENEWABLE_OK")
#pragma pop_macro("POSTDATED")
#pragma pop_macro("PROXIABLE")
#pragma pop_macro("PROXY")
#pragma pop_macro("RENEW")
#pragma pop_macro("RENEWABLE")
#pragma pop_macro("RENEWABLE_OK")
#pragma pop_macro("RESERVED")
#pragma pop_macro("UNUSED10")
#pragma pop_macro("UNUSED11")
#pragma pop_macro("UNUSED7")
#pragma pop_macro("UNUSED9")
#pragma pop_macro("VALIDATE")

#endif // _sun_security_krb5_internal_KDCOptions_h_