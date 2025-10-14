#ifndef _sun_security_krb5_KrbTgsRep_h_
#define _sun_security_krb5_KrbTgsRep_h_
//$ class sun.security.krb5.KrbTgsRep
//$ extends sun.security.krb5.KrbKdcRep

#include <java/lang/Array.h>
#include <sun/security/krb5/KrbKdcRep.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class KrbTgsReq;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class TGSRep;
				class Ticket;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {
					class Credentials;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import KrbTgsRep : public ::sun::security::krb5::KrbKdcRep {
	$class(KrbTgsRep, $NO_CLASS_INIT, ::sun::security::krb5::KrbKdcRep)
public:
	KrbTgsRep();
	void init$($bytes* ibuf, ::sun::security::krb5::KrbTgsReq* tgsReq);
	virtual ::sun::security::krb5::Credentials* getCreds();
	static bool isReferralSname(::sun::security::krb5::PrincipalName* sname);
	virtual ::sun::security::krb5::internal::ccache::Credentials* setCredentials();
	::sun::security::krb5::internal::TGSRep* rep = nullptr;
	::sun::security::krb5::Credentials* creds = nullptr;
	::sun::security::krb5::internal::Ticket* secondTicket = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbTgsRep_h_