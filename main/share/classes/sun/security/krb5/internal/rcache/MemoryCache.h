#ifndef _sun_security_krb5_internal_rcache_MemoryCache_h_
#define _sun_security_krb5_internal_rcache_MemoryCache_h_
//$ class sun.security.krb5.internal.rcache.MemoryCache
//$ extends sun.security.krb5.internal.ReplayCache

#include <sun/security/krb5/internal/ReplayCache.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace util {
		class Map;
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
					class AuthList;
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

class MemoryCache : public ::sun::security::krb5::internal::ReplayCache {
	$class(MemoryCache, 0, ::sun::security::krb5::internal::ReplayCache)
public:
	MemoryCache();
	void init$();
	virtual void checkAndStore(::sun::security::krb5::internal::KerberosTime* currTime, ::sun::security::krb5::internal::rcache::AuthTimeWithHash* time) override;
	static ::sun::security::krb5::internal::rcache::AuthList* lambda$checkAndStore$0($String* k);
	virtual $String* toString() override;
	static int32_t lifespan;
	static bool DEBUG;
	::java::util::Map* content = nullptr;
};

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_rcache_MemoryCache_h_