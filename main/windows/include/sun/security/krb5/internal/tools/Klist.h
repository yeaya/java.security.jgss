#ifndef _sun_security_krb5_internal_tools_Klist_h_
#define _sun_security_krb5_internal_tools_Klist_h_
//$ class sun.security.krb5.internal.tools.Klist
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

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

class $import Klist : public ::java::lang::Object {
	$class(Klist, 0, ::java::lang::Object)
public:
	Klist();
	void init$();
	virtual void displayCache();
	virtual void displayMessage($String* target);
	virtual void displayTab();
	$String* format(::sun::security::krb5::internal::KerberosTime* kt);
	static void main($StringArray* args);
	virtual void printHelp();
	virtual void processArgs($StringArray* args);
	$Object* target = nullptr;
	$chars* options = nullptr;
	$String* name = nullptr;
	char16_t action = 0;
	static bool DEBUG;
};

				} // tools
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_tools_Klist_h_