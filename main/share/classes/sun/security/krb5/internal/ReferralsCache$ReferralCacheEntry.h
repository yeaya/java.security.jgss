#ifndef _sun_security_krb5_internal_ReferralsCache$ReferralCacheEntry_h_
#define _sun_security_krb5_internal_ReferralsCache$ReferralCacheEntry_h_
//$ class sun.security.krb5.internal.ReferralsCache$ReferralCacheEntry
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class ReferralsCache$ReferralCacheEntry : public ::java::lang::Object {
	$class(ReferralsCache$ReferralCacheEntry, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ReferralsCache$ReferralCacheEntry();
	void init$(::sun::security::krb5::Credentials* creds, $String* toRealm);
	::sun::security::krb5::Credentials* getCreds();
	$String* getToRealm();
	::sun::security::krb5::Credentials* creds = nullptr;
	$String* toRealm = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ReferralsCache$ReferralCacheEntry_h_