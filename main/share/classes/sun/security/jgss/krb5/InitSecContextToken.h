#ifndef _sun_security_jgss_krb5_InitSecContextToken_h_
#define _sun_security_jgss_krb5_InitSecContextToken_h_
//$ class sun.security.jgss.krb5.InitSecContextToken
//$ extends sun.security.jgss.krb5.InitialToken

#include <java/lang/Array.h>
#include <sun/security/jgss/krb5/InitialToken.h>

#pragma push_macro("ACCEPTOR_USE_INITIATOR_SEQNUM")
#undef ACCEPTOR_USE_INITIATOR_SEQNUM

namespace java {
	namespace io {
		class InputStream;
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class Krb5AcceptCredential;
				class Krb5Context;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class KrbApReq;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class InitSecContextToken : public ::sun::security::jgss::krb5::InitialToken {
	$class(InitSecContextToken, 0, ::sun::security::jgss::krb5::InitialToken)
public:
	InitSecContextToken();
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::sun::security::krb5::Credentials* tgt, ::sun::security::krb5::Credentials* serviceTicket);
	void init$(::sun::security::jgss::krb5::Krb5Context* context, ::sun::security::jgss::krb5::Krb5AcceptCredential* cred, ::java::io::InputStream* is);
	virtual $bytes* encode() override;
	::sun::security::krb5::KrbApReq* getKrbApReq();
	static bool ACCEPTOR_USE_INITIATOR_SEQNUM;
	::sun::security::krb5::KrbApReq* apReq = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("ACCEPTOR_USE_INITIATOR_SEQNUM")

#endif // _sun_security_jgss_krb5_InitSecContextToken_h_