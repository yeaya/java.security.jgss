#include <sun/security/krb5/internal/LocalSeqNumber.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Confounder.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Confounder = ::sun::security::krb5::Confounder;
using $SeqNumber = ::sun::security::krb5::internal::SeqNumber;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _LocalSeqNumber_FieldInfo_[] = {
	{"lastSeqNumber", "I", nullptr, $PRIVATE, $field(LocalSeqNumber, lastSeqNumber)},
	{}
};

$MethodInfo _LocalSeqNumber_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LocalSeqNumber::*)()>(&LocalSeqNumber::init$))},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(LocalSeqNumber::*)(int32_t)>(&LocalSeqNumber::init$))},
	{"<init>", "(Ljava/lang/Integer;)V", nullptr, $PUBLIC, $method(static_cast<void(LocalSeqNumber::*)($Integer*)>(&LocalSeqNumber::init$))},
	{"current", "()I", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"init", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"next", "()I", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"randInit", "()V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"step", "()I", nullptr, $PUBLIC | $SYNCHRONIZED},
	{}
};

$ClassInfo _LocalSeqNumber_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.LocalSeqNumber",
	"java.lang.Object",
	"sun.security.krb5.internal.SeqNumber",
	_LocalSeqNumber_FieldInfo_,
	_LocalSeqNumber_MethodInfo_
};

$Object* allocate$LocalSeqNumber($Class* clazz) {
	return $of($alloc(LocalSeqNumber));
}

void LocalSeqNumber::init$() {
	randInit();
}

void LocalSeqNumber::init$(int32_t start) {
	init(start);
}

void LocalSeqNumber::init$($Integer* start) {
	init($nc(start)->intValue());
}

void LocalSeqNumber::randInit() {
	$synchronized(this) {
		$var($bytes, data, $Confounder::bytes(4));
		$nc(data)->set(0, (int8_t)((int32_t)(data->get(0) & (uint32_t)63)));
		int32_t result = (((((int32_t)(data->get(3) & (uint32_t)255)) | (((int32_t)(data->get(2) & (uint32_t)255)) << 8)) | (((int32_t)(data->get(1) & (uint32_t)255)) << 16)) | (((int32_t)(data->get(0) & (uint32_t)255)) << 24));
		if (result == 0) {
			result = 1;
		}
		this->lastSeqNumber = result;
	}
}

void LocalSeqNumber::init(int32_t start) {
	$synchronized(this) {
		this->lastSeqNumber = start;
	}
}

int32_t LocalSeqNumber::current() {
	$synchronized(this) {
		return this->lastSeqNumber;
	}
}

int32_t LocalSeqNumber::next() {
	$synchronized(this) {
		return this->lastSeqNumber + 1;
	}
}

int32_t LocalSeqNumber::step() {
	$synchronized(this) {
		return ++this->lastSeqNumber;
	}
}

LocalSeqNumber::LocalSeqNumber() {
}

$Class* LocalSeqNumber::load$($String* name, bool initialize) {
	$loadClass(LocalSeqNumber, name, initialize, &_LocalSeqNumber_ClassInfo_, allocate$LocalSeqNumber);
	return class$;
}

$Class* LocalSeqNumber::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun