#ifndef _sun_security_jgss_GSSUtil$1_h_
#define _sun_security_jgss_GSSUtil$1_h_
//$ class sun.security.jgss.GSSUtil$1
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace java {
	namespace security {
		class AccessControlContext;
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
				class GSSNameSpi;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class GSSUtil$1 : public ::java::security::PrivilegedExceptionAction {
	$class(GSSUtil$1, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	GSSUtil$1();
	void init$(::java::security::AccessControlContext* val$acc, ::org::ietf::jgss::Oid* val$mech, bool val$initiate, $Class* val$credCls, ::sun::security::jgss::spi::GSSNameSpi* val$name);
	virtual $Object* run() override;
	::sun::security::jgss::spi::GSSNameSpi* val$name = nullptr;
	$Class* val$credCls = nullptr;
	bool val$initiate = false;
	::org::ietf::jgss::Oid* val$mech = nullptr;
	::java::security::AccessControlContext* val$acc = nullptr;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_GSSUtil$1_h_