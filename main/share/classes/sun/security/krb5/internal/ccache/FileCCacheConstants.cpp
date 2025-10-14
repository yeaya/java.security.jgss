#include <sun/security/krb5/internal/ccache/FileCCacheConstants.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

#undef FCC_TAG_DELTATIME
#undef KRB5_FCC_FVNO_1
#undef KRB5_FCC_FVNO_2
#undef KRB5_FCC_FVNO_3
#undef KRB5_FCC_FVNO_4
#undef KRB5_NT_UNKNOWN
#undef TKT_FLG_FORWARDABLE
#undef TKT_FLG_FORWARDED
#undef TKT_FLG_HW_AUTH
#undef TKT_FLG_INITIAL
#undef TKT_FLG_INVALID
#undef TKT_FLG_MAY_POSTDATE
#undef TKT_FLG_POSTDATED
#undef TKT_FLG_PRE_AUTH
#undef TKT_FLG_PROXIABLE
#undef TKT_FLG_PROXY
#undef TKT_FLG_RENEWABLE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$FieldInfo _FileCCacheConstants_FieldInfo_[] = {
	{"KRB5_FCC_FVNO_1", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, KRB5_FCC_FVNO_1)},
	{"KRB5_FCC_FVNO_2", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, KRB5_FCC_FVNO_2)},
	{"KRB5_FCC_FVNO_3", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, KRB5_FCC_FVNO_3)},
	{"KRB5_FCC_FVNO_4", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, KRB5_FCC_FVNO_4)},
	{"FCC_TAG_DELTATIME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, FCC_TAG_DELTATIME)},
	{"KRB5_NT_UNKNOWN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, KRB5_NT_UNKNOWN)},
	{"TKT_FLG_FORWARDABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_FORWARDABLE)},
	{"TKT_FLG_FORWARDED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_FORWARDED)},
	{"TKT_FLG_PROXIABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_PROXIABLE)},
	{"TKT_FLG_PROXY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_PROXY)},
	{"TKT_FLG_MAY_POSTDATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_MAY_POSTDATE)},
	{"TKT_FLG_POSTDATED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_POSTDATED)},
	{"TKT_FLG_INVALID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_INVALID)},
	{"TKT_FLG_RENEWABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_RENEWABLE)},
	{"TKT_FLG_INITIAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_INITIAL)},
	{"TKT_FLG_PRE_AUTH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_PRE_AUTH)},
	{"TKT_FLG_HW_AUTH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(FileCCacheConstants, TKT_FLG_HW_AUTH)},
	{}
};

$ClassInfo _FileCCacheConstants_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.security.krb5.internal.ccache.FileCCacheConstants",
	nullptr,
	nullptr,
	_FileCCacheConstants_FieldInfo_
};

$Object* allocate$FileCCacheConstants($Class* clazz) {
	return $of($alloc(FileCCacheConstants));
}

$Class* FileCCacheConstants::load$($String* name, bool initialize) {
	$loadClass(FileCCacheConstants, name, initialize, &_FileCCacheConstants_ClassInfo_, allocate$FileCCacheConstants);
	return class$;
}

$Class* FileCCacheConstants::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun