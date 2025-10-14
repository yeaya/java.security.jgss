#ifndef _sun_security_krb5_internal_ccache_Tag_h_
#define _sun_security_krb5_internal_ccache_Tag_h_
//$ class sun.security.krb5.internal.ccache.Tag
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class Integer;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {

class Tag : public ::java::lang::Object {
	$class(Tag, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Tag();
	void init$(int32_t len, int32_t new_tag, ::java::lang::Integer* new_time, ::java::lang::Integer* new_usec);
	void init$(int32_t new_tag);
	virtual $bytes* toByteArray();
	int32_t length = 0;
	int32_t tag = 0;
	int32_t tagLen = 0;
	::java::lang::Integer* time_offset = nullptr;
	::java::lang::Integer* usec_offset = nullptr;
};

				} // ccache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ccache_Tag_h_