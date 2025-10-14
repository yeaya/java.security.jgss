#ifndef _sun_security_jgss_krb5_AcceptSecContextToken_h_
#define _sun_security_jgss_krb5_AcceptSecContextToken_h_
//$ class sun.security.jgss.krb5.AcceptSecContextToken
//$ extends sun.security.jgss.krb5.InitialToken

#include <java/lang/Array.h>
#include <sun/security/jgss/krb5/InitialToken.h>

namespace java {
	namespace io {
		class InputStream;
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class Krb5Context;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class KrbApRep;
			class KrbApReq;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class AcceptSecContextToken : public ::sun::security::jgss::krb5::InitialToken {
	$class(AcceptSecContextToken, $NO_CLASS_INIT, ::sun::security::jgss::krb5::InitialToken)
public:
	AcceptSecContextToken();
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::sun::security::krb5::KrbApReq* apReq);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::sun::security::krb5::Credentials* serviceCreds, ::sun::security::krb5::KrbApReq* apReq, ::java::io::InputStream* is);
	virtual $bytes* encode() override;
	::sun::security::krb5::KrbApRep* apRep = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_AcceptSecContextToken_h_