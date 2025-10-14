#include <sun/security/jgss/krb5/CipherHelper.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/Math.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/CipherInputStream.h>
#include <javax/crypto/CipherOutputStream.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <org/ietf/jgss/GSSException.h>
#include <sun/security/jgss/krb5/CipherHelper$WrapTokenInputStream.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/krb5/Krb5Util.h>
#include <sun/security/jgss/krb5/MessageToken.h>
#include <sun/security/jgss/krb5/WrapToken.h>
#include <sun/security/jgss/krb5/WrapToken_v2.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/internal/crypto/Aes128.h>
#include <sun/security/krb5/internal/crypto/Aes128Sha2.h>
#include <sun/security/krb5/internal/crypto/Aes256.h>
#include <sun/security/krb5/internal/crypto/Aes256Sha2.h>
#include <sun/security/krb5/internal/crypto/ArcFourHmac.h>
#include <sun/security/krb5/internal/crypto/Des3.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <jcpp.h>

#undef AES_IV_SIZE
#undef CONFOUNDER_SIZE
#undef DEBUG
#undef DECRYPT_MODE
#undef DEFECTIVE_TOKEN
#undef DES_CHECKSUM_SIZE
#undef DES_IV_SIZE
#undef ENCRYPT_MODE
#undef ETYPE_ARCFOUR_HMAC
#undef ETYPE_DES3_CBC_HMAC_SHA1_KD
#undef ETYPE_DES_CBC_CRC
#undef ETYPE_DES_CBC_MD5
#undef FAILURE
#undef HMAC_CHECKSUM_SIZE
#undef KG_USAGE_SEAL
#undef KG_USAGE_SEQ
#undef KG_USAGE_SIGN
#undef KG_USAGE_SIGN_MS
#undef MIC_ID
#undef SEAL_ALG_ARCFOUR_HMAC
#undef SEAL_ALG_DES
#undef SEAL_ALG_DES3_KD
#undef SGN_ALG_DES_MAC
#undef SGN_ALG_DES_MAC_MD5
#undef SGN_ALG_HMAC_MD5_ARCFOUR
#undef SGN_ALG_HMAC_SHA1_DES3_KD
#undef TOKEN_HEADER_SIZE
#undef ZERO_IV
#undef ZERO_IV_AES

using $byteArray2 = $Array<int8_t, 2>;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Cipher = ::javax::crypto::Cipher;
using $CipherInputStream = ::javax::crypto::CipherInputStream;
using $CipherOutputStream = ::javax::crypto::CipherOutputStream;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $CipherHelper$WrapTokenInputStream = ::sun::security::jgss::krb5::CipherHelper$WrapTokenInputStream;
using $Krb5Token = ::sun::security::jgss::krb5::Krb5Token;
using $Krb5Util = ::sun::security::jgss::krb5::Krb5Util;
using $MessageToken = ::sun::security::jgss::krb5::MessageToken;
using $WrapToken = ::sun::security::jgss::krb5::WrapToken;
using $WrapToken_v2 = ::sun::security::jgss::krb5::WrapToken_v2;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $Aes128 = ::sun::security::krb5::internal::crypto::Aes128;
using $Aes128Sha2 = ::sun::security::krb5::internal::crypto::Aes128Sha2;
using $Aes256 = ::sun::security::krb5::internal::crypto::Aes256;
using $Aes256Sha2 = ::sun::security::krb5::internal::crypto::Aes256Sha2;
using $ArcFourHmac = ::sun::security::krb5::internal::crypto::ArcFourHmac;
using $Des3 = ::sun::security::krb5::internal::crypto::Des3;
using $EType = ::sun::security::krb5::internal::crypto::EType;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _CipherHelper_FieldInfo_[] = {
	{"KG_USAGE_SEAL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherHelper, KG_USAGE_SEAL)},
	{"KG_USAGE_SIGN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherHelper, KG_USAGE_SIGN)},
	{"KG_USAGE_SEQ", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherHelper, KG_USAGE_SEQ)},
	{"DES_CHECKSUM_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherHelper, DES_CHECKSUM_SIZE)},
	{"DES_IV_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherHelper, DES_IV_SIZE)},
	{"AES_IV_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherHelper, AES_IV_SIZE)},
	{"HMAC_CHECKSUM_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherHelper, HMAC_CHECKSUM_SIZE)},
	{"KG_USAGE_SIGN_MS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherHelper, KG_USAGE_SIGN_MS)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CipherHelper, DEBUG)},
	{"ZERO_IV", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CipherHelper, ZERO_IV)},
	{"ZERO_IV_AES", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CipherHelper, ZERO_IV_AES)},
	{"etype", "I", nullptr, $PRIVATE, $field(CipherHelper, etype)},
	{"sgnAlg", "I", nullptr, $PRIVATE, $field(CipherHelper, sgnAlg)},
	{"sealAlg", "I", nullptr, $PRIVATE, $field(CipherHelper, sealAlg)},
	{"keybytes", "[B", nullptr, $PRIVATE, $field(CipherHelper, keybytes)},
	{}
};

$MethodInfo _CipherHelper_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/EncryptionKey;)V", nullptr, 0, $method(static_cast<void(CipherHelper::*)($EncryptionKey*)>(&CipherHelper::init$)), "org.ietf.jgss.GSSException"},
	{"aes128Decrypt", "(Lsun/security/jgss/krb5/WrapToken_v2;[BII[BII)V", nullptr, $PRIVATE, $method(static_cast<void(CipherHelper::*)($WrapToken_v2*,$bytes*,int32_t,int32_t,$bytes*,int32_t,int32_t)>(&CipherHelper::aes128Decrypt)), "org.ietf.jgss.GSSException"},
	{"aes128Encrypt", "([B[B[BIII)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(CipherHelper::*)($bytes*,$bytes*,$bytes*,int32_t,int32_t,int32_t)>(&CipherHelper::aes128Encrypt)), "org.ietf.jgss.GSSException"},
	{"aes128Sha2Decrypt", "(Lsun/security/jgss/krb5/WrapToken_v2;[BII[BII)V", nullptr, $PRIVATE, $method(static_cast<void(CipherHelper::*)($WrapToken_v2*,$bytes*,int32_t,int32_t,$bytes*,int32_t,int32_t)>(&CipherHelper::aes128Sha2Decrypt)), "org.ietf.jgss.GSSException"},
	{"aes128Sha2Encrypt", "([B[B[BIII)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(CipherHelper::*)($bytes*,$bytes*,$bytes*,int32_t,int32_t,int32_t)>(&CipherHelper::aes128Sha2Encrypt)), "org.ietf.jgss.GSSException"},
	{"aes256Decrypt", "(Lsun/security/jgss/krb5/WrapToken_v2;[BII[BII)V", nullptr, $PRIVATE, $method(static_cast<void(CipherHelper::*)($WrapToken_v2*,$bytes*,int32_t,int32_t,$bytes*,int32_t,int32_t)>(&CipherHelper::aes256Decrypt)), "org.ietf.jgss.GSSException"},
	{"aes256Encrypt", "([B[B[BIII)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(CipherHelper::*)($bytes*,$bytes*,$bytes*,int32_t,int32_t,int32_t)>(&CipherHelper::aes256Encrypt)), "org.ietf.jgss.GSSException"},
	{"aes256Sha2Decrypt", "(Lsun/security/jgss/krb5/WrapToken_v2;[BII[BII)V", nullptr, $PRIVATE, $method(static_cast<void(CipherHelper::*)($WrapToken_v2*,$bytes*,int32_t,int32_t,$bytes*,int32_t,int32_t)>(&CipherHelper::aes256Sha2Decrypt)), "org.ietf.jgss.GSSException"},
	{"aes256Sha2Encrypt", "([B[B[BIII)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(CipherHelper::*)($bytes*,$bytes*,$bytes*,int32_t,int32_t,int32_t)>(&CipherHelper::aes256Sha2Encrypt)), "org.ietf.jgss.GSSException"},
	{"arcFourDecrypt", "(Lsun/security/jgss/krb5/WrapToken;[BII[BI)V", nullptr, $PRIVATE, $method(static_cast<void(CipherHelper::*)($WrapToken*,$bytes*,int32_t,int32_t,$bytes*,int32_t)>(&CipherHelper::arcFourDecrypt)), "org.ietf.jgss.GSSException"},
	{"arcFourEncrypt", "(Lsun/security/jgss/krb5/WrapToken;[B[BII[B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(CipherHelper::*)($WrapToken*,$bytes*,$bytes*,int32_t,int32_t,$bytes*)>(&CipherHelper::arcFourEncrypt)), "org.ietf.jgss.GSSException"},
	{"calculateChecksum", "(I[B[B[BIII)[B", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"calculateChecksum", "([B[BIII)[B", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"decryptData", "(Lsun/security/jgss/krb5/WrapToken;[BII[BI)V", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"decryptData", "(Lsun/security/jgss/krb5/WrapToken_v2;[BII[BII)V", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"decryptData", "(Lsun/security/jgss/krb5/WrapToken;Ljava/io/InputStream;I[BI)V", nullptr, 0, nullptr, "org.ietf.jgss.GSSException,java.io.IOException"},
	{"decryptData", "(Lsun/security/jgss/krb5/WrapToken_v2;Ljava/io/InputStream;I[BII)V", nullptr, 0, nullptr, "org.ietf.jgss.GSSException,java.io.IOException"},
	{"decryptSeq", "([B[BII)[B", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"des3KdDecrypt", "(Lsun/security/jgss/krb5/WrapToken;[BII[BI)V", nullptr, $PRIVATE, $method(static_cast<void(CipherHelper::*)($WrapToken*,$bytes*,int32_t,int32_t,$bytes*,int32_t)>(&CipherHelper::des3KdDecrypt)), "org.ietf.jgss.GSSException"},
	{"des3KdEncrypt", "([B[BII[B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(CipherHelper::*)($bytes*,$bytes*,int32_t,int32_t,$bytes*)>(&CipherHelper::des3KdEncrypt)), "org.ietf.jgss.GSSException"},
	{"desCbcDecrypt", "(Lsun/security/jgss/krb5/WrapToken;[B[BII[BI)V", nullptr, $PRIVATE, $method(static_cast<void(CipherHelper::*)($WrapToken*,$bytes*,$bytes*,int32_t,int32_t,$bytes*,int32_t)>(&CipherHelper::desCbcDecrypt)), "org.ietf.jgss.GSSException"},
	{"desCbcDecrypt", "(Lsun/security/jgss/krb5/WrapToken;[BLjava/io/InputStream;I[BI)V", nullptr, $PRIVATE, $method(static_cast<void(CipherHelper::*)($WrapToken*,$bytes*,$InputStream*,int32_t,$bytes*,int32_t)>(&CipherHelper::desCbcDecrypt)), "org.ietf.jgss.GSSException,java.io.IOException"},
	{"encryptData", "(Lsun/security/jgss/krb5/WrapToken;[B[BII[BLjava/io/OutputStream;)V", nullptr, 0, nullptr, "org.ietf.jgss.GSSException,java.io.IOException"},
	{"encryptData", "(Lsun/security/jgss/krb5/WrapToken_v2;[B[B[BIII)[B", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"encryptData", "(Lsun/security/jgss/krb5/WrapToken;[B[BII[B[BI)V", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"encryptData", "(Lsun/security/jgss/krb5/WrapToken_v2;[B[B[BII[BII)I", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"encryptSeq", "([B[BII)[B", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"getChecksumLength", "()I", nullptr, 0, nullptr, "org.ietf.jgss.GSSException"},
	{"getDesCbcChecksum", "([B[B[BII)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(CipherHelper::*)($bytes*,$bytes*,$bytes*,int32_t,int32_t)>(&CipherHelper::getDesCbcChecksum)), "org.ietf.jgss.GSSException"},
	{"getDesEncryptionKey", "([B)[B", nullptr, $PRIVATE | $STATIC, $method(static_cast<$bytes*(*)($bytes*)>(&CipherHelper::getDesEncryptionKey)), "org.ietf.jgss.GSSException"},
	{"getEType", "()I", nullptr, 0},
	{"getInitializedDes", "(Z[B[B)Ljavax/crypto/Cipher;", nullptr, $PRIVATE | $FINAL, $method(static_cast<$Cipher*(CipherHelper::*)(bool,$bytes*,$bytes*)>(&CipherHelper::getInitializedDes)), "org.ietf.jgss.GSSException"},
	{"getProto", "()I", nullptr, 0},
	{"getSealAlg", "()I", nullptr, 0},
	{"getSgnAlg", "()I", nullptr, 0},
	{"isArcFour", "()Z", nullptr, 0},
	{}
};

$InnerClassInfo _CipherHelper_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.CipherHelper$WrapTokenInputStream", "sun.security.jgss.krb5.CipherHelper", "WrapTokenInputStream", 0},
	{}
};

$ClassInfo _CipherHelper_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.CipherHelper",
	"java.lang.Object",
	nullptr,
	_CipherHelper_FieldInfo_,
	_CipherHelper_MethodInfo_,
	nullptr,
	nullptr,
	_CipherHelper_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.CipherHelper$WrapTokenInputStream"
};

$Object* allocate$CipherHelper($Class* clazz) {
	return $of($alloc(CipherHelper));
}

bool CipherHelper::DEBUG = false;

$bytes* CipherHelper::ZERO_IV = nullptr;
$bytes* CipherHelper::ZERO_IV_AES = nullptr;

void CipherHelper::init$($EncryptionKey* key) {
	this->etype = $nc(key)->getEType();
	$set(this, keybytes, key->getBytes());
	switch (this->etype) {
	case $EncryptedData::ETYPE_DES_CBC_CRC:
		{}
	case $EncryptedData::ETYPE_DES_CBC_MD5:
		{
			this->sgnAlg = $MessageToken::SGN_ALG_DES_MAC_MD5;
			this->sealAlg = $MessageToken::SEAL_ALG_DES;
			break;
		}
	case $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD:
		{
			this->sgnAlg = $MessageToken::SGN_ALG_HMAC_SHA1_DES3_KD;
			this->sealAlg = $MessageToken::SEAL_ALG_DES3_KD;
			break;
		}
	case $EncryptedData::ETYPE_ARCFOUR_HMAC:
		{
			this->sgnAlg = $MessageToken::SGN_ALG_HMAC_MD5_ARCFOUR;
			this->sealAlg = $MessageToken::SEAL_ALG_ARCFOUR_HMAC;
			break;
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
		{}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
		{}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
		{}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
		{
			this->sgnAlg = -1;
			this->sealAlg = -1;
			break;
		}
	default:
		{
			$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported encryption type: "_s, $$str(this->etype)}));
		}
	}
}

int32_t CipherHelper::getSgnAlg() {
	return this->sgnAlg;
}

int32_t CipherHelper::getSealAlg() {
	return this->sealAlg;
}

int32_t CipherHelper::getProto() {
	return $EType::isNewer(this->etype) ? 1 : 0;
}

int32_t CipherHelper::getEType() {
	return this->etype;
}

bool CipherHelper::isArcFour() {
	bool flag = false;
	if (this->etype == $EncryptedData::ETYPE_ARCFOUR_HMAC) {
		flag = true;
	}
	return flag;
}

$bytes* CipherHelper::calculateChecksum(int32_t alg, $bytes* header$renamed, $bytes* trailer$renamed, $bytes* data$renamed, int32_t start, int32_t len, int32_t tokenId) {
	$var($bytes, trailer, trailer$renamed);
	$var($bytes, data, data$renamed);
	$var($bytes, header, header$renamed);
	{
		$var($bytes, buf, nullptr)
		int32_t offset = 0;
		int32_t total = 0;
		$var($bytes, buffer, nullptr)
		int32_t off = 0;
		int32_t tot = 0;
		switch (alg) {
		case $MessageToken::SGN_ALG_DES_MAC_MD5:
			{
				try {
					$var($MessageDigest, md5, $MessageDigest::getInstance("MD5"_s));
					$nc(md5)->update(header);
					md5->update(data, start, len);
					if (trailer != nullptr) {
						md5->update(trailer);
					}
					$assign(data, md5->digest());
					start = 0;
					len = $nc(data)->length;
					$assign(header, nullptr);
					$assign(trailer, nullptr);
				} catch ($NoSuchAlgorithmException&) {
					$var($NoSuchAlgorithmException, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not get MD5 Message Digest - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
			}
		case $MessageToken::SGN_ALG_DES_MAC:
			{
				return getDesCbcChecksum(this->keybytes, header, data, start, len);
			}
		case $MessageToken::SGN_ALG_HMAC_SHA1_DES3_KD:
			{
				if (header == nullptr && trailer == nullptr) {
					$assign(buf, data);
					total = len;
					offset = start;
				} else {
					total = ((header != nullptr ? $nc(header)->length : 0) + len + (trailer != nullptr ? $nc(trailer)->length : 0));
					$assign(buf, $new($bytes, total));
					int32_t pos = 0;
					if (header != nullptr) {
						$System::arraycopy(header, 0, buf, 0, header->length);
						pos = header->length;
					}
					$System::arraycopy(data, start, buf, pos, len);
					pos += len;
					if (trailer != nullptr) {
						$System::arraycopy(trailer, 0, buf, pos, trailer->length);
					}
					offset = 0;
				}
				try {
					$var($bytes, answer, $Des3::calculateChecksum(this->keybytes, CipherHelper::KG_USAGE_SIGN, buf, offset, total));
					return answer;
				} catch ($GeneralSecurityException&) {
					$var($GeneralSecurityException, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use HMAC-SHA1-DES3-KD signing algorithm - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
			}
		case $MessageToken::SGN_ALG_HMAC_MD5_ARCFOUR:
			{
				if (header == nullptr && trailer == nullptr) {
					$assign(buffer, data);
					tot = len;
					off = start;
				} else {
					tot = ((header != nullptr ? $nc(header)->length : 0) + len + (trailer != nullptr ? $nc(trailer)->length : 0));
					$assign(buffer, $new($bytes, tot));
					int32_t pos = 0;
					if (header != nullptr) {
						$System::arraycopy(header, 0, buffer, 0, header->length);
						pos = header->length;
					}
					$System::arraycopy(data, start, buffer, pos, len);
					pos += len;
					if (trailer != nullptr) {
						$System::arraycopy(trailer, 0, buffer, pos, trailer->length);
					}
					off = 0;
				}
				try {
					int32_t key_usage = CipherHelper::KG_USAGE_SIGN;
					if (tokenId == $Krb5Token::MIC_ID) {
						key_usage = CipherHelper::KG_USAGE_SIGN_MS;
					}
					$var($bytes, answer, $ArcFourHmac::calculateChecksum(this->keybytes, key_usage, buffer, off, tot));
					$var($bytes, output, $new($bytes, getChecksumLength()));
					$System::arraycopy(answer, 0, output, 0, output->length);
					return output;
				} catch ($GeneralSecurityException&) {
					$var($GeneralSecurityException, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use HMAC_MD5_ARCFOUR signing algorithm - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
			}
		default:
			{
				$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported signing algorithm: "_s, $$str(this->sgnAlg)}));
			}
		}
	}
	$shouldNotReachHere();
}

$bytes* CipherHelper::calculateChecksum($bytes* header, $bytes* data, int32_t start, int32_t len, int32_t key_usage) {
	int32_t total = ((header != nullptr ? $nc(header)->length : 0) + len);
	$var($bytes, buf, $new($bytes, total));
	$System::arraycopy(data, start, buf, 0, len);
	if (header != nullptr) {
		$System::arraycopy(header, 0, buf, len, header->length);
	}
	switch (this->etype) {
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
		{
			try {
				$var($bytes, answer, $Aes128::calculateChecksum(this->keybytes, key_usage, buf, 0, total));
				return answer;
			} catch ($GeneralSecurityException&) {
				$var($GeneralSecurityException, e, $catch());
				$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES128 signing algorithm - "_s, $(e->getMessage())})));
				ge->initCause(e);
				$throw(ge);
			}
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
		{
			try {
				$var($bytes, answer, $Aes256::calculateChecksum(this->keybytes, key_usage, buf, 0, total));
				return answer;
			} catch ($GeneralSecurityException&) {
				$var($GeneralSecurityException, e, $catch());
				$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES256 signing algorithm - "_s, $(e->getMessage())})));
				ge->initCause(e);
				$throw(ge);
			}
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
		{
			try {
				$var($bytes, answer, $Aes128Sha2::calculateChecksum(this->keybytes, key_usage, buf, 0, total));
				return answer;
			} catch ($GeneralSecurityException&) {
				$var($GeneralSecurityException, e, $catch());
				$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES128 signing algorithm - "_s, $(e->getMessage())})));
				ge->initCause(e);
				$throw(ge);
			}
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
		{
			try {
				$var($bytes, answer, $Aes256Sha2::calculateChecksum(this->keybytes, key_usage, buf, 0, total));
				return answer;
			} catch ($GeneralSecurityException&) {
				$var($GeneralSecurityException, e, $catch());
				$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES256 signing algorithm - "_s, $(e->getMessage())})));
				ge->initCause(e);
				$throw(ge);
			}
		}
	default:
		{
			$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported encryption type: "_s, $$str(this->etype)}));
		}
	}
	$shouldNotReachHere();
}

$bytes* CipherHelper::encryptSeq($bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	{
		$var($bytes, iv, nullptr)
		$var($bytes, checksum, nullptr)
		switch (this->sgnAlg) {
		case $MessageToken::SGN_ALG_DES_MAC_MD5:
			{}
		case $MessageToken::SGN_ALG_DES_MAC:
			{
				try {
					$var($Cipher, des, getInitializedDes(true, this->keybytes, ivec));
					return $nc(des)->doFinal(plaintext, start, len);
				} catch ($GeneralSecurityException&) {
					$var($GeneralSecurityException, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not encrypt sequence number using DES - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
			}
		case $MessageToken::SGN_ALG_HMAC_SHA1_DES3_KD:
			{
				if ($nc(ivec)->length == CipherHelper::DES_IV_SIZE) {
					$assign(iv, ivec);
				} else {
					$assign(iv, $new($bytes, CipherHelper::DES_IV_SIZE));
					$System::arraycopy(ivec, 0, iv, 0, CipherHelper::DES_IV_SIZE);
				}
				try {
					return $Des3::encryptRaw(this->keybytes, CipherHelper::KG_USAGE_SEQ, iv, plaintext, start, len);
				} catch ($Exception&) {
					$var($Exception, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not encrypt sequence number using DES3-KD - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
			}
		case $MessageToken::SGN_ALG_HMAC_MD5_ARCFOUR:
			{
				if ($nc(ivec)->length == CipherHelper::HMAC_CHECKSUM_SIZE) {
					$assign(checksum, ivec);
				} else {
					$assign(checksum, $new($bytes, CipherHelper::HMAC_CHECKSUM_SIZE));
					$System::arraycopy(ivec, 0, checksum, 0, CipherHelper::HMAC_CHECKSUM_SIZE);
				}
				try {
					return $ArcFourHmac::encryptSeq(this->keybytes, CipherHelper::KG_USAGE_SEQ, checksum, plaintext, start, len);
				} catch ($Exception&) {
					$var($Exception, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not encrypt sequence number using RC4-HMAC - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
			}
		default:
			{
				$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported signing algorithm: "_s, $$str(this->sgnAlg)}));
			}
		}
	}
	$shouldNotReachHere();
}

$bytes* CipherHelper::decryptSeq($bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	{
		$var($bytes, iv, nullptr)
		$var($bytes, checksum, nullptr)
		switch (this->sgnAlg) {
		case $MessageToken::SGN_ALG_DES_MAC_MD5:
			{}
		case $MessageToken::SGN_ALG_DES_MAC:
			{
				try {
					$var($Cipher, des, getInitializedDes(false, this->keybytes, ivec));
					return $nc(des)->doFinal(ciphertext, start, len);
				} catch ($GeneralSecurityException&) {
					$var($GeneralSecurityException, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not decrypt sequence number using DES - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
			}
		case $MessageToken::SGN_ALG_HMAC_SHA1_DES3_KD:
			{
				if ($nc(ivec)->length == CipherHelper::DES_IV_SIZE) {
					$assign(iv, ivec);
				} else {
					$assign(iv, $new($bytes, 8));
					$System::arraycopy(ivec, 0, iv, 0, CipherHelper::DES_IV_SIZE);
				}
				try {
					return $Des3::decryptRaw(this->keybytes, CipherHelper::KG_USAGE_SEQ, iv, ciphertext, start, len);
				} catch ($Exception&) {
					$var($Exception, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not decrypt sequence number using DES3-KD - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
			}
		case $MessageToken::SGN_ALG_HMAC_MD5_ARCFOUR:
			{
				if ($nc(ivec)->length == CipherHelper::HMAC_CHECKSUM_SIZE) {
					$assign(checksum, ivec);
				} else {
					$assign(checksum, $new($bytes, CipherHelper::HMAC_CHECKSUM_SIZE));
					$System::arraycopy(ivec, 0, checksum, 0, CipherHelper::HMAC_CHECKSUM_SIZE);
				}
				try {
					return $ArcFourHmac::decryptSeq(this->keybytes, CipherHelper::KG_USAGE_SEQ, checksum, ciphertext, start, len);
				} catch ($Exception&) {
					$var($Exception, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not decrypt sequence number using RC4-HMAC - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
			}
		default:
			{
				$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported signing algorithm: "_s, $$str(this->sgnAlg)}));
			}
		}
	}
	$shouldNotReachHere();
}

int32_t CipherHelper::getChecksumLength() {
	switch (this->etype) {
	case $EncryptedData::ETYPE_DES_CBC_CRC:
		{}
	case $EncryptedData::ETYPE_DES_CBC_MD5:
		{
			return CipherHelper::DES_CHECKSUM_SIZE;
		}
	case $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD:
		{
			return $Des3::getChecksumLength();
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
		{
			return $Aes128::getChecksumLength();
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
		{
			return $Aes256::getChecksumLength();
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
		{
			return $Aes128Sha2::getChecksumLength();
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
		{
			return $Aes256Sha2::getChecksumLength();
		}
	case $EncryptedData::ETYPE_ARCFOUR_HMAC:
		{
			return CipherHelper::HMAC_CHECKSUM_SIZE;
		}
	default:
		{
			$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported encryption type: "_s, $$str(this->etype)}));
		}
	}
}

void CipherHelper::decryptData($WrapToken* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart) {
	switch (this->sealAlg) {
	case $MessageToken::SEAL_ALG_DES:
		{
			desCbcDecrypt(token, $(getDesEncryptionKey(this->keybytes)), ciphertext, cStart, cLen, plaintext, pStart);
			break;
		}
	case $MessageToken::SEAL_ALG_DES3_KD:
		{
			des3KdDecrypt(token, ciphertext, cStart, cLen, plaintext, pStart);
			break;
		}
	case $MessageToken::SEAL_ALG_ARCFOUR_HMAC:
		{
			arcFourDecrypt(token, ciphertext, cStart, cLen, plaintext, pStart);
			break;
		}
	default:
		{
			$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported seal algorithm: "_s, $$str(this->sealAlg)}));
		}
	}
}

void CipherHelper::decryptData($WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage) {
	switch (this->etype) {
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
		{
			aes128Decrypt(token, ciphertext, cStart, cLen, plaintext, pStart, key_usage);
			break;
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
		{
			aes256Decrypt(token, ciphertext, cStart, cLen, plaintext, pStart, key_usage);
			break;
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
		{
			aes128Sha2Decrypt(token, ciphertext, cStart, cLen, plaintext, pStart, key_usage);
			break;
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
		{
			aes256Sha2Decrypt(token, ciphertext, cStart, cLen, plaintext, pStart, key_usage);
			break;
		}
	default:
		{
			$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported etype: "_s, $$str(this->etype)}));
		}
	}
}

void CipherHelper::decryptData($WrapToken* token, $InputStream* cipherStream, int32_t cLen, $bytes* plaintext, int32_t pStart) {
	{
		$var($bytes, ciphertext, nullptr)
		$var($bytes, ctext, nullptr)
		switch (this->sealAlg) {
		case $MessageToken::SEAL_ALG_DES:
			{
				desCbcDecrypt(token, $(getDesEncryptionKey(this->keybytes)), cipherStream, cLen, plaintext, pStart);
				break;
			}
		case $MessageToken::SEAL_ALG_DES3_KD:
			{
				$assign(ciphertext, $new($bytes, cLen));
				try {
					$Krb5Token::readFully(cipherStream, ciphertext, 0, cLen);
				} catch ($IOException&) {
					$var($IOException, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, "Cannot read complete token"_s));
					ge->initCause(e);
					$throw(ge);
				}
				des3KdDecrypt(token, ciphertext, 0, cLen, plaintext, pStart);
				break;
			}
		case $MessageToken::SEAL_ALG_ARCFOUR_HMAC:
			{
				$assign(ctext, $new($bytes, cLen));
				try {
					$Krb5Token::readFully(cipherStream, ctext, 0, cLen);
				} catch ($IOException&) {
					$var($IOException, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, "Cannot read complete token"_s));
					ge->initCause(e);
					$throw(ge);
				}
				arcFourDecrypt(token, ctext, 0, cLen, plaintext, pStart);
				break;
			}
		default:
			{
				$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported seal algorithm: "_s, $$str(this->sealAlg)}));
			}
		}
	}
}

void CipherHelper::decryptData($WrapToken_v2* token, $InputStream* cipherStream, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage) {
	$var($bytes, ciphertext, $new($bytes, cLen));
	try {
		$Krb5Token::readFully(cipherStream, ciphertext, 0, cLen);
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, "Cannot read complete token"_s));
		ge->initCause(e);
		$throw(ge);
	}
	switch (this->etype) {
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
		{
			aes128Decrypt(token, ciphertext, 0, cLen, plaintext, pStart, key_usage);
			break;
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
		{
			aes256Decrypt(token, ciphertext, 0, cLen, plaintext, pStart, key_usage);
			break;
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
		{
			aes128Sha2Decrypt(token, ciphertext, 0, cLen, plaintext, pStart, key_usage);
			break;
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
		{
			aes256Sha2Decrypt(token, ciphertext, 0, cLen, plaintext, pStart, key_usage);
			break;
		}
	default:
		{
			$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported etype: "_s, $$str(this->etype)}));
		}
	}
}

void CipherHelper::encryptData($WrapToken* token, $bytes* confounder, $bytes* plaintext, int32_t start, int32_t len, $bytes* padding, $OutputStream* os) {
	{
		$var($Cipher, des, nullptr)
		$var($CipherOutputStream, cos, nullptr)
		$var($bytes, ctext, nullptr)
		$var($bytes, ciphertext, nullptr)
		switch (this->sealAlg) {
		case $MessageToken::SEAL_ALG_DES:
			{
				$assign(des, getInitializedDes(true, $(getDesEncryptionKey(this->keybytes)), CipherHelper::ZERO_IV));
				$assign(cos, $new($CipherOutputStream, os, des));
				$nc(cos)->write(confounder);
				$nc(cos)->write(plaintext, start, len);
				$nc(cos)->write(padding);
				break;
			}
		case $MessageToken::SEAL_ALG_DES3_KD:
			{
				$assign(ctext, des3KdEncrypt(confounder, plaintext, start, len, padding));
				$nc(os)->write(ctext);
				break;
			}
		case $MessageToken::SEAL_ALG_ARCFOUR_HMAC:
			{
				$assign(ciphertext, arcFourEncrypt(token, confounder, plaintext, start, len, padding));
				$nc(os)->write(ciphertext);
				break;
			}
		default:
			{
				$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported seal algorithm: "_s, $$str(this->sealAlg)}));
			}
		}
	}
}

$bytes* CipherHelper::encryptData($WrapToken_v2* token, $bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage) {
	switch (this->etype) {
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
		{
			return aes128Encrypt(confounder, tokenHeader, plaintext, start, len, key_usage);
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
		{
			return aes256Encrypt(confounder, tokenHeader, plaintext, start, len, key_usage);
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
		{
			return aes128Sha2Encrypt(confounder, tokenHeader, plaintext, start, len, key_usage);
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
		{
			return aes256Sha2Encrypt(confounder, tokenHeader, plaintext, start, len, key_usage);
		}
	default:
		{
			$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported etype: "_s, $$str(this->etype)}));
		}
	}
}

void CipherHelper::encryptData($WrapToken* token, $bytes* confounder, $bytes* plaintext, int32_t pStart, int32_t pLen, $bytes* padding, $bytes* ciphertext, int32_t cStart) {
	{
		int32_t pos = 0;
		$var($Cipher, des, nullptr)
		$var($bytes, ctext, nullptr)
		$var($bytes, ctext2, nullptr)
		switch (this->sealAlg) {
		case $MessageToken::SEAL_ALG_DES:
			{
				pos = cStart;
				$assign(des, getInitializedDes(true, $(getDesEncryptionKey(this->keybytes)), CipherHelper::ZERO_IV));
				try {
					pos += $nc(des)->update(confounder, 0, $nc(confounder)->length, ciphertext, pos);
					pos += des->update(plaintext, pStart, pLen, ciphertext, pos);
					des->update(padding, 0, $nc(padding)->length, ciphertext, pos);
					des->doFinal();
				} catch ($GeneralSecurityException&) {
					$var($GeneralSecurityException, e, $catch());
					$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use DES Cipher - "_s, $(e->getMessage())})));
					ge->initCause(e);
					$throw(ge);
				}
				break;
			}
		case $MessageToken::SEAL_ALG_DES3_KD:
			{
				$assign(ctext, des3KdEncrypt(confounder, plaintext, pStart, pLen, padding));
				$System::arraycopy(ctext, 0, ciphertext, cStart, $nc(ctext)->length);
				break;
			}
		case $MessageToken::SEAL_ALG_ARCFOUR_HMAC:
			{
				$assign(ctext2, arcFourEncrypt(token, confounder, plaintext, pStart, pLen, padding));
				$System::arraycopy(ctext2, 0, ciphertext, cStart, $nc(ctext2)->length);
				break;
			}
		default:
			{
				$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported seal algorithm: "_s, $$str(this->sealAlg)}));
			}
		}
	}
}

int32_t CipherHelper::encryptData($WrapToken_v2* token, $bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t pStart, int32_t pLen, $bytes* ciphertext, int32_t cStart, int32_t key_usage) {
	$var($bytes, ctext, nullptr);
	switch (this->etype) {
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96:
		{
			$assign(ctext, aes128Encrypt(confounder, tokenHeader, plaintext, pStart, pLen, key_usage));
			break;
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96:
		{
			$assign(ctext, aes256Encrypt(confounder, tokenHeader, plaintext, pStart, pLen, key_usage));
			break;
		}
	case $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128:
		{
			$assign(ctext, aes128Sha2Encrypt(confounder, tokenHeader, plaintext, pStart, pLen, key_usage));
			break;
		}
	case $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192:
		{
			$assign(ctext, aes256Sha2Encrypt(confounder, tokenHeader, plaintext, pStart, pLen, key_usage));
			break;
		}
	default:
		{
			$throwNew($GSSException, $GSSException::FAILURE, -1, $$str({"Unsupported etype: "_s, $$str(this->etype)}));
		}
	}
	$System::arraycopy(ctext, 0, ciphertext, cStart, $nc(ctext)->length);
	return $nc(ctext)->length;
}

$bytes* CipherHelper::getDesCbcChecksum($bytes* key, $bytes* header, $bytes* data, int32_t offset, int32_t len) {
	$var($Cipher, des, getInitializedDes(true, key, CipherHelper::ZERO_IV));
	int32_t blockSize = $nc(des)->getBlockSize();
	$var($bytes, finalBlock, $new($bytes, blockSize));
	int32_t numBlocks = $div(len, blockSize);
	int32_t lastBytes = $mod(len, blockSize);
	if (lastBytes == 0) {
		numBlocks -= 1;
		$System::arraycopy(data, offset + numBlocks * blockSize, finalBlock, 0, blockSize);
	} else {
		$System::arraycopy(data, offset + numBlocks * blockSize, finalBlock, 0, lastBytes);
	}
	try {
		$var($bytes, temp, $new($bytes, $Math::max(blockSize, (header == nullptr ? blockSize : $nc(header)->length))));
		if (header != nullptr) {
			des->update(header, 0, header->length, temp, 0);
		}
		for (int32_t i = 0; i < numBlocks; ++i) {
			des->update(data, offset, blockSize, temp, 0);
			offset += blockSize;
		}
		$var($bytes, retVal, $new($bytes, blockSize));
		des->update(finalBlock, 0, blockSize, retVal, 0);
		des->doFinal();
		return retVal;
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use DES Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	$shouldNotReachHere();
}

$Cipher* CipherHelper::getInitializedDes(bool encryptMode, $bytes* key, $bytes* ivBytes) {
	try {
		$var($IvParameterSpec, iv, $new($IvParameterSpec, ivBytes));
		$var($SecretKey, jceKey, static_cast<$SecretKey*>(($new($SecretKeySpec, key, "DES"_s))));
		$var($Cipher, desCipher, $Cipher::getInstance("DES/CBC/NoPadding"_s));
		$nc(desCipher)->init((encryptMode ? $Cipher::ENCRYPT_MODE : $Cipher::DECRYPT_MODE), static_cast<$Key*>(jceKey), static_cast<$AlgorithmParameterSpec*>(iv));
		return desCipher;
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $(e->getMessage())));
		ge->initCause(e);
		$throw(ge);
	}
	$shouldNotReachHere();
}

void CipherHelper::desCbcDecrypt($WrapToken* token, $bytes* key, $bytes* cipherText, int32_t offset, int32_t len, $bytes* dataOutBuf, int32_t dataOffset) {
	try {
		int32_t temp = 0;
		$var($Cipher, des, getInitializedDes(false, key, CipherHelper::ZERO_IV));
		temp = $nc(des)->update(cipherText, offset, $WrapToken::CONFOUNDER_SIZE, $nc(token)->confounder);
		offset += $WrapToken::CONFOUNDER_SIZE;
		len -= $WrapToken::CONFOUNDER_SIZE;
		int32_t blockSize = des->getBlockSize();
		int32_t numBlocks = $div(len, blockSize) - 1;
		for (int32_t i = 0; i < numBlocks; ++i) {
			temp = des->update(cipherText, offset, blockSize, dataOutBuf, dataOffset);
			offset += blockSize;
			dataOffset += blockSize;
		}
		$var($bytes, finalBlock, $new($bytes, blockSize));
		des->update(cipherText, offset, blockSize, finalBlock);
		des->doFinal();
		int32_t padSize = finalBlock->get(blockSize - 1);
		if (padSize < 1 || padSize > 8) {
			$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, "Invalid padding on Wrap Token"_s);
		}
		$init($WrapToken);
		$set($nc(token), padding, $nc($WrapToken::pads)->get(padSize));
		blockSize -= padSize;
		$System::arraycopy(finalBlock, 0, dataOutBuf, dataOffset, blockSize);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use DES cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
}

void CipherHelper::desCbcDecrypt($WrapToken* token, $bytes* key, $InputStream* is, int32_t len, $bytes* dataOutBuf, int32_t dataOffset) {
	int32_t temp = 0;
	$var($Cipher, des, getInitializedDes(false, key, CipherHelper::ZERO_IV));
	$var($CipherHelper$WrapTokenInputStream, truncatedInputStream, $new($CipherHelper$WrapTokenInputStream, this, is, len));
	$var($CipherInputStream, cis, $new($CipherInputStream, truncatedInputStream, des));
	temp = cis->read($nc(token)->confounder);
	len -= temp;
	int32_t blockSize = $nc(des)->getBlockSize();
	int32_t numBlocks = $div(len, blockSize) - 1;
	for (int32_t i = 0; i < numBlocks; ++i) {
		temp = cis->read(dataOutBuf, dataOffset, blockSize);
		dataOffset += blockSize;
	}
	$var($bytes, finalBlock, $new($bytes, blockSize));
	temp = cis->read(finalBlock);
	try {
		des->doFinal();
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use DES cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	int32_t padSize = finalBlock->get(blockSize - 1);
	if (padSize < 1 || padSize > 8) {
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, "Invalid padding on Wrap Token"_s);
	}
	$init($WrapToken);
	$set($nc(token), padding, $nc($WrapToken::pads)->get(padSize));
	blockSize -= padSize;
	$System::arraycopy(finalBlock, 0, dataOutBuf, dataOffset, blockSize);
}

$bytes* CipherHelper::getDesEncryptionKey($bytes* key) {
	$init(CipherHelper);
	if ($nc(key)->length > 8) {
		$throwNew($GSSException, $GSSException::FAILURE, -100, "Invalid DES Key!"_s);
	}
	$var($bytes, retVal, $new($bytes, $nc(key)->length));
	for (int32_t i = 0; i < key->length; ++i) {
		retVal->set(i, (int8_t)(key->get(i) ^ 240));
	}
	return retVal;
}

void CipherHelper::des3KdDecrypt($WrapToken* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart) {
	$var($bytes, ptext, nullptr);
	try {
		$assign(ptext, $Des3::decryptRaw(this->keybytes, CipherHelper::KG_USAGE_SEAL, CipherHelper::ZERO_IV, ciphertext, cStart, cLen));
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use DES3-KD Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	int32_t padSize = $nc(ptext)->get(ptext->length - 1);
	if (padSize < 1 || padSize > 8) {
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, "Invalid padding on Wrap Token"_s);
	}
	$init($WrapToken);
	$set($nc(token), padding, $nc($WrapToken::pads)->get(padSize));
	int32_t len = ptext->length - $WrapToken::CONFOUNDER_SIZE - padSize;
	$System::arraycopy(ptext, $WrapToken::CONFOUNDER_SIZE, plaintext, pStart, len);
	$System::arraycopy(ptext, 0, token->confounder, 0, $WrapToken::CONFOUNDER_SIZE);
}

$bytes* CipherHelper::des3KdEncrypt($bytes* confounder, $bytes* plaintext, int32_t start, int32_t len, $bytes* padding) {
	$var($bytes, all, $new($bytes, $nc(confounder)->length + len + $nc(padding)->length));
	$System::arraycopy(confounder, 0, all, 0, confounder->length);
	$System::arraycopy(plaintext, start, all, confounder->length, len);
	$System::arraycopy(padding, 0, all, confounder->length + len, padding->length);
	try {
		$var($bytes, answer, $Des3::encryptRaw(this->keybytes, CipherHelper::KG_USAGE_SEAL, CipherHelper::ZERO_IV, all, 0, all->length));
		return answer;
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use DES3-KD Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	$shouldNotReachHere();
}

void CipherHelper::arcFourDecrypt($WrapToken* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart) {
	$var($bytes, var$0, $nc(token)->getChecksum());
	$var($bytes, seqNum, decryptSeq(var$0, $(token->getEncSeqNumber()), 0, 8));
	$var($bytes, ptext, nullptr);
	try {
		$assign(ptext, $ArcFourHmac::decryptRaw(this->keybytes, CipherHelper::KG_USAGE_SEAL, CipherHelper::ZERO_IV, ciphertext, cStart, cLen, seqNum));
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use ArcFour Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	int32_t padSize = $nc(ptext)->get(ptext->length - 1);
	if (padSize < 1) {
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, "Invalid padding on Wrap Token"_s);
	}
	$set($nc(token), padding, $nc($WrapToken::pads)->get(padSize));
	int32_t len = ptext->length - $WrapToken::CONFOUNDER_SIZE - padSize;
	$System::arraycopy(ptext, $WrapToken::CONFOUNDER_SIZE, plaintext, pStart, len);
	$System::arraycopy(ptext, 0, token->confounder, 0, $WrapToken::CONFOUNDER_SIZE);
}

$bytes* CipherHelper::arcFourEncrypt($WrapToken* token, $bytes* confounder, $bytes* plaintext, int32_t start, int32_t len, $bytes* padding) {
	$var($bytes, all, $new($bytes, $nc(confounder)->length + len + $nc(padding)->length));
	$System::arraycopy(confounder, 0, all, 0, confounder->length);
	$System::arraycopy(plaintext, start, all, confounder->length, len);
	$System::arraycopy(padding, 0, all, confounder->length + len, padding->length);
	$var($bytes, seqNum, $new($bytes, 4));
	$WrapToken::writeBigEndian($nc(token)->getSequenceNumber(), seqNum);
	try {
		$var($bytes, answer, $ArcFourHmac::encryptRaw(this->keybytes, CipherHelper::KG_USAGE_SEAL, seqNum, all, 0, all->length));
		return answer;
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use ArcFour Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	$shouldNotReachHere();
}

$bytes* CipherHelper::aes128Encrypt($bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage) {
	$var($bytes, all, $new($bytes, $nc(confounder)->length + len + $nc(tokenHeader)->length));
	$System::arraycopy(confounder, 0, all, 0, confounder->length);
	$System::arraycopy(plaintext, start, all, confounder->length, len);
	$System::arraycopy(tokenHeader, 0, all, confounder->length + len, tokenHeader->length);
	try {
		$var($bytes, answer, $Aes128::encryptRaw(this->keybytes, key_usage, CipherHelper::ZERO_IV_AES, all, 0, all->length));
		return answer;
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES128 Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	$shouldNotReachHere();
}

$bytes* CipherHelper::aes128Sha2Encrypt($bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage) {
	$var($bytes, all, $new($bytes, $nc(confounder)->length + len + $nc(tokenHeader)->length));
	$System::arraycopy(confounder, 0, all, 0, confounder->length);
	$System::arraycopy(plaintext, start, all, confounder->length, len);
	$System::arraycopy(tokenHeader, 0, all, confounder->length + len, tokenHeader->length);
	try {
		$var($bytes, answer, $Aes128Sha2::encryptRaw(this->keybytes, key_usage, CipherHelper::ZERO_IV_AES, all, 0, all->length));
		return answer;
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use Aes128Sha2 Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	$shouldNotReachHere();
}

void CipherHelper::aes128Decrypt($WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage) {
	$var($bytes, ptext, nullptr);
	try {
		$assign(ptext, $Aes128::decryptRaw(this->keybytes, key_usage, CipherHelper::ZERO_IV_AES, ciphertext, cStart, cLen));
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES128 Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	int32_t len = $nc(ptext)->length - $WrapToken_v2::CONFOUNDER_SIZE - $WrapToken_v2::TOKEN_HEADER_SIZE;
	$System::arraycopy(ptext, $WrapToken_v2::CONFOUNDER_SIZE, plaintext, pStart, len);
}

void CipherHelper::aes128Sha2Decrypt($WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage) {
	$var($bytes, ptext, nullptr);
	try {
		$assign(ptext, $Aes128Sha2::decryptRaw(this->keybytes, key_usage, CipherHelper::ZERO_IV_AES, ciphertext, cStart, cLen));
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES128Sha2 Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	int32_t len = $nc(ptext)->length - $WrapToken_v2::CONFOUNDER_SIZE - $WrapToken_v2::TOKEN_HEADER_SIZE;
	$System::arraycopy(ptext, $WrapToken_v2::CONFOUNDER_SIZE, plaintext, pStart, len);
}

$bytes* CipherHelper::aes256Encrypt($bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage) {
	$var($bytes, all, $new($bytes, $nc(confounder)->length + len + $nc(tokenHeader)->length));
	$System::arraycopy(confounder, 0, all, 0, confounder->length);
	$System::arraycopy(plaintext, start, all, confounder->length, len);
	$System::arraycopy(tokenHeader, 0, all, confounder->length + len, tokenHeader->length);
	try {
		$var($bytes, answer, $Aes256::encryptRaw(this->keybytes, key_usage, CipherHelper::ZERO_IV_AES, all, 0, all->length));
		return answer;
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES256 Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	$shouldNotReachHere();
}

$bytes* CipherHelper::aes256Sha2Encrypt($bytes* confounder, $bytes* tokenHeader, $bytes* plaintext, int32_t start, int32_t len, int32_t key_usage) {
	$var($bytes, all, $new($bytes, $nc(confounder)->length + len + $nc(tokenHeader)->length));
	$System::arraycopy(confounder, 0, all, 0, confounder->length);
	$System::arraycopy(plaintext, start, all, confounder->length, len);
	$System::arraycopy(tokenHeader, 0, all, confounder->length + len, tokenHeader->length);
	try {
		$var($bytes, answer, $Aes256Sha2::encryptRaw(this->keybytes, key_usage, CipherHelper::ZERO_IV_AES, all, 0, all->length));
		return answer;
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use Aes256Sha2 Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	$shouldNotReachHere();
}

void CipherHelper::aes256Decrypt($WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage) {
	$var($bytes, ptext, nullptr);
	try {
		$assign(ptext, $Aes256::decryptRaw(this->keybytes, key_usage, CipherHelper::ZERO_IV_AES, ciphertext, cStart, cLen));
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES128 Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	int32_t len = $nc(ptext)->length - $WrapToken_v2::CONFOUNDER_SIZE - $WrapToken_v2::TOKEN_HEADER_SIZE;
	$System::arraycopy(ptext, $WrapToken_v2::CONFOUNDER_SIZE, plaintext, pStart, len);
}

void CipherHelper::aes256Sha2Decrypt($WrapToken_v2* token, $bytes* ciphertext, int32_t cStart, int32_t cLen, $bytes* plaintext, int32_t pStart, int32_t key_usage) {
	$var($bytes, ptext, nullptr);
	try {
		$assign(ptext, $Aes256Sha2::decryptRaw(this->keybytes, key_usage, CipherHelper::ZERO_IV_AES, ciphertext, cStart, cLen));
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, $$str({"Could not use AES256Sha2 Cipher - "_s, $(e->getMessage())})));
		ge->initCause(e);
		$throw(ge);
	}
	int32_t len = $nc(ptext)->length - $WrapToken_v2::CONFOUNDER_SIZE - $WrapToken_v2::TOKEN_HEADER_SIZE;
	$System::arraycopy(ptext, $WrapToken_v2::CONFOUNDER_SIZE, plaintext, pStart, len);
}

void clinit$CipherHelper($Class* class$) {
	$init($Krb5Util);
	CipherHelper::DEBUG = $Krb5Util::DEBUG;
	$assignStatic(CipherHelper::ZERO_IV, $new($bytes, CipherHelper::DES_IV_SIZE));
	$assignStatic(CipherHelper::ZERO_IV_AES, $new($bytes, CipherHelper::AES_IV_SIZE));
}

CipherHelper::CipherHelper() {
}

$Class* CipherHelper::load$($String* name, bool initialize) {
	$loadClass(CipherHelper, name, initialize, &_CipherHelper_ClassInfo_, clinit$CipherHelper, allocate$CipherHelper);
	return class$;
}

$Class* CipherHelper::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun