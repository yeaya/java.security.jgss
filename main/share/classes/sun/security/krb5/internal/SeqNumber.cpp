#include <sun/security/krb5/internal/SeqNumber.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$MethodInfo _SeqNumber_MethodInfo_[] = {
	{"current", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"init", "(I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"next", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"randInit", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"step", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _SeqNumber_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.security.krb5.internal.SeqNumber",
	nullptr,
	nullptr,
	nullptr,
	_SeqNumber_MethodInfo_
};

$Object* allocate$SeqNumber($Class* clazz) {
	return $of($alloc(SeqNumber));
}

$Class* SeqNumber::load$($String* name, bool initialize) {
	$loadClass(SeqNumber, name, initialize, &_SeqNumber_ClassInfo_, allocate$SeqNumber);
	return class$;
}

$Class* SeqNumber::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun