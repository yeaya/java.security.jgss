#ifndef _sun_security_jgss_wrapper_GSSNameElement_h_
#define _sun_security_jgss_wrapper_GSSNameElement_h_
//$ class sun.security.jgss.wrapper.GSSNameElement
//$ extends sun.security.jgss.spi.GSSNameSpi

#include <java/lang/Array.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>

#pragma push_macro("DEF_ACCEPTOR")
#undef DEF_ACCEPTOR

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
			namespace wrapper {
				class GSSLibStub;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

class GSSNameElement : public ::sun::security::jgss::spi::GSSNameSpi {
	$class(GSSNameElement, $HAS_FINALIZE, ::sun::security::jgss::spi::GSSNameSpi)
public:
	GSSNameElement();
	void init$();
	void init$(int64_t pNativeName, ::sun::security::jgss::wrapper::GSSLibStub* stub);
	void init$($bytes* nameBytes, ::org::ietf::jgss::Oid* nameType, ::sun::security::jgss::wrapper::GSSLibStub* stub);
	virtual void dispose();
	virtual bool equals(::sun::security::jgss::spi::GSSNameSpi* other) override;
	virtual bool equals(Object$* other) override;
	virtual $bytes* export$() override;
	virtual void finalize() override;
	virtual $String* getKrbName();
	virtual ::org::ietf::jgss::Oid* getMechanism() override;
	static ::org::ietf::jgss::Oid* getNativeNameType(::org::ietf::jgss::Oid* nameType, ::sun::security::jgss::wrapper::GSSLibStub* stub);
	virtual ::java::security::Provider* getProvider() override;
	virtual ::org::ietf::jgss::Oid* getStringNameType() override;
	virtual int32_t hashCode() override;
	virtual bool isAnonymousName() override;
	void setPrintables();
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	int64_t pName = 0;
	$String* printableName = nullptr;
	::org::ietf::jgss::Oid* printableType = nullptr;
	::sun::security::jgss::wrapper::GSSLibStub* cStub = nullptr;
	static ::sun::security::jgss::wrapper::GSSNameElement* DEF_ACCEPTOR;
};

			} // wrapper
		} // jgss
	} // security
} // sun

#pragma pop_macro("DEF_ACCEPTOR")

#endif // _sun_security_jgss_wrapper_GSSNameElement_h_