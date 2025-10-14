#include <org/ietf/jgss/GSSContext.h>

#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/CompoundAttribute.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NamedAttribute.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/MessageProp.h>
#include <org/ietf/jgss/Oid.h>
#include <jcpp.h>

#undef DEFAULT_LIFETIME
#undef INDEFINITE_LIFETIME

using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSName = ::org::ietf::jgss::GSSName;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $Oid = ::org::ietf::jgss::Oid;

namespace org {
	namespace ietf {
		namespace jgss {

$NamedAttribute GSSContext_Attribute_var$0[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContext_MethodAnnotations_acceptSecContext1[] = {
	{"Ljava/lang/Deprecated;", GSSContext_Attribute_var$0},
	{}
};

$NamedAttribute GSSContext_Attribute_var$1[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContext_MethodAnnotations_getMIC11[] = {
	{"Ljava/lang/Deprecated;", GSSContext_Attribute_var$1},
	{}
};

$NamedAttribute GSSContext_Attribute_var$2[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContext_MethodAnnotations_initSecContext20[] = {
	{"Ljava/lang/Deprecated;", GSSContext_Attribute_var$2},
	{}
};

$NamedAttribute GSSContext_Attribute_var$3[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContext_MethodAnnotations_unwrap35[] = {
	{"Ljava/lang/Deprecated;", GSSContext_Attribute_var$3},
	{}
};

$NamedAttribute GSSContext_Attribute_var$4[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContext_MethodAnnotations_verifyMIC37[] = {
	{"Ljava/lang/Deprecated;", GSSContext_Attribute_var$4},
	{}
};

$NamedAttribute GSSContext_Attribute_var$5[] = {
	{"since", 's', "11"},
	{}
};

$CompoundAttribute _GSSContext_MethodAnnotations_wrap39[] = {
	{"Ljava/lang/Deprecated;", GSSContext_Attribute_var$5},
	{}
};

$FieldInfo _GSSContext_FieldInfo_[] = {
	{"DEFAULT_LIFETIME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSContext, DEFAULT_LIFETIME)},
	{"INDEFINITE_LIFETIME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSContext, INDEFINITE_LIFETIME)},
	{}
};

$MethodInfo _GSSContext_MethodInfo_[] = {
	{"acceptSecContext", "([BII)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"acceptSecContext", "(Ljava/io/InputStream;Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContext_MethodAnnotations_acceptSecContext1},
	{"dispose", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"export", "()[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getAnonymityState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getConfState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getCredDelegState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getDelegCred", "()Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getIntegState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getLifetime", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"getMIC", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getMIC", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContext_MethodAnnotations_getMIC11},
	{"getMech", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getMutualAuthState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getReplayDetState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getSequenceDetState", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getSrcName", "()Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getTargName", "()Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getWrapSizeLimit", "(IZI)I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"initSecContext", "([BII)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"initSecContext", "(Ljava/io/InputStream;Ljava/io/OutputStream;)I", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContext_MethodAnnotations_initSecContext20},
	{"isEstablished", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"isInitiator", "()Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"isProtReady", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"isTransferable", "()Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestAnonymity", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestConf", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestCredDeleg", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestInteg", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestLifetime", "(I)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestMutualAuth", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestReplayDet", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"requestSequenceDet", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"setChannelBinding", "(Lorg/ietf/jgss/ChannelBinding;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"unwrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContext_MethodAnnotations_unwrap35},
	{"verifyMIC", "([BII[BIILorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"verifyMIC", "(Ljava/io/InputStream;Ljava/io/InputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContext_MethodAnnotations_verifyMIC37},
	{"wrap", "([BIILorg/ietf/jgss/MessageProp;)[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"wrap", "(Ljava/io/InputStream;Ljava/io/OutputStream;Lorg/ietf/jgss/MessageProp;)V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "org.ietf.jgss.GSSException", nullptr, _GSSContext_MethodAnnotations_wrap39},
	{}
};

$ClassInfo _GSSContext_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"org.ietf.jgss.GSSContext",
	nullptr,
	nullptr,
	_GSSContext_FieldInfo_,
	_GSSContext_MethodInfo_
};

$Object* allocate$GSSContext($Class* clazz) {
	return $of($alloc(GSSContext));
}

$Class* GSSContext::load$($String* name, bool initialize) {
	$loadClass(GSSContext, name, initialize, &_GSSContext_ClassInfo_, allocate$GSSContext);
	return class$;
}

$Class* GSSContext::class$ = nullptr;

		} // jgss
	} // ietf
} // org