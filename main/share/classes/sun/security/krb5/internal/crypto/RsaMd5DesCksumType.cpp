#include <sun/security/krb5/internal/crypto/RsaMd5DesCksumType.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/MessageDigest.h>
#include <javax/crypto/spec/DESKeySpec.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/Confounder.h>
#include <sun/security/krb5/KrbCryptoException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>
#include <sun/security/krb5/internal/crypto/Des.h>
#include <jcpp.h>

#undef CKSUMTYPE_RSA_MD5_DES
#undef KEYTYPE_DES

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $MessageDigest = ::java::security::MessageDigest;
using $DESKeySpec = ::javax::crypto::spec::DESKeySpec;
using $Checksum = ::sun::security::krb5::Checksum;
using $Confounder = ::sun::security::krb5::Confounder;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $CksumType = ::sun::security::krb5::internal::crypto::CksumType;
using $Des = ::sun::security::krb5::internal::crypto::Des;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _RsaMd5DesCksumType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RsaMd5DesCksumType::*)()>(&RsaMd5DesCksumType::init$))},
	{"calculateChecksum", "([BI[BI)[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{"calculateRawChecksum", "([BI)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(RsaMd5DesCksumType::*)($bytes*,int32_t)>(&RsaMd5DesCksumType::calculateRawChecksum)), "sun.security.krb5.KrbCryptoException"},
	{"cksumSize", "()I", nullptr, $PUBLIC},
	{"cksumType", "()I", nullptr, $PUBLIC},
	{"confounderSize", "()I", nullptr, $PUBLIC},
	{"decryptKeyedChecksum", "([B[B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(RsaMd5DesCksumType::*)($bytes*,$bytes*)>(&RsaMd5DesCksumType::decryptKeyedChecksum)), "sun.security.krb5.KrbCryptoException"},
	{"isKeyed", "()Z", nullptr, $PUBLIC},
	{"keySize", "()I", nullptr, $PUBLIC},
	{"keyType", "()I", nullptr, $PUBLIC},
	{"verifyChecksum", "([BI[B[BI)Z", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbCryptoException"},
	{}
};

$ClassInfo _RsaMd5DesCksumType_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.RsaMd5DesCksumType",
	"sun.security.krb5.internal.crypto.CksumType",
	nullptr,
	nullptr,
	_RsaMd5DesCksumType_MethodInfo_
};

$Object* allocate$RsaMd5DesCksumType($Class* clazz) {
	return $of($alloc(RsaMd5DesCksumType));
}

void RsaMd5DesCksumType::init$() {
	$CksumType::init$();
}

int32_t RsaMd5DesCksumType::confounderSize() {
	return 8;
}

int32_t RsaMd5DesCksumType::cksumType() {
	return $Checksum::CKSUMTYPE_RSA_MD5_DES;
}

bool RsaMd5DesCksumType::isKeyed() {
	return true;
}

int32_t RsaMd5DesCksumType::cksumSize() {
	return 24;
}

int32_t RsaMd5DesCksumType::keyType() {
	return $Krb5::KEYTYPE_DES;
}

int32_t RsaMd5DesCksumType::keySize() {
	return 8;
}

$bytes* RsaMd5DesCksumType::calculateChecksum($bytes* data, int32_t size, $bytes* key, int32_t usage) {
	$var($bytes, new_data, $new($bytes, size + confounderSize()));
	$var($bytes, conf, $Confounder::bytes(confounderSize()));
	$System::arraycopy(conf, 0, new_data, 0, confounderSize());
	$System::arraycopy(data, 0, new_data, confounderSize(), size);
	$var($bytes, mdc_cksum, calculateRawChecksum(new_data, new_data->length));
	$var($bytes, cksum, $new($bytes, cksumSize()));
	$System::arraycopy(conf, 0, cksum, 0, confounderSize());
	$var($Object, var$0, $of(mdc_cksum));
	$var($Object, var$1, $of(cksum));
	int32_t var$2 = confounderSize();
	int32_t var$3 = cksumSize();
	$System::arraycopy(var$0, 0, var$1, var$2, var$3 - confounderSize());
	$var($bytes, new_key, $new($bytes, keySize()));
	$System::arraycopy(key, 0, new_key, 0, $nc(key)->length);
	for (int32_t i = 0; i < new_key->length; ++i) {
		new_key->set(i, (int8_t)(new_key->get(i) ^ 240));
	}
	try {
		if ($DESKeySpec::isWeak(new_key, 0)) {
			new_key->set(7, (int8_t)(new_key->get(7) ^ 240));
		}
	} catch ($InvalidKeyException&) {
		$catch();
	}
	$var($bytes, ivec, $new($bytes, new_key->length));
	$var($bytes, enc_cksum, $new($bytes, cksum->length));
	$Des::cbc_encrypt(cksum, enc_cksum, new_key, ivec, true);
	return enc_cksum;
}

bool RsaMd5DesCksumType::verifyChecksum($bytes* data, int32_t size, $bytes* key, $bytes* checksum, int32_t usage) {
	$var($bytes, cksum, decryptKeyedChecksum(checksum, key));
	$var($bytes, new_data, $new($bytes, size + confounderSize()));
	$System::arraycopy(cksum, 0, new_data, 0, confounderSize());
	$System::arraycopy(data, 0, new_data, confounderSize(), size);
	$var($bytes, new_cksum, calculateRawChecksum(new_data, new_data->length));
	int32_t var$0 = cksumSize();
	$var($bytes, orig_cksum, $new($bytes, var$0 - confounderSize()));
	$var($Object, var$1, $of(cksum));
	int32_t var$2 = confounderSize();
	$var($Object, var$3, $of(orig_cksum));
	int32_t var$4 = cksumSize();
	$System::arraycopy(var$1, var$2, var$3, 0, var$4 - confounderSize());
	return isChecksumEqual(orig_cksum, new_cksum);
}

$bytes* RsaMd5DesCksumType::decryptKeyedChecksum($bytes* enc_cksum, $bytes* key) {
	$var($bytes, new_key, $new($bytes, keySize()));
	$System::arraycopy(key, 0, new_key, 0, $nc(key)->length);
	for (int32_t i = 0; i < new_key->length; ++i) {
		new_key->set(i, (int8_t)(new_key->get(i) ^ 240));
	}
	try {
		if ($DESKeySpec::isWeak(new_key, 0)) {
			new_key->set(7, (int8_t)(new_key->get(7) ^ 240));
		}
	} catch ($InvalidKeyException&) {
		$catch();
	}
	$var($bytes, ivec, $new($bytes, new_key->length));
	$var($bytes, cksum, $new($bytes, $nc(enc_cksum)->length));
	$Des::cbc_encrypt(enc_cksum, cksum, new_key, ivec, false);
	return cksum;
}

$bytes* RsaMd5DesCksumType::calculateRawChecksum($bytes* data, int32_t size) {
	$var($MessageDigest, md5, nullptr);
	$var($bytes, result, nullptr);
	try {
		$assign(md5, $MessageDigest::getInstance("MD5"_s));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$throwNew($KrbCryptoException, $$str({"JCE provider may not be installed. "_s, $(e->getMessage())}));
	}
	try {
		$nc(md5)->update(data);
		$assign(result, md5->digest());
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$throwNew($KrbCryptoException, $(e->getMessage()));
	}
	return result;
}

RsaMd5DesCksumType::RsaMd5DesCksumType() {
}

$Class* RsaMd5DesCksumType::load$($String* name, bool initialize) {
	$loadClass(RsaMd5DesCksumType, name, initialize, &_RsaMd5DesCksumType_ClassInfo_, allocate$RsaMd5DesCksumType);
	return class$;
}

$Class* RsaMd5DesCksumType::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun