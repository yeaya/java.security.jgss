#include <sun/security/jgss/GSSUtil$1.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/EnclosingMethodInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/AccessControlContext.h>
#include <java/util/Iterator.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <javax/security/auth/Subject.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSCredentialImpl.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessControlContext = ::java::security::AccessControlContext;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Iterator = ::java::util::Iterator;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;
using $Subject = ::javax::security::auth::Subject;
using $GSSException = ::org::ietf::jgss::GSSException;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSCredentialImpl = ::sun::security::jgss::GSSCredentialImpl;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $GSSCredentialSpi = ::sun::security::jgss::spi::GSSCredentialSpi;
using $GSSNameSpi = ::sun::security::jgss::spi::GSSNameSpi;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _GSSUtil$1_FieldInfo_[] = {
	{"val$name", "Lsun/security/jgss/spi/GSSNameSpi;", nullptr, $FINAL | $SYNTHETIC, $field(GSSUtil$1, val$name)},
	{"val$credCls", "Ljava/lang/Class;", nullptr, $FINAL | $SYNTHETIC, $field(GSSUtil$1, val$credCls)},
	{"val$initiate", "Z", nullptr, $FINAL | $SYNTHETIC, $field(GSSUtil$1, val$initiate)},
	{"val$mech", "Lorg/ietf/jgss/Oid;", nullptr, $FINAL | $SYNTHETIC, $field(GSSUtil$1, val$mech)},
	{"val$acc", "Ljava/security/AccessControlContext;", nullptr, $FINAL | $SYNTHETIC, $field(GSSUtil$1, val$acc)},
	{}
};

$MethodInfo _GSSUtil$1_MethodInfo_[] = {
	{"<init>", "(Ljava/security/AccessControlContext;Lorg/ietf/jgss/Oid;ZLjava/lang/Class;Lsun/security/jgss/spi/GSSNameSpi;)V", "()V", 0, $method(static_cast<void(GSSUtil$1::*)($AccessControlContext*,$Oid*,bool,$Class*,$GSSNameSpi*)>(&GSSUtil$1::init$))},
	{"run", "()Ljava/util/Vector;", "()Ljava/util/Vector<TT;>;", $PUBLIC, nullptr, "java.lang.Exception"},
	{}
};

$EnclosingMethodInfo _GSSUtil$1_EnclosingMethodInfo_ = {
	"sun.security.jgss.GSSUtil",
	"searchSubject",
	"(Lsun/security/jgss/spi/GSSNameSpi;Lorg/ietf/jgss/Oid;ZLjava/lang/Class;)Ljava/util/Vector;"
};

$InnerClassInfo _GSSUtil$1_InnerClassesInfo_[] = {
	{"sun.security.jgss.GSSUtil$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _GSSUtil$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.GSSUtil$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_GSSUtil$1_FieldInfo_,
	_GSSUtil$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/util/Vector<TT;>;>;",
	&_GSSUtil$1_EnclosingMethodInfo_,
	_GSSUtil$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.GSSUtil"
};

$Object* allocate$GSSUtil$1($Class* clazz) {
	return $of($alloc(GSSUtil$1));
}

void GSSUtil$1::init$($AccessControlContext* val$acc, $Oid* val$mech, bool val$initiate, $Class* val$credCls, $GSSNameSpi* val$name) {
	$set(this, val$acc, val$acc);
	$set(this, val$mech, val$mech);
	this->val$initiate = val$initiate;
	$set(this, val$credCls, val$credCls);
	$set(this, val$name, val$name);
}

$Object* GSSUtil$1::run() {
	$var($Subject, accSubj, $Subject::getSubject(this->val$acc));
	$var($Vector, result, nullptr);
	if (accSubj != nullptr) {
		$assign(result, $new($Vector));
		$load($GSSCredentialImpl);
		$var($Iterator, iterator, $nc($(accSubj->getPrivateCredentials($GSSCredentialImpl::class$)))->iterator());
		while ($nc(iterator)->hasNext()) {
			$var($GSSCredentialImpl, cred, $cast($GSSCredentialImpl, iterator->next()));
			$GSSUtil::debug($$str({"...Found cred"_s, cred}));
			try {
				$var($GSSCredentialSpi, ce, $nc(cred)->getElement(this->val$mech, this->val$initiate));
				$GSSUtil::debug($$str({"......Found element: "_s, ce}));
				bool var$0 = $of($nc($of(ce))->getClass())->equals(this->val$credCls);
				if (var$0 && (this->val$name == nullptr || $nc(this->val$name)->equals($of($($nc(ce)->getName()))))) {
					result->add($cast($GSSCredentialSpi, $($nc(this->val$credCls)->cast(ce))));
				} else {
					$GSSUtil::debug("......Discard element"_s);
				}
			} catch ($GSSException&) {
				$var($GSSException, ge, $catch());
				$GSSUtil::debug($$str({"...Discard cred ("_s, ge, ")"_s}));
			}
		}
	} else {
		$GSSUtil::debug("No Subject"_s);
	}
	return $of(result);
}

GSSUtil$1::GSSUtil$1() {
}

$Class* GSSUtil$1::load$($String* name, bool initialize) {
	$loadClass(GSSUtil$1, name, initialize, &_GSSUtil$1_ClassInfo_, allocate$GSSUtil$1);
	return class$;
}

$Class* GSSUtil$1::class$ = nullptr;

		} // jgss
	} // security
} // sun