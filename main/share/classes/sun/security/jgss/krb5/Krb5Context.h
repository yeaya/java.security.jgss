#ifndef _sun_security_jgss_krb5_Krb5Context_h_
#define _sun_security_jgss_krb5_Krb5Context_h_
//$ class sun.security.jgss.krb5.Krb5Context
//$ extends sun.security.jgss.spi.GSSContextSpi

#include <java/lang/Array.h>
#include <sun/security/jgss/spi/GSSContextSpi.h>

#pragma push_macro("ACCEPTOR_SUBKEY")
#undef ACCEPTOR_SUBKEY
#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("INITIATOR_SUBKEY")
#undef INITIATOR_SUBKEY
#pragma push_macro("SESSION_KEY")
#undef SESSION_KEY
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
			class MessageProp;
			class Oid;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			class GSSCaller;
			class TokenTracker;
		}
	}
}
namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {
				class CipherHelper;
				class Krb5CredElement;
				class Krb5NameElement;
				class MessageToken;
				class MessageToken_v2;
			}
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
		namespace krb5 {
			class Credentials;
			class EncryptionKey;
			class KrbApReq;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class AuthorizationData;
				class Ticket;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

class Krb5Context : public ::sun::security::jgss::spi::GSSContextSpi {
	$class(Krb5Context, 0, ::sun::security::jgss::spi::GSSContextSpi)
public:
	Krb5Context();
	void init$(::sun::security::jgss::GSSCaller* caller, ::sun::security::jgss::krb5::Krb5NameElement* peerName, ::sun::security::jgss::krb5::Krb5CredElement* myCred, int32_t lifetime);
	void init$(::sun::security::jgss::GSSCaller* caller, ::sun::security::jgss::krb5::Krb5CredElement* myCred);
	void init$(::sun::security::jgss::GSSCaller* caller, $bytes* interProcessToken);
	virtual $bytes* acceptSecContext(::java::io::InputStream* is, int32_t mechTokenSize) override;
	void checkPermission($String* principal, $String* action);
	virtual void dispose() override;
	virtual $bytes* export$() override;
	virtual bool getAnonymityState() override;
	virtual ::sun::security::jgss::GSSCaller* getCaller();
	::org::ietf::jgss::ChannelBinding* getChannelBinding();
	::sun::security::jgss::krb5::CipherHelper* getCipherHelper(::sun::security::krb5::EncryptionKey* ckey);
	virtual bool getConfState() override;
	virtual bool getCredDelegState() override;
	virtual ::sun::security::jgss::spi::GSSCredentialSpi* getDelegCred() override;
	virtual bool getDelegPolicyState() override;
	static $String* getHexBytes($bytes* bytes, int32_t pos, int32_t len);
	virtual bool getIntegState() override;
	::sun::security::krb5::EncryptionKey* getKey();
	int32_t getKeySrc();
	virtual int32_t getLifetime() override;
	virtual $bytes* getMIC($bytes* inMsg, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	int32_t getMIC($bytes* inMsg, int32_t offset, int32_t len, $bytes* outBuf, int32_t outOffset, ::org::ietf::jgss::MessageProp* msgProp);
	void getMIC($bytes* inMsg, int32_t offset, int32_t len, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp);
	virtual void getMIC(::java::io::InputStream* is, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual ::org::ietf::jgss::Oid* getMech() override;
	virtual bool getMutualAuthState() override;
	virtual ::java::security::Provider* getProvider() override;
	virtual bool getReplayDetState() override;
	virtual bool getSequenceDetState() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getSrcName() override;
	virtual ::sun::security::jgss::spi::GSSNameSpi* getTargName() override;
	virtual int32_t getWrapSizeLimit(int32_t qop, bool confReq, int32_t maxTokSize) override;
	int32_t incrementMySequenceNumber();
	virtual $bytes* initSecContext(::java::io::InputStream* is, int32_t mechTokenSize) override;
	virtual $Object* inquireSecContext($String* type) override;
	virtual bool isEstablished() override;
	virtual bool isInitiator() override;
	virtual bool isProtReady() override;
	virtual bool isTransferable() override;
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
	void resetMySequenceNumber(int32_t seqNumber);
	void resetPeerSequenceNumber(int32_t seqNumber);
	virtual void setAuthTime($String* authTime);
	virtual void setAuthzData(::sun::security::krb5::internal::AuthorizationData* authzData);
	virtual void setChannelBinding(::org::ietf::jgss::ChannelBinding* channelBinding) override;
	void setConfState(bool state);
	void setCredDelegState(bool state);
	void setDelegCred(::sun::security::jgss::krb5::Krb5CredElement* delegatedCred);
	void setDelegPolicyState(bool state);
	void setIntegState(bool state);
	void setKey(int32_t keySrc, ::sun::security::krb5::EncryptionKey* key);
	void setMutualAuthState(bool state);
	void setReplayDetState(bool state);
	void setSequenceDetState(bool state);
	void setSequencingAndReplayProps(::sun::security::jgss::krb5::MessageToken* token, ::org::ietf::jgss::MessageProp* prop);
	void setSequencingAndReplayProps(::sun::security::jgss::krb5::MessageToken_v2* token, ::org::ietf::jgss::MessageProp* prop);
	virtual void setTktFlags($booleans* tktFlags);
	void tryConstrainedDelegation();
	virtual $bytes* unwrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	int32_t unwrap($bytes* inBuf, int32_t inOffset, int32_t len, $bytes* outBuf, int32_t outOffset, ::org::ietf::jgss::MessageProp* msgProp);
	int32_t unwrap(::java::io::InputStream* is, $bytes* outBuf, int32_t outOffset, ::org::ietf::jgss::MessageProp* msgProp);
	virtual void unwrap(::java::io::InputStream* is, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp) override;
	virtual void verifyMIC($bytes* inTok, int32_t tokOffset, int32_t tokLen, $bytes* inMsg, int32_t msgOffset, int32_t msgLen, ::org::ietf::jgss::MessageProp* msgProp) override;
	void verifyMIC(::java::io::InputStream* is, $bytes* inMsg, int32_t msgOffset, int32_t msgLen, ::org::ietf::jgss::MessageProp* msgProp);
	virtual void verifyMIC(::java::io::InputStream* is, ::java::io::InputStream* msgStr, ::org::ietf::jgss::MessageProp* mProp) override;
	virtual $bytes* wrap($bytes* inBuf, int32_t offset, int32_t len, ::org::ietf::jgss::MessageProp* msgProp) override;
	int32_t wrap($bytes* inBuf, int32_t inOffset, int32_t len, $bytes* outBuf, int32_t outOffset, ::org::ietf::jgss::MessageProp* msgProp);
	void wrap($bytes* inBuf, int32_t offset, int32_t len, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp);
	virtual void wrap(::java::io::InputStream* is, ::java::io::OutputStream* os, ::org::ietf::jgss::MessageProp* msgProp) override;
	static const int32_t STATE_NEW = 1;
	static const int32_t STATE_IN_PROCESS = 2;
	static const int32_t STATE_DONE = 3;
	static const int32_t STATE_DELETED = 4;
	int32_t state = 0;
	static const int32_t SESSION_KEY = 0;
	static const int32_t INITIATOR_SUBKEY = 1;
	static const int32_t ACCEPTOR_SUBKEY = 2;
	bool credDelegState = false;
	bool mutualAuthState = false;
	bool replayDetState = false;
	bool sequenceDetState = false;
	bool confState = false;
	bool integState = false;
	bool delegPolicyState = false;
	bool isConstrainedDelegationTried = false;
	int32_t mySeqNumber = 0;
	int32_t peerSeqNumber = 0;
	int32_t keySrc = 0;
	::sun::security::jgss::TokenTracker* peerTokenTracker = nullptr;
	::sun::security::jgss::krb5::CipherHelper* cipherHelper = nullptr;
	$Object* mySeqNumberLock = nullptr;
	$Object* peerSeqNumberLock = nullptr;
	::sun::security::krb5::EncryptionKey* key = nullptr;
	::sun::security::jgss::krb5::Krb5NameElement* myName = nullptr;
	::sun::security::jgss::krb5::Krb5NameElement* peerName = nullptr;
	int32_t lifetime = 0;
	bool initiator = false;
	::org::ietf::jgss::ChannelBinding* channelBinding = nullptr;
	::sun::security::jgss::krb5::Krb5CredElement* myCred = nullptr;
	::sun::security::jgss::krb5::Krb5CredElement* delegatedCred = nullptr;
	::sun::security::krb5::Credentials* tgt = nullptr;
	::sun::security::krb5::Credentials* serviceCreds = nullptr;
	::sun::security::krb5::KrbApReq* apReq = nullptr;
	::sun::security::krb5::internal::Ticket* serviceTicket = nullptr;
	::sun::security::jgss::GSSCaller* caller = nullptr;
	static bool DEBUG;
	$booleans* tktFlags = nullptr;
	$String* authTime = nullptr;
	::sun::security::krb5::internal::AuthorizationData* authzData = nullptr;
};

			} // krb5
		} // jgss
	} // security
} // sun

#pragma pop_macro("ACCEPTOR_SUBKEY")
#pragma pop_macro("DEBUG")
#pragma pop_macro("INITIATOR_SUBKEY")
#pragma pop_macro("SESSION_KEY")
#pragma pop_macro("STATE_DELETED")
#pragma pop_macro("STATE_DONE")
#pragma pop_macro("STATE_IN_PROCESS")
#pragma pop_macro("STATE_NEW")

#endif // _sun_security_jgss_krb5_Krb5Context_h_