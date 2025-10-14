#ifndef _sun_security_krb5_Config$1_h_
#define _sun_security_krb5_Config$1_h_
//$ class sun.security.krb5.Config$1
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace java {
	namespace nio {
		namespace file {
			class Path;
		}
	}
}
namespace java {
	namespace util {
		class List;
		class Set;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Config;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class Config$1 : public ::java::security::PrivilegedExceptionAction {
	$class(Config$1, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	Config$1();
	void init$(::sun::security::krb5::Config* this$0, $String* val$fileName, ::java::nio::file::Path* val$fullp, ::java::util::List* val$raw, ::java::util::Set* val$dupsCheck);
	virtual $Object* run() override;
	::sun::security::krb5::Config* this$0 = nullptr;
	::java::util::Set* val$dupsCheck = nullptr;
	::java::util::List* val$raw = nullptr;
	::java::nio::file::Path* val$fullp = nullptr;
	$String* val$fileName = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_Config$1_h_