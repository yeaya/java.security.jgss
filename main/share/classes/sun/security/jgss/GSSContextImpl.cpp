#include <sun/security/jgss/GSSContextImpl.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/CompoundAttribute.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NamedAttribute.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/GSSContext.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/MessageProp.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSCredentialImpl.h>
#include <sun/security/jgss/GSSExceptionImpl.h>
#include <sun/security/jgss/GSSHeader.h>
#include <sun/security/jgss/GSSManagerImpl.h>
#include <sun/security/jgss/GSSNameImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/ProviderList.h>
#include <sun/security/jgss/spi/GSSContextSpi.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef BAD_NAME
#undef DEFAULT_MECH_OID
#undef DEFECTIVE_TOKEN
#undef DELETED
#undef FAILURE
#undef INDEFINITE_LIFETIME
#undef IN_PROGRESS
#undef NO_CONTEXT
#undef NO_CRED
#undef PRE_INIT
#undef READY

using $FieldArray = $Array<::java::lang::reflect::Field>;
using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;
using $Provider = ::java::security::Provider;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;
using $GSSContext = ::org::ietf::jgss::GSSContext;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSName = ::org::ietf::jgss::GSSName;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCredentialImpl = ::sun::security::jgss::GSSCredentialImpl;
using $GSSExceptionImpl = ::sun::security::jgss::GSSExceptionImpl;
using $GSSHeader = ::sun::security::jgss::GSSHeader;
using $GSSManagerImpl = ::sun::security::jgss::GSSManagerImpl;
using $GSSNameImpl = ::sun::security::jgss::GSSNameImpl;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $ProviderList = ::sun::security::jgss::ProviderList;
using $GSSContextSpi = ::sun::security::jgss::spi::GSSContextSpi;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {

$NamedAttribute GSSContextImpl_Attribute_var$0[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContextImpl_MethodAnnotations_acceptSecContext6[] = {
	{"Ljava/lang/Deprecated;", GSSContextImpl_Attribute_var$0},
	{}
};

$NamedAttribute GSSContextImpl_Attribute_var$1[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContextImpl_MethodAnnotations_getMIC17[] = {
	{"Ljava/lang/Deprecated;", GSSContextImpl_Attribute_var$1},
	{}
};

$NamedAttribute GSSContextImpl_Attribute_var$2[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContextImpl_MethodAnnotations_initSecContext26[] = {
	{"Ljava/lang/Deprecated;", GSSContextImpl_Attribute_var$2},
	{}
};

$NamedAttribute GSSContextImpl_Attribute_var$3[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContextImpl_MethodAnnotations_unwrap43[] = {
	{"Ljava/lang/Deprecated;", GSSContextImpl_Attribute_var$3},
	{}
};

$NamedAttribute GSSContextImpl_Attribute_var$4[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContextImpl_MethodAnnotations_verifyMIC45[] = {
	{"Ljava/lang/Deprecated;", GSSContextImpl_Attribute_var$4},
	{}
};

$NamedAttribute GSSContextImpl_Attribute_var$5[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContextImpl_MethodAnnotations_wrap47[] = {
	{"Ljava/lang/Deprecated;", GSSContextImpl_Attribute_var$5},
	{}
};

$FieldInfo _GSSContextImpl_FieldInfo_[] = {
	{"gssManager", "Lsun/security/jgss/GSSManagerImpl;", nullptr, $PRIVATE, $field(GSSContextImpl, gssManager)},
	{"initiator", "Z", nullptr, $PRIVATE, $field(GSSContextImpl, initiator)},
	{"PRE_INIT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GSSContextImpl, PRE_INIT)},
	{"IN_PROGRESS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GSSContextImpl, IN_PROGRESS)},
	{"READY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GSSContextImpl, READY)},
	{"DELETED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GSSContextImpl, DELETED)},
	{"currentState", "I", nullptr, $PRIVATE, $field(GSSContextImpl, currentState)},
	{"mechCtxt", "Lsun/security/jgss/spi/GSSContextSpi;", nullptr, $PRIVATE, $field(GSSContextImpl, mechCtxt)},
	{"mechOid", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(GSSContextImpl, mechOid)},
	{"objId", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE, $field(GSSContextImpl, objId)},
	{"myCred", "Lsun/security/jgss/GSSCredentialImpl;", nullptr, $PRIVATE, $field(GSSContextImpl, myCred)},
	{"srcName", "Lsun/security/jgss/GSSNameImpl;", nullptr, $PRIVATE, $field(GSSContextImpl, srcName)},
	{"targName", "Lsun/security/jgss/GSSNameImpl;", nullptr, $PRIVATE, $field(GSSContextImpl, targName)},
	{"reqLifetime", "I", nullptr, $PRIVATE, $field(GSSContextImpl, reqLifetime)},
	{"channelBindings", "Lorg/ietf/jgss/ChannelBinding;", nullptr, $PRIVATE, $field(GSSContextImpl, channelBindings)},
	{"reqConfState", "Z", nullptr, $PRIVATE, $field(GSSContextImpl, reqConfState)},
	{"reqIntegState", "Z", nullptr, $PRIVATE, $field(GSSContextImpl, reqIntegState)},
	{"reqMutualAuthState", "Z", nullptr, $PRIVATE, $field(GSSContextImpl, reqMutualAuthState)},
	{"reqReplayDetState", "Z", nullptr, $PRIVATE, $field(GSSContextImpl, reqReplayDetState)},
	{"reqSequenceDetState", "Z", nullptr, $PRIVATE, $field(GSSContextImpl, reqSequenceDetState)},
	{"reqCredDelegState", "Z", nullptr, $PRIVATE, $field(GSSContextImpl, reqCredDelegState)},
	{"reqAnonState", "Z", nullptr, $PRIVATE, $field(GSSContextImpl, reqAnonState)},
	{"reqDelegPolicyState", "Z", nullptr, $PRIVATE, $field(GSSContextImpl, reqDelegPolicyState)},
	{}
};

$MethodInfo _GSSContextImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(GSSContextImpl::*)()>(&GSSContextImpl::init$))},
	{"<init>", "(Lsun/security/jgss/GSSContextImpl;)V", nullptr, $PROTECTED, $method(static_cast<void(GSSContextImpl::*)(GSSContextImpl*)>(&GSSContextImpl::init$))},
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;Lorg/ietf/jgss/GSSName;Lorg/ietf/jgss/Oid;Lorg/ietf/jgss/GSSCredential;I)V", nullptr, $PUBLIC, $method(static_cast<void(GSSContextImpl::*)($GSSManagerImpl*,$GSSName*,$Oid*,$GSSCredential*,int32_t)>(&GSSContextImpl::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;Lorg/ietf/jgss/GSSCredential;)V", nullptr, $PUBLIC, $method(static_cast<void(GSSContextImpl::*)($GSSManagerImpl*,$GSSCredential*)>(&GSSContextImpl::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/GSSManagerImpl;[B)V", nullptr, $PUBLIC, $method(static_cast<void(GSSContextImpl::*)($GSSManagerImpl*,$bytes*)>(&GSSContextImpl::init$)), "org.ietf.jgss.GSSException"},
	{"acceptSecContext", "([BII)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"acceptSecContext", "(Ljava/io/InputStream;Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContextImpl_MethodAnnotations_acceptSecContext6},
	{"dispose", "()V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"export", "()[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getAnonymityState", "()Z", nullptr, $PUBLIC},
	{"getConfState", "()Z", nullptr, $PUBLIC},
	{"getCredDelegState", "()Z", nullptr, $PUBLIC},
	{"getDelegCred", "()Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getDelegPolicyState", "()Z", nullptr, $PUBLIC},
	{"getIntegState", "()Z", nullptr, $PUBLIC},
	{"getLifetime", "()I", nullptr, $PUBLIC},
	{"getMIC", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMIC", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContextImpl_MethodAnnotations_getMIC17},
	{"getMech", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getMutualAuthState", "()Z", nullptr, $PUBLIC},
	{"getReplayDetState", "()Z", nullptr, $PUBLIC},
	{"getSequenceDetState", "()Z", nullptr, $PUBLIC},
	{"getSrcName", "()Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getTargName", "()Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getWrapSizeLimit", "(IZI)I", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"initSecContext", "([BII)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"initSecContext", "(Ljava/io/InputStream;Ljava/io/OutputStream;)I", nullptr, $PUBLIC | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContextImpl_MethodAnnotations_initSecContext26},
	{"inquireSecContext", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"isEstablished", "()Z", nullptr, $PUBLIC},
	{"isInitiator", "()Z", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
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
	{"setChannelBinding", "(Lorg/ietf/jgss/ChannelBinding;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContextImpl_MethodAnnotations_unwrap43},
	{"verifyMIC", "([BII[BIILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"verifyMIC", "(Ljava/io/InputStream;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContextImpl_MethodAnnotations_verifyMIC45},
	{"wrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContextImpl_MethodAnnotations_wrap47},
	{}
};

$ClassInfo _GSSContextImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.GSSContextImpl",
	"java.lang.Object",
	"org.ietf.jgss.GSSContext",
	_GSSContextImpl_FieldInfo_,
	_GSSContextImpl_MethodInfo_
};

$Object* allocate$GSSContextImpl($Class* clazz) {
	return $of($alloc(GSSContextImpl));
}

void GSSContextImpl::init$() {
	this->currentState = GSSContextImpl::PRE_INIT;
	$set(this, mechCtxt, nullptr);
	$set(this, mechOid, nullptr);
	$set(this, objId, nullptr);
	$set(this, myCred, nullptr);
	$set(this, srcName, nullptr);
	$set(this, targName, nullptr);
	this->reqLifetime = $GSSContext::INDEFINITE_LIFETIME;
	$set(this, channelBindings, nullptr);
	this->reqConfState = true;
	this->reqIntegState = true;
	this->reqMutualAuthState = true;
	this->reqReplayDetState = true;
	this->reqSequenceDetState = true;
	this->reqCredDelegState = false;
	this->reqAnonState = false;
	this->reqDelegPolicyState = false;
}

void GSSContextImpl::init$(GSSContextImpl* src) {
	$beforeCallerSensitive();
	this->currentState = GSSContextImpl::PRE_INIT;
	$set(this, mechCtxt, nullptr);
	$set(this, mechOid, nullptr);
	$set(this, objId, nullptr);
	$set(this, myCred, nullptr);
	$set(this, srcName, nullptr);
	$set(this, targName, nullptr);
	this->reqLifetime = $GSSContext::INDEFINITE_LIFETIME;
	$set(this, channelBindings, nullptr);
	this->reqConfState = true;
	this->reqIntegState = true;
	this->reqMutualAuthState = true;
	this->reqReplayDetState = true;
	this->reqSequenceDetState = true;
	this->reqCredDelegState = false;
	this->reqAnonState = false;
	this->reqDelegPolicyState = false;
	{
		$var($FieldArray, arr$, GSSContextImpl::class$->getDeclaredFields());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Field, f, arr$->get(i$));
			{
				if (!$Modifier::isStatic($nc(f)->getModifiers())) {
					try {
						$nc(f)->set(this, $(f->get(src)));
					} catch ($Exception&) {
						$var($Exception, e, $catch());
						$throwNew($RuntimeException, static_cast<$Throwable*>(e));
					}
				}
			}
		}
	}
}

void GSSContextImpl::init$($GSSManagerImpl* gssManager, $GSSName* peer, $Oid* mech$renamed, $GSSCredential* myCred, int32_t lifetime) {
	$var($Oid, mech, mech$renamed);
	this->currentState = GSSContextImpl::PRE_INIT;
	$set(this, mechCtxt, nullptr);
	$set(this, mechOid, nullptr);
	$set(this, objId, nullptr);
	$set(this, myCred, nullptr);
	$set(this, srcName, nullptr);
	$set(this, targName, nullptr);
	this->reqLifetime = $GSSContext::INDEFINITE_LIFETIME;
	$set(this, channelBindings, nullptr);
	this->reqConfState = true;
	this->reqIntegState = true;
	this->reqMutualAuthState = true;
	this->reqReplayDetState = true;
	this->reqSequenceDetState = true;
	this->reqCredDelegState = false;
	this->reqAnonState = false;
	this->reqDelegPolicyState = false;
	if ((peer == nullptr) || !($instanceOf($GSSNameImpl, peer))) {
		$throwNew($GSSException, $GSSException::BAD_NAME);
	}
	if (mech == nullptr) {
		$init($ProviderList);
		$assign(mech, $ProviderList::DEFAULT_MECH_OID);
	}
	$set(this, gssManager, gssManager);
	$set(this, myCred, $cast($GSSCredentialImpl, myCred));
	this->reqLifetime = lifetime;
	$set(this, targName, $cast($GSSNameImpl, peer));
	$set(this, mechOid, mech);
	this->initiator = true;
}

void GSSContextImpl::init$($GSSManagerImpl* gssManager, $GSSCredential* myCred) {
	this->currentState = GSSContextImpl::PRE_INIT;
	$set(this, mechCtxt, nullptr);
	$set(this, mechOid, nullptr);
	$set(this, objId, nullptr);
	$set(this, myCred, nullptr);
	$set(this, srcName, nullptr);
	$set(this, targName, nullptr);
	this->reqLifetime = $GSSContext::INDEFINITE_LIFETIME;
	$set(this, channelBindings, nullptr);
	this->reqConfState = true;
	this->reqIntegState = true;
	this->reqMutualAuthState = true;
	this->reqReplayDetState = true;
	this->reqSequenceDetState = true;
	this->reqCredDelegState = false;
	this->reqAnonState = false;
	this->reqDelegPolicyState = false;
	$set(this, gssManager, gssManager);
	$set(this, myCred, $cast($GSSCredentialImpl, myCred));
	this->initiator = false;
}

void GSSContextImpl::init$($GSSManagerImpl* gssManager, $bytes* interProcessToken) {
	this->currentState = GSSContextImpl::PRE_INIT;
	$set(this, mechCtxt, nullptr);
	$set(this, mechOid, nullptr);
	$set(this, objId, nullptr);
	$set(this, myCred, nullptr);
	$set(this, srcName, nullptr);
	$set(this, targName, nullptr);
	this->reqLifetime = $GSSContext::INDEFINITE_LIFETIME;
	$set(this, channelBindings, nullptr);
	this->reqConfState = true;
	this->reqIntegState = true;
	this->reqMutualAuthState = true;
	this->reqReplayDetState = true;
	this->reqSequenceDetState = true;
	this->reqCredDelegState = false;
	this->reqAnonState = false;
	this->reqDelegPolicyState = false;
	$set(this, gssManager, gssManager);
	$set(this, mechCtxt, $nc(gssManager)->getMechanismContext(interProcessToken));
	this->initiator = $nc(this->mechCtxt)->isInitiator();
	$set(this, mechOid, $nc(this->mechCtxt)->getMech());
}

$bytes* GSSContextImpl::initSecContext($bytes* inputBuf, int32_t offset, int32_t len) {
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream, 600));
	$var($ByteArrayInputStream, bin, $new($ByteArrayInputStream, inputBuf, offset, len));
	int32_t size = initSecContext(bin, bos);
	return (size == 0 ? ($bytes*)nullptr : bos->toByteArray());
}

int32_t GSSContextImpl::initSecContext($InputStream* inStream, $OutputStream* outStream) {
	if (this->mechCtxt != nullptr && this->currentState != GSSContextImpl::IN_PROGRESS) {
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, "Illegal call to initSecContext"_s);
	}
	$var($GSSHeader, gssHeader, nullptr);
	int32_t inTokenLen = -1;
	$var($GSSCredentialSpi, credElement, nullptr);
	bool firstToken = false;
	try {
		if (this->mechCtxt == nullptr) {
			if (this->myCred != nullptr) {
				try {
					$assign(credElement, $nc(this->myCred)->getElement(this->mechOid, true));
				} catch ($GSSException&) {
					$var($GSSException, ge, $catch());
					bool var$0 = $GSSUtil::isSpNegoMech(this->mechOid);
					if (var$0 && ge->getMajor() == $GSSException::NO_CRED) {
						$assign(credElement, $nc(this->myCred)->getElement($nc($($nc(this->myCred)->getMechs()))->get(0), true));
					} else {
						$throw(ge);
					}
				}
			}
			$var($GSSNameSpi, nameElement, $nc(this->targName)->getElement(this->mechOid));
			$set(this, mechCtxt, $nc(this->gssManager)->getMechanismContext(nameElement, credElement, this->reqLifetime, this->mechOid));
			$nc(this->mechCtxt)->requestConf(this->reqConfState);
			$nc(this->mechCtxt)->requestInteg(this->reqIntegState);
			$nc(this->mechCtxt)->requestCredDeleg(this->reqCredDelegState);
			$nc(this->mechCtxt)->requestMutualAuth(this->reqMutualAuthState);
			$nc(this->mechCtxt)->requestReplayDet(this->reqReplayDetState);
			$nc(this->mechCtxt)->requestSequenceDet(this->reqSequenceDetState);
			$nc(this->mechCtxt)->requestAnonymity(this->reqAnonState);
			$nc(this->mechCtxt)->setChannelBinding(this->channelBindings);
			$nc(this->mechCtxt)->requestDelegPolicy(this->reqDelegPolicyState);
			$set(this, objId, $ObjectIdentifier::of($($nc(this->mechOid)->toString())));
			this->currentState = GSSContextImpl::IN_PROGRESS;
			firstToken = true;
		} else {
			bool var$2 = $nc($($nc($($nc(this->mechCtxt)->getProvider()))->getName()))->equals("SunNativeGSS"_s);
			if (var$2 || $GSSUtil::isSpNegoMech(this->mechOid)) {
			} else {
				$assign(gssHeader, $new($GSSHeader, inStream));
				if (!$nc($(gssHeader->getOid()))->equals(this->objId)) {
					$throwNew($GSSExceptionImpl, $GSSException::DEFECTIVE_TOKEN, $$str({"Mechanism not equal to "_s, $($nc(this->mechOid)->toString()), " in initSecContext token"_s}));
				}
				inTokenLen = gssHeader->getMechTokenLength();
			}
		}
		$var($bytes, obuf, $nc(this->mechCtxt)->initSecContext(inStream, inTokenLen));
		int32_t retVal = 0;
		if (obuf != nullptr) {
			retVal = obuf->length;
			bool var$3 = $nc($($nc($($nc(this->mechCtxt)->getProvider()))->getName()))->equals("SunNativeGSS"_s);
			if (var$3 || (!firstToken && $GSSUtil::isSpNegoMech(this->mechOid))) {
			} else {
				$assign(gssHeader, $new($GSSHeader, this->objId, obuf->length));
				retVal += gssHeader->encode(outStream);
			}
			$nc(outStream)->write(obuf);
		}
		if ($nc(this->mechCtxt)->isEstablished()) {
			this->currentState = GSSContextImpl::READY;
		}
		return retVal;
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::DEFECTIVE_TOKEN, $(e->getMessage()));
	}
	$shouldNotReachHere();
}

$bytes* GSSContextImpl::acceptSecContext($bytes* inTok, int32_t offset, int32_t len) {
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream, 100));
	acceptSecContext($$new($ByteArrayInputStream, inTok, offset, len), bos);
	$var($bytes, out, bos->toByteArray());
	return ($nc(out)->length == 0) ? ($bytes*)nullptr : out;
}

void GSSContextImpl::acceptSecContext($InputStream* inStream, $OutputStream* outStream) {
	if (this->mechCtxt != nullptr && this->currentState != GSSContextImpl::IN_PROGRESS) {
		$throwNew($GSSExceptionImpl, $GSSException::FAILURE, "Illegal call to acceptSecContext"_s);
	}
	$var($GSSHeader, gssHeader, nullptr);
	int32_t inTokenLen = -1;
	$var($GSSCredentialSpi, credElement, nullptr);
	try {
		if (this->mechCtxt == nullptr) {
			$assign(gssHeader, $new($GSSHeader, inStream));
			inTokenLen = gssHeader->getMechTokenLength();
			$set(this, objId, gssHeader->getOid());
			$set(this, mechOid, $new($Oid, $($nc(this->objId)->toString())));
			if (this->myCred != nullptr) {
				$assign(credElement, $nc(this->myCred)->getElement(this->mechOid, false));
			}
			$set(this, mechCtxt, $nc(this->gssManager)->getMechanismContext(credElement, this->mechOid));
			$nc(this->mechCtxt)->setChannelBinding(this->channelBindings);
			this->currentState = GSSContextImpl::IN_PROGRESS;
		} else {
			bool var$1 = $nc($($nc($($nc(this->mechCtxt)->getProvider()))->getName()))->equals("SunNativeGSS"_s);
			if (var$1 || ($GSSUtil::isSpNegoMech(this->mechOid))) {
			} else {
				$assign(gssHeader, $new($GSSHeader, inStream));
				if (!$nc($(gssHeader->getOid()))->equals(this->objId)) {
					$throwNew($GSSExceptionImpl, $GSSException::DEFECTIVE_TOKEN, $$str({"Mechanism not equal to "_s, $($nc(this->mechOid)->toString()), " in acceptSecContext token"_s}));
				}
				inTokenLen = gssHeader->getMechTokenLength();
			}
		}
		$var($bytes, obuf, $nc(this->mechCtxt)->acceptSecContext(inStream, inTokenLen));
		if (obuf != nullptr) {
			int32_t retVal = obuf->length;
			bool var$2 = $nc($($nc($($nc(this->mechCtxt)->getProvider()))->getName()))->equals("SunNativeGSS"_s);
			if (var$2 || ($GSSUtil::isSpNegoMech(this->mechOid))) {
			} else {
				$assign(gssHeader, $new($GSSHeader, this->objId, obuf->length));
				retVal += gssHeader->encode(outStream);
			}
			$nc(outStream)->write(obuf);
		}
		if ($nc(this->mechCtxt)->isEstablished()) {
			this->currentState = GSSContextImpl::READY;
		}
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSExceptionImpl, $GSSException::DEFECTIVE_TOKEN, $(e->getMessage()));
	}
}

bool GSSContextImpl::isEstablished() {
	if (this->mechCtxt == nullptr) {
		return false;
	} else {
		return (this->currentState == GSSContextImpl::READY);
	}
}

int32_t GSSContextImpl::getWrapSizeLimit(int32_t qop, bool confReq, int32_t maxTokenSize) {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getWrapSizeLimit(qop, confReq, maxTokenSize);
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
}

$bytes* GSSContextImpl::wrap($bytes* inBuf, int32_t offset, int32_t len, $MessageProp* msgProp) {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->wrap(inBuf, offset, len, msgProp);
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
}

void GSSContextImpl::wrap($InputStream* inStream, $OutputStream* outStream, $MessageProp* msgProp) {
	if (this->mechCtxt != nullptr) {
		$nc(this->mechCtxt)->wrap(inStream, outStream, msgProp);
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
}

$bytes* GSSContextImpl::unwrap($bytes* inBuf, int32_t offset, int32_t len, $MessageProp* msgProp) {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->unwrap(inBuf, offset, len, msgProp);
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
}

void GSSContextImpl::unwrap($InputStream* inStream, $OutputStream* outStream, $MessageProp* msgProp) {
	if (this->mechCtxt != nullptr) {
		$nc(this->mechCtxt)->unwrap(inStream, outStream, msgProp);
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
}

$bytes* GSSContextImpl::getMIC($bytes* inMsg, int32_t offset, int32_t len, $MessageProp* msgProp) {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getMIC(inMsg, offset, len, msgProp);
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
}

void GSSContextImpl::getMIC($InputStream* inStream, $OutputStream* outStream, $MessageProp* msgProp) {
	if (this->mechCtxt != nullptr) {
		$nc(this->mechCtxt)->getMIC(inStream, outStream, msgProp);
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
}

void GSSContextImpl::verifyMIC($bytes* inTok, int32_t tokOffset, int32_t tokLen, $bytes* inMsg, int32_t msgOffset, int32_t msgLen, $MessageProp* msgProp) {
	if (this->mechCtxt != nullptr) {
		$nc(this->mechCtxt)->verifyMIC(inTok, tokOffset, tokLen, inMsg, msgOffset, msgLen, msgProp);
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
}

void GSSContextImpl::verifyMIC($InputStream* tokStream, $InputStream* msgStream, $MessageProp* msgProp) {
	if (this->mechCtxt != nullptr) {
		$nc(this->mechCtxt)->verifyMIC(tokStream, msgStream, msgProp);
	} else {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
}

$bytes* GSSContextImpl::export$() {
	$var($bytes, result, nullptr);
	bool var$0 = $nc(this->mechCtxt)->isTransferable();
	if (var$0 && $nc($($nc($($nc(this->mechCtxt)->getProvider()))->getName()))->equals("SunNativeGSS"_s)) {
		$assign(result, $nc(this->mechCtxt)->export$());
	}
	return result;
}

void GSSContextImpl::requestMutualAuth(bool state) {
	if (this->mechCtxt == nullptr && this->initiator) {
		this->reqMutualAuthState = state;
	}
}

void GSSContextImpl::requestReplayDet(bool state) {
	if (this->mechCtxt == nullptr && this->initiator) {
		this->reqReplayDetState = state;
	}
}

void GSSContextImpl::requestSequenceDet(bool state) {
	if (this->mechCtxt == nullptr && this->initiator) {
		this->reqSequenceDetState = state;
	}
}

void GSSContextImpl::requestCredDeleg(bool state) {
	if (this->mechCtxt == nullptr && this->initiator) {
		this->reqCredDelegState = state;
	}
}

void GSSContextImpl::requestAnonymity(bool state) {
	if (this->mechCtxt == nullptr && this->initiator) {
		this->reqAnonState = state;
	}
}

void GSSContextImpl::requestConf(bool state) {
	if (this->mechCtxt == nullptr && this->initiator) {
		this->reqConfState = state;
	}
}

void GSSContextImpl::requestInteg(bool state) {
	if (this->mechCtxt == nullptr && this->initiator) {
		this->reqIntegState = state;
	}
}

void GSSContextImpl::requestLifetime(int32_t lifetime) {
	if (this->mechCtxt == nullptr && this->initiator) {
		this->reqLifetime = lifetime;
	}
}

void GSSContextImpl::setChannelBinding($ChannelBinding* channelBindings) {
	if (this->mechCtxt == nullptr) {
		$set(this, channelBindings, channelBindings);
	}
}

bool GSSContextImpl::getCredDelegState() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getCredDelegState();
	} else {
		return this->reqCredDelegState;
	}
}

bool GSSContextImpl::getMutualAuthState() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getMutualAuthState();
	} else {
		return this->reqMutualAuthState;
	}
}

bool GSSContextImpl::getReplayDetState() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getReplayDetState();
	} else {
		return this->reqReplayDetState;
	}
}

bool GSSContextImpl::getSequenceDetState() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getSequenceDetState();
	} else {
		return this->reqSequenceDetState;
	}
}

bool GSSContextImpl::getAnonymityState() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getAnonymityState();
	} else {
		return this->reqAnonState;
	}
}

bool GSSContextImpl::isTransferable() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->isTransferable();
	} else {
		return false;
	}
}

bool GSSContextImpl::isProtReady() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->isProtReady();
	} else {
		return false;
	}
}

bool GSSContextImpl::getConfState() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getConfState();
	} else {
		return this->reqConfState;
	}
}

bool GSSContextImpl::getIntegState() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getIntegState();
	} else {
		return this->reqIntegState;
	}
}

int32_t GSSContextImpl::getLifetime() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getLifetime();
	} else {
		return this->reqLifetime;
	}
}

$GSSName* GSSContextImpl::getSrcName() {
	if (this->srcName == nullptr) {
		$set(this, srcName, $GSSNameImpl::wrapElement(this->gssManager, $($nc(this->mechCtxt)->getSrcName())));
	}
	return this->srcName;
}

$GSSName* GSSContextImpl::getTargName() {
	if (this->targName == nullptr) {
		$set(this, targName, $GSSNameImpl::wrapElement(this->gssManager, $($nc(this->mechCtxt)->getTargName())));
	}
	return this->targName;
}

$Oid* GSSContextImpl::getMech() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getMech();
	}
	return this->mechOid;
}

$GSSCredential* GSSContextImpl::getDelegCred() {
	if (this->mechCtxt == nullptr) {
		$throwNew($GSSExceptionImpl, $GSSException::NO_CONTEXT, "No mechanism context yet!"_s);
	}
	$var($GSSCredentialSpi, delCredElement, $nc(this->mechCtxt)->getDelegCred());
	return (delCredElement == nullptr ? ($GSSCredential*)nullptr : $GSSManagerImpl::wrap($$new($GSSCredentialImpl, this->gssManager, delCredElement)));
}

bool GSSContextImpl::isInitiator() {
	return this->initiator;
}

void GSSContextImpl::dispose() {
	this->currentState = GSSContextImpl::DELETED;
	if (this->mechCtxt != nullptr) {
		$nc(this->mechCtxt)->dispose();
		$set(this, mechCtxt, nullptr);
	}
	$set(this, myCred, nullptr);
	$set(this, srcName, nullptr);
	$set(this, targName, nullptr);
}

$Object* GSSContextImpl::inquireSecContext($String* type) {
	if (this->mechCtxt == nullptr) {
		$throwNew($GSSException, $GSSException::NO_CONTEXT);
	}
	return $of($nc(this->mechCtxt)->inquireSecContext(type));
}

void GSSContextImpl::requestDelegPolicy(bool state) {
	if (this->mechCtxt == nullptr && this->initiator) {
		this->reqDelegPolicyState = state;
	}
}

bool GSSContextImpl::getDelegPolicyState() {
	if (this->mechCtxt != nullptr) {
		return $nc(this->mechCtxt)->getDelegPolicyState();
	} else {
		return this->reqDelegPolicyState;
	}
}

GSSContextImpl::GSSContextImpl() {
}

$Class* GSSContextImpl::load$($String* name, bool initialize) {
	$loadClass(GSSContextImpl, name, initialize, &_GSSContextImpl_ClassInfo_, allocate$GSSContextImpl);
	return class$;
}

$Class* GSSContextImpl::class$ = nullptr;

		} // jgss
	} // security
} // sun