#ifndef _sun_security_jgss_GSSNameImpl_h_
#define _sun_security_jgss_GSSNameImpl_h_
//$ class sun.security.jgss.GSSNameImpl
//$ extends org.ietf.jgss.GSSName

#include <java/lang/Array.h>
#include <org/ietf/jgss/GSSName.h>

namespace java {
	namespace util {
		class HashMap;
		class Set;
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
			class GSSManagerImpl;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {
				class GSSNameSpi;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $export GSSNameImpl : public ::org::ietf::jgss::GSSName {
	$class(GSSNameImpl, 0, ::org::ietf::jgss::GSSName)
public:
	GSSNameImpl();
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, ::sun::security::jgss::spi::GSSNameSpi* mechElement);
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, Object$* appName, ::org::ietf::jgss::Oid* appNameType);
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, Object$* appName, ::org::ietf::jgss::Oid* appNameType, ::org::ietf::jgss::Oid* mech);
	virtual ::org::ietf::jgss::GSSName* canonicalize(::org::ietf::jgss::Oid* mech) override;
	virtual bool equals(::org::ietf::jgss::GSSName* other) override;
	virtual bool equals(Object$* another) override;
	virtual $bytes* export$() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getElement(::org::ietf::jgss::Oid* mechOid);
	virtual ::java::util::Set* getElements();
	static $String* getNameTypeStr(::org::ietf::jgss::Oid* nameTypeOid);
	virtual ::org::ietf::jgss::Oid* getStringNameType() override;
	virtual int32_t hashCode() override;
	void importName(::sun::security::jgss::GSSManagerImpl* gssManager, Object$* appName);
	void init(::sun::security::jgss::GSSManagerImpl* gssManager, Object$* appName, ::org::ietf::jgss::Oid* appNameType, ::org::ietf::jgss::Oid* mech);
	virtual bool isAnonymous() override;
	virtual bool isMN() override;
	virtual $String* toString() override;
	static ::sun::security::jgss::GSSNameImpl* wrapElement(::sun::security::jgss::GSSManagerImpl* gssManager, ::sun::security::jgss::spi::GSSNameSpi* mechElement);
	static ::org::ietf::jgss::Oid* oldHostbasedServiceName;
	::sun::security::jgss::GSSManagerImpl* gssManager = nullptr;
	$String* appNameStr = nullptr;
	$bytes* appNameBytes = nullptr;
	::org::ietf::jgss::Oid* appNameType = nullptr;
	$String* printableName = nullptr;
	::org::ietf::jgss::Oid* printableNameType = nullptr;
	::java::util::HashMap* elements = nullptr;
	::sun::security::jgss::spi::GSSNameSpi* mechElement = nullptr;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_GSSNameImpl_h_