#ifndef _sun_security_jgss_ProviderList$PreferencesEntry_h_
#define _sun_security_jgss_ProviderList$PreferencesEntry_h_
//$ class sun.security.jgss.ProviderList$PreferencesEntry
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

class ProviderList$PreferencesEntry : public ::java::lang::Object {
	$class(ProviderList$PreferencesEntry, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ProviderList$PreferencesEntry();
	void init$(::java::security::Provider* p, ::org::ietf::jgss::Oid* oid);
	virtual bool equals(Object$* other) override;
	::org::ietf::jgss::Oid* getOid();
	::java::security::Provider* getProvider();
	virtual int32_t hashCode() override;
	bool implies(Object$* other);
	bool impliesMechanism(::org::ietf::jgss::Oid* oid);
	virtual $String* toString() override;
	::java::security::Provider* p = nullptr;
	::org::ietf::jgss::Oid* oid = nullptr;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_ProviderList$PreferencesEntry_h_