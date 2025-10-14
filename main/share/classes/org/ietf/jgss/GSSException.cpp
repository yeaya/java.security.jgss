#include <org/ietf/jgss/GSSException.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

#undef BAD_BINDINGS
#undef BAD_MECH
#undef BAD_MIC
#undef BAD_NAME
#undef BAD_NAMETYPE
#undef BAD_QOP
#undef BAD_STATUS
#undef CONTEXT_EXPIRED
#undef CREDENTIALS_EXPIRED
#undef DEFECTIVE_CREDENTIAL
#undef DEFECTIVE_TOKEN
#undef DUPLICATE_ELEMENT
#undef DUPLICATE_TOKEN
#undef FAILURE
#undef GAP_TOKEN
#undef NAME_NOT_MN
#undef NO_CONTEXT
#undef NO_CRED
#undef OLD_TOKEN
#undef UNAUTHORIZED
#undef UNAVAILABLE
#undef UNSEQ_TOKEN

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace org {
	namespace ietf {
		namespace jgss {

$FieldInfo _GSSException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GSSException, serialVersionUID)},
	{"BAD_BINDINGS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, BAD_BINDINGS)},
	{"BAD_MECH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, BAD_MECH)},
	{"BAD_NAME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, BAD_NAME)},
	{"BAD_NAMETYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, BAD_NAMETYPE)},
	{"BAD_STATUS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, BAD_STATUS)},
	{"BAD_MIC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, BAD_MIC)},
	{"CONTEXT_EXPIRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, CONTEXT_EXPIRED)},
	{"CREDENTIALS_EXPIRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, CREDENTIALS_EXPIRED)},
	{"DEFECTIVE_CREDENTIAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, DEFECTIVE_CREDENTIAL)},
	{"DEFECTIVE_TOKEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, DEFECTIVE_TOKEN)},
	{"FAILURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, FAILURE)},
	{"NO_CONTEXT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, NO_CONTEXT)},
	{"NO_CRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, NO_CRED)},
	{"BAD_QOP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, BAD_QOP)},
	{"UNAUTHORIZED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, UNAUTHORIZED)},
	{"UNAVAILABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, UNAVAILABLE)},
	{"DUPLICATE_ELEMENT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, DUPLICATE_ELEMENT)},
	{"NAME_NOT_MN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, NAME_NOT_MN)},
	{"DUPLICATE_TOKEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, DUPLICATE_TOKEN)},
	{"OLD_TOKEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, OLD_TOKEN)},
	{"UNSEQ_TOKEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, UNSEQ_TOKEN)},
	{"GAP_TOKEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSException, GAP_TOKEN)},
	{"messages", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(GSSException, messages)},
	{"major", "I", nullptr, $PRIVATE, $field(GSSException, major)},
	{"minor", "I", nullptr, $PRIVATE, $field(GSSException, minor)},
	{"minorMessage", "Ljava/lang/String;", nullptr, $PRIVATE, $field(GSSException, minorMessage)},
	{"majorString", "Ljava/lang/String;", nullptr, $PRIVATE, $field(GSSException, majorString)},
	{}
};

$MethodInfo _GSSException_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(GSSException::*)(int32_t)>(&GSSException::init$))},
	{"<init>", "(ILjava/lang/String;)V", nullptr, 0, $method(static_cast<void(GSSException::*)(int32_t,$String*)>(&GSSException::init$))},
	{"<init>", "(IILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(GSSException::*)(int32_t,int32_t,$String*)>(&GSSException::init$))},
	{"getMajor", "()I", nullptr, $PUBLIC},
	{"getMajorString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getMinor", "()I", nullptr, $PUBLIC},
	{"getMinorString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"setMinor", "(ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"validateMajor", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(GSSException::*)(int32_t)>(&GSSException::validateMajor))},
	{}
};

$ClassInfo _GSSException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"org.ietf.jgss.GSSException",
	"java.lang.Exception",
	nullptr,
	_GSSException_FieldInfo_,
	_GSSException_MethodInfo_
};

$Object* allocate$GSSException($Class* clazz) {
	return $of($alloc(GSSException));
}

$StringArray* GSSException::messages = nullptr;

void GSSException::init$(int32_t majorCode) {
	$Exception::init$();
	this->minor = 0;
	$set(this, minorMessage, nullptr);
	$set(this, majorString, nullptr);
	if (validateMajor(majorCode)) {
		this->major = majorCode;
	} else {
		this->major = GSSException::FAILURE;
	}
}

void GSSException::init$(int32_t majorCode, $String* majorString) {
	$Exception::init$();
	this->minor = 0;
	$set(this, minorMessage, nullptr);
	$set(this, majorString, nullptr);
	if (validateMajor(majorCode)) {
		this->major = majorCode;
	} else {
		this->major = GSSException::FAILURE;
	}
	$set(this, majorString, majorString);
}

void GSSException::init$(int32_t majorCode, int32_t minorCode, $String* minorString) {
	$Exception::init$();
	this->minor = 0;
	$set(this, minorMessage, nullptr);
	$set(this, majorString, nullptr);
	if (validateMajor(majorCode)) {
		this->major = majorCode;
	} else {
		this->major = GSSException::FAILURE;
	}
	this->minor = minorCode;
	$set(this, minorMessage, minorString);
}

int32_t GSSException::getMajor() {
	return this->major;
}

int32_t GSSException::getMinor() {
	return this->minor;
}

$String* GSSException::getMajorString() {
	if (this->majorString != nullptr) {
		return this->majorString;
	} else {
		return $nc(GSSException::messages)->get(this->major - 1);
	}
}

$String* GSSException::getMinorString() {
	return this->minorMessage;
}

void GSSException::setMinor(int32_t minorCode, $String* message) {
	this->minor = minorCode;
	$set(this, minorMessage, message);
}

$String* GSSException::toString() {
	return ($str({"GSSException: "_s, $(getMessage())}));
}

$String* GSSException::getMessage() {
	if (this->minor == 0) {
		return (getMajorString());
	}
	$var($String, var$1, $$str({$(getMajorString()), " (Mechanism level: "_s}));
	$var($String, var$0, $$concat(var$1, $(getMinorString())));
	return ($concat(var$0, ")"));
}

bool GSSException::validateMajor(int32_t major) {
	if (major > 0 && major <= $nc(GSSException::messages)->length) {
		return (true);
	}
	return (false);
}

void clinit$GSSException($Class* class$) {
	$assignStatic(GSSException::messages, $new($StringArray, {
		"Channel binding mismatch"_s,
		"Unsupported mechanism requested"_s,
		"Invalid name provided"_s,
		"Name of unsupported type provided"_s,
		"Invalid input status selector"_s,
		"Token had invalid integrity check"_s,
		"Specified security context expired"_s,
		"Expired credentials detected"_s,
		"Defective credential detected"_s,
		"Defective token detected"_s,
		"Failure unspecified at GSS-API level"_s,
		"Security context init/accept not yet called or context deleted"_s,
		"No valid credentials provided"_s,
		"Unsupported QOP value"_s,
		"Operation unauthorized"_s,
		"Operation unavailable"_s,
		"Duplicate credential element requested"_s,
		"Name contains multi-mechanism elements"_s,
		"The token was a duplicate of an earlier token"_s,
		"The token\'s validity period has expired"_s,
		"A later token has already been processed"_s,
		"An expected per-message token was not received"_s
	}));
}

GSSException::GSSException() {
}

GSSException::GSSException(const GSSException& e) {
}

GSSException GSSException::wrapper$() {
	$pendingException(this);
	return *this;
}

void GSSException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* GSSException::load$($String* name, bool initialize) {
	$loadClass(GSSException, name, initialize, &_GSSException_ClassInfo_, clinit$GSSException, allocate$GSSException);
	return class$;
}

$Class* GSSException::class$ = nullptr;

		} // jgss
	} // ietf
} // org