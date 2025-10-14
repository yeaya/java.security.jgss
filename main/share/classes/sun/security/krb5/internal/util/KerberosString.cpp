#include <sun/security/krb5/internal/util/KerberosString.h>

#include <java/io/IOException.h>
#include <java/lang/Array.h>
#include <java/lang/Boolean.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef MSNAME
#undef US_ASCII
#undef UTF_8

using $IOException = ::java::io::IOException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace util {

$FieldInfo _KerberosString_FieldInfo_[] = {
	{"MSNAME", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(KerberosString, MSNAME)},
	{"s", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(KerberosString, s)},
	{}
};

$MethodInfo _KerberosString_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosString::*)($String*)>(&KerberosString::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosString::*)($DerValue*)>(&KerberosString::init$)), "java.io.IOException"},
	{"toDerValue", "()Lsun/security/util/DerValue;", nullptr, $PUBLIC, $method(static_cast<$DerValue*(KerberosString::*)()>(&KerberosString::toDerValue))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KerberosString_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.internal.util.KerberosString",
	"java.lang.Object",
	nullptr,
	_KerberosString_FieldInfo_,
	_KerberosString_MethodInfo_
};

$Object* allocate$KerberosString($Class* clazz) {
	return $of($alloc(KerberosString));
}


bool KerberosString::MSNAME = false;

void KerberosString::init$($String* s) {
	$set(this, s, s);
}

void KerberosString::init$($DerValue* der) {
	if ($nc(der)->tag != $DerValue::tag_GeneralString) {
		$throwNew($IOException, $$str({"KerberosString\'s tag is incorrect: "_s, $$str(der->tag)}));
	}
	$init($StandardCharsets);
	$set(this, s, $new($String, $($nc(der)->getDataBytes()), KerberosString::MSNAME ? $StandardCharsets::UTF_8 : $StandardCharsets::US_ASCII));
}

$String* KerberosString::toString() {
	return this->s;
}

$DerValue* KerberosString::toDerValue() {
	$init($StandardCharsets);
	return $new($DerValue, $DerValue::tag_GeneralString, $($nc(this->s)->getBytes(KerberosString::MSNAME ? $StandardCharsets::UTF_8 : $StandardCharsets::US_ASCII)));
}

void clinit$KerberosString($Class* class$) {
	{
		$var($String, prop, $GetPropertyAction::privilegedGetProperty("sun.security.krb5.msinterop.kstring"_s, "true"_s));
		KerberosString::MSNAME = $Boolean::parseBoolean(prop);
	}
}

KerberosString::KerberosString() {
}

$Class* KerberosString::load$($String* name, bool initialize) {
	$loadClass(KerberosString, name, initialize, &_KerberosString_ClassInfo_, clinit$KerberosString, allocate$KerberosString);
	return class$;
}

$Class* KerberosString::class$ = nullptr;

				} // util
			} // internal
		} // krb5
	} // security
} // sun