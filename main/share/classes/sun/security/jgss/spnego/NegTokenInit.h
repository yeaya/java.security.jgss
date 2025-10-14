#ifndef _sun_security_jgss_spnego_NegTokenInit_h_
#define _sun_security_jgss_spnego_NegTokenInit_h_
//$ class sun.security.jgss.spnego.NegTokenInit
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
		namespace util {
			class BitArray;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

class NegTokenInit : public ::sun::security::jgss::spnego::SpNegoToken {
	$class(NegTokenInit, $NO_CLASS_INIT, ::sun::security::jgss::spnego::SpNegoToken)
public:
	NegTokenInit();
	void init$($bytes* mechTypes, ::sun::security::util::BitArray* flags, $bytes* token, $bytes* mechListMIC);
	void init$($bytes* in);
	virtual $bytes* encode() override;
	virtual $bytes* getMechListMIC();
	virtual $bytes* getMechToken();
	virtual $Array<::org::ietf::jgss::Oid>* getMechTypeList();
	virtual $bytes* getMechTypes();
	virtual ::sun::security::util::BitArray* getReqFlags();
	void parseToken($bytes* in);
	$bytes* mechTypes = nullptr;
	$Array<::org::ietf::jgss::Oid>* mechTypeList = nullptr;
	::sun::security::util::BitArray* reqFlags = nullptr;
	$bytes* mechToken = nullptr;
	$bytes* mechListMIC = nullptr;
};

			} // spnego
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_spnego_NegTokenInit_h_