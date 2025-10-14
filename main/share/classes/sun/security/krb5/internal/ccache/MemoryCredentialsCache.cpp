#include <sun/security/krb5/internal/ccache/MemoryCredentialsCache.h>

#include <java/io/File.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $CredentialsCache = ::sun::security::krb5::internal::ccache::CredentialsCache;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$MethodInfo _MemoryCredentialsCache_MethodInfo_[] = {
	{"getCreds", "(Lsun/security/krb5/PrincipalName;)Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC | $ABSTRACT},
	{"getCredsList", "()[Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC | $ABSTRACT},
	{"getPrimaryPrincipal", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MemoryCredentialsCache::*)()>(&MemoryCredentialsCache::init$))},
	{"exists", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getCCacheInstance", "(Lsun/security/krb5/PrincipalName;)Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$CredentialsCache*(*)($PrincipalName*)>(&MemoryCredentialsCache::getCCacheInstance))},
	{"getCCacheInstance", "(Lsun/security/krb5/PrincipalName;Ljava/io/File;)Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$CredentialsCache*(*)($PrincipalName*,$File*)>(&MemoryCredentialsCache::getCCacheInstance))},
	{"update", "(Lsun/security/krb5/internal/ccache/Credentials;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"save", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _MemoryCredentialsCache_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.internal.ccache.MemoryCredentialsCache",
	"sun.security.krb5.internal.ccache.CredentialsCache",
	nullptr,
	nullptr,
	_MemoryCredentialsCache_MethodInfo_
};

$Object* allocate$MemoryCredentialsCache($Class* clazz) {
	return $of($alloc(MemoryCredentialsCache));
}

void MemoryCredentialsCache::init$() {
	$CredentialsCache::init$();
}

$CredentialsCache* MemoryCredentialsCache::getCCacheInstance($PrincipalName* p) {
	$init(MemoryCredentialsCache);
	return nullptr;
}

$CredentialsCache* MemoryCredentialsCache::getCCacheInstance($PrincipalName* p, $File* cacheFile) {
	$init(MemoryCredentialsCache);
	return nullptr;
}

MemoryCredentialsCache::MemoryCredentialsCache() {
}

$Class* MemoryCredentialsCache::load$($String* name, bool initialize) {
	$loadClass(MemoryCredentialsCache, name, initialize, &_MemoryCredentialsCache_ClassInfo_, allocate$MemoryCredentialsCache);
	return class$;
}

$Class* MemoryCredentialsCache::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun