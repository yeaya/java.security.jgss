#include <sun/security/krb5/internal/KRBSafe.h>

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
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/internal/KRBSafeBody.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef KRB_AP_ERR_BADVERSION
#undef KRB_AP_ERR_MSG_TYPE
#undef KRB_SAFE
#undef PVNO
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Checksum = ::sun::security::krb5::Checksum;
using $KRBSafeBody = ::sun::security::krb5::internal::KRBSafeBody;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KRBSafe_FieldInfo_[] = {
	{"pvno", "I", nullptr, $PUBLIC, $field(KRBSafe, pvno)},
	{"msgType", "I", nullptr, $PUBLIC, $field(KRBSafe, msgType)},
	{"safeBody", "Lsun/security/krb5/internal/KRBSafeBody;", nullptr, $PUBLIC, $field(KRBSafe, safeBody)},
	{"cksum", "Lsun/security/krb5/Checksum;", nullptr, $PUBLIC, $field(KRBSafe, cksum)},
	{}
};

$MethodInfo _KRBSafe_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/KRBSafeBody;Lsun/security/krb5/Checksum;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBSafe::*)($KRBSafeBody*,$Checksum*)>(&KRBSafe::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(KRBSafe::*)($bytes*)>(&KRBSafe::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBSafe::*)($DerValue*)>(&KRBSafe::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(KRBSafe::*)($DerValue*)>(&KRBSafe::init)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{}
};

$ClassInfo _KRBSafe_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KRBSafe",
	"java.lang.Object",
	nullptr,
	_KRBSafe_FieldInfo_,
	_KRBSafe_MethodInfo_
};

$Object* allocate$KRBSafe($Class* clazz) {
	return $of($alloc(KRBSafe));
}

void KRBSafe::init$($KRBSafeBody* new_safeBody, $Checksum* new_cksum) {
	this->pvno = $Krb5::PVNO;
	this->msgType = $Krb5::KRB_SAFE;
	$set(this, safeBody, new_safeBody);
	$set(this, cksum, new_cksum);
}

void KRBSafe::init$($bytes* data) {
	init($$new($DerValue, data));
}

void KRBSafe::init$($DerValue* encoding) {
	init(encoding);
}

void KRBSafe::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)20);
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
		if (this->msgType != $Krb5::KRB_SAFE) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MSG_TYPE);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, safeBody, $KRBSafeBody::parse($(der->getData()), (int8_t)2, false));
	$set(this, cksum, $Checksum::parse($(der->getData()), (int8_t)3, false));
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* KRBSafe::asn1Encode() {
	$var($DerOutputStream, temp, $new($DerOutputStream));
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->pvno)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->msgType)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
	bytes->write(var$0, $($nc(this->safeBody)->asn1Encode()));
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
	bytes->write(var$1, $($nc(this->cksum)->asn1Encode()));
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)20), temp);
	return bytes->toByteArray();
}

KRBSafe::KRBSafe() {
}

$Class* KRBSafe::load$($String* name, bool initialize) {
	$loadClass(KRBSafe, name, initialize, &_KRBSafe_ClassInfo_, allocate$KRBSafe);
	return class$;
}

$Class* KRBSafe::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun