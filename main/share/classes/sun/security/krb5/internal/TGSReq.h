#ifndef _sun_security_krb5_internal_TGSReq_h_
#define _sun_security_krb5_internal_TGSReq_h_
//$ class sun.security.krb5.internal.TGSReq
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

class $export TGSReq : public ::sun::security::krb5::internal::KDCReq {
	$class(TGSReq, $NO_CLASS_INIT, ::sun::security::krb5::internal::KDCReq)
public:
	TGSReq();
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

#endif // _sun_security_krb5_internal_TGSReq_h_