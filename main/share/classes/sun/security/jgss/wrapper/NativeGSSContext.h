#ifndef _sun_security_jgss_wrapper_NativeGSSContext_h_
#define _sun_security_jgss_wrapper_NativeGSSContext_h_
//$ class sun.security.jgss.wrapper.NativeGSSContext
//$ extends sun.security.jgss.spi.GSSContextSpi

#include <java/lang/Array.h>
#include <sun/security/jgss/spi/GSSContextSpi.h>

#pragma push_macro("GSS_C_ANON_FLAG")
#undef GSS_C_ANON_FLAG
#pragma push_macro("GSS_C_CONF_FLAG")
#undef GSS_C_CONF_FLAG
#pragma push_macro("GSS_C_DELEG_FLAG")
#undef GSS_C_DELEG_FLAG
#pragma push_macro("GSS_C_INTEG_FLAG")
#undef GSS_C_INTEG_FLAG
#pragma push_macro("GSS_C_MUTUAL_FLAG")
#undef GSS_C_MUTUAL_FLAG
#pragma push_macro("GSS_C_PROT_READY_FLAG")
#undef GSS_C_PROT_READY_FLAG
#pragma push_macro("GSS_C_REPLAY_FLAG")
#undef GSS_C_REPLAY_FLAG
#pragma push_macro("GSS_C_SEQUENCE_FLAG")
#undef GSS_C_SEQUENCE_FLAG
#pragma push_macro("GSS_C_TRANS_FLAG")
#undef GSS_C_TRANS_FLAG
#pragma push_macro("NUM_OF_INQUIRE_VALUES")
#undef NUM_OF_INQUIRE_VALUES

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
	}
}
namespace java {
	namespace security {
		class Provider;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class ChannelBinding;
			class MessageProp;
			class Oid;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {
				class GSSCredentialSpi;
				class GSSNameSpi;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {
				class GSSCredElement;
				class GSSLibStub;
				class GSSNameElement;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

class NativeGSSContext : public ::sun::security::jgss::spi::GSSContextSpi {
	$class(NativeGSSContext, $HAS_FINALIZE, ::sun::security::jgss::spi::GSSContextSpi)
public:
	NativeGSSContext();
	void init$(::sun::security::jgss::wrapper::GSSNameElement* peer, ::sun::security::jgss::wrapper::GSSCredElement* myCred, int32_t time, ::sun::security::jgss::wrapper::GSSLibStub* stub);
	void init$(::sun::security::jgss::wrapper::GSSCredElement* myCred, ::sun::security::jgss::wrapper::GSSLibStub* stub);
	void init$(int64_t pCtxt, ::sun::security::jgss::wrapper::GSSLibStub* stub);
	virtual $bytes* acceptSecContext(::java::io::InputStream* is, int32_t mechTokenLen) override;
	void changeFlags(int32_t flagMask, bool isEnable);
	bool checkFlags(int32_t flagMask);
	virtual void dispose() override;
	void doDelegPermCheck();
	void doServicePermCheck();
	virtual $bytes* export$() override;
	virtual void finalize() override;
	virtual bool getAnonymityState() override;
	virtual bool getConfState() override;
	virtual bool getCredDelegState() override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getDelegCred() override;
	virtual bool getDelegPolicyState() override;
	virtual bool getIntegState() override;
	virtual int32_t getLifetime() override;
	virtual $bytes* getMIC($bytes* in, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void getMIC(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual ::org::ietf::jgss::Oid* getMech() override;
	static ::org::ietf::jgss::Oid* getMechFromSpNegoToken($bytes* token, bool isInitiator);
	virtual bool getMutualAuthState() override;
	virtual ::java::security::Provider* getProvider() override;
	virtual bool getReplayDetState() override;
	virtual bool getSequenceDetState() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getSrcName() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getTargName() override;
	virtual int32_t getWrapSizeLimit(int32_t qop, bool confReq, int32_t maxTokenSize) override;
	virtual $bytes* initSecContext(::java::io::InputStream* is, int32_t mechTokenLen) override;
	virtual $Object* inquireSecContext($String* type) override;
	virtual bool isEstablished() override;
	virtual bool isInitiator() override;
	virtual bool isProtReady() override;
	virtual bool isTransferable() override;
	virtual void requestAnonymity(bool state) override;
	virtual void requestConf(bool state) override;
	virtual void requestCredDeleg(bool state) override;
	virtual void requestDelegPolicy(bool state) override;
	virtual void requestInteg(bool state) override;
	virtual void requestLifetime(int32_t lifetime) override;
	virtual void requestMutualAuth(bool state) override;
	virtual void requestReplayDet(bool state) override;
	virtual void requestSequenceDet(bool state) override;
	$bytes* retrieveToken(::java::io::InputStream* is, int32_t mechTokenLen);
	virtual void setChannelBinding(::org::ietf::jgss::ChannelBinding* cb) override;
	virtual $bytes* unwrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual int32_t unwrap($bytes* inBuf, int32_t inOffset, int32_t len, $bytes* outBuf, int32_t outOffset, ::org::ietf::jgss::MessageProp* msgProp);
	virtual void unwrap(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual int32_t unwrap(::java::io::InputStream* inStream, $bytes* outBuf, int32_t outOffset, ::org::ietf::jgss::MessageProp* msgProp);
	virtual void verifyMIC($bytes* inToken, int32_t tOffset, int32_t tLen, $bytes* inMsg, int32_t mOffset, int32_t mLen, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void verifyMIC(::java::io::InputStream* tokStream, ::java::io::InputStream* msgStream, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual $bytes* wrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void wrap($bytes* inBuf, int32_t offset, int32_t len, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp);
	virtual int32_t wrap($bytes* inBuf, int32_t inOffset, int32_t len, $bytes* outBuf, int32_t outOffset, ::org::ietf::jgss::MessageProp* msgProp);
	virtual void wrap(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream, ::org::ietf::jgss::MessageProp* msgProp) override;
	static bool $assertionsDisabled;
	static const int32_t GSS_C_DELEG_FLAG = 1;
	static const int32_t GSS_C_MUTUAL_FLAG = 2;
	static const int32_t GSS_C_REPLAY_FLAG = 4;
	static const int32_t GSS_C_SEQUENCE_FLAG = 8;
	static const int32_t GSS_C_CONF_FLAG = 16;
	static const int32_t GSS_C_INTEG_FLAG = 32;
	static const int32_t GSS_C_ANON_FLAG = 64;
	static const int32_t GSS_C_PROT_READY_FLAG = 128;
	static const int32_t GSS_C_TRANS_FLAG = 256;
	static const int32_t NUM_OF_INQUIRE_VALUES = 6;
	int64_t pContext = 0;
	::sun::security::jgss::wrapper::GSSNameElement* srcName = nullptr;
	::sun::security::jgss::wrapper::GSSNameElement* targetName = nullptr;
	bool isInitiator$ = false;
	bool isEstablished$ = false;
	::sun::security::jgss::wrapper::GSSCredElement* delegatedCred = nullptr;
	int32_t flags = 0;
	int32_t lifetime = 0;
	::org::ietf::jgss::Oid* actualMech = nullptr;
	::sun::security::jgss::wrapper::GSSCredElement* cred = nullptr;
	::sun::security::jgss::wrapper::GSSCredElement* disposeCred = nullptr;
	::org::ietf::jgss::ChannelBinding* cb = nullptr;
	::sun::security::jgss::wrapper::GSSCredElement* disposeDelegatedCred = nullptr;
	::sun::security::jgss::wrapper::GSSLibStub* cStub = nullptr;
	bool skipDelegPermCheck = false;
	bool skipServicePermCheck = false;
};

			} // wrapper
		} // jgss
	} // security
} // sun

#pragma pop_macro("GSS_C_ANON_FLAG")
#pragma pop_macro("GSS_C_CONF_FLAG")
#pragma pop_macro("GSS_C_DELEG_FLAG")
#pragma pop_macro("GSS_C_INTEG_FLAG")
#pragma pop_macro("GSS_C_MUTUAL_FLAG")
#pragma pop_macro("GSS_C_PROT_READY_FLAG")
#pragma pop_macro("GSS_C_REPLAY_FLAG")
#pragma pop_macro("GSS_C_SEQUENCE_FLAG")
#pragma pop_macro("GSS_C_TRANS_FLAG")
#pragma pop_macro("NUM_OF_INQUIRE_VALUES")

#endif // _sun_security_jgss_wrapper_NativeGSSContext_h_