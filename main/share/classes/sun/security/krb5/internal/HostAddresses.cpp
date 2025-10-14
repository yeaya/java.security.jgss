#include <sun/security/krb5/internal/HostAddresses.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/net/NetworkInterface.h>
#include <java/net/UnknownHostException.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/HostAddress.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/ccache/CCacheOutputStream.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ADDRTYPE_INET
#undef ADDRTYPE_INET6
#undef ASN1_BAD_ID
#undef DEBUG
#undef KRB_ERR_GENERIC
#undef KRB_NT_SRV_HST

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $HostAddressArray = $Array<::sun::security::krb5::internal::HostAddress>;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $NetworkInterface = ::java::net::NetworkInterface;
using $UnknownHostException = ::java::net::UnknownHostException;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Config = ::sun::security::krb5::Config;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $CCacheOutputStream = ::sun::security::krb5::internal::ccache::CCacheOutputStream;
using $KrbDataOutputStream = ::sun::security::krb5::internal::util::KrbDataOutputStream;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _HostAddresses_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(HostAddresses, DEBUG)},
	{"addresses", "[Lsun/security/krb5/internal/HostAddress;", nullptr, $PRIVATE, $field(HostAddresses, addresses)},
	{"hashCode", "I", nullptr, $PRIVATE | $VOLATILE, $field(HostAddresses, hashCode$)},
	{}
};

$MethodInfo _HostAddresses_MethodInfo_[] = {
	{"<init>", "([Lsun/security/krb5/internal/HostAddress;)V", nullptr, $PUBLIC, $method(static_cast<void(HostAddresses::*)($HostAddressArray*)>(&HostAddresses::init$)), "java.io.IOException"},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HostAddresses::*)()>(&HostAddresses::init$)), "java.net.UnknownHostException"},
	{"<init>", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(HostAddresses::*)(int32_t)>(&HostAddresses::init$))},
	{"<init>", "(Lsun/security/krb5/PrincipalName;)V", nullptr, $PUBLIC, $method(static_cast<void(HostAddresses::*)($PrincipalName*)>(&HostAddresses::init$)), "java.net.UnknownHostException,sun.security.krb5.KrbException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(HostAddresses::*)($DerValue*)>(&HostAddresses::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"<init>", "([Ljava/net/InetAddress;)V", nullptr, $PUBLIC, $method(static_cast<void(HostAddresses::*)($InetAddressArray*)>(&HostAddresses::init$))},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getInetAddresses", "()[Ljava/net/InetAddress;", nullptr, $PUBLIC},
	{"getLocalAddresses", "()Lsun/security/krb5/internal/HostAddresses;", nullptr, $PUBLIC | $STATIC, $method(static_cast<HostAddresses*(*)()>(&HostAddresses::getLocalAddresses)), "java.io.IOException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"inList", "(Lsun/security/krb5/internal/HostAddress;)Z", nullptr, $PUBLIC},
	{"parse", "(Lsun/security/util/DerInputStream;BZ)Lsun/security/krb5/internal/HostAddresses;", nullptr, $PUBLIC | $STATIC, $method(static_cast<HostAddresses*(*)($DerInputStream*,int8_t,bool)>(&HostAddresses::parse)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeAddrs", "(Lsun/security/krb5/internal/ccache/CCacheOutputStream;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _HostAddresses_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.HostAddresses",
	"java.lang.Object",
	"java.lang.Cloneable",
	_HostAddresses_FieldInfo_,
	_HostAddresses_MethodInfo_
};

$Object* allocate$HostAddresses($Class* clazz) {
	return $of($alloc(HostAddresses));
}

bool HostAddresses::DEBUG = false;

void HostAddresses::init$($HostAddressArray* new_addresses) {
	$set(this, addresses, nullptr);
	this->hashCode$ = 0;
	if (new_addresses != nullptr) {
		$set(this, addresses, $new($HostAddressArray, new_addresses->length));
		for (int32_t i = 0; i < new_addresses->length; ++i) {
			if (new_addresses->get(i) == nullptr) {
				$throwNew($IOException, "Cannot create a HostAddress"_s);
			} else {
				$nc(this->addresses)->set(i, $cast($HostAddress, $($nc(new_addresses->get(i))->clone())));
			}
		}
	}
}

void HostAddresses::init$() {
	$set(this, addresses, nullptr);
	this->hashCode$ = 0;
	$set(this, addresses, $new($HostAddressArray, 1));
	$nc(this->addresses)->set(0, $$new($HostAddress));
}

void HostAddresses::init$(int32_t dummy) {
	$set(this, addresses, nullptr);
	this->hashCode$ = 0;
}

void HostAddresses::init$($PrincipalName* serverPrincipal) {
	$set(this, addresses, nullptr);
	this->hashCode$ = 0;
	$var($StringArray, components, $nc(serverPrincipal)->getNameStrings());
	if (serverPrincipal->getNameType() != $PrincipalName::KRB_NT_SRV_HST || $nc(components)->length < 2) {
		$throwNew($KrbException, $Krb5::KRB_ERR_GENERIC, "Bad name"_s);
	}
	$var($String, host, $nc(components)->get(1));
	$var($InetAddressArray, addr, $InetAddress::getAllByName(host));
	$var($HostAddressArray, hAddrs, $new($HostAddressArray, $nc(addr)->length));
	for (int32_t i = 0; i < addr->length; ++i) {
		hAddrs->set(i, $$new($HostAddress, addr->get(i)));
	}
	$set(this, addresses, hAddrs);
}

$Object* HostAddresses::clone() {
	$var(HostAddresses, new_hostAddresses, $new(HostAddresses, 0));
	if (this->addresses != nullptr) {
		$set(new_hostAddresses, addresses, $new($HostAddressArray, $nc(this->addresses)->length));
		for (int32_t i = 0; i < $nc(this->addresses)->length; ++i) {
			$nc(new_hostAddresses->addresses)->set(i, $cast($HostAddress, $($nc($nc(this->addresses)->get(i))->clone())));
		}
	}
	return $of(new_hostAddresses);
}

bool HostAddresses::inList($HostAddress* addr) {
	if (this->addresses != nullptr) {
		for (int32_t i = 0; i < $nc(this->addresses)->length; ++i) {
			if ($nc($nc(this->addresses)->get(i))->equals(addr)) {
				return true;
			}
		}
	}
	return false;
}

int32_t HostAddresses::hashCode() {
	if (this->hashCode$ == 0) {
		int32_t result = 17;
		if (this->addresses != nullptr) {
			for (int32_t i = 0; i < $nc(this->addresses)->length; ++i) {
				result = 37 * result + $nc($nc(this->addresses)->get(i))->hashCode();
			}
		}
		this->hashCode$ = result;
	}
	return this->hashCode$;
}

bool HostAddresses::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(HostAddresses, obj))) {
		return false;
	}
	$var(HostAddresses, addrs, $cast(HostAddresses, obj));
	if ((this->addresses == nullptr && $nc(addrs)->addresses != nullptr) || (this->addresses != nullptr && $nc(addrs)->addresses == nullptr)) {
		return false;
	}
	if (this->addresses != nullptr && $nc(addrs)->addresses != nullptr) {
		if ($nc(this->addresses)->length != $nc(addrs->addresses)->length) {
			return false;
		}
		for (int32_t i = 0; i < $nc(this->addresses)->length; ++i) {
			if (!$nc($nc(this->addresses)->get(i))->equals($nc(addrs->addresses)->get(i))) {
				return false;
			}
		}
	}
	return true;
}

void HostAddresses::init$($DerValue* encoding) {
	$set(this, addresses, nullptr);
	this->hashCode$ = 0;
	$var($Vector, tempAddresses, $new($Vector));
	$var($DerValue, der, nullptr);
	while ($nc($($nc(encoding)->getData()))->available() > 0) {
		$assign(der, $nc($(encoding->getData()))->getDerValue());
		tempAddresses->addElement($$new($HostAddress, der));
	}
	if (tempAddresses->size() > 0) {
		$set(this, addresses, $new($HostAddressArray, tempAddresses->size()));
		tempAddresses->copyInto(this->addresses);
	}
}

$bytes* HostAddresses::asn1Encode() {
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	$var($DerOutputStream, temp, $new($DerOutputStream));
	if (this->addresses != nullptr && $nc(this->addresses)->length > 0) {
		for (int32_t i = 0; i < $nc(this->addresses)->length; ++i) {
			bytes->write($($nc($nc(this->addresses)->get(i))->asn1Encode()));
		}
	}
	temp->write($DerValue::tag_Sequence, bytes);
	return temp->toByteArray();
}

HostAddresses* HostAddresses::parse($DerInputStream* data, int8_t explicitTag, bool optional) {
	$init(HostAddresses);
	if ((optional) && (((int32_t)((int8_t)$nc(data)->peekByte() & (uint32_t)(int32_t)(int8_t)31)) != explicitTag)) {
		return nullptr;
	}
	$var($DerValue, der, $nc(data)->getDerValue());
	if (explicitTag != ((int32_t)($nc(der)->getTag() & (uint32_t)(int32_t)(int8_t)31))) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	} else {
		$var($DerValue, subDer, $nc($(der->getData()))->getDerValue());
		return $new(HostAddresses, subDer);
	}
}

void HostAddresses::writeAddrs($CCacheOutputStream* cos) {
	if (this->addresses == nullptr || $nc(this->addresses)->length == 0) {
		$nc(cos)->write32(0);
		return;
	}
	$nc(cos)->write32($nc(this->addresses)->length);
	for (int32_t i = 0; i < $nc(this->addresses)->length; ++i) {
		cos->write16($nc($nc(this->addresses)->get(i))->addrType);
		cos->write32($nc($nc($nc(this->addresses)->get(i))->address)->length);
		cos->write($nc($nc(this->addresses)->get(i))->address, 0, $nc($nc($nc(this->addresses)->get(i))->address)->length);
	}
}

$InetAddressArray* HostAddresses::getInetAddresses() {
	if (this->addresses == nullptr || $nc(this->addresses)->length == 0) {
		return nullptr;
	}
	$var($ArrayList, ipAddrs, $new($ArrayList, $nc(this->addresses)->length));
	for (int32_t i = 0; i < $nc(this->addresses)->length; ++i) {
		try {
			if (($nc($nc(this->addresses)->get(i))->addrType == $Krb5::ADDRTYPE_INET) || ($nc($nc(this->addresses)->get(i))->addrType == $Krb5::ADDRTYPE_INET6)) {
				ipAddrs->add($($nc($nc(this->addresses)->get(i))->getInetAddress()));
			}
		} catch ($UnknownHostException&) {
			$var($UnknownHostException, e, $catch());
			return nullptr;
		}
	}
	$var($InetAddressArray, retVal, $new($InetAddressArray, ipAddrs->size()));
	return $fcast($InetAddressArray, ipAddrs->toArray(retVal));
}

HostAddresses* HostAddresses::getLocalAddresses() {
	$init(HostAddresses);
	$var($Set, all, $new($LinkedHashSet));
	try {
		if (HostAddresses::DEBUG) {
			$init($System);
			$nc($System::out)->println(">>> KrbKdcReq local addresses are:"_s);
		}
		$var($String, extra, $nc($($Config::getInstance()))->getAll($$new($StringArray, {
			"libdefaults"_s,
			"extra_addresses"_s
		})));
		if (extra != nullptr) {
			{
				$var($StringArray, arr$, extra->split("\\s+"_s));
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, s, arr$->get(i$));
					{
						all->add($($InetAddress::getByName(s)));
						if (HostAddresses::DEBUG) {
							$init($System);
							$nc($System::out)->println($$str({"   extra_addresses: "_s, $($InetAddress::getByName(s))}));
						}
					}
				}
			}
		}
		{
			$var($Iterator, i$, $nc($($Collections::list($($NetworkInterface::getNetworkInterfaces()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($NetworkInterface, ni, $cast($NetworkInterface, i$->next()));
				{
					if (HostAddresses::DEBUG) {
						$init($System);
						$nc($System::out)->println($$str({"   NetworkInterface "_s, ni, ":"_s}));
						$nc($System::out)->println($$str({"      "_s, $($Collections::list($($nc(ni)->getInetAddresses())))}));
					}
					all->addAll($(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($Collections::list($($nc(ni)->getInetAddresses())))))));
				}
			}
		}
		return $new(HostAddresses, $fcast($InetAddressArray, $(all->toArray($$new($InetAddressArray, all->size())))));
	} catch ($Exception&) {
		$var($Exception, exc, $catch());
		$throwNew($IOException, $(exc->toString()));
	}
	$shouldNotReachHere();
}

void HostAddresses::init$($InetAddressArray* inetAddresses) {
	$set(this, addresses, nullptr);
	this->hashCode$ = 0;
	if (inetAddresses == nullptr) {
		$set(this, addresses, nullptr);
		return;
	}
	$set(this, addresses, $new($HostAddressArray, $nc(inetAddresses)->length));
	for (int32_t i = 0; i < inetAddresses->length; ++i) {
		$nc(this->addresses)->set(i, $$new($HostAddress, inetAddresses->get(i)));
	}
}

$String* HostAddresses::toString() {
	return $Arrays::toString(this->addresses);
}

void clinit$HostAddresses($Class* class$) {
	$init($Krb5);
	HostAddresses::DEBUG = $Krb5::DEBUG;
}

HostAddresses::HostAddresses() {
}

$Class* HostAddresses::load$($String* name, bool initialize) {
	$loadClass(HostAddresses, name, initialize, &_HostAddresses_ClassInfo_, clinit$HostAddresses, allocate$HostAddresses);
	return class$;
}

$Class* HostAddresses::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun