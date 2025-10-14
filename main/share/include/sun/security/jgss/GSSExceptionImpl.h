#ifndef _sun_security_jgss_GSSExceptionImpl_h_
#define _sun_security_jgss_GSSExceptionImpl_h_
//$ class sun.security.jgss.GSSExceptionImpl
//$ extends org.ietf.jgss.GSSException

#include <org/ietf/jgss/GSSException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class Oid;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $import GSSExceptionImpl : public ::org::ietf::jgss::GSSException {
	$class(GSSExceptionImpl, $NO_CLASS_INIT, ::org::ietf::jgss::GSSException)
public:
	GSSExceptionImpl();
	void init$(int32_t majorCode, ::org::ietf::jgss::Oid* mech);
	void init$(int32_t majorCode, $String* majorMessage);
	void init$(int32_t majorCode, ::java::lang::Exception* cause);
	void init$(int32_t majorCode, $String* majorMessage, ::java::lang::Exception* cause);
	virtual $String* getMessage() override;
	static const int64_t serialVersionUID = (int64_t)0x3AFF4A007414AF07;
	$String* majorMessage = nullptr;
	GSSExceptionImpl(const GSSExceptionImpl& e);
	GSSExceptionImpl wrapper$();
	virtual void throwWrapper$() override;
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_GSSExceptionImpl_h_