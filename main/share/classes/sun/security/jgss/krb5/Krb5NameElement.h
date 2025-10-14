#ifndef _sun_security_jgss_krb5_Krb5NameElement_h_
#define _sun_security_jgss_krb5_Krb5NameElement_h_
//$ class sun.security.jgss.krb5.Krb5NameElement
//$ extends sun.security.jgss.spi.GSSNameSpi

#include <java/lang/Array.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>

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
		namespace krb5 {
			class PrincipalName;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class $export Krb5NameElement : public ::sun::security::jgss::spi::GSSNameSpi {
	$class(Krb5NameElement, $NO_CLASS_INIT, ::sun::security::jgss::spi::GSSNameSpi)
public:
	Krb5NameElement();
	void init$(::sun::security::krb5::PrincipalName* principalName, $String* gssNameStr, ::org::ietf::jgss::Oid* gssNameType);
	virtual bool equals(::sun::security::jgss::spi::GSSNameSpi* other) override;
	virtual bool equals(Object$* another) override;
	virtual $bytes* export$() override;
	static $StringArray* getComponents($String* gssNameStr);
	virtual ::org::ietf::jgss::Oid* getGSSNameType();
	static $String* getHostBasedInstance($String* serviceName, $String* hostName);
	static ::sun::security::jgss::krb5::Krb5NameElement* getInstance($String* gssNameStr, ::org::ietf::jgss::Oid* gssNameType);
	static ::sun::security::jgss::krb5::Krb5NameElement* getInstance(::sun::security::krb5::PrincipalName* principalName);
	::sun::security::krb5::PrincipalName* getKrb5PrincipalName();
	virtual ::org::ietf::jgss::Oid* getMechanism() override;
	virtual ::java::security::Provider* getProvider() override;
	virtual ::org::ietf::jgss::Oid* getStringNameType() override;
	virtual int32_t hashCode() override;
	virtual bool isAnonymousName() override;
	virtual $String* toString() override;
	::sun::security::krb5::PrincipalName* krb5PrincipalName = nullptr;
	$String* gssNameStr = nullptr;
	::org::ietf::jgss::Oid* gssNameType = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5NameElement_h_