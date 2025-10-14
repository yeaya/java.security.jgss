#ifndef _sun_security_krb5_internal_ccache_FileCredentialsCache$2_h_
#define _sun_security_krb5_internal_ccache_FileCredentialsCache$2_h_
//$ class sun.security.krb5.internal.ccache.FileCredentialsCache$2
//$ extends java.security.PrivilegedAction

#include <java/lang/Array.h>
#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

class FileCredentialsCache$2 : public ::java::security::PrivilegedAction {
	$class(FileCredentialsCache$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	FileCredentialsCache$2();
	void init$($StringArray* val$command);
	virtual $Object* run() override;
	$StringArray* val$command = nullptr;
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ccache_FileCredentialsCache$2_h_