#ifndef _sun_security_jgss_spnego_NegTokenTarg_h_
#define _sun_security_jgss_spnego_NegTokenTarg_h_
//$ class sun.security.jgss.spnego.NegTokenTarg
//$ extends sun.security.jgss.spnego.SpNegoToken

#include <java/lang/Array.h>
#include <sun/security/jgss/spnego/SpNegoToken.h>

namespace org {
	namespace ietf {
		namespace jgss {
			class Oid;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

class NegTokenTarg : public ::sun::security::jgss::spnego::SpNegoToken {
	$class(NegTokenTarg, $NO_CLASS_INIT, ::sun::security::jgss::spnego::SpNegoToken)
public:
	NegTokenTarg();
	void init$(int32_t result, ::org::ietf::jgss::Oid* mech, $bytes* token, $bytes* mechListMIC);
	void init$($bytes* in);
	virtual $bytes* encode() override;
	virtual $bytes* getMechListMIC();
	virtual int32_t getNegotiatedResult();
	virtual $bytes* getResponseToken();
	virtual ::org::ietf::jgss::Oid* getSupportedMech();
	void parseToken($bytes* in);
	int32_t negResult = 0;
	::org::ietf::jgss::Oid* supportedMech = nullptr;
	$bytes* responseToken = nullptr;
	$bytes* mechListMIC = nullptr;
};

			} // spnego
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_spnego_NegTokenTarg_h_