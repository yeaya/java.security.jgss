#include <sun/security/krb5/KdcComm$KdcCommunication.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/SocketTimeoutException.h>
#include <sun/security/krb5/KdcComm.h>
#include <sun/security/krb5/internal/NetClient.h>
#include <jcpp.h>

#undef DEBUG

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SocketTimeoutException = ::java::net::SocketTimeoutException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $KdcComm = ::sun::security::krb5::KdcComm;
using $NetClient = ::sun::security::krb5::internal::NetClient;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KdcComm$KdcCommunication_FieldInfo_[] = {
	{"kdc", "Ljava/lang/String;", nullptr, $PRIVATE, $field(KdcComm$KdcCommunication, kdc)},
	{"port", "I", nullptr, $PRIVATE, $field(KdcComm$KdcCommunication, port)},
	{"useTCP", "Z", nullptr, $PRIVATE, $field(KdcComm$KdcCommunication, useTCP)},
	{"timeout", "I", nullptr, $PRIVATE, $field(KdcComm$KdcCommunication, timeout)},
	{"retries", "I", nullptr, $PRIVATE, $field(KdcComm$KdcCommunication, retries)},
	{"obuf", "[B", nullptr, $PRIVATE, $field(KdcComm$KdcCommunication, obuf)},
	{}
};

$MethodInfo _KdcComm$KdcCommunication_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;IZII[B)V", nullptr, $PUBLIC, $method(static_cast<void(KdcComm$KdcCommunication::*)($String*,int32_t,bool,int32_t,int32_t,$bytes*)>(&KdcComm$KdcCommunication::init$))},
	{"run", "()[B", nullptr, $PUBLIC, nullptr, "java.io.IOException,sun.security.krb5.KrbException"},
	{}
};

$InnerClassInfo _KdcComm$KdcCommunication_InnerClassesInfo_[] = {
	{"sun.security.krb5.KdcComm$KdcCommunication", "sun.security.krb5.KdcComm", "KdcCommunication", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _KdcComm$KdcCommunication_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.KdcComm$KdcCommunication",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_KdcComm$KdcCommunication_FieldInfo_,
	_KdcComm$KdcCommunication_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<[B>;",
	nullptr,
	_KdcComm$KdcCommunication_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.KdcComm"
};

$Object* allocate$KdcComm$KdcCommunication($Class* clazz) {
	return $of($alloc(KdcComm$KdcCommunication));
}

void KdcComm$KdcCommunication::init$($String* kdc, int32_t port, bool useTCP, int32_t timeout, int32_t retries, $bytes* obuf) {
	$set(this, kdc, kdc);
	this->port = port;
	this->useTCP = useTCP;
	this->timeout = timeout;
	this->retries = retries;
	$set(this, obuf, obuf);
}

$Object* KdcComm$KdcCommunication::run() {
	$var($bytes, ibuf, nullptr);
	for (int32_t i = 1; i <= this->retries; ++i) {
		$var($String, proto, this->useTCP ? "TCP"_s : "UDP"_s);
		$init($KdcComm);
		if ($KdcComm::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>> KDCCommunication: kdc="_s, this->kdc, " "_s, proto, ":"_s, $$str(this->port), ", timeout="_s, $$str(this->timeout), ",Attempt ="_s, $$str(i), ", #bytes="_s, $$str($nc(this->obuf)->length)}));
		}
		try {
			$var($NetClient, kdcClient, $NetClient::getInstance(proto, this->kdc, this->port, this->timeout));
			{
				$var($Throwable, var$0, nullptr);
				bool break$1 = false;
				try {
					try {
						$nc(kdcClient)->send(this->obuf);
						$assign(ibuf, kdcClient->receive());
						// break;
						break$1 = true;
						goto $finally;
					} catch ($Throwable&) {
						$var($Throwable, t$, $catch());
						if (kdcClient != nullptr) {
							try {
								kdcClient->close();
							} catch ($Throwable&) {
								$var($Throwable, x2, $catch());
								t$->addSuppressed(x2);
							}
						}
						$throw(t$);
					}
				} catch ($Throwable&) {
					$assign(var$0, $catch());
				} $finally: {
					if (kdcClient != nullptr) {
						kdcClient->close();
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
				if (break$1) {
					break;
				}
			}
		} catch ($SocketTimeoutException&) {
			$var($SocketTimeoutException, se, $catch());
			if ($KdcComm::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SocketTimeOutException with attempt: "_s, $$str(i)}));
			}
			if (i == this->retries) {
				$assign(ibuf, nullptr);
				$throw(se);
			}
		}
	}
	return $of(ibuf);
}

KdcComm$KdcCommunication::KdcComm$KdcCommunication() {
}

$Class* KdcComm$KdcCommunication::load$($String* name, bool initialize) {
	$loadClass(KdcComm$KdcCommunication, name, initialize, &_KdcComm$KdcCommunication_ClassInfo_, allocate$KdcComm$KdcCommunication);
	return class$;
}

$Class* KdcComm$KdcCommunication::class$ = nullptr;

		} // krb5
	} // security
} // sun