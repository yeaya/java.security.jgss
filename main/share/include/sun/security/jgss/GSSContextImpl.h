#ifndef _sun_security_jgss_GSSContextImpl_h_
#define _sun_security_jgss_GSSContextImpl_h_
//$ class sun.security.jgss.GSSContextImpl
//$ extends org.ietf.jgss.GSSContext

#include <java/lang/Array.h>
#include <org/ietf/jgss/GSSContext.h>

#pragma push_macro("DELETED")
#undef DELETED
#pragma push_macro("IN_PROGRESS")
#undef IN_PROGRESS
#pragma push_macro("PRE_INIT")
#undef PRE_INIT
#pragma push_macro("READY")
#undef READY

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class ChannelBinding;
			class GSSCredential;
			class GSSName;
			class MessageProp;
			class Oid;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			class GSSCredentialImpl;
			class GSSManagerImpl;
			class GSSNameImpl;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace spi {
				class GSSContextSpi;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class ObjectIdentifier;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {

class $import GSSContextImpl : public ::org::ietf::jgss::GSSContext {
	$class(GSSContextImpl, $NO_CLASS_INIT, ::org::ietf::jgss::GSSContext)
public:
	GSSContextImpl();
	void init$();
	void init$(::sun::security::jgss::GSSContextImpl* src);
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, ::org::ietf::jgss::GSSName* peer, ::org::ietf::jgss::Oid* mech, ::org::ietf::jgss::GSSCredential* myCred, int32_t lifetime);
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, ::org::ietf::jgss::GSSCredential* myCred);
	void init$(::sun::security::jgss::GSSManagerImpl* gssManager, $bytes* interProcessToken);
	virtual $bytes* acceptSecContext($bytes* inTok, int32_t offset, int32_t len) override;
	virtual void acceptSecContext(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream) override;
	virtual void dispose() override;
	virtual $bytes* export$() override;
	virtual bool getAnonymityState() override;
	virtual bool getConfState() override;
	virtual bool getCredDelegState() override;
	virtual ::org::ietf::jgss::GSSCredential* getDelegCred() override;
	virtual bool getDelegPolicyState();
	virtual bool getIntegState() override;
	virtual int32_t getLifetime() override;
	virtual $bytes* getMIC($bytes* inMsg, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void getMIC(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual ::org::ietf::jgss::Oid* getMech() override;
	virtual bool getMutualAuthState() override;
	virtual bool getReplayDetState() override;
	virtual bool getSequenceDetState() override;
	virtual ::org::ietf::jgss::GSSName* getSrcName() override;
	virtual ::org::ietf::jgss::GSSName* getTargName() override;
	virtual int32_t getWrapSizeLimit(int32_t qop, bool confReq, int32_t maxTokenSize) override;
	virtual $bytes* initSecContext($bytes* inputBuf, int32_t offset, int32_t len) override;
	virtual int32_t initSecContext(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream) override;
	virtual $Object* inquireSecContext($String* type);
	virtual bool isEstablished() override;
	virtual bool isInitiator() override;
	virtual bool isProtReady() override;
	virtual bool isTransferable() override;
	virtual void requestAnonymity(bool state) override;
	virtual void requestConf(bool state) override;
	virtual void requestCredDeleg(bool state) override;
	virtual void requestDelegPolicy(bool state);
	virtual void requestInteg(bool state) override;
	virtual void requestLifetime(int32_t lifetime) override;
	virtual void requestMutualAuth(bool state) override;
	virtual void requestReplayDet(bool state) override;
	virtual void requestSequenceDet(bool state) override;
	virtual void setChannelBinding(::org::ietf::jgss::ChannelBinding* channelBindings) override;
	virtual $bytes* unwrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void unwrap(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void verifyMIC($bytes* inTok, int32_t tokOffset, int32_t tokLen, $bytes* inMsg, int32_t msgOffset, int32_t msgLen, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void verifyMIC(::java::io::InputStream* tokStream, ::java::io::InputStream* msgStream, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual $bytes* wrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void wrap(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream, ::org::ietf::jgss::MessageProp* msgProp) override;
	::sun::security::jgss::GSSManagerImpl* gssManager = nullptr;
	bool initiator = false;
	static const int32_t PRE_INIT = 1;
	static const int32_t IN_PROGRESS = 2;
	static const int32_t READY = 3;
	static const int32_t DELETED = 4;
	int32_t currentState = 0;
	::sun::security::jgss::spi::GSSContextSpi* mechCtxt = nullptr;
	::org::ietf::jgss::Oid* mechOid = nullptr;
	::sun::security::util::ObjectIdentifier* objId = nullptr;
	::sun::security::jgss::GSSCredentialImpl* myCred = nullptr;
	::sun::security::jgss::GSSNameImpl* srcName = nullptr;
	::sun::security::jgss::GSSNameImpl* targName = nullptr;
	int32_t reqLifetime = 0;
	::org::ietf::jgss::ChannelBinding* channelBindings = nullptr;
	bool reqConfState = false;
	bool reqIntegState = false;
	bool reqMutualAuthState = false;
	bool reqReplayDetState = false;
	bool reqSequenceDetState = false;
	bool reqCredDelegState = false;
	bool reqAnonState = false;
	bool reqDelegPolicyState = false;
};

		} // jgss
	} // security
} // sun

#pragma pop_macro("DELETED")
#pragma pop_macro("IN_PROGRESS")
#pragma pop_macro("PRE_INIT")
#pragma pop_macro("READY")

#endif // _sun_security_jgss_GSSContextImpl_h_