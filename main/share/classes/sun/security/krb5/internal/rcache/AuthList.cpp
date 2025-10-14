#include <sun/security/krb5/internal/rcache/AuthList.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/ListIterator.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/rcache/AuthTimeWithHash.h>
#include <jcpp.h>

#undef KRB_AP_ERR_REPEAT
#undef MIN_VALUE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractCollection = ::java::util::AbstractCollection;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $ListIterator = ::java::util::ListIterator;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $AuthTime = ::sun::security::krb5::internal::rcache::AuthTime;
using $AuthTimeWithHash = ::sun::security::krb5::internal::rcache::AuthTimeWithHash;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {

$FieldInfo _AuthList_FieldInfo_[] = {
	{"entries", "Ljava/util/LinkedList;", "Ljava/util/LinkedList<Lsun/security/krb5/internal/rcache/AuthTimeWithHash;>;", $PRIVATE | $FINAL, $field(AuthList, entries)},
	{"lifespan", "I", nullptr, $PRIVATE | $FINAL, $field(AuthList, lifespan)},
	{"oldestTime", "I", nullptr, $PRIVATE | $VOLATILE, $field(AuthList, oldestTime)},
	{}
};

$MethodInfo _AuthList_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(AuthList::*)(int32_t)>(&AuthList::init$))},
	{"isEmpty", "()Z", nullptr, $PUBLIC},
	{"put", "(Lsun/security/krb5/internal/rcache/AuthTimeWithHash;Lsun/security/krb5/internal/KerberosTime;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "sun.security.krb5.internal.KrbApErrException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _AuthList_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.rcache.AuthList",
	"java.lang.Object",
	nullptr,
	_AuthList_FieldInfo_,
	_AuthList_MethodInfo_
};

$Object* allocate$AuthList($Class* clazz) {
	return $of($alloc(AuthList));
}

void AuthList::init$(int32_t lifespan) {
	this->oldestTime = $Integer::MIN_VALUE;
	this->lifespan = lifespan;
	$set(this, entries, $new($LinkedList));
}

void AuthList::put($AuthTimeWithHash* t, $KerberosTime* currentTime) {
	$synchronized(this) {
		if ($nc(this->entries)->isEmpty()) {
			$nc(this->entries)->addFirst(t);
			this->oldestTime = $nc(t)->ctime;
			return;
		} else {
			$var($AuthTimeWithHash, temp, $cast($AuthTimeWithHash, $nc(this->entries)->getFirst()));
			int32_t cmp = $nc(temp)->compareTo(t);
			if (cmp < 0) {
				$nc(this->entries)->addFirst(t);
			} else if (cmp == 0) {
				$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_REPEAT);
			} else {
				$var($ListIterator, it, $nc(this->entries)->listIterator(1));
				bool found = false;
				while ($nc(it)->hasNext()) {
					$assign(temp, $cast($AuthTimeWithHash, it->next()));
					cmp = $nc(temp)->compareTo(t);
					if (cmp < 0) {
						$nc(this->entries)->add($nc(this->entries)->indexOf(temp), t);
						found = true;
						break;
					} else if (cmp == 0) {
						$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_REPEAT);
					}
				}
				if (!found) {
					$nc(this->entries)->addLast(t);
				}
			}
		}
		int64_t timeLimit = $nc(currentTime)->getSeconds() - this->lifespan;
		if (this->oldestTime > timeLimit - 5) {
			return;
		}
		while (!$nc(this->entries)->isEmpty()) {
			$var($AuthTimeWithHash, removed, $cast($AuthTimeWithHash, $nc(this->entries)->removeLast()));
			if ($nc(removed)->ctime >= timeLimit) {
				$nc(this->entries)->addLast(removed);
				this->oldestTime = removed->ctime;
				return;
			}
		}
		this->oldestTime = $Integer::MIN_VALUE;
	}
}

bool AuthList::isEmpty() {
	return $nc(this->entries)->isEmpty();
}

$String* AuthList::toString() {
	$var($StringBuilder, sb, $new($StringBuilder));
	$var($Iterator, iter, $nc(this->entries)->descendingIterator());
	int32_t pos = $nc(this->entries)->size();
	while ($nc(iter)->hasNext()) {
		$var($AuthTimeWithHash, at, $cast($AuthTimeWithHash, iter->next()));
		sb->append(u'#')->append(pos--)->append(": "_s)->append($($nc(at)->toString()))->append(u'\n');
	}
	return sb->toString();
}

AuthList::AuthList() {
}

$Class* AuthList::load$($String* name, bool initialize) {
	$loadClass(AuthList, name, initialize, &_AuthList_ClassInfo_, allocate$AuthList);
	return class$;
}

$Class* AuthList::class$ = nullptr;

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun