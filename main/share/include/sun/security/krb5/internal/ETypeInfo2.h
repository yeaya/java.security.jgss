#ifndef _sun_security_krb5_internal_ETypeInfo2_h_
#define _sun_security_krb5_internal_ETypeInfo2_h_
//$ class sun.security.krb5.internal.ETypeInfo2
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("TAG_TYPE")
#undef TAG_TYPE
#pragma push_macro("TAG_VALUE1")
#undef TAG_VALUE1
#pragma push_macro("TAG_VALUE2")
#undef TAG_VALUE2

namespace sun {
	namespace security {
		namespace util {
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import ETypeInfo2 : public ::java::lang::Object {
	$class(ETypeInfo2, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ETypeInfo2();
	void init$();
	void init$(int32_t etype, $String* salt, $bytes* s2kparams);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual int32_t getEType();
	virtual $bytes* getParams();
	virtual $String* getSalt();
	int32_t etype = 0;
	$String* saltStr = nullptr;
	$bytes* s2kparams = nullptr;
	static const int8_t TAG_TYPE = 0;
	static const int8_t TAG_VALUE1 = 1;
	static const int8_t TAG_VALUE2 = 2;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("TAG_TYPE")
#pragma pop_macro("TAG_VALUE1")
#pragma pop_macro("TAG_VALUE2")

#endif // _sun_security_krb5_internal_ETypeInfo2_h_