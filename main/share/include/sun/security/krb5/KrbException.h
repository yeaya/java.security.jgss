#ifndef _sun_security_krb5_KrbException_h_
#define _sun_security_krb5_KrbException_h_
//$ class sun.security.krb5.KrbException
//$ extends java.lang.Exception

#include <java/lang/Exception.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class KRBError;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import KrbException : public ::java::lang::Exception {
	$class(KrbException, $NO_CLASS_INIT, ::java::lang::Exception)
public:
	KrbException();
	void init$($String* s);
	void init$($Throwable* cause);
	void init$(int32_t i);
	void init$(int32_t i, $String* s);
	void init$(::sun::security::krb5::internal::KRBError* e);
	void init$(::sun::security::krb5::internal::KRBError* e, $String* s);
	virtual bool equals(Object$* obj) override;
	static $String* errorMessage(int32_t i);
	virtual ::sun::security::krb5::internal::KRBError* getError();
	virtual $String* getMessage() override;
	virtual int32_t hashCode() override;
	virtual $String* krbErrorMessage();
	virtual int32_t returnCode();
	virtual $String* returnCodeMessage();
	virtual $String* returnCodeSymbol();
	static $String* returnCodeSymbol(int32_t i);
	virtual $String* toString() override;
	static const int64_t serialVersionUID = (int64_t)0xBAB4397D512585EC;
	int32_t returnCode$ = 0;
	::sun::security::krb5::internal::KRBError* error = nullptr;
	KrbException(const KrbException& e);
	KrbException wrapper$();
	virtual void throwWrapper$() override;
};

		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_KrbException_h_