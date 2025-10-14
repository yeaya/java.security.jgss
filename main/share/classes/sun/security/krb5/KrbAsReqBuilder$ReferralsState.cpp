#include <sun/security/krb5/KrbAsReqBuilder$ReferralsState.h>

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Boolean.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/KrbAsReqBuilder.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/KRBError.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <jcpp.h>

#undef DEBUG
#undef DISABLE_REFERRALS
#undef KRB_ERR_WRONG_REALM
#undef KRB_NT_ENTERPRISE
#undef MAX_REFERRALS
#undef TRUE

using $PrintStream = ::java::io::PrintStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Config = ::sun::security::krb5::Config;
using $KrbAsReqBuilder = ::sun::security::krb5::KrbAsReqBuilder;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $KRBError = ::sun::security::krb5::internal::KRBError;
using $Krb5 = ::sun::security::krb5::internal::Krb5;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbAsReqBuilder$ReferralsState_FieldInfo_[] = {
	{"canonicalizeConfig", "Z", nullptr, $PRIVATE | $STATIC, $staticField(KrbAsReqBuilder$ReferralsState, canonicalizeConfig)},
	{"enabled", "Z", nullptr, $PRIVATE, $field(KrbAsReqBuilder$ReferralsState, enabled)},
	{"sendCanonicalize", "Z", nullptr, $PRIVATE, $field(KrbAsReqBuilder$ReferralsState, sendCanonicalize$)},
	{"isEnterpriseCname", "Z", nullptr, $PRIVATE, $field(KrbAsReqBuilder$ReferralsState, isEnterpriseCname)},
	{"count", "I", nullptr, $PRIVATE, $field(KrbAsReqBuilder$ReferralsState, count)},
	{"refreshComm", "Z", nullptr, $PRIVATE, $field(KrbAsReqBuilder$ReferralsState, refreshComm$)},
	{"reqBuilder", "Lsun/security/krb5/KrbAsReqBuilder;", nullptr, $PRIVATE, $field(KrbAsReqBuilder$ReferralsState, reqBuilder)},
	{}
};

$MethodInfo _KrbAsReqBuilder$ReferralsState_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/KrbAsReqBuilder;)V", nullptr, 0, $method(static_cast<void(KrbAsReqBuilder$ReferralsState::*)($KrbAsReqBuilder*)>(&KrbAsReqBuilder$ReferralsState::init$)), "sun.security.krb5.KrbException"},
	{"handleError", "(Lsun/security/krb5/KrbException;)Z", nullptr, 0, $method(static_cast<bool(KrbAsReqBuilder$ReferralsState::*)($KrbException*)>(&KrbAsReqBuilder$ReferralsState::handleError)), "sun.security.krb5.RealmException"},
	{"initStatic", "()V", nullptr, $STATIC, $method(static_cast<void(*)()>(&KrbAsReqBuilder$ReferralsState::initStatic))},
	{"isEnabled", "()Z", nullptr, 0, $method(static_cast<bool(KrbAsReqBuilder$ReferralsState::*)()>(&KrbAsReqBuilder$ReferralsState::isEnabled))},
	{"refreshComm", "()Z", nullptr, 0, $method(static_cast<bool(KrbAsReqBuilder$ReferralsState::*)()>(&KrbAsReqBuilder$ReferralsState::refreshComm))},
	{"sendCanonicalize", "()Z", nullptr, 0, $method(static_cast<bool(KrbAsReqBuilder$ReferralsState::*)()>(&KrbAsReqBuilder$ReferralsState::sendCanonicalize))},
	{"updateStatus", "()V", nullptr, $PRIVATE, $method(static_cast<void(KrbAsReqBuilder$ReferralsState::*)()>(&KrbAsReqBuilder$ReferralsState::updateStatus))},
	{}
};

$InnerClassInfo _KrbAsReqBuilder$ReferralsState_InnerClassesInfo_[] = {
	{"sun.security.krb5.KrbAsReqBuilder$ReferralsState", "sun.security.krb5.KrbAsReqBuilder", "ReferralsState", $STATIC | $FINAL},
	{}
};

$ClassInfo _KrbAsReqBuilder$ReferralsState_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.krb5.KrbAsReqBuilder$ReferralsState",
	"java.lang.Object",
	nullptr,
	_KrbAsReqBuilder$ReferralsState_FieldInfo_,
	_KrbAsReqBuilder$ReferralsState_MethodInfo_,
	nullptr,
	nullptr,
	_KrbAsReqBuilder$ReferralsState_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.KrbAsReqBuilder"
};

$Object* allocate$KrbAsReqBuilder$ReferralsState($Class* clazz) {
	return $of($alloc(KrbAsReqBuilder$ReferralsState));
}

bool KrbAsReqBuilder$ReferralsState::canonicalizeConfig = false;

void KrbAsReqBuilder$ReferralsState::initStatic() {
	$init(KrbAsReqBuilder$ReferralsState);
	KrbAsReqBuilder$ReferralsState::canonicalizeConfig = false;
	try {
		$init($Boolean);
		KrbAsReqBuilder$ReferralsState::canonicalizeConfig = $nc($($Config::getInstance()))->getBooleanObject($$new($StringArray, {
			"libdefaults"_s,
			"canonicalize"_s
		})) == $Boolean::TRUE;
	} catch ($KrbException&) {
		$var($KrbException, e, $catch());
		$init($Krb5);
		if ($Krb5::DEBUG) {
			$init($System);
			$var($String, var$0, $$str({"Exception in getting canonicalize, using default value "_s, $($Boolean::valueOf(KrbAsReqBuilder$ReferralsState::canonicalizeConfig)), ": "_s}));
			$nc($System::out)->println($$concat(var$0, $(e->getMessage())));
		}
	}
}

void KrbAsReqBuilder$ReferralsState::init$($KrbAsReqBuilder* reqBuilder) {
	$set(this, reqBuilder, reqBuilder);
	this->sendCanonicalize$ = KrbAsReqBuilder$ReferralsState::canonicalizeConfig;
	this->isEnterpriseCname = $nc($nc(reqBuilder)->refCname)->getNameType() == $PrincipalName::KRB_NT_ENTERPRISE;
	updateStatus();
	if (!this->enabled && this->isEnterpriseCname) {
		$throwNew($KrbException, "NT-ENTERPRISE principals only allowed when referrals are enabled."_s);
	}
	this->refreshComm$ = true;
}

void KrbAsReqBuilder$ReferralsState::updateStatus() {
	$init($Config);
	this->enabled = !$Config::DISABLE_REFERRALS && (this->isEnterpriseCname || this->sendCanonicalize$);
}

bool KrbAsReqBuilder$ReferralsState::handleError($KrbException* ke) {
	if (this->enabled) {
		if ($nc(ke)->returnCode() == $Krb5::KRB_ERR_WRONG_REALM) {
			$var($Realm, referredRealm, $nc($(ke->getError()))->getClientRealm());
			$init($Config);
			if (referredRealm != nullptr && !$nc($(referredRealm->toString()))->isEmpty() && this->count < $Config::MAX_REFERRALS) {
				int32_t var$0 = $nc($nc(this->reqBuilder)->refCname)->getNameType();
				$set($nc(this->reqBuilder), refCname, $new($PrincipalName, var$0, $($nc($nc(this->reqBuilder)->refCname)->getNameStrings()), referredRealm));
				this->refreshComm$ = true;
				++this->count;
				return true;
			}
		}
		$init($Config);
		if (this->count < $Config::MAX_REFERRALS && this->sendCanonicalize$) {
			$init($Krb5);
			if ($Krb5::DEBUG) {
				$init($System);
				$nc($System::out)->println("KrbAsReqBuilder: AS-REQ failed. Retrying with CANONICALIZE false."_s);
			}
			this->sendCanonicalize$ = false;
			updateStatus();
			return true;
		}
	}
	return false;
}

bool KrbAsReqBuilder$ReferralsState::refreshComm() {
	bool retRefreshComm = this->refreshComm$;
	this->refreshComm$ = false;
	return retRefreshComm;
}

bool KrbAsReqBuilder$ReferralsState::isEnabled() {
	return this->enabled;
}

bool KrbAsReqBuilder$ReferralsState::sendCanonicalize() {
	return this->sendCanonicalize$;
}

void clinit$KrbAsReqBuilder$ReferralsState($Class* class$) {
	{
		KrbAsReqBuilder$ReferralsState::initStatic();
	}
}

KrbAsReqBuilder$ReferralsState::KrbAsReqBuilder$ReferralsState() {
}

$Class* KrbAsReqBuilder$ReferralsState::load$($String* name, bool initialize) {
	$loadClass(KrbAsReqBuilder$ReferralsState, name, initialize, &_KrbAsReqBuilder$ReferralsState_ClassInfo_, clinit$KrbAsReqBuilder$ReferralsState, allocate$KrbAsReqBuilder$ReferralsState);
	return class$;
}

$Class* KrbAsReqBuilder$ReferralsState::class$ = nullptr;

		} // krb5
	} // security
} // sun