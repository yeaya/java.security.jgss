#ifndef _sun_security_jgss_krb5_Krb5InitCredential_h_
#define _sun_security_jgss_krb5_Krb5InitCredential_h_
//$ class sun.security.jgss.krb5.Krb5InitCredential
//$ extends javax.security.auth.kerberos.KerberosTicket
//$ implements sun.security.jgss.krb5.Krb5CredElement

#include <java/lang/Array.h>
#include <javax/security/auth/kerberos/KerberosTicket.h>
#include <sun/security/jgss/krb5/Krb5CredElement.h>

namespace java {
	namespace net {
		class InetAddress;
	}
}
namespace java {
	namespace security {
		class Provider;
	}
}
namespace java {
	namespace util {
		class Date;
	}
}
namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KerberosPrincipal;
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
		namespace jgss {
			namespace krb5 {
				class Krb5NameElement;
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
			class Credentials;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class $import Krb5InitCredential : public ::javax::security::auth::kerberos::KerberosTicket, public ::sun::security::jgss::krb5::Krb5CredElement {
	$class(Krb5InitCredential, $NO_CLASS_INIT, ::javax::security::auth::kerberos::KerberosTicket, ::sun::security::jgss::krb5::Krb5CredElement)
public:
	Krb5InitCredential();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	virtual $Object* clone() override;
	virtual bool equals(Object$* other) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::sun::security::jgss::krb5::Krb5NameElement* name, $bytes* asn1Encoding, ::javax::security::auth::kerberos::KerberosPrincipal* client, ::javax::security::auth::kerberos::KerberosPrincipal* clientAlias, ::javax::security::auth::kerberos::KerberosPrincipal* server, ::javax::security::auth::kerberos::KerberosPrincipal* serverAlias, $bytes* sessionKey, int32_t keyType, $booleans* flags, ::java::util::Date* authTime, ::java::util::Date* startTime, ::java::util::Date* endTime, ::java::util::Date* renewTill, $Array<::java::net::InetAddress>* clientAddresses);
	void init$(::sun::security::jgss::krb5::Krb5NameElement* name, ::sun::security::krb5::Credentials* delegatedCred, $bytes* asn1Encoding, ::javax::security::auth::kerberos::KerberosPrincipal* client, ::javax::security::auth::kerberos::KerberosPrincipal* clientAlias, ::javax::security::auth::kerberos::KerberosPrincipal* server, ::javax::security::auth::kerberos::KerberosPrincipal* serverAlias, $bytes* sessionKey, int32_t keyType, $booleans* flags, ::java::util::Date* authTime, ::java::util::Date* startTime, ::java::util::Date* endTime, ::java::util::Date* renewTill, $Array<::java::net::InetAddress>* clientAddresses);
	virtual void dispose() override;
	virtual int32_t getAcceptLifetime() override;
	virtual int32_t getInitLifetime() override;
	static ::sun::security::jgss::krb5::Krb5InitCredential* getInstance(::sun::security::jgss::GSSCaller* caller, ::sun::security::jgss::krb5::Krb5NameElement* name, int32_t initLifetime);
	static ::sun::security::jgss::krb5::Krb5InitCredential* getInstance(::sun::security::jgss::krb5::Krb5NameElement* name, ::sun::security::krb5::Credentials* delegatedCred);
	virtual ::sun::security::krb5::Credentials* getKrb5Credentials();
	virtual ::org::ietf::jgss::Oid* getMechanism() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getName() override;
	virtual ::java::security::Provider* getProvider() override;
	static ::javax::security::auth::kerberos::KerberosTicket* getTgt(::sun::security::jgss::GSSCaller* caller, ::sun::security::jgss::krb5::Krb5NameElement* name, int32_t initLifetime);
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* impersonate(::sun::security::jgss::spi::GSSNameSpi* name) override;
	virtual bool isAcceptorCredential() override;
	virtual bool isInitiatorCredential() override;
	virtual $String* toString() override;
	static const int64_t serialVersionUID = (int64_t)0x6B2F15A8D51E17F8;
	::sun::security::jgss::krb5::Krb5NameElement* name = nullptr;
	::sun::security::krb5::Credentials* krb5Credentials = nullptr;
	::javax::security::auth::kerberos::KerberosTicket* proxyTicket = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5InitCredential_h_