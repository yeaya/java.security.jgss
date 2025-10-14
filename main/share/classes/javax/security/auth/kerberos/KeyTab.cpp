#include <javax/security/auth/kerberos/KeyTab.h>

#include <java/io/File.h>
#include <java/lang/Array.h>
#include <java/lang/Boolean.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/StackTraceElement.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/AccessControlException.h>
#include <java/util/Objects.h>
#include <javax/security/auth/kerberos/JavaxSecurityAuthKerberosAccessImpl.h>
#include <javax/security/auth/kerberos/KerberosKey.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/JavaxSecurityAuthKerberosAccess.h>
#include <sun/security/krb5/KerberosSecrets.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/RealmException.h>
#include <sun/security/krb5/internal/ktab/KeyTab.h>
#include <jcpp.h>

using $StackTraceElementArray = $Array<::java::lang::StackTraceElement>;
using $KerberosKeyArray = $Array<::javax::security::auth::kerberos::KerberosKey>;
using $EncryptionKeyArray = $Array<::sun::security::krb5::EncryptionKey>;
using $File = ::java::io::File;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AccessControlException = ::java::security::AccessControlException;
using $Objects = ::java::util::Objects;
using $JavaxSecurityAuthKerberosAccessImpl = ::javax::security::auth::kerberos::JavaxSecurityAuthKerberosAccessImpl;
using $KerberosKey = ::javax::security::auth::kerberos::KerberosKey;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $JavaxSecurityAuthKerberosAccess = ::sun::security::krb5::JavaxSecurityAuthKerberosAccess;
using $KerberosSecrets = ::sun::security::krb5::KerberosSecrets;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $RealmException = ::sun::security::krb5::RealmException;
using $KeyTab = ::sun::security::krb5::internal::ktab::KeyTab;

namespace javax {
	namespace security {
		namespace auth {
			namespace kerberos {

$FieldInfo _KeyTab_FieldInfo_[] = {
	{"file", "Ljava/io/File;", nullptr, $PRIVATE | $FINAL, $field(KeyTab, file)},
	{"princ", "Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PRIVATE | $FINAL, $field(KeyTab, princ)},
	{"bound", "Z", nullptr, $PRIVATE | $FINAL, $field(KeyTab, bound)},
	{}
};

$MethodInfo _KeyTab_MethodInfo_[] = {
	{"<init>", "(Ljavax/security/auth/kerberos/KerberosPrincipal;Ljava/io/File;Z)V", nullptr, $PRIVATE, $method(static_cast<void(KeyTab::*)($KerberosPrincipal*,$File*,bool)>(&KeyTab::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"exists", "()Z", nullptr, $PUBLIC, $method(static_cast<bool(KeyTab::*)()>(&KeyTab::exists))},
	{"getEncryptionKeys", "(Lsun/security/krb5/PrincipalName;)[Lsun/security/krb5/EncryptionKey;", nullptr, 0, $method(static_cast<$EncryptionKeyArray*(KeyTab::*)($PrincipalName*)>(&KeyTab::getEncryptionKeys))},
	{"getInstance", "(Ljava/io/File;)Ljavax/security/auth/kerberos/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KeyTab*(*)($File*)>(&KeyTab::getInstance))},
	{"getInstance", "(Ljavax/security/auth/kerberos/KerberosPrincipal;Ljava/io/File;)Ljavax/security/auth/kerberos/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KeyTab*(*)($KerberosPrincipal*,$File*)>(&KeyTab::getInstance))},
	{"getInstance", "()Ljavax/security/auth/kerberos/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KeyTab*(*)()>(&KeyTab::getInstance))},
	{"getInstance", "(Ljavax/security/auth/kerberos/KerberosPrincipal;)Ljavax/security/auth/kerberos/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KeyTab*(*)($KerberosPrincipal*)>(&KeyTab::getInstance))},
	{"getKeys", "(Ljavax/security/auth/kerberos/KerberosPrincipal;)[Ljavax/security/auth/kerberos/KerberosKey;", nullptr, $PUBLIC, $method(static_cast<$KerberosKeyArray*(KeyTab::*)($KerberosPrincipal*)>(&KeyTab::getKeys))},
	{"getPrincipal", "()Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PUBLIC, $method(static_cast<$KerberosPrincipal*(KeyTab::*)()>(&KeyTab::getPrincipal))},
	{"getUnboundInstance", "(Ljava/io/File;)Ljavax/security/auth/kerberos/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KeyTab*(*)($File*)>(&KeyTab::getUnboundInstance))},
	{"getUnboundInstance", "()Ljavax/security/auth/kerberos/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KeyTab*(*)()>(&KeyTab::getUnboundInstance))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isBound", "()Z", nullptr, $PUBLIC, $method(static_cast<bool(KeyTab::*)()>(&KeyTab::isBound))},
	{"takeSnapshot", "()Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, 0, $method(static_cast<$KeyTab*(KeyTab::*)()>(&KeyTab::takeSnapshot))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KeyTab_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"javax.security.auth.kerberos.KeyTab",
	"java.lang.Object",
	nullptr,
	_KeyTab_FieldInfo_,
	_KeyTab_MethodInfo_
};

$Object* allocate$KeyTab($Class* clazz) {
	return $of($alloc(KeyTab));
}

void KeyTab::init$($KerberosPrincipal* princ, $File* file, bool bound) {
	$set(this, princ, princ);
	$set(this, file, file);
	this->bound = bound;
}

KeyTab* KeyTab::getInstance($File* file) {
	$init(KeyTab);
	if (file == nullptr) {
		$throwNew($NullPointerException, "file must be non null"_s);
	}
	return $new(KeyTab, nullptr, file, true);
}

KeyTab* KeyTab::getUnboundInstance($File* file) {
	$init(KeyTab);
	if (file == nullptr) {
		$throwNew($NullPointerException, "file must be non null"_s);
	}
	return $new(KeyTab, nullptr, file, false);
}

KeyTab* KeyTab::getInstance($KerberosPrincipal* princ, $File* file) {
	$init(KeyTab);
	if (princ == nullptr) {
		$throwNew($NullPointerException, "princ must be non null"_s);
	}
	if (file == nullptr) {
		$throwNew($NullPointerException, "file must be non null"_s);
	}
	return $new(KeyTab, princ, file, true);
}

KeyTab* KeyTab::getInstance() {
	$init(KeyTab);
	return $new(KeyTab, nullptr, nullptr, true);
}

KeyTab* KeyTab::getUnboundInstance() {
	$init(KeyTab);
	return $new(KeyTab, nullptr, nullptr, false);
}

KeyTab* KeyTab::getInstance($KerberosPrincipal* princ) {
	$init(KeyTab);
	if (princ == nullptr) {
		$throwNew($NullPointerException, "princ must be non null"_s);
	}
	return $new(KeyTab, princ, nullptr, true);
}

$KeyTab* KeyTab::takeSnapshot() {
	try {
		return $KeyTab::getInstance(this->file);
	} catch ($AccessControlException&) {
		$var($AccessControlException, ace, $catch());
		if (this->file != nullptr) {
			$throw(ace);
		} else {
			$var($AccessControlException, ace2, $new($AccessControlException, "Access to default keytab denied (modified exception)"_s));
			ace2->setStackTrace($(ace->getStackTrace()));
			$throw(ace2);
		}
	}
	$shouldNotReachHere();
}

$KerberosKeyArray* KeyTab::getKeys($KerberosPrincipal* principal) {
	try {
		if (this->princ != nullptr && !$nc(principal)->equals(this->princ)) {
			return $new($KerberosKeyArray, 0);
		}
		$var($PrincipalName, pn, $new($PrincipalName, $($nc(principal)->getName())));
		$var($EncryptionKeyArray, keys, $nc($(takeSnapshot()))->readServiceKeys(pn));
		$var($KerberosKeyArray, kks, $new($KerberosKeyArray, $nc(keys)->length));
		for (int32_t i = 0; i < kks->length; ++i) {
			$var($Integer, tmp, $nc(keys->get(i))->getKeyVersionNumber());
			$var($KerberosPrincipal, var$0, principal);
			$var($bytes, var$1, $nc(keys->get(i))->getBytes());
			int32_t var$2 = $nc(keys->get(i))->getEType();
			kks->set(i, $$new($KerberosKey, var$0, var$1, var$2, tmp == nullptr ? 0 : $nc(tmp)->intValue()));
			$nc(keys->get(i))->destroy();
		}
		return kks;
	} catch ($RealmException&) {
		$var($RealmException, re, $catch());
		return $new($KerberosKeyArray, 0);
	}
	$shouldNotReachHere();
}

$EncryptionKeyArray* KeyTab::getEncryptionKeys($PrincipalName* principal) {
	return $nc($(takeSnapshot()))->readServiceKeys(principal);
}

bool KeyTab::exists() {
	return !$nc($(takeSnapshot()))->isMissing();
}

$String* KeyTab::toString() {
	$var($String, s, (this->file == nullptr) ? "Default keytab"_s : $nc(this->file)->toString());
	if (!this->bound) {
		return s;
	} else if (this->princ == nullptr) {
		return $str({s, " for someone"_s});
	} else {
		return $str({s, " for "_s, this->princ});
	}
}

int32_t KeyTab::hashCode() {
	return $Objects::hash($$new($ObjectArray, {
		$of(this->file),
		$of(this->princ),
		$($of($Boolean::valueOf(this->bound)))
	}));
}

bool KeyTab::equals(Object$* other) {
	if ($equals(other, this)) {
		return true;
	}
	if (!($instanceOf(KeyTab, other))) {
		return false;
	}
	$var(KeyTab, otherKtab, $cast(KeyTab, other));
	bool var$0 = $Objects::equals($nc(otherKtab)->princ, this->princ);
	return var$0 && $Objects::equals($nc(otherKtab)->file, this->file) && this->bound == $nc(otherKtab)->bound;
}

$KerberosPrincipal* KeyTab::getPrincipal() {
	return this->princ;
}

bool KeyTab::isBound() {
	return this->bound;
}

void clinit$KeyTab($Class* class$) {
	{
		$KerberosSecrets::setJavaxSecurityAuthKerberosAccess($$new($JavaxSecurityAuthKerberosAccessImpl));
	}
}

KeyTab::KeyTab() {
}

$Class* KeyTab::load$($String* name, bool initialize) {
	$loadClass(KeyTab, name, initialize, &_KeyTab_ClassInfo_, clinit$KeyTab, allocate$KeyTab);
	return class$;
}

$Class* KeyTab::class$ = nullptr;

			} // kerberos
		} // auth
	} // security
} // javax