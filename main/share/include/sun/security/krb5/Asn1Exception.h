#ifndef _sun_security_krb5_Asn1Exception_h_
#define _sun_security_krb5_Asn1Exception_h_
//$ class sun.security.krb5.Asn1Exception
//$ extends sun.security.krb5.KrbException

#include <sun/security/krb5/KrbException.h>

namespace sun {
	namespace security {
		namespace krb5 {

class $import Asn1Exception : public ::sun::security::krb5::KrbException {
	$class(Asn1Exception, $NO_CLASS_INIT, ::sun::security::krb5::KrbException)
public:
	Asn1Exception();
	void init$(int32_t i);
	static const int64_t serialVersionUID = (int64_t)0x73109366FFB50664;
	Asn1Exception(const Asn1Exception& e);
	Asn1Exception wrapper$();
	virtual void throwWrapper$() override;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_Asn1Exception_h_