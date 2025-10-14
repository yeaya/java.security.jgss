#include <sun/security/krb5/KrbApReq.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/util/Arrays.h>
#include <sun/security/jgss/krb5/Krb5AcceptCredential.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/APOptions.h>
#include <sun/security/krb5/internal/APReq.h>
#include <sun/security/krb5/internal/Authenticator.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/EncTicketPart.h>
#include <sun/security/krb5/internal/HostAddress.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KRBError.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/LocalSeqNumber.h>
#include <sun/security/krb5/internal/ReplayCache.h>
#include <sun/security/krb5/internal/SeqNumber.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/krb5/internal/rcache/AuthTimeWithHash.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef API_INVALID_ARG
#undef AP_OPTS_MUTUAL_REQUIRED
#undef AP_OPTS_USE_SESSION_KEY
#undef DEBUG
#undef DEFAULT_HASH_ALG
#undef KRB_AP_ERR_BADADDR
#undef KRB_AP_ERR_BADMATCH
#undef KRB_AP_ERR_SKEW
#undef KRB_AP_ERR_TKT_EXPIRED
#undef KRB_AP_ERR_TKT_NYV
#undef KU_AP_REQ_AUTHENTICATOR
#undef KU_PA_TGS_REQ_AUTHENTICATOR
#undef KU_TICKET
#undef TKT_OPTS_INVALID

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $EncryptionKeyArray = $Array<::sun::security::krb5::EncryptionKey>;
using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $InetAddress = ::java::net::InetAddress;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Arrays = ::java::util::Arrays;
using $Krb5AcceptCredential = ::sun::security::jgss::krb5::Krb5AcceptCredential;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Checksum = ::sun::security::krb5::Checksum;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $APOptions = ::sun::security::krb5::internal::APOptions;
using $APReq = ::sun::security::krb5::internal::APReq;
using $Authenticator = ::sun::security::krb5::internal::Authenticator;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $EncTicketPart = ::sun::security::krb5::internal::EncTicketPart;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KRBError = ::sun::security::krb5::internal::KRBError;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $LocalSeqNumber = ::sun::security::krb5::internal::LocalSeqNumber;
using $ReplayCache = ::sun::security::krb5::internal::ReplayCache;
using $SeqNumber = ::sun::security::krb5::internal::SeqNumber;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $EType = ::sun::security::krb5::internal::crypto::EType;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $AuthTimeWithHash = ::sun::security::krb5::internal::rcache::AuthTimeWithHash;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbApReq_FieldInfo_[] = {
	{"obuf", "[B", nullptr, $PRIVATE, $field(KrbApReq, obuf)},
	{"ctime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $field(KrbApReq, ctime)},
	{"cusec", "I", nullptr, $PRIVATE, $field(KrbApReq, cusec$)},
	{"authenticator", "Lsun/security/krb5/internal/Authenticator;", nullptr, $PRIVATE, $field(KrbApReq, authenticator)},
	{"creds", "Lsun/security/krb5/Credentials;", nullptr, $PRIVATE, $field(KrbApReq, creds)},
	{"apReqMessg", "Lsun/security/krb5/internal/APReq;", nullptr, $PRIVATE, $field(KrbApReq, apReqMessg)},
	{"rcache", "Lsun/security/krb5/internal/ReplayCache;", nullptr, $PRIVATE | $STATIC, $staticField(KrbApReq, rcache)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(KrbApReq, DEBUG)},
	{"hexConst", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KrbApReq, hexConst)},
	{}
};

$MethodInfo _KrbApReq_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/Credentials;ZZZLsun/security/krb5/Checksum;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbApReq::*)($Credentials*,bool,bool,bool,$Checksum*)>(&KrbApReq::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.KrbCryptoException,sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "([BLsun/security/jgss/krb5/Krb5AcceptCredential;Ljava/net/InetAddress;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbApReq::*)($bytes*,$Krb5AcceptCredential*,$InetAddress*)>(&KrbApReq::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "(Lsun/security/krb5/internal/APOptions;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Checksum;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/AuthorizationData;)V", nullptr, 0, $method(static_cast<void(KrbApReq::*)($APOptions*,$Ticket*,$EncryptionKey*,$PrincipalName*,$Checksum*,$KerberosTime*,$EncryptionKey*,$SeqNumber*,$AuthorizationData*)>(&KrbApReq::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KdcErrException,sun.security.krb5.KrbCryptoException"},
	{"authenticate", "(Lsun/security/jgss/krb5/Krb5AcceptCredential;Ljava/net/InetAddress;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbApReq::*)($Krb5AcceptCredential*,$InetAddress*)>(&KrbApReq::authenticate)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"checkPermittedEType", "(I)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)(int32_t)>(&KrbApReq::checkPermittedEType)), "sun.security.krb5.KrbException"},
	{"createMessage", "(Lsun/security/krb5/internal/APOptions;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Checksum;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/AuthorizationData;I)V", nullptr, $PRIVATE, $method(static_cast<void(KrbApReq::*)($APOptions*,$Ticket*,$EncryptionKey*,$PrincipalName*,$Checksum*,$KerberosTime*,$EncryptionKey*,$SeqNumber*,$AuthorizationData*,int32_t)>(&KrbApReq::createMessage)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KdcErrException,sun.security.krb5.KrbCryptoException"},
	{"cusec", "()I", nullptr, 0},
	{"decode", "()V", nullptr, 0, nullptr, "sun.security.krb5.KrbException,java.io.IOException"},
	{"decode", "(Lsun/security/util/DerValue;)V", nullptr, 0, nullptr, "sun.security.krb5.KrbException,java.io.IOException"},
	{"getAPOptions", "()Lsun/security/krb5/internal/APOptions;", nullptr, 0, nullptr, "sun.security.krb5.KrbException,java.io.IOException"},
	{"getChecksum", "()Lsun/security/krb5/Checksum;", nullptr, $PUBLIC},
	{"getClient", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC},
	{"getCreds", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC},
	{"getCtime", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, 0},
	{"getMessage", "()[B", nullptr, $PUBLIC},
	{"getMutualAuthRequired", "()Z", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException,java.io.IOException"},
	{"getSeqNumber", "()Ljava/lang/Integer;", nullptr, $PUBLIC},
	{"getSubKey", "()Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC},
	{"init", "(Lsun/security/krb5/internal/APOptions;Lsun/security/krb5/Credentials;Lsun/security/krb5/Checksum;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/AuthorizationData;I)V", nullptr, $PRIVATE, $method(static_cast<void(KrbApReq::*)($APOptions*,$Credentials*,$Checksum*,$EncryptionKey*,$SeqNumber*,$AuthorizationData*,int32_t)>(&KrbApReq::init)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"init", "(Lsun/security/krb5/internal/APOptions;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Checksum;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/AuthorizationData;I)V", nullptr, $PRIVATE, $method(static_cast<void(KrbApReq::*)($APOptions*,$Ticket*,$EncryptionKey*,$PrincipalName*,$Checksum*,$KerberosTime*,$EncryptionKey*,$SeqNumber*,$AuthorizationData*,int32_t)>(&KrbApReq::init)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KdcErrException,sun.security.krb5.KrbCryptoException"},
	{"useSessionKey", "()Z", nullptr, 0, nullptr, "sun.security.krb5.KrbException,java.io.IOException"},
	{}
};

$ClassInfo _KrbApReq_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.KrbApReq",
	"java.lang.Object",
	nullptr,
	_KrbApReq_FieldInfo_,
	_KrbApReq_MethodInfo_
};

$Object* allocate$KrbApReq($Class* clazz) {
	return $of($alloc(KrbApReq));
}

$ReplayCache* KrbApReq::rcache = nullptr;
bool KrbApReq::DEBUG = false;
$chars* KrbApReq::hexConst = nullptr;

void KrbApReq::init$($Credentials* tgsCred, bool mutualRequired, bool useSubKey, bool useSeqNumber, $Checksum* cksum) {
	$var($APOptions, apOptions, mutualRequired ? $new($APOptions, $Krb5::AP_OPTS_MUTUAL_REQUIRED) : $new($APOptions));
	if (KrbApReq::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>> KrbApReq: APOptions are "_s, apOptions}));
	}
	$var($EncryptionKey, subKey, useSubKey ? $new($EncryptionKey, $($nc(tgsCred)->getSessionKey())) : ($EncryptionKey*)nullptr);
	$var($SeqNumber, seqNum, $new($LocalSeqNumber));
	init(apOptions, tgsCred, cksum, subKey, seqNum, nullptr, $KeyUsage::KU_AP_REQ_AUTHENTICATOR);
}

void KrbApReq::init$($bytes* message, $Krb5AcceptCredential* cred, $InetAddress* initiator) {
	$set(this, obuf, message);
	if (this->apReqMessg == nullptr) {
		decode();
	}
	authenticate(cred, initiator);
}

void KrbApReq::init$($APOptions* apOptions, $Ticket* ticket, $EncryptionKey* key, $PrincipalName* cname, $Checksum* cksum, $KerberosTime* ctime, $EncryptionKey* subKey, $SeqNumber* seqNumber, $AuthorizationData* authorizationData) {
	init(apOptions, ticket, key, cname, cksum, ctime, subKey, seqNumber, authorizationData, $KeyUsage::KU_PA_TGS_REQ_AUTHENTICATOR);
}

void KrbApReq::init($APOptions* options, $Credentials* tgs_creds, $Checksum* cksum, $EncryptionKey* subKey, $SeqNumber* seqNumber, $AuthorizationData* authorizationData, int32_t usage) {
	$set(this, ctime, $KerberosTime::now());
	init(options, $nc(tgs_creds)->ticket, tgs_creds->key, tgs_creds->client, cksum, this->ctime, subKey, seqNumber, authorizationData, usage);
}

void KrbApReq::init($APOptions* apOptions, $Ticket* ticket, $EncryptionKey* key, $PrincipalName* cname, $Checksum* cksum, $KerberosTime* ctime, $EncryptionKey* subKey, $SeqNumber* seqNumber, $AuthorizationData* authorizationData, int32_t usage) {
	createMessage(apOptions, ticket, key, cname, cksum, ctime, subKey, seqNumber, authorizationData, usage);
	$set(this, obuf, $nc(this->apReqMessg)->asn1Encode());
}

void KrbApReq::decode() {
	$var($DerValue, encoding, $new($DerValue, this->obuf));
	decode(encoding);
}

void KrbApReq::decode($DerValue* encoding) {
	$set(this, apReqMessg, nullptr);
	try {
		$set(this, apReqMessg, $new($APReq, encoding));
	} catch ($Asn1Exception&) {
		$var($Asn1Exception, e, $catch());
		$set(this, apReqMessg, nullptr);
		$var($KRBError, err, $new($KRBError, encoding));
		$var($String, errStr, err->getErrorString());
		$var($String, eText, nullptr);
		if ($nc(errStr)->charAt(errStr->length() - 1) == 0) {
			$assign(eText, errStr->substring(0, errStr->length() - 1));
		} else {
			$assign(eText, errStr);
		}
		$var($KrbException, ke, $new($KrbException, err->getErrorCode(), eText));
		ke->initCause(e);
		$throw(ke);
	}
}

void KrbApReq::authenticate($Krb5AcceptCredential* cred, $InetAddress* initiator) {
	int32_t encPartKeyType = $nc($nc($nc(this->apReqMessg)->ticket)->encPart)->getEType();
	$var($Integer, kvno, $nc($nc($nc(this->apReqMessg)->ticket)->encPart)->getKeyVersionNumber());
	$var($EncryptionKeyArray, keys, $nc(cred)->getKrb5EncryptionKeys($nc($nc(this->apReqMessg)->ticket)->sname));
	$var($EncryptionKey, dkey, $EncryptionKey::findKey(encPartKeyType, kvno, keys));
	if (dkey == nullptr) {
		$throwNew($KrbException, $Krb5::API_INVALID_ARG, $$str({"Cannot find key of appropriate type to decrypt AP-REQ - "_s, $($EType::toString(encPartKeyType))}));
	}
	$var($bytes, bytes, $nc($nc($nc(this->apReqMessg)->ticket)->encPart)->decrypt(dkey, $KeyUsage::KU_TICKET));
	$var($bytes, temp, $nc($nc($nc(this->apReqMessg)->ticket)->encPart)->reset(bytes));
	$var($EncTicketPart, enc_ticketPart, $new($EncTicketPart, temp));
	checkPermittedEType($nc(enc_ticketPart->key)->getEType());
	$var($bytes, bytes2, $nc($nc(this->apReqMessg)->authenticator)->decrypt(enc_ticketPart->key, $KeyUsage::KU_AP_REQ_AUTHENTICATOR));
	$var($bytes, temp2, $nc($nc(this->apReqMessg)->authenticator)->reset(bytes2));
	$set(this, authenticator, $new($Authenticator, temp2));
	$set(this, ctime, $nc(this->authenticator)->ctime);
	this->cusec$ = $nc(this->authenticator)->cusec;
	$set($nc(this->authenticator), ctime, $nc($nc(this->authenticator)->ctime)->withMicroSeconds($nc(this->authenticator)->cusec));
	if (!$nc($nc(this->authenticator)->cname)->equals(enc_ticketPart->cname)) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADMATCH);
	}
	if (!$nc($nc(this->authenticator)->ctime)->inClockSkew()) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_SKEW);
	}
	$init($AuthTimeWithHash);
	$var($String, alg, $AuthTimeWithHash::DEFAULT_HASH_ALG);
	$var($bytes, hash, nullptr);
	try {
		$assign(hash, $nc($($MessageDigest::getInstance($($AuthTimeWithHash::realAlg(alg)))))->digest($nc($nc(this->apReqMessg)->authenticator)->cipher));
	} catch ($NoSuchAlgorithmException&) {
		$var($NoSuchAlgorithmException, ex, $catch());
		$throwNew($AssertionError, $of($$str({"Impossible "_s, alg})));
	}
	$var($chars, h, $new($chars, $nc(hash)->length * 2));
	for (int32_t i = 0; i < hash->length; ++i) {
		h->set(2 * i, $nc(KrbApReq::hexConst)->get(((int32_t)(hash->get(i) & (uint32_t)255)) >> 4));
		h->set(2 * i + 1, $nc(KrbApReq::hexConst)->get((int32_t)(hash->get(i) & (uint32_t)15)));
	}
	$var($String, var$0, $nc($nc(this->authenticator)->cname)->toString());
	$var($String, var$1, $nc($nc($nc(this->apReqMessg)->ticket)->sname)->toString());
	int32_t var$2 = $nc($nc(this->authenticator)->ctime)->getSeconds();
	int32_t var$3 = $nc(this->authenticator)->cusec;
	$var($String, var$4, alg);
	$var($AuthTimeWithHash, time, $new($AuthTimeWithHash, var$0, var$1, var$2, var$3, var$4, $$new($String, h)));
	$nc(KrbApReq::rcache)->checkAndStore($($KerberosTime::now()), time);
	if (initiator != nullptr) {
		$var($HostAddress, sender, $new($HostAddress, initiator));
		if (enc_ticketPart->caddr != nullptr && !$nc(enc_ticketPart->caddr)->inList(sender)) {
			if (KrbApReq::DEBUG) {
				$init($System);
				$var($String, var$5, $$str({">>> KrbApReq: initiator is "_s, $(sender->getInetAddress()), ", but caddr is "_s}));
				$nc($System::out)->println($$concat(var$5, $($Arrays::toString($($nc(enc_ticketPart->caddr)->getInetAddresses())))));
			}
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADADDR);
		}
	}
	$var($KerberosTime, now, $KerberosTime::now());
	bool var$6 = (enc_ticketPart->starttime != nullptr && $nc(enc_ticketPart->starttime)->greaterThanWRTClockSkew(now));
	if (var$6 || $nc(enc_ticketPart->flags)->get($Krb5::TKT_OPTS_INVALID)) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_TKT_NYV);
	}
	if (enc_ticketPart->endtime != nullptr && $nc(now)->greaterThanWRTClockSkew(enc_ticketPart->endtime)) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_TKT_EXPIRED);
	}
	$set(this, creds, $new($Credentials, $nc(this->apReqMessg)->ticket, $nc(this->authenticator)->cname, ($PrincipalName*)nullptr, $nc($nc(this->apReqMessg)->ticket)->sname, ($PrincipalName*)nullptr, enc_ticketPart->key, enc_ticketPart->flags, enc_ticketPart->authtime, enc_ticketPart->starttime, enc_ticketPart->endtime, enc_ticketPart->renewTill, enc_ticketPart->caddr, enc_ticketPart->authorizationData));
	if (KrbApReq::DEBUG) {
		$init($System);
		$nc($System::out)->println(">>> KrbApReq: authenticate succeed."_s);
	}
}

$Credentials* KrbApReq::getCreds() {
	return this->creds;
}

$KerberosTime* KrbApReq::getCtime() {
	if (this->ctime != nullptr) {
		return this->ctime;
	}
	return $nc(this->authenticator)->ctime;
}

int32_t KrbApReq::cusec() {
	return this->cusec$;
}

$APOptions* KrbApReq::getAPOptions() {
	if (this->apReqMessg == nullptr) {
		decode();
	}
	if (this->apReqMessg != nullptr) {
		return $nc(this->apReqMessg)->apOptions;
	}
	return nullptr;
}

bool KrbApReq::getMutualAuthRequired() {
	if (this->apReqMessg == nullptr) {
		decode();
	}
	if (this->apReqMessg != nullptr) {
		return $nc($nc(this->apReqMessg)->apOptions)->get($Krb5::AP_OPTS_MUTUAL_REQUIRED);
	}
	return false;
}

bool KrbApReq::useSessionKey() {
	if (this->apReqMessg == nullptr) {
		decode();
	}
	if (this->apReqMessg != nullptr) {
		return $nc($nc(this->apReqMessg)->apOptions)->get($Krb5::AP_OPTS_USE_SESSION_KEY);
	}
	return false;
}

$EncryptionKey* KrbApReq::getSubKey() {
	return $nc(this->authenticator)->getSubKey();
}

$Integer* KrbApReq::getSeqNumber() {
	return $nc(this->authenticator)->getSeqNumber();
}

$Checksum* KrbApReq::getChecksum() {
	return $nc(this->authenticator)->getChecksum();
}

$bytes* KrbApReq::getMessage() {
	return this->obuf;
}

$PrincipalName* KrbApReq::getClient() {
	return $nc(this->creds)->getClient();
}

void KrbApReq::createMessage($APOptions* apOptions, $Ticket* ticket, $EncryptionKey* key, $PrincipalName* cname, $Checksum* cksum, $KerberosTime* ctime, $EncryptionKey* subKey, $SeqNumber* seqNumber, $AuthorizationData* authorizationData, int32_t usage) {
	$var($Integer, seqno, nullptr);
	if (seqNumber != nullptr) {
		$assign(seqno, $Integer::valueOf(seqNumber->current()));
	}
	$set(this, authenticator, $new($Authenticator, cname, cksum, $nc(ctime)->getMicroSeconds(), ctime, subKey, seqno, authorizationData));
	$var($bytes, temp, $nc(this->authenticator)->asn1Encode());
	$var($EncryptedData, encAuthenticator, $new($EncryptedData, key, temp, usage));
	$set(this, apReqMessg, $new($APReq, apOptions, ticket, encAuthenticator));
}

void KrbApReq::checkPermittedEType(int32_t target) {
	$init(KrbApReq);
	$var($ints, etypes, $EType::getDefaults("permitted_enctypes"_s));
	if (!$EType::isSupported(target, etypes)) {
		$throwNew($KrbException, $$str({$($EType::toString(target)), " encryption type not in permitted_enctypes list"_s}));
	}
}

void clinit$KrbApReq($Class* class$) {
	$assignStatic(KrbApReq::rcache, $ReplayCache::getInstance());
	$init($Krb5);
	KrbApReq::DEBUG = $Krb5::DEBUG;
	$assignStatic(KrbApReq::hexConst, "0123456789ABCDEF"_s->toCharArray());
}

KrbApReq::KrbApReq() {
}

$Class* KrbApReq::load$($String* name, bool initialize) {
	$loadClass(KrbApReq, name, initialize, &_KrbApReq_ClassInfo_, clinit$KrbApReq, allocate$KrbApReq);
	return class$;
}

$Class* KrbApReq::class$ = nullptr;

		} // krb5
	} // security
} // sun