#ifndef _sun_security_jgss_wrapper_SunNativeProvider_h_
#define _sun_security_jgss_wrapper_SunNativeProvider_h_
//$ class sun.security.jgss.wrapper.SunNativeProvider
//$ extends java.security.Provider

#include <java/security/Provider.h>

#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("INFO")
#undef INFO
#pragma push_macro("INSTANCE")
#undef INSTANCE
#pragma push_macro("MECH_MAP")
#undef MECH_MAP
#pragma push_macro("MF_CLASS")
#undef MF_CLASS
#pragma push_macro("NAME")
#undef NAME

namespace java {
	namespace util {
		class HashMap;
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

class SunNativeProvider : public ::java::security::Provider {
	$class(SunNativeProvider, 0, ::java::security::Provider)
public:
	SunNativeProvider();
	using ::java::security::Provider::load;
	using ::java::security::Provider::getProperty;
	void init$();
	static void debug($String* message);
	static const int64_t serialVersionUID = (int64_t)0xFCAF370D531F25C4;
	static $String* NAME;
	static $String* INFO;
	static $String* MF_CLASS;
	static bool DEBUG;
	static ::java::util::HashMap* MECH_MAP;
	static ::java::security::Provider* INSTANCE;
};

			} // wrapper
		} // jgss
	} // security
} // sun

#pragma pop_macro("DEBUG")
#pragma pop_macro("INFO")
#pragma pop_macro("INSTANCE")
#pragma pop_macro("MECH_MAP")
#pragma pop_macro("MF_CLASS")
#pragma pop_macro("NAME")

#endif // _sun_security_jgss_wrapper_SunNativeProvider_h_