#ifndef _sun_security_krb5_internal_KDCReq_h_
#define _sun_security_krb5_internal_KDCReq_h_
//$ class sun.security.krb5.internal.KDCReq
//$ extends java.lang.Object

#include <java/lang/Array.h>

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

class $import KDCReq : public ::java::lang::Object {
	$class(KDCReq, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KDCReq();
	void init$($Array<::sun::security::krb5::internal::PAData>* new_pAData, ::sun::security::krb5::internal::KDCReqBody* new_reqBody, int32_t req_type);
	void init$();
	void init$($bytes* data, int32_t req_type);
	void init$(::sun::security::util::DerValue* der, int32_t req_type);
	virtual $bytes* asn1Encode();
	virtual $bytes* asn1EncodeReqBody();
	virtual void init(::sun::security::util::DerValue* encoding, int32_t req_type);
	::sun::security::krb5::internal::KDCReqBody* reqBody = nullptr;
	$Array<::sun::security::krb5::internal::PAData>* pAData = nullptr;
	int32_t pvno = 0;
	int32_t msgType = 0;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_KDCReq_h_