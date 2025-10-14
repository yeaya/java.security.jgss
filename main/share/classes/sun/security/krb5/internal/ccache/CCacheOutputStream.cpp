#include <sun/security/krb5/internal/ccache/CCacheOutputStream.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/ccache/Credentials.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry.h>
#include <sun/security/krb5/internal/ccache/FileCCacheConstants.h>
#include <sun/security/krb5/internal/util/KrbDataOutputStream.h>
#include <jcpp.h>

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

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;
using $Credentials = ::sun::security::krb5::internal::ccache::Credentials;
using $CredentialsCache$ConfigEntry = ::sun::security::krb5::internal::ccache::CredentialsCache$ConfigEntry;
using $FileCCacheConstants = ::sun::security::krb5::internal::ccache::FileCCacheConstants;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $KrbDataOutputStream = ::sun::security::krb5::internal::util::KrbDataOutputStream;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$MethodInfo _CCacheOutputStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(CCacheOutputStream::*)($OutputStream*)>(&CCacheOutputStream::init$))},
	{"addConfigEntry", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"addCreds", "(Lsun/security/krb5/internal/ccache/Credentials;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,sun.security.krb5.Asn1Exception"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeFlags", "(Lsun/security/krb5/internal/TicketFlags;)V", nullptr, 0, nullptr, "java.io.IOException"},
	{"writeHeader", "(Lsun/security/krb5/PrincipalName;I)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"writeTicket", "(Lsun/security/krb5/internal/Ticket;)V", nullptr, 0, nullptr, "java.io.IOException,sun.security.krb5.Asn1Exception"},
	{}
};

$ClassInfo _CCacheOutputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ccache.CCacheOutputStream",
	"sun.security.krb5.internal.util.KrbDataOutputStream",
	"sun.security.krb5.internal.ccache.FileCCacheConstants",
	nullptr,
	_CCacheOutputStream_MethodInfo_
};

$Object* allocate$CCacheOutputStream($Class* clazz) {
	return $of($alloc(CCacheOutputStream));
}

int32_t CCacheOutputStream::hashCode() {
	 return this->$KrbDataOutputStream::hashCode();
}

bool CCacheOutputStream::equals(Object$* arg0) {
	 return this->$KrbDataOutputStream::equals(arg0);
}

$Object* CCacheOutputStream::clone() {
	 return this->$KrbDataOutputStream::clone();
}

$String* CCacheOutputStream::toString() {
	 return this->$KrbDataOutputStream::toString();
}

void CCacheOutputStream::finalize() {
	this->$KrbDataOutputStream::finalize();
}

void CCacheOutputStream::init$($OutputStream* os) {
	$KrbDataOutputStream::init$(os);
}

void CCacheOutputStream::writeHeader($PrincipalName* p, int32_t version) {
	write(((int32_t)(version & (uint32_t)0x0000FF00)) >> 8);
	write((int32_t)(version & (uint32_t)255));
	$nc(p)->writePrincipal(this);
}

void CCacheOutputStream::addCreds($Credentials* creds) {
	$nc($nc(creds)->cname)->writePrincipal(this);
	$nc(creds->sname)->writePrincipal(this);
	$nc(creds->key)->writeKey(this);
	write32((int32_t)($nc(creds->authtime)->getTime() / 1000));
	if (creds->starttime != nullptr) {
		write32((int32_t)($nc(creds->starttime)->getTime() / 1000));
	} else {
		write32(0);
	}
	write32((int32_t)($nc(creds->endtime)->getTime() / 1000));
	if (creds->renewTill != nullptr) {
		write32((int32_t)($nc(creds->renewTill)->getTime() / 1000));
	} else {
		write32(0);
	}
	if (creds->isEncInSKey) {
		write8(1);
	} else {
		write8(0);
	}
	writeFlags(creds->flags);
	if (creds->caddr == nullptr) {
		write32(0);
	} else {
		$nc(creds->caddr)->writeAddrs(this);
	}
	if (creds->authorizationData == nullptr) {
		write32(0);
	} else {
		$nc(creds->authorizationData)->writeAuth(this);
	}
	writeTicket(creds->ticket);
	writeTicket(creds->secondTicket);
}

void CCacheOutputStream::addConfigEntry($PrincipalName* cname, $CredentialsCache$ConfigEntry* e) {
	$nc(cname)->writePrincipal(this);
	$nc($($nc(e)->getSName()))->writePrincipal(this);
	write16(0);
	write16(0);
	write32(0);
	write32(0);
	write32(0);
	write32(0);
	write32(0);
	write8(0);
	write32(0);
	write32(0);
	write32(0);
	write32($nc($(e->getData()))->length);
	write($(e->getData()));
	write32(0);
}

void CCacheOutputStream::writeTicket($Ticket* t) {
	if (t == nullptr) {
		write32(0);
	} else {
		$var($bytes, bytes, $nc(t)->asn1Encode());
		write32($nc(bytes)->length);
		write(bytes, 0, $nc(bytes)->length);
	}
}

void CCacheOutputStream::writeFlags($TicketFlags* flags) {
	int32_t tFlags = 0;
	$var($booleans, f, $nc(flags)->toBooleanArray());
	if ($nc(f)->get(1) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_FORWARDABLE;
	}
	if ($nc(f)->get(2) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_FORWARDED;
	}
	if ($nc(f)->get(3) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_PROXIABLE;
	}
	if ($nc(f)->get(4) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_PROXY;
	}
	if ($nc(f)->get(5) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_MAY_POSTDATE;
	}
	if ($nc(f)->get(6) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_POSTDATED;
	}
	if ($nc(f)->get(7) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_INVALID;
	}
	if ($nc(f)->get(8) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_RENEWABLE;
	}
	if ($nc(f)->get(9) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_INITIAL;
	}
	if ($nc(f)->get(10) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_PRE_AUTH;
	}
	if ($nc(f)->get(11) == true) {
		tFlags |= $FileCCacheConstants::TKT_FLG_HW_AUTH;
	}
	write32(tFlags);
}

CCacheOutputStream::CCacheOutputStream() {
}

$Class* CCacheOutputStream::load$($String* name, bool initialize) {
	$loadClass(CCacheOutputStream, name, initialize, &_CCacheOutputStream_ClassInfo_, allocate$CCacheOutputStream);
	return class$;
}

$Class* CCacheOutputStream::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun