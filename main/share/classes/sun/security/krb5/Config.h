#ifndef _sun_security_krb5_Config_h_
#define _sun_security_krb5_Config_h_
//$ class sun.security.krb5.Config
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("BASE16_0")
#undef BASE16_0
#pragma push_macro("BASE16_1")
#undef BASE16_1
#pragma push_macro("BASE16_2")
#undef BASE16_2
#pragma push_macro("BASE16_3")
#undef BASE16_3
#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("DISABLE_REFERRALS")
#undef DISABLE_REFERRALS
#pragma push_macro("MAX_REFERRALS")
#undef MAX_REFERRALS

namespace java {
	namespace lang {
		class Boolean;
		class StringBuffer;
		class Void;
	}
}
namespace java {
	namespace nio {
		namespace file {
			class Path;
		}
	}
}
namespace java {
	namespace util {
		class Hashtable;
		class List;
		class Set;
		class Vector;
	}
}

namespace sun {
	namespace security {
		namespace krb5 {

class $export Config : public ::java::lang::Object {
	$class(Config, 0, ::java::lang::Object)
public:
	Config();
	void init$();
	static $String* checkRealm($String* mapRealm);
	virtual $ints* defaultEtype($String* configName);
	static int32_t duration($String* s);
	virtual bool exists($StringArray* keys);
	bool fileExists($String* name);
	$String* findMacosConfigFile();
	virtual $String* get($StringArray* keys);
	$Object* get0($StringArray* keys);
	virtual $String* getAll($StringArray* keys);
	int32_t getBase(int32_t i);
	virtual ::java::lang::Boolean* getBooleanObject($StringArray* keys);
	virtual $String* getDefaultRealm();
	static ::sun::security::krb5::Config* getInstance();
	virtual int32_t getIntValue($StringArray* keys);
	$String* getJavaFileName();
	$String* getKDCFromDNS($String* realm);
	virtual $String* getKDCList($String* realm);
	$String* getNativeFileName();
	$String* getRealmFromDNS();
	::java::util::Vector* getString0($StringArray* keys);
	static int32_t getType($String* input);
	static $String* getWindowsDirectory(bool isSystem);
	static bool isMacosLionOrBetter();
	static ::java::nio::file::Path* lambda$loadConfigFile$0($String* fileName);
	virtual void listTable();
	::java::util::List* loadConfigFile($String* fileName);
	int32_t parseIntValue($String* input);
	::java::util::Hashtable* parseStanzaTable(::java::util::List* v);
	static ::java::lang::Void* readConfigFileLines(::java::nio::file::Path* file, ::java::util::List* content, ::java::util::Set* dups);
	static void refresh();
	virtual void resetDefaultRealm($String* realm);
	virtual $String* toString() override;
	static void toStringInternal($String* prefix, Object$* obj, ::java::lang::StringBuffer* sb);
	static $String* unquote($String* s);
	virtual bool useAddresses();
	bool useDNS($String* name, bool defaultValue);
	bool useDNS_KDC();
	bool useDNS_Realm();
	static bool DISABLE_REFERRALS;
	static int32_t MAX_REFERRALS;
	static ::sun::security::krb5::Config* singleton;
	::java::util::Hashtable* stanzaTable = nullptr;
	static bool DEBUG;
	static const int32_t BASE16_0 = 1;
	static const int32_t BASE16_1 = 16;
	static const int32_t BASE16_2 = 256; // 16 * 16
	static const int32_t BASE16_3 = 4096; // 16 * 16 * 16
	$String* defaultRealm = nullptr;
	$String* defaultKDC = nullptr;
};

		} // krb5
	} // security
} // sun

#pragma pop_macro("BASE16_0")
#pragma pop_macro("BASE16_1")
#pragma pop_macro("BASE16_2")
#pragma pop_macro("BASE16_3")
#pragma pop_macro("DEBUG")
#pragma pop_macro("DISABLE_REFERRALS")
#pragma pop_macro("MAX_REFERRALS")

#endif // _sun_security_krb5_Config_h_