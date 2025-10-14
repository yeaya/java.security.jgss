#ifndef _sun_security_krb5_internal_Ticket_h_
#define _sun_security_krb5_internal_Ticket_h_
//$ class sun.security.krb5.internal.Ticket
//$ extends java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptedData;
			class PrincipalName;
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

class $import Ticket : public ::java::lang::Cloneable {
	$class(Ticket, $NO_CLASS_INIT, ::java::lang::Cloneable)
public:
	Ticket();
	void init$();
	void init$(::sun::security::krb5::PrincipalName* new_sname, ::sun::security::krb5::EncryptedData* new_encPart);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	void init(::sun::security::util::DerValue* encoding);
	static ::sun::security::krb5::internal::Ticket* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	int32_t tkt_vno = 0;
	::sun::security::krb5::PrincipalName* sname = nullptr;
	::sun::security::krb5::EncryptedData* encPart = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_Ticket_h_