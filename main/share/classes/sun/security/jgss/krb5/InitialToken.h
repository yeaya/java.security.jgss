#ifndef _sun_security_jgss_krb5_InitialToken_h_
#define _sun_security_jgss_krb5_InitialToken_h_
//$ class sun.security.jgss.krb5.InitialToken
//$ extends sun.security.jgss.krb5.Krb5Token

#include <java/lang/Array.h>
#include <sun/security/jgss/krb5/Krb5Token.h>

#pragma push_macro("CHANNEL_BINDING_AF_INET")
#undef CHANNEL_BINDING_AF_INET
#pragma push_macro("CHANNEL_BINDING_AF_INET6")
#undef CHANNEL_BINDING_AF_INET6
#pragma push_macro("CHANNEL_BINDING_AF_NULL_ADDR")
#undef CHANNEL_BINDING_AF_NULL_ADDR
#pragma push_macro("CHANNEL_BINDING_AF_UNSPEC")
#undef CHANNEL_BINDING_AF_UNSPEC
#pragma push_macro("CHECKSUM_BINDINGS_SIZE")
#undef CHECKSUM_BINDINGS_SIZE
#pragma push_macro("CHECKSUM_CONF_FLAG")
#undef CHECKSUM_CONF_FLAG
#pragma push_macro("CHECKSUM_DELEG_FLAG")
#undef CHECKSUM_DELEG_FLAG
#pragma push_macro("CHECKSUM_DELEG_LGTH_SIZE")
#undef CHECKSUM_DELEG_LGTH_SIZE
#pragma push_macro("CHECKSUM_DELEG_OPT_SIZE")
#undef CHECKSUM_DELEG_OPT_SIZE
#pragma push_macro("CHECKSUM_FIRST_BYTES")
#undef CHECKSUM_FIRST_BYTES
#pragma push_macro("CHECKSUM_FLAGS_SIZE")
#undef CHECKSUM_FLAGS_SIZE
#pragma push_macro("CHECKSUM_INTEG_FLAG")
#undef CHECKSUM_INTEG_FLAG
#pragma push_macro("CHECKSUM_LENGTH_SIZE")
#undef CHECKSUM_LENGTH_SIZE
#pragma push_macro("CHECKSUM_MUTUAL_FLAG")
#undef CHECKSUM_MUTUAL_FLAG
#pragma push_macro("CHECKSUM_REPLAY_FLAG")
#undef CHECKSUM_REPLAY_FLAG
#pragma push_macro("CHECKSUM_SEQUENCE_FLAG")
#undef CHECKSUM_SEQUENCE_FLAG
#pragma push_macro("CHECKSUM_TYPE")
#undef CHECKSUM_TYPE

namespace java {
	namespace net {
		class InetAddress;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class ChannelBinding;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class InitialToken : public ::sun::security::jgss::krb5::Krb5Token {
	$class(InitialToken, $NO_CLASS_INIT, ::sun::security::jgss::krb5::Krb5Token)
public:
	InitialToken();
	void init$();
	$bytes* computeChannelBinding(::org::ietf::jgss::ChannelBinding* channelBinding);
	virtual $bytes* encode() {return nullptr;}
	$bytes* getAddrBytes(::java::net::InetAddress* addr);
	int32_t getAddrType(::java::net::InetAddress* addr, int32_t defValue);
	static const int32_t CHECKSUM_TYPE = 0x00008003;
	static const int32_t CHECKSUM_LENGTH_SIZE = 4;
	static const int32_t CHECKSUM_BINDINGS_SIZE = 16;
	static const int32_t CHECKSUM_FLAGS_SIZE = 4;
	static const int32_t CHECKSUM_DELEG_OPT_SIZE = 2;
	static const int32_t CHECKSUM_DELEG_LGTH_SIZE = 2;
	static const int32_t CHECKSUM_DELEG_FLAG = 1;
	static const int32_t CHECKSUM_MUTUAL_FLAG = 2;
	static const int32_t CHECKSUM_REPLAY_FLAG = 4;
	static const int32_t CHECKSUM_SEQUENCE_FLAG = 8;
	static const int32_t CHECKSUM_CONF_FLAG = 16;
	static const int32_t CHECKSUM_INTEG_FLAG = 32;
	$bytes* CHECKSUM_FIRST_BYTES = nullptr;
	static const int32_t CHANNEL_BINDING_AF_UNSPEC = 0;
	static const int32_t CHANNEL_BINDING_AF_INET = 2;
	static const int32_t CHANNEL_BINDING_AF_INET6 = 24;
	static const int32_t CHANNEL_BINDING_AF_NULL_ADDR = 255;
	static const int32_t Inet4_ADDRSZ = 4;
	static const int32_t Inet6_ADDRSZ = 16;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("CHANNEL_BINDING_AF_INET")
#pragma pop_macro("CHANNEL_BINDING_AF_INET6")
#pragma pop_macro("CHANNEL_BINDING_AF_NULL_ADDR")
#pragma pop_macro("CHANNEL_BINDING_AF_UNSPEC")
#pragma pop_macro("CHECKSUM_BINDINGS_SIZE")
#pragma pop_macro("CHECKSUM_CONF_FLAG")
#pragma pop_macro("CHECKSUM_DELEG_FLAG")
#pragma pop_macro("CHECKSUM_DELEG_LGTH_SIZE")
#pragma pop_macro("CHECKSUM_DELEG_OPT_SIZE")
#pragma pop_macro("CHECKSUM_FIRST_BYTES")
#pragma pop_macro("CHECKSUM_FLAGS_SIZE")
#pragma pop_macro("CHECKSUM_INTEG_FLAG")
#pragma pop_macro("CHECKSUM_LENGTH_SIZE")
#pragma pop_macro("CHECKSUM_MUTUAL_FLAG")
#pragma pop_macro("CHECKSUM_REPLAY_FLAG")
#pragma pop_macro("CHECKSUM_SEQUENCE_FLAG")
#pragma pop_macro("CHECKSUM_TYPE")

#endif // _sun_security_jgss_krb5_InitialToken_h_