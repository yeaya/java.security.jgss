#ifndef _sun_security_jgss_spnego_SpNegoToken_h_
#define _sun_security_jgss_spnego_SpNegoToken_h_
//$ class sun.security.jgss.spnego.SpNegoToken
//$ extends sun.security.jgss.GSSToken

#include <java/lang/Array.h>
#include <sun/security/jgss/GSSToken.h>

#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("NEG_TOKEN_INIT_ID")
#undef NEG_TOKEN_INIT_ID
#pragma push_macro("NEG_TOKEN_TARG_ID")
#undef NEG_TOKEN_TARG_ID
#pragma push_macro("OID")
#undef OID

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {
				class SpNegoToken$NegoResult;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class ObjectIdentifier;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

class SpNegoToken : public ::sun::security::jgss::GSSToken {
	$class(SpNegoToken, 0, ::sun::security::jgss::GSSToken)
public:
	SpNegoToken();
	void init$(int32_t tokenType);
	static int32_t checkNextField(int32_t last, int32_t current);
	virtual $bytes* encode() {return nullptr;}
	virtual $bytes* getEncoded();
	static $String* getNegoResultString(int32_t result);
	static ::sun::security::jgss::spnego::SpNegoToken$NegoResult* getNegoResultType(int32_t result);
	static $String* getTokenName(int32_t type);
	int32_t getType();
	static const int32_t NEG_TOKEN_INIT_ID = 0;
	static const int32_t NEG_TOKEN_TARG_ID = 1;
	int32_t tokenType = 0;
	static bool DEBUG;
	static ::sun::security::util::ObjectIdentifier* OID;
};

			} // spnego
		} // jgss
	} // security
} // sun

#pragma pop_macro("DEBUG")
#pragma pop_macro("NEG_TOKEN_INIT_ID")
#pragma pop_macro("NEG_TOKEN_TARG_ID")
#pragma pop_macro("OID")

#endif // _sun_security_jgss_spnego_SpNegoToken_h_