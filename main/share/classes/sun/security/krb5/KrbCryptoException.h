#ifndef _sun_security_krb5_KrbCryptoException_h_
#define _sun_security_krb5_KrbCryptoException_h_
//$ class sun.security.krb5.KrbCryptoException
//$ extends sun.security.krb5.KrbException

#include <sun/security/krb5/KrbException.h>

namespace sun {
	namespace security {
		namespace krb5 {

class $export KrbCryptoException : public ::sun::security::krb5::KrbException {
	$class(KrbCryptoException, $NO_CLASS_INIT, ::sun::security::krb5::KrbException)
public:
	KrbCryptoException();
	void init$($String* s);
	static const int64_t serialVersionUID = (int64_t)0xE8FFD8A86B771256;
	KrbCryptoException(const KrbCryptoException& e);
	KrbCryptoException wrapper$();
	virtual void throwWrapper$() override;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbCryptoException_h_