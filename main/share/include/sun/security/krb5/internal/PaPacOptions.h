#ifndef _sun_security_krb5_internal_PaPacOptions_h_
#define _sun_security_krb5_internal_PaPacOptions_h_
//$ class sun.security.krb5.internal.PaPacOptions
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("BRANCH_AWARE")
#undef BRANCH_AWARE
#pragma push_macro("CLAIMS")
#undef CLAIMS
#pragma push_macro("FORWARD_TO_FULL_DC")
#undef FORWARD_TO_FULL_DC
#pragma push_macro("RESOURCE_BASED_CONSTRAINED_DELEGATION")
#undef RESOURCE_BASED_CONSTRAINED_DELEGATION

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace util {
					class KerberosFlags;
				}
			}
		}
	}
}
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

class $import PaPacOptions : public ::java::lang::Object {
	$class(PaPacOptions, $NO_CLASS_INIT, ::java::lang::Object)
public:
	PaPacOptions();
	void init$();
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual bool getBranchAware();
	virtual bool getClaims();
	virtual bool getForwardToFullDC();
	virtual bool getResourceBasedConstrainedDelegation();
	virtual ::sun::security::krb5::internal::PaPacOptions* setBranchAware(bool value);
	virtual ::sun::security::krb5::internal::PaPacOptions* setClaims(bool value);
	virtual ::sun::security::krb5::internal::PaPacOptions* setForwardToFullDC(bool value);
	virtual ::sun::security::krb5::internal::PaPacOptions* setResourceBasedConstrainedDelegation(bool value);
	virtual $String* toString() override;
	static const int32_t CLAIMS = 0;
	static const int32_t BRANCH_AWARE = 1;
	static const int32_t FORWARD_TO_FULL_DC = 2;
	static const int32_t RESOURCE_BASED_CONSTRAINED_DELEGATION = 3;
	::sun::security::krb5::internal::util::KerberosFlags* flags = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("BRANCH_AWARE")
#pragma pop_macro("CLAIMS")
#pragma pop_macro("FORWARD_TO_FULL_DC")
#pragma pop_macro("RESOURCE_BASED_CONSTRAINED_DELEGATION")

#endif // _sun_security_krb5_internal_PaPacOptions_h_