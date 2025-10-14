#include <sun/security/krb5/internal/rcache/AuthTimeWithHash.h>

#include <java/lang/Array.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Objects.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/krb5/internal/rcache/AuthTime.h>
#include <jcpp.h>

#undef DEFAULT_HASH_ALG

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $AuthTime = ::sun::security::krb5::internal::rcache::AuthTime;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {

$FieldInfo _AuthTimeWithHash_FieldInfo_[] = {
	{"DEFAULT_HASH_ALG", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AuthTimeWithHash, DEFAULT_HASH_ALG)},
	{"hashAlg", "Ljava/lang/String;", nullptr, $FINAL, $field(AuthTimeWithHash, hashAlg)},
	{"hash", "Ljava/lang/String;", nullptr, $FINAL, $field(AuthTimeWithHash, hash)},
	{}
};

$MethodInfo _AuthTimeWithHash_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;IILjava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(AuthTimeWithHash::*)($String*,$String*,int32_t,int32_t,$String*,$String*)>(&AuthTimeWithHash::init$))},
	{"compareTo", "(Lsun/security/krb5/internal/rcache/AuthTimeWithHash;)I", nullptr, $PUBLIC},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"encode", "(Z)[B", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isSameIgnoresHash", "(Lsun/security/krb5/internal/rcache/AuthTime;)Z", nullptr, $PUBLIC},
	{"realAlg", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($String*)>(&AuthTimeWithHash::realAlg))},
	{"sameTimeDiffHash", "(Lsun/security/krb5/internal/rcache/AuthTimeWithHash;)Z", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _AuthTimeWithHash_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.rcache.AuthTimeWithHash",
	"sun.security.krb5.internal.rcache.AuthTime",
	"java.lang.Comparable",
	_AuthTimeWithHash_FieldInfo_,
	_AuthTimeWithHash_MethodInfo_,
	"Lsun/security/krb5/internal/rcache/AuthTime;Ljava/lang/Comparable<Lsun/security/krb5/internal/rcache/AuthTimeWithHash;>;"
};

$Object* allocate$AuthTimeWithHash($Class* clazz) {
	return $of($alloc(AuthTimeWithHash));
}

$Object* AuthTimeWithHash::clone() {
	 return this->$AuthTime::clone();
}

void AuthTimeWithHash::finalize() {
	this->$AuthTime::finalize();
}

$String* AuthTimeWithHash::DEFAULT_HASH_ALG = nullptr;

$String* AuthTimeWithHash::realAlg($String* alg) {
	$init(AuthTimeWithHash);
	{
		$var($String, s1915$, alg);
		int32_t tmp1915$ = -1;
		switch ($nc(s1915$)->hashCode()) {
		case 0x0021B90E:
			{
				if (s1915$->equals("HASH"_s)) {
					tmp1915$ = 0;
				}
				break;
			}
		case (int32_t)0x91B72647:
			{
				if (s1915$->equals("SHA256"_s)) {
					tmp1915$ = 1;
				}
				break;
			}
		}
		switch (tmp1915$) {
		case 0:
			{
				return "MD5"_s;
			}
		case 1:
			{
				return "SHA-256"_s;
			}
		default:
			{
				$throwNew($AssertionError, $of($$str({alg, " is not HASH or SHA256"_s})));
			}
		}
	}
}

void AuthTimeWithHash::init$($String* client, $String* server, int32_t ctime, int32_t cusec, $String* hashAlg, $String* hash) {
	$AuthTime::init$(client, server, ctime, cusec);
	$set(this, hashAlg, hashAlg);
	$set(this, hash, hash);
}

bool AuthTimeWithHash::equals(Object$* o) {
	if ($equals(this, o)) {
		return true;
	}
	if (!($instanceOf(AuthTimeWithHash, o))) {
		return false;
	}
	$var(AuthTimeWithHash, that, $cast(AuthTimeWithHash, o));
	bool var$2 = $Objects::equals(this->hash, $nc(that)->hash);
	bool var$1 = var$2 && $Objects::equals(this->hashAlg, $nc(that)->hashAlg);
	bool var$0 = var$1 && $Objects::equals(this->client, $nc(that)->client);
	return var$0 && $Objects::equals(this->server, $nc(that)->server) && this->ctime == $nc(that)->ctime && this->cusec == that->cusec;
}

int32_t AuthTimeWithHash::hashCode() {
	return $Objects::hash($$new($ObjectArray, {$of(this->hash)}));
}

$String* AuthTimeWithHash::toString() {
	return $String::format("%d/%06d/%s/%s"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(this->ctime))),
		$($of($Integer::valueOf(this->cusec))),
		$of(this->hash),
		$of(this->client)
	}));
}

int32_t AuthTimeWithHash::compareTo(AuthTimeWithHash* other) {
	int32_t cmp = 0;
	if (this->ctime != $nc(other)->ctime) {
		cmp = $Integer::compare(this->ctime, other->ctime);
	} else if (this->cusec != other->cusec) {
		cmp = $Integer::compare(this->cusec, other->cusec);
	} else {
		cmp = $nc(this->hash)->compareTo(other->hash);
	}
	return cmp;
}

bool AuthTimeWithHash::sameTimeDiffHash(AuthTimeWithHash* old) {
	if (!this->isSameIgnoresHash(old)) {
		return false;
	}
	bool var$0 = $nc(this->hashAlg)->equals($nc(old)->hashAlg);
	return var$0 && !$nc(this->hash)->equals($nc(old)->hash);
}

bool AuthTimeWithHash::isSameIgnoresHash($AuthTime* old) {
	bool var$0 = $nc(this->client)->equals($nc(old)->client);
	return var$0 && $nc(this->server)->equals($nc(old)->server) && this->ctime == $nc(old)->ctime && this->cusec == old->cusec;
}

$bytes* AuthTimeWithHash::encode(bool withHash) {
	$var($String, cstring, nullptr);
	$var($String, sstring, nullptr);
	if (withHash) {
		$assign(cstring, ""_s);
		$assign(sstring, $String::format("%s:%s %d:%s %d:%s"_s, $$new($ObjectArray, {
			$of(this->hashAlg),
			$of(this->hash),
			$($of($Integer::valueOf($nc(this->client)->length()))),
			$of(this->client),
			$($of($Integer::valueOf($nc(this->server)->length()))),
			$of(this->server)
		})));
	} else {
		$assign(cstring, this->client);
		$assign(sstring, this->server);
	}
	return encode0(cstring, sstring);
}

int32_t AuthTimeWithHash::compareTo(Object$* other) {
	return this->compareTo($cast(AuthTimeWithHash, other));
}

void clinit$AuthTimeWithHash($Class* class$) {
	{
		if ($GetBooleanAction::privilegedGetProperty("jdk.krb5.rcache.useMD5"_s)) {
			$assignStatic(AuthTimeWithHash::DEFAULT_HASH_ALG, "HASH"_s);
		} else {
			$assignStatic(AuthTimeWithHash::DEFAULT_HASH_ALG, "SHA256"_s);
		}
	}
}

AuthTimeWithHash::AuthTimeWithHash() {
}

$Class* AuthTimeWithHash::load$($String* name, bool initialize) {
	$loadClass(AuthTimeWithHash, name, initialize, &_AuthTimeWithHash_ClassInfo_, clinit$AuthTimeWithHash, allocate$AuthTimeWithHash);
	return class$;
}

$Class* AuthTimeWithHash::class$ = nullptr;

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun