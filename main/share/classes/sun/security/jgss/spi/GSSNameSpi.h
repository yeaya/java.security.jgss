#ifndef _sun_security_jgss_spi_GSSNameSpi_h_
#define _sun_security_jgss_spi_GSSNameSpi_h_
//$ interface sun.security.jgss.spi.GSSNameSpi
//$ extends java.lang.Object

#include <java/lang/Array.h>

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
			namespace spi {

class $export GSSNameSpi : public ::java::lang::Object {
	$interface(GSSNameSpi, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual bool equals(Object$* another) override;
	virtual bool equals(::sun::security::jgss::spi::GSSNameSpi* name) {return false;}
	virtual $bytes* export$() {return nullptr;}
	virtual ::org::ietf::jgss::Oid* getMechanism() {return nullptr;}
	virtual ::java::security::Provider* getProvider() {return nullptr;}
	virtual ::org::ietf::jgss::Oid* getStringNameType() {return nullptr;}
	virtual int32_t hashCode() override;
	virtual bool isAnonymousName() {return false;}
	virtual $String* toString() override;
};

			} // spi
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_spi_GSSNameSpi_h_