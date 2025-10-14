#include <sun/security/krb5/internal/ReferralsCache$ReferralCacheKey.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/ReferralsCache.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $ReferralsCache = ::sun::security::krb5::internal::ReferralsCache;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _ReferralsCache$ReferralCacheKey_FieldInfo_[] = {
	{"cname", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(ReferralsCache$ReferralCacheKey, cname)},
	{"sname", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(ReferralsCache$ReferralCacheKey, sname)},
	{}
};

$MethodInfo _ReferralsCache$ReferralCacheKey_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;)V", nullptr, 0, $method(static_cast<void(ReferralsCache$ReferralCacheKey::*)($PrincipalName*,$PrincipalName*)>(&ReferralsCache$ReferralCacheKey::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ReferralsCache$ReferralCacheKey_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ReferralsCache$ReferralCacheKey", "sun.security.krb5.internal.ReferralsCache", "ReferralCacheKey", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ReferralsCache$ReferralCacheKey_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.ReferralsCache$ReferralCacheKey",
	"java.lang.Object",
	nullptr,
	_ReferralsCache$ReferralCacheKey_FieldInfo_,
	_ReferralsCache$ReferralCacheKey_MethodInfo_,
	nullptr,
	nullptr,
	_ReferralsCache$ReferralCacheKey_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ReferralsCache"
};

$Object* allocate$ReferralsCache$ReferralCacheKey($Class* clazz) {
	return $of($alloc(ReferralsCache$ReferralCacheKey));
}

void ReferralsCache$ReferralCacheKey::init$($PrincipalName* cname, $PrincipalName* sname) {
	$set(this, cname, cname);
	$set(this, sname, sname);
}

bool ReferralsCache$ReferralCacheKey::equals(Object$* other) {
	if (!($instanceOf(ReferralsCache$ReferralCacheKey, other))) {
		return false;
	}
	$var(ReferralsCache$ReferralCacheKey, that, $cast(ReferralsCache$ReferralCacheKey, other));
	bool var$0 = $nc(this->cname)->equals($nc(that)->cname);
	return var$0 && $nc(this->sname)->equals($nc(that)->sname);
}

int32_t ReferralsCache$ReferralCacheKey::hashCode() {
	int32_t var$0 = $nc(this->cname)->hashCode();
	return var$0 + $nc(this->sname)->hashCode();
}

ReferralsCache$ReferralCacheKey::ReferralsCache$ReferralCacheKey() {
}

$Class* ReferralsCache$ReferralCacheKey::load$($String* name, bool initialize) {
	$loadClass(ReferralsCache$ReferralCacheKey, name, initialize, &_ReferralsCache$ReferralCacheKey_ClassInfo_, allocate$ReferralsCache$ReferralCacheKey);
	return class$;
}

$Class* ReferralsCache$ReferralCacheKey::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun