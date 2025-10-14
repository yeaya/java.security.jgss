#ifndef _sun_security_krb5_internal_MethodData_h_
#define _sun_security_krb5_internal_MethodData_h_
//$ class sun.security.krb5.internal.MethodData
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace util {
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import MethodData : public ::java::lang::Object {
	$class(MethodData, $NO_CLASS_INIT, ::java::lang::Object)
public:
	MethodData();
	void init$(int32_t type, $bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	int32_t methodType = 0;
	$bytes* methodData = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_MethodData_h_