#ifndef _sun_security_krb5_internal_util_KrbDataOutputStream_h_
#define _sun_security_krb5_internal_util_KrbDataOutputStream_h_
//$ class sun.security.krb5.internal.util.KrbDataOutputStream
//$ extends java.io.BufferedOutputStream

#include <java/io/BufferedOutputStream.h>

namespace java {
	namespace io {
		class OutputStream;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace util {

class $import KrbDataOutputStream : public ::java::io::BufferedOutputStream {
	$class(KrbDataOutputStream, $NO_CLASS_INIT, ::java::io::BufferedOutputStream)
public:
	KrbDataOutputStream();
	void init$(::java::io::OutputStream* os);
	using ::java::io::BufferedOutputStream::write;
	virtual void write16(int32_t num);
	virtual void write32(int32_t num);
	virtual void write8(int32_t num);
};

				} // util
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_util_KrbDataOutputStream_h_