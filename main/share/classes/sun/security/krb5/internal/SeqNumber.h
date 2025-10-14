#ifndef _sun_security_krb5_internal_SeqNumber_h_
#define _sun_security_krb5_internal_SeqNumber_h_
//$ interface sun.security.krb5.internal.SeqNumber
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export SeqNumber : public ::java::lang::Object {
	$interface(SeqNumber, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual int32_t current() {return 0;}
	virtual void init(int32_t start) {}
	virtual int32_t next() {return 0;}
	virtual void randInit() {}
	virtual int32_t step() {return 0;}
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_SeqNumber_h_