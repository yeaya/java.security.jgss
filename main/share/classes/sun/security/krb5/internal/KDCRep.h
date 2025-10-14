#ifndef _sun_security_krb5_internal_KDCRep_h_
#define _sun_security_krb5_internal_KDCRep_h_
//$ class sun.security.krb5.internal.KDCRep
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptedData;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class EncKDCRepPart;
				class PAData;
				class Ticket;
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

class $export KDCRep : public ::java::lang::Object {
	$class(KDCRep, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KDCRep();
	void init$($Array<::sun::security::krb5::internal::PAData>* new_pAData, ::sun::security::krb5::PrincipalName* new_cname, ::sun::security::krb5::internal::Ticket* new_ticket, ::sun::security::krb5::EncryptedData* new_encPart, int32_t req_type);
	void init$();
	void init$($bytes* data, int32_t req_type);
	void init$(::sun::security::util::DerValue* encoding, int32_t req_type);
	virtual $bytes* asn1Encode();
	virtual void init(::sun::security::util::DerValue* encoding, int32_t req_type);
	::sun::security::krb5::PrincipalName* cname = nullptr;
	::sun::security::krb5::internal::Ticket* ticket = nullptr;
	::sun::security::krb5::EncryptedData* encPart = nullptr;
	::sun::security::krb5::internal::EncKDCRepPart* encKDCRepPart = nullptr;
	int32_t pvno = 0;
	int32_t msgType = 0;
	$Array<::sun::security::krb5::internal::PAData>* pAData = nullptr;
	bool DEBUG = false;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_KDCRep_h_