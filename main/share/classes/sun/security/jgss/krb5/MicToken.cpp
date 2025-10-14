#include <sun/security/jgss/krb5/MicToken.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/MessageProp.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/krb5/MessageToken.h>
#include <jcpp.h>

#undef BAD_MIC
#undef MIC_ID
#undef SEAL_ALG_NONE

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSException = ::org::ietf::jgss::GSSException;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;
using $Krb5Token = ::sun::security::jgss::krb5::Krb5Token;
using $MessageToken = ::sun::security::jgss::krb5::MessageToken;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$MethodInfo _MicToken_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;[BIILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, $method(static_cast<void(MicToken::*)($Krb5Context*,$bytes*,int32_t,int32_t,$MessageProp*)>(&MicToken::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, $method(static_cast<void(MicToken::*)($Krb5Context*,$InputStream*,$MessageProp*)>(&MicToken::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Lorg/ietf/jgss/MessageProp;[BII)V", nullptr, $PUBLIC, $method(static_cast<void(MicToken::*)($Krb5Context*,$MessageProp*,$bytes*,int32_t,int32_t)>(&MicToken::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Lorg/ietf/jgss/MessageProp;Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(MicToken::*)($Krb5Context*,$MessageProp*,$InputStream*)>(&MicToken::init$)), "org.ietf.jgss.GSSException,java.io.IOException"},
	{"encode", "([BI)I", nullptr, $PUBLIC, nullptr, "java.io.IOException,org.ietf.jgss.GSSException"},
	{"encode", "()[B", nullptr, $PUBLIC, nullptr, "java.io.IOException,org.ietf.jgss.GSSException"},
	{"getSealAlg", "(ZI)I", nullptr, $PROTECTED},
	{"verify", "([BII)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"verify", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _MicToken_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.MicToken",
	"sun.security.jgss.krb5.MessageToken",
	nullptr,
	nullptr,
	_MicToken_MethodInfo_
};

$Object* allocate$MicToken($Class* clazz) {
	return $of($alloc(MicToken));
}

void MicToken::init$($Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, $MessageProp* prop) {
	$MessageToken::init$($Krb5Token::MIC_ID, context, tokenBytes, tokenOffset, tokenLen, prop);
}

void MicToken::init$($Krb5Context* context, $InputStream* is, $MessageProp* prop) {
	$MessageToken::init$($Krb5Token::MIC_ID, context, is, prop);
}

void MicToken::verify($bytes* data, int32_t offset, int32_t len) {
	if (!verifySignAndSeqNumber(nullptr, data, offset, len, nullptr)) {
		$throwNew($GSSException, $GSSException::BAD_MIC, -1, "Corrupt checksum or sequence number in MIC token"_s);
	}
}

void MicToken::verify($InputStream* data) {
	$var($bytes, dataBytes, nullptr);
	try {
		$assign(dataBytes, $new($bytes, $nc(data)->available()));
		data->read(dataBytes);
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSException, $GSSException::BAD_MIC, -1, "Corrupt checksum or sequence number in MIC token"_s);
	}
	verify(dataBytes, 0, $nc(dataBytes)->length);
}

void MicToken::init$($Krb5Context* context, $MessageProp* prop$renamed, $bytes* data, int32_t pos, int32_t len) {
	$var($MessageProp, prop, prop$renamed);
	$MessageToken::init$($Krb5Token::MIC_ID, context);
	if (prop == nullptr) {
		$assign(prop, $new($MessageProp, 0, false));
	}
	genSignAndSeqNumber(prop, nullptr, data, pos, len, nullptr);
}

void MicToken::init$($Krb5Context* context, $MessageProp* prop$renamed, $InputStream* data) {
	$var($MessageProp, prop, prop$renamed);
	$MessageToken::init$($Krb5Token::MIC_ID, context);
	$var($bytes, dataBytes, $new($bytes, $nc(data)->available()));
	data->read(dataBytes);
	if (prop == nullptr) {
		$assign(prop, $new($MessageProp, 0, false));
	}
	genSignAndSeqNumber(prop, nullptr, dataBytes, 0, dataBytes->length, nullptr);
}

int32_t MicToken::getSealAlg(bool confRequested, int32_t qop) {
	return ($MessageToken::SEAL_ALG_NONE);
}

int32_t MicToken::encode($bytes* outToken, int32_t offset) {
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream));
	$MessageToken::encode(bos);
	$var($bytes, token, bos->toByteArray());
	$System::arraycopy(token, 0, outToken, offset, $nc(token)->length);
	return $nc(token)->length;
}

$bytes* MicToken::encode() {
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream, 50));
	encode(bos);
	return bos->toByteArray();
}

MicToken::MicToken() {
}

$Class* MicToken::load$($String* name, bool initialize) {
	$loadClass(MicToken, name, initialize, &_MicToken_ClassInfo_, allocate$MicToken);
	return class$;
}

$Class* MicToken::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun