#ifndef _sun_security_krb5_internal_APOptions_h_
#define _sun_security_krb5_internal_APOptions_h_
//$ class sun.security.krb5.internal.APOptions
//$ extends sun.security.krb5.internal.util.KerberosFlags

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/util/KerberosFlags.h>

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

class $import APOptions : public ::sun::security::krb5::internal::util::KerberosFlags {
	$class(APOptions, $NO_CLASS_INIT, ::sun::security::krb5::internal::util::KerberosFlags)
public:
	APOptions();
	void init$();
	void init$(int32_t oneBit);
	void init$(int32_t size, $bytes* data);
	void init$($booleans* data);
	void init$(::sun::security::util::DerValue* encoding);
	static ::sun::security::krb5::internal::APOptions* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_APOptions_h_