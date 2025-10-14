#ifndef _sun_security_jgss_spnego_SpNegoContext_h_
#define _sun_security_jgss_spnego_SpNegoContext_h_
//$ class sun.security.jgss.spnego.SpNegoContext
//$ extends sun.security.jgss.spi.GSSContextSpi

#include <java/lang/Array.h>
#include <sun/security/jgss/spi/GSSContextSpi.h>

#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("STATE_DELETED")
#undef STATE_DELETED
#pragma push_macro("STATE_DONE")
#undef STATE_DONE
#pragma push_macro("STATE_IN_PROCESS")
#undef STATE_IN_PROCESS
#pragma push_macro("STATE_NEW")
#undef STATE_NEW

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
			class GSSContext;
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
			namespace spnego {
				class SpNegoCredElement;
				class SpNegoMechFactory;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class BitArray;
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace spnego {

class SpNegoContext : public ::sun::security::jgss::spi::GSSContextSpi {
	$class(SpNegoContext, 0, ::sun::security::jgss::spi::GSSContextSpi)
public:
	SpNegoContext();
	void init$(::sun::security::jgss::spnego::SpNegoMechFactory* factory, ::sun::security::jgss::spi::GSSNameSpi* peerName, ::sun::security::jgss::spi::GSSCredentialSpi* myCred, int32_t lifetime);
	void init$(::sun::security::jgss::spnego::SpNegoMechFactory* factory, ::sun::security::jgss::spi::GSSCredentialSpi* myCred);
	void init$(::sun::security::jgss::spnego::SpNegoMechFactory* factory, $bytes* interProcessToken);
	$bytes* GSS_acceptSecContext($bytes* token);
	$bytes* GSS_initSecContext($bytes* token);
	virtual $bytes* acceptSecContext(::java::io::InputStream* is, int32_t mechTokenSize) override;
	virtual void dispose() override;
	virtual $bytes* export$() override;
	virtual bool getAnonymityState() override;
	$Array<::org::ietf::jgss::Oid>* getAvailableMechs();
	::org::ietf::jgss::ChannelBinding* getChannelBinding();
	virtual bool getConfState() override;
	::sun::security::util::BitArray* getContextFlags();
	virtual bool getCredDelegState() override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getDelegCred() override;
	virtual bool getDelegPolicyState() override;
	$bytes* getEncodedMechs($Array<::org::ietf::jgss::Oid>* mechSet);
	virtual bool getIntegState() override;
	virtual int32_t getLifetime() override;
	virtual $bytes* getMIC($bytes* inMsg, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void getMIC(::java::io::InputStream* is, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual ::org::ietf::jgss::Oid* getMech() override;
	virtual bool getMutualAuthState() override;
	::org::ietf::jgss::Oid* getNegotiatedMech();
	virtual ::java::security::Provider* getProvider() override;
	virtual bool getReplayDetState() override;
	virtual bool getSequenceDetState() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getSrcName() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getTargName() override;
	virtual int32_t getWrapSizeLimit(int32_t qop, bool confReq, int32_t maxTokSize) override;
	virtual $bytes* initSecContext(::java::io::InputStream* is, int32_t mechTokenSize) override;
	virtual $Object* inquireSecContext($String* type) override;
	virtual bool isEstablished() override;
	virtual bool isInitiator() override;
	bool isMechContextEstablished();
	virtual bool isProtReady() override;
	virtual bool isTransferable() override;
	static ::org::ietf::jgss::Oid* negotiate_mech_type($Array<::org::ietf::jgss::Oid>* supported_mechSet, $Array<::org::ietf::jgss::Oid>* mechSet);
	static $String* printState(int32_t state);
	virtual void requestAnonymity(bool value) override;
	virtual void requestConf(bool value) override;
	virtual void requestCredDeleg(bool value) override;
	virtual void requestDelegPolicy(bool value) override;
	virtual void requestInteg(bool value) override;
	virtual void requestLifetime(int32_t lifetime) override;
	virtual void requestMutualAuth(bool value) override;
	virtual void requestReplayDet(bool value) override;
	virtual void requestSequenceDet(bool value) override;
	virtual void setChannelBinding(::org::ietf::jgss::ChannelBinding* channelBinding) override;
	void setContextFlags();
	virtual $bytes* unwrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void unwrap(::java::io::InputStream* is, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void verifyMIC($bytes* inTok, int32_t tokOffset, int32_t tokLen, $bytes* inMsg, int32_t msgOffset, int32_t msgLen, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void verifyMIC(::java::io::InputStream* is, ::java::io::InputStream* msgStr, ::org::ietf::jgss::MessageProp* msgProp) override;
	bool verifyMechListMIC($bytes* mechTypes, $bytes* token);
	virtual $bytes* wrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void wrap(::java::io::InputStream* is, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp) override;
	static const int32_t STATE_NEW = 1;
	static const int32_t STATE_IN_PROCESS = 2;
	static const int32_t STATE_DONE = 3;
	static const int32_t STATE_DELETED = 4;
	int32_t state = 0;
	bool credDelegState = false;
	bool mutualAuthState = false;
	bool replayDetState = false;
	bool sequenceDetState = false;
	bool confState = false;
	bool integState = false;
	bool delegPolicyState = false;
	::sun::security::jgss::spi::GSSNameSpi* peerName = nullptr;
	::sun::security::jgss::spi::GSSNameSpi* myName = nullptr;
	::sun::security::jgss::spnego::SpNegoCredElement* myCred = nullptr;
	::org::ietf::jgss::GSSContext* mechContext = nullptr;
	$bytes* DER_mechTypes = nullptr;
	int32_t lifetime = 0;
	::org::ietf::jgss::ChannelBinding* channelBinding = nullptr;
	bool initiator = false;
	::org::ietf::jgss::Oid* internal_mech = nullptr;
	::sun::security::jgss::spnego::SpNegoMechFactory* factory = nullptr;
	static bool DEBUG;
};

			} // spnego
		} // jgss
	} // security
} // sun

#pragma pop_macro("DEBUG")
#pragma pop_macro("STATE_DELETED")
#pragma pop_macro("STATE_DONE")
#pragma pop_macro("STATE_IN_PROCESS")
#pragma pop_macro("STATE_NEW")

#endif // _sun_security_jgss_spnego_SpNegoContext_h_