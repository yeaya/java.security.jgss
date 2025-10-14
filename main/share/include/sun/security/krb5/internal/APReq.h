#ifndef _sun_security_krb5_internal_APReq_h_
#define _sun_security_krb5_internal_APReq_h_
//$ class sun.security.krb5.internal.APReq
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
				class APOptions;
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

class $import APReq : public ::java::lang::Object {
	$class(APReq, $NO_CLASS_INIT, ::java::lang::Object)
public:
	APReq();
	void init$(::sun::security::krb5::internal::APOptions* new_apOptions, ::sun::security::krb5::internal::Ticket* new_ticket, ::sun::security::krb5::EncryptedData* new_authenticator);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	void init(::sun::security::util::DerValue* encoding);
	int32_t pvno = 0;
	int32_t msgType = 0;
	::sun::security::krb5::internal::APOptions* apOptions = nullptr;
	::sun::security::krb5::internal::Ticket* ticket = nullptr;
	::sun::security::krb5::EncryptedData* authenticator = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_APReq_h_