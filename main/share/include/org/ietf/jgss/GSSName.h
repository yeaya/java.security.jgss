#ifndef _org_ietf_jgss_GSSName_h_
#define _org_ietf_jgss_GSSName_h_
//$ interface org.ietf.jgss.GSSName
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("NT_ANONYMOUS")
#undef NT_ANONYMOUS
#pragma push_macro("NT_EXPORT_NAME")
#undef NT_EXPORT_NAME
#pragma push_macro("NT_HOSTBASED_SERVICE")
#undef NT_HOSTBASED_SERVICE
#pragma push_macro("NT_MACHINE_UID_NAME")
#undef NT_MACHINE_UID_NAME
#pragma push_macro("NT_STRING_UID_NAME")
#undef NT_STRING_UID_NAME
#pragma push_macro("NT_USER_NAME")
#undef NT_USER_NAME

namespace org {
	namespace ietf {
		namespace jgss {
			class Oid;
		}
	}
}

namespace org {
	namespace ietf {
		namespace jgss {

class $import GSSName : public ::java::lang::Object {
	$interface(GSSName, 0, ::java::lang::Object)
public:
	virtual bool equals(Object$* another) override;
	virtual int32_t hashCode() override;
	virtual ::org::ietf::jgss::GSSName* canonicalize(::org::ietf::jgss::Oid* mech) {return nullptr;}
	virtual bool equals(::org::ietf::jgss::GSSName* another) {return false;}
	virtual $bytes* export$() {return nullptr;}
	virtual ::org::ietf::jgss::Oid* getStringNameType() {return nullptr;}
	virtual bool isAnonymous() {return false;}
	virtual bool isMN() {return false;}
	virtual $String* toString() override;
	static ::org::ietf::jgss::Oid* NT_HOSTBASED_SERVICE;
	static ::org::ietf::jgss::Oid* NT_USER_NAME;
	static ::org::ietf::jgss::Oid* NT_MACHINE_UID_NAME;
	static ::org::ietf::jgss::Oid* NT_STRING_UID_NAME;
	static ::org::ietf::jgss::Oid* NT_ANONYMOUS;
	static ::org::ietf::jgss::Oid* NT_EXPORT_NAME;
};

		} // jgss
	} // ietf
} // org

#pragma pop_macro("NT_ANONYMOUS")
#pragma pop_macro("NT_EXPORT_NAME")
#pragma pop_macro("NT_HOSTBASED_SERVICE")
#pragma pop_macro("NT_MACHINE_UID_NAME")
#pragma pop_macro("NT_STRING_UID_NAME")
#pragma pop_macro("NT_USER_NAME")

#endif // _org_ietf_jgss_GSSName_h_