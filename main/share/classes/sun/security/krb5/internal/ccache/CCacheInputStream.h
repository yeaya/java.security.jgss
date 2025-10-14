#ifndef _sun_security_krb5_internal_ccache_CCacheInputStream_h_
#define _sun_security_krb5_internal_ccache_CCacheInputStream_h_
//$ class sun.security.krb5.internal.ccache.CCacheInputStream
//$ extends sun.security.krb5.internal.util.KrbDataInputStream
//$ implements sun.security.krb5.internal.ccache.FileCCacheConstants

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/ccache/FileCCacheConstants.h>
#include <sun/security/krb5/internal/util/KrbDataInputStream.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace io {
		class InputStream;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class AuthorizationDataEntry;
				class HostAddress;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {
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

class CCacheInputStream : public ::sun::security::krb5::internal::util::KrbDataInputStream, public ::sun::security::krb5::internal::ccache::FileCCacheConstants {
	$class(CCacheInputStream, 0, ::sun::security::krb5::internal::util::KrbDataInputStream, ::sun::security::krb5::internal::ccache::FileCCacheConstants)
public:
	CCacheInputStream();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::io::InputStream* is);
	virtual bool isRealm($String* str);
	using ::sun::security::krb5::internal::util::KrbDataInputStream::read;
	virtual $Array<::sun::security::krb5::internal::HostAddress>* readAddr();
	virtual $Array<::sun::security::krb5::internal::AuthorizationDataEntry>* readAuth();
	virtual $Object* readCred(int32_t version);
	virtual $bytes* readData();
	virtual $booleans* readFlags();
	virtual ::sun::security::krb5::EncryptionKey* readKey(int32_t version);
	virtual ::sun::security::krb5::PrincipalName* readPrincipal(int32_t version);
	virtual ::sun::security::krb5::internal::ccache::Tag* readTag();
	virtual $longs* readTimes();
	virtual bool readskey();
	virtual $String* toString() override;
	static bool DEBUG;
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_ccache_CCacheInputStream_h_