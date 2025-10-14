#include <sun/security/jgss/krb5/MessageToken_v2$MessageTokenHeader.h>

#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/MessageProp.h>
#include <sun/security/jgss/GSSToken.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/krb5/MessageToken_v2.h>
#include <jcpp.h>

#undef DEFECTIVE_TOKEN

using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSException = ::org::ietf::jgss::GSSException;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $Krb5Token = ::sun::security::jgss::krb5::Krb5Token;
using $MessageToken_v2 = ::sun::security::jgss::krb5::MessageToken_v2;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _MessageToken_v2$MessageTokenHeader_FieldInfo_[] = {
	{"this$0", "Lsun/security/jgss/krb5/MessageToken_v2;", nullptr, $FINAL | $SYNTHETIC, $field(MessageToken_v2$MessageTokenHeader, this$0)},
	{"tokenId", "I", nullptr, $PRIVATE, $field(MessageToken_v2$MessageTokenHeader, tokenId)},
	{"bytes", "[B", nullptr, $PRIVATE, $field(MessageToken_v2$MessageTokenHeader, bytes)},
	{}
};

$MethodInfo _MessageToken_v2$MessageTokenHeader_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/MessageToken_v2;IZ)V", nullptr, $PUBLIC, $method(static_cast<void(MessageToken_v2$MessageTokenHeader::*)($MessageToken_v2*,int32_t,bool)>(&MessageToken_v2$MessageTokenHeader::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/MessageToken_v2;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;I)V", nullptr, $PUBLIC, $method(static_cast<void(MessageToken_v2$MessageTokenHeader::*)($MessageToken_v2*,$InputStream*,$MessageProp*,int32_t)>(&MessageToken_v2$MessageTokenHeader::init$)), "java.io.IOException,org.ietf.jgss.GSSException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $FINAL, $method(static_cast<void(MessageToken_v2$MessageTokenHeader::*)($OutputStream*)>(&MessageToken_v2$MessageTokenHeader::encode)), "java.io.IOException"},
	{"getBytes", "()[B", nullptr, $PUBLIC | $FINAL, $method(static_cast<$bytes*(MessageToken_v2$MessageTokenHeader::*)()>(&MessageToken_v2$MessageTokenHeader::getBytes))},
	{"getTokenId", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(MessageToken_v2$MessageTokenHeader::*)()>(&MessageToken_v2$MessageTokenHeader::getTokenId))},
	{}
};

$InnerClassInfo _MessageToken_v2$MessageTokenHeader_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.MessageToken_v2$MessageTokenHeader", "sun.security.jgss.krb5.MessageToken_v2", "MessageTokenHeader", 0},
	{}
};

$ClassInfo _MessageToken_v2$MessageTokenHeader_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.MessageToken_v2$MessageTokenHeader",
	"java.lang.Object",
	nullptr,
	_MessageToken_v2$MessageTokenHeader_FieldInfo_,
	_MessageToken_v2$MessageTokenHeader_MethodInfo_,
	nullptr,
	nullptr,
	_MessageToken_v2$MessageTokenHeader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.MessageToken_v2"
};

$Object* allocate$MessageToken_v2$MessageTokenHeader($Class* clazz) {
	return $of($alloc(MessageToken_v2$MessageTokenHeader));
}

void MessageToken_v2$MessageTokenHeader::init$($MessageToken_v2* this$0, int32_t tokenId, bool conf) {
	$set(this, this$0, this$0);
	$set(this, bytes, $new($bytes, 16));
	this->tokenId = tokenId;
	$nc(this->bytes)->set(0, (int8_t)((int32_t)((uint32_t)tokenId >> 8)));
	$nc(this->bytes)->set(1, (int8_t)(tokenId));
	int32_t flags = 0;
	flags = ((this$0->initiator ? 0 : 1) | ((conf && tokenId != 1028) ? 2 : 0)) | (this$0->have_acceptor_subkey ? 4 : 0);
	$nc(this->bytes)->set(2, (int8_t)flags);
	$nc(this->bytes)->set(3, (int8_t)255);
	if (tokenId == 1284) {
		$nc(this->bytes)->set(4, (int8_t)0);
		$nc(this->bytes)->set(5, (int8_t)0);
		$nc(this->bytes)->set(6, (int8_t)0);
		$nc(this->bytes)->set(7, (int8_t)0);
	} else if (tokenId == 1028) {
		for (int32_t i = 4; i < 8; ++i) {
			$nc(this->bytes)->set(i, (int8_t)255);
		}
	}
	$GSSToken::writeBigEndian(this$0->seqNumber, this->bytes, 12);
}

void MessageToken_v2$MessageTokenHeader::init$($MessageToken_v2* this$0, $InputStream* is, $MessageProp* prop, int32_t tokId) {
	$set(this, this$0, this$0);
	$set(this, bytes, $new($bytes, 16));
	$GSSToken::readFully(is, this->bytes, 0, 16);
	this->tokenId = $GSSToken::readInt(this->bytes, 0);
	if (this->tokenId != tokId) {
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({$($Krb5Token::getTokenName(this->tokenId)), ":Defective Token ID!"_s}));
	}
	int32_t acceptor_flag = (this$0->initiator ? 1 : 0);
	int32_t flag = (int32_t)($nc(this->bytes)->get(2) & (uint32_t)1);
	if (flag != acceptor_flag) {
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({$($Krb5Token::getTokenName(this->tokenId)), ":Acceptor Flag Error!"_s}));
	}
	int32_t conf_flag = (int32_t)($nc(this->bytes)->get(2) & (uint32_t)2);
	if ((conf_flag == 2) && (this->tokenId == 1284)) {
		$nc(prop)->setPrivacy(true);
	} else {
		$nc(prop)->setPrivacy(false);
	}
	if (this->tokenId == 1284) {
		if (((int32_t)($nc(this->bytes)->get(3) & (uint32_t)255)) != 255) {
			$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({$($Krb5Token::getTokenName(this->tokenId)), ":Defective Token Filler!"_s}));
		}
		this$0->ec = $GSSToken::readBigEndian(this->bytes, 4, 2);
		this$0->rrc = $GSSToken::readBigEndian(this->bytes, 6, 2);
	} else if (this->tokenId == 1028) {
		for (int32_t i = 3; i < 8; ++i) {
			if (((int32_t)($nc(this->bytes)->get(i) & (uint32_t)255)) != 255) {
				$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({$($Krb5Token::getTokenName(this->tokenId)), ":Defective Token Filler!"_s}));
			}
		}
	}
	$nc(prop)->setQOP(0);
	this$0->seqNumber = $GSSToken::readBigEndian(this->bytes, 12, 4);
}

void MessageToken_v2$MessageTokenHeader::encode($OutputStream* os) {
	$nc(os)->write(this->bytes);
}

int32_t MessageToken_v2$MessageTokenHeader::getTokenId() {
	return this->tokenId;
}

$bytes* MessageToken_v2$MessageTokenHeader::getBytes() {
	return this->bytes;
}

MessageToken_v2$MessageTokenHeader::MessageToken_v2$MessageTokenHeader() {
}

$Class* MessageToken_v2$MessageTokenHeader::load$($String* name, bool initialize) {
	$loadClass(MessageToken_v2$MessageTokenHeader, name, initialize, &_MessageToken_v2$MessageTokenHeader_ClassInfo_, allocate$MessageToken_v2$MessageTokenHeader);
	return class$;
}

$Class* MessageToken_v2$MessageTokenHeader::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun