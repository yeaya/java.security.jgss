#include <sun/security/krb5/internal/crypto/dk/DkCrypto.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Byte.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/GeneralSecurityException.h>
#include <java/util/Arrays.h>
#include <javax/crypto/Cipher.h>
#include <sun/security/krb5/Confounder.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef DECRYPT_MODE
#undef ENCRYPT_MODE
#undef KERBEROS_CONSTANT
#undef UTF_16LE
#undef UTF_8

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Arrays = ::java::util::Arrays;
using $Cipher = ::javax::crypto::Cipher;
using $Confounder = ::sun::security::krb5::Confounder;
using $KeyUsage = ::sun::security::krb5::internal::crypto::KeyUsage;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {
					namespace dk {

$FieldInfo _DkCrypto_FieldInfo_[] = {
	{"debug", "Z", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(DkCrypto, debug)},
	{"KERBEROS_CONSTANT", "[B", nullptr, $STATIC | $FINAL, $staticField(DkCrypto, KERBEROS_CONSTANT)},
	{}
};

$MethodInfo _DkCrypto_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DkCrypto::*)()>(&DkCrypto::init$))},
	{"binaryStringToBytes", "(Ljava/lang/String;)[B", nullptr, $PRIVATE | $STATIC, $method(static_cast<$bytes*(*)($String*)>(&DkCrypto::binaryStringToBytes))},
	{"bytesToString", "([B)Ljava/lang/String;", nullptr, $STATIC, $method(static_cast<$String*(*)($bytes*)>(&DkCrypto::bytesToString))},
	{"calculateChecksum", "([BI[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"charToUtf16", "([C)[B", nullptr, $STATIC, $method(static_cast<$bytes*(*)($chars*)>(&DkCrypto::charToUtf16))},
	{"charToUtf8", "([C)[B", nullptr, $STATIC, $method(static_cast<$bytes*(*)($chars*)>(&DkCrypto::charToUtf8))},
	{"decrypt", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"decryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"dk", "([B[B)[B", nullptr, 0, nullptr, "java.security.GeneralSecurityException"},
	{"dr", "([B[B)[B", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"encrypt", "([BI[B[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"encryptRaw", "([BI[B[BII)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException,sun.security.krb5.KrbCryptoException"},
	{"getChecksumLength", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"getCipher", "([B[BI)Ljavax/crypto/Cipher;", nullptr, $PROTECTED | $ABSTRACT, nullptr, "java.security.GeneralSecurityException"},
	{"getHmac", "([B[B)[B", nullptr, $PROTECTED | $ABSTRACT, nullptr, "java.security.GeneralSecurityException"},
	{"getKeySeedLength", "()I", nullptr, $PROTECTED | $ABSTRACT},
	{"nfold", "([BI)[B", nullptr, $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t)>(&DkCrypto::nfold))},
	{"randomToKey", "([B)[B", nullptr, $PROTECTED | $ABSTRACT},
	{"roundup", "(II)I", nullptr, 0},
	{"traceOutput", "(Ljava/lang/String;[BII)V", nullptr, $STATIC, $method(static_cast<void(*)($String*,$bytes*,int32_t,int32_t)>(&DkCrypto::traceOutput))},
	{}
};

$ClassInfo _DkCrypto_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.krb5.internal.crypto.dk.DkCrypto",
	"java.lang.Object",
	nullptr,
	_DkCrypto_FieldInfo_,
	_DkCrypto_MethodInfo_
};

$Object* allocate$DkCrypto($Class* clazz) {
	return $of($alloc(DkCrypto));
}

$bytes* DkCrypto::KERBEROS_CONSTANT = nullptr;

void DkCrypto::init$() {
}

$bytes* DkCrypto::encrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* new_ivec, $bytes* plaintext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, Ke, nullptr);
	$var($bytes, Ki, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($bytes, constant, $new($bytes, 5));
			constant->set(0, (int8_t)((int32_t)((usage >> 24) & (uint32_t)255)));
			constant->set(1, (int8_t)((int32_t)((usage >> 16) & (uint32_t)255)));
			constant->set(2, (int8_t)((int32_t)((usage >> 8) & (uint32_t)255)));
			constant->set(3, (int8_t)((int32_t)(usage & (uint32_t)255)));
			constant->set(4, (int8_t)170);
			$assign(Ke, dk(baseKey, constant));
			$var($Cipher, encCipher, getCipher(Ke, ivec, $Cipher::ENCRYPT_MODE));
			int32_t blockSize = $nc(encCipher)->getBlockSize();
			$var($bytes, confounder, $Confounder::bytes(blockSize));
			int32_t plainSize = roundup($nc(confounder)->length + len, blockSize);
			$var($bytes, toBeEncrypted, $new($bytes, plainSize));
			$System::arraycopy(confounder, 0, toBeEncrypted, 0, $nc(confounder)->length);
			$System::arraycopy(plaintext, start, toBeEncrypted, $nc(confounder)->length, len);
			$Arrays::fill(toBeEncrypted, $nc(confounder)->length + len, plainSize, (int8_t)0);
			int32_t cipherSize = encCipher->getOutputSize(plainSize);
			int32_t ccSize = cipherSize + getChecksumLength();
			$var($bytes, ciphertext, $new($bytes, ccSize));
			encCipher->doFinal(toBeEncrypted, 0, plainSize, ciphertext, 0);
			if (new_ivec != nullptr && new_ivec->length == blockSize) {
				$System::arraycopy(ciphertext, cipherSize - blockSize, new_ivec, 0, blockSize);
			}
			constant->set(4, (int8_t)85);
			$assign(Ki, dk(baseKey, constant));
			$var($bytes, hmac, getHmac(Ki, toBeEncrypted));
			$System::arraycopy(hmac, 0, ciphertext, cipherSize, getChecksumLength());
			$assign(var$2, ciphertext);
			return$1 = true;
			goto $finally;
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			if (Ke != nullptr) {
				$Arrays::fill(Ke, 0, Ke->length, (int8_t)0);
			}
			if (Ki != nullptr) {
				$Arrays::fill(Ki, 0, Ki->length, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$bytes* DkCrypto::encryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* plaintext, int32_t start, int32_t len) {
	$var($Cipher, encCipher, getCipher(baseKey, ivec, $Cipher::ENCRYPT_MODE));
	int32_t blockSize = $nc(encCipher)->getBlockSize();
	if (($mod(len, blockSize)) != 0) {
		$throwNew($GeneralSecurityException, $$str({"length of data to be encrypted ("_s, $$str(len), ") is not a multiple of the blocksize ("_s, $$str(blockSize), ")"_s}));
	}
	int32_t cipherSize = encCipher->getOutputSize(len);
	$var($bytes, ciphertext, $new($bytes, cipherSize));
	encCipher->doFinal(plaintext, 0, len, ciphertext, 0);
	return ciphertext;
}

$bytes* DkCrypto::decryptRaw($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	$var($Cipher, decCipher, getCipher(baseKey, ivec, $Cipher::DECRYPT_MODE));
	int32_t blockSize = $nc(decCipher)->getBlockSize();
	if (($mod(len, blockSize)) != 0) {
		$throwNew($GeneralSecurityException, $$str({"length of data to be decrypted ("_s, $$str(len), ") is not a multiple of the blocksize ("_s, $$str(blockSize), ")"_s}));
	}
	$var($bytes, decrypted, decCipher->doFinal(ciphertext, start, len));
	return decrypted;
}

$bytes* DkCrypto::decrypt($bytes* baseKey, int32_t usage, $bytes* ivec, $bytes* ciphertext, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, Ke, nullptr);
	$var($bytes, Ki, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($bytes, constant, $new($bytes, 5));
			constant->set(0, (int8_t)((int32_t)((usage >> 24) & (uint32_t)255)));
			constant->set(1, (int8_t)((int32_t)((usage >> 16) & (uint32_t)255)));
			constant->set(2, (int8_t)((int32_t)((usage >> 8) & (uint32_t)255)));
			constant->set(3, (int8_t)((int32_t)(usage & (uint32_t)255)));
			constant->set(4, (int8_t)170);
			$assign(Ke, dk(baseKey, constant));
			$var($Cipher, decCipher, getCipher(Ke, ivec, $Cipher::DECRYPT_MODE));
			int32_t blockSize = $nc(decCipher)->getBlockSize();
			int32_t cksumSize = getChecksumLength();
			int32_t cipherSize = len - cksumSize;
			$var($bytes, decrypted, decCipher->doFinal(ciphertext, start, cipherSize));
			constant->set(4, (int8_t)85);
			$assign(Ki, dk(baseKey, constant));
			$var($bytes, calculatedHmac, getHmac(Ki, decrypted));
			bool cksumFailed = false;
			if ($nc(calculatedHmac)->length >= cksumSize) {
				for (int32_t i = 0; i < cksumSize; ++i) {
					if (calculatedHmac->get(i) != $nc(ciphertext)->get(cipherSize + i)) {
						cksumFailed = true;
						break;
					}
				}
			}
			if (cksumFailed) {
				$throwNew($GeneralSecurityException, "Checksum failed"_s);
			}
			if (ivec != nullptr && ivec->length == blockSize) {
				$System::arraycopy(ciphertext, start + cipherSize - blockSize, ivec, 0, blockSize);
			}
			$var($bytes, plaintext, $new($bytes, $nc(decrypted)->length - blockSize));
			$System::arraycopy(decrypted, blockSize, plaintext, 0, plaintext->length);
			$assign(var$2, plaintext);
			return$1 = true;
			goto $finally;
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			if (Ke != nullptr) {
				$Arrays::fill(Ke, 0, Ke->length, (int8_t)0);
			}
			if (Ki != nullptr) {
				$Arrays::fill(Ki, 0, Ki->length, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

int32_t DkCrypto::roundup(int32_t n, int32_t blocksize) {
	return (($div((n + blocksize - 1), blocksize)) * blocksize);
}

$bytes* DkCrypto::calculateChecksum($bytes* baseKey, int32_t usage, $bytes* input, int32_t start, int32_t len) {
	if (!$KeyUsage::isValid(usage)) {
		$throwNew($GeneralSecurityException, $$str({"Invalid key usage number: "_s, $$str(usage)}));
	}
	$var($bytes, constant, $new($bytes, 5));
	constant->set(0, (int8_t)((int32_t)((usage >> 24) & (uint32_t)255)));
	constant->set(1, (int8_t)((int32_t)((usage >> 16) & (uint32_t)255)));
	constant->set(2, (int8_t)((int32_t)((usage >> 8) & (uint32_t)255)));
	constant->set(3, (int8_t)((int32_t)(usage & (uint32_t)255)));
	constant->set(4, (int8_t)153);
	$var($bytes, Kc, dk(baseKey, constant));
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($bytes, hmac, getHmac(Kc, input));
			if ($nc(hmac)->length == getChecksumLength()) {
				$assign(var$2, hmac);
				return$1 = true;
				goto $finally;
			} else if (hmac->length > getChecksumLength()) {
				$var($bytes, buf, $new($bytes, getChecksumLength()));
				$System::arraycopy(hmac, 0, buf, 0, buf->length);
				$assign(var$2, buf);
				return$1 = true;
				goto $finally;
			} else {
				$throwNew($GeneralSecurityException, $$str({"checksum size too short: "_s, $$str(hmac->length), "; expecting : "_s, $$str(getChecksumLength())}));
			}
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			$Arrays::fill(Kc, 0, $nc(Kc)->length, (int8_t)0);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$bytes* DkCrypto::dk($bytes* key, $bytes* constant) {
	return randomToKey($(dr(key, constant)));
}

$bytes* DkCrypto::dr($bytes* key, $bytes* constant$renamed) {
	$var($bytes, constant, constant$renamed);
	$var($Cipher, encCipher, getCipher(key, nullptr, $Cipher::ENCRYPT_MODE));
	int32_t blocksize = $nc(encCipher)->getBlockSize();
	if ($nc(constant)->length != blocksize) {
		$assign(constant, nfold(constant, blocksize * 8));
	}
	$var($bytes, toBeEncrypted, constant);
	int32_t keybytes = (getKeySeedLength() >> 3);
	$var($bytes, rawkey, $new($bytes, keybytes));
	int32_t posn = 0;
	int32_t n = 0;
	int32_t len = 0;
	while (n < keybytes) {
		$var($bytes, cipherBlock, encCipher->doFinal(toBeEncrypted));
		len = (keybytes - n <= $nc(cipherBlock)->length ? (keybytes - n) : $nc(cipherBlock)->length);
		$System::arraycopy(cipherBlock, 0, rawkey, n, len);
		n += len;
		$assign(toBeEncrypted, cipherBlock);
	}
	return rawkey;
}

$bytes* DkCrypto::nfold($bytes* in, int32_t outbits) {
	$init(DkCrypto);
	int32_t inbits = $nc(in)->length;
	outbits >>= 3;
	int32_t a = 0;
	int32_t b = 0;
	int32_t c = 0;
	int32_t lcm = 0;
	a = outbits;
	b = inbits;
	while (b != 0) {
		c = b;
		b = $mod(a, b);
		a = c;
	}
	lcm = $div(outbits * inbits, a);
	$var($bytes, out, $new($bytes, outbits));
	$Arrays::fill(out, (int8_t)0);
	int32_t thisbyte = 0;
	int32_t msbit = 0;
	int32_t i = 0;
	int32_t bval = 0;
	int32_t oval = 0;
	for (i = lcm - 1; i >= 0; --i) {
		msbit = $mod((((inbits << 3) - 1) + (((inbits << 3) + 13) * ($div(i, inbits))) + ((inbits - ($mod(i, inbits))) << 3)), (inbits << 3));
		bval = (int32_t)(($usr((((int32_t)(in->get($mod(((inbits - 1) - ((int32_t)((uint32_t)msbit >> 3))), inbits)) & (uint32_t)255)) << 8) | ((int32_t)(in->get($mod(((inbits) - ((int32_t)((uint32_t)msbit >> 3))), inbits)) & (uint32_t)255)), ((int32_t)(msbit & (uint32_t)7)) + 1)) & (uint32_t)255);
		thisbyte += bval;
		oval = ((int32_t)(out->get($mod(i, outbits)) & (uint32_t)255));
		thisbyte += oval;
		out->set($mod(i, outbits), (int8_t)((int32_t)(thisbyte & (uint32_t)255)));
		$usrAssign(thisbyte, 8);
	}
	if (thisbyte != 0) {
		for (i = outbits - 1; i >= 0; --i) {
			thisbyte += ((int32_t)(out->get(i) & (uint32_t)255));
			out->set(i, (int8_t)((int32_t)(thisbyte & (uint32_t)255)));
			$usrAssign(thisbyte, 8);
		}
	}
	return out;
}

$String* DkCrypto::bytesToString($bytes* digest) {
	$init(DkCrypto);
	$var($StringBuilder, digestString, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(digest)->length; ++i) {
		if (((int32_t)(digest->get(i) & (uint32_t)255)) < 16) {
			digestString->append(u'0')->append($($Integer::toHexString((int32_t)(digest->get(i) & (uint32_t)255))));
		} else {
			digestString->append($($Integer::toHexString((int32_t)(digest->get(i) & (uint32_t)255))));
		}
	}
	return digestString->toString();
}

$bytes* DkCrypto::binaryStringToBytes($String* str) {
	$init(DkCrypto);
	$var($chars, usageStr, $nc(str)->toCharArray());
	$var($bytes, usage, $new($bytes, usageStr->length / 2));
	for (int32_t i = 0; i < usage->length; ++i) {
		int8_t a = $Byte::parseByte($$new($String, usageStr, i * 2, 1), 16);
		int8_t b = $Byte::parseByte($$new($String, usageStr, i * 2 + 1, 1), 16);
		usage->set(i, (int8_t)((a << 4) | b));
	}
	return usage;
}

void DkCrypto::traceOutput($String* traceTag, $bytes* output, int32_t offset, int32_t len) {
	$init(DkCrypto);
	try {
		$var($ByteArrayOutputStream, out, $new($ByteArrayOutputStream, len));
		$$new($HexDumpEncoder)->encodeBuffer(static_cast<$InputStream*>($$new($ByteArrayInputStream, output, offset, len)), static_cast<$OutputStream*>(out));
		$init($System);
		$nc($System::err)->println($$str({traceTag, ":\n"_s, $(out->toString())}));
	} catch ($Exception&) {
		$catch();
	}
}

$bytes* DkCrypto::charToUtf8($chars* chars) {
	$init(DkCrypto);
	$var($CharBuffer, cb, $CharBuffer::wrap(chars));
	$init($StandardCharsets);
	$var($ByteBuffer, bb, $nc($StandardCharsets::UTF_8)->encode(cb));
	int32_t len = $nc(bb)->limit();
	$var($bytes, answer, $new($bytes, len));
	bb->get(answer, 0, len);
	return answer;
}

$bytes* DkCrypto::charToUtf16($chars* chars) {
	$init(DkCrypto);
	$var($CharBuffer, cb, $CharBuffer::wrap(chars));
	$init($StandardCharsets);
	$var($ByteBuffer, bb, $nc($StandardCharsets::UTF_16LE)->encode(cb));
	int32_t len = $nc(bb)->limit();
	$var($bytes, answer, $new($bytes, len));
	bb->get(answer, 0, len);
	return answer;
}

void clinit$DkCrypto($Class* class$) {
	$assignStatic(DkCrypto::KERBEROS_CONSTANT, $new($bytes, {
		(int8_t)107,
		(int8_t)101,
		(int8_t)114,
		(int8_t)98,
		(int8_t)101,
		(int8_t)114,
		(int8_t)111,
		(int8_t)115
	}));
}

DkCrypto::DkCrypto() {
}

$Class* DkCrypto::load$($String* name, bool initialize) {
	$loadClass(DkCrypto, name, initialize, &_DkCrypto_ClassInfo_, clinit$DkCrypto, allocate$DkCrypto);
	return class$;
}

$Class* DkCrypto::class$ = nullptr;

					} // dk
				} // crypto
			} // internal
		} // krb5
	} // security
} // sun