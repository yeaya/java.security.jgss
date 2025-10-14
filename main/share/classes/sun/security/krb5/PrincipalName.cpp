#include <sun/security/krb5/PrincipalName.h>

#include <java/io/BufferedOutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Boolean.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/Error.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/util/Arrays.h>
#include <java/util/Locale.h>
#include <java/util/Vector.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/ccache/CCacheOutputStream.h>
#include <sun/security/krb5/internal/util/KerberosString.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef ENGLISH
#undef FALSE
#undef KRB_NT_ENTERPRISE
#undef KRB_NT_PRINCIPAL
#undef KRB_NT_SRV_HST
#undef KRB_NT_SRV_INST
#undef KRB_NT_SRV_XHST
#undef KRB_NT_UID
#undef KRB_NT_UNKNOWN
#undef NAME_COMPONENT_SEPARATOR
#undef NAME_COMPONENT_SEPARATOR_STR
#undef NAME_REALM_SEPARATOR
#undef NAME_REALM_SEPARATOR_STR
#undef NAME_STRINGS_OFFSET
#undef REALM_COMPONENT_SEPARATOR
#undef REALM_COMPONENT_SEPARATOR_STR
#undef TAG_CONTEXT
#undef TGS_DEFAULT_NT
#undef TGS_DEFAULT_SRV_NAME
#undef UNSAFE

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $byteArray2 = $Array<int8_t, 2>;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $SecurityException = ::java::lang::SecurityException;
using $Field = ::java::lang::reflect::Field;
using $BigInteger = ::java::math::BigInteger;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $Arrays = ::java::util::Arrays;
using $Locale = ::java::util::Locale;
using $Vector = ::java::util::Vector;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Config = ::sun::security::krb5::Config;
using $KrbException = ::sun::security::krb5::KrbException;
using $Realm = ::sun::security::krb5::Realm;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $CCacheOutputStream = ::sun::security::krb5::internal::ccache::CCacheOutputStream;
using $KerberosString = ::sun::security::krb5::internal::util::KerberosString;
using $KrbDataOutputStream = ::sun::security::krb5::internal::util::KrbDataOutputStream;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _PrincipalName_FieldInfo_[] = {
	{"KRB_NT_UNKNOWN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, KRB_NT_UNKNOWN)},
	{"KRB_NT_PRINCIPAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, KRB_NT_PRINCIPAL)},
	{"KRB_NT_SRV_INST", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, KRB_NT_SRV_INST)},
	{"KRB_NT_SRV_HST", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, KRB_NT_SRV_HST)},
	{"KRB_NT_SRV_XHST", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, KRB_NT_SRV_XHST)},
	{"KRB_NT_UID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, KRB_NT_UID)},
	{"KRB_NT_ENTERPRISE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, KRB_NT_ENTERPRISE)},
	{"TGS_DEFAULT_SRV_NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PrincipalName, TGS_DEFAULT_SRV_NAME)},
	{"TGS_DEFAULT_NT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, TGS_DEFAULT_NT)},
	{"NAME_COMPONENT_SEPARATOR", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, NAME_COMPONENT_SEPARATOR)},
	{"NAME_REALM_SEPARATOR", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, NAME_REALM_SEPARATOR)},
	{"REALM_COMPONENT_SEPARATOR", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PrincipalName, REALM_COMPONENT_SEPARATOR)},
	{"NAME_COMPONENT_SEPARATOR_STR", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PrincipalName, NAME_COMPONENT_SEPARATOR_STR)},
	{"NAME_REALM_SEPARATOR_STR", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PrincipalName, NAME_REALM_SEPARATOR_STR)},
	{"REALM_COMPONENT_SEPARATOR_STR", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PrincipalName, REALM_COMPONENT_SEPARATOR_STR)},
	{"nameType", "I", nullptr, $PRIVATE | $FINAL, $field(PrincipalName, nameType)},
	{"nameStrings", "[Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(PrincipalName, nameStrings)},
	{"nameRealm", "Lsun/security/krb5/Realm;", nullptr, $PRIVATE | $FINAL, $field(PrincipalName, nameRealm)},
	{"realmDeduced", "Z", nullptr, $PRIVATE | $FINAL, $field(PrincipalName, realmDeduced)},
	{"salt", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(PrincipalName, salt)},
	{"NAME_STRINGS_OFFSET", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PrincipalName, NAME_STRINGS_OFFSET)},
	{"UNSAFE", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PrincipalName, UNSAFE)},
	{}
};

$MethodInfo _PrincipalName_MethodInfo_[] = {
	{"<init>", "(I[Ljava/lang/String;Lsun/security/krb5/Realm;)V", nullptr, $PUBLIC, $method(static_cast<void(PrincipalName::*)(int32_t,$StringArray*,$Realm*)>(&PrincipalName::init$))},
	{"<init>", "([Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(PrincipalName::*)($StringArray*,$String*)>(&PrincipalName::init$)), "sun.security.krb5.RealmException"},
	{"<init>", "(Lsun/security/util/DerValue;Lsun/security/krb5/Realm;)V", nullptr, $PUBLIC, $method(static_cast<void(PrincipalName::*)($DerValue*,$Realm*)>(&PrincipalName::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"<init>", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(PrincipalName::*)($String*,int32_t,$String*)>(&PrincipalName::init$)), "sun.security.krb5.RealmException"},
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(static_cast<void(PrincipalName::*)($String*,int32_t)>(&PrincipalName::init$)), "sun.security.krb5.RealmException"},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(PrincipalName::*)($String*)>(&PrincipalName::init$)), "sun.security.krb5.RealmException"},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(PrincipalName::*)($String*,$String*)>(&PrincipalName::init$)), "sun.security.krb5.RealmException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getInstanceComponent", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getNameString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getNameStrings", "()[Ljava/lang/String;", nullptr, $PUBLIC},
	{"getNameType", "()I", nullptr, $PUBLIC},
	{"getPrincipalNameAsString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getRealm", "()Lsun/security/krb5/Realm;", nullptr, $PUBLIC},
	{"getRealmAsString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getRealmString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getSalt", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isRealmDeduced", "()Z", nullptr, $PUBLIC},
	{"mapHostToRealm", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $method(static_cast<$String*(*)($String*)>(&PrincipalName::mapHostToRealm))},
	{"match", "(Lsun/security/krb5/PrincipalName;)Z", nullptr, $PUBLIC},
	{"parse", "(Lsun/security/util/DerInputStream;BZLsun/security/krb5/Realm;)Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $STATIC, $method(static_cast<PrincipalName*(*)($DerInputStream*,int8_t,bool,$Realm*)>(&PrincipalName::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{"parseName", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$StringArray*(*)($String*)>(&PrincipalName::parseName))},
	{"tgsService", "(Ljava/lang/String;Ljava/lang/String;)Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $STATIC, $method(static_cast<PrincipalName*(*)($String*,$String*)>(&PrincipalName::tgsService)), "sun.security.krb5.KrbException"},
	{"toByteArray", "()[[B", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"validateNameStrings", "([Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($StringArray*)>(&PrincipalName::validateNameStrings))},
	{"writePrincipal", "(Lsun/security/krb5/internal/ccache/CCacheOutputStream;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _PrincipalName_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.PrincipalName",
	"java.lang.Object",
	"java.lang.Cloneable",
	_PrincipalName_FieldInfo_,
	_PrincipalName_MethodInfo_
};

$Object* allocate$PrincipalName($Class* clazz) {
	return $of($alloc(PrincipalName));
}


$String* PrincipalName::TGS_DEFAULT_SRV_NAME = nullptr;
$String* PrincipalName::NAME_COMPONENT_SEPARATOR_STR = nullptr;
$String* PrincipalName::NAME_REALM_SEPARATOR_STR = nullptr;
$String* PrincipalName::REALM_COMPONENT_SEPARATOR_STR = nullptr;
int64_t PrincipalName::NAME_STRINGS_OFFSET = 0;
$Unsafe* PrincipalName::UNSAFE = nullptr;

void PrincipalName::init$(int32_t nameType, $StringArray* nameStrings, $Realm* nameRealm) {
	$set(this, salt, nullptr);
	if (nameRealm == nullptr) {
		$throwNew($IllegalArgumentException, "Null realm not allowed"_s);
	}
	validateNameStrings(nameStrings);
	this->nameType = nameType;
	$set(this, nameStrings, $cast($StringArray, $nc(nameStrings)->clone()));
	$set(this, nameRealm, nameRealm);
	this->realmDeduced = false;
}

void PrincipalName::init$($StringArray* nameParts, $String* realm) {
	PrincipalName::init$(PrincipalName::KRB_NT_UNKNOWN, nameParts, $$new($Realm, realm));
}

void PrincipalName::validateNameStrings($StringArray* ns) {
	$init(PrincipalName);
	if (ns == nullptr) {
		$throwNew($IllegalArgumentException, "Null nameStrings not allowed"_s);
	}
	if ($nc(ns)->length == 0) {
		$throwNew($IllegalArgumentException, "Empty nameStrings not allowed"_s);
	}
	{
		$var($StringArray, arr$, ns);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, s, arr$->get(i$));
			{
				if (s == nullptr) {
					$throwNew($IllegalArgumentException, "Null nameString not allowed"_s);
				}
				if ($nc(s)->isEmpty()) {
					$throwNew($IllegalArgumentException, "Empty nameString not allowed"_s);
				}
			}
		}
	}
}

$Object* PrincipalName::clone() {
	try {
		$var(PrincipalName, pName, $cast(PrincipalName, $Cloneable::clone()));
		$nc(PrincipalName::UNSAFE)->putReference(this, PrincipalName::NAME_STRINGS_OFFSET, $($nc(this->nameStrings)->clone()));
		return $of(pName);
	} catch ($CloneNotSupportedException&) {
		$var($CloneNotSupportedException, ex, $catch());
		$throwNew($AssertionError, $of("Should never happen"_s));
	}
	$shouldNotReachHere();
}

bool PrincipalName::equals(Object$* o) {
	if ($equals(this, o)) {
		return true;
	}
	if ($instanceOf(PrincipalName, o)) {
		$var(PrincipalName, other, $cast(PrincipalName, o));
		bool var$0 = $nc(this->nameRealm)->equals($nc(other)->nameRealm);
		return var$0 && $Arrays::equals(this->nameStrings, $nc(other)->nameStrings);
	}
	return false;
}

void PrincipalName::init$($DerValue* encoding, $Realm* realm) {
	$set(this, salt, nullptr);
	if (realm == nullptr) {
		$throwNew($IllegalArgumentException, "Null realm not allowed"_s);
	}
	this->realmDeduced = false;
	$set(this, nameRealm, realm);
	$var($DerValue, der, nullptr);
	if (encoding == nullptr) {
		$throwNew($IllegalArgumentException, "Null encoding not allowed"_s);
	}
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 0) {
		$var($BigInteger, bint, $nc($(der->getData()))->getBigInteger());
		this->nameType = $nc(bint)->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 1) {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		if ($nc(subDer)->getTag() != $DerValue::tag_SequenceOf) {
			$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
		}
		$var($Vector, v, $new($Vector));
		$var($DerValue, subSubDer, nullptr);
		while ($nc($($nc(subDer)->getData()))->available() > 0) {
			$assign(subSubDer, $nc($(subDer->getData()))->getDerValue());
			$var($String, namePart, $$new($KerberosString, subSubDer)->toString());
			v->addElement(namePart);
		}
		$set(this, nameStrings, $new($StringArray, v->size()));
		v->copyInto(this->nameStrings);
		validateNameStrings(this->nameStrings);
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

PrincipalName* PrincipalName::parse($DerInputStream* data, int8_t explicitTag, bool optional, $Realm* realm$renamed) {
	$init(PrincipalName);
	$var($Realm, realm, realm$renamed);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		if (realm == nullptr) {
			$assign(realm, $Realm::getDefault());
		}
		return $new(PrincipalName, subDer, realm);
	}
}

$StringArray* PrincipalName::parseName($String* name) {
	$init(PrincipalName);
	$var($Vector, tempStrings, $new($Vector));
	$var($String, temp, name);
	int32_t i = 0;
	int32_t componentStart = 0;
	$var($String, component, nullptr);
	while (i < $nc(temp)->length()) {
		if (temp->charAt(i) == PrincipalName::NAME_COMPONENT_SEPARATOR) {
			if (i > 0 && temp->charAt(i - 1) == u'\\') {
				$var($String, var$0, $(temp->substring(0, i - 1)));
				$assign(temp, $concat(var$0, $(temp->substring(i, temp->length()))));
				continue;
			} else {
				if (componentStart <= i) {
					$assign(component, temp->substring(componentStart, i));
					tempStrings->addElement(component);
				}
				componentStart = i + 1;
			}
		} else if (temp->charAt(i) == PrincipalName::NAME_REALM_SEPARATOR) {
			if (i > 0 && temp->charAt(i - 1) == u'\\') {
				$var($String, var$1, $(temp->substring(0, i - 1)));
				$assign(temp, $concat(var$1, $(temp->substring(i, temp->length()))));
				continue;
			} else {
				if (componentStart < i) {
					$assign(component, temp->substring(componentStart, i));
					tempStrings->addElement(component);
				}
				componentStart = i + 1;
				break;
			}
		}
		++i;
	}
	if (i == $nc(temp)->length()) {
		$assign(component, temp->substring(componentStart, i));
		tempStrings->addElement(component);
	}
	$var($StringArray, result, $new($StringArray, tempStrings->size()));
	tempStrings->copyInto(result);
	return result;
}

void PrincipalName::init$($String* name, int32_t type, $String* realm$renamed) {
	$var($String, realm, realm$renamed);
	$set(this, salt, nullptr);
	if (name == nullptr) {
		$throwNew($IllegalArgumentException, "Null name not allowed"_s);
	}
	$var($StringArray, nameParts, parseName(name));
	validateNameStrings(nameParts);
	if (realm == nullptr) {
		$assign(realm, $Realm::parseRealmAtSeparator(name));
	}
	this->realmDeduced = realm == nullptr;
	switch (type) {
	case PrincipalName::KRB_NT_SRV_HST:
		{
			if ($nc(nameParts)->length >= 2) {
				$var($String, hostName, nameParts->get(1));
				$var($Boolean, option, nullptr);
				try {
					$assign(option, $nc($($Config::getInstance()))->getBooleanObject($$new($StringArray, {
						"libdefaults"_s,
						"dns_canonicalize_hostname"_s
					})));
				} catch ($KrbException&) {
					$var($KrbException, e, $catch());
					$assign(option, nullptr);
				}
				$init($Boolean);
				if (option != $Boolean::FALSE) {
					try {
						$var($String, canonicalized, $nc(($($InetAddress::getByName(hostName))))->getCanonicalHostName());
						$init($Locale);
						if ($($nc(canonicalized)->toLowerCase($Locale::ENGLISH))->startsWith($$str({$($nc(hostName)->toLowerCase($Locale::ENGLISH)), "."_s}))) {
							$assign(hostName, canonicalized);
						}
					} catch ($UnknownHostException&) {
						$var($Exception, e, $catch());
					} catch ($SecurityException&) {
						$var($Exception, e, $catch());
					}
					if ($nc(hostName)->endsWith("."_s)) {
						$assign(hostName, hostName->substring(0, hostName->length() - 1));
					}
				}
				$init($Locale);
				nameParts->set(1, $($nc(hostName)->toLowerCase($Locale::ENGLISH)));
			}
			$set(this, nameStrings, nameParts);
			this->nameType = type;
			if (realm != nullptr) {
				$set(this, nameRealm, $new($Realm, realm));
			} else {
				$var($String, mapRealm, mapHostToRealm($nc(nameParts)->get(1)));
				if (mapRealm != nullptr) {
					$set(this, nameRealm, $new($Realm, mapRealm));
				} else {
					$set(this, nameRealm, $Realm::getDefault());
				}
			}
			break;
		}
	case PrincipalName::KRB_NT_UNKNOWN:
		{}
	case PrincipalName::KRB_NT_PRINCIPAL:
		{}
	case PrincipalName::KRB_NT_SRV_INST:
		{}
	case PrincipalName::KRB_NT_SRV_XHST:
		{}
	case PrincipalName::KRB_NT_UID:
		{}
	case PrincipalName::KRB_NT_ENTERPRISE:
		{
			$set(this, nameStrings, nameParts);
			this->nameType = type;
			if (realm != nullptr) {
				$set(this, nameRealm, $new($Realm, realm));
			} else {
				$set(this, nameRealm, $Realm::getDefault());
			}
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException, "Illegal name type"_s);
		}
	}
}

void PrincipalName::init$($String* name, int32_t type) {
	PrincipalName::init$(name, type, ($String*)nullptr);
}

void PrincipalName::init$($String* name) {
	PrincipalName::init$(name, PrincipalName::KRB_NT_UNKNOWN);
}

void PrincipalName::init$($String* name, $String* realm) {
	PrincipalName::init$(name, PrincipalName::KRB_NT_UNKNOWN, realm);
}

PrincipalName* PrincipalName::tgsService($String* r1, $String* r2) {
	$init(PrincipalName);
	return $new(PrincipalName, PrincipalName::KRB_NT_SRV_INST, $$new($StringArray, {
		PrincipalName::TGS_DEFAULT_SRV_NAME,
		r1
	}), $$new($Realm, r2));
}

$String* PrincipalName::getRealmAsString() {
	return getRealmString();
}

$String* PrincipalName::getPrincipalNameAsString() {
	$var($StringBuilder, temp, $new($StringBuilder, $nc(this->nameStrings)->get(0)));
	for (int32_t i = 1; i < $nc(this->nameStrings)->length; ++i) {
		temp->append($nc(this->nameStrings)->get(i));
	}
	return temp->toString();
}

int32_t PrincipalName::hashCode() {
	return $nc($(toString()))->hashCode();
}

$String* PrincipalName::getName() {
	return toString();
}

int32_t PrincipalName::getNameType() {
	return this->nameType;
}

$StringArray* PrincipalName::getNameStrings() {
	return $cast($StringArray, $nc(this->nameStrings)->clone());
}

$byteArray2* PrincipalName::toByteArray() {
	$var($byteArray2, result, $new($byteArray2, $nc(this->nameStrings)->length));
	for (int32_t i = 0; i < $nc(this->nameStrings)->length; ++i) {
		result->set(i, $($nc($nc(this->nameStrings)->get(i))->getBytes()));
	}
	return result;
}

$String* PrincipalName::getRealmString() {
	return $nc(this->nameRealm)->toString();
}

$Realm* PrincipalName::getRealm() {
	return this->nameRealm;
}

$String* PrincipalName::getSalt() {
	if (this->salt == nullptr) {
		$var($StringBuilder, salt, $new($StringBuilder));
		salt->append($($nc(this->nameRealm)->toString()));
		for (int32_t i = 0; i < $nc(this->nameStrings)->length; ++i) {
			salt->append($nc(this->nameStrings)->get(i));
		}
		return salt->toString();
	}
	return this->salt;
}

$String* PrincipalName::toString() {
	$var($StringBuilder, str, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(this->nameStrings)->length; ++i) {
		if (i > 0) {
			str->append("/"_s);
		}
		$var($String, n, $nc(this->nameStrings)->get(i));
		$assign(n, $nc(n)->replace(static_cast<$CharSequence*>("@"_s), static_cast<$CharSequence*>("\\@"_s)));
		str->append(n);
	}
	str->append("@"_s);
	str->append($($nc(this->nameRealm)->toString()));
	return str->toString();
}

$String* PrincipalName::getNameString() {
	$var($StringBuilder, str, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(this->nameStrings)->length; ++i) {
		if (i > 0) {
			str->append("/"_s);
		}
		str->append($nc(this->nameStrings)->get(i));
	}
	return str->toString();
}

$bytes* PrincipalName::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	$var($BigInteger, bint, $BigInteger::valueOf((int64_t)this->nameType));
	temp->putInteger(bint);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	$var($DerValueArray, der, $new($DerValueArray, $nc(this->nameStrings)->length));
	for (int32_t i = 0; i < $nc(this->nameStrings)->length; ++i) {
		der->set(i, $($$new($KerberosString, $nc(this->nameStrings)->get(i))->toDerValue()));
	}
	temp->putSequence(der);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

bool PrincipalName::match(PrincipalName* pname) {
	bool matched = true;
	if ((this->nameRealm != nullptr) && ($nc(pname)->nameRealm != nullptr)) {
		if (!($nc($($nc(this->nameRealm)->toString()))->equalsIgnoreCase($($nc(pname->nameRealm)->toString())))) {
			matched = false;
		}
	}
	if ($nc(this->nameStrings)->length != $nc($nc(pname)->nameStrings)->length) {
		matched = false;
	} else {
		for (int32_t i = 0; i < $nc(this->nameStrings)->length; ++i) {
			if (!($nc($nc(this->nameStrings)->get(i))->equalsIgnoreCase($nc(pname->nameStrings)->get(i)))) {
				matched = false;
			}
		}
	}
	return matched;
}

void PrincipalName::writePrincipal($CCacheOutputStream* cos) {
	$nc(cos)->write32(this->nameType);
	cos->write32($nc(this->nameStrings)->length);
	$var($bytes, realmBytes, nullptr);
	$assign(realmBytes, $nc($($nc(this->nameRealm)->toString()))->getBytes());
	cos->write32(realmBytes->length);
	cos->write(realmBytes, 0, realmBytes->length);
	$var($bytes, bytes, nullptr);
	for (int32_t i = 0; i < $nc(this->nameStrings)->length; ++i) {
		$assign(bytes, $nc($nc(this->nameStrings)->get(i))->getBytes());
		cos->write32(bytes->length);
		cos->write(bytes, 0, bytes->length);
	}
}

$String* PrincipalName::getInstanceComponent() {
	if (this->nameStrings != nullptr && $nc(this->nameStrings)->length >= 2) {
		return $new($String, $nc(this->nameStrings)->get(1));
	}
	return nullptr;
}

$String* PrincipalName::mapHostToRealm($String* name) {
	$init(PrincipalName);
	$var($String, result, nullptr);
	try {
		$var($String, subname, nullptr);
		$var($Config, c, $Config::getInstance());
		if (($assign(result, $nc(c)->get($$new($StringArray, {
			"domain_realm"_s,
			name
		})))) != nullptr) {
			return result;
		} else {
			for (int32_t i = 1; i < $nc(name)->length(); ++i) {
				bool var$0 = (name->charAt(i) == u'.');
				if (var$0 && (i != name->length() - 1)) {
					$assign(subname, name->substring(i));
					$assign(result, c->get($$new($StringArray, {
						"domain_realm"_s,
						subname
					})));
					if (result != nullptr) {
						break;
					} else {
						$assign(subname, name->substring(i + 1));
						$assign(result, c->get($$new($StringArray, {
							"domain_realm"_s,
							subname
						})));
						if (result != nullptr) {
							break;
						}
					}
				}
			}
		}
	} catch ($KrbException&) {
		$catch();
	}
	return result;
}

bool PrincipalName::isRealmDeduced() {
	return this->realmDeduced;
}

void clinit$PrincipalName($Class* class$) {
	$assignStatic(PrincipalName::TGS_DEFAULT_SRV_NAME, "krbtgt"_s);
	$assignStatic(PrincipalName::NAME_COMPONENT_SEPARATOR_STR, "/"_s);
	$assignStatic(PrincipalName::NAME_REALM_SEPARATOR_STR, "@"_s);
	$assignStatic(PrincipalName::REALM_COMPONENT_SEPARATOR_STR, "."_s);
	$beforeCallerSensitive();
	{
		try {
			$var($Unsafe, unsafe, $Unsafe::getUnsafe());
			PrincipalName::NAME_STRINGS_OFFSET = $nc(unsafe)->objectFieldOffset($(PrincipalName::class$->getDeclaredField("nameStrings"_s)));
			$assignStatic(PrincipalName::UNSAFE, unsafe);
		} catch ($ReflectiveOperationException&) {
			$var($ReflectiveOperationException, e, $catch());
			$throwNew($Error, static_cast<$Throwable*>(e));
		}
	}
}

PrincipalName::PrincipalName() {
}

$Class* PrincipalName::load$($String* name, bool initialize) {
	$loadClass(PrincipalName, name, initialize, &_PrincipalName_ClassInfo_, clinit$PrincipalName, allocate$PrincipalName);
	return class$;
}

$Class* PrincipalName::class$ = nullptr;

		} // krb5
	} // security
} // sun