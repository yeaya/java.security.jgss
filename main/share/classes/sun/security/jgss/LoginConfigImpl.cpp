#include <sun/security/jgss/LoginConfigImpl.h>

#include <java/lang/Array.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <javax/security/auth/login/AppConfigurationEntry$LoginModuleControlFlag.h>
#include <javax/security/auth/login/AppConfigurationEntry.h>
#include <javax/security/auth/login/Configuration.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/HttpCaller.h>
#include <sun/security/jgss/LoginConfigImpl$1.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef CALLER_ACCEPT
#undef CALLER_INITIATE
#undef CALLER_UNKNOWN
#undef GSS_KRB5_MECH_OID
#undef HTTP_USE_GLOBAL_CREDS
#undef REQUIRED

using $AppConfigurationEntryArray = $Array<::javax::security::auth::login::AppConfigurationEntry>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $AppConfigurationEntry = ::javax::security::auth::login::AppConfigurationEntry;
using $AppConfigurationEntry$LoginModuleControlFlag = ::javax::security::auth::login::AppConfigurationEntry$LoginModuleControlFlag;
using $Configuration = ::javax::security::auth::login::Configuration;
using $Oid = ::org::ietf::jgss::Oid;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $HttpCaller = ::sun::security::jgss::HttpCaller;
using $LoginConfigImpl$1 = ::sun::security::jgss::LoginConfigImpl$1;
using $Debug = ::sun::security::util::Debug;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _LoginConfigImpl_FieldInfo_[] = {
	{"config", "Ljavax/security/auth/login/Configuration;", nullptr, $PRIVATE | $FINAL, $field(LoginConfigImpl, config)},
	{"caller", "Lsun/security/jgss/GSSCaller;", nullptr, $PRIVATE | $FINAL, $field(LoginConfigImpl, caller)},
	{"mechName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(LoginConfigImpl, mechName)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoginConfigImpl, debug)},
	{"HTTP_USE_GLOBAL_CREDS", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LoginConfigImpl, HTTP_USE_GLOBAL_CREDS)},
	{}
};

$MethodInfo _LoginConfigImpl_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/GSSCaller;Lorg/ietf/jgss/Oid;)V", nullptr, $PUBLIC, $method(static_cast<void(LoginConfigImpl::*)($GSSCaller*,$Oid*)>(&LoginConfigImpl::init$))},
	{"getAppConfigurationEntry", "(Ljava/lang/String;)[Ljavax/security/auth/login/AppConfigurationEntry;", nullptr, $PUBLIC},
	{"getDefaultConfigurationEntry", "()[Ljavax/security/auth/login/AppConfigurationEntry;", nullptr, $PRIVATE, $method(static_cast<$AppConfigurationEntryArray*(LoginConfigImpl::*)()>(&LoginConfigImpl::getDefaultConfigurationEntry))},
	{"isServerSide", "(Lsun/security/jgss/GSSCaller;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($GSSCaller*)>(&LoginConfigImpl::isServerSide))},
	{}
};

$InnerClassInfo _LoginConfigImpl_InnerClassesInfo_[] = {
	{"sun.security.jgss.LoginConfigImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LoginConfigImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.LoginConfigImpl",
	"javax.security.auth.login.Configuration",
	nullptr,
	_LoginConfigImpl_FieldInfo_,
	_LoginConfigImpl_MethodInfo_,
	nullptr,
	nullptr,
	_LoginConfigImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.LoginConfigImpl$1"
};

$Object* allocate$LoginConfigImpl($Class* clazz) {
	return $of($alloc(LoginConfigImpl));
}

$Debug* LoginConfigImpl::debug = nullptr;
bool LoginConfigImpl::HTTP_USE_GLOBAL_CREDS = false;

void LoginConfigImpl::init$($GSSCaller* caller, $Oid* mech) {
	$beforeCallerSensitive();
	$Configuration::init$();
	$set(this, caller, caller);
	$init($GSSUtil);
	if ($nc(mech)->equals($GSSUtil::GSS_KRB5_MECH_OID)) {
		$set(this, mechName, "krb5"_s);
	} else {
		$throwNew($IllegalArgumentException, $$str({$(mech->toString()), " not supported"_s}));
	}
	$set(this, config, $cast($Configuration, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LoginConfigImpl$1, this)))));
}

$AppConfigurationEntryArray* LoginConfigImpl::getAppConfigurationEntry($String* name) {
	$var($AppConfigurationEntryArray, entries, nullptr);
	if ("OTHER"_s->equalsIgnoreCase(name)) {
		return nullptr;
	}
	$var($StringArray, alts, nullptr);
	if ("krb5"_s->equals(this->mechName)) {
		$init($GSSCaller);
		if (this->caller == $GSSCaller::CALLER_INITIATE) {
			$assign(alts, $new($StringArray, {
				"com.sun.security.jgss.krb5.initiate"_s,
				"com.sun.security.jgss.initiate"_s
			}));
		} else {
			if (this->caller == $GSSCaller::CALLER_ACCEPT) {
				$assign(alts, $new($StringArray, {
					"com.sun.security.jgss.krb5.accept"_s,
					"com.sun.security.jgss.accept"_s
				}));
			} else if ($instanceOf($HttpCaller, this->caller)) {
				$assign(alts, $new($StringArray, {"com.sun.security.jgss.krb5.initiate"_s}));
			} else {
				if (this->caller == $GSSCaller::CALLER_UNKNOWN) {
					$throwNew($AssertionError, $of("caller not defined"_s));
				}
			}
		}
	} else {
		$throwNew($IllegalArgumentException, $$str({this->mechName, " not supported"_s}));
	}
	{
		$var($StringArray, arr$, alts);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, alt, arr$->get(i$));
			{
				$assign(entries, $nc(this->config)->getAppConfigurationEntry(alt));
				if (LoginConfigImpl::debug != nullptr) {
					$nc(LoginConfigImpl::debug)->println($$str({"Trying "_s, alt, ((entries == nullptr) ? ": does not exist."_s : ": Found!"_s)}));
				}
				if (entries != nullptr) {
					break;
				}
			}
		}
	}
	if (entries == nullptr) {
		if (LoginConfigImpl::debug != nullptr) {
			$nc(LoginConfigImpl::debug)->println("Cannot read JGSS entry, use default values instead."_s);
		}
		$assign(entries, getDefaultConfigurationEntry());
	}
	return entries;
}

$AppConfigurationEntryArray* LoginConfigImpl::getDefaultConfigurationEntry() {
	$var($HashMap, options, $new($HashMap, 2));
	if (this->mechName == nullptr || $nc(this->mechName)->equals("krb5"_s)) {
		if (isServerSide(this->caller)) {
			options->put("useKeyTab"_s, "true"_s);
			options->put("storeKey"_s, "true"_s);
			options->put("doNotPrompt"_s, "true"_s);
			options->put("principal"_s, "*"_s);
			options->put("isInitiator"_s, "false"_s);
		} else {
			if ($instanceOf($HttpCaller, this->caller) && !LoginConfigImpl::HTTP_USE_GLOBAL_CREDS) {
				options->put("useTicketCache"_s, "false"_s);
			} else {
				options->put("useTicketCache"_s, "true"_s);
			}
			options->put("doNotPrompt"_s, "false"_s);
		}
		$init($AppConfigurationEntry$LoginModuleControlFlag);
		return $new($AppConfigurationEntryArray, {$$new($AppConfigurationEntry, "com.sun.security.auth.module.Krb5LoginModule"_s, $AppConfigurationEntry$LoginModuleControlFlag::REQUIRED, options)});
	}
	return nullptr;
}

bool LoginConfigImpl::isServerSide($GSSCaller* caller) {
	$init(LoginConfigImpl);
	$init($GSSCaller);
	return $GSSCaller::CALLER_ACCEPT == caller;
}

void clinit$LoginConfigImpl($Class* class$) {
	$assignStatic(LoginConfigImpl::debug, $Debug::getInstance("gssloginconfig"_s, "\t[GSS LoginConfigImpl]"_s));
	{
		$var($String, prop, $GetPropertyAction::privilegedGetProperty("http.use.global.creds"_s));
		LoginConfigImpl::HTTP_USE_GLOBAL_CREDS = !"false"_s->equalsIgnoreCase(prop);
	}
}

LoginConfigImpl::LoginConfigImpl() {
}

$Class* LoginConfigImpl::load$($String* name, bool initialize) {
	$loadClass(LoginConfigImpl, name, initialize, &_LoginConfigImpl_ClassInfo_, clinit$LoginConfigImpl, allocate$LoginConfigImpl);
	return class$;
}

$Class* LoginConfigImpl::class$ = nullptr;

		} // jgss
	} // security
} // sun