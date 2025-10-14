#ifndef _sun_security_krb5_internal_ReplayCache_h_
#define _sun_security_krb5_internal_ReplayCache_h_
//$ class sun.security.krb5.internal.ReplayCache
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class $export ReplayCache : public ::java::lang::Object {
	$class(ReplayCache, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ReplayCache();
	void init$();
	virtual void checkAndStore(::sun::security::krb5::internal::KerberosTime* currTime, ::sun::security::krb5::internal::rcache::AuthTimeWithHash* time) {}
	static ::sun::security::krb5::internal::ReplayCache* getInstance($String* type);
	static ::sun::security::krb5::internal::ReplayCache* getInstance();
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ReplayCache_h_