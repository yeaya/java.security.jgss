#ifndef _sun_security_krb5_internal_tools_KinitOptions_h_
#define _sun_security_krb5_internal_tools_KinitOptions_h_
//$ class sun.security.krb5.internal.tools.KinitOptions
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

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
				class KerberosTime;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace tools {

class KinitOptions : public ::java::lang::Object {
	$class(KinitOptions, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KinitOptions();
	void init$();
	void init$($StringArray* args);
	virtual bool getAddressOption();
	virtual ::sun::security::krb5::PrincipalName* getDefaultPrincipal();
	virtual $String* getKDCRealm();
	virtual ::sun::security::krb5::PrincipalName* getPrincipal();
	::sun::security::krb5::internal::KerberosTime* getTime(int32_t s);
	virtual $String* keytabFileName();
	virtual void printHelp();
	virtual void setKDCRealm($String* r);
	virtual bool useKeytabFile();
	int32_t action = 0;
	int16_t forwardable = 0;
	int16_t proxiable = 0;
	::sun::security::krb5::internal::KerberosTime* lifetime = nullptr;
	::sun::security::krb5::internal::KerberosTime* renewable_lifetime = nullptr;
	$String* target_service = nullptr;
	$String* keytab_file = nullptr;
	$String* cachename = nullptr;
	::sun::security::krb5::PrincipalName* principal = nullptr;
	$String* realm = nullptr;
	$chars* password = nullptr;
	bool keytab = false;
	bool DEBUG = false;
	bool includeAddresses = false;
	bool useKeytab = false;
	$String* ktabName = nullptr;
};

				} // tools
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_tools_KinitOptions_h_