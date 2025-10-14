#ifndef _sun_security_jgss_krb5_Krb5ProxyCredential_h_
#define _sun_security_jgss_krb5_Krb5ProxyCredential_h_
//$ class sun.security.jgss.krb5.Krb5ProxyCredential
//$ extends sun.security.jgss.krb5.Krb5CredElement

#include <sun/security/jgss/krb5/Krb5CredElement.h>

namespace java {
	namespace security {
		class Provider;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class Oid;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			class GSSCaller;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class Krb5InitCredential;
				class Krb5NameElement;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {
				class GSSCredentialSpi;
				class GSSNameSpi;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class Ticket;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class $export Krb5ProxyCredential : public ::sun::security::jgss::krb5::Krb5CredElement {
	$class(Krb5ProxyCredential, $NO_CLASS_INIT, ::sun::security::jgss::krb5::Krb5CredElement)
public:
	Krb5ProxyCredential();
	void init$(::sun::security::jgss::krb5::Krb5InitCredential* self, ::sun::security::jgss::krb5::Krb5NameElement* client, ::sun::security::krb5::internal::Ticket* tkt);
	virtual void dispose() override;
	virtual int32_t getAcceptLifetime() override;
	virtual int32_t getInitLifetime() override;
	virtual ::org::ietf::jgss::Oid* getMechanism() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getName() override;
	virtual ::java::security::Provider* getProvider() override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* impersonate(::sun::security::jgss::spi::GSSNameSpi* name) override;
	virtual bool isAcceptorCredential() override;
	virtual bool isInitiatorCredential() override;
	static ::sun::security::jgss::krb5::Krb5CredElement* tryImpersonation(::sun::security::jgss::GSSCaller* caller, ::sun::security::jgss::krb5::Krb5InitCredential* initiator);
	::sun::security::jgss::krb5::Krb5InitCredential* self = nullptr;
	::sun::security::jgss::krb5::Krb5NameElement* client = nullptr;
	::sun::security::krb5::internal::Ticket* tkt = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5ProxyCredential_h_