#include <sun/security/krb5/internal/KRBPriv.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef KRB_AP_ERR_BADVERSION
#undef KRB_AP_ERR_MSG_TYPE
#undef KRB_PRIV
#undef PVNO
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KRBPriv_FieldInfo_[] = {
	{"pvno", "I", nullptr, $PUBLIC, $field(KRBPriv, pvno)},
	{"msgType", "I", nullptr, $PUBLIC, $field(KRBPriv, msgType)},
	{"encPart", "Lsun/security/krb5/EncryptedData;", nullptr, $PUBLIC, $field(KRBPriv, encPart)},
	{}
};

$MethodInfo _KRBPriv_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/EncryptedData;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBPriv::*)($EncryptedData*)>(&KRBPriv::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(KRBPriv::*)($bytes*)>(&KRBPriv::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBPriv::*)($DerValue*)>(&KRBPriv::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(KRBPriv::*)($DerValue*)>(&KRBPriv::init)), "sun.security.krb5.Asn1Exception,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{}
};

$ClassInfo _KRBPriv_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KRBPriv",
	"java.lang.Object",
	nullptr,
	_KRBPriv_FieldInfo_,
	_KRBPriv_MethodInfo_
};

$Object* allocate$KRBPriv($Class* clazz) {
	return $of($alloc(KRBPriv));
}

void KRBPriv::init$($EncryptedData* new_encPart) {
	this->pvno = $Krb5::PVNO;
	this->msgType = $Krb5::KRB_PRIV;
	$set(this, encPart, new_encPart);
}

void KRBPriv::init$($bytes* data) {
	init($$new($DerValue, data));
}

void KRBPriv::init$($DerValue* encoding) {
	init(encoding);
}

void KRBPriv::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)21);
	bool var$0 = var$1 || ($nc(encoding)->isApplication() != true);
	if (var$0 || ($nc(encoding)->isConstructed() != true)) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if ($nc(der)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($($nc(der)->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)31)) == 0) {
		this->pvno = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
		if (this->pvno != $Krb5::PVNO) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADVERSION);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)31)) == 1) {
		this->msgType = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
		if (this->msgType != $Krb5::KRB_PRIV) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MSG_TYPE);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, encPart, $EncryptedData::parse($(der->getData()), (int8_t)3, false));
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* KRBPriv::asn1Encode() {
	$var($DerOutputStream, temp, nullptr);
	$var($DerOutputStream, bytes, nullptr);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->pvno)));
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->msgType)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
	bytes->write(var$0, $($nc(this->encPart)->asn1Encode()));
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)21), temp);
	return bytes->toByteArray();
}

KRBPriv::KRBPriv() {
}

$Class* KRBPriv::load$($String* name, bool initialize) {
	$loadClass(KRBPriv, name, initialize, &_KRBPriv_ClassInfo_, allocate$KRBPriv);
	return class$;
}

$Class* KRBPriv::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun