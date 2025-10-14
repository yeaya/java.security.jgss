#include <sun/security/krb5/KrbServiceLocator$SrvRecord.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/StringTokenizer.h>
#include <sun/security/krb5/KrbServiceLocator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $StringTokenizer = ::java::util::StringTokenizer;
using $KrbServiceLocator = ::sun::security::krb5::KrbServiceLocator;

namespace sun {
	namespace security {
		namespace krb5 {

$FieldInfo _KrbServiceLocator$SrvRecord_FieldInfo_[] = {
	{"priority", "I", nullptr, 0, $field(KrbServiceLocator$SrvRecord, priority)},
	{"weight", "I", nullptr, 0, $field(KrbServiceLocator$SrvRecord, weight)},
	{"sum", "I", nullptr, 0, $field(KrbServiceLocator$SrvRecord, sum)},
	{"hostport", "Ljava/lang/String;", nullptr, 0, $field(KrbServiceLocator$SrvRecord, hostport)},
	{}
};

$MethodInfo _KrbServiceLocator$SrvRecord_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(KrbServiceLocator$SrvRecord::*)($String*)>(&KrbServiceLocator$SrvRecord::init$)), "java.lang.Exception"},
	{"compareTo", "(Lsun/security/krb5/KrbServiceLocator$SrvRecord;)I", nullptr, $PUBLIC},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{}
};

$InnerClassInfo _KrbServiceLocator$SrvRecord_InnerClassesInfo_[] = {
	{"sun.security.krb5.KrbServiceLocator$SrvRecord", "sun.security.krb5.KrbServiceLocator", "SrvRecord", $STATIC},
	{}
};

$ClassInfo _KrbServiceLocator$SrvRecord_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.KrbServiceLocator$SrvRecord",
	"java.lang.Object",
	"java.lang.Comparable",
	_KrbServiceLocator$SrvRecord_FieldInfo_,
	_KrbServiceLocator$SrvRecord_MethodInfo_,
	"Ljava/lang/Object;Ljava/lang/Comparable<Lsun/security/krb5/KrbServiceLocator$SrvRecord;>;",
	nullptr,
	_KrbServiceLocator$SrvRecord_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.KrbServiceLocator"
};

$Object* allocate$KrbServiceLocator$SrvRecord($Class* clazz) {
	return $of($alloc(KrbServiceLocator$SrvRecord));
}

void KrbServiceLocator$SrvRecord::init$($String* srvRecord) {
	$var($StringTokenizer, tokenizer, $new($StringTokenizer, srvRecord, " "_s));
	$var($String, port, nullptr);
	if (tokenizer->countTokens() == 4) {
		this->priority = $Integer::parseInt($(tokenizer->nextToken()));
		this->weight = $Integer::parseInt($(tokenizer->nextToken()));
		$assign(port, tokenizer->nextToken());
		$set(this, hostport, $str({$(tokenizer->nextToken()), ":"_s, port}));
	} else {
		$throwNew($IllegalArgumentException);
	}
}

int32_t KrbServiceLocator$SrvRecord::compareTo(KrbServiceLocator$SrvRecord* that) {
	if (this->priority > $nc(that)->priority) {
		return 1;
	} else if (this->priority < that->priority) {
		return -1;
	} else if (this->weight == 0 && that->weight != 0) {
		return -1;
	} else if (this->weight != 0 && that->weight == 0) {
		return 1;
	} else {
		return 0;
	}
}

int32_t KrbServiceLocator$SrvRecord::compareTo(Object$* that) {
	return this->compareTo($cast(KrbServiceLocator$SrvRecord, that));
}

KrbServiceLocator$SrvRecord::KrbServiceLocator$SrvRecord() {
}

$Class* KrbServiceLocator$SrvRecord::load$($String* name, bool initialize) {
	$loadClass(KrbServiceLocator$SrvRecord, name, initialize, &_KrbServiceLocator$SrvRecord_ClassInfo_, allocate$KrbServiceLocator$SrvRecord);
	return class$;
}

$Class* KrbServiceLocator$SrvRecord::class$ = nullptr;

		} // krb5
	} // security
} // sun