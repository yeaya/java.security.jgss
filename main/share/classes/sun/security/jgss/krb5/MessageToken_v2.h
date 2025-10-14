#ifndef _sun_security_jgss_krb5_MessageToken_v2_h_
#define _sun_security_jgss_krb5_MessageToken_v2_h_
//$ class sun.security.jgss.krb5.MessageToken_v2
//$ extends sun.security.jgss.krb5.Krb5Token

#include <java/lang/Array.h>
#include <sun/security/jgss/krb5/Krb5Token.h>

#pragma push_macro("CONFOUNDER_SIZE")
#undef CONFOUNDER_SIZE
#pragma push_macro("FILLER")
#undef FILLER
#pragma push_macro("FLAG_ACCEPTOR_SUBKEY")
#undef FLAG_ACCEPTOR_SUBKEY
#pragma push_macro("FLAG_SENDER_IS_ACCEPTOR")
#undef FLAG_SENDER_IS_ACCEPTOR
#pragma push_macro("FLAG_WRAP_CONFIDENTIAL")
#undef FLAG_WRAP_CONFIDENTIAL
#pragma push_macro("KG_USAGE_ACCEPTOR_SEAL")
#undef KG_USAGE_ACCEPTOR_SEAL
#pragma push_macro("KG_USAGE_ACCEPTOR_SIGN")
#undef KG_USAGE_ACCEPTOR_SIGN
#pragma push_macro("KG_USAGE_INITIATOR_SEAL")
#undef KG_USAGE_INITIATOR_SEAL
#pragma push_macro("KG_USAGE_INITIATOR_SIGN")
#undef KG_USAGE_INITIATOR_SIGN
#pragma push_macro("TOKEN_EC_POS")
#undef TOKEN_EC_POS
#pragma push_macro("TOKEN_FLAG_POS")
#undef TOKEN_FLAG_POS
#pragma push_macro("TOKEN_HEADER_SIZE")
#undef TOKEN_HEADER_SIZE
#pragma push_macro("TOKEN_ID_POS")
#undef TOKEN_ID_POS
#pragma push_macro("TOKEN_RRC_POS")
#undef TOKEN_RRC_POS

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
				class MessageToken_v2$MessageTokenHeader;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class MessageToken_v2 : public ::sun::security::jgss::krb5::Krb5Token {
	$class(MessageToken_v2, $NO_CLASS_INIT, ::sun::security::jgss::krb5::Krb5Token)
public:
	MessageToken_v2();
	void init$(int32_t tokenId, ::sun::security::jgss::krb5::Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, ::org::ietf::jgss::MessageProp* prop);
	void init$(int32_t tokenId, ::sun::security::jgss::krb5::Krb5Context* context, ::java::io::InputStream* is, ::org::ietf::jgss::MessageProp* prop);
	void init$(int32_t tokenId, ::sun::security::jgss::krb5::Krb5Context* context);
	virtual void encode(::java::io::OutputStream* os) {}
	virtual void encodeHeader(::java::io::OutputStream* os);
	virtual void genSignAndSeqNumber(::org::ietf::jgss::MessageProp* prop, $bytes* data, int32_t offset, int32_t len);
	virtual $bytes* getChecksum($bytes* data, int32_t offset, int32_t len);
	bool getConfState();
	int32_t getKeyUsage();
	int32_t getSequenceNumber();
	$bytes* getTokenHeader();
	int32_t getTokenId();
	void init(int32_t tokenId, ::sun::security::jgss::krb5::Krb5Context* context);
	void rotate();
	bool verifySign($bytes* data, int32_t offset, int32_t len);
	static const int32_t TOKEN_HEADER_SIZE = 16;
	static const int32_t TOKEN_ID_POS = 0;
	static const int32_t TOKEN_FLAG_POS = 2;
	static const int32_t TOKEN_EC_POS = 4;
	static const int32_t TOKEN_RRC_POS = 6;
	static const int32_t CONFOUNDER_SIZE = 16;
	static const int32_t KG_USAGE_ACCEPTOR_SEAL = 22;
	static const int32_t KG_USAGE_ACCEPTOR_SIGN = 23;
	static const int32_t KG_USAGE_INITIATOR_SEAL = 24;
	static const int32_t KG_USAGE_INITIATOR_SIGN = 25;
	static const int32_t FLAG_SENDER_IS_ACCEPTOR = 1;
	static const int32_t FLAG_WRAP_CONFIDENTIAL = 2;
	static const int32_t FLAG_ACCEPTOR_SUBKEY = 4;
	static const int32_t FILLER = 255;
	::sun::security::jgss::krb5::MessageToken_v2$MessageTokenHeader* tokenHeader = nullptr;
	int32_t tokenId = 0;
	int32_t seqNumber = 0;
	$bytes* tokenData = nullptr;
	int32_t tokenDataLen = 0;
	int32_t key_usage = 0;
	int32_t ec = 0;
	int32_t rrc = 0;
	$bytes* checksum = nullptr;
	bool confState = false;
	bool initiator = false;
	bool have_acceptor_subkey = false;
	::sun::security::jgss::krb5::CipherHelper* cipherHelper = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("CONFOUNDER_SIZE")
#pragma pop_macro("FILLER")
#pragma pop_macro("FLAG_ACCEPTOR_SUBKEY")
#pragma pop_macro("FLAG_SENDER_IS_ACCEPTOR")
#pragma pop_macro("FLAG_WRAP_CONFIDENTIAL")
#pragma pop_macro("KG_USAGE_ACCEPTOR_SEAL")
#pragma pop_macro("KG_USAGE_ACCEPTOR_SIGN")
#pragma pop_macro("KG_USAGE_INITIATOR_SEAL")
#pragma pop_macro("KG_USAGE_INITIATOR_SIGN")
#pragma pop_macro("TOKEN_EC_POS")
#pragma pop_macro("TOKEN_FLAG_POS")
#pragma pop_macro("TOKEN_HEADER_SIZE")
#pragma pop_macro("TOKEN_ID_POS")
#pragma pop_macro("TOKEN_RRC_POS")

#endif // _sun_security_jgss_krb5_MessageToken_v2_h_