#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

#undef KRB5_KT_VNO
#undef KRB5_KT_VNO_1

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {

$FieldInfo _KeyTabConstants_FieldInfo_[] = {
	{"principalComponentSize", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, principalComponentSize)},
	{"realmSize", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, realmSize)},
	{"principalSize", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, principalSize)},
	{"principalTypeSize", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, principalTypeSize)},
	{"timestampSize", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, timestampSize)},
	{"keyVersionSize", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, keyVersionSize)},
	{"keyTypeSize", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, keyTypeSize)},
	{"keySize", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, keySize)},
	{"KRB5_KT_VNO_1", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, KRB5_KT_VNO_1)},
	{"KRB5_KT_VNO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyTabConstants, KRB5_KT_VNO)},
	{}
};

$ClassInfo _KeyTabConstants_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.security.krb5.internal.ktab.KeyTabConstants",
	nullptr,
	nullptr,
	_KeyTabConstants_FieldInfo_
};

$Object* allocate$KeyTabConstants($Class* clazz) {
	return $of($alloc(KeyTabConstants));
}

$Class* KeyTabConstants::load$($String* name, bool initialize) {
	$loadClass(KeyTabConstants, name, initialize, &_KeyTabConstants_ClassInfo_, allocate$KeyTabConstants);
	return class$;
}

$Class* KeyTabConstants::class$ = nullptr;

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun