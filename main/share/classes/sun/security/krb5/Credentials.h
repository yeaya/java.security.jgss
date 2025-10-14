#ifndef _sun_security_krb5_Credentials_h_
#define _sun_security_krb5_Credentials_h_
//$ class sun.security.krb5.Credentials
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace net {
		class InetAddress;
	}
}
namespace java {
	namespace util {
		class Date;
	}
}
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
				class AuthorizationData;
				class HostAddresses;
				class KerberosTime;
				class Ticket;
				class TicketFlags;
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
					class CredentialsCache;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $export Credentials : public ::java::lang::Object {
	$class(Credentials, 0, ::java::lang::Object)
public:
	Credentials();
	void init$(::sun::security::krb5::internal::Ticket* new_ticket, ::sun::security::krb5::PrincipalName* new_client, ::sun::security::krb5::PrincipalName* new_client_alias, ::sun::security::krb5::PrincipalName* new_server, ::sun::security::krb5::PrincipalName* new_server_alias, ::sun::security::krb5::EncryptionKey* new_key, ::sun::security::krb5::internal::TicketFlags* new_flags, ::sun::security::krb5::internal::KerberosTime* authTime, ::sun::security::krb5::internal::KerberosTime* new_startTime, ::sun::security::krb5::internal::KerberosTime* new_endTime, ::sun::security::krb5::internal::KerberosTime* renewTill, ::sun::security::krb5::internal::HostAddresses* cAddr, ::sun::security::krb5::internal::AuthorizationData* authzData);
	void init$(::sun::security::krb5::internal::Ticket* new_ticket, ::sun::security::krb5::PrincipalName* new_client, ::sun::security::krb5::PrincipalName* new_client_alias, ::sun::security::krb5::PrincipalName* new_server, ::sun::security::krb5::PrincipalName* new_server_alias, ::sun::security::krb5::EncryptionKey* new_key, ::sun::security::krb5::internal::TicketFlags* new_flags, ::sun::security::krb5::internal::KerberosTime* authTime, ::sun::security::krb5::internal::KerberosTime* new_startTime, ::sun::security::krb5::internal::KerberosTime* new_endTime, ::sun::security::krb5::internal::KerberosTime* renewTill, ::sun::security::krb5::internal::HostAddresses* cAddr);
	void init$($bytes* encoding, $String* client, $String* clientAlias, $String* server, $String* serverAlias, $bytes* keyBytes, int32_t keyType, $booleans* flags, ::java::util::Date* authTime, ::java::util::Date* startTime, ::java::util::Date* endTime, ::java::util::Date* renewTill, $Array<::java::net::InetAddress>* cAddrs);
	static ::sun::security::krb5::Credentials* acquireDefaultCreds();
	static ::sun::security::krb5::Credentials* acquireDefaultNativeCreds($ints* eTypes);
	static ::sun::security::krb5::Credentials* acquireS4U2proxyCreds($String* service, ::sun::security::krb5::internal::Ticket* second, ::sun::security::krb5::PrincipalName* client, ::sun::security::krb5::Credentials* ccreds);
	static ::sun::security::krb5::Credentials* acquireS4U2selfCreds(::sun::security::krb5::PrincipalName* user, ::sun::security::krb5::Credentials* ccreds);
	static ::sun::security::krb5::Credentials* acquireServiceCreds($String* service, ::sun::security::krb5::Credentials* ccreds);
	static ::sun::security::krb5::Credentials* acquireTGTFromCache(::sun::security::krb5::PrincipalName* princ, $String* ticketCache);
	virtual bool checkDelegate();
	static ::sun::security::krb5::internal::KerberosTime* date2kt(::java::util::Date* d);
	static void ensureLoaded();
	::java::util::Date* getAuthTime();
	virtual ::sun::security::krb5::internal::AuthorizationData* getAuthzData();
	virtual ::sun::security::krb5::internal::ccache::CredentialsCache* getCache();
	::sun::security::krb5::PrincipalName* getClient();
	$Array<::java::net::InetAddress>* getClientAddresses();
	::sun::security::krb5::PrincipalName* getClientAlias();
	$bytes* getEncoded();
	::java::util::Date* getEndTime();
	$booleans* getFlags();
	virtual ::sun::security::krb5::Credentials* getProxy();
	::java::util::Date* getRenewTill();
	::sun::security::krb5::PrincipalName* getServer();
	::sun::security::krb5::PrincipalName* getServerAlias();
	::sun::security::krb5::EncryptionKey* getSessionKey();
	::java::util::Date* getStartTime();
	virtual ::sun::security::krb5::internal::Ticket* getTicket();
	virtual ::sun::security::krb5::internal::TicketFlags* getTicketFlags();
	virtual bool isForwardable();
	virtual bool isRenewable();
	static void printDebug(::sun::security::krb5::Credentials* c);
	virtual ::sun::security::krb5::Credentials* renew();
	virtual void resetDelegate();
	virtual ::sun::security::krb5::Credentials* setProxy(::sun::security::krb5::Credentials* proxy);
	virtual ::sun::security::krb5::internal::ccache::Credentials* toCCacheCreds();
	virtual $String* toString() override;
	::sun::security::krb5::internal::Ticket* ticket = nullptr;
	::sun::security::krb5::PrincipalName* client = nullptr;
	::sun::security::krb5::PrincipalName* clientAlias = nullptr;
	::sun::security::krb5::PrincipalName* server = nullptr;
	::sun::security::krb5::PrincipalName* serverAlias = nullptr;
	::sun::security::krb5::EncryptionKey* key = nullptr;
	::sun::security::krb5::internal::TicketFlags* flags = nullptr;
	::sun::security::krb5::internal::KerberosTime* authTime = nullptr;
	::sun::security::krb5::internal::KerberosTime* startTime = nullptr;
	::sun::security::krb5::internal::KerberosTime* endTime = nullptr;
	::sun::security::krb5::internal::KerberosTime* renewTill = nullptr;
	::sun::security::krb5::internal::HostAddresses* cAddr = nullptr;
	::sun::security::krb5::internal::AuthorizationData* authzData = nullptr;
	static bool DEBUG;
	static ::sun::security::krb5::internal::ccache::CredentialsCache* cache;
	static bool alreadyLoaded;
	static bool alreadyTried;
	::sun::security::krb5::Credentials* proxy = nullptr;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_Credentials_h_