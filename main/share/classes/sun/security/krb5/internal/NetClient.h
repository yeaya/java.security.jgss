#ifndef _sun_security_krb5_internal_NetClient_h_
#define _sun_security_krb5_internal_NetClient_h_
//$ class sun.security.krb5.internal.NetClient
//$ extends java.lang.AutoCloseable

#include <java/lang/Array.h>
#include <java/lang/AutoCloseable.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export NetClient : public ::java::lang::AutoCloseable {
	$class(NetClient, $NO_CLASS_INIT, ::java::lang::AutoCloseable)
public:
	NetClient();
	virtual void close() override {}
	void init$();
	static ::sun::security::krb5::internal::NetClient* getInstance($String* protocol, $String* hostname, int32_t port, int32_t timeout);
	virtual $bytes* receive() {return nullptr;}
	virtual void send($bytes* data) {}
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_NetClient_h_