#include <sun/security/krb5/internal/util/KrbDataInputStream.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/ByteOrder.h>
#include <jcpp.h>

#undef BIG_ENDIAN

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteOrder = ::java::nio::ByteOrder;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace util {

$FieldInfo _KrbDataInputStream_FieldInfo_[] = {
	{"bigEndian", "Z", nullptr, $PRIVATE, $field(KrbDataInputStream, bigEndian)},
	{}
};

$MethodInfo _KrbDataInputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbDataInputStream::*)($InputStream*)>(&KrbDataInputStream::init$))},
	{"read", "(I)I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"readLength4", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(KrbDataInputStream::*)()>(&KrbDataInputStream::readLength4)), "java.io.IOException"},
	{"readVersion", "()I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"setNativeByteOrder", "()V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KrbDataInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.util.KrbDataInputStream",
	"java.io.BufferedInputStream",
	nullptr,
	_KrbDataInputStream_FieldInfo_,
	_KrbDataInputStream_MethodInfo_
};

$Object* allocate$KrbDataInputStream($Class* clazz) {
	return $of($alloc(KrbDataInputStream));
}

void KrbDataInputStream::setNativeByteOrder() {
	$init($ByteOrder);
	if ($nc($of($($ByteOrder::nativeOrder())))->equals($ByteOrder::BIG_ENDIAN)) {
		this->bigEndian = true;
	} else {
		this->bigEndian = false;
	}
}

void KrbDataInputStream::init$($InputStream* is) {
	$BufferedInputStream::init$(is);
	this->bigEndian = true;
}

int32_t KrbDataInputStream::readLength4() {
	int32_t len = read(4);
	if (len < 0) {
		$throwNew($IOException, "Invalid encoding"_s);
	}
	return len;
}

int32_t KrbDataInputStream::read(int32_t num) {
	$var($bytes, bytes, $new($bytes, num));
	if (read(bytes, 0, num) != num) {
		$throwNew($IOException, "Premature end of stream reached"_s);
	}
	int32_t result = 0;
	for (int32_t i = 0; i < num; ++i) {
		if (this->bigEndian) {
			result |= $sl((int32_t)(bytes->get(i) & (uint32_t)255), (num - i - 1) * 8);
		} else {
			result |= $sl((int32_t)(bytes->get(i) & (uint32_t)255), i * 8);
		}
	}
	return result;
}

int32_t KrbDataInputStream::readVersion() {
	int32_t result = ((int32_t)(read() & (uint32_t)255)) << 8;
	return result | ((int32_t)(read() & (uint32_t)255));
}

KrbDataInputStream::KrbDataInputStream() {
}

$Class* KrbDataInputStream::load$($String* name, bool initialize) {
	$loadClass(KrbDataInputStream, name, initialize, &_KrbDataInputStream_ClassInfo_, allocate$KrbDataInputStream);
	return class$;
}

$Class* KrbDataInputStream::class$ = nullptr;

				} // util
			} // internal
		} // krb5
	} // security
} // sun