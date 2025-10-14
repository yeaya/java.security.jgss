#include <sun/security/jgss/krb5/InitSecContextToken.h>

#include <java/io/InputStream.h>
#include <java/lang/Array.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/util/Date.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/GSSException.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/jgss/krb5/InitialToken$OverloadedChecksum.h>
#include <sun/security/jgss/krb5/InitialToken.h>
#include <sun/security/jgss/krb5/Krb5AcceptCredential.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/jgss/krb5/Krb5CredElement.h>
#include <sun/security/jgss/krb5/Krb5InitCredential.h>
#include <sun/security/jgss/krb5/Krb5NameElement.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbApReq.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ACCEPTOR_USE_INITIATOR_SEQNUM
#undef AP_REQ_ID
#undef DEFECTIVE_TOKEN
#undef INITIATOR_SUBKEY
#undef SESSION_KEY

using $InputStream = ::java::io::InputStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $Date = ::java::util::Date;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $InitialToken = ::sun::security::jgss::krb5::InitialToken;
using $InitialToken$OverloadedChecksum = ::sun::security::jgss::krb5::InitialToken$OverloadedChecksum;
using $Krb5AcceptCredential = ::sun::security::jgss::krb5::Krb5AcceptCredential;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;
using $Krb5CredElement = ::sun::security::jgss::krb5::Krb5CredElement;
using $Krb5InitCredential = ::sun::security::jgss::krb5::Krb5InitCredential;
using $Krb5NameElement = ::sun::security::jgss::krb5::Krb5NameElement;
using $Krb5Token = ::sun::security::jgss::krb5::Krb5Token;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $Checksum = ::sun::security::krb5::Checksum;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbApReq = ::sun::security::krb5::KrbApReq;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _InitSecContextToken_FieldInfo_[] = {
	{"ACCEPTOR_USE_INITIATOR_SEQNUM", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InitSecContextToken, ACCEPTOR_USE_INITIATOR_SEQNUM)},
	{"apReq", "Lsun/security/krb5/KrbApReq;", nullptr, $PRIVATE, $field(InitSecContextToken, apReq)},
	{}
};

$MethodInfo _InitSecContextToken_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Lsun/security/krb5/Credentials;Lsun/security/krb5/Credentials;)V", nullptr, 0, $method(static_cast<void(InitSecContextToken::*)($Krb5Context*,$Credentials*,$Credentials*)>(&InitSecContextToken::init$)), "sun.security.krb5.KrbException,java.io.IOException,org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/Krb5Context;Lsun/security/jgss/krb5/Krb5AcceptCredential;Ljava/io/InputStream;)V", nullptr, 0, $method(static_cast<void(InitSecContextToken::*)($Krb5Context*,$Krb5AcceptCredential*,$InputStream*)>(&InitSecContextToken::init$)), "java.io.IOException,org.ietf.jgss.GSSException,sun.security.krb5.KrbException"},
	{"encode", "()[B", nullptr, $PUBLIC | $FINAL, nullptr, "java.io.IOException"},
	{"getKrbApReq", "()Lsun/security/krb5/KrbApReq;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$KrbApReq*(InitSecContextToken::*)()>(&InitSecContextToken::getKrbApReq))},
	{}
};

$ClassInfo _InitSecContextToken_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.InitSecContextToken",
	"sun.security.jgss.krb5.InitialToken",
	nullptr,
	_InitSecContextToken_FieldInfo_,
	_InitSecContextToken_MethodInfo_
};

$Object* allocate$InitSecContextToken($Class* clazz) {
	return $of($alloc(InitSecContextToken));
}

bool InitSecContextToken::ACCEPTOR_USE_INITIATOR_SEQNUM = false;

void InitSecContextToken::init$($Krb5Context* context, $Credentials* tgt, $Credentials* serviceTicket) {
	$InitialToken::init$();
	$set(this, apReq, nullptr);
	bool mutualRequired = $nc(context)->getMutualAuthState();
	bool useSubkey = true;
	bool useSequenceNumber = true;
	$var($InitialToken$OverloadedChecksum, gssChecksum, $new($InitialToken$OverloadedChecksum, this, context, tgt, serviceTicket));
	$var($Checksum, checksum, gssChecksum->getChecksum());
	context->setTktFlags($($nc(serviceTicket)->getFlags()));
	context->setAuthTime($($$new($KerberosTime, $($nc(serviceTicket)->getAuthTime()))->toString()));
	$set(this, apReq, $new($KrbApReq, serviceTicket, mutualRequired, useSubkey, useSequenceNumber, checksum));
	context->resetMySequenceNumber($nc($($nc(this->apReq)->getSeqNumber()))->intValue());
	$var($EncryptionKey, subKey, $nc(this->apReq)->getSubKey());
	if (subKey != nullptr) {
		context->setKey($Krb5Context::INITIATOR_SUBKEY, subKey);
	} else {
		context->setKey($Krb5Context::SESSION_KEY, $($nc(serviceTicket)->getSessionKey()));
	}
	if (!mutualRequired) {
		context->resetPeerSequenceNumber(InitSecContextToken::ACCEPTOR_USE_INITIATOR_SEQNUM ? $nc($($nc(this->apReq)->getSeqNumber()))->intValue() : 0);
	}
}

void InitSecContextToken::init$($Krb5Context* context, $Krb5AcceptCredential* cred, $InputStream* is) {
	$InitialToken::init$();
	$set(this, apReq, nullptr);
	int32_t var$0 = ($nc(is)->read() << 8);
	int32_t tokenId = (var$0 | is->read());
	if (tokenId != $Krb5Token::AP_REQ_ID) {
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, "AP_REQ token id does not match!"_s);
	}
	$var($bytes, apReqBytes, $$new($DerValue, is)->toByteArray());
	$var($InetAddress, addr, nullptr);
	if ($nc(context)->getChannelBinding() != nullptr) {
		$assign(addr, $nc($(context->getChannelBinding()))->getInitiatorAddress());
	}
	$set(this, apReq, $new($KrbApReq, apReqBytes, cred, addr));
	$var($EncryptionKey, sessionKey, $nc($($nc(this->apReq)->getCreds()))->getSessionKey());
	$var($EncryptionKey, subKey, $nc(this->apReq)->getSubKey());
	if (subKey != nullptr) {
		$nc(context)->setKey($Krb5Context::INITIATOR_SUBKEY, subKey);
	} else {
		$nc(context)->setKey($Krb5Context::SESSION_KEY, sessionKey);
	}
	$var($InitialToken$OverloadedChecksum, gssChecksum, $new($InitialToken$OverloadedChecksum, this, context, $($nc(this->apReq)->getChecksum()), sessionKey, subKey));
	gssChecksum->setContextFlags(context);
	$var($Credentials, delegCred, gssChecksum->getDelegatedCreds());
	if (delegCred != nullptr) {
		$var($Krb5CredElement, credElement, $Krb5InitCredential::getInstance($cast($Krb5NameElement, $($nc(context)->getSrcName())), delegCred));
		$nc(context)->setDelegCred(credElement);
	}
	$var($Integer, apReqSeqNumber, $nc(this->apReq)->getSeqNumber());
	int32_t peerSeqNumber = (apReqSeqNumber != nullptr ? $nc(apReqSeqNumber)->intValue() : 0);
	$nc(context)->resetPeerSequenceNumber(peerSeqNumber);
	if (!context->getMutualAuthState()) {
		context->resetMySequenceNumber(InitSecContextToken::ACCEPTOR_USE_INITIATOR_SEQNUM ? peerSeqNumber : 0);
	}
	context->setAuthTime($($$new($KerberosTime, $($nc($($nc(this->apReq)->getCreds()))->getAuthTime()))->toString()));
	context->setTktFlags($($nc($($nc(this->apReq)->getCreds()))->getFlags()));
	$var($AuthorizationData, ad, $nc($($nc(this->apReq)->getCreds()))->getAuthzData());
	context->setAuthzData(ad);
}

$KrbApReq* InitSecContextToken::getKrbApReq() {
	return this->apReq;
}

$bytes* InitSecContextToken::encode() {
	$var($bytes, apReqBytes, $nc(this->apReq)->getMessage());
	$var($bytes, retVal, $new($bytes, 2 + $nc(apReqBytes)->length));
	writeInt($Krb5Token::AP_REQ_ID, retVal, 0);
	$System::arraycopy(apReqBytes, 0, retVal, 2, apReqBytes->length);
	return retVal;
}

void clinit$InitSecContextToken($Class* class$) {
	{
		$var($String, propName, "sun.security.krb5.acceptor.sequence.number.nonmutual"_s);
		$var($String, s, $GetPropertyAction::privilegedGetProperty(propName, "initiator"_s));
		if ($nc(s)->equals("initiator"_s)) {
			InitSecContextToken::ACCEPTOR_USE_INITIATOR_SEQNUM = true;
		} else {
			bool var$1 = s->equals("zero"_s);
			if (var$1 || s->equals("0"_s)) {
				InitSecContextToken::ACCEPTOR_USE_INITIATOR_SEQNUM = false;
			} else {
				$throwNew($AssertionError, $of($$str({"Unrecognized value for "_s, propName, ": "_s, s})));
			}
		}
	}
}

InitSecContextToken::InitSecContextToken() {
}

$Class* InitSecContextToken::load$($String* name, bool initialize) {
	$loadClass(InitSecContextToken, name, initialize, &_InitSecContextToken_ClassInfo_, clinit$InitSecContextToken, allocate$InitSecContextToken);
	return class$;
}

$Class* InitSecContextToken::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun