#ifndef _sun_security_jgss_GSSCredentialImpl_h_
#define _sun_security_jgss_GSSCredentialImpl_h_
//$ class sun.security.jgss.GSSCredentialImpl
//$ extends org.ietf.jgss.GSSCredential

#include <java/lang/Array.h>
#include <org/ietf/jgss/GSSCredential.h>

namespace java {
	namespace util {
		class Hashtable;
		class Set;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class GSSName;
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
				class GSSCredentialSpi;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $export GSSCredentialImpl : public ::org::ietf::jgss::GSSCredential {
	$class(GSSCredentialImpl, $NO_CLASS_INIT, ::org::ietf::jgss::GSSCredential)
public:
	GSSCredentialImpl();
	void init$();
	void init$(::sun::security::jgss::GSSCredentialImpl* src);
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, int32_t usage);
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, ::org::ietf::jgss::GSSName* name, int32_t lifetime, ::org::ietf::jgss::Oid* mech, int32_t usage);
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, ::org::ietf::jgss::GSSName* name, int32_t lifetime, $Array<::org::ietf::jgss::Oid>* mechs, int32_t usage);
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, ::sun::security::jgss::spi::GSSCredentialSpi* mechElement);
	virtual void add(::org::ietf::jgss::GSSName* name, int32_t initLifetime, int32_t acceptLifetime, ::org::ietf::jgss::Oid* mech, int32_t usage) override;
	virtual void dispose() override;
	virtual bool equals(Object$* another) override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getElement(::org::ietf::jgss::Oid* mechOid, bool initiate);
	static $String* getElementStr(::org::ietf::jgss::Oid* mechOid, int32_t usage);
	virtual ::java::util::Set* getElements();
	virtual $Array<::org::ietf::jgss::Oid>* getMechs() override;
	virtual ::org::ietf::jgss::GSSName* getName() override;
	virtual ::org::ietf::jgss::GSSName* getName(::org::ietf::jgss::Oid* mech) override;
	virtual int32_t getRemainingAcceptLifetime(::org::ietf::jgss::Oid* mech) override;
	virtual int32_t getRemainingInitLifetime(::org::ietf::jgss::Oid* mech) override;
	virtual int32_t getRemainingLifetime() override;
	virtual int32_t getUsage() override;
	virtual int32_t getUsage(::org::ietf::jgss::Oid* mech) override;
	virtual int32_t hashCode() override;
	virtual ::org::ietf::jgss::GSSCredential* impersonate(::org::ietf::jgss::GSSName* name);
	virtual void init(::sun::security::jgss::GSSManagerImpl* gssManager);
	virtual $String* toString() override;
	::sun::security::jgss::GSSManagerImpl* gssManager = nullptr;
	bool destroyed = false;
	::java::util::Hashtable* hashtable = nullptr;
	::sun::security::jgss::spi::GSSCredentialSpi* tempCred = nullptr;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_GSSCredentialImpl_h_