#ifndef _sun_security_krb5_KrbAsReq_h_
#define _sun_security_krb5_KrbAsReq_h_
//$ class sun.security.krb5.KrbAsReq
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class ASReq;
				class HostAddresses;
				class KDCOptions;
				class KerberosTime;
				class PAData;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $export KrbAsReq : public ::java::lang::Object {
	$class(KrbAsReq, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KrbAsReq();
	void init$(::sun::security::krb5::EncryptionKey* pakey, ::sun::security::krb5::internal::KDCOptions* options, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::PrincipalName* sname, ::sun::security::krb5::internal::KerberosTime* from, ::sun::security::krb5::internal::KerberosTime* till, ::sun::security::krb5::internal::KerberosTime* rtime, $ints* eTypes, ::sun::security::krb5::internal::HostAddresses* addresses, $Array<::sun::security::krb5::internal::PAData>* extraPAs);
	virtual $bytes* encoding();
	virtual ::sun::security::krb5::internal::ASReq* getMessage();
	::sun::security::krb5::internal::ASReq* asReqMessg = nullptr;
	bool DEBUG = false;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_KrbAsReq_h_