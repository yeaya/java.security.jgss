#ifndef _sun_security_krb5_internal_PAEncTSEnc_h_
#define _sun_security_krb5_internal_PAEncTSEnc_h_
//$ class sun.security.krb5.internal.PAEncTSEnc
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class Integer;
	}
}
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

class $export PAEncTSEnc : public ::java::lang::Object {
	$class(PAEncTSEnc, $NO_CLASS_INIT, ::java::lang::Object)
public:
	PAEncTSEnc();
	void init$(::sun::security::krb5::internal::KerberosTime* new_pATimeStamp, ::java::lang::Integer* new_pAUSec);
	void init$();
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	::sun::security::krb5::internal::KerberosTime* pATimeStamp = nullptr;
	::java::lang::Integer* pAUSec = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_PAEncTSEnc_h_