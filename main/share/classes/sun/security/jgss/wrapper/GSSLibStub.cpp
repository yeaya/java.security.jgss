#include <sun/security/jgss/wrapper/GSSLibStub.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Hashtable.h>
#include <org/ietf/jgss/ChannelBinding.h>
#include <org/ietf/jgss/MessageProp.h>
#include <org/ietf/jgss/Oid.h>
#include <sun/security/jgss/wrapper/NativeGSSContext.h>
#include <sun/security/jgss/wrapper/SunNativeProvider.h>
#include <jcpp.h>

using $OidArray = $Array<::org::ietf::jgss::Oid>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Hashtable = ::java::util::Hashtable;
using $ChannelBinding = ::org::ietf::jgss::ChannelBinding;
using $MessageProp = ::org::ietf::jgss::MessageProp;
using $Oid = ::org::ietf::jgss::Oid;
using $NativeGSSContext = ::sun::security::jgss::wrapper::NativeGSSContext;
using $SunNativeProvider = ::sun::security::jgss::wrapper::SunNativeProvider;

namespace sun {
	namespace security {
		namespace jgss {
			namespace wrapper {

$FieldInfo _GSSLibStub_FieldInfo_[] = {
	{"mech", "Lorg/ietf/jgss/Oid;", nullptr, $PRIVATE, $field(GSSLibStub, mech)},
	{"pMech", "J", nullptr, $PRIVATE, $field(GSSLibStub, pMech)},
	{"table", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Lorg/ietf/jgss/Oid;Lsun/security/jgss/wrapper/GSSLibStub;>;", $PRIVATE | $STATIC, $staticField(GSSLibStub, table)},
	{}
};

$MethodInfo _GSSLibStub_MethodInfo_[] = {
	{"<init>", "(Lorg/ietf/jgss/Oid;)V", nullptr, $PRIVATE, $method(static_cast<void(GSSLibStub::*)($Oid*)>(&GSSLibStub::init$)), "org.ietf.jgss.GSSException"},
	{"acceptContext", "(JLorg/ietf/jgss/ChannelBinding;[BLsun/security/jgss/wrapper/NativeGSSContext;)[B", nullptr, $NATIVE},
	{"acquireCred", "(JII)J", nullptr, $NATIVE, nullptr, "org.ietf.jgss.GSSException"},
	{"canonicalizeName", "(J)J", nullptr, $NATIVE},
	{"compareName", "(JJ)Z", nullptr, $NATIVE},
	{"deleteContext", "(J)J", nullptr, $NATIVE},
	{"displayName", "(J)[Ljava/lang/Object;", nullptr, $NATIVE, nullptr, "org.ietf.jgss.GSSException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"exportContext", "(J)[B", nullptr, $NATIVE},
	{"exportName", "(J)[B", nullptr, $NATIVE, nullptr, "org.ietf.jgss.GSSException"},
	{"getContextMech", "(J)Lorg/ietf/jgss/Oid;", nullptr, $NATIVE},
	{"getContextName", "(JZ)J", nullptr, $NATIVE},
	{"getContextTime", "(J)I", nullptr, $NATIVE},
	{"getCredName", "(J)J", nullptr, $NATIVE},
	{"getCredTime", "(J)I", nullptr, $NATIVE},
	{"getCredUsage", "(J)I", nullptr, $NATIVE},
	{"getInstance", "(Lorg/ietf/jgss/Oid;)Lsun/security/jgss/wrapper/GSSLibStub;", nullptr, $STATIC, $method(static_cast<GSSLibStub*(*)($Oid*)>(&GSSLibStub::getInstance)), "org.ietf.jgss.GSSException"},
	{"getMech", "()Lorg/ietf/jgss/Oid;", nullptr, 0},
	{"getMechPtr", "([B)J", nullptr, $PRIVATE | $STATIC | $NATIVE, $method(static_cast<int64_t(*)($bytes*)>(&GSSLibStub::getMechPtr))},
	{"getMic", "(JI[B)[B", nullptr, $NATIVE},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"importContext", "([B)Lsun/security/jgss/wrapper/NativeGSSContext;", nullptr, $NATIVE},
	{"importName", "([BLorg/ietf/jgss/Oid;)J", nullptr, $NATIVE},
	{"indicateMechs", "()[Lorg/ietf/jgss/Oid;", nullptr, $STATIC | $NATIVE, $method(static_cast<$OidArray*(*)()>(&GSSLibStub::indicateMechs))},
	{"init", "(Ljava/lang/String;Z)Z", nullptr, $STATIC | $NATIVE, $method(static_cast<bool(*)($String*,bool)>(&GSSLibStub::init))},
	{"initContext", "(JJLorg/ietf/jgss/ChannelBinding;[BLsun/security/jgss/wrapper/NativeGSSContext;)[B", nullptr, $NATIVE},
	{"inquireContext", "(J)[J", nullptr, $NATIVE},
	{"inquireNamesForMech", "()[Lorg/ietf/jgss/Oid;", nullptr, $NATIVE, nullptr, "org.ietf.jgss.GSSException"},
	{"releaseCred", "(J)J", nullptr, $NATIVE},
	{"releaseName", "(J)V", nullptr, $NATIVE},
	{"unwrap", "(J[BLorg/ietf/jgss/MessageProp;)[B", nullptr, $NATIVE},
	{"verifyMic", "(J[B[BLorg/ietf/jgss/MessageProp;)V", nullptr, $NATIVE},
	{"wrap", "(J[BLorg/ietf/jgss/MessageProp;)[B", nullptr, $NATIVE},
	{"wrapSizeLimit", "(JIII)I", nullptr, $NATIVE},
	{}
};

#define _METHOD_INDEX_acceptContext 1
#define _METHOD_INDEX_acquireCred 2
#define _METHOD_INDEX_canonicalizeName 3
#define _METHOD_INDEX_compareName 4
#define _METHOD_INDEX_deleteContext 5
#define _METHOD_INDEX_displayName 6
#define _METHOD_INDEX_exportContext 8
#define _METHOD_INDEX_exportName 9
#define _METHOD_INDEX_getContextMech 10
#define _METHOD_INDEX_getContextName 11
#define _METHOD_INDEX_getContextTime 12
#define _METHOD_INDEX_getCredName 13
#define _METHOD_INDEX_getCredTime 14
#define _METHOD_INDEX_getCredUsage 15
#define _METHOD_INDEX_getMechPtr 18
#define _METHOD_INDEX_getMic 19
#define _METHOD_INDEX_importContext 21
#define _METHOD_INDEX_importName 22
#define _METHOD_INDEX_indicateMechs 23
#define _METHOD_INDEX_init 24
#define _METHOD_INDEX_initContext 25
#define _METHOD_INDEX_inquireContext 26
#define _METHOD_INDEX_inquireNamesForMech 27
#define _METHOD_INDEX_releaseCred 28
#define _METHOD_INDEX_releaseName 29
#define _METHOD_INDEX_unwrap 30
#define _METHOD_INDEX_verifyMic 31
#define _METHOD_INDEX_wrap 32
#define _METHOD_INDEX_wrapSizeLimit 33

$ClassInfo _GSSLibStub_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jgss.wrapper.GSSLibStub",
	"java.lang.Object",
	nullptr,
	_GSSLibStub_FieldInfo_,
	_GSSLibStub_MethodInfo_
};

$Object* allocate$GSSLibStub($Class* clazz) {
	return $of($alloc(GSSLibStub));
}

$Hashtable* GSSLibStub::table = nullptr;

bool GSSLibStub::init($String* lib, bool debug) {
	$init(GSSLibStub);
	bool $ret = false;
	$prepareNativeStatic(GSSLibStub, init, bool, $String* lib, bool debug);
	$ret = $invokeNativeStatic(GSSLibStub, init, lib, debug);
	$finishNativeStatic();
	return $ret;
}

int64_t GSSLibStub::getMechPtr($bytes* oidDerEncoding) {
	$init(GSSLibStub);
	int64_t $ret = 0;
	$prepareNativeStatic(GSSLibStub, getMechPtr, int64_t, $bytes* oidDerEncoding);
	$ret = $invokeNativeStatic(GSSLibStub, getMechPtr, oidDerEncoding);
	$finishNativeStatic();
	return $ret;
}

$OidArray* GSSLibStub::indicateMechs() {
	$init(GSSLibStub);
	$var($OidArray, $ret, nullptr);
	$prepareNativeStatic(GSSLibStub, indicateMechs, $OidArray*);
	$assign($ret, $invokeNativeStatic(GSSLibStub, indicateMechs));
	$finishNativeStatic();
	return $ret;
}

$OidArray* GSSLibStub::inquireNamesForMech() {
	$var($OidArray, $ret, nullptr);
	$prepareNative(GSSLibStub, inquireNamesForMech, $OidArray*);
	$assign($ret, $invokeNative(GSSLibStub, inquireNamesForMech));
	$finishNative();
	return $ret;
}

void GSSLibStub::releaseName(int64_t pName) {
	$prepareNative(GSSLibStub, releaseName, void, int64_t pName);
	$invokeNative(GSSLibStub, releaseName, pName);
	$finishNative();
}

int64_t GSSLibStub::importName($bytes* name, $Oid* type) {
	int64_t $ret = 0;
	$prepareNative(GSSLibStub, importName, int64_t, $bytes* name, $Oid* type);
	$ret = $invokeNative(GSSLibStub, importName, name, type);
	$finishNative();
	return $ret;
}

bool GSSLibStub::compareName(int64_t pName1, int64_t pName2) {
	bool $ret = false;
	$prepareNative(GSSLibStub, compareName, bool, int64_t pName1, int64_t pName2);
	$ret = $invokeNative(GSSLibStub, compareName, pName1, pName2);
	$finishNative();
	return $ret;
}

int64_t GSSLibStub::canonicalizeName(int64_t pName) {
	int64_t $ret = 0;
	$prepareNative(GSSLibStub, canonicalizeName, int64_t, int64_t pName);
	$ret = $invokeNative(GSSLibStub, canonicalizeName, pName);
	$finishNative();
	return $ret;
}

$bytes* GSSLibStub::exportName(int64_t pName) {
	$var($bytes, $ret, nullptr);
	$prepareNative(GSSLibStub, exportName, $bytes*, int64_t pName);
	$assign($ret, $invokeNative(GSSLibStub, exportName, pName));
	$finishNative();
	return $ret;
}

$ObjectArray* GSSLibStub::displayName(int64_t pName) {
	$var($ObjectArray, $ret, nullptr);
	$prepareNative(GSSLibStub, displayName, $ObjectArray*, int64_t pName);
	$assign($ret, $invokeNative(GSSLibStub, displayName, pName));
	$finishNative();
	return $ret;
}

int64_t GSSLibStub::acquireCred(int64_t pName, int32_t lifetime, int32_t usage) {
	int64_t $ret = 0;
	$prepareNative(GSSLibStub, acquireCred, int64_t, int64_t pName, int32_t lifetime, int32_t usage);
	$ret = $invokeNative(GSSLibStub, acquireCred, pName, lifetime, usage);
	$finishNative();
	return $ret;
}

int64_t GSSLibStub::releaseCred(int64_t pCred) {
	int64_t $ret = 0;
	$prepareNative(GSSLibStub, releaseCred, int64_t, int64_t pCred);
	$ret = $invokeNative(GSSLibStub, releaseCred, pCred);
	$finishNative();
	return $ret;
}

int64_t GSSLibStub::getCredName(int64_t pCred) {
	int64_t $ret = 0;
	$prepareNative(GSSLibStub, getCredName, int64_t, int64_t pCred);
	$ret = $invokeNative(GSSLibStub, getCredName, pCred);
	$finishNative();
	return $ret;
}

int32_t GSSLibStub::getCredTime(int64_t pCred) {
	int32_t $ret = 0;
	$prepareNative(GSSLibStub, getCredTime, int32_t, int64_t pCred);
	$ret = $invokeNative(GSSLibStub, getCredTime, pCred);
	$finishNative();
	return $ret;
}

int32_t GSSLibStub::getCredUsage(int64_t pCred) {
	int32_t $ret = 0;
	$prepareNative(GSSLibStub, getCredUsage, int32_t, int64_t pCred);
	$ret = $invokeNative(GSSLibStub, getCredUsage, pCred);
	$finishNative();
	return $ret;
}

$NativeGSSContext* GSSLibStub::importContext($bytes* interProcToken) {
	$var($NativeGSSContext, $ret, nullptr);
	$prepareNative(GSSLibStub, importContext, $NativeGSSContext*, $bytes* interProcToken);
	$assign($ret, $invokeNative(GSSLibStub, importContext, interProcToken));
	$finishNative();
	return $ret;
}

$bytes* GSSLibStub::initContext(int64_t pCred, int64_t targetName, $ChannelBinding* cb, $bytes* inToken, $NativeGSSContext* context) {
	$var($bytes, $ret, nullptr);
	$prepareNative(GSSLibStub, initContext, $bytes*, int64_t pCred, int64_t targetName, $ChannelBinding* cb, $bytes* inToken, $NativeGSSContext* context);
	$assign($ret, $invokeNative(GSSLibStub, initContext, pCred, targetName, cb, inToken, context));
	$finishNative();
	return $ret;
}

$bytes* GSSLibStub::acceptContext(int64_t pCred, $ChannelBinding* cb, $bytes* inToken, $NativeGSSContext* context) {
	$var($bytes, $ret, nullptr);
	$prepareNative(GSSLibStub, acceptContext, $bytes*, int64_t pCred, $ChannelBinding* cb, $bytes* inToken, $NativeGSSContext* context);
	$assign($ret, $invokeNative(GSSLibStub, acceptContext, pCred, cb, inToken, context));
	$finishNative();
	return $ret;
}

$longs* GSSLibStub::inquireContext(int64_t pContext) {
	$var($longs, $ret, nullptr);
	$prepareNative(GSSLibStub, inquireContext, $longs*, int64_t pContext);
	$assign($ret, $invokeNative(GSSLibStub, inquireContext, pContext));
	$finishNative();
	return $ret;
}

$Oid* GSSLibStub::getContextMech(int64_t pContext) {
	$var($Oid, $ret, nullptr);
	$prepareNative(GSSLibStub, getContextMech, $Oid*, int64_t pContext);
	$assign($ret, $invokeNative(GSSLibStub, getContextMech, pContext));
	$finishNative();
	return $ret;
}

int64_t GSSLibStub::getContextName(int64_t pContext, bool isSrc) {
	int64_t $ret = 0;
	$prepareNative(GSSLibStub, getContextName, int64_t, int64_t pContext, bool isSrc);
	$ret = $invokeNative(GSSLibStub, getContextName, pContext, isSrc);
	$finishNative();
	return $ret;
}

int32_t GSSLibStub::getContextTime(int64_t pContext) {
	int32_t $ret = 0;
	$prepareNative(GSSLibStub, getContextTime, int32_t, int64_t pContext);
	$ret = $invokeNative(GSSLibStub, getContextTime, pContext);
	$finishNative();
	return $ret;
}

int64_t GSSLibStub::deleteContext(int64_t pContext) {
	int64_t $ret = 0;
	$prepareNative(GSSLibStub, deleteContext, int64_t, int64_t pContext);
	$ret = $invokeNative(GSSLibStub, deleteContext, pContext);
	$finishNative();
	return $ret;
}

int32_t GSSLibStub::wrapSizeLimit(int64_t pContext, int32_t flags, int32_t qop, int32_t outSize) {
	int32_t $ret = 0;
	$prepareNative(GSSLibStub, wrapSizeLimit, int32_t, int64_t pContext, int32_t flags, int32_t qop, int32_t outSize);
	$ret = $invokeNative(GSSLibStub, wrapSizeLimit, pContext, flags, qop, outSize);
	$finishNative();
	return $ret;
}

$bytes* GSSLibStub::exportContext(int64_t pContext) {
	$var($bytes, $ret, nullptr);
	$prepareNative(GSSLibStub, exportContext, $bytes*, int64_t pContext);
	$assign($ret, $invokeNative(GSSLibStub, exportContext, pContext));
	$finishNative();
	return $ret;
}

$bytes* GSSLibStub::getMic(int64_t pContext, int32_t qop, $bytes* msg) {
	$var($bytes, $ret, nullptr);
	$prepareNative(GSSLibStub, getMic, $bytes*, int64_t pContext, int32_t qop, $bytes* msg);
	$assign($ret, $invokeNative(GSSLibStub, getMic, pContext, qop, msg));
	$finishNative();
	return $ret;
}

void GSSLibStub::verifyMic(int64_t pContext, $bytes* token, $bytes* msg, $MessageProp* prop) {
	$prepareNative(GSSLibStub, verifyMic, void, int64_t pContext, $bytes* token, $bytes* msg, $MessageProp* prop);
	$invokeNative(GSSLibStub, verifyMic, pContext, token, msg, prop);
	$finishNative();
}

$bytes* GSSLibStub::wrap(int64_t pContext, $bytes* msg, $MessageProp* prop) {
	$var($bytes, $ret, nullptr);
	$prepareNative(GSSLibStub, wrap, $bytes*, int64_t pContext, $bytes* msg, $MessageProp* prop);
	$assign($ret, $invokeNative(GSSLibStub, wrap, pContext, msg, prop));
	$finishNative();
	return $ret;
}

$bytes* GSSLibStub::unwrap(int64_t pContext, $bytes* msgToken, $MessageProp* prop) {
	$var($bytes, $ret, nullptr);
	$prepareNative(GSSLibStub, unwrap, $bytes*, int64_t pContext, $bytes* msgToken, $MessageProp* prop);
	$assign($ret, $invokeNative(GSSLibStub, unwrap, pContext, msgToken, prop));
	$finishNative();
	return $ret;
}

GSSLibStub* GSSLibStub::getInstance($Oid* mech) {
	$init(GSSLibStub);
	$var(GSSLibStub, s, $cast(GSSLibStub, $nc(GSSLibStub::table)->get(mech)));
	if (s == nullptr) {
		$assign(s, $new(GSSLibStub, mech));
		$nc(GSSLibStub::table)->put(mech, s);
	}
	return s;
}

void GSSLibStub::init$($Oid* mech) {
	$SunNativeProvider::debug($$str({"Created GSSLibStub for mech "_s, mech}));
	$set(this, mech, mech);
	this->pMech = getMechPtr($($nc(mech)->getDER()));
}

bool GSSLibStub::equals(Object$* obj) {
	if ($equals(obj, this)) {
		return true;
	}
	if (!($instanceOf(GSSLibStub, obj))) {
		return false;
	}
	return ($nc(this->mech)->equals($($nc(($cast(GSSLibStub, obj)))->getMech())));
}

int32_t GSSLibStub::hashCode() {
	return $nc(this->mech)->hashCode();
}

$Oid* GSSLibStub::getMech() {
	return this->mech;
}

void clinit$GSSLibStub($Class* class$) {
	$assignStatic(GSSLibStub::table, $new($Hashtable, 5));
}

GSSLibStub::GSSLibStub() {
}

$Class* GSSLibStub::load$($String* name, bool initialize) {
	$loadClass(GSSLibStub, name, initialize, &_GSSLibStub_ClassInfo_, clinit$GSSLibStub, allocate$GSSLibStub);
	return class$;
}

$Class* GSSLibStub::class$ = nullptr;

			} // wrapper
		} // jgss
	} // security
} // sun