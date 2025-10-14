#ifndef _sun_security_krb5_internal_ReferralsCache_h_
#define _sun_security_krb5_internal_ReferralsCache_h_
//$ class sun.security.krb5.internal.ReferralsCache
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		class Map;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class ReferralsCache$ReferralCacheEntry;
				class ReferralsCache$ReferralCacheKey;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class ReferralsCache : public ::java::lang::Object {
	$class(ReferralsCache, 0, ::java::lang::Object)
public:
	ReferralsCache();
	void init$();
	static ::sun::security::krb5::internal::ReferralsCache$ReferralCacheEntry* get(::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* service, $String* fromRealm);
	static void pruneExpired(::sun::security::krb5::internal::ReferralsCache$ReferralCacheKey* k);
	static void put(::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* service, $String* fromRealm, $String* toRealm, ::sun::security::krb5::Credentials* creds);
	static ::java::util::Map* referralsMap;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ReferralsCache_h_