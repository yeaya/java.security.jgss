#ifndef _org_ietf_jgss_MessageProp_h_
#define _org_ietf_jgss_MessageProp_h_
//$ class org.ietf.jgss.MessageProp
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace org {
	namespace ietf {
		namespace jgss {

class $export MessageProp : public ::java::lang::Object {
	$class(MessageProp, $NO_CLASS_INIT, ::java::lang::Object)
public:
	MessageProp();
	void init$(bool privState);
	void init$(int32_t qop, bool privState);
	virtual int32_t getMinorStatus();
	virtual $String* getMinorString();
	virtual bool getPrivacy();
	virtual int32_t getQOP();
	virtual bool isDuplicateToken();
	virtual bool isGapToken();
	virtual bool isOldToken();
	virtual bool isUnseqToken();
	void resetStatusValues();
	virtual void setPrivacy(bool privState);
	virtual void setQOP(int32_t qop);
	virtual void setSupplementaryStates(bool duplicate, bool old, bool unseq, bool gap, int32_t minorStatus, $String* minorString);
	bool privacyState = false;
	int32_t qop = 0;
	bool dupToken = false;
	bool oldToken = false;
	bool unseqToken = false;
	bool gapToken = false;
	int32_t minorStatus = 0;
	$String* minorString = nullptr;
};

		} // jgss
	} // ietf
} // org

#endif // _org_ietf_jgss_MessageProp_h_