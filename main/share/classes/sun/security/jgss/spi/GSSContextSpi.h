#ifndef _sun_security_jgss_spi_GSSContextSpi_h_
#define _sun_security_jgss_spi_GSSContextSpi_h_
//$ interface sun.security.jgss.spi.GSSContextSpi
//$ extends java.lang.Object

#include <java/lang/Array.h>

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
			namespace spi {

class GSSContextSpi : public ::java::lang::Object {
	$interface(GSSContextSpi, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $bytes* acceptSecContext(::java::io::InputStream* is, int32_t mechTokenSize) {return nullptr;}
	virtual void dispose() {}
	virtual $bytes* export$() {return nullptr;}
	virtual bool getAnonymityState() {return false;}
	virtual bool getConfState() {return false;}
	virtual bool getCredDelegState() {return false;}
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getDelegCred() {return nullptr;}
	virtual bool getDelegPolicyState() {return false;}
	virtual bool getIntegState() {return false;}
	virtual int32_t getLifetime() {return 0;}
	virtual void getMIC(::java::io::InputStream* is, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp) {}
	virtual $bytes* getMIC($bytes* inMsg, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) {return nullptr;}
	virtual ::org::ietf::jgss::Oid* getMech() {return nullptr;}
	virtual bool getMutualAuthState() {return false;}
	virtual ::java::security::Provider* getProvider() {return nullptr;}
	virtual bool getReplayDetState() {return false;}
	virtual bool getSequenceDetState() {return false;}
	virtual ::sun::security::jgss::spi::GSSNameSpi* getSrcName() {return nullptr;}
	virtual ::sun::security::jgss::spi::GSSNameSpi* getTargName() {return nullptr;}
	virtual int32_t getWrapSizeLimit(int32_t qop, bool confReq, int32_t maxTokSize) {return 0;}
	virtual $bytes* initSecContext(::java::io::InputStream* is, int32_t mechTokenSize) {return nullptr;}
	virtual $Object* inquireSecContext($String* type) {return nullptr;}
	virtual bool isEstablished() {return false;}
	virtual bool isInitiator() {return false;}
	virtual bool isProtReady() {return false;}
	virtual bool isTransferable() {return false;}
	virtual void requestAnonymity(bool state) {}
	virtual void requestConf(bool state) {}
	virtual void requestCredDeleg(bool state) {}
	virtual void requestDelegPolicy(bool state) {}
	virtual void requestInteg(bool state) {}
	virtual void requestLifetime(int32_t lifetime) {}
	virtual void requestMutualAuth(bool state) {}
	virtual void requestReplayDet(bool state) {}
	virtual void requestSequenceDet(bool state) {}
	virtual void setChannelBinding(::org::ietf::jgss::ChannelBinding* cb) {}
	virtual void unwrap(::java::io::InputStream* is, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp) {}
	virtual $bytes* unwrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) {return nullptr;}
	virtual void verifyMIC(::java::io::InputStream* is, ::java::io::InputStream* msgStr, ::org::ietf::jgss::MessageProp* mProp) {}
	virtual void verifyMIC($bytes* inTok, int32_t tokOffset, int32_t tokLen, $bytes* inMsg, int32_t msgOffset, int32_t msgLen, ::org::ietf::jgss::MessageProp* msgProp) {}
	virtual void wrap(::java::io::InputStream* is, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp) {}
	virtual $bytes* wrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) {return nullptr;}
};

			} // spi
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_spi_GSSContextSpi_h_