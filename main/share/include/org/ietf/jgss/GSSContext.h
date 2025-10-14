#ifndef _org_ietf_jgss_GSSContext_h_
#define _org_ietf_jgss_GSSContext_h_
//$ interface org.ietf.jgss.GSSContext
//$ extends java.lang.Object

#include <java/lang/Array.h>
#include <java/lang/Integer.h>

#pragma push_macro("DEFAULT_LIFETIME")
#undef DEFAULT_LIFETIME
#pragma push_macro("INDEFINITE_LIFETIME")
#undef INDEFINITE_LIFETIME
#pragma push_macro("MAX_VALUE")
#undef MAX_VALUE

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

namespace org {
	namespace ietf {
		namespace jgss {

class $import GSSContext : public ::java::lang::Object {
	$interface(GSSContext, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $bytes* acceptSecContext($bytes* inToken, int32_t offset, int32_t len) {return nullptr;}
	virtual void acceptSecContext(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream) {}
	virtual void dispose() {}
	virtual $bytes* export$() {return nullptr;}
	virtual bool getAnonymityState() {return false;}
	virtual bool getConfState() {return false;}
	virtual bool getCredDelegState() {return false;}
	virtual ::org::ietf::jgss::GSSCredential* getDelegCred() {return nullptr;}
	virtual bool getIntegState() {return false;}
	virtual int32_t getLifetime() {return 0;}
	virtual $bytes* getMIC($bytes* inMsg, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) {return nullptr;}
	virtual void getMIC(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream, ::org::ietf::jgss::MessageProp* msgProp) {}
	virtual ::org::ietf::jgss::Oid* getMech() {return nullptr;}
	virtual bool getMutualAuthState() {return false;}
	virtual bool getReplayDetState() {return false;}
	virtual bool getSequenceDetState() {return false;}
	virtual ::org::ietf::jgss::GSSName* getSrcName() {return nullptr;}
	virtual ::org::ietf::jgss::GSSName* getTargName() {return nullptr;}
	virtual int32_t getWrapSizeLimit(int32_t qop, bool confReq, int32_t maxTokenSize) {return 0;}
	virtual $bytes* initSecContext($bytes* inputBuf, int32_t offset, int32_t len) {return nullptr;}
	virtual int32_t initSecContext(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream) {return 0;}
	virtual bool isEstablished() {return false;}
	virtual bool isInitiator() {return false;}
	virtual bool isProtReady() {return false;}
	virtual bool isTransferable() {return false;}
	virtual void requestAnonymity(bool state) {}
	virtual void requestConf(bool state) {}
	virtual void requestCredDeleg(bool state) {}
	virtual void requestInteg(bool state) {}
	virtual void requestLifetime(int32_t lifetime) {}
	virtual void requestMutualAuth(bool state) {}
	virtual void requestReplayDet(bool state) {}
	virtual void requestSequenceDet(bool state) {}
	virtual void setChannelBinding(::org::ietf::jgss::ChannelBinding* cb) {}
	virtual $bytes* unwrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) {return nullptr;}
	virtual void unwrap(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream, ::org::ietf::jgss::MessageProp* msgProp) {}
	virtual void verifyMIC($bytes* inToken, int32_t tokOffset, int32_t tokLen, $bytes* inMsg, int32_t msgOffset, int32_t msgLen, ::org::ietf::jgss::MessageProp* msgProp) {}
	virtual void verifyMIC(::java::io::InputStream* tokStream, ::java::io::InputStream* msgStream, ::org::ietf::jgss::MessageProp* msgProp) {}
	virtual $bytes* wrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) {return nullptr;}
	virtual void wrap(::java::io::InputStream* inStream, ::java::io::OutputStream* outStream, ::org::ietf::jgss::MessageProp* msgProp) {}
	static const int32_t DEFAULT_LIFETIME = 0;
	static const int32_t INDEFINITE_LIFETIME = ::java::lang::Integer::MAX_VALUE;
};

		} // jgss
	} // ietf
} // org

#pragma pop_macro("DEFAULT_LIFETIME")
#pragma pop_macro("INDEFINITE_LIFETIME")
#pragma pop_macro("MAX_VALUE")

#endif // _org_ietf_jgss_GSSContext_h_