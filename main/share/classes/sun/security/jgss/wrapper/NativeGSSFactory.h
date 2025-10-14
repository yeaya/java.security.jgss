#ifndef _sun_security_jgss_wrapper_NativeGSSFactory_h_
#define _sun_security_jgss_wrapper_NativeGSSFactory_h_
//$ class sun.security.jgss.wrapper.NativeGSSFactory
//$ extends sun.security.jgss.spi.MechanismFactory

#include <java/lang/Array.h>
#include <sun/security/jgss/spi/MechanismFactory.h>

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
			namespace wrapper {
				class GSSCredElement;
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

class NativeGSSFactory : public ::sun::security::jgss::spi::MechanismFactory {
	$class(NativeGSSFactory, $NO_CLASS_INIT, ::sun::security::jgss::spi::MechanismFactory)
public:
	NativeGSSFactory();
	void init$(::sun::security::jgss::GSSCaller* caller);
	::sun::security::jgss::wrapper::GSSCredElement* getCredFromSubject(::sun::security::jgss::wrapper::GSSNameElement* name, bool initiate);
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getCredentialElement(::sun::security::jgss::spi::GSSNameSpi* name, int32_t initLifetime, int32_t acceptLifetime, int32_t usage) override;
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSNameSpi* peer, ::sun::security::jgss::spi::GSSCredentialSpi* myCred, int32_t lifetime) override;
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSCredentialSpi* myCred) override;
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext($bytes* exportedContext) override;
	virtual ::org::ietf::jgss::Oid* getMechanismOid() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($String* nameStr, ::org::ietf::jgss::Oid* nameType) override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($bytes* name, ::org::ietf::jgss::Oid* nameType) override;
	virtual $Array<::org::ietf::jgss::Oid>* getNameTypes() override;
	virtual ::java::security::Provider* getProvider() override;
	void setMech(::org::ietf::jgss::Oid* mech);
	::sun::security::jgss::wrapper::GSSLibStub* cStub = nullptr;
	::sun::security::jgss::GSSCaller* caller = nullptr;
};

			} // wrapper
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_wrapper_NativeGSSFactory_h_