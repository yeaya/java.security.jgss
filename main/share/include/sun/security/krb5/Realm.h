#ifndef _sun_security_krb5_Realm_h_
#define _sun_security_krb5_Realm_h_
//$ class sun.security.krb5.Realm
//$ extends java.lang.Cloneable

#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

#pragma push_macro("AUTODEDUCEREALM")
#undef AUTODEDUCEREALM

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

class $import Realm : public ::java::lang::Cloneable {
	$class(Realm, 0, ::java::lang::Cloneable)
public:
	Realm();
	void init$($String* name);
	void init$(::sun::security::util::DerValue* encoding);
	virtual $bytes* asn1Encode();
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	static ::sun::security::krb5::Realm* getDefault();
	static $StringArray* getRealmsList($String* cRealm, $String* sRealm);
	virtual int32_t hashCode() override;
	static bool isValidRealmString($String* name);
	static ::sun::security::krb5::Realm* parse(::sun::security::util::DerInputStream* data, int8_t explicitTag, bool optional);
	static $StringArray* parseCapaths($String* cRealm, $String* sRealm);
	static $StringArray* parseHierarchy($String* cRealm, $String* sRealm);
	static $String* parseRealm($String* name);
	static $String* parseRealmAtSeparator($String* name);
	static $String* parseRealmComponent($String* name);
	static $String* subStringFrom($StringArray* components, int32_t from);
	virtual $String* toString() override;
	static bool AUTODEDUCEREALM;
	$String* realm = nullptr;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("AUTODEDUCEREALM")

#endif // _sun_security_krb5_Realm_h_