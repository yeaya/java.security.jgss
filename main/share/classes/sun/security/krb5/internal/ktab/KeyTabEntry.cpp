#include <sun/security/krb5/internal/ktab/KeyTabEntry.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>
#include <jcpp.h>

#undef DEBUG

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KeyTabConstants = ::sun::security::krb5::internal::ktab::KeyTabConstants;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {

$FieldInfo _KeyTabEntry_FieldInfo_[] = {
	{"service", "Lsun/security/krb5/PrincipalName;", nullptr, 0, $field(KeyTabEntry, service)},
	{"realm", "Lsun/security/krb5/Realm;", nullptr, 0, $field(KeyTabEntry, realm)},
	{"timestamp", "Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, $field(KeyTabEntry, timestamp)},
	{"keyVersion", "I", nullptr, 0, $field(KeyTabEntry, keyVersion)},
	{"keyType", "I", nullptr, 0, $field(KeyTabEntry, keyType)},
	{"keyblock", "[B", nullptr, 0, $field(KeyTabEntry, keyblock)},
	{"DEBUG", "Z", nullptr, 0, $field(KeyTabEntry, DEBUG)},
	{}
};

$MethodInfo _KeyTabEntry_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/Realm;Lsun/security/krb5/internal/KerberosTime;II[B)V", nullptr, $PUBLIC, $method(static_cast<void(KeyTabEntry::*)($PrincipalName*,$Realm*,$KerberosTime*,int32_t,int32_t,$bytes*)>(&KeyTabEntry::init$))},
	{"entryLength", "()I", nullptr, $PUBLIC},
	{"getKey", "()Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC},
	{"getKeyString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getService", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC},
	{"getTimeStamp", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KeyTabEntry_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ktab.KeyTabEntry",
	"java.lang.Object",
	"sun.security.krb5.internal.ktab.KeyTabConstants",
	_KeyTabEntry_FieldInfo_,
	_KeyTabEntry_MethodInfo_
};

$Object* allocate$KeyTabEntry($Class* clazz) {
	return $of($alloc(KeyTabEntry));
}

void KeyTabEntry::init$($PrincipalName* new_service, $Realm* new_realm, $KerberosTime* new_time, int32_t new_keyVersion, int32_t new_keyType, $bytes* new_keyblock) {
	$set(this, keyblock, nullptr);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	$set(this, service, new_service);
	$set(this, realm, new_realm);
	$set(this, timestamp, new_time);
	this->keyVersion = new_keyVersion;
	this->keyType = new_keyType;
	if (new_keyblock != nullptr) {
		$set(this, keyblock, $cast($bytes, new_keyblock->clone()));
	}
}

$PrincipalName* KeyTabEntry::getService() {
	return this->service;
}

$EncryptionKey* KeyTabEntry::getKey() {
	$var($EncryptionKey, key, $new($EncryptionKey, this->keyblock, this->keyType, $($Integer::valueOf(this->keyVersion))));
	return key;
}

$String* KeyTabEntry::getKeyString() {
	$var($StringBuilder, sb, $new($StringBuilder, "0x"_s));
	for (int32_t i = 0; i < $nc(this->keyblock)->length; ++i) {
		sb->append($($String::format("%02x"_s, $$new($ObjectArray, {$($of($Integer::valueOf((int32_t)($nc(this->keyblock)->get(i) & (uint32_t)255))))}))));
	}
	return sb->toString();
}

int32_t KeyTabEntry::entryLength() {
	int32_t totalPrincipalLength = 0;
	$var($StringArray, names, $nc(this->service)->getNameStrings());
	for (int32_t i = 0; i < $nc(names)->length; ++i) {
		$init($StandardCharsets);
		totalPrincipalLength += $KeyTabConstants::principalSize + $($nc(names->get(i))->getBytes($StandardCharsets::ISO_8859_1))->length;
	}
	$init($StandardCharsets);
	int32_t realmLen = $($nc($($nc(this->realm)->toString()))->getBytes($StandardCharsets::ISO_8859_1))->length;
	int32_t size = $KeyTabConstants::principalComponentSize + $KeyTabConstants::realmSize + realmLen + totalPrincipalLength + $KeyTabConstants::principalTypeSize + $KeyTabConstants::timestampSize + $KeyTabConstants::keyVersionSize + $KeyTabConstants::keyTypeSize + $KeyTabConstants::keySize + $nc(this->keyblock)->length;
	if (this->DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>> KeyTabEntry: key tab entry size is "_s, $$str(size)}));
	}
	return size;
}

$KerberosTime* KeyTabEntry::getTimeStamp() {
	return this->timestamp;
}

KeyTabEntry::KeyTabEntry() {
}

$Class* KeyTabEntry::load$($String* name, bool initialize) {
	$loadClass(KeyTabEntry, name, initialize, &_KeyTabEntry_ClassInfo_, allocate$KeyTabEntry);
	return class$;
}

$Class* KeyTabEntry::class$ = nullptr;

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun