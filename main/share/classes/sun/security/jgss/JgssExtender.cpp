#include <sun/security/jgss/JgssExtender.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSContext.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSContext = ::org::ietf::jgss::GSSContext;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _JgssExtender_FieldInfo_[] = {
	{"theOne", "Lsun/security/jgss/JgssExtender;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(JgssExtender, theOne)},
	{}
};

$MethodInfo _JgssExtender_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(JgssExtender::*)()>(&JgssExtender::init$))},
	{"getExtender", "()Lsun/security/jgss/JgssExtender;", nullptr, $PUBLIC | $STATIC, $method(static_cast<JgssExtender*(*)()>(&JgssExtender::getExtender))},
	{"setExtender", "(Lsun/security/jgss/JgssExtender;)V", nullptr, $PROTECTED | $STATIC, $method(static_cast<void(*)(JgssExtender*)>(&JgssExtender::setExtender))},
	{"wrap", "(Lorg/ietf/jgss/GSSCredential;)Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC},
	{"wrap", "(Lorg/ietf/jgss/GSSContext;)Lorg/ietf/jgss/GSSContext;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _JgssExtender_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.JgssExtender",
	"java.lang.Object",
	nullptr,
	_JgssExtender_FieldInfo_,
	_JgssExtender_MethodInfo_
};

$Object* allocate$JgssExtender($Class* clazz) {
	return $of($alloc(JgssExtender));
}

$volatile(JgssExtender*) JgssExtender::theOne = nullptr;

void JgssExtender::init$() {
}

JgssExtender* JgssExtender::getExtender() {
	$init(JgssExtender);
	return JgssExtender::theOne;
}

void JgssExtender::setExtender(JgssExtender* theOne) {
	$init(JgssExtender);
	$assignStatic(JgssExtender::theOne, theOne);
}

$GSSCredential* JgssExtender::wrap($GSSCredential* cred) {
	return cred;
}

$GSSContext* JgssExtender::wrap($GSSContext* ctxt) {
	return ctxt;
}

void clinit$JgssExtender($Class* class$) {
	$assignStatic(JgssExtender::theOne, $new(JgssExtender));
}

JgssExtender::JgssExtender() {
}

$Class* JgssExtender::load$($String* name, bool initialize) {
	$loadClass(JgssExtender, name, initialize, &_JgssExtender_ClassInfo_, clinit$JgssExtender, allocate$JgssExtender);
	return class$;
}

$Class* JgssExtender::class$ = nullptr;

		} // jgss
	} // security
} // sun