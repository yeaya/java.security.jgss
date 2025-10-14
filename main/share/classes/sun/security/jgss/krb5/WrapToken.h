#ifndef _sun_security_jgss_krb5_WrapToken_h_
#define _sun_security_jgss_krb5_WrapToken_h_
//$ class sun.security.jgss.krb5.WrapToken
//$ extends sun.security.jgss.krb5.MessageToken

#include <java/lang/Array.h>
#include <sun/security/jgss/krb5/MessageToken.h>

#pragma push_macro("CONFOUNDER_SIZE")
#undef CONFOUNDER_SIZE

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

class WrapToken : public ::sun::security::jgss::krb5::MessageToken {
	$class(WrapToken, 0, ::sun::security::jgss::krb5::MessageToken)
public:
	WrapToken();
	void init$(::sun::security::jgss::krb5::Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, ::org::ietf::jgss::MessageProp* prop);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::java::io::InputStream* is, ::org::ietf::jgss::MessageProp* prop);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::org::ietf::jgss::MessageProp* prop, $bytes* dataBytes, int32_t dataOffset, int32_t dataLen);
	virtual void encode(::java::io::OutputStream* os) override;
	virtual $bytes* encode();
	virtual int32_t encode($bytes* outToken, int32_t offset);
	virtual $bytes* getData();
	virtual int32_t getData($bytes* dataBuf, int32_t dataBufOffset);
	void getDataFromBuffer($bytes* dataBuf, int32_t dataBufOffset);
	void getDataFromStream($bytes* dataBuf, int32_t dataBufOffset);
	virtual int32_t getKrb5TokenSize() override;
	$bytes* getPadding(int32_t len);
	virtual int32_t getSealAlg(bool conf, int32_t qop) override;
	static int32_t getSizeLimit(int32_t qop, bool confReq, int32_t maxTokenSize, ::sun::security::jgss::krb5::CipherHelper* ch);
	static const int32_t CONFOUNDER_SIZE = 8;
	static $Array<int8_t, 2>* pads;
	bool readTokenFromInputStream = false;
	::java::io::InputStream* is = nullptr;
	$bytes* tokenBytes = nullptr;
	int32_t tokenOffset = 0;
	int32_t tokenLen = 0;
	$bytes* dataBytes = nullptr;
	int32_t dataOffset = 0;
	int32_t dataLen = 0;
	int32_t dataSize = 0;
	$bytes* confounder = nullptr;
	$bytes* padding = nullptr;
	bool privacy = false;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("CONFOUNDER_SIZE")

#endif // _sun_security_jgss_krb5_WrapToken_h_