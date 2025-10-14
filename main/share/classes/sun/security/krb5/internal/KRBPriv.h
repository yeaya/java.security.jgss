#ifndef _sun_security_krb5_internal_KRBPriv_h_
#define _sun_security_krb5_internal_KRBPriv_h_
//$ class sun.security.krb5.internal.KRBPriv
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
		namespace util {
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export KRBPriv : public ::java::lang::Object {
	$class(KRBPriv, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KRBPriv();
	void init$(::sun::security::krb5::EncryptedData* new_encPart);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	void init(::sun::security::util::DerValue* encoding);
	int32_t pvno = 0;
	int32_t msgType = 0;
	::sun::security::krb5::EncryptedData* encPart = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_KRBPriv_h_