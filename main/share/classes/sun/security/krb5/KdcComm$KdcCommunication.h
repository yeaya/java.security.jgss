#ifndef _sun_security_krb5_KdcComm$KdcCommunication_h_
#define _sun_security_krb5_KdcComm$KdcCommunication_h_
//$ class sun.security.krb5.KdcComm$KdcCommunication
//$ extends java.security.PrivilegedExceptionAction

#include <java/lang/Array.h>
#include <java/security/PrivilegedExceptionAction.h>

namespace sun {
	namespace security {
		namespace krb5 {

class KdcComm$KdcCommunication : public ::java::security::PrivilegedExceptionAction {
	$class(KdcComm$KdcCommunication, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	KdcComm$KdcCommunication();
	void init$($String* kdc, int32_t port, bool useTCP, int32_t timeout, int32_t retries, $bytes* obuf);
	virtual $Object* run() override;
	$String* kdc = nullptr;
	int32_t port = 0;
	bool useTCP = false;
	int32_t timeout = 0;
	int32_t retries = 0;
	$bytes* obuf = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KdcComm$KdcCommunication_h_