#include <sun/security/krb5/internal/crypto/dk/Des3DkCrypto.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/KeySpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/Mac.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/SecretKeyFactory.h>
#include <javax/crypto/spec/DESKeySpec.h>
#include <javax/crypto/spec/DESedeKeySpec.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/krb5/internal/crypto/dk/DkCrypto.h>
#include <jcpp.h>

#undef KERBEROS_CONSTANT
#undef ZERO_IV

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $KeySpec = ::java::security::spec::KeySpec;
using $Arrays = ::java::util::Arrays;
using $Cipher = ::javax::crypto::Cipher;
using $Mac = ::javax::crypto::Mac;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeyFactory = ::javax::crypto::SecretKeyFactory;
using $DESKeySpec = ::javax::crypto::spec::DESKeySpec;
using $DESedeKeySpec = ::javax::crypto::spec::DESedeKeySpec;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $DkCrypto = ::sun::security::krb5::internal::crypto::dk::DkCrypto;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {
					namespace dk {

$FieldInfo _Des3DkCrypto_FieldInfo_[] = {
	{"ZERO_IV", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Des3DkCrypto, ZERO_IV)},
	{}
};

$MethodInfo _Des3DkCrypto_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Des3DkCrypto::*)()>(&Des3DkCrypto::init$))},
	{"des3Expand", "([BII)[B", nullptr, $PRIVATE | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t,int32_t)>(&Des3DkCrypto::des3Expand))},
	{"getChecksumLength", "()I", nullptr, $PUBLIC},
	{"getCipher", "([B[BI)Ljavax/crypto/Cipher;", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"getHmac", "([B[B)[B", nullptr, $PROTECTED, nullptr, "java.security.GeneralSecurityException"},
	{"getKeySeedLength", "()I", nullptr, $PROTECTED},
	{"keyCorrection", "([B)[B", nullptr, $PRIVATE | $STATIC, $method(static_cast<$bytes*(*)($bytes*)>(&Des3DkCrypto::keyCorrection))},
	{"parityFix", "([B)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"randomToKey", "([B)[B", nullptr, $PROTECTED},
	{"setParityBit", "([B)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($bytes*)>(&Des3DkCrypto::setParityBit))},
	{"stringToKey", "([C)[B", nullptr, $PUBLIC, nullptr, "java.security.GeneralSecurityException"},
	{"stringToKey", "([B[B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(Des3DkCrypto::*)($bytes*,$bytes*)>(&Des3DkCrypto::stringToKey)), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _Des3DkCrypto_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.dk.Des3DkCrypto",
	"sun.security.krb5.internal.crypto.dk.DkCrypto",
	nullptr,
	_Des3DkCrypto_FieldInfo_,
	_Des3DkCrypto_MethodInfo_
};

$Object* allocate$Des3DkCrypto($Class* clazz) {
	return $of($alloc(Des3DkCrypto));
}

$bytes* Des3DkCrypto::ZERO_IV = nullptr;

void Des3DkCrypto::init$() {
	$DkCrypto::init$();
}

int32_t Des3DkCrypto::getKeySeedLength() {
	return 168;
}

$bytes* Des3DkCrypto::stringToKey($chars* salt) {
	$var($bytes, saltUtf8, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(saltUtf8, charToUtf8(salt));
			$assign(var$2, stringToKey(saltUtf8, nullptr));
			return$1 = true;
			goto $finally;
		} catch ($Throwable&) {
			$assign(var$0, $catch());
		} $finally: {
			if (saltUtf8 != nullptr) {
				$Arrays::fill(saltUtf8, (int8_t)0);
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

$bytes* Des3DkCrypto::stringToKey($bytes* secretAndSalt, $bytes* opaque) {
	if (opaque != nullptr && opaque->length > 0) {
		$throwNew($RuntimeException, "Invalid parameter to stringToKey"_s);
	}
	$var($bytes, tmpKey, randomToKey($(nfold(secretAndSalt, getKeySeedLength()))));
	$init($DkCrypto);
	return dk(tmpKey, $DkCrypto::KERBEROS_CONSTANT);
}

$bytes* Des3DkCrypto::parityFix($bytes* value) {
	setParityBit(value);
	return value;
}

$bytes* Des3DkCrypto::randomToKey($bytes* in) {
	if ($nc(in)->length != 21) {
		$throwNew($IllegalArgumentException, "input must be 168 bits"_s);
	}
	$var($bytes, one, keyCorrection($(des3Expand(in, 0, 7))));
	$var($bytes, two, keyCorrection($(des3Expand(in, 7, 14))));
	$var($bytes, three, keyCorrection($(des3Expand(in, 14, 21))));
	$var($bytes, key, $new($bytes, 24));
	$System::arraycopy(one, 0, key, 0, 8);
	$System::arraycopy(two, 0, key, 8, 8);
	$System::arraycopy(three, 0, key, 16, 8);
	return key;
}

$bytes* Des3DkCrypto::keyCorrection($bytes* key) {
	$init(Des3DkCrypto);
	try {
		if ($DESKeySpec::isWeak(key, 0)) {
			$nc(key)->set(7, (int8_t)(key->get(7) ^ 240));
		}
	} catch ($InvalidKeyException&) {
		$catch();
	}
	return key;
}

$bytes* Des3DkCrypto::des3Expand($bytes* input, int32_t start, int32_t end) {
	$init(Des3DkCrypto);
	if ((end - start) != 7) {
		$throwNew($IllegalArgumentException, $$str({"Invalid length of DES Key Value:"_s, $$str(start), ","_s, $$str(end)}));
	}
	$var($bytes, result, $new($bytes, 8));
	int8_t last = (int8_t)0;
	$System::arraycopy(input, start, result, 0, 7);
	int8_t posn = (int8_t)0;
	for (int32_t i = start; i < end; ++i) {
		int8_t bit = (int8_t)((int32_t)($nc(input)->get(i) & (uint32_t)1));
		++posn;
		if (bit != 0) {
			last |= ($sl((int32_t)bit, posn));
		}
	}
	result->set(7, last);
	setParityBit(result);
	return result;
}

void Des3DkCrypto::setParityBit($bytes* key) {
	$init(Des3DkCrypto);
	for (int32_t i = 0; i < $nc(key)->length; ++i) {
		int32_t b = (int32_t)(key->get(i) & (uint32_t)254);
		b |= ((int32_t)($Integer::bitCount(b) & (uint32_t)1)) ^ 1;
		key->set(i, (int8_t)b);
	}
}

$Cipher* Des3DkCrypto::getCipher($bytes* key, $bytes* ivec$renamed, int32_t mode) {
	$var($bytes, ivec, ivec$renamed);
	$var($SecretKeyFactory, factory, $SecretKeyFactory::getInstance("desede"_s));
	$var($KeySpec, spec, $new($DESedeKeySpec, key, 0));
	$var($SecretKey, secretKey, $nc(factory)->generateSecret(spec));
	if (ivec == nullptr) {
		$assign(ivec, Des3DkCrypto::ZERO_IV);
	}
	$var($Cipher, cipher, $Cipher::getInstance("DESede/CBC/NoPadding"_s));
	$var($IvParameterSpec, encIv, $new($IvParameterSpec, ivec, 0, $nc(ivec)->length));
	$nc(cipher)->init(mode, static_cast<$Key*>(secretKey), static_cast<$AlgorithmParameterSpec*>(encIv));
	return cipher;
}

int32_t Des3DkCrypto::getChecksumLength() {
	return 20;
}

$bytes* Des3DkCrypto::getHmac($bytes* key, $bytes* msg) {
	$var($SecretKey, keyKi, $new($SecretKeySpec, key, "HmacSHA1"_s));
	$var($Mac, m, $Mac::getInstance("HmacSHA1"_s));
	$nc(m)->init(keyKi);
	return m->doFinal(msg);
}

void clinit$Des3DkCrypto($Class* class$) {
	$assignStatic(Des3DkCrypto::ZERO_IV, $new($bytes, {
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0
	}));
}

Des3DkCrypto::Des3DkCrypto() {
}

$Class* Des3DkCrypto::load$($String* name, bool initialize) {
	$loadClass(Des3DkCrypto, name, initialize, &_Des3DkCrypto_ClassInfo_, clinit$Des3DkCrypto, allocate$Des3DkCrypto);
	return class$;
}

$Class* Des3DkCrypto::class$ = nullptr;

					} // dk
				} // crypto
			} // internal
		} // krb5
	} // security
} // sun