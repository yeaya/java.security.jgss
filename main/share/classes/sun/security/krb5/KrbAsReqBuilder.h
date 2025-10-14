#ifndef _sun_security_krb5_KrbAsReqBuilder_h_
#define _sun_security_krb5_KrbAsReqBuilder_h_
//$ class sun.security.krb5.KrbAsReqBuilder
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KeyTab;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class EncryptionKey;
			class KrbAsRep;
			class KrbAsReq;
			class KrbAsReqBuilder$ReferralsState;
			class KrbAsReqBuilder$State;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
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
			namespace internal {
				namespace ccache {
					class Credentials;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $export KrbAsReqBuilder : public ::java::lang::Object {
	$class(KrbAsReqBuilder, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KrbAsReqBuilder();
	void init$(::sun::security::krb5::PrincipalName* cname, ::javax::security::auth::kerberos::KeyTab* ktab);
	void init$(::sun::security::krb5::PrincipalName* cname, $chars* pass);
	::sun::security::krb5::KrbAsReqBuilder* action();
	::sun::security::krb5::KrbAsReq* build(::sun::security::krb5::EncryptionKey* key, ::sun::security::krb5::KrbAsReqBuilder$ReferralsState* referralsState);
	void checkState(::sun::security::krb5::KrbAsReqBuilder$State* st, $String* msg);
	void destroy();
	::sun::security::krb5::internal::ccache::Credentials* getCCreds();
	::sun::security::krb5::Credentials* getCreds();
	$Array<::sun::security::krb5::EncryptionKey>* getKeys(bool isInitiator);
	void init(::sun::security::krb5::PrincipalName* cname);
	::sun::security::krb5::KrbAsReqBuilder* resolve();
	::sun::security::krb5::KrbAsReqBuilder* send();
	void setAddresses(::sun::security::krb5::internal::HostAddresses* addresses);
	void setOptions(::sun::security::krb5::internal::KDCOptions* options);
	void setRTime(::sun::security::krb5::internal::KerberosTime* rtime);
	void setTarget(::sun::security::krb5::PrincipalName* sname);
	void setTill(::sun::security::krb5::internal::KerberosTime* till);
	::sun::security::krb5::internal::KDCOptions* options = nullptr;
	::sun::security::krb5::PrincipalName* cname = nullptr;
	::sun::security::krb5::PrincipalName* refCname = nullptr;
	::sun::security::krb5::PrincipalName* sname = nullptr;
	::sun::security::krb5::internal::KerberosTime* from = nullptr;
	::sun::security::krb5::internal::KerberosTime* till = nullptr;
	::sun::security::krb5::internal::KerberosTime* rtime = nullptr;
	::sun::security::krb5::internal::HostAddresses* addresses = nullptr;
	$chars* password = nullptr;
	::javax::security::auth::kerberos::KeyTab* ktab = nullptr;
	$Array<::sun::security::krb5::internal::PAData>* paList = nullptr;
	::sun::security::krb5::KrbAsReq* req = nullptr;
	::sun::security::krb5::KrbAsRep* rep = nullptr;
	::sun::security::krb5::KrbAsReqBuilder$State* state = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbAsReqBuilder_h_