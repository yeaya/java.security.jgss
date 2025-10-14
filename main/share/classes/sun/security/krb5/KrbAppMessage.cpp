#include <sun/security/krb5/KrbAppMessage.h>

#include <java/io/PrintStream.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/HostAddress.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/SeqNumber.h>
#include <jcpp.h>

#undef API_INVALID_ARG
#undef DEBUG
#undef KRB_AP_ERR_BADADDR
#undef KRB_AP_ERR_BADORDER
#undef KRB_AP_ERR_MODIFIED
#undef KRB_AP_ERR_SKEW

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $SeqNumber = ::sun::security::krb5::internal::SeqNumber;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbAppMessage_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(KrbAppMessage, DEBUG)},
	{}
};

$MethodInfo _KrbAppMessage_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(KrbAppMessage::*)()>(&KrbAppMessage::init$))},
	{"check", "(Lsun/security/krb5/internal/KerberosTime;Ljava/lang/Integer;Ljava/lang/Integer;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;ZZLsun/security/krb5/PrincipalName;)V", nullptr, 0, nullptr, "sun.security.krb5.internal.KrbApErrException"},
	{}
};

$ClassInfo _KrbAppMessage_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.KrbAppMessage",
	"java.lang.Object",
	nullptr,
	_KrbAppMessage_FieldInfo_,
	_KrbAppMessage_MethodInfo_
};

$Object* allocate$KrbAppMessage($Class* clazz) {
	return $of($alloc(KrbAppMessage));
}

bool KrbAppMessage::DEBUG = false;

void KrbAppMessage::init$() {
}

void KrbAppMessage::check($KerberosTime* packetTimestamp$renamed, $Integer* packetUsec, $Integer* packetSeqNumber, $HostAddress* packetSAddress, $HostAddress* packetRAddress, $SeqNumber* seqNumber, $HostAddress* sAddress, $HostAddress* rAddress, bool timestampRequired, bool seqNumberRequired, $PrincipalName* packetPrincipal) {
	$var($KerberosTime, packetTimestamp, packetTimestamp$renamed);
	if (sAddress != nullptr) {
		if (packetSAddress == nullptr || sAddress == nullptr || !$nc(packetSAddress)->equals(sAddress)) {
			if (KrbAppMessage::DEBUG && packetSAddress == nullptr) {
				$init($System);
				$nc($System::out)->println("packetSAddress is null"_s);
			}
			if (KrbAppMessage::DEBUG && sAddress == nullptr) {
				$init($System);
				$nc($System::out)->println("sAddress is null"_s);
			}
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADADDR);
		}
	}
	if (rAddress != nullptr) {
		if (packetRAddress == nullptr || rAddress == nullptr || !$nc(packetRAddress)->equals(rAddress)) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADADDR);
		}
	}
	if (packetTimestamp != nullptr) {
		if (packetUsec != nullptr) {
			$assign(packetTimestamp, packetTimestamp->withMicroSeconds(packetUsec->intValue()));
		}
		if (!packetTimestamp->inClockSkew()) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_SKEW);
		}
	} else if (timestampRequired) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_SKEW);
	}
	if (seqNumber == nullptr && seqNumberRequired == true) {
		$throwNew($KrbApErrException, $Krb5::API_INVALID_ARG);
	}
	if (packetSeqNumber != nullptr && seqNumber != nullptr) {
		int32_t var$0 = packetSeqNumber->intValue();
		if (var$0 != seqNumber->current()) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADORDER);
		}
		seqNumber->step();
	} else if (seqNumberRequired) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADORDER);
	}
	if (packetTimestamp == nullptr && packetSeqNumber == nullptr) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
	}
}

void clinit$KrbAppMessage($Class* class$) {
	$init($Krb5);
	KrbAppMessage::DEBUG = $Krb5::DEBUG;
}

KrbAppMessage::KrbAppMessage() {
}

$Class* KrbAppMessage::load$($String* name, bool initialize) {
	$loadClass(KrbAppMessage, name, initialize, &_KrbAppMessage_ClassInfo_, clinit$KrbAppMessage, allocate$KrbAppMessage);
	return class$;
}

$Class* KrbAppMessage::class$ = nullptr;

		} // krb5
	} // security
} // sun