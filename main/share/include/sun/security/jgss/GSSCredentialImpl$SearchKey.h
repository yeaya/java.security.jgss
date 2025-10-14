#ifndef _sun_security_jgss_GSSCredentialImpl$SearchKey_h_
#define _sun_security_jgss_GSSCredentialImpl$SearchKey_h_
//$ class sun.security.jgss.GSSCredentialImpl$SearchKey
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class $import GSSCredentialImpl$SearchKey : public ::java::lang::Object {
	$class(GSSCredentialImpl$SearchKey, $NO_CLASS_INIT, ::java::lang::Object)
public:
	GSSCredentialImpl$SearchKey();
	void init$(::org::ietf::jgss::Oid* mechOid, int32_t usage);
	virtual bool equals(Object$* other) override;
	virtual ::org::ietf::jgss::Oid* getMech();
	virtual int32_t getUsage();
	virtual int32_t hashCode() override;
	::org::ietf::jgss::Oid* mechOid = nullptr;
	int32_t usage = 0;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_GSSCredentialImpl$SearchKey_h_