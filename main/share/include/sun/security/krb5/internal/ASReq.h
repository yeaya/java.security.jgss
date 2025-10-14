#ifndef _sun_security_krb5_internal_ASReq_h_
#define _sun_security_krb5_internal_ASReq_h_
//$ class sun.security.krb5.internal.ASReq
//$ extends sun.security.krb5.internal.KDCReq

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/KDCReq.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class KDCReqBody;
				class PAData;
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

class $import ASReq : public ::sun::security::krb5::internal::KDCReq {
	$class(ASReq, $NO_CLASS_INIT, ::sun::security::krb5::internal::KDCReq)
public:
	ASReq();
	using ::sun::security::krb5::internal::KDCReq::init;
	void init$($Array<::sun::security::krb5::internal::PAData>* new_pAData, ::sun::security::krb5::internal::KDCReqBody* new_reqBody);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	void init(::sun::security::util::DerValue* encoding);
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ASReq_h_