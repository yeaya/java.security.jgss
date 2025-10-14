#include <sun/security/jgss/SunProvider$ProviderService.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <sun/security/jgss/SunProvider.h>
#include <sun/security/jgss/krb5/Krb5MechFactory.h>
#include <sun/security/jgss/spnego/SpNegoMechFactory.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $ProviderException = ::java::security::ProviderException;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $SunProvider = ::sun::security::jgss::SunProvider;
using $Krb5MechFactory = ::sun::security::jgss::krb5::Krb5MechFactory;
using $SpNegoMechFactory = ::sun::security::jgss::spnego::SpNegoMechFactory;

namespace sun {
	namespace security {
		namespace jgss {

$MethodInfo _SunProvider$ProviderService_MethodInfo_[] = {
	{"<init>", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(SunProvider$ProviderService::*)($Provider*,$String*,$String*,$String*)>(&SunProvider$ProviderService::init$))},
	{"newInstance", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.security.NoSuchAlgorithmException"},
	{}
};

$InnerClassInfo _SunProvider$ProviderService_InnerClassesInfo_[] = {
	{"sun.security.jgss.SunProvider$ProviderService", "sun.security.jgss.SunProvider", "ProviderService", $PRIVATE | $STATIC | $FINAL},
	{"java.security.Provider$Service", "java.security.Provider", "Service", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _SunProvider$ProviderService_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.jgss.SunProvider$ProviderService",
	"java.security.Provider$Service",
	nullptr,
	nullptr,
	_SunProvider$ProviderService_MethodInfo_,
	nullptr,
	nullptr,
	_SunProvider$ProviderService_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.SunProvider"
};

$Object* allocate$SunProvider$ProviderService($Class* clazz) {
	return $of($alloc(SunProvider$ProviderService));
}

void SunProvider$ProviderService::init$($Provider* p, $String* type, $String* algo, $String* cn) {
	$Provider$Service::init$(p, type, algo, cn, nullptr, nullptr);
}

$Object* SunProvider$ProviderService::newInstance(Object$* ctrParamObj) {
	$var($String, type, getType());
	if (ctrParamObj != nullptr) {
		$throwNew($InvalidParameterException, $$str({"constructorParameter not used with "_s, type, " engines"_s}));
	}
	$var($String, algo, getAlgorithm());
	try {
		if ($nc(type)->equals("GssApiMechanism"_s)) {
			if ($nc(algo)->equals("1.2.840.113554.1.2.2"_s)) {
				return $of($new($Krb5MechFactory));
			} else if (algo->equals("1.3.6.1.5.5.2"_s)) {
				return $of($new($SpNegoMechFactory));
			}
		}
	} catch ($Exception&) {
		$var($Exception, ex, $catch());
		$throwNew($NoSuchAlgorithmException, $$str({"Error constructing "_s, type, " for "_s, algo, " using SunJGSS"_s}), ex);
	}
	$throwNew($ProviderException, $$str({"No impl for "_s, algo, " "_s, type}));
	$shouldNotReachHere();
}

SunProvider$ProviderService::SunProvider$ProviderService() {
}

$Class* SunProvider$ProviderService::load$($String* name, bool initialize) {
	$loadClass(SunProvider$ProviderService, name, initialize, &_SunProvider$ProviderService_ClassInfo_, allocate$SunProvider$ProviderService);
	return class$;
}

$Class* SunProvider$ProviderService::class$ = nullptr;

		} // jgss
	} // security
} // sun