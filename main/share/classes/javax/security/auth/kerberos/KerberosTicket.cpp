#include <javax/security/auth/kerberos/KerberosTicket.h>

#include <java/io/IOException.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/util/Arrays.h>
#include <java/util/Date.h>
#include <java/util/Objects.h>
#include <javax/crypto/SecretKey.h>
#include <javax/security/auth/DestroyFailedException.h>
#include <javax/security/auth/Destroyable.h>
#include <javax/security/auth/RefreshFailedException.h>
#include <javax/security/auth/kerberos/EncryptionKey.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <javax/security/auth/kerberos/KeyImpl.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef FORWARDABLE_TICKET_FLAG
#undef FORWARDED_TICKET_FLAG
#undef INITIAL_TICKET_FLAG
#undef KRB_NT_SRV_INST
#undef NUM_FLAGS
#undef POSTDATED_TICKET_FLAG
#undef PROXIABLE_TICKET_FLAG
#undef PROXY_TICKET_FLAG
#undef RENEWABLE_TICKET_FLAG

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $IOException = ::java::io::IOException;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $InetAddress = ::java::net::InetAddress;
using $Arrays = ::java::util::Arrays;
using $Date = ::java::util::Date;
using $Objects = ::java::util::Objects;
using $SecretKey = ::javax::crypto::SecretKey;
using $DestroyFailedException = ::javax::security::auth::DestroyFailedException;
using $Destroyable = ::javax::security::auth::Destroyable;
using $RefreshFailedException = ::javax::security::auth::RefreshFailedException;
using $Refreshable = ::javax::security::auth::Refreshable;
using $EncryptionKey = ::javax::security::auth::kerberos::EncryptionKey;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;
using $KeyImpl = ::javax::security::auth::kerberos::KeyImpl;
using $Credentials = ::sun::security::krb5::Credentials;
using $1EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _KerberosTicket_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosTicket, serialVersionUID)},
	{"FORWARDABLE_TICKET_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosTicket, FORWARDABLE_TICKET_FLAG)},
	{"FORWARDED_TICKET_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosTicket, FORWARDED_TICKET_FLAG)},
	{"PROXIABLE_TICKET_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosTicket, PROXIABLE_TICKET_FLAG)},
	{"PROXY_TICKET_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosTicket, PROXY_TICKET_FLAG)},
	{"POSTDATED_TICKET_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosTicket, POSTDATED_TICKET_FLAG)},
	{"RENEWABLE_TICKET_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosTicket, RENEWABLE_TICKET_FLAG)},
	{"INITIAL_TICKET_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosTicket, INITIAL_TICKET_FLAG)},
	{"NUM_FLAGS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KerberosTicket, NUM_FLAGS)},
	{"asn1Encoding", "[B", nullptr, $PRIVATE, $field(KerberosTicket, asn1Encoding)},
	{"sessionKey", "Ljavax/security/auth/kerberos/KeyImpl;", nullptr, $PRIVATE, $field(KerberosTicket, sessionKey)},
	{"flags", "[Z", nullptr, $PRIVATE, $field(KerberosTicket, flags)},
	{"authTime", "Ljava/util/Date;", nullptr, $PRIVATE, $field(KerberosTicket, authTime)},
	{"startTime", "Ljava/util/Date;", nullptr, $PRIVATE, $field(KerberosTicket, startTime)},
	{"endTime", "Ljava/util/Date;", nullptr, $PRIVATE, $field(KerberosTicket, endTime)},
	{"renewTill", "Ljava/util/Date;", nullptr, $PRIVATE, $field(KerberosTicket, renewTill)},
	{"client", "Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PRIVATE, $field(KerberosTicket, client)},
	{"server", "Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PRIVATE, $field(KerberosTicket, server)},
	{"clientAddresses", "[Ljava/net/InetAddress;", nullptr, $PRIVATE, $field(KerberosTicket, clientAddresses)},
	{"proxy", "Ljavax/security/auth/kerberos/KerberosTicket;", nullptr, 0, $field(KerberosTicket, proxy)},
	{"destroyed", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(KerberosTicket, destroyed)},
	{"clientAlias", "Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $TRANSIENT, $field(KerberosTicket, clientAlias)},
	{"serverAlias", "Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $TRANSIENT, $field(KerberosTicket, serverAlias)},
	{}
};

$MethodInfo _KerberosTicket_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "([BLjavax/security/auth/kerberos/KerberosPrincipal;Ljavax/security/auth/kerberos/KerberosPrincipal;[BI[ZLjava/util/Date;Ljava/util/Date;Ljava/util/Date;Ljava/util/Date;[Ljava/net/InetAddress;)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosTicket::*)($bytes*,$KerberosPrincipal*,$KerberosPrincipal*,$bytes*,int32_t,$booleans*,$Date*,$Date*,$Date*,$Date*,$InetAddressArray*)>(&KerberosTicket::init$))},
	{"destroy", "()V", nullptr, $PUBLIC, nullptr, "javax.security.auth.DestroyFailedException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getAuthTime", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Date*(KerberosTicket::*)()>(&KerberosTicket::getAuthTime))},
	{"getClient", "()Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$KerberosPrincipal*(KerberosTicket::*)()>(&KerberosTicket::getClient))},
	{"getClientAddresses", "()[Ljava/net/InetAddress;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$InetAddressArray*(KerberosTicket::*)()>(&KerberosTicket::getClientAddresses))},
	{"getEncoded", "()[B", nullptr, $PUBLIC | $FINAL, $method(static_cast<$bytes*(KerberosTicket::*)()>(&KerberosTicket::getEncoded))},
	{"getEndTime", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Date*(KerberosTicket::*)()>(&KerberosTicket::getEndTime))},
	{"getFlags", "()[Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<$booleans*(KerberosTicket::*)()>(&KerberosTicket::getFlags))},
	{"getRenewTill", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Date*(KerberosTicket::*)()>(&KerberosTicket::getRenewTill))},
	{"getServer", "()Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$KerberosPrincipal*(KerberosTicket::*)()>(&KerberosTicket::getServer))},
	{"getSessionKey", "()Ljavax/crypto/SecretKey;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$SecretKey*(KerberosTicket::*)()>(&KerberosTicket::getSessionKey))},
	{"getSessionKeyType", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(KerberosTicket::*)()>(&KerberosTicket::getSessionKeyType))},
	{"getStartTime", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Date*(KerberosTicket::*)()>(&KerberosTicket::getStartTime))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"init", "([BLjavax/security/auth/kerberos/KerberosPrincipal;Ljavax/security/auth/kerberos/KerberosPrincipal;[BI[ZLjava/util/Date;Ljava/util/Date;Ljava/util/Date;Ljava/util/Date;[Ljava/net/InetAddress;)V", nullptr, $PRIVATE, $method(static_cast<void(KerberosTicket::*)($bytes*,$KerberosPrincipal*,$KerberosPrincipal*,$bytes*,int32_t,$booleans*,$Date*,$Date*,$Date*,$Date*,$InetAddressArray*)>(&KerberosTicket::init))},
	{"init", "([BLjavax/security/auth/kerberos/KerberosPrincipal;Ljavax/security/auth/kerberos/KerberosPrincipal;Ljavax/security/auth/kerberos/KeyImpl;[ZLjava/util/Date;Ljava/util/Date;Ljava/util/Date;Ljava/util/Date;[Ljava/net/InetAddress;)V", nullptr, $PRIVATE, $method(static_cast<void(KerberosTicket::*)($bytes*,$KerberosPrincipal*,$KerberosPrincipal*,$KeyImpl*,$booleans*,$Date*,$Date*,$Date*,$Date*,$InetAddressArray*)>(&KerberosTicket::init))},
	{"isCurrent", "()Z", nullptr, $PUBLIC},
	{"isDestroyed", "()Z", nullptr, $PUBLIC},
	{"isForwardable", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(KerberosTicket::*)()>(&KerberosTicket::isForwardable))},
	{"isForwarded", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(KerberosTicket::*)()>(&KerberosTicket::isForwarded))},
	{"isInitial", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(KerberosTicket::*)()>(&KerberosTicket::isInitial))},
	{"isPostdated", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(KerberosTicket::*)()>(&KerberosTicket::isPostdated))},
	{"isProxiable", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(KerberosTicket::*)()>(&KerberosTicket::isProxiable))},
	{"isProxy", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(KerberosTicket::*)()>(&KerberosTicket::isProxy))},
	{"isRenewable", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(KerberosTicket::*)()>(&KerberosTicket::isRenewable))},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KerberosTicket::*)($ObjectInputStream*)>(&KerberosTicket::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"refresh", "()V", nullptr, $PUBLIC, nullptr, "javax.security.auth.RefreshFailedException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KerberosTicket_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.security.auth.kerberos.KerberosTicket",
	"java.lang.Object",
	"javax.security.auth.Destroyable,javax.security.auth.Refreshable,java.io.Serializable",
	_KerberosTicket_FieldInfo_,
	_KerberosTicket_MethodInfo_
};

$Object* allocate$KerberosTicket($Class* clazz) {
	return $of($alloc(KerberosTicket));
}

$Object* KerberosTicket::clone() {
	 return this->$Destroyable::clone();
}

void KerberosTicket::finalize() {
	this->$Destroyable::finalize();
}

void KerberosTicket::init$($bytes* asn1Encoding, $KerberosPrincipal* client, $KerberosPrincipal* server, $bytes* sessionKey, int32_t keyType, $booleans* flags, $Date* authTime, $Date* startTime, $Date* endTime, $Date* renewTill, $InetAddressArray* clientAddresses) {
	$set(this, proxy, nullptr);
	this->destroyed = false;
	$set(this, clientAlias, nullptr);
	$set(this, serverAlias, nullptr);
	init(asn1Encoding, client, server, sessionKey, keyType, flags, authTime, startTime, endTime, renewTill, clientAddresses);
}

void KerberosTicket::init($bytes* asn1Encoding, $KerberosPrincipal* client, $KerberosPrincipal* server, $bytes* sessionKey, int32_t keyType, $booleans* flags, $Date* authTime, $Date* startTime, $Date* endTime, $Date* renewTill, $InetAddressArray* clientAddresses) {
	if (sessionKey == nullptr) {
		$throwNew($IllegalArgumentException, "Session key for ticket cannot be null"_s);
	}
	init(asn1Encoding, client, server, $$new($KeyImpl, sessionKey, keyType), flags, authTime, startTime, endTime, renewTill, clientAddresses);
}

void KerberosTicket::init($bytes* asn1Encoding, $KerberosPrincipal* client, $KerberosPrincipal* server, $KeyImpl* sessionKey, $booleans* flags, $Date* authTime, $Date* startTime, $Date* endTime, $Date* renewTill, $InetAddressArray* clientAddresses) {
	if (asn1Encoding == nullptr) {
		$throwNew($IllegalArgumentException, "ASN.1 encoding of ticket cannot be null"_s);
	}
	$set(this, asn1Encoding, $cast($bytes, $nc(asn1Encoding)->clone()));
	if (client == nullptr) {
		$throwNew($IllegalArgumentException, "Client name in ticket cannot be null"_s);
	}
	$set(this, client, client);
	if (server == nullptr) {
		$throwNew($IllegalArgumentException, "Server name in ticket cannot be null"_s);
	}
	$set(this, server, server);
	$set(this, sessionKey, sessionKey);
	if (flags != nullptr) {
		if (flags->length >= KerberosTicket::NUM_FLAGS) {
			$set(this, flags, $cast($booleans, flags->clone()));
		} else {
			$set(this, flags, $new($booleans, KerberosTicket::NUM_FLAGS));
			for (int32_t i = 0; i < flags->length; ++i) {
				$nc(this->flags)->set(i, flags->get(i));
			}
		}
	} else {
		$set(this, flags, $new($booleans, KerberosTicket::NUM_FLAGS));
	}
	if ($nc(this->flags)->get(KerberosTicket::RENEWABLE_TICKET_FLAG) && renewTill != nullptr) {
		$set(this, renewTill, $new($Date, renewTill->getTime()));
	}
	if (authTime != nullptr) {
		$set(this, authTime, $new($Date, authTime->getTime()));
	}
	if (startTime != nullptr) {
		$set(this, startTime, $new($Date, startTime->getTime()));
	} else {
		$set(this, startTime, this->authTime);
	}
	if (endTime == nullptr) {
		$throwNew($IllegalArgumentException, "End time for ticket validity cannot be null"_s);
	}
	$set(this, endTime, $new($Date, $nc(endTime)->getTime()));
	if (clientAddresses != nullptr) {
		$set(this, clientAddresses, $cast($InetAddressArray, clientAddresses->clone()));
	}
}

$KerberosPrincipal* KerberosTicket::getClient() {
	return this->client;
}

$KerberosPrincipal* KerberosTicket::getServer() {
	return this->server;
}

$SecretKey* KerberosTicket::getSessionKey() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This ticket is no longer valid"_s);
	}
	$var($bytes, var$0, $nc(this->sessionKey)->getEncoded());
	return $new($EncryptionKey, var$0, $nc(this->sessionKey)->getKeyType());
}

int32_t KerberosTicket::getSessionKeyType() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This ticket is no longer valid"_s);
	}
	return $nc(this->sessionKey)->getKeyType();
}

bool KerberosTicket::isForwardable() {
	return this->flags == nullptr ? false : $nc(this->flags)->get(KerberosTicket::FORWARDABLE_TICKET_FLAG);
}

bool KerberosTicket::isForwarded() {
	return this->flags == nullptr ? false : $nc(this->flags)->get(KerberosTicket::FORWARDED_TICKET_FLAG);
}

bool KerberosTicket::isProxiable() {
	return this->flags == nullptr ? false : $nc(this->flags)->get(KerberosTicket::PROXIABLE_TICKET_FLAG);
}

bool KerberosTicket::isProxy() {
	return this->flags == nullptr ? false : $nc(this->flags)->get(KerberosTicket::PROXY_TICKET_FLAG);
}

bool KerberosTicket::isPostdated() {
	return this->flags == nullptr ? false : $nc(this->flags)->get(KerberosTicket::POSTDATED_TICKET_FLAG);
}

bool KerberosTicket::isRenewable() {
	return this->flags == nullptr ? false : $nc(this->flags)->get(KerberosTicket::RENEWABLE_TICKET_FLAG);
}

bool KerberosTicket::isInitial() {
	return this->flags == nullptr ? false : $nc(this->flags)->get(KerberosTicket::INITIAL_TICKET_FLAG);
}

$booleans* KerberosTicket::getFlags() {
	return (this->flags == nullptr ? ($booleans*)nullptr : $cast($booleans, $nc(this->flags)->clone()));
}

$Date* KerberosTicket::getAuthTime() {
	return (this->authTime == nullptr) ? ($Date*)nullptr : $cast($Date, $nc(this->authTime)->clone());
}

$Date* KerberosTicket::getStartTime() {
	return (this->startTime == nullptr) ? ($Date*)nullptr : $cast($Date, $nc(this->startTime)->clone());
}

$Date* KerberosTicket::getEndTime() {
	return (this->endTime == nullptr) ? ($Date*)nullptr : $cast($Date, $nc(this->endTime)->clone());
}

$Date* KerberosTicket::getRenewTill() {
	return (this->renewTill == nullptr) ? ($Date*)nullptr : $cast($Date, $nc(this->renewTill)->clone());
}

$InetAddressArray* KerberosTicket::getClientAddresses() {
	return (this->clientAddresses == nullptr) ? ($InetAddressArray*)nullptr : $cast($InetAddressArray, $nc(this->clientAddresses)->clone());
}

$bytes* KerberosTicket::getEncoded() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This ticket is no longer valid"_s);
	}
	return $cast($bytes, $nc(this->asn1Encoding)->clone());
}

bool KerberosTicket::isCurrent() {
	bool var$0 = false;
	if (this->endTime == nullptr) {
		var$0 = false;
	} else {
		int64_t var$1 = $System::currentTimeMillis();
		var$0 = (var$1 <= $nc(this->endTime)->getTime());
	}
	return var$0;
}

void KerberosTicket::refresh() {
	if (this->destroyed) {
		$throwNew($RefreshFailedException, "A destroyed ticket cannot be renewd."_s);
	}
	if (!isRenewable()) {
		$throwNew($RefreshFailedException, "This ticket is not renewable"_s);
	}
	if (getRenewTill() == nullptr) {
		return;
	}
	int64_t var$0 = $System::currentTimeMillis();
	if (var$0 > $nc($(getRenewTill()))->getTime()) {
		$throwNew($RefreshFailedException, "This ticket is past its last renewal time."_s);
	}
	$var($Throwable, e, nullptr);
	$var($Credentials, krb5Creds, nullptr);
	try {
		$var($bytes, var$1, this->asn1Encoding);
		$var($String, var$2, $nc(this->client)->getName());
		$var($String, var$3, (this->clientAlias != nullptr ? $nc(this->clientAlias)->getName() : ($String*)nullptr));
		$var($String, var$4, $nc(this->server)->getName());
		$var($String, var$5, (this->serverAlias != nullptr ? $nc(this->serverAlias)->getName() : ($String*)nullptr));
		$var($bytes, var$6, $nc(this->sessionKey)->getEncoded());
		$assign(krb5Creds, $new($Credentials, var$1, var$2, var$3, var$4, var$5, var$6, $nc(this->sessionKey)->getKeyType(), this->flags, this->authTime, this->startTime, this->endTime, this->renewTill, this->clientAddresses));
		$assign(krb5Creds, krb5Creds->renew());
	} catch ($KrbException&) {
		$var($KrbException, krbException, $catch());
		$assign(e, krbException);
	} catch ($IOException&) {
		$var($IOException, ioException, $catch());
		$assign(e, ioException);
	}
	if (e != nullptr) {
		$var($String, var$7, $$str({"Failed to renew Kerberos Ticket for client "_s, this->client, " and server "_s, this->server, " - "_s}));
		$var($RefreshFailedException, rfException, $new($RefreshFailedException, $$concat(var$7, $(e->getMessage()))));
		rfException->initCause(e);
		$throw(rfException);
	}
	$synchronized(this) {
		try {
			this->destroy();
		} catch ($DestroyFailedException&) {
			$catch();
		}
		$var($bytes, var$8, $nc(krb5Creds)->getEncoded());
		$var($KerberosPrincipal, var$9, $new($KerberosPrincipal, $($nc($(krb5Creds->getClient()))->getName())));
		$var($KerberosPrincipal, var$10, $new($KerberosPrincipal, $($nc($(krb5Creds->getServer()))->getName()), $KerberosPrincipal::KRB_NT_SRV_INST));
		$var($bytes, var$11, $nc($(krb5Creds->getSessionKey()))->getBytes());
		int32_t var$12 = $nc($(krb5Creds->getSessionKey()))->getEType();
		$var($booleans, var$13, krb5Creds->getFlags());
		$var($Date, var$14, krb5Creds->getAuthTime());
		$var($Date, var$15, krb5Creds->getStartTime());
		$var($Date, var$16, krb5Creds->getEndTime());
		$var($Date, var$17, krb5Creds->getRenewTill());
		init(var$8, var$9, var$10, var$11, var$12, var$13, var$14, var$15, var$16, var$17, $(krb5Creds->getClientAddresses()));
		this->destroyed = false;
	}
}

void KerberosTicket::destroy() {
	if (!this->destroyed) {
		$Arrays::fill(this->asn1Encoding, (int8_t)0);
		$set(this, client, nullptr);
		$set(this, server, nullptr);
		$nc(this->sessionKey)->destroy();
		$set(this, flags, nullptr);
		$set(this, authTime, nullptr);
		$set(this, startTime, nullptr);
		$set(this, endTime, nullptr);
		$set(this, renewTill, nullptr);
		$set(this, clientAddresses, nullptr);
		this->destroyed = true;
	}
}

bool KerberosTicket::isDestroyed() {
	return this->destroyed;
}

$String* KerberosTicket::toString() {
	if (this->destroyed) {
		return "Destroyed KerberosTicket"_s;
	}
	$var($StringBuilder, caddrString, $new($StringBuilder));
	if (this->clientAddresses != nullptr) {
		for (int32_t i = 0; i < $nc(this->clientAddresses)->length; ++i) {
			caddrString->append($$str({"clientAddresses["_s, $$str(i), "] = "_s, $($nc($nc(this->clientAddresses)->get(i))->toString())}));
		}
	}
	$var($String, var$28, $$str({"Ticket (hex) = \n"_s, $(($$new($HexDumpEncoder))->encodeBuffer(this->asn1Encoding)), "\nClient Principal = "_s}));
	$var($String, var$27, $$concat(var$28, $($nc(this->client)->toString())));
	$var($String, var$26, $$concat(var$27, "\nServer Principal = "));
	$var($String, var$25, $$concat(var$26, $($nc(this->server)->toString())));
	$var($String, var$24, $$concat(var$25, "\nSession Key = "));
	$var($String, var$23, $$concat(var$24, $($nc(this->sessionKey)->toString())));
	$var($String, var$22, $$concat(var$23, "\nForwardable Ticket "));
	$var($String, var$21, $$concat(var$22, $$str($nc(this->flags)->get(KerberosTicket::FORWARDABLE_TICKET_FLAG))));
	$var($String, var$20, $$concat(var$21, "\nForwarded Ticket "));
	$var($String, var$19, $$concat(var$20, $$str($nc(this->flags)->get(KerberosTicket::FORWARDED_TICKET_FLAG))));
	$var($String, var$18, $$concat(var$19, "\nProxiable Ticket "));
	$var($String, var$17, $$concat(var$18, $$str($nc(this->flags)->get(KerberosTicket::PROXIABLE_TICKET_FLAG))));
	$var($String, var$16, $$concat(var$17, "\nProxy Ticket "));
	$var($String, var$15, $$concat(var$16, $$str($nc(this->flags)->get(KerberosTicket::PROXY_TICKET_FLAG))));
	$var($String, var$14, $$concat(var$15, "\nPostdated Ticket "));
	$var($String, var$13, $$concat(var$14, $$str($nc(this->flags)->get(KerberosTicket::POSTDATED_TICKET_FLAG))));
	$var($String, var$12, $$concat(var$13, "\nRenewable Ticket "));
	$var($String, var$11, $$concat(var$12, $$str($nc(this->flags)->get(KerberosTicket::RENEWABLE_TICKET_FLAG))));
	$var($String, var$10, $$concat(var$11, "\nInitial Ticket "));
	$var($String, var$9, $$concat(var$10, $$str($nc(this->flags)->get(KerberosTicket::INITIAL_TICKET_FLAG))));
	$var($String, var$8, $$concat(var$9, "\nAuth Time = "));
	$var($String, var$7, $$concat(var$8, $($String::valueOf($of(this->authTime)))));
	$var($String, var$6, $$concat(var$7, "\nStart Time = "));
	$var($String, var$5, $$concat(var$6, $($String::valueOf($of(this->startTime)))));
	$var($String, var$4, $$concat(var$5, "\nEnd Time = "));
	$var($String, var$3, $$concat(var$4, $($nc(this->endTime)->toString())));
	$var($String, var$2, $$concat(var$3, "\nRenew Till = "));
	$var($String, var$1, $$concat(var$2, $($String::valueOf($of(this->renewTill)))));
	$var($String, var$0, $$concat(var$1, "\nClient Addresses "));
	return ($concat(var$0, (this->clientAddresses == nullptr ? " Null "_s : $$str({$(caddrString->toString()), (this->proxy == nullptr ? ""_s : "\nwith a proxy ticket"_s), "\n"_s}))));
}

int32_t KerberosTicket::hashCode() {
	int32_t result = 17;
	if (isDestroyed()) {
		return result;
	}
	result = result * 37 + $Arrays::hashCode($(getEncoded()));
	result = result * 37 + $nc(this->endTime)->hashCode();
	result = result * 37 + $nc(this->client)->hashCode();
	result = result * 37 + $nc(this->server)->hashCode();
	result = result * 37 + $nc(this->sessionKey)->hashCode();
	if (this->authTime != nullptr) {
		result = result * 37 + $nc(this->authTime)->hashCode();
	}
	if (this->startTime != nullptr) {
		result = result * 37 + $nc(this->startTime)->hashCode();
	}
	if (this->renewTill != nullptr) {
		result = result * 37 + $nc(this->renewTill)->hashCode();
	}
	result = result * 37 + $Arrays::hashCode(this->clientAddresses);
	if (this->proxy != nullptr) {
		result = result * 37 + $nc(this->proxy)->hashCode();
	}
	return result * 37 + $Arrays::hashCode(this->flags);
}

bool KerberosTicket::equals(Object$* other) {
	if ($equals(other, this)) {
		return true;
	}
	if (!($instanceOf(KerberosTicket, other))) {
		return false;
	}
	$var(KerberosTicket, otherTicket, $cast(KerberosTicket, other));
	bool var$0 = isDestroyed();
	if (var$0 || $nc(otherTicket)->isDestroyed()) {
		return false;
	}
	$var($bytes, var$7, getEncoded());
	bool var$6 = !$Arrays::equals(var$7, $($nc(otherTicket)->getEncoded()));
	bool var$5 = var$6 || !$nc(this->endTime)->equals($($nc(otherTicket)->getEndTime()));
	bool var$4 = var$5 || !$nc(this->server)->equals($($nc(otherTicket)->getServer()));
	bool var$3 = var$4 || !$nc(this->client)->equals($($nc(otherTicket)->getClient()));
	bool var$2 = var$3 || !$nc(this->sessionKey)->equals($nc(otherTicket)->sessionKey);
	bool var$1 = var$2 || !$Arrays::equals(this->clientAddresses, $($nc(otherTicket)->getClientAddresses()));
	if (var$1 || !$Arrays::equals(this->flags, $($nc(otherTicket)->getFlags()))) {
		return false;
	}
	if (this->authTime == nullptr) {
		if ($nc(otherTicket)->getAuthTime() != nullptr) {
			return false;
		}
	} else if (!$nc(this->authTime)->equals($($nc(otherTicket)->getAuthTime()))) {
		return false;
	}
	if (this->startTime == nullptr) {
		if ($nc(otherTicket)->getStartTime() != nullptr) {
			return false;
		}
	} else if (!$nc(this->startTime)->equals($($nc(otherTicket)->getStartTime()))) {
		return false;
	}
	if (this->renewTill == nullptr) {
		if ($nc(otherTicket)->getRenewTill() != nullptr) {
			return false;
		}
	} else if (!$nc(this->renewTill)->equals($($nc(otherTicket)->getRenewTill()))) {
		return false;
	}
	if (!$Objects::equals(this->proxy, $nc(otherTicket)->proxy)) {
		return false;
	}
	return true;
}

void KerberosTicket::readObject($ObjectInputStream* s) {
	$nc(s)->defaultReadObject();
	if (this->sessionKey == nullptr) {
		$throwNew($InvalidObjectException, "Session key cannot be null"_s);
	}
	try {
		init(this->asn1Encoding, this->client, this->server, this->sessionKey, this->flags, this->authTime, this->startTime, this->endTime, this->renewTill, this->clientAddresses);
	} catch ($IllegalArgumentException&) {
		$var($IllegalArgumentException, iae, $catch());
		$throw($cast($InvalidObjectException, $($$new($InvalidObjectException, $(iae->getMessage()))->initCause(iae))));
	}
}

KerberosTicket::KerberosTicket() {
}

$Class* KerberosTicket::load$($String* name, bool initialize) {
	$loadClass(KerberosTicket, name, initialize, &_KerberosTicket_ClassInfo_, allocate$KerberosTicket);
	return class$;
}

$Class* KerberosTicket::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax