#include <sun/security/krb5/internal/NetClient.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/TCPClient.h>
#include <sun/security/krb5/internal/UDPClient.h>
#include <jcpp.h>

using $AutoCloseable = ::java::lang::AutoCloseable;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $TCPClient = ::sun::security::krb5::internal::TCPClient;
using $UDPClient = ::sun::security::krb5::internal::UDPClient;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$MethodInfo _NetClient_MethodInfo_[] = {
	{"close", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(NetClient::*)()>(&NetClient::init$))},
	{"getInstance", "(Ljava/lang/String;Ljava/lang/String;II)Lsun/security/krb5/internal/NetClient;", nullptr, $PUBLIC | $STATIC, $method(static_cast<NetClient*(*)($String*,$String*,int32_t,int32_t)>(&NetClient::getInstance)), "java.io.IOException"},
	{"receive", "()[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"send", "([B)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _NetClient_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.internal.NetClient",
	"java.lang.Object",
	"java.lang.AutoCloseable",
	nullptr,
	_NetClient_MethodInfo_
};

$Object* allocate$NetClient($Class* clazz) {
	return $of($alloc(NetClient));
}

void NetClient::init$() {
}

NetClient* NetClient::getInstance($String* protocol, $String* hostname, int32_t port, int32_t timeout) {
	$init(NetClient);
	if ($nc(protocol)->equals("TCP"_s)) {
		return $new($TCPClient, hostname, port, timeout);
	} else {
		return $new($UDPClient, hostname, port, timeout);
	}
}

NetClient::NetClient() {
}

$Class* NetClient::load$($String* name, bool initialize) {
	$loadClass(NetClient, name, initialize, &_NetClient_ClassInfo_, allocate$NetClient);
	return class$;
}

$Class* NetClient::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun