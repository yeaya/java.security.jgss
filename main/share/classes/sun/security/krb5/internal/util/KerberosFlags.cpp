#include <sun/security/krb5/internal/util/KerberosFlags.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Arrays.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerOutputStream.h>
#include <jcpp.h>

#undef BITS_PER_UNIT
#undef KRB_FLAGS_MAX

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $BitArray = ::sun::security::util::BitArray;
using $DerOutputStream = ::sun::security::util::DerOutputStream;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace util {

$FieldInfo _KerberosFlags_FieldInfo_[] = {
	{"bits", "Lsun/security/util/BitArray;", nullptr, 0, $field(KerberosFlags, bits)},
	{"BITS_PER_UNIT", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(KerberosFlags, BITS_PER_UNIT)},
	{}
};

$MethodInfo _KerberosFlags_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosFlags::*)(int32_t)>(&KerberosFlags::init$)), "java.lang.IllegalArgumentException"},
	{"<init>", "(I[B)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosFlags::*)(int32_t,$bytes*)>(&KerberosFlags::init$)), "java.lang.IllegalArgumentException"},
	{"<init>", "([Z)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosFlags::*)($booleans*)>(&KerberosFlags::init$))},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"get", "(I)Z", nullptr, $PUBLIC},
	{"set", "(IZ)V", nullptr, $PUBLIC},
	{"toBooleanArray", "()[Z", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KerberosFlags_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.util.KerberosFlags",
	"java.lang.Object",
	nullptr,
	_KerberosFlags_FieldInfo_,
	_KerberosFlags_MethodInfo_
};

$Object* allocate$KerberosFlags($Class* clazz) {
	return $of($alloc(KerberosFlags));
}

void KerberosFlags::init$(int32_t length) {
	$set(this, bits, $new($BitArray, length));
}

void KerberosFlags::init$(int32_t length, $bytes* a) {
	$set(this, bits, $new($BitArray, length, a));
	if (length != $Krb5::KRB_FLAGS_MAX + 1) {
		$set(this, bits, $new($BitArray, $($Arrays::copyOf($($nc(this->bits)->toBooleanArray()), $Krb5::KRB_FLAGS_MAX + 1))));
	}
}

void KerberosFlags::init$($booleans* bools) {
	$set(this, bits, $new($BitArray, ($nc(bools)->length == $Krb5::KRB_FLAGS_MAX + 1) ? bools : $($Arrays::copyOf(bools, $Krb5::KRB_FLAGS_MAX + 1))));
}

void KerberosFlags::set(int32_t index, bool value) {
	$nc(this->bits)->set(index, value);
}

bool KerberosFlags::get(int32_t index) {
	return $nc(this->bits)->get(index);
}

$booleans* KerberosFlags::toBooleanArray() {
	return $nc(this->bits)->toBooleanArray();
}

$bytes* KerberosFlags::asn1Encode() {
	$var($DerOutputStream, out, $new($DerOutputStream));
	out->putUnalignedBitString(this->bits);
	return out->toByteArray();
}

$String* KerberosFlags::toString() {
	return $nc(this->bits)->toString();
}

KerberosFlags::KerberosFlags() {
}

$Class* KerberosFlags::load$($String* name, bool initialize) {
	$loadClass(KerberosFlags, name, initialize, &_KerberosFlags_ClassInfo_, allocate$KerberosFlags);
	return class$;
}

$Class* KerberosFlags::class$ = nullptr;

				} // util
			} // internal
		} // krb5
	} // security
} // sun