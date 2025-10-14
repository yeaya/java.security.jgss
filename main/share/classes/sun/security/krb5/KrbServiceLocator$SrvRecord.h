#ifndef _sun_security_krb5_KrbServiceLocator$SrvRecord_h_
#define _sun_security_krb5_KrbServiceLocator$SrvRecord_h_
//$ class sun.security.krb5.KrbServiceLocator$SrvRecord
//$ extends java.lang.Comparable

#include <java/lang/Comparable.h>

namespace sun {
	namespace security {
		namespace krb5 {

class KrbServiceLocator$SrvRecord : public ::java::lang::Comparable {
	$class(KrbServiceLocator$SrvRecord, $NO_CLASS_INIT, ::java::lang::Comparable)
public:
	KrbServiceLocator$SrvRecord();
	void init$($String* srvRecord);
	virtual int32_t compareTo(::sun::security::krb5::KrbServiceLocator$SrvRecord* that);
	virtual int32_t compareTo(Object$* that) override;
	int32_t priority = 0;
	int32_t weight = 0;
	int32_t sum = 0;
	$String* hostport = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbServiceLocator$SrvRecord_h_