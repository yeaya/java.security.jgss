#include <sun/security/krb5/internal/HostAddress.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <java/net/Inet4Address.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/util/Arrays.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ADDRTYPE_APPLETALK
#undef ADDRTYPE_CHAOS
#undef ADDRTYPE_DECNET
#undef ADDRTYPE_INET
#undef ADDRTYPE_INET6
#undef ADDRTYPE_IPX
#undef ADDRTYPE_ISO
#undef ASN1_BAD_ID
#undef DEBUG
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $Inet4Address = ::java::net::Inet4Address;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $Arrays = ::java::util::Arrays;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _HostAddress_FieldInfo_[] = {
	{"addrType", "I", nullptr, 0, $field(HostAddress, addrType)},
	{"address", "[B", nullptr, 0, $field(HostAddress, address)},
	{"localInetAddress", "Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC, $staticField(HostAddress, localInetAddress)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HostAddress, DEBUG)},
	{"hashCode", "I", nullptr, $PRIVATE | $VOLATILE, $field(HostAddress, hashCode$)},
	{}
};

$MethodInfo _HostAddress_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(HostAddress::*)(int32_t)>(&HostAddress::init$))},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HostAddress::*)()>(&HostAddress::init$)), "java.net.UnknownHostException"},
	{"<init>", "(I[B)V", nullptr, $PUBLIC, $method(static_cast<void(HostAddress::*)(int32_t,$bytes*)>(&HostAddress::init$)), "sun.security.krb5.internal.KrbApErrException,java.net.UnknownHostException"},
	{"<init>", "(Ljava/net/InetAddress;)V", nullptr, $PUBLIC, $method(static_cast<void(HostAddress::*)($InetAddress*)>(&HostAddress::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(HostAddress::*)($DerValue*)>(&HostAddress::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getAddrType", "(Ljava/net/InetAddress;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(HostAddress::*)($InetAddress*)>(&HostAddress::getAddrType))},
	{"getInetAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC, nullptr, "java.net.UnknownHostException"},
	{"getLocalInetAddress", "()Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<$InetAddress*(*)()>(&HostAddress::getLocalInetAddress)), "java.net.UnknownHostException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/internal/HostAddress;", nullptr, $PUBLIC | $STATIC, $method(static_cast<HostAddress*(*)($DerInputStream*,int8_t,bool)>(&HostAddress::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _HostAddress_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.HostAddress",
	"java.lang.Object",
	"java.lang.Cloneable",
	_HostAddress_FieldInfo_,
	_HostAddress_MethodInfo_
};

$Object* allocate$HostAddress($Class* clazz) {
	return $of($alloc(HostAddress));
}

$InetAddress* HostAddress::localInetAddress = nullptr;
bool HostAddress::DEBUG = false;

void HostAddress::init$(int32_t dummy) {
	$set(this, address, nullptr);
	this->hashCode$ = 0;
}

$Object* HostAddress::clone() {
	$var(HostAddress, new_hostAddress, $new(HostAddress, 0));
	new_hostAddress->addrType = this->addrType;
	if (this->address != nullptr) {
		$set(new_hostAddress, address, $cast($bytes, $nc(this->address)->clone()));
	}
	return $of(new_hostAddress);
}

int32_t HostAddress::hashCode() {
	if (this->hashCode$ == 0) {
		int32_t result = 17;
		result = 37 * result + this->addrType;
		if (this->address != nullptr) {
			for (int32_t i = 0; i < $nc(this->address)->length; ++i) {
				result = 37 * result + $nc(this->address)->get(i);
			}
		}
		this->hashCode$ = result;
	}
	return this->hashCode$;
}

bool HostAddress::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(HostAddress, obj))) {
		return false;
	}
	$var(HostAddress, h, $cast(HostAddress, obj));
	if (this->addrType != $nc(h)->addrType || (this->address != nullptr && $nc(h)->address == nullptr) || (this->address == nullptr && $nc(h)->address != nullptr)) {
		return false;
	}
	if (this->address != nullptr && $nc(h)->address != nullptr) {
		if ($nc(this->address)->length != $nc(h->address)->length) {
			return false;
		}
		for (int32_t i = 0; i < $nc(this->address)->length; ++i) {
			if ($nc(this->address)->get(i) != $nc(h->address)->get(i)) {
				return false;
			}
		}
	}
	return true;
}

$InetAddress* HostAddress::getLocalInetAddress() {
	$load(HostAddress);
	$synchronized(class$) {
		$init(HostAddress);
		if (HostAddress::localInetAddress == nullptr) {
			$assignStatic(HostAddress::localInetAddress, $InetAddress::getLocalHost());
		}
		if (HostAddress::localInetAddress == nullptr) {
			$throwNew($UnknownHostException);
		}
		return (HostAddress::localInetAddress);
	}
}

$InetAddress* HostAddress::getInetAddress() {
	if (this->addrType == $Krb5::ADDRTYPE_INET || this->addrType == $Krb5::ADDRTYPE_INET6) {
		return ($InetAddress::getByAddress(this->address));
	} else {
		return nullptr;
	}
}

int32_t HostAddress::getAddrType($InetAddress* inetAddress) {
	int32_t addressType = 0;
	if ($instanceOf($Inet4Address, inetAddress)) {
		addressType = $Krb5::ADDRTYPE_INET;
	} else if ($instanceOf($Inet6Address, inetAddress)) {
		addressType = $Krb5::ADDRTYPE_INET6;
	}
	return (addressType);
}

void HostAddress::init$() {
	$set(this, address, nullptr);
	this->hashCode$ = 0;
	$var($InetAddress, inetAddress, getLocalInetAddress());
	this->addrType = getAddrType(inetAddress);
	$set(this, address, $nc(inetAddress)->getAddress());
}

void HostAddress::init$(int32_t new_addrType, $bytes* new_address) {
	$set(this, address, nullptr);
	this->hashCode$ = 0;
	switch (new_addrType) {
	case $Krb5::ADDRTYPE_INET:
		{
			if ($nc(new_address)->length != 4) {
				$throwNew($KrbApErrException, 0, "Invalid Internet address"_s);
			}
			break;
		}
	case $Krb5::ADDRTYPE_CHAOS:
		{
			if ($nc(new_address)->length != 2) {
				$throwNew($KrbApErrException, 0, "Invalid CHAOSnet address"_s);
			}
			break;
		}
	case $Krb5::ADDRTYPE_ISO:
		{
			break;
		}
	case $Krb5::ADDRTYPE_IPX:
		{
			if ($nc(new_address)->length != 6) {
				$throwNew($KrbApErrException, 0, "Invalid XNS address"_s);
			}
			break;
		}
	case $Krb5::ADDRTYPE_APPLETALK:
		{
			if ($nc(new_address)->length != 3) {
				$throwNew($KrbApErrException, 0, "Invalid DDP address"_s);
			}
			break;
		}
	case $Krb5::ADDRTYPE_DECNET:
		{
			if ($nc(new_address)->length != 2) {
				$throwNew($KrbApErrException, 0, "Invalid DECnet Phase IV address"_s);
			}
			break;
		}
	case $Krb5::ADDRTYPE_INET6:
		{
			if ($nc(new_address)->length != 16) {
				$throwNew($KrbApErrException, 0, "Invalid Internet IPv6 address"_s);
			}
			break;
		}
	}
	this->addrType = new_addrType;
	if (new_address != nullptr) {
		$set(this, address, $cast($bytes, new_address->clone()));
	}
	if (HostAddress::DEBUG) {
		if (this->addrType == $Krb5::ADDRTYPE_INET || this->addrType == $Krb5::ADDRTYPE_INET6) {
			$init($System);
			$nc($System::out)->println($$str({"Host address is "_s, $($InetAddress::getByAddress(this->address))}));
		}
	}
}

void HostAddress::init$($InetAddress* inetAddress) {
	$set(this, address, nullptr);
	this->hashCode$ = 0;
	this->addrType = getAddrType(inetAddress);
	$set(this, address, $nc(inetAddress)->getAddress());
}

void HostAddress::init$($DerValue* encoding) {
	$set(this, address, nullptr);
	this->hashCode$ = 0;
	$var($DerValue, der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)0) {
		this->addrType = $nc($($nc($(der->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($(encoding->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)1) {
		$set(this, address, $nc($(der->getData()))->getOctetString());
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	if ($nc($(encoding->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

$bytes* HostAddress::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putInteger(this->addrType);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putOctetString(this->address);
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

HostAddress* HostAddress::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(HostAddress);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(HostAddress, subDer);
	}
}

$String* HostAddress::toString() {
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($Arrays::toString(this->address)));
	sb->append(u'(')->append(this->addrType)->append(u')');
	return sb->toString();
}

void clinit$HostAddress($Class* class$) {
	$init($Krb5);
	HostAddress::DEBUG = $Krb5::DEBUG;
}

HostAddress::HostAddress() {
}

$Class* HostAddress::load$($String* name, bool initialize) {
	$loadClass(HostAddress, name, initialize, &_HostAddress_ClassInfo_, clinit$HostAddress, allocate$HostAddress);
	return class$;
}

$Class* HostAddress::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun