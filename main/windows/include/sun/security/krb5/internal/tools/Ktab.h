#ifndef _sun_security_krb5_internal_tools_Ktab_h_
#define _sun_security_krb5_internal_tools_Ktab_h_
//$ class sun.security.krb5.internal.tools.Ktab
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {
					class KeyTab;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace tools {

class $import Ktab : public ::java::lang::Object {
	$class(Ktab, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Ktab();
	void init$();
	virtual void addEntry();
	virtual void deleteEntry();
	virtual void error($StringArray* errors);
	virtual void listKt();
	static void main($StringArray* args);
	virtual void printHelp();
	virtual void processArgs($StringArray* args);
	::sun::security::krb5::internal::ktab::KeyTab* table = nullptr;
	char16_t action = 0;
	$String* name = nullptr;
	$String* principal = nullptr;
	bool showEType = false;
	bool showTime = false;
	int32_t etype = 0;
	$chars* password = nullptr;
	bool forced = false;
	bool append = false;
	int32_t vDel = 0;
	int32_t vAdd = 0;
};

				} // tools
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_tools_Ktab_h_