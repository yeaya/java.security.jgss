#include <sun/security/jgss/spi/GSSNameSpi.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/Oid.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $Oid = ::org::ietf::jgss::Oid;

namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {

$MethodInfo _GSSNameSpi_MethodInfo_[] = {
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"equals", "(Lsun/security/jgss/spi/GSSNameSpi;)Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"export", "()[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanism", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $ABSTRACT},
	{"getStringNameType", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT},
	{"hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"isAnonymousName", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _GSSNameSpi_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.security.jgss.spi.GSSNameSpi",
	nullptr,
	nullptr,
	nullptr,
	_GSSNameSpi_MethodInfo_
};

$Object* allocate$GSSNameSpi($Class* clazz) {
	return $of($alloc(GSSNameSpi));
}

bool GSSNameSpi::equals(Object$* another) {
	 return this->$Object::equals(another);
}

int32_t GSSNameSpi::hashCode() {
	 return this->$Object::hashCode();
}

$String* GSSNameSpi::toString() {
	 return this->$Object::toString();
}

$Class* GSSNameSpi::load$($String* name, bool initialize) {
	$loadClass(GSSNameSpi, name, initialize, &_GSSNameSpi_ClassInfo_, allocate$GSSNameSpi);
	return class$;
}

$Class* GSSNameSpi::class$ = nullptr;

			} // spi
		} // jgss
	} // security
} // sun