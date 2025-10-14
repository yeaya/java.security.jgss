#ifndef _sun_security_krb5_internal_ccache_FileCredentialsCache$1_h_
#define _sun_security_krb5_internal_ccache_FileCredentialsCache$1_h_
//$ class sun.security.krb5.internal.ccache.FileCredentialsCache$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

class FileCredentialsCache$1 : public ::java::security::PrivilegedAction {
	$class(FileCredentialsCache$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	FileCredentialsCache$1();
	void init$();
	virtual $Object* run() override;
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ccache_FileCredentialsCache$1_h_