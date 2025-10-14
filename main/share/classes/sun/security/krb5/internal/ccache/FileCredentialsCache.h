#ifndef _sun_security_krb5_internal_ccache_FileCredentialsCache_h_
#define _sun_security_krb5_internal_ccache_FileCredentialsCache_h_
//$ class sun.security.krb5.internal.ccache.FileCredentialsCache
//$ extends sun.security.krb5.internal.ccache.CredentialsCache
//$ implements sun.security.krb5.internal.ccache.FileCCacheConstants

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache.h>
#include <sun/security/krb5/internal/ccache/FileCCacheConstants.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace util {
		class List;
		class Vector;
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
					class Tag;
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

class FileCredentialsCache : public ::sun::security::krb5::internal::ccache::CredentialsCache, public ::sun::security::krb5::internal::ccache::FileCCacheConstants {
	$class(FileCredentialsCache, 0, ::sun::security::krb5::internal::ccache::CredentialsCache, ::sun::security::krb5::internal::ccache::FileCCacheConstants)
public:
	FileCredentialsCache();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	static ::sun::security::krb5::internal::ccache::FileCredentialsCache* New(::sun::security::krb5::PrincipalName* principal, $String* name);
	static ::sun::security::krb5::internal::ccache::FileCredentialsCache* New(::sun::security::krb5::PrincipalName* principal);
	static ::sun::security::krb5::internal::ccache::FileCredentialsCache* acquireInstance(::sun::security::krb5::PrincipalName* principal, $String* cache);
	static ::sun::security::krb5::internal::ccache::FileCredentialsCache* acquireInstance();
	virtual void addConfigEntry(::sun::security::krb5::internal::ccache::CredentialsCache$ConfigEntry* e) override;
	static $String* checkValidation($String* name);
	static $String* exec($String* c);
	virtual bool exists($String* cache);
	virtual ::java::util::List* getConfigEntries() override;
	virtual ::sun::security::krb5::internal::ccache::Credentials* getCreds(::sun::security::krb5::internal::LoginOptions* options, ::sun::security::krb5::PrincipalName* sname) override;
	virtual ::sun::security::krb5::internal::ccache::Credentials* getCreds(::sun::security::krb5::PrincipalName* sname) override;
	virtual $Array<::sun::security::krb5::internal::ccache::Credentials>* getCredsList() override;
	static $String* getDefaultCacheName();
	virtual ::sun::security::krb5::internal::ccache::Credentials* getDefaultCreds() override;
	virtual ::sun::security::krb5::Credentials* getInitialCreds() override;
	virtual ::sun::security::krb5::PrincipalName* getPrimaryPrincipal() override;
	virtual void init(::sun::security::krb5::PrincipalName* principal, $String* name);
	virtual void load($String* name);
	virtual bool match($StringArray* s1, $StringArray* s2);
	virtual void save() override;
	virtual $String* toString() override;
	virtual void update(::sun::security::krb5::internal::ccache::Credentials* c) override;
	int32_t version = 0;
	::sun::security::krb5::internal::ccache::Tag* tag = nullptr;
	::sun::security::krb5::PrincipalName* primaryPrincipal = nullptr;
	::java::util::Vector* credentialsList = nullptr;
	static $String* dir;
	static bool DEBUG;
	::java::util::List* configEntries = nullptr;
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_ccache_FileCredentialsCache_h_