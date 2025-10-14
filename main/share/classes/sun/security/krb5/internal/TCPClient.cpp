#include <sun/security/krb5/internal/TCPClient.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/FilterInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/Socket.h>
#include <java/net/SocketAddress.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/NetClient.h>
#include <sun/security/util/IOUtils.h>
#include <jcpp.h>

#undef DEBUG

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $FilterInputStream = ::java::io::FilterInputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Socket = ::java::net::Socket;
using $SocketAddress = ::java::net::SocketAddress;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $NetClient = ::sun::security::krb5::internal::NetClient;
using $IOUtils = ::sun::security::util::IOUtils;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _TCPClient_FieldInfo_[] = {
	{"tcpSocket", "Ljava/net/Socket;", nullptr, $PRIVATE, $field(TCPClient, tcpSocket)},
	{"out", "Ljava/io/BufferedOutputStream;", nullptr, $PRIVATE, $field(TCPClient, out)},
	{"in", "Ljava/io/BufferedInputStream;", nullptr, $PRIVATE, $field(TCPClient, in)},
	{}
};

$MethodInfo _TCPClient_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;II)V", nullptr, 0, $method(static_cast<void(TCPClient::*)($String*,int32_t,int32_t)>(&TCPClient::init$)), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"intToNetworkByteOrder", "(I[BII)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)(int32_t,$bytes*,int32_t,int32_t)>(&TCPClient::intToNetworkByteOrder))},
	{"networkByteOrderToInt", "([BII)I", nullptr, $PRIVATE | $STATIC, $method(static_cast<int32_t(*)($bytes*,int32_t,int32_t)>(&TCPClient::networkByteOrderToInt))},
	{"readFully", "([BI)I", nullptr, $PRIVATE, $method(static_cast<int32_t(TCPClient::*)($bytes*,int32_t)>(&TCPClient::readFully)), "java.io.IOException"},
	{"receive", "()[B", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"send", "([B)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _TCPClient_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.internal.TCPClient",
	"sun.security.krb5.internal.NetClient",
	nullptr,
	_TCPClient_FieldInfo_,
	_TCPClient_MethodInfo_
};

$Object* allocate$TCPClient($Class* clazz) {
	return $of($alloc(TCPClient));
}

void TCPClient::init$($String* hostname, int32_t port, int32_t timeout) {
	$NetClient::init$();
	$set(this, tcpSocket, $new($Socket));
	$nc(this->tcpSocket)->connect($$new($InetSocketAddress, hostname, port), timeout);
	$set(this, out, $new($BufferedOutputStream, $($nc(this->tcpSocket)->getOutputStream())));
	$set(this, in, $new($BufferedInputStream, $($nc(this->tcpSocket)->getInputStream())));
	$nc(this->tcpSocket)->setSoTimeout(timeout);
}

void TCPClient::send($bytes* data) {
	$var($bytes, lenField, $new($bytes, 4));
	intToNetworkByteOrder($nc(data)->length, lenField, 0, 4);
	$nc(this->out)->write(lenField);
	$nc(this->out)->write(data);
	$nc(this->out)->flush();
}

$bytes* TCPClient::receive() {
	$var($bytes, lenField, $new($bytes, 4));
	int32_t count = readFully(lenField, 4);
	if (count != 4) {
		$init($Krb5);
		if ($Krb5::DEBUG) {
			$init($System);
			$nc($System::out)->println(">>>DEBUG: TCPClient could not read length field"_s);
		}
		return nullptr;
	}
	int32_t len = networkByteOrderToInt(lenField, 0, 4);
	$init($Krb5);
	if ($Krb5::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>>DEBUG: TCPClient reading "_s, $$str(len), " bytes"_s}));
	}
	if (len <= 0) {
		if ($Krb5::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>>DEBUG: TCPClient zero or negative length field: "_s, $$str(len)}));
		}
		return nullptr;
	}
	try {
		return $IOUtils::readExactlyNBytes(this->in, len);
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		if ($Krb5::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>>DEBUG: TCPClient could not read complete packet ("_s, $$str(len), "/"_s, $$str(count), ")"_s}));
		}
		return nullptr;
	}
	$shouldNotReachHere();
}

void TCPClient::close() {
	$nc(this->tcpSocket)->close();
}

int32_t TCPClient::readFully($bytes* inBuf, int32_t total) {
	int32_t count = 0;
	int32_t pos = 0;
	while (total > 0) {
		count = $nc(this->in)->read(inBuf, pos, total);
		if (count == -1) {
			return (pos == 0 ? -1 : pos);
		}
		pos += count;
		total -= count;
	}
	return pos;
}

int32_t TCPClient::networkByteOrderToInt($bytes* buf, int32_t start, int32_t count) {
	$init(TCPClient);
	if (count > 4) {
		$throwNew($IllegalArgumentException, "Cannot handle more than 4 bytes"_s);
	}
	int32_t answer = 0;
	for (int32_t i = 0; i < count; ++i) {
		answer <<= 8;
		answer |= ((int32_t)((int32_t)$nc(buf)->get(start + i) & (uint32_t)255));
	}
	return answer;
}

void TCPClient::intToNetworkByteOrder(int32_t num, $bytes* buf, int32_t start, int32_t count) {
	$init(TCPClient);
	if (count > 4) {
		$throwNew($IllegalArgumentException, "Cannot handle more than 4 bytes"_s);
	}
	for (int32_t i = count - 1; i >= 0; --i) {
		$nc(buf)->set(start + i, (int8_t)((int32_t)(num & (uint32_t)255)));
		$usrAssign(num, 8);
	}
}

TCPClient::TCPClient() {
}

$Class* TCPClient::load$($String* name, bool initialize) {
	$loadClass(TCPClient, name, initialize, &_TCPClient_ClassInfo_, allocate$TCPClient);
	return class$;
}

$Class* TCPClient::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun