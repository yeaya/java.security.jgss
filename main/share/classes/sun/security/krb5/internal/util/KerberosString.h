#ifndef _sun_security_krb5_internal_util_KerberosString_h_
#define _sun_security_krb5_internal_util_KerberosString_h_
//$ class sun.security.krb5.internal.util.KerberosString
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("MSNAME")
#undef MSNAME

namespace sun {
	namespace security {
		namespace util {
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace util {

class KerberosString : public ::java::lang::Object {
	$class(KerberosString, 0, ::java::lang::Object)
public:
	KerberosString();
	void init$($String* s);
	void init$(::sun::security::util::DerValue* der);
	::sun::security::util::DerValue* toDerValue();
	virtual $String* toString() override;
	static bool MSNAME;
	$String* s = nullptr;
};

				} // util
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("MSNAME")

#endif // _sun_security_krb5_internal_util_KerberosString_h_