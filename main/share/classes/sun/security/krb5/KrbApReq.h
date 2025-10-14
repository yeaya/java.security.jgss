#ifndef _sun_security_krb5_KrbApReq_h_
#define _sun_security_krb5_KrbApReq_h_
//$ class sun.security.krb5.KrbApReq
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace lang {
		class Integer;
	}
}
namespace java {
	namespace net {
		class InetAddress;
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class Krb5AcceptCredential;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Checksum;
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
				class APOptions;
				class APReq;
				class Authenticator;
				class AuthorizationData;
				class KerberosTime;
				class ReplayCache;
				class SeqNumber;
				class Ticket;
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

class $export KrbApReq : public ::java::lang::Object {
	$class(KrbApReq, 0, ::java::lang::Object)
public:
	KrbApReq();
	void init$(::sun::security::krb5::Credentials* tgsCred, bool mutualRequired, bool useSubKey, bool useSeqNumber, ::sun::security::krb5::Checksum* cksum);
	void init$($bytes* message, ::sun::security::jgss::krb5::Krb5AcceptCredential* cred, ::java::net::InetAddress* initiator);
	void init$(::sun::security::krb5::internal::APOptions* apOptions, ::sun::security::krb5::internal::Ticket* ticket, ::sun::security::krb5::EncryptionKey* key, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::Checksum* cksum, ::sun::security::krb5::internal::KerberosTime* ctime, ::sun::security::krb5::EncryptionKey* subKey, ::sun::security::krb5::internal::SeqNumber* seqNumber, ::sun::security::krb5::internal::AuthorizationData* authorizationData);
	void authenticate(::sun::security::jgss::krb5::Krb5AcceptCredential* cred, ::java::net::InetAddress* initiator);
	static void checkPermittedEType(int32_t target);
	void createMessage(::sun::security::krb5::internal::APOptions* apOptions, ::sun::security::krb5::internal::Ticket* ticket, ::sun::security::krb5::EncryptionKey* key, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::Checksum* cksum, ::sun::security::krb5::internal::KerberosTime* ctime, ::sun::security::krb5::EncryptionKey* subKey, ::sun::security::krb5::internal::SeqNumber* seqNumber, ::sun::security::krb5::internal::AuthorizationData* authorizationData, int32_t usage);
	virtual int32_t cusec();
	virtual void decode();
	virtual void decode(::sun::security::util::DerValue* encoding);
	virtual ::sun::security::krb5::internal::APOptions* getAPOptions();
	virtual ::sun::security::krb5::Checksum* getChecksum();
	virtual ::sun::security::krb5::PrincipalName* getClient();
	virtual ::sun::security::krb5::Credentials* getCreds();
	virtual ::sun::security::krb5::internal::KerberosTime* getCtime();
	virtual $bytes* getMessage();
	virtual bool getMutualAuthRequired();
	virtual ::java::lang::Integer* getSeqNumber();
	virtual ::sun::security::krb5::EncryptionKey* getSubKey();
	void init(::sun::security::krb5::internal::APOptions* options, ::sun::security::krb5::Credentials* tgs_creds, ::sun::security::krb5::Checksum* cksum, ::sun::security::krb5::EncryptionKey* subKey, ::sun::security::krb5::internal::SeqNumber* seqNumber, ::sun::security::krb5::internal::AuthorizationData* authorizationData, int32_t usage);
	void init(::sun::security::krb5::internal::APOptions* apOptions, ::sun::security::krb5::internal::Ticket* ticket, ::sun::security::krb5::EncryptionKey* key, ::sun::security::krb5::PrincipalName* cname, ::sun::security::krb5::Checksum* cksum, ::sun::security::krb5::internal::KerberosTime* ctime, ::sun::security::krb5::EncryptionKey* subKey, ::sun::security::krb5::internal::SeqNumber* seqNumber, ::sun::security::krb5::internal::AuthorizationData* authorizationData, int32_t usage);
	virtual bool useSessionKey();
	$bytes* obuf = nullptr;
	::sun::security::krb5::internal::KerberosTime* ctime = nullptr;
	int32_t cusec$ = 0;
	::sun::security::krb5::internal::Authenticator* authenticator = nullptr;
	::sun::security::krb5::Credentials* creds = nullptr;
	::sun::security::krb5::internal::APReq* apReqMessg = nullptr;
	static ::sun::security::krb5::internal::ReplayCache* rcache;
	static bool DEBUG;
	static $chars* hexConst;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_KrbApReq_h_