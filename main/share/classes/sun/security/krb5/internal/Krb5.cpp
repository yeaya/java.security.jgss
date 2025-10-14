#include <sun/security/krb5/internal/Krb5.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Hashtable.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef ADDRTYPE_APPLETALK
#undef ADDRTYPE_ATM
#undef ADDRTYPE_BAN
#undef ADDRTYPE_CCITT
#undef ADDRTYPE_CHAOS
#undef ADDRTYPE_DATAKIT
#undef ADDRTYPE_DECNET
#undef ADDRTYPE_DLI
#undef ADDRTYPE_ECMA
#undef ADDRTYPE_FIREFOX
#undef ADDRTYPE_HYLINK
#undef ADDRTYPE_IMPLINK
#undef ADDRTYPE_INET
#undef ADDRTYPE_INET6
#undef ADDRTYPE_IPX
#undef ADDRTYPE_ISO
#undef ADDRTYPE_LAT
#undef ADDRTYPE_NETBIOS
#undef ADDRTYPE_PUP
#undef ADDRTYPE_SNA
#undef ADDRTYPE_UNIX
#undef ADDRTYPE_VOICEVIEW
#undef ADDRTYPE_XNS
#undef ADDR_LEN_APPLETALK
#undef ADDR_LEN_CHAOS
#undef ADDR_LEN_DECNET
#undef ADDR_LEN_INET
#undef ADDR_LEN_OSI
#undef ADDR_LEN_XNS
#undef API_INVALID_ARG
#undef AP_EMPTY_ADDRESSES_ALLOWED
#undef AP_OPTS_MAX
#undef AP_OPTS_MUTUAL_REQUIRED
#undef AP_OPTS_RESERVED
#undef AP_OPTS_USE_SESSION_KEY
#undef ASN1_BAD_CLASS
#undef ASN1_BAD_FORMAT
#undef ASN1_BAD_ID
#undef ASN1_BAD_LENGTH
#undef ASN1_BAD_TAG
#undef ASN1_BAD_TIMEFORMAT
#undef ASN1_BAD_TYPE
#undef ASN1_CANNOT_ENCODE
#undef ASN1_MISPLACED_FIELD
#undef ASN1_MISSING_FIELD
#undef ASN1_OVERFLOW
#undef ASN1_OVERRUN
#undef ASN1_PARSE_ERROR
#undef ASN1_TYPE_MISMATCH
#undef ASN1_UNSUPPORTED_TYPE
#undef ATT_CHALLENGE_RESPONSE
#undef AUTHNETICATOR_VNO
#undef BITSTRING_BAD_LENGTH
#undef BITSTRING_INDEX_OUT_OF_BOUNDS
#undef BITSTRING_SIZE_INVALID
#undef DEBUG
#undef DEFAULT_ALLOWABLE_CLOCKSKEW
#undef DEFAULT_FORWARDABLE_ALLOWED
#undef DEFAULT_MAXIMUM_RENEWABLE_LIFETIME
#undef DEFAULT_MAXIMUM_TICKET_LIFETIME
#undef DEFAULT_MINIMUM_LIFETIME
#undef DEFAULT_POSTDATE_ALLOWED
#undef DEFAULT_PROXIABLE_ALLOWED
#undef DEFAULT_RENEWABLE_ALLOWED
#undef DOMAIN_X500_COMPRESS
#undef KDC_DEFAULT_UDP_PREF_LIMIT
#undef KDC_ERR_BADOPTION
#undef KDC_ERR_BAD_PVNO
#undef KDC_ERR_CANNOT_POSTDATE
#undef KDC_ERR_CLIENT_NOTYET
#undef KDC_ERR_CLIENT_REVOKED
#undef KDC_ERR_C_OLD_MAST_KVNO
#undef KDC_ERR_C_PRINCIPAL_UNKNOWN
#undef KDC_ERR_ETYPE_NOSUPP
#undef KDC_ERR_KEY_EXPIRED
#undef KDC_ERR_NAME_EXP
#undef KDC_ERR_NEVER_VALID
#undef KDC_ERR_NONE
#undef KDC_ERR_NULL_KEY
#undef KDC_ERR_PADATA_TYPE_NOSUPP
#undef KDC_ERR_POLICY
#undef KDC_ERR_PREAUTH_FAILED
#undef KDC_ERR_PREAUTH_REQUIRED
#undef KDC_ERR_PRINCIPAL_NOT_UNIQUE
#undef KDC_ERR_SERVICE_EXP
#undef KDC_ERR_SERVICE_NOTYET
#undef KDC_ERR_SERVICE_REVOKED
#undef KDC_ERR_SUMTYPE_NOSUPP
#undef KDC_ERR_S_OLD_MAST_KVNO
#undef KDC_ERR_S_PRINCIPAL_UNKNOWN
#undef KDC_ERR_TGT_REVOKED
#undef KDC_ERR_TRTYPE_NOSUPP
#undef KDC_HARD_UDP_LIMIT
#undef KDC_INET_DEFAULT_PORT
#undef KDC_OPTS_MAX
#undef KDC_RETRY_LIMIT
#undef KEYTYPE_AES
#undef KEYTYPE_ARCFOUR_HMAC
#undef KEYTYPE_DES
#undef KEYTYPE_DES3
#undef KEYTYPE_NULL
#undef KRB_AP_ERR_BADADDR
#undef KRB_AP_ERR_BADDIRECTION
#undef KRB_AP_ERR_BADKEYVER
#undef KRB_AP_ERR_BADMATCH
#undef KRB_AP_ERR_BADORDER
#undef KRB_AP_ERR_BADSEQ
#undef KRB_AP_ERR_BADVERSION
#undef KRB_AP_ERR_BAD_INTEGRITY
#undef KRB_AP_ERR_GEN_CRED
#undef KRB_AP_ERR_INAPP_CKSUM
#undef KRB_AP_ERR_METHOD
#undef KRB_AP_ERR_MODIFIED
#undef KRB_AP_ERR_MSG_TYPE
#undef KRB_AP_ERR_MUT_FAIL
#undef KRB_AP_ERR_NOKEY
#undef KRB_AP_ERR_NOREALM
#undef KRB_AP_ERR_NOT_US
#undef KRB_AP_ERR_REPEAT
#undef KRB_AP_ERR_REQ_OPTIONS
#undef KRB_AP_ERR_SKEW
#undef KRB_AP_ERR_TKT_EXPIRED
#undef KRB_AP_ERR_TKT_NYV
#undef KRB_AP_REP
#undef KRB_AP_REQ
#undef KRB_AS_REP
#undef KRB_AS_REQ
#undef KRB_AUTHENTICATOR
#undef KRB_CRED
#undef KRB_CRYPTO_NOT_SUPPORT
#undef KRB_ENC_AP_REP_PART
#undef KRB_ENC_AS_REP_PART
#undef KRB_ENC_KRB_CRED_PART
#undef KRB_ENC_KRB_PRIV_PART
#undef KRB_ENC_TGS_REP_PART
#undef KRB_ENC_TKT_PART
#undef KRB_ERROR
#undef KRB_ERR_FIELD_TOOLONG
#undef KRB_ERR_GENERIC
#undef KRB_ERR_RESPONSE_TOO_BIG
#undef KRB_ERR_WRONG_REALM
#undef KRB_FLAGS_MAX
#undef KRB_PRIV
#undef KRB_SAFE
#undef KRB_TGS_REP
#undef KRB_TGS_REQ
#undef KRB_TKT
#undef LRTYPE_NONE
#undef LRTYPE_TIME_OF_INITIAL_REQ
#undef LRTYPE_TIME_OF_INITIAL_TGT
#undef LRTYPE_TIME_OF_LAST_RENEWAL
#undef LRTYPE_TIME_OF_LAST_REQ
#undef LRTYPE_TIME_OF_NEWEST_TGT
#undef OSF_DCE
#undef PA_ENC_TIMESTAMP
#undef PA_ETYPE_INFO
#undef PA_ETYPE_INFO2
#undef PA_FOR_USER
#undef PA_PAC_OPTIONS
#undef PA_PW_SALT
#undef PA_REQ_ENC_PA_REP
#undef PA_TGS_REQ
#undef PVNO
#undef REALM_ILLCHAR
#undef REALM_NULL
#undef SESAME
#undef TICKET_VNO
#undef TKT_OPTS_DELEGATE
#undef TKT_OPTS_ENC_PA_REP
#undef TKT_OPTS_FORWARDABLE
#undef TKT_OPTS_FORWARDED
#undef TKT_OPTS_HW_AUTHENT
#undef TKT_OPTS_INITIAL
#undef TKT_OPTS_INVALID
#undef TKT_OPTS_MAX
#undef TKT_OPTS_MAY_POSTDATE
#undef TKT_OPTS_POSTDATED
#undef TKT_OPTS_PRE_AUTHENT
#undef TKT_OPTS_PROXIABLE
#undef TKT_OPTS_PROXY
#undef TKT_OPTS_RENEWABLE
#undef TKT_OPTS_RESERVED

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Hashtable = ::java::util::Hashtable;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _Krb5_FieldInfo_[] = {
	{"DEFAULT_ALLOWABLE_CLOCKSKEW", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, DEFAULT_ALLOWABLE_CLOCKSKEW)},
	{"DEFAULT_MINIMUM_LIFETIME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, DEFAULT_MINIMUM_LIFETIME)},
	{"DEFAULT_MAXIMUM_RENEWABLE_LIFETIME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, DEFAULT_MAXIMUM_RENEWABLE_LIFETIME)},
	{"DEFAULT_MAXIMUM_TICKET_LIFETIME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, DEFAULT_MAXIMUM_TICKET_LIFETIME)},
	{"DEFAULT_FORWARDABLE_ALLOWED", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, DEFAULT_FORWARDABLE_ALLOWED)},
	{"DEFAULT_PROXIABLE_ALLOWED", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, DEFAULT_PROXIABLE_ALLOWED)},
	{"DEFAULT_POSTDATE_ALLOWED", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, DEFAULT_POSTDATE_ALLOWED)},
	{"DEFAULT_RENEWABLE_ALLOWED", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, DEFAULT_RENEWABLE_ALLOWED)},
	{"AP_EMPTY_ADDRESSES_ALLOWED", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, AP_EMPTY_ADDRESSES_ALLOWED)},
	{"AP_OPTS_RESERVED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, AP_OPTS_RESERVED)},
	{"AP_OPTS_USE_SESSION_KEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, AP_OPTS_USE_SESSION_KEY)},
	{"AP_OPTS_MUTUAL_REQUIRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, AP_OPTS_MUTUAL_REQUIRED)},
	{"AP_OPTS_MAX", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, AP_OPTS_MAX)},
	{"TKT_OPTS_RESERVED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_RESERVED)},
	{"TKT_OPTS_FORWARDABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_FORWARDABLE)},
	{"TKT_OPTS_FORWARDED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_FORWARDED)},
	{"TKT_OPTS_PROXIABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_PROXIABLE)},
	{"TKT_OPTS_PROXY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_PROXY)},
	{"TKT_OPTS_MAY_POSTDATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_MAY_POSTDATE)},
	{"TKT_OPTS_POSTDATED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_POSTDATED)},
	{"TKT_OPTS_INVALID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_INVALID)},
	{"TKT_OPTS_RENEWABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_RENEWABLE)},
	{"TKT_OPTS_INITIAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_INITIAL)},
	{"TKT_OPTS_PRE_AUTHENT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_PRE_AUTHENT)},
	{"TKT_OPTS_HW_AUTHENT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_HW_AUTHENT)},
	{"TKT_OPTS_DELEGATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_DELEGATE)},
	{"TKT_OPTS_ENC_PA_REP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_ENC_PA_REP)},
	{"TKT_OPTS_MAX", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TKT_OPTS_MAX)},
	{"KDC_OPTS_MAX", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_OPTS_MAX)},
	{"KRB_FLAGS_MAX", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_FLAGS_MAX)},
	{"LRTYPE_NONE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, LRTYPE_NONE)},
	{"LRTYPE_TIME_OF_INITIAL_TGT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, LRTYPE_TIME_OF_INITIAL_TGT)},
	{"LRTYPE_TIME_OF_INITIAL_REQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, LRTYPE_TIME_OF_INITIAL_REQ)},
	{"LRTYPE_TIME_OF_NEWEST_TGT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, LRTYPE_TIME_OF_NEWEST_TGT)},
	{"LRTYPE_TIME_OF_LAST_RENEWAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, LRTYPE_TIME_OF_LAST_RENEWAL)},
	{"LRTYPE_TIME_OF_LAST_REQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, LRTYPE_TIME_OF_LAST_REQ)},
	{"ADDR_LEN_INET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDR_LEN_INET)},
	{"ADDR_LEN_CHAOS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDR_LEN_CHAOS)},
	{"ADDR_LEN_OSI", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDR_LEN_OSI)},
	{"ADDR_LEN_XNS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDR_LEN_XNS)},
	{"ADDR_LEN_APPLETALK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDR_LEN_APPLETALK)},
	{"ADDR_LEN_DECNET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDR_LEN_DECNET)},
	{"ADDRTYPE_UNIX", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_UNIX)},
	{"ADDRTYPE_INET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_INET)},
	{"ADDRTYPE_IMPLINK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_IMPLINK)},
	{"ADDRTYPE_PUP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_PUP)},
	{"ADDRTYPE_CHAOS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_CHAOS)},
	{"ADDRTYPE_XNS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_XNS)},
	{"ADDRTYPE_IPX", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_IPX)},
	{"ADDRTYPE_ISO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_ISO)},
	{"ADDRTYPE_ECMA", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_ECMA)},
	{"ADDRTYPE_DATAKIT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_DATAKIT)},
	{"ADDRTYPE_CCITT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_CCITT)},
	{"ADDRTYPE_SNA", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_SNA)},
	{"ADDRTYPE_DECNET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_DECNET)},
	{"ADDRTYPE_DLI", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_DLI)},
	{"ADDRTYPE_LAT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_LAT)},
	{"ADDRTYPE_HYLINK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_HYLINK)},
	{"ADDRTYPE_APPLETALK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_APPLETALK)},
	{"ADDRTYPE_NETBIOS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_NETBIOS)},
	{"ADDRTYPE_VOICEVIEW", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_VOICEVIEW)},
	{"ADDRTYPE_FIREFOX", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_FIREFOX)},
	{"ADDRTYPE_BAN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_BAN)},
	{"ADDRTYPE_ATM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_ATM)},
	{"ADDRTYPE_INET6", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ADDRTYPE_INET6)},
	{"KDC_INET_DEFAULT_PORT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_INET_DEFAULT_PORT)},
	{"KDC_RETRY_LIMIT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_RETRY_LIMIT)},
	{"KDC_DEFAULT_UDP_PREF_LIMIT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_DEFAULT_UDP_PREF_LIMIT)},
	{"KDC_HARD_UDP_LIMIT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_HARD_UDP_LIMIT)},
	{"KEYTYPE_NULL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KEYTYPE_NULL)},
	{"KEYTYPE_DES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KEYTYPE_DES)},
	{"KEYTYPE_DES3", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KEYTYPE_DES3)},
	{"KEYTYPE_AES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KEYTYPE_AES)},
	{"KEYTYPE_ARCFOUR_HMAC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KEYTYPE_ARCFOUR_HMAC)},
	{"PA_TGS_REQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, PA_TGS_REQ)},
	{"PA_ENC_TIMESTAMP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, PA_ENC_TIMESTAMP)},
	{"PA_PW_SALT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, PA_PW_SALT)},
	{"PA_ETYPE_INFO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, PA_ETYPE_INFO)},
	{"PA_ETYPE_INFO2", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, PA_ETYPE_INFO2)},
	{"PA_FOR_USER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, PA_FOR_USER)},
	{"PA_PAC_OPTIONS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, PA_PAC_OPTIONS)},
	{"PA_REQ_ENC_PA_REP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, PA_REQ_ENC_PA_REP)},
	{"OSF_DCE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, OSF_DCE)},
	{"SESAME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, SESAME)},
	{"ATT_CHALLENGE_RESPONSE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ATT_CHALLENGE_RESPONSE)},
	{"DOMAIN_X500_COMPRESS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, DOMAIN_X500_COMPRESS)},
	{"PVNO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, PVNO)},
	{"AUTHNETICATOR_VNO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, AUTHNETICATOR_VNO)},
	{"TICKET_VNO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, TICKET_VNO)},
	{"KRB_AS_REQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AS_REQ)},
	{"KRB_AS_REP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AS_REP)},
	{"KRB_TGS_REQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_TGS_REQ)},
	{"KRB_TGS_REP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_TGS_REP)},
	{"KRB_AP_REQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_REQ)},
	{"KRB_AP_REP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_REP)},
	{"KRB_SAFE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_SAFE)},
	{"KRB_PRIV", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_PRIV)},
	{"KRB_CRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_CRED)},
	{"KRB_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ERROR)},
	{"KRB_TKT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_TKT)},
	{"KRB_AUTHENTICATOR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AUTHENTICATOR)},
	{"KRB_ENC_TKT_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ENC_TKT_PART)},
	{"KRB_ENC_AS_REP_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ENC_AS_REP_PART)},
	{"KRB_ENC_TGS_REP_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ENC_TGS_REP_PART)},
	{"KRB_ENC_AP_REP_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ENC_AP_REP_PART)},
	{"KRB_ENC_KRB_PRIV_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ENC_KRB_PRIV_PART)},
	{"KRB_ENC_KRB_CRED_PART", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ENC_KRB_CRED_PART)},
	{"KDC_ERR_NONE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_NONE)},
	{"KDC_ERR_NAME_EXP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_NAME_EXP)},
	{"KDC_ERR_SERVICE_EXP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_SERVICE_EXP)},
	{"KDC_ERR_BAD_PVNO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_BAD_PVNO)},
	{"KDC_ERR_C_OLD_MAST_KVNO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_C_OLD_MAST_KVNO)},
	{"KDC_ERR_S_OLD_MAST_KVNO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_S_OLD_MAST_KVNO)},
	{"KDC_ERR_C_PRINCIPAL_UNKNOWN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_C_PRINCIPAL_UNKNOWN)},
	{"KDC_ERR_S_PRINCIPAL_UNKNOWN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_S_PRINCIPAL_UNKNOWN)},
	{"KDC_ERR_PRINCIPAL_NOT_UNIQUE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_PRINCIPAL_NOT_UNIQUE)},
	{"KDC_ERR_NULL_KEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_NULL_KEY)},
	{"KDC_ERR_CANNOT_POSTDATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_CANNOT_POSTDATE)},
	{"KDC_ERR_NEVER_VALID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_NEVER_VALID)},
	{"KDC_ERR_POLICY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_POLICY)},
	{"KDC_ERR_BADOPTION", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_BADOPTION)},
	{"KDC_ERR_ETYPE_NOSUPP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_ETYPE_NOSUPP)},
	{"KDC_ERR_SUMTYPE_NOSUPP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_SUMTYPE_NOSUPP)},
	{"KDC_ERR_PADATA_TYPE_NOSUPP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_PADATA_TYPE_NOSUPP)},
	{"KDC_ERR_TRTYPE_NOSUPP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_TRTYPE_NOSUPP)},
	{"KDC_ERR_CLIENT_REVOKED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_CLIENT_REVOKED)},
	{"KDC_ERR_SERVICE_REVOKED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_SERVICE_REVOKED)},
	{"KDC_ERR_TGT_REVOKED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_TGT_REVOKED)},
	{"KDC_ERR_CLIENT_NOTYET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_CLIENT_NOTYET)},
	{"KDC_ERR_SERVICE_NOTYET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_SERVICE_NOTYET)},
	{"KDC_ERR_KEY_EXPIRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_KEY_EXPIRED)},
	{"KDC_ERR_PREAUTH_FAILED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_PREAUTH_FAILED)},
	{"KDC_ERR_PREAUTH_REQUIRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KDC_ERR_PREAUTH_REQUIRED)},
	{"KRB_AP_ERR_BAD_INTEGRITY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_BAD_INTEGRITY)},
	{"KRB_AP_ERR_TKT_EXPIRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_TKT_EXPIRED)},
	{"KRB_AP_ERR_TKT_NYV", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_TKT_NYV)},
	{"KRB_AP_ERR_REPEAT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_REPEAT)},
	{"KRB_AP_ERR_NOT_US", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_NOT_US)},
	{"KRB_AP_ERR_BADMATCH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_BADMATCH)},
	{"KRB_AP_ERR_SKEW", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_SKEW)},
	{"KRB_AP_ERR_BADADDR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_BADADDR)},
	{"KRB_AP_ERR_BADVERSION", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_BADVERSION)},
	{"KRB_AP_ERR_MSG_TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_MSG_TYPE)},
	{"KRB_AP_ERR_MODIFIED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_MODIFIED)},
	{"KRB_AP_ERR_BADORDER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_BADORDER)},
	{"KRB_AP_ERR_BADKEYVER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_BADKEYVER)},
	{"KRB_AP_ERR_NOKEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_NOKEY)},
	{"KRB_AP_ERR_MUT_FAIL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_MUT_FAIL)},
	{"KRB_AP_ERR_BADDIRECTION", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_BADDIRECTION)},
	{"KRB_AP_ERR_METHOD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_METHOD)},
	{"KRB_AP_ERR_BADSEQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_BADSEQ)},
	{"KRB_AP_ERR_INAPP_CKSUM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_INAPP_CKSUM)},
	{"KRB_ERR_RESPONSE_TOO_BIG", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ERR_RESPONSE_TOO_BIG)},
	{"KRB_ERR_GENERIC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ERR_GENERIC)},
	{"KRB_ERR_FIELD_TOOLONG", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ERR_FIELD_TOOLONG)},
	{"KRB_ERR_WRONG_REALM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_ERR_WRONG_REALM)},
	{"KRB_CRYPTO_NOT_SUPPORT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_CRYPTO_NOT_SUPPORT)},
	{"KRB_AP_ERR_NOREALM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_NOREALM)},
	{"KRB_AP_ERR_GEN_CRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_GEN_CRED)},
	{"KRB_AP_ERR_REQ_OPTIONS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, KRB_AP_ERR_REQ_OPTIONS)},
	{"API_INVALID_ARG", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, API_INVALID_ARG)},
	{"BITSTRING_SIZE_INVALID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, BITSTRING_SIZE_INVALID)},
	{"BITSTRING_INDEX_OUT_OF_BOUNDS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, BITSTRING_INDEX_OUT_OF_BOUNDS)},
	{"BITSTRING_BAD_LENGTH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, BITSTRING_BAD_LENGTH)},
	{"REALM_ILLCHAR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, REALM_ILLCHAR)},
	{"REALM_NULL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, REALM_NULL)},
	{"ASN1_BAD_TIMEFORMAT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_BAD_TIMEFORMAT)},
	{"ASN1_MISSING_FIELD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_MISSING_FIELD)},
	{"ASN1_MISPLACED_FIELD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_MISPLACED_FIELD)},
	{"ASN1_TYPE_MISMATCH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_TYPE_MISMATCH)},
	{"ASN1_OVERFLOW", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_OVERFLOW)},
	{"ASN1_OVERRUN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_OVERRUN)},
	{"ASN1_BAD_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_BAD_ID)},
	{"ASN1_BAD_LENGTH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_BAD_LENGTH)},
	{"ASN1_BAD_FORMAT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_BAD_FORMAT)},
	{"ASN1_PARSE_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_PARSE_ERROR)},
	{"ASN1_BAD_CLASS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_BAD_CLASS)},
	{"ASN1_BAD_TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_BAD_TYPE)},
	{"ASN1_BAD_TAG", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_BAD_TAG)},
	{"ASN1_UNSUPPORTED_TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_UNSUPPORTED_TYPE)},
	{"ASN1_CANNOT_ENCODE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Krb5, ASN1_CANNOT_ENCODE)},
	{"errMsgList", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/Integer;Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticField(Krb5, errMsgList)},
	{"DEBUG", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Krb5, DEBUG)},
	{"hexDumper", "Lsun/security/util/HexDumpEncoder;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Krb5, hexDumper)},
	{}
};

$MethodInfo _Krb5_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Krb5::*)()>(&Krb5::init$))},
	{"getErrorMessage", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)(int32_t)>(&Krb5::getErrorMessage))},
	{}
};

$ClassInfo _Krb5_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.Krb5",
	"java.lang.Object",
	nullptr,
	_Krb5_FieldInfo_,
	_Krb5_MethodInfo_
};

$Object* allocate$Krb5($Class* clazz) {
	return $of($alloc(Krb5));
}

$Hashtable* Krb5::errMsgList = nullptr;
bool Krb5::DEBUG = false;
$HexDumpEncoder* Krb5::hexDumper = nullptr;

void Krb5::init$() {
}

$String* Krb5::getErrorMessage(int32_t i) {
	$init(Krb5);
	return $cast($String, $nc(Krb5::errMsgList)->get($($Integer::valueOf(i))));
}

void clinit$Krb5($Class* class$) {
	Krb5::DEBUG = $GetBooleanAction::privilegedGetProperty("sun.security.krb5.debug"_s);
	$assignStatic(Krb5::hexDumper, $new($HexDumpEncoder));
	{
		$assignStatic(Krb5::errMsgList, $new($Hashtable));
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_NONE)), "No error"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_NAME_EXP)), "Client\'s entry in database expired"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_SERVICE_EXP)), "Server\'s entry in database has expired"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_BAD_PVNO)), "Requested protocol version number not supported"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_C_OLD_MAST_KVNO)), "Client\'s key encrypted in old master key"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_S_OLD_MAST_KVNO)), "Server\'s key encrypted in old master key"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_C_PRINCIPAL_UNKNOWN)), "Client not found in Kerberos database"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_S_PRINCIPAL_UNKNOWN)), "Server not found in Kerberos database"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_PRINCIPAL_NOT_UNIQUE)), "Multiple principal entries in database"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_NULL_KEY)), "The client or server has a null key"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_CANNOT_POSTDATE)), "Ticket not eligible for postdating"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_NEVER_VALID)), "Requested start time is later than end time"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_POLICY)), "KDC policy rejects request"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_BADOPTION)), "KDC cannot accommodate requested option"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_ETYPE_NOSUPP)), "KDC has no support for encryption type"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_SUMTYPE_NOSUPP)), "KDC has no support for checksum type"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_PADATA_TYPE_NOSUPP)), "KDC has no support for padata type"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_TRTYPE_NOSUPP)), "KDC has no support for transited type"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_CLIENT_REVOKED)), "Clients credentials have been revoked"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_SERVICE_REVOKED)), "Credentials for server have been revoked"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_TGT_REVOKED)), "TGT has been revoked"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_CLIENT_NOTYET)), "Client not yet valid - try again later"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_SERVICE_NOTYET)), "Server not yet valid - try again later"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_KEY_EXPIRED)), "Password has expired - change password to reset"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_PREAUTH_FAILED)), "Pre-authentication information was invalid"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KDC_ERR_PREAUTH_REQUIRED)), "Additional pre-authentication required"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_BAD_INTEGRITY)), "Integrity check on decrypted field failed"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_TKT_EXPIRED)), "Ticket expired"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_TKT_NYV)), "Ticket not yet valid"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_REPEAT)), "Request is a replay"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_NOT_US)), "The ticket isn\'t for us"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_BADMATCH)), "Ticket and authenticator don\'t match"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_SKEW)), "Clock skew too great"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_BADADDR)), "Incorrect net address"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_BADVERSION)), "Protocol version mismatch"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_MSG_TYPE)), "Invalid msg type"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_MODIFIED)), "Message stream modified"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_BADORDER)), "Message out of order"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_BADKEYVER)), "Specified version of key is not available"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_NOKEY)), "Service key not available"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_MUT_FAIL)), "Mutual authentication failed"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_BADDIRECTION)), "Incorrect message direction"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_METHOD)), "Alternative authentication method required"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_BADSEQ)), "Incorrect sequence number in message"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_INAPP_CKSUM)), "Inappropriate type of checksum in message"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_ERR_RESPONSE_TOO_BIG)), "Response too big for UDP, retry with TCP"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_ERR_GENERIC)), "Generic error (description in e-text)"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_ERR_FIELD_TOOLONG)), "Field is too long for this implementation"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_NOREALM)), "Realm name not available"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::API_INVALID_ARG)), "Invalid argument"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::BITSTRING_SIZE_INVALID)), "BitString size does not match input byte array"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::BITSTRING_INDEX_OUT_OF_BOUNDS)), "BitString bit index does not fall within size"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::BITSTRING_BAD_LENGTH)), "BitString length is wrong for the expected type"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::REALM_ILLCHAR)), $cstr({'I', 'l', 'l', 'e', 'g', 'a', 'l', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'i', 'n', ' ', 'r', 'e', 'a', 'l', 'm', ' ', 'n', 'a', 'm', 'e', ';', ' ', 'o', 'n', 'e', ' ', 'o', 'f', ':', ' ', '\'', '/', '\'', ',', ' ', '\'', ':', '\'', ',', ' ', '\'', '\0', '\''}));
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::REALM_NULL)), "Null realm name"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_BAD_TIMEFORMAT)), "Input not in GeneralizedTime format"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_MISSING_FIELD)), "Structure is missing a required field"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_MISPLACED_FIELD)), "Unexpected field number"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_TYPE_MISMATCH)), "Type numbers are inconsistent"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_OVERFLOW)), "Value too large"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_OVERRUN)), "Encoding ended unexpectedly"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_BAD_ID)), "Identifier doesn\'t match expected value"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_BAD_LENGTH)), "Length doesn\'t match expected value"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_BAD_FORMAT)), "Badly-formatted encoding"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_PARSE_ERROR)), "Parse error"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_BAD_CLASS)), "Bad class number"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_BAD_TYPE)), "Bad type number"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_BAD_TAG)), "Bad tag number"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_UNSUPPORTED_TYPE)), "Unsupported ASN.1 type encountered"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::ASN1_CANNOT_ENCODE)), "Encoding failed due to invalid parameter(s)"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_CRYPTO_NOT_SUPPORT)), "Client has no support for crypto type"_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_REQ_OPTIONS)), "Invalid option setting in ticket request."_s);
		$nc(Krb5::errMsgList)->put($($Integer::valueOf(Krb5::KRB_AP_ERR_GEN_CRED)), "Fail to create credential."_s);
	}
}

Krb5::Krb5() {
}

$Class* Krb5::load$($String* name, bool initialize) {
	$loadClass(Krb5, name, initialize, &_Krb5_ClassInfo_, clinit$Krb5, allocate$Krb5);
	return class$;
}

$Class* Krb5::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun