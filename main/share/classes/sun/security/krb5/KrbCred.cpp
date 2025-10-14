#include <sun/security/krb5/KrbCred.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/KrbTgsReq.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/EncKrbCredPart.h>
#include <sun/security/krb5/internal/HostAddress.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/KRBCred.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbCredInfo.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef DEBUG
#undef FORWARDABLE
#undef FORWARDED
#undef KRB_ERR_GENERIC
#undef KU_ENC_KRB_CRED_PART
#undef NULL_KEY

using $CredentialsArray = $Array<::sun::security::krb5::Credentials>;
using $KrbCredInfoArray = $Array<::sun::security::krb5::internal::KrbCredInfo>;
using $TicketArray = $Array<::sun::security::krb5::internal::Ticket>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $KrbTgsReq = ::sun::security::krb5::KrbTgsReq;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $EncKrbCredPart = ::sun::security::krb5::internal::EncKrbCredPart;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $KRBCred = ::sun::security::krb5::internal::KRBCred;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbCredInfo = ::sun::security::krb5::internal::KrbCredInfo;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbCred_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(KrbCred, DEBUG)},
	{"obuf", "[B", nullptr, $PRIVATE, $field(KrbCred, obuf)},
	{"credMessg", "Lsun/security/krb5/internal/KRBCred;", nullptr, $PRIVATE, $field(KrbCred, credMessg)},
	{"ticket", "Lsun/security/krb5/internal/Ticket;", nullptr, $PRIVATE, $field(KrbCred, ticket)},
	{"encPart", "Lsun/security/krb5/internal/EncKrbCredPart;", nullptr, $PRIVATE, $field(KrbCred, encPart)},
	{"creds", "Lsun/security/krb5/Credentials;", nullptr, $PRIVATE, $field(KrbCred, creds)},
	{"timeStamp", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $field(KrbCred, timeStamp)},
	{}
};

$MethodInfo _KrbCred_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/Credentials;Lsun/security/krb5/Credentials;Lsun/security/krb5/EncryptionKey;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbCred::*)($Credentials*,$Credentials*,$EncryptionKey*)>(&KrbCred::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "([BLsun/security/krb5/EncryptionKey;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbCred::*)($bytes*,$EncryptionKey*)>(&KrbCred::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"createMessage", "(Lsun/security/krb5/Credentials;Lsun/security/krb5/EncryptionKey;)Lsun/security/krb5/internal/KRBCred;", nullptr, 0, nullptr, "sun.security.krb5.KrbException,java.io.IOException"},
	{"getDelegatedCreds", "()[Lsun/security/krb5/Credentials;", nullptr, $PUBLIC},
	{"getMessage", "()[B", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KrbCred_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.KrbCred",
	"java.lang.Object",
	nullptr,
	_KrbCred_FieldInfo_,
	_KrbCred_MethodInfo_
};

$Object* allocate$KrbCred($Class* clazz) {
	return $of($alloc(KrbCred));
}

bool KrbCred::DEBUG = false;

void KrbCred::init$($Credentials* tgt, $Credentials* serviceTicket, $EncryptionKey* key) {
	$set(this, obuf, nullptr);
	$set(this, credMessg, nullptr);
	$set(this, ticket, nullptr);
	$set(this, encPart, nullptr);
	$set(this, creds, nullptr);
	$set(this, timeStamp, nullptr);
	$var($PrincipalName, client, $nc(tgt)->getClient());
	$var($PrincipalName, tgService, tgt->getServer());
	if (!$nc($($nc(serviceTicket)->getClient()))->equals(client)) {
		$throwNew($KrbException, $Krb5::KRB_ERR_GENERIC, "Client principal does not match"_s);
	}
	$var($KDCOptions, options, $new($KDCOptions));
	options->set($KDCOptions::FORWARDED, true);
	options->set($KDCOptions::FORWARDABLE, true);
	$var($KrbTgsReq, tgsReq, $new($KrbTgsReq, options, tgt, tgService, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr));
	$set(this, credMessg, createMessage($(tgsReq->sendAndGetCreds()), key));
	$set(this, obuf, $nc(this->credMessg)->asn1Encode());
}

$KRBCred* KrbCred::createMessage($Credentials* delegatedCreds, $EncryptionKey* key) {
	$var($EncryptionKey, sessionKey, $nc(delegatedCreds)->getSessionKey());
	$var($PrincipalName, princ, delegatedCreds->getClient());
	$var($PrincipalName, tgService, delegatedCreds->getServer());
	$var($KrbCredInfo, credInfo, $new($KrbCredInfo, sessionKey, princ, delegatedCreds->flags, delegatedCreds->authTime, delegatedCreds->startTime, delegatedCreds->endTime, delegatedCreds->renewTill, tgService, delegatedCreds->cAddr));
	$set(this, timeStamp, $KerberosTime::now());
	$var($KrbCredInfoArray, credInfos, $new($KrbCredInfoArray, {credInfo}));
	$var($EncKrbCredPart, encPart, $new($EncKrbCredPart, credInfos, this->timeStamp, nullptr, nullptr, nullptr, nullptr));
	$var($EncryptedData, encEncPart, $new($EncryptedData, key, $(encPart->asn1Encode()), $KeyUsage::KU_ENC_KRB_CRED_PART));
	$var($TicketArray, tickets, $new($TicketArray, {delegatedCreds->ticket}));
	$set(this, credMessg, $new($KRBCred, tickets, encEncPart));
	return this->credMessg;
}

void KrbCred::init$($bytes* asn1Message, $EncryptionKey* key$renamed) {
	$var($EncryptionKey, key, key$renamed);
	$set(this, obuf, nullptr);
	$set(this, credMessg, nullptr);
	$set(this, ticket, nullptr);
	$set(this, encPart, nullptr);
	$set(this, creds, nullptr);
	$set(this, timeStamp, nullptr);
	$set(this, credMessg, $new($KRBCred, asn1Message));
	$set(this, ticket, $nc($nc(this->credMessg)->tickets)->get(0));
	if ($nc($nc(this->credMessg)->encPart)->getEType() == 0) {
		$init($EncryptionKey);
		$assign(key, $EncryptionKey::NULL_KEY);
	}
	$var($bytes, temp, $nc($nc(this->credMessg)->encPart)->decrypt(key, $KeyUsage::KU_ENC_KRB_CRED_PART));
	$var($bytes, plainText, $nc($nc(this->credMessg)->encPart)->reset(temp));
	$var($DerValue, encoding, $new($DerValue, plainText));
	$var($EncKrbCredPart, encPart, $new($EncKrbCredPart, encoding));
	$set(this, timeStamp, encPart->timeStamp);
	$var($KrbCredInfo, credInfo, $nc(encPart->ticketInfo)->get(0));
	$var($EncryptionKey, credInfoKey, $nc(credInfo)->key);
	$var($PrincipalName, pname, credInfo->pname);
	$var($TicketFlags, flags, credInfo->flags);
	$var($KerberosTime, authtime, credInfo->authtime);
	$var($KerberosTime, starttime, credInfo->starttime);
	$var($KerberosTime, endtime, credInfo->endtime);
	$var($KerberosTime, renewTill, credInfo->renewTill);
	$var($PrincipalName, sname, credInfo->sname);
	$var($HostAddresses, caddr, credInfo->caddr);
	if (KrbCred::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>>Delegated Creds have pname="_s, pname, " sname="_s, sname, " authtime="_s, authtime, " starttime="_s, starttime, " endtime="_s, endtime, "renewTill="_s, renewTill}));
	}
	$set(this, creds, $new($Credentials, this->ticket, pname, nullptr, sname, nullptr, credInfoKey, flags, authtime, starttime, endtime, renewTill, caddr));
}

$CredentialsArray* KrbCred::getDelegatedCreds() {
	$var($CredentialsArray, allCreds, $new($CredentialsArray, {this->creds}));
	return allCreds;
}

$bytes* KrbCred::getMessage() {
	return this->obuf;
}

void clinit$KrbCred($Class* class$) {
	$init($Krb5);
	KrbCred::DEBUG = $Krb5::DEBUG;
}

KrbCred::KrbCred() {
}

$Class* KrbCred::load$($String* name, bool initialize) {
	$loadClass(KrbCred, name, initialize, &_KrbCred_ClassInfo_, clinit$KrbCred, allocate$KrbCred);
	return class$;
}

$Class* KrbCred::class$ = nullptr;

		} // krb5
	} // security
} // sun