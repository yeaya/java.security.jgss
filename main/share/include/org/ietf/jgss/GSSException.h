#ifndef _org_ietf_jgss_GSSException_h_
#define _org_ietf_jgss_GSSException_h_
//$ class org.ietf.jgss.GSSException
//$ extends java.lang.Exception

#include <java/lang/Array.h>
#include <java/lang/Exception.h>

#pragma push_macro("BAD_BINDINGS")
#undef BAD_BINDINGS
#pragma push_macro("BAD_MECH")
#undef BAD_MECH
#pragma push_macro("BAD_MIC")
#undef BAD_MIC
#pragma push_macro("BAD_NAME")
#undef BAD_NAME
#pragma push_macro("BAD_NAMETYPE")
#undef BAD_NAMETYPE
#pragma push_macro("BAD_QOP")
#undef BAD_QOP
#pragma push_macro("BAD_STATUS")
#undef BAD_STATUS
#pragma push_macro("CONTEXT_EXPIRED")
#undef CONTEXT_EXPIRED
#pragma push_macro("CREDENTIALS_EXPIRED")
#undef CREDENTIALS_EXPIRED
#pragma push_macro("DEFECTIVE_CREDENTIAL")
#undef DEFECTIVE_CREDENTIAL
#pragma push_macro("DEFECTIVE_TOKEN")
#undef DEFECTIVE_TOKEN
#pragma push_macro("DUPLICATE_ELEMENT")
#undef DUPLICATE_ELEMENT
#pragma push_macro("DUPLICATE_TOKEN")
#undef DUPLICATE_TOKEN
#pragma push_macro("FAILURE")
#undef FAILURE
#pragma push_macro("GAP_TOKEN")
#undef GAP_TOKEN
#pragma push_macro("NAME_NOT_MN")
#undef NAME_NOT_MN
#pragma push_macro("NO_CONTEXT")
#undef NO_CONTEXT
#pragma push_macro("NO_CRED")
#undef NO_CRED
#pragma push_macro("OLD_TOKEN")
#undef OLD_TOKEN
#pragma push_macro("UNAUTHORIZED")
#undef UNAUTHORIZED
#pragma push_macro("UNAVAILABLE")
#undef UNAVAILABLE
#pragma push_macro("UNSEQ_TOKEN")
#undef UNSEQ_TOKEN

namespace org {
	namespace ietf {
		namespace jgss {

class $import GSSException : public ::java::lang::Exception {
	$class(GSSException, 0, ::java::lang::Exception)
public:
	GSSException();
	void init$(int32_t majorCode);
	void init$(int32_t majorCode, $String* majorString);
	void init$(int32_t majorCode, int32_t minorCode, $String* minorString);
	virtual int32_t getMajor();
	virtual $String* getMajorString();
	virtual $String* getMessage() override;
	virtual int32_t getMinor();
	virtual $String* getMinorString();
	virtual void setMinor(int32_t minorCode, $String* message);
	virtual $String* toString() override;
	bool validateMajor(int32_t major);
	static const int64_t serialVersionUID = (int64_t)0xDA7194351D44E0B0;
	static const int32_t BAD_BINDINGS = 1;
	static const int32_t BAD_MECH = 2;
	static const int32_t BAD_NAME = 3;
	static const int32_t BAD_NAMETYPE = 4;
	static const int32_t BAD_STATUS = 5;
	static const int32_t BAD_MIC = 6;
	static const int32_t CONTEXT_EXPIRED = 7;
	static const int32_t CREDENTIALS_EXPIRED = 8;
	static const int32_t DEFECTIVE_CREDENTIAL = 9;
	static const int32_t DEFECTIVE_TOKEN = 10;
	static const int32_t FAILURE = 11;
	static const int32_t NO_CONTEXT = 12;
	static const int32_t NO_CRED = 13;
	static const int32_t BAD_QOP = 14;
	static const int32_t UNAUTHORIZED = 15;
	static const int32_t UNAVAILABLE = 16;
	static const int32_t DUPLICATE_ELEMENT = 17;
	static const int32_t NAME_NOT_MN = 18;
	static const int32_t DUPLICATE_TOKEN = 19;
	static const int32_t OLD_TOKEN = 20;
	static const int32_t UNSEQ_TOKEN = 21;
	static const int32_t GAP_TOKEN = 22;
	static $StringArray* messages;
	int32_t major = 0;
	int32_t minor = 0;
	$String* minorMessage = nullptr;
	$String* majorString = nullptr;
	GSSException(const GSSException& e);
	GSSException wrapper$();
	virtual void throwWrapper$() override;
};

		} // jgss
	} // ietf
} // org

#pragma pop_macro("BAD_BINDINGS")
#pragma pop_macro("BAD_MECH")
#pragma pop_macro("BAD_MIC")
#pragma pop_macro("BAD_NAME")
#pragma pop_macro("BAD_NAMETYPE")
#pragma pop_macro("BAD_QOP")
#pragma pop_macro("BAD_STATUS")
#pragma pop_macro("CONTEXT_EXPIRED")
#pragma pop_macro("CREDENTIALS_EXPIRED")
#pragma pop_macro("DEFECTIVE_CREDENTIAL")
#pragma pop_macro("DEFECTIVE_TOKEN")
#pragma pop_macro("DUPLICATE_ELEMENT")
#pragma pop_macro("DUPLICATE_TOKEN")
#pragma pop_macro("FAILURE")
#pragma pop_macro("GAP_TOKEN")
#pragma pop_macro("NAME_NOT_MN")
#pragma pop_macro("NO_CONTEXT")
#pragma pop_macro("NO_CRED")
#pragma pop_macro("OLD_TOKEN")
#pragma pop_macro("UNAUTHORIZED")
#pragma pop_macro("UNAVAILABLE")
#pragma pop_macro("UNSEQ_TOKEN")

#endif // _org_ietf_jgss_GSSException_h_