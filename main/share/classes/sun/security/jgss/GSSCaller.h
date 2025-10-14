#ifndef _sun_security_jgss_GSSCaller_h_
#define _sun_security_jgss_GSSCaller_h_
//$ class sun.security.jgss.GSSCaller
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("CALLER_ACCEPT")
#undef CALLER_ACCEPT
#pragma push_macro("CALLER_INITIATE")
#undef CALLER_INITIATE
#pragma push_macro("CALLER_UNKNOWN")
#undef CALLER_UNKNOWN

namespace sun {
	namespace security {
		namespace jgss {

class $export GSSCaller : public ::java::lang::Object {
	$class(GSSCaller, 0, ::java::lang::Object)
public:
	GSSCaller();
	void init$($String* s);
	virtual $String* toString() override;
	static ::sun::security::jgss::GSSCaller* CALLER_UNKNOWN;
	static ::sun::security::jgss::GSSCaller* CALLER_INITIATE;
	static ::sun::security::jgss::GSSCaller* CALLER_ACCEPT;
	$String* name = nullptr;
};

		} // jgss
	} // security
} // sun

#pragma pop_macro("CALLER_ACCEPT")
#pragma pop_macro("CALLER_INITIATE")
#pragma pop_macro("CALLER_UNKNOWN")

#endif // _sun_security_jgss_GSSCaller_h_