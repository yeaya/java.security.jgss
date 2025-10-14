#include <sun/security/jgss/ProviderList.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <java/security/Security.h>
#include <java/util/ArrayList.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSExceptionImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/ProviderList$PreferencesEntry.h>
#include <sun/security/jgss/spi/MechanismFactory.h>
#include <sun/security/jgss/wrapper/NativeGSSFactory.h>
#include <sun/security/jgss/wrapper/SunNativeProvider.h>
#include <jcpp.h>

#undef BAD_MECH
#undef DEFAULT_MECH_OID
#undef GSS_KRB5_MECH_OID
#undef PROV_PROP_PREFIX
#undef PROV_PROP_PREFIX_LEN
#undef SPI_MECH_FACTORY_TYPE

using $ProviderArray = $Array<::java::security::Provider>;
using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Provider = ::java::security::Provider;
using $Security = ::java::security::Security;
using $ArrayList = ::java::util::ArrayList;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $GSSException = ::org::ietf::jgss::GSSException;
using $Oid = ::org::ietf::jgss::Oid;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $GSSCaller = ::sun::security::jgss::GSSCaller;
using $GSSExceptionImpl = ::sun::security::jgss::GSSExceptionImpl;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $ProviderList$PreferencesEntry = ::sun::security::jgss::ProviderList$PreferencesEntry;
using $MechanismFactory = ::sun::security::jgss::spi::MechanismFactory;
using $NativeGSSFactory = ::sun::security::jgss::wrapper::NativeGSSFactory;
using $SunNativeProvider = ::sun::security::jgss::wrapper::SunNativeProvider;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _ProviderList_FieldInfo_[] = {
	{"PROV_PROP_PREFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, PROV_PROP_PREFIX)},
	{"PROV_PROP_PREFIX_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, PROV_PROP_PREFIX_LEN)},
	{"SPI_MECH_FACTORY_TYPE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, SPI_MECH_FACTORY_TYPE)},
	{"DEFAULT_MECH_OID", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ProviderList, DEFAULT_MECH_OID)},
	{"preferences", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Lsun/security/jgss/ProviderList$PreferencesEntry;>;", $PRIVATE, $field(ProviderList, preferences)},
	{"factories", "Ljava/util/HashMap;", "Ljava/util/HashMap<Lsun/security/jgss/ProviderList$PreferencesEntry;Lsun/security/jgss/spi/MechanismFactory;>;", $PRIVATE, $field(ProviderList, factories)},
	{"mechs", "Ljava/util/HashSet;", "Ljava/util/HashSet<Lorg/ietf/jgss/Oid;>;", $PRIVATE, $field(ProviderList, mechs)},
	{"caller", "Lsun/security/jgss/GSSCaller;", nullptr, $PRIVATE | $FINAL, $field(ProviderList, caller)},
	{}
};

$MethodInfo _ProviderList_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/GSSCaller;Z)V", nullptr, $PUBLIC, $method(static_cast<void(ProviderList::*)($GSSCaller*,bool)>(&ProviderList::init$))},
	{"addAllMechsFromProvider", "(Ljava/security/Provider;)Z", nullptr, $PRIVATE, $method(static_cast<bool(ProviderList::*)($Provider*)>(&ProviderList::addAllMechsFromProvider))},
	{"addProviderAtEnd", "(Ljava/security/Provider;Lorg/ietf/jgss/Oid;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $method(static_cast<void(ProviderList::*)($Provider*,$Oid*)>(&ProviderList::addProviderAtEnd)), "org.ietf.jgss.GSSException"},
	{"addProviderAtFront", "(Ljava/security/Provider;Lorg/ietf/jgss/Oid;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $method(static_cast<void(ProviderList::*)($Provider*,$Oid*)>(&ProviderList::addProviderAtFront)), "org.ietf.jgss.GSSException"},
	{"createGSSException", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Exception;)Lorg/ietf/jgss/GSSException;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$GSSException*(*)($Provider*,$String*,$String*,$Exception*)>(&ProviderList::createGSSException))},
	{"getMechFactory", "(Lorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/MechanismFactory;", nullptr, $PUBLIC | $SYNCHRONIZED, $method(static_cast<$MechanismFactory*(ProviderList::*)($Oid*)>(&ProviderList::getMechFactory)), "org.ietf.jgss.GSSException"},
	{"getMechFactory", "(Lorg/ietf/jgss/Oid;Ljava/security/Provider;)Lsun/security/jgss/spi/MechanismFactory;", nullptr, $PUBLIC | $SYNCHRONIZED, $method(static_cast<$MechanismFactory*(ProviderList::*)($Oid*,$Provider*)>(&ProviderList::getMechFactory)), "org.ietf.jgss.GSSException"},
	{"getMechFactory", "(Lsun/security/jgss/ProviderList$PreferencesEntry;Lorg/ietf/jgss/Oid;)Lsun/security/jgss/spi/MechanismFactory;", nullptr, $PRIVATE, $method(static_cast<$MechanismFactory*(ProviderList::*)($ProviderList$PreferencesEntry*,$Oid*)>(&ProviderList::getMechFactory)), "org.ietf.jgss.GSSException"},
	{"getMechFactoryImpl", "(Ljava/security/Provider;Ljava/lang/String;Lorg/ietf/jgss/Oid;Lsun/security/jgss/GSSCaller;)Lsun/security/jgss/spi/MechanismFactory;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$MechanismFactory*(*)($Provider*,$String*,$Oid*,$GSSCaller*)>(&ProviderList::getMechFactoryImpl)), "org.ietf.jgss.GSSException"},
	{"getMechs", "()[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC, $method(static_cast<$OidArray*(ProviderList::*)()>(&ProviderList::getMechs))},
	{"getOidFromMechFactoryProperty", "(Ljava/lang/String;)Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $method(static_cast<$Oid*(ProviderList::*)($String*)>(&ProviderList::getOidFromMechFactoryProperty)), "org.ietf.jgss.GSSException"},
	{"isMechFactoryProperty", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(static_cast<bool(ProviderList::*)($String*)>(&ProviderList::isMechFactoryProperty))},
	{}
};

$InnerClassInfo _ProviderList_InnerClassesInfo_[] = {
	{"sun.security.jgss.ProviderList$PreferencesEntry", "sun.security.jgss.ProviderList", "PreferencesEntry", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ProviderList_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.jgss.ProviderList",
	"java.lang.Object",
	nullptr,
	_ProviderList_FieldInfo_,
	_ProviderList_MethodInfo_,
	nullptr,
	nullptr,
	_ProviderList_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jgss.ProviderList$PreferencesEntry"
};

$Object* allocate$ProviderList($Class* clazz) {
	return $of($alloc(ProviderList));
}

$String* ProviderList::PROV_PROP_PREFIX = nullptr;
int32_t ProviderList::PROV_PROP_PREFIX_LEN = 0;
$String* ProviderList::SPI_MECH_FACTORY_TYPE = nullptr;
$Oid* ProviderList::DEFAULT_MECH_OID = nullptr;

void ProviderList::init$($GSSCaller* caller, bool useNative) {
	$set(this, preferences, $new($ArrayList, 5));
	$set(this, factories, $new($HashMap, 5));
	$set(this, mechs, $new($HashSet, 5));
	$set(this, caller, caller);
	$var($ProviderArray, provList, nullptr);
	if (useNative) {
		$assign(provList, $new($ProviderArray, 1));
		provList->set(0, $$new($SunNativeProvider));
	} else {
		$assign(provList, $Security::getProviders());
	}
	for (int32_t i = 0; i < $nc(provList)->length; ++i) {
		$var($Provider, prov, provList->get(i));
		try {
			addProviderAtEnd(prov, nullptr);
		} catch ($GSSException&) {
			$var($GSSException, ge, $catch());
			$GSSUtil::debug($$str({"Error in adding provider "_s, $($nc(prov)->getName()), ": "_s, ge}));
		}
	}
}

bool ProviderList::isMechFactoryProperty($String* prop) {
	bool var$0 = $nc(prop)->startsWith(ProviderList::PROV_PROP_PREFIX);
	return (var$0 || $nc(prop)->regionMatches(true, 0, ProviderList::PROV_PROP_PREFIX, 0, ProviderList::PROV_PROP_PREFIX_LEN));
}

$Oid* ProviderList::getOidFromMechFactoryProperty($String* prop) {
	$var($String, oidPart, $nc(prop)->substring(ProviderList::PROV_PROP_PREFIX_LEN));
	return $new($Oid, oidPart);
}

$MechanismFactory* ProviderList::getMechFactory($Oid* mechOid$renamed) {
	$synchronized(this) {
		$var($Oid, mechOid, mechOid$renamed);
		if (mechOid == nullptr) {
			$assign(mechOid, ProviderList::DEFAULT_MECH_OID);
		}
		return getMechFactory(mechOid, ($Provider*)nullptr);
	}
}

$MechanismFactory* ProviderList::getMechFactory($Oid* mechOid$renamed, $Provider* p) {
	$synchronized(this) {
		$var($Oid, mechOid, mechOid$renamed);
		if (mechOid == nullptr) {
			$assign(mechOid, ProviderList::DEFAULT_MECH_OID);
		}
		if (p == nullptr) {
			$var($String, className, nullptr);
			$var($ProviderList$PreferencesEntry, entry, nullptr);
			$var($Iterator, list, $nc(this->preferences)->iterator());
			while ($nc(list)->hasNext()) {
				$assign(entry, $cast($ProviderList$PreferencesEntry, list->next()));
				if ($nc(entry)->impliesMechanism(mechOid)) {
					$var($MechanismFactory, retVal, getMechFactory(entry, mechOid));
					if (retVal != nullptr) {
						return retVal;
					}
				}
			}
			$throwNew($GSSExceptionImpl, $GSSException::BAD_MECH, mechOid);
		} else {
			$var($ProviderList$PreferencesEntry, entry, $new($ProviderList$PreferencesEntry, p, mechOid));
			return getMechFactory(entry, mechOid);
		}
	}
}

$MechanismFactory* ProviderList::getMechFactory($ProviderList$PreferencesEntry* e, $Oid* mechOid) {
	$var($Provider, p, $nc(e)->getProvider());
	$var($ProviderList$PreferencesEntry, searchEntry, $new($ProviderList$PreferencesEntry, p, mechOid));
	$var($MechanismFactory, retVal, $cast($MechanismFactory, $nc(this->factories)->get(searchEntry)));
	if (retVal == nullptr) {
		$var($String, prop, $str({ProviderList::PROV_PROP_PREFIX, $($nc(mechOid)->toString())}));
		$var($String, className, $nc(p)->getProperty(prop));
		if (className != nullptr) {
			$assign(retVal, getMechFactoryImpl(p, className, mechOid, this->caller));
			$nc(this->factories)->put(searchEntry, retVal);
		} else if (e->getOid() != nullptr) {
			$throwNew($GSSExceptionImpl, $GSSException::BAD_MECH, $$str({"Provider "_s, $(p->getName()), " does not support mechanism "_s, mechOid}));
		}
	}
	return retVal;
}

$MechanismFactory* ProviderList::getMechFactoryImpl($Provider* p, $String* className, $Oid* mechOid, $GSSCaller* caller) {
	$init(ProviderList);
	$beforeCallerSensitive();
	try {
		$Class* baseClass = $Class::forName(ProviderList::SPI_MECH_FACTORY_TYPE);
		$var($ClassLoader, cl, $nc($of(p))->getClass()->getClassLoader());
		$Class* implClass = nullptr;
		if (cl != nullptr) {
			implClass = cl->loadClass(className);
		} else {
			implClass = $Class::forName(className);
		}
		if ($nc(baseClass)->isAssignableFrom(implClass)) {
			$load($GSSCaller);
			$var($Constructor, c, $nc(implClass)->getConstructor($$new($ClassArray, {$GSSCaller::class$})));
			$var($MechanismFactory, mf, ($cast($MechanismFactory, $nc(c)->newInstance($$new($ObjectArray, {$of(caller)})))));
			if ($instanceOf($NativeGSSFactory, mf)) {
				$nc(($cast($NativeGSSFactory, mf)))->setMech(mechOid);
			}
			return mf;
		} else {
			$throw($(createGSSException(p, className, $$str({"is not a "_s, ProviderList::SPI_MECH_FACTORY_TYPE}), nullptr)));
		}
	} catch ($ClassNotFoundException&) {
		$var($ClassNotFoundException, e, $catch());
		$throw($(createGSSException(p, className, "cannot be created"_s, e)));
	} catch ($NoSuchMethodException&) {
		$var($NoSuchMethodException, e, $catch());
		$throw($(createGSSException(p, className, "cannot be created"_s, e)));
	} catch ($InvocationTargetException&) {
		$var($InvocationTargetException, e, $catch());
		$throw($(createGSSException(p, className, "cannot be created"_s, e)));
	} catch ($InstantiationException&) {
		$var($InstantiationException, e, $catch());
		$throw($(createGSSException(p, className, "cannot be created"_s, e)));
	} catch ($IllegalAccessException&) {
		$var($IllegalAccessException, e, $catch());
		$throw($(createGSSException(p, className, "cannot be created"_s, e)));
	} catch ($SecurityException&) {
		$var($SecurityException, e, $catch());
		$throw($(createGSSException(p, className, "cannot be created"_s, e)));
	}
	$shouldNotReachHere();
}

$GSSException* ProviderList::createGSSException($Provider* p, $String* className, $String* trailingMsg, $Exception* cause) {
	$init(ProviderList);
	$var($String, errClassInfo, $str({className, " configured by "_s, $($nc(p)->getName()), " for GSS-API Mechanism Factory "_s}));
	return $new($GSSExceptionImpl, $GSSException::BAD_MECH, $$str({errClassInfo, trailingMsg}), cause);
}

$OidArray* ProviderList::getMechs() {
	return $fcast($OidArray, $nc(this->mechs)->toArray($$new($OidArray, 0)));
}

void ProviderList::addProviderAtFront($Provider* p, $Oid* mechOid) {
	$synchronized(this) {
		$var($ProviderList$PreferencesEntry, newEntry, $new($ProviderList$PreferencesEntry, p, mechOid));
		$var($ProviderList$PreferencesEntry, oldEntry, nullptr);
		bool foundSomeMech = false;
		$var($Iterator, list, $nc(this->preferences)->iterator());
		while ($nc(list)->hasNext()) {
			$assign(oldEntry, $cast($ProviderList$PreferencesEntry, list->next()));
			if (newEntry->implies(oldEntry)) {
				list->remove();
			}
		}
		if (mechOid == nullptr) {
			foundSomeMech = addAllMechsFromProvider(p);
		} else {
			$var($String, oidStr, $nc(mechOid)->toString());
			if ($nc(p)->getProperty($$str({ProviderList::PROV_PROP_PREFIX, oidStr})) == nullptr) {
				$throwNew($GSSExceptionImpl, $GSSException::BAD_MECH, $$str({"Provider "_s, $(p->getName()), " does not support "_s, oidStr}));
			}
			$nc(this->mechs)->add(mechOid);
			foundSomeMech = true;
		}
		if (foundSomeMech) {
			$nc(this->preferences)->add(0, newEntry);
		}
	}
}

void ProviderList::addProviderAtEnd($Provider* p, $Oid* mechOid) {
	$synchronized(this) {
		$var($ProviderList$PreferencesEntry, newEntry, $new($ProviderList$PreferencesEntry, p, mechOid));
		$var($ProviderList$PreferencesEntry, oldEntry, nullptr);
		bool foundSomeMech = false;
		$var($Iterator, list, $nc(this->preferences)->iterator());
		while ($nc(list)->hasNext()) {
			$assign(oldEntry, $cast($ProviderList$PreferencesEntry, list->next()));
			if ($nc(oldEntry)->implies(newEntry)) {
				return;
			}
		}
		if (mechOid == nullptr) {
			foundSomeMech = addAllMechsFromProvider(p);
		} else {
			$var($String, oidStr, $nc(mechOid)->toString());
			if ($nc(p)->getProperty($$str({ProviderList::PROV_PROP_PREFIX, oidStr})) == nullptr) {
				$throwNew($GSSExceptionImpl, $GSSException::BAD_MECH, $$str({"Provider "_s, $(p->getName()), " does not support "_s, oidStr}));
			}
			$nc(this->mechs)->add(mechOid);
			foundSomeMech = true;
		}
		if (foundSomeMech) {
			$nc(this->preferences)->add(newEntry);
		}
	}
}

bool ProviderList::addAllMechsFromProvider($Provider* p) {
	$var($String, prop, nullptr);
	bool retVal = false;
	$var($Enumeration, props, $nc(p)->keys());
	while ($nc(props)->hasMoreElements()) {
		$assign(prop, $cast($String, props->nextElement()));
		if (isMechFactoryProperty(prop)) {
			try {
				$var($Oid, mechOid, getOidFromMechFactoryProperty(prop));
				$nc(this->mechs)->add(mechOid);
				retVal = true;
			} catch ($GSSException&) {
				$var($GSSException, e, $catch());
				$GSSUtil::debug($$str({"Ignore the invalid property "_s, prop, " from provider "_s, $(p->getName())}));
			}
		}
	}
	return retVal;
}

void clinit$ProviderList($Class* class$) {
	$assignStatic(ProviderList::PROV_PROP_PREFIX, "GssApiMechanism."_s);
	$assignStatic(ProviderList::SPI_MECH_FACTORY_TYPE, "sun.security.jgss.spi.MechanismFactory"_s);
	ProviderList::PROV_PROP_PREFIX_LEN = $nc(ProviderList::PROV_PROP_PREFIX)->length();
	{
		$var($Oid, defOid, nullptr);
		$var($String, defaultOidStr, $GetPropertyAction::privilegedGetProperty("sun.security.jgss.mechanism"_s));
		if (defaultOidStr != nullptr) {
			$assign(defOid, $GSSUtil::createOid(defaultOidStr));
		}
		$init($GSSUtil);
		$assignStatic(ProviderList::DEFAULT_MECH_OID, defOid == nullptr ? $GSSUtil::GSS_KRB5_MECH_OID : defOid);
	}
}

ProviderList::ProviderList() {
}

$Class* ProviderList::load$($String* name, bool initialize) {
	$loadClass(ProviderList, name, initialize, &_ProviderList_ClassInfo_, clinit$ProviderList, allocate$ProviderList);
	return class$;
}

$Class* ProviderList::class$ = nullptr;

		} // jgss
	} // security
} // sun