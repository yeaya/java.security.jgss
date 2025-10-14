#ifndef _sun_security_krb5_KdcComm$KdcAccessibility_h_
#define _sun_security_krb5_KdcComm$KdcAccessibility_h_
//$ class sun.security.krb5.KdcComm$KdcAccessibility
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		class List;
		class Set;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import KdcComm$KdcAccessibility : public ::java::lang::Object {
	$class(KdcComm$KdcAccessibility, 0, ::java::lang::Object)
public:
	KdcComm$KdcAccessibility();
	void init$();
	static void addBad($String* kdc);
	static bool isBad($String* kdc);
	static ::java::util::List* list($String* kdcList);
	static void removeBad($String* kdc);
	static void reset();
	static ::java::util::Set* bads;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KdcComm$KdcAccessibility_h_