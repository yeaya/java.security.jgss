#include <sun/security/krb5/internal/ccache/CredentialsCache.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/LoginOptions.h>
#include <sun/security/krb5/internal/ccache/Credentials.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry.h>
#include <sun/security/krb5/internal/ccache/FileCredentialsCache.h>
#include <jcpp.h>

using $CredentialsArray = $Array<::sun::security::krb5::internal::ccache::Credentials>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $1Credentials = ::sun::security::krb5::Credentials;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $LoginOptions = ::sun::security::krb5::internal::LoginOptions;
using $Credentials = ::sun::security::krb5::internal::ccache::Credentials;
using $CredentialsCache$ConfigEntry = ::sun::security::krb5::internal::ccache::CredentialsCache$ConfigEntry;
using $FileCredentialsCache = ::sun::security::krb5::internal::ccache::FileCredentialsCache;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$FieldInfo _CredentialsCache_FieldInfo_[] = {
	{"singleton", "Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $STATIC, $staticField(CredentialsCache, singleton)},
	{"cacheName", "Ljava/lang/String;", nullptr, $STATIC, $staticField(CredentialsCache, cacheName$)},
	{}
};

$MethodInfo _CredentialsCache_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(CredentialsCache::*)()>(&CredentialsCache::init$))},
	{"addConfigEntry", "(Lsun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"cacheName", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)()>(&CredentialsCache::cacheName))},
	{"create", "(Lsun/security/krb5/PrincipalName;Ljava/lang/String;)Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PUBLIC | $STATIC, $method(static_cast<CredentialsCache*(*)($PrincipalName*,$String*)>(&CredentialsCache::create))},
	{"create", "(Lsun/security/krb5/PrincipalName;)Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PUBLIC | $STATIC, $method(static_cast<CredentialsCache*(*)($PrincipalName*)>(&CredentialsCache::create))},
	{"getConfigEntries", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry;>;", $PUBLIC | $ABSTRACT},
	{"getConfigEntry", "(Ljava/lang/String;)Lsun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry;", nullptr, $PUBLIC},
	{"getCreds", "(Lsun/security/krb5/PrincipalName;)Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC | $ABSTRACT},
	{"getCreds", "(Lsun/security/krb5/internal/LoginOptions;Lsun/security/krb5/PrincipalName;)Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC | $ABSTRACT},
	{"getCredsList", "()[Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC | $ABSTRACT},
	{"getDefaultCreds", "()Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC | $ABSTRACT},
	{"getInitialCreds", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $ABSTRACT},
	{"getInstance", "(Lsun/security/krb5/PrincipalName;)Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PUBLIC | $STATIC, $method(static_cast<CredentialsCache*(*)($PrincipalName*)>(&CredentialsCache::getInstance))},
	{"getInstance", "(Ljava/lang/String;)Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PUBLIC | $STATIC, $method(static_cast<CredentialsCache*(*)($String*)>(&CredentialsCache::getInstance))},
	{"getInstance", "(Lsun/security/krb5/PrincipalName;Ljava/lang/String;)Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PUBLIC | $STATIC, $method(static_cast<CredentialsCache*(*)($PrincipalName*,$String*)>(&CredentialsCache::getInstance))},
	{"getInstance", "()Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PUBLIC | $STATIC, $method(static_cast<CredentialsCache*(*)()>(&CredentialsCache::getInstance))},
	{"getPrimaryPrincipal", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $ABSTRACT},
	{"save", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException,sun.security.krb5.KrbException"},
	{"update", "(Lsun/security/krb5/internal/ccache/Credentials;)V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _CredentialsCache_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ccache.CredentialsCache$ConfigEntry", "sun.security.krb5.internal.ccache.CredentialsCache", "ConfigEntry", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _CredentialsCache_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.internal.ccache.CredentialsCache",
	"java.lang.Object",
	nullptr,
	_CredentialsCache_FieldInfo_,
	_CredentialsCache_MethodInfo_,
	nullptr,
	nullptr,
	_CredentialsCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ccache.CredentialsCache$ConfigEntry"
};

$Object* allocate$CredentialsCache($Class* clazz) {
	return $of($alloc(CredentialsCache));
}

CredentialsCache* CredentialsCache::singleton = nullptr;
$String* CredentialsCache::cacheName$ = nullptr;

void CredentialsCache::init$() {
}

CredentialsCache* CredentialsCache::getInstance($PrincipalName* principal) {
	$init(CredentialsCache);
	return $FileCredentialsCache::acquireInstance(principal, nullptr);
}

CredentialsCache* CredentialsCache::getInstance($String* cache) {
	$init(CredentialsCache);
	bool var$0 = ($nc(cache)->length() >= 5);
	if (var$0 && $(cache->substring(0, 5))->equalsIgnoreCase("FILE:"_s)) {
		return $FileCredentialsCache::acquireInstance(nullptr, $(cache->substring(5)));
	}
	return $FileCredentialsCache::acquireInstance(nullptr, cache);
}

CredentialsCache* CredentialsCache::getInstance($PrincipalName* principal, $String* cache) {
	$init(CredentialsCache);
	bool var$0 = cache != nullptr && (cache->length() >= 5);
	if (var$0 && cache->regionMatches(true, 0, "FILE:"_s, 0, 5)) {
		return $FileCredentialsCache::acquireInstance(principal, $(cache->substring(5)));
	}
	return $FileCredentialsCache::acquireInstance(principal, cache);
}

CredentialsCache* CredentialsCache::getInstance() {
	$init(CredentialsCache);
	return $FileCredentialsCache::acquireInstance();
}

CredentialsCache* CredentialsCache::create($PrincipalName* principal, $String* name$renamed) {
	$init(CredentialsCache);
	$var($String, name, name$renamed);
	if (name == nullptr) {
		$throwNew($RuntimeException, "cache name error"_s);
	}
	bool var$0 = ($nc(name)->length() >= 5);
	if (var$0 && name->regionMatches(true, 0, "FILE:"_s, 0, 5)) {
		$assign(name, name->substring(5));
		return ($FileCredentialsCache::New(principal, name));
	}
	return ($FileCredentialsCache::New(principal, name));
}

CredentialsCache* CredentialsCache::create($PrincipalName* principal) {
	$init(CredentialsCache);
	return ($FileCredentialsCache::New(principal));
}

$String* CredentialsCache::cacheName() {
	$init(CredentialsCache);
	return CredentialsCache::cacheName$;
}

$CredentialsCache$ConfigEntry* CredentialsCache::getConfigEntry($String* name) {
	$var($List, entries, getConfigEntries());
	if (entries != nullptr) {
		{
			$var($Iterator, i$, entries->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($CredentialsCache$ConfigEntry, e, $cast($CredentialsCache$ConfigEntry, i$->next()));
				{
					if ($nc($($nc(e)->getName()))->equals(name)) {
						return e;
					}
				}
			}
		}
	}
	return nullptr;
}

void clinit$CredentialsCache($Class* class$) {
	$assignStatic(CredentialsCache::singleton, nullptr);
}

CredentialsCache::CredentialsCache() {
}

$Class* CredentialsCache::load$($String* name, bool initialize) {
	$loadClass(CredentialsCache, name, initialize, &_CredentialsCache_ClassInfo_, clinit$CredentialsCache, allocate$CredentialsCache);
	return class$;
}

$Class* CredentialsCache::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun