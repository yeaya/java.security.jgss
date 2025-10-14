#include <sun/security/jgss/ProviderList$PreferencesEntry.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/ProviderList.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $Oid = ::org::ietf::jgss::Oid;
using $ProviderList = ::sun::security::jgss::ProviderList;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _ProviderList$PreferencesEntry_FieldInfo_[] = {
	{"p", "Ljava/security/Provider;", nullptr, $PRIVATE, $field(ProviderList$PreferencesEntry, p)},
	{"oid", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(ProviderList$PreferencesEntry, oid)},
	{}
};

$MethodInfo _ProviderList$PreferencesEntry_MethodInfo_[] = {
	{"<init>", "(Ljava/security/Provider;Lorg/ietf/jgss/Oid;)V", nullptr, 0, $method(static_cast<void(ProviderList$PreferencesEntry::*)($Provider*,$Oid*)>(&ProviderList$PreferencesEntry::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getOid", "()Lorg/ietf/jgss/Oid;", nullptr, 0, $method(static_cast<$Oid*(ProviderList$PreferencesEntry::*)()>(&ProviderList$PreferencesEntry::getOid))},
	{"getProvider", "()Ljava/security/Provider;", nullptr, 0, $method(static_cast<$Provider*(ProviderList$PreferencesEntry::*)()>(&ProviderList$PreferencesEntry::getProvider))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"implies", "(Ljava/lang/Object;)Z", nullptr, 0, $method(static_cast<bool(ProviderList$PreferencesEntry::*)(Object$*)>(&ProviderList$PreferencesEntry::implies))},
	{"impliesMechanism", "(Lorg/ietf/jgss/Oid;)Z", nullptr, 0, $method(static_cast<bool(ProviderList$PreferencesEntry::*)($Oid*)>(&ProviderList$PreferencesEntry::impliesMechanism))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ProviderList$PreferencesEntry_InnerClassesInfo_[] = {
	{"sun.security.jgss.ProviderList$PreferencesEntry", "sun.security.jgss.ProviderList", "PreferencesEntry", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ProviderList$PreferencesEntry_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.jgss.ProviderList$PreferencesEntry",
	"java.lang.Object",
	nullptr,
	_ProviderList$PreferencesEntry_FieldInfo_,
	_ProviderList$PreferencesEntry_MethodInfo_,
	nullptr,
	nullptr,
	_ProviderList$PreferencesEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.ProviderList"
};

$Object* allocate$ProviderList$PreferencesEntry($Class* clazz) {
	return $of($alloc(ProviderList$PreferencesEntry));
}

void ProviderList$PreferencesEntry::init$($Provider* p, $Oid* oid) {
	$set(this, p, p);
	$set(this, oid, oid);
}

bool ProviderList$PreferencesEntry::equals(Object$* other) {
	if ($equals(this, other)) {
		return true;
	}
	if (!($instanceOf(ProviderList$PreferencesEntry, other))) {
		return false;
	}
	$var(ProviderList$PreferencesEntry, that, $cast(ProviderList$PreferencesEntry, other));
	if ($nc($($nc(this->p)->getName()))->equals($($nc($nc(that)->p)->getName()))) {
		if (this->oid != nullptr && $nc(that)->oid != nullptr) {
			return $nc(this->oid)->equals(that->oid);
		} else {
			return (this->oid == nullptr && that->oid == nullptr);
		}
	}
	return false;
}

int32_t ProviderList$PreferencesEntry::hashCode() {
	int32_t result = 17;
	result = 37 * result + $nc($($nc(this->p)->getName()))->hashCode();
	if (this->oid != nullptr) {
		result = 37 * result + $nc(this->oid)->hashCode();
	}
	return result;
}

bool ProviderList$PreferencesEntry::implies(Object$* other) {
	if ($instanceOf(ProviderList$PreferencesEntry, other)) {
		$var(ProviderList$PreferencesEntry, temp, $cast(ProviderList$PreferencesEntry, other));
		bool var$0 = equals(temp);
		return (var$0 || $nc($($nc(this->p)->getName()))->equals($($nc($nc(temp)->p)->getName())) && this->oid == nullptr);
	} else {
		return false;
	}
}

$Provider* ProviderList$PreferencesEntry::getProvider() {
	return this->p;
}

$Oid* ProviderList$PreferencesEntry::getOid() {
	return this->oid;
}

bool ProviderList$PreferencesEntry::impliesMechanism($Oid* oid) {
	return (this->oid == nullptr || $nc(this->oid)->equals(oid));
}

$String* ProviderList$PreferencesEntry::toString() {
	$var($StringBuilder, sb, $new($StringBuilder, "<"_s));
	sb->append($($nc(this->p)->getName()));
	sb->append(", "_s);
	sb->append($of(this->oid));
	sb->append(">"_s);
	return sb->toString();
}

ProviderList$PreferencesEntry::ProviderList$PreferencesEntry() {
}

$Class* ProviderList$PreferencesEntry::load$($String* name, bool initialize) {
	$loadClass(ProviderList$PreferencesEntry, name, initialize, &_ProviderList$PreferencesEntry_ClassInfo_, allocate$ProviderList$PreferencesEntry);
	return class$;
}

$Class* ProviderList$PreferencesEntry::class$ = nullptr;

		} // jgss
	} // security
} // sun