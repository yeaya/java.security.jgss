#ifndef _sun_security_jgss_krb5_Krb5AcceptCredential_h_
#define _sun_security_jgss_krb5_Krb5AcceptCredential_h_
//$ class sun.security.jgss.krb5.Krb5AcceptCredential
//$ extends sun.security.jgss.krb5.Krb5CredElement

#include <java/lang/Array.h>
#include <sun/security/jgss/krb5/Krb5CredElement.h>

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
				class Krb5NameElement;
				class ServiceCreds;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {
				class GSSCredentialSpi;
				class GSSNameSpi;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
			class PrincipalName;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class $export Krb5AcceptCredential : public ::sun::security::jgss::krb5::Krb5CredElement {
	$class(Krb5AcceptCredential, $NO_CLASS_INIT, ::sun::security::jgss::krb5::Krb5CredElement)
public:
	Krb5AcceptCredential();
	void init$(::sun::security::jgss::krb5::Krb5NameElement* name, ::sun::security::jgss::krb5::ServiceCreds* creds);
	virtual void destroy();
	virtual void dispose() override;
	virtual int32_t getAcceptLifetime() override;
	virtual int32_t getInitLifetime() override;
	static ::sun::security::jgss::krb5::Krb5AcceptCredential* getInstance(::sun::security::jgss::GSSCaller* caller, ::sun::security::jgss::krb5::Krb5NameElement* name);
	virtual $Array<::sun::security::krb5::EncryptionKey>* getKrb5EncryptionKeys(::sun::security::krb5::PrincipalName* princ);
	virtual ::org::ietf::jgss::Oid* getMechanism() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getName() override;
	virtual ::java::security::Provider* getProvider() override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* impersonate(::sun::security::jgss::spi::GSSNameSpi* name) override;
	virtual bool isAcceptorCredential() override;
	virtual bool isInitiatorCredential() override;
	::sun::security::jgss::krb5::Krb5NameElement* name = nullptr;
	::sun::security::jgss::krb5::ServiceCreds* screds = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5AcceptCredential_h_