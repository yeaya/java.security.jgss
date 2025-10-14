#include <org/ietf/jgss/GSSManager.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/Provider.h>
#include <org/ietf/jgss/GSSContext.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSManagerImpl.h>
#include <jcpp.h>

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $GSSContext = ::org::ietf::jgss::GSSContext;
using $GSSCredential = ::org::ietf::jgss::GSSCredential;
using $GSSName = ::org::ietf::jgss::GSSName;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSManagerImpl = ::sun::security::jgss::GSSManagerImpl;

namespace org {
	namespace ietf {
		namespace jgss {

$MethodInfo _GSSManager_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(GSSManager::*)()>(&GSSManager::init$))},
	{"addProviderAtEnd", "(Ljava/security/Provider;Lorg/ietf/jgss/Oid;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"addProviderAtFront", "(Ljava/security/Provider;Lorg/ietf/jgss/Oid;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createContext", "(Lorg/ietf/jgss/GSSName;Lorg/ietf/jgss/Oid;Lorg/ietf/jgss/GSSCredential;I)Lorg/ietf/jgss/GSSContext;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createContext", "(Lorg/ietf/jgss/GSSCredential;)Lorg/ietf/jgss/GSSContext;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createContext", "([B)Lorg/ietf/jgss/GSSContext;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createCredential", "(I)Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createCredential", "(Lorg/ietf/jgss/GSSName;ILorg/ietf/jgss/Oid;I)Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createCredential", "(Lorg/ietf/jgss/GSSName;I[Lorg/ietf/jgss/Oid;I)Lorg/ietf/jgss/GSSCredential;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createName", "(Ljava/lang/String;Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createName", "([BLorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createName", "(Ljava/lang/String;Lorg/ietf/jgss/Oid;Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"createName", "([BLorg/ietf/jgss/Oid;Lorg/ietf/jgss/Oid;)Lorg/ietf/jgss/GSSName;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{"getInstance", "()Lorg/ietf/jgss/GSSManager;", nullptr, $PUBLIC | $STATIC, $method(static_cast<GSSManager*(*)()>(&GSSManager::getInstance))},
	{"getMechs", "()[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT},
	{"getMechsForName", "(Lorg/ietf/jgss/Oid;)[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT},
	{"getNamesForMech", "(Lorg/ietf/jgss/Oid;)[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _GSSManager_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"org.ietf.jgss.GSSManager",
	"java.lang.Object",
	nullptr,
	nullptr,
	_GSSManager_MethodInfo_
};

$Object* allocate$GSSManager($Class* clazz) {
	return $of($alloc(GSSManager));
}

void GSSManager::init$() {
}

GSSManager* GSSManager::getInstance() {
	return $new($GSSManagerImpl);
}

GSSManager::GSSManager() {
}

$Class* GSSManager::load$($String* name, bool initialize) {
	$loadClass(GSSManager, name, initialize, &_GSSManager_ClassInfo_, allocate$GSSManager);
	return class$;
}

$Class* GSSManager::class$ = nullptr;

		} // jgss
	} // ietf
} // org