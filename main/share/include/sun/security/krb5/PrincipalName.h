#ifndef _sun_security_krb5_PrincipalName_h_
#define _sun_security_krb5_PrincipalName_h_
//$ class sun.security.krb5.PrincipalName
//$ extends java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

#pragma push_macro("KRB_NT_ENTERPRISE")
#undef KRB_NT_ENTERPRISE
#pragma push_macro("KRB_NT_PRINCIPAL")
#undef KRB_NT_PRINCIPAL
#pragma push_macro("KRB_NT_SRV_HST")
#undef KRB_NT_SRV_HST
#pragma push_macro("KRB_NT_SRV_INST")
#undef KRB_NT_SRV_INST
#pragma push_macro("KRB_NT_SRV_XHST")
#undef KRB_NT_SRV_XHST
#pragma push_macro("KRB_NT_UID")
#undef KRB_NT_UID
#pragma push_macro("KRB_NT_UNKNOWN")
#undef KRB_NT_UNKNOWN
#pragma push_macro("NAME_COMPONENT_SEPARATOR")
#undef NAME_COMPONENT_SEPARATOR
#pragma push_macro("NAME_COMPONENT_SEPARATOR_STR")
#undef NAME_COMPONENT_SEPARATOR_STR
#pragma push_macro("NAME_REALM_SEPARATOR")
#undef NAME_REALM_SEPARATOR
#pragma push_macro("NAME_REALM_SEPARATOR_STR")
#undef NAME_REALM_SEPARATOR_STR
#pragma push_macro("NAME_STRINGS_OFFSET")
#undef NAME_STRINGS_OFFSET
#pragma push_macro("REALM_COMPONENT_SEPARATOR")
#undef REALM_COMPONENT_SEPARATOR
#pragma push_macro("REALM_COMPONENT_SEPARATOR_STR")
#undef REALM_COMPONENT_SEPARATOR_STR
#pragma push_macro("TGS_DEFAULT_NT")
#undef TGS_DEFAULT_NT
#pragma push_macro("TGS_DEFAULT_SRV_NAME")
#undef TGS_DEFAULT_SRV_NAME
#pragma push_macro("UNSAFE")
#undef UNSAFE

namespace jdk {
	namespace internal {
		namespace misc {
			class Unsafe;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class Realm;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ccache {
					class CCacheOutputStream;
				}
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace util {
			class DerInputStream;
			class DerValue;
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $import PrincipalName : public ::java::lang::Cloneable {
	$class(PrincipalName, 0, ::java::lang::Cloneable)
public:
	PrincipalName();
	void init$(int32_t nameType, $StringArray* nameStrings, ::sun::security::krb5::Realm* nameRealm);
	void init$($StringArray* nameParts, $String* realm);
	void init$(::sun::security::util::DerValue* encoding, ::sun::security::krb5::Realm* realm);
	void init$($String* name, int32_t type, $String* realm);
	void init$($String* name, int32_t type);
	void init$($String* name);
	void init$($String* name, $String* realm);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual bool equals(Object$* o) override;
	virtual $String* getInstanceComponent();
	virtual $String* getName();
	virtual $String* getNameString();
	virtual $StringArray* getNameStrings();
	virtual int32_t getNameType();
	virtual $String* getPrincipalNameAsString();
	virtual ::sun::security::krb5::Realm* getRealm();
	virtual $String* getRealmAsString();
	virtual $String* getRealmString();
	virtual $String* getSalt();
	virtual int32_t hashCode() override;
	virtual bool isRealmDeduced();
	static $String* mapHostToRealm($String* name);
	virtual bool match(::sun::security::krb5::PrincipalName* pname);
	static ::sun::security::krb5::PrincipalName* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional, ::sun::security::krb5::Realm* realm);
	static $StringArray* parseName($String* name);
	static ::sun::security::krb5::PrincipalName* tgsService($String* r1, $String* r2);
	virtual $Array<int8_t, 2>* toByteArray();
	virtual $String* toString() override;
	static void validateNameStrings($StringArray* ns);
	virtual void writePrincipal(::sun::security::krb5::internal::ccache::CCacheOutputStream* cos);
	static const int32_t KRB_NT_UNKNOWN = 0;
	static const int32_t KRB_NT_PRINCIPAL = 1;
	static const int32_t KRB_NT_SRV_INST = 2;
	static const int32_t KRB_NT_SRV_HST = 3;
	static const int32_t KRB_NT_SRV_XHST = 4;
	static const int32_t KRB_NT_UID = 5;
	static const int32_t KRB_NT_ENTERPRISE = 10;
	static $String* TGS_DEFAULT_SRV_NAME;
	static const int32_t TGS_DEFAULT_NT = KRB_NT_SRV_INST;
	static const char16_t NAME_COMPONENT_SEPARATOR = ((char16_t)47);
	static const char16_t NAME_REALM_SEPARATOR = ((char16_t)64);
	static const char16_t REALM_COMPONENT_SEPARATOR = ((char16_t)46);
	static $String* NAME_COMPONENT_SEPARATOR_STR;
	static $String* NAME_REALM_SEPARATOR_STR;
	static $String* REALM_COMPONENT_SEPARATOR_STR;
	int32_t nameType = 0;
	$StringArray* nameStrings = nullptr;
	::sun::security::krb5::Realm* nameRealm = nullptr;
	bool realmDeduced = false;
	$String* salt = nullptr;
	static int64_t NAME_STRINGS_OFFSET;
	static ::jdk::internal::misc::Unsafe* UNSAFE;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("KRB_NT_ENTERPRISE")
#pragma pop_macro("KRB_NT_PRINCIPAL")
#pragma pop_macro("KRB_NT_SRV_HST")
#pragma pop_macro("KRB_NT_SRV_INST")
#pragma pop_macro("KRB_NT_SRV_XHST")
#pragma pop_macro("KRB_NT_UID")
#pragma pop_macro("KRB_NT_UNKNOWN")
#pragma pop_macro("NAME_COMPONENT_SEPARATOR")
#pragma pop_macro("NAME_COMPONENT_SEPARATOR_STR")
#pragma pop_macro("NAME_REALM_SEPARATOR")
#pragma pop_macro("NAME_REALM_SEPARATOR_STR")
#pragma pop_macro("NAME_STRINGS_OFFSET")
#pragma pop_macro("REALM_COMPONENT_SEPARATOR")
#pragma pop_macro("REALM_COMPONENT_SEPARATOR_STR")
#pragma pop_macro("TGS_DEFAULT_NT")
#pragma pop_macro("TGS_DEFAULT_SRV_NAME")
#pragma pop_macro("UNSAFE")

#endif // _sun_security_krb5_PrincipalName_h_