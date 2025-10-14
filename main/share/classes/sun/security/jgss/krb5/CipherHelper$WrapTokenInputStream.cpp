#include <sun/security/jgss/krb5/CipherHelper$WrapTokenInputStream.h>

#include <java/io/InputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/Math.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/jgss/krb5/CipherHelper.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $CipherHelper = ::sun::security::jgss::krb5::CipherHelper;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _CipherHelper$WrapTokenInputStream_FieldInfo_[] = {
	{"this$0", "Lsun/security/jgss/krb5/CipherHelper;", nullptr, $FINAL | $SYNTHETIC, $field(CipherHelper$WrapTokenInputStream, this$0)},
	{"is", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(CipherHelper$WrapTokenInputStream, is)},
	{"length", "I", nullptr, $PRIVATE, $field(CipherHelper$WrapTokenInputStream, length)},
	{"remaining", "I", nullptr, $PRIVATE, $field(CipherHelper$WrapTokenInputStream, remaining)},
	{"temp", "I", nullptr, $PRIVATE, $field(CipherHelper$WrapTokenInputStream, temp)},
	{}
};

$MethodInfo _CipherHelper$WrapTokenInputStream_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/CipherHelper;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, $method(static_cast<void(CipherHelper$WrapTokenInputStream::*)($CipherHelper*,$InputStream*,int32_t)>(&CipherHelper$WrapTokenInputStream::init$))},
	{"available", "()I", nullptr, $PUBLIC | $FINAL, nullptr, "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC | $FINAL, nullptr, "java.io.IOException"},
	{"read", "()I", nullptr, $PUBLIC | $FINAL, nullptr, "java.io.IOException"},
	{"read", "([B)I", nullptr, $PUBLIC | $FINAL, nullptr, "java.io.IOException"},
	{"read", "([BII)I", nullptr, $PUBLIC | $FINAL, nullptr, "java.io.IOException"},
	{"skip", "(J)J", nullptr, $PUBLIC | $FINAL, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _CipherHelper$WrapTokenInputStream_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.CipherHelper$WrapTokenInputStream", "sun.security.jgss.krb5.CipherHelper", "WrapTokenInputStream", 0},
	{}
};

$ClassInfo _CipherHelper$WrapTokenInputStream_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.CipherHelper$WrapTokenInputStream",
	"java.io.InputStream",
	nullptr,
	_CipherHelper$WrapTokenInputStream_FieldInfo_,
	_CipherHelper$WrapTokenInputStream_MethodInfo_,
	nullptr,
	nullptr,
	_CipherHelper$WrapTokenInputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.CipherHelper"
};

$Object* allocate$CipherHelper$WrapTokenInputStream($Class* clazz) {
	return $of($alloc(CipherHelper$WrapTokenInputStream));
}

void CipherHelper$WrapTokenInputStream::init$($CipherHelper* this$0, $InputStream* is, int32_t length) {
	$set(this, this$0, this$0);
	$InputStream::init$();
	$set(this, is, is);
	this->length = length;
	this->remaining = length;
}

int32_t CipherHelper$WrapTokenInputStream::read() {
	if (this->remaining == 0) {
		return -1;
	} else {
		this->temp = $nc(this->is)->read();
		if (this->temp != -1) {
			this->remaining -= this->temp;
		}
		return this->temp;
	}
}

int32_t CipherHelper$WrapTokenInputStream::read($bytes* b) {
	if (this->remaining == 0) {
		return -1;
	} else {
		this->temp = $Math::min(this->remaining, $nc(b)->length);
		this->temp = $nc(this->is)->read(b, 0, this->temp);
		if (this->temp != -1) {
			this->remaining -= this->temp;
		}
		return this->temp;
	}
}

int32_t CipherHelper$WrapTokenInputStream::read($bytes* b, int32_t off, int32_t len) {
	if (this->remaining == 0) {
		return -1;
	} else {
		this->temp = $Math::min(this->remaining, len);
		this->temp = $nc(this->is)->read(b, off, this->temp);
		if (this->temp != -1) {
			this->remaining -= this->temp;
		}
		return this->temp;
	}
}

int64_t CipherHelper$WrapTokenInputStream::skip(int64_t n) {
	if (this->remaining == 0) {
		return 0;
	} else {
		this->temp = (int32_t)$Math::min((int64_t)this->remaining, n);
		this->temp = (int32_t)$nc(this->is)->skip(this->temp);
		this->remaining -= this->temp;
		return this->temp;
	}
}

int32_t CipherHelper$WrapTokenInputStream::available() {
	return $Math::min(this->remaining, $nc(this->is)->available());
}

void CipherHelper$WrapTokenInputStream::close() {
	this->remaining = 0;
}

CipherHelper$WrapTokenInputStream::CipherHelper$WrapTokenInputStream() {
}

$Class* CipherHelper$WrapTokenInputStream::load$($String* name, bool initialize) {
	$loadClass(CipherHelper$WrapTokenInputStream, name, initialize, &_CipherHelper$WrapTokenInputStream_ClassInfo_, allocate$CipherHelper$WrapTokenInputStream);
	return class$;
}

$Class* CipherHelper$WrapTokenInputStream::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun