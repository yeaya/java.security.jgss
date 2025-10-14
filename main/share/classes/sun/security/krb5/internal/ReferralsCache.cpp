#include <sun/security/krb5/internal/ReferralsCache.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSequentialList.h>
#include <java/util/Date.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/ReferralsCache$ReferralCacheEntry.h>
#include <sun/security/krb5/internal/ReferralsCache$ReferralCacheKey.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractSequentialList = ::java::util::AbstractSequentialList;
using $Date = ::java::util::Date;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Credentials = ::sun::security::krb5::Credentials;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $ReferralsCache$ReferralCacheEntry = ::sun::security::krb5::internal::ReferralsCache$ReferralCacheEntry;
using $ReferralsCache$ReferralCacheKey = ::sun::security::krb5::internal::ReferralsCache$ReferralCacheKey;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _ReferralsCache_FieldInfo_[] = {
	{"referralsMap", "Ljava/util/Map;", "Ljava/util/Map<Lsun/security/krb5/internal/ReferralsCache$ReferralCacheKey;Ljava/util/Map<Ljava/lang/String;Lsun/security/krb5/internal/ReferralsCache$ReferralCacheEntry;>;>;", $PRIVATE | $STATIC, $staticField(ReferralsCache, referralsMap)},
	{}
};

$MethodInfo _ReferralsCache_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(ReferralsCache::*)()>(&ReferralsCache::init$))},
	{"get", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Ljava/lang/String;)Lsun/security/krb5/internal/ReferralsCache$ReferralCacheEntry;", nullptr, $STATIC | $SYNCHRONIZED, $method(static_cast<$ReferralsCache$ReferralCacheEntry*(*)($PrincipalName*,$PrincipalName*,$String*)>(&ReferralsCache::get))},
	{"pruneExpired", "(Lsun/security/krb5/internal/ReferralsCache$ReferralCacheKey;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($ReferralsCache$ReferralCacheKey*)>(&ReferralsCache::pruneExpired))},
	{"put", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Ljava/lang/String;Ljava/lang/String;Lsun/security/krb5/Credentials;)V", nullptr, $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)($PrincipalName*,$PrincipalName*,$String*,$String*,$Credentials*)>(&ReferralsCache::put))},
	{}
};

$InnerClassInfo _ReferralsCache_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ReferralsCache$ReferralCacheEntry", "sun.security.krb5.internal.ReferralsCache", "ReferralCacheEntry", $STATIC | $FINAL},
	{"sun.security.krb5.internal.ReferralsCache$ReferralCacheKey", "sun.security.krb5.internal.ReferralsCache", "ReferralCacheKey", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ReferralsCache_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.ReferralsCache",
	"java.lang.Object",
	nullptr,
	_ReferralsCache_FieldInfo_,
	_ReferralsCache_MethodInfo_,
	nullptr,
	nullptr,
	_ReferralsCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ReferralsCache$ReferralCacheEntry,sun.security.krb5.internal.ReferralsCache$ReferralCacheKey"
};

$Object* allocate$ReferralsCache($Class* clazz) {
	return $of($alloc(ReferralsCache));
}

$Map* ReferralsCache::referralsMap = nullptr;

void ReferralsCache::init$() {
}

void ReferralsCache::put($PrincipalName* cname, $PrincipalName* service, $String* fromRealm, $String* toRealm, $Credentials* creds) {
	$load(ReferralsCache);
	$synchronized(class$) {
		$init(ReferralsCache);
		$var($ReferralsCache$ReferralCacheKey, k, $new($ReferralsCache$ReferralCacheKey, cname, service));
		pruneExpired(k);
		if ($nc($($nc(creds)->getEndTime()))->before($$new($Date))) {
			return;
		}
		$var($Map, entries, $cast($Map, $nc(ReferralsCache::referralsMap)->get(k)));
		if (entries == nullptr) {
			$assign(entries, $new($HashMap));
			$nc(ReferralsCache::referralsMap)->put(k, entries);
		}
		$nc(entries)->remove(fromRealm);
		$var($ReferralsCache$ReferralCacheEntry, newEntry, $new($ReferralsCache$ReferralCacheEntry, creds, toRealm));
		entries->put(fromRealm, newEntry);
		$var($ReferralsCache$ReferralCacheEntry, current, newEntry);
		$var($List, seen, $new($LinkedList));
		while (current != nullptr) {
			if (seen->contains(current)) {
				entries->remove($(newEntry->getToRealm()));
				break;
			}
			seen->add(current);
			$assign(current, $cast($ReferralsCache$ReferralCacheEntry, entries->get($(current->getToRealm()))));
		}
	}
}

$ReferralsCache$ReferralCacheEntry* ReferralsCache::get($PrincipalName* cname, $PrincipalName* service, $String* fromRealm) {
	$load(ReferralsCache);
	$synchronized(class$) {
		$init(ReferralsCache);
		$var($ReferralsCache$ReferralCacheKey, k, $new($ReferralsCache$ReferralCacheKey, cname, service));
		pruneExpired(k);
		$var($Map, entries, $cast($Map, $nc(ReferralsCache::referralsMap)->get(k)));
		if (entries != nullptr) {
			$var($ReferralsCache$ReferralCacheEntry, toRef, $cast($ReferralsCache$ReferralCacheEntry, entries->get(fromRealm)));
			if (toRef != nullptr) {
				return toRef;
			}
		}
		return nullptr;
	}
}

void ReferralsCache::pruneExpired($ReferralsCache$ReferralCacheKey* k) {
	$init(ReferralsCache);
	$var($Date, now, $new($Date));
	$var($Map, entries, $cast($Map, $nc(ReferralsCache::referralsMap)->get(k)));
	if (entries != nullptr) {
		{
			$var($Iterator, i$, $nc($(entries->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, mapEntry, $cast($Map$Entry, i$->next()));
				{
					if ($nc($($nc($($nc(($cast($ReferralsCache$ReferralCacheEntry, $($nc(mapEntry)->getValue()))))->getCreds()))->getEndTime()))->before(now)) {
						entries->remove($(mapEntry->getKey()));
					}
				}
			}
		}
	}
}

void clinit$ReferralsCache($Class* class$) {
	$assignStatic(ReferralsCache::referralsMap, $new($HashMap));
}

ReferralsCache::ReferralsCache() {
}

$Class* ReferralsCache::load$($String* name, bool initialize) {
	$loadClass(ReferralsCache, name, initialize, &_ReferralsCache_ClassInfo_, clinit$ReferralsCache, allocate$ReferralsCache);
	return class$;
}

$Class* ReferralsCache::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun