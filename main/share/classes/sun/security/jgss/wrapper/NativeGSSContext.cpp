#include <sun/security/jgss/wrapper/NativeGSSContext.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/Provider.h>
#include <javax/security/auth/kerberos/DelegationPermission.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/MessageProp.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSExceptionImpl.h>
#include <sun/security/jgss/GSSHeader.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/spnego/NegTokenInit.h>
#include <sun/security/jgss/spnego/NegTokenTarg.h>
#include <sun/security/jgss/wrapper/GSSCredElement.h>
#include <sun/security/jgss/wrapper/GSSLibStub.h>
#include <sun/security/jgss/wrapper/GSSNameElement.h>
#include <sun/security/jgss/wrapper/Krb5Util.h>
#include <sun/security/jgss/wrapper/SunNativeProvider.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef ACCEPT_ONLY
#undef DEFAULT_LIFETIME
#undef FAILURE
#undef GSS_C_ANON_FLAG
#undef GSS_C_CONF_FLAG
#undef GSS_C_DELEG_FLAG
#undef GSS_C_INTEG_FLAG
#undef GSS_C_MUTUAL_FLAG
#undef GSS_C_PROT_READY_FLAG
#undef GSS_C_REPLAY_FLAG
#undef GSS_C_SEQUENCE_FLAG
#undef GSS_C_TRANS_FLAG
#undef GSS_KRB5_MECH_OID
#undef INITIATE_ONLY
#undef INSTANCE
#undef NUM_OF_INQUIRE_VALUES
#undef UNAVAILABLE

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityManager = ::java::lang::SecurityManager;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $Provider = ::java::security::Provider;
using $DelegationPermission = ::javax::security::auth::kerberos::DelegationPermission;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSExceptionImpl = ::sun::security::jgss::GSSExceptionImpl;
using $GSSHeader = ::sun::security::jgss::GSSHeader;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $GSSContextSpi = ::sun::security::jgss::spi::GSSContextSpi;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $NegTokenInit = ::sun::security::jgss::spnego::NegTokenInit;
using $NegTokenTarg = ::sun::security::jgss::spnego::NegTokenTarg;
using $GSSCredElement = ::sun::security::jgss::wrapper::GSSCredElement;
using $GSSLibStub = ::sun::security::jgss::wrapper::GSSLibStub;
using $GSSNameElement = ::sun::security::jgss::wrapper::GSSNameElement;
using $Krb5Util = ::sun::security::jgss::wrapper::Krb5Util;
using $SunNativeProvider = ::sun::security::jgss::wrapper::SunNativeProvider;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

$FieldInfo _NativeGSSContext_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(NativeGSSContext, $assertionsDisabled)},
	{"GSS_C_DELEG_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, GSS_C_DELEG_FLAG)},
	{"GSS_C_MUTUAL_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, GSS_C_MUTUAL_FLAG)},
	{"GSS_C_REPLAY_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, GSS_C_REPLAY_FLAG)},
	{"GSS_C_SEQUENCE_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, GSS_C_SEQUENCE_FLAG)},
	{"GSS_C_CONF_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, GSS_C_CONF_FLAG)},
	{"GSS_C_INTEG_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, GSS_C_INTEG_FLAG)},
	{"GSS_C_ANON_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, GSS_C_ANON_FLAG)},
	{"GSS_C_PROT_READY_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, GSS_C_PROT_READY_FLAG)},
	{"GSS_C_TRANS_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, GSS_C_TRANS_FLAG)},
	{"NUM_OF_INQUIRE_VALUES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeGSSContext, NUM_OF_INQUIRE_VALUES)},
	{"pContext", "J", nullptr, $PRIVATE, $field(NativeGSSContext, pContext)},
	{"srcName", "Lsun/security/jgss/wrapper/GSSNameElement;", nullptr, $PRIVATE, $field(NativeGSSContext, srcName)},
	{"targetName", "Lsun/security/jgss/wrapper/GSSNameElement;", nullptr, $PRIVATE, $field(NativeGSSContext, targetName)},
	{"isInitiator", "Z", nullptr, $PRIVATE, $field(NativeGSSContext, isInitiator$)},
	{"isEstablished", "Z", nullptr, $PRIVATE, $field(NativeGSSContext, isEstablished$)},
	{"delegatedCred", "Lsun/security/jgss/wrapper/GSSCredElement;", nullptr, $PRIVATE, $field(NativeGSSContext, delegatedCred)},
	{"flags", "I", nullptr, $PRIVATE, $field(NativeGSSContext, flags)},
	{"lifetime", "I", nullptr, $PRIVATE, $field(NativeGSSContext, lifetime)},
	{"actualMech", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(NativeGSSContext, actualMech)},
	{"cred", "Lsun/security/jgss/wrapper/GSSCredElement;", nullptr, $PRIVATE, $field(NativeGSSContext, cred)},
	{"disposeCred", "Lsun/security/jgss/wrapper/GSSCredElement;", nullptr, $PRIVATE, $field(NativeGSSContext, disposeCred)},
	{"cb", "Lorg/ietf/jgss/ChannelBinding;", nullptr, $PRIVATE, $field(NativeGSSContext, cb)},
	{"disposeDelegatedCred", "Lsun/security/jgss/wrapper/GSSCredElement;", nullptr, $PRIVATE, $field(NativeGSSContext, disposeDelegatedCred)},
	{"cStub", "Lsun/security/jgss/wrapper/GSSLibStub;", nullptr, $PRIVATE | $FINAL, $field(NativeGSSContext, cStub)},
	{"skipDelegPermCheck", "Z", nullptr, $PRIVATE, $field(NativeGSSContext, skipDelegPermCheck)},
	{"skipServicePermCheck", "Z", nullptr, $PRIVATE, $field(NativeGSSContext, skipServicePermCheck)},
	{}
};

$MethodInfo _NativeGSSContext_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/wrapper/GSSNameElement;Lsun/security/jgss/wrapper/GSSCredElement;ILsun/security/jgss/wrapper/GSSLibStub;)V", nullptr, 0, $method(static_cast<void(NativeGSSContext::*)($GSSNameElement*,$GSSCredElement*,int32_t,$GSSLibStub*)>(&NativeGSSContext::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/wrapper/GSSCredElement;Lsun/security/jgss/wrapper/GSSLibStub;)V", nullptr, 0, $method(static_cast<void(NativeGSSContext::*)($GSSCredElement*,$GSSLibStub*)>(&NativeGSSContext::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(JLsun/security/jgss/wrapper/GSSLibStub;)V", nullptr, 0, $method(static_cast<void(NativeGSSContext::*)(int64_t,$GSSLibStub*)>(&NativeGSSContext::init$)), "org.ietf.jgss.GSSException"},
	{"acceptSecContext", "(Ljava/io/InputStream;I)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"changeFlags", "(IZ)V", nullptr, $PRIVATE, $method(static_cast<void(NativeGSSContext::*)(int32_t,bool)>(&NativeGSSContext::changeFlags))},
	{"checkFlags", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(NativeGSSContext::*)(int32_t)>(&NativeGSSContext::checkFlags))},
	{"dispose", "()V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"doDelegPermCheck", "()V", nullptr, $PRIVATE, $method(static_cast<void(NativeGSSContext::*)()>(&NativeGSSContext::doDelegPermCheck)), "org.ietf.jgss.GSSException"},
	{"doServicePermCheck", "()V", nullptr, $PRIVATE, $method(static_cast<void(NativeGSSContext::*)()>(&NativeGSSContext::doServicePermCheck)), "org.ietf.jgss.GSSException"},
	{"export", "()[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"finalize", "()V", nullptr, $PROTECTED, nullptr, "java.lang.Throwable"},
	{"getAnonymityState", "()Z", nullptr, $PUBLIC},
	{"getConfState", "()Z", nullptr, $PUBLIC},
	{"getCredDelegState", "()Z", nullptr, $PUBLIC},
	{"getDelegCred", "()Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getDelegPolicyState", "()Z", nullptr, $PUBLIC},
	{"getIntegState", "()Z", nullptr, $PUBLIC},
	{"getLifetime", "()I", nullptr, $PUBLIC},
	{"getMIC", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMIC", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMech", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechFromSpNegoToken", "([BZ)Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Oid*(*)($bytes*,bool)>(&NativeGSSContext::getMechFromSpNegoToken)), "org.ietf.jgss.GSSException"},
	{"getMutualAuthState", "()Z", nullptr, $PUBLIC},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC},
	{"getReplayDetState", "()Z", nullptr, $PUBLIC},
	{"getSequenceDetState", "()Z", nullptr, $PUBLIC},
	{"getSrcName", "()Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getTargName", "()Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getWrapSizeLimit", "(IZI)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"initSecContext", "(Ljava/io/InputStream;I)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"inquireSecContext", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isEstablished", "()Z", nullptr, $PUBLIC},
	{"isInitiator", "()Z", nullptr, $PUBLIC},
	{"isProtReady", "()Z", nullptr, $PUBLIC},
	{"isTransferable", "()Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestAnonymity", "(Z)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestConf", "(Z)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestCredDeleg", "(Z)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestDelegPolicy", "(Z)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestInteg", "(Z)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestLifetime", "(I)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestMutualAuth", "(Z)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestReplayDet", "(Z)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestSequenceDet", "(Z)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"retrieveToken", "(Ljava/io/InputStream;I)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(NativeGSSContext::*)($InputStream*,int32_t)>(&NativeGSSContext::retrieveToken)), "org.ietf.jgss.GSSException"},
	{"setChannelBinding", "(Lorg/ietf/jgss/ChannelBinding;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "([BII[BILorg/ietf/jgss/MessageProp;)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "(Ljava/io/InputStream;[BILorg/ietf/jgss/MessageProp;)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"verifyMIC", "([BII[BIILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"verifyMIC", "(Ljava/io/InputStream;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "([BIILjava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "([BII[BILorg/ietf/jgss/MessageProp;)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _NativeGSSContext_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.wrapper.NativeGSSContext",
	"java.lang.Object",
	"sun.security.jgss.spi.GSSContextSpi",
	_NativeGSSContext_FieldInfo_,
	_NativeGSSContext_MethodInfo_
};

$Object* allocate$NativeGSSContext($Class* clazz) {
	return $of($alloc(NativeGSSContext));
}

bool NativeGSSContext::$assertionsDisabled = false;

$Oid* NativeGSSContext::getMechFromSpNegoToken($bytes* token, bool isInitiator) {
	$init(NativeGSSContext);
	$var($Oid, mech, nullptr);
	if (isInitiator) {
		$var($GSSHeader, header, nullptr);
		try {
			$assign(header, $new($GSSHeader, $$new($ByteArrayInputStream, token)));
		} catch ($IOException&) {
			$var($IOException, ioe, $catch());
			$throwNew($GSSExceptionImpl, $GSSException::FAILURE, static_cast<$Exception*>(ioe));
		}
		int32_t negTokenLen = $nc(header)->getMechTokenLength();
		$var($bytes, negToken, $new($bytes, negTokenLen));
		$System::arraycopy(token, $nc(token)->length - negTokenLen, negToken, 0, negToken->length);
		$var($NegTokenInit, ntok, $new($NegTokenInit, negToken));
		if (ntok->getMechToken() != nullptr) {
			$var($OidArray, mechList, ntok->getMechTypeList());
			$assign(mech, $nc(mechList)->get(0));
		}
	} else {
		$var($NegTokenTarg, ntok, $new($NegTokenTarg, token));
		$assign(mech, ntok->getSupportedMech());
	}
	return mech;
}

void NativeGSSContext::doServicePermCheck() {
	if ($System::getSecurityManager() != nullptr) {
		$var($String, action, this->isInitiator$ ? "initiate"_s : "accept"_s);
		if ($GSSUtil::isSpNegoMech($($nc(this->cStub)->getMech())) && this->isInitiator$ && !this->isEstablished$) {
			if (this->srcName == nullptr) {
				$init($GSSUtil);
				$var($GSSCredElement, tempCred, $new($GSSCredElement, nullptr, this->lifetime, $GSSCredential::INITIATE_ONLY, $($GSSLibStub::getInstance($GSSUtil::GSS_KRB5_MECH_OID))));
				tempCred->dispose();
			} else {
				$var($String, tgsName, $Krb5Util::getTGSName(this->srcName));
				$Krb5Util::checkServicePermission(tgsName, action);
			}
		}
		$var($String, targetStr, $nc(this->targetName)->getKrbName());
		$Krb5Util::checkServicePermission(targetStr, action);
		this->skipServicePermCheck = true;
	}
}

void NativeGSSContext::doDelegPermCheck() {
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($String, targetStr, $nc(this->targetName)->getKrbName());
		$var($String, tgsStr, $Krb5Util::getTGSName(this->targetName));
		$var($StringBuilder, sb, $new($StringBuilder, "\""_s));
		sb->append(targetStr)->append("\" \""_s);
		sb->append(tgsStr)->append(u'\"');
		$var($String, krbPrincPair, sb->toString());
		$SunNativeProvider::debug($$str({"Checking DelegationPermission ("_s, krbPrincPair, ")"_s}));
		$var($DelegationPermission, perm, $new($DelegationPermission, krbPrincPair));
		sm->checkPermission(perm);
		this->skipDelegPermCheck = true;
	}
}

$bytes* NativeGSSContext::retrieveToken($InputStream* is, int32_t mechTokenLen) {
	try {
		$var($bytes, result, nullptr);
		if (mechTokenLen != -1) {
			$SunNativeProvider::debug($$str({"Precomputed mechToken length: "_s, $$str(mechTokenLen)}));
			$var($GSSHeader, gssHeader, $new($GSSHeader, $($ObjectIdentifier::of($($nc($($nc(this->cStub)->getMech()))->toString()))), mechTokenLen));
			$var($ByteArrayOutputStream, baos, $new($ByteArrayOutputStream, 600));
			$var($bytes, mechToken, $new($bytes, mechTokenLen));
			int32_t len = $nc(is)->read(mechToken);
			if (!NativeGSSContext::$assertionsDisabled && !(mechTokenLen == len)) {
				$throwNew($AssertionError);
			}
			gssHeader->encode(baos);
			baos->write(mechToken);
			$assign(result, baos->toByteArray());
		} else {
			if (!NativeGSSContext::$assertionsDisabled && !(mechTokenLen == -1)) {
				$throwNew($AssertionError);
			}
			$var($DerValue, dv, $new($DerValue, is));
			$assign(result, dv->toByteArray());
		}
		$SunNativeProvider::debug($$str({"Complete Token length: "_s, $$str($nc(result)->length)}));
		return result;
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, static_cast<$Exception*>(ioe));
	}
	$shouldNotReachHere();
}

void NativeGSSContext::init$($GSSNameElement* peer, $GSSCredElement* myCred, int32_t time, $GSSLibStub* stub) {
	this->pContext = 0;
	this->lifetime = $GSSCredential::DEFAULT_LIFETIME;
	if (peer == nullptr) {
		$throwNew($GSSException, $GSSException::FAILURE, 1, "null peer"_s);
	}
	$set(this, cStub, stub);
	$set(this, cred, myCred);
	$set(this, disposeCred, nullptr);
	$set(this, targetName, peer);
	this->isInitiator$ = true;
	this->lifetime = time;
	if ($GSSUtil::isKerberosMech($($nc(this->cStub)->getMech()))) {
		doServicePermCheck();
		if (this->cred == nullptr) {
			$set(this, disposeCred, ($assignField(this, cred, $new($GSSCredElement, nullptr, this->lifetime, $GSSCredential::INITIATE_ONLY, this->cStub))));
		}
		$set(this, srcName, $cast($GSSNameElement, $nc(this->cred)->getName()));
	}
}

void NativeGSSContext::init$($GSSCredElement* myCred, $GSSLibStub* stub) {
	this->pContext = 0;
	this->lifetime = $GSSCredential::DEFAULT_LIFETIME;
	$set(this, cStub, stub);
	$set(this, cred, myCred);
	$set(this, disposeCred, nullptr);
	if (this->cred != nullptr) {
		$set(this, targetName, $cast($GSSNameElement, $nc(this->cred)->getName()));
	}
	this->isInitiator$ = false;
	if ($GSSUtil::isKerberosMech($($nc(this->cStub)->getMech())) && this->targetName != nullptr) {
		doServicePermCheck();
	}
}

void NativeGSSContext::init$(int64_t pCtxt, $GSSLibStub* stub) {
	this->pContext = 0;
	this->lifetime = $GSSCredential::DEFAULT_LIFETIME;
	if (!NativeGSSContext::$assertionsDisabled && !(this->pContext != 0)) {
		$throwNew($AssertionError);
	}
	this->pContext = pCtxt;
	$set(this, cStub, stub);
	$var($longs, info, $nc(this->cStub)->inquireContext(this->pContext));
	if ($nc(info)->length != NativeGSSContext::NUM_OF_INQUIRE_VALUES) {
		$throwNew($RuntimeException, "Bug w/ GSSLibStub.inquireContext()"_s);
	}
	$set(this, srcName, $new($GSSNameElement, $nc(info)->get(0), this->cStub));
	$set(this, targetName, $new($GSSNameElement, $nc(info)->get(1), this->cStub));
	this->isInitiator$ = ($nc(info)->get(2) != 0);
	this->isEstablished$ = (info->get(3) != 0);
	this->flags = (int32_t)info->get(4);
	this->lifetime = (int32_t)info->get(5);
	$var($Oid, mech, $nc(this->cStub)->getMech());
	bool var$0 = $GSSUtil::isSpNegoMech(mech);
	if (var$0 || $GSSUtil::isKerberosMech(mech)) {
		doServicePermCheck();
	}
}

$Provider* NativeGSSContext::getProvider() {
	$init($SunNativeProvider);
	return $SunNativeProvider::INSTANCE;
}

$bytes* NativeGSSContext::initSecContext($InputStream* is, int32_t mechTokenLen) {
	$var($bytes, outToken, nullptr);
	if ((!this->isEstablished$) && (this->isInitiator$)) {
		$var($bytes, inToken, nullptr);
		if (this->pContext != 0) {
			$assign(inToken, retrieveToken(is, mechTokenLen));
			$SunNativeProvider::debug($$str({"initSecContext=> inToken len="_s, $$str($nc(inToken)->length)}));
		}
		if (!getCredDelegState()) {
			this->skipDelegPermCheck = true;
		}
		if ($GSSUtil::isKerberosMech($($nc(this->cStub)->getMech())) && !this->skipDelegPermCheck) {
			doDelegPermCheck();
		}
		int64_t pCred = (this->cred == nullptr ? (int64_t)0 : $nc(this->cred)->pCred);
		$assign(outToken, $nc(this->cStub)->initContext(pCred, $nc(this->targetName)->pName, this->cb, inToken, this));
		$SunNativeProvider::debug($$str({"initSecContext=> outToken len="_s, $$str((outToken == nullptr ? 0 : $nc(outToken)->length))}));
		if ($GSSUtil::isSpNegoMech($($nc(this->cStub)->getMech())) && outToken != nullptr) {
			$set(this, actualMech, getMechFromSpNegoToken(outToken, true));
			if ($GSSUtil::isKerberosMech(this->actualMech)) {
				if (!this->skipServicePermCheck) {
					doServicePermCheck();
				}
				if (!this->skipDelegPermCheck) {
					doDelegPermCheck();
				}
			}
		}
		if (this->isEstablished$) {
			if (this->srcName == nullptr) {
				$set(this, srcName, $new($GSSNameElement, $nc(this->cStub)->getContextName(this->pContext, true), this->cStub));
			}
			if (this->cred == nullptr) {
				$set(this, disposeCred, ($assignField(this, cred, $new($GSSCredElement, this->srcName, this->lifetime, $GSSCredential::INITIATE_ONLY, this->cStub))));
			}
		}
	}
	return outToken;
}

$bytes* NativeGSSContext::acceptSecContext($InputStream* is, int32_t mechTokenLen) {
	$var($bytes, outToken, nullptr);
	if ((!this->isEstablished$) && (!this->isInitiator$)) {
		$var($bytes, inToken, retrieveToken(is, mechTokenLen));
		$SunNativeProvider::debug($$str({"acceptSecContext=> inToken len="_s, $$str($nc(inToken)->length)}));
		int64_t pCred = (this->cred == nullptr ? (int64_t)0 : $nc(this->cred)->pCred);
		$assign(outToken, $nc(this->cStub)->acceptContext(pCred, this->cb, inToken, this));
		$set(this, disposeDelegatedCred, this->delegatedCred);
		$SunNativeProvider::debug($$str({"acceptSecContext=> outToken len="_s, $$str((outToken == nullptr ? 0 : $nc(outToken)->length))}));
		if (this->targetName == nullptr) {
			$set(this, targetName, $new($GSSNameElement, $nc(this->cStub)->getContextName(this->pContext, false), this->cStub));
			if (this->disposeCred != nullptr) {
				$nc(this->disposeCred)->dispose();
			}
			$set(this, disposeCred, ($assignField(this, cred, $new($GSSCredElement, this->targetName, this->lifetime, $GSSCredential::ACCEPT_ONLY, this->cStub))));
		}
		if ($GSSUtil::isSpNegoMech($($nc(this->cStub)->getMech())) && (outToken != nullptr) && !this->skipServicePermCheck) {
			if ($GSSUtil::isKerberosMech($(getMechFromSpNegoToken(outToken, false)))) {
				doServicePermCheck();
			}
		}
	}
	return outToken;
}

bool NativeGSSContext::isEstablished() {
	return this->isEstablished$;
}

void NativeGSSContext::dispose() {
	if (this->disposeCred != nullptr) {
		$nc(this->disposeCred)->dispose();
	}
	if (this->disposeDelegatedCred != nullptr) {
		$nc(this->disposeDelegatedCred)->dispose();
	}
	$set(this, disposeDelegatedCred, ($assignField(this, disposeCred, ($assignField(this, cred, nullptr)))));
	$set(this, srcName, nullptr);
	$set(this, targetName, nullptr);
	$set(this, delegatedCred, nullptr);
	if (this->pContext != 0) {
		this->pContext = $nc(this->cStub)->deleteContext(this->pContext);
		this->pContext = 0;
	}
}

int32_t NativeGSSContext::getWrapSizeLimit(int32_t qop, bool confReq, int32_t maxTokenSize) {
	return $nc(this->cStub)->wrapSizeLimit(this->pContext, (confReq ? 1 : 0), qop, maxTokenSize);
}

$bytes* NativeGSSContext::wrap($bytes* inBuf, int32_t offset, int32_t len, $MessageProp* msgProp) {
	$var($bytes, data, inBuf);
	if ((offset != 0) || (len != $nc(inBuf)->length)) {
		$assign(data, $new($bytes, len));
		$System::arraycopy(inBuf, offset, data, 0, len);
	}
	return $nc(this->cStub)->wrap(this->pContext, data, msgProp);
}

void NativeGSSContext::wrap($bytes* inBuf, int32_t offset, int32_t len, $OutputStream* os, $MessageProp* msgProp) {
	try {
		$var($bytes, result, wrap(inBuf, offset, len, msgProp));
		$nc(os)->write(result);
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, static_cast<$Exception*>(ioe));
	}
}

int32_t NativeGSSContext::wrap($bytes* inBuf, int32_t inOffset, int32_t len, $bytes* outBuf, int32_t outOffset, $MessageProp* msgProp) {
	$var($bytes, result, wrap(inBuf, inOffset, len, msgProp));
	$System::arraycopy(result, 0, outBuf, outOffset, $nc(result)->length);
	return $nc(result)->length;
}

void NativeGSSContext::wrap($InputStream* inStream, $OutputStream* outStream, $MessageProp* msgProp) {
	try {
		$var($bytes, data, $new($bytes, $nc(inStream)->available()));
		int32_t length = inStream->read(data);
		$var($bytes, token, wrap(data, 0, length, msgProp));
		$nc(outStream)->write(token);
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, static_cast<$Exception*>(ioe));
	}
}

$bytes* NativeGSSContext::unwrap($bytes* inBuf, int32_t offset, int32_t len, $MessageProp* msgProp) {
	if ((offset != 0) || (len != $nc(inBuf)->length)) {
		$var($bytes, temp, $new($bytes, len));
		$System::arraycopy(inBuf, offset, temp, 0, len);
		return $nc(this->cStub)->unwrap(this->pContext, temp, msgProp);
	} else {
		return $nc(this->cStub)->unwrap(this->pContext, inBuf, msgProp);
	}
}

int32_t NativeGSSContext::unwrap($bytes* inBuf, int32_t inOffset, int32_t len, $bytes* outBuf, int32_t outOffset, $MessageProp* msgProp) {
	$var($bytes, result, nullptr);
	if ((inOffset != 0) || (len != $nc(inBuf)->length)) {
		$var($bytes, temp, $new($bytes, len));
		$System::arraycopy(inBuf, inOffset, temp, 0, len);
		$assign(result, $nc(this->cStub)->unwrap(this->pContext, temp, msgProp));
	} else {
		$assign(result, $nc(this->cStub)->unwrap(this->pContext, inBuf, msgProp));
	}
	$System::arraycopy(result, 0, outBuf, outOffset, $nc(result)->length);
	return $nc(result)->length;
}

void NativeGSSContext::unwrap($InputStream* inStream, $OutputStream* outStream, $MessageProp* msgProp) {
	try {
		$var($bytes, wrapped, $new($bytes, $nc(inStream)->available()));
		int32_t wLength = inStream->read(wrapped);
		$var($bytes, data, unwrap(wrapped, 0, wLength, msgProp));
		$nc(outStream)->write(data);
		outStream->flush();
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, static_cast<$Exception*>(ioe));
	}
}

int32_t NativeGSSContext::unwrap($InputStream* inStream, $bytes* outBuf, int32_t outOffset, $MessageProp* msgProp) {
	$var($bytes, wrapped, nullptr);
	int32_t wLength = 0;
	try {
		$assign(wrapped, $new($bytes, $nc(inStream)->available()));
		wLength = inStream->read(wrapped);
		$var($bytes, result, unwrap(wrapped, 0, wLength, msgProp));
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, static_cast<$Exception*>(ioe));
	}
	$var($bytes, result, unwrap(wrapped, 0, wLength, msgProp));
	$System::arraycopy(result, 0, outBuf, outOffset, $nc(result)->length);
	return $nc(result)->length;
}

$bytes* NativeGSSContext::getMIC($bytes* in, int32_t offset, int32_t len, $MessageProp* msgProp) {
	int32_t qop = (msgProp == nullptr ? 0 : $nc(msgProp)->getQOP());
	$var($bytes, inMsg, in);
	if ((offset != 0) || (len != $nc(in)->length)) {
		$assign(inMsg, $new($bytes, len));
		$System::arraycopy(in, offset, inMsg, 0, len);
	}
	return $nc(this->cStub)->getMic(this->pContext, qop, inMsg);
}

void NativeGSSContext::getMIC($InputStream* inStream, $OutputStream* outStream, $MessageProp* msgProp) {
	try {
		int32_t length = 0;
		$var($bytes, msg, $new($bytes, $nc(inStream)->available()));
		length = inStream->read(msg);
		$var($bytes, msgToken, getMIC(msg, 0, length, msgProp));
		if ((msgToken != nullptr) && msgToken->length != 0) {
			$nc(outStream)->write(msgToken);
		}
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, static_cast<$Exception*>(ioe));
	}
}

void NativeGSSContext::verifyMIC($bytes* inToken, int32_t tOffset, int32_t tLen, $bytes* inMsg, int32_t mOffset, int32_t mLen, $MessageProp* msgProp) {
	$var($bytes, token, inToken);
	$var($bytes, msg, inMsg);
	if ((tOffset != 0) || (tLen != $nc(inToken)->length)) {
		$assign(token, $new($bytes, tLen));
		$System::arraycopy(inToken, tOffset, token, 0, tLen);
	}
	if ((mOffset != 0) || (mLen != $nc(inMsg)->length)) {
		$assign(msg, $new($bytes, mLen));
		$System::arraycopy(inMsg, mOffset, msg, 0, mLen);
	}
	$nc(this->cStub)->verifyMic(this->pContext, token, msg, msgProp);
}

void NativeGSSContext::verifyMIC($InputStream* tokStream, $InputStream* msgStream, $MessageProp* msgProp) {
	try {
		$var($bytes, msg, $new($bytes, $nc(msgStream)->available()));
		int32_t mLength = msgStream->read(msg);
		$var($bytes, tok, $new($bytes, $nc(tokStream)->available()));
		int32_t tLength = tokStream->read(tok);
		verifyMIC(tok, 0, tLength, msg, 0, mLength, msgProp);
	} catch ($IOException&) {
		$var($IOException, ioe, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, static_cast<$Exception*>(ioe));
	}
}

$bytes* NativeGSSContext::export$() {
	$var($bytes, result, $nc(this->cStub)->exportContext(this->pContext));
	this->pContext = 0;
	return result;
}

void NativeGSSContext::changeFlags(int32_t flagMask, bool isEnable) {
	if (this->isInitiator$ && this->pContext == 0) {
		if (isEnable) {
			this->flags |= flagMask;
		} else {
			this->flags &= (uint32_t)~flagMask;
		}
	}
}

void NativeGSSContext::requestMutualAuth(bool state) {
	changeFlags(NativeGSSContext::GSS_C_MUTUAL_FLAG, state);
}

void NativeGSSContext::requestReplayDet(bool state) {
	changeFlags(NativeGSSContext::GSS_C_REPLAY_FLAG, state);
}

void NativeGSSContext::requestSequenceDet(bool state) {
	changeFlags(NativeGSSContext::GSS_C_SEQUENCE_FLAG, state);
}

void NativeGSSContext::requestCredDeleg(bool state) {
	changeFlags(NativeGSSContext::GSS_C_DELEG_FLAG, state);
}

void NativeGSSContext::requestAnonymity(bool state) {
	changeFlags(NativeGSSContext::GSS_C_ANON_FLAG, state);
}

void NativeGSSContext::requestConf(bool state) {
	changeFlags(NativeGSSContext::GSS_C_CONF_FLAG, state);
}

void NativeGSSContext::requestInteg(bool state) {
	changeFlags(NativeGSSContext::GSS_C_INTEG_FLAG, state);
}

void NativeGSSContext::requestDelegPolicy(bool state) {
}

void NativeGSSContext::requestLifetime(int32_t lifetime) {
	if (this->isInitiator$ && this->pContext == 0) {
		this->lifetime = lifetime;
	}
}

void NativeGSSContext::setChannelBinding($ChannelBinding* cb) {
	if (this->pContext == 0) {
		$set(this, cb, cb);
	}
}

bool NativeGSSContext::checkFlags(int32_t flagMask) {
	return (((int32_t)(this->flags & (uint32_t)flagMask)) != 0);
}

bool NativeGSSContext::getCredDelegState() {
	return checkFlags(NativeGSSContext::GSS_C_DELEG_FLAG);
}

bool NativeGSSContext::getMutualAuthState() {
	return checkFlags(NativeGSSContext::GSS_C_MUTUAL_FLAG);
}

bool NativeGSSContext::getReplayDetState() {
	return checkFlags(NativeGSSContext::GSS_C_REPLAY_FLAG);
}

bool NativeGSSContext::getSequenceDetState() {
	return checkFlags(NativeGSSContext::GSS_C_SEQUENCE_FLAG);
}

bool NativeGSSContext::getAnonymityState() {
	return checkFlags(NativeGSSContext::GSS_C_ANON_FLAG);
}

bool NativeGSSContext::isTransferable() {
	return checkFlags(NativeGSSContext::GSS_C_TRANS_FLAG);
}

bool NativeGSSContext::isProtReady() {
	return checkFlags(NativeGSSContext::GSS_C_PROT_READY_FLAG);
}

bool NativeGSSContext::getConfState() {
	return checkFlags(NativeGSSContext::GSS_C_CONF_FLAG);
}

bool NativeGSSContext::getIntegState() {
	return checkFlags(NativeGSSContext::GSS_C_INTEG_FLAG);
}

bool NativeGSSContext::getDelegPolicyState() {
	return false;
}

int32_t NativeGSSContext::getLifetime() {
	return $nc(this->cStub)->getContextTime(this->pContext);
}

$GSSNameSpi* NativeGSSContext::getSrcName() {
	return this->srcName;
}

$GSSNameSpi* NativeGSSContext::getTargName() {
	return this->targetName;
}

$Oid* NativeGSSContext::getMech() {
	if (this->isEstablished$ && this->actualMech != nullptr) {
		return this->actualMech;
	} else {
		return $nc(this->cStub)->getMech();
	}
}

$GSSCredentialSpi* NativeGSSContext::getDelegCred() {
	$set(this, disposeDelegatedCred, nullptr);
	return this->delegatedCred;
}

bool NativeGSSContext::isInitiator() {
	return this->isInitiator$;
}

void NativeGSSContext::finalize() {
	dispose();
}

$Object* NativeGSSContext::inquireSecContext($String* type) {
	$throwNew($GSSException, $GSSException::UNAVAILABLE, -1, "Inquire type not supported."_s);
	$shouldNotReachHere();
}

void clinit$NativeGSSContext($Class* class$) {
	NativeGSSContext::$assertionsDisabled = !NativeGSSContext::class$->desiredAssertionStatus();
}

NativeGSSContext::NativeGSSContext() {
}

$Class* NativeGSSContext::load$($String* name, bool initialize) {
	$loadClass(NativeGSSContext, name, initialize, &_NativeGSSContext_ClassInfo_, clinit$NativeGSSContext, allocate$NativeGSSContext);
	return class$;
}

$Class* NativeGSSContext::class$ = nullptr;

			} // wrapper
		} // jgss
	} // security
} // sun