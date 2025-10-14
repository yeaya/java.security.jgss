#include <sun/net/www/protocol/http/spnego/NegotiatorImpl.h>

#include <java/io/IOException.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSContext.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/net/www/protocol/http/HttpCallerInfo.h>
#include <sun/net/www/protocol/http/Negotiator.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSContextImpl.h>
#include <sun/security/jgss/GSSManagerImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/HttpCaller.h>
#include <jcpp.h>

#undef DEBUG
#undef DEFAULT_LIFETIME
#undef GSS_KRB5_MECH_OID
#undef GSS_SPNEGO_MECH_OID
#undef NT_HOSTBASED_SERVICE

using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $GSSContext = ::org::ietf::jgss::GSSContext;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $HttpCallerInfo = ::sun::net::www::protocol::http::HttpCallerInfo;
using $Negotiator = ::sun::net::www::protocol::http::Negotiator;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $GSSContextImpl = ::sun::security::jgss::GSSContextImpl;
using $GSSManagerImpl = ::sun::security::jgss::GSSManagerImpl;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $HttpCaller = ::sun::security::jgss::HttpCaller;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace http {
					namespace spnego {

$FieldInfo _NegotiatorImpl_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NegotiatorImpl, DEBUG)},
	{"context", "Lorg/ietf/jgss/GSSContext;", nullptr, $PRIVATE, $field(NegotiatorImpl, context)},
	{"oneToken", "[B", nullptr, $PRIVATE, $field(NegotiatorImpl, oneToken)},
	{}
};

$MethodInfo _NegotiatorImpl_MethodInfo_[] = {
	{"<init>", "(Lsun/net/www/protocol/http/HttpCallerInfo;)V", nullptr, $PUBLIC, $method(static_cast<void(NegotiatorImpl::*)($HttpCallerInfo*)>(&NegotiatorImpl::init$)), "java.io.IOException"},
	{"firstToken", "()[B", nullptr, $PUBLIC},
	{"init", "(Lsun/net/www/protocol/http/HttpCallerInfo;)V", nullptr, $PRIVATE, $method(static_cast<void(NegotiatorImpl::*)($HttpCallerInfo*)>(&NegotiatorImpl::init)), "org.ietf.jgss.GSSException"},
	{"nextToken", "([B)[B", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _NegotiatorImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.http.spnego.NegotiatorImpl",
	"sun.net.www.protocol.http.Negotiator",
	nullptr,
	_NegotiatorImpl_FieldInfo_,
	_NegotiatorImpl_MethodInfo_
};

$Object* allocate$NegotiatorImpl($Class* clazz) {
	return $of($alloc(NegotiatorImpl));
}

bool NegotiatorImpl::DEBUG = false;

void NegotiatorImpl::init($HttpCallerInfo* hci) {
	$var($Oid, oid, nullptr);
	if ($nc($nc(hci)->scheme)->equalsIgnoreCase("Kerberos"_s)) {
		$init($GSSUtil);
		$assign(oid, $GSSUtil::GSS_KRB5_MECH_OID);
	} else {
		$var($String, pref, $GetPropertyAction::privilegedGetProperty("http.auth.preference"_s, "spnego"_s));
		if ($nc(pref)->equalsIgnoreCase("kerberos"_s)) {
			$init($GSSUtil);
			$assign(oid, $GSSUtil::GSS_KRB5_MECH_OID);
		} else {
			$init($GSSUtil);
			$assign(oid, $GSSUtil::GSS_SPNEGO_MECH_OID);
		}
	}
	$var($GSSManagerImpl, manager, $new($GSSManagerImpl, $$new($HttpCaller, hci)));
	$var($String, peerName, $str({"HTTP@"_s, $($nc($nc(hci)->host)->toLowerCase())}));
	$init($GSSName);
	$var($GSSName, serverName, manager->createName(peerName, $GSSName::NT_HOSTBASED_SERVICE));
	$set(this, context, manager->createContext(serverName, oid, nullptr, $GSSContext::DEFAULT_LIFETIME));
	if ($instanceOf($GSSContextImpl, this->context)) {
		$nc(($cast($GSSContextImpl, this->context)))->requestDelegPolicy(true);
	}
	$set(this, oneToken, $nc(this->context)->initSecContext($$new($bytes, 0), 0, 0));
}

void NegotiatorImpl::init$($HttpCallerInfo* hci) {
	$Negotiator::init$();
	try {
		init(hci);
	} catch ($GSSException&) {
		$var($GSSException, e, $catch());
		if (NegotiatorImpl::DEBUG) {
			$init($System);
			$nc($System::out)->println("Negotiate support not initiated, will fallback to other scheme if allowed. Reason:"_s);
			e->printStackTrace();
		}
		$var($IOException, ioe, $new($IOException, "Negotiate support not initiated"_s));
		ioe->initCause(e);
		$throw(ioe);
	}
}

$bytes* NegotiatorImpl::firstToken() {
	return this->oneToken;
}

$bytes* NegotiatorImpl::nextToken($bytes* token) {
	try {
		return $nc(this->context)->initSecContext(token, 0, $nc(token)->length);
	} catch ($GSSException&) {
		$var($GSSException, e, $catch());
		if (NegotiatorImpl::DEBUG) {
			$init($System);
			$nc($System::out)->println("Negotiate support cannot continue. Reason:"_s);
			e->printStackTrace();
		}
		$var($IOException, ioe, $new($IOException, "Negotiate support cannot continue"_s));
		ioe->initCause(e);
		$throw(ioe);
	}
	$shouldNotReachHere();
}

void clinit$NegotiatorImpl($Class* class$) {
	NegotiatorImpl::DEBUG = $GetBooleanAction::privilegedGetProperty("sun.security.krb5.debug"_s);
}

NegotiatorImpl::NegotiatorImpl() {
}

$Class* NegotiatorImpl::load$($String* name, bool initialize) {
	$loadClass(NegotiatorImpl, name, initialize, &_NegotiatorImpl_ClassInfo_, clinit$NegotiatorImpl, allocate$NegotiatorImpl);
	return class$;
}

$Class* NegotiatorImpl::class$ = nullptr;

					} // spnego
				} // http
			} // protocol
		} // www
	} // net
} // sun