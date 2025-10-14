#include <org/ietf/jgss/ChannelBinding.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/net/InetAddress.h>
#include <java/util/Arrays.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $Arrays = ::java::util::Arrays;

namespace org {
	namespace ietf {
		namespace jgss {

$FieldInfo _ChannelBinding_FieldInfo_[] = {
	{"initiator", "Ljava/net/InetAddress;", nullptr, $PRIVATE, $field(ChannelBinding, initiator)},
	{"acceptor", "Ljava/net/InetAddress;", nullptr, $PRIVATE, $field(ChannelBinding, acceptor)},
	{"appData", "[B", nullptr, $PRIVATE, $field(ChannelBinding, appData)},
	{}
};

$MethodInfo _ChannelBinding_MethodInfo_[] = {
	{"<init>", "(Ljava/net/InetAddress;Ljava/net/InetAddress;[B)V", nullptr, $PUBLIC, $method(static_cast<void(ChannelBinding::*)($InetAddress*,$InetAddress*,$bytes*)>(&ChannelBinding::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(ChannelBinding::*)($bytes*)>(&ChannelBinding::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getAcceptorAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC},
	{"getApplicationData", "()[B", nullptr, $PUBLIC},
	{"getInitiatorAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ChannelBinding_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"org.ietf.jgss.ChannelBinding",
	"java.lang.Object",
	nullptr,
	_ChannelBinding_FieldInfo_,
	_ChannelBinding_MethodInfo_
};

$Object* allocate$ChannelBinding($Class* clazz) {
	return $of($alloc(ChannelBinding));
}

void ChannelBinding::init$($InetAddress* initAddr, $InetAddress* acceptAddr, $bytes* appData) {
	$set(this, initiator, initAddr);
	$set(this, acceptor, acceptAddr);
	if (appData != nullptr) {
		$set(this, appData, $new($bytes, appData->length));
		$System::arraycopy(appData, 0, this->appData, 0, appData->length);
	}
}

void ChannelBinding::init$($bytes* appData) {
	ChannelBinding::init$(nullptr, nullptr, appData);
}

$InetAddress* ChannelBinding::getInitiatorAddress() {
	return this->initiator;
}

$InetAddress* ChannelBinding::getAcceptorAddress() {
	return this->acceptor;
}

$bytes* ChannelBinding::getApplicationData() {
	if (this->appData == nullptr) {
		return nullptr;
	}
	$var($bytes, retVal, $new($bytes, $nc(this->appData)->length));
	$System::arraycopy(this->appData, 0, retVal, 0, $nc(this->appData)->length);
	return retVal;
}

bool ChannelBinding::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(ChannelBinding, obj))) {
		return false;
	}
	$var(ChannelBinding, cb, $cast(ChannelBinding, obj));
	if ((this->initiator != nullptr && $nc(cb)->initiator == nullptr) || (this->initiator == nullptr && $nc(cb)->initiator != nullptr)) {
		return false;
	}
	if (this->initiator != nullptr && !$nc(this->initiator)->equals($nc(cb)->initiator)) {
		return false;
	}
	if ((this->acceptor != nullptr && $nc(cb)->acceptor == nullptr) || (this->acceptor == nullptr && $nc(cb)->acceptor != nullptr)) {
		return false;
	}
	if (this->acceptor != nullptr && !$nc(this->acceptor)->equals($nc(cb)->acceptor)) {
		return false;
	}
	return $Arrays::equals(this->appData, $nc(cb)->appData);
}

int32_t ChannelBinding::hashCode() {
	if (this->initiator != nullptr) {
		return $nc(this->initiator)->hashCode();
	} else if (this->acceptor != nullptr) {
		return $nc(this->acceptor)->hashCode();
	} else if (this->appData != nullptr) {
		return $$new($String, this->appData)->hashCode();
	} else {
		return 1;
	}
}

ChannelBinding::ChannelBinding() {
}

$Class* ChannelBinding::load$($String* name, bool initialize) {
	$loadClass(ChannelBinding, name, initialize, &_ChannelBinding_ClassInfo_, allocate$ChannelBinding);
	return class$;
}

$Class* ChannelBinding::class$ = nullptr;

		} // jgss
	} // ietf
} // org