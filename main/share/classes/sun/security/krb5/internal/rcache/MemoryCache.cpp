#include <sun/security/krb5/internal/rcache/MemoryCache.h>

#include <java/io/PrintStream.h>
#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Function.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/ReplayCache.h>
#include <sun/security/krb5/internal/rcache/AuthList.h>
#include <sun/security/krb5/internal/rcache/AuthTimeWithHash.h>
#include <jcpp.h>

#undef DEBUG

using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Function = ::java::util::function::Function;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $ReplayCache = ::sun::security::krb5::internal::ReplayCache;
using $AuthList = ::sun::security::krb5::internal::rcache::AuthList;
using $AuthTime = ::sun::security::krb5::internal::rcache::AuthTime;
using $AuthTimeWithHash = ::sun::security::krb5::internal::rcache::AuthTimeWithHash;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {

class MemoryCache$$Lambda$lambda$checkAndStore$0 : public $Function {
	$class(MemoryCache$$Lambda$lambda$checkAndStore$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(MemoryCache::lambda$checkAndStore$0($cast($String, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MemoryCache$$Lambda$lambda$checkAndStore$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MemoryCache$$Lambda$lambda$checkAndStore$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MemoryCache$$Lambda$lambda$checkAndStore$0::*)()>(&MemoryCache$$Lambda$lambda$checkAndStore$0::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MemoryCache$$Lambda$lambda$checkAndStore$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.krb5.internal.rcache.MemoryCache$$Lambda$lambda$checkAndStore$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* MemoryCache$$Lambda$lambda$checkAndStore$0::load$($String* name, bool initialize) {
	$loadClass(MemoryCache$$Lambda$lambda$checkAndStore$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MemoryCache$$Lambda$lambda$checkAndStore$0::class$ = nullptr;

$FieldInfo _MemoryCache_FieldInfo_[] = {
	{"lifespan", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MemoryCache, lifespan)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MemoryCache, DEBUG)},
	{"content", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/krb5/internal/rcache/AuthList;>;", $PRIVATE | $FINAL, $field(MemoryCache, content)},
	{}
};

$MethodInfo _MemoryCache_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MemoryCache::*)()>(&MemoryCache::init$))},
	{"checkAndStore", "(Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/rcache/AuthTimeWithHash;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "sun.security.krb5.internal.KrbApErrException"},
	{"lambda$checkAndStore$0", "(Ljava/lang/String;)Lsun/security/krb5/internal/rcache/AuthList;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$AuthList*(*)($String*)>(&MemoryCache::lambda$checkAndStore$0))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _MemoryCache_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.rcache.MemoryCache",
	"sun.security.krb5.internal.ReplayCache",
	nullptr,
	_MemoryCache_FieldInfo_,
	_MemoryCache_MethodInfo_
};

$Object* allocate$MemoryCache($Class* clazz) {
	return $of($alloc(MemoryCache));
}

int32_t MemoryCache::lifespan = 0;
bool MemoryCache::DEBUG = false;

void MemoryCache::init$() {
	$ReplayCache::init$();
	$set(this, content, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
}

void MemoryCache::checkAndStore($KerberosTime* currTime, $AuthTimeWithHash* time) {
	$synchronized(this) {
		$var($String, key, $str({$nc(time)->client, "|"_s, time->server}));
		$nc(($cast($AuthList, $($nc(this->content)->computeIfAbsent(key, static_cast<$Function*>($$new(MemoryCache$$Lambda$lambda$checkAndStore$0)))))))->put(time, currTime);
		if (MemoryCache::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({"MemoryCache: add "_s, time, " to "_s, key}));
		}
	}
}

$String* MemoryCache::toString() {
	$var($StringBuilder, sb, $new($StringBuilder));
	{
		$var($Iterator, i$, $nc($($nc(this->content)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($AuthList, rc, $cast($AuthList, i$->next()));
			{
				sb->append($($nc(rc)->toString()));
			}
		}
	}
	return sb->toString();
}

$AuthList* MemoryCache::lambda$checkAndStore$0($String* k) {
	$init(MemoryCache);
	return $new($AuthList, MemoryCache::lifespan);
}

void clinit$MemoryCache($Class* class$) {
	MemoryCache::lifespan = $KerberosTime::getDefaultSkew();
	$init($Krb5);
	MemoryCache::DEBUG = $Krb5::DEBUG;
}

MemoryCache::MemoryCache() {
}

$Class* MemoryCache::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MemoryCache$$Lambda$lambda$checkAndStore$0::classInfo$.name)) {
			return MemoryCache$$Lambda$lambda$checkAndStore$0::load$(name, initialize);
		}
	}
	$loadClass(MemoryCache, name, initialize, &_MemoryCache_ClassInfo_, clinit$MemoryCache, allocate$MemoryCache);
	return class$;
}

$Class* MemoryCache::class$ = nullptr;

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun