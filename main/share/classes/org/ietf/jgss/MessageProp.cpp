#include <org/ietf/jgss/MessageProp.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace org {
	namespace ietf {
		namespace jgss {

$FieldInfo _MessageProp_FieldInfo_[] = {
	{"privacyState", "Z", nullptr, $PRIVATE, $field(MessageProp, privacyState)},
	{"qop", "I", nullptr, $PRIVATE, $field(MessageProp, qop)},
	{"dupToken", "Z", nullptr, $PRIVATE, $field(MessageProp, dupToken)},
	{"oldToken", "Z", nullptr, $PRIVATE, $field(MessageProp, oldToken)},
	{"unseqToken", "Z", nullptr, $PRIVATE, $field(MessageProp, unseqToken)},
	{"gapToken", "Z", nullptr, $PRIVATE, $field(MessageProp, gapToken)},
	{"minorStatus", "I", nullptr, $PRIVATE, $field(MessageProp, minorStatus)},
	{"minorString", "Ljava/lang/String;", nullptr, $PRIVATE, $field(MessageProp, minorString)},
	{}
};

$MethodInfo _MessageProp_MethodInfo_[] = {
	{"<init>", "(Z)V", nullptr, $PUBLIC, $method(static_cast<void(MessageProp::*)(bool)>(&MessageProp::init$))},
	{"<init>", "(IZ)V", nullptr, $PUBLIC, $method(static_cast<void(MessageProp::*)(int32_t,bool)>(&MessageProp::init$))},
	{"getMinorStatus", "()I", nullptr, $PUBLIC},
	{"getMinorString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getPrivacy", "()Z", nullptr, $PUBLIC},
	{"getQOP", "()I", nullptr, $PUBLIC},
	{"isDuplicateToken", "()Z", nullptr, $PUBLIC},
	{"isGapToken", "()Z", nullptr, $PUBLIC},
	{"isOldToken", "()Z", nullptr, $PUBLIC},
	{"isUnseqToken", "()Z", nullptr, $PUBLIC},
	{"resetStatusValues", "()V", nullptr, $PRIVATE, $method(static_cast<void(MessageProp::*)()>(&MessageProp::resetStatusValues))},
	{"setPrivacy", "(Z)V", nullptr, $PUBLIC},
	{"setQOP", "(I)V", nullptr, $PUBLIC},
	{"setSupplementaryStates", "(ZZZZILjava/lang/String;)V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _MessageProp_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"org.ietf.jgss.MessageProp",
	"java.lang.Object",
	nullptr,
	_MessageProp_FieldInfo_,
	_MessageProp_MethodInfo_
};

$Object* allocate$MessageProp($Class* clazz) {
	return $of($alloc(MessageProp));
}

void MessageProp::init$(bool privState) {
	MessageProp::init$(0, privState);
}

void MessageProp::init$(int32_t qop, bool privState) {
	this->qop = qop;
	this->privacyState = privState;
	resetStatusValues();
}

int32_t MessageProp::getQOP() {
	return this->qop;
}

bool MessageProp::getPrivacy() {
	return (this->privacyState);
}

void MessageProp::setQOP(int32_t qop) {
	this->qop = qop;
}

void MessageProp::setPrivacy(bool privState) {
	this->privacyState = privState;
}

bool MessageProp::isDuplicateToken() {
	return this->dupToken;
}

bool MessageProp::isOldToken() {
	return this->oldToken;
}

bool MessageProp::isUnseqToken() {
	return this->unseqToken;
}

bool MessageProp::isGapToken() {
	return this->gapToken;
}

int32_t MessageProp::getMinorStatus() {
	return this->minorStatus;
}

$String* MessageProp::getMinorString() {
	return this->minorString;
}

void MessageProp::setSupplementaryStates(bool duplicate, bool old, bool unseq, bool gap, int32_t minorStatus, $String* minorString) {
	this->dupToken = duplicate;
	this->oldToken = old;
	this->unseqToken = unseq;
	this->gapToken = gap;
	this->minorStatus = minorStatus;
	$set(this, minorString, minorString);
}

void MessageProp::resetStatusValues() {
	this->dupToken = false;
	this->oldToken = false;
	this->unseqToken = false;
	this->gapToken = false;
	this->minorStatus = 0;
	$set(this, minorString, nullptr);
}

MessageProp::MessageProp() {
}

$Class* MessageProp::load$($String* name, bool initialize) {
	$loadClass(MessageProp, name, initialize, &_MessageProp_ClassInfo_, allocate$MessageProp);
	return class$;
}

$Class* MessageProp::class$ = nullptr;

		} // jgss
	} // ietf
} // org