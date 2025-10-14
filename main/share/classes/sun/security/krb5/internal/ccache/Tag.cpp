#include <sun/security/krb5/internal/ccache/Tag.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$FieldInfo _Tag_FieldInfo_[] = {
	{"length", "I", nullptr, 0, $field(Tag, length)},
	{"tag", "I", nullptr, 0, $field(Tag, tag)},
	{"tagLen", "I", nullptr, 0, $field(Tag, tagLen)},
	{"time_offset", "Ljava/lang/Integer;", nullptr, 0, $field(Tag, time_offset)},
	{"usec_offset", "Ljava/lang/Integer;", nullptr, 0, $field(Tag, usec_offset)},
	{}
};

$MethodInfo _Tag_MethodInfo_[] = {
	{"<init>", "(IILjava/lang/Integer;Ljava/lang/Integer;)V", nullptr, $PUBLIC, $method(static_cast<void(Tag::*)(int32_t,int32_t,$Integer*,$Integer*)>(&Tag::init$))},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(Tag::*)(int32_t)>(&Tag::init$))},
	{"toByteArray", "()[B", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Tag_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ccache.Tag",
	"java.lang.Object",
	nullptr,
	_Tag_FieldInfo_,
	_Tag_MethodInfo_
};

$Object* allocate$Tag($Class* clazz) {
	return $of($alloc(Tag));
}

void Tag::init$(int32_t len, int32_t new_tag, $Integer* new_time, $Integer* new_usec) {
	this->tag = new_tag;
	this->tagLen = 8;
	$set(this, time_offset, new_time);
	$set(this, usec_offset, new_usec);
	this->length = 4 + this->tagLen;
}

void Tag::init$(int32_t new_tag) {
	this->tag = new_tag;
	this->tagLen = 0;
	this->length = 4 + this->tagLen;
}

$bytes* Tag::toByteArray() {
	$var($ByteArrayOutputStream, os, $new($ByteArrayOutputStream));
	os->write(this->length);
	os->write(this->tag);
	os->write(this->tagLen);
	if (this->time_offset != nullptr) {
		os->write($nc(this->time_offset)->intValue());
	}
	if (this->usec_offset != nullptr) {
		os->write($nc(this->usec_offset)->intValue());
	}
	return os->toByteArray();
}

Tag::Tag() {
}

$Class* Tag::load$($String* name, bool initialize) {
	$loadClass(Tag, name, initialize, &_Tag_ClassInfo_, allocate$Tag);
	return class$;
}

$Class* Tag::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun