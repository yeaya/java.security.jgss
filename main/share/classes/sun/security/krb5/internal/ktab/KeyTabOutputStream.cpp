#include <sun/security/krb5/internal/ktab/KeyTabOutputStream.h>

#include <java/io/FilterOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>
#include <sun/security/krb5/internal/ktab/KeyTabEntry.h>
#include <sun/security/krb5/internal/util/KrbDataOutputStream.h>
#include <jcpp.h>

#undef KRB5_KT_VNO_1

using $FilterOutputStream = ::java::io::FilterOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $KeyTabConstants = ::sun::security::krb5::internal::ktab::KeyTabConstants;
using $KeyTabEntry = ::sun::security::krb5::internal::ktab::KeyTabEntry;
using $KrbDataOutputStream = ::sun::security::krb5::internal::util::KrbDataOutputStream;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {

$FieldInfo _KeyTabOutputStream_FieldInfo_[] = {
	{"entry", "Lsun/security/krb5/internal/ktab/KeyTabEntry;", nullptr, $PRIVATE, $field(KeyTabOutputStream, entry)},
	{"keyType", "I", nullptr, $PRIVATE, $field(KeyTabOutputStream, keyType)},
	{"keyValue", "[B", nullptr, $PRIVATE, $field(KeyTabOutputStream, keyValue)},
	{"version", "I", nullptr, $PUBLIC, $field(KeyTabOutputStream, version)},
	{}
};

$MethodInfo _KeyTabOutputStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(KeyTabOutputStream::*)($OutputStream*)>(&KeyTabOutputStream::init$))},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeEntry", "(Lsun/security/krb5/internal/ktab/KeyTabEntry;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"writeVersion", "(I)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _KeyTabOutputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ktab.KeyTabOutputStream",
	"sun.security.krb5.internal.util.KrbDataOutputStream",
	"sun.security.krb5.internal.ktab.KeyTabConstants",
	_KeyTabOutputStream_FieldInfo_,
	_KeyTabOutputStream_MethodInfo_
};

$Object* allocate$KeyTabOutputStream($Class* clazz) {
	return $of($alloc(KeyTabOutputStream));
}

int32_t KeyTabOutputStream::hashCode() {
	 return this->$KrbDataOutputStream::hashCode();
}

bool KeyTabOutputStream::equals(Object$* arg0) {
	 return this->$KrbDataOutputStream::equals(arg0);
}

$Object* KeyTabOutputStream::clone() {
	 return this->$KrbDataOutputStream::clone();
}

$String* KeyTabOutputStream::toString() {
	 return this->$KrbDataOutputStream::toString();
}

void KeyTabOutputStream::finalize() {
	this->$KrbDataOutputStream::finalize();
}

void KeyTabOutputStream::init$($OutputStream* os) {
	$KrbDataOutputStream::init$(os);
}

void KeyTabOutputStream::writeVersion(int32_t num) {
	this->version = num;
	write16(num);
}

void KeyTabOutputStream::writeEntry($KeyTabEntry* entry) {
	write32($nc(entry)->entryLength());
	$var($StringArray, serviceNames, $nc($nc(entry)->service)->getNameStrings());
	int32_t comp_num = $nc(serviceNames)->length;
	if (this->version == $KeyTabConstants::KRB5_KT_VNO_1) {
		write16(comp_num + 1);
	} else {
		write16(comp_num);
	}
	$init($StandardCharsets);
	$var($bytes, realm, $nc($($nc(entry->service)->getRealmString()))->getBytes($StandardCharsets::ISO_8859_1));
	write16(realm->length);
	write(realm);
	for (int32_t i = 0; i < comp_num; ++i) {
		$var($bytes, serviceName, $nc(serviceNames->get(i))->getBytes($StandardCharsets::ISO_8859_1));
		write16(serviceName->length);
		write(serviceName);
	}
	write32($nc(entry->service)->getNameType());
	write32((int32_t)($nc(entry->timestamp)->getTime() / 1000));
	write8(entry->keyVersion % 256);
	write16(entry->keyType);
	write16($nc(entry->keyblock)->length);
	write(entry->keyblock);
}

KeyTabOutputStream::KeyTabOutputStream() {
}

$Class* KeyTabOutputStream::load$($String* name, bool initialize) {
	$loadClass(KeyTabOutputStream, name, initialize, &_KeyTabOutputStream_ClassInfo_, allocate$KeyTabOutputStream);
	return class$;
}

$Class* KeyTabOutputStream::class$ = nullptr;

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun