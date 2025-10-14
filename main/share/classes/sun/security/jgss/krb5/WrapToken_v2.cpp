#include <sun/security/jgss/krb5/WrapToken_v2.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Arrays.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/MessageProp.h>
#include <sun/security/jgss/GSSHeader.h>
#include <sun/security/jgss/krb5/CipherHelper.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/krb5/MessageToken_v2.h>
#include <sun/security/krb5/Confounder.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef BAD_MIC
#undef CONFOUNDER_SIZE
#undef OID
#undef TOKEN_HEADER_SIZE

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $GSSException = ::org::ietf::jgss::GSSException;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $GSSHeader = ::sun::security::jgss::GSSHeader;
using $CipherHelper = ::sun::security::jgss::krb5::CipherHelper;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;
using $Krb5Token = ::sun::security::jgss::krb5::Krb5Token;
using $MessageToken_v2 = ::sun::security::jgss::krb5::MessageToken_v2;
using $Confounder = ::sun::security::krb5::Confounder;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _WrapToken_v2_FieldInfo_[] = {
	{"confounder", "[B", nullptr, 0, $field(WrapToken_v2, confounder)},
	{"privacy", "Z", nullptr, $PRIVATE | $FINAL, $field(WrapToken_v2, privacy)},
	{}
};

$MethodInfo _WrapToken_v2_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;[BIILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, $method(static_cast<void(WrapToken_v2::*)($Krb5Context*,$bytes*,int32_t,int32_t,$MessageProp*)>(&WrapToken_v2::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, $method(static_cast<void(WrapToken_v2::*)($Krb5Context*,$InputStream*,$MessageProp*)>(&WrapToken_v2::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Lorg/ietf/jgss/MessageProp;[BII)V", nullptr, $PUBLIC, $method(static_cast<void(WrapToken_v2::*)($Krb5Context*,$MessageProp*,$bytes*,int32_t,int32_t)>(&WrapToken_v2::init$)), "org.ietf.jgss.GSSException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"encode", "()[B", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"encode", "([BI)I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getData", "()[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getData", "([BI)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getSizeLimit", "(IZILsun/security/jgss/krb5/CipherHelper;)I", nullptr, $STATIC, $method(static_cast<int32_t(*)(int32_t,bool,int32_t,$CipherHelper*)>(&WrapToken_v2::getSizeLimit)), "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _WrapToken_v2_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.WrapToken_v2",
	"sun.security.jgss.krb5.MessageToken_v2",
	nullptr,
	_WrapToken_v2_FieldInfo_,
	_WrapToken_v2_MethodInfo_
};

$Object* allocate$WrapToken_v2($Class* clazz) {
	return $of($alloc(WrapToken_v2));
}

void WrapToken_v2::init$($Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, $MessageProp* prop) {
	$MessageToken_v2::init$($Krb5Token::WRAP_ID_v2, context, tokenBytes, tokenOffset, tokenLen, prop);
	$set(this, confounder, nullptr);
	this->privacy = $nc(prop)->getPrivacy();
}

void WrapToken_v2::init$($Krb5Context* context, $InputStream* is, $MessageProp* prop) {
	$MessageToken_v2::init$($Krb5Token::WRAP_ID_v2, context, is, prop);
	$set(this, confounder, nullptr);
	this->privacy = $nc(prop)->getPrivacy();
}

$bytes* WrapToken_v2::getData() {
	$var($bytes, temp, $new($bytes, this->tokenDataLen));
	int32_t len = getData(temp, 0);
	return $Arrays::copyOf(temp, len);
}

int32_t WrapToken_v2::getData($bytes* dataBuf, int32_t dataBufOffset) {
	if (this->privacy) {
		$nc(this->cipherHelper)->decryptData(this, this->tokenData, 0, this->tokenDataLen, dataBuf, dataBufOffset, getKeyUsage());
		return this->tokenDataLen - $MessageToken_v2::CONFOUNDER_SIZE - $MessageToken_v2::TOKEN_HEADER_SIZE - $nc(this->cipherHelper)->getChecksumLength();
	} else {
		int32_t data_length = this->tokenDataLen - $nc(this->cipherHelper)->getChecksumLength();
		$System::arraycopy(this->tokenData, 0, dataBuf, dataBufOffset, data_length);
		if (!verifySign(dataBuf, dataBufOffset, data_length)) {
			$throwNew($GSSException, $GSSException::BAD_MIC, -1, "Corrupt checksum in Wrap token"_s);
		}
		return data_length;
	}
}

void WrapToken_v2::init$($Krb5Context* context, $MessageProp* prop, $bytes* dataBytes, int32_t dataOffset, int32_t dataLen) {
	$MessageToken_v2::init$($Krb5Token::WRAP_ID_v2, context);
	$set(this, confounder, nullptr);
	$set(this, confounder, $Confounder::bytes($MessageToken_v2::CONFOUNDER_SIZE));
	genSignAndSeqNumber(prop, dataBytes, dataOffset, dataLen);
	if (!$nc(context)->getConfState()) {
		$nc(prop)->setPrivacy(false);
	}
	this->privacy = $nc(prop)->getPrivacy();
	if (!this->privacy) {
		$set(this, tokenData, $new($bytes, dataLen + $nc(this->checksum)->length));
		$System::arraycopy(dataBytes, dataOffset, this->tokenData, 0, dataLen);
		$System::arraycopy(this->checksum, 0, this->tokenData, dataLen, $nc(this->checksum)->length);
	} else {
		$var($bytes, var$0, this->confounder);
		$var($bytes, var$1, getTokenHeader());
		$var($bytes, var$2, dataBytes);
		int32_t var$3 = dataOffset;
		int32_t var$4 = dataLen;
		$set(this, tokenData, $nc(this->cipherHelper)->encryptData(this, var$0, var$1, var$2, var$3, var$4, getKeyUsage()));
	}
}

void WrapToken_v2::encode($OutputStream* os) {
	encodeHeader(os);
	$nc(os)->write(this->tokenData);
}

$bytes* WrapToken_v2::encode() {
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream, $MessageToken_v2::TOKEN_HEADER_SIZE + $nc(this->tokenData)->length));
	encode(bos);
	return bos->toByteArray();
}

int32_t WrapToken_v2::encode($bytes* outToken, int32_t offset) {
	$var($bytes, token, encode());
	$System::arraycopy(token, 0, outToken, offset, $nc(token)->length);
	return $nc(token)->length;
}

int32_t WrapToken_v2::getSizeLimit(int32_t qop, bool confReq, int32_t maxTokenSize, $CipherHelper* ch) {
	$init(WrapToken_v2);
	$init($Krb5Token);
	int32_t var$0 = $GSSHeader::getMaxMechTokenSize($Krb5Token::OID, maxTokenSize);
	return (var$0 - ($MessageToken_v2::TOKEN_HEADER_SIZE + $nc(ch)->getChecksumLength() + $MessageToken_v2::CONFOUNDER_SIZE) - 8);
}

WrapToken_v2::WrapToken_v2() {
}

$Class* WrapToken_v2::load$($String* name, bool initialize) {
	$loadClass(WrapToken_v2, name, initialize, &_WrapToken_v2_ClassInfo_, allocate$WrapToken_v2);
	return class$;
}

$Class* WrapToken_v2::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun