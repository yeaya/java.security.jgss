#ifndef _sun_security_krb5_internal_TicketFlags_h_
#define _sun_security_krb5_internal_TicketFlags_h_
//$ class sun.security.krb5.internal.TicketFlags
//$ extends sun.security.krb5.internal.util.KerberosFlags

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/util/KerberosFlags.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class LoginOptions;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class DerInputStream;
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export TicketFlags : public ::sun::security::krb5::internal::util::KerberosFlags {
	$class(TicketFlags, $NO_CLASS_INIT, ::sun::security::krb5::internal::util::KerberosFlags)
public:
	TicketFlags();
	void init$();
	void init$($booleans* flags);
	void init$(int32_t size, $bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $Object* clone() override;
	virtual bool match(::sun::security::krb5::internal::LoginOptions* options);
	virtual bool match(::sun::security::krb5::internal::TicketFlags* flags);
	static ::sun::security::krb5::internal::TicketFlags* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	virtual $String* toString() override;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_TicketFlags_h_