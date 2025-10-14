#ifndef _sun_security_krb5_Confounder_h_
#define _sun_security_krb5_Confounder_h_
//$ class sun.security.krb5.Confounder
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace security {
		class SecureRandom;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $export Confounder : public ::java::lang::Object {
	$class(Confounder, 0, ::java::lang::Object)
public:
	Confounder();
	void init$();
	static $bytes* bytes(int32_t size);
	static int32_t intValue();
	static int64_t longValue();
	static ::java::security::SecureRandom* srand;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_Confounder_h_