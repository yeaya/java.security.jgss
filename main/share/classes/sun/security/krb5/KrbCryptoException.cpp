#include <sun/security/krb5/KrbCryptoException.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/KrbException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KrbException = ::sun::security::krb5::KrbException;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbCryptoException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KrbCryptoException, serialVersionUID)},
	{}
};

$MethodInfo _KrbCryptoException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbCryptoException::*)($String*)>(&KrbCryptoException::init$))},
	{}
};

$ClassInfo _KrbCryptoException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.KrbCryptoException",
	"sun.security.krb5.KrbException",
	nullptr,
	_KrbCryptoException_FieldInfo_,
	_KrbCryptoException_MethodInfo_
};

$Object* allocate$KrbCryptoException($Class* clazz) {
	return $of($alloc(KrbCryptoException));
}

void KrbCryptoException::init$($String* s) {
	$KrbException::init$(s);
}

KrbCryptoException::KrbCryptoException() {
}

KrbCryptoException::KrbCryptoException(const KrbCryptoException& e) {
}

KrbCryptoException KrbCryptoException::wrapper$() {
	$pendingException(this);
	return *this;
}

void KrbCryptoException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* KrbCryptoException::load$($String* name, bool initialize) {
	$loadClass(KrbCryptoException, name, initialize, &_KrbCryptoException_ClassInfo_, allocate$KrbCryptoException);
	return class$;
}

$Class* KrbCryptoException::class$ = nullptr;

		} // krb5
	} // security
} // sun