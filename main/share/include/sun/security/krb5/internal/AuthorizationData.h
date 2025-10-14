#ifndef _sun_security_krb5_internal_AuthorizationData_h_
#define _sun_security_krb5_internal_AuthorizationData_h_
//$ class sun.security.krb5.internal.AuthorizationData
//$ extends java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class AuthorizationDataEntry;
			}
		}
	}
}
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
			class DerInputStream;
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import AuthorizationData : public ::java::lang::Cloneable {
	$class(AuthorizationData, $NO_CLASS_INIT, ::java::lang::Cloneable)
public:
	AuthorizationData();
	void init$();
	void init$($Array<::sun::security::krb5::internal::AuthorizationDataEntry>* new_entries);
	void init$(::sun::security::krb5::internal::AuthorizationDataEntry* new_entry);
	void init$(::sun::security::util::DerValue* der);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual int32_t count();
	virtual ::sun::security::krb5::internal::AuthorizationDataEntry* item(int32_t i);
	static ::sun::security::krb5::internal::AuthorizationData* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	virtual $String* toString() override;
	virtual void writeAuth(::sun::security::krb5::internal::ccache::CCacheOutputStream* cos);
	$Array<::sun::security::krb5::internal::AuthorizationDataEntry>* entry = nullptr;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_AuthorizationData_h_