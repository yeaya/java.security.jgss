#ifndef _sun_security_krb5_internal_AuthContext_h_
#define _sun_security_krb5_internal_AuthContext_h_
//$ class sun.security.krb5.internal.AuthContext
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace util {
		class BitSet;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class Authenticator;
				class HostAddress;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import AuthContext : public ::java::lang::Object {
	$class(AuthContext, $NO_CLASS_INIT, ::java::lang::Object)
public:
	AuthContext();
	void init$();
	::sun::security::krb5::internal::HostAddress* remoteAddress = nullptr;
	int32_t remotePort = 0;
	::sun::security::krb5::internal::HostAddress* localAddress = nullptr;
	int32_t localPort = 0;
	::sun::security::krb5::EncryptionKey* keyBlock = nullptr;
	::sun::security::krb5::EncryptionKey* localSubkey = nullptr;
	::sun::security::krb5::EncryptionKey* remoteSubkey = nullptr;
	::java::util::BitSet* authContextFlags = nullptr;
	int32_t remoteSeqNumber = 0;
	int32_t localSeqNumber = 0;
	::sun::security::krb5::internal::Authenticator* authenticator = nullptr;
	int32_t reqCksumType = 0;
	int32_t safeCksumType = 0;
	$bytes* initializationVector = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_AuthContext_h_