#include <sun/security/krb5/KdcComm.h>

#include <java/io/IOException.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/KdcComm$1.h>
#include <sun/security/krb5/KdcComm$BpType.h>
#include <sun/security/krb5/KdcComm$KdcAccessibility.h>
#include <sun/security/krb5/KdcComm$KdcCommunication.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/internal/KRBError.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <jcpp.h>

#undef DEBUG
#undef ENGLISH
#undef KDC_DEFAULT_UDP_PREF_LIMIT
#undef KDC_HARD_UDP_LIMIT
#undef KDC_INET_DEFAULT_PORT
#undef KDC_RETRY_LIMIT
#undef KRB_ERR_GENERIC
#undef KRB_ERR_RESPONSE_TOO_BIG
#undef NONE
#undef TRY_LAST
#undef TRY_LESS

using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Config = ::sun::security::krb5::Config;
using $KdcComm$1 = ::sun::security::krb5::KdcComm$1;
using $KdcComm$BpType = ::sun::security::krb5::KdcComm$BpType;
using $KdcComm$KdcAccessibility = ::sun::security::krb5::KdcComm$KdcAccessibility;
using $KdcComm$KdcCommunication = ::sun::security::krb5::KdcComm$KdcCommunication;
using $KrbException = ::sun::security::krb5::KrbException;
using $KRBError = ::sun::security::krb5::internal::KRBError;
using $Krb5 = ::sun::security::krb5::internal::Krb5;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KdcComm_FieldInfo_[] = {
	{"defaultKdcRetryLimit", "I", nullptr, $PRIVATE | $STATIC, $staticField(KdcComm, defaultKdcRetryLimit)},
	{"defaultKdcTimeout", "I", nullptr, $PRIVATE | $STATIC, $staticField(KdcComm, defaultKdcTimeout)},
	{"defaultUdpPrefLimit", "I", nullptr, $PRIVATE | $STATIC, $staticField(KdcComm, defaultUdpPrefLimit)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KdcComm, DEBUG)},
	{"tryLessMaxRetries", "I", nullptr, $PRIVATE | $STATIC, $staticField(KdcComm, tryLessMaxRetries)},
	{"tryLessTimeout", "I", nullptr, $PRIVATE | $STATIC, $staticField(KdcComm, tryLessTimeout)},
	{"badPolicy", "Lsun/security/krb5/KdcComm$BpType;", nullptr, $PRIVATE | $STATIC, $staticField(KdcComm, badPolicy)},
	{"realm", "Ljava/lang/String;", nullptr, $PRIVATE, $field(KdcComm, realm)},
	{}
};

$MethodInfo _KdcComm_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KdcComm::*)($String*)>(&KdcComm::init$)), "sun.security.krb5.KrbException"},
	{"getRealmSpecificValue", "(Ljava/lang/String;Ljava/lang/String;I)I", nullptr, $PRIVATE, $method(static_cast<int32_t(KdcComm::*)($String*,$String*,int32_t)>(&KdcComm::getRealmSpecificValue))},
	{"initStatic", "()V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)()>(&KdcComm::initStatic))},
	{"parsePositiveIntString", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $method(static_cast<int32_t(*)($String*)>(&KdcComm::parsePositiveIntString))},
	{"parseTimeString", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $method(static_cast<int32_t(*)($String*)>(&KdcComm::parseTimeString))},
	{"send", "([B)[B", nullptr, $PUBLIC, $method(static_cast<$bytes*(KdcComm::*)($bytes*)>(&KdcComm::send)), "java.io.IOException,sun.security.krb5.KrbException"},
	{"send", "([BZ)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(KdcComm::*)($bytes*,bool)>(&KdcComm::send)), "java.io.IOException,sun.security.krb5.KrbException"},
	{"send", "([BLjava/lang/String;Z)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(KdcComm::*)($bytes*,$String*,bool)>(&KdcComm::send)), "java.io.IOException,sun.security.krb5.KrbException"},
	{"sendIfPossible", "([BLjava/lang/String;Z)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(KdcComm::*)($bytes*,$String*,bool)>(&KdcComm::sendIfPossible)), "java.io.IOException,sun.security.krb5.KrbException"},
	{}
};

$InnerClassInfo _KdcComm_InnerClassesInfo_[] = {
	{"sun.security.krb5.KdcComm$KdcAccessibility", "sun.security.krb5.KdcComm", "KdcAccessibility", $STATIC},
	{"sun.security.krb5.KdcComm$KdcCommunication", "sun.security.krb5.KdcComm", "KdcCommunication", $PRIVATE | $STATIC},
	{"sun.security.krb5.KdcComm$BpType", "sun.security.krb5.KdcComm", "BpType", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{"sun.security.krb5.KdcComm$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _KdcComm_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.KdcComm",
	"java.lang.Object",
	nullptr,
	_KdcComm_FieldInfo_,
	_KdcComm_MethodInfo_,
	nullptr,
	nullptr,
	_KdcComm_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.KdcComm$KdcAccessibility,sun.security.krb5.KdcComm$KdcCommunication,sun.security.krb5.KdcComm$BpType,sun.security.krb5.KdcComm$1"
};

$Object* allocate$KdcComm($Class* clazz) {
	return $of($alloc(KdcComm));
}


int32_t KdcComm::defaultKdcRetryLimit = 0;

int32_t KdcComm::defaultKdcTimeout = 0;

int32_t KdcComm::defaultUdpPrefLimit = 0;
bool KdcComm::DEBUG = false;
int32_t KdcComm::tryLessMaxRetries = 0;
int32_t KdcComm::tryLessTimeout = 0;
$KdcComm$BpType* KdcComm::badPolicy = nullptr;

void KdcComm::initStatic() {
	$init(KdcComm);
	$beforeCallerSensitive();
	$var($String, value, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($KdcComm$1)))));
	if (value != nullptr) {
		$init($Locale);
		$assign(value, value->toLowerCase($Locale::ENGLISH));
		$var($StringArray, ss, value->split(":"_s));
		if ("tryless"_s->equals(ss->get(0))) {
			if (ss->length > 1) {
				$var($StringArray, params, $nc(ss->get(1))->split(","_s));
				try {
					int32_t tmp0 = $Integer::parseInt(params->get(0));
					if (params->length > 1) {
						KdcComm::tryLessTimeout = $Integer::parseInt(params->get(1));
					}
					KdcComm::tryLessMaxRetries = tmp0;
				} catch ($NumberFormatException&) {
					$var($NumberFormatException, nfe, $catch());
					if (KdcComm::DEBUG) {
						$init($System);
						$nc($System::out)->println($$str({"Invalid krb5.kdc.bad.policy parameter for tryLess: "_s, value, ", use default"_s}));
					}
				}
			}
			$init($KdcComm$BpType);
			$assignStatic(KdcComm::badPolicy, $KdcComm$BpType::TRY_LESS);
		} else if ("trylast"_s->equals(ss->get(0))) {
			$init($KdcComm$BpType);
			$assignStatic(KdcComm::badPolicy, $KdcComm$BpType::TRY_LAST);
		} else {
			$init($KdcComm$BpType);
			$assignStatic(KdcComm::badPolicy, $KdcComm$BpType::NONE);
		}
	} else {
		$init($KdcComm$BpType);
		$assignStatic(KdcComm::badPolicy, $KdcComm$BpType::NONE);
	}
	int32_t timeout = -1;
	int32_t max_retries = -1;
	int32_t udp_pref_limit = -1;
	try {
		$var($Config, cfg, $Config::getInstance());
		$var($String, temp, $nc(cfg)->get($$new($StringArray, {
			"libdefaults"_s,
			"kdc_timeout"_s
		})));
		timeout = parseTimeString(temp);
		$assign(temp, cfg->get($$new($StringArray, {
			"libdefaults"_s,
			"max_retries"_s
		})));
		max_retries = parsePositiveIntString(temp);
		$assign(temp, cfg->get($$new($StringArray, {
			"libdefaults"_s,
			"udp_preference_limit"_s
		})));
		udp_pref_limit = parsePositiveIntString(temp);
	} catch ($Exception&) {
		$var($Exception, exc, $catch());
		if (KdcComm::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({"Exception in getting KDC communication settings, using default value "_s, $(exc->getMessage())}));
		}
	}
	KdcComm::defaultKdcTimeout = timeout > 0 ? timeout : 30 * 1000;
	KdcComm::defaultKdcRetryLimit = max_retries > 0 ? max_retries : $Krb5::KDC_RETRY_LIMIT;
	if (udp_pref_limit < 0) {
		KdcComm::defaultUdpPrefLimit = $Krb5::KDC_DEFAULT_UDP_PREF_LIMIT;
	} else if (udp_pref_limit > $Krb5::KDC_HARD_UDP_LIMIT) {
		KdcComm::defaultUdpPrefLimit = $Krb5::KDC_HARD_UDP_LIMIT;
	} else {
		KdcComm::defaultUdpPrefLimit = udp_pref_limit;
	}
	$KdcComm$KdcAccessibility::reset();
}

void KdcComm::init$($String* realm$renamed) {
	$var($String, realm, realm$renamed);
	if (realm == nullptr) {
		$assign(realm, $nc($($Config::getInstance()))->getDefaultRealm());
		if (realm == nullptr) {
			$throwNew($KrbException, $Krb5::KRB_ERR_GENERIC, "Cannot find default realm"_s);
		}
	}
	$set(this, realm, realm);
}

$bytes* KdcComm::send($bytes* obuf) {
	int32_t udpPrefLimit = getRealmSpecificValue(this->realm, "udp_preference_limit"_s, KdcComm::defaultUdpPrefLimit);
	bool useTCP = (udpPrefLimit > 0 && (obuf != nullptr && obuf->length > udpPrefLimit));
	return send(obuf, useTCP);
}

$bytes* KdcComm::send($bytes* obuf, bool useTCP) {
	if (obuf == nullptr) {
		return nullptr;
	}
	$var($Config, cfg, $Config::getInstance());
	if (this->realm == nullptr) {
		$set(this, realm, $nc(cfg)->getDefaultRealm());
		if (this->realm == nullptr) {
			$throwNew($KrbException, $Krb5::KRB_ERR_GENERIC, "Cannot find default realm"_s);
		}
	}
	$var($String, kdcList, $nc(cfg)->getKDCList(this->realm));
	if (kdcList == nullptr) {
		$throwNew($KrbException, $$str({"Cannot get kdc for realm "_s, this->realm}));
	}
	$var($Iterator, tempKdc, $nc($($KdcComm$KdcAccessibility::list(kdcList)))->iterator());
	if (!$nc(tempKdc)->hasNext()) {
		$throwNew($KrbException, $$str({"Cannot get kdc for realm "_s, this->realm}));
	}
	$var($bytes, ibuf, nullptr);
	try {
		$assign(ibuf, sendIfPossible(obuf, $cast($String, $($nc(tempKdc)->next())), useTCP));
	} catch ($Exception&) {
		$var($Exception, first, $catch());
		bool ok = false;
		while ($nc(tempKdc)->hasNext()) {
			try {
				$assign(ibuf, sendIfPossible(obuf, $cast($String, $(tempKdc->next())), useTCP));
				ok = true;
				break;
			} catch ($Exception&) {
				$catch();
			}
		}
		if (!ok) {
			$throw(first);
		}
	}
	if (ibuf == nullptr) {
		$throwNew($IOException, "Cannot get a KDC reply"_s);
	}
	return ibuf;
}

$bytes* KdcComm::sendIfPossible($bytes* obuf, $String* tempKdc, bool useTCP) {
	try {
		$var($bytes, ibuf, send(obuf, tempKdc, useTCP));
		$var($KRBError, ke, nullptr);
		try {
			$assign(ke, $new($KRBError, ibuf));
		} catch ($Exception&) {
			$catch();
		}
		if (ke != nullptr && ke->getErrorCode() == $Krb5::KRB_ERR_RESPONSE_TOO_BIG) {
			$assign(ibuf, send(obuf, tempKdc, true));
		}
		$KdcComm$KdcAccessibility::removeBad(tempKdc);
		return ibuf;
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		if (KdcComm::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>> KrbKdcReq send: error trying "_s, tempKdc}));
			e->printStackTrace($System::out);
		}
		$KdcComm$KdcAccessibility::addBad(tempKdc);
		$throw(e);
	}
	$shouldNotReachHere();
}

$bytes* KdcComm::send($bytes* obuf, $String* tempKdc, bool useTCP) {
	$beforeCallerSensitive();
	if (obuf == nullptr) {
		return nullptr;
	}
	int32_t port = $Krb5::KDC_INET_DEFAULT_PORT;
	int32_t retries = getRealmSpecificValue(this->realm, "max_retries"_s, KdcComm::defaultKdcRetryLimit);
	int32_t timeout = getRealmSpecificValue(this->realm, "kdc_timeout"_s, KdcComm::defaultKdcTimeout);
	$init($KdcComm$BpType);
	if (KdcComm::badPolicy == $KdcComm$BpType::TRY_LESS && $KdcComm$KdcAccessibility::isBad(tempKdc)) {
		if (retries > KdcComm::tryLessMaxRetries) {
			retries = KdcComm::tryLessMaxRetries;
		}
		if (timeout > KdcComm::tryLessTimeout) {
			timeout = KdcComm::tryLessTimeout;
		}
	}
	$var($String, kdc, nullptr);
	$var($String, portStr, nullptr);
	if ($nc(tempKdc)->charAt(0) == u'[') {
		int32_t pos = tempKdc->indexOf((int32_t)u']', 1);
		if (pos == -1) {
			$throwNew($IOException, $$str({"Illegal KDC: "_s, tempKdc}));
		}
		$assign(kdc, tempKdc->substring(1, pos));
		if (pos != tempKdc->length() - 1) {
			if (tempKdc->charAt(pos + 1) != u':') {
				$throwNew($IOException, $$str({"Illegal KDC: "_s, tempKdc}));
			}
			$assign(portStr, tempKdc->substring(pos + 2));
		}
	} else {
		int32_t colon = tempKdc->indexOf((int32_t)u':');
		if (colon == -1) {
			$assign(kdc, tempKdc);
		} else {
			int32_t nextColon = tempKdc->indexOf((int32_t)u':', colon + 1);
			if (nextColon > 0) {
				$assign(kdc, tempKdc);
			} else {
				$assign(kdc, tempKdc->substring(0, colon));
				$assign(portStr, tempKdc->substring(colon + 1));
			}
		}
	}
	if (portStr != nullptr) {
		int32_t tempPort = parsePositiveIntString(portStr);
		if (tempPort > 0) {
			port = tempPort;
		}
	}
	if (KdcComm::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>> KrbKdcReq send: kdc="_s, kdc, (useTCP ? " TCP:"_s : " UDP:"_s), $$str(port), ", timeout="_s, $$str(timeout), ", number of retries ="_s, $$str(retries), ", #bytes="_s, $$str($nc(obuf)->length)}));
	}
	$var($KdcComm$KdcCommunication, kdcCommunication, $new($KdcComm$KdcCommunication, kdc, port, useTCP, timeout, retries, obuf));
	try {
		$var($bytes, ibuf, $cast($bytes, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>(kdcCommunication))));
		if (KdcComm::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>> KrbKdcReq send: #bytes read="_s, $$str((ibuf != nullptr ? $nc(ibuf)->length : 0))}));
		}
		return ibuf;
	} catch ($PrivilegedActionException&) {
		$var($PrivilegedActionException, e, $catch());
		$var($Exception, wrappedException, e->getException());
		if ($instanceOf($IOException, wrappedException)) {
			$throw($cast($IOException, wrappedException));
		} else {
			$throw($cast($KrbException, wrappedException));
		}
	}
	$shouldNotReachHere();
}

int32_t KdcComm::parseTimeString($String* s) {
	$init(KdcComm);
	if (s == nullptr) {
		return -1;
	}
	if ($nc(s)->endsWith("s"_s)) {
		int32_t seconds = parsePositiveIntString($(s->substring(0, s->length() - 1)));
		return (seconds < 0) ? -1 : (seconds * 1000);
	} else {
		return parsePositiveIntString(s);
	}
}

int32_t KdcComm::getRealmSpecificValue($String* realm, $String* key, int32_t defValue) {
	int32_t v = defValue;
	if (realm == nullptr) {
		return v;
	}
	int32_t temp = -1;
	try {
		$var($String, value, $nc($($Config::getInstance()))->get($$new($StringArray, {
			"realms"_s,
			realm,
			key
		})));
		if ($nc(key)->equals("kdc_timeout"_s)) {
			temp = parseTimeString(value);
		} else {
			temp = parsePositiveIntString(value);
		}
	} catch ($Exception&) {
		$catch();
	}
	if (temp > 0) {
		v = temp;
	}
	return v;
}

int32_t KdcComm::parsePositiveIntString($String* intString) {
	$init(KdcComm);
	if (intString == nullptr) {
		return -1;
	}
	int32_t ret = -1;
	try {
		ret = $Integer::parseInt(intString);
	} catch ($Exception&) {
		$var($Exception, exc, $catch());
		return -1;
	}
	if (ret >= 0) {
		return ret;
	}
	return -1;
}

void clinit$KdcComm($Class* class$) {
	$init($Krb5);
	KdcComm::DEBUG = $Krb5::DEBUG;
	KdcComm::tryLessMaxRetries = 1;
	KdcComm::tryLessTimeout = 5000;
	{
		KdcComm::initStatic();
	}
}

KdcComm::KdcComm() {
}

$Class* KdcComm::load$($String* name, bool initialize) {
	$loadClass(KdcComm, name, initialize, &_KdcComm_ClassInfo_, clinit$KdcComm, allocate$KdcComm);
	return class$;
}

$Class* KdcComm::class$ = nullptr;

		} // krb5
	} // security
} // sun