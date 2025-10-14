#include <sun/security/jgss/krb5/MessageToken.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
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
#include <java/security/MessageDigest.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/MessageProp.h>
#include <sun/security/jgss/GSSHeader.h>
#include <sun/security/jgss/GSSToken.h>
#include <sun/security/jgss/krb5/CipherHelper.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/krb5/MessageToken$MessageTokenHeader.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef DEFECTIVE_TOKEN
#undef FILLER
#undef OID
#undef SEAL_ALG_ARCFOUR_HMAC
#undef SEAL_ALG_DES
#undef SEAL_ALG_DES3_KD
#undef SEAL_ALG_NONE
#undef SEAL_ALG_POS
#undef SGN_ALG_DES_MAC
#undef SGN_ALG_DES_MAC_MD5
#undef SGN_ALG_HMAC_MD5_ARCFOUR
#undef SGN_ALG_HMAC_SHA1_DES3_KD
#undef SIGN_ALG_POS
#undef TOKEN_ID_POS
#undef TOKEN_NO_CKSUM_SIZE

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MessageDigest = ::java::security::MessageDigest;
using $GSSException = ::org::ietf::jgss::GSSException;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $GSSHeader = ::sun::security::jgss::GSSHeader;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $CipherHelper = ::sun::security::jgss::krb5::CipherHelper;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;
using $Krb5Token = ::sun::security::jgss::krb5::Krb5Token;
using $MessageToken$MessageTokenHeader = ::sun::security::jgss::krb5::MessageToken$MessageTokenHeader;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _MessageToken_FieldInfo_[] = {
	{"TOKEN_NO_CKSUM_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken, TOKEN_NO_CKSUM_SIZE)},
	{"FILLER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken, FILLER)},
	{"SGN_ALG_DES_MAC_MD5", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken, SGN_ALG_DES_MAC_MD5)},
	{"SGN_ALG_DES_MAC", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken, SGN_ALG_DES_MAC)},
	{"SGN_ALG_HMAC_SHA1_DES3_KD", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken, SGN_ALG_HMAC_SHA1_DES3_KD)},
	{"SEAL_ALG_NONE", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken, SEAL_ALG_NONE)},
	{"SEAL_ALG_DES", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken, SEAL_ALG_DES)},
	{"SEAL_ALG_DES3_KD", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken, SEAL_ALG_DES3_KD)},
	{"SEAL_ALG_ARCFOUR_HMAC", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken, SEAL_ALG_ARCFOUR_HMAC)},
	{"SGN_ALG_HMAC_MD5_ARCFOUR", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken, SGN_ALG_HMAC_MD5_ARCFOUR)},
	{"TOKEN_ID_POS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken, TOKEN_ID_POS)},
	{"SIGN_ALG_POS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken, SIGN_ALG_POS)},
	{"SEAL_ALG_POS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken, SEAL_ALG_POS)},
	{"seqNumber", "I", nullptr, $PRIVATE, $field(MessageToken, seqNumber)},
	{"confState", "Z", nullptr, $PRIVATE, $field(MessageToken, confState)},
	{"initiator", "Z", nullptr, $PRIVATE, $field(MessageToken, initiator)},
	{"tokenId", "I", nullptr, $PRIVATE, $field(MessageToken, tokenId)},
	{"gssHeader", "Lsun/security/jgss/GSSHeader;", nullptr, $PRIVATE, $field(MessageToken, gssHeader)},
	{"tokenHeader", "Lsun/security/jgss/krb5/MessageToken$MessageTokenHeader;", nullptr, $PRIVATE, $field(MessageToken, tokenHeader)},
	{"checksum", "[B", nullptr, $PRIVATE, $field(MessageToken, checksum)},
	{"encSeqNumber", "[B", nullptr, $PRIVATE, $field(MessageToken, encSeqNumber)},
	{"seqNumberData", "[B", nullptr, $PRIVATE, $field(MessageToken, seqNumberData)},
	{"cipherHelper", "Lsun/security/jgss/krb5/CipherHelper;", nullptr, 0, $field(MessageToken, cipherHelper)},
	{}
};

$MethodInfo _MessageToken_MethodInfo_[] = {
	{"<init>", "(ILsun/security/jgss/krb5/Krb5Context;[BIILorg/ietf/jgss/MessageProp;)V", nullptr, 0, $method(static_cast<void(MessageToken::*)(int32_t,$Krb5Context*,$bytes*,int32_t,int32_t,$MessageProp*)>(&MessageToken::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(ILsun/security/jgss/krb5/Krb5Context;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, 0, $method(static_cast<void(MessageToken::*)(int32_t,$Krb5Context*,$InputStream*,$MessageProp*)>(&MessageToken::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(ILsun/security/jgss/krb5/Krb5Context;)V", nullptr, 0, $method(static_cast<void(MessageToken::*)(int32_t,$Krb5Context*)>(&MessageToken::init$)), "org.ietf.jgss.GSSException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,org.ietf.jgss.GSSException"},
	{"genSignAndSeqNumber", "(Lorg/ietf/jgss/MessageProp;[B[BII[B)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getChecksum", "()[B", nullptr, $PUBLIC | $FINAL, $method(static_cast<$bytes*(MessageToken::*)()>(&MessageToken::getChecksum))},
	{"getChecksum", "([B[BII[B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(MessageToken::*)($bytes*,$bytes*,int32_t,int32_t,$bytes*)>(&MessageToken::getChecksum)), "org.ietf.jgss.GSSException"},
	{"getConfState", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(MessageToken::*)()>(&MessageToken::getConfState))},
	{"getEncSeqNumber", "()[B", nullptr, $PUBLIC | $FINAL, $method(static_cast<$bytes*(MessageToken::*)()>(&MessageToken::getEncSeqNumber))},
	{"getGSSHeader", "()Lsun/security/jgss/GSSHeader;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$GSSHeader*(MessageToken::*)()>(&MessageToken::getGSSHeader))},
	{"getKrb5TokenSize", "()I", nullptr, $PROTECTED, nullptr, "org.ietf.jgss.GSSException"},
	{"getSealAlg", "(ZI)I", nullptr, $PROTECTED | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getSequenceNumber", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(MessageToken::*)()>(&MessageToken::getSequenceNumber))},
	{"getSgnAlg", "(I)I", nullptr, $PROTECTED, nullptr, "org.ietf.jgss.GSSException"},
	{"getTokenId", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(MessageToken::*)()>(&MessageToken::getTokenId))},
	{"getTokenSize", "()I", nullptr, $PROTECTED | $FINAL, $method(static_cast<int32_t(MessageToken::*)()>(&MessageToken::getTokenSize)), "org.ietf.jgss.GSSException"},
	{"getTokenSize", "(Lsun/security/jgss/krb5/CipherHelper;)I", nullptr, $PROTECTED | $STATIC | $FINAL, $method(static_cast<int32_t(*)($CipherHelper*)>(&MessageToken::getTokenSize)), "org.ietf.jgss.GSSException"},
	{"init", "(ILsun/security/jgss/krb5/Krb5Context;)V", nullptr, $PRIVATE, $method(static_cast<void(MessageToken::*)(int32_t,$Krb5Context*)>(&MessageToken::init)), "org.ietf.jgss.GSSException"},
	{"verifySignAndSeqNumber", "([B[BII[B)Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(MessageToken::*)($bytes*,$bytes*,int32_t,int32_t,$bytes*)>(&MessageToken::verifySignAndSeqNumber)), "org.ietf.jgss.GSSException"},
	{}
};

$InnerClassInfo _MessageToken_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.MessageToken$MessageTokenHeader", "sun.security.jgss.krb5.MessageToken", "MessageTokenHeader", 0},
	{}
};

$ClassInfo _MessageToken_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.jgss.krb5.MessageToken",
	"sun.security.jgss.krb5.Krb5Token",
	nullptr,
	_MessageToken_FieldInfo_,
	_MessageToken_MethodInfo_,
	nullptr,
	nullptr,
	_MessageToken_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.MessageToken$MessageTokenHeader"
};

$Object* allocate$MessageToken($Class* clazz) {
	return $of($alloc(MessageToken));
}

void MessageToken::init$(int32_t tokenId, $Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, $MessageProp* prop) {
	MessageToken::init$(tokenId, context, $$new($ByteArrayInputStream, tokenBytes, tokenOffset, tokenLen), prop);
}

void MessageToken::init$(int32_t tokenId, $Krb5Context* context, $InputStream* is, $MessageProp* prop) {
	$Krb5Token::init$();
	this->confState = true;
	this->initiator = true;
	this->tokenId = 0;
	$set(this, gssHeader, nullptr);
	$set(this, tokenHeader, nullptr);
	$set(this, checksum, nullptr);
	$set(this, encSeqNumber, nullptr);
	$set(this, seqNumberData, nullptr);
	$set(this, cipherHelper, nullptr);
	init(tokenId, context);
	try {
		$set(this, gssHeader, $new($GSSHeader, is));
		$init($Krb5Token);
		if (!$nc($($nc(this->gssHeader)->getOid()))->equals($Krb5Token::OID)) {
			$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $(getTokenName(tokenId)));
		}
		if (!this->confState) {
			$nc(prop)->setPrivacy(false);
		}
		$set(this, tokenHeader, $new($MessageToken$MessageTokenHeader, this, is, prop));
		$set(this, encSeqNumber, $new($bytes, 8));
		readFully(is, this->encSeqNumber);
		$set(this, checksum, $new($bytes, $nc(this->cipherHelper)->getChecksumLength()));
		readFully(is, this->checksum);
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$var($String, var$0, $$str({$(getTokenName(tokenId)), ":"_s}));
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$concat(var$0, $(e->getMessage())));
	}
}

$GSSHeader* MessageToken::getGSSHeader() {
	return this->gssHeader;
}

int32_t MessageToken::getTokenId() {
	return this->tokenId;
}

$bytes* MessageToken::getEncSeqNumber() {
	return this->encSeqNumber;
}

$bytes* MessageToken::getChecksum() {
	return this->checksum;
}

bool MessageToken::getConfState() {
	return this->confState;
}

void MessageToken::genSignAndSeqNumber($MessageProp* prop, $bytes* optionalHeader, $bytes* data, int32_t offset, int32_t len, $bytes* optionalTrailer) {
	int32_t qop = $nc(prop)->getQOP();
	if (qop != 0) {
		qop = 0;
		prop->setQOP(qop);
	}
	if (!this->confState) {
		prop->setPrivacy(false);
	}
	$set(this, tokenHeader, $new($MessageToken$MessageTokenHeader, this, this->tokenId, prop->getPrivacy(), qop));
	$set(this, checksum, getChecksum(optionalHeader, data, offset, len, optionalTrailer));
	$set(this, seqNumberData, $new($bytes, 8));
	if ($nc(this->cipherHelper)->isArcFour()) {
		writeBigEndian(this->seqNumber, this->seqNumberData);
	} else {
		writeLittleEndian(this->seqNumber, this->seqNumberData);
	}
	if (!this->initiator) {
		$nc(this->seqNumberData)->set(4, (int8_t)255);
		$nc(this->seqNumberData)->set(5, (int8_t)255);
		$nc(this->seqNumberData)->set(6, (int8_t)255);
		$nc(this->seqNumberData)->set(7, (int8_t)255);
	}
	$set(this, encSeqNumber, $nc(this->cipherHelper)->encryptSeq(this->checksum, this->seqNumberData, 0, 8));
}

bool MessageToken::verifySignAndSeqNumber($bytes* optionalHeader, $bytes* data, int32_t offset, int32_t len, $bytes* optionalTrailer) {
	$var($bytes, myChecksum, getChecksum(optionalHeader, data, offset, len, optionalTrailer));
	if ($MessageDigest::isEqual(this->checksum, myChecksum)) {
		$set(this, seqNumberData, $nc(this->cipherHelper)->decryptSeq(this->checksum, this->encSeqNumber, 0, 8));
		int8_t directionByte = (int8_t)0;
		if (this->initiator) {
			directionByte = (int8_t)255;
		}
		if (($nc(this->seqNumberData)->get(4) == directionByte) && ($nc(this->seqNumberData)->get(5) == directionByte) && ($nc(this->seqNumberData)->get(6) == directionByte) && ($nc(this->seqNumberData)->get(7) == directionByte)) {
			return true;
		}
	}
	return false;
}

int32_t MessageToken::getSequenceNumber() {
	int32_t sequenceNum = 0;
	if ($nc(this->cipherHelper)->isArcFour()) {
		sequenceNum = readBigEndian(this->seqNumberData, 0, 4);
	} else {
		sequenceNum = readLittleEndian(this->seqNumberData, 0, 4);
	}
	return sequenceNum;
}

$bytes* MessageToken::getChecksum($bytes* optionalHeader, $bytes* data, int32_t offset, int32_t len, $bytes* optionalTrailer) {
	$var($bytes, tokenHeaderBytes, $nc(this->tokenHeader)->getBytes());
	$var($bytes, existingHeader, optionalHeader);
	$var($bytes, checksumDataHeader, tokenHeaderBytes);
	if (existingHeader != nullptr) {
		$assign(checksumDataHeader, $new($bytes, $nc(tokenHeaderBytes)->length + existingHeader->length));
		$System::arraycopy(tokenHeaderBytes, 0, checksumDataHeader, 0, tokenHeaderBytes->length);
		$System::arraycopy(existingHeader, 0, checksumDataHeader, tokenHeaderBytes->length, existingHeader->length);
	}
	return $nc(this->cipherHelper)->calculateChecksum($nc(this->tokenHeader)->getSignAlg(), checksumDataHeader, optionalTrailer, data, offset, len, this->tokenId);
}

void MessageToken::init$(int32_t tokenId, $Krb5Context* context) {
	$Krb5Token::init$();
	this->confState = true;
	this->initiator = true;
	this->tokenId = 0;
	$set(this, gssHeader, nullptr);
	$set(this, tokenHeader, nullptr);
	$set(this, checksum, nullptr);
	$set(this, encSeqNumber, nullptr);
	$set(this, seqNumberData, nullptr);
	$set(this, cipherHelper, nullptr);
	init(tokenId, context);
	this->seqNumber = $nc(context)->incrementMySequenceNumber();
}

void MessageToken::init(int32_t tokenId, $Krb5Context* context) {
	this->tokenId = tokenId;
	this->confState = $nc(context)->getConfState();
	this->initiator = context->isInitiator();
	$set(this, cipherHelper, context->getCipherHelper(nullptr));
}

void MessageToken::encode($OutputStream* os) {
	$init($Krb5Token);
	$set(this, gssHeader, $new($GSSHeader, $Krb5Token::OID, getKrb5TokenSize()));
	$nc(this->gssHeader)->encode(os);
	$nc(this->tokenHeader)->encode(os);
	$nc(os)->write(this->encSeqNumber);
	os->write(this->checksum);
}

int32_t MessageToken::getKrb5TokenSize() {
	return getTokenSize();
}

int32_t MessageToken::getTokenSize() {
	return MessageToken::TOKEN_NO_CKSUM_SIZE + $nc(this->cipherHelper)->getChecksumLength();
}

int32_t MessageToken::getTokenSize($CipherHelper* ch) {
	$init(MessageToken);
	return MessageToken::TOKEN_NO_CKSUM_SIZE + $nc(ch)->getChecksumLength();
}

int32_t MessageToken::getSgnAlg(int32_t qop) {
	return $nc(this->cipherHelper)->getSgnAlg();
}

MessageToken::MessageToken() {
}

$Class* MessageToken::load$($String* name, bool initialize) {
	$loadClass(MessageToken, name, initialize, &_MessageToken_ClassInfo_, allocate$MessageToken);
	return class$;
}

$Class* MessageToken::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun