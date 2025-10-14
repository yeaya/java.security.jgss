#ifndef _sun_security_jgss_GSSToken_h_
#define _sun_security_jgss_GSSToken_h_
//$ class sun.security.jgss.GSSToken
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $export GSSToken : public ::java::lang::Object {
	$class(GSSToken, $NO_CLASS_INIT, ::java::lang::Object)
public:
	GSSToken();
	void init$();
	static void debug($String* str);
	static $String* getHexBytes($bytes* bytes);
	static $String* getHexBytes($bytes* bytes, int32_t len);
	static $String* getHexBytes($bytes* bytes, int32_t pos, int32_t len);
	static int32_t readBigEndian($bytes* data, int32_t pos, int32_t size);
	static void readFully(::java::io::InputStream* is, $bytes* buffer);
	static void readFully(::java::io::InputStream* is, $bytes* buffer, int32_t offset, int32_t len);
	static int32_t readInt(::java::io::InputStream* is);
	static int32_t readInt($bytes* src, int32_t pos);
	static int32_t readLittleEndian($bytes* data, int32_t pos, int32_t size);
	static void writeBigEndian(int32_t value, $bytes* array);
	static void writeBigEndian(int32_t value, $bytes* array, int32_t pos);
	static void writeInt(int32_t val, ::java::io::OutputStream* os);
	static int32_t writeInt(int32_t val, $bytes* dest, int32_t pos);
	static void writeLittleEndian(int32_t value, $bytes* array);
	static void writeLittleEndian(int32_t value, $bytes* array, int32_t pos);
};

		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_GSSToken_h_