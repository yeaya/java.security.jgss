#ifndef _sun_security_krb5_internal_rcache_AuthTimeWithHash_h_
#define _sun_security_krb5_internal_rcache_AuthTimeWithHash_h_
//$ class sun.security.krb5.internal.rcache.AuthTimeWithHash
//$ extends sun.security.krb5.internal.rcache.AuthTime
//$ implements java.lang.Comparable

#include <java/lang/Array.h>
#include <java/lang/Comparable.h>
#include <sun/security/krb5/internal/rcache/AuthTime.h>

#pragma push_macro("DEFAULT_HASH_ALG")
#undef DEFAULT_HASH_ALG

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {

class AuthTimeWithHash : public ::sun::security::krb5::internal::rcache::AuthTime, public ::java::lang::Comparable {
	$class(AuthTimeWithHash, 0, ::sun::security::krb5::internal::rcache::AuthTime, ::java::lang::Comparable)
public:
	AuthTimeWithHash();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	virtual $Object* clone() override;
	virtual void finalize() override;
	void init$($String* client, $String* server, int32_t ctime, int32_t cusec, $String* hashAlg, $String* hash);
	virtual int32_t compareTo(::sun::security::krb5::internal::rcache::AuthTimeWithHash* other);
	virtual int32_t compareTo(Object$* other) override;
	virtual $bytes* encode(bool withHash) override;
	virtual bool equals(Object$* o) override;
	virtual int32_t hashCode() override;
	virtual bool isSameIgnoresHash(::sun::security::krb5::internal::rcache::AuthTime* old);
	static $String* realAlg($String* alg);
	virtual bool sameTimeDiffHash(::sun::security::krb5::internal::rcache::AuthTimeWithHash* old);
	virtual $String* toString() override;
	static $String* DEFAULT_HASH_ALG;
	$String* hashAlg = nullptr;
	$String* hash = nullptr;
};

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEFAULT_HASH_ALG")

#endif // _sun_security_krb5_internal_rcache_AuthTimeWithHash_h_