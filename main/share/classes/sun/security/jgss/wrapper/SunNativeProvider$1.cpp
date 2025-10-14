#include <sun/security/jgss/wrapper/SunNativeProvider$1.h>

#include <java/lang/Array.h>
#include <java/lang/Boolean.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/Error.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/HashMap.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/wrapper/GSSLibStub.h>
#include <sun/security/jgss/wrapper/SunNativeProvider.h>
#include <jcpp.h>

#undef DEBUG

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Error = ::java::lang::Error;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $HashMap = ::java::util::HashMap;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSLibStub = ::sun::security::jgss::wrapper::GSSLibStub;
using $SunNativeProvider = ::sun::security::jgss::wrapper::SunNativeProvider;

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

$MethodInfo _SunNativeProvider$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(SunNativeProvider$1::*)()>(&SunNativeProvider$1::init$))},
	{"run", "()Ljava/util/HashMap;", "()Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC},
	{}
};

$EnclosingMethodInfo _SunNativeProvider$1_EnclosingMethodInfo_ = {
	"sun.security.jgss.wrapper.SunNativeProvider",
	nullptr,
	nullptr
};

$InnerClassInfo _SunNativeProvider$1_InnerClassesInfo_[] = {
	{"sun.security.jgss.wrapper.SunNativeProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SunNativeProvider$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.wrapper.SunNativeProvider$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_SunNativeProvider$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;>;",
	&_SunNativeProvider$1_EnclosingMethodInfo_,
	_SunNativeProvider$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.wrapper.SunNativeProvider"
};

$Object* allocate$SunNativeProvider$1($Class* clazz) {
	return $of($alloc(SunNativeProvider$1));
}

void SunNativeProvider$1::init$() {
}

$Object* SunNativeProvider$1::run() {
	$beforeCallerSensitive();
	$init($SunNativeProvider);
	$SunNativeProvider::DEBUG = $Boolean::parseBoolean($($System::getProperty("sun.security.nativegss.debug"_s)));
	try {
		$Class::forName("java.net.InetAddress"_s);
		$System::loadLibrary("j2gss"_s);
	} catch ($ClassNotFoundException&) {
		$var($Throwable, err, $catch());
		$SunNativeProvider::debug("No j2gss library found!"_s);
		if ($SunNativeProvider::DEBUG) {
			err->printStackTrace();
		}
		return $of(nullptr);
	} catch ($Error&) {
		$var($Throwable, err, $catch());
		$SunNativeProvider::debug("No j2gss library found!"_s);
		if ($SunNativeProvider::DEBUG) {
			err->printStackTrace();
		}
		return $of(nullptr);
	}
	$var($StringArray, gssLibs, nullptr);
	$var($String, defaultLib, $System::getProperty("sun.security.jgss.lib"_s));
	if (defaultLib == nullptr || $($nc(defaultLib)->trim())->equals(""_s)) {
		$var($String, osname, $System::getProperty("os.name"_s));
		if ($nc(osname)->startsWith("Linux"_s)) {
			$assign(gssLibs, $new($StringArray, {
				"libgssapi.so"_s,
				"libgssapi_krb5.so"_s,
				"libgssapi_krb5.so.2"_s
			}));
		} else if (osname->contains("OS X"_s)) {
			$assign(gssLibs, $new($StringArray, {
				"libgssapi_krb5.dylib"_s,
				"/usr/lib/sasl2/libgssapiv2.2.so"_s
			}));
		} else if (osname->contains("Windows"_s)) {
			$assign(gssLibs, $new($StringArray, {$$str({$($System::getProperty("java.home"_s)), "\\bin\\sspi_bridge.dll"_s})}));
		} else {
			$assign(gssLibs, $new($StringArray, 0));
		}
	} else {
		$assign(gssLibs, $new($StringArray, {defaultLib}));
	}
	{
		$var($StringArray, arr$, gssLibs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, libName, arr$->get(i$));
			{
				if ($GSSLibStub::init(libName, $SunNativeProvider::DEBUG)) {
					$SunNativeProvider::debug($$str({"Loaded GSS library: "_s, libName}));
					$var($OidArray, mechs, $GSSLibStub::indicateMechs());
					$var($HashMap, map, $new($HashMap));
					for (int32_t i = 0; i < $nc(mechs)->length; ++i) {
						$SunNativeProvider::debug($$str({"Native MF for "_s, mechs->get(i)}));
						map->put($$str({"GssApiMechanism."_s, mechs->get(i)}), "sun.security.jgss.wrapper.NativeGSSFactory"_s);
					}
					return $of(map);
				}
			}
		}
	}
	return $of(nullptr);
}

SunNativeProvider$1::SunNativeProvider$1() {
}

$Class* SunNativeProvider$1::load$($String* name, bool initialize) {
	$loadClass(SunNativeProvider$1, name, initialize, &_SunNativeProvider$1_ClassInfo_, allocate$SunNativeProvider$1);
	return class$;
}

$Class* SunNativeProvider$1::class$ = nullptr;

			} // wrapper
		} // jgss
	} // security
} // sun