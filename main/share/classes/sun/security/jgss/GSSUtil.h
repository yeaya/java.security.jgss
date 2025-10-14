#ifndef _sun_security_jgss_GSSUtil_h_
#define _sun_security_jgss_GSSUtil_h_
//$ class sun.security.jgss.GSSUtil
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("GSS_KRB5_MECH_OID")
#undef GSS_KRB5_MECH_OID
#pragma push_macro("GSS_KRB5_MECH_OID2")
#undef GSS_KRB5_MECH_OID2
#pragma push_macro("GSS_KRB5_MECH_OID_MS")
#undef GSS_KRB5_MECH_OID_MS
#pragma push_macro("GSS_SPNEGO_MECH_OID")
#undef GSS_SPNEGO_MECH_OID
#pragma push_macro("NT_GSS_KRB5_PRINCIPAL")
#undef NT_GSS_KRB5_PRINCIPAL

namespace java {
	namespace util {
		class Set;
		class Vector;
	}
}
namespace javax {
	namespace security {
		namespace auth {
			class Subject;
		}
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class GSSCredential;
			class GSSName;
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
			namespace spi {
				class GSSNameSpi;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $export GSSUtil : public ::java::lang::Object {
	$class(GSSUtil, 0, ::java::lang::Object)
public:
	GSSUtil();
	void init$();
	static ::org::ietf::jgss::Oid* createOid($String* oidStr);
	static void debug($String* message);
	static $String* getMechStr(::org::ietf::jgss::Oid* oid);
	static ::javax::security::auth::Subject* getSubject(::org::ietf::jgss::GSSName* name, ::org::ietf::jgss::GSSCredential* creds);
	static bool isKerberosMech(::org::ietf::jgss::Oid* oid);
	static bool isSpNegoMech(::org::ietf::jgss::Oid* oid);
	static ::javax::security::auth::Subject* login(::sun::security::jgss::GSSCaller* caller, ::org::ietf::jgss::Oid* mech);
	static void populateCredentials(::java::util::Set* credentials, ::java::util::Set* gssCredentials);
	static ::java::util::Vector* searchSubject(::sun::security::jgss::spi::GSSNameSpi* name, ::org::ietf::jgss::Oid* mech, bool initiate, $Class* credCls);
	static bool useMSInterop();
	static bool useSubjectCredsOnly(::sun::security::jgss::GSSCaller* caller);
	static bool $assertionsDisabled;
	static ::org::ietf::jgss::Oid* GSS_KRB5_MECH_OID;
	static ::org::ietf::jgss::Oid* GSS_KRB5_MECH_OID2;
	static ::org::ietf::jgss::Oid* GSS_KRB5_MECH_OID_MS;
	static ::org::ietf::jgss::Oid* GSS_SPNEGO_MECH_OID;
	static ::org::ietf::jgss::Oid* NT_GSS_KRB5_PRINCIPAL;
	static bool DEBUG;
};

		} // jgss
	} // security
} // sun

#pragma pop_macro("DEBUG")
#pragma pop_macro("GSS_KRB5_MECH_OID")
#pragma pop_macro("GSS_KRB5_MECH_OID2")
#pragma pop_macro("GSS_KRB5_MECH_OID_MS")
#pragma pop_macro("GSS_SPNEGO_MECH_OID")
#pragma pop_macro("NT_GSS_KRB5_PRINCIPAL")

#endif // _sun_security_jgss_GSSUtil_h_