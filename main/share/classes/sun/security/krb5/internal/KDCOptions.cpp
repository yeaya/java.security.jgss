#include <sun/security/krb5/internal/KDCOptions.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Boolean.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/util/KerberosFlags.h>
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ALLOW_POSTDATE
#undef ASN1_BAD_ID
#undef BITSTRING_BAD_LENGTH
#undef BITS_PER_UNIT
#undef CANONICALIZE
#undef CNAME_IN_ADDL_TKT
#undef DEBUG
#undef ENC_TKT_IN_SKEY
#undef FORWARDABLE
#undef FORWARDED
#undef KDC_OPTS_MAX
#undef KDC_OPT_FORWARDABLE
#undef KDC_OPT_PROXIABLE
#undef KDC_OPT_RENEWABLE_OK
#undef POSTDATED
#undef PROXIABLE
#undef PROXY
#undef RENEW
#undef RENEWABLE
#undef RENEWABLE_OK
#undef RESERVED
#undef TRUE
#undef UNUSED10
#undef UNUSED11
#undef UNUSED7
#undef UNUSED9
#undef VALIDATE

using $PrintStream = ::java::io::PrintStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Config = ::sun::security::krb5::Config;
using $KrbException = ::sun::security::krb5::KrbException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $BitArray = ::sun::security::util::BitArray;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KDCOptions_FieldInfo_[] = {
	{"KDC_OPT_PROXIABLE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KDCOptions, KDC_OPT_PROXIABLE)},
	{"KDC_OPT_RENEWABLE_OK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KDCOptions, KDC_OPT_RENEWABLE_OK)},
	{"KDC_OPT_FORWARDABLE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KDCOptions, KDC_OPT_FORWARDABLE)},
	{"RESERVED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, RESERVED)},
	{"FORWARDABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, FORWARDABLE)},
	{"FORWARDED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, FORWARDED)},
	{"PROXIABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, PROXIABLE)},
	{"PROXY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, PROXY)},
	{"ALLOW_POSTDATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, ALLOW_POSTDATE)},
	{"POSTDATED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, POSTDATED)},
	{"UNUSED7", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, UNUSED7)},
	{"RENEWABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, RENEWABLE)},
	{"UNUSED9", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, UNUSED9)},
	{"UNUSED10", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, UNUSED10)},
	{"UNUSED11", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, UNUSED11)},
	{"CNAME_IN_ADDL_TKT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, CNAME_IN_ADDL_TKT)},
	{"CANONICALIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, CANONICALIZE)},
	{"RENEWABLE_OK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, RENEWABLE_OK)},
	{"ENC_TKT_IN_SKEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, ENC_TKT_IN_SKEY)},
	{"RENEW", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, RENEW)},
	{"VALIDATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KDCOptions, VALIDATE)},
	{"names", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KDCOptions, names)},
	{"DEBUG", "Z", nullptr, $PRIVATE, $field(KDCOptions, DEBUG)},
	{}
};

$MethodInfo _KDCOptions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(KDCOptions::*)()>(&KDCOptions::init$))},
	{"<init>", "(I[B)V", nullptr, $PUBLIC, $method(static_cast<void(KDCOptions::*)(int32_t,$bytes*)>(&KDCOptions::init$)), "sun.security.krb5.Asn1Exception"},
	{"<init>", "([Z)V", nullptr, $PUBLIC, $method(static_cast<void(KDCOptions::*)($booleans*)>(&KDCOptions::init$)), "sun.security.krb5.Asn1Exception"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(KDCOptions::*)($DerValue*)>(&KDCOptions::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(KDCOptions::*)($bytes*)>(&KDCOptions::init$))},
	{"get", "(I)Z", nullptr, $PUBLIC, nullptr, "java.lang.ArrayIndexOutOfBoundsException"},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/internal/KDCOptions;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KDCOptions*(*)($DerInputStream*,int8_t,bool)>(&KDCOptions::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"set", "(IZ)V", nullptr, $PUBLIC, nullptr, "java.lang.ArrayIndexOutOfBoundsException"},
	{"setDefault", "()V", nullptr, $PRIVATE, $method(static_cast<void(KDCOptions::*)()>(&KDCOptions::setDefault))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"with", "([I)Lsun/security/krb5/internal/KDCOptions;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<KDCOptions*(*)($ints*)>(&KDCOptions::with))},
	{}
};

$ClassInfo _KDCOptions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KDCOptions",
	"sun.security.krb5.internal.util.KerberosFlags",
	nullptr,
	_KDCOptions_FieldInfo_,
	_KDCOptions_MethodInfo_
};

$Object* allocate$KDCOptions($Class* clazz) {
	return $of($alloc(KDCOptions));
}

$StringArray* KDCOptions::names = nullptr;

KDCOptions* KDCOptions::with($ints* flags) {
	$init(KDCOptions);
	$var(KDCOptions, options, $new(KDCOptions));
	{
		$var($ints, arr$, flags);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int32_t flag = arr$->get(i$);
			{
				options->set(flag, true);
			}
		}
	}
	return options;
}

void KDCOptions::init$() {
	$KerberosFlags::init$($Krb5::KDC_OPTS_MAX + 1);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	setDefault();
}

void KDCOptions::init$(int32_t size, $bytes* data) {
	$KerberosFlags::init$(size, data);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	if ((size > $nc(data)->length * $KerberosFlags::BITS_PER_UNIT) || (size > $Krb5::KDC_OPTS_MAX + 1)) {
		$throwNew($Asn1Exception, $Krb5::BITSTRING_BAD_LENGTH);
	}
}

void KDCOptions::init$($booleans* data) {
	$KerberosFlags::init$(data);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
	if ($nc(data)->length > $Krb5::KDC_OPTS_MAX + 1) {
		$throwNew($Asn1Exception, $Krb5::BITSTRING_BAD_LENGTH);
	}
}

void KDCOptions::init$($DerValue* encoding) {
	KDCOptions::init$($($nc($($nc(encoding)->getUnalignedBitString(true)))->toBooleanArray()));
}

void KDCOptions::init$($bytes* options) {
	$KerberosFlags::init$($nc(options)->length * $KerberosFlags::BITS_PER_UNIT, options);
	$init($Krb5);
	this->DEBUG = $Krb5::DEBUG;
}

KDCOptions* KDCOptions::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(KDCOptions);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(KDCOptions, subDer);
	}
}

void KDCOptions::set(int32_t option, bool value) {
	$KerberosFlags::set(option, value);
}

bool KDCOptions::get(int32_t option) {
	return $KerberosFlags::get(option);
}

$String* KDCOptions::toString() {
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("KDCOptions: "_s);
	for (int32_t i = 0; i < $Krb5::KDC_OPTS_MAX + 1; ++i) {
		if (get(i)) {
			if ($nc(KDCOptions::names)->get(i) != nullptr) {
				sb->append($nc(KDCOptions::names)->get(i))->append(","_s);
			} else {
				sb->append(i)->append(","_s);
			}
		}
	}
	return sb->toString();
}

void KDCOptions::setDefault() {
	try {
		$var($Config, config, $Config::getInstance());
		int32_t options = $nc(config)->getIntValue($$new($StringArray, {
			"libdefaults"_s,
			"kdc_default_options"_s
		}));
		if (((int32_t)(options & (uint32_t)KDCOptions::KDC_OPT_RENEWABLE_OK)) == KDCOptions::KDC_OPT_RENEWABLE_OK) {
			set(KDCOptions::RENEWABLE_OK, true);
		} else {
			$init($Boolean);
			if (config->getBooleanObject($$new($StringArray, {
				"libdefaults"_s,
				"renewable"_s
			})) == $Boolean::TRUE) {
				set(KDCOptions::RENEWABLE_OK, true);
			}
		}
		if (((int32_t)(options & (uint32_t)KDCOptions::KDC_OPT_PROXIABLE)) == KDCOptions::KDC_OPT_PROXIABLE) {
			set(KDCOptions::PROXIABLE, true);
		} else {
			$init($Boolean);
			if (config->getBooleanObject($$new($StringArray, {
				"libdefaults"_s,
				"proxiable"_s
			})) == $Boolean::TRUE) {
				set(KDCOptions::PROXIABLE, true);
			}
		}
		if (((int32_t)(options & (uint32_t)KDCOptions::KDC_OPT_FORWARDABLE)) == KDCOptions::KDC_OPT_FORWARDABLE) {
			set(KDCOptions::FORWARDABLE, true);
		} else {
			$init($Boolean);
			if (config->getBooleanObject($$new($StringArray, {
				"libdefaults"_s,
				"forwardable"_s
			})) == $Boolean::TRUE) {
				set(KDCOptions::FORWARDABLE, true);
			}
		}
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		if (this->DEBUG) {
			$init($System);
			$nc($System::out)->println("Exception in getting default values for KDC Options from the configuration "_s);
			e->printStackTrace();
		}
	}
}

void clinit$KDCOptions($Class* class$) {
	$assignStatic(KDCOptions::names, $new($StringArray, {
		"RESERVED"_s,
		"FORWARDABLE"_s,
		"FORWARDED"_s,
		"PROXIABLE"_s,
		"PROXY"_s,
		"ALLOW_POSTDATE"_s,
		"POSTDATED"_s,
		"UNUSED7"_s,
		"RENEWABLE"_s,
		"UNUSED9"_s,
		"UNUSED10"_s,
		"UNUSED11"_s,
		($String*)nullptr,
		($String*)nullptr,
		"CNAME_IN_ADDL_TKT"_s,
		"CANONICALIZE"_s,
		($String*)nullptr,
		($String*)nullptr,
		($String*)nullptr,
		($String*)nullptr,
		($String*)nullptr,
		($String*)nullptr,
		($String*)nullptr,
		($String*)nullptr,
		($String*)nullptr,
		($String*)nullptr,
		($String*)nullptr,
		"RENEWABLE_OK"_s,
		"ENC_TKT_IN_SKEY"_s,
		($String*)nullptr,
		"RENEW"_s,
		"VALIDATE"_s
	}));
}

KDCOptions::KDCOptions() {
}

$Class* KDCOptions::load$($String* name, bool initialize) {
	$loadClass(KDCOptions, name, initialize, &_KDCOptions_ClassInfo_, clinit$KDCOptions, allocate$KDCOptions);
	return class$;
}

$Class* KDCOptions::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun