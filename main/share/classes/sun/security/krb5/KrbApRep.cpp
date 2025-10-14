#include <sun/security/krb5/KrbApRep.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbApReq.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/internal/APRep.h>
#include <sun/security/krb5/internal/EncAPRepPart.h>
#include <sun/security/krb5/internal/KRBError.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/LocalSeqNumber.h>
#include <sun/security/krb5/internal/SeqNumber.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef KRB_AP_ERR_MUT_FAIL
#undef KU_ENC_AP_REP_PART

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbApReq = ::sun::security::krb5::KrbApReq;
using $KrbException = ::sun::security::krb5::KrbException;
using $APRep = ::sun::security::krb5::internal::APRep;
using $EncAPRepPart = ::sun::security::krb5::internal::EncAPRepPart;
using $KRBError = ::sun::security::krb5::internal::KRBError;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $LocalSeqNumber = ::sun::security::krb5::internal::LocalSeqNumber;
using $SeqNumber = ::sun::security::krb5::internal::SeqNumber;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbApRep_FieldInfo_[] = {
	{"obuf", "[B", nullptr, $PRIVATE, $field(KrbApRep, obuf)},
	{"ibuf", "[B", nullptr, $PRIVATE, $field(KrbApRep, ibuf)},
	{"encPart", "Lsun/security/krb5/internal/EncAPRepPart;", nullptr, $PRIVATE, $field(KrbApRep, encPart)},
	{"apRepMessg", "Lsun/security/krb5/internal/APRep;", nullptr, $PRIVATE, $field(KrbApRep, apRepMessg)},
	{}
};

$MethodInfo _KrbApRep_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/KrbApReq;ZLsun/security/krb5/EncryptionKey;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbApRep::*)($KrbApReq*,bool,$EncryptionKey*)>(&KrbApRep::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "([BLsun/security/krb5/Credentials;Lsun/security/krb5/KrbApReq;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbApRep::*)($bytes*,$Credentials*,$KrbApReq*)>(&KrbApRep::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "([BLsun/security/krb5/Credentials;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbApRep::*)($bytes*,$Credentials*)>(&KrbApRep::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;Lsun/security/krb5/Credentials;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbApRep::*)($DerValue*,$Credentials*)>(&KrbApRep::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"authenticate", "(Lsun/security/krb5/KrbApReq;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbApRep::*)($KrbApReq*)>(&KrbApRep::authenticate)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"createMessage", "(Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/KerberosTime;ILsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbApRep::*)($EncryptionKey*,$KerberosTime*,int32_t,$EncryptionKey*,$SeqNumber*)>(&KrbApRep::createMessage)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KdcErrException,sun.security.krb5.KrbCryptoException"},
	{"getMessage", "()[B", nullptr, $PUBLIC},
	{"getSeqNumber", "()Ljava/lang/Integer;", nullptr, $PUBLIC},
	{"getSubKey", "()Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC},
	{"init", "(Lsun/security/krb5/KrbApReq;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbApRep::*)($KrbApReq*,$EncryptionKey*,$SeqNumber*)>(&KrbApRep::init)), "sun.security.krb5.KrbException,java.io.IOException"},
	{}
};

$ClassInfo _KrbApRep_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.KrbApRep",
	"java.lang.Object",
	nullptr,
	_KrbApRep_FieldInfo_,
	_KrbApRep_MethodInfo_
};

$Object* allocate$KrbApRep($Class* clazz) {
	return $of($alloc(KrbApRep));
}

void KrbApRep::init$($KrbApReq* incomingReq, bool useSeqNumber, $EncryptionKey* subKey) {
	$var($SeqNumber, seqNum, $new($LocalSeqNumber));
	init(incomingReq, subKey, seqNum);
}

void KrbApRep::init$($bytes* message, $Credentials* tgtCreds, $KrbApReq* outgoingReq) {
	KrbApRep::init$(message, tgtCreds);
	authenticate(outgoingReq);
}

void KrbApRep::init($KrbApReq* apReq, $EncryptionKey* subKey, $SeqNumber* seqNumber) {
	$var($EncryptionKey, var$0, $nc($($nc(apReq)->getCreds()))->key);
	$var($KerberosTime, var$1, apReq->getCtime());
	createMessage(var$0, var$1, apReq->cusec(), subKey, seqNumber);
	$set(this, obuf, $nc(this->apRepMessg)->asn1Encode());
}

void KrbApRep::init$($bytes* msg, $Credentials* tgs_creds) {
	KrbApRep::init$($$new($DerValue, msg), tgs_creds);
}

void KrbApRep::init$($DerValue* encoding$renamed, $Credentials* tgs_creds) {
	$var($DerValue, encoding, encoding$renamed);
	$var($APRep, rep, nullptr);
	try {
		$assign(rep, $new($APRep, encoding));
	} catch ($Asn1Exception&) {
		$var($Asn1Exception, e, $catch());
		$assign(rep, nullptr);
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
	$var($bytes, temp, $nc($nc(rep)->encPart)->decrypt($nc(tgs_creds)->key, $KeyUsage::KU_ENC_AP_REP_PART));
	$var($bytes, enc_ap_rep_part, $nc(rep->encPart)->reset(temp));
	$assign(encoding, $new($DerValue, enc_ap_rep_part));
	$set(this, encPart, $new($EncAPRepPart, encoding));
}

void KrbApRep::authenticate($KrbApReq* apReq) {
	int32_t var$1 = $nc($nc(this->encPart)->ctime)->getSeconds();
	bool var$0 = var$1 != $nc($($nc(apReq)->getCtime()))->getSeconds();
	if (var$0 || $nc(this->encPart)->cusec != $nc($($nc(apReq)->getCtime()))->getMicroSeconds()) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MUT_FAIL);
	}
}

$EncryptionKey* KrbApRep::getSubKey() {
	return $nc(this->encPart)->getSubKey();
}

$Integer* KrbApRep::getSeqNumber() {
	return $nc(this->encPart)->getSeqNumber();
}

$bytes* KrbApRep::getMessage() {
	return this->obuf;
}

void KrbApRep::createMessage($EncryptionKey* key, $KerberosTime* ctime, int32_t cusec, $EncryptionKey* subKey, $SeqNumber* seqNumber) {
	$var($Integer, seqno, nullptr);
	if (seqNumber != nullptr) {
		$assign(seqno, $Integer::valueOf(seqNumber->current()));
	}
	$set(this, encPart, $new($EncAPRepPart, ctime, cusec, subKey, seqno));
	$var($bytes, encPartEncoding, $nc(this->encPart)->asn1Encode());
	$var($EncryptedData, encEncPart, $new($EncryptedData, key, encPartEncoding, $KeyUsage::KU_ENC_AP_REP_PART));
	$set(this, apRepMessg, $new($APRep, encEncPart));
}

KrbApRep::KrbApRep() {
}

$Class* KrbApRep::load$($String* name, bool initialize) {
	$loadClass(KrbApRep, name, initialize, &_KrbApRep_ClassInfo_, allocate$KrbApRep);
	return class$;
}

$Class* KrbApRep::class$ = nullptr;

		} // krb5
	} // security
} // sun