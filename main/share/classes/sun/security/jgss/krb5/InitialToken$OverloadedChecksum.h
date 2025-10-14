#ifndef _sun_security_jgss_krb5_InitialToken$OverloadedChecksum_h_
#define _sun_security_jgss_krb5_InitialToken$OverloadedChecksum_h_
//$ class sun.security.jgss.krb5.InitialToken$OverloadedChecksum
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class CipherHelper;
				class InitialToken;
				class Krb5Context;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Checksum;
			class Credentials;
			class EncryptionKey;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class InitialToken$OverloadedChecksum : public ::java::lang::Object {
	$class(InitialToken$OverloadedChecksum, $NO_CLASS_INIT, ::java::lang::Object)
public:
	InitialToken$OverloadedChecksum();
	void init$(::sun::security::jgss::krb5::InitialToken* this$0, ::sun::security::jgss::krb5::Krb5Context* context, ::sun::security::krb5::Credentials* tgt, ::sun::security::krb5::Credentials* serviceTicket);
	void init$(::sun::security::jgss::krb5::InitialToken* this$0, ::sun::security::jgss::krb5::Krb5Context* context, ::sun::security::krb5::Checksum* checksum, ::sun::security::krb5::EncryptionKey* key, ::sun::security::krb5::EncryptionKey* subKey);
	virtual ::sun::security::krb5::Checksum* getChecksum();
	virtual ::sun::security::krb5::Credentials* getDelegatedCreds();
	virtual void setContextFlags(::sun::security::jgss::krb5::Krb5Context* context);
	bool useNullKey(::sun::security::jgss::krb5::CipherHelper* ch);
	::sun::security::jgss::krb5::InitialToken* this$0 = nullptr;
	$bytes* checksumBytes = nullptr;
	::sun::security::krb5::Credentials* delegCreds = nullptr;
	int32_t flags = 0;
};

			} // krb5
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_krb5_InitialToken$OverloadedChecksum_h_