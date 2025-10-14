#ifndef _sun_security_krb5_KerberosSecrets_h_
#define _sun_security_krb5_KerberosSecrets_h_
//$ class sun.security.krb5.KerberosSecrets
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class JavaxSecurityAuthKerberosAccess;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import KerberosSecrets : public ::java::lang::Object {
	$class(KerberosSecrets, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KerberosSecrets();
	void init$();
	static ::sun::security::krb5::JavaxSecurityAuthKerberosAccess* getJavaxSecurityAuthKerberosAccess();
	static void setJavaxSecurityAuthKerberosAccess(::sun::security::krb5::JavaxSecurityAuthKerberosAccess* jsaka);
	static ::sun::security::krb5::JavaxSecurityAuthKerberosAccess* javaxSecurityAuthKerberosAccess;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KerberosSecrets_h_