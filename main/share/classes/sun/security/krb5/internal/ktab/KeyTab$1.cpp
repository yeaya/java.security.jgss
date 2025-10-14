#include <sun/security/krb5/internal/ktab/KeyTab$1.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/internal/ktab/KeyTab.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KeyTab = ::sun::security::krb5::internal::ktab::KeyTab;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {

$FieldInfo _KeyTab$1_FieldInfo_[] = {
	{"this$0", "Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $FINAL | $SYNTHETIC, $field(KeyTab$1, this$0)},
	{}
};

$MethodInfo _KeyTab$1_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/ktab/KeyTab;)V", nullptr, 0, $method(static_cast<void(KeyTab$1::*)($KeyTab*)>(&KeyTab$1::init$))},
	{"compare", "(Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/EncryptionKey;)I", nullptr, $PUBLIC},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{}
};

$EnclosingMethodInfo _KeyTab$1_EnclosingMethodInfo_ = {
	"sun.security.krb5.internal.ktab.KeyTab",
	"readServiceKeys",
	"(Lsun/security/krb5/PrincipalName;)[Lsun/security/krb5/EncryptionKey;"
};

$InnerClassInfo _KeyTab$1_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ktab.KeyTab$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _KeyTab$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.internal.ktab.KeyTab$1",
	"java.lang.Object",
	"java.util.Comparator",
	_KeyTab$1_FieldInfo_,
	_KeyTab$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/Comparator<Lsun/security/krb5/EncryptionKey;>;",
	&_KeyTab$1_EnclosingMethodInfo_,
	_KeyTab$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ktab.KeyTab"
};

$Object* allocate$KeyTab$1($Class* clazz) {
	return $of($alloc(KeyTab$1));
}

void KeyTab$1::init$($KeyTab* this$0) {
	$set(this, this$0, this$0);
}

int32_t KeyTab$1::compare($EncryptionKey* o1, $EncryptionKey* o2) {
	int32_t var$0 = $nc($($nc(o2)->getKeyVersionNumber()))->intValue();
	return var$0 - $nc($($nc(o1)->getKeyVersionNumber()))->intValue();
}

int32_t KeyTab$1::compare(Object$* o1, Object$* o2) {
	return this->compare($cast($EncryptionKey, o1), $cast($EncryptionKey, o2));
}

KeyTab$1::KeyTab$1() {
}

$Class* KeyTab$1::load$($String* name, bool initialize) {
	$loadClass(KeyTab$1, name, initialize, &_KeyTab$1_ClassInfo_, allocate$KeyTab$1);
	return class$;
}

$Class* KeyTab$1::class$ = nullptr;

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun