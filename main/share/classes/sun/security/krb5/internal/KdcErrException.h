#ifndef _sun_security_krb5_internal_KdcErrException_h_
#define _sun_security_krb5_internal_KdcErrException_h_
//$ class sun.security.krb5.internal.KdcErrException
//$ extends sun.security.krb5.KrbException

#include <sun/security/krb5/KrbException.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export KdcErrException : public ::sun::security::krb5::KrbException {
	$class(KdcErrException, $NO_CLASS_INIT, ::sun::security::krb5::KrbException)
public:
	KdcErrException();
	void init$(int32_t i);
	void init$(int32_t i, $String* s);
	static const int64_t serialVersionUID = (int64_t)0x860A175DD333E69E;
	KdcErrException(const KdcErrException& e);
	KdcErrException wrapper$();
	virtual void throwWrapper$() override;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_KdcErrException_h_