#ifndef _sun_security_krb5_internal_CredentialsUtil$S4U2Type_h_
#define _sun_security_krb5_internal_CredentialsUtil$S4U2Type_h_
//$ class sun.security.krb5.internal.CredentialsUtil$S4U2Type
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("NONE")
#undef NONE
#pragma push_macro("PROXY")
#undef PROXY
#pragma push_macro("SELF")
#undef SELF

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class CredentialsUtil$S4U2Type : public ::java::lang::Enum {
	$class(CredentialsUtil$S4U2Type, 0, ::java::lang::Enum)
public:
	CredentialsUtil$S4U2Type();
	static $Array<::sun::security::krb5::internal::CredentialsUtil$S4U2Type>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::sun::security::krb5::internal::CredentialsUtil$S4U2Type* valueOf($String* name);
	static $Array<::sun::security::krb5::internal::CredentialsUtil$S4U2Type>* values();
	static ::sun::security::krb5::internal::CredentialsUtil$S4U2Type* NONE;
	static ::sun::security::krb5::internal::CredentialsUtil$S4U2Type* SELF;
	static ::sun::security::krb5::internal::CredentialsUtil$S4U2Type* PROXY;
	static $Array<::sun::security::krb5::internal::CredentialsUtil$S4U2Type>* $VALUES;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("NONE")
#pragma pop_macro("PROXY")
#pragma pop_macro("SELF")

#endif // _sun_security_krb5_internal_CredentialsUtil$S4U2Type_h_