#include <sun/security/jgss/spnego/SpNegoContext.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/CompoundAttribute.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NamedAttribute.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/GSSContext.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/MessageProp.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/jgss/GSSContextImpl.h>
#include <sun/security/jgss/GSSCredentialImpl.h>
#include <sun/security/jgss/GSSManagerImpl.h>
#include <sun/security/jgss/GSSNameImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/spnego/NegTokenInit.h>
#include <sun/security/jgss/spnego/NegTokenTarg.h>
#include <sun/security/jgss/spnego/SpNegoCredElement.h>
#include <sun/security/jgss/spnego/SpNegoMechFactory.h>
#include <sun/security/jgss/spnego/SpNegoToken$NegoResult.h>
#include <sun/security/jgss/spnego/SpNegoToken.h>
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef ACCEPT_COMPLETE
#undef ACCEPT_INCOMPLETE
#undef BAD_MECH
#undef DEBUG
#undef DEFAULT_LIFETIME
#undef DEFECTIVE_TOKEN
#undef FAILURE
#undef GSS_SPNEGO_MECH_OID
#undef INDEFINITE_LIFETIME
#undef INITIATE_ONLY
#undef NO_CONTEXT
#undef NO_CRED
#undef PROVIDER
#undef REJECT
#undef STATE_DELETED
#undef STATE_DONE
#undef STATE_IN_PROCESS
#undef STATE_NEW
#undef UNAVAILABLE

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $Provider = ::java::security::Provider;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;
using $GSSContext = ::org::ietf::jgss::GSSContext;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSName = ::org::ietf::jgss::GSSName;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $Oid = ::org::ietf::jgss::Oid;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $GSSContextImpl = ::sun::security::jgss::GSSContextImpl;
using $GSSCredentialImpl = ::sun::security::jgss::GSSCredentialImpl;
using $GSSManagerImpl = ::sun::security::jgss::GSSManagerImpl;
using $GSSNameImpl = ::sun::security::jgss::GSSNameImpl;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $GSSContextSpi = ::sun::security::jgss::spi::GSSContextSpi;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $NegTokenInit = ::sun::security::jgss::spnego::NegTokenInit;
using $NegTokenTarg = ::sun::security::jgss::spnego::NegTokenTarg;
using $SpNegoCredElement = ::sun::security::jgss::spnego::SpNegoCredElement;
using $SpNegoMechFactory = ::sun::security::jgss::spnego::SpNegoMechFactory;
using $SpNegoToken = ::sun::security::jgss::spnego::SpNegoToken;
using $SpNegoToken$NegoResult = ::sun::security::jgss::spnego::SpNegoToken$NegoResult;
using $BitArray = ::sun::security::util::BitArray;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

$NamedAttribute SpNegoContext_Attribute_var$0[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _SpNegoContext_MethodAnnotations_acceptSecContext5[] = {
	{"Ljava/lang/Deprecated;", SpNegoContext_Attribute_var$0},
	{}
};

$NamedAttribute SpNegoContext_Attribute_var$1[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _SpNegoContext_MethodAnnotations_getMIC20[] = {
	{"Ljava/lang/Deprecated;", SpNegoContext_Attribute_var$1},
	{}
};

$NamedAttribute SpNegoContext_Attribute_var$2[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _SpNegoContext_MethodAnnotations_initSecContext30[] = {
	{"Ljava/lang/Deprecated;", SpNegoContext_Attribute_var$2},
	{}
};

$NamedAttribute SpNegoContext_Attribute_var$3[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _SpNegoContext_MethodAnnotations_unwrap51[] = {
	{"Ljava/lang/Deprecated;", SpNegoContext_Attribute_var$3},
	{}
};

$NamedAttribute SpNegoContext_Attribute_var$4[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _SpNegoContext_MethodAnnotations_verifyMIC53[] = {
	{"Ljava/lang/Deprecated;", SpNegoContext_Attribute_var$4},
	{}
};

$NamedAttribute SpNegoContext_Attribute_var$5[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _SpNegoContext_MethodAnnotations_wrap56[] = {
	{"Ljava/lang/Deprecated;", SpNegoContext_Attribute_var$5},
	{}
};

$FieldInfo _SpNegoContext_FieldInfo_[] = {
	{"STATE_NEW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SpNegoContext, STATE_NEW)},
	{"STATE_IN_PROCESS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SpNegoContext, STATE_IN_PROCESS)},
	{"STATE_DONE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SpNegoContext, STATE_DONE)},
	{"STATE_DELETED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SpNegoContext, STATE_DELETED)},
	{"state", "I", nullptr, $PRIVATE, $field(SpNegoContext, state)},
	{"credDelegState", "Z", nullptr, $PRIVATE, $field(SpNegoContext, credDelegState)},
	{"mutualAuthState", "Z", nullptr, $PRIVATE, $field(SpNegoContext, mutualAuthState)},
	{"replayDetState", "Z", nullptr, $PRIVATE, $field(SpNegoContext, replayDetState)},
	{"sequenceDetState", "Z", nullptr, $PRIVATE, $field(SpNegoContext, sequenceDetState)},
	{"confState", "Z", nullptr, $PRIVATE, $field(SpNegoContext, confState)},
	{"integState", "Z", nullptr, $PRIVATE, $field(SpNegoContext, integState)},
	{"delegPolicyState", "Z", nullptr, $PRIVATE, $field(SpNegoContext, delegPolicyState)},
	{"peerName", "Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PRIVATE, $field(SpNegoContext, peerName)},
	{"myName", "Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PRIVATE, $field(SpNegoContext, myName)},
	{"myCred", "Lsun/security/jgss/spnego/SpNegoCredElement;", nullptr, $PRIVATE, $field(SpNegoContext, myCred)},
	{"mechContext", "Lorg/ietf/jgss/GSSContext;", nullptr, $PRIVATE, $field(SpNegoContext, mechContext)},
	{"DER_mechTypes", "[B", nullptr, $PRIVATE, $field(SpNegoContext, DER_mechTypes)},
	{"lifetime", "I", nullptr, $PRIVATE, $field(SpNegoContext, lifetime)},
	{"channelBinding", "Lorg/ietf/jgss/ChannelBinding;", nullptr, $PRIVATE, $field(SpNegoContext, channelBinding)},
	{"initiator", "Z", nullptr, $PRIVATE, $field(SpNegoContext, initiator)},
	{"internal_mech", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(SpNegoContext, internal_mech)},
	{"factory", "Lsun/security/jgss/spnego/SpNegoMechFactory;", nullptr, $PRIVATE | $FINAL, $field(SpNegoContext, factory)},
	{"DEBUG", "Z", nullptr, $STATIC | $FINAL, $staticField(SpNegoContext, DEBUG)},
	{}
};

$MethodInfo _SpNegoContext_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/spnego/SpNegoMechFactory;Lsun/security/jgss/spi/GSSNameSpi;Lsun/security/jgss/spi/GSSCredentialSpi;I)V", nullptr, $PUBLIC, $method(static_cast<void(SpNegoContext::*)($SpNegoMechFactory*,$GSSNameSpi*,$GSSCredentialSpi*,int32_t)>(&SpNegoContext::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/spnego/SpNegoMechFactory;Lsun/security/jgss/spi/GSSCredentialSpi;)V", nullptr, $PUBLIC, $method(static_cast<void(SpNegoContext::*)($SpNegoMechFactory*,$GSSCredentialSpi*)>(&SpNegoContext::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/spnego/SpNegoMechFactory;[B)V", nullptr, $PUBLIC, $method(static_cast<void(SpNegoContext::*)($SpNegoMechFactory*,$bytes*)>(&SpNegoContext::init$)), "org.ietf.jgss.GSSException"},
	{"GSS_acceptSecContext", "([B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(SpNegoContext::*)($bytes*)>(&SpNegoContext::GSS_acceptSecContext)), "org.ietf.jgss.GSSException"},
	{"GSS_initSecContext", "([B)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(SpNegoContext::*)($bytes*)>(&SpNegoContext::GSS_initSecContext)), "org.ietf.jgss.GSSException"},
	{"acceptSecContext", "(Ljava/io/InputStream;I)[B", nullptr, $PUBLIC | $FINAL | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _SpNegoContext_MethodAnnotations_acceptSecContext5},
	{"dispose", "()V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"export", "()[B", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"getAnonymityState", "()Z", nullptr, $PUBLIC | $FINAL},
	{"getAvailableMechs", "()[Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $method(static_cast<$OidArray*(SpNegoContext::*)()>(&SpNegoContext::getAvailableMechs))},
	{"getChannelBinding", "()Lorg/ietf/jgss/ChannelBinding;", nullptr, $FINAL, $method(static_cast<$ChannelBinding*(SpNegoContext::*)()>(&SpNegoContext::getChannelBinding))},
	{"getConfState", "()Z", nullptr, $PUBLIC | $FINAL},
	{"getContextFlags", "()Lsun/security/util/BitArray;", nullptr, $PRIVATE, $method(static_cast<$BitArray*(SpNegoContext::*)()>(&SpNegoContext::getContextFlags))},
	{"getCredDelegState", "()Z", nullptr, $PUBLIC | $FINAL},
	{"getDelegCred", "()Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"getDelegPolicyState", "()Z", nullptr, $PUBLIC | $FINAL},
	{"getEncodedMechs", "([Lorg/ietf/jgss/Oid;)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(SpNegoContext::*)($OidArray*)>(&SpNegoContext::getEncodedMechs)), "java.io.IOException,org.ietf.jgss.GSSException"},
	{"getIntegState", "()Z", nullptr, $PUBLIC | $FINAL},
	{"getLifetime", "()I", nullptr, $PUBLIC | $FINAL},
	{"getMIC", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"getMIC", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $FINAL | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _SpNegoContext_MethodAnnotations_getMIC20},
	{"getMech", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $FINAL},
	{"getMutualAuthState", "()Z", nullptr, $PUBLIC | $FINAL},
	{"getNegotiatedMech", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Oid*(SpNegoContext::*)()>(&SpNegoContext::getNegotiatedMech))},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $FINAL},
	{"getReplayDetState", "()Z", nullptr, $PUBLIC | $FINAL},
	{"getSequenceDetState", "()Z", nullptr, $PUBLIC | $FINAL},
	{"getSrcName", "()Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"getTargName", "()Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"getWrapSizeLimit", "(IZI)I", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"initSecContext", "(Ljava/io/InputStream;I)[B", nullptr, $PUBLIC | $FINAL | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _SpNegoContext_MethodAnnotations_initSecContext30},
	{"inquireSecContext", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isEstablished", "()Z", nullptr, $PUBLIC | $FINAL},
	{"isInitiator", "()Z", nullptr, $PUBLIC | $FINAL},
	{"isMechContextEstablished", "()Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(SpNegoContext::*)()>(&SpNegoContext::isMechContextEstablished))},
	{"isProtReady", "()Z", nullptr, $PUBLIC | $FINAL},
	{"isTransferable", "()Z", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"negotiate_mech_type", "([Lorg/ietf/jgss/Oid;[Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Oid*(*)($OidArray*,$OidArray*)>(&SpNegoContext::negotiate_mech_type))},
	{"printState", "(I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)(int32_t)>(&SpNegoContext::printState))},
	{"requestAnonymity", "(Z)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"requestConf", "(Z)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"requestCredDeleg", "(Z)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"requestDelegPolicy", "(Z)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"requestInteg", "(Z)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"requestLifetime", "(I)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"requestMutualAuth", "(Z)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"requestReplayDet", "(Z)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"requestSequenceDet", "(Z)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"setChannelBinding", "(Lorg/ietf/jgss/ChannelBinding;)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"setContextFlags", "()V", nullptr, $PRIVATE, $method(static_cast<void(SpNegoContext::*)()>(&SpNegoContext::setContextFlags))},
	{"unwrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $FINAL | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _SpNegoContext_MethodAnnotations_unwrap51},
	{"verifyMIC", "([BII[BIILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"verifyMIC", "(Ljava/io/InputStream;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $FINAL | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _SpNegoContext_MethodAnnotations_verifyMIC53},
	{"verifyMechListMIC", "([B[B)Z", nullptr, $PRIVATE, $method(static_cast<bool(SpNegoContext::*)($bytes*,$bytes*)>(&SpNegoContext::verifyMechListMIC)), "org.ietf.jgss.GSSException"},
	{"wrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC | $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $FINAL | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _SpNegoContext_MethodAnnotations_wrap56},
	{}
};

$ClassInfo _SpNegoContext_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.spnego.SpNegoContext",
	"java.lang.Object",
	"sun.security.jgss.spi.GSSContextSpi",
	_SpNegoContext_FieldInfo_,
	_SpNegoContext_MethodInfo_
};

$Object* allocate$SpNegoContext($Class* clazz) {
	return $of($alloc(SpNegoContext));
}

bool SpNegoContext::DEBUG = false;

void SpNegoContext::init$($SpNegoMechFactory* factory, $GSSNameSpi* peerName, $GSSCredentialSpi* myCred, int32_t lifetime) {
	this->state = SpNegoContext::STATE_NEW;
	this->credDelegState = false;
	this->mutualAuthState = true;
	this->replayDetState = true;
	this->sequenceDetState = true;
	this->confState = true;
	this->integState = true;
	this->delegPolicyState = false;
	$set(this, peerName, nullptr);
	$set(this, myName, nullptr);
	$set(this, myCred, nullptr);
	$set(this, mechContext, nullptr);
	$set(this, DER_mechTypes, nullptr);
	$set(this, internal_mech, nullptr);
	if (peerName == nullptr) {
		$throwNew($IllegalArgumentException, "Cannot have null peer name"_s);
	}
	if ((myCred != nullptr) && !($instanceOf($SpNegoCredElement, myCred))) {
		$throwNew($IllegalArgumentException, "Wrong cred element type"_s);
	}
	$set(this, peerName, peerName);
	$set(this, myCred, $cast($SpNegoCredElement, myCred));
	this->lifetime = lifetime;
	this->initiator = true;
	$set(this, factory, factory);
}

void SpNegoContext::init$($SpNegoMechFactory* factory, $GSSCredentialSpi* myCred) {
	this->state = SpNegoContext::STATE_NEW;
	this->credDelegState = false;
	this->mutualAuthState = true;
	this->replayDetState = true;
	this->sequenceDetState = true;
	this->confState = true;
	this->integState = true;
	this->delegPolicyState = false;
	$set(this, peerName, nullptr);
	$set(this, myName, nullptr);
	$set(this, myCred, nullptr);
	$set(this, mechContext, nullptr);
	$set(this, DER_mechTypes, nullptr);
	$set(this, internal_mech, nullptr);
	if ((myCred != nullptr) && !($instanceOf($SpNegoCredElement, myCred))) {
		$throwNew($IllegalArgumentException, "Wrong cred element type"_s);
	}
	$set(this, myCred, $cast($SpNegoCredElement, myCred));
	this->initiator = false;
	$set(this, factory, factory);
}

void SpNegoContext::init$($SpNegoMechFactory* factory, $bytes* interProcessToken) {
	this->state = SpNegoContext::STATE_NEW;
	this->credDelegState = false;
	this->mutualAuthState = true;
	this->replayDetState = true;
	this->sequenceDetState = true;
	this->confState = true;
	this->integState = true;
	this->delegPolicyState = false;
	$set(this, peerName, nullptr);
	$set(this, myName, nullptr);
	$set(this, myCred, nullptr);
	$set(this, mechContext, nullptr);
	$set(this, DER_mechTypes, nullptr);
	$set(this, internal_mech, nullptr);
	$throwNew($GSSException, $GSSException::UNAVAILABLE, -1, "GSS Import Context not available"_s);
}

void SpNegoContext::requestConf(bool value) {
	if (this->state == SpNegoContext::STATE_NEW && isInitiator()) {
		this->confState = value;
	}
}

bool SpNegoContext::getConfState() {
	return this->confState;
}

void SpNegoContext::requestInteg(bool value) {
	if (this->state == SpNegoContext::STATE_NEW && isInitiator()) {
		this->integState = value;
	}
}

void SpNegoContext::requestDelegPolicy(bool value) {
	if (this->state == SpNegoContext::STATE_NEW && isInitiator()) {
		this->delegPolicyState = value;
	}
}

bool SpNegoContext::getIntegState() {
	return this->integState;
}

bool SpNegoContext::getDelegPolicyState() {
	if (isInitiator() && this->mechContext != nullptr && $instanceOf($GSSContextImpl, this->mechContext) && (this->state == SpNegoContext::STATE_IN_PROCESS || this->state == SpNegoContext::STATE_DONE)) {
		return $nc(($cast($GSSContextImpl, this->mechContext)))->getDelegPolicyState();
	} else {
		return this->delegPolicyState;
	}
}

void SpNegoContext::requestCredDeleg(bool value) {
	if (this->state == SpNegoContext::STATE_NEW && isInitiator()) {
		this->credDelegState = value;
	}
}

bool SpNegoContext::getCredDelegState() {
	if (isInitiator() && this->mechContext != nullptr && (this->state == SpNegoContext::STATE_IN_PROCESS || this->state == SpNegoContext::STATE_DONE)) {
		return $nc(this->mechContext)->getCredDelegState();
	} else {
		return this->credDelegState;
	}
}

void SpNegoContext::requestMutualAuth(bool value) {
	if (this->state == SpNegoContext::STATE_NEW && isInitiator()) {
		this->mutualAuthState = value;
	}
}

bool SpNegoContext::getMutualAuthState() {
	return this->mutualAuthState;
}

$Oid* SpNegoContext::getMech() {
	if (isEstablished()) {
		return getNegotiatedMech();
	}
	$init($SpNegoMechFactory);
	return ($SpNegoMechFactory::GSS_SPNEGO_MECH_OID);
}

$Oid* SpNegoContext::getNegotiatedMech() {
	return (this->internal_mech);
}

$Provider* SpNegoContext::getProvider() {
	$init($SpNegoMechFactory);
	return $SpNegoMechFactory::PROVIDER;
}

void SpNegoContext::dispose() {
	$set(this, mechContext, nullptr);
	this->state = SpNegoContext::STATE_DELETED;
}

bool SpNegoContext::isInitiator() {
	return this->initiator;
}

bool SpNegoContext::isProtReady() {
	return (this->state == SpNegoContext::STATE_DONE);
}

$bytes* SpNegoContext::initSecContext($InputStream* is, int32_t mechTokenSize) {
	$var($bytes, retVal, nullptr);
	$var($NegTokenInit, initToken, nullptr);
	$var($bytes, mechToken, nullptr);
	int32_t errorCode = $GSSException::FAILURE;
	if (SpNegoContext::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"Entered SpNego.initSecContext with state="_s, $(printState(this->state))}));
	}
	if (!isInitiator()) {
		$throwNew($GSSException, $GSSException::FAILURE, -1, "initSecContext on an acceptor GSSContext"_s);
	}
	try {
		if (this->state == SpNegoContext::STATE_NEW) {
			this->state = SpNegoContext::STATE_IN_PROCESS;
			errorCode = $GSSException::NO_CRED;
			$var($OidArray, mechList, getAvailableMechs());
			$set(this, DER_mechTypes, getEncodedMechs(mechList));
			$set(this, internal_mech, $nc(mechList)->get(0));
			$assign(mechToken, GSS_initSecContext(nullptr));
			errorCode = $GSSException::DEFECTIVE_TOKEN;
			$assign(initToken, $new($NegTokenInit, this->DER_mechTypes, $(getContextFlags()), mechToken, nullptr));
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.initSecContext: sending token of type = "_s, $($SpNegoToken::getTokenName(initToken->getType()))}));
			}
			$assign(retVal, initToken->getEncoded());
		} else if (this->state == SpNegoContext::STATE_IN_PROCESS) {
			errorCode = $GSSException::FAILURE;
			if (is == nullptr) {
				$throwNew($GSSException, errorCode, -1, "No token received from peer!"_s);
			}
			errorCode = $GSSException::DEFECTIVE_TOKEN;
			$var($bytes, server_token, $new($bytes, $nc(is)->available()));
			$SpNegoToken::readFully(is, server_token);
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.initSecContext: process received token = "_s, $($SpNegoToken::getHexBytes(server_token))}));
			}
			$var($NegTokenTarg, targToken, $new($NegTokenTarg, server_token));
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.initSecContext: received token of type = "_s, $($SpNegoToken::getTokenName(targToken->getType()))}));
			}
			$set(this, internal_mech, targToken->getSupportedMech());
			if (this->internal_mech == nullptr) {
				$throwNew($GSSException, errorCode, -1, "supported mechanism from server is null"_s);
			}
			$SpNegoToken$NegoResult* negoResult = nullptr;
			int32_t result = targToken->getNegotiatedResult();
			switch (result) {
			case 0:
				{
					$init($SpNegoToken$NegoResult);
					negoResult = $SpNegoToken$NegoResult::ACCEPT_COMPLETE;
					this->state = SpNegoContext::STATE_DONE;
					break;
				}
			case 1:
				{
					$init($SpNegoToken$NegoResult);
					negoResult = $SpNegoToken$NegoResult::ACCEPT_INCOMPLETE;
					this->state = SpNegoContext::STATE_IN_PROCESS;
					break;
				}
			case 2:
				{
					$init($SpNegoToken$NegoResult);
					negoResult = $SpNegoToken$NegoResult::REJECT;
					this->state = SpNegoContext::STATE_DELETED;
					break;
				}
			default:
				{
					this->state = SpNegoContext::STATE_DONE;
					break;
				}
			}
			errorCode = $GSSException::BAD_MECH;
			$init($SpNegoToken$NegoResult);
			if (negoResult == $SpNegoToken$NegoResult::REJECT) {
				$throwNew($GSSException, errorCode, -1, $($nc(this->internal_mech)->toString()));
			}
			errorCode = $GSSException::DEFECTIVE_TOKEN;
			if ((negoResult == $SpNegoToken$NegoResult::ACCEPT_COMPLETE) || (negoResult == $SpNegoToken$NegoResult::ACCEPT_INCOMPLETE)) {
				$var($bytes, accept_token, targToken->getResponseToken());
				if (accept_token == nullptr) {
					if (!isMechContextEstablished()) {
						$throwNew($GSSException, errorCode, -1, "mechanism token from server is null"_s);
					}
				} else {
					$assign(mechToken, GSS_initSecContext(accept_token));
				}
				if (!$GSSUtil::useMSInterop()) {
					$var($bytes, micToken, targToken->getMechListMIC());
					if (!verifyMechListMIC(this->DER_mechTypes, micToken)) {
						$throwNew($GSSException, errorCode, -1, "verification of MIC on MechList Failed!"_s);
					}
				}
				if (isMechContextEstablished()) {
					this->state = SpNegoContext::STATE_DONE;
					$assign(retVal, mechToken);
					if (SpNegoContext::DEBUG) {
						$init($System);
						$var($String, var$0, $$str({"SPNEGO Negotiated Mechanism = "_s, this->internal_mech, " "_s}));
						$nc($System::out)->println($$concat(var$0, $($GSSUtil::getMechStr(this->internal_mech))));
					}
				} else {
					$assign(initToken, $new($NegTokenInit, nullptr, nullptr, mechToken, nullptr));
					if (SpNegoContext::DEBUG) {
						$init($System);
						$nc($System::out)->println($$str({"SpNegoContext.initSecContext: continue sending token of type = "_s, $($SpNegoToken::getTokenName(initToken->getType()))}));
					}
					$assign(retVal, initToken->getEncoded());
				}
			}
		} else if (SpNegoContext::DEBUG) {
			$init($System);
			$nc($System::out)->println(this->state);
		}
		if (SpNegoContext::DEBUG) {
			if (retVal != nullptr) {
				$init($System);
				$nc($System::out)->println($$str({"SNegoContext.initSecContext: sending token = "_s, $($SpNegoToken::getHexBytes(retVal))}));
			}
		}
	} catch ($GSSException&) {
		$var($GSSException, e, $catch());
		$var($GSSException, gssException, $new($GSSException, errorCode, -1, $(e->getMessage())));
		gssException->initCause(e);
		$throw(gssException);
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$var($GSSException, gssException, $new($GSSException, $GSSException::FAILURE, -1, $(e->getMessage())));
		gssException->initCause(e);
		$throw(gssException);
	}
	return retVal;
}

$bytes* SpNegoContext::acceptSecContext($InputStream* is, int32_t mechTokenSize) {
	$var($bytes, retVal, nullptr);
	$SpNegoToken$NegoResult* negoResult = nullptr;
	bool valid = true;
	if (SpNegoContext::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"Entered SpNegoContext.acceptSecContext with state="_s, $(printState(this->state))}));
	}
	if (isInitiator()) {
		$throwNew($GSSException, $GSSException::FAILURE, -1, "acceptSecContext on an initiator GSSContext"_s);
	}
	try {
		if (this->state == SpNegoContext::STATE_NEW) {
			this->state = SpNegoContext::STATE_IN_PROCESS;
			$var($bytes, token, $new($bytes, $nc(is)->available()));
			$SpNegoToken::readFully(is, token);
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: receiving token = "_s, $($SpNegoToken::getHexBytes(token))}));
			}
			$var($NegTokenInit, initToken, $new($NegTokenInit, token));
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: received token of type = "_s, $($SpNegoToken::getTokenName(initToken->getType()))}));
			}
			$var($OidArray, mechList, initToken->getMechTypeList());
			$set(this, DER_mechTypes, initToken->getMechTypes());
			if (this->DER_mechTypes == nullptr) {
				valid = false;
			}
			$var($OidArray, supported_mechSet, getAvailableMechs());
			$var($Oid, mech_wanted, negotiate_mech_type(supported_mechSet, mechList));
			if (mech_wanted == nullptr) {
				valid = false;
			}
			$set(this, internal_mech, mech_wanted);
			$var($bytes, accept_token, nullptr);
			bool var$0 = $nc($nc(mechList)->get(0))->equals(mech_wanted);
			if (!var$0) {
				bool var$1 = $GSSUtil::isKerberosMech($nc(mechList)->get(0));
				var$0 = (var$1 && $GSSUtil::isKerberosMech(mech_wanted));
			}
			if (var$0) {
				if (SpNegoContext::DEBUG && !$nc(mech_wanted)->equals($nc(mechList)->get(0))) {
					$init($System);
					$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: negotiated mech adjusted to "_s, $nc(mechList)->get(0)}));
				}
				$var($bytes, mechToken, initToken->getMechToken());
				if (mechToken == nullptr) {
					$throwNew($GSSException, $GSSException::FAILURE, -1, "mechToken is missing"_s);
				}
				$assign(accept_token, GSS_acceptSecContext(mechToken));
				$assign(mech_wanted, $nc(mechList)->get(0));
			} else {
				$assign(accept_token, nullptr);
			}
			if (!$GSSUtil::useMSInterop() && valid) {
				valid = verifyMechListMIC(this->DER_mechTypes, $(initToken->getMechListMIC()));
			}
			if (valid) {
				if (isMechContextEstablished()) {
					$init($SpNegoToken$NegoResult);
					negoResult = $SpNegoToken$NegoResult::ACCEPT_COMPLETE;
					this->state = SpNegoContext::STATE_DONE;
					setContextFlags();
					if (SpNegoContext::DEBUG) {
						$init($System);
						$var($String, var$2, $$str({"SPNEGO Negotiated Mechanism = "_s, this->internal_mech, " "_s}));
						$nc($System::out)->println($$concat(var$2, $($GSSUtil::getMechStr(this->internal_mech))));
					}
				} else {
					$init($SpNegoToken$NegoResult);
					negoResult = $SpNegoToken$NegoResult::ACCEPT_INCOMPLETE;
					this->state = SpNegoContext::STATE_IN_PROCESS;
				}
			} else {
				$init($SpNegoToken$NegoResult);
				negoResult = $SpNegoToken$NegoResult::REJECT;
				this->state = SpNegoContext::STATE_DELETED;
				$throwNew($GSSException, $GSSException::FAILURE);
			}
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: mechanism wanted = "_s, mech_wanted}));
				$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: negotiated result = "_s, negoResult}));
			}
			$var($NegTokenTarg, targToken, $new($NegTokenTarg, $nc(negoResult)->ordinal(), mech_wanted, accept_token, nullptr));
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: sending token of type = "_s, $($SpNegoToken::getTokenName(targToken->getType()))}));
			}
			$assign(retVal, targToken->getEncoded());
		} else if (this->state == SpNegoContext::STATE_IN_PROCESS) {
			$var($bytes, token, $new($bytes, $nc(is)->available()));
			$SpNegoToken::readFully(is, token);
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: receiving token = "_s, $($SpNegoToken::getHexBytes(token))}));
			}
			$var($NegTokenTarg, inputToken, $new($NegTokenTarg, token));
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: received token of type = "_s, $($SpNegoToken::getTokenName(inputToken->getType()))}));
			}
			$var($bytes, client_token, inputToken->getResponseToken());
			$var($bytes, accept_token, GSS_acceptSecContext(client_token));
			if (accept_token == nullptr) {
				valid = false;
			}
			if (valid) {
				if (isMechContextEstablished()) {
					$init($SpNegoToken$NegoResult);
					negoResult = $SpNegoToken$NegoResult::ACCEPT_COMPLETE;
					this->state = SpNegoContext::STATE_DONE;
				} else {
					$init($SpNegoToken$NegoResult);
					negoResult = $SpNegoToken$NegoResult::ACCEPT_INCOMPLETE;
					this->state = SpNegoContext::STATE_IN_PROCESS;
				}
			} else {
				$init($SpNegoToken$NegoResult);
				negoResult = $SpNegoToken$NegoResult::REJECT;
				this->state = SpNegoContext::STATE_DELETED;
				$throwNew($GSSException, $GSSException::FAILURE);
			}
			$var($NegTokenTarg, targToken, $new($NegTokenTarg, $nc(negoResult)->ordinal(), nullptr, accept_token, nullptr));
			if (SpNegoContext::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: sending token of type = "_s, $($SpNegoToken::getTokenName(targToken->getType()))}));
			}
			$assign(retVal, targToken->getEncoded());
		} else if (SpNegoContext::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({"AcceptSecContext: state = "_s, $$str(this->state)}));
		}
		if (SpNegoContext::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({"SpNegoContext.acceptSecContext: sending token = "_s, $($SpNegoToken::getHexBytes(retVal))}));
		}
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$var($GSSException, gssException, $new($GSSException, $GSSException::FAILURE, -1, $(e->getMessage())));
		gssException->initCause(e);
		$throw(gssException);
	}
	if (this->state == SpNegoContext::STATE_DONE) {
		setContextFlags();
	}
	return retVal;
}

$OidArray* SpNegoContext::getAvailableMechs() {
	if (this->myCred != nullptr) {
		$var($OidArray, mechs, $new($OidArray, 1));
		mechs->set(0, $($nc(this->myCred)->getInternalMech()));
		return mechs;
	} else {
		return $nc(this->factory)->availableMechs;
	}
}

$bytes* SpNegoContext::getEncodedMechs($OidArray* mechSet) {
	$var($DerOutputStream, mech, $new($DerOutputStream));
	for (int32_t i = 0; i < $nc(mechSet)->length; ++i) {
		$var($bytes, mechType, $nc(mechSet->get(i))->getDER());
		mech->write(mechType);
	}
	$var($DerOutputStream, mechTypeList, $new($DerOutputStream));
	mechTypeList->write($DerValue::tag_Sequence, mech);
	$var($bytes, encoded, mechTypeList->toByteArray());
	return encoded;
}

$BitArray* SpNegoContext::getContextFlags() {
	$var($BitArray, out, $new($BitArray, 7));
	if (getCredDelegState()) {
		out->set(0, true);
	}
	if (getMutualAuthState()) {
		out->set(1, true);
	}
	if (getReplayDetState()) {
		out->set(2, true);
	}
	if (getSequenceDetState()) {
		out->set(3, true);
	}
	if (getConfState()) {
		out->set(5, true);
	}
	if (getIntegState()) {
		out->set(6, true);
	}
	return out;
}

void SpNegoContext::setContextFlags() {
	if (this->mechContext != nullptr) {
		if ($nc(this->mechContext)->getCredDelegState()) {
			this->credDelegState = true;
		}
		if (!$nc(this->mechContext)->getMutualAuthState()) {
			this->mutualAuthState = false;
		}
		if (!$nc(this->mechContext)->getReplayDetState()) {
			this->replayDetState = false;
		}
		if (!$nc(this->mechContext)->getSequenceDetState()) {
			this->sequenceDetState = false;
		}
		if (!$nc(this->mechContext)->getIntegState()) {
			this->integState = false;
		}
		if (!$nc(this->mechContext)->getConfState()) {
			this->confState = false;
		}
	}
}

bool SpNegoContext::verifyMechListMIC($bytes* mechTypes, $bytes* token) {
	if (token == nullptr) {
		if (SpNegoContext::DEBUG) {
			$init($System);
			$nc($System::out)->println("SpNegoContext: no MIC token validation"_s);
		}
		return true;
	}
	if (!$nc(this->mechContext)->getIntegState()) {
		if (SpNegoContext::DEBUG) {
			$init($System);
			$nc($System::out)->println("SpNegoContext: no MIC token validation - mechanism does not support integrity"_s);
		}
		return true;
	}
	bool valid = false;
	try {
		$var($MessageProp, prop, $new($MessageProp, 0, true));
		verifyMIC(token, 0, $nc(token)->length, mechTypes, 0, $nc(mechTypes)->length, prop);
		valid = true;
	} catch ($GSSException&) {
		$var($GSSException, e, $catch());
		valid = false;
		if (SpNegoContext::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({"SpNegoContext: MIC validation failed! "_s, $(e->getMessage())}));
		}
	}
	return valid;
}

$bytes* SpNegoContext::GSS_initSecContext($bytes* token) {
	$var($bytes, tok, nullptr);
	if (this->mechContext == nullptr) {
		$var($String, var$0, $nc(this->peerName)->toString());
		$var($GSSName, serverName, $nc($nc(this->factory)->manager)->createName(var$0, $($nc(this->peerName)->getStringNameType()), this->internal_mech));
		$var($GSSCredential, cred, nullptr);
		if (this->myCred != nullptr) {
			$assign(cred, $new($GSSCredentialImpl, $nc(this->factory)->manager, $($nc(this->myCred)->getInternalCred())));
		}
		$set(this, mechContext, $nc($nc(this->factory)->manager)->createContext(serverName, this->internal_mech, cred, $GSSContext::DEFAULT_LIFETIME));
		$nc(this->mechContext)->requestConf(this->confState);
		$nc(this->mechContext)->requestInteg(this->integState);
		$nc(this->mechContext)->requestCredDeleg(this->credDelegState);
		$nc(this->mechContext)->requestMutualAuth(this->mutualAuthState);
		$nc(this->mechContext)->requestReplayDet(this->replayDetState);
		$nc(this->mechContext)->requestSequenceDet(this->sequenceDetState);
		if ($instanceOf($GSSContextImpl, this->mechContext)) {
			$nc(($cast($GSSContextImpl, this->mechContext)))->requestDelegPolicy(this->delegPolicyState);
		}
	}
	if (token != nullptr) {
		$assign(tok, token);
	} else {
		$assign(tok, $new($bytes, 0));
	}
	$var($bytes, init_token, $nc(this->mechContext)->initSecContext(tok, 0, $nc(tok)->length));
	return init_token;
}

$bytes* SpNegoContext::GSS_acceptSecContext($bytes* token) {
	if (this->mechContext == nullptr) {
		$var($GSSCredential, cred, nullptr);
		if (this->myCred != nullptr) {
			$assign(cred, $new($GSSCredentialImpl, $nc(this->factory)->manager, $($nc(this->myCred)->getInternalCred())));
		}
		$set(this, mechContext, $nc($nc(this->factory)->manager)->createContext(cred));
	}
	$var($bytes, accept_token, $nc(this->mechContext)->acceptSecContext(token, 0, $nc(token)->length));
	return accept_token;
}

$Oid* SpNegoContext::negotiate_mech_type($OidArray* supported_mechSet, $OidArray* mechSet) {
	$init(SpNegoContext);
	for (int32_t i = 0; i < $nc(supported_mechSet)->length; ++i) {
		for (int32_t j = 0; j < $nc(mechSet)->length; ++j) {
			if ($nc(mechSet->get(j))->equals(supported_mechSet->get(i))) {
				if (SpNegoContext::DEBUG) {
					$init($System);
					$nc($System::out)->println($$str({"SpNegoContext: negotiated mechanism = "_s, mechSet->get(j)}));
				}
				return (mechSet->get(j));
			}
		}
	}
	return nullptr;
}

bool SpNegoContext::isEstablished() {
	return (this->state == SpNegoContext::STATE_DONE);
}

bool SpNegoContext::isMechContextEstablished() {
	if (this->mechContext != nullptr) {
		return $nc(this->mechContext)->isEstablished();
	} else {
		if (SpNegoContext::DEBUG) {
			$init($System);
			$nc($System::out)->println("The underlying mechanism context has not been initialized"_s);
		}
		return false;
	}
}

$bytes* SpNegoContext::export$() {
	$throwNew($GSSException, $GSSException::UNAVAILABLE, -1, "GSS Export Context not available"_s);
	$shouldNotReachHere();
}

void SpNegoContext::setChannelBinding($ChannelBinding* channelBinding) {
	$set(this, channelBinding, channelBinding);
}

$ChannelBinding* SpNegoContext::getChannelBinding() {
	return this->channelBinding;
}

void SpNegoContext::requestAnonymity(bool value) {
}

bool SpNegoContext::getAnonymityState() {
	return false;
}

void SpNegoContext::requestLifetime(int32_t lifetime) {
	if (this->state == SpNegoContext::STATE_NEW && isInitiator()) {
		this->lifetime = lifetime;
	}
}

int32_t SpNegoContext::getLifetime() {
	if (this->mechContext != nullptr) {
		return $nc(this->mechContext)->getLifetime();
	} else {
		return $GSSContext::INDEFINITE_LIFETIME;
	}
}

bool SpNegoContext::isTransferable() {
	return false;
}

void SpNegoContext::requestSequenceDet(bool value) {
	if (this->state == SpNegoContext::STATE_NEW && isInitiator()) {
		this->sequenceDetState = value;
	}
}

bool SpNegoContext::getSequenceDetState() {
	return this->sequenceDetState || this->replayDetState;
}

void SpNegoContext::requestReplayDet(bool value) {
	if (this->state == SpNegoContext::STATE_NEW && isInitiator()) {
		this->replayDetState = value;
	}
}

bool SpNegoContext::getReplayDetState() {
	return this->replayDetState || this->sequenceDetState;
}

$GSSNameSpi* SpNegoContext::getTargName() {
	if (this->mechContext != nullptr) {
		$var($GSSNameImpl, targName, $cast($GSSNameImpl, $nc(this->mechContext)->getTargName()));
		$set(this, peerName, $nc(targName)->getElement(this->internal_mech));
		return this->peerName;
	} else {
		if (SpNegoContext::DEBUG) {
			$init($System);
			$nc($System::out)->println("The underlying mechanism context has not been initialized"_s);
		}
		return nullptr;
	}
}

$GSSNameSpi* SpNegoContext::getSrcName() {
	if (this->mechContext != nullptr) {
		$var($GSSNameImpl, srcName, $cast($GSSNameImpl, $nc(this->mechContext)->getSrcName()));
		$set(this, myName, $nc(srcName)->getElement(this->internal_mech));
		return this->myName;
	} else {
		if (SpNegoContext::DEBUG) {
			$init($System);
			$nc($System::out)->println("The underlying mechanism context has not been initialized"_s);
		}
		return nullptr;
	}
}

$GSSCredentialSpi* SpNegoContext::getDelegCred() {
	if (this->state != SpNegoContext::STATE_IN_PROCESS && this->state != SpNegoContext::STATE_DONE) {
		$throwNew($GSSException, $GSSException::NO_CONTEXT);
	}
	if (this->mechContext != nullptr) {
		$var($GSSCredentialImpl, delegCred, $cast($GSSCredentialImpl, $nc(this->mechContext)->getDelegCred()));
		if (delegCred == nullptr) {
			return nullptr;
		}
		bool initiate = false;
		if ($nc(delegCred)->getUsage() == $GSSCredential::INITIATE_ONLY) {
			initiate = true;
		}
		$var($GSSCredentialSpi, mechCred, $nc(delegCred)->getElement(this->internal_mech, initiate));
		$var($SpNegoCredElement, cred, $new($SpNegoCredElement, mechCred));
		return cred->getInternalCred();
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "getDelegCred called in invalid state!"_s);
	}
}

int32_t SpNegoContext::getWrapSizeLimit(int32_t qop, bool confReq, int32_t maxTokSize) {
	if (this->mechContext != nullptr) {
		return $nc(this->mechContext)->getWrapSizeLimit(qop, confReq, maxTokSize);
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "getWrapSizeLimit called in invalid state!"_s);
	}
}

$bytes* SpNegoContext::wrap($bytes* inBuf, int32_t offset, int32_t len, $MessageProp* msgProp) {
	if (this->mechContext != nullptr) {
		return $nc(this->mechContext)->wrap(inBuf, offset, len, msgProp);
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "Wrap called in invalid state!"_s);
	}
}

void SpNegoContext::wrap($InputStream* is, $OutputStream* os, $MessageProp* msgProp) {
	if (this->mechContext != nullptr) {
		$nc(this->mechContext)->wrap(is, os, msgProp);
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "Wrap called in invalid state!"_s);
	}
}

$bytes* SpNegoContext::unwrap($bytes* inBuf, int32_t offset, int32_t len, $MessageProp* msgProp) {
	if (this->mechContext != nullptr) {
		return $nc(this->mechContext)->unwrap(inBuf, offset, len, msgProp);
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "UnWrap called in invalid state!"_s);
	}
}

void SpNegoContext::unwrap($InputStream* is, $OutputStream* os, $MessageProp* msgProp) {
	if (this->mechContext != nullptr) {
		$nc(this->mechContext)->unwrap(is, os, msgProp);
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "UnWrap called in invalid state!"_s);
	}
}

$bytes* SpNegoContext::getMIC($bytes* inMsg, int32_t offset, int32_t len, $MessageProp* msgProp) {
	if (this->mechContext != nullptr) {
		return $nc(this->mechContext)->getMIC(inMsg, offset, len, msgProp);
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "getMIC called in invalid state!"_s);
	}
}

void SpNegoContext::getMIC($InputStream* is, $OutputStream* os, $MessageProp* msgProp) {
	if (this->mechContext != nullptr) {
		$nc(this->mechContext)->getMIC(is, os, msgProp);
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "getMIC called in invalid state!"_s);
	}
}

void SpNegoContext::verifyMIC($bytes* inTok, int32_t tokOffset, int32_t tokLen, $bytes* inMsg, int32_t msgOffset, int32_t msgLen, $MessageProp* msgProp) {
	if (this->mechContext != nullptr) {
		$nc(this->mechContext)->verifyMIC(inTok, tokOffset, tokLen, inMsg, msgOffset, msgLen, msgProp);
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "verifyMIC called in invalid state!"_s);
	}
}

void SpNegoContext::verifyMIC($InputStream* is, $InputStream* msgStr, $MessageProp* msgProp) {
	if (this->mechContext != nullptr) {
		$nc(this->mechContext)->verifyMIC(is, msgStr, msgProp);
	} else {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "verifyMIC called in invalid state!"_s);
	}
}

$String* SpNegoContext::printState(int32_t state) {
	$init(SpNegoContext);
	switch (state) {
	case SpNegoContext::STATE_NEW:
		{
			return ("STATE_NEW"_s);
		}
	case SpNegoContext::STATE_IN_PROCESS:
		{
			return ("STATE_IN_PROCESS"_s);
		}
	case SpNegoContext::STATE_DONE:
		{
			return ("STATE_DONE"_s);
		}
	case SpNegoContext::STATE_DELETED:
		{
			return ("STATE_DELETED"_s);
		}
	default:
		{
			return ($str({"Unknown state "_s, $$str(state)}));
		}
	}
}

$Object* SpNegoContext::inquireSecContext($String* type) {
	if (this->mechContext == nullptr) {
		$throwNew($GSSException, $GSSException::NO_CONTEXT, -1, "Underlying mech not established."_s);
	}
	if ($instanceOf($GSSContextImpl, this->mechContext)) {
		return $of($nc(($cast($GSSContextImpl, this->mechContext)))->inquireSecContext(type));
	} else {
		$throwNew($GSSException, $GSSException::BAD_MECH, -1, "inquireSecContext not supported by underlying mech."_s);
	}
}

void clinit$SpNegoContext($Class* class$) {
	SpNegoContext::DEBUG = $GetBooleanAction::privilegedGetProperty("sun.security.spnego.debug"_s);
}

SpNegoContext::SpNegoContext() {
}

$Class* SpNegoContext::load$($String* name, bool initialize) {
	$loadClass(SpNegoContext, name, initialize, &_SpNegoContext_ClassInfo_, clinit$SpNegoContext, allocate$SpNegoContext);
	return class$;
}

$Class* SpNegoContext::class$ = nullptr;

			} // spnego
		} // jgss
	} // security
} // sun