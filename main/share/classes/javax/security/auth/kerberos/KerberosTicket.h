#ifndef _javax_security_auth_kerberos_KerberosTicket_h_
#define _javax_security_auth_kerberos_KerberosTicket_h_
//$ class javax.security.auth.kerberos.KerberosTicket
//$ extends javax.security.auth.Destroyable
//$ implements javax.security.auth.Refreshable,java.io.Serializable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <javax/security/auth/Destroyable.h>
#include <javax/security/auth/Refreshable.h>

#pragma push_macro("FORWARDABLE_TICKET_FLAG")
#undef FORWARDABLE_TICKET_FLAG
#pragma push_macro("FORWARDED_TICKET_FLAG")
#undef FORWARDED_TICKET_FLAG
#pragma push_macro("INITIAL_TICKET_FLAG")
#undef INITIAL_TICKET_FLAG
#pragma push_macro("NUM_FLAGS")
#undef NUM_FLAGS
#pragma push_macro("POSTDATED_TICKET_FLAG")
#undef POSTDATED_TICKET_FLAG
#pragma push_macro("PROXIABLE_TICKET_FLAG")
#undef PROXIABLE_TICKET_FLAG
#pragma push_macro("PROXY_TICKET_FLAG")
#undef PROXY_TICKET_FLAG
#pragma push_macro("RENEWABLE_TICKET_FLAG")
#undef RENEWABLE_TICKET_FLAG

namespace java {
	namespace io {
		class ObjectInputStream;
	}
}
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
namespace javax {
	namespace crypto {
		class SecretKey;
	}
}
namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {
				class KerberosPrincipal;
				class KeyImpl;
			}
		}
	}
}

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

class $export KerberosTicket : public ::javax::security::auth::Destroyable, public ::javax::security::auth::Refreshable, public ::java::io::Serializable {
	$class(KerberosTicket, $NO_CLASS_INIT, ::javax::security::auth::Destroyable, ::javax::security::auth::Refreshable, ::java::io::Serializable)
public:
	KerberosTicket();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	virtual $Object* clone() override;
	virtual void finalize() override;
	void init$($bytes* asn1Encoding, ::javax::security::auth::kerberos::KerberosPrincipal* client, ::javax::security::auth::kerberos::KerberosPrincipal* server, $bytes* sessionKey, int32_t keyType, $booleans* flags, ::java::util::Date* authTime, ::java::util::Date* startTime, ::java::util::Date* endTime, ::java::util::Date* renewTill, $Array<::java::net::InetAddress>* clientAddresses);
	virtual void destroy() override;
	virtual bool equals(Object$* other) override;
	::java::util::Date* getAuthTime();
	::javax::security::auth::kerberos::KerberosPrincipal* getClient();
	$Array<::java::net::InetAddress>* getClientAddresses();
	$bytes* getEncoded();
	::java::util::Date* getEndTime();
	$booleans* getFlags();
	::java::util::Date* getRenewTill();
	::javax::security::auth::kerberos::KerberosPrincipal* getServer();
	::javax::crypto::SecretKey* getSessionKey();
	int32_t getSessionKeyType();
	::java::util::Date* getStartTime();
	virtual int32_t hashCode() override;
	void init($bytes* asn1Encoding, ::javax::security::auth::kerberos::KerberosPrincipal* client, ::javax::security::auth::kerberos::KerberosPrincipal* server, $bytes* sessionKey, int32_t keyType, $booleans* flags, ::java::util::Date* authTime, ::java::util::Date* startTime, ::java::util::Date* endTime, ::java::util::Date* renewTill, $Array<::java::net::InetAddress>* clientAddresses);
	void init($bytes* asn1Encoding, ::javax::security::auth::kerberos::KerberosPrincipal* client, ::javax::security::auth::kerberos::KerberosPrincipal* server, ::javax::security::auth::kerberos::KeyImpl* sessionKey, $booleans* flags, ::java::util::Date* authTime, ::java::util::Date* startTime, ::java::util::Date* endTime, ::java::util::Date* renewTill, $Array<::java::net::InetAddress>* clientAddresses);
	virtual bool isCurrent() override;
	virtual bool isDestroyed() override;
	bool isForwardable();
	bool isForwarded();
	bool isInitial();
	bool isPostdated();
	bool isProxiable();
	bool isProxy();
	bool isRenewable();
	void readObject(::java::io::ObjectInputStream* s);
	virtual void refresh() override;
	virtual $String* toString() override;
	static const int64_t serialVersionUID = (int64_t)0x66A1816D7077C3BB;
	static const int32_t FORWARDABLE_TICKET_FLAG = 1;
	static const int32_t FORWARDED_TICKET_FLAG = 2;
	static const int32_t PROXIABLE_TICKET_FLAG = 3;
	static const int32_t PROXY_TICKET_FLAG = 4;
	static const int32_t POSTDATED_TICKET_FLAG = 6;
	static const int32_t RENEWABLE_TICKET_FLAG = 8;
	static const int32_t INITIAL_TICKET_FLAG = 9;
	static const int32_t NUM_FLAGS = 32;
	$bytes* asn1Encoding = nullptr;
	::javax::security::auth::kerberos::KeyImpl* sessionKey = nullptr;
	$booleans* flags = nullptr;
	::java::util::Date* authTime = nullptr;
	::java::util::Date* startTime = nullptr;
	::java::util::Date* endTime = nullptr;
	::java::util::Date* renewTill = nullptr;
	::javax::security::auth::kerberos::KerberosPrincipal* client = nullptr;
	::javax::security::auth::kerberos::KerberosPrincipal* server = nullptr;
	$Array<::java::net::InetAddress>* clientAddresses = nullptr;
	::javax::security::auth::kerberos::KerberosTicket* proxy = nullptr;
	bool destroyed = false;
	::javax::security::auth::kerberos::KerberosPrincipal* clientAlias = nullptr;
	::javax::security::auth::kerberos::KerberosPrincipal* serverAlias = nullptr;
};

			} // kerberos
		} // auth
	} // security
} // javax

#pragma pop_macro("FORWARDABLE_TICKET_FLAG")
#pragma pop_macro("FORWARDED_TICKET_FLAG")
#pragma pop_macro("INITIAL_TICKET_FLAG")
#pragma pop_macro("NUM_FLAGS")
#pragma pop_macro("POSTDATED_TICKET_FLAG")
#pragma pop_macro("PROXIABLE_TICKET_FLAG")
#pragma pop_macro("PROXY_TICKET_FLAG")
#pragma pop_macro("RENEWABLE_TICKET_FLAG")

#endif // _javax_security_auth_kerberos_KerberosTicket_h_