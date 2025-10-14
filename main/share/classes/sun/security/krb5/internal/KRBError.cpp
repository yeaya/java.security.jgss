#include <sun/security/krb5/internal/KRBError.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/math/BigInteger.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Date.h>
#include <java/util/List.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/internal/APOptions.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/util/KerberosString.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef ASN1_BAD_ID
#undef DEBUG
#undef KDC_ERR_PREAUTH_FAILED
#undef KDC_ERR_PREAUTH_REQUIRED
#undef KRB_AP_ERR_BADVERSION
#undef KRB_AP_ERR_MSG_TYPE
#undef KRB_ERROR
#undef PVNO
#undef TAG_APPLICATION
#undef TAG_CONTEXT

using $PADataArray = $Array<::sun::security::krb5::internal::PAData>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $BigInteger = ::java::math::BigInteger;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Date = ::java::util::Date;
using $List = ::java::util::List;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $Checksum = ::sun::security::krb5::Checksum;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Realm = ::sun::security::krb5::Realm;
using $APOptions = ::sun::security::krb5::internal::APOptions;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $PAData = ::sun::security::krb5::internal::PAData;
using $KerberosString = ::sun::security::krb5::internal::util::KerberosString;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _KRBError_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(KRBError, serialVersionUID)},
	{"pvno", "I", nullptr, $PRIVATE, $field(KRBError, pvno)},
	{"msgType", "I", nullptr, $PRIVATE, $field(KRBError, msgType)},
	{"cTime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $field(KRBError, cTime)},
	{"cuSec", "Ljava/lang/Integer;", nullptr, $PRIVATE, $field(KRBError, cuSec)},
	{"sTime", "Lsun/security/krb5/internal/KerberosTime;", nullptr, $PRIVATE, $field(KRBError, sTime)},
	{"suSec", "Ljava/lang/Integer;", nullptr, $PRIVATE, $field(KRBError, suSec)},
	{"errorCode", "I", nullptr, $PRIVATE, $field(KRBError, errorCode)},
	{"crealm", "Lsun/security/krb5/Realm;", nullptr, $PRIVATE, $field(KRBError, crealm)},
	{"cname", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KRBError, cname)},
	{"sname", "Lsun/security/krb5/PrincipalName;", nullptr, $PRIVATE, $field(KRBError, sname)},
	{"eText", "Ljava/lang/String;", nullptr, $PRIVATE, $field(KRBError, eText)},
	{"eData", "[B", nullptr, $PRIVATE, $field(KRBError, eData)},
	{"eCksum", "Lsun/security/krb5/Checksum;", nullptr, $PRIVATE, $field(KRBError, eCksum)},
	{"pa", "[Lsun/security/krb5/internal/PAData;", nullptr, $PRIVATE, $field(KRBError, pa)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC, $staticField(KRBError, DEBUG)},
	{}
};

$MethodInfo _KRBError_MethodInfo_[] = {
	{"<init>", "(Lsun/security/krb5/internal/APOptions;Lsun/security/krb5/internal/KerberosTime;Ljava/lang/Integer;Lsun/security/krb5/internal/KerberosTime;Ljava/lang/Integer;ILsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Ljava/lang/String;[B)V", nullptr, $PUBLIC, $method(static_cast<void(KRBError::*)($APOptions*,$KerberosTime*,$Integer*,$KerberosTime*,$Integer*,int32_t,$PrincipalName*,$PrincipalName*,$String*,$bytes*)>(&KRBError::init$)), "java.io.IOException,sun.security.krb5.Asn1Exception"},
	{"<init>", "(Lsun/security/krb5/internal/APOptions;Lsun/security/krb5/internal/KerberosTime;Ljava/lang/Integer;Lsun/security/krb5/internal/KerberosTime;Ljava/lang/Integer;ILsun/security/krb5/PrincipalName;Lsun/security/krb5/PrincipalName;Ljava/lang/String;[BLsun/security/krb5/Checksum;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBError::*)($APOptions*,$KerberosTime*,$Integer*,$KerberosTime*,$Integer*,int32_t,$PrincipalName*,$PrincipalName*,$String*,$bytes*,$Checksum*)>(&KRBError::init$)), "java.io.IOException,sun.security.krb5.Asn1Exception"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(KRBError::*)($bytes*)>(&KRBError::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(KRBError::*)($DerValue*)>(&KRBError::init$)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getClientMicroSeconds", "()Ljava/lang/Integer;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Integer*(KRBError::*)()>(&KRBError::getClientMicroSeconds))},
	{"getClientRealm", "()Lsun/security/krb5/Realm;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Realm*(KRBError::*)()>(&KRBError::getClientRealm))},
	{"getClientTime", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$KerberosTime*(KRBError::*)()>(&KRBError::getClientTime))},
	{"getErrorCode", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(KRBError::*)()>(&KRBError::getErrorCode))},
	{"getErrorString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$String*(KRBError::*)()>(&KRBError::getErrorString))},
	{"getPA", "()[Lsun/security/krb5/internal/PAData;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$PADataArray*(KRBError::*)()>(&KRBError::getPA))},
	{"getServerMicroSeconds", "()Ljava/lang/Integer;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$Integer*(KRBError::*)()>(&KRBError::getServerMicroSeconds))},
	{"getServerTime", "()Lsun/security/krb5/internal/KerberosTime;", nullptr, $PUBLIC | $FINAL, $method(static_cast<$KerberosTime*(KRBError::*)()>(&KRBError::getServerTime))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"init", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(static_cast<void(KRBError::*)($DerValue*)>(&KRBError::init)), "sun.security.krb5.Asn1Exception,sun.security.krb5.RealmException,sun.security.krb5.internal.KrbApErrException,java.io.IOException"},
	{"isEqual", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)(Object$*,Object$*)>(&KRBError::isEqual))},
	{"parseEData", "([B)V", nullptr, $PRIVATE, $method(static_cast<void(KRBError::*)($bytes*)>(&KRBError::parseEData)), "java.io.IOException"},
	{"parsePAData", "([B)V", nullptr, $PRIVATE, $method(static_cast<void(KRBError::*)($bytes*)>(&KRBError::parsePAData)), "java.io.IOException,sun.security.krb5.Asn1Exception"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KRBError::*)($ObjectInputStream*)>(&KRBError::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"showDebug", "()V", nullptr, $PRIVATE, $method(static_cast<void(KRBError::*)()>(&KRBError::showDebug))},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(KRBError::*)($ObjectOutputStream*)>(&KRBError::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _KRBError_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.KRBError",
	"java.lang.Object",
	"java.io.Serializable",
	_KRBError_FieldInfo_,
	_KRBError_MethodInfo_
};

$Object* allocate$KRBError($Class* clazz) {
	return $of($alloc(KRBError));
}

bool KRBError::DEBUG = false;

void KRBError::readObject($ObjectInputStream* is) {
	try {
		init($$new($DerValue, $cast($bytes, $($nc(is)->readObject()))));
		parseEData(this->eData);
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
}

void KRBError::writeObject($ObjectOutputStream* os) {
	try {
		$nc(os)->writeObject($(asn1Encode()));
	} catch ($Exception&) {
		$var($Exception, e, $catch());
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
}

void KRBError::init$($APOptions* new_apOptions, $KerberosTime* new_cTime, $Integer* new_cuSec, $KerberosTime* new_sTime, $Integer* new_suSec, int32_t new_errorCode, $PrincipalName* new_cname, $PrincipalName* new_sname, $String* new_eText, $bytes* new_eData) {
	this->pvno = $Krb5::PVNO;
	this->msgType = $Krb5::KRB_ERROR;
	$set(this, cTime, new_cTime);
	$set(this, cuSec, new_cuSec);
	$set(this, sTime, new_sTime);
	$set(this, suSec, new_suSec);
	this->errorCode = new_errorCode;
	$set(this, crealm, new_cname != nullptr ? $nc(new_cname)->getRealm() : ($Realm*)nullptr);
	$set(this, cname, new_cname);
	$set(this, sname, new_sname);
	$set(this, eText, new_eText);
	$set(this, eData, new_eData);
	parseEData(this->eData);
}

void KRBError::init$($APOptions* new_apOptions, $KerberosTime* new_cTime, $Integer* new_cuSec, $KerberosTime* new_sTime, $Integer* new_suSec, int32_t new_errorCode, $PrincipalName* new_cname, $PrincipalName* new_sname, $String* new_eText, $bytes* new_eData, $Checksum* new_eCksum) {
	this->pvno = $Krb5::PVNO;
	this->msgType = $Krb5::KRB_ERROR;
	$set(this, cTime, new_cTime);
	$set(this, cuSec, new_cuSec);
	$set(this, sTime, new_sTime);
	$set(this, suSec, new_suSec);
	this->errorCode = new_errorCode;
	$set(this, crealm, new_cname != nullptr ? $nc(new_cname)->getRealm() : ($Realm*)nullptr);
	$set(this, cname, new_cname);
	$set(this, sname, new_sname);
	$set(this, eText, new_eText);
	$set(this, eData, new_eData);
	$set(this, eCksum, new_eCksum);
	parseEData(this->eData);
}

void KRBError::init$($bytes* data) {
	init($$new($DerValue, data));
	parseEData(this->eData);
}

void KRBError::init$($DerValue* encoding) {
	init(encoding);
	showDebug();
	parseEData(this->eData);
}

void KRBError::parseEData($bytes* data) {
	if (data == nullptr) {
		return;
	}
	if (this->errorCode == $Krb5::KDC_ERR_PREAUTH_REQUIRED || this->errorCode == $Krb5::KDC_ERR_PREAUTH_FAILED) {
		try {
			parsePAData(data);
		} catch ($Exception&) {
			$var($Exception, e, $catch());
			if (KRBError::DEBUG) {
				$init($System);
				$nc($System::out)->println($$str({"Unable to parse eData field of KRB-ERROR:\n"_s, $($$new($HexDumpEncoder)->encodeBuffer(data))}));
			}
			$var($IOException, ioe, $new($IOException, "Unable to parse eData field of KRB-ERROR"_s));
			ioe->initCause(e);
			$throw(ioe);
		}
	} else if (KRBError::DEBUG) {
		$init($System);
		$nc($System::out)->println($$str({"Unknown eData field of KRB-ERROR:\n"_s, $($$new($HexDumpEncoder)->encodeBuffer(data))}));
	}
}

void KRBError::parsePAData($bytes* data) {
	$var($DerValue, derPA, $new($DerValue, data));
	$var($List, paList, $new($ArrayList));
	while ($nc(derPA->data$)->available() > 0) {
		$var($DerValue, tmp, $nc(derPA->data$)->getDerValue());
		$var($PAData, pa_data, $new($PAData, tmp));
		paList->add(pa_data);
		if (KRBError::DEBUG) {
			$init($System);
			$nc($System::out)->println($of(pa_data));
		}
	}
	$set(this, pa, $fcast($PADataArray, paList->toArray($$new($PADataArray, paList->size()))));
}

$Realm* KRBError::getClientRealm() {
	return this->crealm;
}

$KerberosTime* KRBError::getServerTime() {
	return this->sTime;
}

$KerberosTime* KRBError::getClientTime() {
	return this->cTime;
}

$Integer* KRBError::getServerMicroSeconds() {
	return this->suSec;
}

$Integer* KRBError::getClientMicroSeconds() {
	return this->cuSec;
}

int32_t KRBError::getErrorCode() {
	return this->errorCode;
}

$PADataArray* KRBError::getPA() {
	return this->pa;
}

$String* KRBError::getErrorString() {
	return this->eText;
}

void KRBError::init($DerValue* encoding) {
	$var($DerValue, der, nullptr);
	$var($DerValue, subDer, nullptr);
	bool var$1 = (((int32_t)($nc(encoding)->getTag() & (uint32_t)(int32_t)(int8_t)31)) != (int8_t)30);
	bool var$0 = var$1 || ($nc(encoding)->isApplication() != true);
	if (var$0 || ($nc(encoding)->isConstructed() != true)) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(der, $nc($($nc(encoding)->getData()))->getDerValue());
	if ($nc(der)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($($nc(der)->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)0) {
		this->pvno = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
		if (this->pvno != $Krb5::PVNO) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_BADVERSION);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)1) {
		this->msgType = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
		if (this->msgType != $Krb5::KRB_ERROR) {
			$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_MSG_TYPE);
		}
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, cTime, $KerberosTime::parse($(der->getData()), (int8_t)2, true));
	if (((int32_t)($nc($(der->getData()))->peekByte() & (uint32_t)31)) == 3) {
		$assign(subDer, $nc($(der->getData()))->getDerValue());
		$set(this, cuSec, $Integer::valueOf($nc($($nc($($nc(subDer)->getData()))->getBigInteger()))->intValue()));
	} else {
		$set(this, cuSec, nullptr);
	}
	$set(this, sTime, $KerberosTime::parse($(der->getData()), (int8_t)4, false));
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)5) {
		$set(this, suSec, $Integer::valueOf($nc($($nc($(subDer->getData()))->getBigInteger()))->intValue()));
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$assign(subDer, $nc($(der->getData()))->getDerValue());
	if (((int32_t)($nc(subDer)->getTag() & (uint32_t)(int32_t)(int8_t)31)) == (int8_t)6) {
		this->errorCode = $nc($($nc($(subDer->getData()))->getBigInteger()))->intValue();
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$set(this, crealm, $Realm::parse($(der->getData()), (int8_t)7, true));
	$set(this, cname, $PrincipalName::parse($(der->getData()), (int8_t)8, true, this->crealm));
	$var($Realm, realm, $Realm::parse($(der->getData()), (int8_t)9, false));
	$set(this, sname, $PrincipalName::parse($(der->getData()), (int8_t)10, false, realm));
	$set(this, eText, nullptr);
	$set(this, eData, nullptr);
	$set(this, eCksum, nullptr);
	if ($nc($(der->getData()))->available() > 0) {
		if (((int32_t)($nc($(der->getData()))->peekByte() & (uint32_t)31)) == 11) {
			$assign(subDer, $nc($(der->getData()))->getDerValue());
			$set(this, eText, $$new($KerberosString, $($nc($($nc(subDer)->getData()))->getDerValue()))->toString());
		}
	}
	if ($nc($(der->getData()))->available() > 0) {
		if (((int32_t)($nc($(der->getData()))->peekByte() & (uint32_t)31)) == 12) {
			$assign(subDer, $nc($(der->getData()))->getDerValue());
			$set(this, eData, $nc($($nc(subDer)->getData()))->getOctetString());
		}
	}
	if ($nc($(der->getData()))->available() > 0) {
		$set(this, eCksum, $Checksum::parse($(der->getData()), (int8_t)13, true));
	}
	if ($nc($(der->getData()))->available() > 0) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

void KRBError::showDebug() {
	if (KRBError::DEBUG) {
		$init($System);
		$nc($System::out)->println(">>>KRBError:"_s);
		if (this->cTime != nullptr) {
			$var($String, var$0, $$str({"\t cTime is "_s, $($nc($($nc(this->cTime)->toDate()))->toString()), " "_s}));
			$nc($System::out)->println($$concat(var$0, $$str($nc($($nc(this->cTime)->toDate()))->getTime())));
		}
		if (this->cuSec != nullptr) {
			$nc($System::out)->println($$str({"\t cuSec is "_s, $$str($nc(this->cuSec)->intValue())}));
		}
		$var($String, var$1, $$str({"\t sTime is "_s, $($nc($($nc(this->sTime)->toDate()))->toString()), " "_s}));
		$nc($System::out)->println($$concat(var$1, $$str($nc($($nc(this->sTime)->toDate()))->getTime())));
		$nc($System::out)->println($$str({"\t suSec is "_s, this->suSec}));
		$nc($System::out)->println($$str({"\t error code is "_s, $$str(this->errorCode)}));
		$nc($System::out)->println($$str({"\t error Message is "_s, $($Krb5::getErrorMessage(this->errorCode))}));
		if (this->crealm != nullptr) {
			$nc($System::out)->println($$str({"\t crealm is "_s, $($nc(this->crealm)->toString())}));
		}
		if (this->cname != nullptr) {
			$nc($System::out)->println($$str({"\t cname is "_s, $($nc(this->cname)->toString())}));
		}
		if (this->sname != nullptr) {
			$nc($System::out)->println($$str({"\t sname is "_s, $($nc(this->sname)->toString())}));
		}
		if (this->eData != nullptr) {
			$nc($System::out)->println("\t eData provided."_s);
		}
		if (this->eCksum != nullptr) {
			$nc($System::out)->println("\t checksum provided."_s);
		}
		$nc($System::out)->println($$str({"\t msgType is "_s, $$str(this->msgType)}));
	}
}

$bytes* KRBError::asn1Encode() {
	$var($DerOutputStream, temp, $new($DerOutputStream));
	$var($DerOutputStream, bytes, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->pvno)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->msgType)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)1), temp);
	if (this->cTime != nullptr) {
		int8_t var$0 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)2);
		bytes->write(var$0, $($nc(this->cTime)->asn1Encode()));
	}
	if (this->cuSec != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putInteger($($BigInteger::valueOf((int64_t)$nc(this->cuSec)->intValue())));
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)3), temp);
	}
	int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)4);
	bytes->write(var$1, $($nc(this->sTime)->asn1Encode()));
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)$nc(this->suSec)->intValue())));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)5), temp);
	$assign(temp, $new($DerOutputStream));
	temp->putInteger($($BigInteger::valueOf((int64_t)this->errorCode)));
	bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)6), temp);
	if (this->crealm != nullptr) {
		int8_t var$2 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)7);
		bytes->write(var$2, $($nc(this->crealm)->asn1Encode()));
	}
	if (this->cname != nullptr) {
		int8_t var$3 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)8);
		bytes->write(var$3, $($nc(this->cname)->asn1Encode()));
	}
	int8_t var$4 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)9);
	bytes->write(var$4, $($nc($($nc(this->sname)->getRealm()))->asn1Encode()));
	int8_t var$5 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)10);
	bytes->write(var$5, $($nc(this->sname)->asn1Encode()));
	if (this->eText != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putDerValue($($$new($KerberosString, this->eText)->toDerValue()));
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)11), temp);
	}
	if (this->eData != nullptr) {
		$assign(temp, $new($DerOutputStream));
		temp->putOctetString(this->eData);
		bytes->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)12), temp);
	}
	if (this->eCksum != nullptr) {
		int8_t var$6 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)13);
		bytes->write(var$6, $($nc(this->eCksum)->asn1Encode()));
	}
	$assign(temp, $new($DerOutputStream));
	temp->write($DerValue::tag_Sequence, bytes);
	$assign(bytes, $new($DerOutputStream));
	bytes->write($DerValue::createTag($DerValue::TAG_APPLICATION, true, (int8_t)30), temp);
	return bytes->toByteArray();
}

bool KRBError::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(KRBError, obj))) {
		return false;
	}
	$var(KRBError, other, $cast(KRBError, obj));
	bool var$8 = this->pvno == $nc(other)->pvno && this->msgType == other->msgType && isEqual(this->cTime, other->cTime);
	bool var$7 = var$8 && isEqual(this->cuSec, other->cuSec);
	bool var$6 = var$7 && isEqual(this->sTime, other->sTime);
	bool var$5 = var$6 && isEqual(this->suSec, other->suSec) && this->errorCode == other->errorCode;
	bool var$4 = var$5 && isEqual(this->crealm, other->crealm);
	bool var$3 = var$4 && isEqual(this->cname, other->cname);
	bool var$2 = var$3 && isEqual(this->sname, other->sname);
	bool var$1 = var$2 && isEqual(this->eText, other->eText);
	bool var$0 = var$1 && $Arrays::equals(this->eData, other->eData);
	return var$0 && isEqual(this->eCksum, other->eCksum);
}

bool KRBError::isEqual(Object$* a, Object$* b) {
	$init(KRBError);
	return (a == nullptr) ? (b == nullptr) : ($nc($of(a))->equals(b));
}

int32_t KRBError::hashCode() {
	int32_t result = 17;
	result = 37 * result + this->pvno;
	result = 37 * result + this->msgType;
	if (this->cTime != nullptr) {
		result = 37 * result + $nc(this->cTime)->hashCode();
	}
	if (this->cuSec != nullptr) {
		result = 37 * result + $nc(this->cuSec)->hashCode();
	}
	if (this->sTime != nullptr) {
		result = 37 * result + $nc(this->sTime)->hashCode();
	}
	if (this->suSec != nullptr) {
		result = 37 * result + $nc(this->suSec)->hashCode();
	}
	result = 37 * result + this->errorCode;
	if (this->crealm != nullptr) {
		result = 37 * result + $nc(this->crealm)->hashCode();
	}
	if (this->cname != nullptr) {
		result = 37 * result + $nc(this->cname)->hashCode();
	}
	if (this->sname != nullptr) {
		result = 37 * result + $nc(this->sname)->hashCode();
	}
	if (this->eText != nullptr) {
		result = 37 * result + $nc(this->eText)->hashCode();
	}
	result = 37 * result + $Arrays::hashCode(this->eData);
	if (this->eCksum != nullptr) {
		result = 37 * result + $nc(this->eCksum)->hashCode();
	}
	return result;
}

void clinit$KRBError($Class* class$) {
	$init($Krb5);
	KRBError::DEBUG = $Krb5::DEBUG;
}

KRBError::KRBError() {
}

$Class* KRBError::load$($String* name, bool initialize) {
	$loadClass(KRBError, name, initialize, &_KRBError_ClassInfo_, clinit$KRBError, allocate$KRBError);
	return class$;
}

$Class* KRBError::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun