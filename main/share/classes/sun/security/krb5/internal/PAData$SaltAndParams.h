#ifndef _sun_security_krb5_internal_PAData$SaltAndParams_h_
#define _sun_security_krb5_internal_PAData$SaltAndParams_h_
//$ class sun.security.krb5.internal.PAData$SaltAndParams
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export PAData$SaltAndParams : public ::java::lang::Object {
	$class(PAData$SaltAndParams, $NO_CLASS_INIT, ::java::lang::Object)
public:
	PAData$SaltAndParams();
	void init$($String* s, $bytes* p);
	$String* salt = nullptr;
	$bytes* params = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_PAData$SaltAndParams_h_