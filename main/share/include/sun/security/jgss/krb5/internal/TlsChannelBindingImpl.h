#ifndef _sun_security_jgss_krb5_internal_TlsChannelBindingImpl_h_
#define _sun_security_jgss_krb5_internal_TlsChannelBindingImpl_h_
//$ class sun.security.jgss.krb5.internal.TlsChannelBindingImpl
//$ extends org.ietf.jgss.ChannelBinding

#include <java/lang/Array.h>
#include <org/ietf/jgss/ChannelBinding.h>

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				namespace internal {

class $import TlsChannelBindingImpl : public ::org::ietf::jgss::ChannelBinding {
	$class(TlsChannelBindingImpl, $NO_CLASS_INIT, ::org::ietf::jgss::ChannelBinding)
public:
	TlsChannelBindingImpl();
	void init$($bytes* appData);
};

				} // internal
			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_internal_TlsChannelBindingImpl_h_