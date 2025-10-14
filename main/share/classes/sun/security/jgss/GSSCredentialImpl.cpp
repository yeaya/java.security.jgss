#include <sun/security/jgss/GSSCredentialImpl.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractSet.h>
#include <java/util/Enumeration.h>
#include <java/util/HashSet.h>
#include <java/util/Hashtable.h>
#include <java/util/Map$Entry.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSCredentialImpl$SearchKey.h>
#include <sun/security/jgss/GSSExceptionImpl.h>
#include <sun/security/jgss/GSSManagerImpl.h>
#include <sun/security/jgss/GSSNameImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/ProviderList.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/spnego/SpNegoCredElement.h>
#include <jcpp.h>

#undef ACCEPT_ONLY
#undef BAD_MECH
#undef DEFAULT_LIFETIME
#undef DEFAULT_MECH_OID
#undef DUPLICATE_ELEMENT
#undef GSS_SPNEGO_MECH_OID
#undef INDEFINITE_LIFETIME
#undef INITIATE_AND_ACCEPT
#undef INITIATE_ONLY
#undef NO_CRED

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AbstractSet = ::java::util::AbstractSet;
using $Enumeration = ::java::util::Enumeration;
using $HashSet = ::java::util::HashSet;
using $Hashtable = ::java::util::Hashtable;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCredentialImpl$SearchKey = ::sun::security::jgss::GSSCredentialImpl$SearchKey;
using $GSSExceptionImpl = ::sun::security::jgss::GSSExceptionImpl;
using $GSSManagerImpl = ::sun::security::jgss::GSSManagerImpl;
using $GSSNameImpl = ::sun::security::jgss::GSSNameImpl;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $ProviderList = ::sun::security::jgss::ProviderList;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $SpNegoCredElement = ::sun::security::jgss::spnego::SpNegoCredElement;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _GSSCredentialImpl_FieldInfo_[] = {
	{"gssManager", "Lsun/security/jgss/GSSManagerImpl;", nullptr, $PRIVATE, $field(GSSCredentialImpl, gssManager)},
	{"destroyed", "Z", nullptr, $PRIVATE, $field(GSSCredentialImpl, destroyed)},
	{"hashtable", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Lsun/security/jgss/GSSCredentialImpl$SearchKey;Lsun/security/jgss/spi/GSSCredentialSpi;>;", $PRIVATE, $field(GSSCredentialImpl, hashtable)},
	{"tempCred", "Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PRIVATE, $field(GSSCredentialImpl, tempCred)},
	{}
};

$MethodInfo _GSSCredentialImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(GSSCredentialImpl::*)()>(&GSSCredentialImpl::init$))},
	{"<init>", "(Lsun/security/jgss/GSSCredentialImpl;)V", nullptr, $PROTECTED, $method(static_cast<void(GSSCredentialImpl::*)(GSSCredentialImpl*)>(&GSSCredentialImpl::init$))},
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;I)V", nullptr, 0, $method(static_cast<void(GSSCredentialImpl::*)($GSSManagerImpl*,int32_t)>(&GSSCredentialImpl::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;Lorg/ietf/jgss/GSSName;ILorg/ietf/jgss/Oid;I)V", nullptr, 0, $method(static_cast<void(GSSCredentialImpl::*)($GSSManagerImpl*,$GSSName*,int32_t,$Oid*,int32_t)>(&GSSCredentialImpl::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;Lorg/ietf/jgss/GSSName;I[Lorg/ietf/jgss/Oid;I)V", nullptr, 0, $method(static_cast<void(GSSCredentialImpl::*)($GSSManagerImpl*,$GSSName*,int32_t,$OidArray*,int32_t)>(&GSSCredentialImpl::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;Lsun/security/jgss/spi/GSSCredentialSpi;)V", nullptr, $PUBLIC, $method(static_cast<void(GSSCredentialImpl::*)($GSSManagerImpl*,$GSSCredentialSpi*)>(&GSSCredentialImpl::init$)), "org.ietf.jgss.GSSException"},
	{"add", "(Lorg/ietf/jgss/GSSName;IILorg/ietf/jgss/Oid;I)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"dispose", "()V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getElement", "(Lorg/ietf/jgss/Oid;Z)Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getElementStr", "(Lorg/ietf/jgss/Oid;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($Oid*,int32_t)>(&GSSCredentialImpl::getElementStr))},
	{"getElements", "()Ljava/util/Set;", "()Ljava/util/Set<Lsun/security/jgss/spi/GSSCredentialSpi;>;", 0},
	{"getMechs", "()[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getName", "()Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getName", "(Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getRemainingAcceptLifetime", "(Lorg/ietf/jgss/Oid;)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getRemainingInitLifetime", "(Lorg/ietf/jgss/Oid;)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getRemainingLifetime", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getUsage", "()I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getUsage", "(Lorg/ietf/jgss/Oid;)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"impersonate", "(Lorg/ietf/jgss/GSSName;)Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"init", "(Lsun/security/jgss/GSSManagerImpl;)V", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _GSSCredentialImpl_InnerClassesInfo_[] = {
	{"sun.security.jgss.GSSCredentialImpl$SearchKey", "sun.security.jgss.GSSCredentialImpl", "SearchKey", $STATIC},
	{}
};

$ClassInfo _GSSCredentialImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.GSSCredentialImpl",
	"java.lang.Object",
	"org.ietf.jgss.GSSCredential",
	_GSSCredentialImpl_FieldInfo_,
	_GSSCredentialImpl_MethodInfo_,
	nullptr,
	nullptr,
	_GSSCredentialImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.GSSCredentialImpl$SearchKey"
};

$Object* allocate$GSSCredentialImpl($Class* clazz) {
	return $of($alloc(GSSCredentialImpl));
}

void GSSCredentialImpl::init$() {
	$set(this, gssManager, nullptr);
	this->destroyed = false;
	$set(this, hashtable, nullptr);
	$set(this, tempCred, nullptr);
}

void GSSCredentialImpl::init$(GSSCredentialImpl* src) {
	$set(this, gssManager, nullptr);
	this->destroyed = false;
	$set(this, hashtable, nullptr);
	$set(this, tempCred, nullptr);
	$set(this, gssManager, $nc(src)->gssManager);
	this->destroyed = src->destroyed;
	$set(this, hashtable, src->hashtable);
	$set(this, tempCred, src->tempCred);
}

void GSSCredentialImpl::init$($GSSManagerImpl* gssManager, int32_t usage) {
	GSSCredentialImpl::init$(gssManager, ($GSSName*)nullptr, $GSSCredential::DEFAULT_LIFETIME, ($OidArray*)nullptr, usage);
}

void GSSCredentialImpl::init$($GSSManagerImpl* gssManager, $GSSName* name, int32_t lifetime, $Oid* mech$renamed, int32_t usage) {
	$var($Oid, mech, mech$renamed);
	$set(this, gssManager, nullptr);
	this->destroyed = false;
	$set(this, hashtable, nullptr);
	$set(this, tempCred, nullptr);
	if (mech == nullptr) {
		$init($ProviderList);
		$assign(mech, $ProviderList::DEFAULT_MECH_OID);
	}
	init(gssManager);
	add(name, lifetime, lifetime, mech, usage);
}

void GSSCredentialImpl::init$($GSSManagerImpl* gssManager, $GSSName* name, int32_t lifetime, $OidArray* mechs$renamed, int32_t usage) {
	$var($OidArray, mechs, mechs$renamed);
	$set(this, gssManager, nullptr);
	this->destroyed = false;
	$set(this, hashtable, nullptr);
	$set(this, tempCred, nullptr);
	init(gssManager);
	bool defaultList = false;
	if (mechs == nullptr) {
		$assign(mechs, $nc(gssManager)->getMechs());
		defaultList = true;
	}
	for (int32_t i = 0; i < $nc(mechs)->length; ++i) {
		try {
			add(name, lifetime, lifetime, mechs->get(i), usage);
		} catch ($GSSException&) {
			$var($GSSException, e, $catch());
			if (defaultList) {
				$GSSUtil::debug($$str({"Ignore "_s, e, " while acquring cred for "_s, mechs->get(i)}));
			} else {
				$throw(e);
			}
		}
	}
	bool var$0 = ($nc(this->hashtable)->size() == 0);
	if (var$0 || (usage != getUsage())) {
		$throwNew($GSSException, $GSSException::NO_CRED);
	}
}

void GSSCredentialImpl::init$($GSSManagerImpl* gssManager, $GSSCredentialSpi* mechElement) {
	$set(this, gssManager, nullptr);
	this->destroyed = false;
	$set(this, hashtable, nullptr);
	$set(this, tempCred, nullptr);
	init(gssManager);
	int32_t usage = $GSSCredential::ACCEPT_ONLY;
	if ($nc(mechElement)->isInitiatorCredential()) {
		if (mechElement->isAcceptorCredential()) {
			usage = $GSSCredential::INITIATE_AND_ACCEPT;
		} else {
			usage = $GSSCredential::INITIATE_ONLY;
		}
	}
	$var($GSSCredentialImpl$SearchKey, key, $new($GSSCredentialImpl$SearchKey, $($nc(mechElement)->getMechanism()), usage));
	$set(this, tempCred, mechElement);
	$nc(this->hashtable)->put(key, this->tempCred);
	if (!$GSSUtil::isSpNegoMech($($nc(mechElement)->getMechanism()))) {
		$init($GSSUtil);
		$assign(key, $new($GSSCredentialImpl$SearchKey, $GSSUtil::GSS_SPNEGO_MECH_OID, usage));
		$nc(this->hashtable)->put(key, $$new($SpNegoCredElement, mechElement));
	}
}

void GSSCredentialImpl::init($GSSManagerImpl* gssManager) {
	$set(this, gssManager, gssManager);
	$set(this, hashtable, $new($Hashtable, $nc($($nc(gssManager)->getMechs()))->length));
}

void GSSCredentialImpl::dispose() {
	if (!this->destroyed) {
		$var($GSSCredentialSpi, element, nullptr);
		$var($Enumeration, values, $nc(this->hashtable)->elements());
		while ($nc(values)->hasMoreElements()) {
			$assign(element, $cast($GSSCredentialSpi, values->nextElement()));
			$nc(element)->dispose();
		}
		this->destroyed = true;
	}
}

$GSSCredential* GSSCredentialImpl::impersonate($GSSName* name) {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($Oid, mech, $nc(this->tempCred)->getMechanism());
	$var($GSSNameSpi, nameElement, name == nullptr ? ($GSSNameSpi*)nullptr : $nc(($cast($GSSNameImpl, name)))->getElement(mech));
	$var($GSSCredentialSpi, cred, $nc(this->tempCred)->impersonate(nameElement));
	return (cred == nullptr ? ($GSSCredential*)nullptr : $GSSManagerImpl::wrap($$new(GSSCredentialImpl, this->gssManager, cred)));
}

$GSSName* GSSCredentialImpl::getName() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	return $GSSNameImpl::wrapElement(this->gssManager, $($nc(this->tempCred)->getName()));
}

$GSSName* GSSCredentialImpl::getName($Oid* mech$renamed) {
	$var($Oid, mech, mech$renamed);
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($GSSCredentialImpl$SearchKey, key, nullptr);
	$var($GSSCredentialSpi, element, nullptr);
	if (mech == nullptr) {
		$init($ProviderList);
		$assign(mech, $ProviderList::DEFAULT_MECH_OID);
	}
	$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::INITIATE_ONLY));
	$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	if (element == nullptr) {
		$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::ACCEPT_ONLY));
		$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	}
	if (element == nullptr) {
		$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::INITIATE_AND_ACCEPT));
		$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	}
	if (element == nullptr) {
		$throwNew($GSSExceptionImpl, $GSSException::BAD_MECH, mech);
	}
	return $GSSNameImpl::wrapElement(this->gssManager, $($nc(element)->getName()));
}

int32_t GSSCredentialImpl::getRemainingLifetime() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($GSSCredentialImpl$SearchKey, tempKey, nullptr);
	$var($GSSCredentialSpi, tempCred, nullptr);
	int32_t tempLife = 0;
	int32_t tempInitLife = 0;
	int32_t tempAcceptLife = 0;
	int32_t min = $GSSCredential::INDEFINITE_LIFETIME;
	{
		$var($Enumeration, e, $nc(this->hashtable)->keys());
		for (; $nc(e)->hasMoreElements();) {
			$assign(tempKey, $cast($GSSCredentialImpl$SearchKey, e->nextElement()));
			$assign(tempCred, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(tempKey)));
			if ($nc(tempKey)->getUsage() == $GSSCredential::INITIATE_ONLY) {
				tempLife = $nc(tempCred)->getInitLifetime();
			} else if (tempKey->getUsage() == $GSSCredential::ACCEPT_ONLY) {
				tempLife = $nc(tempCred)->getAcceptLifetime();
			} else {
				tempInitLife = $nc(tempCred)->getInitLifetime();
				tempAcceptLife = tempCred->getAcceptLifetime();
				tempLife = (tempInitLife < tempAcceptLife ? tempInitLife : tempAcceptLife);
			}
			if (min > tempLife) {
				min = tempLife;
			}
		}
	}
	return min;
}

int32_t GSSCredentialImpl::getRemainingInitLifetime($Oid* mech$renamed) {
	$var($Oid, mech, mech$renamed);
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($GSSCredentialSpi, element, nullptr);
	$var($GSSCredentialImpl$SearchKey, key, nullptr);
	bool found = false;
	int32_t max = 0;
	if (mech == nullptr) {
		$init($ProviderList);
		$assign(mech, $ProviderList::DEFAULT_MECH_OID);
	}
	$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::INITIATE_ONLY));
	$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	if (element != nullptr) {
		found = true;
		if (max < element->getInitLifetime()) {
			max = element->getInitLifetime();
		}
	}
	$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::INITIATE_AND_ACCEPT));
	$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	if (element != nullptr) {
		found = true;
		if (max < element->getInitLifetime()) {
			max = element->getInitLifetime();
		}
	}
	if (!found) {
		$throwNew($GSSExceptionImpl, $GSSException::BAD_MECH, mech);
	}
	return max;
}

int32_t GSSCredentialImpl::getRemainingAcceptLifetime($Oid* mech$renamed) {
	$var($Oid, mech, mech$renamed);
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($GSSCredentialSpi, element, nullptr);
	$var($GSSCredentialImpl$SearchKey, key, nullptr);
	bool found = false;
	int32_t max = 0;
	if (mech == nullptr) {
		$init($ProviderList);
		$assign(mech, $ProviderList::DEFAULT_MECH_OID);
	}
	$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::ACCEPT_ONLY));
	$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	if (element != nullptr) {
		found = true;
		if (max < element->getAcceptLifetime()) {
			max = element->getAcceptLifetime();
		}
	}
	$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::INITIATE_AND_ACCEPT));
	$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	if (element != nullptr) {
		found = true;
		if (max < element->getAcceptLifetime()) {
			max = element->getAcceptLifetime();
		}
	}
	if (!found) {
		$throwNew($GSSExceptionImpl, $GSSException::BAD_MECH, mech);
	}
	return max;
}

int32_t GSSCredentialImpl::getUsage() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($GSSCredentialImpl$SearchKey, tempKey, nullptr);
	bool initiate = false;
	bool accept = false;
	{
		$var($Enumeration, e, $nc(this->hashtable)->keys());
		for (; $nc(e)->hasMoreElements();) {
			$assign(tempKey, $cast($GSSCredentialImpl$SearchKey, e->nextElement()));
			if ($nc(tempKey)->getUsage() == $GSSCredential::INITIATE_ONLY) {
				initiate = true;
			} else if (tempKey->getUsage() == $GSSCredential::ACCEPT_ONLY) {
				accept = true;
			} else {
				return $GSSCredential::INITIATE_AND_ACCEPT;
			}
		}
	}
	if (initiate) {
		if (accept) {
			return $GSSCredential::INITIATE_AND_ACCEPT;
		} else {
			return $GSSCredential::INITIATE_ONLY;
		}
	} else {
		return $GSSCredential::ACCEPT_ONLY;
	}
}

int32_t GSSCredentialImpl::getUsage($Oid* mech$renamed) {
	$var($Oid, mech, mech$renamed);
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($GSSCredentialSpi, element, nullptr);
	$var($GSSCredentialImpl$SearchKey, key, nullptr);
	bool initiate = false;
	bool accept = false;
	if (mech == nullptr) {
		$init($ProviderList);
		$assign(mech, $ProviderList::DEFAULT_MECH_OID);
	}
	$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::INITIATE_ONLY));
	$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	if (element != nullptr) {
		initiate = true;
	}
	$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::ACCEPT_ONLY));
	$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	if (element != nullptr) {
		accept = true;
	}
	$assign(key, $new($GSSCredentialImpl$SearchKey, mech, $GSSCredential::INITIATE_AND_ACCEPT));
	$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
	if (element != nullptr) {
		initiate = true;
		accept = true;
	}
	if (initiate && accept) {
		return $GSSCredential::INITIATE_AND_ACCEPT;
	} else if (initiate) {
		return $GSSCredential::INITIATE_ONLY;
	} else if (accept) {
		return $GSSCredential::ACCEPT_ONLY;
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::BAD_MECH, mech);
	}
}

$OidArray* GSSCredentialImpl::getMechs() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($Vector, result, $new($Vector, $nc(this->hashtable)->size()));
	{
		$var($Enumeration, e, $nc(this->hashtable)->keys());
		for (; $nc(e)->hasMoreElements();) {
			$var($GSSCredentialImpl$SearchKey, tempKey, $cast($GSSCredentialImpl$SearchKey, e->nextElement()));
			result->addElement($($nc(tempKey)->getMech()));
		}
	}
	return $fcast($OidArray, result->toArray($$new($OidArray, 0)));
}

void GSSCredentialImpl::add($GSSName* name, int32_t initLifetime, int32_t acceptLifetime, $Oid* mech$renamed, int32_t usage) {
	$var($Oid, mech, mech$renamed);
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	if (mech == nullptr) {
		$init($ProviderList);
		$assign(mech, $ProviderList::DEFAULT_MECH_OID);
	}
	$var($GSSCredentialImpl$SearchKey, key, $new($GSSCredentialImpl$SearchKey, mech, usage));
	if ($nc(this->hashtable)->containsKey(key)) {
		$throwNew($GSSExceptionImpl, $GSSException::DUPLICATE_ELEMENT, $$str({"Duplicate element found: "_s, $(getElementStr(mech, usage))}));
	}
	$var($GSSNameSpi, nameElement, name == nullptr ? ($GSSNameSpi*)nullptr : $nc(($cast($GSSNameImpl, name)))->getElement(mech));
	$set(this, tempCred, $nc(this->gssManager)->getCredentialElement(nameElement, initLifetime, acceptLifetime, mech, usage));
	if (this->tempCred != nullptr) {
		bool var$0 = usage == $GSSCredential::INITIATE_AND_ACCEPT;
		if (var$0) {
			bool var$1 = !$nc(this->tempCred)->isAcceptorCredential();
			var$0 = (var$1 || !$nc(this->tempCred)->isInitiatorCredential());
		}
		if (var$0) {
			int32_t currentUsage = 0;
			int32_t desiredUsage = 0;
			if (!$nc(this->tempCred)->isInitiatorCredential()) {
				currentUsage = $GSSCredential::ACCEPT_ONLY;
				desiredUsage = $GSSCredential::INITIATE_ONLY;
			} else {
				currentUsage = $GSSCredential::INITIATE_ONLY;
				desiredUsage = $GSSCredential::ACCEPT_ONLY;
			}
			$assign(key, $new($GSSCredentialImpl$SearchKey, mech, currentUsage));
			$nc(this->hashtable)->put(key, this->tempCred);
			$set(this, tempCred, $nc(this->gssManager)->getCredentialElement(nameElement, initLifetime, acceptLifetime, mech, desiredUsage));
			$assign(key, $new($GSSCredentialImpl$SearchKey, mech, desiredUsage));
			$nc(this->hashtable)->put(key, this->tempCred);
		} else {
			$nc(this->hashtable)->put(key, this->tempCred);
		}
	}
}

bool GSSCredentialImpl::equals(Object$* another) {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	if ($equals(this, another)) {
		return true;
	}
	if (!($instanceOf(GSSCredentialImpl, another))) {
		return false;
	}
	return false;
}

int32_t GSSCredentialImpl::hashCode() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	return 1;
}

$GSSCredentialSpi* GSSCredentialImpl::getElement($Oid* mechOid$renamed, bool initiate) {
	$var($Oid, mechOid, mechOid$renamed);
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($GSSCredentialImpl$SearchKey, key, nullptr);
	$var($GSSCredentialSpi, element, nullptr);
	if (mechOid == nullptr) {
		$init($ProviderList);
		$assign(mechOid, $ProviderList::DEFAULT_MECH_OID);
		$assign(key, $new($GSSCredentialImpl$SearchKey, mechOid, initiate ? $GSSCredential::INITIATE_ONLY : $GSSCredential::ACCEPT_ONLY));
		$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
		if (element == nullptr) {
			$assign(key, $new($GSSCredentialImpl$SearchKey, mechOid, $GSSCredential::INITIATE_AND_ACCEPT));
			$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
			if (element == nullptr) {
				$var($ObjectArray, elements, $nc($($nc(this->hashtable)->entrySet()))->toArray());
				for (int32_t i = 0; i < $nc(elements)->length; ++i) {
					$assign(element, $cast($GSSCredentialSpi, $nc(($cast($Map$Entry, elements->get(i))))->getValue()));
					if ($nc(element)->isInitiatorCredential() == initiate) {
						break;
					}
				}
			}
		}
	} else {
		if (initiate) {
			$assign(key, $new($GSSCredentialImpl$SearchKey, mechOid, $GSSCredential::INITIATE_ONLY));
		} else {
			$assign(key, $new($GSSCredentialImpl$SearchKey, mechOid, $GSSCredential::ACCEPT_ONLY));
		}
		$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
		if (element == nullptr) {
			$assign(key, $new($GSSCredentialImpl$SearchKey, mechOid, $GSSCredential::INITIATE_AND_ACCEPT));
			$assign(element, $cast($GSSCredentialSpi, $nc(this->hashtable)->get(key)));
		}
	}
	if (element == nullptr) {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CRED, $$str({"No credential found for: "_s, $(getElementStr(mechOid, initiate ? $GSSCredential::INITIATE_ONLY : $GSSCredential::ACCEPT_ONLY))}));
	}
	return element;
}

$Set* GSSCredentialImpl::getElements() {
	$var($HashSet, retVal, $new($HashSet, $nc(this->hashtable)->size()));
	$var($Enumeration, values, $nc(this->hashtable)->elements());
	while ($nc(values)->hasMoreElements()) {
		$var($GSSCredentialSpi, o, $cast($GSSCredentialSpi, values->nextElement()));
		retVal->add(o);
	}
	return retVal;
}

$String* GSSCredentialImpl::getElementStr($Oid* mechOid, int32_t usage) {
	$init(GSSCredentialImpl);
	$var($String, displayString, $nc(mechOid)->toString());
	if (usage == $GSSCredential::INITIATE_ONLY) {
		$assign(displayString, $nc(displayString)->concat(" usage: Initiate"_s));
	} else if (usage == $GSSCredential::ACCEPT_ONLY) {
		$assign(displayString, $nc(displayString)->concat(" usage: Accept"_s));
	} else {
		$assign(displayString, $nc(displayString)->concat(" usage: Initiate and Accept"_s));
	}
	return displayString;
}

$String* GSSCredentialImpl::toString() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This credential is no longer valid"_s);
	}
	$var($GSSCredentialSpi, element, nullptr);
	$var($StringBuilder, sb, $new($StringBuilder, "[GSSCredential: "_s));
	$var($ObjectArray, elements, $nc($($nc(this->hashtable)->entrySet()))->toArray());
	for (int32_t i = 0; i < $nc(elements)->length; ++i) {
		try {
			sb->append(u'\n');
			$assign(element, $cast($GSSCredentialSpi, $nc(($cast($Map$Entry, elements->get(i))))->getValue()));
			sb->append($($of($nc(element)->getName())));
			sb->append(u' ');
			sb->append($($of($nc(element)->getMechanism())));
			sb->append($nc(element)->isInitiatorCredential() ? " Initiate"_s : ""_s);
			sb->append($nc(element)->isAcceptorCredential() ? " Accept"_s : ""_s);
			sb->append(" ["_s);
			sb->append($of($nc($of(element))->getClass()));
			sb->append(u']');
		} catch ($GSSException&) {
			$catch();
		}
	}
	sb->append(u']');
	return sb->toString();
}

GSSCredentialImpl::GSSCredentialImpl() {
}

$Class* GSSCredentialImpl::load$($String* name, bool initialize) {
	$loadClass(GSSCredentialImpl, name, initialize, &_GSSCredentialImpl_ClassInfo_, allocate$GSSCredentialImpl);
	return class$;
}

$Class* GSSCredentialImpl::class$ = nullptr;

		} // jgss
	} // security
} // sun