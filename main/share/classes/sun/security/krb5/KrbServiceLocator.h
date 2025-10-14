#ifndef _sun_security_krb5_KrbServiceLocator_h_
#define _sun_security_krb5_KrbServiceLocator_h_
//$ class sun.security.krb5.KrbServiceLocator
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("SRV_RR")
#undef SRV_RR
#pragma push_macro("SRV_RR_ATTR")
#undef SRV_RR_ATTR
#pragma push_macro("SRV_TXT")
#undef SRV_TXT
#pragma push_macro("SRV_TXT_ATTR")
#undef SRV_TXT_ATTR

namespace java {
	namespace util {
		class Random;
	}
}
namespace javax {
	namespace naming {
		class Context;
	}
}
namespace javax {
	namespace naming {
		namespace directory {
			class Attributes;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class KrbServiceLocator$SrvRecord;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class KrbServiceLocator : public ::java::lang::Object {
	$class(KrbServiceLocator, 0, ::java::lang::Object)
public:
	KrbServiceLocator();
	void init$();
	static $StringArray* extractHostports($Array<::sun::security::krb5::KrbServiceLocator$SrvRecord>* srvRecords);
	static $StringArray* getKerberosService($String* realmName);
	static $StringArray* getKerberosService($String* realmName, $String* protocol);
	static ::javax::naming::directory::Attributes* lambda$getKerberosService$0(::javax::naming::Context* ctx, $String* dnsUrl);
	static ::javax::naming::directory::Attributes* lambda$getKerberosService$1(::javax::naming::Context* ctx, $String* dnsUrl);
	static $String* selectHostport($Array<::sun::security::krb5::KrbServiceLocator$SrvRecord>* srvRecords, int32_t head, int32_t tail);
	static $String* SRV_RR;
	static $StringArray* SRV_RR_ATTR;
	static $String* SRV_TXT;
	static $StringArray* SRV_TXT_ATTR;
	static ::java::util::Random* random;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("SRV_RR")
#pragma pop_macro("SRV_RR_ATTR")
#pragma pop_macro("SRV_TXT")
#pragma pop_macro("SRV_TXT_ATTR")

#endif // _sun_security_krb5_KrbServiceLocator_h_