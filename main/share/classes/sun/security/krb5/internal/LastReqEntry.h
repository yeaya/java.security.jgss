#ifndef _sun_security_krb5_internal_LastReqEntry_h_
#define _sun_security_krb5_internal_LastReqEntry_h_
//$ class sun.security.krb5.internal.LastReqEntry
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class KerberosTime;
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

class $export LastReqEntry : public ::java::lang::Object {
	$class(LastReqEntry, $NO_CLASS_INIT, ::java::lang::Object)
public:
	LastReqEntry();
	void init$();
	void init$(int32_t Type, ::sun::security::krb5::internal::KerberosTime* time);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	int32_t lrType = 0;
	::sun::security::krb5::internal::KerberosTime* lrValue = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_LastReqEntry_h_