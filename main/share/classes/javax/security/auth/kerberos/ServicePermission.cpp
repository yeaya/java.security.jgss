#include <javax/security/auth/kerberos/ServicePermission.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <javax/security/auth/kerberos/KrbServicePermissionCollection.h>
#include <jcpp.h>

#undef ACCEPT
#undef ALL
#undef INITIATE
#undef NONE

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $KrbServicePermissionCollection = ::javax::security::auth::kerberos::KrbServicePermissionCollection;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _ServicePermission_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServicePermission, serialVersionUID)},
	{"INITIATE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServicePermission, INITIATE)},
	{"ACCEPT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServicePermission, ACCEPT)},
	{"ALL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServicePermission, ALL)},
	{"NONE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServicePermission, NONE)},
	{"mask", "I", nullptr, $PRIVATE | $TRANSIENT, $field(ServicePermission, mask)},
	{"actions", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ServicePermission, actions)},
	{}
};

$MethodInfo _ServicePermission_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ServicePermission::*)($String*,$String*)>(&ServicePermission::init$))},
	{"<init>", "(Ljava/lang/String;I)V", nullptr, 0, $method(static_cast<void(ServicePermission::*)($String*,int32_t)>(&ServicePermission::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getActions", "(I)Ljava/lang/String;", nullptr, $STATIC, $method(static_cast<$String*(*)(int32_t)>(&ServicePermission::getActions))},
	{"getActions", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getMask", "()I", nullptr, 0, $method(static_cast<int32_t(ServicePermission::*)()>(&ServicePermission::getMask))},
	{"getMask", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $method(static_cast<int32_t(*)($String*)>(&ServicePermission::getMask))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"implies", "(Ljava/security/Permission;)Z", nullptr, $PUBLIC},
	{"impliesIgnoreMask", "(Ljavax/security/auth/kerberos/ServicePermission;)Z", nullptr, 0, $method(static_cast<bool(ServicePermission::*)(ServicePermission*)>(&ServicePermission::impliesIgnoreMask))},
	{"init", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(static_cast<void(ServicePermission::*)($String*,int32_t)>(&ServicePermission::init))},
	{"newPermissionCollection", "()Ljava/security/PermissionCollection;", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(ServicePermission::*)($ObjectInputStream*)>(&ServicePermission::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(ServicePermission::*)($ObjectOutputStream*)>(&ServicePermission::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _ServicePermission_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"javax.security.auth.kerberos.ServicePermission",
	"java.security.Permission",
	nullptr,
	_ServicePermission_FieldInfo_,
	_ServicePermission_MethodInfo_
};

$Object* allocate$ServicePermission($Class* clazz) {
	return $of($alloc(ServicePermission));
}

void ServicePermission::init$($String* servicePrincipal, $String* action) {
	$Permission::init$(servicePrincipal);
	init(servicePrincipal, getMask(action));
}

void ServicePermission::init$($String* servicePrincipal, int32_t mask) {
	$Permission::init$(servicePrincipal);
	init(servicePrincipal, mask);
}

void ServicePermission::init($String* servicePrincipal, int32_t mask) {
	if (servicePrincipal == nullptr) {
		$throwNew($NullPointerException, "service principal can\'t be null"_s);
	}
	if (((int32_t)(mask & (uint32_t)ServicePermission::ALL)) != mask) {
		$throwNew($IllegalArgumentException, "invalid actions mask"_s);
	}
	this->mask = mask;
}

bool ServicePermission::implies($Permission* p) {
	if (!($instanceOf(ServicePermission, p))) {
		return false;
	}
	$var(ServicePermission, that, $cast(ServicePermission, p));
	return (((int32_t)(this->mask & (uint32_t)$nc(that)->mask)) == that->mask) && impliesIgnoreMask(that);
}

bool ServicePermission::impliesIgnoreMask(ServicePermission* p) {
	bool var$1 = ($nc($(this->getName()))->equals("*"_s));
	bool var$0 = var$1 || $nc($(this->getName()))->equals($($nc(p)->getName()));
	if (!var$0) {
		bool var$2 = $nc($($nc(p)->getName()))->startsWith("@"_s);
		var$0 = (var$2 && $nc($(this->getName()))->endsWith($(p->getName())));
	}
	return (var$0);
}

bool ServicePermission::equals(Object$* obj) {
	if ($equals(obj, this)) {
		return true;
	}
	if (!($instanceOf(ServicePermission, obj))) {
		return false;
	}
	$var(ServicePermission, that, $cast(ServicePermission, obj));
	return (this->mask == $nc(that)->mask) && $nc($(this->getName()))->equals($(that->getName()));
}

int32_t ServicePermission::hashCode() {
	return ($nc($(getName()))->hashCode() ^ this->mask);
}

$String* ServicePermission::getActions(int32_t mask) {
	$init(ServicePermission);
	$var($StringBuilder, sb, $new($StringBuilder));
	bool comma = false;
	if (((int32_t)(mask & (uint32_t)ServicePermission::INITIATE)) == ServicePermission::INITIATE) {
		if (comma) {
			sb->append(u',');
		} else {
			comma = true;
		}
		sb->append("initiate"_s);
	}
	if (((int32_t)(mask & (uint32_t)ServicePermission::ACCEPT)) == ServicePermission::ACCEPT) {
		if (comma) {
			sb->append(u',');
		} else {
			comma = true;
		}
		sb->append("accept"_s);
	}
	return sb->toString();
}

$String* ServicePermission::getActions() {
	if (this->actions == nullptr) {
		$set(this, actions, getActions(this->mask));
	}
	return this->actions;
}

$PermissionCollection* ServicePermission::newPermissionCollection() {
	return $new($KrbServicePermissionCollection);
}

int32_t ServicePermission::getMask() {
	return this->mask;
}

int32_t ServicePermission::getMask($String* action) {
	$init(ServicePermission);
	if (action == nullptr) {
		$throwNew($NullPointerException, "action can\'t be null"_s);
	}
	if ($nc(action)->equals(""_s)) {
		$throwNew($IllegalArgumentException, "action can\'t be empty"_s);
	}
	int32_t mask = ServicePermission::NONE;
	$var($chars, a, $nc(action)->toCharArray());
	if (a->length == 1 && a->get(0) == u'-') {
		return mask;
	}
	int32_t i = a->length - 1;
	while (i != -1) {
		char16_t c = 0;
		while (true) {
			bool var$0 = (i != -1);
			if (var$0) {
				bool var$4 = (c = a->get(i)) == u' ';
				bool var$3 = var$4 || c == u'\r';
				bool var$2 = var$3 || c == u'\n';
				bool var$1 = var$2 || c == u'\f';
				var$0 = (var$1 || c == u'\t');
			}
			if (!(var$0)) {
				break;
			}
			{
				--i;
			}
		}
		int32_t matchlen = 0;
		if (i >= 7 && (a->get(i - 7) == u'i' || a->get(i - 7) == u'I') && (a->get(i - 6) == u'n' || a->get(i - 6) == u'N') && (a->get(i - 5) == u'i' || a->get(i - 5) == u'I') && (a->get(i - 4) == u't' || a->get(i - 4) == u'T') && (a->get(i - 3) == u'i' || a->get(i - 3) == u'I') && (a->get(i - 2) == u'a' || a->get(i - 2) == u'A') && (a->get(i - 1) == u't' || a->get(i - 1) == u'T') && (a->get(i) == u'e' || a->get(i) == u'E')) {
			matchlen = 8;
			mask |= ServicePermission::INITIATE;
		} else if (i >= 5 && (a->get(i - 5) == u'a' || a->get(i - 5) == u'A') && (a->get(i - 4) == u'c' || a->get(i - 4) == u'C') && (a->get(i - 3) == u'c' || a->get(i - 3) == u'C') && (a->get(i - 2) == u'e' || a->get(i - 2) == u'E') && (a->get(i - 1) == u'p' || a->get(i - 1) == u'P') && (a->get(i) == u't' || a->get(i) == u'T')) {
			matchlen = 6;
			mask |= ServicePermission::ACCEPT;
		} else {
			$throwNew($IllegalArgumentException, $$str({"invalid permission: "_s, action}));
		}
		bool seencomma = false;
		while (i >= matchlen && !seencomma) {
			switch (a->get(i - matchlen)) {
			case u',':
				{
					seencomma = true;
					break;
				}
			case u' ':
				{}
			case u'\r':
				{}
			case u'\n':
				{}
			case u'\f':
				{}
			case u'\t':
				{
					break;
				}
			default:
				{
					$throwNew($IllegalArgumentException, $$str({"invalid permission: "_s, action}));
				}
			}
			--i;
		}
		i -= matchlen;
	}
	return mask;
}

void ServicePermission::writeObject($ObjectOutputStream* s) {
	if (this->actions == nullptr) {
		getActions();
	}
	$nc(s)->defaultWriteObject();
}

void ServicePermission::readObject($ObjectInputStream* s) {
	$nc(s)->defaultReadObject();
	$var($String, var$0, getName());
	init(var$0, getMask(this->actions));
}

ServicePermission::ServicePermission() {
}

$Class* ServicePermission::load$($String* name, bool initialize) {
	$loadClass(ServicePermission, name, initialize, &_ServicePermission_ClassInfo_, allocate$ServicePermission);
	return class$;
}

$Class* ServicePermission::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax