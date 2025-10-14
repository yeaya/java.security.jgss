#include <sun/security/krb5/internal/crypto/KeyUsage.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

#undef KU_AD_KDC_ISSUED_CKSUM
#undef KU_AP_REQ_AUTHENTICATOR
#undef KU_AS_REQ
#undef KU_AUTHENTICATOR_CKSUM
#undef KU_ENC_AP_REP_PART
#undef KU_ENC_AS_REP_PART
#undef KU_ENC_KRB_CRED_PART
#undef KU_ENC_KRB_PRIV_PART
#undef KU_ENC_TGS_REP_PART_SESSKEY
#undef KU_ENC_TGS_REP_PART_SUBKEY
#undef KU_KRB_SAFE_CKSUM
#undef KU_PA_ENC_TS
#undef KU_PA_FOR_USER_ENC_CKSUM
#undef KU_PA_TGS_REQ_AUTHENTICATOR
#undef KU_PA_TGS_REQ_CKSUM
#undef KU_TGS_REQ_AUTH_DATA_SESSKEY
#undef KU_TGS_REQ_AUTH_DATA_SUBKEY
#undef KU_TICKET
#undef KU_UNKNOWN

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

$FieldInfo _KeyUsage_FieldInfo_[] = {
	{"KU_UNKNOWN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_UNKNOWN)},
	{"KU_PA_ENC_TS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_PA_ENC_TS)},
	{"KU_TICKET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_TICKET)},
	{"KU_ENC_AS_REP_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_ENC_AS_REP_PART)},
	{"KU_TGS_REQ_AUTH_DATA_SESSKEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_TGS_REQ_AUTH_DATA_SESSKEY)},
	{"KU_TGS_REQ_AUTH_DATA_SUBKEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_TGS_REQ_AUTH_DATA_SUBKEY)},
	{"KU_PA_TGS_REQ_CKSUM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_PA_TGS_REQ_CKSUM)},
	{"KU_PA_TGS_REQ_AUTHENTICATOR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_PA_TGS_REQ_AUTHENTICATOR)},
	{"KU_ENC_TGS_REP_PART_SESSKEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_ENC_TGS_REP_PART_SESSKEY)},
	{"KU_ENC_TGS_REP_PART_SUBKEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_ENC_TGS_REP_PART_SUBKEY)},
	{"KU_AUTHENTICATOR_CKSUM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_AUTHENTICATOR_CKSUM)},
	{"KU_AP_REQ_AUTHENTICATOR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_AP_REQ_AUTHENTICATOR)},
	{"KU_ENC_AP_REP_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_ENC_AP_REP_PART)},
	{"KU_ENC_KRB_PRIV_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_ENC_KRB_PRIV_PART)},
	{"KU_ENC_KRB_CRED_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_ENC_KRB_CRED_PART)},
	{"KU_KRB_SAFE_CKSUM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_KRB_SAFE_CKSUM)},
	{"KU_PA_FOR_USER_ENC_CKSUM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_PA_FOR_USER_ENC_CKSUM)},
	{"KU_AD_KDC_ISSUED_CKSUM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_AD_KDC_ISSUED_CKSUM)},
	{"KU_AS_REQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(KeyUsage, KU_AS_REQ)},
	{}
};

$MethodInfo _KeyUsage_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(KeyUsage::*)()>(&KeyUsage::init$))},
	{"isValid", "(I)Z", nullptr, $PUBLIC | $STATIC | $FINAL, $method(static_cast<bool(*)(int32_t)>(&KeyUsage::isValid))},
	{}
};

$ClassInfo _KeyUsage_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.crypto.KeyUsage",
	"java.lang.Object",
	nullptr,
	_KeyUsage_FieldInfo_,
	_KeyUsage_MethodInfo_
};

$Object* allocate$KeyUsage($Class* clazz) {
	return $of($alloc(KeyUsage));
}

void KeyUsage::init$() {
}

bool KeyUsage::isValid(int32_t usage) {
	return usage >= 0;
}

KeyUsage::KeyUsage() {
}

$Class* KeyUsage::load$($String* name, bool initialize) {
	$loadClass(KeyUsage, name, initialize, &_KeyUsage_ClassInfo_, allocate$KeyUsage);
	return class$;
}

$Class* KeyUsage::class$ = nullptr;

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun