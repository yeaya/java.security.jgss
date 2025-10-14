#ifndef _sun_security_jgss_krb5_CipherHelper$WrapTokenInputStream_h_
#define _sun_security_jgss_krb5_CipherHelper$WrapTokenInputStream_h_
//$ class sun.security.jgss.krb5.CipherHelper$WrapTokenInputStream
//$ extends java.io.InputStream

#include <java/io/InputStream.h>
#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class CipherHelper;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class CipherHelper$WrapTokenInputStream : public ::java::io::InputStream {
	$class(CipherHelper$WrapTokenInputStream, $NO_CLASS_INIT, ::java::io::InputStream)
public:
	CipherHelper$WrapTokenInputStream();
	void init$(::sun::security::jgss::krb5::CipherHelper* this$0, ::java::io::InputStream* is, int32_t length);
	virtual int32_t available() override;
	virtual void close() override;
	virtual int32_t read() override;
	virtual int32_t read($bytes* b) override;
	virtual int32_t read($bytes* b, int32_t off, int32_t len) override;
	virtual int64_t skip(int64_t n) override;
	::sun::security::jgss::krb5::CipherHelper* this$0 = nullptr;
	::java::io::InputStream* is = nullptr;
	int32_t length = 0;
	int32_t remaining = 0;
	int32_t temp = 0;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_CipherHelper$WrapTokenInputStream_h_