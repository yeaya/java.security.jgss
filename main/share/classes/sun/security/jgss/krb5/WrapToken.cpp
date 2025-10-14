#include <sun/security/jgss/krb5/WrapToken.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/MessageProp.h>
#include <sun/security/jgss/GSSHeader.h>
#include <sun/security/jgss/krb5/CipherHelper.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/krb5/MessageToken.h>
#include <sun/security/krb5/Confounder.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef BAD_MIC
#undef CONFOUNDER_SIZE
#undef DEFECTIVE_TOKEN
#undef OID
#undef SEAL_ALG_NONE
#undef WRAP_ID

using $byteArray2 = $Array<int8_t, 2>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSException = ::org::ietf::jgss::GSSException;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $GSSHeader = ::sun::security::jgss::GSSHeader;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $CipherHelper = ::sun::security::jgss::krb5::CipherHelper;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;
using $Krb5Token = ::sun::security::jgss::krb5::Krb5Token;
using $MessageToken = ::sun::security::jgss::krb5::MessageToken;
using $Confounder = ::sun::security::krb5::Confounder;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _WrapToken_FieldInfo_[] = {
	{"CONFOUNDER_SIZE", "I", nullptr, $STATIC | $FINAL, $constField(WrapToken, CONFOUNDER_SIZE)},
	{"pads", "[[B", nullptr, $STATIC | $FINAL, $staticField(WrapToken, pads)},
	{"readTokenFromInputStream", "Z", nullptr, $PRIVATE, $field(WrapToken, readTokenFromInputStream)},
	{"is", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(WrapToken, is)},
	{"tokenBytes", "[B", nullptr, $PRIVATE, $field(WrapToken, tokenBytes)},
	{"tokenOffset", "I", nullptr, $PRIVATE, $field(WrapToken, tokenOffset)},
	{"tokenLen", "I", nullptr, $PRIVATE, $field(WrapToken, tokenLen)},
	{"dataBytes", "[B", nullptr, $PRIVATE, $field(WrapToken, dataBytes)},
	{"dataOffset", "I", nullptr, $PRIVATE, $field(WrapToken, dataOffset)},
	{"dataLen", "I", nullptr, $PRIVATE, $field(WrapToken, dataLen)},
	{"dataSize", "I", nullptr, $PRIVATE, $field(WrapToken, dataSize)},
	{"confounder", "[B", nullptr, 0, $field(WrapToken, confounder)},
	{"padding", "[B", nullptr, 0, $field(WrapToken, padding)},
	{"privacy", "Z", nullptr, $PRIVATE, $field(WrapToken, privacy)},
	{}
};

$MethodInfo _WrapToken_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;[BIILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, $method(static_cast<void(WrapToken::*)($Krb5Context*,$bytes*,int32_t,int32_t,$MessageProp*)>(&WrapToken::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, $method(static_cast<void(WrapToken::*)($Krb5Context*,$InputStream*,$MessageProp*)>(&WrapToken::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Lorg/ietf/jgss/MessageProp;[BII)V", nullptr, $PUBLIC, $method(static_cast<void(WrapToken::*)($Krb5Context*,$MessageProp*,$bytes*,int32_t,int32_t)>(&WrapToken::init$)), "org.ietf.jgss.GSSException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,org.ietf.jgss.GSSException"},
	{"encode", "()[B", nullptr, $PUBLIC, nullptr, "java.io.IOException,org.ietf.jgss.GSSException"},
	{"encode", "([BI)I", nullptr, $PUBLIC, nullptr, "java.io.IOException,org.ietf.jgss.GSSException"},
	{"getData", "()[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getData", "([BI)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getDataFromBuffer", "([BI)V", nullptr, $PRIVATE, $method(static_cast<void(WrapToken::*)($bytes*,int32_t)>(&WrapToken::getDataFromBuffer)), "org.ietf.jgss.GSSException"},
	{"getDataFromStream", "([BI)V", nullptr, $PRIVATE, $method(static_cast<void(WrapToken::*)($bytes*,int32_t)>(&WrapToken::getDataFromStream)), "org.ietf.jgss.GSSException"},
	{"getKrb5TokenSize", "()I", nullptr, $PROTECTED, nullptr, "org.ietf.jgss.GSSException"},
	{"getPadding", "(I)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(WrapToken::*)(int32_t)>(&WrapToken::getPadding))},
	{"getSealAlg", "(ZI)I", nullptr, $PROTECTED, nullptr, "org.ietf.jgss.GSSException"},
	{"getSizeLimit", "(IZILsun/security/jgss/krb5/CipherHelper;)I", nullptr, $STATIC, $method(static_cast<int32_t(*)(int32_t,bool,int32_t,$CipherHelper*)>(&WrapToken::getSizeLimit)), "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _WrapToken_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.WrapToken",
	"sun.security.jgss.krb5.MessageToken",
	nullptr,
	_WrapToken_FieldInfo_,
	_WrapToken_MethodInfo_
};

$Object* allocate$WrapToken($Class* clazz) {
	return $of($alloc(WrapToken));
}

$byteArray2* WrapToken::pads = nullptr;

void WrapToken::init$($Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, $MessageProp* prop) {
	$MessageToken::init$($Krb5Token::WRAP_ID, context, tokenBytes, tokenOffset, tokenLen, prop);
	this->readTokenFromInputStream = true;
	$set(this, is, nullptr);
	$set(this, tokenBytes, nullptr);
	this->tokenOffset = 0;
	this->tokenLen = 0;
	$set(this, dataBytes, nullptr);
	this->dataOffset = 0;
	this->dataLen = 0;
	this->dataSize = 0;
	$set(this, confounder, nullptr);
	$set(this, padding, nullptr);
	this->privacy = false;
	this->readTokenFromInputStream = false;
	$set(this, tokenBytes, tokenBytes);
	this->tokenOffset = tokenOffset;
	this->tokenLen = tokenLen;
	this->privacy = $nc(prop)->getPrivacy();
	int32_t var$0 = $nc($(getGSSHeader()))->getMechTokenLength();
	this->dataSize = var$0 - getKrb5TokenSize();
}

void WrapToken::init$($Krb5Context* context, $InputStream* is, $MessageProp* prop) {
	$MessageToken::init$($Krb5Token::WRAP_ID, context, is, prop);
	this->readTokenFromInputStream = true;
	$set(this, is, nullptr);
	$set(this, tokenBytes, nullptr);
	this->tokenOffset = 0;
	this->tokenLen = 0;
	$set(this, dataBytes, nullptr);
	this->dataOffset = 0;
	this->dataLen = 0;
	this->dataSize = 0;
	$set(this, confounder, nullptr);
	$set(this, padding, nullptr);
	this->privacy = false;
	$set(this, is, is);
	this->privacy = $nc(prop)->getPrivacy();
	int32_t var$0 = $nc($(getGSSHeader()))->getMechTokenLength();
	this->dataSize = var$0 - getTokenSize();
}

$bytes* WrapToken::getData() {
	$var($bytes, temp, $new($bytes, this->dataSize));
	getData(temp, 0);
	$var($bytes, retVal, $new($bytes, this->dataSize - $nc(this->confounder)->length - $nc(this->padding)->length));
	$System::arraycopy(temp, 0, retVal, 0, retVal->length);
	return retVal;
}

int32_t WrapToken::getData($bytes* dataBuf, int32_t dataBufOffset) {
	if (this->readTokenFromInputStream) {
		getDataFromStream(dataBuf, dataBufOffset);
	} else {
		getDataFromBuffer(dataBuf, dataBufOffset);
	}
	return (this->dataSize - $nc(this->confounder)->length - $nc(this->padding)->length);
}

void WrapToken::getDataFromBuffer($bytes* dataBuf, int32_t dataBufOffset) {
	$var($GSSHeader, gssHeader, getGSSHeader());
	int32_t var$0 = this->tokenOffset + $nc(gssHeader)->getLength();
	int32_t dataPos = var$0 + getTokenSize();
	if (dataPos + this->dataSize > this->tokenOffset + this->tokenLen) {
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({"Insufficient data in "_s, $(getTokenName(getTokenId()))}));
	}
	$set(this, confounder, $new($bytes, WrapToken::CONFOUNDER_SIZE));
	if (this->privacy) {
		$nc(this->cipherHelper)->decryptData(this, this->tokenBytes, dataPos, this->dataSize, dataBuf, dataBufOffset);
	} else {
		$System::arraycopy(this->tokenBytes, dataPos, this->confounder, 0, WrapToken::CONFOUNDER_SIZE);
		int32_t padSize = $nc(this->tokenBytes)->get(dataPos + this->dataSize - 1);
		if (padSize < 0) {
			padSize = 0;
		}
		if (padSize > 8) {
			$modAssign(padSize, 8);
		}
		$set(this, padding, $nc(WrapToken::pads)->get(padSize));
		$System::arraycopy(this->tokenBytes, dataPos + WrapToken::CONFOUNDER_SIZE, dataBuf, dataBufOffset, this->dataSize - WrapToken::CONFOUNDER_SIZE - padSize);
	}
	if (!verifySignAndSeqNumber(this->confounder, dataBuf, dataBufOffset, this->dataSize - WrapToken::CONFOUNDER_SIZE - $nc(this->padding)->length, this->padding)) {
		$throwNew($GSSException, $GSSException::BAD_MIC, -1, "Corrupt checksum or sequence number in Wrap token"_s);
	}
}

void WrapToken::getDataFromStream($bytes* dataBuf, int32_t dataBufOffset) {
	$var($GSSHeader, gssHeader, getGSSHeader());
	$set(this, confounder, $new($bytes, WrapToken::CONFOUNDER_SIZE));
	try {
		if (this->privacy) {
			$nc(this->cipherHelper)->decryptData(this, this->is, this->dataSize, dataBuf, dataBufOffset);
		} else {
			readFully(this->is, this->confounder);
			if ($nc(this->cipherHelper)->isArcFour()) {
				$set(this, padding, $nc(WrapToken::pads)->get(1));
				readFully(this->is, dataBuf, dataBufOffset, this->dataSize - WrapToken::CONFOUNDER_SIZE - 1);
			} else {
				int32_t numBlocks = (this->dataSize - WrapToken::CONFOUNDER_SIZE) / 8 - 1;
				int32_t offset = dataBufOffset;
				for (int32_t i = 0; i < numBlocks; ++i) {
					readFully(this->is, dataBuf, offset, 8);
					offset += 8;
				}
				$var($bytes, finalBlock, $new($bytes, 8));
				readFully(this->is, finalBlock);
				int32_t padSize = finalBlock->get(7);
				$set(this, padding, $nc(WrapToken::pads)->get(padSize));
				$System::arraycopy(finalBlock, 0, dataBuf, offset, finalBlock->length - padSize);
			}
		}
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$var($String, var$0, $$str({$(getTokenName(getTokenId())), ": "_s}));
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$concat(var$0, $(e->getMessage())));
	}
	if (!verifySignAndSeqNumber(this->confounder, dataBuf, dataBufOffset, this->dataSize - WrapToken::CONFOUNDER_SIZE - $nc(this->padding)->length, this->padding)) {
		$throwNew($GSSException, $GSSException::BAD_MIC, -1, "Corrupt checksum or sequence number in Wrap token"_s);
	}
}

$bytes* WrapToken::getPadding(int32_t len) {
	int32_t padSize = 0;
	if ($nc(this->cipherHelper)->isArcFour()) {
		padSize = 1;
	} else {
		padSize = len % 8;
		padSize = 8 - padSize;
	}
	return $nc(WrapToken::pads)->get(padSize);
}

void WrapToken::init$($Krb5Context* context, $MessageProp* prop, $bytes* dataBytes, int32_t dataOffset, int32_t dataLen) {
	$MessageToken::init$($Krb5Token::WRAP_ID, context);
	this->readTokenFromInputStream = true;
	$set(this, is, nullptr);
	$set(this, tokenBytes, nullptr);
	this->tokenOffset = 0;
	this->tokenLen = 0;
	$set(this, dataBytes, nullptr);
	this->dataOffset = 0;
	this->dataLen = 0;
	this->dataSize = 0;
	$set(this, confounder, nullptr);
	$set(this, padding, nullptr);
	this->privacy = false;
	$set(this, confounder, $Confounder::bytes(WrapToken::CONFOUNDER_SIZE));
	$set(this, padding, getPadding(dataLen));
	this->dataSize = $nc(this->confounder)->length + dataLen + $nc(this->padding)->length;
	$set(this, dataBytes, dataBytes);
	this->dataOffset = dataOffset;
	this->dataLen = dataLen;
	genSignAndSeqNumber(prop, this->confounder, dataBytes, dataOffset, dataLen, this->padding);
	if (!$nc(context)->getConfState()) {
		$nc(prop)->setPrivacy(false);
	}
	this->privacy = $nc(prop)->getPrivacy();
}

void WrapToken::encode($OutputStream* os) {
	$MessageToken::encode(os);
	if (!this->privacy) {
		$nc(os)->write(this->confounder);
		os->write(this->dataBytes, this->dataOffset, this->dataLen);
		os->write(this->padding);
	} else {
		$nc(this->cipherHelper)->encryptData(this, this->confounder, this->dataBytes, this->dataOffset, this->dataLen, this->padding, os);
	}
}

$bytes* WrapToken::encode() {
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream, this->dataSize + 50));
	encode(bos);
	return bos->toByteArray();
}

int32_t WrapToken::encode($bytes* outToken, int32_t offset) {
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream));
	$MessageToken::encode(bos);
	$var($bytes, header, bos->toByteArray());
	$System::arraycopy(header, 0, outToken, offset, $nc(header)->length);
	offset += $nc(header)->length;
	if (!this->privacy) {
		$System::arraycopy(this->confounder, 0, outToken, offset, $nc(this->confounder)->length);
		offset += $nc(this->confounder)->length;
		$System::arraycopy(this->dataBytes, this->dataOffset, outToken, offset, this->dataLen);
		offset += this->dataLen;
		$System::arraycopy(this->padding, 0, outToken, offset, $nc(this->padding)->length);
	} else {
		$nc(this->cipherHelper)->encryptData(this, this->confounder, this->dataBytes, this->dataOffset, this->dataLen, this->padding, outToken, offset);
	}
	return (header->length + $nc(this->confounder)->length + this->dataLen + $nc(this->padding)->length);
}

int32_t WrapToken::getKrb5TokenSize() {
	return (getTokenSize() + this->dataSize);
}

int32_t WrapToken::getSealAlg(bool conf, int32_t qop) {
	if (!conf) {
		return $MessageToken::SEAL_ALG_NONE;
	}
	return $nc(this->cipherHelper)->getSealAlg();
}

int32_t WrapToken::getSizeLimit(int32_t qop, bool confReq, int32_t maxTokenSize, $CipherHelper* ch) {
	$init(WrapToken);
	$init($Krb5Token);
	int32_t var$0 = $GSSHeader::getMaxMechTokenSize($Krb5Token::OID, maxTokenSize);
	return (var$0 - (getTokenSize(ch) + WrapToken::CONFOUNDER_SIZE) - 8);
}

void clinit$WrapToken($Class* class$) {
	$assignStatic(WrapToken::pads, $new($byteArray2, {
		($bytes*)nullptr,
		$$new($bytes, {(int8_t)1}),
		$$new($bytes, {
			(int8_t)2,
			(int8_t)2
		}),
		$$new($bytes, {
			(int8_t)3,
			(int8_t)3,
			(int8_t)3
		}),
		$$new($bytes, {
			(int8_t)4,
			(int8_t)4,
			(int8_t)4,
			(int8_t)4
		}),
		$$new($bytes, {
			(int8_t)5,
			(int8_t)5,
			(int8_t)5,
			(int8_t)5,
			(int8_t)5
		}),
		$$new($bytes, {
			(int8_t)6,
			(int8_t)6,
			(int8_t)6,
			(int8_t)6,
			(int8_t)6,
			(int8_t)6
		}),
		$$new($bytes, {
			(int8_t)7,
			(int8_t)7,
			(int8_t)7,
			(int8_t)7,
			(int8_t)7,
			(int8_t)7,
			(int8_t)7
		}),
		$$new($bytes, {
			(int8_t)8,
			(int8_t)8,
			(int8_t)8,
			(int8_t)8,
			(int8_t)8,
			(int8_t)8,
			(int8_t)8,
			(int8_t)8
		})
	}));
}

WrapToken::WrapToken() {
}

$Class* WrapToken::load$($String* name, bool initialize) {
	$loadClass(WrapToken, name, initialize, &_WrapToken_ClassInfo_, clinit$WrapToken, allocate$WrapToken);
	return class$;
}

$Class* WrapToken::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun