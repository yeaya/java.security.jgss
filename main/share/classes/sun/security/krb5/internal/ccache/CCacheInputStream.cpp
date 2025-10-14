#include <sun/security/krb5/internal/ccache/CCacheInputStream.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/FilterInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Date.h>
#include <java/util/List.h>
#include <java/util/StringTokenizer.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/RealmException.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/AuthorizationDataEntry.h>
#include <sun/security/krb5/internal/HostAddress.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/ccache/Credentials.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry.h>
#include <sun/security/krb5/internal/ccache/FileCCacheConstants.h>
#include <sun/security/krb5/internal/ccache/Tag.h>
#include <sun/security/krb5/internal/util/KrbDataInputStream.h>
#include <sun/security/util/IOUtils.h>
#include <jcpp.h>

#undef DEBUG
#undef FCC_TAG_DELTATIME
#undef KRB5_FCC_FVNO_1
#undef KRB5_FCC_FVNO_3
#undef KRB5_NT_UNKNOWN
#undef TKT_FLG_FORWARDABLE
#undef TKT_FLG_FORWARDED
#undef TKT_FLG_HW_AUTH
#undef TKT_FLG_INITIAL
#undef TKT_FLG_INVALID
#undef TKT_FLG_MAY_POSTDATE
#undef TKT_FLG_POSTDATED
#undef TKT_FLG_PRE_AUTH
#undef TKT_FLG_PROXIABLE
#undef TKT_FLG_PROXY
#undef TKT_FLG_RENEWABLE
#undef TKT_OPTS_MAX

using $AuthorizationDataEntryArray = $Array<::sun::security::krb5::internal::AuthorizationDataEntry>;
using $HostAddressArray = $Array<::sun::security::krb5::internal::HostAddress>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $FilterInputStream = ::java::io::FilterInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Date = ::java::util::Date;
using $List = ::java::util::List;
using $StringTokenizer = ::java::util::StringTokenizer;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $RealmException = ::sun::security::krb5::RealmException;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $AuthorizationDataEntry = ::sun::security::krb5::internal::AuthorizationDataEntry;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $Credentials = ::sun::security::krb5::internal::ccache::Credentials;
using $CredentialsCache$ConfigEntry = ::sun::security::krb5::internal::ccache::CredentialsCache$ConfigEntry;
using $FileCCacheConstants = ::sun::security::krb5::internal::ccache::FileCCacheConstants;
using $Tag = ::sun::security::krb5::internal::ccache::Tag;
using $KrbDataInputStream = ::sun::security::krb5::internal::util::KrbDataInputStream;
using $IOUtils = ::sun::security::util::IOUtils;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$FieldInfo _CCacheInputStream_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(CCacheInputStream, DEBUG)},
	{}
};

$MethodInfo _CCacheInputStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(CCacheInputStream::*)($InputStream*)>(&CCacheInputStream::init$))},
	{"isRealm", "(Ljava/lang/String;)Z", nullptr, 0},
	{"readAddr", "()[Lsun/security/krb5/internal/HostAddress;", nullptr, 0, nullptr, "java.io.IOException,sun.security.krb5.internal.KrbApErrException"},
	{"readAuth", "()[Lsun/security/krb5/internal/AuthorizationDataEntry;", nullptr, 0, nullptr, "java.io.IOException"},
	{"readCred", "(I)Ljava/lang/Object;", nullptr, 0, nullptr, "java.io.IOException,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,sun.security.krb5.Asn1Exception"},
	{"readData", "()[B", nullptr, 0, nullptr, "java.io.IOException"},
	{"readFlags", "()[Z", nullptr, 0, nullptr, "java.io.IOException"},
	{"readKey", "(I)Lsun/security/krb5/EncryptionKey;", nullptr, 0, nullptr, "java.io.IOException"},
	{"readPrincipal", "(I)Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, nullptr, "java.io.IOException,sun.security.krb5.RealmException"},
	{"readTag", "()Lsun/security/krb5/internal/ccache/Tag;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"readTimes", "()[J", nullptr, 0, nullptr, "java.io.IOException"},
	{"readskey", "()Z", nullptr, 0, nullptr, "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _CCacheInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ccache.CCacheInputStream",
	"sun.security.krb5.internal.util.KrbDataInputStream",
	"sun.security.krb5.internal.ccache.FileCCacheConstants",
	_CCacheInputStream_FieldInfo_,
	_CCacheInputStream_MethodInfo_
};

$Object* allocate$CCacheInputStream($Class* clazz) {
	return $of($alloc(CCacheInputStream));
}

int32_t CCacheInputStream::hashCode() {
	 return this->$KrbDataInputStream::hashCode();
}

bool CCacheInputStream::equals(Object$* arg0) {
	 return this->$KrbDataInputStream::equals(arg0);
}

$Object* CCacheInputStream::clone() {
	 return this->$KrbDataInputStream::clone();
}

$String* CCacheInputStream::toString() {
	 return this->$KrbDataInputStream::toString();
}

void CCacheInputStream::finalize() {
	this->$KrbDataInputStream::finalize();
}

bool CCacheInputStream::DEBUG = false;

void CCacheInputStream::init$($InputStream* is) {
	$KrbDataInputStream::init$(is);
}

$Tag* CCacheInputStream::readTag() {
	$var($chars, buf, $new($chars, 1024));
	int32_t len = 0;
	int32_t tag = -1;
	int32_t taglen = 0;
	$var($Integer, time_offset, nullptr);
	$var($Integer, usec_offset, nullptr);
	len = read(2);
	if (len < 0) {
		$throwNew($IOException, "stop."_s);
	}
	if (len > buf->length) {
		$throwNew($IOException, "Invalid tag length."_s);
	}
	while (len > 0) {
		tag = read(2);
		taglen = read(2);
		switch (tag) {
		case $FileCCacheConstants::FCC_TAG_DELTATIME:
			{
				$assign(time_offset, $Integer::valueOf(read(4)));
				$assign(usec_offset, $Integer::valueOf(read(4)));
				break;
			}
		default:
			{}
		}
		len = len - (4 + taglen);
	}
	return $new($Tag, len, tag, time_offset, usec_offset);
}

$PrincipalName* CCacheInputStream::readPrincipal(int32_t version) {
	int32_t type = 0;
	int32_t length = 0;
	int32_t namelength = 0;
	int32_t kret = 0;
	$var($StringArray, pname, nullptr);
	$var($String, realm, nullptr);
	if (version == $FileCCacheConstants::KRB5_FCC_FVNO_1) {
		type = $FileCCacheConstants::KRB5_NT_UNKNOWN;
	} else {
		type = read(4);
	}
	length = readLength4();
	$var($List, result, $new($ArrayList));
	if (version == $FileCCacheConstants::KRB5_FCC_FVNO_1) {
		--length;
	}
	for (int32_t i = 0; i <= length; ++i) {
		namelength = readLength4();
		$var($bytes, bytes, $IOUtils::readExactlyNBytes(this, namelength));
		result->add($$new($String, bytes));
	}
	if (result->isEmpty()) {
		$throwNew($IOException, "No realm or principal"_s);
	}
	if (isRealm($cast($String, $(result->get(0))))) {
		$assign(realm, $cast($String, result->remove(0)));
		if (result->isEmpty()) {
			$throwNew($IOException, "No principal name components"_s);
		}
		int32_t var$0 = type;
		$var($StringArray, var$1, $fcast($StringArray, result->toArray($$new($StringArray, result->size()))));
		return $new($PrincipalName, var$0, var$1, $$new($Realm, realm));
	}
	try {
		int32_t var$2 = type;
		$var($StringArray, var$3, $fcast($StringArray, result->toArray($$new($StringArray, result->size()))));
		return $new($PrincipalName, var$2, var$3, $($Realm::getDefault()));
	} catch ($RealmException&) {
		$var($RealmException, re, $catch());
		return nullptr;
	}
	$shouldNotReachHere();
}

bool CCacheInputStream::isRealm($String* str) {
	try {
		$var($Realm, r, $new($Realm, str));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		return false;
	}
	$var($StringTokenizer, st, $new($StringTokenizer, str, "."_s));
	$var($String, s, nullptr);
	while (st->hasMoreTokens()) {
		$assign(s, st->nextToken());
		for (int32_t i = 0; i < $nc(s)->length(); ++i) {
			if (s->charAt(i) >= 141) {
				return false;
			}
		}
	}
	return true;
}

$EncryptionKey* CCacheInputStream::readKey(int32_t version) {
	int32_t keyType = 0;
	int32_t keyLen = 0;
	keyType = read(2);
	if (version == $FileCCacheConstants::KRB5_FCC_FVNO_3) {
		read(2);
	}
	keyLen = readLength4();
	$var($bytes, bytes, $IOUtils::readExactlyNBytes(this, keyLen));
	return $new($EncryptionKey, bytes, keyType, $($Integer::valueOf(version)));
}

$longs* CCacheInputStream::readTimes() {
	$var($longs, times, $new($longs, 4));
	times->set(0, (int64_t)read(4) * 1000);
	times->set(1, (int64_t)read(4) * 1000);
	times->set(2, (int64_t)read(4) * 1000);
	times->set(3, (int64_t)read(4) * 1000);
	return times;
}

bool CCacheInputStream::readskey() {
	if (read() == 0) {
		return false;
	} else {
		return true;
	}
}

$HostAddressArray* CCacheInputStream::readAddr() {
	int32_t numAddrs = 0;
	int32_t addrType = 0;
	int32_t addrLength = 0;
	numAddrs = readLength4();
	if (numAddrs > 0) {
		$var($List, addrs, $new($ArrayList));
		for (int32_t i = 0; i < numAddrs; ++i) {
			addrType = read(2);
			addrLength = readLength4();
			if (!(addrLength == 4 || addrLength == 16)) {
				if (CCacheInputStream::DEBUG) {
					$init($System);
					$nc($System::out)->println("Incorrect address format."_s);
				}
				return nullptr;
			}
			$var($bytes, result, $new($bytes, addrLength));
			for (int32_t j = 0; j < addrLength; ++j) {
				result->set(j, (int8_t)read(1));
			}
			addrs->add($$new($HostAddress, addrType, result));
		}
		return $fcast($HostAddressArray, addrs->toArray($$new($HostAddressArray, addrs->size())));
	}
	return nullptr;
}

$AuthorizationDataEntryArray* CCacheInputStream::readAuth() {
	int32_t num = 0;
	int32_t adtype = 0;
	int32_t adlength = 0;
	num = readLength4();
	if (num > 0) {
		$var($List, auData, $new($ArrayList));
		$var($bytes, data, nullptr);
		for (int32_t i = 0; i < num; ++i) {
			adtype = read(2);
			adlength = readLength4();
			$assign(data, $IOUtils::readExactlyNBytes(this, adlength));
			auData->add($$new($AuthorizationDataEntry, adtype, data));
		}
		return $fcast($AuthorizationDataEntryArray, auData->toArray($$new($AuthorizationDataEntryArray, auData->size())));
	} else {
		return nullptr;
	}
}

$bytes* CCacheInputStream::readData() {
	int32_t length = 0;
	length = readLength4();
	if (length == 0) {
		return nullptr;
	} else {
		return $IOUtils::readExactlyNBytes(this, length);
	}
}

$booleans* CCacheInputStream::readFlags() {
	$var($booleans, flags, $new($booleans, $Krb5::TKT_OPTS_MAX + 1));
	int32_t ticketFlags = 0;
	ticketFlags = read(4);
	if (((int32_t)(ticketFlags & (uint32_t)0x40000000)) == $FileCCacheConstants::TKT_FLG_FORWARDABLE) {
		flags->set(1, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x20000000)) == $FileCCacheConstants::TKT_FLG_FORWARDED) {
		flags->set(2, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x10000000)) == $FileCCacheConstants::TKT_FLG_PROXIABLE) {
		flags->set(3, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x08000000)) == $FileCCacheConstants::TKT_FLG_PROXY) {
		flags->set(4, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x04000000)) == $FileCCacheConstants::TKT_FLG_MAY_POSTDATE) {
		flags->set(5, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x02000000)) == $FileCCacheConstants::TKT_FLG_POSTDATED) {
		flags->set(6, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x01000000)) == $FileCCacheConstants::TKT_FLG_INVALID) {
		flags->set(7, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x00800000)) == $FileCCacheConstants::TKT_FLG_RENEWABLE) {
		flags->set(8, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x00400000)) == $FileCCacheConstants::TKT_FLG_INITIAL) {
		flags->set(9, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x00200000)) == $FileCCacheConstants::TKT_FLG_PRE_AUTH) {
		flags->set(10, true);
	}
	if (((int32_t)(ticketFlags & (uint32_t)0x00100000)) == $FileCCacheConstants::TKT_FLG_HW_AUTH) {
		flags->set(11, true);
	}
	if (CCacheInputStream::DEBUG) {
		$var($String, msg, ">>> CCacheInputStream: readFlags() "_s);
		if (flags->get(1) == true) {
			$plusAssign(msg, " FORWARDABLE;"_s);
		}
		if (flags->get(2) == true) {
			$plusAssign(msg, " FORWARDED;"_s);
		}
		if (flags->get(3) == true) {
			$plusAssign(msg, " PROXIABLE;"_s);
		}
		if (flags->get(4) == true) {
			$plusAssign(msg, " PROXY;"_s);
		}
		if (flags->get(5) == true) {
			$plusAssign(msg, " MAY_POSTDATE;"_s);
		}
		if (flags->get(6) == true) {
			$plusAssign(msg, " POSTDATED;"_s);
		}
		if (flags->get(7) == true) {
			$plusAssign(msg, " INVALID;"_s);
		}
		if (flags->get(8) == true) {
			$plusAssign(msg, " RENEWABLE;"_s);
		}
		if (flags->get(9) == true) {
			$plusAssign(msg, " INITIAL;"_s);
		}
		if (flags->get(10) == true) {
			$plusAssign(msg, " PRE_AUTH;"_s);
		}
		if (flags->get(11) == true) {
			$plusAssign(msg, " HW_AUTH;"_s);
		}
		$init($System);
		$nc($System::out)->println(msg);
	}
	return flags;
}

$Object* CCacheInputStream::readCred(int32_t version) {
	$var($PrincipalName, cpname, nullptr);
	try {
		$assign(cpname, readPrincipal(version));
	} catch ($Exception&) {
		$catch();
	}
	if (CCacheInputStream::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>>DEBUG <CCacheInputStream>  client principal is "_s, cpname}));
	}
	$var($PrincipalName, spname, nullptr);
	try {
		$assign(spname, readPrincipal(version));
	} catch ($Exception&) {
		$catch();
	}
	if (CCacheInputStream::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>>DEBUG <CCacheInputStream> server principal is "_s, spname}));
	}
	$var($EncryptionKey, key, readKey(version));
	if (CCacheInputStream::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>>DEBUG <CCacheInputStream> key type: "_s, $$str($nc(key)->getEType())}));
	}
	$var($longs, times, readTimes());
	$var($KerberosTime, authtime, $new($KerberosTime, $nc(times)->get(0)));
	$var($KerberosTime, starttime, ($nc(times)->get(1) == 0) ? ($KerberosTime*)nullptr : $new($KerberosTime, $nc(times)->get(1)));
	$var($KerberosTime, endtime, $new($KerberosTime, $nc(times)->get(2)));
	$var($KerberosTime, renewTill, ($nc(times)->get(3) == 0) ? ($KerberosTime*)nullptr : $new($KerberosTime, $nc(times)->get(3)));
	if (CCacheInputStream::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({">>>DEBUG <CCacheInputStream> auth time: "_s, $($nc($(authtime->toDate()))->toString())}));
		$nc($System::out)->println($$str({">>>DEBUG <CCacheInputStream> start time: "_s, ((starttime == nullptr) ? "null"_s : $($nc($($nc(starttime)->toDate()))->toString()))}));
		$nc($System::out)->println($$str({">>>DEBUG <CCacheInputStream> end time: "_s, $($nc($(endtime->toDate()))->toString())}));
		$nc($System::out)->println($$str({">>>DEBUG <CCacheInputStream> renew_till time: "_s, ((renewTill == nullptr) ? "null"_s : $($nc($($nc(renewTill)->toDate()))->toString()))}));
	}
	bool skey = readskey();
	$var($booleans, flags, readFlags());
	$var($TicketFlags, tFlags, $new($TicketFlags, flags));
	$var($HostAddressArray, addr, readAddr());
	$var($HostAddresses, addrs, nullptr);
	if (addr != nullptr) {
		$assign(addrs, $new($HostAddresses, addr));
	}
	$var($AuthorizationDataEntryArray, auDataEntry, readAuth());
	$var($AuthorizationData, auData, nullptr);
	if (auDataEntry != nullptr) {
		$assign(auData, $new($AuthorizationData, auDataEntry));
	}
	$var($bytes, ticketData, readData());
	$var($bytes, ticketData2, readData());
	if (cpname == nullptr || spname == nullptr) {
		return $of(nullptr);
	}
	try {
		if ($nc($($nc(spname)->getRealmString()))->equals("X-CACHECONF:"_s)) {
			$var($StringArray, nameParts, spname->getNameStrings());
			if ($nc($nc(nameParts)->get(0))->equals("krb5_ccache_conf_data"_s)) {
				return $of($new($CredentialsCache$ConfigEntry, nameParts->get(1), nameParts->length > 2 ? $$new($PrincipalName, nameParts->get(2)) : ($PrincipalName*)nullptr, ticketData));
			}
		}
		$var($PrincipalName, var$0, cpname);
		$var($PrincipalName, var$1, spname);
		$var($EncryptionKey, var$2, key);
		$var($KerberosTime, var$3, authtime);
		$var($KerberosTime, var$4, starttime);
		$var($KerberosTime, var$5, endtime);
		$var($KerberosTime, var$6, renewTill);
		bool var$7 = skey;
		$var($TicketFlags, var$8, tFlags);
		$var($HostAddresses, var$9, addrs);
		$var($AuthorizationData, var$10, auData);
		$var($Ticket, var$11, ticketData != nullptr ? $new($Ticket, ticketData) : ($Ticket*)nullptr);
		return $of($new($Credentials, var$0, var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, var$9, var$10, var$11, ticketData2 != nullptr ? $$new($Ticket, ticketData2) : ($Ticket*)nullptr));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		if (CCacheInputStream::DEBUG) {
			$init($System);
			e->printStackTrace($System::out);
		}
		return $of(nullptr);
	}
	$shouldNotReachHere();
}

void clinit$CCacheInputStream($Class* class$) {
	$init($Krb5);
	CCacheInputStream::DEBUG = $Krb5::DEBUG;
}

CCacheInputStream::CCacheInputStream() {
}

$Class* CCacheInputStream::load$($String* name, bool initialize) {
	$loadClass(CCacheInputStream, name, initialize, &_CCacheInputStream_ClassInfo_, clinit$CCacheInputStream, allocate$CCacheInputStream);
	return class$;
}

$Class* CCacheInputStream::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun