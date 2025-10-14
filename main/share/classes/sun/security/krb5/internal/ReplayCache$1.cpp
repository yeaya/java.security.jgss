#include <sun/security/krb5/internal/ReplayCache$1.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/ReplayCache.h>
#include <sun/security/krb5/internal/rcache/AuthTimeWithHash.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $ReplayCache = ::sun::security::krb5::internal::ReplayCache;
using $AuthTimeWithHash = ::sun::security::krb5::internal::rcache::AuthTimeWithHash;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$MethodInfo _ReplayCache$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(ReplayCache$1::*)()>(&ReplayCache$1::init$))},
	{"checkAndStore", "(Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/rcache/AuthTimeWithHash;)V", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KrbApErrException"},
	{}
};

$EnclosingMethodInfo _ReplayCache$1_EnclosingMethodInfo_ = {
	"sun.security.krb5.internal.ReplayCache",
	"getInstance",
	"(Ljava/lang/String;)Lsun/security/krb5/internal/ReplayCache;"
};

$InnerClassInfo _ReplayCache$1_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ReplayCache$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReplayCache$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.internal.ReplayCache$1",
	"sun.security.krb5.internal.ReplayCache",
	nullptr,
	nullptr,
	_ReplayCache$1_MethodInfo_,
	nullptr,
	&_ReplayCache$1_EnclosingMethodInfo_,
	_ReplayCache$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ReplayCache"
};

$Object* allocate$ReplayCache$1($Class* clazz) {
	return $of($alloc(ReplayCache$1));
}

void ReplayCache$1::init$() {
	$ReplayCache::init$();
}

void ReplayCache$1::checkAndStore($KerberosTime* currTime, $AuthTimeWithHash* time) {
}

ReplayCache$1::ReplayCache$1() {
}

$Class* ReplayCache$1::load$($String* name, bool initialize) {
	$loadClass(ReplayCache$1, name, initialize, &_ReplayCache$1_ClassInfo_, allocate$ReplayCache$1);
	return class$;
}

$Class* ReplayCache$1::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun