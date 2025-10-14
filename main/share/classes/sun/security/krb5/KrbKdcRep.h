#ifndef _sun_security_krb5_KrbKdcRep_h_
#define _sun_security_krb5_KrbKdcRep_h_
//$ class sun.security.krb5.KrbKdcRep
//$ extends java.lang.Object

#include <java/lang/Object.h>

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
				class KDCRep;
				class KDCReq;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $export KrbKdcRep : public ::java::lang::Object {
	$class(KrbKdcRep, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KrbKdcRep();
	void init$();
	static void check(bool isAsReq, ::sun::security::krb5::internal::KDCReq* req, ::sun::security::krb5::internal::KDCRep* rep, ::sun::security::krb5::EncryptionKey* replyKey);
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbKdcRep_h_