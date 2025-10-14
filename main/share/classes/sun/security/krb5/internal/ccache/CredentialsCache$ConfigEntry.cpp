#include <sun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry.h>

#include <java/lang/Array.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/RealmException.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $RealmException = ::sun::security::krb5::RealmException;
using $CredentialsCache = ::sun::security::krb5::internal::ccache::CredentialsCache;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$FieldInfo _CredentialsCache$ConfigEntry_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(CredentialsCache$ConfigEntry, name)},
	{"princ", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE | $FINAL, $field(CredentialsCache$ConfigEntry, princ)},
	{"data", "[B", nullptr, $PRIVATE | $FINAL, $field(CredentialsCache$ConfigEntry, data)},
	{}
};

$MethodInfo _CredentialsCache$ConfigEntry_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Lsun/security/krb5/PrincipalName;[B)V", nullptr, $PUBLIC, $method(static_cast<void(CredentialsCache$ConfigEntry::*)($String*,$PrincipalName*,$bytes*)>(&CredentialsCache$ConfigEntry::init$))},
	{"getData", "()[B", nullptr, $PUBLIC},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getPrinc", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC},
	{"getSName", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _CredentialsCache$ConfigEntry_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ccache.CredentialsCache$ConfigEntry", "sun.security.krb5.internal.ccache.CredentialsCache", "ConfigEntry", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _CredentialsCache$ConfigEntry_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ccache.CredentialsCache$ConfigEntry",
	"java.lang.Object",
	nullptr,
	_CredentialsCache$ConfigEntry_FieldInfo_,
	_CredentialsCache$ConfigEntry_MethodInfo_,
	nullptr,
	nullptr,
	_CredentialsCache$ConfigEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ccache.CredentialsCache"
};

$Object* allocate$CredentialsCache$ConfigEntry($Class* clazz) {
	return $of($alloc(CredentialsCache$ConfigEntry));
}

void CredentialsCache$ConfigEntry::init$($String* name, $PrincipalName* princ, $bytes* data) {
	$set(this, name, name);
	$set(this, princ, princ);
	$set(this, data, data);
}

$String* CredentialsCache$ConfigEntry::getName() {
	return this->name;
}

$PrincipalName* CredentialsCache$ConfigEntry::getPrinc() {
	return this->princ;
}

$bytes* CredentialsCache$ConfigEntry::getData() {
	return this->data;
}

$String* CredentialsCache$ConfigEntry::toString() {
	$var($String, var$0, $$str({this->name, (this->princ != nullptr ? ($$str({"."_s, this->princ})) : ""_s), ": "_s}));
	return $concat(var$0, $$new($String, this->data));
}

$PrincipalName* CredentialsCache$ConfigEntry::getSName() {
	try {
		return $new($PrincipalName, $$str({"krb5_ccache_conf_data/"_s, this->name, (this->princ != nullptr ? ($$str({"/"_s, this->princ})) : ""_s), "@X-CACHECONF:"_s}));
	} catch ($RealmException&) {
		$var($RealmException, e, $catch());
		$throwNew($AssertionError, $of(e));
	}
	$shouldNotReachHere();
}

CredentialsCache$ConfigEntry::CredentialsCache$ConfigEntry() {
}

$Class* CredentialsCache$ConfigEntry::load$($String* name, bool initialize) {
	$loadClass(CredentialsCache$ConfigEntry, name, initialize, &_CredentialsCache$ConfigEntry_ClassInfo_, allocate$CredentialsCache$ConfigEntry);
	return class$;
}

$Class* CredentialsCache$ConfigEntry::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun