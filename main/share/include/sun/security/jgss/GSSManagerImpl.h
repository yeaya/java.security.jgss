#ifndef _sun_security_jgss_GSSManagerImpl_h_
#define _sun_security_jgss_GSSManagerImpl_h_
//$ class sun.security.jgss.GSSManagerImpl
//$ extends org.ietf.jgss.GSSManager

#include <java/lang/Array.h>
#include <org/ietf/jgss/GSSManager.h>

#pragma push_macro("USE_NATIVE")
#undef USE_NATIVE

namespace java {
	namespace lang {
		class Boolean;
	}
}
namespace java {
	namespace security {
		class Provider;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class GSSContext;
			class GSSCredential;
			class GSSName;
			class Oid;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			class GSSCaller;
			class GSSContextImpl;
			class GSSCredentialImpl;
			class ProviderList;
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

class $import GSSManagerImpl : public ::org::ietf::jgss::GSSManager {
	$class(GSSManagerImpl, 0, ::org::ietf::jgss::GSSManager)
public:
	GSSManagerImpl();
	void init$(::sun::security::jgss::GSSCaller* caller, bool useNative);
	void init$(::sun::security::jgss::GSSCaller* caller);
	void init$();
	virtual void addProviderAtEnd(::java::security::Provider* p, ::org::ietf::jgss::Oid* mech) override;
	virtual void addProviderAtFront(::java::security::Provider* p, ::org::ietf::jgss::Oid* mech) override;
	virtual ::org::ietf::jgss::GSSContext* createContext(::org::ietf::jgss::GSSName* peer, ::org::ietf::jgss::Oid* mech, ::org::ietf::jgss::GSSCredential* myCred, int32_t lifetime) override;
	virtual ::org::ietf::jgss::GSSContext* createContext(::org::ietf::jgss::GSSCredential* myCred) override;
	virtual ::org::ietf::jgss::GSSContext* createContext($bytes* interProcessToken) override;
	virtual ::org::ietf::jgss::GSSCredential* createCredential(int32_t usage) override;
	virtual ::org::ietf::jgss::GSSCredential* createCredential(::org::ietf::jgss::GSSName* aName, int32_t lifetime, ::org::ietf::jgss::Oid* mech, int32_t usage) override;
	virtual ::org::ietf::jgss::GSSCredential* createCredential(::org::ietf::jgss::GSSName* aName, int32_t lifetime, $Array<::org::ietf::jgss::Oid>* mechs, int32_t usage) override;
	virtual ::org::ietf::jgss::GSSName* createName($String* nameStr, ::org::ietf::jgss::Oid* nameType) override;
	virtual ::org::ietf::jgss::GSSName* createName($bytes* name, ::org::ietf::jgss::Oid* nameType) override;
	virtual ::org::ietf::jgss::GSSName* createName($String* nameStr, ::org::ietf::jgss::Oid* nameType, ::org::ietf::jgss::Oid* mech) override;
	virtual ::org::ietf::jgss::GSSName* createName($bytes* name, ::org::ietf::jgss::Oid* nameType, ::org::ietf::jgss::Oid* mech) override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getCredentialElement(::sun::security::jgss::spi::GSSNameSpi* name, int32_t initLifetime, int32_t acceptLifetime, ::org::ietf::jgss::Oid* mech, int32_t usage);
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSNameSpi* peer, ::sun::security::jgss::spi::GSSCredentialSpi* myInitiatorCred, int32_t lifetime, ::org::ietf::jgss::Oid* mech);
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSCredentialSpi* myAcceptorCred, ::org::ietf::jgss::Oid* mech);
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext($bytes* exportedContext);
	virtual $Array<::org::ietf::jgss::Oid>* getMechs() override;
	virtual $Array<::org::ietf::jgss::Oid>* getMechsForName(::org::ietf::jgss::Oid* nameType) override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($String* name, ::org::ietf::jgss::Oid* nameType, ::org::ietf::jgss::Oid* mech);
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($bytes* name, ::org::ietf::jgss::Oid* nameType, ::org::ietf::jgss::Oid* mech);
	virtual $Array<::org::ietf::jgss::Oid>* getNamesForMech(::org::ietf::jgss::Oid* mech) override;
	static ::org::ietf::jgss::GSSCredential* wrap(::sun::security::jgss::GSSCredentialImpl* cred);
	static ::org::ietf::jgss::GSSContext* wrap(::sun::security::jgss::GSSContextImpl* ctxt);
	static ::java::lang::Boolean* USE_NATIVE;
	::sun::security::jgss::ProviderList* list = nullptr;
};

		} // jgss
	} // security
} // sun

#pragma pop_macro("USE_NATIVE")

#endif // _sun_security_jgss_GSSManagerImpl_h_