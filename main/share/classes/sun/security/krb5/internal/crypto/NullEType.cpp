#include <sun/security/krb5/internal/crypto/NullEType.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <jcpp.h>

#undef CKSUMTYPE_NULL
#undef ETYPE_NULL
#undef KEYTYPE_NULL

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Checksum = ::sun::security::krb5::Checksum;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $EType = ::sun::security::krb5::internal::crypto::EType;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _NullEType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(NullEType::*)()>(&NullEType::init$))},
	{"blockSize", "()I", nullptr, $PUBLIC},
	{"checksumSize", "()I", nullptr, $PUBLIC},
	{"checksumType", "()I", nullptr, $PUBLIC},
	{"confounderSize", "()I", nullptr, $PUBLIC},
	{"decrypt", "([B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KrbApErrException"},
	{"decrypt", "([B[B[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KrbApErrException"},
	{"eType", "()I", nullptr, $PUBLIC},
	{"encrypt", "([B[BI)[B", nullptr, $PUBLIC},
	{"encrypt", "([B[B[BI)[B", nullptr, $PUBLIC},
	{"keySize", "()I", nullptr, $PUBLIC},
	{"keyType", "()I", nullptr, $PUBLIC},
	{"minimumPadSize", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _NullEType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.NullEType",
	"sun.security.krb5.internal.crypto.EType",
	nullptr,
	nullptr,
	_NullEType_MethodInfo_
};

$Object* allocate$NullEType($Class* clazz) {
	return $of($alloc(NullEType));
}

void NullEType::init$() {
	$EType::init$();
}

int32_t NullEType::eType() {
	return $EncryptedData::ETYPE_NULL;
}

int32_t NullEType::minimumPadSize() {
	return 0;
}

int32_t NullEType::confounderSize() {
	return 0;
}

int32_t NullEType::checksumType() {
	return $Checksum::CKSUMTYPE_NULL;
}

int32_t NullEType::checksumSize() {
	return 0;
}

int32_t NullEType::blockSize() {
	return 1;
}

int32_t NullEType::keyType() {
	return $Krb5::KEYTYPE_NULL;
}

int32_t NullEType::keySize() {
	return 0;
}

$bytes* NullEType::encrypt($bytes* data, $bytes* key, int32_t usage) {
	$var($bytes, cipher, $new($bytes, $nc(data)->length));
	$System::arraycopy(data, 0, cipher, 0, data->length);
	return cipher;
}

$bytes* NullEType::encrypt($bytes* data, $bytes* key, $bytes* ivec, int32_t usage) {
	$var($bytes, cipher, $new($bytes, $nc(data)->length));
	$System::arraycopy(data, 0, cipher, 0, data->length);
	return cipher;
}

$bytes* NullEType::decrypt($bytes* cipher, $bytes* key, int32_t usage) {
	return $cast($bytes, $nc(cipher)->clone());
}

$bytes* NullEType::decrypt($bytes* cipher, $bytes* key, $bytes* ivec, int32_t usage) {
	return $cast($bytes, $nc(cipher)->clone());
}

NullEType::NullEType() {
}

$Class* NullEType::load$($String* name, bool initialize) {
	$loadClass(NullEType, name, initialize, &_NullEType_ClassInfo_, allocate$NullEType);
	return class$;
}

$Class* NullEType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun