#ifndef _sun_security_krb5_internal_KRBCred_h_
#define _sun_security_krb5_internal_KRBCred_h_
//$ class sun.security.krb5.internal.KRBCred
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptedData;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
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

class $export KRBCred : public ::java::lang::Object {
	$class(KRBCred, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KRBCred();
	void init$($Array<::sun::security::krb5::internal::Ticket>* new_tickets, ::sun::security::krb5::EncryptedData* new_encPart);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	void init(::sun::security::util::DerValue* encoding);
	$Array<::sun::security::krb5::internal::Ticket>* tickets = nullptr;
	::sun::security::krb5::EncryptedData* encPart = nullptr;
	int32_t pvno = 0;
	int32_t msgType = 0;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_KRBCred_h_