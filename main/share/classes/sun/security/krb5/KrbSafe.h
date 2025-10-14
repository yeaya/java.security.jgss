#ifndef _sun_security_krb5_KrbSafe_h_
#define _sun_security_krb5_KrbSafe_h_
//$ class sun.security.krb5.KrbSafe
//$ extends sun.security.krb5.KrbAppMessage

#include <java/lang/Array.h>
#include <sun/security/krb5/KrbAppMessage.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class EncryptionKey;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class HostAddress;
				class KRBSafe;
				class KerberosTime;
				class SeqNumber;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class KrbSafe : public ::sun::security::krb5::KrbAppMessage {
	$class(KrbSafe, $NO_CLASS_INIT, ::sun::security::krb5::KrbAppMessage)
public:
	KrbSafe();
	void init$($bytes* userData, ::sun::security::krb5::Credentials* creds, ::sun::security::krb5::EncryptionKey* subKey, ::sun::security::krb5::internal::KerberosTime* timestamp, ::sun::security::krb5::internal::SeqNumber* seqNumber, ::sun::security::krb5::internal::HostAddress* saddr, ::sun::security::krb5::internal::HostAddress* raddr);
	void init$($bytes* msg, ::sun::security::krb5::Credentials* creds, ::sun::security::krb5::EncryptionKey* subKey, ::sun::security::krb5::internal::SeqNumber* seqNumber, ::sun::security::krb5::internal::HostAddress* saddr, ::sun::security::krb5::internal::HostAddress* raddr, bool timestampRequired, bool seqNumberRequired);
	virtual $bytes* getData();
	virtual $bytes* getMessage();
	$bytes* mk_safe($bytes* userData, ::sun::security::krb5::EncryptionKey* key, ::sun::security::krb5::internal::KerberosTime* timestamp, ::sun::security::krb5::internal::SeqNumber* seqNumber, ::sun::security::krb5::internal::HostAddress* sAddress, ::sun::security::krb5::internal::HostAddress* rAddress);
	$bytes* rd_safe(::sun::security::krb5::internal::KRBSafe* krb_safe, ::sun::security::krb5::EncryptionKey* key, ::sun::security::krb5::internal::SeqNumber* seqNumber, ::sun::security::krb5::internal::HostAddress* sAddress, ::sun::security::krb5::internal::HostAddress* rAddress, bool timestampRequired, bool seqNumberRequired, ::sun::security::krb5::PrincipalName* cname);
	$bytes* obuf = nullptr;
	$bytes* userData = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbSafe_h_