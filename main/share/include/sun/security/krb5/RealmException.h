#ifndef _sun_security_krb5_RealmException_h_
#define _sun_security_krb5_RealmException_h_
//$ class sun.security.krb5.RealmException
//$ extends sun.security.krb5.KrbException

#include <sun/security/krb5/KrbException.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import RealmException : public ::sun::security::krb5::KrbException {
	$class(RealmException, $NO_CLASS_INIT, ::sun::security::krb5::KrbException)
public:
	RealmException();
	void init$(int32_t i);
	void init$($String* s);
	void init$(int32_t i, $String* s);
	void init$($Throwable* cause);
	static const int64_t serialVersionUID = (int64_t)0x81B4EFDD32906DA0;
	RealmException(const RealmException& e);
	RealmException wrapper$();
	virtual void throwWrapper$() override;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_RealmException_h_