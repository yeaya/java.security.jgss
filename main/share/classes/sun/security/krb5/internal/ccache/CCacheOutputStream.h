#ifndef _sun_security_krb5_internal_ccache_CCacheOutputStream_h_
#define _sun_security_krb5_internal_ccache_CCacheOutputStream_h_
//$ class sun.security.krb5.internal.ccache.CCacheOutputStream
//$ extends sun.security.krb5.internal.util.KrbDataOutputStream
//$ implements sun.security.krb5.internal.ccache.FileCCacheConstants

#include <sun/security/krb5/internal/ccache/FileCCacheConstants.h>
#include <sun/security/krb5/internal/util/KrbDataOutputStream.h>

namespace java {
	namespace io {
		class OutputStream;
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
				class Ticket;
				class TicketFlags;
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

class CCacheOutputStream : public ::sun::security::krb5::internal::util::KrbDataOutputStream, public ::sun::security::krb5::internal::ccache::FileCCacheConstants {
	$class(CCacheOutputStream, $NO_CLASS_INIT, ::sun::security::krb5::internal::util::KrbDataOutputStream, ::sun::security::krb5::internal::ccache::FileCCacheConstants)
public:
	CCacheOutputStream();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::io::OutputStream* os);
	virtual void addConfigEntry(::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::internal::ccache::CredentialsCache$ConfigEntry* e);
	virtual void addCreds(::sun::security::krb5::internal::ccache::Credentials* creds);
	using ::sun::security::krb5::internal::util::KrbDataOutputStream::write;
	virtual $String* toString() override;
	virtual void writeFlags(::sun::security::krb5::internal::TicketFlags* flags);
	virtual void writeHeader(::sun::security::krb5::PrincipalName* p, int32_t version);
	virtual void writeTicket(::sun::security::krb5::internal::Ticket* t);
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ccache_CCacheOutputStream_h_