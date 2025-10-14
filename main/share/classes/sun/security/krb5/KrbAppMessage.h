#ifndef _sun_security_krb5_KrbAppMessage_h_
#define _sun_security_krb5_KrbAppMessage_h_
//$ class sun.security.krb5.KrbAppMessage
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace lang {
		class Integer;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class HostAddress;
				class KerberosTime;
				class SeqNumber;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class KrbAppMessage : public ::java::lang::Object {
	$class(KrbAppMessage, 0, ::java::lang::Object)
public:
	KrbAppMessage();
	void init$();
	virtual void check(::sun::security::krb5::internal::KerberosTime* packetTimestamp, ::java::lang::Integer* packetUsec, ::java::lang::Integer* packetSeqNumber, ::sun::security::krb5::internal::HostAddress* packetSAddress, ::sun::security::krb5::internal::HostAddress* packetRAddress, ::sun::security::krb5::internal::SeqNumber* seqNumber, ::sun::security::krb5::internal::HostAddress* sAddress, ::sun::security::krb5::internal::HostAddress* rAddress, bool timestampRequired, bool seqNumberRequired, ::sun::security::krb5::PrincipalName* packetPrincipal);
	static bool DEBUG;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_KrbAppMessage_h_