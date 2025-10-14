#include <sun/security/jgss/GSSExceptionImpl.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/Oid.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSException = ::org::ietf::jgss::GSSException;
using $Oid = ::org::ietf::jgss::Oid;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _GSSExceptionImpl_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GSSExceptionImpl, serialVersionUID)},
	{"majorMessage", "Ljava/lang/String;", nullptr, $PRIVATE, $field(GSSExceptionImpl, majorMessage)},
	{}
};

$MethodInfo _GSSExceptionImpl_MethodInfo_[] = {
	{"<init>", "(ILorg/ietf/jgss/Oid;)V", nullptr, 0, $method(static_cast<void(GSSExceptionImpl::*)(int32_t,$Oid*)>(&GSSExceptionImpl::init$))},
	{"<init>", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(GSSExceptionImpl::*)(int32_t,$String*)>(&GSSExceptionImpl::init$))},
	{"<init>", "(ILjava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(GSSExceptionImpl::*)(int32_t,$Exception*)>(&GSSExceptionImpl::init$))},
	{"<init>", "(ILjava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(GSSExceptionImpl::*)(int32_t,$String*,$Exception*)>(&GSSExceptionImpl::init$))},
	{"getMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _GSSExceptionImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.GSSExceptionImpl",
	"org.ietf.jgss.GSSException",
	nullptr,
	_GSSExceptionImpl_FieldInfo_,
	_GSSExceptionImpl_MethodInfo_
};

$Object* allocate$GSSExceptionImpl($Class* clazz) {
	return $of($alloc(GSSExceptionImpl));
}

void GSSExceptionImpl::init$(int32_t majorCode, $Oid* mech) {
	$GSSException::init$(majorCode);
	$set(this, majorMessage, $str({$($GSSException::getMajorString()), ": "_s, mech}));
}

void GSSExceptionImpl::init$(int32_t majorCode, $String* majorMessage) {
	$GSSException::init$(majorCode);
	$set(this, majorMessage, majorMessage);
}

void GSSExceptionImpl::init$(int32_t majorCode, $Exception* cause) {
	$GSSException::init$(majorCode);
	initCause(cause);
}

void GSSExceptionImpl::init$(int32_t majorCode, $String* majorMessage, $Exception* cause) {
	GSSExceptionImpl::init$(majorCode, majorMessage);
	initCause(cause);
}

$String* GSSExceptionImpl::getMessage() {
	if (this->majorMessage != nullptr) {
		return this->majorMessage;
	} else {
		return $GSSException::getMessage();
	}
}

GSSExceptionImpl::GSSExceptionImpl() {
}

GSSExceptionImpl::GSSExceptionImpl(const GSSExceptionImpl& e) {
}

GSSExceptionImpl GSSExceptionImpl::wrapper$() {
	$pendingException(this);
	return *this;
}

void GSSExceptionImpl::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* GSSExceptionImpl::load$($String* name, bool initialize) {
	$loadClass(GSSExceptionImpl, name, initialize, &_GSSExceptionImpl_ClassInfo_, allocate$GSSExceptionImpl);
	return class$;
}

$Class* GSSExceptionImpl::class$ = nullptr;

		} // jgss
	} // security
} // sun