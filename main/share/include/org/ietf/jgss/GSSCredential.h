#ifndef _org_ietf_jgss_GSSCredential_h_
#define _org_ietf_jgss_GSSCredential_h_
//$ interface org.ietf.jgss.GSSCredential
//$ extends java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>
#include <java/lang/Integer.h>

#pragma push_macro("ACCEPT_ONLY")
#undef ACCEPT_ONLY
#pragma push_macro("DEFAULT_LIFETIME")
#undef DEFAULT_LIFETIME
#pragma push_macro("INDEFINITE_LIFETIME")
#undef INDEFINITE_LIFETIME
#pragma push_macro("INITIATE_AND_ACCEPT")
#undef INITIATE_AND_ACCEPT
#pragma push_macro("INITIATE_ONLY")
#undef INITIATE_ONLY
#pragma push_macro("MAX_VALUE")
#undef MAX_VALUE

namespace org {
	namespace ietf {
		namespace jgss {
			class GSSName;
			class Oid;
		}
	}
}

namespace org {
	namespace ietf {
		namespace jgss {

class $import GSSCredential : public ::java::lang::Cloneable {
	$interface(GSSCredential, $NO_CLASS_INIT, ::java::lang::Cloneable)
public:
	virtual void add(::org::ietf::jgss::GSSName* name, int32_t initLifetime, int32_t acceptLifetime, ::org::ietf::jgss::Oid* mech, int32_t usage) {}
	virtual void dispose() {}
	virtual bool equals(Object$* another) override;
	virtual $Array<::org::ietf::jgss::Oid>* getMechs() {return nullptr;}
	virtual ::org::ietf::jgss::GSSName* getName() {return nullptr;}
	virtual ::org::ietf::jgss::GSSName* getName(::org::ietf::jgss::Oid* mech) {return nullptr;}
	virtual int32_t getRemainingAcceptLifetime(::org::ietf::jgss::Oid* mech) {return 0;}
	virtual int32_t getRemainingInitLifetime(::org::ietf::jgss::Oid* mech) {return 0;}
	virtual int32_t getRemainingLifetime() {return 0;}
	virtual int32_t getUsage() {return 0;}
	virtual int32_t getUsage(::org::ietf::jgss::Oid* mech) {return 0;}
	virtual int32_t hashCode() override;
	static const int32_t INITIATE_AND_ACCEPT = 0;
	static const int32_t INITIATE_ONLY = 1;
	static const int32_t ACCEPT_ONLY = 2;
	static const int32_t DEFAULT_LIFETIME = 0;
	static const int32_t INDEFINITE_LIFETIME = ::java::lang::Integer::MAX_VALUE;
};

		} // jgss
	} // ietf
} // org

#pragma pop_macro("ACCEPT_ONLY")
#pragma pop_macro("DEFAULT_LIFETIME")
#pragma pop_macro("INDEFINITE_LIFETIME")
#pragma pop_macro("INITIATE_AND_ACCEPT")
#pragma pop_macro("INITIATE_ONLY")
#pragma pop_macro("MAX_VALUE")

#endif // _org_ietf_jgss_GSSCredential_h_