#include <sun/security/krb5/Credentials.h>

#include <java/io/IOException.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Date.h>
#include <java/util/Locale.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Credentials$1.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/KrbTgsReq.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/CredentialsUtil.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/ccache/Credentials.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <jcpp.h>

#undef DEBUG
#undef ENGLISH
#undef KRB_NT_PRINCIPAL
#undef KRB_NT_SRV_INST
#undef RENEW
#undef RENEWABLE
#undef TKT_OPTS_DELEGATE
#undef TKT_OPTS_FORWARDABLE
#undef TKT_OPTS_RENEWABLE

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $TicketArray = $Array<::sun::security::krb5::internal::Ticket>;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Date = ::java::util::Date;
using $Locale = ::java::util::Locale;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Credentials$1 = ::sun::security::krb5::Credentials$1;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $KrbTgsReq = ::sun::security::krb5::KrbTgsReq;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $CredentialsUtil = ::sun::security::krb5::internal::CredentialsUtil;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $Credentials = ::sun::security::krb5::internal::ccache::Credentials;
using $CredentialsCache = ::sun::security::krb5::internal::ccache::CredentialsCache;
using $EType = ::sun::security::krb5::internal::crypto::EType;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _Credentials_FieldInfo_[] = {
	{"ticket", "Lsun/security/krb5/internal/Ticket;", nullptr, 0, $field(Credentials, ticket)},
	{"client", "Lsun/security/krb5/PrincipalName;", nullptr, 0, $field(Credentials, client)},
	{"clientAlias", "Lsun/security/krb5/PrincipalName;", nullptr, 0, $field(Credentials, clientAlias)},
	{"server", "Lsun/security/krb5/PrincipalName;", nullptr, 0, $field(Credentials, server)},
	{"serverAlias", "Lsun/security/krb5/PrincipalName;", nullptr, 0, $field(Credentials, serverAlias)},
	{"key", "Lsun/security/krb5/EncryptionKey;", nullptr, 0, $field(Credentials, key)},
	{"flags", "Lsun/security/krb5/internal/TicketFlags;", nullptr, 0, $field(Credentials, flags)},
	{"authTime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, $field(Credentials, authTime)},
	{"startTime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, $field(Credentials, startTime)},
	{"endTime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, $field(Credentials, endTime)},
	{"renewTill", "Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, $field(Credentials, renewTill)},
	{"cAddr", "Lsun/security/krb5/internal/HostAddresses;", nullptr, 0, $field(Credentials, cAddr)},
	{"authzData", "Lsun/security/krb5/internal/AuthorizationData;", nullptr, 0, $field(Credentials, authzData)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(Credentials, DEBUG)},
	{"cache", "Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PRIVATE | $STATIC, $staticField(Credentials, cache)},
	{"alreadyLoaded", "Z", nullptr, $STATIC, $staticField(Credentials, alreadyLoaded)},
	{"alreadyTried", "Z", nullptr, $PRIVATE | $STATIC, $staticField(Credentials, alreadyTried)},
	{"proxy", "Lsun/security/krb5/Credentials;", nullptr, $PRIVATE, $field(Credentials, proxy)},
	{}
};

$MethodInfo _Credentials_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/TicketFlags;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/HostAddresses;Lsun/security/krb5/internal/AuthorizationData;)V", nullptr, $PUBLIC, $method(static_cast<void(Credentials::*)($Ticket*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$EncryptionKey*,$TicketFlags*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$HostAddresses*,$AuthorizationData*)>(&Credentials::init$))},
	{"<init>", "(Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/TicketFlags;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/HostAddresses;)V", nullptr, $PUBLIC, $method(static_cast<void(Credentials::*)($Ticket*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$PrincipalName*,$EncryptionKey*,$TicketFlags*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$HostAddresses*)>(&Credentials::init$))},
	{"<init>", "([BLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[BI[ZLjava/util/Date;Ljava/util/Date;Ljava/util/Date;Ljava/util/Date;[Ljava/net/InetAddress;)V", nullptr, $PUBLIC, $method(static_cast<void(Credentials::*)($bytes*,$String*,$String*,$String*,$String*,$bytes*,int32_t,$booleans*,$Date*,$Date*,$Date*,$Date*,$InetAddressArray*)>(&Credentials::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"acquireDefaultCreds", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<Credentials*(*)()>(&Credentials::acquireDefaultCreds))},
	{"acquireDefaultNativeCreds", "([I)Lsun/security/krb5/Credentials;", nullptr, $PRIVATE | $STATIC | $NATIVE, $method(static_cast<Credentials*(*)($ints*)>(&Credentials::acquireDefaultNativeCreds))},
	{"acquireS4U2proxyCreds", "(Ljava/lang/String;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Credentials;)Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Credentials*(*)($String*,$Ticket*,$PrincipalName*,Credentials*)>(&Credentials::acquireS4U2proxyCreds)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"acquireS4U2selfCreds", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Credentials;)Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Credentials*(*)($PrincipalName*,Credentials*)>(&Credentials::acquireS4U2selfCreds)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"acquireServiceCreds", "(Ljava/lang/String;Lsun/security/krb5/Credentials;)Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Credentials*(*)($String*,Credentials*)>(&Credentials::acquireServiceCreds)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"acquireTGTFromCache", "(Lsun/security/krb5/PrincipalName;Ljava/lang/String;)Lsun/security/krb5/Credentials;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Credentials*(*)($PrincipalName*,$String*)>(&Credentials::acquireTGTFromCache)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"checkDelegate", "()Z", nullptr, $PUBLIC},
	{"date2kt", "(Ljava/util/Date;)Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$KerberosTime*(*)($Date*)>(&Credentials::date2kt))},
	{"ensureLoaded", "()V", nullptr, $STATIC, $method(static_cast<void(*)()>(&Credentials::ensureLoaded))},
	{"getAuthTime", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Date*(Credentials::*)()>(&Credentials::getAuthTime))},
	{"getAuthzData", "()Lsun/security/krb5/internal/AuthorizationData;", nullptr, $PUBLIC},
	{"getCache", "()Lsun/security/krb5/internal/ccache/CredentialsCache;", nullptr, $PUBLIC},
	{"getClient", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$PrincipalName*(Credentials::*)()>(&Credentials::getClient))},
	{"getClientAddresses", "()[Ljava/net/InetAddress;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$InetAddressArray*(Credentials::*)()>(&Credentials::getClientAddresses))},
	{"getClientAlias", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$PrincipalName*(Credentials::*)()>(&Credentials::getClientAlias))},
	{"getEncoded", "()[B", nullptr, $PUBLIC | $FINAL, $method(static_cast<$bytes*(Credentials::*)()>(&Credentials::getEncoded))},
	{"getEndTime", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Date*(Credentials::*)()>(&Credentials::getEndTime))},
	{"getFlags", "()[Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<$booleans*(Credentials::*)()>(&Credentials::getFlags))},
	{"getProxy", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC},
	{"getRenewTill", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Date*(Credentials::*)()>(&Credentials::getRenewTill))},
	{"getServer", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$PrincipalName*(Credentials::*)()>(&Credentials::getServer))},
	{"getServerAlias", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$PrincipalName*(Credentials::*)()>(&Credentials::getServerAlias))},
	{"getSessionKey", "()Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$EncryptionKey*(Credentials::*)()>(&Credentials::getSessionKey))},
	{"getStartTime", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Date*(Credentials::*)()>(&Credentials::getStartTime))},
	{"getTicket", "()Lsun/security/krb5/internal/Ticket;", nullptr, $PUBLIC},
	{"getTicketFlags", "()Lsun/security/krb5/internal/TicketFlags;", nullptr, $PUBLIC},
	{"isForwardable", "()Z", nullptr, $PUBLIC},
	{"isRenewable", "()Z", nullptr, $PUBLIC},
	{"printDebug", "(Lsun/security/krb5/Credentials;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)(Credentials*)>(&Credentials::printDebug))},
	{"renew", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException,java.io.IOException"},
	{"resetDelegate", "()V", nullptr, $PUBLIC},
	{"setProxy", "(Lsun/security/krb5/Credentials;)Lsun/security/krb5/Credentials;", nullptr, $PUBLIC},
	{"toCCacheCreds", "()Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

#define _METHOD_INDEX_acquireDefaultNativeCreds 4

$InnerClassInfo _Credentials_InnerClassesInfo_[] = {
	{"sun.security.krb5.Credentials$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Credentials_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.Credentials",
	"java.lang.Object",
	nullptr,
	_Credentials_FieldInfo_,
	_Credentials_MethodInfo_,
	nullptr,
	nullptr,
	_Credentials_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.Credentials$1"
};

$Object* allocate$Credentials($Class* clazz) {
	return $of($alloc(Credentials));
}

bool Credentials::DEBUG = false;
$CredentialsCache* Credentials::cache = nullptr;
bool Credentials::alreadyLoaded = false;
bool Credentials::alreadyTried = false;

Credentials* Credentials::getProxy() {
	return this->proxy;
}

Credentials* Credentials::setProxy(Credentials* proxy) {
	$set(this, proxy, proxy);
	return this;
}

Credentials* Credentials::acquireDefaultNativeCreds($ints* eTypes) {
	$init(Credentials);
	$var(Credentials, $ret, nullptr);
	$prepareNativeStatic(Credentials, acquireDefaultNativeCreds, Credentials*, $ints* eTypes);
	$assign($ret, $invokeNativeStatic(Credentials, acquireDefaultNativeCreds, eTypes));
	$finishNativeStatic();
	return $ret;
}

void Credentials::init$($Ticket* new_ticket, $PrincipalName* new_client, $PrincipalName* new_client_alias, $PrincipalName* new_server, $PrincipalName* new_server_alias, $EncryptionKey* new_key, $TicketFlags* new_flags, $KerberosTime* authTime, $KerberosTime* new_startTime, $KerberosTime* new_endTime, $KerberosTime* renewTill, $HostAddresses* cAddr, $AuthorizationData* authzData) {
	Credentials::init$(new_ticket, new_client, new_client_alias, new_server, new_server_alias, new_key, new_flags, authTime, new_startTime, new_endTime, renewTill, cAddr);
	$set(this, authzData, authzData);
}

void Credentials::init$($Ticket* new_ticket, $PrincipalName* new_client, $PrincipalName* new_client_alias, $PrincipalName* new_server, $PrincipalName* new_server_alias, $EncryptionKey* new_key, $TicketFlags* new_flags, $KerberosTime* authTime, $KerberosTime* new_startTime, $KerberosTime* new_endTime, $KerberosTime* renewTill, $HostAddresses* cAddr) {
	$set(this, proxy, nullptr);
	$set(this, ticket, new_ticket);
	$set(this, client, new_client);
	$set(this, clientAlias, new_client_alias);
	$set(this, server, new_server);
	$set(this, serverAlias, new_server_alias);
	$set(this, key, new_key);
	$set(this, flags, new_flags);
	$set(this, authTime, authTime);
	$set(this, startTime, new_startTime);
	$set(this, endTime, new_endTime);
	$set(this, renewTill, renewTill);
	$set(this, cAddr, cAddr);
}

void Credentials::init$($bytes* encoding, $String* client, $String* clientAlias, $String* server, $String* serverAlias, $bytes* keyBytes, int32_t keyType, $booleans* flags, $Date* authTime, $Date* startTime, $Date* endTime, $Date* renewTill, $InetAddressArray* cAddrs) {
	$var($Ticket, var$0, $new($Ticket, encoding));
	$var($PrincipalName, var$1, $new($PrincipalName, client, $PrincipalName::KRB_NT_PRINCIPAL));
	$var($PrincipalName, var$2, (clientAlias == nullptr ? ($PrincipalName*)nullptr : $new($PrincipalName, clientAlias, $PrincipalName::KRB_NT_PRINCIPAL)));
	$var($PrincipalName, var$3, $new($PrincipalName, server, $PrincipalName::KRB_NT_SRV_INST));
	$var($PrincipalName, var$4, (serverAlias == nullptr ? ($PrincipalName*)nullptr : $new($PrincipalName, serverAlias, $PrincipalName::KRB_NT_SRV_INST)));
	$var($EncryptionKey, var$5, $new($EncryptionKey, keyType, keyBytes));
	$var($TicketFlags, var$6, (flags == nullptr ? ($TicketFlags*)nullptr : $new($TicketFlags, flags)));
	$var($KerberosTime, var$7, (authTime == nullptr ? ($KerberosTime*)nullptr : $new($KerberosTime, authTime)));
	$var($KerberosTime, var$8, (startTime == nullptr ? ($KerberosTime*)nullptr : $new($KerberosTime, startTime)));
	$var($KerberosTime, var$9, (endTime == nullptr ? ($KerberosTime*)nullptr : $new($KerberosTime, endTime)));
	Credentials::init$(var$0, var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, var$9, (renewTill == nullptr ? ($KerberosTime*)nullptr : $$new($KerberosTime, renewTill)), nullptr);
}

$PrincipalName* Credentials::getClient() {
	return this->client;
}

$PrincipalName* Credentials::getClientAlias() {
	return this->clientAlias;
}

$PrincipalName* Credentials::getServer() {
	return this->server;
}

$PrincipalName* Credentials::getServerAlias() {
	return this->serverAlias;
}

$EncryptionKey* Credentials::getSessionKey() {
	return this->key;
}

$Date* Credentials::getAuthTime() {
	if (this->authTime != nullptr) {
		return $nc(this->authTime)->toDate();
	} else {
		return nullptr;
	}
}

$Date* Credentials::getStartTime() {
	if (this->startTime != nullptr) {
		return $nc(this->startTime)->toDate();
	}
	return nullptr;
}

$Date* Credentials::getEndTime() {
	if (this->endTime != nullptr) {
		return $nc(this->endTime)->toDate();
	}
	return nullptr;
}

$Date* Credentials::getRenewTill() {
	if (this->renewTill != nullptr) {
		return $nc(this->renewTill)->toDate();
	}
	return nullptr;
}

$booleans* Credentials::getFlags() {
	if (this->flags == nullptr) {
		return nullptr;
	}
	return $nc(this->flags)->toBooleanArray();
}

$InetAddressArray* Credentials::getClientAddresses() {
	if (this->cAddr == nullptr) {
		return nullptr;
	}
	return $nc(this->cAddr)->getInetAddresses();
}

$bytes* Credentials::getEncoded() {
	$var($bytes, retVal, nullptr);
	try {
		$assign(retVal, $nc(this->ticket)->asn1Encode());
	} catch ($Asn1Exception&) {
		$var($Asn1Exception, e, $catch());
		if (Credentials::DEBUG) {
			$init($System);
			$nc($System::out)->println($of(e));
		}
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		if (Credentials::DEBUG) {
			$init($System);
			$nc($System::out)->println($of(ioe));
		}
	}
	return retVal;
}

bool Credentials::isForwardable() {
	return $nc(this->flags)->get($Krb5::TKT_OPTS_FORWARDABLE);
}

bool Credentials::isRenewable() {
	return $nc(this->flags)->get($Krb5::TKT_OPTS_RENEWABLE);
}

$Ticket* Credentials::getTicket() {
	return this->ticket;
}

$TicketFlags* Credentials::getTicketFlags() {
	return this->flags;
}

$AuthorizationData* Credentials::getAuthzData() {
	return this->authzData;
}

bool Credentials::checkDelegate() {
	return $nc(this->flags)->get($Krb5::TKT_OPTS_DELEGATE);
}

void Credentials::resetDelegate() {
	$nc(this->flags)->set($Krb5::TKT_OPTS_DELEGATE, false);
}

Credentials* Credentials::renew() {
	$var($KDCOptions, options, $new($KDCOptions));
	options->set($KDCOptions::RENEW, true);
	options->set($KDCOptions::RENEWABLE, true);
	return $$new($KrbTgsReq, options, this, this->server, this->serverAlias, nullptr, nullptr, nullptr, nullptr, this->cAddr, nullptr, nullptr, nullptr)->sendAndGetCreds();
}

Credentials* Credentials::acquireTGTFromCache($PrincipalName* princ, $String* ticketCache) {
	$init(Credentials);
	if (ticketCache == nullptr) {
		$var($String, os, $GetPropertyAction::privilegedGetProperty("os.name"_s));
		$init($Locale);
		bool var$0 = $($nc(os)->toUpperCase($Locale::ENGLISH))->startsWith("WINDOWS"_s);
		if (var$0 || $($nc(os)->toUpperCase($Locale::ENGLISH))->contains("OS X"_s)) {
			$var(Credentials, creds, acquireDefaultCreds());
			if (creds == nullptr) {
				if (Credentials::DEBUG) {
					$init($System);
					$nc($System::out)->println(">>> Found no TGT\'s in native ccache"_s);
				}
				return nullptr;
			}
			if (princ != nullptr) {
				if ($nc($($nc(creds)->getClient()))->equals(princ)) {
					if (Credentials::DEBUG) {
						$init($System);
						$nc($System::out)->println($$str({">>> Obtained TGT from native ccache: "_s, creds}));
					}
					return creds;
				} else {
					if (Credentials::DEBUG) {
						$init($System);
						$nc($System::out)->println($$str({">>> native ccache contains TGT for "_s, $(creds->getClient()), " not "_s, princ}));
					}
					return nullptr;
				}
			} else {
				if (Credentials::DEBUG) {
					$init($System);
					$nc($System::out)->println($$str({">>> Obtained TGT from native ccache: "_s, creds}));
				}
				return creds;
			}
		}
	}
	$var($CredentialsCache, ccache, $CredentialsCache::getInstance(princ, ticketCache));
	if (ccache == nullptr) {
		return nullptr;
	}
	$var(Credentials, tgtCred, $nc(ccache)->getInitialCreds());
	if (tgtCred == nullptr) {
		return nullptr;
	}
	if ($EType::isSupported($nc($nc(tgtCred)->key)->getEType())) {
		return tgtCred;
	} else {
		if (Credentials::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>> unsupported key type found the default TGT: "_s, $$str($nc($nc(tgtCred)->key)->getEType())}));
		}
		return nullptr;
	}
}

Credentials* Credentials::acquireDefaultCreds() {
	$load(Credentials);
	$synchronized(class$) {
		$init(Credentials);
		$var(Credentials, result, nullptr);
		if (Credentials::cache == nullptr) {
			$assignStatic(Credentials::cache, $CredentialsCache::getInstance());
		}
		if (Credentials::cache != nullptr) {
			$var(Credentials, temp, $nc(Credentials::cache)->getInitialCreds());
			if (temp != nullptr) {
				if (Credentials::DEBUG) {
					$init($System);
					$nc($System::out)->println(">>> KrbCreds found the default ticket granting ticket in credential cache."_s);
				}
				if ($EType::isSupported($nc(temp->key)->getEType())) {
					$assign(result, temp);
				} else {
					if (Credentials::DEBUG) {
						$init($System);
						$nc($System::out)->println($$str({">>> unsupported key type found the default TGT: "_s, $$str($nc(temp->key)->getEType())}));
					}
				}
			}
		}
		if (result == nullptr) {
			if (!Credentials::alreadyTried) {
				try {
					ensureLoaded();
				} catch ($Exception&) {
					$var($Exception, e, $catch());
					if (Credentials::DEBUG) {
						$init($System);
						$nc($System::out)->println("Can not load native ccache library"_s);
						e->printStackTrace();
					}
					Credentials::alreadyTried = true;
				}
			}
			if (Credentials::alreadyLoaded) {
				if (Credentials::DEBUG) {
					$init($System);
					$nc($System::out)->println(">> Acquire default native Credentials"_s);
				}
				try {
					$assign(result, acquireDefaultNativeCreds($($EType::getDefaults("default_tkt_enctypes"_s))));
				} catch ($KrbException&) {
					$catch();
				}
			}
		}
		return result;
	}
}

Credentials* Credentials::acquireServiceCreds($String* service, Credentials* ccreds) {
	$init(Credentials);
	return $CredentialsUtil::acquireServiceCreds(service, ccreds);
}

Credentials* Credentials::acquireS4U2selfCreds($PrincipalName* user, Credentials* ccreds) {
	$init(Credentials);
	return $CredentialsUtil::acquireS4U2selfCreds(user, ccreds);
}

Credentials* Credentials::acquireS4U2proxyCreds($String* service, $Ticket* second, $PrincipalName* client, Credentials* ccreds) {
	$init(Credentials);
	return $CredentialsUtil::acquireS4U2proxyCreds(service, second, client, ccreds);
}

$CredentialsCache* Credentials::getCache() {
	return Credentials::cache;
}

void Credentials::printDebug(Credentials* c) {
	$init(Credentials);
	$init($System);
	$nc($System::out)->println(">>> DEBUG: ----Credentials----"_s);
	$nc($System::out)->println($$str({"\tclient: "_s, $($nc($nc(c)->client)->toString())}));
	if ($nc(c)->clientAlias != nullptr) {
		$nc($System::out)->println($$str({"\tclient alias: "_s, $($nc(c->clientAlias)->toString())}));
	}
	$nc($System::out)->println($$str({"\tserver: "_s, $($nc($nc(c)->server)->toString())}));
	if ($nc(c)->serverAlias != nullptr) {
		$nc($System::out)->println($$str({"\tserver alias: "_s, $($nc(c->serverAlias)->toString())}));
	}
	$nc($System::out)->println($$str({"\tticket: sname: "_s, $($nc($nc($nc(c)->ticket)->sname)->toString())}));
	if ($nc(c)->startTime != nullptr) {
		$nc($System::out)->println($$str({"\tstartTime: "_s, $$str($nc(c->startTime)->getTime())}));
	}
	$nc($System::out)->println($$str({"\tendTime: "_s, $$str($nc($nc(c)->endTime)->getTime())}));
	$nc($System::out)->println("        ----Credentials end----"_s);
}

void Credentials::ensureLoaded() {
	$init(Credentials);
	$beforeCallerSensitive();
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Credentials$1)));
	Credentials::alreadyLoaded = true;
}

$String* Credentials::toString() {
	$var($StringBuilder, sb, $new($StringBuilder, "Credentials:"_s));
	sb->append("\n      client="_s)->append($of(this->client));
	if (this->clientAlias != nullptr) {
		sb->append("\n      clientAlias="_s)->append($of(this->clientAlias));
	}
	sb->append("\n      server="_s)->append($of(this->server));
	if (this->serverAlias != nullptr) {
		sb->append("\n      serverAlias="_s)->append($of(this->serverAlias));
	}
	if (this->authTime != nullptr) {
		sb->append("\n    authTime="_s)->append($of(this->authTime));
	}
	if (this->startTime != nullptr) {
		sb->append("\n   startTime="_s)->append($of(this->startTime));
	}
	sb->append("\n     endTime="_s)->append($of(this->endTime));
	sb->append("\n   renewTill="_s)->append($of(this->renewTill));
	sb->append("\n       flags="_s)->append($of(this->flags));
	sb->append("\nEType (skey)="_s)->append($nc(this->key)->getEType());
	sb->append("\n   (tkt key)="_s)->append($nc($nc(this->ticket)->encPart)->eType);
	return sb->toString();
}

$Credentials* Credentials::toCCacheCreds() {
	$var($PrincipalName, var$0, getClient());
	$var($PrincipalName, var$1, getServer());
	$var($EncryptionKey, var$2, getSessionKey());
	$var($KerberosTime, var$3, date2kt($(getAuthTime())));
	$var($KerberosTime, var$4, date2kt($(getStartTime())));
	$var($KerberosTime, var$5, date2kt($(getEndTime())));
	$var($KerberosTime, var$6, date2kt($(getRenewTill())));
	$var($TicketFlags, var$7, this->flags);
	$var($HostAddresses, var$8, $new($HostAddresses, $(getClientAddresses())));
	$var($AuthorizationData, var$9, getAuthzData());
	return $new($Credentials, var$0, var$1, var$2, var$3, var$4, var$5, var$6, false, var$7, var$8, var$9, $(getTicket()), nullptr);
}

$KerberosTime* Credentials::date2kt($Date* d) {
	$init(Credentials);
	return d == nullptr ? ($KerberosTime*)nullptr : $new($KerberosTime, d);
}

void clinit$Credentials($Class* class$) {
	$init($Krb5);
	Credentials::DEBUG = $Krb5::DEBUG;
	Credentials::alreadyLoaded = false;
	Credentials::alreadyTried = false;
}

Credentials::Credentials() {
}

$Class* Credentials::load$($String* name, bool initialize) {
	$loadClass(Credentials, name, initialize, &_Credentials_ClassInfo_, clinit$Credentials, allocate$Credentials);
	return class$;
}

$Class* Credentials::class$ = nullptr;

		} // krb5
	} // security
} // sun