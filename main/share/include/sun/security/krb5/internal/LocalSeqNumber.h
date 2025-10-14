#ifndef _sun_security_krb5_internal_LocalSeqNumber_h_
#define _sun_security_krb5_internal_LocalSeqNumber_h_
//$ class sun.security.krb5.internal.LocalSeqNumber
//$ extends sun.security.krb5.internal.SeqNumber

#include <sun/security/krb5/internal/SeqNumber.h>

namespace java {
	namespace lang {
		class Integer;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $import LocalSeqNumber : public ::sun::security::krb5::internal::SeqNumber {
	$class(LocalSeqNumber, $NO_CLASS_INIT, ::sun::security::krb5::internal::SeqNumber)
public:
	LocalSeqNumber();
	void init$();
	void init$(int32_t start);
	void init$(::java::lang::Integer* start);
	virtual int32_t current() override;
	virtual void init(int32_t start) override;
	virtual int32_t next() override;
	virtual void randInit() override;
	virtual int32_t step() override;
	int32_t lastSeqNumber = 0;
};

			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_LocalSeqNumber_h_