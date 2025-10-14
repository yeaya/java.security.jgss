#include <javax/security/auth/kerberos/KrbServicePermissionCollection.h>

#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamField.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/SecurityException.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/util/Collection.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/Vector.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/BiFunction.h>
#include <javax/security/auth/kerberos/KrbServicePermissionCollection$1.h>
#include <javax/security/auth/kerberos/ServicePermission.h>
#include <jcpp.h>

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Collection = ::java::util::Collection;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $Vector = ::java::util::Vector;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $BiFunction = ::java::util::function::BiFunction;
using $KrbServicePermissionCollection$1 = ::javax::security::auth::kerberos::KrbServicePermissionCollection$1;
using $ServicePermission = ::javax::security::auth::kerberos::ServicePermission;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _KrbServicePermissionCollection_FieldInfo_[] = {
	{"perms", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/security/Permission;>;", $PRIVATE | $TRANSIENT, $field(KrbServicePermissionCollection, perms)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KrbServicePermissionCollection, serialVersionUID)},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KrbServicePermissionCollection, serialPersistentFields)},
	{}
};

$MethodInfo _KrbServicePermissionCollection_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(KrbServicePermissionCollection::*)()>(&KrbServicePermissionCollection::init$))},
	{"add", "(Ljava/security/Permission;)V", nullptr, $PUBLIC},
	{"elements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/security/Permission;>;", $PUBLIC},
	{"implies", "(Ljava/security/Permission;)Z", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbServicePermissionCollection::*)($ObjectInputStream*)>(&KrbServicePermissionCollection::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbServicePermissionCollection::*)($ObjectOutputStream*)>(&KrbServicePermissionCollection::writeObject)), "java.io.IOException"},
	{}
};

$InnerClassInfo _KrbServicePermissionCollection_InnerClassesInfo_[] = {
	{"javax.security.auth.kerberos.KrbServicePermissionCollection$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _KrbServicePermissionCollection_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"javax.security.auth.kerberos.KrbServicePermissionCollection",
	"java.security.PermissionCollection",
	nullptr,
	_KrbServicePermissionCollection_FieldInfo_,
	_KrbServicePermissionCollection_MethodInfo_,
	nullptr,
	nullptr,
	_KrbServicePermissionCollection_InnerClassesInfo_,
	nullptr,
	nullptr,
	"javax.security.auth.kerberos.KrbServicePermissionCollection$1"
};

$Object* allocate$KrbServicePermissionCollection($Class* clazz) {
	return $of($alloc(KrbServicePermissionCollection));
}


$ObjectStreamFieldArray* KrbServicePermissionCollection::serialPersistentFields = nullptr;

void KrbServicePermissionCollection::init$() {
	$PermissionCollection::init$();
	$set(this, perms, $new($ConcurrentHashMap));
}

bool KrbServicePermissionCollection::implies($Permission* permission) {
	if (!($instanceOf($ServicePermission, permission))) {
		return false;
	}
	$var($ServicePermission, np, $cast($ServicePermission, permission));
	int32_t desired = $nc(np)->getMask();
	if (desired == 0) {
		{
			$var($Iterator, i$, $nc($($nc(this->perms)->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Permission, p, $cast($Permission, i$->next()));
				{
					$var($ServicePermission, sp, $cast($ServicePermission, p));
					if ($nc(sp)->impliesIgnoreMask(np)) {
						return true;
					}
				}
			}
		}
		return false;
	}
	$var($ServicePermission, x, $cast($ServicePermission, $nc(this->perms)->get("*"_s)));
	if (x != nullptr) {
		if (((int32_t)(x->getMask() & (uint32_t)desired)) == desired) {
			return true;
		}
	}
	$assign(x, $cast($ServicePermission, $nc(this->perms)->get($(np->getName()))));
	if (x != nullptr) {
		if (((int32_t)(x->getMask() & (uint32_t)desired)) == desired) {
			return true;
		}
	}
	return false;
}

void KrbServicePermissionCollection::add($Permission* permission) {
	if (!($instanceOf($ServicePermission, permission))) {
		$throwNew($IllegalArgumentException, $$str({"invalid permission: "_s, permission}));
	}
	if (isReadOnly()) {
		$throwNew($SecurityException, "attempt to add a Permission to a readonly PermissionCollection"_s);
	}
	$var($ServicePermission, sp, $cast($ServicePermission, permission));
	$var($String, princName, $nc(sp)->getName());
	$nc(this->perms)->merge(princName, sp, $$new($KrbServicePermissionCollection$1, this, princName));
}

$Enumeration* KrbServicePermissionCollection::elements() {
	return $nc(this->perms)->elements();
}

void KrbServicePermissionCollection::writeObject($ObjectOutputStream* out) {
	$var($Vector, permissions, $new($Vector, $($nc(this->perms)->values())));
	$var($ObjectOutputStream$PutField, pfields, $nc(out)->putFields());
	$nc(pfields)->put("permissions"_s, $of(permissions));
	out->writeFields();
}

void KrbServicePermissionCollection::readObject($ObjectInputStream* in) {
	$var($ObjectInputStream$GetField, gfields, $nc(in)->readFields());
	$var($Vector, permissions, $cast($Vector, $nc(gfields)->get("permissions"_s, ($Object*)nullptr)));
	$set(this, perms, $new($ConcurrentHashMap, $nc(permissions)->size()));
	{
		$var($Iterator, i$, $nc(permissions)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Permission, perm, $cast($Permission, i$->next()));
			{
				$nc(this->perms)->put($($nc(perm)->getName()), perm);
			}
		}
	}
}

void clinit$KrbServicePermissionCollection($Class* class$) {
	$load($Vector);
	$assignStatic(KrbServicePermissionCollection::serialPersistentFields, $new($ObjectStreamFieldArray, {$$new($ObjectStreamField, "permissions"_s, $Vector::class$)}));
}

KrbServicePermissionCollection::KrbServicePermissionCollection() {
}

$Class* KrbServicePermissionCollection::load$($String* name, bool initialize) {
	$loadClass(KrbServicePermissionCollection, name, initialize, &_KrbServicePermissionCollection_ClassInfo_, clinit$KrbServicePermissionCollection, allocate$KrbServicePermissionCollection);
	return class$;
}

$Class* KrbServicePermissionCollection::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax