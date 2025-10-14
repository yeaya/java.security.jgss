#ifndef _sun_security_krb5_internal_KrbErrException_h_
#define _sun_security_krb5_internal_KrbErrException_h_
//$ class sun.security.krb5.internal.KrbErrException
//$ extends sun.security.krb5.KrbException

#include <sun/security/krb5/KrbException.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import KrbErrException : public ::sun::security::krb5::KrbException {
	$class(KrbErrException, $NO_CLASS_INIT, ::sun::security::krb5::KrbException)
public:
	KrbErrException();
	void init$(int32_t i);
	void init$(int32_t i, $String* s);
	static const int64_t serialVersionUID = (int64_t)0x1E5820F096F7F57D;
	KrbErrException(const KrbErrException& e);
	KrbErrException wrapper$();
	virtual void throwWrapper$() override;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_KrbErrException_h_