#ifndef _sun_security_krb5_internal_ktab_KeyTab$1_h_
#define _sun_security_krb5_internal_ktab_KeyTab$1_h_
//$ class sun.security.krb5.internal.ktab.KeyTab$1
//$ extends java.util.Comparator

#include <java/util/Comparator.h>

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
				namespace ktab {
					class KeyTab;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {

class KeyTab$1 : public ::java::util::Comparator {
	$class(KeyTab$1, $NO_CLASS_INIT, ::java::util::Comparator)
public:
	KeyTab$1();
	void init$(::sun::security::krb5::internal::ktab::KeyTab* this$0);
	virtual int32_t compare(::sun::security::krb5::EncryptionKey* o1, ::sun::security::krb5::EncryptionKey* o2);
	virtual int32_t compare(Object$* o1, Object$* o2) override;
	::sun::security::krb5::internal::ktab::KeyTab* this$0 = nullptr;
};

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ktab_KeyTab$1_h_