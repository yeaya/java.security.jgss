#include <sun/security/krb5/internal/util/KrbDataOutputStream.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace util {

$MethodInfo _KrbDataOutputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbDataOutputStream::*)($OutputStream*)>(&KrbDataOutputStream::init$))},
	{"write16", "(I)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"write32", "(I)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"write8", "(I)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _KrbDataOutputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.util.KrbDataOutputStream",
	"java.io.BufferedOutputStream",
	nullptr,
	nullptr,
	_KrbDataOutputStream_MethodInfo_
};

$Object* allocate$KrbDataOutputStream($Class* clazz) {
	return $of($alloc(KrbDataOutputStream));
}

void KrbDataOutputStream::init$($OutputStream* os) {
	$BufferedOutputStream::init$(os);
}

void KrbDataOutputStream::write32(int32_t num) {
	$var($bytes, bytes, $new($bytes, 4));
	bytes->set(0, (int8_t)((int32_t)((((int32_t)(num & (uint32_t)(int32_t)0xFF000000)) >> 24) & (uint32_t)255)));
	bytes->set(1, (int8_t)((int32_t)((((int32_t)(num & (uint32_t)0x00FF0000)) >> 16) & (uint32_t)255)));
	bytes->set(2, (int8_t)((int32_t)((((int32_t)(num & (uint32_t)0x0000FF00)) >> 8) & (uint32_t)255)));
	bytes->set(3, (int8_t)((int32_t)(num & (uint32_t)255)));
	write(bytes, 0, 4);
}

void KrbDataOutputStream::write16(int32_t num) {
	$var($bytes, bytes, $new($bytes, 2));
	bytes->set(0, (int8_t)((int32_t)((((int32_t)(num & (uint32_t)0x0000FF00)) >> 8) & (uint32_t)255)));
	bytes->set(1, (int8_t)((int32_t)(num & (uint32_t)255)));
	write(bytes, 0, 2);
}

void KrbDataOutputStream::write8(int32_t num) {
	write((int32_t)(num & (uint32_t)255));
}

KrbDataOutputStream::KrbDataOutputStream() {
}

$Class* KrbDataOutputStream::load$($String* name, bool initialize) {
	$loadClass(KrbDataOutputStream, name, initialize, &_KrbDataOutputStream_ClassInfo_, allocate$KrbDataOutputStream);
	return class$;
}

$Class* KrbDataOutputStream::class$ = nullptr;

				} // util
			} // internal
		} // krb5
	} // security
} // sun