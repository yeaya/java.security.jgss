#include <sun/security/krb5/internal/crypto/Crc32CksumType.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>
#include <sun/security/krb5/internal/crypto/crc32.h>
#include <jcpp.h>

#undef CKSUMTYPE_CRC32
#undef KEYTYPE_NULL

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Checksum = ::sun::security::krb5::Checksum;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $CksumType = ::sun::security::krb5::internal::crypto::CksumType;
using $crc32 = ::sun::security::krb5::internal::crypto::crc32;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _Crc32CksumType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Crc32CksumType::*)()>(&Crc32CksumType::init$))},
	{"bytes2long", "([B)J", nullptr, $PUBLIC | $STATIC, $method(static_cast<int64_t(*)($bytes*)>(&Crc32CksumType::bytes2long))},
	{"calculateChecksum", "([BI[BI)[B", nullptr, $PUBLIC},
	{"cksumSize", "()I", nullptr, $PUBLIC},
	{"cksumType", "()I", nullptr, $PUBLIC},
	{"confounderSize", "()I", nullptr, $PUBLIC},
	{"int2quad", "(J)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)(int64_t)>(&Crc32CksumType::int2quad))},
	{"isKeyed", "()Z", nullptr, $PUBLIC},
	{"keySize", "()I", nullptr, $PUBLIC},
	{"keyType", "()I", nullptr, $PUBLIC},
	{"verifyChecksum", "([BI[B[BI)Z", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Crc32CksumType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.Crc32CksumType",
	"sun.security.krb5.internal.crypto.CksumType",
	nullptr,
	nullptr,
	_Crc32CksumType_MethodInfo_
};

$Object* allocate$Crc32CksumType($Class* clazz) {
	return $of($alloc(Crc32CksumType));
}

void Crc32CksumType::init$() {
	$CksumType::init$();
}

int32_t Crc32CksumType::confounderSize() {
	return 0;
}

int32_t Crc32CksumType::cksumType() {
	return $Checksum::CKSUMTYPE_CRC32;
}

bool Crc32CksumType::isKeyed() {
	return false;
}

int32_t Crc32CksumType::cksumSize() {
	return 4;
}

int32_t Crc32CksumType::keyType() {
	return $Krb5::KEYTYPE_NULL;
}

int32_t Crc32CksumType::keySize() {
	return 0;
}

$bytes* Crc32CksumType::calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) {
	return $crc32::byte2crc32sum_bytes(data, size);
}

bool Crc32CksumType::verifyChecksum($bytes* data, int32_t size, $bytes* key, $bytes* checksum, int32_t usage) {
	return $CksumType::isChecksumEqual(checksum, $($crc32::byte2crc32sum_bytes(data)));
}

$bytes* Crc32CksumType::int2quad(int64_t input) {
	$init(Crc32CksumType);
	$var($bytes, output, $new($bytes, 4));
	for (int32_t i = 0; i < 4; ++i) {
		output->set(i, (int8_t)((int64_t)(($usr(input, i * 8)) & (uint64_t)(int64_t)255)));
	}
	return output;
}

int64_t Crc32CksumType::bytes2long($bytes* input) {
	$init(Crc32CksumType);
	int64_t result = 0;
	result |= ((int64_t)(((int64_t)$nc(input)->get(0)) & (uint64_t)(int64_t)255)) << 24;
	result |= ((int64_t)(((int64_t)input->get(1)) & (uint64_t)(int64_t)255)) << 16;
	result |= ((int64_t)(((int64_t)input->get(2)) & (uint64_t)(int64_t)255)) << 8;
	result |= ((int64_t)(((int64_t)input->get(3)) & (uint64_t)(int64_t)255));
	return result;
}

Crc32CksumType::Crc32CksumType() {
}

$Class* Crc32CksumType::load$($String* name, bool initialize) {
	$loadClass(Crc32CksumType, name, initialize, &_Crc32CksumType_ClassInfo_, allocate$Crc32CksumType);
	return class$;
}

$Class* Crc32CksumType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun