#include <sun/security/krb5/internal/UDPClient.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/DatagramPacket.h>
#include <java/net/DatagramSocket.h>
#include <java/net/InetAddress.h>
#include <java/net/PortUnreachableException.h>
#include <java/net/SocketException.h>
#include <sun/security/krb5/internal/NetClient.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $DatagramPacket = ::java::net::DatagramPacket;
using $DatagramSocket = ::java::net::DatagramSocket;
using $InetAddress = ::java::net::InetAddress;
using $PortUnreachableException = ::java::net::PortUnreachableException;
using $SocketException = ::java::net::SocketException;
using $NetClient = ::sun::security::krb5::internal::NetClient;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _UDPClient_FieldInfo_[] = {
	{"iaddr", "Ljava/net/InetAddress;", nullptr, 0, $field(UDPClient, iaddr)},
	{"iport", "I", nullptr, 0, $field(UDPClient, iport)},
	{"bufSize", "I", nullptr, 0, $field(UDPClient, bufSize)},
	{"dgSocket", "Ljava/net/DatagramSocket;", nullptr, 0, $field(UDPClient, dgSocket)},
	{"dgPacketIn", "Ljava/net/DatagramPacket;", nullptr, 0, $field(UDPClient, dgPacketIn)},
	{}
};

$MethodInfo _UDPClient_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;II)V", nullptr, 0, $method(static_cast<void(UDPClient::*)($String*,int32_t,int32_t)>(&UDPClient::init$)), "java.net.UnknownHostException,java.net.SocketException"},
	{"close", "()V", nullptr, $PUBLIC},
	{"receive", "()[B", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"send", "([B)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _UDPClient_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.internal.UDPClient",
	"sun.security.krb5.internal.NetClient",
	nullptr,
	_UDPClient_FieldInfo_,
	_UDPClient_MethodInfo_
};

$Object* allocate$UDPClient($Class* clazz) {
	return $of($alloc(UDPClient));
}

void UDPClient::init$($String* hostname, int32_t port, int32_t timeout) {
	$NetClient::init$();
	this->bufSize = 0x0000FFE3;
	$set(this, iaddr, $InetAddress::getByName(hostname));
	this->iport = port;
	$set(this, dgSocket, $new($DatagramSocket));
	$nc(this->dgSocket)->setSoTimeout(timeout);
	$nc(this->dgSocket)->connect(this->iaddr, this->iport);
}

void UDPClient::send($bytes* data) {
	$var($DatagramPacket, dgPacketOut, $new($DatagramPacket, data, $nc(data)->length, this->iaddr, this->iport));
	$nc(this->dgSocket)->send(dgPacketOut);
}

$bytes* UDPClient::receive() {
	$var($bytes, ibuf, $new($bytes, this->bufSize));
	$set(this, dgPacketIn, $new($DatagramPacket, ibuf, ibuf->length));
	try {
		$nc(this->dgSocket)->receive(this->dgPacketIn);
	} catch ($SocketException&) {
		$var($SocketException, e, $catch());
		if ($instanceOf($PortUnreachableException, e)) {
			$throw(e);
		}
		$nc(this->dgSocket)->receive(this->dgPacketIn);
	}
	$var($bytes, data, $new($bytes, $nc(this->dgPacketIn)->getLength()));
	$var($Object, var$0, $of($nc(this->dgPacketIn)->getData()));
	$var($Object, var$1, $of(data));
	$System::arraycopy(var$0, 0, var$1, 0, $nc(this->dgPacketIn)->getLength());
	return data;
}

void UDPClient::close() {
	$nc(this->dgSocket)->close();
}

UDPClient::UDPClient() {
}

$Class* UDPClient::load$($String* name, bool initialize) {
	$loadClass(UDPClient, name, initialize, &_UDPClient_ClassInfo_, allocate$UDPClient);
	return class$;
}

$Class* UDPClient::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun