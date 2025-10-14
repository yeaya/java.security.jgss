#ifndef _sun_security_jgss_krb5_Krb5MechFactory_h_
#define _sun_security_jgss_krb5_Krb5MechFactory_h_
//$ class sun.security.jgss.krb5.Krb5MechFactory
//$ extends sun.security.jgss.spi.MechanismFactory

#include <java/lang/Array.h>
#include <sun/security/jgss/spi/MechanismFactory.h>

#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("GSS_KRB5_MECH_OID")
#undef GSS_KRB5_MECH_OID
#pragma push_macro("NT_GSS_KRB5_PRINCIPAL")
#undef NT_GSS_KRB5_PRINCIPAL
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
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class Krb5CredElement;
				class Krb5NameElement;
			}
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
			namespace krb5 {

class $import Krb5MechFactory : public ::sun::security::jgss::spi::MechanismFactory {
	$class(Krb5MechFactory, 0, ::sun::security::jgss::spi::MechanismFactory)
public:
	Krb5MechFactory();
	void init$();
	void init$(::sun::security::jgss::GSSCaller* caller);
	static void checkAcceptCredPermission(::sun::security::jgss::krb5::Krb5NameElement* name, ::sun::security::jgss::spi::GSSNameSpi* originalName);
	static void checkInitCredPermission(::sun::security::jgss::krb5::Krb5NameElement* name);
	static ::org::ietf::jgss::Oid* createOid($String* oidStr);
	static ::sun::security::jgss::krb5::Krb5CredElement* getCredFromSubject(::sun::security::jgss::spi::GSSNameSpi* name, bool initiate);
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getCredentialElement(::sun::security::jgss::spi::GSSNameSpi* name, int32_t initLifetime, int32_t acceptLifetime, int32_t usage) override;
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSNameSpi* peer, ::sun::security::jgss::spi::GSSCredentialSpi* myInitiatorCred, int32_t lifetime) override;
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext(::sun::security::jgss::spi::GSSCredentialSpi* myAcceptorCred) override;
	virtual ::sun::security::jgss::spi::GSSContextSpi* getMechanismContext($bytes* exportedContext) override;
	virtual ::org::ietf::jgss::Oid* getMechanismOid() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($String* nameStr, ::org::ietf::jgss::Oid* nameType) override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getNameElement($bytes* name, ::org::ietf::jgss::Oid* nameType) override;
	virtual $Array<::org::ietf::jgss::Oid>* getNameTypes() override;
	virtual ::java::security::Provider* getProvider() override;
	static bool DEBUG;
	static ::java::security::Provider* PROVIDER;
	static ::org::ietf::jgss::Oid* GSS_KRB5_MECH_OID;
	static ::org::ietf::jgss::Oid* NT_GSS_KRB5_PRINCIPAL;
	static $Array<::org::ietf::jgss::Oid>* nameTypes;
	::sun::security::jgss::GSSCaller* caller = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("DEBUG")
#pragma pop_macro("GSS_KRB5_MECH_OID")
#pragma pop_macro("NT_GSS_KRB5_PRINCIPAL")
#pragma pop_macro("PROVIDER")

#endif // _sun_security_jgss_krb5_Krb5MechFactory_h_