#ifndef _sun_security_jgss_spi_MechanismFactory_h_
#define _sun_security_jgss_spi_MechanismFactory_h_
//$ interface sun.security.jgss.spi.MechanismFactory
//$ extends java.lang.Object

#include <java/lang/Array.h>

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
				class GSSContextSpi;
				class GSSCredentialSpi;
				class GSSNameSpi;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {

class $export MechanismFactory : public ::java::lang::Object {
	$interface(MechanismFactory, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getCredentialElement(::sun::security::jgss::spi::GSSNameSpi* name, int32_t initLifetime, int32_t acceptLifetime, int32_t usage) {return nullptr;}
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSNameSpi* peer, ::sun::security::jgss::spi::GSSCredentialSpi* myInitiatorCred, int32_t lifetime) {return nullptr;}
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSCredentialSpi* myAcceptorCred) {return nullptr;}
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext($bytes* exportedContext) {return nullptr;}
	virtual ::org::ietf::jgss::Oid* getMechanismOid() {return nullptr;}
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($String* nameStr, ::org::ietf::jgss::Oid* nameType) {return nullptr;}
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($bytes* name, ::org::ietf::jgss::Oid* nameType) {return nullptr;}
	virtual $Array<::org::ietf::jgss::Oid>* getNameTypes() {return nullptr;}
	virtual ::java::security::Provider* getProvider() {return nullptr;}
};

			} // spi
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_spi_MechanismFactory_h_