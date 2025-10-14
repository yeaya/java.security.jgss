#ifndef _sun_security_krb5_KrbApRep_h_
#define _sun_security_krb5_KrbApRep_h_
//$ class sun.security.krb5.KrbApRep
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
			class Credentials;
			class EncryptionKey;
			class KrbApReq;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class APRep;
				class EncAPRepPart;
				class KerberosTime;
				class SeqNumber;
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

class $import KrbApRep : public ::java::lang::Object {
	$class(KrbApRep, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KrbApRep();
	void init$(::sun::security::krb5::KrbApReq* incomingReq, bool useSeqNumber, ::sun::security::krb5::EncryptionKey* subKey);
	void init$($bytes* message, ::sun::security::krb5::Credentials* tgtCreds, ::sun::security::krb5::KrbApReq* outgoingReq);
	void init$($bytes* msg, ::sun::security::krb5::Credentials* tgs_creds);
	void init$(::sun::security::util::DerValue* encoding, ::sun::security::krb5::Credentials* tgs_creds);
	void authenticate(::sun::security::krb5::KrbApReq* apReq);
	void createMessage(::sun::security::krb5::EncryptionKey* key, ::sun::security::krb5::internal::KerberosTime* ctime, int32_t cusec, ::sun::security::krb5::EncryptionKey* subKey, ::sun::security::krb5::internal::SeqNumber* seqNumber);
	virtual $bytes* getMessage();
	virtual ::java::lang::Integer* getSeqNumber();
	virtual ::sun::security::krb5::EncryptionKey* getSubKey();
	void init(::sun::security::krb5::KrbApReq* apReq, ::sun::security::krb5::EncryptionKey* subKey, ::sun::security::krb5::internal::SeqNumber* seqNumber);
	$bytes* obuf = nullptr;
	$bytes* ibuf = nullptr;
	::sun::security::krb5::internal::EncAPRepPart* encPart = nullptr;
	::sun::security::krb5::internal::APRep* apRepMessg = nullptr;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbApRep_h_