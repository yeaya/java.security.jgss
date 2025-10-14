#include <sun/security/krb5/internal/APOptions.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/util/KerberosFlags.h>
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef AP_OPTS_MAX
#undef ASN1_BAD_ID
#undef BITSTRING_BAD_LENGTH
#undef BITS_PER_UNIT

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $BitArray = ::sun::security::util::BitArray;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$MethodInfo _APOptions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(APOptions::*)()>(&APOptions::init$))},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(APOptions::*)(int32_t)>(&APOptions::init$)), "sun.security.krb5.Asn1Exception"},
	{"<init>", "(I[B)V", nullptr, $PUBLIC, $method(static_cast<void(APOptions::*)(int32_t,$bytes*)>(&APOptions::init$)), "sun.security.krb5.Asn1Exception"},
	{"<init>", "([Z)V", nullptr, $PUBLIC, $method(static_cast<void(APOptions::*)($booleans*)>(&APOptions::init$)), "sun.security.krb5.Asn1Exception"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(APOptions::*)($DerValue*)>(&APOptions::init$)), "java.io.IOException,sun.security.krb5.Asn1Exception"},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/internal/APOptions;", nullptr, $PUBLIC | $STATIC, $method(static_cast<APOptions*(*)($DerInputStream*,int8_t,bool)>(&APOptions::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{}
};

$ClassInfo _APOptions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.APOptions",
	"sun.security.krb5.internal.util.KerberosFlags",
	nullptr,
	nullptr,
	_APOptions_MethodInfo_
};

$Object* allocate$APOptions($Class* clazz) {
	return $of($alloc(APOptions));
}

void APOptions::init$() {
	$KerberosFlags::init$($Krb5::AP_OPTS_MAX + 1);
}

void APOptions::init$(int32_t oneBit) {
	$KerberosFlags::init$($Krb5::AP_OPTS_MAX + 1);
	set(oneBit, true);
}

void APOptions::init$(int32_t size, $bytes* data) {
	$KerberosFlags::init$(size, data);
	if ((size > $nc(data)->length * $KerberosFlags::BITS_PER_UNIT) || (size > $Krb5::AP_OPTS_MAX + 1)) {
		$throwNew($Asn1Exception, $Krb5::BITSTRING_BAD_LENGTH);
	}
}

void APOptions::init$($booleans* data) {
	$KerberosFlags::init$(data);
	if ($nc(data)->length > $Krb5::AP_OPTS_MAX + 1) {
		$throwNew($Asn1Exception, $Krb5::BITSTRING_BAD_LENGTH);
	}
}

void APOptions::init$($DerValue* encoding) {
	APOptions::init$($($nc($($nc(encoding)->getUnalignedBitString(true)))->toBooleanArray()));
}

APOptions* APOptions::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(APOptions);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(APOptions, subDer);
	}
}

APOptions::APOptions() {
}

$Class* APOptions::load$($String* name, bool initialize) {
	$loadClass(APOptions, name, initialize, &_APOptions_ClassInfo_, allocate$APOptions);
	return class$;
}

$Class* APOptions::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun