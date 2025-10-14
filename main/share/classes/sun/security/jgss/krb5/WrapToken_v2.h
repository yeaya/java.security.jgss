#ifndef _sun_security_jgss_krb5_WrapToken_v2_h_
#define _sun_security_jgss_krb5_WrapToken_v2_h_
//$ class sun.security.jgss.krb5.WrapToken_v2
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
				class CipherHelper;
				class Krb5Context;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class WrapToken_v2 : public ::sun::security::jgss::krb5::MessageToken_v2 {
	$class(WrapToken_v2, $NO_CLASS_INIT, ::sun::security::jgss::krb5::MessageToken_v2)
public:
	WrapToken_v2();
	void init$(::sun::security::jgss::krb5::Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, ::org::ietf::jgss::MessageProp* prop);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::java::io::InputStream* is, ::org::ietf::jgss::MessageProp* prop);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::org::ietf::jgss::MessageProp* prop, $bytes* dataBytes, int32_t dataOffset, int32_t dataLen);
	virtual void encode(::java::io::OutputStream* os) override;
	virtual $bytes* encode();
	virtual int32_t encode($bytes* outToken, int32_t offset);
	virtual $bytes* getData();
	virtual int32_t getData($bytes* dataBuf, int32_t dataBufOffset);
	static int32_t getSizeLimit(int32_t qop, bool confReq, int32_t maxTokenSize, ::sun::security::jgss::krb5::CipherHelper* ch);
	$bytes* confounder = nullptr;
	bool privacy = false;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_WrapToken_v2_h_