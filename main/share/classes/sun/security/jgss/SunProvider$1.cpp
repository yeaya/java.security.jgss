#include <sun/security/jgss/SunProvider$1.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <sun/security/jgss/SunProvider$ProviderService.h>
#include <sun/security/jgss/SunProvider.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $SunProvider = ::sun::security::jgss::SunProvider;
using $SunProvider$ProviderService = ::sun::security::jgss::SunProvider$ProviderService;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _SunProvider$1_FieldInfo_[] = {
	{"this$0", "Lsun/security/jgss/SunProvider;", nullptr, $FINAL | $SYNTHETIC, $field(SunProvider$1, this$0)},
	{"val$p", "Ljava/security/Provider;", nullptr, $FINAL | $SYNTHETIC, $field(SunProvider$1, val$p)},
	{}
};

$MethodInfo _SunProvider$1_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/SunProvider;Ljava/security/Provider;)V", "()V", 0, $method(static_cast<void(SunProvider$1::*)($SunProvider*,$Provider*)>(&SunProvider$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _SunProvider$1_EnclosingMethodInfo_ = {
	"sun.security.jgss.SunProvider",
	"<init>",
	"()V"
};

$InnerClassInfo _SunProvider$1_InnerClassesInfo_[] = {
	{"sun.security.jgss.SunProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SunProvider$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.SunProvider$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_SunProvider$1_FieldInfo_,
	_SunProvider$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_SunProvider$1_EnclosingMethodInfo_,
	_SunProvider$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.SunProvider"
};

$Object* allocate$SunProvider$1($Class* clazz) {
	return $of($alloc(SunProvider$1));
}

void SunProvider$1::init$($SunProvider* this$0, $Provider* val$p) {
	$set(this, this$0, this$0);
	$set(this, val$p, val$p);
}

$Object* SunProvider$1::run() {
	$SunProvider::access$000(this->this$0, $$new($SunProvider$ProviderService, this->val$p, "GssApiMechanism"_s, "1.2.840.113554.1.2.2"_s, "sun.security.jgss.krb5.Krb5MechFactory"_s));
	$SunProvider::access$100(this->this$0, $$new($SunProvider$ProviderService, this->val$p, "GssApiMechanism"_s, "1.3.6.1.5.5.2"_s, "sun.security.jgss.spnego.SpNegoMechFactory"_s));
	return $of(nullptr);
}

SunProvider$1::SunProvider$1() {
}

$Class* SunProvider$1::load$($String* name, bool initialize) {
	$loadClass(SunProvider$1, name, initialize, &_SunProvider$1_ClassInfo_, allocate$SunProvider$1);
	return class$;
}

$Class* SunProvider$1::class$ = nullptr;

		} // jgss
	} // security
} // sun