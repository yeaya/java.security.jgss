#include <sun/security/jgss/HttpCaller.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/net/www/protocol/http/HttpCallerInfo.h>
#include <sun/security/jgss/GSSCaller.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpCallerInfo = ::sun::net::www::protocol::http::HttpCallerInfo;
using $GSSCaller = ::sun::security::jgss::GSSCaller;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _HttpCaller_FieldInfo_[] = {
	{"hci", "Lsun/net/www/protocol/http/HttpCallerInfo;", nullptr, $PRIVATE | $FINAL, $field(HttpCaller, hci)},
	{}
};

$MethodInfo _HttpCaller_MethodInfo_[] = {
	{"<init>", "(Lsun/net/www/protocol/http/HttpCallerInfo;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpCaller::*)($HttpCallerInfo*)>(&HttpCaller::init$))},
	{"info", "()Lsun/net/www/protocol/http/HttpCallerInfo;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _HttpCaller_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.HttpCaller",
	"sun.security.jgss.GSSCaller",
	nullptr,
	_HttpCaller_FieldInfo_,
	_HttpCaller_MethodInfo_
};

$Object* allocate$HttpCaller($Class* clazz) {
	return $of($alloc(HttpCaller));
}

void HttpCaller::init$($HttpCallerInfo* hci) {
	$GSSCaller::init$("HTTP_CLIENT"_s);
	$set(this, hci, hci);
}

$HttpCallerInfo* HttpCaller::info() {
	return this->hci;
}

HttpCaller::HttpCaller() {
}

$Class* HttpCaller::load$($String* name, bool initialize) {
	$loadClass(HttpCaller, name, initialize, &_HttpCaller_ClassInfo_, allocate$HttpCaller);
	return class$;
}

$Class* HttpCaller::class$ = nullptr;

		} // jgss
	} // security
} // sun