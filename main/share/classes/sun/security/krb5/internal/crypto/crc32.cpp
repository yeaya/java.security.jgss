#include <sun/security/krb5/internal/crypto/crc32.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/DigestException.h>
#include <java/security/MessageDigestSpi.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <jcpp.h>

#undef CRC32_LENGTH
#undef DEBUG

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $DigestException = ::java::security::DigestException;
using $MessageDigestSpi = ::java::security::MessageDigestSpi;
using $Krb5 = ::sun::security::krb5::internal::Krb5;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$FieldInfo _crc32_FieldInfo_[] = {
	{"CRC32_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(crc32, CRC32_LENGTH)},
	{"seed", "I", nullptr, $PRIVATE, $field(crc32, seed)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(crc32, DEBUG)},
	{"crc32Table", "[I", nullptr, $PRIVATE | $STATIC, $staticField(crc32, crc32Table)},
	{}
};

$MethodInfo _crc32_MethodInfo_[] = {
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(crc32::*)()>(&crc32::init$))},
	{"byte2crc32", "([B)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($bytes*)>(&crc32::byte2crc32))},
	{"byte2crc32sum", "(I[BI)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)(int32_t,$bytes*,int32_t)>(&crc32::byte2crc32sum))},
	{"byte2crc32sum", "(I[B)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)(int32_t,$bytes*)>(&crc32::byte2crc32sum))},
	{"byte2crc32sum", "([B)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($bytes*)>(&crc32::byte2crc32sum))},
	{"byte2crc32sum_bytes", "([B)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*)>(&crc32::byte2crc32sum_bytes))},
	{"byte2crc32sum_bytes", "([BI)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($bytes*,int32_t)>(&crc32::byte2crc32sum_bytes))},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"engineDigest", "()[B", nullptr, $PROTECTED},
	{"engineDigest", "([BII)I", nullptr, $PROTECTED, nullptr, "java.security.DigestException"},
	{"engineGetDigestLength", "()I", nullptr, $PROTECTED},
	{"engineReset", "()V", nullptr, $PROTECTED},
	{"engineUpdate", "(B)V", nullptr, $PROTECTED | $SYNCHRONIZED},
	{"engineUpdate", "([BII)V", nullptr, $PROTECTED | $SYNCHRONIZED},
	{"init", "()V", nullptr, $PUBLIC, $method(static_cast<void(crc32::*)()>(&crc32::init))},
	{"int2crc32", "(I)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)(int32_t)>(&crc32::int2crc32))},
	{"int2quad", "(J)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)(int64_t)>(&crc32::int2quad))},
	{"printcrc32Table", "()V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)()>(&crc32::printcrc32Table))},
	{"processData", "([BII)V", nullptr, $PRIVATE, $method(static_cast<void(crc32::*)($bytes*,int32_t,int32_t)>(&crc32::processData))},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _crc32_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.crc32",
	"java.security.MessageDigestSpi",
	"java.lang.Cloneable",
	_crc32_FieldInfo_,
	_crc32_MethodInfo_
};

$Object* allocate$crc32($Class* clazz) {
	return $of($alloc(crc32));
}

int32_t crc32::hashCode() {
	 return this->$MessageDigestSpi::hashCode();
}

bool crc32::equals(Object$* arg0) {
	 return this->$MessageDigestSpi::equals(arg0);
}

$String* crc32::toString() {
	 return this->$MessageDigestSpi::toString();
}

void crc32::finalize() {
	this->$MessageDigestSpi::finalize();
}

bool crc32::DEBUG = false;
$ints* crc32::crc32Table = nullptr;

void crc32::init$() {
	$MessageDigestSpi::init$();
	init();
}

$Object* crc32::clone() {
	try {
		$var(crc32, crc, $cast(crc32, $MessageDigestSpi::clone()));
		$nc(crc)->init();
		return $of(crc);
	} catch ($CloneNotSupportedException&) {
		$catch();
	}
	return $of(nullptr);
}

int32_t crc32::engineGetDigestLength() {
	return (crc32::CRC32_LENGTH);
}

$bytes* crc32::engineDigest() {
	$var($bytes, result, $new($bytes, crc32::CRC32_LENGTH));
	$assign(result, int2quad(this->seed));
	init();
	return result;
}

int32_t crc32::engineDigest($bytes* buf, int32_t offset, int32_t len) {
	$var($bytes, result, $new($bytes, crc32::CRC32_LENGTH));
	$assign(result, int2quad(this->seed));
	if (len < crc32::CRC32_LENGTH) {
		$throwNew($DigestException, "partial digests not returned"_s);
	}
	if ($nc(buf)->length - offset < crc32::CRC32_LENGTH) {
		$throwNew($DigestException, "insufficient space in the output buffer to store the digest"_s);
	}
	$System::arraycopy(result, 0, buf, offset, crc32::CRC32_LENGTH);
	init();
	return crc32::CRC32_LENGTH;
}

void crc32::engineUpdate(int8_t b) {
	$synchronized(this) {
		$var($bytes, input, $new($bytes, 1));
		input->set(0, b);
		engineUpdate(input, this->seed, 1);
	}
}

void crc32::engineUpdate($bytes* input, int32_t offset, int32_t len) {
	$synchronized(this) {
		processData(input, offset, len);
	}
}

void crc32::engineReset() {
	init();
}

void crc32::init() {
	this->seed = 0;
}

void crc32::processData($bytes* data, int32_t off, int32_t len) {
	int32_t result = this->seed;
	for (int32_t i = 0; i < len; ++i) {
		result = ((int32_t)((uint32_t)result >> 8)) ^ $nc(crc32::crc32Table)->get((int32_t)((result ^ $nc(data)->get(i)) & (uint32_t)255));
	}
	this->seed = result;
}

int32_t crc32::int2crc32(int32_t b) {
	$init(crc32);
	int32_t crc = b;
	for (int32_t i = 8; i > 0; --i) {
		if (((int32_t)(crc & (uint32_t)1)) != 0) {
			crc = ((int32_t)((uint32_t)crc >> 1)) ^ (int32_t)0xEDB88320;
		} else {
			crc = (int32_t)((uint32_t)crc >> 1);
		}
	}
	return crc;
}

void crc32::printcrc32Table() {
	$init(crc32);
	$var($String, temp, nullptr);
	$var($String, zerofill, "00000000"_s);
	$init($System);
	$nc($System::out)->print("\tpublic static int[] crc32Table = {"_s);
	for (int32_t i = 0; i < 256; ++i) {
		if ((i % 4) == 0) {
			$nc($System::out)->print("\n\t\t"_s);
		}
		$assign(temp, $Integer::toHexString(int2crc32(i)));
		$nc($System::out)->print($$str({"0x"_s, $(zerofill->substring($nc(temp)->length())), temp}));
		if (i != 255) {
			$nc($System::out)->print(", "_s);
		}
	}
	$nc($System::out)->println("\n\t};"_s);
}

int32_t crc32::byte2crc32sum(int32_t seed, $bytes* data, int32_t size) {
	$init(crc32);
	int32_t crc = seed;
	for (int32_t i = 0; i < size; ++i) {
		crc = ((int32_t)((uint32_t)crc >> 8)) ^ $nc(crc32::crc32Table)->get((int32_t)((crc ^ $nc(data)->get(i)) & (uint32_t)255));
	}
	return crc;
}

int32_t crc32::byte2crc32sum(int32_t seed, $bytes* data) {
	$init(crc32);
	return byte2crc32sum(seed, data, $nc(data)->length);
}

int32_t crc32::byte2crc32sum($bytes* data) {
	$init(crc32);
	return byte2crc32sum(0, data);
}

int32_t crc32::byte2crc32($bytes* data) {
	$init(crc32);
	return ~byte2crc32sum(-1, data);
}

$bytes* crc32::byte2crc32sum_bytes($bytes* data) {
	$init(crc32);
	int32_t temp = byte2crc32sum(data);
	return int2quad(temp);
}

$bytes* crc32::byte2crc32sum_bytes($bytes* data, int32_t size) {
	$init(crc32);
	int32_t temp = byte2crc32sum(0, data, size);
	if (crc32::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>>crc32: "_s, $($Integer::toHexString(temp))}));
		$nc($System::out)->println($$str({">>>crc32: "_s, $($Integer::toBinaryString(temp))}));
	}
	return int2quad(temp);
}

$bytes* crc32::int2quad(int64_t input) {
	$init(crc32);
	$var($bytes, output, $new($bytes, 4));
	for (int32_t i = 0; i < 4; ++i) {
		output->set(i, (int8_t)((int64_t)(($usr(input, i * 8)) & (uint64_t)(int64_t)255)));
	}
	return output;
}

void clinit$crc32($Class* class$) {
	$init($Krb5);
	crc32::DEBUG = $Krb5::DEBUG;
	$assignStatic(crc32::crc32Table, $new($ints, {
		0,
		0x77073096,
		(int32_t)0xEE0E612C,
		(int32_t)0x990951BA,
		0x076DC419,
		0x706AF48F,
		(int32_t)0xE963A535,
		(int32_t)0x9E6495A3,
		0x0EDB8832,
		0x79DCB8A4,
		(int32_t)0xE0D5E91E,
		(int32_t)0x97D2D988,
		0x09B64C2B,
		0x7EB17CBD,
		(int32_t)0xE7B82D07,
		(int32_t)0x90BF1D91,
		0x1DB71064,
		0x6AB020F2,
		(int32_t)0xF3B97148,
		(int32_t)0x84BE41DE,
		0x1ADAD47D,
		0x6DDDE4EB,
		(int32_t)0xF4D4B551,
		(int32_t)0x83D385C7,
		0x136C9856,
		0x646BA8C0,
		(int32_t)0xFD62F97A,
		(int32_t)0x8A65C9EC,
		0x14015C4F,
		0x63066CD9,
		(int32_t)0xFA0F3D63,
		(int32_t)0x8D080DF5,
		0x3B6E20C8,
		0x4C69105E,
		(int32_t)0xD56041E4,
		(int32_t)0xA2677172,
		0x3C03E4D1,
		0x4B04D447,
		(int32_t)0xD20D85FD,
		(int32_t)0xA50AB56B,
		0x35B5A8FA,
		0x42B2986C,
		(int32_t)0xDBBBC9D6,
		(int32_t)0xACBCF940,
		0x32D86CE3,
		0x45DF5C75,
		(int32_t)0xDCD60DCF,
		(int32_t)0xABD13D59,
		0x26D930AC,
		0x51DE003A,
		(int32_t)0xC8D75180,
		(int32_t)0xBFD06116,
		0x21B4F4B5,
		0x56B3C423,
		(int32_t)0xCFBA9599,
		(int32_t)0xB8BDA50F,
		0x2802B89E,
		0x5F058808,
		(int32_t)0xC60CD9B2,
		(int32_t)0xB10BE924,
		0x2F6F7C87,
		0x58684C11,
		(int32_t)0xC1611DAB,
		(int32_t)0xB6662D3D,
		0x76DC4190,
		0x01DB7106,
		(int32_t)0x98D220BC,
		(int32_t)0xEFD5102A,
		0x71B18589,
		0x06B6B51F,
		(int32_t)0x9FBFE4A5,
		(int32_t)0xE8B8D433,
		0x7807C9A2,
		0x0F00F934,
		(int32_t)0x9609A88E,
		(int32_t)0xE10E9818,
		0x7F6A0DBB,
		0x086D3D2D,
		(int32_t)0x91646C97,
		(int32_t)0xE6635C01,
		0x6B6B51F4,
		0x1C6C6162,
		(int32_t)0x856530D8,
		(int32_t)0xF262004E,
		0x6C0695ED,
		0x1B01A57B,
		(int32_t)0x8208F4C1,
		(int32_t)0xF50FC457,
		0x65B0D9C6,
		0x12B7E950,
		(int32_t)0x8BBEB8EA,
		(int32_t)0xFCB9887C,
		0x62DD1DDF,
		0x15DA2D49,
		(int32_t)0x8CD37CF3,
		(int32_t)0xFBD44C65,
		0x4DB26158,
		0x3AB551CE,
		(int32_t)0xA3BC0074,
		(int32_t)0xD4BB30E2,
		0x4ADFA541,
		0x3DD895D7,
		(int32_t)0xA4D1C46D,
		(int32_t)0xD3D6F4FB,
		0x4369E96A,
		0x346ED9FC,
		(int32_t)0xAD678846,
		(int32_t)0xDA60B8D0,
		0x44042D73,
		0x33031DE5,
		(int32_t)0xAA0A4C5F,
		(int32_t)0xDD0D7CC9,
		0x5005713C,
		0x270241AA,
		(int32_t)0xBE0B1010,
		(int32_t)0xC90C2086,
		0x5768B525,
		0x206F85B3,
		(int32_t)0xB966D409,
		(int32_t)0xCE61E49F,
		0x5EDEF90E,
		0x29D9C998,
		(int32_t)0xB0D09822,
		(int32_t)0xC7D7A8B4,
		0x59B33D17,
		0x2EB40D81,
		(int32_t)0xB7BD5C3B,
		(int32_t)0xC0BA6CAD,
		(int32_t)0xEDB88320,
		(int32_t)0x9ABFB3B6,
		0x03B6E20C,
		0x74B1D29A,
		(int32_t)0xEAD54739,
		(int32_t)0x9DD277AF,
		0x04DB2615,
		0x73DC1683,
		(int32_t)0xE3630B12,
		(int32_t)0x94643B84,
		0x0D6D6A3E,
		0x7A6A5AA8,
		(int32_t)0xE40ECF0B,
		(int32_t)0x9309FF9D,
		0x0A00AE27,
		0x7D079EB1,
		(int32_t)0xF00F9344,
		(int32_t)0x8708A3D2,
		0x1E01F268,
		0x6906C2FE,
		(int32_t)0xF762575D,
		(int32_t)0x806567CB,
		0x196C3671,
		0x6E6B06E7,
		(int32_t)0xFED41B76,
		(int32_t)0x89D32BE0,
		0x10DA7A5A,
		0x67DD4ACC,
		(int32_t)0xF9B9DF6F,
		(int32_t)0x8EBEEFF9,
		0x17B7BE43,
		0x60B08ED5,
		(int32_t)0xD6D6A3E8,
		(int32_t)0xA1D1937E,
		0x38D8C2C4,
		0x4FDFF252,
		(int32_t)0xD1BB67F1,
		(int32_t)0xA6BC5767,
		0x3FB506DD,
		0x48B2364B,
		(int32_t)0xD80D2BDA,
		(int32_t)0xAF0A1B4C,
		0x36034AF6,
		0x41047A60,
		(int32_t)0xDF60EFC3,
		(int32_t)0xA867DF55,
		0x316E8EEF,
		0x4669BE79,
		(int32_t)0xCB61B38C,
		(int32_t)0xBC66831A,
		0x256FD2A0,
		0x5268E236,
		(int32_t)0xCC0C7795,
		(int32_t)0xBB0B4703,
		0x220216B9,
		0x5505262F,
		(int32_t)0xC5BA3BBE,
		(int32_t)0xB2BD0B28,
		0x2BB45A92,
		0x5CB36A04,
		(int32_t)0xC2D7FFA7,
		(int32_t)0xB5D0CF31,
		0x2CD99E8B,
		0x5BDEAE1D,
		(int32_t)0x9B64C2B0,
		(int32_t)0xEC63F226,
		0x756AA39C,
		0x026D930A,
		(int32_t)0x9C0906A9,
		(int32_t)0xEB0E363F,
		0x72076785,
		0x05005713,
		(int32_t)0x95BF4A82,
		(int32_t)0xE2B87A14,
		0x7BB12BAE,
		0x0CB61B38,
		(int32_t)0x92D28E9B,
		(int32_t)0xE5D5BE0D,
		0x7CDCEFB7,
		0x0BDBDF21,
		(int32_t)0x86D3D2D4,
		(int32_t)0xF1D4E242,
		0x68DDB3F8,
		0x1FDA836E,
		(int32_t)0x81BE16CD,
		(int32_t)0xF6B9265B,
		0x6FB077E1,
		0x18B74777,
		(int32_t)0x88085AE6,
		(int32_t)0xFF0F6A70,
		0x66063BCA,
		0x11010B5C,
		(int32_t)0x8F659EFF,
		(int32_t)0xF862AE69,
		0x616BFFD3,
		0x166CCF45,
		(int32_t)0xA00AE278,
		(int32_t)0xD70DD2EE,
		0x4E048354,
		0x3903B3C2,
		(int32_t)0xA7672661,
		(int32_t)0xD06016F7,
		0x4969474D,
		0x3E6E77DB,
		(int32_t)0xAED16A4A,
		(int32_t)0xD9D65ADC,
		0x40DF0B66,
		0x37D83BF0,
		(int32_t)0xA9BCAE53,
		(int32_t)0xDEBB9EC5,
		0x47B2CF7F,
		0x30B5FFE9,
		(int32_t)0xBDBDF21C,
		(int32_t)0xCABAC28A,
		0x53B39330,
		0x24B4A3A6,
		(int32_t)0xBAD03605,
		(int32_t)0xCDD70693,
		0x54DE5729,
		0x23D967BF,
		(int32_t)0xB3667A2E,
		(int32_t)0xC4614AB8,
		0x5D681B02,
		0x2A6F2B94,
		(int32_t)0xB40BBE37,
		(int32_t)0xC30C8EA1,
		0x5A05DF1B,
		0x2D02EF8D
	}));
}

crc32::crc32() {
}

$Class* crc32::load$($String* name, bool initialize) {
	$loadClass(crc32, name, initialize, &_crc32_ClassInfo_, clinit$crc32, allocate$crc32);
	return class$;
}

$Class* crc32::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun