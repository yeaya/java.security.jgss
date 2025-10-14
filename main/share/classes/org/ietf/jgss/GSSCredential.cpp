#include <org/ietf/jgss/GSSCredential.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Cloneable.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <jcpp.h>

#undef ACCEPT_ONLY
#undef DEFAULT_LIFETIME
#undef INDEFINITE_LIFETIME
#undef INITIATE_AND_ACCEPT
#undef INITIATE_ONLY

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;

namespace org {
	namespace ietf {
		namespace jgss {

$FieldInfo _GSSCredential_FieldInfo_[] = {
	{"INITIATE_AND_ACCEPT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSCredential, INITIATE_AND_ACCEPT)},
	{"INITIATE_ONLY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSCredential, INITIATE_ONLY)},
	{"ACCEPT_ONLY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSCredential, ACCEPT_ONLY)},
	{"DEFAULT_LIFETIME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSCredential, DEFAULT_LIFETIME)},
	{"INDEFINITE_LIFETIME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSCredential, INDEFINITE_LIFETIME)},
	{}
};

$MethodInfo _GSSCredential_MethodInfo_[] = {
	{"add", "(Lorg/ietf/jgss/GSSName;IILorg/ietf/jgss/Oid;I)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"dispose", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"getMechs", "()[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getName", "()Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getName", "(Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getRemainingAcceptLifetime", "(Lorg/ietf/jgss/Oid;)I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getRemainingInitLifetime", "(Lorg/ietf/jgss/Oid;)I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getRemainingLifetime", "()I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getUsage", "()I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getUsage", "(Lorg/ietf/jgss/Oid;)I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _GSSCredential_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"org.ietf.jgss.GSSCredential",
	nullptr,
	"java.lang.Cloneable",
	_GSSCredential_FieldInfo_,
	_GSSCredential_MethodInfo_
};

$Object* allocate$GSSCredential($Class* clazz) {
	return $of($alloc(GSSCredential));
}

bool GSSCredential::equals(Object$* another) {
	 return this->$Cloneable::equals(another);
}

int32_t GSSCredential::hashCode() {
	 return this->$Cloneable::hashCode();
}

$Class* GSSCredential::load$($String* name, bool initialize) {
	$loadClass(GSSCredential, name, initialize, &_GSSCredential_ClassInfo_, allocate$GSSCredential);
	return class$;
}

$Class* GSSCredential::class$ = nullptr;

		} // jgss
	} // ietf
} // org