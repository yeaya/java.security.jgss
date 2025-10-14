#ifndef _sun_net_www_protocol_http_spnego_NegotiateCallbackHandler_h_
#define _sun_net_www_protocol_http_spnego_NegotiateCallbackHandler_h_
//$ class sun.net.www.protocol.http.spnego.NegotiateCallbackHandler
//$ extends javax.security.auth.callback.CallbackHandler

#include <java/lang/Array.h>
#include <javax/security/auth/callback/CallbackHandler.h>

namespace javax {
	namespace security {
		namespace auth {
			namespace callback {
				class Callback;
			}
		}
	}
}
namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace http {
					class HttpCallerInfo;
				}
			}
		}
	}
}

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace http {
					namespace spnego {

class NegotiateCallbackHandler : public ::javax::security::auth::callback::CallbackHandler {
	$class(NegotiateCallbackHandler, $NO_CLASS_INIT, ::javax::security::auth::callback::CallbackHandler)
public:
	NegotiateCallbackHandler();
	void init$(::sun::net::www::protocol::http::HttpCallerInfo* hci);
	void getAnswer();
	virtual void handle($Array<::javax::security::auth::callback::Callback>* callbacks) override;
	$String* username = nullptr;
	$chars* password = nullptr;
	bool answered = false;
	::sun::net::www::protocol::http::HttpCallerInfo* hci = nullptr;
};

					} // spnego
				} // http
			} // protocol
		} // www
	} // net
} // sun

#endif // _sun_net_www_protocol_http_spnego_NegotiateCallbackHandler_h_