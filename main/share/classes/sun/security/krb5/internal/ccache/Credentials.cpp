#include <sun/security/krb5/internal/ccache/Credentials.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/EncKDCRepPart.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCRep.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $AuthorizationData = ::sun::security::krb5::internal::AuthorizationData;
using $EncKDCRepPart = ::sun::security::krb5::internal::EncKDCRepPart;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCRep = ::sun::security::krb5::internal::KDCRep;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Ticket = ::sun::security::krb5::internal::Ticket;
using $TicketFlags = ::sun::security::krb5::internal::TicketFlags;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

$FieldInfo _Credentials_FieldInfo_[] = {
	{"cname", "Lsun/security/krb5/PrincipalName;", nullptr, 0, $field(Credentials, cname)},
	{"sname", "Lsun/security/krb5/PrincipalName;", nullptr, 0, $field(Credentials, sname)},
	{"key", "Lsun/security/krb5/EncryptionKey;", nullptr, 0, $field(Credentials, key)},
	{"authtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, $field(Credentials, authtime)},
	{"starttime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, $field(Credentials, starttime)},
	{"endtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, $field(Credentials, endtime)},
	{"renewTill", "Lsun/security/krb5/internal/KerberosTime;", nullptr, 0, $field(Credentials, renewTill)},
	{"caddr", "Lsun/security/krb5/internal/HostAddresses;", nullptr, 0, $field(Credentials, caddr)},
	{"authorizationData", "Lsun/security/krb5/internal/AuthorizationData;", nullptr, 0, $field(Credentials, authorizationData)},
	{"isEncInSKey", "Z", nullptr, $PUBLIC, $field(Credentials, isEncInSKey)},
	{"flags", "Lsun/security/krb5/internal/TicketFlags;", nullptr, 0, $field(Credentials, flags)},
	{"ticket", "Lsun/security/krb5/internal/Ticket;", nullptr, 0, $field(Credentials, ticket)},
	{"secondTicket", "Lsun/security/krb5/internal/Ticket;", nullptr, 0, $field(Credentials, secondTicket)},
	{}
};

$MethodInfo _Credentials_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;Lsun/security/krb5/internal/KerberosTime;ZLsun/security/krb5/internal/TicketFlags;Lsun/security/krb5/internal/HostAddresses;Lsun/security/krb5/internal/AuthorizationData;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/internal/Ticket;)V", nullptr, $PUBLIC, $method(static_cast<void(Credentials::*)($PrincipalName*,$PrincipalName*,$EncryptionKey*,$KerberosTime*,$KerberosTime*,$KerberosTime*,$KerberosTime*,bool,$TicketFlags*,$HostAddresses*,$AuthorizationData*,$Ticket*,$Ticket*)>(&Credentials::init$))},
	{"<init>", "(Lsun/security/krb5/internal/KDCRep;Lsun/security/krb5/internal/Ticket;Lsun/security/krb5/internal/AuthorizationData;Z)V", nullptr, $PUBLIC, $method(static_cast<void(Credentials::*)($KDCRep*,$Ticket*,$AuthorizationData*,bool)>(&Credentials::init$))},
	{"<init>", "(Lsun/security/krb5/internal/KDCRep;)V", nullptr, $PUBLIC, $method(static_cast<void(Credentials::*)($KDCRep*)>(&Credentials::init$))},
	{"<init>", "(Lsun/security/krb5/internal/KDCRep;Lsun/security/krb5/internal/Ticket;)V", nullptr, $PUBLIC, $method(static_cast<void(Credentials::*)($KDCRep*,$Ticket*)>(&Credentials::init$))},
	{"getAuthTime", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC},
	{"getClientPrincipal", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, nullptr, "sun.security.krb5.RealmException"},
	{"getEType", "()I", nullptr, $PUBLIC},
	{"getEndTime", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC},
	{"getKey", "()Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC},
	{"getRenewTill", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC},
	{"getServicePrincipal", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, nullptr, "sun.security.krb5.RealmException"},
	{"getServicePrincipal2", "()Lsun/security/krb5/PrincipalName;", nullptr, $PUBLIC, nullptr, "sun.security.krb5.RealmException"},
	{"getStartTime", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC},
	{"getTicket", "()Lsun/security/krb5/internal/Ticket;", nullptr, $PUBLIC, nullptr, "sun.security.krb5.RealmException"},
	{"getTicketFlags", "()Lsun/security/krb5/internal/TicketFlags;", nullptr, $PUBLIC},
	{"getTktEType", "()I", nullptr, $PUBLIC},
	{"getTktEType2", "()I", nullptr, $PUBLIC},
	{"isValid", "()Z", nullptr, $PUBLIC},
	{"setKrbCreds", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Credentials_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.ccache.Credentials",
	"java.lang.Object",
	nullptr,
	_Credentials_FieldInfo_,
	_Credentials_MethodInfo_
};

$Object* allocate$Credentials($Class* clazz) {
	return $of($alloc(Credentials));
}

void Credentials::init$($PrincipalName* new_cname, $PrincipalName* new_sname, $EncryptionKey* new_key, $KerberosTime* new_authtime, $KerberosTime* new_starttime, $KerberosTime* new_endtime, $KerberosTime* new_renewTill, bool new_isEncInSKey, $TicketFlags* new_flags, $HostAddresses* new_caddr, $AuthorizationData* new_authData, $Ticket* new_ticket, $Ticket* new_secondTicket) {
	$set(this, cname, $cast($PrincipalName, $nc(new_cname)->clone()));
	$set(this, sname, $cast($PrincipalName, $nc(new_sname)->clone()));
	$set(this, key, $cast($EncryptionKey, $nc(new_key)->clone()));
	$set(this, authtime, new_authtime);
	$set(this, starttime, new_starttime);
	$set(this, endtime, new_endtime);
	$set(this, renewTill, new_renewTill);
	if (new_caddr != nullptr) {
		$set(this, caddr, $cast($HostAddresses, new_caddr->clone()));
	}
	if (new_authData != nullptr) {
		$set(this, authorizationData, $cast($AuthorizationData, new_authData->clone()));
	}
	this->isEncInSKey = new_isEncInSKey;
	$set(this, flags, $cast($TicketFlags, $nc(new_flags)->clone()));
	$set(this, ticket, ($cast($Ticket, $nc(new_ticket)->clone())));
	if (new_secondTicket != nullptr) {
		$set(this, secondTicket, $cast($Ticket, new_secondTicket->clone()));
	}
}

void Credentials::init$($KDCRep* kdcRep, $Ticket* new_secondTicket, $AuthorizationData* new_authorizationData, bool new_isEncInSKey) {
	if ($nc(kdcRep)->encKDCRepPart == nullptr) {
		return;
	}
	$set(this, cname, $cast($PrincipalName, $nc($nc(kdcRep)->cname)->clone()));
	$set(this, ticket, $cast($Ticket, $nc(kdcRep->ticket)->clone()));
	$set(this, key, $cast($EncryptionKey, $nc($nc(kdcRep->encKDCRepPart)->key)->clone()));
	$set(this, flags, $cast($TicketFlags, $nc($nc(kdcRep->encKDCRepPart)->flags)->clone()));
	$set(this, authtime, $nc(kdcRep->encKDCRepPart)->authtime);
	$set(this, starttime, $nc(kdcRep->encKDCRepPart)->starttime);
	$set(this, endtime, $nc(kdcRep->encKDCRepPart)->endtime);
	$set(this, renewTill, $nc(kdcRep->encKDCRepPart)->renewTill);
	$set(this, sname, $cast($PrincipalName, $nc($nc(kdcRep->encKDCRepPart)->sname)->clone()));
	$set(this, caddr, $cast($HostAddresses, $nc($nc(kdcRep->encKDCRepPart)->caddr)->clone()));
	$set(this, secondTicket, $cast($Ticket, $nc(new_secondTicket)->clone()));
	$set(this, authorizationData, $cast($AuthorizationData, $nc(new_authorizationData)->clone()));
	this->isEncInSKey = new_isEncInSKey;
}

void Credentials::init$($KDCRep* kdcRep) {
	Credentials::init$(kdcRep, nullptr);
}

void Credentials::init$($KDCRep* kdcRep, $Ticket* new_ticket) {
	$set(this, sname, $cast($PrincipalName, $nc($nc($nc(kdcRep)->encKDCRepPart)->sname)->clone()));
	$set(this, cname, $cast($PrincipalName, $nc(kdcRep->cname)->clone()));
	$set(this, key, $cast($EncryptionKey, $nc($nc(kdcRep->encKDCRepPart)->key)->clone()));
	$set(this, authtime, $nc(kdcRep->encKDCRepPart)->authtime);
	$set(this, starttime, $nc(kdcRep->encKDCRepPart)->starttime);
	$set(this, endtime, $nc(kdcRep->encKDCRepPart)->endtime);
	$set(this, renewTill, $nc(kdcRep->encKDCRepPart)->renewTill);
	$set(this, flags, $nc(kdcRep->encKDCRepPart)->flags);
	if ($nc(kdcRep->encKDCRepPart)->caddr != nullptr) {
		$set(this, caddr, $cast($HostAddresses, $nc($nc(kdcRep->encKDCRepPart)->caddr)->clone()));
	} else {
		$set(this, caddr, nullptr);
	}
	$set(this, ticket, $cast($Ticket, $nc(kdcRep->ticket)->clone()));
	if (new_ticket != nullptr) {
		$set(this, secondTicket, $cast($Ticket, new_ticket->clone()));
		this->isEncInSKey = true;
	} else {
		$set(this, secondTicket, nullptr);
		this->isEncInSKey = false;
	}
}

bool Credentials::isValid() {
	bool valid = true;
	int64_t var$0 = $nc(this->endtime)->getTime();
	if (var$0 < $System::currentTimeMillis()) {
		valid = false;
	} else if (this->starttime != nullptr) {
		int64_t var$1 = $nc(this->starttime)->getTime();
		if (var$1 > $System::currentTimeMillis()) {
			valid = false;
		}
	} else {
		int64_t var$3 = $nc(this->authtime)->getTime();
		if (var$3 > $System::currentTimeMillis()) {
			valid = false;
		}
	}
	return valid;
}

$PrincipalName* Credentials::getServicePrincipal() {
	return this->sname;
}

$Ticket* Credentials::getTicket() {
	return this->ticket;
}

$PrincipalName* Credentials::getServicePrincipal2() {
	return this->secondTicket == nullptr ? ($PrincipalName*)nullptr : $nc(this->secondTicket)->sname;
}

$PrincipalName* Credentials::getClientPrincipal() {
	return this->cname;
}

$Credentials* Credentials::setKrbCreds() {
	return $new($Credentials, this->ticket, this->cname, nullptr, this->sname, nullptr, this->key, this->flags, this->authtime, this->starttime, this->endtime, this->renewTill, this->caddr);
}

$KerberosTime* Credentials::getStartTime() {
	return this->starttime;
}

$KerberosTime* Credentials::getAuthTime() {
	return this->authtime;
}

$KerberosTime* Credentials::getEndTime() {
	return this->endtime;
}

$KerberosTime* Credentials::getRenewTill() {
	return this->renewTill;
}

$TicketFlags* Credentials::getTicketFlags() {
	return this->flags;
}

int32_t Credentials::getEType() {
	return $nc(this->key)->getEType();
}

$EncryptionKey* Credentials::getKey() {
	return this->key;
}

int32_t Credentials::getTktEType() {
	return $nc($nc(this->ticket)->encPart)->getEType();
}

int32_t Credentials::getTktEType2() {
	return (this->secondTicket == nullptr) ? 0 : $nc($nc(this->secondTicket)->encPart)->getEType();
}

Credentials::Credentials() {
}

$Class* Credentials::load$($String* name, bool initialize) {
	$loadClass(Credentials, name, initialize, &_Credentials_ClassInfo_, allocate$Credentials);
	return class$;
}

$Class* Credentials::class$ = nullptr;

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun