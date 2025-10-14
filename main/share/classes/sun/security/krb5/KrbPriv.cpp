#include <sun/security/krb5/KrbPriv.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbAppMessage.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/EncKrbPrivPart.h>
#include <sun/security/krb5/internal/HostAddress.h>
#include <sun/security/krb5/internal/KRBPriv.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/SeqNumber.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef KU_ENC_KRB_PRIV_PART

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbAppMessage = ::sun::security::krb5::KrbAppMessage;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $EncKrbPrivPart = ::sun::security::krb5::internal::EncKrbPrivPart;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;
using $KRBPriv = ::sun::security::krb5::internal::KRBPriv;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $SeqNumber = ::sun::security::krb5::internal::SeqNumber;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbPriv_FieldInfo_[] = {
	{"obuf", "[B", nullptr, $PRIVATE, $field(KrbPriv, obuf)},
	{"userData", "[B", nullptr, $PRIVATE, $field(KrbPriv, userData)},
	{}
};

$MethodInfo _KrbPriv_MethodInfo_[] = {
	{"<init>", "([BLsun/security/krb5/Credentials;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbPriv::*)($bytes*,$Credentials*,$EncryptionKey*,$KerberosTime*,$SeqNumber*,$HostAddress*,$HostAddress*)>(&KrbPriv::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"<init>", "([BLsun/security/krb5/Credentials;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;ZZ)V", nullptr, $PRIVATE, $method(static_cast<void(KrbPriv::*)($bytes*,$Credentials*,$EncryptionKey*,$SeqNumber*,$HostAddress*,$HostAddress*,bool,bool)>(&KrbPriv::init$)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"getData", "()[B", nullptr, $PUBLIC},
	{"getMessage", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException"},
	{"mk_priv", "([BLsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(KrbPriv::*)($bytes*,$EncryptionKey*,$KerberosTime*,$SeqNumber*,$HostAddress*,$HostAddress*)>(&KrbPriv::mk_priv)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.internal.KdcErrException,sun.security.krb5.KrbCryptoException"},
	{"rd_priv", "(Lsun/security/krb5/internal/KRBPriv;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/SeqNumber;Lsun/security/krb5/internal/HostAddress;Lsun/security/krb5/internal/HostAddress;ZZLsun/security/krb5/PrincipalName;)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(KrbPriv::*)($KRBPriv*,$EncryptionKey*,$SeqNumber*,$HostAddress*,$HostAddress*,bool,bool,$PrincipalName*)>(&KrbPriv::rd_priv)), "sun.security.krb5.Asn1Exception,sun.security.krb5.internal.KdcErrException,sun.security.krb5.internal.KrbApErrException,java.io.IOException,sun.security.krb5.KrbCryptoException"},
	{}
};

$ClassInfo _KrbPriv_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.KrbPriv",
	"sun.security.krb5.KrbAppMessage",
	nullptr,
	_KrbPriv_FieldInfo_,
	_KrbPriv_MethodInfo_
};

$Object* allocate$KrbPriv($Class* clazz) {
	return $of($alloc(KrbPriv));
}

void KrbPriv::init$($bytes* userData, $Credentials* creds, $EncryptionKey* subKey, $KerberosTime* timestamp, $SeqNumber* seqNumber, $HostAddress* saddr, $HostAddress* raddr) {
	$KrbAppMessage::init$();
	$var($EncryptionKey, reqKey, nullptr);
	if (subKey != nullptr) {
		$assign(reqKey, subKey);
	} else {
		$assign(reqKey, $nc(creds)->key);
	}
	$set(this, obuf, mk_priv(userData, reqKey, timestamp, seqNumber, saddr, raddr));
}

void KrbPriv::init$($bytes* msg, $Credentials* creds, $EncryptionKey* subKey, $SeqNumber* seqNumber, $HostAddress* saddr, $HostAddress* raddr, bool timestampRequired, bool seqNumberRequired) {
	$KrbAppMessage::init$();
	$var($KRBPriv, krb_priv, $new($KRBPriv, msg));
	$var($EncryptionKey, reqKey, nullptr);
	if (subKey != nullptr) {
		$assign(reqKey, subKey);
	} else {
		$assign(reqKey, $nc(creds)->key);
	}
	$set(this, userData, rd_priv(krb_priv, reqKey, seqNumber, saddr, raddr, timestampRequired, seqNumberRequired, $nc(creds)->client));
}

$bytes* KrbPriv::getMessage() {
	return this->obuf;
}

$bytes* KrbPriv::getData() {
	return this->userData;
}

$bytes* KrbPriv::mk_priv($bytes* userData, $EncryptionKey* key, $KerberosTime* timestamp, $SeqNumber* seqNumber, $HostAddress* sAddress, $HostAddress* rAddress) {
	$var($Integer, usec, nullptr);
	$var($Integer, seqno, nullptr);
	if (timestamp != nullptr) {
		$assign(usec, $Integer::valueOf(timestamp->getMicroSeconds()));
	}
	if (seqNumber != nullptr) {
		$assign(seqno, $Integer::valueOf(seqNumber->current()));
		seqNumber->step();
	}
	$var($EncKrbPrivPart, unenc_encKrbPrivPart, $new($EncKrbPrivPart, userData, timestamp, usec, seqno, sAddress, rAddress));
	$var($bytes, temp, unenc_encKrbPrivPart->asn1Encode());
	$var($EncryptedData, encKrbPrivPart, $new($EncryptedData, key, temp, $KeyUsage::KU_ENC_KRB_PRIV_PART));
	$var($KRBPriv, krb_priv, $new($KRBPriv, encKrbPrivPart));
	$assign(temp, krb_priv->asn1Encode());
	return krb_priv->asn1Encode();
}

$bytes* KrbPriv::rd_priv($KRBPriv* krb_priv, $EncryptionKey* key, $SeqNumber* seqNumber, $HostAddress* sAddress, $HostAddress* rAddress, bool timestampRequired, bool seqNumberRequired, $PrincipalName* cname) {
	$var($bytes, bytes, $nc($nc(krb_priv)->encPart)->decrypt(key, $KeyUsage::KU_ENC_KRB_PRIV_PART));
	$var($bytes, temp, $nc(krb_priv->encPart)->reset(bytes));
	$var($DerValue, ref, $new($DerValue, temp));
	$var($EncKrbPrivPart, enc_part, $new($EncKrbPrivPart, ref));
	check(enc_part->timestamp, enc_part->usec, enc_part->seqNumber, enc_part->sAddress, enc_part->rAddress, seqNumber, sAddress, rAddress, timestampRequired, seqNumberRequired, cname);
	return enc_part->userData;
}

KrbPriv::KrbPriv() {
}

$Class* KrbPriv::load$($String* name, bool initialize) {
	$loadClass(KrbPriv, name, initialize, &_KrbPriv_ClassInfo_, allocate$KrbPriv);
	return class$;
}

$Class* KrbPriv::class$ = nullptr;

		} // krb5
	} // security
} // sun