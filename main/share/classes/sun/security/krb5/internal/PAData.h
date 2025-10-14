#ifndef _sun_security_krb5_internal_PAData_h_
#define _sun_security_krb5_internal_PAData_h_
//$ class sun.security.krb5.internal.PAData
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("TAG_PATYPE")
#undef TAG_PATYPE
#pragma push_macro("TAG_PAVALUE")
#undef TAG_PAVALUE

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class PAData$SaltAndParams;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class DerInputStream;
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export PAData : public ::java::lang::Object {
	$class(PAData, $NO_CLASS_INIT, ::java::lang::Object)
public:
	PAData();
	void init$();
	void init$(int32_t new_pADataType, $bytes* new_pADataValue);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	static int32_t getPreferredEType($Array<::sun::security::krb5::internal::PAData>* pas, int32_t defaultEType);
	static ::sun::security::krb5::internal::PAData$SaltAndParams* getSaltAndParams(int32_t eType, $Array<::sun::security::krb5::internal::PAData>* pas);
	virtual int32_t getType();
	virtual $bytes* getValue();
	static $Array<::sun::security::krb5::internal::PAData>* parseSequence(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	virtual $String* toString() override;
	int32_t pADataType = 0;
	$bytes* pADataValue = nullptr;
	static const int8_t TAG_PATYPE = 1;
	static const int8_t TAG_PAVALUE = 2;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("TAG_PATYPE")
#pragma pop_macro("TAG_PAVALUE")

#endif // _sun_security_krb5_internal_PAData_h_