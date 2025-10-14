#include <javax/security/auth/kerberos/DelegationPermission.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/StringTokenizer.h>
#include <javax/security/auth/kerberos/KrbDelegationPermissionCollection.h>
#include <jcpp.h>

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $StringTokenizer = ::java::util::StringTokenizer;
using $KrbDelegationPermissionCollection = ::javax::security::auth::kerberos::KrbDelegationPermissionCollection;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _DelegationPermission_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DelegationPermission, serialVersionUID)},
	{"subordinate", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(DelegationPermission, subordinate)},
	{"service", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(DelegationPermission, service)},
	{}
};

$MethodInfo _DelegationPermission_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(DelegationPermission::*)($String*)>(&DelegationPermission::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(DelegationPermission::*)($String*,$String*)>(&DelegationPermission::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"implies", "(Ljava/security/Permission;)Z", nullptr, $PUBLIC},
	{"init", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(DelegationPermission::*)($String*)>(&DelegationPermission::init))},
	{"newPermissionCollection", "()Ljava/security/PermissionCollection;", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<void(DelegationPermission::*)($ObjectInputStream*)>(&DelegationPermission::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<void(DelegationPermission::*)($ObjectOutputStream*)>(&DelegationPermission::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _DelegationPermission_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"javax.security.auth.kerberos.DelegationPermission",
	"java.security.BasicPermission",
	nullptr,
	_DelegationPermission_FieldInfo_,
	_DelegationPermission_MethodInfo_
};

$Object* allocate$DelegationPermission($Class* clazz) {
	return $of($alloc(DelegationPermission));
}

void DelegationPermission::init$($String* principals) {
	$BasicPermission::init$(principals);
	init(principals);
}

void DelegationPermission::init$($String* principals, $String* actions) {
	$BasicPermission::init$(principals, actions);
	init(principals);
}

void DelegationPermission::init($String* target) {
	$var($StringTokenizer, t, $new($StringTokenizer, target, "\""_s, true));
	try {
		if (!$nc($(t->nextToken()))->equals("\""_s)) {
			$throwNew($IllegalArgumentException, $$str({"Illegal input ["_s, target, "]: improperly quoted"_s}));
		}
		$set(this, subordinate, t->nextToken());
		if ($nc(this->subordinate)->equals("\""_s)) {
			$throwNew($IllegalArgumentException, $$str({"Illegal input ["_s, target, "]: bad subordinate name"_s}));
		}
		t->nextToken();
		if (!$($nc($(t->nextToken()))->trim())->isEmpty()) {
			$throwNew($IllegalArgumentException, $$str({"Illegal input ["_s, target, "]: improperly separated"_s}));
		}
		t->nextToken();
		$set(this, service, t->nextToken());
		if ($nc(this->service)->equals("\""_s)) {
			$throwNew($IllegalArgumentException, $$str({"Illegal input ["_s, target, "]: bad service name"_s}));
		}
		t->nextToken();
	} catch ($NoSuchElementException&) {
		$var($NoSuchElementException, e, $catch());
		$throwNew($IllegalArgumentException, $$str({"Illegal input ["_s, target, "]: not enough input"_s}));
	}
	if (t->hasMoreTokens()) {
		$throwNew($IllegalArgumentException, $$str({"Illegal input ["_s, target, "]: extra input"_s}));
	}
}

bool DelegationPermission::implies($Permission* p) {
	return equals(p);
}

bool DelegationPermission::equals(Object$* obj) {
	if ($equals(obj, this)) {
		return true;
	}
	if (!($instanceOf(DelegationPermission, obj))) {
		return false;
	}
	$var(DelegationPermission, that, $cast(DelegationPermission, obj));
	bool var$0 = $nc(this->subordinate)->equals($nc(that)->subordinate);
	return var$0 && $nc(this->service)->equals($nc(that)->service);
}

int32_t DelegationPermission::hashCode() {
	int32_t var$0 = 17 * $nc(this->subordinate)->hashCode();
	return var$0 + 31 * $nc(this->service)->hashCode();
}

$PermissionCollection* DelegationPermission::newPermissionCollection() {
	return $new($KrbDelegationPermissionCollection);
}

void DelegationPermission::writeObject($ObjectOutputStream* s) {
	$synchronized(this) {
		$nc(s)->defaultWriteObject();
	}
}

void DelegationPermission::readObject($ObjectInputStream* s) {
	$synchronized(this) {
		$nc(s)->defaultReadObject();
		init($(getName()));
	}
}

DelegationPermission::DelegationPermission() {
}

$Class* DelegationPermission::load$($String* name, bool initialize) {
	$loadClass(DelegationPermission, name, initialize, &_DelegationPermission_ClassInfo_, allocate$DelegationPermission);
	return class$;
}

$Class* DelegationPermission::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax