#include <sun/security/krb5/internal/AuthContext.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/BitSet.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/internal/Authenticator.h>
#include <sun/security/krb5/internal/HostAddress.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BitSet = ::java::util::BitSet;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $Authenticator = ::sun::security::krb5::internal::Authenticator;
using $HostAddress = ::sun::security::krb5::internal::HostAddress;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _AuthContext_FieldInfo_[] = {
	{"remoteAddress", "Lsun/security/krb5/internal/HostAddress;", nullptr, $PUBLIC, $field(AuthContext, remoteAddress)},
	{"remotePort", "I", nullptr, $PUBLIC, $field(AuthContext, remotePort)},
	{"localAddress", "Lsun/security/krb5/internal/HostAddress;", nullptr, $PUBLIC, $field(AuthContext, localAddress)},
	{"localPort", "I", nullptr, $PUBLIC, $field(AuthContext, localPort)},
	{"keyBlock", "Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC, $field(AuthContext, keyBlock)},
	{"localSubkey", "Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC, $field(AuthContext, localSubkey)},
	{"remoteSubkey", "Lsun/security/krb5/EncryptionKey;", nullptr, $PUBLIC, $field(AuthContext, remoteSubkey)},
	{"authContextFlags", "Ljava/util/BitSet;", nullptr, $PUBLIC, $field(AuthContext, authContextFlags)},
	{"remoteSeqNumber", "I", nullptr, $PUBLIC, $field(AuthContext, remoteSeqNumber)},
	{"localSeqNumber", "I", nullptr, $PUBLIC, $field(AuthContext, localSeqNumber)},
	{"authenticator", "Lsun/security/krb5/internal/Authenticator;", nullptr, $PUBLIC, $field(AuthContext, authenticator)},
	{"reqCksumType", "I", nullptr, $PUBLIC, $field(AuthContext, reqCksumType)},
	{"safeCksumType", "I", nullptr, $PUBLIC, $field(AuthContext, safeCksumType)},
	{"initializationVector", "[B", nullptr, $PUBLIC, $field(AuthContext, initializationVector)},
	{}
};

$MethodInfo _AuthContext_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(AuthContext::*)()>(&AuthContext::init$))},
	{}
};

$ClassInfo _AuthContext_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.AuthContext",
	"java.lang.Object",
	nullptr,
	_AuthContext_FieldInfo_,
	_AuthContext_MethodInfo_
};

$Object* allocate$AuthContext($Class* clazz) {
	return $of($alloc(AuthContext));
}

void AuthContext::init$() {
}

AuthContext::AuthContext() {
}

$Class* AuthContext::load$($String* name, bool initialize) {
	$loadClass(AuthContext, name, initialize, &_AuthContext_ClassInfo_, allocate$AuthContext);
	return class$;
}

$Class* AuthContext::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun