#ifndef _sun_security_jgss_TokenTracker$Entry_h_
#define _sun_security_jgss_TokenTracker$Entry_h_
//$ class sun.security.jgss.TokenTracker$Entry
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace security {
		namespace jgss {
			class TokenTracker;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $import TokenTracker$Entry : public ::java::lang::Object {
	$class(TokenTracker$Entry, $NO_CLASS_INIT, ::java::lang::Object)
public:
	TokenTracker$Entry();
	void init$(::sun::security::jgss::TokenTracker* this$0, int32_t number);
	void append(int32_t number);
	int32_t compareTo(int32_t number);
	bool contains(int32_t number);
	int32_t getEnd();
	int32_t getStart();
	void setEnd(int32_t end);
	void setInterval(int32_t start, int32_t end);
	void setStart(int32_t start);
	virtual $String* toString() override;
	::sun::security::jgss::TokenTracker* this$0 = nullptr;
	int32_t start = 0;
	int32_t end = 0;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_TokenTracker$Entry_h_