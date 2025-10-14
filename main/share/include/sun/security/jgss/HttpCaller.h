#ifndef _sun_security_jgss_HttpCaller_h_
#define _sun_security_jgss_HttpCaller_h_
//$ class sun.security.jgss.HttpCaller
//$ extends sun.security.jgss.GSSCaller

#include <sun/security/jgss/GSSCaller.h>

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
	namespace security {
		namespace jgss {

class $import HttpCaller : public ::sun::security::jgss::GSSCaller {
	$class(HttpCaller, $NO_CLASS_INIT, ::sun::security::jgss::GSSCaller)
public:
	HttpCaller();
	void init$(::sun::net::www::protocol::http::HttpCallerInfo* hci);
	virtual ::sun::net::www::protocol::http::HttpCallerInfo* info();
	::sun::net::www::protocol::http::HttpCallerInfo* hci = nullptr;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_HttpCaller_h_