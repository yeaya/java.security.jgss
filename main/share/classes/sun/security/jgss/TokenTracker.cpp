#include <sun/security/jgss/TokenTracker.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/LinkedList.h>
#include <org/ietf/jgss/MessageProp.h>
#include <sun/security/jgss/TokenTracker$Entry.h>
#include <jcpp.h>

#undef MAX_INTERVALS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $LinkedList = ::java::util::LinkedList;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $TokenTracker$Entry = ::sun::security::jgss::TokenTracker$Entry;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _TokenTracker_FieldInfo_[] = {
	{"MAX_INTERVALS", "I", nullptr, $STATIC | $FINAL, $constField(TokenTracker, MAX_INTERVALS)},
	{"initNumber", "I", nullptr, $PRIVATE, $field(TokenTracker, initNumber)},
	{"windowStart", "I", nullptr, $PRIVATE, $field(TokenTracker, windowStart)},
	{"expectedNumber", "I", nullptr, $PRIVATE, $field(TokenTracker, expectedNumber)},
	{"windowStartIndex", "I", nullptr, $PRIVATE, $field(TokenTracker, windowStartIndex)},
	{"list", "Ljava/util/LinkedList;", "Ljava/util/LinkedList<Lsun/security/jgss/TokenTracker$Entry;>;", $PRIVATE, $field(TokenTracker, list)},
	{}
};

$MethodInfo _TokenTracker_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(TokenTracker::*)(int32_t)>(&TokenTracker::init$))},
	{"add", "(II)V", nullptr, $PRIVATE, $method(static_cast<void(TokenTracker::*)(int32_t,int32_t)>(&TokenTracker::add))},
	{"getIntervalIndex", "(I)I", nullptr, $PRIVATE, $method(static_cast<int32_t(TokenTracker::*)(int32_t)>(&TokenTracker::getIntervalIndex))},
	{"getProps", "(ILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $FINAL | $SYNCHRONIZED, $method(static_cast<void(TokenTracker::*)(int32_t,$MessageProp*)>(&TokenTracker::getProps))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _TokenTracker_InnerClassesInfo_[] = {
	{"sun.security.jgss.TokenTracker$Entry", "sun.security.jgss.TokenTracker", "Entry", 0},
	{}
};

$ClassInfo _TokenTracker_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.TokenTracker",
	"java.lang.Object",
	nullptr,
	_TokenTracker_FieldInfo_,
	_TokenTracker_MethodInfo_,
	nullptr,
	nullptr,
	_TokenTracker_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.TokenTracker$Entry"
};

$Object* allocate$TokenTracker($Class* clazz) {
	return $of($alloc(TokenTracker));
}

void TokenTracker::init$(int32_t initNumber) {
	this->windowStartIndex = 0;
	$set(this, list, $new($LinkedList));
	this->initNumber = initNumber;
	this->windowStart = initNumber;
	this->expectedNumber = initNumber;
	$var($TokenTracker$Entry, entry, $new($TokenTracker$Entry, this, initNumber - 1));
	$nc(this->list)->add(entry);
}

int32_t TokenTracker::getIntervalIndex(int32_t number) {
	$var($TokenTracker$Entry, entry, nullptr);
	int32_t i = 0;
	for (i = $nc(this->list)->size() - 1; i >= 0; --i) {
		$assign(entry, $cast($TokenTracker$Entry, $nc(this->list)->get(i)));
		if ($nc(entry)->compareTo(number) <= 0) {
			break;
		}
	}
	return i;
}

void TokenTracker::getProps(int32_t number, $MessageProp* prop) {
	$synchronized(this) {
		bool gap = false;
		bool old = false;
		bool unsequenced = false;
		bool duplicate = false;
		int32_t pos = getIntervalIndex(number);
		$var($TokenTracker$Entry, entry, nullptr);
		if (pos != -1) {
			$assign(entry, $cast($TokenTracker$Entry, $nc(this->list)->get(pos)));
		}
		if (number == this->expectedNumber) {
			++this->expectedNumber;
		} else if (entry != nullptr && entry->contains(number)) {
			duplicate = true;
		} else if (this->expectedNumber >= this->initNumber) {
			if (number > this->expectedNumber) {
				gap = true;
			} else if (number >= this->windowStart) {
				unsequenced = true;
			} else if (number >= this->initNumber) {
				old = true;
			} else {
				gap = true;
			}
		} else if (number > this->expectedNumber) {
			if (number < this->initNumber) {
				gap = true;
			} else if (this->windowStart >= this->initNumber) {
				if (number >= this->windowStart) {
					unsequenced = true;
				} else {
					old = true;
				}
			} else {
				old = true;
			}
		} else if (this->windowStart > this->expectedNumber) {
			unsequenced = true;
		} else if (number < this->windowStart) {
			old = true;
		} else {
			unsequenced = true;
		}
		if (!duplicate && !old) {
			add(number, pos);
		}
		if (gap) {
			this->expectedNumber = number + 1;
		}
		$nc(prop)->setSupplementaryStates(duplicate, old, unsequenced, gap, 0, nullptr);
	}
}

void TokenTracker::add(int32_t number, int32_t prevEntryPos) {
	$var($TokenTracker$Entry, entry, nullptr);
	$var($TokenTracker$Entry, entryBefore, nullptr);
	$var($TokenTracker$Entry, entryAfter, nullptr);
	bool appended = false;
	bool prepended = false;
	if (prevEntryPos != -1) {
		$assign(entryBefore, $cast($TokenTracker$Entry, $nc(this->list)->get(prevEntryPos)));
		if (number == ($nc(entryBefore)->getEnd() + 1)) {
			entryBefore->setEnd(number);
			appended = true;
		}
	}
	int32_t nextEntryPos = prevEntryPos + 1;
	if ((nextEntryPos) < $nc(this->list)->size()) {
		$assign(entryAfter, $cast($TokenTracker$Entry, $nc(this->list)->get(nextEntryPos)));
		if (number == ($nc(entryAfter)->getStart() - 1)) {
			if (!appended) {
				entryAfter->setStart(number);
			} else {
				entryAfter->setStart($nc(entryBefore)->getStart());
				$nc(this->list)->remove(prevEntryPos);
				if (this->windowStartIndex > prevEntryPos) {
					--this->windowStartIndex;
				}
			}
			prepended = true;
		}
	}
	if (prepended || appended) {
		return;
	}
	if ($nc(this->list)->size() < TokenTracker::MAX_INTERVALS) {
		$assign(entry, $new($TokenTracker$Entry, this, number));
		if (prevEntryPos < this->windowStartIndex) {
			++this->windowStartIndex;
		}
	} else {
		int32_t oldWindowStartIndex = this->windowStartIndex;
		if (this->windowStartIndex == ($nc(this->list)->size() - 1)) {
			this->windowStartIndex = 0;
		}
		$assign(entry, $cast($TokenTracker$Entry, $nc(this->list)->remove(oldWindowStartIndex)));
		this->windowStart = $nc(($cast($TokenTracker$Entry, $($nc(this->list)->get(this->windowStartIndex)))))->getStart();
		entry->setStart(number);
		entry->setEnd(number);
		if (prevEntryPos >= oldWindowStartIndex) {
			--prevEntryPos;
		} else if (oldWindowStartIndex != this->windowStartIndex) {
			if (prevEntryPos == -1) {
				this->windowStart = number;
			}
		} else {
			++this->windowStartIndex;
		}
	}
	$nc(this->list)->add(prevEntryPos + 1, entry);
}

$String* TokenTracker::toString() {
	$var($StringBuilder, sb, $new($StringBuilder, "TokenTracker: "_s));
	sb->append(" initNumber="_s)->append(this->initNumber);
	sb->append(" windowStart="_s)->append(this->windowStart);
	sb->append(" expectedNumber="_s)->append(this->expectedNumber);
	sb->append(" windowStartIndex="_s)->append(this->windowStartIndex);
	sb->append("\n\tIntervals are: {"_s);
	for (int32_t i = 0; i < $nc(this->list)->size(); ++i) {
		if (i != 0) {
			sb->append(", "_s);
		}
		sb->append($($nc(($cast($TokenTracker$Entry, $($nc(this->list)->get(i)))))->toString()));
	}
	sb->append(u'}');
	return sb->toString();
}

TokenTracker::TokenTracker() {
}

$Class* TokenTracker::load$($String* name, bool initialize) {
	$loadClass(TokenTracker, name, initialize, &_TokenTracker_ClassInfo_, allocate$TokenTracker);
	return class$;
}

$Class* TokenTracker::class$ = nullptr;

		} // jgss
	} // security
} // sun