#include <sun/security/jgss/krb5/MicToken_v2.h>

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
#include <sun/security/jgss/krb5/MessageToken_v2.h>
#include <jcpp.h>

#undef BAD_MIC

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
using $MessageToken_v2 = ::sun::security::jgss::krb5::MessageToken_v2;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$MethodInfo _MicToken_v2_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;[BIILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, $method(static_cast<void(MicToken_v2::*)($Krb5Context*,$bytes*,int32_t,int32_t,$MessageProp*)>(&MicToken_v2::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, $method(static_cast<void(MicToken_v2::*)($Krb5Context*,$InputStream*,$MessageProp*)>(&MicToken_v2::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Lorg/ietf/jgss/MessageProp;[BII)V", nullptr, $PUBLIC, $method(static_cast<void(MicToken_v2::*)($Krb5Context*,$MessageProp*,$bytes*,int32_t,int32_t)>(&MicToken_v2::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Lorg/ietf/jgss/MessageProp;Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(MicToken_v2::*)($Krb5Context*,$MessageProp*,$InputStream*)>(&MicToken_v2::init$)), "org.ietf.jgss.GSSException,java.io.IOException"},
	{"encode", "()[B", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"encode", "([BI)I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"verify", "([BII)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"verify", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _MicToken_v2_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.MicToken_v2",
	"sun.security.jgss.krb5.MessageToken_v2",
	nullptr,
	nullptr,
	_MicToken_v2_MethodInfo_
};

$Object* allocate$MicToken_v2($Class* clazz) {
	return $of($alloc(MicToken_v2));
}

void MicToken_v2::init$($Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, $MessageProp* prop) {
	$MessageToken_v2::init$($Krb5Token::MIC_ID_v2, context, tokenBytes, tokenOffset, tokenLen, prop);
}

void MicToken_v2::init$($Krb5Context* context, $InputStream* is, $MessageProp* prop) {
	$MessageToken_v2::init$($Krb5Token::MIC_ID_v2, context, is, prop);
}

void MicToken_v2::verify($bytes* data, int32_t offset, int32_t len) {
	if (!verifySign(data, offset, len)) {
		$throwNew($GSSException, $GSSException::BAD_MIC, -1, "Corrupt checksum or sequence number in MIC token"_s);
	}
}

void MicToken_v2::verify($InputStream* data) {
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

void MicToken_v2::init$($Krb5Context* context, $MessageProp* prop$renamed, $bytes* data, int32_t pos, int32_t len) {
	$var($MessageProp, prop, prop$renamed);
	$MessageToken_v2::init$($Krb5Token::MIC_ID_v2, context);
	if (prop == nullptr) {
		$assign(prop, $new($MessageProp, 0, false));
	}
	genSignAndSeqNumber(prop, data, pos, len);
}

void MicToken_v2::init$($Krb5Context* context, $MessageProp* prop$renamed, $InputStream* data) {
	$var($MessageProp, prop, prop$renamed);
	$MessageToken_v2::init$($Krb5Token::MIC_ID_v2, context);
	$var($bytes, dataBytes, $new($bytes, $nc(data)->available()));
	data->read(dataBytes);
	if (prop == nullptr) {
		$assign(prop, $new($MessageProp, 0, false));
	}
	genSignAndSeqNumber(prop, dataBytes, 0, dataBytes->length);
}

$bytes* MicToken_v2::encode() {
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream, 50));
	encode(bos);
	return bos->toByteArray();
}

int32_t MicToken_v2::encode($bytes* outToken, int32_t offset) {
	$var($bytes, token, encode());
	$System::arraycopy(token, 0, outToken, offset, $nc(token)->length);
	return $nc(token)->length;
}

void MicToken_v2::encode($OutputStream* os) {
	encodeHeader(os);
	$nc(os)->write(this->checksum);
}

MicToken_v2::MicToken_v2() {
}

$Class* MicToken_v2::load$($String* name, bool initialize) {
	$loadClass(MicToken_v2, name, initialize, &_MicToken_v2_ClassInfo_, allocate$MicToken_v2);
	return class$;
}

$Class* MicToken_v2::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun