#ifndef _sun_security_krb5_internal_Krb5_h_
#define _sun_security_krb5_internal_Krb5_h_
//$ class sun.security.krb5.internal.Krb5
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("ADDRTYPE_APPLETALK")
#undef ADDRTYPE_APPLETALK
#pragma push_macro("ADDRTYPE_ATM")
#undef ADDRTYPE_ATM
#pragma push_macro("ADDRTYPE_BAN")
#undef ADDRTYPE_BAN
#pragma push_macro("ADDRTYPE_CCITT")
#undef ADDRTYPE_CCITT
#pragma push_macro("ADDRTYPE_CHAOS")
#undef ADDRTYPE_CHAOS
#pragma push_macro("ADDRTYPE_DATAKIT")
#undef ADDRTYPE_DATAKIT
#pragma push_macro("ADDRTYPE_DECNET")
#undef ADDRTYPE_DECNET
#pragma push_macro("ADDRTYPE_DLI")
#undef ADDRTYPE_DLI
#pragma push_macro("ADDRTYPE_ECMA")
#undef ADDRTYPE_ECMA
#pragma push_macro("ADDRTYPE_FIREFOX")
#undef ADDRTYPE_FIREFOX
#pragma push_macro("ADDRTYPE_HYLINK")
#undef ADDRTYPE_HYLINK
#pragma push_macro("ADDRTYPE_IMPLINK")
#undef ADDRTYPE_IMPLINK
#pragma push_macro("ADDRTYPE_INET")
#undef ADDRTYPE_INET
#pragma push_macro("ADDRTYPE_INET6")
#undef ADDRTYPE_INET6
#pragma push_macro("ADDRTYPE_IPX")
#undef ADDRTYPE_IPX
#pragma push_macro("ADDRTYPE_ISO")
#undef ADDRTYPE_ISO
#pragma push_macro("ADDRTYPE_LAT")
#undef ADDRTYPE_LAT
#pragma push_macro("ADDRTYPE_NETBIOS")
#undef ADDRTYPE_NETBIOS
#pragma push_macro("ADDRTYPE_PUP")
#undef ADDRTYPE_PUP
#pragma push_macro("ADDRTYPE_SNA")
#undef ADDRTYPE_SNA
#pragma push_macro("ADDRTYPE_UNIX")
#undef ADDRTYPE_UNIX
#pragma push_macro("ADDRTYPE_VOICEVIEW")
#undef ADDRTYPE_VOICEVIEW
#pragma push_macro("ADDRTYPE_XNS")
#undef ADDRTYPE_XNS
#pragma push_macro("ADDR_LEN_APPLETALK")
#undef ADDR_LEN_APPLETALK
#pragma push_macro("ADDR_LEN_CHAOS")
#undef ADDR_LEN_CHAOS
#pragma push_macro("ADDR_LEN_DECNET")
#undef ADDR_LEN_DECNET
#pragma push_macro("ADDR_LEN_INET")
#undef ADDR_LEN_INET
#pragma push_macro("ADDR_LEN_OSI")
#undef ADDR_LEN_OSI
#pragma push_macro("ADDR_LEN_XNS")
#undef ADDR_LEN_XNS
#pragma push_macro("API_INVALID_ARG")
#undef API_INVALID_ARG
#pragma push_macro("AP_EMPTY_ADDRESSES_ALLOWED")
#undef AP_EMPTY_ADDRESSES_ALLOWED
#pragma push_macro("AP_OPTS_MAX")
#undef AP_OPTS_MAX
#pragma push_macro("AP_OPTS_MUTUAL_REQUIRED")
#undef AP_OPTS_MUTUAL_REQUIRED
#pragma push_macro("AP_OPTS_RESERVED")
#undef AP_OPTS_RESERVED
#pragma push_macro("AP_OPTS_USE_SESSION_KEY")
#undef AP_OPTS_USE_SESSION_KEY
#pragma push_macro("ASN1_BAD_CLASS")
#undef ASN1_BAD_CLASS
#pragma push_macro("ASN1_BAD_FORMAT")
#undef ASN1_BAD_FORMAT
#pragma push_macro("ASN1_BAD_ID")
#undef ASN1_BAD_ID
#pragma push_macro("ASN1_BAD_LENGTH")
#undef ASN1_BAD_LENGTH
#pragma push_macro("ASN1_BAD_TAG")
#undef ASN1_BAD_TAG
#pragma push_macro("ASN1_BAD_TIMEFORMAT")
#undef ASN1_BAD_TIMEFORMAT
#pragma push_macro("ASN1_BAD_TYPE")
#undef ASN1_BAD_TYPE
#pragma push_macro("ASN1_CANNOT_ENCODE")
#undef ASN1_CANNOT_ENCODE
#pragma push_macro("ASN1_MISPLACED_FIELD")
#undef ASN1_MISPLACED_FIELD
#pragma push_macro("ASN1_MISSING_FIELD")
#undef ASN1_MISSING_FIELD
#pragma push_macro("ASN1_OVERFLOW")
#undef ASN1_OVERFLOW
#pragma push_macro("ASN1_OVERRUN")
#undef ASN1_OVERRUN
#pragma push_macro("ASN1_PARSE_ERROR")
#undef ASN1_PARSE_ERROR
#pragma push_macro("ASN1_TYPE_MISMATCH")
#undef ASN1_TYPE_MISMATCH
#pragma push_macro("ASN1_UNSUPPORTED_TYPE")
#undef ASN1_UNSUPPORTED_TYPE
#pragma push_macro("ATT_CHALLENGE_RESPONSE")
#undef ATT_CHALLENGE_RESPONSE
#pragma push_macro("AUTHNETICATOR_VNO")
#undef AUTHNETICATOR_VNO
#pragma push_macro("BITSTRING_BAD_LENGTH")
#undef BITSTRING_BAD_LENGTH
#pragma push_macro("BITSTRING_INDEX_OUT_OF_BOUNDS")
#undef BITSTRING_INDEX_OUT_OF_BOUNDS
#pragma push_macro("BITSTRING_SIZE_INVALID")
#undef BITSTRING_SIZE_INVALID
#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("DEFAULT_ALLOWABLE_CLOCKSKEW")
#undef DEFAULT_ALLOWABLE_CLOCKSKEW
#pragma push_macro("DEFAULT_FORWARDABLE_ALLOWED")
#undef DEFAULT_FORWARDABLE_ALLOWED
#pragma push_macro("DEFAULT_MAXIMUM_RENEWABLE_LIFETIME")
#undef DEFAULT_MAXIMUM_RENEWABLE_LIFETIME
#pragma push_macro("DEFAULT_MAXIMUM_TICKET_LIFETIME")
#undef DEFAULT_MAXIMUM_TICKET_LIFETIME
#pragma push_macro("DEFAULT_MINIMUM_LIFETIME")
#undef DEFAULT_MINIMUM_LIFETIME
#pragma push_macro("DEFAULT_POSTDATE_ALLOWED")
#undef DEFAULT_POSTDATE_ALLOWED
#pragma push_macro("DEFAULT_PROXIABLE_ALLOWED")
#undef DEFAULT_PROXIABLE_ALLOWED
#pragma push_macro("DEFAULT_RENEWABLE_ALLOWED")
#undef DEFAULT_RENEWABLE_ALLOWED
#pragma push_macro("DOMAIN_X500_COMPRESS")
#undef DOMAIN_X500_COMPRESS
#pragma push_macro("KDC_DEFAULT_UDP_PREF_LIMIT")
#undef KDC_DEFAULT_UDP_PREF_LIMIT
#pragma push_macro("KDC_ERR_BADOPTION")
#undef KDC_ERR_BADOPTION
#pragma push_macro("KDC_ERR_BAD_PVNO")
#undef KDC_ERR_BAD_PVNO
#pragma push_macro("KDC_ERR_CANNOT_POSTDATE")
#undef KDC_ERR_CANNOT_POSTDATE
#pragma push_macro("KDC_ERR_CLIENT_NOTYET")
#undef KDC_ERR_CLIENT_NOTYET
#pragma push_macro("KDC_ERR_CLIENT_REVOKED")
#undef KDC_ERR_CLIENT_REVOKED
#pragma push_macro("KDC_ERR_C_OLD_MAST_KVNO")
#undef KDC_ERR_C_OLD_MAST_KVNO
#pragma push_macro("KDC_ERR_C_PRINCIPAL_UNKNOWN")
#undef KDC_ERR_C_PRINCIPAL_UNKNOWN
#pragma push_macro("KDC_ERR_ETYPE_NOSUPP")
#undef KDC_ERR_ETYPE_NOSUPP
#pragma push_macro("KDC_ERR_KEY_EXPIRED")
#undef KDC_ERR_KEY_EXPIRED
#pragma push_macro("KDC_ERR_NAME_EXP")
#undef KDC_ERR_NAME_EXP
#pragma push_macro("KDC_ERR_NEVER_VALID")
#undef KDC_ERR_NEVER_VALID
#pragma push_macro("KDC_ERR_NONE")
#undef KDC_ERR_NONE
#pragma push_macro("KDC_ERR_NULL_KEY")
#undef KDC_ERR_NULL_KEY
#pragma push_macro("KDC_ERR_PADATA_TYPE_NOSUPP")
#undef KDC_ERR_PADATA_TYPE_NOSUPP
#pragma push_macro("KDC_ERR_POLICY")
#undef KDC_ERR_POLICY
#pragma push_macro("KDC_ERR_PREAUTH_FAILED")
#undef KDC_ERR_PREAUTH_FAILED
#pragma push_macro("KDC_ERR_PREAUTH_REQUIRED")
#undef KDC_ERR_PREAUTH_REQUIRED
#pragma push_macro("KDC_ERR_PRINCIPAL_NOT_UNIQUE")
#undef KDC_ERR_PRINCIPAL_NOT_UNIQUE
#pragma push_macro("KDC_ERR_SERVICE_EXP")
#undef KDC_ERR_SERVICE_EXP
#pragma push_macro("KDC_ERR_SERVICE_NOTYET")
#undef KDC_ERR_SERVICE_NOTYET
#pragma push_macro("KDC_ERR_SERVICE_REVOKED")
#undef KDC_ERR_SERVICE_REVOKED
#pragma push_macro("KDC_ERR_SUMTYPE_NOSUPP")
#undef KDC_ERR_SUMTYPE_NOSUPP
#pragma push_macro("KDC_ERR_S_OLD_MAST_KVNO")
#undef KDC_ERR_S_OLD_MAST_KVNO
#pragma push_macro("KDC_ERR_S_PRINCIPAL_UNKNOWN")
#undef KDC_ERR_S_PRINCIPAL_UNKNOWN
#pragma push_macro("KDC_ERR_TGT_REVOKED")
#undef KDC_ERR_TGT_REVOKED
#pragma push_macro("KDC_ERR_TRTYPE_NOSUPP")
#undef KDC_ERR_TRTYPE_NOSUPP
#pragma push_macro("KDC_HARD_UDP_LIMIT")
#undef KDC_HARD_UDP_LIMIT
#pragma push_macro("KDC_INET_DEFAULT_PORT")
#undef KDC_INET_DEFAULT_PORT
#pragma push_macro("KDC_OPTS_MAX")
#undef KDC_OPTS_MAX
#pragma push_macro("KDC_RETRY_LIMIT")
#undef KDC_RETRY_LIMIT
#pragma push_macro("KEYTYPE_AES")
#undef KEYTYPE_AES
#pragma push_macro("KEYTYPE_ARCFOUR_HMAC")
#undef KEYTYPE_ARCFOUR_HMAC
#pragma push_macro("KEYTYPE_DES")
#undef KEYTYPE_DES
#pragma push_macro("KEYTYPE_DES3")
#undef KEYTYPE_DES3
#pragma push_macro("KEYTYPE_NULL")
#undef KEYTYPE_NULL
#pragma push_macro("KRB_AP_ERR_BADADDR")
#undef KRB_AP_ERR_BADADDR
#pragma push_macro("KRB_AP_ERR_BADDIRECTION")
#undef KRB_AP_ERR_BADDIRECTION
#pragma push_macro("KRB_AP_ERR_BADKEYVER")
#undef KRB_AP_ERR_BADKEYVER
#pragma push_macro("KRB_AP_ERR_BADMATCH")
#undef KRB_AP_ERR_BADMATCH
#pragma push_macro("KRB_AP_ERR_BADORDER")
#undef KRB_AP_ERR_BADORDER
#pragma push_macro("KRB_AP_ERR_BADSEQ")
#undef KRB_AP_ERR_BADSEQ
#pragma push_macro("KRB_AP_ERR_BADVERSION")
#undef KRB_AP_ERR_BADVERSION
#pragma push_macro("KRB_AP_ERR_BAD_INTEGRITY")
#undef KRB_AP_ERR_BAD_INTEGRITY
#pragma push_macro("KRB_AP_ERR_GEN_CRED")
#undef KRB_AP_ERR_GEN_CRED
#pragma push_macro("KRB_AP_ERR_INAPP_CKSUM")
#undef KRB_AP_ERR_INAPP_CKSUM
#pragma push_macro("KRB_AP_ERR_METHOD")
#undef KRB_AP_ERR_METHOD
#pragma push_macro("KRB_AP_ERR_MODIFIED")
#undef KRB_AP_ERR_MODIFIED
#pragma push_macro("KRB_AP_ERR_MSG_TYPE")
#undef KRB_AP_ERR_MSG_TYPE
#pragma push_macro("KRB_AP_ERR_MUT_FAIL")
#undef KRB_AP_ERR_MUT_FAIL
#pragma push_macro("KRB_AP_ERR_NOKEY")
#undef KRB_AP_ERR_NOKEY
#pragma push_macro("KRB_AP_ERR_NOREALM")
#undef KRB_AP_ERR_NOREALM
#pragma push_macro("KRB_AP_ERR_NOT_US")
#undef KRB_AP_ERR_NOT_US
#pragma push_macro("KRB_AP_ERR_REPEAT")
#undef KRB_AP_ERR_REPEAT
#pragma push_macro("KRB_AP_ERR_REQ_OPTIONS")
#undef KRB_AP_ERR_REQ_OPTIONS
#pragma push_macro("KRB_AP_ERR_SKEW")
#undef KRB_AP_ERR_SKEW
#pragma push_macro("KRB_AP_ERR_TKT_EXPIRED")
#undef KRB_AP_ERR_TKT_EXPIRED
#pragma push_macro("KRB_AP_ERR_TKT_NYV")
#undef KRB_AP_ERR_TKT_NYV
#pragma push_macro("KRB_AP_REP")
#undef KRB_AP_REP
#pragma push_macro("KRB_AP_REQ")
#undef KRB_AP_REQ
#pragma push_macro("KRB_AS_REP")
#undef KRB_AS_REP
#pragma push_macro("KRB_AS_REQ")
#undef KRB_AS_REQ
#pragma push_macro("KRB_AUTHENTICATOR")
#undef KRB_AUTHENTICATOR
#pragma push_macro("KRB_CRED")
#undef KRB_CRED
#pragma push_macro("KRB_CRYPTO_NOT_SUPPORT")
#undef KRB_CRYPTO_NOT_SUPPORT
#pragma push_macro("KRB_ENC_AP_REP_PART")
#undef KRB_ENC_AP_REP_PART
#pragma push_macro("KRB_ENC_AS_REP_PART")
#undef KRB_ENC_AS_REP_PART
#pragma push_macro("KRB_ENC_KRB_CRED_PART")
#undef KRB_ENC_KRB_CRED_PART
#pragma push_macro("KRB_ENC_KRB_PRIV_PART")
#undef KRB_ENC_KRB_PRIV_PART
#pragma push_macro("KRB_ENC_TGS_REP_PART")
#undef KRB_ENC_TGS_REP_PART
#pragma push_macro("KRB_ENC_TKT_PART")
#undef KRB_ENC_TKT_PART
#pragma push_macro("KRB_ERROR")
#undef KRB_ERROR
#pragma push_macro("KRB_ERR_FIELD_TOOLONG")
#undef KRB_ERR_FIELD_TOOLONG
#pragma push_macro("KRB_ERR_GENERIC")
#undef KRB_ERR_GENERIC
#pragma push_macro("KRB_ERR_RESPONSE_TOO_BIG")
#undef KRB_ERR_RESPONSE_TOO_BIG
#pragma push_macro("KRB_ERR_WRONG_REALM")
#undef KRB_ERR_WRONG_REALM
#pragma push_macro("KRB_FLAGS_MAX")
#undef KRB_FLAGS_MAX
#pragma push_macro("KRB_PRIV")
#undef KRB_PRIV
#pragma push_macro("KRB_SAFE")
#undef KRB_SAFE
#pragma push_macro("KRB_TGS_REP")
#undef KRB_TGS_REP
#pragma push_macro("KRB_TGS_REQ")
#undef KRB_TGS_REQ
#pragma push_macro("KRB_TKT")
#undef KRB_TKT
#pragma push_macro("LRTYPE_NONE")
#undef LRTYPE_NONE
#pragma push_macro("LRTYPE_TIME_OF_INITIAL_REQ")
#undef LRTYPE_TIME_OF_INITIAL_REQ
#pragma push_macro("LRTYPE_TIME_OF_INITIAL_TGT")
#undef LRTYPE_TIME_OF_INITIAL_TGT
#pragma push_macro("LRTYPE_TIME_OF_LAST_RENEWAL")
#undef LRTYPE_TIME_OF_LAST_RENEWAL
#pragma push_macro("LRTYPE_TIME_OF_LAST_REQ")
#undef LRTYPE_TIME_OF_LAST_REQ
#pragma push_macro("LRTYPE_TIME_OF_NEWEST_TGT")
#undef LRTYPE_TIME_OF_NEWEST_TGT
#pragma push_macro("OSF_DCE")
#undef OSF_DCE
#pragma push_macro("PA_ENC_TIMESTAMP")
#undef PA_ENC_TIMESTAMP
#pragma push_macro("PA_ETYPE_INFO")
#undef PA_ETYPE_INFO
#pragma push_macro("PA_ETYPE_INFO2")
#undef PA_ETYPE_INFO2
#pragma push_macro("PA_FOR_USER")
#undef PA_FOR_USER
#pragma push_macro("PA_PAC_OPTIONS")
#undef PA_PAC_OPTIONS
#pragma push_macro("PA_PW_SALT")
#undef PA_PW_SALT
#pragma push_macro("PA_REQ_ENC_PA_REP")
#undef PA_REQ_ENC_PA_REP
#pragma push_macro("PA_TGS_REQ")
#undef PA_TGS_REQ
#pragma push_macro("PVNO")
#undef PVNO
#pragma push_macro("REALM_ILLCHAR")
#undef REALM_ILLCHAR
#pragma push_macro("REALM_NULL")
#undef REALM_NULL
#pragma push_macro("SESAME")
#undef SESAME
#pragma push_macro("TICKET_VNO")
#undef TICKET_VNO
#pragma push_macro("TKT_OPTS_DELEGATE")
#undef TKT_OPTS_DELEGATE
#pragma push_macro("TKT_OPTS_ENC_PA_REP")
#undef TKT_OPTS_ENC_PA_REP
#pragma push_macro("TKT_OPTS_FORWARDABLE")
#undef TKT_OPTS_FORWARDABLE
#pragma push_macro("TKT_OPTS_FORWARDED")
#undef TKT_OPTS_FORWARDED
#pragma push_macro("TKT_OPTS_HW_AUTHENT")
#undef TKT_OPTS_HW_AUTHENT
#pragma push_macro("TKT_OPTS_INITIAL")
#undef TKT_OPTS_INITIAL
#pragma push_macro("TKT_OPTS_INVALID")
#undef TKT_OPTS_INVALID
#pragma push_macro("TKT_OPTS_MAX")
#undef TKT_OPTS_MAX
#pragma push_macro("TKT_OPTS_MAY_POSTDATE")
#undef TKT_OPTS_MAY_POSTDATE
#pragma push_macro("TKT_OPTS_POSTDATED")
#undef TKT_OPTS_POSTDATED
#pragma push_macro("TKT_OPTS_PRE_AUTHENT")
#undef TKT_OPTS_PRE_AUTHENT
#pragma push_macro("TKT_OPTS_PROXIABLE")
#undef TKT_OPTS_PROXIABLE
#pragma push_macro("TKT_OPTS_PROXY")
#undef TKT_OPTS_PROXY
#pragma push_macro("TKT_OPTS_RENEWABLE")
#undef TKT_OPTS_RENEWABLE
#pragma push_macro("TKT_OPTS_RESERVED")
#undef TKT_OPTS_RESERVED

namespace java {
	namespace util {
		class Hashtable;
	}
}
namespace sun {
	namespace security {
		namespace util {
			class HexDumpEncoder;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export Krb5 : public ::java::lang::Object {
	$class(Krb5, 0, ::java::lang::Object)
public:
	Krb5();
	void init$();
	static $String* getErrorMessage(int32_t i);
	static const int32_t DEFAULT_ALLOWABLE_CLOCKSKEW = 300; // 5 * 60
	static const int32_t DEFAULT_MINIMUM_LIFETIME = 300; // 5 * 60
	static const int32_t DEFAULT_MAXIMUM_RENEWABLE_LIFETIME = 604800; // 7 * 24 * 60 * 60
	static const int32_t DEFAULT_MAXIMUM_TICKET_LIFETIME = 86400; // 24 * 60 * 60
	static const bool DEFAULT_FORWARDABLE_ALLOWED = true;
	static const bool DEFAULT_PROXIABLE_ALLOWED = true;
	static const bool DEFAULT_POSTDATE_ALLOWED = true;
	static const bool DEFAULT_RENEWABLE_ALLOWED = true;
	static const bool AP_EMPTY_ADDRESSES_ALLOWED = true;
	static const int32_t AP_OPTS_RESERVED = 0;
	static const int32_t AP_OPTS_USE_SESSION_KEY = 1;
	static const int32_t AP_OPTS_MUTUAL_REQUIRED = 2;
	static const int32_t AP_OPTS_MAX = 31;
	static const int32_t TKT_OPTS_RESERVED = 0;
	static const int32_t TKT_OPTS_FORWARDABLE = 1;
	static const int32_t TKT_OPTS_FORWARDED = 2;
	static const int32_t TKT_OPTS_PROXIABLE = 3;
	static const int32_t TKT_OPTS_PROXY = 4;
	static const int32_t TKT_OPTS_MAY_POSTDATE = 5;
	static const int32_t TKT_OPTS_POSTDATED = 6;
	static const int32_t TKT_OPTS_INVALID = 7;
	static const int32_t TKT_OPTS_RENEWABLE = 8;
	static const int32_t TKT_OPTS_INITIAL = 9;
	static const int32_t TKT_OPTS_PRE_AUTHENT = 10;
	static const int32_t TKT_OPTS_HW_AUTHENT = 11;
	static const int32_t TKT_OPTS_DELEGATE = 13;
	static const int32_t TKT_OPTS_ENC_PA_REP = 15;
	static const int32_t TKT_OPTS_MAX = 31;
	static const int32_t KDC_OPTS_MAX = 31;
	static const int32_t KRB_FLAGS_MAX = 31;
	static const int32_t LRTYPE_NONE = 0;
	static const int32_t LRTYPE_TIME_OF_INITIAL_TGT = 1;
	static const int32_t LRTYPE_TIME_OF_INITIAL_REQ = 2;
	static const int32_t LRTYPE_TIME_OF_NEWEST_TGT = 3;
	static const int32_t LRTYPE_TIME_OF_LAST_RENEWAL = 4;
	static const int32_t LRTYPE_TIME_OF_LAST_REQ = 5;
	static const int32_t ADDR_LEN_INET = 4;
	static const int32_t ADDR_LEN_CHAOS = 2;
	static const int32_t ADDR_LEN_OSI = 0;
	static const int32_t ADDR_LEN_XNS = 6;
	static const int32_t ADDR_LEN_APPLETALK = 3;
	static const int32_t ADDR_LEN_DECNET = 2;
	static const int32_t ADDRTYPE_UNIX = 1;
	static const int32_t ADDRTYPE_INET = 2;
	static const int32_t ADDRTYPE_IMPLINK = 3;
	static const int32_t ADDRTYPE_PUP = 4;
	static const int32_t ADDRTYPE_CHAOS = 5;
	static const int32_t ADDRTYPE_XNS = 6;
	static const int32_t ADDRTYPE_IPX = 6;
	static const int32_t ADDRTYPE_ISO = 7;
	static const int32_t ADDRTYPE_ECMA = 8;
	static const int32_t ADDRTYPE_DATAKIT = 9;
	static const int32_t ADDRTYPE_CCITT = 10;
	static const int32_t ADDRTYPE_SNA = 11;
	static const int32_t ADDRTYPE_DECNET = 12;
	static const int32_t ADDRTYPE_DLI = 13;
	static const int32_t ADDRTYPE_LAT = 14;
	static const int32_t ADDRTYPE_HYLINK = 15;
	static const int32_t ADDRTYPE_APPLETALK = 16;
	static const int32_t ADDRTYPE_NETBIOS = 17;
	static const int32_t ADDRTYPE_VOICEVIEW = 18;
	static const int32_t ADDRTYPE_FIREFOX = 19;
	static const int32_t ADDRTYPE_BAN = 21;
	static const int32_t ADDRTYPE_ATM = 22;
	static const int32_t ADDRTYPE_INET6 = 24;
	static const int32_t KDC_INET_DEFAULT_PORT = 88;
	static const int32_t KDC_RETRY_LIMIT = 3;
	static const int32_t KDC_DEFAULT_UDP_PREF_LIMIT = 1465;
	static const int32_t KDC_HARD_UDP_LIMIT = 32700;
	static const int32_t KEYTYPE_NULL = 0;
	static const int32_t KEYTYPE_DES = 1;
	static const int32_t KEYTYPE_DES3 = 2;
	static const int32_t KEYTYPE_AES = 3;
	static const int32_t KEYTYPE_ARCFOUR_HMAC = 4;
	static const int32_t PA_TGS_REQ = 1;
	static const int32_t PA_ENC_TIMESTAMP = 2;
	static const int32_t PA_PW_SALT = 3;
	static const int32_t PA_ETYPE_INFO = 11;
	static const int32_t PA_ETYPE_INFO2 = 19;
	static const int32_t PA_FOR_USER = 129;
	static const int32_t PA_PAC_OPTIONS = 167;
	static const int32_t PA_REQ_ENC_PA_REP = 149;
	static const int32_t OSF_DCE = 64;
	static const int32_t SESAME = 65;
	static const int32_t ATT_CHALLENGE_RESPONSE = 64;
	static const int32_t DOMAIN_X500_COMPRESS = 1;
	static const int32_t PVNO = 5;
	static const int32_t AUTHNETICATOR_VNO = 5;
	static const int32_t TICKET_VNO = 5;
	static const int32_t KRB_AS_REQ = 10;
	static const int32_t KRB_AS_REP = 11;
	static const int32_t KRB_TGS_REQ = 12;
	static const int32_t KRB_TGS_REP = 13;
	static const int32_t KRB_AP_REQ = 14;
	static const int32_t KRB_AP_REP = 15;
	static const int32_t KRB_SAFE = 20;
	static const int32_t KRB_PRIV = 21;
	static const int32_t KRB_CRED = 22;
	static const int32_t KRB_ERROR = 30;
	static const int32_t KRB_TKT = 1;
	static const int32_t KRB_AUTHENTICATOR = 2;
	static const int32_t KRB_ENC_TKT_PART = 3;
	static const int32_t KRB_ENC_AS_REP_PART = 25;
	static const int32_t KRB_ENC_TGS_REP_PART = 26;
	static const int32_t KRB_ENC_AP_REP_PART = 27;
	static const int32_t KRB_ENC_KRB_PRIV_PART = 28;
	static const int32_t KRB_ENC_KRB_CRED_PART = 29;
	static const int32_t KDC_ERR_NONE = 0;
	static const int32_t KDC_ERR_NAME_EXP = 1;
	static const int32_t KDC_ERR_SERVICE_EXP = 2;
	static const int32_t KDC_ERR_BAD_PVNO = 3;
	static const int32_t KDC_ERR_C_OLD_MAST_KVNO = 4;
	static const int32_t KDC_ERR_S_OLD_MAST_KVNO = 5;
	static const int32_t KDC_ERR_C_PRINCIPAL_UNKNOWN = 6;
	static const int32_t KDC_ERR_S_PRINCIPAL_UNKNOWN = 7;
	static const int32_t KDC_ERR_PRINCIPAL_NOT_UNIQUE = 8;
	static const int32_t KDC_ERR_NULL_KEY = 9;
	static const int32_t KDC_ERR_CANNOT_POSTDATE = 10;
	static const int32_t KDC_ERR_NEVER_VALID = 11;
	static const int32_t KDC_ERR_POLICY = 12;
	static const int32_t KDC_ERR_BADOPTION = 13;
	static const int32_t KDC_ERR_ETYPE_NOSUPP = 14;
	static const int32_t KDC_ERR_SUMTYPE_NOSUPP = 15;
	static const int32_t KDC_ERR_PADATA_TYPE_NOSUPP = 16;
	static const int32_t KDC_ERR_TRTYPE_NOSUPP = 17;
	static const int32_t KDC_ERR_CLIENT_REVOKED = 18;
	static const int32_t KDC_ERR_SERVICE_REVOKED = 19;
	static const int32_t KDC_ERR_TGT_REVOKED = 20;
	static const int32_t KDC_ERR_CLIENT_NOTYET = 21;
	static const int32_t KDC_ERR_SERVICE_NOTYET = 22;
	static const int32_t KDC_ERR_KEY_EXPIRED = 23;
	static const int32_t KDC_ERR_PREAUTH_FAILED = 24;
	static const int32_t KDC_ERR_PREAUTH_REQUIRED = 25;
	static const int32_t KRB_AP_ERR_BAD_INTEGRITY = 31;
	static const int32_t KRB_AP_ERR_TKT_EXPIRED = 32;
	static const int32_t KRB_AP_ERR_TKT_NYV = 33;
	static const int32_t KRB_AP_ERR_REPEAT = 34;
	static const int32_t KRB_AP_ERR_NOT_US = 35;
	static const int32_t KRB_AP_ERR_BADMATCH = 36;
	static const int32_t KRB_AP_ERR_SKEW = 37;
	static const int32_t KRB_AP_ERR_BADADDR = 38;
	static const int32_t KRB_AP_ERR_BADVERSION = 39;
	static const int32_t KRB_AP_ERR_MSG_TYPE = 40;
	static const int32_t KRB_AP_ERR_MODIFIED = 41;
	static const int32_t KRB_AP_ERR_BADORDER = 42;
	static const int32_t KRB_AP_ERR_BADKEYVER = 44;
	static const int32_t KRB_AP_ERR_NOKEY = 45;
	static const int32_t KRB_AP_ERR_MUT_FAIL = 46;
	static const int32_t KRB_AP_ERR_BADDIRECTION = 47;
	static const int32_t KRB_AP_ERR_METHOD = 48;
	static const int32_t KRB_AP_ERR_BADSEQ = 49;
	static const int32_t KRB_AP_ERR_INAPP_CKSUM = 50;
	static const int32_t KRB_ERR_RESPONSE_TOO_BIG = 52;
	static const int32_t KRB_ERR_GENERIC = 60;
	static const int32_t KRB_ERR_FIELD_TOOLONG = 61;
	static const int32_t KRB_ERR_WRONG_REALM = 68;
	static const int32_t KRB_CRYPTO_NOT_SUPPORT = 100;
	static const int32_t KRB_AP_ERR_NOREALM = 62;
	static const int32_t KRB_AP_ERR_GEN_CRED = 63;
	static const int32_t KRB_AP_ERR_REQ_OPTIONS = 101;
	static const int32_t API_INVALID_ARG = 400;
	static const int32_t BITSTRING_SIZE_INVALID = 500;
	static const int32_t BITSTRING_INDEX_OUT_OF_BOUNDS = 501;
	static const int32_t BITSTRING_BAD_LENGTH = 502;
	static const int32_t REALM_ILLCHAR = 600;
	static const int32_t REALM_NULL = 601;
	static const int32_t ASN1_BAD_TIMEFORMAT = 900;
	static const int32_t ASN1_MISSING_FIELD = 901;
	static const int32_t ASN1_MISPLACED_FIELD = 902;
	static const int32_t ASN1_TYPE_MISMATCH = 903;
	static const int32_t ASN1_OVERFLOW = 904;
	static const int32_t ASN1_OVERRUN = 905;
	static const int32_t ASN1_BAD_ID = 906;
	static const int32_t ASN1_BAD_LENGTH = 907;
	static const int32_t ASN1_BAD_FORMAT = 908;
	static const int32_t ASN1_PARSE_ERROR = 909;
	static const int32_t ASN1_BAD_CLASS = 910;
	static const int32_t ASN1_BAD_TYPE = 911;
	static const int32_t ASN1_BAD_TAG = 912;
	static const int32_t ASN1_UNSUPPORTED_TYPE = 913;
	static const int32_t ASN1_CANNOT_ENCODE = 914;
	static ::java::util::Hashtable* errMsgList;
	static bool DEBUG;
	static ::sun::security::util::HexDumpEncoder* hexDumper;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("ADDRTYPE_APPLETALK")
#pragma pop_macro("ADDRTYPE_ATM")
#pragma pop_macro("ADDRTYPE_BAN")
#pragma pop_macro("ADDRTYPE_CCITT")
#pragma pop_macro("ADDRTYPE_CHAOS")
#pragma pop_macro("ADDRTYPE_DATAKIT")
#pragma pop_macro("ADDRTYPE_DECNET")
#pragma pop_macro("ADDRTYPE_DLI")
#pragma pop_macro("ADDRTYPE_ECMA")
#pragma pop_macro("ADDRTYPE_FIREFOX")
#pragma pop_macro("ADDRTYPE_HYLINK")
#pragma pop_macro("ADDRTYPE_IMPLINK")
#pragma pop_macro("ADDRTYPE_INET")
#pragma pop_macro("ADDRTYPE_INET6")
#pragma pop_macro("ADDRTYPE_IPX")
#pragma pop_macro("ADDRTYPE_ISO")
#pragma pop_macro("ADDRTYPE_LAT")
#pragma pop_macro("ADDRTYPE_NETBIOS")
#pragma pop_macro("ADDRTYPE_PUP")
#pragma pop_macro("ADDRTYPE_SNA")
#pragma pop_macro("ADDRTYPE_UNIX")
#pragma pop_macro("ADDRTYPE_VOICEVIEW")
#pragma pop_macro("ADDRTYPE_XNS")
#pragma pop_macro("ADDR_LEN_APPLETALK")
#pragma pop_macro("ADDR_LEN_CHAOS")
#pragma pop_macro("ADDR_LEN_DECNET")
#pragma pop_macro("ADDR_LEN_INET")
#pragma pop_macro("ADDR_LEN_OSI")
#pragma pop_macro("ADDR_LEN_XNS")
#pragma pop_macro("API_INVALID_ARG")
#pragma pop_macro("AP_EMPTY_ADDRESSES_ALLOWED")
#pragma pop_macro("AP_OPTS_MAX")
#pragma pop_macro("AP_OPTS_MUTUAL_REQUIRED")
#pragma pop_macro("AP_OPTS_RESERVED")
#pragma pop_macro("AP_OPTS_USE_SESSION_KEY")
#pragma pop_macro("ASN1_BAD_CLASS")
#pragma pop_macro("ASN1_BAD_FORMAT")
#pragma pop_macro("ASN1_BAD_ID")
#pragma pop_macro("ASN1_BAD_LENGTH")
#pragma pop_macro("ASN1_BAD_TAG")
#pragma pop_macro("ASN1_BAD_TIMEFORMAT")
#pragma pop_macro("ASN1_BAD_TYPE")
#pragma pop_macro("ASN1_CANNOT_ENCODE")
#pragma pop_macro("ASN1_MISPLACED_FIELD")
#pragma pop_macro("ASN1_MISSING_FIELD")
#pragma pop_macro("ASN1_OVERFLOW")
#pragma pop_macro("ASN1_OVERRUN")
#pragma pop_macro("ASN1_PARSE_ERROR")
#pragma pop_macro("ASN1_TYPE_MISMATCH")
#pragma pop_macro("ASN1_UNSUPPORTED_TYPE")
#pragma pop_macro("ATT_CHALLENGE_RESPONSE")
#pragma pop_macro("AUTHNETICATOR_VNO")
#pragma pop_macro("BITSTRING_BAD_LENGTH")
#pragma pop_macro("BITSTRING_INDEX_OUT_OF_BOUNDS")
#pragma pop_macro("BITSTRING_SIZE_INVALID")
#pragma pop_macro("DEBUG")
#pragma pop_macro("DEFAULT_ALLOWABLE_CLOCKSKEW")
#pragma pop_macro("DEFAULT_FORWARDABLE_ALLOWED")
#pragma pop_macro("DEFAULT_MAXIMUM_RENEWABLE_LIFETIME")
#pragma pop_macro("DEFAULT_MAXIMUM_TICKET_LIFETIME")
#pragma pop_macro("DEFAULT_MINIMUM_LIFETIME")
#pragma pop_macro("DEFAULT_POSTDATE_ALLOWED")
#pragma pop_macro("DEFAULT_PROXIABLE_ALLOWED")
#pragma pop_macro("DEFAULT_RENEWABLE_ALLOWED")
#pragma pop_macro("DOMAIN_X500_COMPRESS")
#pragma pop_macro("KDC_DEFAULT_UDP_PREF_LIMIT")
#pragma pop_macro("KDC_ERR_BADOPTION")
#pragma pop_macro("KDC_ERR_BAD_PVNO")
#pragma pop_macro("KDC_ERR_CANNOT_POSTDATE")
#pragma pop_macro("KDC_ERR_CLIENT_NOTYET")
#pragma pop_macro("KDC_ERR_CLIENT_REVOKED")
#pragma pop_macro("KDC_ERR_C_OLD_MAST_KVNO")
#pragma pop_macro("KDC_ERR_C_PRINCIPAL_UNKNOWN")
#pragma pop_macro("KDC_ERR_ETYPE_NOSUPP")
#pragma pop_macro("KDC_ERR_KEY_EXPIRED")
#pragma pop_macro("KDC_ERR_NAME_EXP")
#pragma pop_macro("KDC_ERR_NEVER_VALID")
#pragma pop_macro("KDC_ERR_NONE")
#pragma pop_macro("KDC_ERR_NULL_KEY")
#pragma pop_macro("KDC_ERR_PADATA_TYPE_NOSUPP")
#pragma pop_macro("KDC_ERR_POLICY")
#pragma pop_macro("KDC_ERR_PREAUTH_FAILED")
#pragma pop_macro("KDC_ERR_PREAUTH_REQUIRED")
#pragma pop_macro("KDC_ERR_PRINCIPAL_NOT_UNIQUE")
#pragma pop_macro("KDC_ERR_SERVICE_EXP")
#pragma pop_macro("KDC_ERR_SERVICE_NOTYET")
#pragma pop_macro("KDC_ERR_SERVICE_REVOKED")
#pragma pop_macro("KDC_ERR_SUMTYPE_NOSUPP")
#pragma pop_macro("KDC_ERR_S_OLD_MAST_KVNO")
#pragma pop_macro("KDC_ERR_S_PRINCIPAL_UNKNOWN")
#pragma pop_macro("KDC_ERR_TGT_REVOKED")
#pragma pop_macro("KDC_ERR_TRTYPE_NOSUPP")
#pragma pop_macro("KDC_HARD_UDP_LIMIT")
#pragma pop_macro("KDC_INET_DEFAULT_PORT")
#pragma pop_macro("KDC_OPTS_MAX")
#pragma pop_macro("KDC_RETRY_LIMIT")
#pragma pop_macro("KEYTYPE_AES")
#pragma pop_macro("KEYTYPE_ARCFOUR_HMAC")
#pragma pop_macro("KEYTYPE_DES")
#pragma pop_macro("KEYTYPE_DES3")
#pragma pop_macro("KEYTYPE_NULL")
#pragma pop_macro("KRB_AP_ERR_BADADDR")
#pragma pop_macro("KRB_AP_ERR_BADDIRECTION")
#pragma pop_macro("KRB_AP_ERR_BADKEYVER")
#pragma pop_macro("KRB_AP_ERR_BADMATCH")
#pragma pop_macro("KRB_AP_ERR_BADORDER")
#pragma pop_macro("KRB_AP_ERR_BADSEQ")
#pragma pop_macro("KRB_AP_ERR_BADVERSION")
#pragma pop_macro("KRB_AP_ERR_BAD_INTEGRITY")
#pragma pop_macro("KRB_AP_ERR_GEN_CRED")
#pragma pop_macro("KRB_AP_ERR_INAPP_CKSUM")
#pragma pop_macro("KRB_AP_ERR_METHOD")
#pragma pop_macro("KRB_AP_ERR_MODIFIED")
#pragma pop_macro("KRB_AP_ERR_MSG_TYPE")
#pragma pop_macro("KRB_AP_ERR_MUT_FAIL")
#pragma pop_macro("KRB_AP_ERR_NOKEY")
#pragma pop_macro("KRB_AP_ERR_NOREALM")
#pragma pop_macro("KRB_AP_ERR_NOT_US")
#pragma pop_macro("KRB_AP_ERR_REPEAT")
#pragma pop_macro("KRB_AP_ERR_REQ_OPTIONS")
#pragma pop_macro("KRB_AP_ERR_SKEW")
#pragma pop_macro("KRB_AP_ERR_TKT_EXPIRED")
#pragma pop_macro("KRB_AP_ERR_TKT_NYV")
#pragma pop_macro("KRB_AP_REP")
#pragma pop_macro("KRB_AP_REQ")
#pragma pop_macro("KRB_AS_REP")
#pragma pop_macro("KRB_AS_REQ")
#pragma pop_macro("KRB_AUTHENTICATOR")
#pragma pop_macro("KRB_CRED")
#pragma pop_macro("KRB_CRYPTO_NOT_SUPPORT")
#pragma pop_macro("KRB_ENC_AP_REP_PART")
#pragma pop_macro("KRB_ENC_AS_REP_PART")
#pragma pop_macro("KRB_ENC_KRB_CRED_PART")
#pragma pop_macro("KRB_ENC_KRB_PRIV_PART")
#pragma pop_macro("KRB_ENC_TGS_REP_PART")
#pragma pop_macro("KRB_ENC_TKT_PART")
#pragma pop_macro("KRB_ERROR")
#pragma pop_macro("KRB_ERR_FIELD_TOOLONG")
#pragma pop_macro("KRB_ERR_GENERIC")
#pragma pop_macro("KRB_ERR_RESPONSE_TOO_BIG")
#pragma pop_macro("KRB_ERR_WRONG_REALM")
#pragma pop_macro("KRB_FLAGS_MAX")
#pragma pop_macro("KRB_PRIV")
#pragma pop_macro("KRB_SAFE")
#pragma pop_macro("KRB_TGS_REP")
#pragma pop_macro("KRB_TGS_REQ")
#pragma pop_macro("KRB_TKT")
#pragma pop_macro("LRTYPE_NONE")
#pragma pop_macro("LRTYPE_TIME_OF_INITIAL_REQ")
#pragma pop_macro("LRTYPE_TIME_OF_INITIAL_TGT")
#pragma pop_macro("LRTYPE_TIME_OF_LAST_RENEWAL")
#pragma pop_macro("LRTYPE_TIME_OF_LAST_REQ")
#pragma pop_macro("LRTYPE_TIME_OF_NEWEST_TGT")
#pragma pop_macro("OSF_DCE")
#pragma pop_macro("PA_ENC_TIMESTAMP")
#pragma pop_macro("PA_ETYPE_INFO")
#pragma pop_macro("PA_ETYPE_INFO2")
#pragma pop_macro("PA_FOR_USER")
#pragma pop_macro("PA_PAC_OPTIONS")
#pragma pop_macro("PA_PW_SALT")
#pragma pop_macro("PA_REQ_ENC_PA_REP")
#pragma pop_macro("PA_TGS_REQ")
#pragma pop_macro("PVNO")
#pragma pop_macro("REALM_ILLCHAR")
#pragma pop_macro("REALM_NULL")
#pragma pop_macro("SESAME")
#pragma pop_macro("TICKET_VNO")
#pragma pop_macro("TKT_OPTS_DELEGATE")
#pragma pop_macro("TKT_OPTS_ENC_PA_REP")
#pragma pop_macro("TKT_OPTS_FORWARDABLE")
#pragma pop_macro("TKT_OPTS_FORWARDED")
#pragma pop_macro("TKT_OPTS_HW_AUTHENT")
#pragma pop_macro("TKT_OPTS_INITIAL")
#pragma pop_macro("TKT_OPTS_INVALID")
#pragma pop_macro("TKT_OPTS_MAX")
#pragma pop_macro("TKT_OPTS_MAY_POSTDATE")
#pragma pop_macro("TKT_OPTS_POSTDATED")
#pragma pop_macro("TKT_OPTS_PRE_AUTHENT")
#pragma pop_macro("TKT_OPTS_PROXIABLE")
#pragma pop_macro("TKT_OPTS_PROXY")
#pragma pop_macro("TKT_OPTS_RENEWABLE")
#pragma pop_macro("TKT_OPTS_RESERVED")

#endif // _sun_security_krb5_internal_Krb5_h_