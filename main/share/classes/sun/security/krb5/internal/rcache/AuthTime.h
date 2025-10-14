#ifndef _sun_security_krb5_internal_rcache_AuthTime_h_
#define _sun_security_krb5_internal_rcache_AuthTime_h_
//$ class sun.security.krb5.internal.rcache.AuthTime
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace nio {
		namespace channels {
			class SeekableByteChannel;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {

class AuthTime : public ::java::lang::Object {
	$class(AuthTime, $NO_CLASS_INIT, ::java::lang::Object)
public:
	AuthTime();
	void init$($String* client, $String* server, int32_t ctime, int32_t cusec);
	virtual $bytes* encode(bool withHash);
	virtual $bytes* encode0($String* cstring, $String* sstring);
	static ::sun::security::krb5::internal::rcache::AuthTime* readFrom(::java::nio::channels::SeekableByteChannel* chan);
	static $String* readStringWithLength(::java::nio::channels::SeekableByteChannel* chan);
	virtual $String* toString() override;
	int32_t ctime = 0;
	int32_t cusec = 0;
	$String* client = nullptr;
	$String* server = nullptr;
};

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_rcache_AuthTime_h_