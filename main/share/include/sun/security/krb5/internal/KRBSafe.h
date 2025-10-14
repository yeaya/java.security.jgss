#ifndef _sun_security_krb5_internal_KRBSafe_h_
#define _sun_security_krb5_internal_KRBSafe_h_
//$ class sun.security.krb5.internal.KRBSafe
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class Checksum;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class KRBSafeBody;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import KRBSafe : public ::java::lang::Object {
	$class(KRBSafe, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KRBSafe();
	void init$(::sun::security::krb5::internal::KRBSafeBody* new_safeBody, ::sun::security::krb5::Checksum* new_cksum);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	void init(::sun::security::util::DerValue* encoding);
	int32_t pvno = 0;
	int32_t msgType = 0;
	::sun::security::krb5::internal::KRBSafeBody* safeBody = nullptr;
	::sun::security::krb5::Checksum* cksum = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_KRBSafe_h_