#ifndef _sun_security_jgss_SunProvider_h_
#define _sun_security_jgss_SunProvider_h_
//$ class sun.security.jgss.SunProvider
//$ extends java.security.Provider

#include <java/security/Provider.h>

#pragma push_macro("INFO")
#undef INFO

namespace java {
	namespace security {
		class Provider$Service;
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $export SunProvider : public ::java::security::Provider {
	$class(SunProvider, 0, ::java::security::Provider)
public:
	SunProvider();
	using ::java::security::Provider::getProperty;
	void init$();
	static void access$000(::sun::security::jgss::SunProvider* x0, ::java::security::Provider$Service* x1);
	static void access$100(::sun::security::jgss::SunProvider* x0, ::java::security::Provider$Service* x1);
	using ::java::security::Provider::load;
	static const int64_t serialVersionUID = (int64_t)0xFCAF370D531F25CA;
	static $String* INFO;
};

		} // jgss
	} // security
} // sun

#pragma pop_macro("INFO")

#endif // _sun_security_jgss_SunProvider_h_