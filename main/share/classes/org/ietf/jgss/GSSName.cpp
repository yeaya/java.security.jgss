#include <org/ietf/jgss/GSSName.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/Oid.h>
#include <jcpp.h>

#undef NT_ANONYMOUS
#undef NT_EXPORT_NAME
#undef NT_HOSTBASED_SERVICE
#undef NT_MACHINE_UID_NAME
#undef NT_STRING_UID_NAME
#undef NT_USER_NAME

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Oid = ::org::ietf::jgss::Oid;

namespace org {
	namespace ietf {
		namespace jgss {

$FieldInfo _GSSName_FieldInfo_[] = {
	{"NT_HOSTBASED_SERVICE", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSName, NT_HOSTBASED_SERVICE)},
	{"NT_USER_NAME", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSName, NT_USER_NAME)},
	{"NT_MACHINE_UID_NAME", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSName, NT_MACHINE_UID_NAME)},
	{"NT_STRING_UID_NAME", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSName, NT_STRING_UID_NAME)},
	{"NT_ANONYMOUS", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSName, NT_ANONYMOUS)},
	{"NT_EXPORT_NAME", "Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(GSSName, NT_EXPORT_NAME)},
	{}
};

$MethodInfo _GSSName_MethodInfo_[] = {
	{"canonicalize", "(Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"equals", "(Lorg/ietf/jgss/GSSName;)Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"export", "()[B", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getStringNameType", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"isAnonymous", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"isMN", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _GSSName_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"org.ietf.jgss.GSSName",
	nullptr,
	nullptr,
	_GSSName_FieldInfo_,
	_GSSName_MethodInfo_
};

$Object* allocate$GSSName($Class* clazz) {
	return $of($alloc(GSSName));
}

bool GSSName::equals(Object$* another) {
	 return this->$Object::equals(another);
}

int32_t GSSName::hashCode() {
	 return this->$Object::hashCode();
}

$String* GSSName::toString() {
	 return this->$Object::toString();
}


$Oid* GSSName::NT_HOSTBASED_SERVICE = nullptr;

$Oid* GSSName::NT_USER_NAME = nullptr;

$Oid* GSSName::NT_MACHINE_UID_NAME = nullptr;

$Oid* GSSName::NT_STRING_UID_NAME = nullptr;

$Oid* GSSName::NT_ANONYMOUS = nullptr;

$Oid* GSSName::NT_EXPORT_NAME = nullptr;

void clinit$GSSName($Class* class$) {
	$assignStatic(GSSName::NT_HOSTBASED_SERVICE, $Oid::getInstance("1.2.840.113554.1.2.1.4"_s));
	$assignStatic(GSSName::NT_USER_NAME, $Oid::getInstance("1.2.840.113554.1.2.1.1"_s));
	$assignStatic(GSSName::NT_MACHINE_UID_NAME, $Oid::getInstance("1.2.840.113554.1.2.1.2"_s));
	$assignStatic(GSSName::NT_STRING_UID_NAME, $Oid::getInstance("1.2.840.113554.1.2.1.3"_s));
	$assignStatic(GSSName::NT_ANONYMOUS, $Oid::getInstance("1.3.6.1.5.6.3"_s));
	$assignStatic(GSSName::NT_EXPORT_NAME, $Oid::getInstance("1.3.6.1.5.6.4"_s));
}

$Class* GSSName::load$($String* name, bool initialize) {
	$loadClass(GSSName, name, initialize, &_GSSName_ClassInfo_, clinit$GSSName, allocate$GSSName);
	return class$;
}

$Class* GSSName::class$ = nullptr;

		} // jgss
	} // ietf
} // org