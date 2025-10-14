#ifndef _sun_security_jgss_krb5_MessageToken_v2$MessageTokenHeader_h_
#define _sun_security_jgss_krb5_MessageToken_v2$MessageTokenHeader_h_
//$ class sun.security.jgss.krb5.MessageToken_v2$MessageTokenHeader
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class MessageProp;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class MessageToken_v2;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class MessageToken_v2$MessageTokenHeader : public ::java::lang::Object {
	$class(MessageToken_v2$MessageTokenHeader, $NO_CLASS_INIT, ::java::lang::Object)
public:
	MessageToken_v2$MessageTokenHeader();
	void init$(::sun::security::jgss::krb5::MessageToken_v2* this$0, int32_t tokenId, bool conf);
	void init$(::sun::security::jgss::krb5::MessageToken_v2* this$0, ::java::io::InputStream* is, ::org::ietf::jgss::MessageProp* prop, int32_t tokId);
	void encode(::java::io::OutputStream* os);
	$bytes* getBytes();
	int32_t getTokenId();
	::sun::security::jgss::krb5::MessageToken_v2* this$0 = nullptr;
	int32_t tokenId = 0;
	$bytes* bytes = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_MessageToken_v2$MessageTokenHeader_h_