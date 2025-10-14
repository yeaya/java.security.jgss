#include <sun/security/jgss/krb5/ServiceCreds.h>

#include <java/io/IOException.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <javax/security/auth/Subject.h>
#include <javax/security/auth/kerberos/KerberosKey.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <javax/security/auth/kerberos/KerberosTicket.h>
#include <javax/security/auth/kerberos/KeyTab.h>
#include <sun/security/jgss/krb5/Krb5Util.h>
#include <sun/security/jgss/krb5/SubjectComber.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/ktab/KeyTab.h>
#include <jcpp.h>

using $KerberosKeyArray = $Array<::javax::security::auth::kerberos::KerberosKey>;
using $EncryptionKeyArray = $Array<::sun::security::krb5::EncryptionKey>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $Subject = ::javax::security::auth::Subject;
using $KerberosKey = ::javax::security::auth::kerberos::KerberosKey;
using $KerberosPrincipal = ::javax::security::auth::kerberos::KerberosPrincipal;
using $KerberosTicket = ::javax::security::auth::kerberos::KerberosTicket;
using $1KeyTab = ::javax::security::auth::kerberos::KeyTab;
using $Krb5Util = ::sun::security::jgss::krb5::Krb5Util;
using $SubjectComber = ::sun::security::jgss::krb5::SubjectComber;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $KeyTab = ::sun::security::krb5::internal::ktab::KeyTab;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _ServiceCreds_FieldInfo_[] = {
	{"kp", "Ljavax/security/auth/kerberos/KerberosPrincipal;", nullptr, $PRIVATE, $field(ServiceCreds, kp)},
	{"allPrincs", "Ljava/util/Set;", "Ljava/util/Set<Ljavax/security/auth/kerberos/KerberosPrincipal;>;", $PRIVATE, $field(ServiceCreds, allPrincs)},
	{"ktabs", "Ljava/util/List;", "Ljava/util/List<Ljavax/security/auth/kerberos/KeyTab;>;", $PRIVATE, $field(ServiceCreds, ktabs)},
	{"kk", "Ljava/util/List;", "Ljava/util/List<Ljavax/security/auth/kerberos/KerberosKey;>;", $PRIVATE, $field(ServiceCreds, kk)},
	{"tgt", "Ljavax/security/auth/kerberos/KerberosTicket;", nullptr, $PRIVATE, $field(ServiceCreds, tgt)},
	{"destroyed", "Z", nullptr, $PRIVATE, $field(ServiceCreds, destroyed)},
	{}
};

$MethodInfo _ServiceCreds_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ServiceCreds::*)()>(&ServiceCreds::init$))},
	{"destroy", "()V", nullptr, $PUBLIC, $method(static_cast<void(ServiceCreds::*)()>(&ServiceCreds::destroy))},
	{"getEKeys", "(Lsun/security/krb5/PrincipalName;)[Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC, $method(static_cast<$EncryptionKeyArray*(ServiceCreds::*)($PrincipalName*)>(&ServiceCreds::getEKeys))},
	{"getInitCred", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC, $method(static_cast<$Credentials*(ServiceCreds::*)()>(&ServiceCreds::getInitCred))},
	{"getInstance", "(Ljavax/security/auth/Subject;Ljava/lang/String;)Lsun/security/jgss/krb5/ServiceCreds;", nullptr, $PUBLIC | $STATIC, $method(static_cast<ServiceCreds*(*)($Subject*,$String*)>(&ServiceCreds::getInstance))},
	{"getKKeys", "()[Ljavax/security/auth/kerberos/KerberosKey;", nullptr, $PUBLIC, $method(static_cast<$KerberosKeyArray*(ServiceCreds::*)()>(&ServiceCreds::getKKeys))},
	{"getKKeys", "(Ljavax/security/auth/kerberos/KerberosPrincipal;)[Ljavax/security/auth/kerberos/KerberosKey;", nullptr, $PUBLIC, $method(static_cast<$KerberosKeyArray*(ServiceCreds::*)($KerberosPrincipal*)>(&ServiceCreds::getKKeys))},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(static_cast<$String*(ServiceCreds::*)()>(&ServiceCreds::getName))},
	{}
};

$ClassInfo _ServiceCreds_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.jgss.krb5.ServiceCreds",
	"java.lang.Object",
	nullptr,
	_ServiceCreds_FieldInfo_,
	_ServiceCreds_MethodInfo_
};

$Object* allocate$ServiceCreds($Class* clazz) {
	return $of($alloc(ServiceCreds));
}

void ServiceCreds::init$() {
}

ServiceCreds* ServiceCreds::getInstance($Subject* subj, $String* serverPrincipal$renamed) {
	$var($String, serverPrincipal, serverPrincipal$renamed);
	$var(ServiceCreds, sc, $new(ServiceCreds));
	$load($KerberosPrincipal);
	$set(sc, allPrincs, $nc(subj)->getPrincipals($KerberosPrincipal::class$));
	{
		$load($KerberosKey);
		$var($Iterator, i$, $nc($($SubjectComber::findMany(subj, serverPrincipal, nullptr, $KerberosKey::class$)))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($KerberosKey, key, $cast($KerberosKey, i$->next()));
			{
				$nc(sc->allPrincs)->add($($nc(key)->getPrincipal()));
			}
		}
	}
	if (serverPrincipal != nullptr) {
		$set(sc, kp, $new($KerberosPrincipal, serverPrincipal));
	} else if ($nc(sc->allPrincs)->size() == 1) {
		bool hasUnbound = false;
		{
			$load($1KeyTab);
			$var($Iterator, i$, $nc($($SubjectComber::findMany(subj, nullptr, nullptr, $1KeyTab::class$)))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($1KeyTab, ktab, $cast($1KeyTab, i$->next()));
				{
					if (!$nc(ktab)->isBound()) {
						hasUnbound = true;
						break;
					}
				}
			}
		}
		if (!hasUnbound) {
			$set(sc, kp, $cast($KerberosPrincipal, $nc($($nc(sc->allPrincs)->iterator()))->next()));
			$assign(serverPrincipal, $nc(sc->kp)->getName());
		}
	}
	$load($1KeyTab);
	$set(sc, ktabs, $SubjectComber::findMany(subj, serverPrincipal, nullptr, $1KeyTab::class$));
	$load($KerberosKey);
	$set(sc, kk, $SubjectComber::findMany(subj, serverPrincipal, nullptr, $KerberosKey::class$));
	$load($KerberosTicket);
	$set(sc, tgt, $cast($KerberosTicket, $SubjectComber::find(subj, nullptr, serverPrincipal, $KerberosTicket::class$)));
	bool var$0 = $nc(sc->ktabs)->isEmpty();
	if (var$0 && $nc(sc->kk)->isEmpty() && sc->tgt == nullptr) {
		return nullptr;
	}
	sc->destroyed = false;
	return sc;
}

$String* ServiceCreds::getName() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This object is destroyed"_s);
	}
	return this->kp == nullptr ? ($String*)nullptr : $nc(this->kp)->getName();
}

$KerberosKeyArray* ServiceCreds::getKKeys() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This object is destroyed"_s);
	}
	$var($KerberosPrincipal, one, this->kp);
	if (one == nullptr && !$nc(this->allPrincs)->isEmpty()) {
		$assign(one, $cast($KerberosPrincipal, $nc($($nc(this->allPrincs)->iterator()))->next()));
	}
	if (one == nullptr) {
		{
			$var($Iterator, i$, $nc(this->ktabs)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($1KeyTab, ktab, $cast($1KeyTab, i$->next()));
				{
					$var($PrincipalName, pn, $nc($($Krb5Util::snapshotFromJavaxKeyTab(ktab)))->getOneName());
					if (pn != nullptr) {
						$assign(one, $new($KerberosPrincipal, $(pn->getName())));
						break;
					}
				}
			}
		}
	}
	if (one != nullptr) {
		return getKKeys(one);
	} else {
		return $new($KerberosKeyArray, 0);
	}
}

$KerberosKeyArray* ServiceCreds::getKKeys($KerberosPrincipal* princ) {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This object is destroyed"_s);
	}
	$var($ArrayList, keys, $new($ArrayList));
	if (this->kp != nullptr && !$nc(princ)->equals(this->kp)) {
		return $new($KerberosKeyArray, 0);
	}
	{
		$var($Iterator, i$, $nc(this->kk)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($KerberosKey, k, $cast($KerberosKey, i$->next()));
			{
				if ($nc($($nc(k)->getPrincipal()))->equals(princ)) {
					keys->add(k);
				}
			}
		}
	}
	{
		$var($Iterator, i$, $nc(this->ktabs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($1KeyTab, ktab, $cast($1KeyTab, i$->next()));
			{
				bool var$0 = $nc(ktab)->getPrincipal() == nullptr;
				if (var$0 && ktab->isBound()) {
					if (!$nc(this->allPrincs)->contains(princ)) {
						continue;
					}
				}
				{
					$var($KerberosKeyArray, arr$, $nc(ktab)->getKeys(princ));
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($KerberosKey, k, arr$->get(i$));
						{
							keys->add(k);
						}
					}
				}
			}
		}
	}
	return $fcast($KerberosKeyArray, keys->toArray($$new($KerberosKeyArray, keys->size())));
}

$EncryptionKeyArray* ServiceCreds::getEKeys($PrincipalName* princ) {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This object is destroyed"_s);
	}
	$var($KerberosKeyArray, kkeys, getKKeys($$new($KerberosPrincipal, $($nc(princ)->getName()))));
	if ($nc(kkeys)->length == 0) {
		$assign(kkeys, getKKeys());
	}
	$var($EncryptionKeyArray, ekeys, $new($EncryptionKeyArray, $nc(kkeys)->length));
	for (int32_t i = 0; i < ekeys->length; ++i) {
		$var($bytes, var$0, $nc(kkeys->get(i))->getEncoded());
		int32_t var$1 = $nc(kkeys->get(i))->getKeyType();
		ekeys->set(i, $$new($EncryptionKey, var$0, var$1, $($Integer::valueOf($nc(kkeys->get(i))->getVersionNumber()))));
	}
	return ekeys;
}

$Credentials* ServiceCreds::getInitCred() {
	if (this->destroyed) {
		$throwNew($IllegalStateException, "This object is destroyed"_s);
	}
	if (this->tgt == nullptr) {
		return nullptr;
	}
	try {
		return $Krb5Util::ticketToCreds(this->tgt);
	} catch ($KrbException&) {
		$var($Exception, e, $catch());
		return nullptr;
	} catch ($IOException&) {
		$var($Exception, e, $catch());
		return nullptr;
	}
	$shouldNotReachHere();
}

void ServiceCreds::destroy() {
	this->destroyed = true;
	$set(this, kp, nullptr);
	$nc(this->ktabs)->clear();
	$nc(this->kk)->clear();
	$set(this, tgt, nullptr);
}

ServiceCreds::ServiceCreds() {
}

$Class* ServiceCreds::load$($String* name, bool initialize) {
	$loadClass(ServiceCreds, name, initialize, &_ServiceCreds_ClassInfo_, allocate$ServiceCreds);
	return class$;
}

$Class* ServiceCreds::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun