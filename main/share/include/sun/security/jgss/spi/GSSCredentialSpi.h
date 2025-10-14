#ifndef _sun_security_jgss_spi_GSSCredentialSpi_h_
#define _sun_security_jgss_spi_GSSCredentialSpi_h_
//$ interface sun.security.jgss.spi.GSSCredentialSpi
//$ extends java.lang.Object

#include <java/lang/Object.h>

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
			namespace spi {

class $import GSSCredentialSpi : public ::java::lang::Object {
	$interface(GSSCredentialSpi, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void dispose() {}
	virtual int32_t getAcceptLifetime() {return 0;}
	virtual int32_t getInitLifetime() {return 0;}
	virtual ::org::ietf::jgss::Oid* getMechanism() {return nullptr;}
	virtual ::sun::security::jgss::spi::GSSNameSpi* getName() {return nullptr;}
	virtual ::java::security::Provider* getProvider() {return nullptr;}
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* impersonate(::sun::security::jgss::spi::GSSNameSpi* name) {return nullptr;}
	virtual bool isAcceptorCredential() {return false;}
	virtual bool isInitiatorCredential() {return false;}
};

			} // spi
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_spi_GSSCredentialSpi_h_