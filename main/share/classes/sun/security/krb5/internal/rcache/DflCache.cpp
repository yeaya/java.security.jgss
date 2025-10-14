#include <sun/security/krb5/internal/rcache/DflCache.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/file/Path.h>
#include <jdk/internal/misc/VM.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/ReplayCache.h>
#include <sun/security/krb5/internal/rcache/AuthTimeWithHash.h>
#include <sun/security/krb5/internal/rcache/DflCache$Storage.h>
#include <jcpp.h>

#undef EXCESSREPS
#undef KRB5_RV_VNO
#undef KRB_ERR_GENERIC

using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Path = ::java::nio::file::Path;
using $VM = ::jdk::internal::misc::VM;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $ReplayCache = ::sun::security::krb5::internal::ReplayCache;
using $AuthTime = ::sun::security::krb5::internal::rcache::AuthTime;
using $AuthTimeWithHash = ::sun::security::krb5::internal::rcache::AuthTimeWithHash;
using $DflCache$Storage = ::sun::security::krb5::internal::rcache::DflCache$Storage;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {

$FieldInfo _DflCache_FieldInfo_[] = {
	{"KRB5_RV_VNO", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DflCache, KRB5_RV_VNO)},
	{"EXCESSREPS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DflCache, EXCESSREPS)},
	{"source", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(DflCache, source)},
	{"uid", "J", nullptr, $PRIVATE | $STATIC, $staticField(DflCache, uid)},
	{}
};

$MethodInfo _DflCache_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(DflCache::*)($String*)>(&DflCache::init$))},
	{"checkAndStore", "(Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/rcache/AuthTimeWithHash;)V", nullptr, $PUBLIC, nullptr, "sun.security.krb5.internal.KrbApErrException"},
	{"checkAndStore0", "(Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/rcache/AuthTimeWithHash;)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<void(DflCache::*)($KerberosTime*,$AuthTimeWithHash*)>(&DflCache::checkAndStore0)), "java.io.IOException,sun.security.krb5.internal.KrbApErrException"},
	{"defaultFile", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($String*)>(&DflCache::defaultFile))},
	{"defaultPath", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)()>(&DflCache::defaultPath))},
	{"getFileName", "(Ljava/lang/String;Ljava/lang/String;)Ljava/nio/file/Path;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Path*(*)($String*,$String*)>(&DflCache::getFileName))},
	{}
};

$InnerClassInfo _DflCache_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.rcache.DflCache$Storage", "sun.security.krb5.internal.rcache.DflCache", "Storage", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DflCache_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.rcache.DflCache",
	"sun.security.krb5.internal.ReplayCache",
	nullptr,
	_DflCache_FieldInfo_,
	_DflCache_MethodInfo_,
	nullptr,
	nullptr,
	_DflCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.rcache.DflCache$Storage"
};

$Object* allocate$DflCache($Class* clazz) {
	return $of($alloc(DflCache));
}

int64_t DflCache::uid = 0;

void DflCache::init$($String* source) {
	$ReplayCache::init$();
	$set(this, source, source);
}

$String* DflCache::defaultPath() {
	$init(DflCache);
	return $GetPropertyAction::privilegedGetProperty("java.io.tmpdir"_s);
}

$String* DflCache::defaultFile($String* server$renamed) {
	$init(DflCache);
	$var($String, server, server$renamed);
	int32_t slash = $nc(server)->indexOf((int32_t)u'/');
	if (slash == -1) {
		slash = server->indexOf((int32_t)u'@');
	}
	if (slash != -1) {
		$assign(server, server->substring(0, slash));
	}
	if (DflCache::uid != -1) {
		$plusAssign(server, $$str({"_"_s, $$str(DflCache::uid)}));
	}
	return server;
}

$Path* DflCache::getFileName($String* source$renamed, $String* server) {
	$init(DflCache);
	$var($String, source, source$renamed);
	$var($String, path, nullptr);
	$var($String, file, nullptr);
	if ($nc(source)->equals("dfl"_s)) {
		$assign(path, defaultPath());
		$assign(file, defaultFile(server));
	} else if (source->startsWith("dfl:"_s)) {
		$assign(source, source->substring(4));
		int32_t pos = source->lastIndexOf((int32_t)u'/');
		int32_t pos1 = source->lastIndexOf((int32_t)u'\\');
		if (pos1 > pos) {
			pos = pos1;
		}
		if (pos == -1) {
			$assign(path, defaultPath());
			$assign(file, source);
		} else if ($$new($File, source)->isDirectory()) {
			$assign(path, source);
			$assign(file, defaultFile(server));
		} else {
			$assign(path, nullptr);
			$assign(file, source);
		}
	} else {
		$throwNew($IllegalArgumentException);
	}
	return $$new($File, path, file)->toPath();
}

void DflCache::checkAndStore($KerberosTime* currTime, $AuthTimeWithHash* time) {
	try {
		checkAndStore0(currTime, time);
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		$var($KrbApErrException, ke, $new($KrbApErrException, $Krb5::KRB_ERR_GENERIC));
		ke->initCause(ioe);
		$throw(ke);
	}
}

void DflCache::checkAndStore0($KerberosTime* currTime, $AuthTimeWithHash* time) {
	$synchronized(this) {
		$var($Path, p, getFileName(this->source, $nc(time)->server));
		int32_t missed = 0;
		{
			$var($DflCache$Storage, s, $new($DflCache$Storage));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						try {
							missed = s->loadAndCheck(p, time, currTime);
						} catch ($IOException&) {
							$var($IOException, ioe, $catch());
							$DflCache$Storage::create(p);
							missed = s->loadAndCheck(p, time, currTime);
						}
						s->append(time);
					} catch ($Throwable&) {
						$var($Throwable, t$, $catch());
						try {
							s->close();
						} catch ($Throwable&) {
							$var($Throwable, x2, $catch());
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable&) {
					$assign(var$0, $catch());
				} /*finally*/ {
					s->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
		if (missed > DflCache::EXCESSREPS) {
			$DflCache$Storage::expunge(p, currTime);
		}
	}
}

void clinit$DflCache($Class* class$) {
	{
		DflCache::uid = $VM::geteuid();
	}
}

DflCache::DflCache() {
}

$Class* DflCache::load$($String* name, bool initialize) {
	$loadClass(DflCache, name, initialize, &_DflCache_ClassInfo_, clinit$DflCache, allocate$DflCache);
	return class$;
}

$Class* DflCache::class$ = nullptr;

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun