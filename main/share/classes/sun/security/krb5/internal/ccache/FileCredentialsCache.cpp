#include <sun/security/krb5/internal/ccache/FileCredentialsCache.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedReader.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintStream.h>
#include <java/io/Reader.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/Process.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/StringTokenizer.h>
#include <java/util/Vector.h>
#include <jdk/internal/misc/VM.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/LoginOptions.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/ccache/CCacheInputStream.h>
#include <sun/security/krb5/internal/ccache/CCacheOutputStream.h>
#include <sun/security/krb5/internal/ccache/Credentials.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache.h>
#include <sun/security/krb5/internal/ccache/FileCCacheConstants.h>
#include <sun/security/krb5/internal/ccache/FileCredentialsCache$1.h>
#include <sun/security/krb5/internal/ccache/FileCredentialsCache$2.h>
#include <sun/security/krb5/internal/ccache/Tag.h>
#include <sun/security/util/SecurityProperties.h>
#include <jcpp.h>

#undef DEBUG
#undef KRB5_FCC_FVNO_1
#undef KRB5_FCC_FVNO_2
#undef KRB5_FCC_FVNO_3
#undef KRB5_FCC_FVNO_4
#undef UTF_8

using $CredentialsArray = $Array<::sun::security::krb5::internal::ccache::Credentials>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedReader = ::java::io::BufferedReader;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileOutputStream = ::java::io::FileOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Process = ::java::lang::Process;
using $RuntimeException = ::java::lang::RuntimeException;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $StringTokenizer = ::java::util::StringTokenizer;
using $Vector = ::java::util::Vector;
using $VM = ::jdk::internal::misc::VM;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $1Credentials = ::sun::security::krb5::Credentials;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $LoginOptions = ::sun::security::krb5::internal::LoginOptions;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $CCacheInputStream = ::sun::security::krb5::internal::ccache::CCacheInputStream;
using $CCacheOutputStream = ::sun::security::krb5::internal::ccache::CCacheOutputStream;
using $Credentials = ::sun::security::krb5::internal::ccache::Credentials;
using $CredentialsCache = ::sun::security::krb5::internal::ccache::CredentialsCache;
using $CredentialsCache$ConfigEntry = ::sun::security::krb5::internal::ccache::CredentialsCache$ConfigEntry;
using $FileCCacheConstants = ::sun::security::krb5::internal::ccache::FileCCacheConstants;
using $FileCredentialsCache$1 = ::sun::security::krb5::internal::ccache::FileCredentialsCache$1;
using $FileCredentialsCache$2 = ::sun::security::krb5::internal::ccache::FileCredentialsCache$2;
using $Tag = ::sun::security::krb5::internal::ccache::Tag;
using $KrbDataInputStream = ::sun::security::krb5::internal::util::KrbDataInputStream;
using $SecurityProperties = ::sun::security::util::SecurityProperties;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$FieldInfo _FileCredentialsCache_FieldInfo_[] = {
	{"version", "I", nullptr, $PUBLIC, $field(FileCredentialsCache, version)},
	{"tag", "Lsun/security/krb5/internal/ccache/Tag;", nullptr, $PUBLIC, $field(FileCredentialsCache, tag)},
	{"primaryPrincipal", "Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, $field(FileCredentialsCache, primaryPrincipal)},
	{"credentialsList", "Ljava/util/Vector;", "Ljava/util/Vector<Lsun/security/krb5/internal/ccache/Credentials;>;", $PRIVATE, $field(FileCredentialsCache, credentialsList)},
	{"dir", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(FileCredentialsCache, dir)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(FileCredentialsCache, DEBUG)},
	{"configEntries", "Ljava/util/List;", "Ljava/util/List<Lsun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry;>;", $PRIVATE, $field(FileCredentialsCache, configEntries)},
	{}
};

$MethodInfo _FileCredentialsCache_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(FileCredentialsCache::*)()>(&FileCredentialsCache::init$))},
	{"New", "(Lsun/security/krb5/PrincipalName;Ljava/lang/String;)Lsun/security/krb5/internal/ccache/FileCredentialsCache;", nullptr, $STATIC | $SYNCHRONIZED, $method(static_cast<FileCredentialsCache*(*)($PrincipalName*,$String*)>(&FileCredentialsCache::New))},
	{"New", "(Lsun/security/krb5/PrincipalName;)Lsun/security/krb5/internal/ccache/FileCredentialsCache;", nullptr, $STATIC | $SYNCHRONIZED, $method(static_cast<FileCredentialsCache*(*)($PrincipalName*)>(&FileCredentialsCache::New))},
	{"acquireInstance", "(Lsun/security/krb5/PrincipalName;Ljava/lang/String;)Lsun/security/krb5/internal/ccache/FileCredentialsCache;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<FileCredentialsCache*(*)($PrincipalName*,$String*)>(&FileCredentialsCache::acquireInstance))},
	{"acquireInstance", "()Lsun/security/krb5/internal/ccache/FileCredentialsCache;", nullptr, $PUBLIC | $STATIC, $method(static_cast<FileCredentialsCache*(*)()>(&FileCredentialsCache::acquireInstance))},
	{"addConfigEntry", "(Lsun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry;)V", nullptr, $PUBLIC},
	{"checkValidation", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($String*)>(&FileCredentialsCache::checkValidation))},
	{"exec", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($String*)>(&FileCredentialsCache::exec))},
	{"exists", "(Ljava/lang/String;)Z", nullptr, 0},
	{"getConfigEntries", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry;>;", $PUBLIC},
	{"getCreds", "(Lsun/security/krb5/internal/LoginOptions;Lsun/security/krb5/PrincipalName;)Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC},
	{"getCreds", "(Lsun/security/krb5/PrincipalName;)Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC},
	{"getCredsList", "()[Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"getDefaultCacheName", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)()>(&FileCredentialsCache::getDefaultCacheName))},
	{"getDefaultCreds", "()Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC},
	{"getInitialCreds", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC},
	{"getPrimaryPrincipal", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"init", "(Lsun/security/krb5/PrincipalName;Ljava/lang/String;)V", nullptr, $SYNCHRONIZED, nullptr, "java.io.IOException,sun.security.krb5.KrbException"},
	{"load", "(Ljava/lang/String;)V", nullptr, $SYNCHRONIZED, nullptr, "java.io.IOException,sun.security.krb5.KrbException"},
	{"match", "([Ljava/lang/String;[Ljava/lang/String;)Z", nullptr, 0},
	{"save", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException,sun.security.krb5.Asn1Exception"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"update", "(Lsun/security/krb5/internal/ccache/Credentials;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{}
};

$InnerClassInfo _FileCredentialsCache_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.ccache.FileCredentialsCache$2", nullptr, nullptr, 0},
	{"sun.security.krb5.internal.ccache.FileCredentialsCache$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileCredentialsCache_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ccache.FileCredentialsCache",
	"sun.security.krb5.internal.ccache.CredentialsCache",
	"sun.security.krb5.internal.ccache.FileCCacheConstants",
	_FileCredentialsCache_FieldInfo_,
	_FileCredentialsCache_MethodInfo_,
	nullptr,
	nullptr,
	_FileCredentialsCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.ccache.FileCredentialsCache$2,sun.security.krb5.internal.ccache.FileCredentialsCache$1"
};

$Object* allocate$FileCredentialsCache($Class* clazz) {
	return $of($alloc(FileCredentialsCache));
}

int32_t FileCredentialsCache::hashCode() {
	 return this->$CredentialsCache::hashCode();
}

bool FileCredentialsCache::equals(Object$* arg0) {
	 return this->$CredentialsCache::equals(arg0);
}

$Object* FileCredentialsCache::clone() {
	 return this->$CredentialsCache::clone();
}

$String* FileCredentialsCache::toString() {
	 return this->$CredentialsCache::toString();
}

void FileCredentialsCache::finalize() {
	this->$CredentialsCache::finalize();
}

$String* FileCredentialsCache::dir = nullptr;
bool FileCredentialsCache::DEBUG = false;

FileCredentialsCache* FileCredentialsCache::acquireInstance($PrincipalName* principal, $String* cache) {
	$load(FileCredentialsCache);
	$synchronized(class$) {
		$init(FileCredentialsCache);
		try {
			$var(FileCredentialsCache, fcc, $new(FileCredentialsCache));
			if (cache == nullptr) {
				$init($CredentialsCache);
				$assignStatic($CredentialsCache::cacheName$, FileCredentialsCache::getDefaultCacheName());
			} else {
				$init($CredentialsCache);
				$assignStatic($CredentialsCache::cacheName$, FileCredentialsCache::checkValidation(cache));
			}
			$init($CredentialsCache);
			if (($CredentialsCache::cacheName$ == nullptr) || !($$new($File, $CredentialsCache::cacheName$))->exists()) {
				return nullptr;
			}
			if (principal != nullptr) {
				$set(fcc, primaryPrincipal, principal);
			}
			fcc->load($CredentialsCache::cacheName$);
			return fcc;
		} catch ($IOException&) {
			$var($IOException, e, $catch());
			if (FileCredentialsCache::DEBUG) {
				e->printStackTrace();
			}
		} catch ($KrbException&) {
			$var($KrbException, e, $catch());
			if (FileCredentialsCache::DEBUG) {
				e->printStackTrace();
			}
		}
		return nullptr;
	}
}

FileCredentialsCache* FileCredentialsCache::acquireInstance() {
	$init(FileCredentialsCache);
	return acquireInstance(nullptr, nullptr);
}

FileCredentialsCache* FileCredentialsCache::New($PrincipalName* principal, $String* name) {
	$load(FileCredentialsCache);
	$synchronized(class$) {
		$init(FileCredentialsCache);
		try {
			$var(FileCredentialsCache, fcc, $new(FileCredentialsCache));
			$init($CredentialsCache);
			$assignStatic($CredentialsCache::cacheName$, FileCredentialsCache::checkValidation(name));
			if ($CredentialsCache::cacheName$ == nullptr) {
				return nullptr;
			}
			fcc->init(principal, $CredentialsCache::cacheName$);
			return fcc;
		} catch ($IOException&) {
			$catch();
		} catch ($KrbException&) {
			$catch();
		}
		return nullptr;
	}
}

FileCredentialsCache* FileCredentialsCache::New($PrincipalName* principal) {
	$load(FileCredentialsCache);
	$synchronized(class$) {
		$init(FileCredentialsCache);
		try {
			$var(FileCredentialsCache, fcc, $new(FileCredentialsCache));
			$init($CredentialsCache);
			$assignStatic($CredentialsCache::cacheName$, FileCredentialsCache::getDefaultCacheName());
			fcc->init(principal, $CredentialsCache::cacheName$);
			return fcc;
		} catch ($IOException&) {
			$var($IOException, e, $catch());
			if (FileCredentialsCache::DEBUG) {
				e->printStackTrace();
			}
		} catch ($KrbException&) {
			$var($KrbException, e, $catch());
			if (FileCredentialsCache::DEBUG) {
				e->printStackTrace();
			}
		}
		return nullptr;
	}
}

void FileCredentialsCache::init$() {
	$CredentialsCache::init$();
	$set(this, configEntries, $new($ArrayList));
}

bool FileCredentialsCache::exists($String* cache) {
	$var($File, file, $new($File, cache));
	if (file->exists()) {
		return true;
	} else {
		return false;
	}
}

void FileCredentialsCache::init($PrincipalName* principal, $String* name) {
	$synchronized(this) {
		$set(this, primaryPrincipal, principal);
		{
			$var($FileOutputStream, fos, $new($FileOutputStream, name));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						$var($CCacheOutputStream, cos, $new($CCacheOutputStream, fos));
						{
							$var($Throwable, var$1, nullptr);
							try {
								try {
									this->version = $FileCCacheConstants::KRB5_FCC_FVNO_3;
									cos->writeHeader(this->primaryPrincipal, this->version);
								} catch ($Throwable&) {
									$var($Throwable, t$, $catch());
									try {
										cos->close();
									} catch ($Throwable&) {
										$var($Throwable, x2, $catch());
										t$->addSuppressed(x2);
									}
									$throw(t$);
								}
							} catch ($Throwable&) {
								$assign(var$1, $catch());
							} /*finally*/ {
								cos->close();
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
						}
					} catch ($Throwable&) {
						$var($Throwable, t$, $catch());
						try {
							fos->close();
						} catch ($Throwable&) {
							$var($Throwable, x2, $catch());
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable&) {
					$assign(var$0, $catch());
				} /*finally*/ {
					fos->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
		load(name);
	}
}

void FileCredentialsCache::load($String* name) {
	$synchronized(this) {
		$var($PrincipalName, p, nullptr);
		{
			$var($FileInputStream, fis, $new($FileInputStream, name));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						$var($CCacheInputStream, cis, $new($CCacheInputStream, fis));
						{
							$var($Throwable, var$1, nullptr);
							try {
								try {
									this->version = cis->readVersion();
									if (this->version == $FileCCacheConstants::KRB5_FCC_FVNO_4) {
										$set(this, tag, cis->readTag());
									} else {
										$set(this, tag, nullptr);
										if (this->version == $FileCCacheConstants::KRB5_FCC_FVNO_1 || this->version == $FileCCacheConstants::KRB5_FCC_FVNO_2) {
											cis->setNativeByteOrder();
										}
									}
									$assign(p, cis->readPrincipal(this->version));
									if (this->primaryPrincipal != nullptr) {
										if (!($nc(this->primaryPrincipal)->match(p))) {
											$throwNew($IOException, "Primary principals don\'t match."_s);
										}
									} else {
										$set(this, primaryPrincipal, p);
									}
									$set(this, credentialsList, $new($Vector));
									while (cis->available() > 0) {
										$var($Object, cred, cis->readCred(this->version));
										if (cred != nullptr) {
											if ($instanceOf($Credentials, cred)) {
												$nc(this->credentialsList)->addElement($cast($Credentials, cred));
											} else {
												addConfigEntry($cast($CredentialsCache$ConfigEntry, cred));
											}
										}
									}
								} catch ($Throwable&) {
									$var($Throwable, t$, $catch());
									try {
										cis->close();
									} catch ($Throwable&) {
										$var($Throwable, x2, $catch());
										t$->addSuppressed(x2);
									}
									$throw(t$);
								}
							} catch ($Throwable&) {
								$assign(var$1, $catch());
							} /*finally*/ {
								cis->close();
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
						}
					} catch ($Throwable&) {
						$var($Throwable, t$, $catch());
						try {
							fis->close();
						} catch ($Throwable&) {
							$var($Throwable, x2, $catch());
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable&) {
					$assign(var$0, $catch());
				} /*finally*/ {
					fis->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	}
}

void FileCredentialsCache::update($Credentials* c) {
	$synchronized(this) {
		if (this->credentialsList != nullptr) {
			if ($nc(this->credentialsList)->isEmpty()) {
				$nc(this->credentialsList)->addElement(c);
			} else {
				$var($Credentials, tmp, nullptr);
				bool matched = false;
				for (int32_t i = 0; i < $nc(this->credentialsList)->size(); ++i) {
					$assign(tmp, $cast($Credentials, $nc(this->credentialsList)->elementAt(i)));
					$var($StringArray, var$1, $nc($nc(c)->sname)->getNameStrings());
					bool var$0 = match(var$1, $($nc($nc(tmp)->sname)->getNameStrings()));
					if (var$0 && ($nc(($($nc($nc(c)->sname)->getRealmString())))->equalsIgnoreCase($($nc($nc(tmp)->sname)->getRealmString())))) {
						matched = true;
						int64_t var$2 = $nc(c->endtime)->getTime();
						if (var$2 >= $nc($nc(tmp)->endtime)->getTime()) {
							if (FileCredentialsCache::DEBUG) {
								$init($System);
								$nc($System::out)->println(" >>> FileCredentialsCache Ticket matched, overwrite the old one."_s);
							}
							$nc(this->credentialsList)->removeElementAt(i);
							$nc(this->credentialsList)->addElement(c);
						}
					}
				}
				if (matched == false) {
					if (FileCredentialsCache::DEBUG) {
						$init($System);
						$nc($System::out)->println(" >>> FileCredentialsCache Ticket not exactly matched, add new one into cache."_s);
					}
					$nc(this->credentialsList)->addElement(c);
				}
			}
		}
	}
}

$PrincipalName* FileCredentialsCache::getPrimaryPrincipal() {
	$synchronized(this) {
		return this->primaryPrincipal;
	}
}

void FileCredentialsCache::save() {
	$synchronized(this) {
		{
			$init($CredentialsCache);
			$var($FileOutputStream, fos, $new($FileOutputStream, $CredentialsCache::cacheName$));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						$var($CCacheOutputStream, cos, $new($CCacheOutputStream, fos));
						{
							$var($Throwable, var$1, nullptr);
							try {
								try {
									cos->writeHeader(this->primaryPrincipal, this->version);
									$var($CredentialsArray, tmp, nullptr);
									if (($assign(tmp, getCredsList())) != nullptr) {
										for (int32_t i = 0; i < $nc(tmp)->length; ++i) {
											cos->addCreds(tmp->get(i));
										}
									}
									{
										$var($Iterator, i$, $nc($(getConfigEntries()))->iterator());
										for (; $nc(i$)->hasNext();) {
											$var($CredentialsCache$ConfigEntry, e, $cast($CredentialsCache$ConfigEntry, i$->next()));
											{
												cos->addConfigEntry(this->primaryPrincipal, e);
											}
										}
									}
								} catch ($Throwable&) {
									$var($Throwable, t$, $catch());
									try {
										cos->close();
									} catch ($Throwable&) {
										$var($Throwable, x2, $catch());
										t$->addSuppressed(x2);
									}
									$throw(t$);
								}
							} catch ($Throwable&) {
								$assign(var$1, $catch());
							} /*finally*/ {
								cos->close();
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
						}
					} catch ($Throwable&) {
						$var($Throwable, t$, $catch());
						try {
							fos->close();
						} catch ($Throwable&) {
							$var($Throwable, x2, $catch());
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable&) {
					$assign(var$0, $catch());
				} /*finally*/ {
					fos->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	}
}

bool FileCredentialsCache::match($StringArray* s1, $StringArray* s2) {
	if ($nc(s1)->length != $nc(s2)->length) {
		return false;
	} else {
		for (int32_t i = 0; i < s1->length; ++i) {
			if (!($nc(s1->get(i))->equalsIgnoreCase(s2->get(i)))) {
				return false;
			}
		}
	}
	return true;
}

$CredentialsArray* FileCredentialsCache::getCredsList() {
	$synchronized(this) {
		if ((this->credentialsList == nullptr) || ($nc(this->credentialsList)->isEmpty())) {
			return nullptr;
		} else {
			$var($CredentialsArray, tmp, $new($CredentialsArray, $nc(this->credentialsList)->size()));
			for (int32_t i = 0; i < $nc(this->credentialsList)->size(); ++i) {
				tmp->set(i, $cast($Credentials, $($nc(this->credentialsList)->elementAt(i))));
			}
			return tmp;
		}
	}
}

$Credentials* FileCredentialsCache::getCreds($LoginOptions* options, $PrincipalName* sname) {
	if (options == nullptr) {
		return getCreds(sname);
	} else {
		$var($CredentialsArray, list, getCredsList());
		if (list == nullptr) {
			return nullptr;
		} else {
			for (int32_t i = 0; i < $nc(list)->length; ++i) {
				if ($nc(sname)->match($nc(list->get(i))->sname)) {
					if ($nc($nc(list->get(i))->flags)->match(options)) {
						return list->get(i);
					}
				}
			}
		}
		return nullptr;
	}
}

void FileCredentialsCache::addConfigEntry($CredentialsCache$ConfigEntry* e) {
	$nc(this->configEntries)->add(e);
}

$List* FileCredentialsCache::getConfigEntries() {
	return $Collections::unmodifiableList(this->configEntries);
}

$Credentials* FileCredentialsCache::getCreds($PrincipalName* sname) {
	$var($CredentialsArray, list, getCredsList());
	if (list == nullptr) {
		return nullptr;
	} else {
		for (int32_t i = 0; i < $nc(list)->length; ++i) {
			if ($nc(sname)->match($nc(list->get(i))->sname)) {
				return list->get(i);
			}
		}
	}
	return nullptr;
}

$1Credentials* FileCredentialsCache::getInitialCreds() {
	$var($Credentials, defaultCreds, getDefaultCreds());
	if (defaultCreds == nullptr) {
		return nullptr;
	}
	$var($1Credentials, tgt, $nc(defaultCreds)->setKrbCreds());
	$var($CredentialsCache$ConfigEntry, entry, getConfigEntry("proxy_impersonator"_s));
	if (entry == nullptr) {
		if (FileCredentialsCache::DEBUG) {
			$init($System);
			$nc($System::out)->println("get normal credential"_s);
		}
		return tgt;
	}
	bool force = false;
	$var($String, prop, $SecurityProperties::privilegedGetOverridable("jdk.security.krb5.default.initiate.credential"_s));
	if (prop == nullptr) {
		$assign(prop, "always-impersonate"_s);
	}
	{
		$var($String, s12798$, prop);
		int32_t tmp12798$ = -1;
		switch ($nc(s12798$)->hashCode()) {
		case 0x1A43A46D:
			{
				if (s12798$->equals("no-impersonate"_s)) {
					tmp12798$ = 0;
				}
				break;
			}
		case (int32_t)0xAA453167:
			{
				if (s12798$->equals("try-impersonate"_s)) {
					tmp12798$ = 1;
				}
				break;
			}
		case (int32_t)0xF2B923BB:
			{
				if (s12798$->equals("always-impersonate"_s)) {
					tmp12798$ = 2;
				}
				break;
			}
		}
		switch (tmp12798$) {
		case 0:
			{
				if (FileCredentialsCache::DEBUG) {
					$init($System);
					$nc($System::out)->println("get normal credential"_s);
				}
				return tgt;
			}
		case 1:
			{
				force = false;
				break;
			}
		case 2:
			{
				force = true;
				break;
			}
		default:
			{
				$throwNew($RuntimeException, "Invalid jdk.security.krb5.default.initiate.credential"_s);
			}
		}
	}
	try {
		$init($StandardCharsets);
		$var($PrincipalName, service, $new($PrincipalName, $$new($String, $($nc(entry)->getData()), $StandardCharsets::UTF_8)));
		if (!$nc($($nc(tgt)->getClient()))->equals(service)) {
			if (FileCredentialsCache::DEBUG) {
				$init($System);
				$nc($System::out)->println("proxy_impersonator does not match service name"_s);
			}
			return force ? ($1Credentials*)nullptr : tgt;
		}
		$var($PrincipalName, client, getPrimaryPrincipal());
		$var($Credentials, proxy, nullptr);
		{
			$var($CredentialsArray, arr$, getCredsList());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Credentials, c, arr$->get(i$));
				{
					bool var$0 = $nc($($nc(c)->getClientPrincipal()))->equals(client);
					if (var$0 && $nc($(c->getServicePrincipal()))->equals(service)) {
						$assign(proxy, c);
						break;
					}
				}
			}
		}
		if (proxy == nullptr) {
			if (FileCredentialsCache::DEBUG) {
				$init($System);
				$nc($System::out)->println("Cannot find evidence ticket in ccache"_s);
			}
			return force ? ($1Credentials*)nullptr : tgt;
		}
		if (FileCredentialsCache::DEBUG) {
			$init($System);
			$nc($System::out)->println("Get proxied credential"_s);
		}
		return $nc(tgt)->setProxy($($nc(proxy)->setKrbCreds()));
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		if (FileCredentialsCache::DEBUG) {
			$init($System);
			$nc($System::out)->println("Impersonation with ccache failed"_s);
		}
		return force ? ($1Credentials*)nullptr : tgt;
	}
	$shouldNotReachHere();
}

$Credentials* FileCredentialsCache::getDefaultCreds() {
	$var($CredentialsArray, list, getCredsList());
	if (list == nullptr) {
		return nullptr;
	} else {
		for (int32_t i = $nc(list)->length - 1; i >= 0; --i) {
			if ($nc($($nc($nc(list->get(i))->sname)->toString()))->startsWith("krbtgt"_s)) {
				$var($StringArray, nameStrings, $nc($nc(list->get(i))->sname)->getNameStrings());
				if ($nc($nc(nameStrings)->get(1))->equals($($nc($($nc($nc(list->get(i))->sname)->getRealm()))->toString()))) {
					return list->get(i);
				}
			}
		}
	}
	return nullptr;
}

$String* FileCredentialsCache::getDefaultCacheName() {
	$init(FileCredentialsCache);
	$beforeCallerSensitive();
	$var($String, stdCacheNameComponent, "krb5cc"_s);
	$var($String, name, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($FileCredentialsCache$1)))));
	if (name != nullptr) {
		if (FileCredentialsCache::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>>KinitOptions cache name is "_s, name}));
		}
		return name;
	}
	$var($String, osname, $GetPropertyAction::privilegedGetProperty("os.name"_s));
	if (osname != nullptr && !osname->startsWith("Windows"_s)) {
		int64_t uid = $VM::getuid();
		if (uid != -1) {
			$init($File);
			$assign(name, $str({$File::separator, "tmp"_s, $File::separator, stdCacheNameComponent, "_"_s, $$str(uid)}));
			if (FileCredentialsCache::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({">>>KinitOptions cache name is "_s, name}));
			}
			return name;
		} else {
			if (FileCredentialsCache::DEBUG) {
				$init($System);
				$nc($System::out)->println("Error in obtaining uid for Unix platforms Using user\'s home directory"_s);
			}
		}
	}
	$var($String, user_name, $GetPropertyAction::privilegedGetProperty("user.name"_s));
	$var($String, user_home, $GetPropertyAction::privilegedGetProperty("user.home"_s));
	if (user_home == nullptr) {
		$assign(user_home, $GetPropertyAction::privilegedGetProperty("user.dir"_s));
	}
	if (user_name != nullptr) {
		$init($File);
		$assign(name, $str({user_home, $File::separator, stdCacheNameComponent, "_"_s, user_name}));
	} else {
		$init($File);
		$assign(name, $str({user_home, $File::separator, stdCacheNameComponent}));
	}
	if (FileCredentialsCache::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>>KinitOptions cache name is "_s, name}));
	}
	return name;
}

$String* FileCredentialsCache::checkValidation($String* name) {
	$init(FileCredentialsCache);
	$var($String, fullname, nullptr);
	if (name == nullptr) {
		return nullptr;
	}
	try {
		$assign(fullname, ($$new($File, name))->getCanonicalPath());
		$var($File, fCheck, $new($File, fullname));
		if (!(fCheck->exists())) {
			$var($File, temp, $new($File, $(fCheck->getParent())));
			if (!(temp->isDirectory())) {
				$assign(fullname, nullptr);
			}
			$assign(temp, nullptr);
		}
		$assign(fCheck, nullptr);
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$assign(fullname, nullptr);
	}
	return fullname;
}

$String* FileCredentialsCache::exec($String* c) {
	$init(FileCredentialsCache);
	$beforeCallerSensitive();
	$var($StringTokenizer, st, $new($StringTokenizer, c));
	$var($Vector, v, $new($Vector));
	while (st->hasMoreTokens()) {
		v->addElement($(st->nextToken()));
	}
	$var($StringArray, command, $new($StringArray, v->size()));
	v->copyInto(command);
	try {
		$var($Process, p, $cast($Process, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($FileCredentialsCache$2, command)))));
		if (p == nullptr) {
			return nullptr;
		}
		$init($StandardCharsets);
		$var($BufferedReader, commandResult, $new($BufferedReader, $$new($InputStreamReader, $($nc(p)->getInputStream()), $StandardCharsets::ISO_8859_1)));
		$var($String, s1, nullptr);
		if ((command->length == 1) && ($nc(command->get(0))->equals("/usr/bin/env"_s))) {
			while (($assign(s1, commandResult->readLine())) != nullptr) {
				if ($nc(s1)->length() >= 11) {
					if (($(s1->substring(0, 11)))->equalsIgnoreCase("KRB5CCNAME="_s)) {
						$assign(s1, s1->substring(11));
						break;
					}
				}
			}
		} else {
			$assign(s1, commandResult->readLine());
		}
		commandResult->close();
		return s1;
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		if (FileCredentialsCache::DEBUG) {
			e->printStackTrace();
		}
	}
	return nullptr;
}

void clinit$FileCredentialsCache($Class* class$) {
	$init($Krb5);
	FileCredentialsCache::DEBUG = $Krb5::DEBUG;
}

FileCredentialsCache::FileCredentialsCache() {
}

$Class* FileCredentialsCache::load$($String* name, bool initialize) {
	$loadClass(FileCredentialsCache, name, initialize, &_FileCredentialsCache_ClassInfo_, clinit$FileCredentialsCache, allocate$FileCredentialsCache);
	return class$;
}

$Class* FileCredentialsCache::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun