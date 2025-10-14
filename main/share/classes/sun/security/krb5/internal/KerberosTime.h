#ifndef _sun_security_krb5_internal_KerberosTime_h_
#define _sun_security_krb5_internal_KerberosTime_h_
//$ class sun.security.krb5.internal.KerberosTime
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace time {
		class Instant;
	}
}
namespace java {
	namespace util {
		class Date;
	}
}
namespace sun {
	namespace security {
		namespace util {
			class DerInputStream;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export KerberosTime : public ::java::lang::Object {
	$class(KerberosTime, 0, ::java::lang::Object)
public:
	KerberosTime();
	void init$(int64_t time, int32_t micro);
	void init$(int64_t time);
	void init$($String* time);
	void init$(::java::util::Date* time);
	void init$(::java::time::Instant* instant);
	virtual $bytes* asn1Encode();
	virtual bool equals(Object$* obj) override;
	static int32_t getDefaultSkew();
	virtual int32_t getMicroSeconds();
	virtual int32_t getSeconds();
	virtual int64_t getTime();
	virtual bool greaterThan(::sun::security::krb5::internal::KerberosTime* time);
	virtual bool greaterThanWRTClockSkew(::sun::security::krb5::internal::KerberosTime* time, int32_t clockSkew);
	virtual bool greaterThanWRTClockSkew(::sun::security::krb5::internal::KerberosTime* time);
	virtual int32_t hashCode() override;
	bool inClockSkew(int32_t clockSkew);
	virtual bool inClockSkew();
	virtual bool isZero();
	static ::sun::security::krb5::internal::KerberosTime* now();
	static ::sun::security::krb5::internal::KerberosTime* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	virtual ::java::util::Date* toDate();
	virtual $String* toGeneralizedTimeString();
	static int64_t toKerberosTime($String* time);
	virtual $String* toString() override;
	virtual ::sun::security::krb5::internal::KerberosTime* withMicroSeconds(int32_t usec);
	int64_t kerberosTime = 0;
	int32_t microSeconds = 0;
	static int64_t initMilli;
	static int64_t initMicro;
	static bool DEBUG;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_KerberosTime_h_