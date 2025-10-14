#include <sun/security/krb5/internal/tools/Kinit.h>

#include <java/io/File.h>
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
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Arrays.h>
#include <javax/security/auth/kerberos/KeyTab.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/KrbAsReqBuilder.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/ccache/Credentials.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache.h>
#include <sun/security/krb5/internal/tools/KinitOptions.h>
#include <sun/security/util/Password.h>
#include <jcpp.h>

#undef DEBUG
#undef FORWARDABLE
#undef PROXIABLE

using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $KeyTab = ::javax::security::auth::kerberos::KeyTab;
using $Config = ::sun::security::krb5::Config;
using $1Credentials = ::sun::security::krb5::Credentials;
using $KrbAsReqBuilder = ::sun::security::krb5::KrbAsReqBuilder;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Credentials = ::sun::security::krb5::internal::ccache::Credentials;
using $CredentialsCache = ::sun::security::krb5::internal::ccache::CredentialsCache;
using $KinitOptions = ::sun::security::krb5::internal::tools::KinitOptions;
using $Password = ::sun::security::util::Password;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace tools {

$FieldInfo _Kinit_FieldInfo_[] = {
	{"options", "Lsun/security/krb5/internal/tools/KinitOptions;", nullptr, $PRIVATE, $field(Kinit, options)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Kinit, DEBUG)},
	{}
};

$MethodInfo _Kinit_MethodInfo_[] = {
	{"<init>", "([Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(Kinit::*)($StringArray*)>(&Kinit::init$)), "java.io.IOException,sun.security.krb5.RealmException,sun.security.krb5.KrbException"},
	{"acquire", "()V", nullptr, $PRIVATE, $method(static_cast<void(Kinit::*)()>(&Kinit::acquire)), "java.io.IOException,sun.security.krb5.RealmException,sun.security.krb5.KrbException"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($StringArray*)>(&Kinit::main))},
	{"renew", "()V", nullptr, $PRIVATE, $method(static_cast<void(Kinit::*)()>(&Kinit::renew)), "java.io.IOException,sun.security.krb5.RealmException,sun.security.krb5.KrbException"},
	{"setOptions", "(IILsun/security/krb5/internal/KDCOptions;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)(int32_t,int32_t,$KDCOptions*)>(&Kinit::setOptions))},
	{}
};

$ClassInfo _Kinit_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.tools.Kinit",
	"java.lang.Object",
	nullptr,
	_Kinit_FieldInfo_,
	_Kinit_MethodInfo_
};

$Object* allocate$Kinit($Class* clazz) {
	return $of($alloc(Kinit));
}

bool Kinit::DEBUG = false;

void Kinit::main($StringArray* args) {
	$init(Kinit);
	try {
		$var(Kinit, self, $new(Kinit, args));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$var($String, msg, nullptr);
		if ($instanceOf($KrbException, e)) {
			$var($String, var$0, $$str({$($nc(($cast($KrbException, e)))->krbErrorMessage()), " "_s}));
			$assign(msg, $concat(var$0, $($nc(($cast($KrbException, e)))->returnCodeMessage())));
		} else {
			$assign(msg, e->getMessage());
		}
		if (msg != nullptr) {
			$init($System);
			$nc($System::err)->println($$str({"Exception: "_s, msg}));
		} else {
			$init($System);
			$nc($System::out)->println($$str({"Exception: "_s, e}));
		}
		e->printStackTrace();
		$System::exit(-1);
	}
	return;
}

void Kinit::init$($StringArray* args) {
	if (args == nullptr || $nc(args)->length == 0) {
		$set(this, options, $new($KinitOptions));
	} else {
		$set(this, options, $new($KinitOptions, args));
	}
	switch ($nc(this->options)->action) {
	case 1:
		{
			acquire();
			break;
		}
	case 2:
		{
			renew();
			break;
		}
	default:
		{
			$throwNew($KrbException, $$str({"kinit does not support action "_s, $$str($nc(this->options)->action)}));
		}
	}
}

void Kinit::renew() {
	$var($PrincipalName, principal, $nc(this->options)->getPrincipal());
	$var($String, realm, $nc(principal)->getRealmAsString());
	$var($CredentialsCache, cache, $CredentialsCache::getInstance($nc(this->options)->cachename));
	if (cache == nullptr) {
		$throwNew($IOException, $$str({"Unable to find existing cache file "_s, $nc(this->options)->cachename}));
	}
	$var($Credentials, credentials, $nc(cache)->getCreds($($PrincipalName::tgsService(realm, realm))));
	$assign(credentials, $nc($($nc($($nc(credentials)->setKrbCreds()))->renew()))->toCCacheCreds());
	$assign(cache, $CredentialsCache::create(principal, $nc(this->options)->cachename));
	if (cache == nullptr) {
		$throwNew($IOException, $$str({"Unable to create the cache file "_s, $nc(this->options)->cachename}));
	}
	cache->update(credentials);
	cache->save();
}

void Kinit::acquire() {
	$var($String, princName, nullptr);
	$var($PrincipalName, principal, $nc(this->options)->getPrincipal());
	if (principal != nullptr) {
		$assign(princName, principal->toString());
	}
	$var($KrbAsReqBuilder, builder, nullptr);
	if (Kinit::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"Principal is "_s, principal}));
	}
	$var($chars, psswd, $nc(this->options)->password);
	bool useKeytab = $nc(this->options)->useKeytabFile();
	if (!useKeytab) {
		if (princName == nullptr) {
			$throwNew($IllegalArgumentException, " Can not obtain principal name"_s);
		}
		if (psswd == nullptr) {
			$init($System);
			$nc($System::out)->print($$str({"Password for "_s, princName, ":"_s}));
			$nc($System::out)->flush();
			$assign(psswd, $Password::readPassword($System::in));
			if (Kinit::DEBUG) {
				$nc($System::out)->println($$str({">>> Kinit console input "_s, $$new($String, psswd)}));
			}
		}
		$assign(builder, $new($KrbAsReqBuilder, principal, psswd));
	} else {
		if (Kinit::DEBUG) {
			$init($System);
			$nc($System::out)->println(">>> Kinit using keytab"_s);
		}
		if (princName == nullptr) {
			$throwNew($IllegalArgumentException, "Principal name must be specified."_s);
		}
		$var($String, ktabName, $nc(this->options)->keytabFileName());
		if (ktabName != nullptr) {
			if (Kinit::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({">>> Kinit keytab file name: "_s, ktabName}));
			}
		}
		$assign(builder, $new($KrbAsReqBuilder, principal, ktabName == nullptr ? $($KeyTab::getInstance()) : $($KeyTab::getInstance($$new($File, ktabName)))));
	}
	$var($KDCOptions, opt, $new($KDCOptions));
	setOptions($KDCOptions::FORWARDABLE, $nc(this->options)->forwardable, opt);
	setOptions($KDCOptions::PROXIABLE, $nc(this->options)->proxiable, opt);
	$nc(builder)->setOptions(opt);
	$var($String, realm, $nc(this->options)->getKDCRealm());
	if (realm == nullptr) {
		$assign(realm, $nc($($Config::getInstance()))->getDefaultRealm());
	}
	if (Kinit::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>> Kinit realm name is "_s, realm}));
	}
	$var($PrincipalName, sname, $PrincipalName::tgsService(realm, realm));
	builder->setTarget(sname);
	if (Kinit::DEBUG) {
		$init($System);
		$nc($System::out)->println(">>> Creating KrbAsReq"_s);
	}
	if ($nc(this->options)->getAddressOption()) {
		builder->setAddresses($($HostAddresses::getLocalAddresses()));
	}
	builder->setTill($nc(this->options)->lifetime);
	builder->setRTime($nc(this->options)->renewable_lifetime);
	builder->action();
	$var($Credentials, credentials, builder->getCCreds());
	builder->destroy();
	$var($CredentialsCache, cache, $CredentialsCache::create(principal, $nc(this->options)->cachename));
	if (cache == nullptr) {
		$throwNew($IOException, $$str({"Unable to create the cache file "_s, $nc(this->options)->cachename}));
	}
	$nc(cache)->update(credentials);
	cache->save();
	if ($nc(this->options)->password == nullptr) {
		$init($System);
		$nc($System::out)->println($$str({"New ticket is stored in cache file "_s, $nc(this->options)->cachename}));
	} else {
		$Arrays::fill($nc(this->options)->password, u'0');
	}
	if (psswd != nullptr) {
		$Arrays::fill(psswd, u'0');
	}
	$set(this, options, nullptr);
}

void Kinit::setOptions(int32_t flag, int32_t option, $KDCOptions* opt) {
	$init(Kinit);
	switch (option) {
	case 0:
		{
			break;
		}
	case -1:
		{
			$nc(opt)->set(flag, false);
			break;
		}
	case 1:
		{
			$nc(opt)->set(flag, true);
		}
	}
}

void clinit$Kinit($Class* class$) {
	$init($Krb5);
	Kinit::DEBUG = $Krb5::DEBUG;
}

Kinit::Kinit() {
}

$Class* Kinit::load$($String* name, bool initialize) {
	$loadClass(Kinit, name, initialize, &_Kinit_ClassInfo_, clinit$Kinit, allocate$Kinit);
	return class$;
}

$Class* Kinit::class$ = nullptr;

				} // tools
			} // internal
		} // krb5
	} // security
} // sun