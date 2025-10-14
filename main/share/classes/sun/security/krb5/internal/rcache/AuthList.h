#ifndef _sun_security_krb5_internal_rcache_AuthList_h_
#define _sun_security_krb5_internal_rcache_AuthList_h_
//$ class sun.security.krb5.internal.rcache.AuthList
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		class LinkedList;
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

class AuthList : public ::java::lang::Object {
	$class(AuthList, $NO_CLASS_INIT, ::java::lang::Object)
public:
	AuthList();
	void init$(int32_t lifespan);
	virtual bool isEmpty();
	virtual void put(::sun::security::krb5::internal::rcache::AuthTimeWithHash* t, ::sun::security::krb5::internal::KerberosTime* currentTime);
	virtual $String* toString() override;
	::java::util::LinkedList* entries = nullptr;
	int32_t lifespan = 0;
	$volatile(int32_t) oldestTime = 0;
};

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_rcache_AuthList_h_