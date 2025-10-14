#ifndef _sun_net_www_protocol_http_spnego_NegotiatorImpl_h_
#define _sun_net_www_protocol_http_spnego_NegotiatorImpl_h_
//$ class sun.net.www.protocol.http.spnego.NegotiatorImpl
//$ extends sun.net.www.protocol.http.Negotiator

#include <java/lang/Array.h>
#include <sun/net/www/protocol/http/Negotiator.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace org {
	namespace ietf {
		namespace jgss {
			class GSSContext;
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

class NegotiatorImpl : public ::sun::net::www::protocol::http::Negotiator {
	$class(NegotiatorImpl, 0, ::sun::net::www::protocol::http::Negotiator)
public:
	NegotiatorImpl();
	void init$(::sun::net::www::protocol::http::HttpCallerInfo* hci);
	virtual $bytes* firstToken() override;
	void init(::sun::net::www::protocol::http::HttpCallerInfo* hci);
	virtual $bytes* nextToken($bytes* token) override;
	static bool DEBUG;
	::org::ietf::jgss::GSSContext* context = nullptr;
	$bytes* oneToken = nullptr;
};

					} // spnego
				} // http
			} // protocol
		} // www
	} // net
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_net_www_protocol_http_spnego_NegotiatorImpl_h_