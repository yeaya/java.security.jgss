#ifndef _sun_security_jgss_TokenTracker_h_
#define _sun_security_jgss_TokenTracker_h_
//$ class sun.security.jgss.TokenTracker
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("MAX_INTERVALS")
#undef MAX_INTERVALS

namespace java {
	namespace util {
		class LinkedList;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class MessageProp;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $import TokenTracker : public ::java::lang::Object {
	$class(TokenTracker, $NO_CLASS_INIT, ::java::lang::Object)
public:
	TokenTracker();
	void init$(int32_t initNumber);
	void add(int32_t number, int32_t prevEntryPos);
	int32_t getIntervalIndex(int32_t number);
	void getProps(int32_t number, ::org::ietf::jgss::MessageProp* prop);
	virtual $String* toString() override;
	static const int32_t MAX_INTERVALS = 5;
	int32_t initNumber = 0;
	int32_t windowStart = 0;
	int32_t expectedNumber = 0;
	int32_t windowStartIndex = 0;
	::java::util::LinkedList* list = nullptr;
};

		} // jgss
	} // security
} // sun

#pragma pop_macro("MAX_INTERVALS")

#endif // _sun_security_jgss_TokenTracker_h_