#ifndef _sun_security_jgss_krb5_MicToken_h_
#define _sun_security_jgss_krb5_MicToken_h_
//$ class sun.security.jgss.krb5.MicToken
//$ extends sun.security.jgss.krb5.MessageToken

#include <java/lang/Array.h>
#include <sun/security/jgss/krb5/MessageToken.h>

namespace java {
	namespace io {
		class InputStream;
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
				class Krb5Context;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class MicToken : public ::sun::security::jgss::krb5::MessageToken {
	$class(MicToken, $NO_CLASS_INIT, ::sun::security::jgss::krb5::MessageToken)
public:
	MicToken();
	using ::sun::security::jgss::krb5::MessageToken::encode;
	void init$(::sun::security::jgss::krb5::Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, ::org::ietf::jgss::MessageProp* prop);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::java::io::InputStream* is, ::org::ietf::jgss::MessageProp* prop);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::org::ietf::jgss::MessageProp* prop, $bytes* data, int32_t pos, int32_t len);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::org::ietf::jgss::MessageProp* prop, ::java::io::InputStream* data);
	virtual int32_t encode($bytes* outToken, int32_t offset);
	virtual $bytes* encode();
	virtual int32_t getSealAlg(bool confRequested, int32_t qop) override;
	virtual void verify($bytes* data, int32_t offset, int32_t len);
	virtual void verify(::java::io::InputStream* data);
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_MicToken_h_