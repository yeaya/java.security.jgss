#include <sun/security/jgss/GSSNameImpl.h>

#include <java/io/IOException.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/AbstractSet.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSExceptionImpl.h>
#include <sun/security/jgss/GSSManagerImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/ProviderList.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef BAD_NAME
#undef DEFAULT_MECH_OID
#undef FAILURE
#undef NT_ANONYMOUS
#undef NT_EXPORT_NAME
#undef NT_GSS_KRB5_PRINCIPAL
#undef NT_HOSTBASED_SERVICE
#undef NT_USER_NAME
#undef UTF_8

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AbstractSet = ::java::util::AbstractSet;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSExceptionImpl = ::sun::security::jgss::GSSExceptionImpl;
using $GSSManagerImpl = ::sun::security::jgss::GSSManagerImpl;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $ProviderList = ::sun::security::jgss::ProviderList;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _GSSNameImpl_FieldInfo_[] = {
	{"oldHostbasedServiceName", "Lorg/ietf/jgss/Oid;", nullptr, $STATIC | $FINAL, $staticField(GSSNameImpl, oldHostbasedServiceName)},
	{"gssManager", "Lsun/security/jgss/GSSManagerImpl;", nullptr, $PRIVATE, $field(GSSNameImpl, gssManager)},
	{"appNameStr", "Ljava/lang/String;", nullptr, $PRIVATE, $field(GSSNameImpl, appNameStr)},
	{"appNameBytes", "[B", nullptr, $PRIVATE, $field(GSSNameImpl, appNameBytes)},
	{"appNameType", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(GSSNameImpl, appNameType)},
	{"printableName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(GSSNameImpl, printableName)},
	{"printableNameType", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(GSSNameImpl, printableNameType)},
	{"elements", "Ljava/util/HashMap;", "Ljava/util/HashMap<Lorg/ietf/jgss/Oid;Lsun/security/jgss/spi/GSSNameSpi;>;", $PRIVATE, $field(GSSNameImpl, elements)},
	{"mechElement", "Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PRIVATE, $field(GSSNameImpl, mechElement)},
	{}
};

$MethodInfo _GSSNameImpl_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;Lsun/security/jgss/spi/GSSNameSpi;)V", nullptr, 0, $method(static_cast<void(GSSNameImpl::*)($GSSManagerImpl*,$GSSNameSpi*)>(&GSSNameImpl::init$))},
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;Ljava/lang/Object;Lorg/ietf/jgss/Oid;)V", nullptr, 0, $method(static_cast<void(GSSNameImpl::*)($GSSManagerImpl*,Object$*,$Oid*)>(&GSSNameImpl::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;Ljava/lang/Object;Lorg/ietf/jgss/Oid;Lorg/ietf/jgss/Oid;)V", nullptr, 0, $method(static_cast<void(GSSNameImpl::*)($GSSManagerImpl*,Object$*,$Oid*,$Oid*)>(&GSSNameImpl::init$)), "org.ietf.jgss.GSSException"},
	{"canonicalize", "(Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"equals", "(Lorg/ietf/jgss/GSSName;)Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"export", "()[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getElement", "(Lorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "org.ietf.jgss.GSSException"},
	{"getElements", "()Ljava/util/Set;", "()Ljava/util/Set<Lsun/security/jgss/spi/GSSNameSpi;>;", 0},
	{"getNameTypeStr", "(Lorg/ietf/jgss/Oid;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($Oid*)>(&GSSNameImpl::getNameTypeStr))},
	{"getStringNameType", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"importName", "(Lsun/security/jgss/GSSManagerImpl;Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(static_cast<void(GSSNameImpl::*)($GSSManagerImpl*,Object$*)>(&GSSNameImpl::importName)), "org.ietf.jgss.GSSException"},
	{"init", "(Lsun/security/jgss/GSSManagerImpl;Ljava/lang/Object;Lorg/ietf/jgss/Oid;Lorg/ietf/jgss/Oid;)V", nullptr, $PRIVATE, $method(static_cast<void(GSSNameImpl::*)($GSSManagerImpl*,Object$*,$Oid*,$Oid*)>(&GSSNameImpl::init)), "org.ietf.jgss.GSSException"},
	{"isAnonymous", "()Z", nullptr, $PUBLIC},
	{"isMN", "()Z", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"wrapElement", "(Lsun/security/jgss/GSSManagerImpl;Lsun/security/jgss/spi/GSSNameSpi;)Lsun/security/jgss/GSSNameImpl;", nullptr, $STATIC, $method(static_cast<GSSNameImpl*(*)($GSSManagerImpl*,$GSSNameSpi*)>(&GSSNameImpl::wrapElement)), "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _GSSNameImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.GSSNameImpl",
	"java.lang.Object",
	"org.ietf.jgss.GSSName",
	_GSSNameImpl_FieldInfo_,
	_GSSNameImpl_MethodInfo_
};

$Object* allocate$GSSNameImpl($Class* clazz) {
	return $of($alloc(GSSNameImpl));
}


$Oid* GSSNameImpl::oldHostbasedServiceName = nullptr;

GSSNameImpl* GSSNameImpl::wrapElement($GSSManagerImpl* gssManager, $GSSNameSpi* mechElement) {
	$init(GSSNameImpl);
	return (mechElement == nullptr ? (GSSNameImpl*)nullptr : $new(GSSNameImpl, gssManager, mechElement));
}

void GSSNameImpl::init$($GSSManagerImpl* gssManager, $GSSNameSpi* mechElement) {
	$set(this, gssManager, nullptr);
	$set(this, appNameStr, nullptr);
	$set(this, appNameBytes, nullptr);
	$set(this, appNameType, nullptr);
	$set(this, printableName, nullptr);
	$set(this, printableNameType, nullptr);
	$set(this, elements, nullptr);
	$set(this, mechElement, nullptr);
	$set(this, gssManager, gssManager);
	$set(this, appNameStr, ($assignField(this, printableName, $nc(mechElement)->toString())));
	$set(this, appNameType, ($assignField(this, printableNameType, mechElement->getStringNameType())));
	$set(this, mechElement, mechElement);
	$set(this, elements, $new($HashMap, 1));
	$nc(this->elements)->put($(mechElement->getMechanism()), this->mechElement);
}

void GSSNameImpl::init$($GSSManagerImpl* gssManager, Object$* appName, $Oid* appNameType) {
	GSSNameImpl::init$(gssManager, appName, appNameType, nullptr);
}

void GSSNameImpl::init$($GSSManagerImpl* gssManager, Object$* appName, $Oid* appNameType$renamed, $Oid* mech$renamed) {
	$var($Oid, mech, mech$renamed);
	$var($Oid, appNameType, appNameType$renamed);
	$set(this, gssManager, nullptr);
	$set(this, appNameStr, nullptr);
	$set(this, appNameBytes, nullptr);
	$set(this, appNameType, nullptr);
	$set(this, printableName, nullptr);
	$set(this, printableNameType, nullptr);
	$set(this, elements, nullptr);
	$set(this, mechElement, nullptr);
	if ($nc(GSSNameImpl::oldHostbasedServiceName)->equals(appNameType)) {
		$init($GSSName);
		$assign(appNameType, $GSSName::NT_HOSTBASED_SERVICE);
	}
	if (appName == nullptr) {
		$throwNew($GSSExceptionImpl, $GSSException::BAD_NAME, "Cannot import null name"_s);
	}
	if (mech == nullptr) {
		$init($ProviderList);
		$assign(mech, $ProviderList::DEFAULT_MECH_OID);
	}
	$init($GSSName);
	if ($nc($GSSName::NT_EXPORT_NAME)->equals(appNameType)) {
		importName(gssManager, appName);
	} else {
		init(gssManager, appName, appNameType, mech);
	}
}

void GSSNameImpl::init($GSSManagerImpl* gssManager, Object$* appName, $Oid* appNameType, $Oid* mech) {
	$set(this, gssManager, gssManager);
	$set(this, elements, $new($HashMap, $nc($($nc(gssManager)->getMechs()))->length));
	if ($instanceOf($String, appName)) {
		$set(this, appNameStr, $cast($String, appName));
		if (appNameType != nullptr) {
			$set(this, printableName, this->appNameStr);
			$set(this, printableNameType, appNameType);
		}
	} else {
		$set(this, appNameBytes, $cast($bytes, appName));
	}
	$set(this, appNameType, appNameType);
	$set(this, mechElement, getElement(mech));
	if (this->printableName == nullptr) {
		$set(this, printableName, $nc(this->mechElement)->toString());
		$set(this, printableNameType, $nc(this->mechElement)->getStringNameType());
	}
}

void GSSNameImpl::importName($GSSManagerImpl* gssManager, Object$* appName) {
	int32_t pos = 0;
	$var($bytes, bytes, nullptr);
	if ($instanceOf($String, appName)) {
		$init($StandardCharsets);
		$assign(bytes, $nc(($cast($String, appName)))->getBytes($StandardCharsets::UTF_8));
	} else {
		$assign(bytes, $cast($bytes, appName));
	}
	bool var$0 = ($nc(bytes)->get(pos++) != 4);
	if (var$0 || ($nc(bytes)->get(pos++) != 1)) {
		$throwNew($GSSExceptionImpl, $GSSException::BAD_NAME, "Exported name token id is corrupted!"_s);
	}
	int32_t var$1 = (((int32_t)(255 & (uint32_t)(int32_t)$nc(bytes)->get(pos++))) << 8);
	int32_t oidLen = (var$1 | ((int32_t)(255 & (uint32_t)(int32_t)bytes->get(pos++))));
	$var($ObjectIdentifier, temp, nullptr);
	try {
		$var($DerInputStream, din, $new($DerInputStream, bytes, pos, oidLen));
		$assign(temp, $new($ObjectIdentifier, din));
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::BAD_NAME, "Exported name Object identifier is corrupted!"_s);
	}
	$var($Oid, oid, $new($Oid, $($nc(temp)->toString())));
	pos += oidLen;
	int32_t var$4 = (((int32_t)(255 & (uint32_t)(int32_t)bytes->get(pos++))) << 24);
	int32_t var$3 = var$4 | (((int32_t)(255 & (uint32_t)(int32_t)bytes->get(pos++))) << 16);
	int32_t var$2 = var$3 | (((int32_t)(255 & (uint32_t)(int32_t)bytes->get(pos++))) << 8);
	int32_t mechPortionLen = (var$2 | ((int32_t)(255 & (uint32_t)(int32_t)bytes->get(pos++))));
	if (mechPortionLen < 0 || pos > bytes->length - mechPortionLen) {
		$throwNew($GSSExceptionImpl, $GSSException::BAD_NAME, "Exported name mech name is corrupted!"_s);
	}
	$var($bytes, mechPortion, $new($bytes, mechPortionLen));
	$System::arraycopy(bytes, pos, mechPortion, 0, mechPortionLen);
	$init($GSSName);
	init(gssManager, mechPortion, $GSSName::NT_EXPORT_NAME, oid);
}

$GSSName* GSSNameImpl::canonicalize($Oid* mech$renamed) {
	$var($Oid, mech, mech$renamed);
	if (mech == nullptr) {
		$init($ProviderList);
		$assign(mech, $ProviderList::DEFAULT_MECH_OID);
	}
	return wrapElement(this->gssManager, $(getElement(mech)));
}

bool GSSNameImpl::equals($GSSName* other) {
	bool var$0 = this->isAnonymous();
	if (var$0 || $nc(other)->isAnonymous()) {
		return false;
	}
	if ($equals(other, this)) {
		return true;
	}
	if (!($instanceOf(GSSNameImpl, other))) {
		$var($String, var$1, $nc(other)->toString());
		return equals($($nc(this->gssManager)->createName(var$1, $(other->getStringNameType()))));
	}
	$var(GSSNameImpl, that, $cast(GSSNameImpl, other));
	$var($GSSNameSpi, myElement, this->mechElement);
	$var($GSSNameSpi, element, $nc(that)->mechElement);
	if ((myElement == nullptr) && (element != nullptr)) {
		$assign(myElement, this->getElement($(element->getMechanism())));
	} else if ((myElement != nullptr) && (element == nullptr)) {
		$assign(element, that->getElement($(myElement->getMechanism())));
	}
	if (myElement != nullptr && element != nullptr) {
		return myElement->equals(element);
	}
	if ((this->appNameType != nullptr) && (that->appNameType != nullptr)) {
		if (!$nc(this->appNameType)->equals(that->appNameType)) {
			return false;
		}
		$init($StandardCharsets);
		$var($bytes, myBytes, this->appNameStr != nullptr ? $nc(this->appNameStr)->getBytes($StandardCharsets::UTF_8) : this->appNameBytes);
		$var($bytes, bytes, that->appNameStr != nullptr ? $nc(that->appNameStr)->getBytes($StandardCharsets::UTF_8) : that->appNameBytes);
		return $Arrays::equals(myBytes, bytes);
	}
	return false;
}

int32_t GSSNameImpl::hashCode() {
	return 1;
}

bool GSSNameImpl::equals(Object$* another) {
	try {
		if ($instanceOf($GSSName, another)) {
			return equals($cast($GSSName, another));
		}
	} catch ($GSSException&) {
		$catch();
	}
	return false;
}

$bytes* GSSNameImpl::export$() {
	if (this->mechElement == nullptr) {
		$init($ProviderList);
		$set(this, mechElement, getElement($ProviderList::DEFAULT_MECH_OID));
	}
	$var($bytes, mechPortion, $nc(this->mechElement)->export$());
	$var($bytes, oidBytes, nullptr);
	$var($ObjectIdentifier, oid, nullptr);
	try {
		$assign(oid, $ObjectIdentifier::of($($nc($($nc(this->mechElement)->getMechanism()))->toString())));
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, "Invalid OID String "_s);
	}
	$var($DerOutputStream, dout, $new($DerOutputStream));
	try {
		dout->putOID(oid);
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, $$str({"Could not ASN.1 Encode "_s, $($nc(oid)->toString())}));
	}
	$assign(oidBytes, dout->toByteArray());
	$var($bytes, retVal, $new($bytes, 2 + 2 + $nc(oidBytes)->length + 4 + $nc(mechPortion)->length));
	int32_t pos = 0;
	retVal->set(pos++, (int8_t)4);
	retVal->set(pos++, (int8_t)1);
	retVal->set(pos++, (int8_t)((int32_t)((uint32_t)oidBytes->length >> 8)));
	retVal->set(pos++, (int8_t)oidBytes->length);
	$System::arraycopy(oidBytes, 0, retVal, pos, oidBytes->length);
	pos += oidBytes->length;
	retVal->set(pos++, (int8_t)((int32_t)((uint32_t)mechPortion->length >> 24)));
	retVal->set(pos++, (int8_t)((int32_t)((uint32_t)mechPortion->length >> 16)));
	retVal->set(pos++, (int8_t)((int32_t)((uint32_t)mechPortion->length >> 8)));
	retVal->set(pos++, (int8_t)mechPortion->length);
	$System::arraycopy(mechPortion, 0, retVal, pos, mechPortion->length);
	return retVal;
}

$String* GSSNameImpl::toString() {
	return this->printableName;
}

$Oid* GSSNameImpl::getStringNameType() {
	return this->printableNameType;
}

bool GSSNameImpl::isAnonymous() {
	if (this->printableNameType == nullptr) {
		return false;
	} else {
		$init($GSSName);
		return $nc($GSSName::NT_ANONYMOUS)->equals(this->printableNameType);
	}
}

bool GSSNameImpl::isMN() {
	return true;
}

$GSSNameSpi* GSSNameImpl::getElement($Oid* mechOid) {
	$synchronized(this) {
		$var($GSSNameSpi, retVal, $cast($GSSNameSpi, $nc(this->elements)->get(mechOid)));
		if (retVal == nullptr) {
			if (this->appNameStr != nullptr) {
				$assign(retVal, $nc(this->gssManager)->getNameElement(this->appNameStr, this->appNameType, mechOid));
			} else {
				$assign(retVal, $nc(this->gssManager)->getNameElement(this->appNameBytes, this->appNameType, mechOid));
			}
			$nc(this->elements)->put(mechOid, retVal);
		}
		return retVal;
	}
}

$Set* GSSNameImpl::getElements() {
	return $new($HashSet, $($nc(this->elements)->values()));
}

$String* GSSNameImpl::getNameTypeStr($Oid* nameTypeOid) {
	$init(GSSNameImpl);
	if (nameTypeOid == nullptr) {
		return "(NT is null)"_s;
	}
	$init($GSSName);
	if ($nc(nameTypeOid)->equals($GSSName::NT_USER_NAME)) {
		return "NT_USER_NAME"_s;
	}
	if ($nc(nameTypeOid)->equals($GSSName::NT_HOSTBASED_SERVICE)) {
		return "NT_HOSTBASED_SERVICE"_s;
	}
	if ($nc(nameTypeOid)->equals($GSSName::NT_EXPORT_NAME)) {
		return "NT_EXPORT_NAME"_s;
	}
	$init($GSSUtil);
	if ($nc(nameTypeOid)->equals($GSSUtil::NT_GSS_KRB5_PRINCIPAL)) {
		return "NT_GSS_KRB5_PRINCIPAL"_s;
	} else {
		return "Unknown"_s;
	}
}

void clinit$GSSNameImpl($Class* class$) {
	{
		$var($Oid, tmp, nullptr);
		try {
			$assign(tmp, $new($Oid, "1.3.6.1.5.6.2"_s));
		} catch ($Exception&) {
			$catch();
		}
		$assignStatic(GSSNameImpl::oldHostbasedServiceName, tmp);
	}
}

GSSNameImpl::GSSNameImpl() {
}

$Class* GSSNameImpl::load$($String* name, bool initialize) {
	$loadClass(GSSNameImpl, name, initialize, &_GSSNameImpl_ClassInfo_, clinit$GSSNameImpl, allocate$GSSNameImpl);
	return class$;
}

$Class* GSSNameImpl::class$ = nullptr;

		} // jgss
	} // security
} // sun