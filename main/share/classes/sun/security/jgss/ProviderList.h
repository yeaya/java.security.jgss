#ifndef _sun_security_jgss_ProviderList_h_
#define _sun_security_jgss_ProviderList_h_
//$ class sun.security.jgss.ProviderList
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEFAULT_MECH_OID")
#undef DEFAULT_MECH_OID
#pragma push_macro("PROV_PROP_PREFIX")
#undef PROV_PROP_PREFIX
#pragma push_macro("PROV_PROP_PREFIX_LEN")
#undef PROV_PROP_PREFIX_LEN
#pragma push_macro("SPI_MECH_FACTORY_TYPE")
#undef SPI_MECH_FACTORY_TYPE

namespace java {
	namespace lang {
		class Exception;
	}
}
namespace java {
	namespace security {
		class Provider;
	}
}
namespace java {
	namespace util {
		class ArrayList;
		class HashMap;
		class HashSet;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class GSSException;
			class Oid;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			class GSSCaller;
			class ProviderList$PreferencesEntry;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {
				class MechanismFactory;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $export ProviderList : public ::java::lang::Object {
	$class(ProviderList, 0, ::java::lang::Object)
public:
	ProviderList();
	void init$(::sun::security::jgss::GSSCaller* caller, bool useNative);
	bool addAllMechsFromProvider(::java::security::Provider* p);
	void addProviderAtEnd(::java::security::Provider* p, ::org::ietf::jgss::Oid* mechOid);
	void addProviderAtFront(::java::security::Provider* p, ::org::ietf::jgss::Oid* mechOid);
	static ::org::ietf::jgss::GSSException* createGSSException(::java::security::Provider* p, $String* className, $String* trailingMsg, ::java::lang::Exception* cause);
	::sun::security::jgss::spi::MechanismFactory* getMechFactory(::org::ietf::jgss::Oid* mechOid);
	::sun::security::jgss::spi::MechanismFactory* getMechFactory(::org::ietf::jgss::Oid* mechOid, ::java::security::Provider* p);
	::sun::security::jgss::spi::MechanismFactory* getMechFactory(::sun::security::jgss::ProviderList$PreferencesEntry* e, ::org::ietf::jgss::Oid* mechOid);
	static ::sun::security::jgss::spi::MechanismFactory* getMechFactoryImpl(::java::security::Provider* p, $String* className, ::org::ietf::jgss::Oid* mechOid, ::sun::security::jgss::GSSCaller* caller);
	$Array<::org::ietf::jgss::Oid>* getMechs();
	::org::ietf::jgss::Oid* getOidFromMechFactoryProperty($String* prop);
	bool isMechFactoryProperty($String* prop);
	static $String* PROV_PROP_PREFIX;
	static int32_t PROV_PROP_PREFIX_LEN;
	static $String* SPI_MECH_FACTORY_TYPE;
	static ::org::ietf::jgss::Oid* DEFAULT_MECH_OID;
	::java::util::ArrayList* preferences = nullptr;
	::java::util::HashMap* factories = nullptr;
	::java::util::HashSet* mechs = nullptr;
	::sun::security::jgss::GSSCaller* caller = nullptr;
};

		} // jgss
	} // security
} // sun

#pragma pop_macro("DEFAULT_MECH_OID")
#pragma pop_macro("PROV_PROP_PREFIX")
#pragma pop_macro("PROV_PROP_PREFIX_LEN")
#pragma pop_macro("SPI_MECH_FACTORY_TYPE")

#endif // _sun_security_jgss_ProviderList_h_