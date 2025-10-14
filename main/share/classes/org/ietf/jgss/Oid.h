#ifndef _org_ietf_jgss_Oid_h_
#define _org_ietf_jgss_Oid_h_
//$ class org.ietf.jgss.Oid
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace io {
		class InputStream;
	}
}
namespace sun {
	namespace security {
		namespace util {
			class ObjectIdentifier;
		}
	}
}

namespace org {
	namespace ietf {
		namespace jgss {

class $export Oid : public ::java::lang::Object {
	$class(Oid, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Oid();
	void init$($String* strOid);
	void init$(::java::io::InputStream* derOid);
	void init$($bytes* data);
	virtual bool containedIn($Array<::org::ietf::jgss::Oid>* oids);
	virtual bool equals(Object$* other) override;
	virtual $bytes* getDER();
	static ::org::ietf::jgss::Oid* getInstance($String* strOid);
	virtual int32_t hashCode() override;
	virtual $String* toString() override;
	::sun::security::util::ObjectIdentifier* oid = nullptr;
	$bytes* derEncoding = nullptr;
};

		} // jgss
	} // ietf
} // org

#endif // _org_ietf_jgss_Oid_h_