#include <sun/security/krb5/internal/crypto/Des.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/SecretKeyFactory.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/krb5/KrbCryptoException.h>
#include <jcpp.h>

#undef CHARSET
#undef DECRYPT_MODE
#undef ENCRYPT_MODE

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $Cipher = ::javax::crypto::Cipher;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeyFactory = ::javax::crypto::SecretKeyFactory;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $KrbCryptoException = ::sun::security::krb5::KrbCryptoException;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$FieldInfo _Des_FieldInfo_[] = {
	{"CHARSET", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Des, CHARSET)},
	{"bad_keys", "[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Des, bad_keys)},
	{"good_parity", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Des, good_parity)},
	{}
};

$MethodInfo _Des_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Des::*)()>(&Des::init$))},
	{"bad_key", "(J)Z", nullptr, $PUBLIC | $STATIC | $FINAL, $method(static_cast<bool(*)(int64_t)>(&Des::bad_key))},
	{"bad_key", "([B)Z", nullptr, $PUBLIC | $STATIC | $FINAL, $method(static_cast<bool(*)($bytes*)>(&Des::bad_key))},
	{"cbc_encrypt", "([B[B[B[BZ)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($bytes*,$bytes*,$bytes*,$bytes*,bool)>(&Des::cbc_encrypt)), "sun.security.krb5.KrbCryptoException"},
	{"char_to_key", "([C)J", nullptr, $PUBLIC | $STATIC, $method(static_cast<int64_t(*)($chars*)>(&Des::char_to_key)), "sun.security.krb5.KrbCryptoException"},
	{"des_cksum", "([B[B[B)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,$bytes*,$bytes*)>(&Des::des_cksum)), "sun.security.krb5.KrbCryptoException"},
	{"long2octet", "(J)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)(int64_t)>(&Des::long2octet))},
	{"long2octet", "(J[B)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)(int64_t,$bytes*)>(&Des::long2octet))},
	{"long2octet", "(J[BI)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)(int64_t,$bytes*,int32_t)>(&Des::long2octet))},
	{"octet2long", "([B)J", nullptr, $PUBLIC | $STATIC, $method(static_cast<int64_t(*)($bytes*)>(&Des::octet2long))},
	{"octet2long", "([BI)J", nullptr, $PUBLIC | $STATIC, $method(static_cast<int64_t(*)($bytes*,int32_t)>(&Des::octet2long))},
	{"pad", "([B)[B", nullptr, $STATIC, $method(static_cast<$bytes*(*)($bytes*)>(&Des::pad))},
	{"set_parity", "([B)[B", nullptr, $PUBLIC | $STATIC | $FINAL, $method(static_cast<$bytes*(*)($bytes*)>(&Des::set_parity))},
	{"set_parity", "(J)J", nullptr, $PUBLIC | $STATIC | $FINAL, $method(static_cast<int64_t(*)(int64_t)>(&Des::set_parity))},
	{"string_to_key_bytes", "([C)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($chars*)>(&Des::string_to_key_bytes)), "sun.security.krb5.KrbCryptoException"},
	{}
};

$ClassInfo _Des_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.Des",
	"java.lang.Object",
	nullptr,
	_Des_FieldInfo_,
	_Des_MethodInfo_
};

$Object* allocate$Des($Class* clazz) {
	return $of($alloc(Des));
}

$String* Des::CHARSET = nullptr;
$longs* Des::bad_keys = nullptr;
$bytes* Des::good_parity = nullptr;

void Des::init$() {
}

$bytes* Des::set_parity($bytes* key) {
	$init(Des);
	for (int32_t i = 0; i < 8; ++i) {
		$nc(key)->set(i, $nc(Des::good_parity)->get((int32_t)(key->get(i) & (uint32_t)255)));
	}
	return key;
}

int64_t Des::set_parity(int64_t key) {
	$init(Des);
	return octet2long($(set_parity($(long2octet(key)))));
}

bool Des::bad_key(int64_t key) {
	$init(Des);
	for (int32_t i = 0; i < $nc(Des::bad_keys)->length; ++i) {
		if ($nc(Des::bad_keys)->get(i) == key) {
			return true;
		}
	}
	return false;
}

bool Des::bad_key($bytes* key) {
	$init(Des);
	return bad_key(octet2long(key));
}

int64_t Des::octet2long($bytes* input) {
	$init(Des);
	return octet2long(input, 0);
}

int64_t Des::octet2long($bytes* input, int32_t offset) {
	$init(Des);
	int64_t result = 0;
	for (int32_t i = 0; i < 8; ++i) {
		if (i + offset < $nc(input)->length) {
			result |= $sl((int64_t)(((int64_t)input->get(i + offset)) & (uint64_t)(int64_t)255), (7 - i) * 8);
		}
	}
	return result;
}

$bytes* Des::long2octet(int64_t input) {
	$init(Des);
	$var($bytes, output, $new($bytes, 8));
	for (int32_t i = 0; i < 8; ++i) {
		output->set(i, (int8_t)((int64_t)(($usr(input, (7 - i) * 8)) & (uint64_t)(int64_t)255)));
	}
	return output;
}

void Des::long2octet(int64_t input, $bytes* output) {
	$init(Des);
	long2octet(input, output, 0);
}

void Des::long2octet(int64_t input, $bytes* output, int32_t offset) {
	$init(Des);
	for (int32_t i = 0; i < 8; ++i) {
		if (i + offset < $nc(output)->length) {
			output->set(i + offset, (int8_t)((int64_t)(($usr(input, (7 - i) * 8)) & (uint64_t)(int64_t)255)));
		}
	}
}

void Des::cbc_encrypt($bytes* input, $bytes* output, $bytes* key, $bytes* ivec, bool encrypt) {
	$init(Des);
	$var($Cipher, cipher, nullptr);
	try {
		$assign(cipher, $Cipher::getInstance("DES/CBC/NoPadding"_s));
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $$str({"JCE provider may not be installed. "_s, $(e->getMessage())})));
		ke->initCause(e);
		$throw(ke);
	}
	$var($IvParameterSpec, params, $new($IvParameterSpec, ivec));
	$var($SecretKeySpec, skSpec, $new($SecretKeySpec, key, "DES"_s));
	try {
		$var($SecretKeyFactory, skf, $SecretKeyFactory::getInstance("DES"_s));
		$var($SecretKey, sk, static_cast<$SecretKey*>(skSpec));
		if (encrypt) {
			$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(sk), static_cast<$AlgorithmParameterSpec*>(params));
		} else {
			$nc(cipher)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>(sk), static_cast<$AlgorithmParameterSpec*>(params));
		}
		$var($bytes, result, nullptr);
		$assign(result, $nc(cipher)->doFinal(input));
		$System::arraycopy(result, 0, output, 0, $nc(result)->length);
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
}

int64_t Des::char_to_key($chars* passwdChars) {
	$init(Des);
	int64_t key = 0;
	int64_t octet = 0;
	int64_t octet1 = 0;
	int64_t octet2 = 0;
	$var($bytes, cbytes, nullptr);
	try {
		if (Des::CHARSET == nullptr) {
			$assign(cbytes, ($$new($String, passwdChars))->getBytes());
		} else {
			$assign(cbytes, ($$new($String, passwdChars))->getBytes(Des::CHARSET));
		}
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		if (cbytes != nullptr) {
			$Arrays::fill(cbytes, 0, cbytes->length, (int8_t)0);
		}
		$var($KrbCryptoException, ce, $new($KrbCryptoException, $$str({"Unable to convert passwd, "_s, e})));
		ce->initCause(e);
		$throw(ce);
	}
	$var($bytes, passwdBytes, pad(cbytes));
	$var($bytes, newkey, $new($bytes, 8));
	int32_t length = ($nc(passwdBytes)->length / 8) + (passwdBytes->length % 8 == 0 ? 0 : 1);
	for (int32_t i = 0; i < length; ++i) {
		octet = (int64_t)(octet2long(passwdBytes, i * 8) & (uint64_t)(int64_t)0x7F7F7F7F7F7F7F7F);
		if (i % 2 == 1) {
			octet1 = 0;
			for (int32_t j = 0; j < 64; ++j) {
				octet1 |= $sl($usr((int64_t)(octet & (uint64_t)($sl((int64_t)1, j))), j), 63 - j);
			}
			octet = (int64_t)((uint64_t)octet1 >> 1);
		}
		key ^= (octet << 1);
	}
	key = set_parity(key);
	if (bad_key(key)) {
		$var($bytes, temp, long2octet(key));
		(*$nc(temp))[7] ^= 240;
		key = octet2long(temp);
	}
	$var($bytes, var$0, long2octet(key));
	$var($bytes, var$1, passwdBytes);
	$assign(newkey, des_cksum(var$0, var$1, $(long2octet(key))));
	key = octet2long($(set_parity(newkey)));
	if (bad_key(key)) {
		$var($bytes, temp, long2octet(key));
		(*$nc(temp))[7] ^= 240;
		key = octet2long(temp);
	}
	if (cbytes != nullptr) {
		$Arrays::fill(cbytes, 0, cbytes->length, (int8_t)0);
	}
	if (passwdBytes != nullptr) {
		$Arrays::fill(passwdBytes, 0, passwdBytes->length, (int8_t)0);
	}
	return key;
}

$bytes* Des::des_cksum($bytes* ivec, $bytes* msg, $bytes* key) {
	$init(Des);
	$var($Cipher, cipher, nullptr);
	$var($bytes, result, $new($bytes, 8));
	try {
		$assign(cipher, $Cipher::getInstance("DES/CBC/NoPadding"_s));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $$str({"JCE provider may not be installed. "_s, $(e->getMessage())})));
		ke->initCause(e);
		$throw(ke);
	}
	$var($IvParameterSpec, params, $new($IvParameterSpec, ivec));
	$var($SecretKeySpec, skSpec, $new($SecretKeySpec, key, "DES"_s));
	try {
		$var($SecretKeyFactory, skf, $SecretKeyFactory::getInstance("DES"_s));
		$var($SecretKey, sk, static_cast<$SecretKey*>(skSpec));
		$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(sk), static_cast<$AlgorithmParameterSpec*>(params));
		for (int32_t i = 0; i < $nc(msg)->length / 8; ++i) {
			$assign(result, cipher->doFinal(msg, i * 8, 8));
			cipher->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(sk), (static_cast<$AlgorithmParameterSpec*>($$new($IvParameterSpec, result))));
		}
	} catch ($GeneralSecurityException&) {
		$var($GeneralSecurityException, e, $catch());
		$var($KrbCryptoException, ke, $new($KrbCryptoException, $(e->getMessage())));
		ke->initCause(e);
		$throw(ke);
	}
	return result;
}

$bytes* Des::pad($bytes* data) {
	$init(Des);
	int32_t len = 0;
	if ($nc(data)->length < 8) {
		len = data->length;
	} else {
		len = data->length % 8;
	}
	if (len == 0) {
		return data;
	} else {
		$var($bytes, padding, $new($bytes, 8 - len + $nc(data)->length));
		for (int32_t i = padding->length - 1; i > data->length - 1; --i) {
			padding->set(i, (int8_t)0);
		}
		$System::arraycopy(data, 0, padding, 0, data->length);
		return padding;
	}
}

$bytes* Des::string_to_key_bytes($chars* passwdChars) {
	$init(Des);
	return long2octet(char_to_key(passwdChars));
}

void clinit$Des($Class* class$) {
	$assignStatic(Des::CHARSET, $GetPropertyAction::privilegedGetProperty("sun.security.krb5.msinterop.des.s2kcharset"_s));
	$assignStatic(Des::bad_keys, $new($longs, {
		(int64_t)0x0101010101010101,
		(int64_t)0xFEFEFEFEFEFEFEFE,
		(int64_t)0x1F1F1F1F1F1F1F1F,
		(int64_t)0xE0E0E0E0E0E0E0E0,
		(int64_t)0x01FE01FE01FE01FE,
		(int64_t)0xFE01FE01FE01FE01,
		(int64_t)0x1FE01FE00EF10EF1,
		(int64_t)0xE01FE01FF10EF10E,
		(int64_t)0x01E001E001F101F1,
		(int64_t)0xE001E001F101F101,
		(int64_t)0x1FFE1FFE0EFE0EFE,
		(int64_t)0xFE1FFE1FFE0EFE0E,
		(int64_t)0x011F011F010E010E,
		(int64_t)0x1F011F010E010E01,
		(int64_t)0xE0FEE0FEF1FEF1FE,
		(int64_t)0xFEE0FEE0FEF1FEF1
	}));
	$assignStatic(Des::good_parity, $new($bytes, {
		(int8_t)1,
		(int8_t)1,
		(int8_t)2,
		(int8_t)2,
		(int8_t)4,
		(int8_t)4,
		(int8_t)7,
		(int8_t)7,
		(int8_t)8,
		(int8_t)8,
		(int8_t)11,
		(int8_t)11,
		(int8_t)13,
		(int8_t)13,
		(int8_t)14,
		(int8_t)14,
		(int8_t)16,
		(int8_t)16,
		(int8_t)19,
		(int8_t)19,
		(int8_t)21,
		(int8_t)21,
		(int8_t)22,
		(int8_t)22,
		(int8_t)25,
		(int8_t)25,
		(int8_t)26,
		(int8_t)26,
		(int8_t)28,
		(int8_t)28,
		(int8_t)31,
		(int8_t)31,
		(int8_t)32,
		(int8_t)32,
		(int8_t)35,
		(int8_t)35,
		(int8_t)37,
		(int8_t)37,
		(int8_t)38,
		(int8_t)38,
		(int8_t)41,
		(int8_t)41,
		(int8_t)42,
		(int8_t)42,
		(int8_t)44,
		(int8_t)44,
		(int8_t)47,
		(int8_t)47,
		(int8_t)49,
		(int8_t)49,
		(int8_t)50,
		(int8_t)50,
		(int8_t)52,
		(int8_t)52,
		(int8_t)55,
		(int8_t)55,
		(int8_t)56,
		(int8_t)56,
		(int8_t)59,
		(int8_t)59,
		(int8_t)61,
		(int8_t)61,
		(int8_t)62,
		(int8_t)62,
		(int8_t)64,
		(int8_t)64,
		(int8_t)67,
		(int8_t)67,
		(int8_t)69,
		(int8_t)69,
		(int8_t)70,
		(int8_t)70,
		(int8_t)73,
		(int8_t)73,
		(int8_t)74,
		(int8_t)74,
		(int8_t)76,
		(int8_t)76,
		(int8_t)79,
		(int8_t)79,
		(int8_t)81,
		(int8_t)81,
		(int8_t)82,
		(int8_t)82,
		(int8_t)84,
		(int8_t)84,
		(int8_t)87,
		(int8_t)87,
		(int8_t)88,
		(int8_t)88,
		(int8_t)91,
		(int8_t)91,
		(int8_t)93,
		(int8_t)93,
		(int8_t)94,
		(int8_t)94,
		(int8_t)97,
		(int8_t)97,
		(int8_t)98,
		(int8_t)98,
		(int8_t)100,
		(int8_t)100,
		(int8_t)103,
		(int8_t)103,
		(int8_t)104,
		(int8_t)104,
		(int8_t)107,
		(int8_t)107,
		(int8_t)109,
		(int8_t)109,
		(int8_t)110,
		(int8_t)110,
		(int8_t)112,
		(int8_t)112,
		(int8_t)115,
		(int8_t)115,
		(int8_t)117,
		(int8_t)117,
		(int8_t)118,
		(int8_t)118,
		(int8_t)121,
		(int8_t)121,
		(int8_t)122,
		(int8_t)122,
		(int8_t)124,
		(int8_t)124,
		(int8_t)127,
		(int8_t)127,
		(int8_t)128,
		(int8_t)128,
		(int8_t)131,
		(int8_t)131,
		(int8_t)133,
		(int8_t)133,
		(int8_t)134,
		(int8_t)134,
		(int8_t)137,
		(int8_t)137,
		(int8_t)138,
		(int8_t)138,
		(int8_t)140,
		(int8_t)140,
		(int8_t)143,
		(int8_t)143,
		(int8_t)145,
		(int8_t)145,
		(int8_t)146,
		(int8_t)146,
		(int8_t)148,
		(int8_t)148,
		(int8_t)151,
		(int8_t)151,
		(int8_t)152,
		(int8_t)152,
		(int8_t)155,
		(int8_t)155,
		(int8_t)157,
		(int8_t)157,
		(int8_t)158,
		(int8_t)158,
		(int8_t)161,
		(int8_t)161,
		(int8_t)162,
		(int8_t)162,
		(int8_t)164,
		(int8_t)164,
		(int8_t)167,
		(int8_t)167,
		(int8_t)168,
		(int8_t)168,
		(int8_t)171,
		(int8_t)171,
		(int8_t)173,
		(int8_t)173,
		(int8_t)174,
		(int8_t)174,
		(int8_t)176,
		(int8_t)176,
		(int8_t)179,
		(int8_t)179,
		(int8_t)181,
		(int8_t)181,
		(int8_t)182,
		(int8_t)182,
		(int8_t)185,
		(int8_t)185,
		(int8_t)186,
		(int8_t)186,
		(int8_t)188,
		(int8_t)188,
		(int8_t)191,
		(int8_t)191,
		(int8_t)193,
		(int8_t)193,
		(int8_t)194,
		(int8_t)194,
		(int8_t)196,
		(int8_t)196,
		(int8_t)199,
		(int8_t)199,
		(int8_t)200,
		(int8_t)200,
		(int8_t)203,
		(int8_t)203,
		(int8_t)205,
		(int8_t)205,
		(int8_t)206,
		(int8_t)206,
		(int8_t)208,
		(int8_t)208,
		(int8_t)211,
		(int8_t)211,
		(int8_t)213,
		(int8_t)213,
		(int8_t)214,
		(int8_t)214,
		(int8_t)217,
		(int8_t)217,
		(int8_t)218,
		(int8_t)218,
		(int8_t)220,
		(int8_t)220,
		(int8_t)223,
		(int8_t)223,
		(int8_t)224,
		(int8_t)224,
		(int8_t)227,
		(int8_t)227,
		(int8_t)229,
		(int8_t)229,
		(int8_t)230,
		(int8_t)230,
		(int8_t)233,
		(int8_t)233,
		(int8_t)234,
		(int8_t)234,
		(int8_t)236,
		(int8_t)236,
		(int8_t)239,
		(int8_t)239,
		(int8_t)241,
		(int8_t)241,
		(int8_t)242,
		(int8_t)242,
		(int8_t)244,
		(int8_t)244,
		(int8_t)247,
		(int8_t)247,
		(int8_t)248,
		(int8_t)248,
		(int8_t)251,
		(int8_t)251,
		(int8_t)253,
		(int8_t)253,
		(int8_t)254,
		(int8_t)254
	}));
}

Des::Des() {
}

$Class* Des::load$($String* name, bool initialize) {
	$loadClass(Des, name, initialize, &_Des_ClassInfo_, clinit$Des, allocate$Des);
	return class$;
}

$Class* Des::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun