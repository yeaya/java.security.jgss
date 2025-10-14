#ifndef _sun_security_krb5_internal_KrbApErrException_h_
#define _sun_security_krb5_internal_KrbApErrException_h_
//$ class sun.security.krb5.internal.KrbApErrException
//$ extends sun.security.krb5.KrbException

#include <sun/security/krb5/KrbException.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import KrbApErrException : public ::sun::security::krb5::KrbException {
	$class(KrbApErrException, $NO_CLASS_INIT, ::sun::security::krb5::KrbException)
public:
	KrbApErrException();
	void init$(int32_t i);
	void init$(int32_t i, $String* s);
	static const int64_t serialVersionUID = (int64_t)0x68B62A01E48546EB;
	KrbApErrException(const KrbApErrException& e);
	KrbApErrException wrapper$();
	virtual void throwWrapper$() override;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_KrbApErrException_h_