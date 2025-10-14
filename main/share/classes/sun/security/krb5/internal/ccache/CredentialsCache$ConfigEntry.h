#ifndef _sun_security_krb5_internal_ccache_CredentialsCache$ConfigEntry_h_
#define _sun_security_krb5_internal_ccache_CredentialsCache$ConfigEntry_h_
//$ class sun.security.krb5.internal.ccache.CredentialsCache$ConfigEntry
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class PrincipalName;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

class CredentialsCache$ConfigEntry : public ::java::lang::Object {
	$class(CredentialsCache$ConfigEntry, $NO_CLASS_INIT, ::java::lang::Object)
public:
	CredentialsCache$ConfigEntry();
	void init$($String* name, ::sun::security::krb5::PrincipalName* princ, $bytes* data);
	virtual $bytes* getData();
	virtual $String* getName();
	virtual ::sun::security::krb5::PrincipalName* getPrinc();
	virtual ::sun::security::krb5::PrincipalName* getSName();
	virtual $String* toString() override;
	$String* name = nullptr;
	::sun::security::krb5::PrincipalName* princ = nullptr;
	$bytes* data = nullptr;
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ccache_CredentialsCache$ConfigEntry_h_