#include <sun/security/krb5/internal/EncAPRepPart.h>

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
#include <java/util/Vector.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Vector = ::java::util::Vector;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _EncAPRepPart_FieldInfo_[] = {
	{"ctime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(EncAPRepPart, ctime)},
	{"cusec", "I", nullptr, $PUBLIC, $field(EncAPRepPart, cusec)},
	{"subKey", "Lsun/security/krb5/EncryptionKey;", nullptr, 0, $field(EncAPRepPart, subKey)},
	{"seqNumber", "Ljava/lang/Integer;", nullptr, 0, $field(EncAPRepPart, seqNumber)},
	{}
};

$MethodInfo _EncAPRepPart_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/KerberosTime;ILsun/security/krb5/EncryptionKey;Ljava/lang/Integer;)V", nullptr, $PUBLIC, $method(static_cast<void(EncAPRepPart::*)($KerberosTime*,int32_t,$EncryptionKey*,$Integer*)>(&EncAPRepPart::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(EncAPRepPart::*)($bytes*)>(&EncAPRepPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(EncAPRepPart::*)($DerValue*)>(&EncAPRepPart::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"getSeqNumber", "()Ljava/lang/Integer;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Integer*(EncAPRepPart::*)()>(&EncAPRepPart::getSeqNumber))},
	{"getSubKey", "()Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$EncryptionKey*(EncAPRepPart::*)()>(&EncAPRepPart::getSubKey))},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(EncAPRepPart::*)($DerValue*)>(&EncAPRepPart::init)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{}
};

$ClassInfo _EncAPRepPart_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.EncAPRepPart",
	"java.lang.Object",
	nullptr,
	_EncAPRepPart_FieldInfo_,
	_EncAPRepPart_MethodInfo_
};

$Object* allocate$EncAPRepPart($Class* clazz) {
	return $of($alloc(EncAPRepPart));
}

void EncAPRepPart::init$($KerberosTime* new_ctime, int32_t new_cusec, $EncryptionKey* new_subKey, $Integer* new_seqNumber) {
	$set(this, ctime, new_ctime);
	this->cusec = new_cusec;
	$set(this, subKey, new_subKey);
	$set(this, seqNumber, new_seqNumber);
}

void EncAPRepPart::init$($bytes* data) {
	init($$new($DerValue, data));
}

void EncAPRepPart::init$($DerValue* encoding) {
	init(encoding);
}

void EncAPRepPart::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)27);
	bool var$0 = var$1 || ($nc(encoding)->isApplication() != true);
	if (var$0 || ($nc(encoding)->isConstructed() != true)) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if ($nc(der)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, ctime, $KerberosTime::parse($($nc(der)->getData()), (int8_t)0, true));
	$assign(subDer, $nc($($nc(der)->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)1) {
		this->cusec = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, subKey, $EncryptionKey::parse($(der->getData()), (int8_t)2, true));
	} else {
		$set(this, subKey, nullptr);
		$set(this, seqNumber, nullptr);
	}
	if ($nc($(der->getData()))->available() > 0) {
		$assign(subDer, $nc($(der->getData()))->getDerValue());
		if (((int32_t)($nc(subDer)->getTag() & (uint32_t)31)) != 3) {
			$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
		}
		$set(this, seqNumber, $Integer::valueOf($nc($($nc($($nc(subDer)->getData()))->getBigInteger()))->intValue()));
	} else {
		$set(this, seqNumber, nullptr);
	}
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* EncAPRepPart::asn1Encode() {
	$var($Vector, v, $new($Vector));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0);
	v->addElement($$new($DerValue, var$0, $($nc(this->ctime)->asn1Encode())));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->cusec)));
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1);
	v->addElement($$new($DerValue, var$1, $(temp->toByteArray())));
	if (this->subKey != nullptr) {
		int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
		v->addElement($$new($DerValue, var$2, $($nc(this->subKey)->asn1Encode())));
	}
	if (this->seqNumber != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putInteger($($BigInteger::valueOf($nc(this->seqNumber)->longValue())));
		int8_t var$3 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3);
		v->addElement($$new($DerValue, var$3, $(temp->toByteArray())));
	}
	$var($DerValueArray, der, $new($DerValueArray, v->size()));
	v->copyInto(der);
	$assign(temp, $new($DerOutputStream));
	temp->putSequence(der);
	$var($DerOutputStream, out, $new($DerOutputStream));
	out->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)27), temp);
	return out->toByteArray();
}

$EncryptionKey* EncAPRepPart::getSubKey() {
	return this->subKey;
}

$Integer* EncAPRepPart::getSeqNumber() {
	return this->seqNumber;
}

EncAPRepPart::EncAPRepPart() {
}

$Class* EncAPRepPart::load$($String* name, bool initialize) {
	$loadClass(EncAPRepPart, name, initialize, &_EncAPRepPart_ClassInfo_, allocate$EncAPRepPart);
	return class$;
}

$Class* EncAPRepPart::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun