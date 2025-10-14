#ifndef _sun_security_krb5_internal_crypto_KeyUsage_h_
#define _sun_security_krb5_internal_crypto_KeyUsage_h_
//$ class sun.security.krb5.internal.crypto.KeyUsage
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("KU_AD_KDC_ISSUED_CKSUM")
#undef KU_AD_KDC_ISSUED_CKSUM
#pragma push_macro("KU_AP_REQ_AUTHENTICATOR")
#undef KU_AP_REQ_AUTHENTICATOR
#pragma push_macro("KU_AS_REQ")
#undef KU_AS_REQ
#pragma push_macro("KU_AUTHENTICATOR_CKSUM")
#undef KU_AUTHENTICATOR_CKSUM
#pragma push_macro("KU_ENC_AP_REP_PART")
#undef KU_ENC_AP_REP_PART
#pragma push_macro("KU_ENC_AS_REP_PART")
#undef KU_ENC_AS_REP_PART
#pragma push_macro("KU_ENC_KRB_CRED_PART")
#undef KU_ENC_KRB_CRED_PART
#pragma push_macro("KU_ENC_KRB_PRIV_PART")
#undef KU_ENC_KRB_PRIV_PART
#pragma push_macro("KU_ENC_TGS_REP_PART_SESSKEY")
#undef KU_ENC_TGS_REP_PART_SESSKEY
#pragma push_macro("KU_ENC_TGS_REP_PART_SUBKEY")
#undef KU_ENC_TGS_REP_PART_SUBKEY
#pragma push_macro("KU_KRB_SAFE_CKSUM")
#undef KU_KRB_SAFE_CKSUM
#pragma push_macro("KU_PA_ENC_TS")
#undef KU_PA_ENC_TS
#pragma push_macro("KU_PA_FOR_USER_ENC_CKSUM")
#undef KU_PA_FOR_USER_ENC_CKSUM
#pragma push_macro("KU_PA_TGS_REQ_AUTHENTICATOR")
#undef KU_PA_TGS_REQ_AUTHENTICATOR
#pragma push_macro("KU_PA_TGS_REQ_CKSUM")
#undef KU_PA_TGS_REQ_CKSUM
#pragma push_macro("KU_TGS_REQ_AUTH_DATA_SESSKEY")
#undef KU_TGS_REQ_AUTH_DATA_SESSKEY
#pragma push_macro("KU_TGS_REQ_AUTH_DATA_SUBKEY")
#undef KU_TGS_REQ_AUTH_DATA_SUBKEY
#pragma push_macro("KU_TICKET")
#undef KU_TICKET
#pragma push_macro("KU_UNKNOWN")
#undef KU_UNKNOWN

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace crypto {

class KeyUsage : public ::java::lang::Object {
	$class(KeyUsage, $NO_CLASS_INIT, ::java::lang::Object)
public:
	KeyUsage();
	void init$();
	static bool isValid(int32_t usage);
	static const int32_t KU_UNKNOWN = 0;
	static const int32_t KU_PA_ENC_TS = 1;
	static const int32_t KU_TICKET = 2;
	static const int32_t KU_ENC_AS_REP_PART = 3;
	static const int32_t KU_TGS_REQ_AUTH_DATA_SESSKEY = 4;
	static const int32_t KU_TGS_REQ_AUTH_DATA_SUBKEY = 5;
	static const int32_t KU_PA_TGS_REQ_CKSUM = 6;
	static const int32_t KU_PA_TGS_REQ_AUTHENTICATOR = 7;
	static const int32_t KU_ENC_TGS_REP_PART_SESSKEY = 8;
	static const int32_t KU_ENC_TGS_REP_PART_SUBKEY = 9;
	static const int32_t KU_AUTHENTICATOR_CKSUM = 10;
	static const int32_t KU_AP_REQ_AUTHENTICATOR = 11;
	static const int32_t KU_ENC_AP_REP_PART = 12;
	static const int32_t KU_ENC_KRB_PRIV_PART = 13;
	static const int32_t KU_ENC_KRB_CRED_PART = 14;
	static const int32_t KU_KRB_SAFE_CKSUM = 15;
	static const int32_t KU_PA_FOR_USER_ENC_CKSUM = 17;
	static const int32_t KU_AD_KDC_ISSUED_CKSUM = 19;
	static const int32_t KU_AS_REQ = 56;
};

				} // crypto
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("KU_AD_KDC_ISSUED_CKSUM")
#pragma pop_macro("KU_AP_REQ_AUTHENTICATOR")
#pragma pop_macro("KU_AS_REQ")
#pragma pop_macro("KU_AUTHENTICATOR_CKSUM")
#pragma pop_macro("KU_ENC_AP_REP_PART")
#pragma pop_macro("KU_ENC_AS_REP_PART")
#pragma pop_macro("KU_ENC_KRB_CRED_PART")
#pragma pop_macro("KU_ENC_KRB_PRIV_PART")
#pragma pop_macro("KU_ENC_TGS_REP_PART_SESSKEY")
#pragma pop_macro("KU_ENC_TGS_REP_PART_SUBKEY")
#pragma pop_macro("KU_KRB_SAFE_CKSUM")
#pragma pop_macro("KU_PA_ENC_TS")
#pragma pop_macro("KU_PA_FOR_USER_ENC_CKSUM")
#pragma pop_macro("KU_PA_TGS_REQ_AUTHENTICATOR")
#pragma pop_macro("KU_PA_TGS_REQ_CKSUM")
#pragma pop_macro("KU_TGS_REQ_AUTH_DATA_SESSKEY")
#pragma pop_macro("KU_TGS_REQ_AUTH_DATA_SUBKEY")
#pragma pop_macro("KU_TICKET")
#pragma pop_macro("KU_UNKNOWN")

#endif // _sun_security_krb5_internal_crypto_KeyUsage_h_