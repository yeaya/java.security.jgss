#ifndef _sun_security_jgss_spnego_SpNegoMechFactory_h_
#define _sun_security_jgss_spnego_SpNegoMechFactory_h_
//$ class sun.security.jgss.spnego.SpNegoMechFactory
//$ extends sun.security.jgss.spi.MechanismFactory

#include <java/lang/Array.h>
#include <sun/security/jgss/spi/MechanismFactory.h>

#pragma push_macro("DEFAULT_SPNEGO_MECH_OID")
#undef DEFAULT_SPNEGO_MECH_OID
#pragma push_macro("GSS_SPNEGO_MECH_OID")
#undef GSS_SPNEGO_MECH_OID
#pragma push_macro("PROVIDER")
#undef PROVIDER

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
			class GSSManagerImpl;
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
			namespace spnego {
				class SpNegoCredElement;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

class SpNegoMechFactory : public ::sun::security::jgss::spi::MechanismFactory {
	$class(SpNegoMechFactory, 0, ::sun::security::jgss::spi::MechanismFactory)
public:
	SpNegoMechFactory();
	void init$();
	void init$(::sun::security::jgss::GSSCaller* caller);
	static ::sun::security::jgss::spnego::SpNegoCredElement* getCredFromSubject(::sun::security::jgss::spi::GSSNameSpi* name, bool initiate);
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getCredentialElement(::sun::security::jgss::spi::GSSNameSpi* name, int32_t initLifetime, int32_t acceptLifetime, int32_t usage) override;
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSNameSpi* peer, ::sun::security::jgss::spi::GSSCredentialSpi* myInitiatorCred, int32_t lifetime) override;
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSCredentialSpi* myAcceptorCred) override;
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext($bytes* exportedContext) override;
	virtual ::org::ietf::jgss::Oid* getMechanismOid() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($String* nameStr, ::org::ietf::jgss::Oid* nameType) override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($bytes* name, ::org::ietf::jgss::Oid* nameType) override;
	virtual $Array<::org::ietf::jgss::Oid>* getNameTypes() override;
	virtual ::java::security::Provider* getProvider() override;
	static ::java::security::Provider* PROVIDER;
	static ::org::ietf::jgss::Oid* GSS_SPNEGO_MECH_OID;
	static $Array<::org::ietf::jgss::Oid>* nameTypes;
	static ::org::ietf::jgss::Oid* DEFAULT_SPNEGO_MECH_OID;
	::sun::security::jgss::GSSManagerImpl* manager = nullptr;
	$Array<::org::ietf::jgss::Oid>* availableMechs = nullptr;
};

			} // spnego
		} // jgss
	} // security
} // sun

#pragma pop_macro("DEFAULT_SPNEGO_MECH_OID")
#pragma pop_macro("GSS_SPNEGO_MECH_OID")
#pragma pop_macro("PROVIDER")

#endif // _sun_security_jgss_spnego_SpNegoMechFactory_h_