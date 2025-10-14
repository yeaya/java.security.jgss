#ifndef _sun_security_krb5_internal_AuthorizationDataEntry_h_
#define _sun_security_krb5_internal_AuthorizationDataEntry_h_
//$ class sun.security.krb5.internal.AuthorizationDataEntry
//$ extends java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {
					class CCacheOutputStream;
				}
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

class $import AuthorizationDataEntry : public ::java::lang::Cloneable {
	$class(AuthorizationDataEntry, $NO_CLASS_INIT, ::java::lang::Cloneable)
public:
	AuthorizationDataEntry();
	void init$();
	void init$(int32_t new_adType, $bytes* new_adData);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual $String* toString() override;
	virtual void writeEntry(::sun::security::krb5::internal::ccache::CCacheOutputStream* cos);
	int32_t adType = 0;
	$bytes* adData = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_AuthorizationDataEntry_h_