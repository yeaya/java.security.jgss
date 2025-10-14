#ifndef _sun_security_jgss_wrapper_GSSLibStub_h_
#define _sun_security_jgss_wrapper_GSSLibStub_h_
//$ class sun.security.jgss.wrapper.GSSLibStub
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace util {
		class Hashtable;
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
			namespace wrapper {
				class NativeGSSContext;
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

class GSSLibStub : public ::java::lang::Object {
	$class(GSSLibStub, 0, ::java::lang::Object)
public:
	GSSLibStub();
	void init$(::org::ietf::jgss::Oid* mech);
	virtual $bytes* acceptContext(int64_t pCred, ::org::ietf::jgss::ChannelBinding* cb, $bytes* inToken, ::sun::security::jgss::wrapper::NativeGSSContext* context);
	virtual int64_t acquireCred(int64_t pName, int32_t lifetime, int32_t usage);
	virtual int64_t canonicalizeName(int64_t pName);
	virtual bool compareName(int64_t pName1, int64_t pName2);
	virtual int64_t deleteContext(int64_t pContext);
	virtual $ObjectArray* displayName(int64_t pName);
	virtual bool equals(Object$* obj) override;
	virtual $bytes* exportContext(int64_t pContext);
	virtual $bytes* exportName(int64_t pName);
	virtual ::org::ietf::jgss::Oid* getContextMech(int64_t pContext);
	virtual int64_t getContextName(int64_t pContext, bool isSrc);
	virtual int32_t getContextTime(int64_t pContext);
	virtual int64_t getCredName(int64_t pCred);
	virtual int32_t getCredTime(int64_t pCred);
	virtual int32_t getCredUsage(int64_t pCred);
	static ::sun::security::jgss::wrapper::GSSLibStub* getInstance(::org::ietf::jgss::Oid* mech);
	virtual ::org::ietf::jgss::Oid* getMech();
	static int64_t getMechPtr($bytes* oidDerEncoding);
	virtual $bytes* getMic(int64_t pContext, int32_t qop, $bytes* msg);
	virtual int32_t hashCode() override;
	virtual ::sun::security::jgss::wrapper::NativeGSSContext* importContext($bytes* interProcToken);
	virtual int64_t importName($bytes* name, ::org::ietf::jgss::Oid* type);
	static $Array<::org::ietf::jgss::Oid>* indicateMechs();
	static bool init($String* lib, bool debug);
	virtual $bytes* initContext(int64_t pCred, int64_t targetName, ::org::ietf::jgss::ChannelBinding* cb, $bytes* inToken, ::sun::security::jgss::wrapper::NativeGSSContext* context);
	virtual $longs* inquireContext(int64_t pContext);
	virtual $Array<::org::ietf::jgss::Oid>* inquireNamesForMech();
	virtual int64_t releaseCred(int64_t pCred);
	virtual void releaseName(int64_t pName);
	virtual $bytes* unwrap(int64_t pContext, $bytes* msgToken, ::org::ietf::jgss::MessageProp* prop);
	virtual void verifyMic(int64_t pContext, $bytes* token, $bytes* msg, ::org::ietf::jgss::MessageProp* prop);
	virtual $bytes* wrap(int64_t pContext, $bytes* msg, ::org::ietf::jgss::MessageProp* prop);
	virtual int32_t wrapSizeLimit(int64_t pContext, int32_t flags, int32_t qop, int32_t outSize);
	::org::ietf::jgss::Oid* mech = nullptr;
	int64_t pMech = 0;
	static ::java::util::Hashtable* table;
};

			} // wrapper
		} // jgss
	} // security
} // sun

#endif // _sun_security_jgss_wrapper_GSSLibStub_h_