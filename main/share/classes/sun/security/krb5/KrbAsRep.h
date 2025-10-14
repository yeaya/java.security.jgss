#ifndef _sun_security_krb5_KrbAsRep_h_
#define _sun_security_krb5_KrbAsRep_h_
//$ class sun.security.krb5.KrbAsRep
//$ extends sun.security.krb5.KrbKdcRep

#include <java/lang/Array.h>
#include <sun/security/krb5/KrbKdcRep.h>

#pragma push_macro("DEBUG")
#undef DEBUG

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
			class KrbAsReq;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class ASRep;
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

class KrbAsRep : public ::sun::security::krb5::KrbKdcRep {
	$class(KrbAsRep, $NO_CLASS_INIT, ::sun::security::krb5::KrbKdcRep)
public:
	KrbAsRep();
	void init$($bytes* ibuf);
	void decrypt(::sun::security::krb5::EncryptionKey* dkey, ::sun::security::krb5::KrbAsReq* asReq, ::sun::security::krb5::PrincipalName* cname);
	virtual void decryptUsingKeyTab(::javax::security::auth::kerberos::KeyTab* ktab, ::sun::security::krb5::KrbAsReq* asReq, ::sun::security::krb5::PrincipalName* cname);
	virtual void decryptUsingPassword($chars* password, ::sun::security::krb5::KrbAsReq* asReq, ::sun::security::krb5::PrincipalName* cname);
	virtual ::sun::security::krb5::internal::ccache::Credentials* getCCreds();
	virtual ::sun::security::krb5::Credentials* getCreds();
	virtual $Array<::sun::security::krb5::internal::PAData>* getPA();
	::sun::security::krb5::internal::ASRep* rep = nullptr;
	::sun::security::krb5::Credentials* creds = nullptr;
	bool DEBUG = false;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_KrbAsRep_h_