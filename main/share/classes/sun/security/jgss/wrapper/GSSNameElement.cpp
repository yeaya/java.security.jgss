#include <sun/security/jgss/wrapper/GSSNameElement.h>

#include <java/io/IOException.h>
#include <java/lang/Array.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Long.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Permission.h>
#include <java/security/Provider.h>
#include <javax/security/auth/kerberos/ServicePermission.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSExceptionImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/wrapper/GSSLibStub.h>
#include <sun/security/jgss/wrapper/SunNativeProvider.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef AUTODEDUCEREALM
#undef BAD_MECH
#undef BAD_NAME
#undef DEF_ACCEPTOR
#undef FAILURE
#undef GSS_KRB5_MECH_OID
#undef INSTANCE
#undef NT_ANONYMOUS
#undef NT_EXPORT_NAME
#undef NT_GSS_KRB5_PRINCIPAL
#undef NT_USER_NAME

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Permission = ::java::security::Permission;
using $Provider = ::java::security::Provider;
using $ServicePermission = ::javax::security::auth::kerberos::ServicePermission;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSExceptionImpl = ::sun::security::jgss::GSSExceptionImpl;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $GSSLibStub = ::sun::security::jgss::wrapper::GSSLibStub;
using $SunNativeProvider = ::sun::security::jgss::wrapper::SunNativeProvider;
using $Realm = ::sun::security::krb5::Realm;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

$FieldInfo _GSSNameElement_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(GSSNameElement, $assertionsDisabled)},
	{"pName", "J", nullptr, 0, $field(GSSNameElement, pName)},
	{"printableName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(GSSNameElement, printableName)},
	{"printableType", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(GSSNameElement, printableType)},
	{"cStub", "Lsun/security/jgss/wrapper/GSSLibStub;", nullptr, $PRIVATE, $field(GSSNameElement, cStub)},
	{"DEF_ACCEPTOR", "Lsun/security/jgss/wrapper/GSSNameElement;", nullptr, $STATIC | $FINAL, $staticField(GSSNameElement, DEF_ACCEPTOR)},
	{}
};

$MethodInfo _GSSNameElement_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(GSSNameElement::*)()>(&GSSNameElement::init$))},
	{"<init>", "(JLsun/security/jgss/wrapper/GSSLibStub;)V", nullptr, 0, $method(static_cast<void(GSSNameElement::*)(int64_t,$GSSLibStub*)>(&GSSNameElement::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "([BLorg/ietf/jgss/Oid;Lsun/security/jgss/wrapper/GSSLibStub;)V", nullptr, 0, $method(static_cast<void(GSSNameElement::*)($bytes*,$Oid*,$GSSLibStub*)>(&GSSNameElement::init$)), "org.ietf.jgss.GSSException"},
	{"dispose", "()V", nullptr, $PUBLIC},
	{"equals", "(Lsun/security/jgss/spi/GSSNameSpi;)Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"export", "()[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"finalize", "()V", nullptr, $PROTECTED, nullptr, "java.lang.Throwable"},
	{"getKrbName", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechanism", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getNativeNameType", "(Lorg/ietf/jgss/Oid;Lsun/security/jgss/wrapper/GSSLibStub;)Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Oid*(*)($Oid*,$GSSLibStub*)>(&GSSNameElement::getNativeNameType))},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC},
	{"getStringNameType", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isAnonymousName", "()Z", nullptr, $PUBLIC},
	{"setPrintables", "()V", nullptr, $PRIVATE, $method(static_cast<void(GSSNameElement::*)()>(&GSSNameElement::setPrintables)), "org.ietf.jgss.GSSException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _GSSNameElement_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.wrapper.GSSNameElement",
	"java.lang.Object",
	"sun.security.jgss.spi.GSSNameSpi",
	_GSSNameElement_FieldInfo_,
	_GSSNameElement_MethodInfo_
};

$Object* allocate$GSSNameElement($Class* clazz) {
	return $of($alloc(GSSNameElement));
}

bool GSSNameElement::$assertionsDisabled = false;
GSSNameElement* GSSNameElement::DEF_ACCEPTOR = nullptr;

$Oid* GSSNameElement::getNativeNameType($Oid* nameType, $GSSLibStub* stub$renamed) {
	$init(GSSNameElement);
	$var($GSSLibStub, stub, stub$renamed);
	$init($GSSUtil);
	if ($nc($GSSUtil::NT_GSS_KRB5_PRINCIPAL)->equals(nameType)) {
		$var($OidArray, supportedNTs, nullptr);
		try {
			$assign(supportedNTs, $nc(stub)->inquireNamesForMech());
		} catch ($GSSException&) {
			$var($GSSException, ge, $catch());
			bool var$0 = ge->getMajor() == $GSSException::BAD_MECH;
			if (var$0 && $GSSUtil::isSpNegoMech($($nc(stub)->getMech()))) {
				try {
					$assign(stub, $GSSLibStub::getInstance($GSSUtil::GSS_KRB5_MECH_OID));
					$assign(supportedNTs, $nc(stub)->inquireNamesForMech());
				} catch ($GSSException&) {
					$var($GSSException, ge2, $catch());
					$SunNativeProvider::debug($$str({"Name type list unavailable: "_s, $(ge2->getMajorString())}));
				}
			} else {
				$SunNativeProvider::debug($$str({"Name type list unavailable: "_s, $(ge->getMajorString())}));
			}
		}
		if (supportedNTs != nullptr) {
			for (int32_t i = 0; i < supportedNTs->length; ++i) {
				if ($nc(supportedNTs->get(i))->equals(nameType)) {
					return nameType;
				}
			}
			$SunNativeProvider::debug($$str({"Override "_s, nameType, " with mechanism default(null)"_s}));
			return nullptr;
		}
	}
	return nameType;
}

void GSSNameElement::init$() {
	this->pName = 0;
	$set(this, printableName, "<DEFAULT ACCEPTOR>"_s);
}

void GSSNameElement::init$(int64_t pNativeName, $GSSLibStub* stub) {
	this->pName = 0;
	if (!GSSNameElement::$assertionsDisabled && !(stub != nullptr)) {
		$throwNew($AssertionError);
	}
	if (pNativeName == 0) {
		$throwNew($GSSException, $GSSException::BAD_NAME);
	}
	this->pName = pNativeName;
	$set(this, cStub, stub);
	setPrintables();
}

void GSSNameElement::init$($bytes* nameBytes, $Oid* nameType$renamed, $GSSLibStub* stub) {
	$var($Oid, nameType, nameType$renamed);
	this->pName = 0;
	if (!GSSNameElement::$assertionsDisabled && !(stub != nullptr)) {
		$throwNew($AssertionError);
	}
	if (nameBytes == nullptr) {
		$throwNew($GSSException, $GSSException::BAD_NAME);
	}
	$set(this, cStub, stub);
	$var($bytes, name, nameBytes);
	if (nameType != nullptr) {
		$assign(nameType, getNativeNameType(nameType, stub));
		$init($GSSName);
		if ($nc($GSSName::NT_EXPORT_NAME)->equals(nameType)) {
			$var($bytes, mechBytes, nullptr);
			$var($DerOutputStream, dout, $new($DerOutputStream));
			$var($Oid, mech, $nc(this->cStub)->getMech());
			try {
				dout->putOID($($ObjectIdentifier::of($($nc(mech)->toString()))));
			} catch ($IOException&) {
				$var($IOException, e, $catch());
				$throwNew($GSSExceptionImpl, $GSSException::FAILURE, static_cast<$Exception*>(e));
			}
			$assign(mechBytes, dout->toByteArray());
			$assign(name, $new($bytes, 2 + 2 + $nc(mechBytes)->length + 4 + $nc(nameBytes)->length));
			int32_t pos = 0;
			name->set(pos++, (int8_t)4);
			name->set(pos++, (int8_t)1);
			name->set(pos++, (int8_t)((int32_t)((uint32_t)mechBytes->length >> 8)));
			name->set(pos++, (int8_t)mechBytes->length);
			$System::arraycopy(mechBytes, 0, name, pos, mechBytes->length);
			pos += mechBytes->length;
			name->set(pos++, (int8_t)((int32_t)((uint32_t)nameBytes->length >> 24)));
			name->set(pos++, (int8_t)((int32_t)((uint32_t)nameBytes->length >> 16)));
			name->set(pos++, (int8_t)((int32_t)((uint32_t)nameBytes->length >> 8)));
			name->set(pos++, (int8_t)nameBytes->length);
			$System::arraycopy(nameBytes, 0, name, pos, nameBytes->length);
		}
	}
	this->pName = $nc(this->cStub)->importName(name, nameType);
	setPrintables();
	$var($SecurityManager, sm, $System::getSecurityManager());
	$init($Realm);
	if (sm != nullptr && !$Realm::AUTODEDUCEREALM) {
		$var($String, krbName, getKrbName());
		int32_t atPos = $nc(krbName)->lastIndexOf((int32_t)u'@');
		if (atPos != -1) {
			$var($String, atRealm, krbName->substring(atPos));
			$init($GSSUtil);
			bool var$0 = (nameType == nullptr || $nc(nameType)->equals($GSSUtil::NT_GSS_KRB5_PRINCIPAL));
			if (var$0 && $$new($String, nameBytes)->endsWith(atRealm)) {
			} else {
				try {
					sm->checkPermission($$new($ServicePermission, atRealm, "-"_s));
				} catch ($SecurityException&) {
					$var($SecurityException, se, $catch());
					$throwNew($GSSException, $GSSException::FAILURE);
				}
			}
		}
	}
	$SunNativeProvider::debug($$str({"Imported "_s, this->printableName, " w/ type "_s, this->printableType}));
}

void GSSNameElement::setPrintables() {
	$var($ObjectArray, printables, nullptr);
	$assign(printables, $nc(this->cStub)->displayName(this->pName));
	if (!GSSNameElement::$assertionsDisabled && !((printables != nullptr) && (printables->length == 2))) {
		$throwNew($AssertionError);
	}
	$set(this, printableName, $cast($String, $nc(printables)->get(0)));
	if (!GSSNameElement::$assertionsDisabled && !(this->printableName != nullptr)) {
		$throwNew($AssertionError);
	}
	$set(this, printableType, $cast($Oid, printables->get(1)));
	if (this->printableType == nullptr) {
		$init($GSSName);
		$set(this, printableType, $GSSName::NT_USER_NAME);
	}
}

$String* GSSNameElement::getKrbName() {
	int64_t mName = 0;
	$var($GSSLibStub, stub, this->cStub);
	if (!$GSSUtil::isKerberosMech($($nc(this->cStub)->getMech()))) {
		$init($GSSUtil);
		$assign(stub, $GSSLibStub::getInstance($GSSUtil::GSS_KRB5_MECH_OID));
	}
	mName = $nc(stub)->canonicalizeName(this->pName);
	$var($ObjectArray, printables2, stub->displayName(mName));
	stub->releaseName(mName);
	$SunNativeProvider::debug($$str({"Got kerberized name: "_s, $nc(printables2)->get(0)}));
	return $cast($String, $nc(printables2)->get(0));
}

$Provider* GSSNameElement::getProvider() {
	$init($SunNativeProvider);
	return $SunNativeProvider::INSTANCE;
}

bool GSSNameElement::equals($GSSNameSpi* other) {
	if (!($instanceOf(GSSNameElement, other))) {
		return false;
	}
	return $nc(this->cStub)->compareName(this->pName, $nc(($cast(GSSNameElement, other)))->pName);
}

bool GSSNameElement::equals(Object$* other) {
	if (!($instanceOf(GSSNameElement, other))) {
		return false;
	}
	try {
		return equals($cast(GSSNameElement, other));
	} catch ($GSSException&) {
		$var($GSSException, ex, $catch());
		return false;
	}
	$shouldNotReachHere();
}

int32_t GSSNameElement::hashCode() {
	return $Long::hashCode(this->pName);
}

$bytes* GSSNameElement::export$() {
	$var($bytes, nameVal, $nc(this->cStub)->exportName(this->pName));
	int32_t pos = 0;
	bool var$0 = ($nc(nameVal)->get(pos++) != 4);
	if (var$0 || ($nc(nameVal)->get(pos++) != 1)) {
		$throwNew($GSSException, $GSSException::BAD_NAME);
	}
	int32_t var$1 = (((int32_t)(255 & (uint32_t)(int32_t)$nc(nameVal)->get(pos++))) << 8);
	int32_t mechOidLen = (var$1 | ((int32_t)(255 & (uint32_t)(int32_t)nameVal->get(pos++))));
	$var($ObjectIdentifier, temp, nullptr);
	try {
		$var($DerInputStream, din, $new($DerInputStream, nameVal, pos, mechOidLen));
		$assign(temp, $new($ObjectIdentifier, din));
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::BAD_NAME, static_cast<$Exception*>(e));
	}
	$var($Oid, mech2, $new($Oid, $($nc(temp)->toString())));
	if (!GSSNameElement::$assertionsDisabled && !(mech2->equals($(getMechanism())))) {
		$throwNew($AssertionError);
	}
	pos += mechOidLen;
	int32_t var$4 = (((int32_t)(255 & (uint32_t)(int32_t)nameVal->get(pos++))) << 24);
	int32_t var$3 = var$4 | (((int32_t)(255 & (uint32_t)(int32_t)nameVal->get(pos++))) << 16);
	int32_t var$2 = var$3 | (((int32_t)(255 & (uint32_t)(int32_t)nameVal->get(pos++))) << 8);
	int32_t mechPortionLen = (var$2 | ((int32_t)(255 & (uint32_t)(int32_t)nameVal->get(pos++))));
	if (mechPortionLen < 0) {
		$throwNew($GSSException, $GSSException::BAD_NAME);
	}
	$var($bytes, mechPortion, $new($bytes, mechPortionLen));
	$System::arraycopy(nameVal, pos, mechPortion, 0, mechPortionLen);
	return mechPortion;
}

$Oid* GSSNameElement::getMechanism() {
	return $nc(this->cStub)->getMech();
}

$String* GSSNameElement::toString() {
	return this->printableName;
}

$Oid* GSSNameElement::getStringNameType() {
	return this->printableType;
}

bool GSSNameElement::isAnonymousName() {
	$init($GSSName);
	return ($nc($GSSName::NT_ANONYMOUS)->equals(this->printableType));
}

void GSSNameElement::dispose() {
	if (this->pName != 0) {
		$nc(this->cStub)->releaseName(this->pName);
		this->pName = 0;
	}
}

void GSSNameElement::finalize() {
	dispose();
}

void clinit$GSSNameElement($Class* class$) {
	GSSNameElement::$assertionsDisabled = !GSSNameElement::class$->desiredAssertionStatus();
	$assignStatic(GSSNameElement::DEF_ACCEPTOR, $new(GSSNameElement));
}

GSSNameElement::GSSNameElement() {
}

$Class* GSSNameElement::load$($String* name, bool initialize) {
	$loadClass(GSSNameElement, name, initialize, &_GSSNameElement_ClassInfo_, clinit$GSSNameElement, allocate$GSSNameElement);
	return class$;
}

$Class* GSSNameElement::class$ = nullptr;

			} // wrapper
		} // jgss
	} // security
} // sun