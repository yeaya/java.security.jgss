#include <sun/security/krb5/internal/PAEncTSEnc.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _PAEncTSEnc_FieldInfo_[] = {
	{"pATimeStamp", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(PAEncTSEnc, pATimeStamp)},
	{"pAUSec", "Ljava/lang/Integer;", nullptr, $PUBLIC, $field(PAEncTSEnc, pAUSec)},
	{}
};

$MethodInfo _PAEncTSEnc_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/KerberosTime;Ljava/lang/Integer;)V", nullptr, $PUBLIC, $method(static_cast<void(PAEncTSEnc::*)($KerberosTime*,$Integer*)>(&PAEncTSEnc::init$))},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(PAEncTSEnc::*)()>(&PAEncTSEnc::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(PAEncTSEnc::*)($DerValue*)>(&PAEncTSEnc::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{}
};

$ClassInfo _PAEncTSEnc_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.PAEncTSEnc",
	"java.lang.Object",
	nullptr,
	_PAEncTSEnc_FieldInfo_,
	_PAEncTSEnc_MethodInfo_
};

$Object* allocate$PAEncTSEnc($Class* clazz) {
	return $of($alloc(PAEncTSEnc));
}

void PAEncTSEnc::init$($KerberosTime* new_pATimeStamp, $Integer* new_pAUSec) {
	$set(this, pATimeStamp, new_pATimeStamp);
	$set(this, pAUSec, new_pAUSec);
}

void PAEncTSEnc::init$() {
	$var($KerberosTime, now, $KerberosTime::now());
	$set(this, pATimeStamp, now);
	$set(this, pAUSec, $Integer::valueOf($nc(now)->getMicroSeconds()));
}

void PAEncTSEnc::init$($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, pATimeStamp, $KerberosTime::parse($($nc(encoding)->getData()), (int8_t)0, false));
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$assign(der, $nc($(encoding->getData()))->getDerValue());
		if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 1) {
			$set(this, pAUSec, $Integer::valueOf($nc($($nc($(der->getData()))->getBigInteger()))->intValue()));
		} else {
			$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
		}
	}
	if ($nc($($nc(encoding)->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* PAEncTSEnc::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0);
	bytes->write(var$0, $($nc(this->pATimeStamp)->asn1Encode()));
	if (this->pAUSec != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putInteger($($BigInteger::valueOf((int64_t)$nc(this->pAUSec)->intValue())));
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	}
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

PAEncTSEnc::PAEncTSEnc() {
}

$Class* PAEncTSEnc::load$($String* name, bool initialize) {
	$loadClass(PAEncTSEnc, name, initialize, &_PAEncTSEnc_ClassInfo_, allocate$PAEncTSEnc);
	return class$;
}

$Class* PAEncTSEnc::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun