#include <sun/security/krb5/KrbSafe.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbAppMessage.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/HostAddress.h>
#include <sun/security/krb5/internal/KRBSafe.h>
#include <sun/security/krb5/internal/KRBSafeBody.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/SeqNumber.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <jcpp.h>

#undef KRB_AP_ERR_MODIFIED
#undef KU_KRB_SAFE_CKSUM
#undef SAFECKSUMTYPE_DEFAULT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Checksum = ::sun::security::krb5::Checksum;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbAppMessage = ::sun::security::krb5::KrbAppMessage;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;
using $KRBSafe = ::sun::security::krb5::internal::KRBSafe;
using $KRBSafeBody = ::sun::security::krb5::internal::KRBSafeBody;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $SeqNumber = ::sun::security::krb5::internal::SeqNumber;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbSafe_FieldInfo_[] = {
	{"obuf", "[B", nullptr, $PRIVATE, $field(KrbSafe, obuf)},
	{"userData", "[B", nullptr, $PRIVATE, $field(KrbSafe, userData)},
	{}
};

$MethodInfo _KrbSafe_MethodInfo_[] = {
	{"<init>", "([BLsun/security/krb5/Credentials;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbSafe::*)($bytes*,$Credentials*,$EncryptionKey*,$KerberosTime*,$SeqNumber*,$HostAddress*,$HostAddress*)>(&KrbSafe::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "([BLsun/security/krb5/Credentials;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;ZZ)V", nullptr, $PUBLIC, $method(static_cast<void(KrbSafe::*)($bytes*,$Credentials*,$EncryptionKey*,$SeqNumber*,$HostAddress*,$HostAddress*,bool,bool)>(&KrbSafe::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"getData", "()[B", nullptr, $PUBLIC},
	{"getMessage", "()[B", nullptr, $PUBLIC},
	{"mk_safe", "([BLsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(KrbSafe::*)($bytes*,$EncryptionKey*,$KerberosTime*,$SeqNumber*,$HostAddress*,$HostAddress*)>(&KrbSafe::mk_safe)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KdcErrException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.KrbCryptoException"},
	{"rd_safe", "(Lsun/security/krb5/internal/KRBSafe;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;ZZLsun/security/krb5/PrincipalName;)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(KrbSafe::*)($KRBSafe*,$EncryptionKey*,$SeqNumber*,$HostAddress*,$HostAddress*,bool,bool,$PrincipalName*)>(&KrbSafe::rd_safe)), "sun.security.krb5.Asn1Exception,sun.security.krb5.internal.KdcErrException,sun.security.krb5.internal.KrbApErrException,java.io.IOException,sun.security.krb5.KrbCryptoException"},
	{}
};

$ClassInfo _KrbSafe_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.KrbSafe",
	"sun.security.krb5.KrbAppMessage",
	nullptr,
	_KrbSafe_FieldInfo_,
	_KrbSafe_MethodInfo_
};

$Object* allocate$KrbSafe($Class* clazz) {
	return $of($alloc(KrbSafe));
}

void KrbSafe::init$($bytes* userData, $Credentials* creds, $EncryptionKey* subKey, $KerberosTime* timestamp, $SeqNumber* seqNumber, $HostAddress* saddr, $HostAddress* raddr) {
	$KrbAppMessage::init$();
	$var($EncryptionKey, reqKey, nullptr);
	if (subKey != nullptr) {
		$assign(reqKey, subKey);
	} else {
		$assign(reqKey, $nc(creds)->key);
	}
	$set(this, obuf, mk_safe(userData, reqKey, timestamp, seqNumber, saddr, raddr));
}

void KrbSafe::init$($bytes* msg, $Credentials* creds, $EncryptionKey* subKey, $SeqNumber* seqNumber, $HostAddress* saddr, $HostAddress* raddr, bool timestampRequired, bool seqNumberRequired) {
	$KrbAppMessage::init$();
	$var($KRBSafe, krb_safe, $new($KRBSafe, msg));
	$var($EncryptionKey, reqKey, nullptr);
	if (subKey != nullptr) {
		$assign(reqKey, subKey);
	} else {
		$assign(reqKey, $nc(creds)->key);
	}
	$set(this, userData, rd_safe(krb_safe, reqKey, seqNumber, saddr, raddr, timestampRequired, seqNumberRequired, $nc(creds)->client));
}

$bytes* KrbSafe::getMessage() {
	return this->obuf;
}

$bytes* KrbSafe::getData() {
	return this->userData;
}

$bytes* KrbSafe::mk_safe($bytes* userData, $EncryptionKey* key, $KerberosTime* timestamp, $SeqNumber* seqNumber, $HostAddress* sAddress, $HostAddress* rAddress) {
	$var($Integer, usec, nullptr);
	$var($Integer, seqno, nullptr);
	if (timestamp != nullptr) {
		$assign(usec, $Integer::valueOf(timestamp->getMicroSeconds()));
	}
	if (seqNumber != nullptr) {
		$assign(seqno, $Integer::valueOf(seqNumber->current()));
		seqNumber->step();
	}
	$var($KRBSafeBody, krb_safeBody, $new($KRBSafeBody, userData, timestamp, usec, seqno, sAddress, rAddress));
	$var($bytes, temp, krb_safeBody->asn1Encode());
	$init($Checksum);
	$var($Checksum, cksum, $new($Checksum, $Checksum::SAFECKSUMTYPE_DEFAULT, temp, key, $KeyUsage::KU_KRB_SAFE_CKSUM));
	$var($KRBSafe, krb_safe, $new($KRBSafe, krb_safeBody, cksum));
	$assign(temp, krb_safe->asn1Encode());
	return krb_safe->asn1Encode();
}

$bytes* KrbSafe::rd_safe($KRBSafe* krb_safe, $EncryptionKey* key, $SeqNumber* seqNumber, $HostAddress* sAddress, $HostAddress* rAddress, bool timestampRequired, bool seqNumberRequired, $PrincipalName* cname) {
	$var($bytes, temp, $nc($nc(krb_safe)->safeBody)->asn1Encode());
	if (!$nc(krb_safe->cksum)->verifyKeyedChecksum(temp, key, $KeyUsage::KU_KRB_SAFE_CKSUM)) {
		$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MODIFIED);
	}
	check($nc(krb_safe->safeBody)->timestamp, $nc(krb_safe->safeBody)->usec, $nc(krb_safe->safeBody)->seqNumber, $nc(krb_safe->safeBody)->sAddress, $nc(krb_safe->safeBody)->rAddress, seqNumber, sAddress, rAddress, timestampRequired, seqNumberRequired, cname);
	return $nc(krb_safe->safeBody)->userData;
}

KrbSafe::KrbSafe() {
}

$Class* KrbSafe::load$($String* name, bool initialize) {
	$loadClass(KrbSafe, name, initialize, &_KrbSafe_ClassInfo_, allocate$KrbSafe);
	return class$;
}

$Class* KrbSafe::class$ = nullptr;

		} // krb5
	} // security
} // sun