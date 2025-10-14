#ifndef _sun_security_krb5_KrbCred_h_
#define _sun_security_krb5_KrbCred_h_
//$ class sun.security.krb5.KrbCred
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			class Credentials;
			class EncryptionKey;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class EncKrbCredPart;
				class KRBCred;
				class KerberosTime;
				class Ticket;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $export KrbCred : public ::java::lang::Object {
	$class(KrbCred, 0, ::java::lang::Object)
public:
	KrbCred();
	void init$(::sun::security::krb5::Credentials* tgt, ::sun::security::krb5::Credentials* serviceTicket, ::sun::security::krb5::EncryptionKey* key);
	void init$($bytes* asn1Message, ::sun::security::krb5::EncryptionKey* key);
	virtual ::sun::security::krb5::internal::KRBCred* createMessage(::sun::security::krb5::Credentials* delegatedCreds, ::sun::security::krb5::EncryptionKey* key);
	virtual $Array<::sun::security::krb5::Credentials>* getDelegatedCreds();
	virtual $bytes* getMessage();
	static bool DEBUG;
	$bytes* obuf = nullptr;
	::sun::security::krb5::internal::KRBCred* credMessg = nullptr;
	::sun::security::krb5::internal::Ticket* ticket = nullptr;
	::sun::security::krb5::internal::EncKrbCredPart* encPart = nullptr;
	::sun::security::krb5::Credentials* creds = nullptr;
	::sun::security::krb5::internal::KerberosTime* timeStamp = nullptr;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_KrbCred_h_