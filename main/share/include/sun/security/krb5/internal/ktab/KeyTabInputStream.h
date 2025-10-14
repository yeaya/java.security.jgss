#ifndef _sun_security_krb5_internal_ktab_KeyTabInputStream_h_
#define _sun_security_krb5_internal_ktab_KeyTabInputStream_h_
//$ class sun.security.krb5.internal.ktab.KeyTabInputStream
//$ extends sun.security.krb5.internal.util.KrbDataInputStream
//$ implements sun.security.krb5.internal.ktab.KeyTabConstants

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>
#include <sun/security/krb5/internal/util/KrbDataInputStream.h>

#pragma push_macro("DEBUG")
#undef DEBUG

namespace java {
	namespace io {
		class InputStream;
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				class KerberosTime;
			}
		}
	}
}
namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace ktab {
					class KeyTabEntry;
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

class $import KeyTabInputStream : public ::sun::security::krb5::internal::util::KrbDataInputStream, public ::sun::security::krb5::internal::ktab::KeyTabConstants {
	$class(KeyTabInputStream, $NO_CLASS_INIT, ::sun::security::krb5::internal::util::KrbDataInputStream, ::sun::security::krb5::internal::ktab::KeyTabConstants)
public:
	KeyTabInputStream();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::io::InputStream* is);
	using ::sun::security::krb5::internal::util::KrbDataInputStream::read;
	virtual ::sun::security::krb5::internal::ktab::KeyTabEntry* readEntry(int32_t entryLen, int32_t ktVersion);
	virtual int32_t readEntryLength();
	virtual $bytes* readKey(int32_t length);
	virtual $String* readName();
	virtual ::sun::security::krb5::internal::KerberosTime* readTimeStamp();
	virtual $String* toString() override;
	bool DEBUG = false;
	int32_t index = 0;
};

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun

#pragma pop_macro("DEBUG")

#endif // _sun_security_krb5_internal_ktab_KeyTabInputStream_h_