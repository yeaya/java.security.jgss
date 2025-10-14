#ifndef _sun_security_jgss_krb5_SubjectComber_h_
#define _sun_security_jgss_krb5_SubjectComber_h_
//$ class sun.security.jgss.krb5.SubjectComber
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace util {
		class List;
	}
}
namespace javax {
	namespace security {
		namespace auth {
			class Subject;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class SubjectComber : public ::java::lang::Object {
	$class(SubjectComber, 0, ::java::lang::Object)
public:
	SubjectComber();
	void init$();
	static $Object* find(::javax::security::auth::Subject* subject, $String* serverPrincipal, $String* clientPrincipal, $Class* credClass);
	static $Object* findAux(::javax::security::auth::Subject* subject, $String* serverPrincipal, $String* clientPrincipal, $Class* credClass, bool oneOnly);
	static ::java::util::List* findMany(::javax::security::auth::Subject* subject, $String* serverPrincipal, $String* clientPrincipal, $Class* credClass);
	static bool DEBUG;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_jgss_krb5_SubjectComber_h_