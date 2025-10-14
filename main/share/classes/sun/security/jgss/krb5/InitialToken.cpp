#include <sun/security/jgss/krb5/InitialToken.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/Inet4Address.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/GSSException.h>
#include <sun/security/jgss/GSSToken.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/krb5/internal/TlsChannelBindingImpl.h>
#include <jcpp.h>

#undef CHANNEL_BINDING_AF_INET
#undef CHANNEL_BINDING_AF_INET6
#undef CHANNEL_BINDING_AF_NULL_ADDR
#undef CHANNEL_BINDING_AF_UNSPEC
#undef CHECKSUM_BINDINGS_SIZE
#undef CHECKSUM_CONF_FLAG
#undef CHECKSUM_DELEG_FLAG
#undef CHECKSUM_DELEG_LGTH_SIZE
#undef CHECKSUM_DELEG_OPT_SIZE
#undef CHECKSUM_FIRST_BYTES
#undef CHECKSUM_FLAGS_SIZE
#undef CHECKSUM_INTEG_FLAG
#undef CHECKSUM_LENGTH_SIZE
#undef CHECKSUM_MUTUAL_FLAG
#undef CHECKSUM_REPLAY_FLAG
#undef CHECKSUM_SEQUENCE_FLAG
#undef CHECKSUM_TYPE
#undef FAILURE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Inet4Address = ::java::net::Inet4Address;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $Krb5Token = ::sun::security::jgss::krb5::Krb5Token;
using $TlsChannelBindingImpl = ::sun::security::jgss::krb5::internal::TlsChannelBindingImpl;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _InitialToken_FieldInfo_[] = {
	{"CHECKSUM_TYPE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_TYPE)},
	{"CHECKSUM_LENGTH_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_LENGTH_SIZE)},
	{"CHECKSUM_BINDINGS_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_BINDINGS_SIZE)},
	{"CHECKSUM_FLAGS_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_FLAGS_SIZE)},
	{"CHECKSUM_DELEG_OPT_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_DELEG_OPT_SIZE)},
	{"CHECKSUM_DELEG_LGTH_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_DELEG_LGTH_SIZE)},
	{"CHECKSUM_DELEG_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_DELEG_FLAG)},
	{"CHECKSUM_MUTUAL_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_MUTUAL_FLAG)},
	{"CHECKSUM_REPLAY_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_REPLAY_FLAG)},
	{"CHECKSUM_SEQUENCE_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_SEQUENCE_FLAG)},
	{"CHECKSUM_CONF_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_CONF_FLAG)},
	{"CHECKSUM_INTEG_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHECKSUM_INTEG_FLAG)},
	{"CHECKSUM_FIRST_BYTES", "[B", nullptr, $PRIVATE | $FINAL, $field(InitialToken, CHECKSUM_FIRST_BYTES)},
	{"CHANNEL_BINDING_AF_UNSPEC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHANNEL_BINDING_AF_UNSPEC)},
	{"CHANNEL_BINDING_AF_INET", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHANNEL_BINDING_AF_INET)},
	{"CHANNEL_BINDING_AF_INET6", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHANNEL_BINDING_AF_INET6)},
	{"CHANNEL_BINDING_AF_NULL_ADDR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, CHANNEL_BINDING_AF_NULL_ADDR)},
	{"Inet4_ADDRSZ", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, Inet4_ADDRSZ)},
	{"Inet6_ADDRSZ", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InitialToken, Inet6_ADDRSZ)},
	{}
};

$MethodInfo _InitialToken_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(InitialToken::*)()>(&InitialToken::init$))},
	{"computeChannelBinding", "(Lorg/ietf/jgss/ChannelBinding;)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(InitialToken::*)($ChannelBinding*)>(&InitialToken::computeChannelBinding)), "org.ietf.jgss.GSSException"},
	{"encode", "()[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"getAddrBytes", "(Ljava/net/InetAddress;)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(InitialToken::*)($InetAddress*)>(&InitialToken::getAddrBytes)), "org.ietf.jgss.GSSException"},
	{"getAddrType", "(Ljava/net/InetAddress;I)I", nullptr, $PRIVATE, $method(static_cast<int32_t(InitialToken::*)($InetAddress*,int32_t)>(&InitialToken::getAddrType))},
	{}
};

$InnerClassInfo _InitialToken_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.InitialToken$OverloadedChecksum", "sun.security.jgss.krb5.InitialToken", "OverloadedChecksum", $PROTECTED},
	{}
};

$ClassInfo _InitialToken_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.jgss.krb5.InitialToken",
	"sun.security.jgss.krb5.Krb5Token",
	nullptr,
	_InitialToken_FieldInfo_,
	_InitialToken_MethodInfo_,
	nullptr,
	nullptr,
	_InitialToken_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.InitialToken$OverloadedChecksum"
};

$Object* allocate$InitialToken($Class* clazz) {
	return $of($alloc(InitialToken));
}

void InitialToken::init$() {
	$Krb5Token::init$();
	$set(this, CHECKSUM_FIRST_BYTES, $new($bytes, {
		(int8_t)16,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0
	}));
}

int32_t InitialToken::getAddrType($InetAddress* addr, int32_t defValue) {
	int32_t addressType = defValue;
	if ($instanceOf($Inet4Address, addr)) {
		addressType = InitialToken::CHANNEL_BINDING_AF_INET;
	} else if ($instanceOf($Inet6Address, addr)) {
		addressType = InitialToken::CHANNEL_BINDING_AF_INET6;
	}
	return (addressType);
}

$bytes* InitialToken::getAddrBytes($InetAddress* addr) {
	int32_t addressType = getAddrType(addr, InitialToken::CHANNEL_BINDING_AF_NULL_ADDR);
	$var($bytes, addressBytes, $nc(addr)->getAddress());
	if (addressBytes != nullptr) {
		switch (addressType) {
		case InitialToken::CHANNEL_BINDING_AF_INET:
			{
				if (addressBytes->length != InitialToken::Inet4_ADDRSZ) {
					$throwNew($GSSException, $GSSException::FAILURE, -1, "Incorrect AF-INET address length in ChannelBinding."_s);
				}
				return (addressBytes);
			}
		case InitialToken::CHANNEL_BINDING_AF_INET6:
			{
				if (addressBytes->length != InitialToken::Inet6_ADDRSZ) {
					$throwNew($GSSException, $GSSException::FAILURE, -1, "Incorrect AF-INET6 address length in ChannelBinding."_s);
				}
				return (addressBytes);
			}
		default:
			{
				$throwNew($GSSException, $GSSException::FAILURE, -1, "Cannot handle non AF-INET addresses in ChannelBinding."_s);
			}
		}
	}
	return nullptr;
}

$bytes* InitialToken::computeChannelBinding($ChannelBinding* channelBinding) {
	$var($InetAddress, initiatorAddress, $nc(channelBinding)->getInitiatorAddress());
	$var($InetAddress, acceptorAddress, channelBinding->getAcceptorAddress());
	int32_t size = 5 * 4;
	int32_t initiatorAddressType = getAddrType(initiatorAddress, ($instanceOf($TlsChannelBindingImpl, channelBinding)) ? InitialToken::CHANNEL_BINDING_AF_UNSPEC : InitialToken::CHANNEL_BINDING_AF_NULL_ADDR);
	int32_t acceptorAddressType = getAddrType(acceptorAddress, ($instanceOf($TlsChannelBindingImpl, channelBinding)) ? InitialToken::CHANNEL_BINDING_AF_UNSPEC : InitialToken::CHANNEL_BINDING_AF_NULL_ADDR);
	$var($bytes, initiatorAddressBytes, nullptr);
	if (initiatorAddress != nullptr) {
		$assign(initiatorAddressBytes, getAddrBytes(initiatorAddress));
		size += $nc(initiatorAddressBytes)->length;
	}
	$var($bytes, acceptorAddressBytes, nullptr);
	if (acceptorAddress != nullptr) {
		$assign(acceptorAddressBytes, getAddrBytes(acceptorAddress));
		size += $nc(acceptorAddressBytes)->length;
	}
	$var($bytes, appDataBytes, channelBinding->getApplicationData());
	if (appDataBytes != nullptr) {
		size += appDataBytes->length;
	}
	$var($bytes, data, $new($bytes, size));
	int32_t pos = 0;
	writeLittleEndian(initiatorAddressType, data, pos);
	pos += 4;
	if (initiatorAddressBytes != nullptr) {
		writeLittleEndian(initiatorAddressBytes->length, data, pos);
		pos += 4;
		$System::arraycopy(initiatorAddressBytes, 0, data, pos, initiatorAddressBytes->length);
		pos += initiatorAddressBytes->length;
	} else {
		pos += 4;
	}
	writeLittleEndian(acceptorAddressType, data, pos);
	pos += 4;
	if (acceptorAddressBytes != nullptr) {
		writeLittleEndian(acceptorAddressBytes->length, data, pos);
		pos += 4;
		$System::arraycopy(acceptorAddressBytes, 0, data, pos, acceptorAddressBytes->length);
		pos += acceptorAddressBytes->length;
	} else {
		pos += 4;
	}
	if (appDataBytes != nullptr) {
		writeLittleEndian(appDataBytes->length, data, pos);
		pos += 4;
		$System::arraycopy(appDataBytes, 0, data, pos, appDataBytes->length);
		pos += appDataBytes->length;
	} else {
		pos += 4;
	}
	try {
		$var($MessageDigest, md5, $MessageDigest::getInstance("MD5"_s));
		return $nc(md5)->digest(data);
	} catch ($NoSuchAlgorithmException&) {
		$var($NoSuchAlgorithmException, e, $catch());
		$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Could not get MD5 Message Digest - "_s, $(e->getMessage())}));
	}
	$shouldNotReachHere();
}

InitialToken::InitialToken() {
}

$Class* InitialToken::load$($String* name, bool initialize) {
	$loadClass(InitialToken, name, initialize, &_InitialToken_ClassInfo_, allocate$InitialToken);
	return class$;
}

$Class* InitialToken::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun