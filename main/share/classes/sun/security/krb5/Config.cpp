#include <sun/security/krb5/Config.h>

#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/PrintStream.h>
#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/Boolean.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Class.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/String.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/Void.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/HashSet.h>
#include <java/util/Hashtable.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/PropertyPermission.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <java/util/Vector.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <sun/net/dns/ResolverConfiguration.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/Config$1.h>
#include <sun/security/krb5/Config$2.h>
#include <sun/security/krb5/Config$3.h>
#include <sun/security/krb5/Config$FileExistsAction.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/KdcComm.h>
#include <sun/security/krb5/KrbAsReqBuilder$ReferralsState.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/KrbServiceLocator.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/SCDynamicStoreConfig.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <sun/security/util/SecurityProperties.h>
#include <jcpp.h>

#undef BASE16_0
#undef BASE16_1
#undef BASE16_2
#undef BASE16_3
#undef CASE_INSENSITIVE
#undef CKSUMTYPE_CRC32
#undef CKSUMTYPE_DES_MAC
#undef CKSUMTYPE_DES_MAC_K
#undef CKSUMTYPE_HMAC_MD5_ARCFOUR
#undef CKSUMTYPE_HMAC_SHA1_DES3_KD
#undef CKSUMTYPE_RSA_MD5
#undef CKSUMTYPE_RSA_MD5_DES
#undef DEBUG
#undef DISABLE_REFERRALS
#undef ETYPE_ARCFOUR_HMAC
#undef ETYPE_DES3_CBC_HMAC_SHA1_KD
#undef ETYPE_DES_CBC_CRC
#undef ETYPE_DES_CBC_MD4
#undef ETYPE_DES_CBC_MD5
#undef ETYPE_NULL
#undef FALSE
#undef KRB_ERR_GENERIC
#undef MAX_REFERRALS
#undef MIN_VALUE
#undef PREF_FILE
#undef TRUE
#undef US

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $PermissionArray = $Array<::java::security::Permission>;
using $Closeable = ::java::io::Closeable;
using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $Files = ::java::nio::file::Files;
using $LinkOption = ::java::nio::file::LinkOption;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $AbstractList = ::java::util::AbstractList;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $HashSet = ::java::util::HashSet;
using $Hashtable = ::java::util::Hashtable;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $PropertyPermission = ::java::util::PropertyPermission;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $Vector = ::java::util::Vector;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $ResolverConfiguration = ::sun::net::dns::ResolverConfiguration;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $Checksum = ::sun::security::krb5::Checksum;
using $Config$1 = ::sun::security::krb5::Config$1;
using $Config$2 = ::sun::security::krb5::Config$2;
using $Config$3 = ::sun::security::krb5::Config$3;
using $Config$FileExistsAction = ::sun::security::krb5::Config$FileExistsAction;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $KdcComm = ::sun::security::krb5::KdcComm;
using $KrbAsReqBuilder$ReferralsState = ::sun::security::krb5::KrbAsReqBuilder$ReferralsState;
using $KrbException = ::sun::security::krb5::KrbException;
using $KrbServiceLocator = ::sun::security::krb5::KrbServiceLocator;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $SCDynamicStoreConfig = ::sun::security::krb5::SCDynamicStoreConfig;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $EType = ::sun::security::krb5::internal::crypto::EType;
using $SecurityProperties = ::sun::security::util::SecurityProperties;

namespace sun {
	namespace security {
		namespace krb5 {

class Config$$Lambda$lambda$loadConfigFile$0 : public $PrivilegedAction {
	$class(Config$$Lambda$lambda$loadConfigFile$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* fileName) {
		$set(this, fileName, fileName);
	}
	virtual $Object* run() override {
		 return $of(Config::lambda$loadConfigFile$0(fileName));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Config$$Lambda$lambda$loadConfigFile$0>());
	}
	$String* fileName = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Config$$Lambda$lambda$loadConfigFile$0::fieldInfos[2] = {
	{"fileName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Config$$Lambda$lambda$loadConfigFile$0, fileName)},
	{}
};
$MethodInfo Config$$Lambda$lambda$loadConfigFile$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Config$$Lambda$lambda$loadConfigFile$0::*)($String*)>(&Config$$Lambda$lambda$loadConfigFile$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Config$$Lambda$lambda$loadConfigFile$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.krb5.Config$$Lambda$lambda$loadConfigFile$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Config$$Lambda$lambda$loadConfigFile$0::load$($String* name, bool initialize) {
	$loadClass(Config$$Lambda$lambda$loadConfigFile$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Config$$Lambda$lambda$loadConfigFile$0::class$ = nullptr;

$FieldInfo _Config_FieldInfo_[] = {
	{"DISABLE_REFERRALS", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Config, DISABLE_REFERRALS)},
	{"MAX_REFERRALS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Config, MAX_REFERRALS)},
	{"singleton", "Lsun/security/krb5/Config;", nullptr, $PRIVATE | $STATIC, $staticField(Config, singleton)},
	{"stanzaTable", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE, $field(Config, stanzaTable)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(Config, DEBUG)},
	{"BASE16_0", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Config, BASE16_0)},
	{"BASE16_1", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Config, BASE16_1)},
	{"BASE16_2", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Config, BASE16_2)},
	{"BASE16_3", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Config, BASE16_3)},
	{"defaultRealm", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Config, defaultRealm)},
	{"defaultKDC", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Config, defaultKDC)},
	{}
};

$MethodInfo _Config_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Config::*)()>(&Config::init$)), "sun.security.krb5.KrbException"},
	{"checkRealm", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($String*)>(&Config::checkRealm))},
	{"defaultEtype", "(Ljava/lang/String;)[I", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException"},
	{"duration", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($String*)>(&Config::duration)), "sun.security.krb5.KrbException"},
	{"exists", "([Ljava/lang/String;)Z", nullptr, $PUBLIC | $TRANSIENT},
	{"fileExists", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(static_cast<bool(Config::*)($String*)>(&Config::fileExists))},
	{"findMacosConfigFile", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Config::*)()>(&Config::findMacosConfigFile))},
	{"get", "([Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $TRANSIENT},
	{"get0", "([Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PRIVATE | $TRANSIENT, $method(static_cast<$Object*(Config::*)($StringArray*)>(&Config::get0))},
	{"getAll", "([Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $TRANSIENT},
	{"getBase", "(I)I", nullptr, $PRIVATE, $method(static_cast<int32_t(Config::*)(int32_t)>(&Config::getBase))},
	{"getBooleanObject", "([Ljava/lang/String;)Ljava/lang/Boolean;", nullptr, $PUBLIC | $TRANSIENT},
	{"getDefaultRealm", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException"},
	{"getInstance", "()Lsun/security/krb5/Config;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<Config*(*)()>(&Config::getInstance)), "sun.security.krb5.KrbException"},
	{"getIntValue", "([Ljava/lang/String;)I", nullptr, $PUBLIC | $TRANSIENT},
	{"getJavaFileName", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Config::*)()>(&Config::getJavaFileName))},
	{"getKDCFromDNS", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Config::*)($String*)>(&Config::getKDCFromDNS)), "sun.security.krb5.KrbException"},
	{"getKDCList", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException"},
	{"getNativeFileName", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Config::*)()>(&Config::getNativeFileName))},
	{"getRealmFromDNS", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Config::*)()>(&Config::getRealmFromDNS)), "sun.security.krb5.KrbException"},
	{"getString0", "([Ljava/lang/String;)Ljava/util/Vector;", "([Ljava/lang/String;)Ljava/util/Vector<Ljava/lang/String;>;", $PRIVATE | $TRANSIENT, $method(static_cast<$Vector*(Config::*)($StringArray*)>(&Config::getString0))},
	{"getType", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($String*)>(&Config::getType))},
	{"getWindowsDirectory", "(Z)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $method(static_cast<$String*(*)(bool)>(&Config::getWindowsDirectory))},
	{"isMacosLionOrBetter", "()Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)()>(&Config::isMacosLionOrBetter))},
	{"lambda$loadConfigFile$0", "(Ljava/lang/String;)Ljava/nio/file/Path;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Path*(*)($String*)>(&Config::lambda$loadConfigFile$0))},
	{"listTable", "()V", nullptr, $PUBLIC},
	{"loadConfigFile", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $method(static_cast<$List*(Config::*)($String*)>(&Config::loadConfigFile)), "java.io.IOException,sun.security.krb5.KrbException"},
	{"parseIntValue", "(Ljava/lang/String;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(Config::*)($String*)>(&Config::parseIntValue)), "java.lang.NumberFormatException"},
	{"parseStanzaTable", "(Ljava/util/List;)Ljava/util/Hashtable;", "(Ljava/util/List<Ljava/lang/String;>;)Ljava/util/Hashtable<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE, $method(static_cast<$Hashtable*(Config::*)($List*)>(&Config::parseStanzaTable)), "sun.security.krb5.KrbException"},
	{"readConfigFileLines", "(Ljava/nio/file/Path;Ljava/util/List;Ljava/util/Set;)Ljava/lang/Void;", "(Ljava/nio/file/Path;Ljava/util/List<Ljava/lang/String;>;Ljava/util/Set<Ljava/nio/file/Path;>;)Ljava/lang/Void;", $PRIVATE | $STATIC, $method(static_cast<$Void*(*)($Path*,$List*,$Set*)>(&Config::readConfigFileLines)), "java.io.IOException"},
	{"refresh", "()V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)()>(&Config::refresh)), "sun.security.krb5.KrbException"},
	{"resetDefaultRealm", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"toStringInternal", "(Ljava/lang/String;Ljava/lang/Object;Ljava/lang/StringBuffer;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($String*,Object$*,$StringBuffer*)>(&Config::toStringInternal))},
	{"unquote", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($String*)>(&Config::unquote))},
	{"useAddresses", "()Z", nullptr, $PUBLIC},
	{"useDNS", "(Ljava/lang/String;Z)Z", nullptr, $PRIVATE, $method(static_cast<bool(Config::*)($String*,bool)>(&Config::useDNS))},
	{"useDNS_KDC", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(Config::*)()>(&Config::useDNS_KDC))},
	{"useDNS_Realm", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(Config::*)()>(&Config::useDNS_Realm))},
	{}
};

#define _METHOD_INDEX_getWindowsDirectory 22

$InnerClassInfo _Config_InnerClassesInfo_[] = {
	{"sun.security.krb5.Config$FileExistsAction", "sun.security.krb5.Config", "FileExistsAction", $STATIC},
	{"sun.security.krb5.Config$3", nullptr, nullptr, 0},
	{"sun.security.krb5.Config$2", nullptr, nullptr, 0},
	{"sun.security.krb5.Config$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Config_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.Config",
	"java.lang.Object",
	nullptr,
	_Config_FieldInfo_,
	_Config_MethodInfo_,
	nullptr,
	nullptr,
	_Config_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.Config$FileExistsAction,sun.security.krb5.Config$3,sun.security.krb5.Config$2,sun.security.krb5.Config$1"
};

$Object* allocate$Config($Class* clazz) {
	return $of($alloc(Config));
}


bool Config::DISABLE_REFERRALS = false;

int32_t Config::MAX_REFERRALS = 0;
Config* Config::singleton = nullptr;
bool Config::DEBUG = false;

$String* Config::getWindowsDirectory(bool isSystem) {
	$init(Config);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(Config, getWindowsDirectory, $String*, bool isSystem);
	$assign($ret, $invokeNativeStatic(Config, getWindowsDirectory, isSystem));
	$finishNativeStatic();
	return $ret;
}

Config* Config::getInstance() {
	$load(Config);
	$synchronized(class$) {
		$init(Config);
		if (Config::singleton == nullptr) {
			$assignStatic(Config::singleton, $new(Config));
		}
		return Config::singleton;
	}
}

void Config::refresh() {
	$init(Config);
	$synchronized(Config::class$) {
		$assignStatic(Config::singleton, $new(Config));
	}
	$KdcComm::initStatic();
	$EType::initStatic();
	$Checksum::initStatic();
	$KrbAsReqBuilder$ReferralsState::initStatic();
}

bool Config::isMacosLionOrBetter() {
	$init(Config);
	$var($String, osname, $GetPropertyAction::privilegedGetProperty("os.name"_s));
	if (!$nc(osname)->contains("OS X"_s)) {
		return false;
	}
	$var($String, osVersion, $GetPropertyAction::privilegedGetProperty("os.version"_s));
	$var($StringArray, fragments, $nc(osVersion)->split("\\."_s));
	if (fragments->length < 2) {
		return false;
	}
	try {
		int32_t majorVers = $Integer::parseInt(fragments->get(0));
		int32_t minorVers = $Integer::parseInt(fragments->get(1));
		if (majorVers > 10) {
			return true;
		}
		if (majorVers == 10 && minorVers >= 7) {
			return true;
		}
	} catch ($NumberFormatException&) {
		$catch();
	}
	return false;
}

void Config::init$() {
	$set(this, stanzaTable, $new($Hashtable));
	$var($String, tmp, $GetPropertyAction::privilegedGetProperty("java.security.krb5.kdc"_s));
	if (tmp != nullptr) {
		$set(this, defaultKDC, tmp->replace(u':', u' '));
	} else {
		$set(this, defaultKDC, nullptr);
	}
	$set(this, defaultRealm, $GetPropertyAction::privilegedGetProperty("java.security.krb5.realm"_s));
	if ((this->defaultKDC == nullptr && this->defaultRealm != nullptr) || (this->defaultRealm == nullptr && this->defaultKDC != nullptr)) {
		$throwNew($KrbException, "System property java.security.krb5.kdc and java.security.krb5.realm both must be set or neither must be set."_s);
	}
	try {
		$var($List, configFile, nullptr);
		$var($String, fileName, getJavaFileName());
		if (fileName != nullptr) {
			$assign(configFile, loadConfigFile(fileName));
			$set(this, stanzaTable, parseStanzaTable(configFile));
			if (Config::DEBUG) {
				$init($System);
				$nc($System::out)->println("Loaded from Java config"_s);
			}
		} else {
			bool found = false;
			if (isMacosLionOrBetter()) {
				try {
					$set(this, stanzaTable, $SCDynamicStoreConfig::getConfig());
					if (Config::DEBUG) {
						$init($System);
						$nc($System::out)->println("Loaded from SCDynamicStoreConfig"_s);
					}
					found = true;
				} catch ($IOException&) {
					$catch();
				}
			}
			if (!found) {
				$assign(fileName, getNativeFileName());
				$assign(configFile, loadConfigFile(fileName));
				$set(this, stanzaTable, parseStanzaTable(configFile));
				if (Config::DEBUG) {
					$init($System);
					$nc($System::out)->println("Loaded from native config"_s);
				}
			}
		}
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		if (Config::DEBUG) {
			$init($System);
			$nc($System::out)->println("Exception thrown in loading config:"_s);
			ioe->printStackTrace($System::out);
		}
		$throwNew($KrbException, "krb5.conf loading failed"_s);
	}
}

$String* Config::get($StringArray* keys) {
	$var($Vector, v, getString0(keys));
	if (v == nullptr) {
		return nullptr;
	}
	return $cast($String, $nc(v)->firstElement());
}

$Boolean* Config::getBooleanObject($StringArray* keys) {
	$var($String, s, get(keys));
	if (s == nullptr) {
		return nullptr;
	}
	{
		$init($Locale);
		$var($String, s11083$, $nc(s)->toLowerCase($Locale::US));
		int32_t tmp11083$ = -1;
		switch (s11083$->hashCode()) {
		case 0x0001D2E7:
			{
				if (s11083$->equals("yes"_s)) {
					tmp11083$ = 0;
				}
				break;
			}
		case 0x0036758E:
			{
				if (s11083$->equals("true"_s)) {
					tmp11083$ = 1;
				}
				break;
			}
		case 3521:
			{
				if (s11083$->equals("no"_s)) {
					tmp11083$ = 2;
				}
				break;
			}
		case 0x05CB1923:
			{
				if (s11083$->equals("false"_s)) {
					tmp11083$ = 3;
				}
				break;
			}
		}
		switch (tmp11083$) {
		case 0:
			{}
		case 1:
			{
				$init($Boolean);
				return $Boolean::TRUE;
			}
		case 2:
			{}
		case 3:
			{
				$init($Boolean);
				return $Boolean::FALSE;
			}
		default:
			{
				return nullptr;
			}
		}
	}
}

$String* Config::getAll($StringArray* keys) {
	$var($Vector, v, getString0(keys));
	if (v == nullptr) {
		return nullptr;
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	bool first = true;
	{
		$var($Iterator, i$, $nc(v)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, s, $cast($String, i$->next()));
			{
				$assign(s, $nc(s)->replaceAll("[\\s,]+"_s, " "_s));
				if (first) {
					sb->append(s);
					first = false;
				} else {
					sb->append(u' ')->append(s);
				}
			}
		}
	}
	return sb->toString();
}

bool Config::exists($StringArray* keys) {
	return get0(keys) != nullptr;
}

$Vector* Config::getString0($StringArray* keys) {
	try {
		return $cast($Vector, get0(keys));
	} catch ($ClassCastException&) {
		$var($ClassCastException, cce, $catch());
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(cce));
	}
	$shouldNotReachHere();
}

$Object* Config::get0($StringArray* keys) {
	$var($Object, current, this->stanzaTable);
	try {
		{
			$var($StringArray, arr$, keys);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, key, arr$->get(i$));
				{
					$assign(current, $nc(($cast($Hashtable, current)))->get(key));
					if (current == nullptr) {
						return $of(nullptr);
					}
				}
			}
		}
		return $of(current);
	} catch ($ClassCastException&) {
		$var($ClassCastException, cce, $catch());
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(cce));
	}
	$shouldNotReachHere();
}

int32_t Config::duration($String* s) {
	$init(Config);
	if ($nc(s)->isEmpty()) {
		$throwNew($KrbException, "Duration cannot be empty"_s);
	}
	if ($nc(s)->matches("\\d+"_s)) {
		return $Integer::parseInt(s);
	}
	$var($Matcher, m, $nc($($Pattern::compile("(\\d+):(\\d+)(:(\\d+))?"_s)))->matcher(s));
	if ($nc(m)->matches()) {
		int32_t hr = $Integer::parseInt($(m->group(1)));
		int32_t min = $Integer::parseInt($(m->group(2)));
		if (min >= 60) {
			$throwNew($KrbException, $$str({"Illegal duration format "_s, s}));
		}
		int32_t result = hr * 3600 + min * 60;
		if (m->group(4) != nullptr) {
			int32_t sec = $Integer::parseInt($(m->group(4)));
			if (sec >= 60) {
				$throwNew($KrbException, $$str({"Illegal duration format "_s, s}));
			}
			result += sec;
		}
		return result;
	}
	$assign(m, $nc($($Pattern::compile("((\\d+)d)?\\s*((\\d+)h)?\\s*((\\d+)m)?\\s*((\\d+)s)?"_s, $Pattern::CASE_INSENSITIVE)))->matcher(s));
	if ($nc(m)->matches()) {
		int32_t result = 0;
		if (m->group(2) != nullptr) {
			result += 0x00015180 * $Integer::parseInt($(m->group(2)));
		}
		if (m->group(4) != nullptr) {
			result += 3600 * $Integer::parseInt($(m->group(4)));
		}
		if (m->group(6) != nullptr) {
			result += 60 * $Integer::parseInt($(m->group(6)));
		}
		if (m->group(8) != nullptr) {
			result += $Integer::parseInt($(m->group(8)));
		}
		return result;
	}
	$throwNew($KrbException, $$str({"Illegal duration format "_s, s}));
}

int32_t Config::getIntValue($StringArray* keys) {
	$var($String, result, get(keys));
	int32_t value = $Integer::MIN_VALUE;
	if (result != nullptr) {
		try {
			value = parseIntValue(result);
		} catch ($NumberFormatException&) {
			$var($NumberFormatException, e, $catch());
			if (Config::DEBUG) {
				$init($System);
				$var($String, var$0, $$str({"Exception in getting value of "_s, $($Arrays::toString(keys)), ": "_s}));
				$nc($System::out)->println($$concat(var$0, $(e->getMessage())));
				$nc($System::out)->println($$str({"Setting "_s, $($Arrays::toString(keys)), " to minimum value"_s}));
			}
			value = $Integer::MIN_VALUE;
		}
	}
	return value;
}

int32_t Config::parseIntValue($String* input) {
	int32_t value = 0;
	if ($nc(input)->startsWith("+"_s)) {
		$var($String, temp, input->substring(1));
		return $Integer::parseInt(temp);
	} else if (input->startsWith("0x"_s)) {
		$var($String, temp, input->substring(2));
		$var($chars, chars, temp->toCharArray());
		if (chars->length > 8) {
			$throwNew($NumberFormatException);
		} else {
			for (int32_t i = 0; i < chars->length; ++i) {
				int32_t index = chars->length - i - 1;
				switch (chars->get(i)) {
				case u'0':
					{
						value += 0;
						break;
					}
				case u'1':
					{
						value += 1 * getBase(index);
						break;
					}
				case u'2':
					{
						value += 2 * getBase(index);
						break;
					}
				case u'3':
					{
						value += 3 * getBase(index);
						break;
					}
				case u'4':
					{
						value += 4 * getBase(index);
						break;
					}
				case u'5':
					{
						value += 5 * getBase(index);
						break;
					}
				case u'6':
					{
						value += 6 * getBase(index);
						break;
					}
				case u'7':
					{
						value += 7 * getBase(index);
						break;
					}
				case u'8':
					{
						value += 8 * getBase(index);
						break;
					}
				case u'9':
					{
						value += 9 * getBase(index);
						break;
					}
				case u'a':
					{}
				case u'A':
					{
						value += 10 * getBase(index);
						break;
					}
				case u'b':
					{}
				case u'B':
					{
						value += 11 * getBase(index);
						break;
					}
				case u'c':
					{}
				case u'C':
					{
						value += 12 * getBase(index);
						break;
					}
				case u'd':
					{}
				case u'D':
					{
						value += 13 * getBase(index);
						break;
					}
				case u'e':
					{}
				case u'E':
					{
						value += 14 * getBase(index);
						break;
					}
				case u'f':
					{}
				case u'F':
					{
						value += 15 * getBase(index);
						break;
					}
				default:
					{
						$throwNew($NumberFormatException, "Invalid numerical format"_s);
					}
				}
			}
		}
		if (value < 0) {
			$throwNew($NumberFormatException, "Data overflow."_s);
		}
	} else {
		value = $Integer::parseInt(input);
	}
	return value;
}

int32_t Config::getBase(int32_t i) {
	int32_t result = 16;
	switch (i) {
	case 0:
		{
			result = Config::BASE16_0;
			break;
		}
	case 1:
		{
			result = Config::BASE16_1;
			break;
		}
	case 2:
		{
			result = Config::BASE16_2;
			break;
		}
	case 3:
		{
			result = Config::BASE16_3;
			break;
		}
	default:
		{
			for (int32_t j = 1; j < i; ++j) {
				result *= 16;
			}
		}
	}
	return result;
}

$Void* Config::readConfigFileLines($Path* file, $List* content, $Set* dups) {
	$init(Config);
	if (Config::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"Loading krb5 profile at "_s, file}));
	}
	if (!$nc(file)->isAbsolute()) {
		$throwNew($IOException, "Profile path not absolute"_s);
	}
	if (!$nc(dups)->add(file)) {
		$throwNew($IOException, "Profile path included more than once"_s);
	}
	$var($List, lines, $Files::readAllLines(file));
	bool inDirectives = true;
	{
		$var($Iterator, i$, $nc(lines)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, line, $cast($String, i$->next()));
			{
				$assign(line, $nc(line)->trim());
				bool var$1 = line->isEmpty();
				bool var$0 = var$1 || line->startsWith("#"_s);
				if (var$0 || line->startsWith(";"_s)) {
					continue;
				}
				if (inDirectives) {
					if (line->charAt(0) == u'[') {
						inDirectives = false;
						$nc(content)->add(line);
					} else if (line->startsWith("includedir "_s)) {
						$var($Path, dir, $Paths::get($($(line->substring("includedir "_s->length()))->trim()), $$new($StringArray, 0)));
						{
							$var($DirectoryStream, files, $Files::newDirectoryStream(dir));
							{
								$var($Throwable, var$2, nullptr);
								try {
									try {
										{
											$var($Iterator, i$, $nc(files)->iterator());
											for (; $nc(i$)->hasNext();) {
												$var($Path, p, $cast($Path, i$->next()));
												{
													if ($Files::isDirectory(p, $$new($LinkOptionArray, 0))) {
														continue;
													}
													$var($String, name, $nc($($nc(p)->getFileName()))->toString());
													bool var$3 = $nc(name)->matches("[a-zA-Z0-9_-]+"_s);
													if (!var$3) {
														bool var$4 = !$nc(name)->startsWith("."_s);
														var$3 = (var$4 && name->endsWith(".conf"_s));
													}
													if (var$3) {
														readConfigFileLines(p, content, dups);
													}
												}
											}
										}
									} catch ($Throwable&) {
										$var($Throwable, t$, $catch());
										if (files != nullptr) {
											try {
												files->close();
											} catch ($Throwable&) {
												$var($Throwable, x2, $catch());
												t$->addSuppressed(x2);
											}
										}
										$throw(t$);
									}
								} catch ($Throwable&) {
									$assign(var$2, $catch());
								} /*finally*/ {
									if (files != nullptr) {
										files->close();
									}
								}
								if (var$2 != nullptr) {
									$throw(var$2);
								}
							}
						}
					} else if (line->startsWith("include "_s)) {
						readConfigFileLines($($Paths::get($($(line->substring("include "_s->length()))->trim()), $$new($StringArray, 0))), content, dups);
					} else {
						if (Config::DEBUG) {
							$init($System);
							$nc($System::out)->println($$str({"Unknown directive: "_s, line}));
						}
					}
				} else {
					$nc(content)->add(line);
				}
			}
		}
	}
	return nullptr;
}

$List* Config::loadConfigFile($String* fileName) {
	$beforeCallerSensitive();
	$var($List, result, $new($ArrayList));
	$var($List, raw, $new($ArrayList));
	$var($Set, dupsCheck, $new($HashSet));
	try {
		$var($PrivilegedAction, var$0, static_cast<$PrivilegedAction*>($new(Config$$Lambda$lambda$loadConfigFile$0, fileName)));
		$var($Path, fullp, $cast($Path, $AccessController::doPrivileged(var$0, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($PropertyPermission, "user.dir"_s, "read"_s))}))));
		$var($PrivilegedExceptionAction, var$1, static_cast<$PrivilegedExceptionAction*>($new($Config$1, this, fileName, fullp, raw, dupsCheck)));
		$AccessController::doPrivileged(var$1, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($FilePermission, "<<ALL FILES>>"_s, "read"_s))}));
	} catch ($PrivilegedActionException&) {
		$var($PrivilegedActionException, pe, $catch());
		$throw($cast($IOException, $(pe->getException())));
	}
	$var($String, previous, nullptr);
	{
		$var($Iterator, i$, raw->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, line, $cast($String, i$->next()));
			{
				if ($nc(line)->startsWith("["_s)) {
					if (!line->endsWith("]"_s)) {
						$throwNew($KrbException, $$str({"Illegal config content:"_s, line}));
					}
					if (previous != nullptr) {
						result->add(previous);
						result->add("}"_s);
					}
					$var($String, title, $(line->substring(1, line->length() - 1))->trim());
					if (title->isEmpty()) {
						$throwNew($KrbException, $$str({"Illegal config content:"_s, line}));
					}
					$assign(previous, $str({title, " = {"_s}));
				} else if (line->startsWith("{"_s)) {
					if (previous == nullptr) {
						$throwNew($KrbException, "Config file should not start with \"{\""_s);
					}
					$plusAssign(previous, " {"_s);
					if (line->length() > 1) {
						result->add(previous);
						$assign(previous, $(line->substring(1))->trim());
					}
				} else {
					if (previous == nullptr) {
						$throwNew($KrbException, "Config file must starts with a section"_s);
					}
					result->add(previous);
					$assign(previous, line);
				}
			}
		}
	}
	if (previous != nullptr) {
		result->add(previous);
		result->add("}"_s);
	}
	return result;
}

$Hashtable* Config::parseStanzaTable($List* v) {
	$var($Hashtable, current, this->stanzaTable);
	{
		$var($Iterator, i$, $nc(v)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, line, $cast($String, i$->next()));
			{
				if ($nc(line)->equals("}"_s)) {
					$assign(current, $cast($Hashtable, $nc(current)->remove(" PARENT "_s)));
					if (current == nullptr) {
						$throwNew($KrbException, "Unmatched close brace"_s);
					}
				} else {
					int32_t pos = line->indexOf((int32_t)u'=');
					if (pos < 0) {
						$throwNew($KrbException, $$str({"Illegal config content:"_s, line}));
					}
					$var($String, key, $(line->substring(0, pos))->trim());
					$var($String, value, unquote($(line->substring(pos + 1))));
					if ($nc(value)->equals("{"_s)) {
						$var($Hashtable, subTable, nullptr);
						if (current == this->stanzaTable) {
							$init($Locale);
							$assign(key, key->toLowerCase($Locale::US));
						}
						if ($nc(current)->containsKey(key)) {
							if (current == this->stanzaTable) {
								$assign(subTable, $cast($Hashtable, current->get(key)));
							} else {
								$assign(subTable, $new($Hashtable));
							}
						} else {
							$assign(subTable, $new($Hashtable));
							current->put(key, subTable);
						}
						$nc(subTable)->put(" PARENT "_s, current);
						$assign(current, subTable);
					} else {
						$var($Vector, values, nullptr);
						if ($nc(current)->containsKey(key)) {
							$var($Object, obj, current->get(key));
							if ($instanceOf($Vector, obj)) {
								$assign(values, $cast($Vector, obj));
								$nc(values)->add(value);
							} else {
							}
						} else {
							$assign(values, $new($Vector));
							values->add(value);
							current->put(key, values);
						}
					}
				}
			}
		}
	}
	if (current != this->stanzaTable) {
		$throwNew($KrbException, "Not closed"_s);
	}
	return current;
}

$String* Config::getJavaFileName() {
	$var($String, name, $GetPropertyAction::privilegedGetProperty("java.security.krb5.conf"_s));
	if (name == nullptr) {
		$init($File);
		$assign(name, $str({$($GetPropertyAction::privilegedGetProperty("java.home"_s)), $File::separator, "conf"_s, $File::separator, "security"_s, $File::separator, "krb5.conf"_s}));
		if (!fileExists(name)) {
			$assign(name, nullptr);
		}
	}
	if (Config::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"Java config name: "_s, name}));
	}
	return name;
}

$String* Config::getNativeFileName() {
	$var($String, name, nullptr);
	$var($String, osname, $GetPropertyAction::privilegedGetProperty("os.name"_s));
	if ($nc(osname)->startsWith("Windows"_s)) {
		try {
			$Credentials::ensureLoaded();
		} catch ($Exception&) {
			$catch();
		}
		$init($Credentials);
		if ($Credentials::alreadyLoaded) {
			$var($String, path, getWindowsDirectory(false));
			if (path != nullptr) {
				if (path->endsWith("\\"_s)) {
					$assign(path, $str({path, "krb5.ini"_s}));
				} else {
					$assign(path, $str({path, "\\krb5.ini"_s}));
				}
				if (fileExists(path)) {
					$assign(name, path);
				}
			}
			if (name == nullptr) {
				$assign(path, getWindowsDirectory(true));
				if (path != nullptr) {
					if (path->endsWith("\\"_s)) {
						$assign(path, $str({path, "krb5.ini"_s}));
					} else {
						$assign(path, $str({path, "\\krb5.ini"_s}));
					}
					$assign(name, path);
				}
			}
		}
		if (name == nullptr) {
			$assign(name, "c:\\winnt\\krb5.ini"_s);
		}
	} else if (osname->contains("OS X"_s)) {
		$assign(name, findMacosConfigFile());
	} else {
		$assign(name, "/etc/krb5.conf"_s);
	}
	if (Config::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"Native config name: "_s, name}));
	}
	return name;
}

$String* Config::findMacosConfigFile() {
	$var($String, userHome, $GetPropertyAction::privilegedGetProperty("user.home"_s));
	$var($String, PREF_FILE, "/Library/Preferences/edu.mit.Kerberos"_s);
	$var($String, userPrefs, $str({userHome, PREF_FILE}));
	if (fileExists(userPrefs)) {
		return userPrefs;
	}
	if (fileExists(PREF_FILE)) {
		return PREF_FILE;
	}
	return "/etc/krb5.conf"_s;
}

$String* Config::unquote($String* s$renamed) {
	$init(Config);
	$var($String, s, s$renamed);
	$assign(s, $nc(s)->trim());
	bool var$0 = s->length() >= 2;
	if (var$0) {
		bool var$2 = s->charAt(0) == u'\"';
		bool var$1 = (var$2 && s->charAt(s->length() - 1) == u'\"');
		if (!var$1) {
			bool var$3 = s->charAt(0) == u'\'';
			var$1 = (var$3 && s->charAt(s->length() - 1) == u'\'');
		}
		var$0 = (var$1);
	}
	if (var$0) {
		$assign(s, $(s->substring(1, s->length() - 1))->trim());
	}
	return s;
}

void Config::listTable() {
	$init($System);
	$nc($System::out)->println($of(this));
}

$ints* Config::defaultEtype($String* configName) {
	$var($String, default_enctypes, nullptr);
	$assign(default_enctypes, get($$new($StringArray, {
		"libdefaults"_s,
		configName
	})));
	if (default_enctypes == nullptr && !$nc(configName)->equals("permitted_enctypes"_s)) {
		$assign(default_enctypes, get($$new($StringArray, {
			"libdefaults"_s,
			"permitted_enctypes"_s
		})));
	}
	$var($ints, etype, nullptr);
	if (default_enctypes == nullptr) {
		if (Config::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({"Using builtin default etypes for "_s, configName}));
		}
		$assign(etype, $EType::getBuiltInDefaults());
	} else {
		$var($String, delim, " "_s);
		$var($StringTokenizer, st, nullptr);
		for (int32_t j = 0; j < $nc(default_enctypes)->length(); ++j) {
			if ($(default_enctypes->substring(j, j + 1))->equals(","_s)) {
				$assign(delim, ","_s);
				break;
			}
		}
		$assign(st, $new($StringTokenizer, default_enctypes, delim));
		int32_t len = st->countTokens();
		$var($ArrayList, ls, $new($ArrayList, len));
		int32_t type = 0;
		for (int32_t i = 0; i < len; ++i) {
			type = Config::getType($(st->nextToken()));
			if (type != -1 && $EType::isSupported(type)) {
				ls->add($($Integer::valueOf(type)));
			}
		}
		if (ls->isEmpty()) {
			$throwNew($KrbException, $$str({"no supported default etypes for "_s, configName}));
		} else {
			$assign(etype, $new($ints, ls->size()));
			for (int32_t i = 0; i < etype->length; ++i) {
				etype->set(i, $nc(($cast($Integer, $(ls->get(i)))))->intValue());
			}
		}
	}
	if (Config::DEBUG) {
		$init($System);
		$nc($System::out)->print($$str({"default etypes for "_s, configName, ":"_s}));
		for (int32_t i = 0; i < $nc(etype)->length; ++i) {
			$nc($System::out)->print($$str({" "_s, $$str(etype->get(i))}));
		}
		$nc($System::out)->println("."_s);
	}
	return etype;
}

int32_t Config::getType($String* input) {
	$init(Config);
	int32_t result = -1;
	if (input == nullptr) {
		return result;
	}
	bool var$0 = $nc(input)->startsWith("d"_s);
	if (var$0 || ($nc(input)->startsWith("D"_s))) {
		if (input->equalsIgnoreCase("des-cbc-crc"_s)) {
			result = $EncryptedData::ETYPE_DES_CBC_CRC;
		} else if (input->equalsIgnoreCase("des-cbc-md5"_s)) {
			result = $EncryptedData::ETYPE_DES_CBC_MD5;
		} else if (input->equalsIgnoreCase("des-mac"_s)) {
			result = $Checksum::CKSUMTYPE_DES_MAC;
		} else if (input->equalsIgnoreCase("des-mac-k"_s)) {
			result = $Checksum::CKSUMTYPE_DES_MAC_K;
		} else if (input->equalsIgnoreCase("des-cbc-md4"_s)) {
			result = $EncryptedData::ETYPE_DES_CBC_MD4;
		} else {
			bool var$6 = input->equalsIgnoreCase("des3-cbc-sha1"_s);
			bool var$5 = var$6 || input->equalsIgnoreCase("des3-hmac-sha1"_s);
			bool var$4 = var$5 || input->equalsIgnoreCase("des3-cbc-sha1-kd"_s);
			if (var$4 || input->equalsIgnoreCase("des3-cbc-hmac-sha1-kd"_s)) {
				result = $EncryptedData::ETYPE_DES3_CBC_HMAC_SHA1_KD;
			}
		}
	} else {
		bool var$8 = input->startsWith("a"_s);
		if (var$8 || (input->startsWith("A"_s))) {
			bool var$10 = input->equalsIgnoreCase("aes128-cts"_s);
			bool var$9 = var$10 || input->equalsIgnoreCase("aes128-sha1"_s);
			if (var$9 || input->equalsIgnoreCase("aes128-cts-hmac-sha1-96"_s)) {
				result = $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA1_96;
			} else {
				bool var$14 = input->equalsIgnoreCase("aes256-cts"_s);
				bool var$13 = var$14 || input->equalsIgnoreCase("aes256-sha1"_s);
				if (var$13 || input->equalsIgnoreCase("aes256-cts-hmac-sha1-96"_s)) {
					result = $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA1_96;
				} else {
					bool var$16 = input->equalsIgnoreCase("aes128-sha2"_s);
					if (var$16 || input->equalsIgnoreCase("aes128-cts-hmac-sha256-128"_s)) {
						result = $EncryptedData::ETYPE_AES128_CTS_HMAC_SHA256_128;
					} else {
						bool var$18 = input->equalsIgnoreCase("aes256-sha2"_s);
						if (var$18 || input->equalsIgnoreCase("aes256-cts-hmac-sha384-192"_s)) {
							result = $EncryptedData::ETYPE_AES256_CTS_HMAC_SHA384_192;
						} else {
							bool var$20 = input->equalsIgnoreCase("arcfour-hmac"_s);
							if (var$20 || input->equalsIgnoreCase("arcfour-hmac-md5"_s)) {
								result = $EncryptedData::ETYPE_ARCFOUR_HMAC;
							}
						}
					}
				}
			}
		} else if (input->equalsIgnoreCase("rc4-hmac"_s)) {
			result = $EncryptedData::ETYPE_ARCFOUR_HMAC;
		} else if (input->equalsIgnoreCase("CRC32"_s)) {
			result = $Checksum::CKSUMTYPE_CRC32;
		} else {
			bool var$22 = input->startsWith("r"_s);
			if (var$22 || (input->startsWith("R"_s))) {
				if (input->equalsIgnoreCase("rsa-md5"_s)) {
					result = $Checksum::CKSUMTYPE_RSA_MD5;
				} else if (input->equalsIgnoreCase("rsa-md5-des"_s)) {
					result = $Checksum::CKSUMTYPE_RSA_MD5_DES;
				}
			} else if (input->equalsIgnoreCase("hmac-sha1-des3-kd"_s)) {
				result = $Checksum::CKSUMTYPE_HMAC_SHA1_DES3_KD;
			} else if (input->equalsIgnoreCase("hmac-sha1-96-aes128"_s)) {
				result = $Checksum::CKSUMTYPE_HMAC_SHA1_96_AES128;
			} else if (input->equalsIgnoreCase("hmac-sha1-96-aes256"_s)) {
				result = $Checksum::CKSUMTYPE_HMAC_SHA1_96_AES256;
			} else if (input->equalsIgnoreCase("hmac-sha256-128-aes128"_s)) {
				result = $Checksum::CKSUMTYPE_HMAC_SHA256_128_AES128;
			} else if (input->equalsIgnoreCase("hmac-sha384-192-aes256"_s)) {
				result = $Checksum::CKSUMTYPE_HMAC_SHA384_192_AES256;
			} else {
				bool var$26 = input->equalsIgnoreCase("hmac-md5-rc4"_s);
				bool var$25 = var$26 || input->equalsIgnoreCase("hmac-md5-arcfour"_s);
				if (var$25 || input->equalsIgnoreCase("hmac-md5-enc"_s)) {
					result = $Checksum::CKSUMTYPE_HMAC_MD5_ARCFOUR;
				} else if (input->equalsIgnoreCase("NULL"_s)) {
					result = $EncryptedData::ETYPE_NULL;
				}
			}
		}
	}
	return result;
}

void Config::resetDefaultRealm($String* realm) {
	if (Config::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>> Config try resetting default kdc "_s, realm}));
	}
}

bool Config::useAddresses() {
	$init($Boolean);
	bool var$0 = getBooleanObject($$new($StringArray, {
		"libdefaults"_s,
		"no_addresses"_s
	})) == $Boolean::FALSE;
	return var$0 || getBooleanObject($$new($StringArray, {
		"libdefaults"_s,
		"noaddresses"_s
	})) == $Boolean::FALSE;
}

bool Config::useDNS($String* name, bool defaultValue) {
	$var($Boolean, value, getBooleanObject($$new($StringArray, {
		"libdefaults"_s,
		name
	})));
	if (value != nullptr) {
		return value->booleanValue();
	}
	$assign(value, getBooleanObject($$new($StringArray, {
		"libdefaults"_s,
		"dns_fallback"_s
	})));
	if (value != nullptr) {
		return value->booleanValue();
	}
	return defaultValue;
}

bool Config::useDNS_KDC() {
	return useDNS("dns_lookup_kdc"_s, true);
}

bool Config::useDNS_Realm() {
	return useDNS("dns_lookup_realm"_s, false);
}

$String* Config::getDefaultRealm() {
	$beforeCallerSensitive();
	if (this->defaultRealm != nullptr) {
		return this->defaultRealm;
	}
	$var($Exception, cause, nullptr);
	$var($String, realm, get($$new($StringArray, {
		"libdefaults"_s,
		"default_realm"_s
	})));
	if ((realm == nullptr) && useDNS_Realm()) {
		try {
			$assign(realm, getRealmFromDNS());
		} catch ($KrbException&) {
			$var($KrbException, ke, $catch());
			$assign(cause, ke);
		}
	}
	if (realm == nullptr) {
		$assign(realm, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Config$2, this)))));
	}
	if (realm == nullptr) {
		$var($KrbException, ke, $new($KrbException, "Cannot locate default realm"_s));
		if (cause != nullptr) {
			ke->initCause(cause);
		}
		$throw(ke);
	}
	return realm;
}

$String* Config::getKDCList($String* realm$renamed) {
	$var($String, realm, realm$renamed);
	$beforeCallerSensitive();
	if (realm == nullptr) {
		$assign(realm, getDefaultRealm());
	}
	if ($nc(realm)->equalsIgnoreCase(this->defaultRealm)) {
		return this->defaultKDC;
	}
	$var($Exception, cause, nullptr);
	$var($String, kdcs, getAll($$new($StringArray, {
		"realms"_s,
		realm,
		"kdc"_s
	})));
	if ((kdcs == nullptr) && useDNS_KDC()) {
		try {
			$assign(kdcs, getKDCFromDNS(realm));
		} catch ($KrbException&) {
			$var($KrbException, ke, $catch());
			$assign(cause, ke);
		}
	}
	if (kdcs == nullptr) {
		$assign(kdcs, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Config$3, this)))));
	}
	if (kdcs == nullptr) {
		if (this->defaultKDC != nullptr) {
			return this->defaultKDC;
		}
		$var($KrbException, ke, $new($KrbException, "Cannot locate KDC"_s));
		if (cause != nullptr) {
			ke->initCause(cause);
		}
		$throw(ke);
	}
	return kdcs;
}

$String* Config::getRealmFromDNS() {
	$var($String, realm, nullptr);
	$var($String, hostName, nullptr);
	try {
		$assign(hostName, $nc($($InetAddress::getLocalHost()))->getCanonicalHostName());
	} catch ($UnknownHostException&) {
		$var($UnknownHostException, e, $catch());
		$var($KrbException, ke, $new($KrbException, $Krb5::KRB_ERR_GENERIC, $$str({"Unable to locate Kerberos realm: "_s, $(e->getMessage())})));
		ke->initCause(e);
		$throw(ke);
	}
	$var($String, mapRealm, $PrincipalName::mapHostToRealm(hostName));
	if (mapRealm == nullptr) {
		$var($List, srchlist, $nc($($ResolverConfiguration::open()))->searchlist());
		{
			$var($Iterator, i$, $nc(srchlist)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, domain, $cast($String, i$->next()));
				{
					$assign(realm, checkRealm(domain));
					if (realm != nullptr) {
						break;
					}
				}
			}
		}
	} else {
		$assign(realm, checkRealm(mapRealm));
	}
	if (realm == nullptr) {
		$throwNew($KrbException, $Krb5::KRB_ERR_GENERIC, "Unable to locate Kerberos realm"_s);
	}
	return realm;
}

$String* Config::checkRealm($String* mapRealm) {
	$init(Config);
	if (Config::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"getRealmFromDNS: trying "_s, mapRealm}));
	}
	$var($StringArray, records, nullptr);
	$var($String, newRealm, mapRealm);
	while ((records == nullptr) && (newRealm != nullptr)) {
		$assign(records, $KrbServiceLocator::getKerberosService(newRealm));
		$assign(newRealm, $Realm::parseRealmComponent(newRealm));
	}
	if (records != nullptr) {
		for (int32_t i = 0; i < records->length; ++i) {
			if ($nc(records->get(i))->equalsIgnoreCase(mapRealm)) {
				return records->get(i);
			}
		}
	}
	return nullptr;
}

$String* Config::getKDCFromDNS($String* realm) {
	$var($String, kdcs, ""_s);
	$var($StringArray, srvs, nullptr);
	if (Config::DEBUG) {
		$init($System);
		$nc($System::out)->println("getKDCFromDNS using UDP"_s);
	}
	$assign(srvs, $KrbServiceLocator::getKerberosService(realm, "_udp"_s));
	if (srvs == nullptr) {
		if (Config::DEBUG) {
			$init($System);
			$nc($System::out)->println("getKDCFromDNS using TCP"_s);
		}
		$assign(srvs, $KrbServiceLocator::getKerberosService(realm, "_tcp"_s));
	}
	if (srvs == nullptr) {
		$throwNew($KrbException, $Krb5::KRB_ERR_GENERIC, $$str({"Unable to locate KDC for realm "_s, realm}));
	}
	if ($nc(srvs)->length == 0) {
		return nullptr;
	}
	for (int32_t i = 0; i < $nc(srvs)->length; ++i) {
		$plusAssign(kdcs, $$str({$($nc(srvs->get(i))->trim()), " "_s}));
	}
	$assign(kdcs, kdcs->trim());
	if (kdcs->equals(""_s)) {
		return nullptr;
	}
	return kdcs;
}

bool Config::fileExists($String* name) {
	$beforeCallerSensitive();
	return $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Config$FileExistsAction, name)))))))->booleanValue();
}

$String* Config::toString() {
	$var($StringBuffer, sb, $new($StringBuffer));
	toStringInternal(""_s, this->stanzaTable, sb);
	return sb->toString();
}

void Config::toStringInternal($String* prefix, Object$* obj, $StringBuffer* sb) {
	$init(Config);
	if ($instanceOf($String, obj)) {
		$nc(sb)->append(obj)->append(u'\n');
	} else if ($instanceOf($Hashtable, obj)) {
		$var($Hashtable, tab, $cast($Hashtable, obj));
		$nc(sb)->append("{\n"_s);
		{
			$var($Iterator, i$, $nc($($nc(tab)->keySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Object, o, i$->next());
				{
					sb->append(prefix)->append("    "_s)->append(o)->append(" = "_s);
					toStringInternal($$str({prefix, "    "_s}), $(tab->get(o)), sb);
				}
			}
		}
		sb->append(prefix)->append("}\n"_s);
	} else if ($instanceOf($Vector, obj)) {
		$var($Vector, v, $cast($Vector, obj));
		$nc(sb)->append("["_s);
		bool first = true;
		{
			$var($ObjectArray, arr$, $nc(v)->toArray());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, o, arr$->get(i$));
				{
					if (!first) {
						sb->append(","_s);
					}
					sb->append(o);
					first = false;
				}
			}
		}
		sb->append("]\n"_s);
	}
}

$Path* Config::lambda$loadConfigFile$0($String* fileName) {
	$init(Config);
	return $nc($($Paths::get(fileName, $$new($StringArray, 0))))->toAbsolutePath();
}

void clinit$Config($Class* class$) {
	{
		$var($String, disableReferralsProp, $SecurityProperties::privilegedGetOverridable("sun.security.krb5.disableReferrals"_s));
		if (disableReferralsProp != nullptr) {
			Config::DISABLE_REFERRALS = "true"_s->equalsIgnoreCase(disableReferralsProp);
		} else {
			Config::DISABLE_REFERRALS = false;
		}
		int32_t maxReferralsValue = 5;
		$var($String, maxReferralsProp, $SecurityProperties::privilegedGetOverridable("sun.security.krb5.maxReferrals"_s));
		try {
			maxReferralsValue = $Integer::parseInt(maxReferralsProp);
		} catch ($NumberFormatException&) {
			$catch();
		}
		Config::MAX_REFERRALS = maxReferralsValue;
	}
	$assignStatic(Config::singleton, nullptr);
	$init($Krb5);
	Config::DEBUG = $Krb5::DEBUG;
}

Config::Config() {
}

$Class* Config::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Config$$Lambda$lambda$loadConfigFile$0::classInfo$.name)) {
			return Config$$Lambda$lambda$loadConfigFile$0::load$(name, initialize);
		}
	}
	$loadClass(Config, name, initialize, &_Config_ClassInfo_, clinit$Config, allocate$Config);
	return class$;
}

$Class* Config::class$ = nullptr;

		} // krb5
	} // security
} // sun