#ifndef _sun_security_krb5_internal_ASRep_h_
#define _sun_security_krb5_internal_ASRep_h_
//$ class sun.security.krb5.internal.ASRep
//$ extends sun.security.krb5.internal.KDCRep

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/KDCRep.h>

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

class $import ASRep : public ::sun::security::krb5::internal::KDCRep {
	$class(ASRep, $NO_CLASS_INIT, ::sun::security::krb5::internal::KDCRep)
public:
	ASRep();
	using ::sun::security::krb5::internal::KDCRep::init;
	void init$($Array<::sun::security::krb5::internal::PAData>* new_pAData, ::sun::security::krb5::PrincipalName* new_cname, ::sun::security::krb5::internal::Ticket* new_ticket, ::sun::security::krb5::EncryptedData* new_encPart);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	void init(::sun::security::util::DerValue* encoding);
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ASRep_h_