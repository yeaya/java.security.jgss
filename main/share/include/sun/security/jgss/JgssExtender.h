#ifndef _sun_security_jgss_JgssExtender_h_
#define _sun_security_jgss_JgssExtender_h_
//$ class sun.security.jgss.JgssExtender
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace org {
	namespace ietf {
		namespace jgss {
			class GSSContext;
			class GSSCredential;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $import JgssExtender : public ::java::lang::Object {
	$class(JgssExtender, 0, ::java::lang::Object)
public:
	JgssExtender();
	void init$();
	static ::sun::security::jgss::JgssExtender* getExtender();
	static void setExtender(::sun::security::jgss::JgssExtender* theOne);
	virtual ::org::ietf::jgss::GSSCredential* wrap(::org::ietf::jgss::GSSCredential* cred);
	virtual ::org::ietf::jgss::GSSContext* wrap(::org::ietf::jgss::GSSContext* ctxt);
	static $volatile(::sun::security::jgss::JgssExtender*) theOne;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_JgssExtender_h_