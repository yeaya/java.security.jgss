#ifndef _sun_security_krb5_internal_rcache_DflCache$Storage_h_
#define _sun_security_krb5_internal_rcache_DflCache$Storage_h_
//$ class sun.security.krb5.internal.rcache.DflCache$Storage
//$ extends java.io.Closeable

#include <java/io/Closeable.h>

namespace java {
	namespace nio {
		namespace channels {
			class SeekableByteChannel;
		}
	}
}
namespace java {
	namespace nio {
		namespace file {
			class Path;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class KerberosTime;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {
					class AuthTimeWithHash;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {

class DflCache$Storage : public ::java::io::Closeable {
	$class(DflCache$Storage, $NO_CLASS_INIT, ::java::io::Closeable)
public:
	DflCache$Storage();
	void init$();
	void append(::sun::security::krb5::internal::rcache::AuthTimeWithHash* at);
	virtual void close() override;
	static void create(::java::nio::file::Path* p);
	static ::java::nio::channels::SeekableByteChannel* createNoClose(::java::nio::file::Path* p);
	static void expunge(::java::nio::file::Path* p, ::sun::security::krb5::internal::KerberosTime* currTime);
	int32_t loadAndCheck(::java::nio::file::Path* p, ::sun::security::krb5::internal::rcache::AuthTimeWithHash* time, ::sun::security::krb5::internal::KerberosTime* currTime);
	static void makeMine(::java::nio::file::Path* p);
	static int32_t readHeader(::java::nio::channels::SeekableByteChannel* chan);
	::java::nio::channels::SeekableByteChannel* chan = nullptr;
};

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_rcache_DflCache$Storage_h_