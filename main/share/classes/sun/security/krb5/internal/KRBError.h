#ifndef _sun_security_krb5_internal_KRBError_h_
#define _sun_security_krb5_internal_KRBError_h_
//$ class sun.security.krb5.internal.KRBError
//$ extends java.io.Serializable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
	}
}
namespace java {
	namespace lang {
		class Integer;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Checksum;
			class PrincipalName;
			class Realm;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class APOptions;
				class KerberosTime;
				class PAData;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

class $export KRBError : public ::java::io::Serializable {
	$class(KRBError, 0, ::java::io::Serializable)
public:
	KRBError();
	void init$(::sun::security::krb5::internal::APOptions* new_apOptions, ::sun::security::krb5::internal::KerberosTime* new_cTime, ::java::lang::Integer* new_cuSec, ::sun::security::krb5::internal::KerberosTime* new_sTime, ::java::lang::Integer* new_suSec, int32_t new_errorCode, ::sun::security::krb5::PrincipalName* new_cname, ::sun::security::krb5::PrincipalName* new_sname, $String* new_eText, $bytes* new_eData);
	void init$(::sun::security::krb5::internal::APOptions* new_apOptions, ::sun::security::krb5::internal::KerberosTime* new_cTime, ::java::lang::Integer* new_cuSec, ::sun::security::krb5::internal::KerberosTime* new_sTime, ::java::lang::Integer* new_suSec, int32_t new_errorCode, ::sun::security::krb5::PrincipalName* new_cname, ::sun::security::krb5::PrincipalName* new_sname, $String* new_eText, $bytes* new_eData, ::sun::security::krb5::Checksum* new_eCksum);
	void init$($bytes* data);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual bool equals(Object$* obj) override;
	::java::lang::Integer* getClientMicroSeconds();
	::sun::security::krb5::Realm* getClientRealm();
	::sun::security::krb5::internal::KerberosTime* getClientTime();
	int32_t getErrorCode();
	$String* getErrorString();
	$Array<::sun::security::krb5::internal::PAData>* getPA();
	::java::lang::Integer* getServerMicroSeconds();
	::sun::security::krb5::internal::KerberosTime* getServerTime();
	virtual int32_t hashCode() override;
	void init(::sun::security::util::DerValue* encoding);
	static bool isEqual(Object$* a, Object$* b);
	void parseEData($bytes* data);
	void parsePAData($bytes* data);
	void readObject(::java::io::ObjectInputStream* is);
	void showDebug();
	void writeObject(::java::io::ObjectOutputStream* os);
	static const int64_t serialVersionUID = (int64_t)0x3291694965773E17;
	int32_t pvno = 0;
	int32_t msgType = 0;
	::sun::security::krb5::internal::KerberosTime* cTime = nullptr;
	::java::lang::Integer* cuSec = nullptr;
	::sun::security::krb5::internal::KerberosTime* sTime = nullptr;
	::java::lang::Integer* suSec = nullptr;
	int32_t errorCode = 0;
	::sun::security::krb5::Realm* crealm = nullptr;
	::sun::security::krb5::PrincipalName* cname = nullptr;
	::sun::security::krb5::PrincipalName* sname = nullptr;
	$String* eText = nullptr;
	$bytes* eData = nullptr;
	::sun::security::krb5::Checksum* eCksum = nullptr;
	$Array<::sun::security::krb5::internal::PAData>* pa = nullptr;
	static bool DEBUG;
};

			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_KRBError_h_