#include <sun/security/krb5/internal/TicketFlags.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/LoginOptions.h>
#include <sun/security/krb5/internal/util/KerberosFlags.h>
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef BITSTRING_BAD_LENGTH
#undef BITS_PER_UNIT
#undef FORWARDABLE
#undef PROXIABLE
#undef RENEWABLE
#undef TKT_OPTS_FORWARDABLE
#undef TKT_OPTS_MAX
#undef TKT_OPTS_PROXIABLE
#undef TKT_OPTS_RENEWABLE

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $LoginOptions = ::sun::security::krb5::internal::LoginOptions;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $BitArray = ::sun::security::util::BitArray;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$MethodInfo _TicketFlags_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TicketFlags::*)()>(&TicketFlags::init$))},
	{"<init>", "([Z)V", nullptr, $PUBLIC, $method(static_cast<void(TicketFlags::*)($booleans*)>(&TicketFlags::init$)), "sun.security.krb5.Asn1Exception"},
	{"<init>", "(I[B)V", nullptr, $PUBLIC, $method(static_cast<void(TicketFlags::*)(int32_t,$bytes*)>(&TicketFlags::init$)), "sun.security.krb5.Asn1Exception"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(TicketFlags::*)($DerValue*)>(&TicketFlags::init$)), "java.io.IOException,sun.security.krb5.Asn1Exception"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"match", "(Lsun/security/krb5/internal/LoginOptions;)Z", nullptr, $PUBLIC},
	{"match", "(Lsun/security/krb5/internal/TicketFlags;)Z", nullptr, $PUBLIC},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/internal/TicketFlags;", nullptr, $PUBLIC | $STATIC, $method(static_cast<TicketFlags*(*)($DerInputStream*,int8_t,bool)>(&TicketFlags::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _TicketFlags_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.TicketFlags",
	"sun.security.krb5.internal.util.KerberosFlags",
	nullptr,
	nullptr,
	_TicketFlags_MethodInfo_
};

$Object* allocate$TicketFlags($Class* clazz) {
	return $of($alloc(TicketFlags));
}

void TicketFlags::init$() {
	$KerberosFlags::init$($Krb5::TKT_OPTS_MAX + 1);
}

void TicketFlags::init$($booleans* flags) {
	$KerberosFlags::init$(flags);
	if ($nc(flags)->length > $Krb5::TKT_OPTS_MAX + 1) {
		$throwNew($Asn1Exception, $Krb5::BITSTRING_BAD_LENGTH);
	}
}

void TicketFlags::init$(int32_t size, $bytes* data) {
	$KerberosFlags::init$(size, data);
	if ((size > $nc(data)->length * $KerberosFlags::BITS_PER_UNIT) || (size > $Krb5::TKT_OPTS_MAX + 1)) {
		$throwNew($Asn1Exception, $Krb5::BITSTRING_BAD_LENGTH);
	}
}

void TicketFlags::init$($DerValue* encoding) {
	TicketFlags::init$($($nc($($nc(encoding)->getUnalignedBitString(true)))->toBooleanArray()));
}

TicketFlags* TicketFlags::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(TicketFlags);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(TicketFlags, subDer);
	}
}

$Object* TicketFlags::clone() {
	try {
		return $of($new(TicketFlags, $(this->toBooleanArray())));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		return $of(nullptr);
	}
	$shouldNotReachHere();
}

bool TicketFlags::match($LoginOptions* options) {
	bool matched = false;
	bool var$0 = this->get($Krb5::TKT_OPTS_FORWARDABLE);
	if (var$0 == ($nc(options)->get($KDCOptions::FORWARDABLE))) {
		bool var$1 = this->get($Krb5::TKT_OPTS_PROXIABLE);
		if (var$1 == (options->get($KDCOptions::PROXIABLE))) {
			bool var$2 = this->get($Krb5::TKT_OPTS_RENEWABLE);
			if (var$2 == (options->get($KDCOptions::RENEWABLE))) {
				matched = true;
			}
		}
	}
	return matched;
}

bool TicketFlags::match(TicketFlags* flags) {
	bool matched = true;
	for (int32_t i = 0; i <= $Krb5::TKT_OPTS_MAX; ++i) {
		bool var$0 = this->get(i);
		if (var$0 != $nc(flags)->get(i)) {
			return false;
		}
	}
	return matched;
}

$String* TicketFlags::toString() {
	$var($StringBuilder, sb, $new($StringBuilder));
	$var($booleans, flags, toBooleanArray());
	for (int32_t i = 0; i < $nc(flags)->length; ++i) {
		if (flags->get(i) == true) {
			switch (i) {
			case 0:
				{
					sb->append("RESERVED;"_s);
					break;
				}
			case 1:
				{
					sb->append("FORWARDABLE;"_s);
					break;
				}
			case 2:
				{
					sb->append("FORWARDED;"_s);
					break;
				}
			case 3:
				{
					sb->append("PROXIABLE;"_s);
					break;
				}
			case 4:
				{
					sb->append("PROXY;"_s);
					break;
				}
			case 5:
				{
					sb->append("MAY-POSTDATE;"_s);
					break;
				}
			case 6:
				{
					sb->append("POSTDATED;"_s);
					break;
				}
			case 7:
				{
					sb->append("INVALID;"_s);
					break;
				}
			case 8:
				{
					sb->append("RENEWABLE;"_s);
					break;
				}
			case 9:
				{
					sb->append("INITIAL;"_s);
					break;
				}
			case 10:
				{
					sb->append("PRE-AUTHENT;"_s);
					break;
				}
			case 11:
				{
					sb->append("HW-AUTHENT;"_s);
					break;
				}
			case 15:
				{
					sb->append("ENC-PA-REP;"_s);
					break;
				}
			}
		}
	}
	$var($String, result, sb->toString());
	if ($nc(result)->length() > 0) {
		$assign(result, result->substring(0, result->length() - 1));
	}
	return result;
}

TicketFlags::TicketFlags() {
}

$Class* TicketFlags::load$($String* name, bool initialize) {
	$loadClass(TicketFlags, name, initialize, &_TicketFlags_ClassInfo_, allocate$TicketFlags);
	return class$;
}

$Class* TicketFlags::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun