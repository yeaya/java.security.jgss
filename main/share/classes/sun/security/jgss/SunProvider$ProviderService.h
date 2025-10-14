#ifndef _sun_security_jgss_SunProvider$ProviderService_h_
#define _sun_security_jgss_SunProvider$ProviderService_h_
//$ class sun.security.jgss.SunProvider$ProviderService
//$ extends java.security.Provider$Service

#include <java/security/Provider$Service.h>

namespace java {
	namespace security {
		class Provider;
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class SunProvider$ProviderService : public ::java::security::Provider$Service {
	$class(SunProvider$ProviderService, $NO_CLASS_INIT, ::java::security::Provider$Service)
public:
	SunProvider$ProviderService();
	void init$(::java::security::Provider* p, $String* type, $String* algo, $String* cn);
	virtual $Object* newInstance(Object$* ctrParamObj) override;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_SunProvider$ProviderService_h_