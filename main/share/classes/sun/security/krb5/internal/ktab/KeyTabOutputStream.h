#ifndef _sun_security_krb5_internal_ktab_KeyTabOutputStream_h_
#define _sun_security_krb5_internal_ktab_KeyTabOutputStream_h_
//$ class sun.security.krb5.internal.ktab.KeyTabOutputStream
//$ extends sun.security.krb5.internal.util.KrbDataOutputStream
//$ implements sun.security.krb5.internal.ktab.KeyTabConstants

#include <java/lang/Array.h>
#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>
#include <sun/security/krb5/internal/util/KrbDataOutputStream.h>

namespace java {
	namespace io {
		class OutputStream;
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

class $export KeyTabOutputStream : public ::sun::security::krb5::internal::util::KrbDataOutputStream, public ::sun::security::krb5::internal::ktab::KeyTabConstants {
	$class(KeyTabOutputStream, $NO_CLASS_INIT, ::sun::security::krb5::internal::util::KrbDataOutputStream, ::sun::security::krb5::internal::ktab::KeyTabConstants)
public:
	KeyTabOutputStream();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::io::OutputStream* os);
	using ::sun::security::krb5::internal::util::KrbDataOutputStream::write;
	virtual $String* toString() override;
	virtual void writeEntry(::sun::security::krb5::internal::ktab::KeyTabEntry* entry);
	virtual void writeVersion(int32_t num);
	::sun::security::krb5::internal::ktab::KeyTabEntry* entry = nullptr;
	int32_t keyType = 0;
	$bytes* keyValue = nullptr;
	int32_t version = 0;
};

				} // ktab
			} // internal
		} // krb5
	} // security
} // sun

#endif // _sun_security_krb5_internal_ktab_KeyTabOutputStream_h_