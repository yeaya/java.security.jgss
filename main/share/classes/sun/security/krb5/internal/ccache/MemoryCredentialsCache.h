#ifndef _sun_security_krb5_internal_ccache_MemoryCredentialsCache_h_
#define _sun_security_krb5_internal_ccache_MemoryCredentialsCache_h_
//$ class sun.security.krb5.internal.ccache.MemoryCredentialsCache
//$ extends sun.security.krb5.internal.ccache.CredentialsCache

#include <sun/security/krb5/internal/ccache/CredentialsCache.h>

namespace java {
	namespace io {
		class File;
	}
}
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
				namespace ccache {

class MemoryCredentialsCache : public ::sun::security::krb5::internal::ccache::CredentialsCache {
	$class(MemoryCredentialsCache, $NO_CLASS_INIT, ::sun::security::krb5::internal::ccache::CredentialsCache)
public:
	MemoryCredentialsCache();
	using ::sun::security::krb5::internal::ccache::CredentialsCache::getCreds;
	virtual ::sun::security::krb5::internal::ccache::Credentials* getCreds(::sun::security::krb5::PrincipalName* sname) override {return nullptr;}
	virtual $Array<::sun::security::krb5::internal::ccache::Credentials>* getCredsList() override {return nullptr;}
	virtual ::sun::security::krb5::PrincipalName* getPrimaryPrincipal() override {return nullptr;}
	void init$();
	virtual bool exists($String* cache) {return false;}
	static ::sun::security::krb5::internal::ccache::CredentialsCache* getCCacheInstance(::sun::security::krb5::PrincipalName* p);
	static ::sun::security::krb5::internal::ccache::CredentialsCache* getCCacheInstance(::sun::security::krb5::PrincipalName* p, ::java::io::File* cacheFile);
	virtual void save() override {}
	virtual void update(::sun::security::krb5::internal::ccache::Credentials* c) override {}
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ccache_MemoryCredentialsCache_h_