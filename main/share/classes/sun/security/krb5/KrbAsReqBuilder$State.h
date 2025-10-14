#ifndef _sun_security_krb5_KrbAsReqBuilder$State_h_
#define _sun_security_krb5_KrbAsReqBuilder$State_h_
//$ class sun.security.krb5.KrbAsReqBuilder$State
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("DESTROYED")
#undef DESTROYED
#pragma push_macro("INIT")
#undef INIT
#pragma push_macro("REQ_OK")
#undef REQ_OK

namespace sun {
	namespace security {
		namespace krb5 {

class KrbAsReqBuilder$State : public ::java::lang::Enum {
	$class(KrbAsReqBuilder$State, 0, ::java::lang::Enum)
public:
	KrbAsReqBuilder$State();
	static $Array<::sun::security::krb5::KrbAsReqBuilder$State>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::sun::security::krb5::KrbAsReqBuilder$State* valueOf($String* name);
	static $Array<::sun::security::krb5::KrbAsReqBuilder$State>* values();
	static ::sun::security::krb5::KrbAsReqBuilder$State* INIT;
	static ::sun::security::krb5::KrbAsReqBuilder$State* REQ_OK;
	static ::sun::security::krb5::KrbAsReqBuilder$State* DESTROYED;
	static $Array<::sun::security::krb5::KrbAsReqBuilder$State>* $VALUES;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DESTROYED")
#pragma pop_macro("INIT")
#pragma pop_macro("REQ_OK")

#endif // _sun_security_krb5_KrbAsReqBuilder$State_h_