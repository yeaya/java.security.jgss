#include <org/ietf/jgss/Oid.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSException.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef FAILURE

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSException = ::org::ietf::jgss::GSSException;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace org {
	namespace ietf {
		namespace jgss {

$FieldInfo _Oid_FieldInfo_[] = {
	{"oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE, $field(Oid, oid)},
	{"derEncoding", "[B", nullptr, $PRIVATE, $field(Oid, derEncoding)},
	{}
};

$MethodInfo _Oid_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Oid::*)($String*)>(&Oid::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(Oid::*)($InputStream*)>(&Oid::init$)), "org.ietf.jgss.GSSException"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(Oid::*)($bytes*)>(&Oid::init$)), "org.ietf.jgss.GSSException"},
	{"containedIn", "([Lorg/ietf/jgss/Oid;)Z", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getDER", "()[B", nullptr, $PUBLIC, nullptr, "org.ietf.jgss.GSSException"},
	{"getInstance", "(Ljava/lang/String;)Lorg/ietf/jgss/Oid;", nullptr, $STATIC, $method(static_cast<Oid*(*)($String*)>(&Oid::getInstance))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Oid_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"org.ietf.jgss.Oid",
	"java.lang.Object",
	nullptr,
	_Oid_FieldInfo_,
	_Oid_MethodInfo_
};

$Object* allocate$Oid($Class* clazz) {
	return $of($alloc(Oid));
}

void Oid::init$($String* strOid) {
	try {
		$set(this, oid, $ObjectIdentifier::of(strOid));
		$set(this, derEncoding, nullptr);
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$throwNew($GSSException, $GSSException::FAILURE, $$str({"Improperly formatted Object Identifier String - "_s, strOid}));
	}
}

void Oid::init$($InputStream* derOid) {
	try {
		$var($DerValue, derVal, $new($DerValue, derOid));
		$set(this, derEncoding, derVal->toByteArray());
		$set(this, oid, derVal->getOID());
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSException, $GSSException::FAILURE, "Improperly formatted ASN.1 DER encoding for Oid"_s);
	}
}

void Oid::init$($bytes* data) {
	try {
		$var($DerValue, derVal, $new($DerValue, data));
		$set(this, derEncoding, derVal->toByteArray());
		$set(this, oid, derVal->getOID());
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSException, $GSSException::FAILURE, "Improperly formatted ASN.1 DER encoding for Oid"_s);
	}
}

Oid* Oid::getInstance($String* strOid) {
	$var(Oid, retVal, nullptr);
	try {
		$assign(retVal, $new(Oid, strOid));
	} catch ($GSSException&) {
		$catch();
	}
	return retVal;
}

$String* Oid::toString() {
	return $nc(this->oid)->toString();
}

bool Oid::equals(Object$* other) {
	if ($equals(this, other)) {
		return (true);
	}
	if ($instanceOf(Oid, other)) {
		return $nc(this->oid)->equals($nc(($cast(Oid, other)))->oid);
	} else if ($instanceOf($ObjectIdentifier, other)) {
		return $nc(this->oid)->equals(other);
	} else {
		return false;
	}
}

$bytes* Oid::getDER() {
	if (this->derEncoding == nullptr) {
		$var($DerOutputStream, dout, $new($DerOutputStream));
		try {
			dout->putOID(this->oid);
		} catch ($IOException&) {
			$var($IOException, e, $catch());
			$throwNew($GSSException, $GSSException::FAILURE, $(e->getMessage()));
		}
		$set(this, derEncoding, dout->toByteArray());
	}
	return $cast($bytes, $nc(this->derEncoding)->clone());
}

bool Oid::containedIn($OidArray* oids) {
	for (int32_t i = 0; i < $nc(oids)->length; ++i) {
		if ($nc(oids->get(i))->equals(this)) {
			return (true);
		}
	}
	return (false);
}

int32_t Oid::hashCode() {
	return $nc(this->oid)->hashCode();
}

Oid::Oid() {
}

$Class* Oid::load$($String* name, bool initialize) {
	$loadClass(Oid, name, initialize, &_Oid_ClassInfo_, allocate$Oid);
	return class$;
}

$Class* Oid::class$ = nullptr;

		} // jgss
	} // ietf
} // org