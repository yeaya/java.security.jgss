#include <sun/security/jgss/krb5/Krb5CredElement.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$ClassInfo _Krb5CredElement_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"sun.security.jgss.krb5.Krb5CredElement",
	nullptr,
	"sun.security.jgss.spi.GSSCredentialSpi"
};

$Object* allocate$Krb5CredElement($Class* clazz) {
	return $of($alloc(Krb5CredElement));
}

$Class* Krb5CredElement::load$($String* name, bool initialize) {
	$loadClass(Krb5CredElement, name, initialize, &_Krb5CredElement_ClassInfo_, allocate$Krb5CredElement);
	return class$;
}

$Class* Krb5CredElement::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun