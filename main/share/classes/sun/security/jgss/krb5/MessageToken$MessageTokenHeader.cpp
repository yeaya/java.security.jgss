#include <sun/security/jgss/krb5/MessageToken$MessageTokenHeader.h>

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
#include <org/ietf/jgss/MessageProp.h>
#include <sun/security/jgss/GSSToken.h>
#include <sun/security/jgss/krb5/MessageToken.h>
#include <jcpp.h>

#undef FILLER

using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $MessageToken = ::sun::security::jgss::krb5::MessageToken;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _MessageToken$MessageTokenHeader_FieldInfo_[] = {
	{"this$0", "Lsun/security/jgss/krb5/MessageToken;", nullptr, $FINAL | $SYNTHETIC, $field(MessageToken$MessageTokenHeader, this$0)},
	{"tokenId", "I", nullptr, $PRIVATE, $field(MessageToken$MessageTokenHeader, tokenId)},
	{"signAlg", "I", nullptr, $PRIVATE, $field(MessageToken$MessageTokenHeader, signAlg)},
	{"sealAlg", "I", nullptr, $PRIVATE, $field(MessageToken$MessageTokenHeader, sealAlg)},
	{"bytes", "[B", nullptr, $PRIVATE, $field(MessageToken$MessageTokenHeader, bytes)},
	{}
};

$MethodInfo _MessageToken$MessageTokenHeader_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/MessageToken;IZI)V", nullptr, $PUBLIC, $method(static_cast<void(MessageToken$MessageTokenHeader::*)($MessageToken*,int32_t,bool,int32_t)>(&MessageToken$MessageTokenHeader::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/MessageToken;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, $method(static_cast<void(MessageToken$MessageTokenHeader::*)($MessageToken*,$InputStream*,$MessageProp*)>(&MessageToken$MessageTokenHeader::init$)), "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $FINAL, $method(static_cast<void(MessageToken$MessageTokenHeader::*)($OutputStream*)>(&MessageToken$MessageTokenHeader::encode)), "java.io.IOException"},
	{"getBytes", "()[B", nullptr, $PUBLIC | $FINAL, $method(static_cast<$bytes*(MessageToken$MessageTokenHeader::*)()>(&MessageToken$MessageTokenHeader::getBytes))},
	{"getSealAlg", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(MessageToken$MessageTokenHeader::*)()>(&MessageToken$MessageTokenHeader::getSealAlg))},
	{"getSignAlg", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(MessageToken$MessageTokenHeader::*)()>(&MessageToken$MessageTokenHeader::getSignAlg))},
	{"getTokenId", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(MessageToken$MessageTokenHeader::*)()>(&MessageToken$MessageTokenHeader::getTokenId))},
	{}
};

$InnerClassInfo _MessageToken$MessageTokenHeader_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.MessageToken$MessageTokenHeader", "sun.security.jgss.krb5.MessageToken", "MessageTokenHeader", 0},
	{}
};

$ClassInfo _MessageToken$MessageTokenHeader_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.MessageToken$MessageTokenHeader",
	"java.lang.Object",
	nullptr,
	_MessageToken$MessageTokenHeader_FieldInfo_,
	_MessageToken$MessageTokenHeader_MethodInfo_,
	nullptr,
	nullptr,
	_MessageToken$MessageTokenHeader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.MessageToken"
};

$Object* allocate$MessageToken$MessageTokenHeader($Class* clazz) {
	return $of($alloc(MessageToken$MessageTokenHeader));
}

void MessageToken$MessageTokenHeader::init$($MessageToken* this$0, int32_t tokenId, bool conf, int32_t qop) {
	$set(this, this$0, this$0);
	$set(this, bytes, $new($bytes, 8));
	this->tokenId = tokenId;
	this->signAlg = this$0->getSgnAlg(qop);
	this->sealAlg = this$0->getSealAlg(conf, qop);
	$nc(this->bytes)->set(0, (int8_t)((int32_t)((uint32_t)tokenId >> 8)));
	$nc(this->bytes)->set(1, (int8_t)(tokenId));
	$nc(this->bytes)->set(2, (int8_t)((int32_t)((uint32_t)this->signAlg >> 8)));
	$nc(this->bytes)->set(3, (int8_t)(this->signAlg));
	$nc(this->bytes)->set(4, (int8_t)((int32_t)((uint32_t)this->sealAlg >> 8)));
	$nc(this->bytes)->set(5, (int8_t)(this->sealAlg));
	$nc(this->bytes)->set(6, (int8_t)((int32_t)((uint32_t)$MessageToken::FILLER >> 8)));
	$nc(this->bytes)->set(7, (int8_t)($MessageToken::FILLER));
}

void MessageToken$MessageTokenHeader::init$($MessageToken* this$0, $InputStream* is, $MessageProp* prop) {
	$set(this, this$0, this$0);
	$set(this, bytes, $new($bytes, 8));
	$GSSToken::readFully(is, this->bytes);
	this->tokenId = $GSSToken::readInt(this->bytes, 0);
	this->signAlg = $GSSToken::readInt(this->bytes, 2);
	this->sealAlg = $GSSToken::readInt(this->bytes, 4);
	int32_t temp = $GSSToken::readInt(this->bytes, 4 + 2);
	switch (this->sealAlg) {
	case 0:
		{}
	case 512:
		{}
	case 4096:
		{
			$nc(prop)->setPrivacy(true);
			break;
		}
	default:
		{
			$nc(prop)->setPrivacy(false);
		}
	}
	$nc(prop)->setQOP(0);
}

void MessageToken$MessageTokenHeader::encode($OutputStream* os) {
	$nc(os)->write(this->bytes);
}

int32_t MessageToken$MessageTokenHeader::getTokenId() {
	return this->tokenId;
}

int32_t MessageToken$MessageTokenHeader::getSignAlg() {
	return this->signAlg;
}

int32_t MessageToken$MessageTokenHeader::getSealAlg() {
	return this->sealAlg;
}

$bytes* MessageToken$MessageTokenHeader::getBytes() {
	return this->bytes;
}

MessageToken$MessageTokenHeader::MessageToken$MessageTokenHeader() {
}

$Class* MessageToken$MessageTokenHeader::load$($String* name, bool initialize) {
	$loadClass(MessageToken$MessageTokenHeader, name, initialize, &_MessageToken$MessageTokenHeader_ClassInfo_, allocate$MessageToken$MessageTokenHeader);
	return class$;
}

$Class* MessageToken$MessageTokenHeader::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun