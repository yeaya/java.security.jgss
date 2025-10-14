#ifndef _sun_security_jgss_krb5_Krb5Token_h_
#define _sun_security_jgss_krb5_Krb5Token_h_
//$ class sun.security.jgss.krb5.Krb5Token
//$ extends sun.security.jgss.GSSToken

#include <sun/security/jgss/GSSToken.h>

#pragma push_macro("AP_REP_ID")
#undef AP_REP_ID
#pragma push_macro("AP_REQ_ID")
#undef AP_REQ_ID
#pragma push_macro("ERR_ID")
#undef ERR_ID
#pragma push_macro("MIC_ID")
#undef MIC_ID
#pragma push_macro("OID")
#undef OID
#pragma push_macro("WRAP_ID")
#undef WRAP_ID

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
			namespace krb5 {

class Krb5Token : public ::sun::security::jgss::GSSToken {
	$class(Krb5Token, 0, ::sun::security::jgss::GSSToken)
public:
	Krb5Token();
	void init$();
	static $String* getTokenName(int32_t tokenId);
	static const int32_t AP_REQ_ID = 256;
	static const int32_t AP_REP_ID = 512;
	static const int32_t ERR_ID = 768;
	static const int32_t MIC_ID = 257;
	static const int32_t WRAP_ID = 513;
	static const int32_t MIC_ID_v2 = 1028;
	static const int32_t WRAP_ID_v2 = 1284;
	static ::sun::security::util::ObjectIdentifier* OID;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("AP_REP_ID")
#pragma pop_macro("AP_REQ_ID")
#pragma pop_macro("ERR_ID")
#pragma pop_macro("MIC_ID")
#pragma pop_macro("OID")
#pragma pop_macro("WRAP_ID")

#endif // _sun_security_jgss_krb5_Krb5Token_h_