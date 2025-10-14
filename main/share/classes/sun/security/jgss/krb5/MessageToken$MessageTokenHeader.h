#ifndef _sun_security_jgss_krb5_MessageToken$MessageTokenHeader_h_
#define _sun_security_jgss_krb5_MessageToken$MessageTokenHeader_h_
//$ class sun.security.jgss.krb5.MessageToken$MessageTokenHeader
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
				class MessageToken;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class MessageToken$MessageTokenHeader : public ::java::lang::Object {
	$class(MessageToken$MessageTokenHeader, $NO_CLASS_INIT, ::java::lang::Object)
public:
	MessageToken$MessageTokenHeader();
	void init$(::sun::security::jgss::krb5::MessageToken* this$0, int32_t tokenId, bool conf, int32_t qop);
	void init$(::sun::security::jgss::krb5::MessageToken* this$0, ::java::io::InputStream* is, ::org::ietf::jgss::MessageProp* prop);
	void encode(::java::io::OutputStream* os);
	$bytes* getBytes();
	int32_t getSealAlg();
	int32_t getSignAlg();
	int32_t getTokenId();
	::sun::security::jgss::krb5::MessageToken* this$0 = nullptr;
	int32_t tokenId = 0;
	int32_t signAlg = 0;
	int32_t sealAlg = 0;
	$bytes* bytes = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_MessageToken$MessageTokenHeader_h_