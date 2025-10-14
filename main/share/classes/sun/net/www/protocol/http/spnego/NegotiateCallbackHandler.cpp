#include <sun/net/www/protocol/http/spnego/NegotiateCallbackHandler.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/Authenticator$RequestorType.h>
#include <java/net/Authenticator.h>
#include <java/net/InetAddress.h>
#include <java/net/PasswordAuthentication.h>
#include <java/net/URL.h>
#include <java/util/Arrays.h>
#include <javax/security/auth/callback/Callback.h>
#include <javax/security/auth/callback/NameCallback.h>
#include <javax/security/auth/callback/PasswordCallback.h>
#include <javax/security/auth/callback/UnsupportedCallbackException.h>
#include <sun/net/www/protocol/http/HttpCallerInfo.h>
#include <sun/security/jgss/LoginConfigImpl.h>
#include <jcpp.h>

#undef HTTP_USE_GLOBAL_CREDS

using $CallbackArray = $Array<::javax::security::auth::callback::Callback>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Authenticator = ::java::net::Authenticator;
using $Authenticator$RequestorType = ::java::net::Authenticator$RequestorType;
using $InetAddress = ::java::net::InetAddress;
using $PasswordAuthentication = ::java::net::PasswordAuthentication;
using $URL = ::java::net::URL;
using $Arrays = ::java::util::Arrays;
using $Callback = ::javax::security::auth::callback::Callback;
using $CallbackHandler = ::javax::security::auth::callback::CallbackHandler;
using $NameCallback = ::javax::security::auth::callback::NameCallback;
using $PasswordCallback = ::javax::security::auth::callback::PasswordCallback;
using $UnsupportedCallbackException = ::javax::security::auth::callback::UnsupportedCallbackException;
using $HttpCallerInfo = ::sun::net::www::protocol::http::HttpCallerInfo;
using $LoginConfigImpl = ::sun::security::jgss::LoginConfigImpl;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace http {
					namespace spnego {

$FieldInfo _NegotiateCallbackHandler_FieldInfo_[] = {
	{"username", "Ljava/lang/String;", nullptr, $PRIVATE, $field(NegotiateCallbackHandler, username)},
	{"password", "[C", nullptr, $PRIVATE, $field(NegotiateCallbackHandler, password)},
	{"answered", "Z", nullptr, $PRIVATE, $field(NegotiateCallbackHandler, answered)},
	{"hci", "Lsun/net/www/protocol/http/HttpCallerInfo;", nullptr, $PRIVATE | $FINAL, $field(NegotiateCallbackHandler, hci)},
	{}
};

$MethodInfo _NegotiateCallbackHandler_MethodInfo_[] = {
	{"<init>", "(Lsun/net/www/protocol/http/HttpCallerInfo;)V", nullptr, $PUBLIC, $method(static_cast<void(NegotiateCallbackHandler::*)($HttpCallerInfo*)>(&NegotiateCallbackHandler::init$))},
	{"getAnswer", "()V", nullptr, $PRIVATE, $method(static_cast<void(NegotiateCallbackHandler::*)()>(&NegotiateCallbackHandler::getAnswer))},
	{"handle", "([Ljavax/security/auth/callback/Callback;)V", nullptr, $PUBLIC, nullptr, "javax.security.auth.callback.UnsupportedCallbackException,java.io.IOException"},
	{}
};

$ClassInfo _NegotiateCallbackHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.http.spnego.NegotiateCallbackHandler",
	"java.lang.Object",
	"javax.security.auth.callback.CallbackHandler",
	_NegotiateCallbackHandler_FieldInfo_,
	_NegotiateCallbackHandler_MethodInfo_
};

$Object* allocate$NegotiateCallbackHandler($Class* clazz) {
	return $of($alloc(NegotiateCallbackHandler));
}

void NegotiateCallbackHandler::init$($HttpCallerInfo* hci) {
	$set(this, hci, hci);
}

void NegotiateCallbackHandler::getAnswer() {
	if (!this->answered) {
		this->answered = true;
		$var($Authenticator, auth, nullptr);
		if ($nc(this->hci)->authenticator != nullptr) {
			$assign(auth, $nc(this->hci)->authenticator);
		} else {
			$init($LoginConfigImpl);
			$assign(auth, $LoginConfigImpl::HTTP_USE_GLOBAL_CREDS ? $Authenticator::getDefault() : ($Authenticator*)nullptr);
		}
		if (auth != nullptr) {
			$var($PasswordAuthentication, passAuth, auth->requestPasswordAuthenticationInstance($nc(this->hci)->host, $nc(this->hci)->addr, $nc(this->hci)->port, $nc(this->hci)->protocol, $nc(this->hci)->prompt, $nc(this->hci)->scheme, $nc(this->hci)->url, $nc(this->hci)->authType));
			if (passAuth != nullptr) {
				$set(this, username, passAuth->getUserName());
				$set(this, password, passAuth->getPassword());
			}
		}
	}
}

void NegotiateCallbackHandler::handle($CallbackArray* callbacks) {
	for (int32_t i = 0; i < $nc(callbacks)->length; ++i) {
		$var($Callback, callBack, callbacks->get(i));
		if ($instanceOf($NameCallback, callBack)) {
			getAnswer();
			$nc(($cast($NameCallback, callBack)))->setName(this->username);
		} else if ($instanceOf($PasswordCallback, callBack)) {
			getAnswer();
			$nc(($cast($PasswordCallback, callBack)))->setPassword(this->password);
			if (this->password != nullptr) {
				$Arrays::fill(this->password, u' ');
			}
		} else {
			$throwNew($UnsupportedCallbackException, callBack, "Call back not supported"_s);
		}
	}
}

NegotiateCallbackHandler::NegotiateCallbackHandler() {
}

$Class* NegotiateCallbackHandler::load$($String* name, bool initialize) {
	$loadClass(NegotiateCallbackHandler, name, initialize, &_NegotiateCallbackHandler_ClassInfo_, allocate$NegotiateCallbackHandler);
	return class$;
}

$Class* NegotiateCallbackHandler::class$ = nullptr;

					} // spnego
				} // http
			} // protocol
		} // www
	} // net
} // sun