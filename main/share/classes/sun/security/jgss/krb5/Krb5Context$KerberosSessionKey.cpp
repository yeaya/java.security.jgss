#include <sun/security/jgss/krb5/Krb5Context$KerberosSessionKey.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Key = ::java::security::Key;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5Context$KerberosSessionKey_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Krb5Context$KerberosSessionKey, serialVersionUID)},
	{"key", "Lsun/security/krb5/EncryptionKey;", nullptr, $PRIVATE | $FINAL, $field(Krb5Context$KerberosSessionKey, key)},
	{}
};

$MethodInfo _Krb5Context$KerberosSessionKey_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/EncryptionKey;)V", nullptr, 0, $method(static_cast<void(Krb5Context$KerberosSessionKey::*)($EncryptionKey*)>(&Krb5Context$KerberosSessionKey::init$))},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getEncoded", "()[B", nullptr, $PUBLIC},
	{"getFormat", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Krb5Context$KerberosSessionKey_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.Krb5Context$KerberosSessionKey", "sun.security.jgss.krb5.Krb5Context", "KerberosSessionKey", $STATIC},
	{}
};

$ClassInfo _Krb5Context$KerberosSessionKey_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.krb5.Krb5Context$KerberosSessionKey",
	"java.lang.Object",
	"java.security.Key",
	_Krb5Context$KerberosSessionKey_FieldInfo_,
	_Krb5Context$KerberosSessionKey_MethodInfo_,
	nullptr,
	nullptr,
	_Krb5Context$KerberosSessionKey_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.Krb5Context"
};

$Object* allocate$Krb5Context$KerberosSessionKey($Class* clazz) {
	return $of($alloc(Krb5Context$KerberosSessionKey));
}

void Krb5Context$KerberosSessionKey::init$($EncryptionKey* key) {
	$set(this, key, key);
}

$String* Krb5Context$KerberosSessionKey::getAlgorithm() {
	return $Integer::toString($nc(this->key)->getEType());
}

$String* Krb5Context$KerberosSessionKey::getFormat() {
	return "RAW"_s;
}

$bytes* Krb5Context$KerberosSessionKey::getEncoded() {
	return $cast($bytes, $nc($($nc(this->key)->getBytes()))->clone());
}

$String* Krb5Context$KerberosSessionKey::toString() {
	$var($String, var$0, $$str({"Kerberos session key: etype: "_s, $$str($nc(this->key)->getEType()), "\n"_s}));
	return $concat(var$0, $($$new($HexDumpEncoder)->encodeBuffer($($nc(this->key)->getBytes()))));
}

Krb5Context$KerberosSessionKey::Krb5Context$KerberosSessionKey() {
}

$Class* Krb5Context$KerberosSessionKey::load$($String* name, bool initialize) {
	$loadClass(Krb5Context$KerberosSessionKey, name, initialize, &_Krb5Context$KerberosSessionKey_ClassInfo_, allocate$Krb5Context$KerberosSessionKey);
	return class$;
}

$Class* Krb5Context$KerberosSessionKey::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun