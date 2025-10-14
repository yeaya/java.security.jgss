#ifndef _org_ietf_jgss_ChannelBinding_h_
#define _org_ietf_jgss_ChannelBinding_h_
//$ class org.ietf.jgss.ChannelBinding
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace net {
		class InetAddress;
	}
}

namespace org {
	namespace ietf {
		namespace jgss {

class $import ChannelBinding : public ::java::lang::Object {
	$class(ChannelBinding, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ChannelBinding();
	void init$(::java::net::InetAddress* initAddr, ::java::net::InetAddress* acceptAddr, $bytes* appData);
	void init$($bytes* appData);
	virtual bool equals(Object$* obj) override;
	virtual ::java::net::InetAddress* getAcceptorAddress();
	virtual $bytes* getApplicationData();
	virtual ::java::net::InetAddress* getInitiatorAddress();
	virtual int32_t hashCode() override;
	::java::net::InetAddress* initiator = nullptr;
	::java::net::InetAddress* acceptor = nullptr;
	$bytes* appData = nullptr;
};

		} // jgss
	} // ietf
} // org

#endif // _org_ietf_jgss_ChannelBinding_h_