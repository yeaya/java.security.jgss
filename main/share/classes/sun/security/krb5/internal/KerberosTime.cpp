#include <sun/security/krb5/internal/KerberosTime.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/Math.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/time/Instant.h>
#include <java/util/Calendar.h>
#include <java/util/Date.h>
#include <java/util/TimeZone.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef ASN1_BAD_TIMEFORMAT
#undef DAY_OF_MONTH
#undef DEBUG
#undef DEFAULT_ALLOWABLE_CLOCKSKEW
#undef HOUR_OF_DAY
#undef MINUTE
#undef MIN_VALUE
#undef MONTH
#undef SECOND
#undef YEAR

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Instant = ::java::time::Instant;
using $Calendar = ::java::util::Calendar;
using $Date = ::java::util::Date;
using $TimeZone = ::java::util::TimeZone;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Config = ::sun::security::krb5::Config;
using $KrbException = ::sun::security::krb5::KrbException;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KerberosTime_FieldInfo_[] = {
	{"kerberosTime", "J", nullptr, $PRIVATE | $FINAL, $field(KerberosTime, kerberosTime)},
	{"microSeconds", "I", nullptr, $PRIVATE | $FINAL, $field(KerberosTime, microSeconds)},
	{"initMilli", "J", nullptr, $PRIVATE | $STATIC, $staticField(KerberosTime, initMilli)},
	{"initMicro", "J", nullptr, $PRIVATE | $STATIC, $staticField(KerberosTime, initMicro)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(KerberosTime, DEBUG)},
	{}
};

$MethodInfo _KerberosTime_MethodInfo_[] = {
	{"<init>", "(JI)V", nullptr, $PRIVATE, $method(static_cast<void(KerberosTime::*)(int64_t,int32_t)>(&KerberosTime::init$))},
	{"<init>", "(J)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosTime::*)(int64_t)>(&KerberosTime::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosTime::*)($String*)>(&KerberosTime::init$)), "sun.security.krb5.Asn1Exception"},
	{"<init>", "(Ljava/util/Date;)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosTime::*)($Date*)>(&KerberosTime::init$))},
	{"<init>", "(Ljava/time/Instant;)V", nullptr, $PUBLIC, $method(static_cast<void(KerberosTime::*)($Instant*)>(&KerberosTime::init$))},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getDefaultSkew", "()I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)()>(&KerberosTime::getDefaultSkew))},
	{"getMicroSeconds", "()I", nullptr, $PUBLIC},
	{"getSeconds", "()I", nullptr, $PUBLIC},
	{"getTime", "()J", nullptr, $PUBLIC},
	{"greaterThan", "(Lsun/security/krb5/internal/KerberosTime;)Z", nullptr, $PUBLIC},
	{"greaterThanWRTClockSkew", "(Lsun/security/krb5/internal/KerberosTime;I)Z", nullptr, $PUBLIC},
	{"greaterThanWRTClockSkew", "(Lsun/security/krb5/internal/KerberosTime;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"inClockSkew", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(KerberosTime::*)(int32_t)>(&KerberosTime::inClockSkew))},
	{"inClockSkew", "()Z", nullptr, $PUBLIC},
	{"isZero", "()Z", nullptr, $PUBLIC},
	{"now", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KerberosTime*(*)()>(&KerberosTime::now))},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC | $STATIC, $method(static_cast<KerberosTime*(*)($DerInputStream*,int8_t,bool)>(&KerberosTime::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"toDate", "()Ljava/util/Date;", nullptr, $PUBLIC},
	{"toGeneralizedTimeString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"toKerberosTime", "(Ljava/lang/String;)J", nullptr, $PRIVATE | $STATIC, $method(static_cast<int64_t(*)($String*)>(&KerberosTime::toKerberosTime)), "sun.security.krb5.Asn1Exception"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"withMicroSeconds", "(I)Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _KerberosTime_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KerberosTime",
	"java.lang.Object",
	nullptr,
	_KerberosTime_FieldInfo_,
	_KerberosTime_MethodInfo_
};

$Object* allocate$KerberosTime($Class* clazz) {
	return $of($alloc(KerberosTime));
}

int64_t KerberosTime::initMilli = 0;
int64_t KerberosTime::initMicro = 0;
bool KerberosTime::DEBUG = false;

void KerberosTime::init$(int64_t time, int32_t micro) {
	this->kerberosTime = time;
	this->microSeconds = micro;
}

void KerberosTime::init$(int64_t time) {
	KerberosTime::init$(time, 0);
}

void KerberosTime::init$($String* time) {
	KerberosTime::init$(toKerberosTime(time), 0);
}

int64_t KerberosTime::toKerberosTime($String* time) {
	$init(KerberosTime);
	if ($nc(time)->length() != 15) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_TIMEFORMAT);
	}
	if ($nc(time)->charAt(14) != u'Z') {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_TIMEFORMAT);
	}
	int32_t year = $Integer::parseInt($($nc(time)->substring(0, 4)));
	$var($Calendar, calendar, $Calendar::getInstance($($TimeZone::getTimeZone("UTC"_s))));
	$nc(calendar)->clear();
	int32_t var$0 = year;
	int32_t var$1 = $Integer::parseInt($($nc(time)->substring(4, 6))) - 1;
	int32_t var$2 = $Integer::parseInt($($nc(time)->substring(6, 8)));
	int32_t var$3 = $Integer::parseInt($($nc(time)->substring(8, 10)));
	int32_t var$4 = $Integer::parseInt($($nc(time)->substring(10, 12)));
	calendar->set(var$0, var$1, var$2, var$3, var$4, $Integer::parseInt($($nc(time)->substring(12, 14))));
	return calendar->getTimeInMillis();
}

void KerberosTime::init$($Date* time) {
	KerberosTime::init$($nc(time)->getTime(), 0);
}

void KerberosTime::init$($Instant* instant) {
	int64_t var$1 = $nc(instant)->getEpochSecond() * 1000;
	int64_t var$0 = var$1 + $div(instant->getNano(), (int64_t)1000000);
	KerberosTime::init$(var$0, instant->getNano() / 1000 % 1000);
}

KerberosTime* KerberosTime::now() {
	$init(KerberosTime);
	int64_t newMilli = $System::currentTimeMillis();
	int64_t newMicro = $System::nanoTime() / 1000;
	int64_t microElapsed = newMicro - KerberosTime::initMicro;
	int64_t calcMilli = KerberosTime::initMilli + microElapsed / 1000;
	if (calcMilli - newMilli > 100 || newMilli - calcMilli > 100) {
		if (KerberosTime::DEBUG) {
			$nc($System::out)->println("System time adjusted"_s);
		}
		KerberosTime::initMilli = newMilli;
		KerberosTime::initMicro = newMicro;
		return $new(KerberosTime, newMilli, 0);
	} else {
		return $new(KerberosTime, calcMilli, (int32_t)(microElapsed % 1000));
	}
}

$String* KerberosTime::toGeneralizedTimeString() {
	$var($Calendar, calendar, $Calendar::getInstance($($TimeZone::getTimeZone("UTC"_s))));
	$nc(calendar)->clear();
	calendar->setTimeInMillis(this->kerberosTime);
	return $String::format("%04d%02d%02d%02d%02d%02dZ"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(calendar->get($Calendar::YEAR)))),
		$($of($Integer::valueOf(calendar->get($Calendar::MONTH) + 1))),
		$($of($Integer::valueOf(calendar->get($Calendar::DAY_OF_MONTH)))),
		$($of($Integer::valueOf(calendar->get($Calendar::HOUR_OF_DAY)))),
		$($of($Integer::valueOf(calendar->get($Calendar::MINUTE)))),
		$($of($Integer::valueOf(calendar->get($Calendar::SECOND))))
	}));
}

$bytes* KerberosTime::asn1Encode() {
	$var($DerOutputStream, out, $new($DerOutputStream));
	out->putGeneralizedTime($(this->toDate()));
	return out->toByteArray();
}

int64_t KerberosTime::getTime() {
	return this->kerberosTime;
}

$Date* KerberosTime::toDate() {
	return $new($Date, this->kerberosTime);
}

int32_t KerberosTime::getMicroSeconds() {
	int32_t temp_int = (int32_t)(($mod(this->kerberosTime, (int64_t)1000)) * (int64_t)1000);
	return temp_int + this->microSeconds;
}

KerberosTime* KerberosTime::withMicroSeconds(int32_t usec) {
	return $new(KerberosTime, this->kerberosTime - $mod(this->kerberosTime, (int64_t)1000) + $div(usec, (int64_t)1000), usec % 1000);
}

bool KerberosTime::inClockSkew(int32_t clockSkew) {
	return $Math::abs(this->kerberosTime - $System::currentTimeMillis()) <= clockSkew * (int64_t)1000;
}

bool KerberosTime::inClockSkew() {
	return inClockSkew(getDefaultSkew());
}

bool KerberosTime::greaterThanWRTClockSkew(KerberosTime* time, int32_t clockSkew) {
	if ((this->kerberosTime - $nc(time)->kerberosTime) > clockSkew * (int64_t)1000) {
		return true;
	}
	return false;
}

bool KerberosTime::greaterThanWRTClockSkew(KerberosTime* time) {
	return greaterThanWRTClockSkew(time, getDefaultSkew());
}

bool KerberosTime::greaterThan(KerberosTime* time) {
	return this->kerberosTime > $nc(time)->kerberosTime || this->kerberosTime == $nc(time)->kerberosTime && this->microSeconds > time->microSeconds;
}

bool KerberosTime::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(KerberosTime, obj))) {
		return false;
	}
	return this->kerberosTime == $nc(($cast(KerberosTime, obj)))->kerberosTime && this->microSeconds == ($cast(KerberosTime, obj))->microSeconds;
}

int32_t KerberosTime::hashCode() {
	int32_t result = 37 * 17 + (int32_t)(this->kerberosTime ^ ((int64_t)((uint64_t)this->kerberosTime >> 32)));
	return result * 17 + this->microSeconds;
}

bool KerberosTime::isZero() {
	return this->kerberosTime == 0 && this->microSeconds == 0;
}

int32_t KerberosTime::getSeconds() {
	return (int32_t)($div(this->kerberosTime, (int64_t)1000));
}

KerberosTime* KerberosTime::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(KerberosTime);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		$var($Date, temp, $nc(subDer)->getGeneralizedTime());
		return $new(KerberosTime, $nc(temp)->getTime(), 0);
	}
}

int32_t KerberosTime::getDefaultSkew() {
	$init(KerberosTime);
	int32_t tdiff = $Krb5::DEFAULT_ALLOWABLE_CLOCKSKEW;
	try {
		if ((tdiff = $nc($($Config::getInstance()))->getIntValue($$new($StringArray, {
			"libdefaults"_s,
			"clockskew"_s
		}))) == $Integer::MIN_VALUE) {
			tdiff = $Krb5::DEFAULT_ALLOWABLE_CLOCKSKEW;
		}
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		if (KerberosTime::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({"Exception in getting clockskew from Configuration using default value: "_s, $(e->getMessage())}));
		}
	}
	return tdiff;
}

$String* KerberosTime::toString() {
	return toGeneralizedTimeString();
}

void clinit$KerberosTime($Class* class$) {
	KerberosTime::initMilli = $System::currentTimeMillis();
	KerberosTime::initMicro = $System::nanoTime() / 1000;
	$init($Krb5);
	KerberosTime::DEBUG = $Krb5::DEBUG;
}

KerberosTime::KerberosTime() {
}

$Class* KerberosTime::load$($String* name, bool initialize) {
	$loadClass(KerberosTime, name, initialize, &_KerberosTime_ClassInfo_, clinit$KerberosTime, allocate$KerberosTime);
	return class$;
}

$Class* KerberosTime::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun