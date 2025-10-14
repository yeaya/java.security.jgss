#include <sun/security/jgss/spi/GSSContextSpi.h>

#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/MessageProp.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;

namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {

$MethodInfo _GSSContextSpi_MethodInfo_[] = {
	{"acceptSecContext", "(Ljava/io/InputStream;I)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"dispose", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"export", "()[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getAnonymityState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getConfState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getCredDelegState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getDelegCred", "()Lsun/security/jgss/spi/GSSCredentialSpi;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getDelegPolicyState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getIntegState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getLifetime", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"getMIC", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getMIC", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getMech", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getMutualAuthState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $ABSTRACT},
	{"getReplayDetState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getSequenceDetState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getSrcName", "()Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getTargName", "()Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getWrapSizeLimit", "(IZI)I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"initSecContext", "(Ljava/io/InputStream;I)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"inquireSecContext", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"isEstablished", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"isInitiator", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"isProtReady", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"isTransferable", "()Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestAnonymity", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestConf", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestCredDeleg", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestDelegPolicy", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestInteg", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestLifetime", "(I)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestMutualAuth", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestReplayDet", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestSequenceDet", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"setChannelBinding", "(Lorg/ietf/jgss/ChannelBinding;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"verifyMIC", "(Ljava/io/InputStream;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"verifyMIC", "([BII[BIILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _GSSContextSpi_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.security.jgss.spi.GSSContextSpi",
	nullptr,
	nullptr,
	nullptr,
	_GSSContextSpi_MethodInfo_
};

$Object* allocate$GSSContextSpi($Class* clazz) {
	return $of($alloc(GSSContextSpi));
}

$Class* GSSContextSpi::load$($String* name, bool initialize) {
	$loadClass(GSSContextSpi, name, initialize, &_GSSContextSpi_ClassInfo_, allocate$GSSContextSpi);
	return class$;
}

$Class* GSSContextSpi::class$ = nullptr;

			} // spi
		} // jgss
	} // security
} // sun