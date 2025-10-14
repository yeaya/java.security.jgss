#include <sun/security/krb5/internal/ReferralsCache$ReferralCacheEntry.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/internal/ReferralsCache.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Credentials = ::sun::security::krb5::Credentials;
using $ReferralsCache = ::sun::security::krb5::internal::ReferralsCache;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _ReferralsCache$ReferralCacheEntry_FieldInfo_[] = {
	{"creds", "Lsun/security/krb5/Credentials;", nullptr, $PRIVATE | $FINAL, $field(ReferralsCache$ReferralCacheEntry, creds)},
	{"toRealm", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ReferralsCache$ReferralCacheEntry, toRealm)},
	{}
};

$MethodInfo _ReferralsCache$ReferralCacheEntry_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/Credentials;Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(ReferralsCache$ReferralCacheEntry::*)($Credentials*,$String*)>(&ReferralsCache$ReferralCacheEntry::init$))},
	{"getCreds", "()Lsun/security/krb5/Credentials;", nullptr, 0, $method(static_cast<$Credentials*(ReferralsCache$ReferralCacheEntry::*)()>(&ReferralsCache$ReferralCacheEntry::getCreds))},
	{"getToRealm", "()Ljava/lang/String;", nullptr, 0, $method(static_cast<$String*(ReferralsCache$ReferralCacheEntry::*)()>(&ReferralsCache$ReferralCacheEntry::getToRealm))},
	{}
};

$InnerClassInfo _ReferralsCache$ReferralCacheEntry_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ReferralsCache$ReferralCacheEntry", "sun.security.krb5.internal.ReferralsCache", "ReferralCacheEntry", $STATIC | $FINAL},
	{}
};

$ClassInfo _ReferralsCache$ReferralCacheEntry_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.ReferralsCache$ReferralCacheEntry",
	"java.lang.Object",
	nullptr,
	_ReferralsCache$ReferralCacheEntry_FieldInfo_,
	_ReferralsCache$ReferralCacheEntry_MethodInfo_,
	nullptr,
	nullptr,
	_ReferralsCache$ReferralCacheEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ReferralsCache"
};

$Object* allocate$ReferralsCache$ReferralCacheEntry($Class* clazz) {
	return $of($alloc(ReferralsCache$ReferralCacheEntry));
}

void ReferralsCache$ReferralCacheEntry::init$($Credentials* creds, $String* toRealm) {
	$set(this, creds, creds);
	$set(this, toRealm, toRealm);
}

$Credentials* ReferralsCache$ReferralCacheEntry::getCreds() {
	return this->creds;
}

$String* ReferralsCache$ReferralCacheEntry::getToRealm() {
	return this->toRealm;
}

ReferralsCache$ReferralCacheEntry::ReferralsCache$ReferralCacheEntry() {
}

$Class* ReferralsCache$ReferralCacheEntry::load$($String* name, bool initialize) {
	$loadClass(ReferralsCache$ReferralCacheEntry, name, initialize, &_ReferralsCache$ReferralCacheEntry_ClassInfo_, allocate$ReferralsCache$ReferralCacheEntry);
	return class$;
}

$Class* ReferralsCache$ReferralCacheEntry::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun