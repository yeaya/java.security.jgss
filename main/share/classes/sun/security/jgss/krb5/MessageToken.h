#ifndef _sun_security_jgss_krb5_MessageToken_h_
#define _sun_security_jgss_krb5_MessageToken_h_
//$ class sun.security.jgss.krb5.MessageToken
//$ extends sun.security.jgss.krb5.Krb5Token

#include <java/lang/Array.h>
#include <sun/security/jgss/krb5/Krb5Token.h>

#pragma push_macro("FILLER")
#undef FILLER
#pragma push_macro("SEAL_ALG_ARCFOUR_HMAC")
#undef SEAL_ALG_ARCFOUR_HMAC
#pragma push_macro("SEAL_ALG_DES")
#undef SEAL_ALG_DES
#pragma push_macro("SEAL_ALG_DES3_KD")
#undef SEAL_ALG_DES3_KD
#pragma push_macro("SEAL_ALG_NONE")
#undef SEAL_ALG_NONE
#pragma push_macro("SEAL_ALG_POS")
#undef SEAL_ALG_POS
#pragma push_macro("SGN_ALG_DES_MAC")
#undef SGN_ALG_DES_MAC
#pragma push_macro("SGN_ALG_DES_MAC_MD5")
#undef SGN_ALG_DES_MAC_MD5
#pragma push_macro("SGN_ALG_HMAC_MD5_ARCFOUR")
#undef SGN_ALG_HMAC_MD5_ARCFOUR
#pragma push_macro("SGN_ALG_HMAC_SHA1_DES3_KD")
#undef SGN_ALG_HMAC_SHA1_DES3_KD
#pragma push_macro("SIGN_ALG_POS")
#undef SIGN_ALG_POS
#pragma push_macro("TOKEN_ID_POS")
#undef TOKEN_ID_POS
#pragma push_macro("TOKEN_NO_CKSUM_SIZE")
#undef TOKEN_NO_CKSUM_SIZE

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
			class GSSHeader;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class CipherHelper;
				class Krb5Context;
				class MessageToken$MessageTokenHeader;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class MessageToken : public ::sun::security::jgss::krb5::Krb5Token {
	$class(MessageToken, $NO_CLASS_INIT, ::sun::security::jgss::krb5::Krb5Token)
public:
	MessageToken();
	void init$(int32_t tokenId, ::sun::security::jgss::krb5::Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, ::org::ietf::jgss::MessageProp* prop);
	void init$(int32_t tokenId, ::sun::security::jgss::krb5::Krb5Context* context, ::java::io::InputStream* is, ::org::ietf::jgss::MessageProp* prop);
	void init$(int32_t tokenId, ::sun::security::jgss::krb5::Krb5Context* context);
	virtual void encode(::java::io::OutputStream* os);
	virtual void genSignAndSeqNumber(::org::ietf::jgss::MessageProp* prop, $bytes* optionalHeader, $bytes* data, int32_t offset, int32_t len, $bytes* optionalTrailer);
	$bytes* getChecksum();
	$bytes* getChecksum($bytes* optionalHeader, $bytes* data, int32_t offset, int32_t len, $bytes* optionalTrailer);
	bool getConfState();
	$bytes* getEncSeqNumber();
	::sun::security::jgss::GSSHeader* getGSSHeader();
	virtual int32_t getKrb5TokenSize();
	virtual int32_t getSealAlg(bool confRequested, int32_t qop) {return 0;}
	int32_t getSequenceNumber();
	virtual int32_t getSgnAlg(int32_t qop);
	int32_t getTokenId();
	int32_t getTokenSize();
	static int32_t getTokenSize(::sun::security::jgss::krb5::CipherHelper* ch);
	void init(int32_t tokenId, ::sun::security::jgss::krb5::Krb5Context* context);
	bool verifySignAndSeqNumber($bytes* optionalHeader, $bytes* data, int32_t offset, int32_t len, $bytes* optionalTrailer);
	static const int32_t TOKEN_NO_CKSUM_SIZE = 16;
	static const int32_t FILLER = 0x0000FFFF;
	static const int32_t SGN_ALG_DES_MAC_MD5 = 0;
	static const int32_t SGN_ALG_DES_MAC = 512;
	static const int32_t SGN_ALG_HMAC_SHA1_DES3_KD = 1024;
	static const int32_t SEAL_ALG_NONE = 0x0000FFFF;
	static const int32_t SEAL_ALG_DES = 0;
	static const int32_t SEAL_ALG_DES3_KD = 512;
	static const int32_t SEAL_ALG_ARCFOUR_HMAC = 4096;
	static const int32_t SGN_ALG_HMAC_MD5_ARCFOUR = 4352;
	static const int32_t TOKEN_ID_POS = 0;
	static const int32_t SIGN_ALG_POS = 2;
	static const int32_t SEAL_ALG_POS = 4;
	int32_t seqNumber = 0;
	bool confState = false;
	bool initiator = false;
	int32_t tokenId = 0;
	::sun::security::jgss::GSSHeader* gssHeader = nullptr;
	::sun::security::jgss::krb5::MessageToken$MessageTokenHeader* tokenHeader = nullptr;
	$bytes* checksum = nullptr;
	$bytes* encSeqNumber = nullptr;
	$bytes* seqNumberData = nullptr;
	::sun::security::jgss::krb5::CipherHelper* cipherHelper = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("FILLER")
#pragma pop_macro("SEAL_ALG_ARCFOUR_HMAC")
#pragma pop_macro("SEAL_ALG_DES")
#pragma pop_macro("SEAL_ALG_DES3_KD")
#pragma pop_macro("SEAL_ALG_NONE")
#pragma pop_macro("SEAL_ALG_POS")
#pragma pop_macro("SGN_ALG_DES_MAC")
#pragma pop_macro("SGN_ALG_DES_MAC_MD5")
#pragma pop_macro("SGN_ALG_HMAC_MD5_ARCFOUR")
#pragma pop_macro("SGN_ALG_HMAC_SHA1_DES3_KD")
#pragma pop_macro("SIGN_ALG_POS")
#pragma pop_macro("TOKEN_ID_POS")
#pragma pop_macro("TOKEN_NO_CKSUM_SIZE")

#endif // _sun_security_jgss_krb5_MessageToken_h_