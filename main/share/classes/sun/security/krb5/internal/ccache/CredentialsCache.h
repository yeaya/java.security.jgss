#ifndef _sun_security_krb5_internal_ccache_CredentialsCache_h_
#define _sun_security_krb5_internal_ccache_CredentialsCache_h_
//$ class sun.security.krb5.internal.ccache.CredentialsCache
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace util {
		class List;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class LoginOptions;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {
					class Credentials;
					class CredentialsCache$ConfigEntry;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

class CredentialsCache : public ::java::lang::Object {
	$class(CredentialsCache, 0, ::java::lang::Object)
public:
	CredentialsCache();
	void init$();
	virtual void addConfigEntry(::sun::security::krb5::internal::ccache::CredentialsCache$ConfigEntry* e) {}
	static $String* cacheName();
	static ::sun::security::krb5::internal::ccache::CredentialsCache* create(::sun::security::krb5::PrincipalName* principal, $String* name);
	static ::sun::security::krb5::internal::ccache::CredentialsCache* create(::sun::security::krb5::PrincipalName* principal);
	virtual ::java::util::List* getConfigEntries() {return nullptr;}
	virtual ::sun::security::krb5::internal::ccache::CredentialsCache$ConfigEntry* getConfigEntry($String* name);
	virtual ::sun::security::krb5::internal::ccache::Credentials* getCreds(::sun::security::krb5::PrincipalName* sname) {return nullptr;}
	virtual ::sun::security::krb5::internal::ccache::Credentials* getCreds(::sun::security::krb5::internal::LoginOptions* options, ::sun::security::krb5::PrincipalName* sname) {return nullptr;}
	virtual $Array<::sun::security::krb5::internal::ccache::Credentials>* getCredsList() {return nullptr;}
	virtual ::sun::security::krb5::internal::ccache::Credentials* getDefaultCreds() {return nullptr;}
	virtual ::sun::security::krb5::Credentials* getInitialCreds() {return nullptr;}
	static ::sun::security::krb5::internal::ccache::CredentialsCache* getInstance(::sun::security::krb5::PrincipalName* principal);
	static ::sun::security::krb5::internal::ccache::CredentialsCache* getInstance($String* cache);
	static ::sun::security::krb5::internal::ccache::CredentialsCache* getInstance(::sun::security::krb5::PrincipalName* principal, $String* cache);
	static ::sun::security::krb5::internal::ccache::CredentialsCache* getInstance();
	virtual ::sun::security::krb5::PrincipalName* getPrimaryPrincipal() {return nullptr;}
	virtual void save() {}
	virtual void update(::sun::security::krb5::internal::ccache::Credentials* c) {}
	static ::sun::security::krb5::internal::ccache::CredentialsCache* singleton;
	static $String* cacheName$;
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ccache_CredentialsCache_h_