#ifndef _sun_security_krb5_internal_ETypeInfo_h_
#define _sun_security_krb5_internal_ETypeInfo_h_
//$ class sun.security.krb5.internal.ETypeInfo
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("TAG_TYPE")
#undef TAG_TYPE
#pragma push_macro("TAG_VALUE")
#undef TAG_VALUE

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

class $import ETypeInfo : public ::java::lang::Object {
	$class(ETypeInfo, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ETypeInfo();
	void init$();
	void init$(int32_t etype, $String* salt);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual int32_t getEType();
	virtual $String* getSalt();
	int32_t etype = 0;
	$String* salt = nullptr;
	static const int8_t TAG_TYPE = 0;
	static const int8_t TAG_VALUE = 1;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("TAG_TYPE")
#pragma pop_macro("TAG_VALUE")

#endif // _sun_security_krb5_internal_ETypeInfo_h_