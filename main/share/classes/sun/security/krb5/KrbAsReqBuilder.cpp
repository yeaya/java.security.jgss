#include <sun/security/krb5/KrbAsReqBuilder.h>

#include <java/io/IOException.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Arrays.h>
#include <javax/security/auth/kerberos/KeyTab.h>
#include <sun/security/jgss/krb5/Krb5Util.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KdcComm.h>
#include <sun/security/krb5/KrbAsRep.h>
#include <sun/security/krb5/KrbAsReq.h>
#include <sun/security/krb5/KrbAsReqBuilder$ReferralsState.h>
#include <sun/security/krb5/KrbAsReqBuilder$State.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/KRBError.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/PAData$SaltAndParams.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/ccache/Credentials.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <jcpp.h>

#undef ASN1_PARSE_ERROR
#undef CANONICALIZE
#undef DEBUG
#undef DESTROYED
#undef ETYPE_ARCFOUR_HMAC
#undef INIT
#undef KDC_ERR_PREAUTH_FAILED
#undef KDC_ERR_PREAUTH_REQUIRED
#undef PA_REQ_ENC_PA_REP
#undef REQ_OK

using $EncryptionKeyArray = $Array<::sun::security::krb5::EncryptionKey>;
using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Arrays = ::java::util::Arrays;
using $KeyTab = ::javax::security::auth::kerberos::KeyTab;
using $Krb5Util = ::sun::security::jgss::krb5::Krb5Util;
using $1Credentials = ::sun::security::krb5::Credentials;
using $EncryptedData = ::sun::security::krb5::EncryptedData;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KdcComm = ::sun::security::krb5::KdcComm;
using $KrbAsRep = ::sun::security::krb5::KrbAsRep;
using $KrbAsReq = ::sun::security::krb5::KrbAsReq;
using $KrbAsReqBuilder$ReferralsState = ::sun::security::krb5::KrbAsReqBuilder$ReferralsState;
using $KrbAsReqBuilder$State = ::sun::security::krb5::KrbAsReqBuilder$State;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $HostAddresses = ::sun::security::krb5::internal::HostAddresses;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $KRBError = ::sun::security::krb5::internal::KRBError;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $PAData = ::sun::security::krb5::internal::PAData;
using $PAData$SaltAndParams = ::sun::security::krb5::internal::PAData$SaltAndParams;
using $Credentials = ::sun::security::krb5::internal::ccache::Credentials;
using $EType = ::sun::security::krb5::internal::crypto::EType;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbAsReqBuilder_FieldInfo_[] = {
	{"options", "Lsun/security/krb5/internal/KDCOptions;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, options)},
	{"cname", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, cname)},
	{"refCname", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, refCname)},
	{"sname", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, sname)},
	{"from", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, from)},
	{"till", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, till)},
	{"rtime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, rtime)},
	{"addresses", "Lsun/security/krb5/internal/HostAddresses;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, addresses)},
	{"password", "[C", nullptr, $PRIVATE | $FINAL, $field(KrbAsReqBuilder, password)},
	{"ktab", "Ljavax/security/auth/kerberos/KeyTab;", nullptr, $PRIVATE | $FINAL, $field(KrbAsReqBuilder, ktab)},
	{"paList", "[Lsun/security/krb5/internal/PAData;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, paList)},
	{"req", "Lsun/security/krb5/KrbAsReq;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, req)},
	{"rep", "Lsun/security/krb5/KrbAsRep;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, rep)},
	{"state", "Lsun/security/krb5/KrbAsReqBuilder$State;", nullptr, $PRIVATE, $field(KrbAsReqBuilder, state)},
	{}
};

$MethodInfo _KrbAsReqBuilder_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/PrincipalName;Ljavax/security/auth/kerberos/KeyTab;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbAsReqBuilder::*)($PrincipalName*,$KeyTab*)>(&KrbAsReqBuilder::init$)), "sun.security.krb5.KrbException"},
	{"<init>", "(Lsun/security/krb5/PrincipalName;[C)V", nullptr, $PUBLIC, $method(static_cast<void(KrbAsReqBuilder::*)($PrincipalName*,$chars*)>(&KrbAsReqBuilder::init$)), "sun.security.krb5.KrbException"},
	{"action", "()Lsun/security/krb5/KrbAsReqBuilder;", nullptr, $PUBLIC, $method(static_cast<KrbAsReqBuilder*(KrbAsReqBuilder::*)()>(&KrbAsReqBuilder::action)), "sun.security.krb5.KrbException,sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"build", "(Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/KrbAsReqBuilder$ReferralsState;)Lsun/security/krb5/KrbAsReq;", nullptr, $PRIVATE, $method(static_cast<$KrbAsReq*(KrbAsReqBuilder::*)($EncryptionKey*,$KrbAsReqBuilder$ReferralsState*)>(&KrbAsReqBuilder::build)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"checkState", "(Lsun/security/krb5/KrbAsReqBuilder$State;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbAsReqBuilder::*)($KrbAsReqBuilder$State*,$String*)>(&KrbAsReqBuilder::checkState))},
	{"destroy", "()V", nullptr, $PUBLIC, $method(static_cast<void(KrbAsReqBuilder::*)()>(&KrbAsReqBuilder::destroy))},
	{"getCCreds", "()Lsun/security/krb5/internal/ccache/Credentials;", nullptr, $PUBLIC, $method(static_cast<$Credentials*(KrbAsReqBuilder::*)()>(&KrbAsReqBuilder::getCCreds))},
	{"getCreds", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC, $method(static_cast<$1Credentials*(KrbAsReqBuilder::*)()>(&KrbAsReqBuilder::getCreds))},
	{"getKeys", "(Z)[Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC, $method(static_cast<$EncryptionKeyArray*(KrbAsReqBuilder::*)(bool)>(&KrbAsReqBuilder::getKeys)), "sun.security.krb5.KrbException"},
	{"init", "(Lsun/security/krb5/PrincipalName;)V", nullptr, $PRIVATE, $method(static_cast<void(KrbAsReqBuilder::*)($PrincipalName*)>(&KrbAsReqBuilder::init)), "sun.security.krb5.KrbException"},
	{"resolve", "()Lsun/security/krb5/KrbAsReqBuilder;", nullptr, $PRIVATE, $method(static_cast<KrbAsReqBuilder*(KrbAsReqBuilder::*)()>(&KrbAsReqBuilder::resolve)), "sun.security.krb5.KrbException,sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"send", "()Lsun/security/krb5/KrbAsReqBuilder;", nullptr, $PRIVATE, $method(static_cast<KrbAsReqBuilder*(KrbAsReqBuilder::*)()>(&KrbAsReqBuilder::send)), "sun.security.krb5.KrbException,java.io.IOException"},
	{"setAddresses", "(Lsun/security/krb5/internal/HostAddresses;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbAsReqBuilder::*)($HostAddresses*)>(&KrbAsReqBuilder::setAddresses))},
	{"setOptions", "(Lsun/security/krb5/internal/KDCOptions;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbAsReqBuilder::*)($KDCOptions*)>(&KrbAsReqBuilder::setOptions))},
	{"setRTime", "(Lsun/security/krb5/internal/KerberosTime;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbAsReqBuilder::*)($KerberosTime*)>(&KrbAsReqBuilder::setRTime))},
	{"setTarget", "(Lsun/security/krb5/PrincipalName;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbAsReqBuilder::*)($PrincipalName*)>(&KrbAsReqBuilder::setTarget))},
	{"setTill", "(Lsun/security/krb5/internal/KerberosTime;)V", nullptr, $PUBLIC, $method(static_cast<void(KrbAsReqBuilder::*)($KerberosTime*)>(&KrbAsReqBuilder::setTill))},
	{}
};

$InnerClassInfo _KrbAsReqBuilder_InnerClassesInfo_[] = {
	{"sun.security.krb5.KrbAsReqBuilder$ReferralsState", "sun.security.krb5.KrbAsReqBuilder", "ReferralsState", $STATIC | $FINAL},
	{"sun.security.krb5.KrbAsReqBuilder$State", "sun.security.krb5.KrbAsReqBuilder", "State", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _KrbAsReqBuilder_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.krb5.KrbAsReqBuilder",
	"java.lang.Object",
	nullptr,
	_KrbAsReqBuilder_FieldInfo_,
	_KrbAsReqBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_KrbAsReqBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.krb5.KrbAsReqBuilder$ReferralsState,sun.security.krb5.KrbAsReqBuilder$State"
};

$Object* allocate$KrbAsReqBuilder($Class* clazz) {
	return $of($alloc(KrbAsReqBuilder));
}

void KrbAsReqBuilder::init($PrincipalName* cname) {
	$set(this, cname, cname);
	$set(this, refCname, cname);
	$init($KrbAsReqBuilder$State);
	$set(this, state, $KrbAsReqBuilder$State::INIT);
}

void KrbAsReqBuilder::init$($PrincipalName* cname, $KeyTab* ktab) {
	init(cname);
	$set(this, ktab, ktab);
	$set(this, password, nullptr);
}

void KrbAsReqBuilder::init$($PrincipalName* cname, $chars* pass) {
	init(cname);
	$set(this, password, $cast($chars, $nc(pass)->clone()));
	$set(this, ktab, nullptr);
}

$EncryptionKeyArray* KrbAsReqBuilder::getKeys(bool isInitiator) {
	$init($KrbAsReqBuilder$State);
	checkState(isInitiator ? $KrbAsReqBuilder$State::REQ_OK : $KrbAsReqBuilder$State::INIT, "Cannot get keys"_s);
	if (this->password != nullptr) {
		$var($ints, eTypes, $EType::getDefaults("default_tkt_enctypes"_s));
		$var($EncryptionKeyArray, result, $new($EncryptionKeyArray, $nc(eTypes)->length));
		$var($String, salt, nullptr);
		try {
			for (int32_t i = 0; i < eTypes->length; ++i) {
				$var($PAData$SaltAndParams, snp, $PAData::getSaltAndParams(eTypes->get(i), this->paList));
				if (snp != nullptr) {
					if (eTypes->get(i) != $EncryptedData::ETYPE_ARCFOUR_HMAC && snp->salt != nullptr) {
						$assign(salt, snp->salt);
					}
					result->set(i, $($EncryptionKey::acquireSecretKey(this->cname, this->password, eTypes->get(i), snp)));
				}
			}
			if (salt == nullptr) {
				$assign(salt, $nc(this->cname)->getSalt());
			}
			for (int32_t i = 0; i < eTypes->length; ++i) {
				if (result->get(i) == nullptr) {
					result->set(i, $($EncryptionKey::acquireSecretKey(this->password, salt, eTypes->get(i), ($bytes*)nullptr)));
				}
			}
		} catch ($IOException&) {
			$var($IOException, ioe, $catch());
			$var($KrbException, ke, $new($KrbException, $Krb5::ASN1_PARSE_ERROR));
			ke->initCause(ioe);
			$throw(ke);
		}
		return result;
	} else {
		$throwNew($IllegalStateException, "Required password not provided"_s);
	}
}

void KrbAsReqBuilder::setOptions($KDCOptions* options) {
	$init($KrbAsReqBuilder$State);
	checkState($KrbAsReqBuilder$State::INIT, "Cannot specify options"_s);
	$set(this, options, options);
}

void KrbAsReqBuilder::setTill($KerberosTime* till) {
	$init($KrbAsReqBuilder$State);
	checkState($KrbAsReqBuilder$State::INIT, "Cannot specify till"_s);
	$set(this, till, till);
}

void KrbAsReqBuilder::setRTime($KerberosTime* rtime) {
	$init($KrbAsReqBuilder$State);
	checkState($KrbAsReqBuilder$State::INIT, "Cannot specify rtime"_s);
	$set(this, rtime, rtime);
}

void KrbAsReqBuilder::setTarget($PrincipalName* sname) {
	$init($KrbAsReqBuilder$State);
	checkState($KrbAsReqBuilder$State::INIT, "Cannot specify target"_s);
	$set(this, sname, sname);
}

void KrbAsReqBuilder::setAddresses($HostAddresses* addresses) {
	$init($KrbAsReqBuilder$State);
	checkState($KrbAsReqBuilder$State::INIT, "Cannot specify addresses"_s);
	$set(this, addresses, addresses);
}

$KrbAsReq* KrbAsReqBuilder::build($EncryptionKey* key, $KrbAsReqBuilder$ReferralsState* referralsState) {
	$var($PADataArray, extraPAs, nullptr);
	$var($ints, eTypes, nullptr);
	if (this->password != nullptr) {
		$assign(eTypes, $EType::getDefaults("default_tkt_enctypes"_s));
	} else {
		$var($EncryptionKeyArray, ks, $Krb5Util::keysFromJavaxKeyTab(this->ktab, this->cname));
		$assign(eTypes, $EType::getDefaults("default_tkt_enctypes"_s, ks));
		{
			$var($EncryptionKeyArray, arr$, ks);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($EncryptionKey, k, arr$->get(i$));
				$nc(k)->destroy();
			}
		}
	}
	$set(this, options, (this->options == nullptr) ? $new($KDCOptions) : this->options);
	if ($nc(referralsState)->isEnabled()) {
		if (referralsState->sendCanonicalize()) {
			$nc(this->options)->set($KDCOptions::CANONICALIZE, true);
		}
		$assign(extraPAs, $new($PADataArray, {$$new($PAData, $Krb5::PA_REQ_ENC_PA_REP, $$new($bytes, 0))}));
	} else {
		$nc(this->options)->set($KDCOptions::CANONICALIZE, false);
	}
	return $new($KrbAsReq, key, this->options, this->refCname, this->sname, this->from, this->till, this->rtime, eTypes, this->addresses, extraPAs);
}

KrbAsReqBuilder* KrbAsReqBuilder::resolve() {
	if (this->ktab != nullptr) {
		$nc(this->rep)->decryptUsingKeyTab(this->ktab, this->req, this->cname);
	} else {
		$nc(this->rep)->decryptUsingPassword(this->password, this->req, this->cname);
	}
	if ($nc(this->rep)->getPA() != nullptr) {
		if (this->paList == nullptr || $nc(this->paList)->length == 0) {
			$set(this, paList, $nc(this->rep)->getPA());
		} else {
			int32_t extraLen = $nc($($nc(this->rep)->getPA()))->length;
			if (extraLen > 0) {
				int32_t oldLen = $nc(this->paList)->length;
				$set(this, paList, $fcast($PADataArray, $Arrays::copyOf(this->paList, $nc(this->paList)->length + extraLen)));
				$System::arraycopy($($nc(this->rep)->getPA()), 0, this->paList, oldLen, extraLen);
			}
		}
	}
	return this;
}

KrbAsReqBuilder* KrbAsReqBuilder::send() {
	bool preAuthFailedOnce = false;
	$var($KdcComm, comm, nullptr);
	$var($EncryptionKey, pakey, nullptr);
	$var($KrbAsReqBuilder$ReferralsState, referralsState, $new($KrbAsReqBuilder$ReferralsState, this));
	while (true) {
		if (referralsState->refreshComm()) {
			$assign(comm, $new($KdcComm, $($nc(this->refCname)->getRealmAsString())));
		}
		try {
			$set(this, req, build(pakey, referralsState));
			$set(this, rep, $new($KrbAsRep, $($nc(comm)->send($($nc(this->req)->encoding())))));
			return this;
		} catch ($KrbException&) {
			$var($KrbException, ke, $catch());
			bool var$0 = !preAuthFailedOnce;
			if (var$0) {
				bool var$1 = ke->returnCode() == $Krb5::KDC_ERR_PREAUTH_FAILED;
				var$0 = (var$1 || ke->returnCode() == $Krb5::KDC_ERR_PREAUTH_REQUIRED);
			}
			if (var$0) {
				$init($Krb5);
				if ($Krb5::DEBUG) {
					$init($System);
					$nc($System::out)->println("KrbAsReqBuilder: PREAUTH FAILED/REQ, re-send AS-REQ"_s);
				}
				preAuthFailedOnce = true;
				$var($KRBError, kerr, ke->getError());
				$var($PADataArray, var$2, $nc(kerr)->getPA());
				int32_t paEType = $PAData::getPreferredEType(var$2, $nc($($EType::getDefaults("default_tkt_enctypes"_s)))->get(0));
				if (this->password == nullptr) {
					$var($EncryptionKeyArray, ks, $Krb5Util::keysFromJavaxKeyTab(this->ktab, this->cname));
					$assign(pakey, $EncryptionKey::findKey(paEType, ks));
					if (pakey != nullptr) {
						$assign(pakey, $cast($EncryptionKey, pakey->clone()));
					}
					{
						$var($EncryptionKeyArray, arr$, ks);
						int32_t len$ = $nc(arr$)->length;
						int32_t i$ = 0;
						for (; i$ < len$; ++i$) {
							$var($EncryptionKey, k, arr$->get(i$));
							$nc(k)->destroy();
						}
					}
				} else {
					$assign(pakey, $EncryptionKey::acquireSecretKey(this->cname, this->password, paEType, $($PAData::getSaltAndParams(paEType, $($nc(kerr)->getPA())))));
				}
				$set(this, paList, $nc(kerr)->getPA());
			} else {
				if (referralsState->handleError(ke)) {
					$assign(pakey, nullptr);
					preAuthFailedOnce = false;
					continue;
				}
				$throw(ke);
			}
		}
	}
	$shouldNotReachHere();
}

KrbAsReqBuilder* KrbAsReqBuilder::action() {
	$init($KrbAsReqBuilder$State);
	checkState($KrbAsReqBuilder$State::INIT, "Cannot call action"_s);
	$set(this, state, $KrbAsReqBuilder$State::REQ_OK);
	return $nc($(send()))->resolve();
}

$1Credentials* KrbAsReqBuilder::getCreds() {
	$init($KrbAsReqBuilder$State);
	checkState($KrbAsReqBuilder$State::REQ_OK, "Cannot retrieve creds"_s);
	return $nc(this->rep)->getCreds();
}

$Credentials* KrbAsReqBuilder::getCCreds() {
	$init($KrbAsReqBuilder$State);
	checkState($KrbAsReqBuilder$State::REQ_OK, "Cannot retrieve CCreds"_s);
	return $nc(this->rep)->getCCreds();
}

void KrbAsReqBuilder::destroy() {
	$init($KrbAsReqBuilder$State);
	$set(this, state, $KrbAsReqBuilder$State::DESTROYED);
	if (this->password != nullptr) {
		$Arrays::fill(this->password, (char16_t)0);
	}
}

void KrbAsReqBuilder::checkState($KrbAsReqBuilder$State* st, $String* msg) {
	if (this->state != st) {
		$throwNew($IllegalStateException, $$str({msg, " at "_s, st, " state"_s}));
	}
}

KrbAsReqBuilder::KrbAsReqBuilder() {
}

$Class* KrbAsReqBuilder::load$($String* name, bool initialize) {
	$loadClass(KrbAsReqBuilder, name, initialize, &_KrbAsReqBuilder_ClassInfo_, allocate$KrbAsReqBuilder);
	return class$;
}

$Class* KrbAsReqBuilder::class$ = nullptr;

		} // krb5
	} // security
} // sun