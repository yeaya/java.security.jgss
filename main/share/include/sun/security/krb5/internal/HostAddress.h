#ifndef _sun_security_krb5_internal_HostAddress_h_
#define _sun_security_krb5_internal_HostAddress_h_
//$ class sun.security.krb5.internal.HostAddress
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

class $import HostAddress : public ::java::lang::Cloneable {
	$class(HostAddress, 0, ::java::lang::Cloneable)
public:
	HostAddress();
	void init$(int32_t dummy);
	void init$();
	void init$(int32_t new_addrType, $bytes* new_address);
	void init$(::java::net::InetAddress* inetAddress);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	int32_t getAddrType(::java::net::InetAddress* inetAddress);
	virtual ::java::net::InetAddress* getInetAddress();
	static ::java::net::InetAddress* getLocalInetAddress();
	virtual int32_t hashCode() override;
	static ::sun::security::krb5::internal::HostAddress* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	virtual $String* toString() override;
	int32_t addrType = 0;
	$bytes* address = nullptr;
	static ::java::net::InetAddress* localInetAddress;
	static bool DEBUG;
	$volatile(int32_t) hashCode$ = 0;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_HostAddress_h_