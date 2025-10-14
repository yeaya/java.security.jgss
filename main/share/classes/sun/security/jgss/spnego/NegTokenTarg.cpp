#include <sun/security/jgss/spnego/NegTokenTarg.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/GSSToken.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/spnego/SpNegoToken.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef DEBUG
#undef DEFECTIVE_TOKEN
#undef NEG_TOKEN_TARG_ID
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSException = ::org::ietf::jgss::GSSException;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $SpNegoToken = ::sun::security::jgss::spnego::SpNegoToken;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

$FieldInfo _NegTokenTarg_FieldInfo_[] = {
	{"negResult", "I", nullptr, $PRIVATE, $field(NegTokenTarg, negResult)},
	{"supportedMech", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(NegTokenTarg, supportedMech)},
	{"responseToken", "[B", nullptr, $PRIVATE, $field(NegTokenTarg, responseToken)},
	{"mechListMIC", "[B", nullptr, $PRIVATE, $field(NegTokenTarg, mechListMIC)},
	{}
};

$MethodInfo _NegTokenTarg_MethodInfo_[] = {
	{"<init>", "(ILorg/ietf/jgss/Oid;[B[B)V", nullptr, 0, $method(static_cast<void(NegTokenTarg::*)(int32_t,$Oid*,$bytes*,$bytes*)>(&NegTokenTarg::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(NegTokenTarg::*)($bytes*)>(&NegTokenTarg::init$)), "org.ietf.jgss.GSSException"},
	{"encode", "()[B", nullptr, $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechListMIC", "()[B", nullptr, 0},
	{"getNegotiatedResult", "()I", nullptr, 0},
	{"getResponseToken", "()[B", nullptr, 0},
	{"getSupportedMech", "()Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"parseToken", "([B)V", nullptr, $PRIVATE, $method(static_cast<void(NegTokenTarg::*)($bytes*)>(&NegTokenTarg::parseToken)), "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _NegTokenTarg_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.spnego.NegTokenTarg",
	"sun.security.jgss.spnego.SpNegoToken",
	nullptr,
	_NegTokenTarg_FieldInfo_,
	_NegTokenTarg_MethodInfo_
};

$Object* allocate$NegTokenTarg($Class* clazz) {
	return $of($alloc(NegTokenTarg));
}

void NegTokenTarg::init$(int32_t result, $Oid* mech, $bytes* token, $bytes* mechListMIC) {
	$SpNegoToken::init$($SpNegoToken::NEG_TOKEN_TARG_ID);
	this->negResult = 0;
	$set(this, supportedMech, nullptr);
	$set(this, responseToken, nullptr);
	$set(this, mechListMIC, nullptr);
	this->negResult = result;
	$set(this, supportedMech, mech);
	$set(this, responseToken, token);
	$set(this, mechListMIC, mechListMIC);
}

void NegTokenTarg::init$($bytes* in) {
	$SpNegoToken::init$($SpNegoToken::NEG_TOKEN_TARG_ID);
	this->negResult = 0;
	$set(this, supportedMech, nullptr);
	$set(this, responseToken, nullptr);
	$set(this, mechListMIC, nullptr);
	parseToken(in);
}

$bytes* NegTokenTarg::encode() {
	try {
		$var($DerOutputStream, targToken, $new($DerOutputStream));
		$var($DerOutputStream, result, $new($DerOutputStream));
		result->putEnumerated(this->negResult);
		targToken->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), result);
		if (this->supportedMech != nullptr) {
			$var($DerOutputStream, mech, $new($DerOutputStream));
			$var($bytes, mechType, $nc(this->supportedMech)->getDER());
			mech->write(mechType);
			targToken->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), mech);
		}
		if (this->responseToken != nullptr) {
			$var($DerOutputStream, rspToken, $new($DerOutputStream));
			rspToken->putOctetString(this->responseToken);
			targToken->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), rspToken);
		}
		if (this->mechListMIC != nullptr) {
			$init($SpNegoToken);
			if ($SpNegoToken::DEBUG) {
				$init($System);
				$nc($System::out)->println("SpNegoToken NegTokenTarg: sending MechListMIC"_s);
			}
			$var($DerOutputStream, mic, $new($DerOutputStream));
			mic->putOctetString(this->mechListMIC);
			targToken->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3), mic);
		}
		$var($DerOutputStream, out, $new($DerOutputStream));
		out->write($DerValue::tag_Sequence, targToken);
		return out->toByteArray();
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({"Invalid SPNEGO NegTokenTarg token : "_s, $(e->getMessage())}));
	}
	$shouldNotReachHere();
}

void NegTokenTarg::parseToken($bytes* in) {
	try {
		$var($DerValue, der, $new($DerValue, in));
		if (!der->isContextSpecific((int8_t)$SpNegoToken::NEG_TOKEN_TARG_ID)) {
			$throwNew($IOException, "SPNEGO NegoTokenTarg : did not have the right token type"_s);
		}
		$var($DerValue, tmp1, $nc(der->data$)->getDerValue());
		if ($nc(tmp1)->tag != $DerValue::tag_Sequence) {
			$throwNew($IOException, "SPNEGO NegoTokenTarg : did not have the Sequence tag"_s);
		}
		int32_t lastField = -1;
		while ($nc($nc(tmp1)->data$)->available() > 0) {
			$var($DerValue, tmp2, $nc(tmp1->data$)->getDerValue());
			if ($nc(tmp2)->isContextSpecific((int8_t)0)) {
				lastField = checkNextField(lastField, 0);
				this->negResult = $nc(tmp2->data$)->getEnumerated();
				$init($SpNegoToken);
				if ($SpNegoToken::DEBUG) {
					$init($System);
					$nc($System::out)->println($$str({"SpNegoToken NegTokenTarg: negotiated result = "_s, $(getNegoResultString(this->negResult))}));
				}
			} else if (tmp2->isContextSpecific((int8_t)1)) {
				lastField = checkNextField(lastField, 1);
				$var($ObjectIdentifier, mech, $nc(tmp2->data$)->getOID());
				$set(this, supportedMech, $new($Oid, $($nc(mech)->toString())));
				$init($SpNegoToken);
				if ($SpNegoToken::DEBUG) {
					$init($System);
					$nc($System::out)->println($$str({"SpNegoToken NegTokenTarg: supported mechanism = "_s, this->supportedMech}));
				}
			} else if (tmp2->isContextSpecific((int8_t)2)) {
				lastField = checkNextField(lastField, 2);
				$set(this, responseToken, $nc(tmp2->data$)->getOctetString());
			} else if (tmp2->isContextSpecific((int8_t)3)) {
				lastField = checkNextField(lastField, 3);
				if (!$GSSUtil::useMSInterop()) {
					$set(this, mechListMIC, $nc(tmp2->data$)->getOctetString());
					$init($SpNegoToken);
					if ($SpNegoToken::DEBUG) {
						$init($System);
						$nc($System::out)->println($$str({"SpNegoToken NegTokenTarg: MechListMIC Token = "_s, $(getHexBytes(this->mechListMIC))}));
					}
				}
			}
		}
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({"Invalid SPNEGO NegTokenTarg token : "_s, $(e->getMessage())}));
	}
}

int32_t NegTokenTarg::getNegotiatedResult() {
	return this->negResult;
}

$Oid* NegTokenTarg::getSupportedMech() {
	return this->supportedMech;
}

$bytes* NegTokenTarg::getResponseToken() {
	return this->responseToken;
}

$bytes* NegTokenTarg::getMechListMIC() {
	return this->mechListMIC;
}

NegTokenTarg::NegTokenTarg() {
}

$Class* NegTokenTarg::load$($String* name, bool initialize) {
	$loadClass(NegTokenTarg, name, initialize, &_NegTokenTarg_ClassInfo_, allocate$NegTokenTarg);
	return class$;
}

$Class* NegTokenTarg::class$ = nullptr;

			} // spnego
		} // jgss
	} // security
} // sun