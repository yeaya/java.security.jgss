#include <sun/security/jgss/wrapper/SunNativeProvider.h>

#include <java/io/PrintStream.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Provider.h>
#include <java/util/AbstractMap.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <sun/security/action/PutAllAction.h>
#include <sun/security/jgss/wrapper/SunNativeProvider$1.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef DEBUG
#undef INFO
#undef INSTANCE
#undef MECH_MAP
#undef MF_CLASS
#undef NAME
#undef PROVIDER_VER

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $AbstractMap = ::java::util::AbstractMap;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $PutAllAction = ::sun::security::action::PutAllAction;
using $SunNativeProvider$1 = ::sun::security::jgss::wrapper::SunNativeProvider$1;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

$FieldInfo _SunNativeProvider_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SunNativeProvider, serialVersionUID)},
	{"NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunNativeProvider, NAME)},
	{"INFO", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunNativeProvider, INFO)},
	{"MF_CLASS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunNativeProvider, MF_CLASS)},
	{"DEBUG", "Z", nullptr, $STATIC, $staticField(SunNativeProvider, DEBUG)},
	{"MECH_MAP", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SunNativeProvider, MECH_MAP)},
	{"INSTANCE", "Ljava/security/Provider;", nullptr, $STATIC | $FINAL, $staticField(SunNativeProvider, INSTANCE)},
	{}
};

$MethodInfo _SunNativeProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SunNativeProvider::*)()>(&SunNativeProvider::init$))},
	{"debug", "(Ljava/lang/String;)V", nullptr, $STATIC, $method(static_cast<void(*)($String*)>(&SunNativeProvider::debug))},
	{}
};

$InnerClassInfo _SunNativeProvider_InnerClassesInfo_[] = {
	{"sun.security.jgss.wrapper.SunNativeProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SunNativeProvider_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.jgss.wrapper.SunNativeProvider",
	"java.security.Provider",
	nullptr,
	_SunNativeProvider_FieldInfo_,
	_SunNativeProvider_MethodInfo_,
	nullptr,
	nullptr,
	_SunNativeProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.wrapper.SunNativeProvider$1"
};

$Object* allocate$SunNativeProvider($Class* clazz) {
	return $of($alloc(SunNativeProvider));
}

$String* SunNativeProvider::NAME = nullptr;
$String* SunNativeProvider::INFO = nullptr;
$String* SunNativeProvider::MF_CLASS = nullptr;
bool SunNativeProvider::DEBUG = false;
$HashMap* SunNativeProvider::MECH_MAP = nullptr;
$Provider* SunNativeProvider::INSTANCE = nullptr;

void SunNativeProvider::debug($String* message) {
	$init(SunNativeProvider);
	if (SunNativeProvider::DEBUG) {
		if (message == nullptr) {
			$throwNew($NullPointerException);
		}
		$init($System);
		$nc($System::out)->println($$str({SunNativeProvider::NAME, ": "_s, message}));
	}
}

void SunNativeProvider::init$() {
	$beforeCallerSensitive();
	$init($SecurityConstants);
	$Provider::init$(SunNativeProvider::NAME, $SecurityConstants::PROVIDER_VER, SunNativeProvider::INFO);
	if (SunNativeProvider::MECH_MAP != nullptr) {
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PutAllAction, this, SunNativeProvider::MECH_MAP)));
	}
}

void clinit$SunNativeProvider($Class* class$) {
	$assignStatic(SunNativeProvider::NAME, "SunNativeGSS"_s);
	$assignStatic(SunNativeProvider::INFO, "Sun Native GSS provider"_s);
	$assignStatic(SunNativeProvider::MF_CLASS, "sun.security.jgss.wrapper.NativeGSSFactory"_s);
	$beforeCallerSensitive();
	$assignStatic(SunNativeProvider::MECH_MAP, $cast($HashMap, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SunNativeProvider$1)))));
	$assignStatic(SunNativeProvider::INSTANCE, $new(SunNativeProvider));
}

SunNativeProvider::SunNativeProvider() {
}

$Class* SunNativeProvider::load$($String* name, bool initialize) {
	$loadClass(SunNativeProvider, name, initialize, &_SunNativeProvider_ClassInfo_, clinit$SunNativeProvider, allocate$SunNativeProvider);
	return class$;
}

$Class* SunNativeProvider::class$ = nullptr;

			} // wrapper
		} // jgss
	} // security
} // sun