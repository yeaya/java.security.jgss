#ifndef _sun_security_krb5_KdcComm$BpType_h_
#define _sun_security_krb5_KdcComm$BpType_h_
//$ class sun.security.krb5.KdcComm$BpType
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("NONE")
#undef NONE
#pragma push_macro("TRY_LAST")
#undef TRY_LAST
#pragma push_macro("TRY_LESS")
#undef TRY_LESS

namespace sun {
	namespace security {
		namespace krb5 {

class KdcComm$BpType : public ::java::lang::Enum {
	$class(KdcComm$BpType, 0, ::java::lang::Enum)
public:
	KdcComm$BpType();
	static $Array<::sun::security::krb5::KdcComm$BpType>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::sun::security::krb5::KdcComm$BpType* valueOf($String* name);
	static $Array<::sun::security::krb5::KdcComm$BpType>* values();
	static ::sun::security::krb5::KdcComm$BpType* NONE;
	static ::sun::security::krb5::KdcComm$BpType* TRY_LAST;
	static ::sun::security::krb5::KdcComm$BpType* TRY_LESS;
	static $Array<::sun::security::krb5::KdcComm$BpType>* $VALUES;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("NONE")
#pragma pop_macro("TRY_LAST")
#pragma pop_macro("TRY_LESS")

#endif // _sun_security_krb5_KdcComm$BpType_h_