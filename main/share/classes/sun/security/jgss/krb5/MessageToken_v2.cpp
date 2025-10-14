#include <sun/security/jgss/krb5/MessageToken_v2.h>

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
#include <java/util/Arrays.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/MessageProp.h>
#include <sun/security/jgss/GSSToken.h>
#include <sun/security/jgss/krb5/CipherHelper.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/krb5/MessageToken_v2$MessageTokenHeader.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <jcpp.h>

#undef ACCEPTOR_SUBKEY
#undef CONFOUNDER_SIZE
#undef DEFECTIVE_TOKEN
#undef FILLER
#undef FLAG_ACCEPTOR_SUBKEY
#undef FLAG_SENDER_IS_ACCEPTOR
#undef FLAG_WRAP_CONFIDENTIAL
#undef KG_USAGE_ACCEPTOR_SEAL
#undef KG_USAGE_ACCEPTOR_SIGN
#undef KG_USAGE_INITIATOR_SEAL
#undef KG_USAGE_INITIATOR_SIGN
#undef TOKEN_EC_POS
#undef TOKEN_FLAG_POS
#undef TOKEN_HEADER_SIZE
#undef TOKEN_ID_POS
#undef TOKEN_RRC_POS

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MessageDigest = ::java::security::MessageDigest;
using $Arrays = ::java::util::Arrays;
using $GSSException = ::org::ietf::jgss::GSSException;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $CipherHelper = ::sun::security::jgss::krb5::CipherHelper;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;
using $Krb5Token = ::sun::security::jgss::krb5::Krb5Token;
using $MessageToken_v2$MessageTokenHeader = ::sun::security::jgss::krb5::MessageToken_v2$MessageTokenHeader;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _MessageToken_v2_FieldInfo_[] = {
	{"TOKEN_HEADER_SIZE", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(MessageToken_v2, TOKEN_HEADER_SIZE)},
	{"TOKEN_ID_POS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken_v2, TOKEN_ID_POS)},
	{"TOKEN_FLAG_POS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken_v2, TOKEN_FLAG_POS)},
	{"TOKEN_EC_POS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken_v2, TOKEN_EC_POS)},
	{"TOKEN_RRC_POS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken_v2, TOKEN_RRC_POS)},
	{"CONFOUNDER_SIZE", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(MessageToken_v2, CONFOUNDER_SIZE)},
	{"KG_USAGE_ACCEPTOR_SEAL", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken_v2, KG_USAGE_ACCEPTOR_SEAL)},
	{"KG_USAGE_ACCEPTOR_SIGN", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken_v2, KG_USAGE_ACCEPTOR_SIGN)},
	{"KG_USAGE_INITIATOR_SEAL", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken_v2, KG_USAGE_INITIATOR_SEAL)},
	{"KG_USAGE_INITIATOR_SIGN", "I", nullptr, $STATIC | $FINAL, $constField(MessageToken_v2, KG_USAGE_INITIATOR_SIGN)},
	{"FLAG_SENDER_IS_ACCEPTOR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken_v2, FLAG_SENDER_IS_ACCEPTOR)},
	{"FLAG_WRAP_CONFIDENTIAL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken_v2, FLAG_WRAP_CONFIDENTIAL)},
	{"FLAG_ACCEPTOR_SUBKEY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken_v2, FLAG_ACCEPTOR_SUBKEY)},
	{"FILLER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageToken_v2, FILLER)},
	{"tokenHeader", "Lsun/security/jgss/krb5/MessageToken_v2$MessageTokenHeader;", nullptr, $PRIVATE, $field(MessageToken_v2, tokenHeader)},
	{"tokenId", "I", nullptr, $PRIVATE, $field(MessageToken_v2, tokenId)},
	{"seqNumber", "I", nullptr, $PRIVATE, $field(MessageToken_v2, seqNumber)},
	{"tokenData", "[B", nullptr, $PROTECTED, $field(MessageToken_v2, tokenData)},
	{"tokenDataLen", "I", nullptr, $PROTECTED, $field(MessageToken_v2, tokenDataLen)},
	{"key_usage", "I", nullptr, $PRIVATE, $field(MessageToken_v2, key_usage)},
	{"ec", "I", nullptr, $PRIVATE, $field(MessageToken_v2, ec)},
	{"rrc", "I", nullptr, $PRIVATE, $field(MessageToken_v2, rrc)},
	{"checksum", "[B", nullptr, 0, $field(MessageToken_v2, checksum)},
	{"confState", "Z", nullptr, $PRIVATE, $field(MessageToken_v2, confState)},
	{"initiator", "Z", nullptr, $PRIVATE, $field(MessageToken_v2, initiator)},
	{"have_acceptor_subkey", "Z", nullptr, $PRIVATE, $field(MessageToken_v2, have_acceptor_subkey)},
	{"cipherHelper", "Lsun/security/jgss/krb5/CipherHelper;", nullptr, 0, $field(MessageToken_v2, cipherHelper)},
	{}
};

$MethodInfo _MessageToken_v2_MethodInfo_[] = {
	{"<init>", "(ILsun/security/jgss/krb5/Krb5Context;[BIILorg/ietf/jgss/MessageProp;)V", nullptr, 0, $method(static_cast<void(MessageToken_v2::*)(int32_t,$Krb5Context*,$bytes*,int32_t,int32_t,$MessageProp*)>(&MessageToken_v2::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(ILsun/security/jgss/krb5/Krb5Context;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, 0, $method(static_cast<void(MessageToken_v2::*)(int32_t,$Krb5Context*,$InputStream*,$MessageProp*)>(&MessageToken_v2::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(ILsun/security/jgss/krb5/Krb5Context;)V", nullptr, 0, $method(static_cast<void(MessageToken_v2::*)(int32_t,$Krb5Context*)>(&MessageToken_v2::init$)), "org.ietf.jgss.GSSException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"encodeHeader", "(Ljava/io/OutputStream;)V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"genSignAndSeqNumber", "(Lorg/ietf/jgss/MessageProp;[BII)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getChecksum", "([BII)[B", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"getConfState", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(MessageToken_v2::*)()>(&MessageToken_v2::getConfState))},
	{"getKeyUsage", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(MessageToken_v2::*)()>(&MessageToken_v2::getKeyUsage))},
	{"getSequenceNumber", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(MessageToken_v2::*)()>(&MessageToken_v2::getSequenceNumber))},
	{"getTokenHeader", "()[B", nullptr, $PROTECTED | $FINAL, $method(static_cast<$bytes*(MessageToken_v2::*)()>(&MessageToken_v2::getTokenHeader))},
	{"getTokenId", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(MessageToken_v2::*)()>(&MessageToken_v2::getTokenId))},
	{"init", "(ILsun/security/jgss/krb5/Krb5Context;)V", nullptr, $PRIVATE, $method(static_cast<void(MessageToken_v2::*)(int32_t,$Krb5Context*)>(&MessageToken_v2::init)), "org.ietf.jgss.GSSException"},
	{"rotate", "()V", nullptr, $PRIVATE, $method(static_cast<void(MessageToken_v2::*)()>(&MessageToken_v2::rotate))},
	{"verifySign", "([BII)Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(MessageToken_v2::*)($bytes*,int32_t,int32_t)>(&MessageToken_v2::verifySign)), "org.ietf.jgss.GSSException"},
	{}
};

$InnerClassInfo _MessageToken_v2_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.MessageToken_v2$MessageTokenHeader", "sun.security.jgss.krb5.MessageToken_v2", "MessageTokenHeader", 0},
	{}
};

$ClassInfo _MessageToken_v2_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.jgss.krb5.MessageToken_v2",
	"sun.security.jgss.krb5.Krb5Token",
	nullptr,
	_MessageToken_v2_FieldInfo_,
	_MessageToken_v2_MethodInfo_,
	nullptr,
	nullptr,
	_MessageToken_v2_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.MessageToken_v2$MessageTokenHeader"
};

$Object* allocate$MessageToken_v2($Class* clazz) {
	return $of($alloc(MessageToken_v2));
}

void MessageToken_v2::init$(int32_t tokenId, $Krb5Context* context, $bytes* tokenBytes, int32_t tokenOffset, int32_t tokenLen, $MessageProp* prop) {
	MessageToken_v2::init$(tokenId, context, $$new($ByteArrayInputStream, tokenBytes, tokenOffset, tokenLen), prop);
}

void MessageToken_v2::init$(int32_t tokenId, $Krb5Context* context, $InputStream* is, $MessageProp* prop) {
	$Krb5Token::init$();
	$set(this, tokenHeader, nullptr);
	this->tokenId = 0;
	this->key_usage = 0;
	this->ec = 0;
	this->rrc = 0;
	$set(this, checksum, nullptr);
	this->confState = true;
	this->initiator = true;
	this->have_acceptor_subkey = false;
	$set(this, cipherHelper, nullptr);
	init(tokenId, context);
	try {
		if (!this->confState) {
			$nc(prop)->setPrivacy(false);
		}
		$set(this, tokenHeader, $new($MessageToken_v2$MessageTokenHeader, this, is, prop, tokenId));
		if (tokenId == $Krb5Token::WRAP_ID_v2) {
			this->key_usage = (!this->initiator ? MessageToken_v2::KG_USAGE_INITIATOR_SEAL : MessageToken_v2::KG_USAGE_ACCEPTOR_SEAL);
		} else if (tokenId == $Krb5Token::MIC_ID_v2) {
			this->key_usage = (!this->initiator ? MessageToken_v2::KG_USAGE_INITIATOR_SIGN : MessageToken_v2::KG_USAGE_ACCEPTOR_SIGN);
		}
		int32_t minSize = 0;
		if (tokenId == $Krb5Token::WRAP_ID_v2 && $nc(prop)->getPrivacy()) {
			minSize = MessageToken_v2::CONFOUNDER_SIZE + MessageToken_v2::TOKEN_HEADER_SIZE + $nc(this->cipherHelper)->getChecksumLength();
		} else {
			minSize = $nc(this->cipherHelper)->getChecksumLength();
		}
		if (tokenId == $Krb5Token::MIC_ID_v2) {
			this->tokenDataLen = minSize;
			$set(this, tokenData, $new($bytes, minSize));
			readFully(is, this->tokenData);
		} else {
			this->tokenDataLen = $nc(is)->available();
			if (this->tokenDataLen >= minSize) {
				$set(this, tokenData, $new($bytes, this->tokenDataLen));
				readFully(is, this->tokenData);
			} else {
				$var($bytes, tmp, $new($bytes, minSize));
				readFully(is, tmp);
				int32_t more = is->available();
				this->tokenDataLen = minSize + more;
				$set(this, tokenData, $Arrays::copyOf(tmp, this->tokenDataLen));
				readFully(is, this->tokenData, minSize, more);
			}
		}
		if (tokenId == $Krb5Token::WRAP_ID_v2) {
			rotate();
		}
		if (tokenId == $Krb5Token::MIC_ID_v2 || (tokenId == $Krb5Token::WRAP_ID_v2 && !$nc(prop)->getPrivacy())) {
			int32_t chkLen = $nc(this->cipherHelper)->getChecksumLength();
			$set(this, checksum, $new($bytes, chkLen));
			$System::arraycopy(this->tokenData, this->tokenDataLen - chkLen, this->checksum, 0, chkLen);
			if (tokenId == $Krb5Token::WRAP_ID_v2 && !prop->getPrivacy()) {
				if (chkLen != this->ec) {
					$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({$(getTokenName(tokenId)), ":EC incorrect!"_s}));
				}
			}
		}
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$var($String, var$0, $$str({$(getTokenName(tokenId)), ":"_s}));
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$concat(var$0, $(e->getMessage())));
	}
}

int32_t MessageToken_v2::getTokenId() {
	return this->tokenId;
}

int32_t MessageToken_v2::getKeyUsage() {
	return this->key_usage;
}

bool MessageToken_v2::getConfState() {
	return this->confState;
}

void MessageToken_v2::genSignAndSeqNumber($MessageProp* prop, $bytes* data, int32_t offset, int32_t len) {
	int32_t qop = $nc(prop)->getQOP();
	if (qop != 0) {
		qop = 0;
		prop->setQOP(qop);
	}
	if (!this->confState) {
		prop->setPrivacy(false);
	}
	$set(this, tokenHeader, $new($MessageToken_v2$MessageTokenHeader, this, this->tokenId, prop->getPrivacy()));
	if (this->tokenId == $Krb5Token::WRAP_ID_v2) {
		this->key_usage = (this->initiator ? MessageToken_v2::KG_USAGE_INITIATOR_SEAL : MessageToken_v2::KG_USAGE_ACCEPTOR_SEAL);
	} else if (this->tokenId == $Krb5Token::MIC_ID_v2) {
		this->key_usage = (this->initiator ? MessageToken_v2::KG_USAGE_INITIATOR_SIGN : MessageToken_v2::KG_USAGE_ACCEPTOR_SIGN);
	}
	if ((this->tokenId == $Krb5Token::MIC_ID_v2) || (!prop->getPrivacy() && (this->tokenId == $Krb5Token::WRAP_ID_v2))) {
		$set(this, checksum, getChecksum(data, offset, len));
	}
	if (!prop->getPrivacy() && (this->tokenId == $Krb5Token::WRAP_ID_v2)) {
		$var($bytes, tok_header, $nc(this->tokenHeader)->getBytes());
		$nc(tok_header)->set(4, (int8_t)((int32_t)((uint32_t)$nc(this->checksum)->length >> 8)));
		tok_header->set(5, (int8_t)($nc(this->checksum)->length));
	}
}

bool MessageToken_v2::verifySign($bytes* data, int32_t offset, int32_t len) {
	$var($bytes, myChecksum, getChecksum(data, offset, len));
	if ($MessageDigest::isEqual(this->checksum, myChecksum)) {
		return true;
	}
	return false;
}

void MessageToken_v2::rotate() {
	if ($mod(this->rrc, this->tokenDataLen) != 0) {
		this->rrc = $mod(this->rrc, this->tokenDataLen);
		$var($bytes, newBytes, $new($bytes, this->tokenDataLen));
		$System::arraycopy(this->tokenData, this->rrc, newBytes, 0, this->tokenDataLen - this->rrc);
		$System::arraycopy(this->tokenData, 0, newBytes, this->tokenDataLen - this->rrc, this->rrc);
		$set(this, tokenData, newBytes);
	}
}

int32_t MessageToken_v2::getSequenceNumber() {
	return this->seqNumber;
}

$bytes* MessageToken_v2::getChecksum($bytes* data, int32_t offset, int32_t len) {
	$var($bytes, tokenHeaderBytes, $nc(this->tokenHeader)->getBytes());
	int32_t conf_flag = (int32_t)($nc(tokenHeaderBytes)->get(MessageToken_v2::TOKEN_FLAG_POS) & (uint32_t)MessageToken_v2::FLAG_WRAP_CONFIDENTIAL);
	if ((conf_flag == 0) && (this->tokenId == $Krb5Token::WRAP_ID_v2)) {
		tokenHeaderBytes->set(4, (int8_t)0);
		tokenHeaderBytes->set(5, (int8_t)0);
		tokenHeaderBytes->set(6, (int8_t)0);
		tokenHeaderBytes->set(7, (int8_t)0);
	}
	return $nc(this->cipherHelper)->calculateChecksum(tokenHeaderBytes, data, offset, len, this->key_usage);
}

void MessageToken_v2::init$(int32_t tokenId, $Krb5Context* context) {
	$Krb5Token::init$();
	$set(this, tokenHeader, nullptr);
	this->tokenId = 0;
	this->key_usage = 0;
	this->ec = 0;
	this->rrc = 0;
	$set(this, checksum, nullptr);
	this->confState = true;
	this->initiator = true;
	this->have_acceptor_subkey = false;
	$set(this, cipherHelper, nullptr);
	init(tokenId, context);
	this->seqNumber = $nc(context)->incrementMySequenceNumber();
}

void MessageToken_v2::init(int32_t tokenId, $Krb5Context* context) {
	this->tokenId = tokenId;
	this->confState = $nc(context)->getConfState();
	this->initiator = context->isInitiator();
	this->have_acceptor_subkey = context->getKeySrc() == $Krb5Context::ACCEPTOR_SUBKEY;
	$set(this, cipherHelper, context->getCipherHelper(nullptr));
}

void MessageToken_v2::encodeHeader($OutputStream* os) {
	$nc(this->tokenHeader)->encode(os);
}

$bytes* MessageToken_v2::getTokenHeader() {
	return ($nc(this->tokenHeader)->getBytes());
}

MessageToken_v2::MessageToken_v2() {
}

$Class* MessageToken_v2::load$($String* name, bool initialize) {
	$loadClass(MessageToken_v2, name, initialize, &_MessageToken_v2_ClassInfo_, allocate$MessageToken_v2);
	return class$;
}

$Class* MessageToken_v2::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun