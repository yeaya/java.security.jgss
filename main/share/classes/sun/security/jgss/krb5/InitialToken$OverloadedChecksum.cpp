#include <sun/security/jgss/krb5/InitialToken$OverloadedChecksum.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/util/Arrays.h>
#include <javax/security/auth/kerberos/DelegationPermission.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/GSSException.h>
#include <sun/security/jgss/GSSToken.h>
#include <sun/security/jgss/krb5/CipherHelper.h>
#include <sun/security/jgss/krb5/InitialToken.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/KrbCred.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <jcpp.h>

#undef BAD_BINDINGS
#undef CHECKSUM_FIRST_BYTES
#undef FAILURE
#undef KRB_AP_ERR_INAPP_CKSUM
#undef NULL_KEY

using $CredentialsArray = $Array<::sun::security::krb5::Credentials>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityManager = ::java::lang::SecurityManager;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $Arrays = ::java::util::Arrays;
using $DelegationPermission = ::javax::security::auth::kerberos::DelegationPermission;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;
using $GSSException = ::org::ietf::jgss::GSSException;
using $GSSToken = ::sun::security::jgss::GSSToken;
using $CipherHelper = ::sun::security::jgss::krb5::CipherHelper;
using $InitialToken = ::sun::security::jgss::krb5::InitialToken;
using $Krb5Context = ::sun::security::jgss::krb5::Krb5Context;
using $Checksum = ::sun::security::krb5::Checksum;
using $Credentials = ::sun::security::krb5::Credentials;
using $EncryptionKey = ::sun::security::krb5::EncryptionKey;
using $KrbCred = ::sun::security::krb5::KrbCred;
using $KrbException = ::sun::security::krb5::KrbException;
using $PrincipalName = ::sun::security::krb5::PrincipalName;
using $Krb5 = ::sun::security::krb5::internal::Krb5;

namespace sun {
	namespace security {
		namespace jgss {
			namespace krb5 {

$FieldInfo _InitialToken$OverloadedChecksum_FieldInfo_[] = {
	{"this$0", "Lsun/security/jgss/krb5/InitialToken;", nullptr, $FINAL | $SYNTHETIC, $field(InitialToken$OverloadedChecksum, this$0)},
	{"checksumBytes", "[B", nullptr, $PRIVATE, $field(InitialToken$OverloadedChecksum, checksumBytes)},
	{"delegCreds", "Lsun/security/krb5/Credentials;", nullptr, $PRIVATE, $field(InitialToken$OverloadedChecksum, delegCreds)},
	{"flags", "I", nullptr, $PRIVATE, $field(InitialToken$OverloadedChecksum, flags)},
	{}
};

$MethodInfo _InitialToken$OverloadedChecksum_MethodInfo_[] = {
	{"<init>", "(Lsun/security/jgss/krb5/InitialToken;Lsun/security/jgss/krb5/Krb5Context;Lsun/security/krb5/Credentials;Lsun/security/krb5/Credentials;)V", nullptr, $PUBLIC, $method(static_cast<void(InitialToken$OverloadedChecksum::*)($InitialToken*,$Krb5Context*,$Credentials*,$Credentials*)>(&InitialToken$OverloadedChecksum::init$)), "sun.security.krb5.KrbException,java.io.IOException,org.ietf.jgss.GSSException"},
	{"<init>", "(Lsun/security/jgss/krb5/InitialToken;Lsun/security/jgss/krb5/Krb5Context;Lsun/security/krb5/Checksum;Lsun/security/krb5/EncryptionKey;Lsun/security/krb5/EncryptionKey;)V", nullptr, $PUBLIC, $method(static_cast<void(InitialToken$OverloadedChecksum::*)($InitialToken*,$Krb5Context*,$Checksum*,$EncryptionKey*,$EncryptionKey*)>(&InitialToken$OverloadedChecksum::init$)), "org.ietf.jgss.GSSException,sun.security.krb5.KrbException,java.io.IOException"},
	{"getChecksum", "()Lsun/security/krb5/Checksum;", nullptr, $PUBLIC, nullptr, "sun.security.krb5.KrbException"},
	{"getDelegatedCreds", "()Lsun/security/krb5/Credentials;", nullptr, $PUBLIC},
	{"setContextFlags", "(Lsun/security/jgss/krb5/Krb5Context;)V", nullptr, $PUBLIC},
	{"useNullKey", "(Lsun/security/jgss/krb5/CipherHelper;)Z", nullptr, $PRIVATE, $method(static_cast<bool(InitialToken$OverloadedChecksum::*)($CipherHelper*)>(&InitialToken$OverloadedChecksum::useNullKey))},
	{}
};

$InnerClassInfo _InitialToken$OverloadedChecksum_InnerClassesInfo_[] = {
	{"sun.security.jgss.krb5.InitialToken$OverloadedChecksum", "sun.security.jgss.krb5.InitialToken", "OverloadedChecksum", $PROTECTED},
	{}
};

$ClassInfo _InitialToken$OverloadedChecksum_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.krb5.InitialToken$OverloadedChecksum",
	"java.lang.Object",
	nullptr,
	_InitialToken$OverloadedChecksum_FieldInfo_,
	_InitialToken$OverloadedChecksum_MethodInfo_,
	nullptr,
	nullptr,
	_InitialToken$OverloadedChecksum_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jgss.krb5.InitialToken"
};

$Object* allocate$InitialToken$OverloadedChecksum($Class* clazz) {
	return $of($alloc(InitialToken$OverloadedChecksum));
}

void InitialToken$OverloadedChecksum::init$($InitialToken* this$0, $Krb5Context* context, $Credentials* tgt, $Credentials* serviceTicket) {
	$set(this, this$0, this$0);
	$set(this, checksumBytes, nullptr);
	$set(this, delegCreds, nullptr);
	this->flags = 0;
	$var($bytes, krbCredMessage, nullptr);
	int32_t pos = 0;
	int32_t size = 4 + 16 + 4;
	if (!$nc(tgt)->isForwardable()) {
		$nc(context)->setCredDelegState(false);
		context->setDelegPolicyState(false);
	} else if (context->getCredDelegState()) {
		if (context->getDelegPolicyState()) {
			if (!$nc(serviceTicket)->checkDelegate()) {
				context->setDelegPolicyState(false);
			}
		}
	} else if (context->getDelegPolicyState()) {
		if ($nc(serviceTicket)->checkDelegate()) {
			context->setCredDelegState(true);
		} else {
			context->setDelegPolicyState(false);
		}
	}
	if (context->getCredDelegState()) {
		$var($KrbCred, krbCred, nullptr);
		$var($CipherHelper, cipherHelper, context->getCipherHelper($($nc(serviceTicket)->getSessionKey())));
		if (useNullKey(cipherHelper)) {
			$init($EncryptionKey);
			$assign(krbCred, $new($KrbCred, tgt, serviceTicket, $EncryptionKey::NULL_KEY));
		} else {
			$assign(krbCred, $new($KrbCred, tgt, serviceTicket, $($nc(serviceTicket)->getSessionKey())));
		}
		$assign(krbCredMessage, $nc(krbCred)->getMessage());
		size += 2 + 2 + $nc(krbCredMessage)->length;
	}
	$set(this, checksumBytes, $new($bytes, size));
	$nc(this->checksumBytes)->set(pos++, $nc(this$0->CHECKSUM_FIRST_BYTES)->get(0));
	$nc(this->checksumBytes)->set(pos++, $nc(this$0->CHECKSUM_FIRST_BYTES)->get(1));
	$nc(this->checksumBytes)->set(pos++, $nc(this$0->CHECKSUM_FIRST_BYTES)->get(2));
	$nc(this->checksumBytes)->set(pos++, $nc(this$0->CHECKSUM_FIRST_BYTES)->get(3));
	$var($ChannelBinding, localBindings, context->getChannelBinding());
	if (localBindings != nullptr) {
		$var($bytes, localBindingsBytes, this$0->computeChannelBinding($(context->getChannelBinding())));
		$System::arraycopy(localBindingsBytes, 0, this->checksumBytes, pos, $nc(localBindingsBytes)->length);
	}
	pos += 16;
	if (context->getCredDelegState()) {
		this->flags |= 1;
	}
	if (context->getMutualAuthState()) {
		this->flags |= 2;
	}
	if (context->getReplayDetState()) {
		this->flags |= 4;
	}
	if (context->getSequenceDetState()) {
		this->flags |= 8;
	}
	if (context->getIntegState()) {
		this->flags |= 32;
	}
	if (context->getConfState()) {
		this->flags |= 16;
	}
	$var($bytes, temp, $new($bytes, 4));
	$GSSToken::writeLittleEndian(this->flags, temp);
	$nc(this->checksumBytes)->set(pos++, temp->get(0));
	$nc(this->checksumBytes)->set(pos++, temp->get(1));
	$nc(this->checksumBytes)->set(pos++, temp->get(2));
	$nc(this->checksumBytes)->set(pos++, temp->get(3));
	if (context->getCredDelegState()) {
		$var($PrincipalName, delegateTo, $nc(serviceTicket)->getServer());
		$var($StringBuilder, sb, $new($StringBuilder, "\""_s));
		sb->append($($nc(delegateTo)->getName()))->append(u'\"');
		$var($String, realm, $nc(delegateTo)->getRealmAsString());
		sb->append(" \"krbtgt/"_s)->append(realm)->append(u'@');
		sb->append(realm)->append(u'\"');
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			$var($DelegationPermission, perm, $new($DelegationPermission, $(sb->toString())));
			sm->checkPermission(perm);
		}
		$nc(this->checksumBytes)->set(pos++, (int8_t)1);
		$nc(this->checksumBytes)->set(pos++, (int8_t)0);
		if ($nc(krbCredMessage)->length > 0x0000FFFF) {
			$throwNew($GSSException, $GSSException::FAILURE, -1, "Incorrect message length"_s);
		}
		$GSSToken::writeLittleEndian($nc(krbCredMessage)->length, temp);
		$nc(this->checksumBytes)->set(pos++, temp->get(0));
		$nc(this->checksumBytes)->set(pos++, temp->get(1));
		$System::arraycopy(krbCredMessage, 0, this->checksumBytes, pos, $nc(krbCredMessage)->length);
	}
}

void InitialToken$OverloadedChecksum::init$($InitialToken* this$0, $Krb5Context* context, $Checksum* checksum, $EncryptionKey* key, $EncryptionKey* subKey) {
	$set(this, this$0, this$0);
	$set(this, checksumBytes, nullptr);
	$set(this, delegCreds, nullptr);
	this->flags = 0;
	int32_t pos = 0;
	if (checksum == nullptr) {
		$var($GSSException, ge, $new($GSSException, $GSSException::FAILURE, -1, "No cksum in AP_REQ\'s authenticator"_s));
		ge->initCause($$new($KrbException, $Krb5::KRB_AP_ERR_INAPP_CKSUM));
		$throw(ge);
	}
	$set(this, checksumBytes, $nc(checksum)->getBytes());
	if (($nc(this->checksumBytes)->get(0) != $nc(this$0->CHECKSUM_FIRST_BYTES)->get(0)) || ($nc(this->checksumBytes)->get(1) != $nc(this$0->CHECKSUM_FIRST_BYTES)->get(1)) || ($nc(this->checksumBytes)->get(2) != $nc(this$0->CHECKSUM_FIRST_BYTES)->get(2)) || ($nc(this->checksumBytes)->get(3) != $nc(this$0->CHECKSUM_FIRST_BYTES)->get(3))) {
		$throwNew($GSSException, $GSSException::FAILURE, -1, "Incorrect checksum"_s);
	}
	$var($ChannelBinding, localBindings, context->getChannelBinding());
	if (localBindings != nullptr) {
		$var($bytes, remoteBindingBytes, $new($bytes, 16));
		$System::arraycopy(this->checksumBytes, 4, remoteBindingBytes, 0, 16);
		$var($bytes, noBindings, $new($bytes, 16));
		if (!$Arrays::equals(noBindings, remoteBindingBytes)) {
			$var($bytes, localBindingsBytes, this$0->computeChannelBinding(localBindings));
			if (!$Arrays::equals(localBindingsBytes, remoteBindingBytes)) {
				$throwNew($GSSException, $GSSException::BAD_BINDINGS, -1, "Bytes mismatch!"_s);
			}
		} else {
			$throwNew($GSSException, $GSSException::BAD_BINDINGS, -1, "Token missing ChannelBinding!"_s);
		}
	}
	this->flags = $GSSToken::readLittleEndian(this->checksumBytes, 20, 4);
	if (((int32_t)(this->flags & (uint32_t)1)) > 0) {
		int32_t credLen = $GSSToken::readLittleEndian(this->checksumBytes, 26, 2);
		$var($bytes, credBytes, $new($bytes, credLen));
		$System::arraycopy(this->checksumBytes, 28, credBytes, 0, credLen);
		$var($KrbCred, cred, nullptr);
		try {
			$assign(cred, $new($KrbCred, credBytes, key));
		} catch ($KrbException&) {
			$var($KrbException, ke, $catch());
			if (subKey != nullptr) {
				$assign(cred, $new($KrbCred, credBytes, subKey));
			} else {
				$throw(ke);
			}
		}
		$set(this, delegCreds, $nc($($nc(cred)->getDelegatedCreds()))->get(0));
	}
}

bool InitialToken$OverloadedChecksum::useNullKey($CipherHelper* ch) {
	bool flag = true;
	bool var$0 = ($nc(ch)->getProto() == 1);
	if (var$0 || $nc(ch)->isArcFour()) {
		flag = false;
	}
	return flag;
}

$Checksum* InitialToken$OverloadedChecksum::getChecksum() {
	return $new($Checksum, this->checksumBytes, 0x00008003);
}

$Credentials* InitialToken$OverloadedChecksum::getDelegatedCreds() {
	return this->delegCreds;
}

void InitialToken$OverloadedChecksum::setContextFlags($Krb5Context* context) {
	if (((int32_t)(this->flags & (uint32_t)1)) > 0) {
		context->setCredDelegState(true);
	}
	if (((int32_t)(this->flags & (uint32_t)2)) == 0) {
		context->setMutualAuthState(false);
	}
	if (((int32_t)(this->flags & (uint32_t)4)) == 0) {
		context->setReplayDetState(false);
	}
	if (((int32_t)(this->flags & (uint32_t)8)) == 0) {
		context->setSequenceDetState(false);
	}
	if (((int32_t)(this->flags & (uint32_t)16)) == 0) {
		context->setConfState(false);
	}
	if (((int32_t)(this->flags & (uint32_t)32)) == 0) {
		context->setIntegState(false);
	}
}

InitialToken$OverloadedChecksum::InitialToken$OverloadedChecksum() {
}

$Class* InitialToken$OverloadedChecksum::load$($String* name, bool initialize) {
	$loadClass(InitialToken$OverloadedChecksum, name, initialize, &_InitialToken$OverloadedChecksum_ClassInfo_, allocate$InitialToken$OverloadedChecksum);
	return class$;
}

$Class* InitialToken$OverloadedChecksum::class$ = nullptr;

			} // krb5
		} // jgss
	} // security
} // sun