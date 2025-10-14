#include <sun/security/krb5/internal/ReplayCache.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/ReplayCache$1.h>
#include <sun/security/krb5/internal/rcache/AuthTimeWithHash.h>
#include <sun/security/krb5/internal/rcache/DflCache.h>
#include <sun/security/krb5/internal/rcache/MemoryCache.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $ReplayCache$1 = ::sun::security::krb5::internal::ReplayCache$1;
using $AuthTimeWithHash = ::sun::security::krb5::internal::rcache::AuthTimeWithHash;
using $DflCache = ::sun::security::krb5::internal::rcache::DflCache;
using $MemoryCache = ::sun::security::krb5::internal::rcache::MemoryCache;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$MethodInfo _ReplayCache_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ReplayCache::*)()>(&ReplayCache::init$))},
	{"checkAndStore", "(Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/rcache/AuthTimeWithHash;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "sun.security.krb5.internal.KrbApErrException"},
	{"getInstance", "(Ljava/lang/String;)Lsun/security/krb5/internal/ReplayCache;", nullptr, $PUBLIC | $STATIC, $method(static_cast<ReplayCache*(*)($String*)>(&ReplayCache::getInstance))},
	{"getInstance", "()Lsun/security/krb5/internal/ReplayCache;", nullptr, $PUBLIC | $STATIC, $method(static_cast<ReplayCache*(*)()>(&ReplayCache::getInstance))},
	{}
};

$InnerClassInfo _ReplayCache_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ReplayCache$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReplayCache_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.internal.ReplayCache",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ReplayCache_MethodInfo_,
	nullptr,
	nullptr,
	_ReplayCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ReplayCache$1"
};

$Object* allocate$ReplayCache($Class* clazz) {
	return $of($alloc(ReplayCache));
}

void ReplayCache::init$() {
}

ReplayCache* ReplayCache::getInstance($String* type) {
	if (type == nullptr) {
		return $new($MemoryCache);
	} else {
		bool var$1 = type->equals("dfl"_s);
		if (var$1 || type->startsWith("dfl:"_s)) {
			return $new($DflCache, type);
		} else if (type->equals("none"_s)) {
			return $new($ReplayCache$1);
		} else {
			$throwNew($IllegalArgumentException, $$str({"Unknown type: "_s, type}));
		}
	}
}

ReplayCache* ReplayCache::getInstance() {
	$var($String, type, $GetPropertyAction::privilegedGetProperty("sun.security.krb5.rcache"_s));
	return getInstance(type);
}

ReplayCache::ReplayCache() {
}

$Class* ReplayCache::load$($String* name, bool initialize) {
	$loadClass(ReplayCache, name, initialize, &_ReplayCache_ClassInfo_, allocate$ReplayCache);
	return class$;
}

$Class* ReplayCache::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun