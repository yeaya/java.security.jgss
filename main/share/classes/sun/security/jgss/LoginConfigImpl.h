#ifndef _sun_security_jgss_LoginConfigImpl_h_
#define _sun_security_jgss_LoginConfigImpl_h_
//$ class sun.security.jgss.LoginConfigImpl
//$ extends javax.security.auth.login.Configuration

#include <java/lang/Array.h>
#include <javax/security/auth/login/Configuration.h>

#pragma push_macro("HTTP_USE_GLOBAL_CREDS")
#undef HTTP_USE_GLOBAL_CREDS

namespace javax {
	namespace security {
		namespace auth {
			namespace login {
				class AppConfigurationEntry;
			}
		}
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
		namespace util {
			class Debug;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $export LoginConfigImpl : public ::javax::security::auth::login::Configuration {
	$class(LoginConfigImpl, 0, ::javax::security::auth::login::Configuration)
public:
	LoginConfigImpl();
	void init$(::sun::security::jgss::GSSCaller* caller, ::org::ietf::jgss::Oid* mech);
	virtual $Array<::javax::security::auth::login::AppConfigurationEntry>* getAppConfigurationEntry($String* name) override;
	$Array<::javax::security::auth::login::AppConfigurationEntry>* getDefaultConfigurationEntry();
	static bool isServerSide(::sun::security::jgss::GSSCaller* caller);
	::javax::security::auth::login::Configuration* config = nullptr;
	::sun::security::jgss::GSSCaller* caller = nullptr;
	$String* mechName = nullptr;
	static ::sun::security::util::Debug* debug;
	static bool HTTP_USE_GLOBAL_CREDS;
};

		} // jgss
	} // security
} // sun

#pragma pop_macro("HTTP_USE_GLOBAL_CREDS")

#endif // _sun_security_jgss_LoginConfigImpl_h_