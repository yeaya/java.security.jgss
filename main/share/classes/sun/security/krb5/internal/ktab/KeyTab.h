#ifndef _sun_security_krb5_internal_ktab_KeyTab_h_
#define _sun_security_krb5_internal_ktab_KeyTab_h_
//$ class sun.security.krb5.internal.ktab.KeyTab
//$ extends sun.security.krb5.internal.ktab.KeyTabConstants

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace io {
		class File;
	}
}
namespace java {
	namespace util {
		class Map;
		class Vector;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			class EncryptionKey;
			class PrincipalName;
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {
					class KeyTabEntry;
					class KeyTabInputStream;
				}
			}
		}
	}
}

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {

class $export KeyTab : public ::sun::security::krb5::internal::ktab::KeyTabConstants {
	$class(KeyTab, 0, ::sun::security::krb5::internal::ktab::KeyTabConstants)
public:
	KeyTab();
	void init$($String* filename);
	virtual void addEntry(::sun::security::krb5::PrincipalName* service, $chars* psswd, int32_t kvno, bool append);
	virtual void addEntry(::sun::security::krb5::PrincipalName* service, $String* salt, $chars* psswd, int32_t kvno, bool append);
	static ::sun::security::krb5::internal::ktab::KeyTab* create();
	static ::sun::security::krb5::internal::ktab::KeyTab* create($String* name);
	virtual void createVersion(::java::io::File* file);
	virtual int32_t deleteEntries(::sun::security::krb5::PrincipalName* service, int32_t etype, int32_t kvno);
	virtual bool findServiceEntry(::sun::security::krb5::PrincipalName* service);
	static $String* getDefaultTabName();
	virtual $Array<::sun::security::krb5::internal::ktab::KeyTabEntry>* getEntries();
	static ::sun::security::krb5::internal::ktab::KeyTab* getInstance($String* s);
	static ::sun::security::krb5::internal::ktab::KeyTab* getInstance(::java::io::File* file);
	static ::sun::security::krb5::internal::ktab::KeyTab* getInstance();
	static ::sun::security::krb5::internal::ktab::KeyTab* getInstance0($String* s);
	virtual ::sun::security::krb5::PrincipalName* getOneName();
	virtual bool isMissing();
	virtual bool isValid();
	void load(::sun::security::krb5::internal::ktab::KeyTabInputStream* kis);
	static $String* normalize($String* name);
	virtual $Array<::sun::security::krb5::EncryptionKey>* readServiceKeys(::sun::security::krb5::PrincipalName* service);
	virtual void save();
	virtual $String* tabName();
	static bool DEBUG;
	static $String* defaultTabName;
	static ::java::util::Map* map;
	bool isMissing$ = false;
	bool isValid$ = false;
	$String* tabName$ = nullptr;
	int64_t lastModified = 0;
	int32_t kt_vno = 0;
	::java::util::Vector* entries = nullptr;
};

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_ktab_KeyTab_h_