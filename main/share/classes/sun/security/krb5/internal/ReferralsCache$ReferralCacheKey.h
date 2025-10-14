#ifndef _sun_security_krb5_internal_ReferralsCache$ReferralCacheKey_h_
#define _sun_security_krb5_internal_ReferralsCache$ReferralCacheKey_h_
//$ class sun.security.krb5.internal.ReferralsCache$ReferralCacheKey
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class ReferralsCache$ReferralCacheKey : public ::java::lang::Object {
	$class(ReferralsCache$ReferralCacheKey, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ReferralsCache$ReferralCacheKey();
	void init$(::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* sname);
	virtual bool equals(Object$* other) override;
	virtual int32_t hashCode() override;
	::sun::security::krb5::PrincipalName* cname = nullptr;
	::sun::security::krb5::PrincipalName* sname = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ReferralsCache$ReferralCacheKey_h_