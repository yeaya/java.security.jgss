#include <sun/security/jgss/GSSCredentialImpl$SearchKey.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSCredentialImpl.h>
#include <jcpp.h>

#undef INITIATE_AND_ACCEPT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCredentialImpl = ::sun::security::jgss::GSSCredentialImpl;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _GSSCredentialImpl$SearchKey_FieldInfo_[] = {
	{"mechOid", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(GSSCredentialImpl$SearchKey, mechOid)},
	{"usage", "I", nullptr, $PRIVATE, $field(GSSCredentialImpl$SearchKey, usage)},
	{}
};

$MethodInfo _GSSCredentialImpl$SearchKey_MethodInfo_[] = {
	{"<init>", "(Lorg/ietf/jgss/Oid;I)V", nullptr, $PUBLIC, $method(static_cast<void(GSSCredentialImpl$SearchKey::*)($Oid*,int32_t)>(&GSSCredentialImpl$SearchKey::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getMech", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getUsage", "()I", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _GSSCredentialImpl$SearchKey_InnerClassesInfo_[] = {
	{"sun.security.jgss.GSSCredentialImpl$SearchKey", "sun.security.jgss.GSSCredentialImpl", "SearchKey", $STATIC},
	{}
};

$ClassInfo _GSSCredentialImpl$SearchKey_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.GSSCredentialImpl$SearchKey",
	"java.lang.Object",
	nullptr,
	_GSSCredentialImpl$SearchKey_FieldInfo_,
	_GSSCredentialImpl$SearchKey_MethodInfo_,
	nullptr,
	nullptr,
	_GSSCredentialImpl$SearchKey_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.GSSCredentialImpl"
};

$Object* allocate$GSSCredentialImpl$SearchKey($Class* clazz) {
	return $of($alloc(GSSCredentialImpl$SearchKey));
}

void GSSCredentialImpl$SearchKey::init$($Oid* mechOid, int32_t usage) {
	$set(this, mechOid, nullptr);
	this->usage = $GSSCredential::INITIATE_AND_ACCEPT;
	$set(this, mechOid, mechOid);
	this->usage = usage;
}

$Oid* GSSCredentialImpl$SearchKey::getMech() {
	return this->mechOid;
}

int32_t GSSCredentialImpl$SearchKey::getUsage() {
	return this->usage;
}

bool GSSCredentialImpl$SearchKey::equals(Object$* other) {
	if (!($instanceOf(GSSCredentialImpl$SearchKey, other))) {
		return false;
	}
	$var(GSSCredentialImpl$SearchKey, that, $cast(GSSCredentialImpl$SearchKey, other));
	return (($nc(this->mechOid)->equals($nc(that)->mechOid)) && (this->usage == $nc(that)->usage));
}

int32_t GSSCredentialImpl$SearchKey::hashCode() {
	return $nc(this->mechOid)->hashCode();
}

GSSCredentialImpl$SearchKey::GSSCredentialImpl$SearchKey() {
}

$Class* GSSCredentialImpl$SearchKey::load$($String* name, bool initialize) {
	$loadClass(GSSCredentialImpl$SearchKey, name, initialize, &_GSSCredentialImpl$SearchKey_ClassInfo_, allocate$GSSCredentialImpl$SearchKey);
	return class$;
}

$Class* GSSCredentialImpl$SearchKey::class$ = nullptr;

		} // jgss
	} // security
} // sun