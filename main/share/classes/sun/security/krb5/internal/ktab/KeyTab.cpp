#include <sun/security/krb5/internal/ktab/KeyTab.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/FileOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Comparator.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/StringTokenizer.h>
#include <java/util/Vector.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <sun/security/krb5/internal/ktab/KeyTab$1.h>
#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>
#include <sun/security/krb5/internal/ktab/KeyTabEntry.h>
#include <sun/security/krb5/internal/ktab/KeyTabInputStream.h>
#include <sun/security/krb5/internal/ktab/KeyTabOutputStream.h>
#include <jcpp.h>

#undef DEBUG
#undef KRB5_KT_VNO
#undef KRB5_KT_VNO_1

using $EncryptionKeyArray = $Array<::sun::security::krb5::EncryptionKey>;
using $KeyTabEntryArray = $Array<::sun::security::krb5::internal::ktab::KeyTabEntry>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $FileOutputStream = ::java::io::FileOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Comparator = ::java::util::Comparator;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $StringTokenizer = ::java::util::StringTokenizer;
using $Vector = ::java::util::Vector;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $Config = ::sun::security::krb5::Config;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $EType = ::sun::security::krb5::internal::crypto::EType;
using $KeyTab$1 = ::sun::security::krb5::internal::ktab::KeyTab$1;
using $KeyTabConstants = ::sun::security::krb5::internal::ktab::KeyTabConstants;
using $KeyTabEntry = ::sun::security::krb5::internal::ktab::KeyTabEntry;
using $KeyTabInputStream = ::sun::security::krb5::internal::ktab::KeyTabInputStream;
using $KeyTabOutputStream = ::sun::security::krb5::internal::ktab::KeyTabOutputStream;
using $KrbDataInputStream = ::sun::security::krb5::internal::util::KrbDataInputStream;
using $KrbDataOutputStream = ::sun::security::krb5::internal::util::KrbDataOutputStream;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {

$FieldInfo _KeyTab_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeyTab, DEBUG)},
	{"defaultTabName", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(KeyTab, defaultTabName)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/krb5/internal/ktab/KeyTab;>;", $PRIVATE | $STATIC, $staticField(KeyTab, map)},
	{"isMissing", "Z", nullptr, $PRIVATE, $field(KeyTab, isMissing$)},
	{"isValid", "Z", nullptr, $PRIVATE, $field(KeyTab, isValid$)},
	{"tabName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(KeyTab, tabName$)},
	{"lastModified", "J", nullptr, $PRIVATE, $field(KeyTab, lastModified)},
	{"kt_vno", "I", nullptr, $PRIVATE, $field(KeyTab, kt_vno)},
	{"entries", "Ljava/util/Vector;", "Ljava/util/Vector<Lsun/security/krb5/internal/ktab/KeyTabEntry;>;", $PRIVATE, $field(KeyTab, entries)},
	{}
};

$MethodInfo _KeyTab_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(KeyTab::*)($String*)>(&KeyTab::init$))},
	{"addEntry", "(Lsun/security/krb5/PrincipalName;[CIZ)V", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException"},
	{"addEntry", "(Lsun/security/krb5/PrincipalName;Ljava/lang/String;[CIZ)V", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException"},
	{"create", "()Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<KeyTab*(*)()>(&KeyTab::create)), "java.io.IOException,sun.security.krb5.RealmException"},
	{"create", "(Ljava/lang/String;)Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<KeyTab*(*)($String*)>(&KeyTab::create)), "java.io.IOException,sun.security.krb5.RealmException"},
	{"createVersion", "(Ljava/io/File;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"deleteEntries", "(Lsun/security/krb5/PrincipalName;II)I", nullptr, $PUBLIC},
	{"findServiceEntry", "(Lsun/security/krb5/PrincipalName;)Z", nullptr, $PUBLIC},
	{"getDefaultTabName", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)()>(&KeyTab::getDefaultTabName))},
	{"getEntries", "()[Lsun/security/krb5/internal/ktab/KeyTabEntry;", nullptr, $PUBLIC},
	{"getInstance", "(Ljava/lang/String;)Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KeyTab*(*)($String*)>(&KeyTab::getInstance))},
	{"getInstance", "(Ljava/io/File;)Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KeyTab*(*)($File*)>(&KeyTab::getInstance))},
	{"getInstance", "()Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KeyTab*(*)()>(&KeyTab::getInstance))},
	{"getInstance0", "(Ljava/lang/String;)Lsun/security/krb5/internal/ktab/KeyTab;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<KeyTab*(*)($String*)>(&KeyTab::getInstance0))},
	{"getOneName", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC},
	{"isMissing", "()Z", nullptr, $PUBLIC},
	{"isValid", "()Z", nullptr, $PUBLIC},
	{"load", "(Lsun/security/krb5/internal/ktab/KeyTabInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KeyTab::*)($KeyTabInputStream*)>(&KeyTab::load)), "java.io.IOException,sun.security.krb5.RealmException"},
	{"normalize", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($String*)>(&KeyTab::normalize))},
	{"readServiceKeys", "(Lsun/security/krb5/PrincipalName;)[Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC},
	{"save", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"tabName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _KeyTab_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ktab.KeyTab$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _KeyTab_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ktab.KeyTab",
	"java.lang.Object",
	"sun.security.krb5.internal.ktab.KeyTabConstants",
	_KeyTab_FieldInfo_,
	_KeyTab_MethodInfo_,
	nullptr,
	nullptr,
	_KeyTab_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ktab.KeyTab$1"
};

$Object* allocate$KeyTab($Class* clazz) {
	return $of($alloc(KeyTab));
}

bool KeyTab::DEBUG = false;
$String* KeyTab::defaultTabName = nullptr;
$Map* KeyTab::map = nullptr;

void KeyTab::init$($String* filename) {
	this->isMissing$ = false;
	this->isValid$ = true;
	this->kt_vno = $KeyTabConstants::KRB5_KT_VNO;
	$set(this, entries, $new($Vector));
	$set(this, tabName$, filename);
	try {
		this->lastModified = $$new($File, this->tabName$)->lastModified();
		{
			$var($KeyTabInputStream, kis, $new($KeyTabInputStream, $$new($FileInputStream, filename)));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						load(kis);
					} catch ($Throwable&) {
						$var($Throwable, t$, $catch());
						try {
							kis->close();
						} catch ($Throwable&) {
							$var($Throwable, x2, $catch());
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable&) {
					$assign(var$0, $catch());
				} /*finally*/ {
					kis->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	} catch ($FileNotFoundException&) {
		$var($FileNotFoundException, e, $catch());
		$nc(this->entries)->clear();
		this->isMissing$ = true;
	} catch ($Exception&) {
		$var($Exception, ioe, $catch());
		$nc(this->entries)->clear();
		this->isValid$ = false;
	}
}

KeyTab* KeyTab::getInstance0($String* s) {
	$load(KeyTab);
	$synchronized(class$) {
		$init(KeyTab);
		int64_t lm = $$new($File, s)->lastModified();
		$var(KeyTab, old, $cast(KeyTab, $nc(KeyTab::map)->get(s)));
		if (old != nullptr && old->isValid() && old->lastModified == lm) {
			return old;
		}
		$var(KeyTab, ktab, $new(KeyTab, s));
		if (ktab->isValid()) {
			$nc(KeyTab::map)->put(s, ktab);
			return ktab;
		} else if (old != nullptr) {
			return old;
		} else {
			return ktab;
		}
	}
}

KeyTab* KeyTab::getInstance($String* s) {
	$init(KeyTab);
	if (s == nullptr) {
		return getInstance();
	} else {
		return getInstance0($(normalize(s)));
	}
}

KeyTab* KeyTab::getInstance($File* file) {
	$init(KeyTab);
	if (file == nullptr) {
		return getInstance();
	} else {
		return getInstance0($($nc(file)->getPath()));
	}
}

KeyTab* KeyTab::getInstance() {
	$init(KeyTab);
	return getInstance($(getDefaultTabName()));
}

bool KeyTab::isMissing() {
	return this->isMissing$;
}

bool KeyTab::isValid() {
	return this->isValid$;
}

$String* KeyTab::getDefaultTabName() {
	$init(KeyTab);
	if (KeyTab::defaultTabName != nullptr) {
		return KeyTab::defaultTabName;
	} else {
		$var($String, kname, nullptr);
		try {
			$var($String, keytab_names, $nc($($Config::getInstance()))->get($$new($StringArray, {
				"libdefaults"_s,
				"default_keytab_name"_s
			})));
			if (keytab_names != nullptr) {
				$var($StringTokenizer, st, $new($StringTokenizer, keytab_names, " "_s));
				while (st->hasMoreTokens()) {
					$assign(kname, normalize($(st->nextToken())));
					if ($$new($File, kname)->exists()) {
						break;
					}
				}
			}
		} catch ($KrbException&) {
			$var($KrbException, e, $catch());
			$assign(kname, nullptr);
		}
		if (kname == nullptr) {
			$var($String, user_home, $GetPropertyAction::privilegedGetProperty("user.home"_s));
			if (user_home == nullptr) {
				$assign(user_home, $GetPropertyAction::privilegedGetProperty("user.dir"_s));
			}
			$init($File);
			$assign(kname, $str({user_home, $File::separator, "krb5.keytab"_s}));
		}
		$assignStatic(KeyTab::defaultTabName, kname);
		return kname;
	}
}

$String* KeyTab::normalize($String* name) {
	$init(KeyTab);
	$var($String, kname, nullptr);
	bool var$0 = ($nc(name)->length() >= 5);
	if (var$0 && ($(name->substring(0, 5))->equalsIgnoreCase("FILE:"_s))) {
		$assign(kname, name->substring(5));
	} else {
		bool var$2 = (name->length() >= 9);
		if (var$2 && ($(name->substring(0, 9))->equalsIgnoreCase("ANY:FILE:"_s))) {
			$assign(kname, name->substring(9));
		} else {
			bool var$4 = (name->length() >= 7);
			if (var$4 && ($(name->substring(0, 7))->equalsIgnoreCase("SRVTAB:"_s))) {
				$assign(kname, name->substring(7));
			} else {
				$assign(kname, name);
			}
		}
	}
	return kname;
}

void KeyTab::load($KeyTabInputStream* kis) {
	$nc(this->entries)->clear();
	this->kt_vno = $nc(kis)->readVersion();
	if (this->kt_vno == $KeyTabConstants::KRB5_KT_VNO_1) {
		kis->setNativeByteOrder();
	}
	int32_t entryLength = 0;
	$var($KeyTabEntry, entry, nullptr);
	while (kis->available() > 0) {
		entryLength = kis->readEntryLength();
		$assign(entry, kis->readEntry(entryLength, this->kt_vno));
		if (KeyTab::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>> KeyTab: load() entry length: "_s, $$str(entryLength), "; type: "_s, $$str((entry != nullptr ? $nc(entry)->keyType : 0))}));
		}
		if (entry != nullptr) {
			$nc(this->entries)->addElement(entry);
		}
	}
}

$PrincipalName* KeyTab::getOneName() {
	int32_t size = $nc(this->entries)->size();
	return size > 0 ? $nc(($cast($KeyTabEntry, $($nc(this->entries)->elementAt(size - 1)))))->service : ($PrincipalName*)nullptr;
}

$EncryptionKeyArray* KeyTab::readServiceKeys($PrincipalName* service) {
	$var($KeyTabEntry, entry, nullptr);
	$var($EncryptionKey, key, nullptr);
	int32_t size = $nc(this->entries)->size();
	$var($ArrayList, keys, $new($ArrayList, size));
	if (KeyTab::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"Looking for keys for: "_s, service}));
	}
	for (int32_t i = size - 1; i >= 0; --i) {
		$assign(entry, $cast($KeyTabEntry, $nc(this->entries)->elementAt(i)));
		if ($nc($nc(entry)->service)->match(service)) {
			if ($EType::isSupported(entry->keyType)) {
				$assign(key, $new($EncryptionKey, entry->keyblock, entry->keyType, $($Integer::valueOf(entry->keyVersion))));
				keys->add(key);
				if (KeyTab::DEBUG) {
					$init($System);
					$nc($System::out)->println($$str({"Added key: "_s, $$str(entry->keyType), ", version: "_s, $$str(entry->keyVersion)}));
				}
			} else if (KeyTab::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"Found unsupported keytype ("_s, $$str(entry->keyType), ") for "_s, service}));
			}
		}
	}
	size = keys->size();
	$var($EncryptionKeyArray, retVal, $fcast($EncryptionKeyArray, keys->toArray($$new($EncryptionKeyArray, size))));
	$Arrays::sort(retVal, $$new($KeyTab$1, this));
	return retVal;
}

bool KeyTab::findServiceEntry($PrincipalName* service) {
	$var($KeyTabEntry, entry, nullptr);
	for (int32_t i = 0; i < $nc(this->entries)->size(); ++i) {
		$assign(entry, $cast($KeyTabEntry, $nc(this->entries)->elementAt(i)));
		if ($nc($nc(entry)->service)->match(service)) {
			if ($EType::isSupported(entry->keyType)) {
				return true;
			} else if (KeyTab::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"Found unsupported keytype ("_s, $$str(entry->keyType), ") for "_s, service}));
			}
		}
	}
	return false;
}

$String* KeyTab::tabName() {
	return this->tabName$;
}

void KeyTab::addEntry($PrincipalName* service, $chars* psswd, int32_t kvno, bool append) {
	addEntry(service, $($nc(service)->getSalt()), psswd, kvno, append);
}

void KeyTab::addEntry($PrincipalName* service, $String* salt, $chars* psswd, int32_t kvno, bool append) {
	$var($EncryptionKeyArray, encKeys, $EncryptionKey::acquireSecretKeys(psswd, salt));
	int32_t maxKvno = 0;
	for (int32_t i = $nc(this->entries)->size() - 1; i >= 0; --i) {
		$var($KeyTabEntry, e, $cast($KeyTabEntry, $nc(this->entries)->get(i)));
		if ($nc($nc(e)->service)->match(service)) {
			if (e->keyVersion > maxKvno) {
				maxKvno = e->keyVersion;
			}
			if (!append || e->keyVersion == kvno) {
				$nc(this->entries)->removeElementAt(i);
			}
		}
	}
	if (kvno == -1) {
		kvno = maxKvno + 1;
	}
	for (int32_t i = 0; encKeys != nullptr && i < encKeys->length; ++i) {
		int32_t keyType = $nc(encKeys->get(i))->getEType();
		$var($bytes, keyValue, $nc(encKeys->get(i))->getBytes());
		$var($PrincipalName, var$0, service);
		$var($Realm, var$1, $nc(service)->getRealm());
		$var($KeyTabEntry, newEntry, $new($KeyTabEntry, var$0, var$1, $$new($KerberosTime, $System::currentTimeMillis()), kvno, keyType, keyValue));
		$nc(this->entries)->addElement(newEntry);
	}
}

$KeyTabEntryArray* KeyTab::getEntries() {
	$var($KeyTabEntryArray, kentries, $new($KeyTabEntryArray, $nc(this->entries)->size()));
	for (int32_t i = 0; i < kentries->length; ++i) {
		kentries->set(i, $cast($KeyTabEntry, $($nc(this->entries)->elementAt(i))));
	}
	return kentries;
}

KeyTab* KeyTab::create() {
	$load(KeyTab);
	$synchronized(class$) {
		$init(KeyTab);
		$var($String, dname, getDefaultTabName());
		return create(dname);
	}
}

KeyTab* KeyTab::create($String* name) {
	$load(KeyTab);
	$synchronized(class$) {
		$init(KeyTab);
		{
			$var($KeyTabOutputStream, kos, $new($KeyTabOutputStream, $$new($FileOutputStream, name)));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						kos->writeVersion($KeyTabConstants::KRB5_KT_VNO);
					} catch ($Throwable&) {
						$var($Throwable, t$, $catch());
						try {
							kos->close();
						} catch ($Throwable&) {
							$var($Throwable, x2, $catch());
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable&) {
					$assign(var$0, $catch());
				} /*finally*/ {
					kos->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
		return $new(KeyTab, name);
	}
}

void KeyTab::save() {
	$synchronized(this) {
		{
			$var($KeyTabOutputStream, kos, $new($KeyTabOutputStream, $$new($FileOutputStream, this->tabName$)));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						kos->writeVersion(this->kt_vno);
						for (int32_t i = 0; i < $nc(this->entries)->size(); ++i) {
							kos->writeEntry($cast($KeyTabEntry, $($nc(this->entries)->elementAt(i))));
						}
					} catch ($Throwable&) {
						$var($Throwable, t$, $catch());
						try {
							kos->close();
						} catch ($Throwable&) {
							$var($Throwable, x2, $catch());
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable&) {
					$assign(var$0, $catch());
				} /*finally*/ {
					kos->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	}
}

int32_t KeyTab::deleteEntries($PrincipalName* service, int32_t etype, int32_t kvno) {
	int32_t count = 0;
	$var($Map, highest, $new($HashMap));
	for (int32_t i = $nc(this->entries)->size() - 1; i >= 0; --i) {
		$var($KeyTabEntry, e, $cast($KeyTabEntry, $nc(this->entries)->get(i)));
		if ($nc(service)->match($($nc(e)->getService()))) {
			if (etype == -1 || $nc(e)->keyType == etype) {
				if (kvno == -2) {
					if (highest->containsKey($($Integer::valueOf(e->keyType)))) {
						int32_t n = $nc(($cast($Integer, $(highest->get($($Integer::valueOf(e->keyType)))))))->intValue();
						if (e->keyVersion > n) {
							$var($Object, var$0, $of($Integer::valueOf(e->keyType)));
							highest->put(var$0, $($Integer::valueOf(e->keyVersion)));
						}
					} else {
						$var($Object, var$1, $of($Integer::valueOf(e->keyType)));
						highest->put(var$1, $($Integer::valueOf(e->keyVersion)));
					}
				} else if (kvno == -1 || e->keyVersion == kvno) {
					$nc(this->entries)->removeElementAt(i);
					++count;
				}
			}
		}
	}
	if (kvno == -2) {
		for (int32_t i = $nc(this->entries)->size() - 1; i >= 0; --i) {
			$var($KeyTabEntry, e, $cast($KeyTabEntry, $nc(this->entries)->get(i)));
			if ($nc(service)->match($($nc(e)->getService()))) {
				if (etype == -1 || $nc(e)->keyType == etype) {
					int32_t n = $nc(($cast($Integer, $(highest->get($($Integer::valueOf(e->keyType)))))))->intValue();
					if (e->keyVersion != n) {
						$nc(this->entries)->removeElementAt(i);
						++count;
					}
				}
			}
		}
	}
	return count;
}

void KeyTab::createVersion($File* file) {
	$synchronized(this) {
		{
			$var($KeyTabOutputStream, kos, $new($KeyTabOutputStream, $$new($FileOutputStream, file)));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						kos->write16($KeyTabConstants::KRB5_KT_VNO);
					} catch ($Throwable&) {
						$var($Throwable, t$, $catch());
						try {
							kos->close();
						} catch ($Throwable&) {
							$var($Throwable, x2, $catch());
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable&) {
					$assign(var$0, $catch());
				} /*finally*/ {
					kos->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	}
}

void clinit$KeyTab($Class* class$) {
	$init($Krb5);
	KeyTab::DEBUG = $Krb5::DEBUG;
	$assignStatic(KeyTab::defaultTabName, nullptr);
	$assignStatic(KeyTab::map, $new($HashMap));
}

KeyTab::KeyTab() {
}

$Class* KeyTab::load$($String* name, bool initialize) {
	$loadClass(KeyTab, name, initialize, &_KeyTab_ClassInfo_, clinit$KeyTab, allocate$KeyTab);
	return class$;
}

$Class* KeyTab::class$ = nullptr;

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun