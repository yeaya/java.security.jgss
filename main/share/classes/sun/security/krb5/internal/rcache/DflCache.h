#ifndef _sun_security_krb5_internal_rcache_DflCache_h_
#define _sun_security_krb5_internal_rcache_DflCache_h_
//$ class sun.security.krb5.internal.rcache.DflCache
//$ extends sun.security.krb5.internal.ReplayCache

#include <sun/security/krb5/internal/ReplayCache.h>

#pragma push_macro("EXCESSREPS")
#undef EXCESSREPS
#pragma push_macro("KRB5_RV_VNO")
#undef KRB5_RV_VNO

namespace java {
	namespace nio {
		namespace file {
			class Path;
		}
	}
}
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
				namespace rcache {

class DflCache : public ::sun::security::krb5::internal::ReplayCache {
	$class(DflCache, 0, ::sun::security::krb5::internal::ReplayCache)
public:
	DflCache();
	void init$($String* source);
	virtual void checkAndStore(::sun::security::krb5::internal::KerberosTime* currTime, ::sun::security::krb5::internal::rcache::AuthTimeWithHash* time) override;
	void checkAndStore0(::sun::security::krb5::internal::KerberosTime* currTime, ::sun::security::krb5::internal::rcache::AuthTimeWithHash* time);
	static $String* defaultFile($String* server);
	static $String* defaultPath();
	static ::java::nio::file::Path* getFileName($String* source, $String* server);
	static const int32_t KRB5_RV_VNO = 1281;
	static const int32_t EXCESSREPS = 30;
	$String* source = nullptr;
	static int64_t uid;
};

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("EXCESSREPS")
#pragma pop_macro("KRB5_RV_VNO")

#endif // _sun_security_krb5_internal_rcache_DflCache_h_