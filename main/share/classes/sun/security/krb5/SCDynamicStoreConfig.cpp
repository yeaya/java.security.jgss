#include <sun/security/krb5/SCDynamicStoreConfig.h>

#include <java/io/IOException.h>
#include <java/io/PrintStream.h>
#include <java/lang/Boolean.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Hashtable.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Vector.h>
#include <sun/security/krb5/SCDynamicStoreConfig$1.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <jcpp.h>

#undef DEBUG

using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Hashtable = ::java::util::Hashtable;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Vector = ::java::util::Vector;
using $SCDynamicStoreConfig$1 = ::sun::security::krb5::SCDynamicStoreConfig$1;
using $Krb5 = ::sun::security::krb5::internal::Krb5;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _SCDynamicStoreConfig_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(SCDynamicStoreConfig, DEBUG)},
	{}
};

$MethodInfo _SCDynamicStoreConfig_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SCDynamicStoreConfig::*)()>(&SCDynamicStoreConfig::init$))},
	{"getConfig", "()Ljava/util/Hashtable;", "()Ljava/util/Hashtable<Ljava/lang/String;Ljava/lang/Object;>;", $PUBLIC | $STATIC, $method(static_cast<$Hashtable*(*)()>(&SCDynamicStoreConfig::getConfig)), "java.io.IOException"},
	{"getKerberosConfig", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC | $NATIVE, $method(static_cast<$List*(*)()>(&SCDynamicStoreConfig::getKerberosConfig))},
	{"installNotificationCallback", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $method(static_cast<void(*)()>(&SCDynamicStoreConfig::installNotificationCallback))},
	{"v1", "(Ljava/lang/String;)Ljava/util/Vector;", "(Ljava/lang/String;)Ljava/util/Vector<Ljava/lang/String;>;", $PRIVATE | $STATIC, $method(static_cast<$Vector*(*)($String*)>(&SCDynamicStoreConfig::v1))},
	{}
};

#define _METHOD_INDEX_getKerberosConfig 2
#define _METHOD_INDEX_installNotificationCallback 3

$InnerClassInfo _SCDynamicStoreConfig_InnerClassesInfo_[] = {
	{"sun.security.krb5.SCDynamicStoreConfig$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SCDynamicStoreConfig_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.SCDynamicStoreConfig",
	"java.lang.Object",
	nullptr,
	_SCDynamicStoreConfig_FieldInfo_,
	_SCDynamicStoreConfig_MethodInfo_,
	nullptr,
	nullptr,
	_SCDynamicStoreConfig_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.SCDynamicStoreConfig$1"
};

$Object* allocate$SCDynamicStoreConfig($Class* clazz) {
	return $of($alloc(SCDynamicStoreConfig));
}

bool SCDynamicStoreConfig::DEBUG = false;

void SCDynamicStoreConfig::init$() {
}

void SCDynamicStoreConfig::installNotificationCallback() {
	$init(SCDynamicStoreConfig);
	$prepareNativeStatic(SCDynamicStoreConfig, installNotificationCallback, void);
	$invokeNativeStatic(SCDynamicStoreConfig, installNotificationCallback);
	$finishNativeStatic();
}

$List* SCDynamicStoreConfig::getKerberosConfig() {
	$init(SCDynamicStoreConfig);
	$var($List, $ret, nullptr);
	$prepareNativeStatic(SCDynamicStoreConfig, getKerberosConfig, $List*);
	$assign($ret, $invokeNativeStatic(SCDynamicStoreConfig, getKerberosConfig));
	$finishNativeStatic();
	return $ret;
}

$Hashtable* SCDynamicStoreConfig::getConfig() {
	$init(SCDynamicStoreConfig);
	$var($List, list, getKerberosConfig());
	if (list == nullptr) {
		$throwNew($IOException, "Could not load configuration from SCDynamicStore"_s);
	}
	if (SCDynamicStoreConfig::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"Raw map from JNI: "_s, list}));
	}
	$var($Hashtable, v, $new($Hashtable));
	$var($Hashtable, realms, $new($Hashtable));
	$var($Iterator, iterator, $nc(list)->iterator());
	$var($String, defaultRealm, nullptr);
	while (true) {
		$var($String, nextRealm, $cast($String, $nc(iterator)->next()));
		if (nextRealm == nullptr) {
			break;
		}
		if (defaultRealm == nullptr) {
			$assign(defaultRealm, nextRealm);
			$var($Hashtable, dr, $new($Hashtable));
			dr->put("default_realm"_s, $(v1(defaultRealm)));
			v->put("libdefaults"_s, dr);
		}
		$var($Vector, kdcs, $new($Vector));
		while (true) {
			$var($String, nextKdc, $cast($String, iterator->next()));
			if (nextKdc == nullptr) {
				break;
			}
			kdcs->add(nextKdc);
		}
		if (!kdcs->isEmpty()) {
			$var($Hashtable, ri, $new($Hashtable));
			ri->put("kdc"_s, kdcs);
			realms->put(nextRealm, ri);
		}
	}
	if (!realms->isEmpty()) {
		v->put("realms"_s, realms);
	}
	$var($Hashtable, mapping, $new($Hashtable));
	while (true) {
		if (!$nc(iterator)->hasNext()) {
			break;
		}
		$var($Object, var$0, $cast($String, $nc(iterator)->next()));
		mapping->put(var$0, $(v1($cast($String, $(iterator->next())))));
	}
	if (!mapping->isEmpty()) {
		v->put("domain_realm"_s, mapping);
	}
	return v;
}

$Vector* SCDynamicStoreConfig::v1($String* s) {
	$init(SCDynamicStoreConfig);
	$var($Vector, out, $new($Vector));
	out->add(s);
	return out;
}

void clinit$SCDynamicStoreConfig($Class* class$) {
	$beforeCallerSensitive();
	$init($Krb5);
	SCDynamicStoreConfig::DEBUG = $Krb5::DEBUG;
	{
		bool isMac = $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SCDynamicStoreConfig$1)))))))->booleanValue();
		if (isMac) {
			SCDynamicStoreConfig::installNotificationCallback();
		}
	}
}

SCDynamicStoreConfig::SCDynamicStoreConfig() {
}

$Class* SCDynamicStoreConfig::load$($String* name, bool initialize) {
	$loadClass(SCDynamicStoreConfig, name, initialize, &_SCDynamicStoreConfig_ClassInfo_, clinit$SCDynamicStoreConfig, allocate$SCDynamicStoreConfig);
	return class$;
}

$Class* SCDynamicStoreConfig::class$ = nullptr;

		} // krb5
	} // security
} // sun