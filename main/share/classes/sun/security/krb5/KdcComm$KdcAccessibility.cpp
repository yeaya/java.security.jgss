#include <sun/security/krb5/KdcComm$KdcAccessibility.h>

#include <java/io/PrintStream.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <sun/security/krb5/KdcComm$BpType.h>
#include <sun/security/krb5/KdcComm.h>
#include <jcpp.h>

#undef DEBUG
#undef TRY_LAST

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractList = ::java::util::AbstractList;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $KdcComm = ::sun::security::krb5::KdcComm;
using $KdcComm$BpType = ::sun::security::krb5::KdcComm$BpType;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KdcComm$KdcAccessibility_FieldInfo_[] = {
	{"bads", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticField(KdcComm$KdcAccessibility, bads)},
	{}
};

$MethodInfo _KdcComm$KdcAccessibility_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(KdcComm$KdcAccessibility::*)()>(&KdcComm$KdcAccessibility::init$))},
	{"addBad", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)($String*)>(&KdcComm$KdcAccessibility::addBad))},
	{"isBad", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<bool(*)($String*)>(&KdcComm$KdcAccessibility::isBad))},
	{"list", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<$List*(*)($String*)>(&KdcComm$KdcAccessibility::list))},
	{"removeBad", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)($String*)>(&KdcComm$KdcAccessibility::removeBad))},
	{"reset", "()V", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)()>(&KdcComm$KdcAccessibility::reset))},
	{}
};

$InnerClassInfo _KdcComm$KdcAccessibility_InnerClassesInfo_[] = {
	{"sun.security.krb5.KdcComm$KdcAccessibility", "sun.security.krb5.KdcComm", "KdcAccessibility", $STATIC},
	{}
};

$ClassInfo _KdcComm$KdcAccessibility_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.KdcComm$KdcAccessibility",
	"java.lang.Object",
	nullptr,
	_KdcComm$KdcAccessibility_FieldInfo_,
	_KdcComm$KdcAccessibility_MethodInfo_,
	nullptr,
	nullptr,
	_KdcComm$KdcAccessibility_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.KdcComm"
};

$Object* allocate$KdcComm$KdcAccessibility($Class* clazz) {
	return $of($alloc(KdcComm$KdcAccessibility));
}

$Set* KdcComm$KdcAccessibility::bads = nullptr;

void KdcComm$KdcAccessibility::init$() {
}

void KdcComm$KdcAccessibility::addBad($String* kdc) {
	$load(KdcComm$KdcAccessibility);
	$synchronized(class$) {
		$init(KdcComm$KdcAccessibility);
		$init($KdcComm);
		if ($KdcComm::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>> KdcAccessibility: add "_s, kdc}));
		}
		$nc(KdcComm$KdcAccessibility::bads)->add(kdc);
	}
}

void KdcComm$KdcAccessibility::removeBad($String* kdc) {
	$load(KdcComm$KdcAccessibility);
	$synchronized(class$) {
		$init(KdcComm$KdcAccessibility);
		$init($KdcComm);
		if ($KdcComm::DEBUG) {
			$init($System);
			$nc($System::out)->println($$str({">>> KdcAccessibility: remove "_s, kdc}));
		}
		$nc(KdcComm$KdcAccessibility::bads)->remove(kdc);
	}
}

bool KdcComm$KdcAccessibility::isBad($String* kdc) {
	$load(KdcComm$KdcAccessibility);
	$synchronized(class$) {
		$init(KdcComm$KdcAccessibility);
		return $nc(KdcComm$KdcAccessibility::bads)->contains(kdc);
	}
}

void KdcComm$KdcAccessibility::reset() {
	$load(KdcComm$KdcAccessibility);
	$synchronized(class$) {
		$init(KdcComm$KdcAccessibility);
		$init($KdcComm);
		if ($KdcComm::DEBUG) {
			$init($System);
			$nc($System::out)->println(">>> KdcAccessibility: reset"_s);
		}
		$nc(KdcComm$KdcAccessibility::bads)->clear();
	}
}

$List* KdcComm$KdcAccessibility::list($String* kdcList) {
	$load(KdcComm$KdcAccessibility);
	$synchronized(class$) {
		$init(KdcComm$KdcAccessibility);
		$var($StringTokenizer, st, $new($StringTokenizer, kdcList));
		$var($List, list, $new($ArrayList));
		$init($KdcComm);
		$init($KdcComm$BpType);
		if ($KdcComm::badPolicy == $KdcComm$BpType::TRY_LAST) {
			$var($List, badkdcs, $new($ArrayList));
			while (st->hasMoreTokens()) {
				$var($String, t, st->nextToken());
				if ($nc(KdcComm$KdcAccessibility::bads)->contains(t)) {
					badkdcs->add(t);
				} else {
					list->add(t);
				}
			}
			list->addAll(badkdcs);
		} else {
			while (st->hasMoreTokens()) {
				list->add($(st->nextToken()));
			}
		}
		return list;
	}
}

void clinit$KdcComm$KdcAccessibility($Class* class$) {
	$assignStatic(KdcComm$KdcAccessibility::bads, $new($HashSet));
}

KdcComm$KdcAccessibility::KdcComm$KdcAccessibility() {
}

$Class* KdcComm$KdcAccessibility::load$($String* name, bool initialize) {
	$loadClass(KdcComm$KdcAccessibility, name, initialize, &_KdcComm$KdcAccessibility_ClassInfo_, clinit$KdcComm$KdcAccessibility, allocate$KdcComm$KdcAccessibility);
	return class$;
}

$Class* KdcComm$KdcAccessibility::class$ = nullptr;

		} // krb5
	} // security
} // sun