#ifndef _sun_security_krb5_internal_TCPClient_h_
#define _sun_security_krb5_internal_TCPClient_h_
//$ class sun.security.krb5.internal.TCPClient
//$ extends sun.security.krb5.internal.NetClient

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/NetClient.h>

namespace java {
	namespace io {
		class BufferedInputStream;
		class BufferedOutputStream;
	}
}
namespace java {
	namespace net {
		class Socket;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class TCPClient : public ::sun::security::krb5::internal::NetClient {
	$class(TCPClient, $NO_CLASS_INIT, ::sun::security::krb5::internal::NetClient)
public:
	TCPClient();
	void init$($String* hostname, int32_t port, int32_t timeout);
	virtual void close() override;
	static void intToNetworkByteOrder(int32_t num, $bytes* buf, int32_t start, int32_t count);
	static int32_t networkByteOrderToInt($bytes* buf, int32_t start, int32_t count);
	int32_t readFully($bytes* inBuf, int32_t total);
	virtual $bytes* receive() override;
	virtual void send($bytes* data) override;
	::java::net::Socket* tcpSocket = nullptr;
	::java::io::BufferedOutputStream* out = nullptr;
	::java::io::BufferedInputStream* in = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_TCPClient_h_