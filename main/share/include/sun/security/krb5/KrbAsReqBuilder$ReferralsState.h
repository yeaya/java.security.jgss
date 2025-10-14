#ifndef _sun_security_krb5_KrbAsReqBuilder$ReferralsState_h_
#define _sun_security_krb5_KrbAsReqBuilder$ReferralsState_h_
//$ class sun.security.krb5.KrbAsReqBuilder$ReferralsState
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class KrbAsReqBuilder;
			class KrbException;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import KrbAsReqBuilder$ReferralsState : public ::java::lang::Object {
	$class(KrbAsReqBuilder$ReferralsState, 0, ::java::lang::Object)
public:
	KrbAsReqBuilder$ReferralsState();
	void init$(::sun::security::krb5::KrbAsReqBuilder* reqBuilder);
	bool handleError(::sun::security::krb5::KrbException* ke);
	static void initStatic();
	bool isEnabled();
	bool refreshComm();
	bool sendCanonicalize();
	void updateStatus();
	static bool canonicalizeConfig;
	bool enabled = false;
	bool sendCanonicalize$ = false;
	bool isEnterpriseCname = false;
	int32_t count = 0;
	bool refreshComm$ = false;
	::sun::security::krb5::KrbAsReqBuilder* reqBuilder = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbAsReqBuilder$ReferralsState_h_