#include <sun/security/krb5/Realm.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/LinkedList.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/RealmException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/util/KerberosString.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef AUTODEDUCEREALM
#undef NAME_REALM_SEPARATOR
#undef REALM_COMPONENT_SEPARATOR
#undef REALM_ILLCHAR
#undef REALM_NULL

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $AbstractStringBuilder = ::java::lang::AbstractStringBuilder;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $LinkedList = ::java::util::LinkedList;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Config = ::sun::security::krb5::Config;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $RealmException = ::sun::security::krb5::RealmException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KerberosString = ::sun::security::krb5::internal::util::KerberosString;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _Realm_FieldInfo_[] = {
	{"AUTODEDUCEREALM", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Realm, AUTODEDUCEREALM)},
	{"realm", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Realm, realm)},
	{}
};

$MethodInfo _Realm_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Realm::*)($String*)>(&Realm::init$)), "sun.security.krb5.RealmException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(Realm::*)($DerValue*)>(&Realm::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getDefault", "()Lsun/security/krb5/Realm;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Realm*(*)()>(&Realm::getDefault)), "sun.security.krb5.RealmException"},
	{"getRealmsList", "(Ljava/lang/String;Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$StringArray*(*)($String*,$String*)>(&Realm::getRealmsList))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isValidRealmString", "(Ljava/lang/String;)Z", nullptr, $PROTECTED | $STATIC, $method(static_cast<bool(*)($String*)>(&Realm::isValidRealmString))},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/Realm;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Realm*(*)($DerInputStream*,int8_t,bool)>(&Realm::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException,sun.security.krb5.RealmException"},
	{"parseCapaths", "(Ljava/lang/String;Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$StringArray*(*)($String*,$String*)>(&Realm::parseCapaths)), "sun.security.krb5.KrbException"},
	{"parseHierarchy", "(Ljava/lang/String;Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$StringArray*(*)($String*,$String*)>(&Realm::parseHierarchy))},
	{"parseRealm", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PROTECTED | $STATIC, $method(static_cast<$String*(*)($String*)>(&Realm::parseRealm)), "sun.security.krb5.RealmException"},
	{"parseRealmAtSeparator", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($String*)>(&Realm::parseRealmAtSeparator)), "sun.security.krb5.RealmException"},
	{"parseRealmComponent", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($String*)>(&Realm::parseRealmComponent))},
	{"subStringFrom", "([Ljava/lang/String;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($StringArray*,int32_t)>(&Realm::subStringFrom))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Realm_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.Realm",
	"java.lang.Object",
	"java.lang.Cloneable",
	_Realm_FieldInfo_,
	_Realm_MethodInfo_
};

$Object* allocate$Realm($Class* clazz) {
	return $of($alloc(Realm));
}

bool Realm::AUTODEDUCEREALM = false;

void Realm::init$($String* name) {
	$set(this, realm, parseRealm(name));
}

Realm* Realm::getDefault() {
	$init(Realm);
	try {
		return $new(Realm, $($nc($($Config::getInstance()))->getDefaultRealm()));
	} catch ($RealmException&) {
		$var($RealmException, re, $catch());
		$throw(re);
	} catch ($KrbException&) {
		$var($KrbException, ke, $catch());
		$throwNew($RealmException, static_cast<$Throwable*>(ke));
	}
	$shouldNotReachHere();
}

$Object* Realm::clone() {
	return $of(this);
}

bool Realm::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(Realm, obj))) {
		return false;
	}
	$var(Realm, that, $cast(Realm, obj));
	return $nc(this->realm)->equals($nc(that)->realm);
}

int32_t Realm::hashCode() {
	return $nc(this->realm)->hashCode();
}

void Realm::init$($DerValue* encoding) {
	if (encoding == nullptr) {
		$throwNew($IllegalArgumentException, "encoding can not be null"_s);
	}
	$set(this, realm, $$new($KerberosString, encoding)->toString());
	if (this->realm == nullptr || $nc(this->realm)->length() == 0) {
		$throwNew($RealmException, $Krb5::REALM_NULL);
	}
	if (!isValidRealmString(this->realm)) {
		$throwNew($RealmException, $Krb5::REALM_ILLCHAR);
	}
}

$String* Realm::toString() {
	return this->realm;
}

$String* Realm::parseRealmAtSeparator($String* name) {
	$init(Realm);
	if (name == nullptr) {
		$throwNew($IllegalArgumentException, "null input name is not allowed"_s);
	}
	$var($String, temp, $new($String, name));
	$var($String, result, nullptr);
	int32_t i = 0;
	while (i < temp->length()) {
		if (temp->charAt(i) == $PrincipalName::NAME_REALM_SEPARATOR) {
			if (i == 0 || temp->charAt(i - 1) != u'\\') {
				if (i + 1 < temp->length()) {
					$assign(result, temp->substring(i + 1, temp->length()));
				} else {
					$throwNew($IllegalArgumentException, "empty realm part not allowed"_s);
				}
				break;
			}
		}
		++i;
	}
	if (result != nullptr) {
		if (result->length() == 0) {
			$throwNew($RealmException, $Krb5::REALM_NULL);
		}
		if (!isValidRealmString(result)) {
			$throwNew($RealmException, $Krb5::REALM_ILLCHAR);
		}
	}
	return result;
}

$String* Realm::parseRealmComponent($String* name) {
	$init(Realm);
	if (name == nullptr) {
		$throwNew($IllegalArgumentException, "null input name is not allowed"_s);
	}
	$var($String, temp, $new($String, name));
	$var($String, result, nullptr);
	int32_t i = 0;
	while (i < temp->length()) {
		if (temp->charAt(i) == $PrincipalName::REALM_COMPONENT_SEPARATOR) {
			if (i == 0 || temp->charAt(i - 1) != u'\\') {
				if (i + 1 < temp->length()) {
					$assign(result, temp->substring(i + 1, temp->length()));
				}
				break;
			}
		}
		++i;
	}
	return result;
}

$String* Realm::parseRealm($String* name) {
	$init(Realm);
	$var($String, result, parseRealmAtSeparator(name));
	if (result == nullptr) {
		$assign(result, name);
	}
	if (result == nullptr || $nc(result)->length() == 0) {
		$throwNew($RealmException, $Krb5::REALM_NULL);
	}
	if (!isValidRealmString(result)) {
		$throwNew($RealmException, $Krb5::REALM_ILLCHAR);
	}
	return result;
}

bool Realm::isValidRealmString($String* name) {
	$init(Realm);
	if (name == nullptr) {
		return false;
	}
	if ($nc(name)->length() == 0) {
		return false;
	}
	for (int32_t i = 0; i < $nc(name)->length(); ++i) {
		bool var$0 = name->charAt(i) == u'/';
		if (var$0 || name->charAt(i) == u'\0') {
			return false;
		}
	}
	return true;
}

$bytes* Realm::asn1Encode() {
	$var($DerOutputStream, out, $new($DerOutputStream));
	out->putDerValue($($$new($KerberosString, this->realm)->toDerValue()));
	return out->toByteArray();
}

Realm* Realm::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(Realm);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(Realm, subDer);
	}
}

$StringArray* Realm::getRealmsList($String* cRealm, $String* sRealm) {
	$init(Realm);
	try {
		return parseCapaths(cRealm, sRealm);
	} catch ($KrbException&) {
		$var($KrbException, ke, $catch());
		return parseHierarchy(cRealm, sRealm);
	}
	$shouldNotReachHere();
}

$StringArray* Realm::parseCapaths($String* cRealm, $String* sRealm) {
	$init(Realm);
	$var($Config, cfg, $Config::getInstance());
	if (!$nc(cfg)->exists($$new($StringArray, {
		"capaths"_s,
		cRealm,
		sRealm
	}))) {
		$throwNew($KrbException, "No conf"_s);
	}
	$var($LinkedList, path, $new($LinkedList));
	$var($String, head, sRealm);
	while (true) {
		$var($String, value, $nc(cfg)->getAll($$new($StringArray, {
			"capaths"_s,
			cRealm,
			head
		})));
		if (value == nullptr) {
			break;
		}
		$var($StringArray, more, $nc(value)->split("\\s+"_s));
		bool changed = false;
		for (int32_t i = more->length - 1; i >= 0; --i) {
			bool var$3 = path->contains(more->get(i));
			bool var$2 = var$3 || $nc(more->get(i))->equals("."_s);
			bool var$1 = var$2 || $nc(more->get(i))->equals(cRealm);
			bool var$0 = var$1 || $nc(more->get(i))->equals(sRealm);
			if (var$0 || $nc(more->get(i))->equals(head)) {
				continue;
			}
			changed = true;
			path->addFirst(more->get(i));
		}
		if (!changed) {
			break;
		}
		$assign(head, $cast($String, path->getFirst()));
	}
	path->addFirst(cRealm);
	return $fcast($StringArray, path->toArray($$new($StringArray, path->size())));
}

$StringArray* Realm::parseHierarchy($String* cRealm, $String* sRealm) {
	$init(Realm);
	$var($StringArray, cComponents, $nc(cRealm)->split("\\."_s));
	$var($StringArray, sComponents, $nc(sRealm)->split("\\."_s));
	int32_t cPos = cComponents->length;
	int32_t sPos = sComponents->length;
	bool hasCommon = false;
	for (--sPos, --cPos; sPos >= 0 && cPos >= 0 && $nc(sComponents->get(sPos))->equals(cComponents->get(cPos)); --sPos, --cPos) {
		hasCommon = true;
	}
	$var($LinkedList, path, $new($LinkedList));
	for (int32_t i = 0; i <= cPos; ++i) {
		path->addLast($(subStringFrom(cComponents, i)));
	}
	if (hasCommon) {
		path->addLast($(subStringFrom(cComponents, cPos + 1)));
	}
	for (int32_t i = sPos; i >= 0; --i) {
		path->addLast($(subStringFrom(sComponents, i)));
	}
	path->removeLast();
	return $fcast($StringArray, path->toArray($$new($StringArray, path->size())));
}

$String* Realm::subStringFrom($StringArray* components, int32_t from) {
	$init(Realm);
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t i = from; i < $nc(components)->length; ++i) {
		if (sb->length() != 0) {
			sb->append(u'.');
		}
		sb->append(components->get(i));
	}
	return sb->toString();
}

void clinit$Realm($Class* class$) {
	Realm::AUTODEDUCEREALM = $GetBooleanAction::privilegedGetProperty("sun.security.krb5.autodeducerealm"_s);
}

Realm::Realm() {
}

$Class* Realm::load$($String* name, bool initialize) {
	$loadClass(Realm, name, initialize, &_Realm_ClassInfo_, clinit$Realm, allocate$Realm);
	return class$;
}

$Class* Realm::class$ = nullptr;

		} // krb5
	} // security
} // sun