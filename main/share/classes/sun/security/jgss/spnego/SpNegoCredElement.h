#ifndef _sun_security_jgss_spnego_SpNegoCredElement_h_
#define _sun_security_jgss_spnego_SpNegoCredElement_h_
//$ class sun.security.jgss.spnego.SpNegoCredElement
//$ extends sun.security.jgss.spi.GSSCredentialSpi

#include <sun/security/jgss/spi/GSSCredentialSpi.h>

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
			namespace spi {
				class GSSNameSpi;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

class SpNegoCredElement : public ::sun::security::jgss::spi::GSSCredentialSpi {
	$class(SpNegoCredElement, $NO_CLASS_INIT, ::sun::security::jgss::spi::GSSCredentialSpi)
public:
	SpNegoCredElement();
	void init$(::sun::security::jgss::spi::GSSCredentialSpi* cred);
	virtual void dispose() override;
	virtual int32_t getAcceptLifetime() override;
	virtual int32_t getInitLifetime() override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getInternalCred();
	virtual ::org::ietf::jgss::Oid* getInternalMech();
	virtual ::org::ietf::jgss::Oid* getMechanism() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getName() override;
	virtual ::java::security::Provider* getProvider() override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* impersonate(::sun::security::jgss::spi::GSSNameSpi* name) override;
	virtual bool isAcceptorCredential() override;
	virtual bool isInitiatorCredential() override;
	::sun::security::jgss::spi::GSSCredentialSpi* cred = nullptr;
};

			} // spnego
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_spnego_SpNegoCredElement_h_