#ifndef _sun_security_krb5_internal_EncAPRepPart_h_
#define _sun_security_krb5_internal_EncAPRepPart_h_
//$ class sun.security.krb5.internal.EncAPRepPart
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
			class EncryptionKey;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
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

class $export EncAPRepPart : public ::java::lang::Object {
	$class(EncAPRepPart, $NO_CLASS_INIT, ::java::lang::Object)
public:
	EncAPRepPart();
	void init$(::sun::security::krb5::internal::KerberosTime* new_ctime, int32_t new_cusec, ::sun::security::krb5::EncryptionKey* new_subKey, ::java::lang::Integer* new_seqNumber);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	::java::lang::Integer* getSeqNumber();
	::sun::security::krb5::EncryptionKey* getSubKey();
	void init(::sun::security::util::DerValue* encoding);
	::sun::security::krb5::internal::KerberosTime* ctime = nullptr;
	int32_t cusec = 0;
	::sun::security::krb5::EncryptionKey* subKey = nullptr;
	::java::lang::Integer* seqNumber = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_EncAPRepPart_h_