#include <sun/security/krb5/internal/KDCReq.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
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
#include <sun/security/krb5/internal/KDCReqBody.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef KRB_AP_ERR_BADVERSION
#undef KRB_AP_ERR_MSG_TYPE
#undef PVNO
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $KDCReqBody = ::sun::security::krb5::internal::KDCReqBody;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $PAData = ::sun::security::krb5::internal::PAData;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KDCReq_FieldInfo_[] = {
	{"reqBody", "Lsun/security/krb5/internal/KDCReqBody;", nullptr, $PUBLIC, $field(KDCReq, reqBody)},
	{"pAData", "[Lsun/security/krb5/internal/PAData;", nullptr, $PUBLIC, $field(KDCReq, pAData)},
	{"pvno", "I", nullptr, $PRIVATE, $field(KDCReq, pvno)},
	{"msgType", "I", nullptr, $PRIVATE, $field(KDCReq, msgType)},
	{}
};

$MethodInfo _KDCReq_MethodInfo_[] = {
	{"<init>", "([Lsun/security/krb5/internal/PAData;Lsun/security/krb5/internal/KDCReqBody;I)V", nullptr, $PUBLIC, $method(static_cast<void(KDCReq::*)($PADataArray*,$KDCReqBody*,int32_t)>(&KDCReq::init$)), "java.io.IOException"},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(KDCReq::*)()>(&KDCReq::init$))},
	{"<init>", "([BI)V", nullptr, $PUBLIC, $method(static_cast<void(KDCReq::*)($bytes*,int32_t)>(&KDCReq::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{"<init>", "(Lsun/security/util/DerValue;I)V", nullptr, $PUBLIC, $method(static_cast<void(KDCReq::*)($DerValue*,int32_t)>(&KDCReq::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1EncodeReqBody", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"init", "(Lsun/security/util/DerValue;I)V", nullptr, $PROTECTED, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.KrbException"},
	{}
};

$ClassInfo _KDCReq_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KDCReq",
	"java.lang.Object",
	nullptr,
	_KDCReq_FieldInfo_,
	_KDCReq_MethodInfo_
};

$Object* allocate$KDCReq($Class* clazz) {
	return $of($alloc(KDCReq));
}

void KDCReq::init$($PADataArray* new_pAData, $KDCReqBody* new_reqBody, int32_t req_type) {
	$set(this, pAData, nullptr);
	this->pvno = $Krb5::PVNO;
	this->msgType = req_type;
	if (new_pAData != nullptr) {
		$set(this, pAData, $new($PADataArray, new_pAData->length));
		for (int32_t i = 0; i < new_pAData->length; ++i) {
			if (new_pAData->get(i) == nullptr) {
				$throwNew($IOException, "Cannot create a KDCRep"_s);
			} else {
				$nc(this->pAData)->set(i, $cast($PAData, $($nc(new_pAData->get(i))->clone())));
			}
		}
	}
	$set(this, reqBody, new_reqBody);
}

void KDCReq::init$() {
	$set(this, pAData, nullptr);
}

void KDCReq::init$($bytes* data, int32_t req_type) {
	$set(this, pAData, nullptr);
	init($$new($DerValue, data), req_type);
}

void KDCReq::init$($DerValue* der, int32_t req_type) {
	$set(this, pAData, nullptr);
	init(der, req_type);
}

void KDCReq::init($DerValue* encoding, int32_t req_type) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	$var($BigInteger, bint, nullptr);
	if (((int32_t)($nc(encoding)->getTag() & (uint32_t)31)) != req_type) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if ($nc(der)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($($nc(der)->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)31)) == 1) {
		$assign(bint, $nc($(subDer->getData()))->getBigInteger());
		this->pvno = $nc(bint)->intValue();
		if (this->pvno != $Krb5::PVNO) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADVERSION);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)31)) == 2) {
		$assign(bint, $nc($(subDer->getData()))->getBigInteger());
		this->msgType = $nc(bint)->intValue();
		if (this->msgType != req_type) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MSG_TYPE);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, pAData, $PAData::parseSequence($(der->getData()), (int8_t)3, true));
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)31)) == 4) {
		$var($DerValue, subsubDer, $nc($(subDer->getData()))->getDerValue());
		$set(this, reqBody, $new($KDCReqBody, subsubDer, this->msgType));
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* KDCReq::asn1Encode() {
	$var($DerOutputStream, temp, nullptr);
	$var($DerOutputStream, bytes, nullptr);
	$var($DerOutputStream, out, nullptr);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->pvno)));
	$assign(out, $new($DerOutputStream));
	out->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->msgType)));
	out->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), temp);
	if (this->pAData != nullptr && $nc(this->pAData)->length > 0) {
		$assign(temp, $new($DerOutputStream));
		for (int32_t i = 0; i < $nc(this->pAData)->length; ++i) {
			temp->write($($nc($nc(this->pAData)->get(i))->asn1Encode()));
		}
		$assign(bytes, $new($DerOutputStream));
		bytes->write($DerValue::tag_SequenceOf, temp);
		out->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3), bytes);
	}
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
	out->write(var$0, $($nc(this->reqBody)->asn1Encode(this->msgType)));
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::tag_Sequence, out);
	$assign(out, $new($DerOutputStream));
	out->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)this->msgType), bytes);
	return out->toByteArray();
}

$bytes* KDCReq::asn1EncodeReqBody() {
	return $nc(this->reqBody)->asn1Encode(this->msgType);
}

KDCReq::KDCReq() {
}

$Class* KDCReq::load$($String* name, bool initialize) {
	$loadClass(KDCReq, name, initialize, &_KDCReq_ClassInfo_, allocate$KDCReq);
	return class$;
}

$Class* KDCReq::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun