#include <sun/security/krb5/internal/crypto/Nonce.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Confounder.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Confounder = ::sun::security::krb5::Confounder;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$MethodInfo _Nonce_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Nonce::*)()>(&Nonce::init$))},
	{"value", "()I", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<int32_t(*)()>(&Nonce::value))},
	{}
};

$ClassInfo _Nonce_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.Nonce",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Nonce_MethodInfo_
};

$Object* allocate$Nonce($Class* clazz) {
	return $of($alloc(Nonce));
}

void Nonce::init$() {
}

int32_t Nonce::value() {
	$load(Nonce);
	$synchronized(class$) {
		return (int32_t)($Confounder::intValue() & (uint32_t)0x7FFFFFFF);
	}
}

Nonce::Nonce() {
}

$Class* Nonce::load$($String* name, bool initialize) {
	$loadClass(Nonce, name, initialize, &_Nonce_ClassInfo_, allocate$Nonce);
	return class$;
}

$Class* Nonce::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun