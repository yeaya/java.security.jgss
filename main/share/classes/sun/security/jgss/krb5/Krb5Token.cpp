#include <sun/security/jgss/krb5/Krb5Token.h>

#include <java/io/IOException.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSToken.h>
#include <sun/security/jgss/krb5/Krb5MechFactory.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef AP_REP_ID
#undef AP_REQ_ID
#undef ERR_ID
#undef GSS_KRB5_MECH_OID
#undef MIC_ID
#undef OID
#undef WRAP_ID

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $Krb5MechFactory = ::sun::security::jgss::krb5::Krb5MechFactory;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _Krb5Token_FieldInfo_[] = {
	{"AP_REQ_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5Token, AP_REQ_ID)},
	{"AP_REP_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5Token, AP_REP_ID)},
	{"ERR_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5Token, ERR_ID)},
	{"MIC_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5Token, MIC_ID)},
	{"WRAP_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5Token, WRAP_ID)},
	{"MIC_ID_v2", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5Token, MIC_ID_v2)},
	{"WRAP_ID_v2", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5Token, WRAP_ID_v2)},
	{"OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC, $staticField(Krb5Token, OID)},
	{}
};

$MethodInfo _Krb5Token_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Krb5Token::*)()>(&Krb5Token::init$))},
	{"getTokenName", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)(int32_t)>(&Krb5Token::getTokenName))},
	{}
};

$ClassInfo _Krb5Token_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.jgss.krb5.Krb5Token",
	"sun.security.jgss.GSSToken",
	nullptr,
	_Krb5Token_FieldInfo_,
	_Krb5Token_MethodInfo_
};

$Object* allocate$Krb5Token($Class* clazz) {
	return $of($alloc(Krb5Token));
}


$ObjectIdentifier* Krb5Token::OID = nullptr;

void Krb5Token::init$() {
	$GSSToken::init$();
}

$String* Krb5Token::getTokenName(int32_t tokenId) {
	$init(Krb5Token);
	$var($String, retVal, nullptr);
	switch (tokenId) {
	case Krb5Token::AP_REQ_ID:
		{}
	case Krb5Token::AP_REP_ID:
		{
			$assign(retVal, "Context Establishment Token"_s);
			break;
		}
	case Krb5Token::MIC_ID:
		{
			$assign(retVal, "MIC Token"_s);
			break;
		}
	case Krb5Token::MIC_ID_v2:
		{
			$assign(retVal, "MIC Token (new format)"_s);
			break;
		}
	case Krb5Token::WRAP_ID:
		{
			$assign(retVal, "Wrap Token"_s);
			break;
		}
	case Krb5Token::WRAP_ID_v2:
		{
			$assign(retVal, "Wrap Token (new format)"_s);
			break;
		}
	default:
		{
			$assign(retVal, "Kerberos GSS-API Mechanism Token"_s);
			break;
		}
	}
	return retVal;
}

void clinit$Krb5Token($Class* class$) {
	{
		try {
			$init($Krb5MechFactory);
			$assignStatic(Krb5Token::OID, $ObjectIdentifier::of($($nc($Krb5MechFactory::GSS_KRB5_MECH_OID)->toString())));
		} catch ($IOException&) {
			$catch();
		}
	}
}

Krb5Token::Krb5Token() {
}

$Class* Krb5Token::load$($String* name, bool initialize) {
	$loadClass(Krb5Token, name, initialize, &_Krb5Token_ClassInfo_, clinit$Krb5Token, allocate$Krb5Token);
	return class$;
}

$Class* Krb5Token::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun