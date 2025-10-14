#ifndef _sun_security_krb5_internal_ReplayCache$1_h_
#define _sun_security_krb5_internal_ReplayCache$1_h_
//$ class sun.security.krb5.internal.ReplayCache$1
//$ extends sun.security.krb5.internal.ReplayCache

#include <sun/security/krb5/internal/ReplayCache.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class KerberosTime;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {
					class AuthTimeWithHash;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class ReplayCache$1 : public ::sun::security::krb5::internal::ReplayCache {
	$class(ReplayCache$1, $NO_CLASS_INIT, ::sun::security::krb5::internal::ReplayCache)
public:
	ReplayCache$1();
	void init$();
	virtual void checkAndStore(::sun::security::krb5::internal::KerberosTime* currTime, ::sun::security::krb5::internal::rcache::AuthTimeWithHash* time) override;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ReplayCache$1_h_