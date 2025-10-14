#ifndef _sun_security_jgss_krb5_MicToken_v2_h_
#define _sun_security_jgss_krb5_MicToken_v2_h_
//$ class sun.security.jgss.krb5.MicToken_v2
//$ extends sun.security.jgss.krb5.MessageToken_v2

#include <java/lang/Array.h>
#include <sun/security/jgss/krb5/MessageToken_v2.h>

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
				class Krb5Context;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class MicToken_v2 : public ::sun::security::jgss::krb5::MessageToken_v2 {
	$class(MicToken_v2, $NO_CLASS_INIT, ::sun::security::jgss::krb5::MessageToken_v2)
public:
	MicToken_v2();
	void init$(::sun::security::jgss::krb5::Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, ::org::ietf::jgss::MessageProp* prop);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::java::io::InputStream* is, ::org::ietf::jgss::MessageProp* prop);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::org::ietf::jgss::MessageProp* prop, $bytes* data, int32_t pos, int32_t len);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::org::ietf::jgss::MessageProp* prop, ::java::io::InputStream* data);
	virtual $bytes* encode();
	virtual int32_t encode($bytes* outToken, int32_t offset);
	virtual void encode(::java::io::OutputStream* os) override;
	virtual void verify($bytes* data, int32_t offset, int32_t len);
	virtual void verify(::java::io::InputStream* data);
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_MicToken_v2_h_