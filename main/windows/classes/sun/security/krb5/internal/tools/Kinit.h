#ifndef _sun_security_krb5_internal_tools_Kinit_h_
#define _sun_security_krb5_internal_tools_Kinit_h_
//$ class sun.security.krb5.internal.tools.Kinit
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class KDCOptions;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace tools {
					class KinitOptions;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace tools {

class $export Kinit : public ::java::lang::Object {
	$class(Kinit, 0, ::java::lang::Object)
public:
	Kinit();
	void init$($StringArray* args);
	void acquire();
	static void main($StringArray* args);
	void renew();
	static void setOptions(int32_t flag, int32_t option, ::sun::security::krb5::internal::KDCOptions* opt);
	::sun::security::krb5::internal::tools::KinitOptions* options = nullptr;
	static bool DEBUG;
};

				} // tools
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_tools_Kinit_h_