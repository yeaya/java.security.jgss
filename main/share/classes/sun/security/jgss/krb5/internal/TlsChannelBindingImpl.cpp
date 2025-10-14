#include <sun/security/jgss/krb5/internal/TlsChannelBindingImpl.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				namespace internal {

$MethodInfo _TlsChannelBindingImpl_MethodInfo_[] = {
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(TlsChannelBindingImpl::*)($bytes*)>(&TlsChannelBindingImpl::init$))},
	{}
};

$ClassInfo _TlsChannelBindingImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.krb5.internal.TlsChannelBindingImpl",
	"org.ietf.jgss.ChannelBinding",
	nullptr,
	nullptr,
	_TlsChannelBindingImpl_MethodInfo_
};

$Object* allocate$TlsChannelBindingImpl($Class* clazz) {
	return $of($alloc(TlsChannelBindingImpl));
}

void TlsChannelBindingImpl::init$($bytes* appData) {
	$ChannelBinding::init$(appData);
}

TlsChannelBindingImpl::TlsChannelBindingImpl() {
}

$Class* TlsChannelBindingImpl::load$($String* name, bool initialize) {
	$loadClass(TlsChannelBindingImpl, name, initialize, &_TlsChannelBindingImpl_ClassInfo_, allocate$TlsChannelBindingImpl);
	return class$;
}

$Class* TlsChannelBindingImpl::class$ = nullptr;

				} // internal
			} // krb5
		} // jgss
	} // security
} // sun