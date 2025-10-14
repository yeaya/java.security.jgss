#ifndef _sun_security_jgss_spnego_SpNegoToken$NegoResult_h_
#define _sun_security_jgss_spnego_SpNegoToken$NegoResult_h_
//$ class sun.security.jgss.spnego.SpNegoToken$NegoResult
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("ACCEPT_COMPLETE")
#undef ACCEPT_COMPLETE
#pragma push_macro("ACCEPT_INCOMPLETE")
#undef ACCEPT_INCOMPLETE
#pragma push_macro("REJECT")
#undef REJECT

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

class SpNegoToken$NegoResult : public ::java::lang::Enum {
	$class(SpNegoToken$NegoResult, 0, ::java::lang::Enum)
public:
	SpNegoToken$NegoResult();
	static $Array<::sun::security::jgss::spnego::SpNegoToken$NegoResult>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::sun::security::jgss::spnego::SpNegoToken$NegoResult* valueOf($String* name);
	static $Array<::sun::security::jgss::spnego::SpNegoToken$NegoResult>* values();
	static ::sun::security::jgss::spnego::SpNegoToken$NegoResult* ACCEPT_COMPLETE;
	static ::sun::security::jgss::spnego::SpNegoToken$NegoResult* ACCEPT_INCOMPLETE;
	static ::sun::security::jgss::spnego::SpNegoToken$NegoResult* REJECT;
	static $Array<::sun::security::jgss::spnego::SpNegoToken$NegoResult>* $VALUES;
};

			} // spnego
		} // jgss
	} // security
} // sun

#pragma pop_macro("ACCEPT_COMPLETE")
#pragma pop_macro("ACCEPT_INCOMPLETE")
#pragma pop_macro("REJECT")

#endif // _sun_security_jgss_spnego_SpNegoToken$NegoResult_h_