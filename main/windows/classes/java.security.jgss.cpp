#include <java.security.jgss.h>

#include <java.base.h>
#include <java.logging.h>
#include <java.naming.h>
#include <java.security.sasl.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>
#include <module-info>

#include <javax/security/auth/kerberos/DelegationPermission.h>
#include <javax/security/auth/kerberos/EncryptionKey.h>
#include <javax/security/auth/kerberos/JavaxSecurityAuthKerberosAccessImpl.h>
#include <javax/security/auth/kerberos/KerberosCredMessage.h>
#include <javax/security/auth/kerberos/KerberosKey.h>
#include <javax/security/auth/kerberos/KerberosPrincipal.h>
#include <javax/security/auth/kerberos/KerberosTicket.h>
#include <javax/security/auth/kerberos/KeyImpl.h>
#include <javax/security/auth/kerberos/KeyTab.h>
#include <javax/security/auth/kerberos/KrbDelegationPermissionCollection.h>
#include <javax/security/auth/kerberos/KrbServicePermissionCollection.h>
#include <javax/security/auth/kerberos/KrbServicePermissionCollection$1.h>
#include <javax/security/auth/kerberos/ServicePermission.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/GSSContext.h>
#include <org/ietf/jgss/GSSCredential.h>
#include <org/ietf/jgss/GSSException.h>
#include <org/ietf/jgss/GSSManager.h>
#include <org/ietf/jgss/GSSName.h>
#include <org/ietf/jgss/MessageProp.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/net/www/protocol/http/spnego/NegotiateCallbackHandler.h>
#include <sun/net/www/protocol/http/spnego/NegotiatorImpl.h>
#include <sun/security/jgss/GSSCaller.h>
#include <sun/security/jgss/GSSContextImpl.h>
#include <sun/security/jgss/GSSCredentialImpl.h>
#include <sun/security/jgss/GSSCredentialImpl$SearchKey.h>
#include <sun/security/jgss/GSSExceptionImpl.h>
#include <sun/security/jgss/GSSHeader.h>
#include <sun/security/jgss/GSSManagerImpl.h>
#include <sun/security/jgss/GSSNameImpl.h>
#include <sun/security/jgss/GSSToken.h>
#include <sun/security/jgss/GSSUtil.h>
#include <sun/security/jgss/GSSUtil$1.h>
#include <sun/security/jgss/HttpCaller.h>
#include <sun/security/jgss/JgssExtender.h>
#include <sun/security/jgss/LoginConfigImpl.h>
#include <sun/security/jgss/LoginConfigImpl$1.h>
#include <sun/security/jgss/ProviderList.h>
#include <sun/security/jgss/ProviderList$PreferencesEntry.h>
#include <sun/security/jgss/SunProvider.h>
#include <sun/security/jgss/SunProvider$1.h>
#include <sun/security/jgss/SunProvider$ProviderService.h>
#include <sun/security/jgss/TokenTracker.h>
#include <sun/security/jgss/TokenTracker$Entry.h>
#include <sun/security/jgss/krb5/AcceptSecContextToken.h>
#include <sun/security/jgss/krb5/CipherHelper.h>
#include <sun/security/jgss/krb5/CipherHelper$WrapTokenInputStream.h>
#include <sun/security/jgss/krb5/InitSecContextToken.h>
#include <sun/security/jgss/krb5/InitialToken.h>
#include <sun/security/jgss/krb5/InitialToken$OverloadedChecksum.h>
#include <sun/security/jgss/krb5/Krb5AcceptCredential.h>
#include <sun/security/jgss/krb5/Krb5AcceptCredential$1.h>
#include <sun/security/jgss/krb5/Krb5Context.h>
#include <sun/security/jgss/krb5/Krb5Context$1.h>
#include <sun/security/jgss/krb5/Krb5Context$2.h>
#include <sun/security/jgss/krb5/Krb5Context$3.h>
#include <sun/security/jgss/krb5/Krb5Context$KerberosSessionKey.h>
#include <sun/security/jgss/krb5/Krb5CredElement.h>
#include <sun/security/jgss/krb5/Krb5InitCredential.h>
#include <sun/security/jgss/krb5/Krb5InitCredential$1.h>
#include <sun/security/jgss/krb5/Krb5MechFactory.h>
#include <sun/security/jgss/krb5/Krb5NameElement.h>
#include <sun/security/jgss/krb5/Krb5ProxyCredential.h>
#include <sun/security/jgss/krb5/Krb5Token.h>
#include <sun/security/jgss/krb5/Krb5Util.h>
#include <sun/security/jgss/krb5/MessageToken.h>
#include <sun/security/jgss/krb5/MessageToken$MessageTokenHeader.h>
#include <sun/security/jgss/krb5/MessageToken_v2.h>
#include <sun/security/jgss/krb5/MessageToken_v2$MessageTokenHeader.h>
#include <sun/security/jgss/krb5/MicToken.h>
#include <sun/security/jgss/krb5/MicToken_v2.h>
#include <sun/security/jgss/krb5/ServiceCreds.h>
#include <sun/security/jgss/krb5/SubjectComber.h>
#include <sun/security/jgss/krb5/WrapToken.h>
#include <sun/security/jgss/krb5/WrapToken_v2.h>
#include <sun/security/jgss/krb5/internal/TlsChannelBindingImpl.h>
#include <sun/security/jgss/spi/GSSContextSpi.h>
#include <sun/security/jgss/spi/GSSCredentialSpi.h>
#include <sun/security/jgss/spi/GSSNameSpi.h>
#include <sun/security/jgss/spi/MechanismFactory.h>
#include <sun/security/jgss/spnego/NegTokenInit.h>
#include <sun/security/jgss/spnego/NegTokenTarg.h>
#include <sun/security/jgss/spnego/SpNegoContext.h>
#include <sun/security/jgss/spnego/SpNegoCredElement.h>
#include <sun/security/jgss/spnego/SpNegoMechFactory.h>
#include <sun/security/jgss/spnego/SpNegoToken.h>
#include <sun/security/jgss/spnego/SpNegoToken$NegoResult.h>
#include <sun/security/jgss/wrapper/GSSCredElement.h>
#include <sun/security/jgss/wrapper/GSSLibStub.h>
#include <sun/security/jgss/wrapper/GSSNameElement.h>
#include <sun/security/jgss/wrapper/Krb5Util.h>
#include <sun/security/jgss/wrapper/NativeGSSContext.h>
#include <sun/security/jgss/wrapper/NativeGSSFactory.h>
#include <sun/security/jgss/wrapper/SunNativeProvider.h>
#include <sun/security/jgss/wrapper/SunNativeProvider$1.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/Checksum.h>
#include <sun/security/krb5/Config.h>
#include <sun/security/krb5/Config$1.h>
#include <sun/security/krb5/Config$2.h>
#include <sun/security/krb5/Config$3.h>
#include <sun/security/krb5/Config$FileExistsAction.h>
#include <sun/security/krb5/Confounder.h>
#include <sun/security/krb5/Credentials.h>
#include <sun/security/krb5/Credentials$1.h>
#include <sun/security/krb5/EncryptedData.h>
#include <sun/security/krb5/EncryptionKey.h>
#include <sun/security/krb5/JavaxSecurityAuthKerberosAccess.h>
#include <sun/security/krb5/KdcComm.h>
#include <sun/security/krb5/KdcComm$1.h>
#include <sun/security/krb5/KdcComm$BpType.h>
#include <sun/security/krb5/KdcComm$KdcAccessibility.h>
#include <sun/security/krb5/KdcComm$KdcCommunication.h>
#include <sun/security/krb5/KerberosSecrets.h>
#include <sun/security/krb5/KrbApRep.h>
#include <sun/security/krb5/KrbApReq.h>
#include <sun/security/krb5/KrbAppMessage.h>
#include <sun/security/krb5/KrbAsRep.h>
#include <sun/security/krb5/KrbAsReq.h>
#include <sun/security/krb5/KrbAsReqBuilder.h>
#include <sun/security/krb5/KrbAsReqBuilder$ReferralsState.h>
#include <sun/security/krb5/KrbAsReqBuilder$State.h>
#include <sun/security/krb5/KrbCred.h>
#include <sun/security/krb5/KrbCryptoException.h>
#include <sun/security/krb5/KrbException.h>
#include <sun/security/krb5/KrbKdcRep.h>
#include <sun/security/krb5/KrbPriv.h>
#include <sun/security/krb5/KrbSafe.h>
#include <sun/security/krb5/KrbServiceLocator.h>
#include <sun/security/krb5/KrbServiceLocator$SrvRecord.h>
#include <sun/security/krb5/KrbTgsRep.h>
#include <sun/security/krb5/KrbTgsReq.h>
#include <sun/security/krb5/PrincipalName.h>
#include <sun/security/krb5/Realm.h>
#include <sun/security/krb5/RealmException.h>
#include <sun/security/krb5/SCDynamicStoreConfig.h>
#include <sun/security/krb5/SCDynamicStoreConfig$1.h>
#include <sun/security/krb5/internal/APOptions.h>
#include <sun/security/krb5/internal/APRep.h>
#include <sun/security/krb5/internal/APReq.h>
#include <sun/security/krb5/internal/ASRep.h>
#include <sun/security/krb5/internal/ASReq.h>
#include <sun/security/krb5/internal/AuthContext.h>
#include <sun/security/krb5/internal/Authenticator.h>
#include <sun/security/krb5/internal/AuthorizationData.h>
#include <sun/security/krb5/internal/AuthorizationDataEntry.h>
#include <sun/security/krb5/internal/CredentialsUtil.h>
#include <sun/security/krb5/internal/CredentialsUtil$S4U2Type.h>
#include <sun/security/krb5/internal/ETypeInfo.h>
#include <sun/security/krb5/internal/ETypeInfo2.h>
#include <sun/security/krb5/internal/EncAPRepPart.h>
#include <sun/security/krb5/internal/EncASRepPart.h>
#include <sun/security/krb5/internal/EncKDCRepPart.h>
#include <sun/security/krb5/internal/EncKrbCredPart.h>
#include <sun/security/krb5/internal/EncKrbPrivPart.h>
#include <sun/security/krb5/internal/EncTGSRepPart.h>
#include <sun/security/krb5/internal/EncTicketPart.h>
#include <sun/security/krb5/internal/HostAddress.h>
#include <sun/security/krb5/internal/HostAddresses.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/KDCRep.h>
#include <sun/security/krb5/internal/KDCReq.h>
#include <sun/security/krb5/internal/KDCReqBody.h>
#include <sun/security/krb5/internal/KRBCred.h>
#include <sun/security/krb5/internal/KRBError.h>
#include <sun/security/krb5/internal/KRBPriv.h>
#include <sun/security/krb5/internal/KRBSafe.h>
#include <sun/security/krb5/internal/KRBSafeBody.h>
#include <sun/security/krb5/internal/KdcErrException.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/KrbCredInfo.h>
#include <sun/security/krb5/internal/KrbErrException.h>
#include <sun/security/krb5/internal/LastReq.h>
#include <sun/security/krb5/internal/LastReqEntry.h>
#include <sun/security/krb5/internal/LocalSeqNumber.h>
#include <sun/security/krb5/internal/LoginOptions.h>
#include <sun/security/krb5/internal/MethodData.h>
#include <sun/security/krb5/internal/NetClient.h>
#include <sun/security/krb5/internal/PAData.h>
#include <sun/security/krb5/internal/PAData$SaltAndParams.h>
#include <sun/security/krb5/internal/PAEncTSEnc.h>
#include <sun/security/krb5/internal/PAForUserEnc.h>
#include <sun/security/krb5/internal/PaPacOptions.h>
#include <sun/security/krb5/internal/ReferralsCache.h>
#include <sun/security/krb5/internal/ReferralsCache$ReferralCacheEntry.h>
#include <sun/security/krb5/internal/ReferralsCache$ReferralCacheKey.h>
#include <sun/security/krb5/internal/ReplayCache.h>
#include <sun/security/krb5/internal/ReplayCache$1.h>
#include <sun/security/krb5/internal/SeqNumber.h>
#include <sun/security/krb5/internal/TCPClient.h>
#include <sun/security/krb5/internal/TGSRep.h>
#include <sun/security/krb5/internal/TGSReq.h>
#include <sun/security/krb5/internal/Ticket.h>
#include <sun/security/krb5/internal/TicketFlags.h>
#include <sun/security/krb5/internal/TransitedEncoding.h>
#include <sun/security/krb5/internal/UDPClient.h>
#include <sun/security/krb5/internal/ccache/CCacheInputStream.h>
#include <sun/security/krb5/internal/ccache/CCacheOutputStream.h>
#include <sun/security/krb5/internal/ccache/Credentials.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache.h>
#include <sun/security/krb5/internal/ccache/CredentialsCache$ConfigEntry.h>
#include <sun/security/krb5/internal/ccache/FileCCacheConstants.h>
#include <sun/security/krb5/internal/ccache/FileCredentialsCache.h>
#include <sun/security/krb5/internal/ccache/FileCredentialsCache$1.h>
#include <sun/security/krb5/internal/ccache/FileCredentialsCache$2.h>
#include <sun/security/krb5/internal/ccache/MemoryCredentialsCache.h>
#include <sun/security/krb5/internal/ccache/Tag.h>
#include <sun/security/krb5/internal/crypto/Aes128.h>
#include <sun/security/krb5/internal/crypto/Aes128CtsHmacSha1EType.h>
#include <sun/security/krb5/internal/crypto/Aes128CtsHmacSha2EType.h>
#include <sun/security/krb5/internal/crypto/Aes128Sha2.h>
#include <sun/security/krb5/internal/crypto/Aes256.h>
#include <sun/security/krb5/internal/crypto/Aes256CtsHmacSha1EType.h>
#include <sun/security/krb5/internal/crypto/Aes256CtsHmacSha2EType.h>
#include <sun/security/krb5/internal/crypto/Aes256Sha2.h>
#include <sun/security/krb5/internal/crypto/ArcFourHmac.h>
#include <sun/security/krb5/internal/crypto/ArcFourHmacEType.h>
#include <sun/security/krb5/internal/crypto/CksumType.h>
#include <sun/security/krb5/internal/crypto/Crc32CksumType.h>
#include <sun/security/krb5/internal/crypto/Des.h>
#include <sun/security/krb5/internal/crypto/Des3.h>
#include <sun/security/krb5/internal/crypto/Des3CbcHmacSha1KdEType.h>
#include <sun/security/krb5/internal/crypto/DesCbcCrcEType.h>
#include <sun/security/krb5/internal/crypto/DesCbcEType.h>
#include <sun/security/krb5/internal/crypto/DesCbcMd5EType.h>
#include <sun/security/krb5/internal/crypto/DesMacCksumType.h>
#include <sun/security/krb5/internal/crypto/DesMacKCksumType.h>
#include <sun/security/krb5/internal/crypto/EType.h>
#include <sun/security/krb5/internal/crypto/HmacMd5ArcFourCksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha1Aes128CksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha1Aes256CksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha1Des3KdCksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha2Aes128CksumType.h>
#include <sun/security/krb5/internal/crypto/HmacSha2Aes256CksumType.h>
#include <sun/security/krb5/internal/crypto/KeyUsage.h>
#include <sun/security/krb5/internal/crypto/Nonce.h>
#include <sun/security/krb5/internal/crypto/NullEType.h>
#include <sun/security/krb5/internal/crypto/RsaMd5CksumType.h>
#include <sun/security/krb5/internal/crypto/RsaMd5DesCksumType.h>
#include <sun/security/krb5/internal/crypto/crc32.h>
#include <sun/security/krb5/internal/crypto/dk/AesDkCrypto.h>
#include <sun/security/krb5/internal/crypto/dk/AesSha2DkCrypto.h>
#include <sun/security/krb5/internal/crypto/dk/ArcFourCrypto.h>
#include <sun/security/krb5/internal/crypto/dk/Des3DkCrypto.h>
#include <sun/security/krb5/internal/crypto/dk/DkCrypto.h>
#include <sun/security/krb5/internal/ktab/KeyTab.h>
#include <sun/security/krb5/internal/ktab/KeyTab$1.h>
#include <sun/security/krb5/internal/ktab/KeyTabConstants.h>
#include <sun/security/krb5/internal/ktab/KeyTabEntry.h>
#include <sun/security/krb5/internal/ktab/KeyTabInputStream.h>
#include <sun/security/krb5/internal/ktab/KeyTabOutputStream.h>
#include <sun/security/krb5/internal/rcache/AuthList.h>
#include <sun/security/krb5/internal/rcache/AuthTime.h>
#include <sun/security/krb5/internal/rcache/AuthTimeWithHash.h>
#include <sun/security/krb5/internal/rcache/DflCache.h>
#include <sun/security/krb5/internal/rcache/DflCache$Storage.h>
#include <sun/security/krb5/internal/rcache/MemoryCache.h>
#include <sun/security/krb5/internal/tools/Kinit.h>
#include <sun/security/krb5/internal/tools/KinitOptions.h>
#include <sun/security/krb5/internal/tools/Klist.h>
#include <sun/security/krb5/internal/tools/Ktab.h>
#include <sun/security/krb5/internal/util/KerberosFlags.h>
#include <sun/security/krb5/internal/util/KerberosString.h>
#include <sun/security/krb5/internal/util/KrbDataInputStream.h>
#include <sun/security/krb5/internal/util/KrbDataOutputStream.h>


#define $classEntry(name, clazz) {name, clazz::load$, $getMark(clazz)}
::java::lang::ClassEntry _java$security$jgss_classes_[] = {
	$classEntry("javax.security.auth.kerberos.DelegationPermission", ::javax::security::auth::kerberos::DelegationPermission),
	$classEntry("javax.security.auth.kerberos.EncryptionKey", ::javax::security::auth::kerberos::EncryptionKey),
	$classEntry("javax.security.auth.kerberos.JavaxSecurityAuthKerberosAccessImpl", ::javax::security::auth::kerberos::JavaxSecurityAuthKerberosAccessImpl),
	$classEntry("javax.security.auth.kerberos.KerberosCredMessage", ::javax::security::auth::kerberos::KerberosCredMessage),
	$classEntry("javax.security.auth.kerberos.KerberosKey", ::javax::security::auth::kerberos::KerberosKey),
	$classEntry("javax.security.auth.kerberos.KerberosPrincipal", ::javax::security::auth::kerberos::KerberosPrincipal),
	$classEntry("javax.security.auth.kerberos.KerberosTicket", ::javax::security::auth::kerberos::KerberosTicket),
	$classEntry("javax.security.auth.kerberos.KeyImpl", ::javax::security::auth::kerberos::KeyImpl),
	$classEntry("javax.security.auth.kerberos.KeyTab", ::javax::security::auth::kerberos::KeyTab),
	$classEntry("javax.security.auth.kerberos.KrbDelegationPermissionCollection", ::javax::security::auth::kerberos::KrbDelegationPermissionCollection),
	$classEntry("javax.security.auth.kerberos.KrbServicePermissionCollection", ::javax::security::auth::kerberos::KrbServicePermissionCollection),
	$classEntry("javax.security.auth.kerberos.KrbServicePermissionCollection$1", ::javax::security::auth::kerberos::KrbServicePermissionCollection$1),
	$classEntry("javax.security.auth.kerberos.ServicePermission", ::javax::security::auth::kerberos::ServicePermission),
	$classEntry("org.ietf.jgss.ChannelBinding", ::org::ietf::jgss::ChannelBinding),
	$classEntry("org.ietf.jgss.GSSContext", ::org::ietf::jgss::GSSContext),
	$classEntry("org.ietf.jgss.GSSCredential", ::org::ietf::jgss::GSSCredential),
	$classEntry("org.ietf.jgss.GSSException", ::org::ietf::jgss::GSSException),
	$classEntry("org.ietf.jgss.GSSManager", ::org::ietf::jgss::GSSManager),
	$classEntry("org.ietf.jgss.GSSName", ::org::ietf::jgss::GSSName),
	$classEntry("org.ietf.jgss.MessageProp", ::org::ietf::jgss::MessageProp),
	$classEntry("org.ietf.jgss.Oid", ::org::ietf::jgss::Oid),
	$classEntry("sun.net.www.protocol.http.spnego.NegotiateCallbackHandler", ::sun::net::www::protocol::http::spnego::NegotiateCallbackHandler),
	$classEntry("sun.net.www.protocol.http.spnego.NegotiatorImpl", ::sun::net::www::protocol::http::spnego::NegotiatorImpl),
	$classEntry("sun.security.jgss.GSSCaller", ::sun::security::jgss::GSSCaller),
	$classEntry("sun.security.jgss.GSSContextImpl", ::sun::security::jgss::GSSContextImpl),
	$classEntry("sun.security.jgss.GSSCredentialImpl", ::sun::security::jgss::GSSCredentialImpl),
	$classEntry("sun.security.jgss.GSSCredentialImpl$SearchKey", ::sun::security::jgss::GSSCredentialImpl$SearchKey),
	$classEntry("sun.security.jgss.GSSExceptionImpl", ::sun::security::jgss::GSSExceptionImpl),
	$classEntry("sun.security.jgss.GSSHeader", ::sun::security::jgss::GSSHeader),
	$classEntry("sun.security.jgss.GSSManagerImpl", ::sun::security::jgss::GSSManagerImpl),
	$classEntry("sun.security.jgss.GSSNameImpl", ::sun::security::jgss::GSSNameImpl),
	$classEntry("sun.security.jgss.GSSToken", ::sun::security::jgss::GSSToken),
	$classEntry("sun.security.jgss.GSSUtil", ::sun::security::jgss::GSSUtil),
	$classEntry("sun.security.jgss.GSSUtil$1", ::sun::security::jgss::GSSUtil$1),
	$classEntry("sun.security.jgss.HttpCaller", ::sun::security::jgss::HttpCaller),
	$classEntry("sun.security.jgss.JgssExtender", ::sun::security::jgss::JgssExtender),
	$classEntry("sun.security.jgss.LoginConfigImpl", ::sun::security::jgss::LoginConfigImpl),
	$classEntry("sun.security.jgss.LoginConfigImpl$1", ::sun::security::jgss::LoginConfigImpl$1),
	$classEntry("sun.security.jgss.ProviderList", ::sun::security::jgss::ProviderList),
	$classEntry("sun.security.jgss.ProviderList$PreferencesEntry", ::sun::security::jgss::ProviderList$PreferencesEntry),
	$classEntry("sun.security.jgss.SunProvider", ::sun::security::jgss::SunProvider),
	$classEntry("sun.security.jgss.SunProvider$1", ::sun::security::jgss::SunProvider$1),
	$classEntry("sun.security.jgss.SunProvider$ProviderService", ::sun::security::jgss::SunProvider$ProviderService),
	$classEntry("sun.security.jgss.TokenTracker", ::sun::security::jgss::TokenTracker),
	$classEntry("sun.security.jgss.TokenTracker$Entry", ::sun::security::jgss::TokenTracker$Entry),
	$classEntry("sun.security.jgss.krb5.AcceptSecContextToken", ::sun::security::jgss::krb5::AcceptSecContextToken),
	$classEntry("sun.security.jgss.krb5.CipherHelper", ::sun::security::jgss::krb5::CipherHelper),
	$classEntry("sun.security.jgss.krb5.CipherHelper$WrapTokenInputStream", ::sun::security::jgss::krb5::CipherHelper$WrapTokenInputStream),
	$classEntry("sun.security.jgss.krb5.InitSecContextToken", ::sun::security::jgss::krb5::InitSecContextToken),
	$classEntry("sun.security.jgss.krb5.InitialToken", ::sun::security::jgss::krb5::InitialToken),
	$classEntry("sun.security.jgss.krb5.InitialToken$OverloadedChecksum", ::sun::security::jgss::krb5::InitialToken$OverloadedChecksum),
	$classEntry("sun.security.jgss.krb5.Krb5AcceptCredential", ::sun::security::jgss::krb5::Krb5AcceptCredential),
	$classEntry("sun.security.jgss.krb5.Krb5AcceptCredential$1", ::sun::security::jgss::krb5::Krb5AcceptCredential$1),
	$classEntry("sun.security.jgss.krb5.Krb5Context", ::sun::security::jgss::krb5::Krb5Context),
	$classEntry("sun.security.jgss.krb5.Krb5Context$1", ::sun::security::jgss::krb5::Krb5Context$1),
	$classEntry("sun.security.jgss.krb5.Krb5Context$2", ::sun::security::jgss::krb5::Krb5Context$2),
	$classEntry("sun.security.jgss.krb5.Krb5Context$3", ::sun::security::jgss::krb5::Krb5Context$3),
	$classEntry("sun.security.jgss.krb5.Krb5Context$KerberosSessionKey", ::sun::security::jgss::krb5::Krb5Context$KerberosSessionKey),
	$classEntry("sun.security.jgss.krb5.Krb5CredElement", ::sun::security::jgss::krb5::Krb5CredElement),
	$classEntry("sun.security.jgss.krb5.Krb5InitCredential", ::sun::security::jgss::krb5::Krb5InitCredential),
	$classEntry("sun.security.jgss.krb5.Krb5InitCredential$1", ::sun::security::jgss::krb5::Krb5InitCredential$1),
	$classEntry("sun.security.jgss.krb5.Krb5MechFactory", ::sun::security::jgss::krb5::Krb5MechFactory),
	$classEntry("sun.security.jgss.krb5.Krb5NameElement", ::sun::security::jgss::krb5::Krb5NameElement),
	$classEntry("sun.security.jgss.krb5.Krb5ProxyCredential", ::sun::security::jgss::krb5::Krb5ProxyCredential),
	$classEntry("sun.security.jgss.krb5.Krb5Token", ::sun::security::jgss::krb5::Krb5Token),
	$classEntry("sun.security.jgss.krb5.Krb5Util", ::sun::security::jgss::krb5::Krb5Util),
	$classEntry("sun.security.jgss.krb5.MessageToken", ::sun::security::jgss::krb5::MessageToken),
	$classEntry("sun.security.jgss.krb5.MessageToken$MessageTokenHeader", ::sun::security::jgss::krb5::MessageToken$MessageTokenHeader),
	$classEntry("sun.security.jgss.krb5.MessageToken_v2", ::sun::security::jgss::krb5::MessageToken_v2),
	$classEntry("sun.security.jgss.krb5.MessageToken_v2$MessageTokenHeader", ::sun::security::jgss::krb5::MessageToken_v2$MessageTokenHeader),
	$classEntry("sun.security.jgss.krb5.MicToken", ::sun::security::jgss::krb5::MicToken),
	$classEntry("sun.security.jgss.krb5.MicToken_v2", ::sun::security::jgss::krb5::MicToken_v2),
	$classEntry("sun.security.jgss.krb5.ServiceCreds", ::sun::security::jgss::krb5::ServiceCreds),
	$classEntry("sun.security.jgss.krb5.SubjectComber", ::sun::security::jgss::krb5::SubjectComber),
	$classEntry("sun.security.jgss.krb5.WrapToken", ::sun::security::jgss::krb5::WrapToken),
	$classEntry("sun.security.jgss.krb5.WrapToken_v2", ::sun::security::jgss::krb5::WrapToken_v2),
	$classEntry("sun.security.jgss.krb5.internal.TlsChannelBindingImpl", ::sun::security::jgss::krb5::internal::TlsChannelBindingImpl),
	$classEntry("sun.security.jgss.spi.GSSContextSpi", ::sun::security::jgss::spi::GSSContextSpi),
	$classEntry("sun.security.jgss.spi.GSSCredentialSpi", ::sun::security::jgss::spi::GSSCredentialSpi),
	$classEntry("sun.security.jgss.spi.GSSNameSpi", ::sun::security::jgss::spi::GSSNameSpi),
	$classEntry("sun.security.jgss.spi.MechanismFactory", ::sun::security::jgss::spi::MechanismFactory),
	$classEntry("sun.security.jgss.spnego.NegTokenInit", ::sun::security::jgss::spnego::NegTokenInit),
	$classEntry("sun.security.jgss.spnego.NegTokenTarg", ::sun::security::jgss::spnego::NegTokenTarg),
	$classEntry("sun.security.jgss.spnego.SpNegoContext", ::sun::security::jgss::spnego::SpNegoContext),
	$classEntry("sun.security.jgss.spnego.SpNegoCredElement", ::sun::security::jgss::spnego::SpNegoCredElement),
	$classEntry("sun.security.jgss.spnego.SpNegoMechFactory", ::sun::security::jgss::spnego::SpNegoMechFactory),
	$classEntry("sun.security.jgss.spnego.SpNegoToken", ::sun::security::jgss::spnego::SpNegoToken),
	$classEntry("sun.security.jgss.spnego.SpNegoToken$NegoResult", ::sun::security::jgss::spnego::SpNegoToken$NegoResult),
	$classEntry("sun.security.jgss.wrapper.GSSCredElement", ::sun::security::jgss::wrapper::GSSCredElement),
	$classEntry("sun.security.jgss.wrapper.GSSLibStub", ::sun::security::jgss::wrapper::GSSLibStub),
	$classEntry("sun.security.jgss.wrapper.GSSNameElement", ::sun::security::jgss::wrapper::GSSNameElement),
	$classEntry("sun.security.jgss.wrapper.Krb5Util", ::sun::security::jgss::wrapper::Krb5Util),
	$classEntry("sun.security.jgss.wrapper.NativeGSSContext", ::sun::security::jgss::wrapper::NativeGSSContext),
	$classEntry("sun.security.jgss.wrapper.NativeGSSFactory", ::sun::security::jgss::wrapper::NativeGSSFactory),
	$classEntry("sun.security.jgss.wrapper.SunNativeProvider", ::sun::security::jgss::wrapper::SunNativeProvider),
	$classEntry("sun.security.jgss.wrapper.SunNativeProvider$1", ::sun::security::jgss::wrapper::SunNativeProvider$1),
	$classEntry("sun.security.krb5.Asn1Exception", ::sun::security::krb5::Asn1Exception),
	$classEntry("sun.security.krb5.Checksum", ::sun::security::krb5::Checksum),
	$classEntry("sun.security.krb5.Config", ::sun::security::krb5::Config),
	$classEntry("sun.security.krb5.Config$1", ::sun::security::krb5::Config$1),
	$classEntry("sun.security.krb5.Config$2", ::sun::security::krb5::Config$2),
	$classEntry("sun.security.krb5.Config$3", ::sun::security::krb5::Config$3),
	$classEntry("sun.security.krb5.Config$FileExistsAction", ::sun::security::krb5::Config$FileExistsAction),
	$classEntry("sun.security.krb5.Confounder", ::sun::security::krb5::Confounder),
	$classEntry("sun.security.krb5.Credentials", ::sun::security::krb5::Credentials),
	$classEntry("sun.security.krb5.Credentials$1", ::sun::security::krb5::Credentials$1),
	$classEntry("sun.security.krb5.EncryptedData", ::sun::security::krb5::EncryptedData),
	$classEntry("sun.security.krb5.EncryptionKey", ::sun::security::krb5::EncryptionKey),
	$classEntry("sun.security.krb5.JavaxSecurityAuthKerberosAccess", ::sun::security::krb5::JavaxSecurityAuthKerberosAccess),
	$classEntry("sun.security.krb5.KdcComm", ::sun::security::krb5::KdcComm),
	$classEntry("sun.security.krb5.KdcComm$1", ::sun::security::krb5::KdcComm$1),
	$classEntry("sun.security.krb5.KdcComm$BpType", ::sun::security::krb5::KdcComm$BpType),
	$classEntry("sun.security.krb5.KdcComm$KdcAccessibility", ::sun::security::krb5::KdcComm$KdcAccessibility),
	$classEntry("sun.security.krb5.KdcComm$KdcCommunication", ::sun::security::krb5::KdcComm$KdcCommunication),
	$classEntry("sun.security.krb5.KerberosSecrets", ::sun::security::krb5::KerberosSecrets),
	$classEntry("sun.security.krb5.KrbApRep", ::sun::security::krb5::KrbApRep),
	$classEntry("sun.security.krb5.KrbApReq", ::sun::security::krb5::KrbApReq),
	$classEntry("sun.security.krb5.KrbAppMessage", ::sun::security::krb5::KrbAppMessage),
	$classEntry("sun.security.krb5.KrbAsRep", ::sun::security::krb5::KrbAsRep),
	$classEntry("sun.security.krb5.KrbAsReq", ::sun::security::krb5::KrbAsReq),
	$classEntry("sun.security.krb5.KrbAsReqBuilder", ::sun::security::krb5::KrbAsReqBuilder),
	$classEntry("sun.security.krb5.KrbAsReqBuilder$ReferralsState", ::sun::security::krb5::KrbAsReqBuilder$ReferralsState),
	$classEntry("sun.security.krb5.KrbAsReqBuilder$State", ::sun::security::krb5::KrbAsReqBuilder$State),
	$classEntry("sun.security.krb5.KrbCred", ::sun::security::krb5::KrbCred),
	$classEntry("sun.security.krb5.KrbCryptoException", ::sun::security::krb5::KrbCryptoException),
	$classEntry("sun.security.krb5.KrbException", ::sun::security::krb5::KrbException),
	$classEntry("sun.security.krb5.KrbKdcRep", ::sun::security::krb5::KrbKdcRep),
	$classEntry("sun.security.krb5.KrbPriv", ::sun::security::krb5::KrbPriv),
	$classEntry("sun.security.krb5.KrbSafe", ::sun::security::krb5::KrbSafe),
	$classEntry("sun.security.krb5.KrbServiceLocator", ::sun::security::krb5::KrbServiceLocator),
	$classEntry("sun.security.krb5.KrbServiceLocator$SrvRecord", ::sun::security::krb5::KrbServiceLocator$SrvRecord),
	$classEntry("sun.security.krb5.KrbTgsRep", ::sun::security::krb5::KrbTgsRep),
	$classEntry("sun.security.krb5.KrbTgsReq", ::sun::security::krb5::KrbTgsReq),
	$classEntry("sun.security.krb5.PrincipalName", ::sun::security::krb5::PrincipalName),
	$classEntry("sun.security.krb5.Realm", ::sun::security::krb5::Realm),
	$classEntry("sun.security.krb5.RealmException", ::sun::security::krb5::RealmException),
	$classEntry("sun.security.krb5.SCDynamicStoreConfig", ::sun::security::krb5::SCDynamicStoreConfig),
	$classEntry("sun.security.krb5.SCDynamicStoreConfig$1", ::sun::security::krb5::SCDynamicStoreConfig$1),
	$classEntry("sun.security.krb5.internal.APOptions", ::sun::security::krb5::internal::APOptions),
	$classEntry("sun.security.krb5.internal.APRep", ::sun::security::krb5::internal::APRep),
	$classEntry("sun.security.krb5.internal.APReq", ::sun::security::krb5::internal::APReq),
	$classEntry("sun.security.krb5.internal.ASRep", ::sun::security::krb5::internal::ASRep),
	$classEntry("sun.security.krb5.internal.ASReq", ::sun::security::krb5::internal::ASReq),
	$classEntry("sun.security.krb5.internal.AuthContext", ::sun::security::krb5::internal::AuthContext),
	$classEntry("sun.security.krb5.internal.Authenticator", ::sun::security::krb5::internal::Authenticator),
	$classEntry("sun.security.krb5.internal.AuthorizationData", ::sun::security::krb5::internal::AuthorizationData),
	$classEntry("sun.security.krb5.internal.AuthorizationDataEntry", ::sun::security::krb5::internal::AuthorizationDataEntry),
	$classEntry("sun.security.krb5.internal.CredentialsUtil", ::sun::security::krb5::internal::CredentialsUtil),
	$classEntry("sun.security.krb5.internal.CredentialsUtil$S4U2Type", ::sun::security::krb5::internal::CredentialsUtil$S4U2Type),
	$classEntry("sun.security.krb5.internal.ETypeInfo", ::sun::security::krb5::internal::ETypeInfo),
	$classEntry("sun.security.krb5.internal.ETypeInfo2", ::sun::security::krb5::internal::ETypeInfo2),
	$classEntry("sun.security.krb5.internal.EncAPRepPart", ::sun::security::krb5::internal::EncAPRepPart),
	$classEntry("sun.security.krb5.internal.EncASRepPart", ::sun::security::krb5::internal::EncASRepPart),
	$classEntry("sun.security.krb5.internal.EncKDCRepPart", ::sun::security::krb5::internal::EncKDCRepPart),
	$classEntry("sun.security.krb5.internal.EncKrbCredPart", ::sun::security::krb5::internal::EncKrbCredPart),
	$classEntry("sun.security.krb5.internal.EncKrbPrivPart", ::sun::security::krb5::internal::EncKrbPrivPart),
	$classEntry("sun.security.krb5.internal.EncTGSRepPart", ::sun::security::krb5::internal::EncTGSRepPart),
	$classEntry("sun.security.krb5.internal.EncTicketPart", ::sun::security::krb5::internal::EncTicketPart),
	$classEntry("sun.security.krb5.internal.HostAddress", ::sun::security::krb5::internal::HostAddress),
	$classEntry("sun.security.krb5.internal.HostAddresses", ::sun::security::krb5::internal::HostAddresses),
	$classEntry("sun.security.krb5.internal.KDCOptions", ::sun::security::krb5::internal::KDCOptions),
	$classEntry("sun.security.krb5.internal.KDCRep", ::sun::security::krb5::internal::KDCRep),
	$classEntry("sun.security.krb5.internal.KDCReq", ::sun::security::krb5::internal::KDCReq),
	$classEntry("sun.security.krb5.internal.KDCReqBody", ::sun::security::krb5::internal::KDCReqBody),
	$classEntry("sun.security.krb5.internal.KRBCred", ::sun::security::krb5::internal::KRBCred),
	$classEntry("sun.security.krb5.internal.KRBError", ::sun::security::krb5::internal::KRBError),
	$classEntry("sun.security.krb5.internal.KRBPriv", ::sun::security::krb5::internal::KRBPriv),
	$classEntry("sun.security.krb5.internal.KRBSafe", ::sun::security::krb5::internal::KRBSafe),
	$classEntry("sun.security.krb5.internal.KRBSafeBody", ::sun::security::krb5::internal::KRBSafeBody),
	$classEntry("sun.security.krb5.internal.KdcErrException", ::sun::security::krb5::internal::KdcErrException),
	$classEntry("sun.security.krb5.internal.KerberosTime", ::sun::security::krb5::internal::KerberosTime),
	$classEntry("sun.security.krb5.internal.Krb5", ::sun::security::krb5::internal::Krb5),
	$classEntry("sun.security.krb5.internal.KrbApErrException", ::sun::security::krb5::internal::KrbApErrException),
	$classEntry("sun.security.krb5.internal.KrbCredInfo", ::sun::security::krb5::internal::KrbCredInfo),
	$classEntry("sun.security.krb5.internal.KrbErrException", ::sun::security::krb5::internal::KrbErrException),
	$classEntry("sun.security.krb5.internal.LastReq", ::sun::security::krb5::internal::LastReq),
	$classEntry("sun.security.krb5.internal.LastReqEntry", ::sun::security::krb5::internal::LastReqEntry),
	$classEntry("sun.security.krb5.internal.LocalSeqNumber", ::sun::security::krb5::internal::LocalSeqNumber),
	$classEntry("sun.security.krb5.internal.LoginOptions", ::sun::security::krb5::internal::LoginOptions),
	$classEntry("sun.security.krb5.internal.MethodData", ::sun::security::krb5::internal::MethodData),
	$classEntry("sun.security.krb5.internal.NetClient", ::sun::security::krb5::internal::NetClient),
	$classEntry("sun.security.krb5.internal.PAData", ::sun::security::krb5::internal::PAData),
	$classEntry("sun.security.krb5.internal.PAData$SaltAndParams", ::sun::security::krb5::internal::PAData$SaltAndParams),
	$classEntry("sun.security.krb5.internal.PAEncTSEnc", ::sun::security::krb5::internal::PAEncTSEnc),
	$classEntry("sun.security.krb5.internal.PAForUserEnc", ::sun::security::krb5::internal::PAForUserEnc),
	$classEntry("sun.security.krb5.internal.PaPacOptions", ::sun::security::krb5::internal::PaPacOptions),
	$classEntry("sun.security.krb5.internal.ReferralsCache", ::sun::security::krb5::internal::ReferralsCache),
	$classEntry("sun.security.krb5.internal.ReferralsCache$ReferralCacheEntry", ::sun::security::krb5::internal::ReferralsCache$ReferralCacheEntry),
	$classEntry("sun.security.krb5.internal.ReferralsCache$ReferralCacheKey", ::sun::security::krb5::internal::ReferralsCache$ReferralCacheKey),
	$classEntry("sun.security.krb5.internal.ReplayCache", ::sun::security::krb5::internal::ReplayCache),
	$classEntry("sun.security.krb5.internal.ReplayCache$1", ::sun::security::krb5::internal::ReplayCache$1),
	$classEntry("sun.security.krb5.internal.SeqNumber", ::sun::security::krb5::internal::SeqNumber),
	$classEntry("sun.security.krb5.internal.TCPClient", ::sun::security::krb5::internal::TCPClient),
	$classEntry("sun.security.krb5.internal.TGSRep", ::sun::security::krb5::internal::TGSRep),
	$classEntry("sun.security.krb5.internal.TGSReq", ::sun::security::krb5::internal::TGSReq),
	$classEntry("sun.security.krb5.internal.Ticket", ::sun::security::krb5::internal::Ticket),
	$classEntry("sun.security.krb5.internal.TicketFlags", ::sun::security::krb5::internal::TicketFlags),
	$classEntry("sun.security.krb5.internal.TransitedEncoding", ::sun::security::krb5::internal::TransitedEncoding),
	$classEntry("sun.security.krb5.internal.UDPClient", ::sun::security::krb5::internal::UDPClient),
	$classEntry("sun.security.krb5.internal.ccache.CCacheInputStream", ::sun::security::krb5::internal::ccache::CCacheInputStream),
	$classEntry("sun.security.krb5.internal.ccache.CCacheOutputStream", ::sun::security::krb5::internal::ccache::CCacheOutputStream),
	$classEntry("sun.security.krb5.internal.ccache.Credentials", ::sun::security::krb5::internal::ccache::Credentials),
	$classEntry("sun.security.krb5.internal.ccache.CredentialsCache", ::sun::security::krb5::internal::ccache::CredentialsCache),
	$classEntry("sun.security.krb5.internal.ccache.CredentialsCache$ConfigEntry", ::sun::security::krb5::internal::ccache::CredentialsCache$ConfigEntry),
	$classEntry("sun.security.krb5.internal.ccache.FileCCacheConstants", ::sun::security::krb5::internal::ccache::FileCCacheConstants),
	$classEntry("sun.security.krb5.internal.ccache.FileCredentialsCache", ::sun::security::krb5::internal::ccache::FileCredentialsCache),
	$classEntry("sun.security.krb5.internal.ccache.FileCredentialsCache$1", ::sun::security::krb5::internal::ccache::FileCredentialsCache$1),
	$classEntry("sun.security.krb5.internal.ccache.FileCredentialsCache$2", ::sun::security::krb5::internal::ccache::FileCredentialsCache$2),
	$classEntry("sun.security.krb5.internal.ccache.MemoryCredentialsCache", ::sun::security::krb5::internal::ccache::MemoryCredentialsCache),
	$classEntry("sun.security.krb5.internal.ccache.Tag", ::sun::security::krb5::internal::ccache::Tag),
	$classEntry("sun.security.krb5.internal.crypto.Aes128", ::sun::security::krb5::internal::crypto::Aes128),
	$classEntry("sun.security.krb5.internal.crypto.Aes128CtsHmacSha1EType", ::sun::security::krb5::internal::crypto::Aes128CtsHmacSha1EType),
	$classEntry("sun.security.krb5.internal.crypto.Aes128CtsHmacSha2EType", ::sun::security::krb5::internal::crypto::Aes128CtsHmacSha2EType),
	$classEntry("sun.security.krb5.internal.crypto.Aes128Sha2", ::sun::security::krb5::internal::crypto::Aes128Sha2),
	$classEntry("sun.security.krb5.internal.crypto.Aes256", ::sun::security::krb5::internal::crypto::Aes256),
	$classEntry("sun.security.krb5.internal.crypto.Aes256CtsHmacSha1EType", ::sun::security::krb5::internal::crypto::Aes256CtsHmacSha1EType),
	$classEntry("sun.security.krb5.internal.crypto.Aes256CtsHmacSha2EType", ::sun::security::krb5::internal::crypto::Aes256CtsHmacSha2EType),
	$classEntry("sun.security.krb5.internal.crypto.Aes256Sha2", ::sun::security::krb5::internal::crypto::Aes256Sha2),
	$classEntry("sun.security.krb5.internal.crypto.ArcFourHmac", ::sun::security::krb5::internal::crypto::ArcFourHmac),
	$classEntry("sun.security.krb5.internal.crypto.ArcFourHmacEType", ::sun::security::krb5::internal::crypto::ArcFourHmacEType),
	$classEntry("sun.security.krb5.internal.crypto.CksumType", ::sun::security::krb5::internal::crypto::CksumType),
	$classEntry("sun.security.krb5.internal.crypto.Crc32CksumType", ::sun::security::krb5::internal::crypto::Crc32CksumType),
	$classEntry("sun.security.krb5.internal.crypto.Des", ::sun::security::krb5::internal::crypto::Des),
	$classEntry("sun.security.krb5.internal.crypto.Des3", ::sun::security::krb5::internal::crypto::Des3),
	$classEntry("sun.security.krb5.internal.crypto.Des3CbcHmacSha1KdEType", ::sun::security::krb5::internal::crypto::Des3CbcHmacSha1KdEType),
	$classEntry("sun.security.krb5.internal.crypto.DesCbcCrcEType", ::sun::security::krb5::internal::crypto::DesCbcCrcEType),
	$classEntry("sun.security.krb5.internal.crypto.DesCbcEType", ::sun::security::krb5::internal::crypto::DesCbcEType),
	$classEntry("sun.security.krb5.internal.crypto.DesCbcMd5EType", ::sun::security::krb5::internal::crypto::DesCbcMd5EType),
	$classEntry("sun.security.krb5.internal.crypto.DesMacCksumType", ::sun::security::krb5::internal::crypto::DesMacCksumType),
	$classEntry("sun.security.krb5.internal.crypto.DesMacKCksumType", ::sun::security::krb5::internal::crypto::DesMacKCksumType),
	$classEntry("sun.security.krb5.internal.crypto.EType", ::sun::security::krb5::internal::crypto::EType),
	$classEntry("sun.security.krb5.internal.crypto.HmacMd5ArcFourCksumType", ::sun::security::krb5::internal::crypto::HmacMd5ArcFourCksumType),
	$classEntry("sun.security.krb5.internal.crypto.HmacSha1Aes128CksumType", ::sun::security::krb5::internal::crypto::HmacSha1Aes128CksumType),
	$classEntry("sun.security.krb5.internal.crypto.HmacSha1Aes256CksumType", ::sun::security::krb5::internal::crypto::HmacSha1Aes256CksumType),
	$classEntry("sun.security.krb5.internal.crypto.HmacSha1Des3KdCksumType", ::sun::security::krb5::internal::crypto::HmacSha1Des3KdCksumType),
	$classEntry("sun.security.krb5.internal.crypto.HmacSha2Aes128CksumType", ::sun::security::krb5::internal::crypto::HmacSha2Aes128CksumType),
	$classEntry("sun.security.krb5.internal.crypto.HmacSha2Aes256CksumType", ::sun::security::krb5::internal::crypto::HmacSha2Aes256CksumType),
	$classEntry("sun.security.krb5.internal.crypto.KeyUsage", ::sun::security::krb5::internal::crypto::KeyUsage),
	$classEntry("sun.security.krb5.internal.crypto.Nonce", ::sun::security::krb5::internal::crypto::Nonce),
	$classEntry("sun.security.krb5.internal.crypto.NullEType", ::sun::security::krb5::internal::crypto::NullEType),
	$classEntry("sun.security.krb5.internal.crypto.RsaMd5CksumType", ::sun::security::krb5::internal::crypto::RsaMd5CksumType),
	$classEntry("sun.security.krb5.internal.crypto.RsaMd5DesCksumType", ::sun::security::krb5::internal::crypto::RsaMd5DesCksumType),
	$classEntry("sun.security.krb5.internal.crypto.crc32", ::sun::security::krb5::internal::crypto::crc32),
	$classEntry("sun.security.krb5.internal.crypto.dk.AesDkCrypto", ::sun::security::krb5::internal::crypto::dk::AesDkCrypto),
	$classEntry("sun.security.krb5.internal.crypto.dk.AesSha2DkCrypto", ::sun::security::krb5::internal::crypto::dk::AesSha2DkCrypto),
	$classEntry("sun.security.krb5.internal.crypto.dk.ArcFourCrypto", ::sun::security::krb5::internal::crypto::dk::ArcFourCrypto),
	$classEntry("sun.security.krb5.internal.crypto.dk.Des3DkCrypto", ::sun::security::krb5::internal::crypto::dk::Des3DkCrypto),
	$classEntry("sun.security.krb5.internal.crypto.dk.DkCrypto", ::sun::security::krb5::internal::crypto::dk::DkCrypto),
	$classEntry("sun.security.krb5.internal.ktab.KeyTab", ::sun::security::krb5::internal::ktab::KeyTab),
	$classEntry("sun.security.krb5.internal.ktab.KeyTab$1", ::sun::security::krb5::internal::ktab::KeyTab$1),
	$classEntry("sun.security.krb5.internal.ktab.KeyTabConstants", ::sun::security::krb5::internal::ktab::KeyTabConstants),
	$classEntry("sun.security.krb5.internal.ktab.KeyTabEntry", ::sun::security::krb5::internal::ktab::KeyTabEntry),
	$classEntry("sun.security.krb5.internal.ktab.KeyTabInputStream", ::sun::security::krb5::internal::ktab::KeyTabInputStream),
	$classEntry("sun.security.krb5.internal.ktab.KeyTabOutputStream", ::sun::security::krb5::internal::ktab::KeyTabOutputStream),
	$classEntry("sun.security.krb5.internal.rcache.AuthList", ::sun::security::krb5::internal::rcache::AuthList),
	$classEntry("sun.security.krb5.internal.rcache.AuthTime", ::sun::security::krb5::internal::rcache::AuthTime),
	$classEntry("sun.security.krb5.internal.rcache.AuthTimeWithHash", ::sun::security::krb5::internal::rcache::AuthTimeWithHash),
	$classEntry("sun.security.krb5.internal.rcache.DflCache", ::sun::security::krb5::internal::rcache::DflCache),
	$classEntry("sun.security.krb5.internal.rcache.DflCache$Storage", ::sun::security::krb5::internal::rcache::DflCache$Storage),
	$classEntry("sun.security.krb5.internal.rcache.MemoryCache", ::sun::security::krb5::internal::rcache::MemoryCache),
	$classEntry("sun.security.krb5.internal.tools.Kinit", ::sun::security::krb5::internal::tools::Kinit),
	$classEntry("sun.security.krb5.internal.tools.KinitOptions", ::sun::security::krb5::internal::tools::KinitOptions),
	$classEntry("sun.security.krb5.internal.tools.Klist", ::sun::security::krb5::internal::tools::Klist),
	$classEntry("sun.security.krb5.internal.tools.Ktab", ::sun::security::krb5::internal::tools::Ktab),
	$classEntry("sun.security.krb5.internal.util.KerberosFlags", ::sun::security::krb5::internal::util::KerberosFlags),
	$classEntry("sun.security.krb5.internal.util.KerberosString", ::sun::security::krb5::internal::util::KerberosString),
	$classEntry("sun.security.krb5.internal.util.KrbDataInputStream", ::sun::security::krb5::internal::util::KrbDataInputStream),
	$classEntry("sun.security.krb5.internal.util.KrbDataOutputStream", ::sun::security::krb5::internal::util::KrbDataOutputStream)
};

const char* _java$security$jgss_packages_[] = {
	"javax.security.auth.kerberos",
	"org.ietf.jgss",
	"sun.net.www.protocol.http.spnego",
	"sun.security.jgss",
	"sun.security.jgss.krb5",
	"sun.security.jgss.krb5.internal",
	"sun.security.jgss.spi",
	"sun.security.jgss.spnego",
	"sun.security.jgss.wrapper",
	"sun.security.krb5",
	"sun.security.krb5.internal",
	"sun.security.krb5.internal.ccache",
	"sun.security.krb5.internal.crypto",
	"sun.security.krb5.internal.crypto.dk",
	"sun.security.krb5.internal.ktab",
	"sun.security.krb5.internal.rcache",
	"sun.security.krb5.internal.tools",
	"sun.security.krb5.internal.util"
};

void java$security$jgss$PreloadClass(void* eventData) {
	::java::lang::PreloadClassEvent* event = (::java::lang::PreloadClassEvent*)eventData;
	int32_t length = $lengthOf(_java$security$jgss_classes_);
	for (int i = 0; i < length; i++) {
		::java::lang::ClassEntry* classEntry = &_java$security$jgss_classes_[i];
		if (event->preinit) {
			if ($hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, true);
				continue;
			}
		}
		if (event->preload) {
			if ($hasFlag(classEntry->mark, $PRELOAD) || $hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, false);
			}
		}
	}
}

void java$security$jgss$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$security$jgss$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$setCurrentObjectStack();
	}
}

$StringArray* java$security$jgss$GetPackages() {
	int32_t length = $lengthOf(_java$security$jgss_packages_);
	$var($StringArray, packages, $new($StringArray, length));
	for (int32_t i = 0; i < length; i++) {
		packages->set(i, $str(_java$security$jgss_packages_[i]));
	}
	return packages;
}

::java::lang::ClassEntry* java$security$jgss$GetClassEntry($String* name) {
	int32_t begin = 0;
	int32_t end = $lengthOf(_java$security$jgss_classes_) - 1;
	while (begin <= end) {
		int32_t mid = begin + (end - begin) / 2;
		::java::lang::ClassEntry* classEntry = &_java$security$jgss_classes_[mid];
		int32_t ret = name->compareTo(classEntry->name);
		if (ret < 0) {
			end = mid - 1;
		} else if (ret > 0) {
			begin = mid + 1;
		} else {
			return classEntry;
		}
	}
	return nullptr;
}

$bytes* java$security$jgss$GetResource($String* name) {
	return nullptr;
}

void java$security$jgss::init() {
	::java$base::init();
	::java$logging::init();
	::java$naming::init();
	::java$security$sasl::init();
	::java::lang::Library lib = {
		"java.security.jgss", "17.35", "",
		&_java$security$jgss_ModuleInfo_,
		java$security$jgss$LibEventAction,
		java$security$jgss$GetPackages,
		java$security$jgss$GetClassEntry,
		java$security$jgss$GetResource
	};
	$System::addLibrary(&lib);
}