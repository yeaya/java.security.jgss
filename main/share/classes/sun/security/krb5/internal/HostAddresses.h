#ifndef _sun_security_krb5_internal_HostAddresses_h_
#define _sun_security_krb5_internal_HostAddresses_h_
//$ class sun.security.krb5.internal.HostAddresses
//$ extends java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace net {
		class InetAddress;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class HostAddress;
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

class $export HostAddresses : public ::java::lang::Cloneable {
	$class(HostAddresses, 0, ::java::lang::Cloneable)
public:
	HostAddresses();
	void init$($Array<::sun::security::krb5::internal::HostAddress>* new_addresses);
	void init$();
	void init$(int32_t dummy);
	void init$(::sun::security::krb5::PrincipalName* serverPrincipal);
	void init$(::sun::security::util::DerValue* encoding);
	void init$($Array<::java::net::InetAddress>* inetAddresses);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual $Array<::java::net::InetAddress>* getInetAddresses();
	static ::sun::security::krb5::internal::HostAddresses* getLocalAddresses();
	virtual int32_t hashCode() override;
	virtual bool inList(::sun::security::krb5::internal::HostAddress* addr);
	static ::sun::security::krb5::internal::HostAddresses* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	virtual $String* toString() override;
	virtual void writeAddrs(::sun::security::krb5::internal::ccache::CCacheOutputStream* cos);
	static bool DEBUG;
	$Array<::sun::security::krb5::internal::HostAddress>* addresses = nullptr;
	$volatile(int32_t) hashCode$ = 0;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_HostAddresses_h_