#include <sun/security/krb5/internal/ktab/KeyTabInputStream.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/RealmException.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>
#include <sun/security/krb5/internal/ktab/KeyTabEntry.h>
#include <sun/security/krb5/internal/util/KrbDataInputStream.h>
#include <jcpp.h>

#undef DEBUG
#undef KRB5_KT_VNO_1

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $RealmException = ::sun::security::krb5::RealmException;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KeyTabConstants = ::sun::security::krb5::internal::ktab::KeyTabConstants;
using $KeyTabEntry = ::sun::security::krb5::internal::ktab::KeyTabEntry;
using $KrbDataInputStream = ::sun::security::krb5::internal::util::KrbDataInputStream;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {

$FieldInfo _KeyTabInputStream_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, 0, $field(KeyTabInputStream, DEBUG)},
	{"index", "I", nullptr, 0, $field(KeyTabInputStream, index)},
	{}
};

$MethodInfo _KeyTabInputStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(KeyTabInputStream::*)($InputStream*)>(&KeyTabInputStream::init$))},
	{"readEntry", "(II)Lsun/security/krb5/internal/ktab/KeyTabEntry;", nullptr, 0, nullptr, "java.io.IOException,sun.security.krb5.RealmException"},
	{"readEntryLength", "()I", nullptr, 0, nullptr, "java.io.IOException"},
	{"readKey", "(I)[B", nullptr, 0, nullptr, "java.io.IOException"},
	{"readName", "()Ljava/lang/String;", nullptr, 0, nullptr, "java.io.IOException"},
	{"readTimeStamp", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, nullptr, "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KeyTabInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ktab.KeyTabInputStream",
	"sun.security.krb5.internal.util.KrbDataInputStream",
	"sun.security.krb5.internal.ktab.KeyTabConstants",
	_KeyTabInputStream_FieldInfo_,
	_KeyTabInputStream_MethodInfo_
};

$Object* allocate$KeyTabInputStream($Class* clazz) {
	return $of($alloc(KeyTabInputStream));
}

int32_t KeyTabInputStream::hashCode() {
	 return this->$KrbDataInputStream::hashCode();
}

bool KeyTabInputStream::equals(Object$* arg0) {
	 return this->$KrbDataInputStream::equals(arg0);
}

$Object* KeyTabInputStream::clone() {
	 return this->$KrbDataInputStream::clone();
}

$String* KeyTabInputStream::toString() {
	 return this->$KrbDataInputStream::toString();
}

void KeyTabInputStream::finalize() {
	this->$KrbDataInputStream::finalize();
}

void KeyTabInputStream::init$($InputStream* is) {
	$KrbDataInputStream::init$(is);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
}

int32_t KeyTabInputStream::readEntryLength() {
	return read(4);
}

$KeyTabEntry* KeyTabInputStream::readEntry(int32_t entryLen, int32_t ktVersion) {
	this->index = entryLen;
	if (this->index == 0) {
		return nullptr;
	}
	if (this->index < 0) {
		int64_t n = -this->index;
		while (n > 0) {
			int64_t n2 = skip(n);
			if (n2 == 0) {
				$throwNew($IOException, "Premature end of stream reached"_s);
			} else {
				n -= n2;
			}
		}
		return nullptr;
	}
	int32_t principalNum = read(2);
	this->index -= 2;
	if (ktVersion == $KeyTabConstants::KRB5_KT_VNO_1) {
		principalNum -= 1;
	}
	$var($Realm, realm, $new($Realm, $(readName())));
	$var($StringArray, nameParts, $new($StringArray, principalNum));
	for (int32_t i = 0; i < principalNum; ++i) {
		nameParts->set(i, $(readName()));
	}
	int32_t nameType = read(4);
	this->index -= 4;
	$var($PrincipalName, service, $new($PrincipalName, nameType, nameParts, realm));
	$var($KerberosTime, timeStamp, readTimeStamp());
	int32_t keyVersion = (int32_t)(read() & (uint32_t)255);
	this->index -= 1;
	int32_t keyType = read(2);
	this->index -= 2;
	int32_t keyLength = read(2);
	this->index -= 2;
	$var($bytes, keyblock, readKey(keyLength));
	this->index -= keyLength;
	if (this->index >= 4) {
		int32_t extKvno = read(4);
		if (extKvno != 0) {
			keyVersion = extKvno;
		}
		this->index -= 4;
	}
	if (this->index < 0) {
		$throwNew($RealmException, "Keytab is corrupted"_s);
	}
	skip(this->index);
	return $new($KeyTabEntry, service, realm, timeStamp, keyVersion, keyType, keyblock);
}

$bytes* KeyTabInputStream::readKey(int32_t length) {
	$var($bytes, bytes, $new($bytes, length));
	read(bytes, 0, length);
	return bytes;
}

$KerberosTime* KeyTabInputStream::readTimeStamp() {
	this->index -= 4;
	return $new($KerberosTime, (int64_t)read(4) * 1000);
}

$String* KeyTabInputStream::readName() {
	$var($String, name, nullptr);
	int32_t length = read(2);
	this->index -= 2;
	$var($bytes, bytes, $new($bytes, length));
	read(bytes, 0, length);
	this->index -= length;
	$assign(name, $new($String, bytes));
	if (this->DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>> KeyTabInputStream, readName(): "_s, name}));
	}
	return name;
}

KeyTabInputStream::KeyTabInputStream() {
}

$Class* KeyTabInputStream::load$($String* name, bool initialize) {
	$loadClass(KeyTabInputStream, name, initialize, &_KeyTabInputStream_ClassInfo_, allocate$KeyTabInputStream);
	return class$;
}

$Class* KeyTabInputStream::class$ = nullptr;

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun