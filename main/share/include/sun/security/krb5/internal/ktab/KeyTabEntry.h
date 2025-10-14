#ifndef _sun_security_krb5_internal_ktab_KeyTabEntry_h_
#define _sun_security_krb5_internal_ktab_KeyTabEntry_h_
//$ class sun.security.krb5.internal.ktab.KeyTabEntry
//$ extends sun.security.krb5.internal.ktab.KeyTabConstants

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
			class PrincipalName;
			class Realm;
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
		namespace krb5 {
			namespace internal {
				namespace ktab {

class $import KeyTabEntry : public ::sun::security::krb5::internal::ktab::KeyTabConstants {
	$class(KeyTabEntry, $NO_CLASS_INIT, ::sun::security::krb5::internal::ktab::KeyTabConstants)
public:
	KeyTabEntry();
	void init$(::sun::security::krb5::PrincipalName* new_service, ::sun::security::krb5::Realm* new_realm, ::sun::security::krb5::internal::KerberosTime* new_time, int32_t new_keyVersion, int32_t new_keyType, $bytes* new_keyblock);
	virtual int32_t entryLength();
	virtual ::sun::security::krb5::EncryptionKey* getKey();
	virtual $String* getKeyString();
	virtual ::sun::security::krb5::PrincipalName* getService();
	virtual ::sun::security::krb5::internal::KerberosTime* getTimeStamp();
	::sun::security::krb5::PrincipalName* service = nullptr;
	::sun::security::krb5::Realm* realm = nullptr;
	::sun::security::krb5::internal::KerberosTime* timestamp = nullptr;
	int32_t keyVersion = 0;
	int32_t keyType = 0;
	$bytes* keyblock = nullptr;
	bool DEBUG = false;
};

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_ktab_KeyTabEntry_h_