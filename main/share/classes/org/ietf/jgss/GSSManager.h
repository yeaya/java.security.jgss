#ifndef _org_ietf_jgss_GSSManager_h_
#define _org_ietf_jgss_GSSManager_h_
//$ class org.ietf.jgss.GSSManager
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace security {
		class Provider;
	}
}
namespace org {
	namespace ietf {
		namespace jgss {
			class GSSContext;
			class GSSCredential;
			class GSSName;
			class Oid;
		}
	}
}

namespace org {
	namespace ietf {
		namespace jgss {

class $export GSSManager : public ::java::lang::Object {
	$class(GSSManager, $NO_CLASS_INIT, ::java::lang::Object)
public:
	GSSManager();
	void init$();
	virtual void addProviderAtEnd(::java::security::Provider* p, ::org::ietf::jgss::Oid* mech) {}
	virtual void addProviderAtFront(::java::security::Provider* p, ::org::ietf::jgss::Oid* mech) {}
	virtual ::org::ietf::jgss::GSSContext* createContext(::org::ietf::jgss::GSSName* peer, ::org::ietf::jgss::Oid* mech, ::org::ietf::jgss::GSSCredential* myCred, int32_t lifetime) {return nullptr;}
	virtual ::org::ietf::jgss::GSSContext* createContext(::org::ietf::jgss::GSSCredential* myCred) {return nullptr;}
	virtual ::org::ietf::jgss::GSSContext* createContext($bytes* interProcessToken) {return nullptr;}
	virtual ::org::ietf::jgss::GSSCredential* createCredential(int32_t usage) {return nullptr;}
	virtual ::org::ietf::jgss::GSSCredential* createCredential(::org::ietf::jgss::GSSName* name, int32_t lifetime, ::org::ietf::jgss::Oid* mech, int32_t usage) {return nullptr;}
	virtual ::org::ietf::jgss::GSSCredential* createCredential(::org::ietf::jgss::GSSName* name, int32_t lifetime, $Array<::org::ietf::jgss::Oid>* mechs, int32_t usage) {return nullptr;}
	virtual ::org::ietf::jgss::GSSName* createName($String* nameStr, ::org::ietf::jgss::Oid* nameType) {return nullptr;}
	virtual ::org::ietf::jgss::GSSName* createName($bytes* name, ::org::ietf::jgss::Oid* nameType) {return nullptr;}
	virtual ::org::ietf::jgss::GSSName* createName($String* nameStr, ::org::ietf::jgss::Oid* nameType, ::org::ietf::jgss::Oid* mech) {return nullptr;}
	virtual ::org::ietf::jgss::GSSName* createName($bytes* name, ::org::ietf::jgss::Oid* nameType, ::org::ietf::jgss::Oid* mech) {return nullptr;}
	static ::org::ietf::jgss::GSSManager* getInstance();
	virtual $Array<::org::ietf::jgss::Oid>* getMechs() {return nullptr;}
	virtual $Array<::org::ietf::jgss::Oid>* getMechsForName(::org::ietf::jgss::Oid* nameType) {return nullptr;}
	virtual $Array<::org::ietf::jgss::Oid>* getNamesForMech(::org::ietf::jgss::Oid* mech) {return nullptr;}
};

		} // jgss
	} // ietf
} // org

#endif // _org_ietf_jgss_GSSManager_h_