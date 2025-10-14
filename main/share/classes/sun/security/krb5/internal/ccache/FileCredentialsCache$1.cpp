#include <sun/security/krb5/internal/ccache/FileCredentialsCache$1.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/internal/ccache/FileCredentialsCache.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $FileCredentialsCache = ::sun::security::krb5::internal::ccache::FileCredentialsCache;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$MethodInfo _FileCredentialsCache$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(FileCredentialsCache$1::*)()>(&FileCredentialsCache$1::init$))},
	{"run", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _FileCredentialsCache$1_EnclosingMethodInfo_ = {
	"sun.security.krb5.internal.ccache.FileCredentialsCache",
	"getDefaultCacheName",
	"()Ljava/lang/String;"
};

$InnerClassInfo _FileCredentialsCache$1_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ccache.FileCredentialsCache$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileCredentialsCache$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.internal.ccache.FileCredentialsCache$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_FileCredentialsCache$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/String;>;",
	&_FileCredentialsCache$1_EnclosingMethodInfo_,
	_FileCredentialsCache$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ccache.FileCredentialsCache"
};

$Object* allocate$FileCredentialsCache$1($Class* clazz) {
	return $of($alloc(FileCredentialsCache$1));
}

void FileCredentialsCache$1::init$() {
}

$Object* FileCredentialsCache$1::run() {
	$var($String, cache, $System::getenv("KRB5CCNAME"_s));
	bool var$0 = cache != nullptr && (cache->length() >= 5);
	if (var$0 && cache->regionMatches(true, 0, "FILE:"_s, 0, 5)) {
		$assign(cache, cache->substring(5));
	}
	return $of(cache);
}

FileCredentialsCache$1::FileCredentialsCache$1() {
}

$Class* FileCredentialsCache$1::load$($String* name, bool initialize) {
	$loadClass(FileCredentialsCache$1, name, initialize, &_FileCredentialsCache$1_ClassInfo_, allocate$FileCredentialsCache$1);
	return class$;
}

$Class* FileCredentialsCache$1::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun