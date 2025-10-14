#ifndef _sun_security_jgss_wrapper_GSSCredElement_h_
#define _sun_security_jgss_wrapper_GSSCredElement_h_
//$ class sun.security.jgss.wrapper.GSSCredElement
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
			namespace wrapper {
				class GSSLibStub;
				class GSSNameElement;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

class GSSCredElement : public ::sun::security::jgss::spi::GSSCredentialSpi {
	$class(GSSCredElement, $HAS_FINALIZE | $NO_CLASS_INIT, ::sun::security::jgss::spi::GSSCredentialSpi)
public:
	GSSCredElement();
	void init$(int64_t pCredentials, ::sun::security::jgss::wrapper::GSSNameElement* srcName, ::org::ietf::jgss::Oid* mech);
	void init$(::sun::security::jgss::wrapper::GSSNameElement* name, int32_t lifetime, int32_t usage, ::sun::security::jgss::wrapper::GSSLibStub* stub);
	virtual void dispose() override;
	virtual void doServicePermCheck();
	virtual void finalize() override;
	virtual int32_t getAcceptLifetime() override;
	virtual int32_t getInitLifetime() override;
	virtual ::org::ietf::jgss::Oid* getMechanism() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getName() override;
	virtual ::java::security::Provider* getProvider() override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* impersonate(::sun::security::jgss::spi::GSSNameSpi* name) override;
	virtual bool isAcceptorCredential() override;
	virtual bool isInitiatorCredential() override;
	virtual $String* toString() override;
	int32_t usage = 0;
	int64_t pCred = 0;
	::sun::security::jgss::wrapper::GSSNameElement* name = nullptr;
	::sun::security::jgss::wrapper::GSSLibStub* cStub = nullptr;
};

			} // wrapper
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_wrapper_GSSCredElement_h_