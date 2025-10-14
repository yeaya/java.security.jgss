#ifndef _sun_security_jgss_GSSHeader_h_
#define _sun_security_jgss_GSSHeader_h_
//$ class sun.security.jgss.GSSHeader
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("TOKEN_ID")
#undef TOKEN_ID

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
	}
}
namespace sun {
	namespace security {
		namespace util {
			class ObjectIdentifier;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $import GSSHeader : public ::java::lang::Object {
	$class(GSSHeader, $NO_CLASS_INIT, ::java::lang::Object)
public:
	GSSHeader();
	void init$(::sun::security::util::ObjectIdentifier* mechOid, int32_t mechTokenLength);
	void init$(::java::io::InputStream* is);
	void debug($String* str);
	virtual int32_t encode(::java::io::OutputStream* os);
	$String* getHexBytes($bytes* bytes, int32_t len);
	int32_t getLenFieldSize(int32_t len);
	virtual int32_t getLength();
	int32_t getLength(::java::io::InputStream* in);
	int32_t getLength(int32_t lenByte, ::java::io::InputStream* in);
	static int32_t getMaxMechTokenSize(::sun::security::util::ObjectIdentifier* mechOid, int32_t maxTotalSize);
	virtual int32_t getMechTokenLength();
	virtual ::sun::security::util::ObjectIdentifier* getOid();
	int32_t putLength(int32_t len, ::java::io::OutputStream* out);
	::sun::security::util::ObjectIdentifier* mechOid = nullptr;
	$bytes* mechOidBytes = nullptr;
	int32_t mechTokenLength = 0;
	static const int32_t TOKEN_ID = 96;
};

		} // jgss
	} // security
} // sun

#pragma pop_macro("TOKEN_ID")

#endif // _sun_security_jgss_GSSHeader_h_