#include <sun/security/jgss/TokenTracker$Entry.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/jgss/TokenTracker.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $TokenTracker = ::sun::security::jgss::TokenTracker;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _TokenTracker$Entry_FieldInfo_[] = {
	{"this$0", "Lsun/security/jgss/TokenTracker;", nullptr, $FINAL | $SYNTHETIC, $field(TokenTracker$Entry, this$0)},
	{"start", "I", nullptr, $PRIVATE, $field(TokenTracker$Entry, start)},
	{"end", "I", nullptr, $PRIVATE, $field(TokenTracker$Entry, end)},
	{}
};

$MethodInfo _TokenTracker$Entry_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/TokenTracker;I)V", nullptr, 0, $method(static_cast<void(TokenTracker$Entry::*)($TokenTracker*,int32_t)>(&TokenTracker$Entry::init$))},
	{"append", "(I)V", nullptr, $FINAL, $method(static_cast<void(TokenTracker$Entry::*)(int32_t)>(&TokenTracker$Entry::append))},
	{"compareTo", "(I)I", nullptr, $FINAL, $method(static_cast<int32_t(TokenTracker$Entry::*)(int32_t)>(&TokenTracker$Entry::compareTo))},
	{"contains", "(I)Z", nullptr, $FINAL, $method(static_cast<bool(TokenTracker$Entry::*)(int32_t)>(&TokenTracker$Entry::contains))},
	{"getEnd", "()I", nullptr, $FINAL, $method(static_cast<int32_t(TokenTracker$Entry::*)()>(&TokenTracker$Entry::getEnd))},
	{"getStart", "()I", nullptr, $FINAL, $method(static_cast<int32_t(TokenTracker$Entry::*)()>(&TokenTracker$Entry::getStart))},
	{"setEnd", "(I)V", nullptr, $FINAL, $method(static_cast<void(TokenTracker$Entry::*)(int32_t)>(&TokenTracker$Entry::setEnd))},
	{"setInterval", "(II)V", nullptr, $FINAL, $method(static_cast<void(TokenTracker$Entry::*)(int32_t,int32_t)>(&TokenTracker$Entry::setInterval))},
	{"setStart", "(I)V", nullptr, $FINAL, $method(static_cast<void(TokenTracker$Entry::*)(int32_t)>(&TokenTracker$Entry::setStart))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _TokenTracker$Entry_InnerClassesInfo_[] = {
	{"sun.security.jgss.TokenTracker$Entry", "sun.security.jgss.TokenTracker", "Entry", 0},
	{}
};

$ClassInfo _TokenTracker$Entry_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.TokenTracker$Entry",
	"java.lang.Object",
	nullptr,
	_TokenTracker$Entry_FieldInfo_,
	_TokenTracker$Entry_MethodInfo_,
	nullptr,
	nullptr,
	_TokenTracker$Entry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.TokenTracker"
};

$Object* allocate$TokenTracker$Entry($Class* clazz) {
	return $of($alloc(TokenTracker$Entry));
}

void TokenTracker$Entry::init$($TokenTracker* this$0, int32_t number) {
	$set(this, this$0, this$0);
	this->start = number;
	this->end = number;
}

int32_t TokenTracker$Entry::compareTo(int32_t number) {
	if (this->start > number) {
		return 1;
	} else if (this->end < number) {
		return -1;
	} else {
		return 0;
	}
}

bool TokenTracker$Entry::contains(int32_t number) {
	return (number >= this->start && number <= this->end);
}

void TokenTracker$Entry::append(int32_t number) {
	if (number == (this->end + 1)) {
		this->end = number;
	}
}

void TokenTracker$Entry::setInterval(int32_t start, int32_t end) {
	this->start = start;
	this->end = end;
}

void TokenTracker$Entry::setEnd(int32_t end) {
	this->end = end;
}

void TokenTracker$Entry::setStart(int32_t start) {
	this->start = start;
}

int32_t TokenTracker$Entry::getStart() {
	return this->start;
}

int32_t TokenTracker$Entry::getEnd() {
	return this->end;
}

$String* TokenTracker$Entry::toString() {
	return ($str({"["_s, $$str(this->start), ", "_s, $$str(this->end), "]"_s}));
}

TokenTracker$Entry::TokenTracker$Entry() {
}

$Class* TokenTracker$Entry::load$($String* name, bool initialize) {
	$loadClass(TokenTracker$Entry, name, initialize, &_TokenTracker$Entry_ClassInfo_, allocate$TokenTracker$Entry);
	return class$;
}

$Class* TokenTracker$Entry::class$ = nullptr;

		} // jgss
	} // security
} // sun