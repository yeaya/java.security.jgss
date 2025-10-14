#include <sun/security/jgss/SunProvider.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <sun/security/jgss/SunProvider$1.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef INFO
#undef PROVIDER_VER

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $SunProvider$1 = ::sun::security::jgss::SunProvider$1;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _SunProvider_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SunProvider, serialVersionUID)},
	{"INFO", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunProvider, INFO)},
	{}
};

$MethodInfo _SunProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SunProvider::*)()>(&SunProvider::init$))},
	{"access$000", "(Lsun/security/jgss/SunProvider;Ljava/security/Provider$Service;)V", nullptr, $STATIC | $SYNTHETIC, $method(static_cast<void(*)(SunProvider*,$Provider$Service*)>(&SunProvider::access$000))},
	{"access$100", "(Lsun/security/jgss/SunProvider;Ljava/security/Provider$Service;)V", nullptr, $STATIC | $SYNTHETIC, $method(static_cast<void(*)(SunProvider*,$Provider$Service*)>(&SunProvider::access$100))},
	{}
};

$InnerClassInfo _SunProvider_InnerClassesInfo_[] = {
	{"sun.security.jgss.SunProvider$ProviderService", "sun.security.jgss.SunProvider", "ProviderService", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.jgss.SunProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SunProvider_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.jgss.SunProvider",
	"java.security.Provider",
	nullptr,
	_SunProvider_FieldInfo_,
	_SunProvider_MethodInfo_,
	nullptr,
	nullptr,
	_SunProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.SunProvider$ProviderService,sun.security.jgss.SunProvider$1"
};

$Object* allocate$SunProvider($Class* clazz) {
	return $of($alloc(SunProvider));
}

$String* SunProvider::INFO = nullptr;

void SunProvider::access$100(SunProvider* x0, $Provider$Service* x1) {
	$init(SunProvider);
	$nc(x0)->putService(x1);
}

void SunProvider::access$000(SunProvider* x0, $Provider$Service* x1) {
	$init(SunProvider);
	$nc(x0)->putService(x1);
}

void SunProvider::init$() {
	$beforeCallerSensitive();
	$init($SecurityConstants);
	$Provider::init$("SunJGSS"_s, $SecurityConstants::PROVIDER_VER, SunProvider::INFO);
	$var($Provider, p, this);
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SunProvider$1, this, p)));
}

SunProvider::SunProvider() {
}

void clinit$SunProvider($Class* class$) {
	$assignStatic(SunProvider::INFO, "Sun (Kerberos v5, SPNEGO)"_s);
}

$Class* SunProvider::load$($String* name, bool initialize) {
	$loadClass(SunProvider, name, initialize, &_SunProvider_ClassInfo_, clinit$SunProvider, allocate$SunProvider);
	return class$;
}

$Class* SunProvider::class$ = nullptr;

		} // jgss
	} // security
} // sun