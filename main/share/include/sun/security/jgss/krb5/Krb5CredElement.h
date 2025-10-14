#ifndef _sun_security_jgss_krb5_Krb5CredElement_h_
#define _sun_security_jgss_krb5_Krb5CredElement_h_
//$ interface sun.security.jgss.krb5.Krb5CredElement
//$ extends sun.security.jgss.spi.GSSCredentialSpi

#include <sun/security/jgss/spi/GSSCredentialSpi.h>

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class $import Krb5CredElement : public ::sun::security::jgss::spi::GSSCredentialSpi {
	$interface(Krb5CredElement, $NO_CLASS_INIT, ::sun::security::jgss::spi::GSSCredentialSpi)
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_Krb5CredElement_h_