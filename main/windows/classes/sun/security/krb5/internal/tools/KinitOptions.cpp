#include <sun/security/krb5/internal/tools/KinitOptions.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/FileInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/time/Instant.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/RealmException.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/ccache/CCacheInputStream.h>
#include <sun/security/krb5/internal/ccache/FileCCacheConstants.h>
#include <sun/security/krb5/internal/ccache/FileCredentialsCache.h>
#include <sun/security/krb5/internal/ccache/Tag.h>
#include <jcpp.h>

#undef DEBUG
#undef KRB5_FCC_FVNO_1
#undef KRB5_FCC_FVNO_2
#undef KRB5_FCC_FVNO_4

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $FileInputStream = ::java::io::FileInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Instant = ::java::time::Instant;
using $Config = ::sun::security::krb5::Config;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $RealmException = ::sun::security::krb5::RealmException;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $CCacheInputStream = ::sun::security::krb5::internal::ccache::CCacheInputStream;
using $FileCCacheConstants = ::sun::security::krb5::internal::ccache::FileCCacheConstants;
using $FileCredentialsCache = ::sun::security::krb5::internal::ccache::FileCredentialsCache;
using $Tag = ::sun::security::krb5::internal::ccache::Tag;
using $KrbDataInputStream = ::sun::security::krb5::internal::util::KrbDataInputStream;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace tools {

$FieldInfo _KinitOptions_FieldInfo_[] = {
	{"action", "I", nullptr, $PUBLIC, $field(KinitOptions, action)},
	{"forwardable", "S", nullptr, $PUBLIC, $field(KinitOptions, forwardable)},
	{"proxiable", "S", nullptr, $PUBLIC, $field(KinitOptions, proxiable)},
	{"lifetime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KinitOptions, lifetime)},
	{"renewable_lifetime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC, $field(KinitOptions, renewable_lifetime)},
	{"target_service", "Ljava/lang/String;", nullptr, $PUBLIC, $field(KinitOptions, target_service)},
	{"keytab_file", "Ljava/lang/String;", nullptr, $PUBLIC, $field(KinitOptions, keytab_file)},
	{"cachename", "Ljava/lang/String;", nullptr, $PUBLIC, $field(KinitOptions, cachename)},
	{"principal", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KinitOptions, principal)},
	{"realm", "Ljava/lang/String;", nullptr, $PUBLIC, $field(KinitOptions, realm)},
	{"password", "[C", nullptr, 0, $field(KinitOptions, password)},
	{"keytab", "Z", nullptr, $PUBLIC, $field(KinitOptions, keytab)},
	{"DEBUG", "Z", nullptr, $PRIVATE, $field(KinitOptions, DEBUG)},
	{"includeAddresses", "Z", nullptr, $PRIVATE, $field(KinitOptions, includeAddresses)},
	{"useKeytab", "Z", nullptr, $PRIVATE, $field(KinitOptions, useKeytab)},
	{"ktabName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(KinitOptions, ktabName)},
	{}
};

$MethodInfo _KinitOptions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(KinitOptions::*)()>(&KinitOptions::init$)), "java.lang.RuntimeException,sun.security.krb5.RealmException"},
	{"<init>", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KinitOptions::*)($StringArray*)>(&KinitOptions::init$)), "sun.security.krb5.KrbException,java.lang.RuntimeException,java.io.IOException"},
	{"getAddressOption", "()Z", nullptr, $PUBLIC},
	{"getDefaultPrincipal", "()Lsun/security/krb5/PrincipalName;", nullptr, 0},
	{"getKDCRealm", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getPrincipal", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC},
	{"getTime", "(I)Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $method(static_cast<$KerberosTime*(KinitOptions::*)(int32_t)>(&KinitOptions::getTime))},
	{"keytabFileName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"printHelp", "()V", nullptr, 0},
	{"setKDCRealm", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "sun.security.krb5.RealmException"},
	{"useKeytabFile", "()Z", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KinitOptions_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.internal.tools.KinitOptions",
	"java.lang.Object",
	nullptr,
	_KinitOptions_FieldInfo_,
	_KinitOptions_MethodInfo_
};

$Object* allocate$KinitOptions($Class* clazz) {
	return $of($alloc(KinitOptions));
}

void KinitOptions::init$() {
	this->action = 1;
	this->forwardable = (int16_t)0;
	this->proxiable = (int16_t)0;
	$set(this, password, nullptr);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	this->includeAddresses = true;
	this->useKeytab = false;
	$set(this, cachename, $FileCredentialsCache::getDefaultCacheName());
	if (this->cachename == nullptr) {
		$throwNew($RuntimeException, "default cache name error"_s);
	}
	$set(this, principal, getDefaultPrincipal());
}

void KinitOptions::setKDCRealm($String* r) {
	$set(this, realm, r);
}

$String* KinitOptions::getKDCRealm() {
	if (this->realm == nullptr) {
		if (this->principal != nullptr) {
			return $nc(this->principal)->getRealmString();
		}
	}
	return nullptr;
}

void KinitOptions::init$($StringArray* args) {
	this->action = 1;
	this->forwardable = (int16_t)0;
	this->proxiable = (int16_t)0;
	$set(this, password, nullptr);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	this->includeAddresses = true;
	this->useKeytab = false;
	$var($String, p, nullptr);
	for (int32_t i = 0; i < $nc(args)->length; ++i) {
		if ($nc(args->get(i))->equals("-f"_s)) {
			this->forwardable = (int16_t)1;
		} else if ($nc(args->get(i))->equals("-p"_s)) {
			this->proxiable = (int16_t)1;
		} else if ($nc(args->get(i))->equals("-c"_s)) {
			if ($nc(args->get(i + 1))->startsWith("-"_s)) {
				$throwNew($IllegalArgumentException, "input format  not correct:  -c  option must be followed by the cache name"_s);
			}
			$set(this, cachename, args->get(++i));
			bool var$0 = ($nc(this->cachename)->length() >= 5);
			if (var$0 && $($nc(this->cachename)->substring(0, 5))->equalsIgnoreCase("FILE:"_s)) {
				$set(this, cachename, $nc(this->cachename)->substring(5));
			}
		} else if ($nc(args->get(i))->equals("-A"_s)) {
			this->includeAddresses = false;
		} else if ($nc(args->get(i))->equals("-k"_s)) {
			this->useKeytab = true;
		} else if ($nc(args->get(i))->equals("-t"_s)) {
			if (this->ktabName != nullptr) {
				$throwNew($IllegalArgumentException, "-t option/keytab file name repeated"_s);
			} else if (i + 1 < args->length) {
				$set(this, ktabName, args->get(++i));
			} else {
				$throwNew($IllegalArgumentException, "-t option requires keytab file name"_s);
			}
			this->useKeytab = true;
		} else if ($nc(args->get(i))->equals("-R"_s)) {
			this->action = 2;
		} else if ($nc(args->get(i))->equals("-l"_s)) {
			$set(this, lifetime, getTime($Config::duration(args->get(++i))));
		} else if ($nc(args->get(i))->equals("-r"_s)) {
			$set(this, renewable_lifetime, getTime($Config::duration(args->get(++i))));
		} else {
			bool var$6 = $nc(args->get(i))->equalsIgnoreCase("-?"_s);
			bool var$5 = var$6 || $nc(args->get(i))->equalsIgnoreCase("-h"_s);
			bool var$4 = var$5 || $nc(args->get(i))->equalsIgnoreCase("--help"_s);
			if (var$4 || $nc(args->get(i))->equalsIgnoreCase("-help"_s)) {
				printHelp();
				$System::exit(0);
			} else if (p == nullptr) {
				$assign(p, args->get(i));
				try {
					$set(this, principal, $new($PrincipalName, p));
				} catch ($Exception&) {
					$var($Exception, e, $catch());
					$throwNew($IllegalArgumentException, $$str({"invalid Principal name: "_s, p, $(e->getMessage())}));
				}
			} else if (this->password == nullptr) {
				$set(this, password, $nc(args->get(i))->toCharArray());
			} else {
				$throwNew($IllegalArgumentException, "too many parameters"_s);
			}
		}
	}
	if (this->cachename == nullptr) {
		$set(this, cachename, $FileCredentialsCache::getDefaultCacheName());
		if (this->cachename == nullptr) {
			$throwNew($RuntimeException, "default cache name error"_s);
		}
	}
	if (this->principal == nullptr) {
		$set(this, principal, getDefaultPrincipal());
	}
}

$PrincipalName* KinitOptions::getDefaultPrincipal() {
	try {
		$var($CCacheInputStream, cis, $new($CCacheInputStream, $$new($FileInputStream, this->cachename)));
		int32_t version = 0;
		if ((version = cis->readVersion()) == $FileCCacheConstants::KRB5_FCC_FVNO_4) {
			cis->readTag();
		} else if (version == $FileCCacheConstants::KRB5_FCC_FVNO_1 || version == $FileCCacheConstants::KRB5_FCC_FVNO_2) {
			cis->setNativeByteOrder();
		}
		$var($PrincipalName, p, cis->readPrincipal(version));
		cis->close();
		if (this->DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>>KinitOptions principal name from the cache is: "_s, p}));
		}
		return p;
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		if (this->DEBUG) {
			e->printStackTrace();
		}
	} catch ($RealmException&) {
		$var($RealmException, e, $catch());
		if (this->DEBUG) {
			e->printStackTrace();
		}
	}
	$var($String, username, $System::getProperty("user.name"_s));
	if (this->DEBUG) {
		$nc($System::out)->println($$str({">>>KinitOptions default username is: "_s, username}));
	}
	try {
		$var($PrincipalName, p, $new($PrincipalName, username));
		return p;
	} catch ($RealmException&) {
		$var($RealmException, e, $catch());
		if (this->DEBUG) {
			$nc($System::out)->println($$str({"Exception in getting principal name "_s, $(e->getMessage())}));
			e->printStackTrace();
		}
	}
	return nullptr;
}

void KinitOptions::printHelp() {
	$init($System);
	$nc($System::out)->println("Usage:\n\n1. Initial ticket request:\n    kinit [-A] [-f] [-p] [-c cachename] [-l lifetime] [-r renewable_time]\n          [[-k [-t keytab_file_name]] [principal] [password]"_s);
	$nc($System::out)->println("2. Renew a ticket:\n    kinit -R [-c cachename] [principal]"_s);
	$nc($System::out)->println("\nAvailable options to Kerberos 5 ticket request:"_s);
	$nc($System::out)->println("\t-A   do not include addresses"_s);
	$nc($System::out)->println("\t-f   forwardable"_s);
	$nc($System::out)->println("\t-p   proxiable"_s);
	$nc($System::out)->println("\t-c   cache name (i.e., FILE:\\d:\\myProfiles\\mykrb5cache)"_s);
	$nc($System::out)->println("\t-l   lifetime"_s);
	$nc($System::out)->println("\t-r   renewable time (total lifetime a ticket can be renewed)"_s);
	$nc($System::out)->println("\t-k   use keytab"_s);
	$nc($System::out)->println("\t-t   keytab file name"_s);
	$nc($System::out)->println("\tprincipal   the principal name (i.e., qweadf@ATHENA.MIT.EDU qweadf)"_s);
	$nc($System::out)->println("\tpassword    the principal\'s Kerberos password"_s);
}

bool KinitOptions::getAddressOption() {
	return this->includeAddresses;
}

bool KinitOptions::useKeytabFile() {
	return this->useKeytab;
}

$String* KinitOptions::keytabFileName() {
	return this->ktabName;
}

$PrincipalName* KinitOptions::getPrincipal() {
	return this->principal;
}

$KerberosTime* KinitOptions::getTime(int32_t s) {
	return $new($KerberosTime, $($nc($($Instant::now()))->plusSeconds(s)));
}

KinitOptions::KinitOptions() {
}

$Class* KinitOptions::load$($String* name, bool initialize) {
	$loadClass(KinitOptions, name, initialize, &_KinitOptions_ClassInfo_, allocate$KinitOptions);
	return class$;
}

$Class* KinitOptions::class$ = nullptr;

				} // tools
			} // internal
		} // krb5
	} // security
} // sun