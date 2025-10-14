#ifndef _sun_security_krb5_internal_util_KrbDataInputStream_h_
#define _sun_security_krb5_internal_util_KrbDataInputStream_h_
//$ class sun.security.krb5.internal.util.KrbDataInputStream
//$ extends java.io.BufferedInputStream

#include <java/io/BufferedInputStream.h>

namespace java {
	namespace io {
		class InputStream;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace util {

class $export KrbDataInputStream : public ::java::io::BufferedInputStream {
	$class(KrbDataInputStream, $NO_CLASS_INIT, ::java::io::BufferedInputStream)
public:
	KrbDataInputStream();
	void init$(::java::io::InputStream* is);
	using ::java::io::BufferedInputStream::read;
	virtual int32_t read(int32_t num);
	int32_t readLength4();
	virtual int32_t readVersion();
	virtual void setNativeByteOrder();
	bool bigEndian = false;
};

				} // util
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_util_KrbDataInputStream_h_