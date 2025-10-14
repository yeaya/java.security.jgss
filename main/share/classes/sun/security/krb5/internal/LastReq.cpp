#include <sun/security/krb5/internal/LastReq.h>

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
#include <java/util/Vector.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/LastReqEntry.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID

using $LastReqEntryArray = $Array<::sun::security::krb5::internal::LastReqEntry>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Vector = ::java::util::Vector;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $LastReqEntry = ::sun::security::krb5::internal::LastReqEntry;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _LastReq_FieldInfo_[] = {
	{"entry", "[Lsun/security/krb5/internal/LastReqEntry;", nullptr, $PRIVATE, $field(LastReq, entry)},
	{}
};

$MethodInfo _LastReq_MethodInfo_[] = {
	{"<init>", "([Lsun/security/krb5/internal/LastReqEntry;)V", nullptr, $PUBLIC, $method(static_cast<void(LastReq::*)($LastReqEntryArray*)>(&LastReq::init$)), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(LastReq::*)($DerValue*)>(&LastReq::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/internal/LastReq;", nullptr, $PUBLIC | $STATIC, $method(static_cast<LastReq*(*)($DerInputStream*,int8_t,bool)>(&LastReq::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{}
};

$ClassInfo _LastReq_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.LastReq",
	"java.lang.Object",
	nullptr,
	_LastReq_FieldInfo_,
	_LastReq_MethodInfo_
};

$Object* allocate$LastReq($Class* clazz) {
	return $of($alloc(LastReq));
}

void LastReq::init$($LastReqEntryArray* entries) {
	$set(this, entry, nullptr);
	if (entries != nullptr) {
		$set(this, entry, $new($LastReqEntryArray, entries->length));
		for (int32_t i = 0; i < entries->length; ++i) {
			if (entries->get(i) == nullptr) {
				$throwNew($IOException, "Cannot create a LastReqEntry"_s);
			} else {
				$nc(this->entry)->set(i, $cast($LastReqEntry, $($nc(entries->get(i))->clone())));
			}
		}
	}
}

void LastReq::init$($DerValue* encoding) {
	$set(this, entry, nullptr);
	$var($Vector, v, $new($Vector));
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	while ($nc($($nc(encoding)->getData()))->available() > 0) {
		v->addElement($$new($LastReqEntry, $($nc($(encoding->getData()))->getDerValue())));
	}
	if (v->size() > 0) {
		$set(this, entry, $new($LastReqEntryArray, v->size()));
		v->copyInto(this->entry);
	}
}

$bytes* LastReq::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	if (this->entry != nullptr && $nc(this->entry)->length > 0) {
		$var($DerOutputStream, temp, $new($DerOutputStream));
		for (int32_t i = 0; i < $nc(this->entry)->length; ++i) {
			temp->write($($nc($nc(this->entry)->get(i))->asn1Encode()));
		}
		bytes->write($DerValue::tag_Sequence, temp);
		return bytes->toByteArray();
	}
	return nullptr;
}

LastReq* LastReq::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(LastReq, subDer);
	}
}

LastReq::LastReq() {
}

$Class* LastReq::load$($String* name, bool initialize) {
	$loadClass(LastReq, name, initialize, &_LastReq_ClassInfo_, allocate$LastReq);
	return class$;
}

$Class* LastReq::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun