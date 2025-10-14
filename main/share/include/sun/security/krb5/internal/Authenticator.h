#ifndef _sun_security_krb5_internal_Authenticator_h_
#define _sun_security_krb5_internal_Authenticator_h_
//$ class sun.security.krb5.internal.Authenticator
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class Integer;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Checksum;
			class EncryptionKey;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class AuthorizationData;
				class KerberosTime;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import Authenticator : public ::java::lang::Object {
	$class(Authenticator, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Authenticator();
	void init$(::sun::security::krb5::PrincipalName* new_cname, ::sun::security::krb5::Checksum* new_cksum, int32_t new_cusec, ::sun::security::krb5::internal::KerberosTime* new_ctime, ::sun::security::krb5::EncryptionKey* new_subKey, ::java::lang::Integer* new_seqNumber, ::sun::security::krb5::internal::AuthorizationData* new_authorizationData);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	::sun::security::krb5::Checksum* getChecksum();
	::java::lang::Integer* getSeqNumber();
	::sun::security::krb5::EncryptionKey* getSubKey();
	void init(::sun::security::util::DerValue* encoding);
	int32_t authenticator_vno = 0;
	::sun::security::krb5::PrincipalName* cname = nullptr;
	::sun::security::krb5::Checksum* cksum = nullptr;
	int32_t cusec = 0;
	::sun::security::krb5::internal::KerberosTime* ctime = nullptr;
	::sun::security::krb5::EncryptionKey* subKey = nullptr;
	::java::lang::Integer* seqNumber = nullptr;
	::sun::security::krb5::internal::AuthorizationData* authorizationData = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_Authenticator_h_