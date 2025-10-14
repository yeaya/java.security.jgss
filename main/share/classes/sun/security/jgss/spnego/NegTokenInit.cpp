#include <sun/security/jgss/spnego/NegTokenInit.h>

#include <java/io/IOException.h>
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
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef DEBUG
#undef DEFECTIVE_TOKEN
#undef NEG_TOKEN_INIT_ID
#undef TAG_CONTEXT

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSException = ::org::ietf::jgss::GSSException;
using $Oid = ::org::ietf::jgss::Oid;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $GSSUtil = ::sun::security::jgss::GSSUtil;
using $SpNegoToken = ::sun::security::jgss::spnego::SpNegoToken;
using $BitArray = ::sun::security::util::BitArray;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

$FieldInfo _NegTokenInit_FieldInfo_[] = {
	{"mechTypes", "[B", nullptr, $PRIVATE, $field(NegTokenInit, mechTypes)},
	{"mechTypeList", "[Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(NegTokenInit, mechTypeList)},
	{"reqFlags", "Lsun/security/util/BitArray;", nullptr, $PRIVATE, $field(NegTokenInit, reqFlags)},
	{"mechToken", "[B", nullptr, $PRIVATE, $field(NegTokenInit, mechToken)},
	{"mechListMIC", "[B", nullptr, $PRIVATE, $field(NegTokenInit, mechListMIC)},
	{}
};

$MethodInfo _NegTokenInit_MethodInfo_[] = {
	{"<init>", "([BLsun/security/util/BitArray;[B[B)V", nullptr, 0, $method(static_cast<void(NegTokenInit::*)($bytes*,$BitArray*,$bytes*,$bytes*)>(&NegTokenInit::init$))},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(NegTokenInit::*)($bytes*)>(&NegTokenInit::init$)), "org.ietf.jgss.GSSException"},
	{"encode", "()[B", nullptr, $FINAL, nullptr, "org.ietf.jgss.GSSException"},
	{"getMechListMIC", "()[B", nullptr, 0},
	{"getMechToken", "()[B", nullptr, $PUBLIC},
	{"getMechTypeList", "()[Lorg/ietf/jgss/Oid;", nullptr, $PUBLIC},
	{"getMechTypes", "()[B", nullptr, 0},
	{"getReqFlags", "()Lsun/security/util/BitArray;", nullptr, 0},
	{"parseToken", "([B)V", nullptr, $PRIVATE, $method(static_cast<void(NegTokenInit::*)($bytes*)>(&NegTokenInit::parseToken)), "org.ietf.jgss.GSSException"},
	{}
};

$ClassInfo _NegTokenInit_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.spnego.NegTokenInit",
	"sun.security.jgss.spnego.SpNegoToken",
	nullptr,
	_NegTokenInit_FieldInfo_,
	_NegTokenInit_MethodInfo_
};

$Object* allocate$NegTokenInit($Class* clazz) {
	return $of($alloc(NegTokenInit));
}

void NegTokenInit::init$($bytes* mechTypes, $BitArray* flags, $bytes* token, $bytes* mechListMIC) {
	$SpNegoToken::init$($SpNegoToken::NEG_TOKEN_INIT_ID);
	$set(this, mechTypes, nullptr);
	$set(this, mechTypeList, nullptr);
	$set(this, reqFlags, nullptr);
	$set(this, mechToken, nullptr);
	$set(this, mechListMIC, nullptr);
	$set(this, mechTypes, mechTypes);
	$set(this, reqFlags, flags);
	$set(this, mechToken, token);
	$set(this, mechListMIC, mechListMIC);
}

void NegTokenInit::init$($bytes* in) {
	$SpNegoToken::init$($SpNegoToken::NEG_TOKEN_INIT_ID);
	$set(this, mechTypes, nullptr);
	$set(this, mechTypeList, nullptr);
	$set(this, reqFlags, nullptr);
	$set(this, mechToken, nullptr);
	$set(this, mechListMIC, nullptr);
	parseToken(in);
}

$bytes* NegTokenInit::encode() {
	try {
		$var($DerOutputStream, initToken, $new($DerOutputStream));
		if (this->mechTypes != nullptr) {
			initToken->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), this->mechTypes);
		}
		if (this->reqFlags != nullptr) {
			$var($DerOutputStream, flags, $new($DerOutputStream));
			flags->putUnalignedBitString(this->reqFlags);
			initToken->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), flags);
		}
		if (this->mechToken != nullptr) {
			$var($DerOutputStream, dataValue, $new($DerOutputStream));
			dataValue->putOctetString(this->mechToken);
			initToken->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2), dataValue);
		}
		if (this->mechListMIC != nullptr) {
			$init($SpNegoToken);
			if ($SpNegoToken::DEBUG) {
				$init($System);
				$nc($System::out)->println("SpNegoToken NegTokenInit: sending MechListMIC"_s);
			}
			$var($DerOutputStream, mic, $new($DerOutputStream));
			mic->putOctetString(this->mechListMIC);
			initToken->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3), mic);
		}
		$var($DerOutputStream, out, $new($DerOutputStream));
		out->write($DerValue::tag_Sequence, initToken);
		return out->toByteArray();
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({"Invalid SPNEGO NegTokenInit token : "_s, $(e->getMessage())}));
	}
	$shouldNotReachHere();
}

void NegTokenInit::parseToken($bytes* in) {
	try {
		$var($DerValue, der, $new($DerValue, in));
		if (!der->isContextSpecific((int8_t)$SpNegoToken::NEG_TOKEN_INIT_ID)) {
			$throwNew($IOException, "SPNEGO NegoTokenInit : did not have right token type"_s);
		}
		$var($DerValue, tmp1, $nc(der->data$)->getDerValue());
		if ($nc(tmp1)->tag != $DerValue::tag_Sequence) {
			$throwNew($IOException, "SPNEGO NegoTokenInit : did not have the Sequence tag"_s);
		}
		int32_t lastField = -1;
		while ($nc($nc(tmp1)->data$)->available() > 0) {
			$var($DerValue, tmp2, $nc(tmp1->data$)->getDerValue());
			if ($nc(tmp2)->isContextSpecific((int8_t)0)) {
				lastField = checkNextField(lastField, 0);
				$var($DerInputStream, mValue, tmp2->data$);
				$set(this, mechTypes, $nc(mValue)->toByteArray());
				$var($DerValueArray, mList, mValue->getSequence(0));
				$set(this, mechTypeList, $new($OidArray, $nc(mList)->length));
				$var($ObjectIdentifier, mech, nullptr);
				for (int32_t i = 0; i < mList->length; ++i) {
					$assign(mech, $nc(mList->get(i))->getOID());
					$init($SpNegoToken);
					if ($SpNegoToken::DEBUG) {
						$init($System);
						$nc($System::out)->println($$str({"SpNegoToken NegTokenInit: reading Mechanism Oid = "_s, mech}));
					}
					$nc(this->mechTypeList)->set(i, $$new($Oid, $($nc(mech)->toString())));
				}
			} else if (tmp2->isContextSpecific((int8_t)1)) {
				lastField = checkNextField(lastField, 1);
			} else if (tmp2->isContextSpecific((int8_t)2)) {
				lastField = checkNextField(lastField, 2);
				$init($SpNegoToken);
				if ($SpNegoToken::DEBUG) {
					$init($System);
					$nc($System::out)->println("SpNegoToken NegTokenInit: reading Mech Token"_s);
				}
				$set(this, mechToken, $nc(tmp2->data$)->getOctetString());
			} else if (tmp2->isContextSpecific((int8_t)3)) {
				lastField = checkNextField(lastField, 3);
				if (!$GSSUtil::useMSInterop()) {
					$set(this, mechListMIC, $nc(tmp2->data$)->getOctetString());
					$init($SpNegoToken);
					if ($SpNegoToken::DEBUG) {
						$init($System);
						$nc($System::out)->println($$str({"SpNegoToken NegTokenInit: MechListMIC Token = "_s, $(getHexBytes(this->mechListMIC))}));
					}
				}
			}
		}
	} catch ($IOException&) {
		$var($IOException, e, $catch());
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, $$str({"Invalid SPNEGO NegTokenInit token : "_s, $(e->getMessage())}));
	}
}

$bytes* NegTokenInit::getMechTypes() {
	return this->mechTypes;
}

$OidArray* NegTokenInit::getMechTypeList() {
	return this->mechTypeList;
}

$BitArray* NegTokenInit::getReqFlags() {
	return this->reqFlags;
}

$bytes* NegTokenInit::getMechToken() {
	return this->mechToken;
}

$bytes* NegTokenInit::getMechListMIC() {
	return this->mechListMIC;
}

NegTokenInit::NegTokenInit() {
}

$Class* NegTokenInit::load$($String* name, bool initialize) {
	$loadClass(NegTokenInit, name, initialize, &_NegTokenInit_ClassInfo_, allocate$NegTokenInit);
	return class$;
}

$Class* NegTokenInit::class$ = nullptr;

			} // spnego
		} // jgss
	} // security
} // sun