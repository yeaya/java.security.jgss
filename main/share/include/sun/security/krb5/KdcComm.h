#ifndef _sun_security_krb5_KdcComm_h_
#define _sun_security_krb5_KdcComm_h_
//$ class sun.security.krb5.KdcComm
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			class KdcComm$BpType;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import KdcComm : public ::java::lang::Object {
	$class(KdcComm, 0, ::java::lang::Object)
public:
	KdcComm();
	void init$($String* realm);
	int32_t getRealmSpecificValue($String* realm, $String* key, int32_t defValue);
	static void initStatic();
	static int32_t parsePositiveIntString($String* intString);
	static int32_t parseTimeString($String* s);
	$bytes* send($bytes* obuf);
	$bytes* send($bytes* obuf, bool useTCP);
	$bytes* send($bytes* obuf, $String* tempKdc, bool useTCP);
	$bytes* sendIfPossible($bytes* obuf, $String* tempKdc, bool useTCP);
	static int32_t defaultKdcRetryLimit;
	static int32_t defaultKdcTimeout;
	static int32_t defaultUdpPrefLimit;
	static bool DEBUG;
	static int32_t tryLessMaxRetries;
	static int32_t tryLessTimeout;
	static ::sun::security::krb5::KdcComm$BpType* badPolicy;
	$String* realm = nullptr;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_KdcComm_h_