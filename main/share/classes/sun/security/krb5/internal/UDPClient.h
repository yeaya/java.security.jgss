#ifndef _sun_security_krb5_internal_UDPClient_h_
#define _sun_security_krb5_internal_UDPClient_h_
//$ class sun.security.krb5.internal.UDPClient
//$ extends sun.security.krb5.internal.NetClient

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/NetClient.h>

namespace java {
	namespace net {
		class DatagramPacket;
		class DatagramSocket;
		class InetAddress;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class UDPClient : public ::sun::security::krb5::internal::NetClient {
	$class(UDPClient, $NO_CLASS_INIT, ::sun::security::krb5::internal::NetClient)
public:
	UDPClient();
	void init$($String* hostname, int32_t port, int32_t timeout);
	virtual void close() override;
	virtual $bytes* receive() override;
	virtual void send($bytes* data) override;
	::java::net::InetAddress* iaddr = nullptr;
	int32_t iport = 0;
	int32_t bufSize = 0;
	::java::net::DatagramSocket* dgSocket = nullptr;
	::java::net::DatagramPacket* dgPacketIn = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_UDPClient_h_